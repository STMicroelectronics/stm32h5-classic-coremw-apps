/**
  ******************************************************************************
  * @file    LwIP/LwIP_HTTP_Server_Raw/LWIP/App/httpd_cg_ssi.c
  * @author  MCD Application Team
  * @brief   Webserver SSI and CGI handlers
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
#include "main.h"
#include "lwip/debug.h"
#include "lwip/tcp.h"
#include "lwip/apps/httpd.h"
#include "http_cgi_ssi.h"


#include <string.h>
#include <stdlib.h>

/* we will use character "t" as tag for CGI */
char const* TAGCHAR="t";
char const** TAGS=&TAGCHAR;

u16_t PB_Handler(int iIndex, char *pcInsert, int iInsertLen);

char PB_count = 0;

/* CGI handler for LED control */
const char * LEDS_CGI_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);
void httpd_ssi_init(void);
void httpd_cgi_init(void);

/* Html request for "/leds.cgi" will start LEDS_CGI_Handler */
const tCGI LEDS_CGI={"/leds.cgi", LEDS_CGI_Handler};

/* Cgi call table, only one CGI used */
tCGI CGI_TAB[1];

/**
  * @brief  PB_Handler : SSI handler for Push Button page
  */
u16_t PB_Handler(int iIndex, char *pcInsert, int iInsertLen)
{
  /* We have only one SSI handler iIndex = 0 */
  if (iIndex ==0)
  {
    /*  insert the count characters in html*/
    sprintf(pcInsert, "%d", PB_count);
    return strlen(pcInsert);
  }
  return 0;
}

/**
  * @brief  CGI handler for LEDs control
  */
const char * LEDS_CGI_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
  uint32_t i=0;

  /* We have only one SSI handler iIndex = 0 */
  if (iIndex==0)
  {
    /* All LEDs off */
    BSP_LED_Off(LED1);
    BSP_LED_Off(LED2);
    BSP_LED_Off(LED3);

    /* Check cgi parameter : application GET /leds.cgi?led=2&led=4 */
    for (i=0; i<iNumParams; i++)
    {
      /* check parameter "led" */
      if (strcmp(pcParam[i] , "led")==0)
      {
        /* Switch LED1 ON if 1 */
        if(strcmp(pcValue[i], "1") ==0)
          BSP_LED_On(LED1);

        /* Switch LED2 ON if 2 */
        else if(strcmp(pcValue[i], "2") ==0)
          BSP_LED_On(LED2);

        /* Switch LED3 ON if 3 */
        else if(strcmp(pcValue[i], "3") ==0)
          BSP_LED_On(LED3);
      }
    }
  }
  /* uri to send after cgi call*/
  return "/STM32H5xxLED.html";
}

/**
  * @brief  Http webserver Init
  */
void http_server_init(void)
{
  /* Httpd Init */
  httpd_init();

  /* configure SSI handlers (PB page SSI) */
  http_set_ssi_handler(PB_Handler, (char const **)TAGS, 1);

  /* configure CGI handlers (LEDs control CGI) */
  CGI_TAB[0] = LEDS_CGI;
  http_set_cgi_handlers(CGI_TAB, 1);
}


