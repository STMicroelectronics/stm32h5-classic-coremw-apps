/**
  ******************************************************************************
  * @file    LwIP/LwIP_TCP_Echo_Server/LWIP/App/app_ethernet.c
  * @author  MCD Application Team
  * @brief   Ethernet specefic module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "lwip/opt.h"
#include "main.h"
#if LWIP_DHCP
#include "lwip/dhcp.h"
#endif
#include "app_ethernet.h"
#include "ethernetif.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

uint32_t EthernetLinkTimer;

#if LWIP_DHCP
#define MAX_DHCP_TRIES  4
uint32_t DHCPfineTimer = 0;
uint8_t DHCP_state = DHCP_OFF;
#endif

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Notify the User about the network interface config status
  * @param  netif: the network interface
  * @retval None
  */
void ethernet_link_status_updated(struct netif *netif)
{
  if (netif_is_link_up(netif))
  {
#if LWIP_DHCP
    /* Update DHCP state machine */
    DHCP_state = DHCP_START;
#else
    ip_addr_t ipaddr;
    char ip_str[16];
    ip4_addr_set_u32(&ipaddr, netif_ip4_addr(netif)->addr);
    ip4addr_ntoa_r(&ipaddr, ip_str, sizeof(ip_str));
    printf("Static IPv4 address: %s\n", ip_str);
    BSP_LED_On(LED_YELLOW);
    BSP_LED_Off(LED_RED);
#endif /* LWIP_DHCP */
  }
  else
  {
#if LWIP_DHCP
    /* Update DHCP state machine */
    DHCP_state = DHCP_LINK_DOWN;
#else
    printf ("The network cable is not connected \r\n");
    BSP_LED_Off(LED_YELLOW);
    BSP_LED_On(LED_RED);
#endif /* LWIP_DHCP */
  }
}

#if LWIP_NETIF_LINK_CALLBACK
/**
  * @brief  Ethernet Link periodic check
  * @param  netif: the network interface
  * @retval None
  */
void Ethernet_Link_Periodic_Handle(struct netif *netif)
{
  /* Ethernet Link every 100ms */
  if (HAL_GetTick() - EthernetLinkTimer >= 100)
  {
    EthernetLinkTimer = HAL_GetTick();
    ethernet_link_check_state(netif);
  }
}
#endif

#if LWIP_DHCP
/**
  * @brief  DHCP_Process_Handle
  * @param  netif: the network interface
  * @retval None
  */
void DHCP_Process(struct netif *netif)
{
  ip_addr_t ipaddr;
  ip_addr_t netmask;
  ip_addr_t gw;
  struct dhcp *dhcp;
  char ip_str[16];

  switch (DHCP_state)
  {
    case DHCP_START:
    {
      BSP_LED_Off(LED_YELLOW);
      BSP_LED_Off(LED_RED);
      printf ("State: Looking for DHCP server ...\r\n");

      ip_addr_set_zero_ip4(&netif->ip_addr);
      ip_addr_set_zero_ip4(&netif->netmask);
      ip_addr_set_zero_ip4(&netif->gw);

      dhcp_start(netif);
      DHCP_state = DHCP_WAIT_ADDRESS;
    }
    break;

  case DHCP_WAIT_ADDRESS:
    {
      if (dhcp_supplied_address(netif))
      {
        DHCP_state = DHCP_ADDRESS_ASSIGNED;
        BSP_LED_On(LED_YELLOW);
        BSP_LED_Off(LED_RED);

        ip4_addr_set_u32(&ipaddr, netif_ip4_addr(netif)->addr);
        ip4addr_ntoa_r(&ipaddr, ip_str, sizeof(ip_str));
        printf("IPv4 address assigned by a DHCP server: %s\r\n", ip_str);
      }
      else
      {
        dhcp = (struct dhcp *)netif_get_client_data(netif, LWIP_NETIF_CLIENT_DATA_INDEX_DHCP);

        /* DHCP timeout */
        if (dhcp->tries > MAX_DHCP_TRIES)
        {
          DHCP_state = DHCP_TIMEOUT;

          /* Static address used */
          IP_ADDR4(&ipaddr, IP_ADDR0 ,IP_ADDR1 , IP_ADDR2 , IP_ADDR3 );
          IP_ADDR4(&netmask, NETMASK_ADDR0, NETMASK_ADDR1, NETMASK_ADDR2, NETMASK_ADDR3);
          IP_ADDR4(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);
          netif_set_addr(netif, &ipaddr, &netmask, &gw);

          ip4_addr_set_u32(&ipaddr, netif_ip4_addr(netif)->addr);
          ip4addr_ntoa_r(&ipaddr, ip_str, sizeof(ip_str));
          printf ("DHCP Timeout !! \r\n");
          printf("Static IPv4 address: %s\r\n", ip_str);
          BSP_LED_On(LED_YELLOW);
          BSP_LED_Off(LED_RED);

        }
      }
    }
    break;
  case DHCP_LINK_DOWN:
    {
      DHCP_state = DHCP_OFF;

      printf ("The network cable is not connected \r\n");
      BSP_LED_Off(LED_YELLOW);
      BSP_LED_On(LED_RED);
    }
    break;
  default: break;
  }
}

/**
  * @brief  DHCP periodic check
  * @param  netif: the network interface
  * @retval None
  */
void DHCP_Periodic_Handle(struct netif *netif)
{
  /* Fine DHCP periodic process every 500ms */
  if (HAL_GetTick() - DHCPfineTimer >= DHCP_FINE_TIMER_MSECS)
  {
    DHCPfineTimer =  HAL_GetTick();
    /* process DHCP state machine */
    DHCP_Process(netif);
  }
}
#endif


