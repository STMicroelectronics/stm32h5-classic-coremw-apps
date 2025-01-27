/**
  ******************************************************************************
  * @file    LwIP/LwIP_UDPTCP_Echo_Server_Netconn_RTOS/LWIP/App/tcpecho.c
  * @author  MCD Application Team
  * @brief   tcp echo server main thread using LwIP Netconn API
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
#include "tcpecho.h"
#include "lwip/opt.h"
#include "FreeRTOS.h"



#if LWIP_NETCONN

#include "lwip/sys.h"
#include "lwip/api.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define TCPECHO_THREAD_PRIO  (osPriorityAboveNormal)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
static void tcpecho_thread(void *arg)
{
  struct netconn *conn, *newconn;
  err_t err;
  LWIP_UNUSED_ARG(arg);

  /* Create a new connection identifier. */
  /* Bind connection to well known port number 7. */
  conn = netconn_new(NETCONN_TCP);
  netconn_bind(conn, IP_ADDR_ANY, 7);

  LWIP_ERROR("tcpecho: invalid conn", (conn != NULL), return;);

  /* Tell connection to go into listening mode. */
  netconn_listen(conn);

  while (1) {

    /* Grab new connection. */
    err = netconn_accept(conn, &newconn);

    /* Process the new connection. */
    if (err == ERR_OK) {

      struct netbuf *buf;
      void *data;
      u16_t len;

      while ((err = netconn_recv(newconn, &buf)) == ERR_OK) {
        do {
             netbuf_data(buf, &data, &len);
             err = netconn_write(newconn, data, len, NETCONN_COPY);
        } while (netbuf_next(buf) >= 0);
        netbuf_delete(buf);
      }
      /* Close connection and discard connection identifier. */
      netconn_close(newconn);
      netconn_delete(newconn);
    }
  }
}
/*-----------------------------------------------------------------------------------*/
void tcpecho_init(void)
{
  sys_thread_new("tcpecho_thread", tcpecho_thread, NULL, (configMINIMAL_STACK_SIZE * 9), TCPECHO_THREAD_PRIO);
}
/*-----------------------------------------------------------------------------------*/

#endif /* LWIP_NETCONN */
