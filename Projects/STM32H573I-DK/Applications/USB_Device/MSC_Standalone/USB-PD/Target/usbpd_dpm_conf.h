/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usbpd_dpm_conf.h
  * @author  MCD Application Team
  * @brief   Header file for stack/application settings file
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
/* USER CODE END Header */

#ifndef __USBPD_DPM_CONF_H
#define __USBPD_DPM_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "usbpd_dpm_user.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private variables ---------------------------------------------------------*/
#ifndef __USBPD_DPM_CORE_C
extern USBPD_SettingsTypeDef            DPM_Settings[USBPD_PORT_COUNT];
#else /* __USBPD_DPM_CORE_C */
const USBPD_SettingsTypeDef       DPM_Settings[USBPD_PORT_COUNT] =
{
  {
    .PE_DefaultRole = USBPD_PORTPOWERROLE_SNK,  /* Default port role                                       */
  }
};

#endif /* !__USBPD_DPM_CORE_C */
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

#ifdef __cplusplus
}
#endif

#endif /* __USBPD_DPM_CONF_H */
