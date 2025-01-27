/**
  ******************************************************************************
  * @file    LwIP/LwIP_UDPTCP_Echo_Server_Netconn_RTOS/LWIP/App/udpecho.c
  * @author  MCD Application Team
  * @brief   udp echo server main thread using LwIP Netconn API
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
#include "udpecho.h"
#include "lwip/opt.h"
#include "FreeRTOS.h"



#if LWIP_NETCONN

#include "lwip/api.h"
#include "lwip/sys.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define UDPECHO_THREAD_PRIO  (osPriorityAboveNormal)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
static void
udpecho_thread(void *arg)
{
  struct netconn *conn;
  struct netbuf *buf, *tx_buf;
  err_t err;
  LWIP_UNUSED_ARG(arg);

  conn = netconn_new(NETCONN_UDP);
  netconn_bind(conn, IP_ADDR_ANY, 7);

  LWIP_ERROR("udpecho: invalid conn", (conn != NULL), return;);

  while (1) {
    err = netconn_recv(conn, &buf);

    if (err == ERR_OK) {

      tx_buf = netbuf_new();
      netbuf_alloc(tx_buf, buf->p->tot_len);

      pbuf_take(tx_buf->p, (const void *)buf->p->payload, buf->p->tot_len);

      err = netconn_sendto(conn, tx_buf, (const ip_addr_t *)&(buf->addr), buf->port);
      if(err != ERR_OK) {
        LWIP_DEBUGF(LWIP_DBG_ON, ("netconn_send failed: %d\n", (int)err));
      } else {
        LWIP_DEBUGF(LWIP_DBG_ON, ("got %s\n", buffer));
      }
      netbuf_delete(tx_buf);
    }

    netbuf_delete(buf);
  }
}
/*-----------------------------------------------------------------------------------*/
void udpecho_init(void)
{
  sys_thread_new("udpecho_thread", udpecho_thread, NULL, (configMINIMAL_STACK_SIZE * 9), UDPECHO_THREAD_PRIO);
}

#endif /* LWIP_NETCONN */
