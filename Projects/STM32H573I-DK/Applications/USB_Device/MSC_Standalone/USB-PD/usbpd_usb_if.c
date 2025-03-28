/**
  ******************************************************************************
  * @file    usbpd_usb_if.c
  * @author  MCD Application Team
  * @brief   This file contains the usb if functions.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "usbpd_usb_if.h"
#include "usbpd_trace.h"
#include "usbd_core.h"
/* USB include files ---------------------------------------------------------*/
/* USER CODE BEGIN USB Include files */

/* USER CODE END USB Include file */

/* Private enums -------------------------------------------------------------*/
/* USER CODE BEGIN USB Private enums */

/* USER CODE END USB Private enums */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN USB Private typedef */

/* USER CODE END USB Private typedef */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN USB Private define */

/* USER CODE END USB Private define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN USB Private macro */

/* USER CODE END USB Private macro */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN USB Private function prototypes */

/* USER CODE END USB Private function prototypes */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN USB Private variables */
extern USBD_HandleTypeDef hUsbDeviceFS;
/* USER CODE END USB Private variables */

/* Exported functions ---------------------------------------------------------*/
/**
  * @brief  Initialize billboard driver
  * @param  None
  * @retval status
  */
int32_t USBPD_USBIF_Init(void)
{
  USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t *)"USB_IF init", 11);
  return 0;
}

/** @addtogroup USBPD_CORE_USBIF_Exported_Functions
  * @{
  */
void USBPD_USBIF_DeviceStart(uint32_t PortNum)
{
  USBPD_TRACE_Add(USBPD_TRACE_DEBUG, PortNum, 0, (uint8_t *)"USBIF Device start", 18);
  if (USBD_Start(&hUsbDeviceFS) != USBD_OK)
  {
    Error_Handler();
  }
}

void USBPD_USBIF_DeviceStop(uint32_t PortNum)
{
  USBPD_TRACE_Add(USBPD_TRACE_DEBUG, PortNum, 0, (uint8_t *)"USBIF Device stop", 16);
  if (USBD_Stop(&hUsbDeviceFS)!=USBD_OK)
  {
    Error_Handler();
  }
}

void USBPD_USBIF_HostStart(uint32_t PortNum)
{
  USBPD_TRACE_Add(USBPD_TRACE_DEBUG, PortNum, 0, (uint8_t *)"USBIF host start", 16);
}

void USBPD_USBIF_HostStop(uint32_t PortNum)
{
  USBPD_TRACE_Add(USBPD_TRACE_DEBUG, PortNum, 0, (uint8_t *)"USBIF host stop", 14);
}

void USBPD_USBIF_DeviceBillboard(uint32_t PortNum)
{
  USBPD_TRACE_Add(USBPD_TRACE_DEBUG, PortNum, 0, (uint8_t *)"USBIF device billboard", 22);
}

void USBPD_USBIF_Swap2Host(uint32_t PortNum)
{
  USBPD_TRACE_Add(USBPD_TRACE_DEBUG, PortNum, 0, (uint8_t *)"USBIF swap to host", 18);
}

void USBPD_USBIF_Swap2Device(uint32_t PortNum)
{
  USBPD_TRACE_Add(USBPD_TRACE_DEBUG, PortNum, 0, (uint8_t *)"USBIF swap to device", 20);
}

void USBPD_USBIF_DeviceSetBOSInfo(uint32_t PortNum, void *DataPtr)
{
  USBPD_TRACE_Add(USBPD_TRACE_DEBUG, PortNum, 0, (uint8_t *)"USBIF set BOS info", 18);
}

void USBPD_USBIF_DeviceSetVDMInfo(uint32_t PortNum, void *DataPtr)
{
  USBPD_TRACE_Add(USBPD_TRACE_DEBUG, PortNum, 0, (uint8_t *)"USBIF set VDM info", 18);
}

/**
  * @}
  */

/** @addtogroup USBPD_CORE_USBIF_Private_Functions
  * @{
  */

/* USER CODE BEGIN Private functions */

/* USER CODE END Private functions */

/**
  * @}
  */

