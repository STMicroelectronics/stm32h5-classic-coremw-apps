/**
  ******************************************************************************
  * @file    ncv26004.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the
  *          ncv26004.c PHY driver.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef NCV26004_H
#define NCV26004_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Component
  * @{
  */

/** @defgroup NCV26004
  * @{
  */
/* Exported constants --------------------------------------------------------*/
/** @defgroup NCV26004_Exported_Constants NCV26004 Exported Constants
  * @{
  */

/** @defgroup NCV26004_Registers_Mapping NCV26004 Registers Mapping
  * @{
  */
#define NCV26004_MIIMCTL      ((uint16_t)0x0000U)
#define NCV26004_PHYID0       ((uint16_t)0x0002U)
#define NCV26004_PHYID1       ((uint16_t)0x0003U)
#define NCV26004_PMDCTL       ((uint16_t)0x0010U)
#define NCV26004_TWEAKS0      ((uint16_t)0x0011U)
#define NCV26004_TWEAKS1      ((uint16_t)0x0012U)

/**
  * @}
  */

/** @defgroup NCV26004_MIIMCTL_Bit_Definition NCV26004 MIIMCTL Bit Definition
  * @{
  */
#define NCV26004_MIIMCTL_RESET         ((uint16_t)0x8000U)
#define NCV26004_MIIMCTL_LOOPBACK      ((uint16_t)0x4000U)
/**
  * @}
  */

/** @defgroup NCV26004_PHYID0_Bit_Definition NCV26004 PHYID0 Bit Definition
  * @{
  */
#define NCV26004_PHYID0_OUI_3_18           ((uint16_t)0xFFFFU)
/**
  * @}
  */

/** @defgroup NCV26004_PHYID1_Bit_Definition NCV26004 PHYID1 Bit Definition
  * @{
  */
#define NCV26004_PHYID1_OUI_3_18           ((uint16_t)0xFFFFU)
/**
  * @}
  */

/** @defgroup NCV26004_PMDCTL_Bit_Definition NCV26004 PMDCTL Bit Definition
  * @{
  */
#define NCV26004_PMDCTL_FDCAP              ((uint16_t)0x8000U)
#define NCV26004_PMDCTL_HDCAP              ((uint16_t)0x4000U)
#define NCV26004_PMDCTL_TPREFN             ((uint16_t)0x0002U)
#define NCV26004_PMDCTL_TPEN               ((uint16_t)0x0001U)

/**
  * @}
  */

/** @defgroup NCV26004_TWEAKS0_Bit_Definition NCV26004 TWEAKS0 Bit Definition
  * @{
  */
#define NCV26004_TWEAKS0_TX_GAIN         ((uint16_t)0xC000U)
#define NCV26004_TWEAKS0_RX_CD           ((uint16_t)0x3000U)
#define NCV26004_TWEAKS0_RX_ED           ((uint16_t)0x0F00U)
#define NCV26004_TWEAKS0_ED_FB           ((uint16_t)0x0080U)
#define NCV26004_TWEAKS0_RX_RB           ((uint16_t)0x0040U)
#define NCV26004_TWEAKS0_TXSLEW          ((uint16_t)0x0030U)
#define NCV26004_TWEAKS0_TSD             ((uint16_t)0x0008U)
#define NCV26004_TWEAKS0_CMC             ((uint16_t)0x0003U)
/**
  * @}
  */

/** @defgroup NCV26004_TWEAKS1_Bit_Definition NCV26004 TWEAKS1 Bit Definition
  * @{
  */
#define NCV26004_TWEAKS1_WAKE_TMR_DONE      ((uint16_t)0x8000U)
#define NCV26004_TWEAKS1_JABBER_TMR_DONE    ((uint16_t)0x4000U)
#define NCV26004_TWEAKS1_TSD_TRIGGERED      ((uint16_t)0x2000U)
#define NCV26004_TWEAKS1_POR_VCC            ((uint16_t)0x1000U)
#define NCV26004_TWEAKS1_POR_VIO            ((uint16_t)0x0800U)
#define NCV26004_TWEAKS1_SLEEP              ((uint16_t)0x0400U)
#define NCV26004_TWEAKS1_HFCLKG             ((uint16_t)0x0100U)
#define NCV26004_TWEAKS1_WUD_DIS_CHECK      ((uint16_t)0x0080U)
#define NCV26004_TWEAKS1_WUD_TH             ((uint16_t)0x0040U)
#define NCV26004_TWEAKS1_COL_ALGORITM_DIS   ((uint16_t)0x0020U)
#define NCV26004_TWEAKS1_DSLEW              ((uint16_t)0x0010U)
#define NCV26004_TWEAKS1_COL_DET_THR        ((uint16_t)0x000FU)
/**
  * @}
  */

/** @defgroup NCV26004_Status NCV26004 Status
  * @{
  */

#define  NCV26004_STATUS_READ_ERROR            ((int32_t)-5)
#define  NCV26004_STATUS_WRITE_ERROR           ((int32_t)-4)
#define  NCV26004_STATUS_ADDRESS_ERROR         ((int32_t)-3)
#define  NCV26004_STATUS_RESET_TIMEOUT         ((int32_t)-2)
#define  NCV26004_STATUS_ERROR                 ((int32_t)-1)
#define  NCV26004_STATUS_OK                    ((int32_t) 0)
#define  NCV26004_STATUS_FULLDUPLEX            ((int32_t) 1)
#define  NCV26004_STATUS_HALFDUPLEX            ((int32_t) 2)

/**
  * @}
  */

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup NCV26004_Exported_Types NCV26004 Exported Types
  * @{
  */
typedef int32_t  (*ncv26004_Init_Func) (void); 
typedef int32_t  (*ncv26004_DeInit_Func) (void);
typedef int32_t  (*ncv26004_ReadReg_Func)   (uint32_t, uint32_t, uint32_t *);
typedef int32_t  (*ncv26004_WriteReg_Func)  (uint32_t, uint32_t, uint32_t);
typedef int32_t  (*ncv26004_GetTick_Func)  (void);

typedef struct 
{
  ncv26004_Init_Func      Init;
  ncv26004_DeInit_Func    DeInit;
  ncv26004_WriteReg_Func  WriteReg;
  ncv26004_ReadReg_Func   ReadReg;
  ncv26004_GetTick_Func   GetTick;
} ncv26004_IOCtx_t;

typedef struct
{
  uint32_t            DevAddr;
  uint32_t            Is_Initialized;
  ncv26004_IOCtx_t    IO;
  void               *pData;
}ncv26004_Object_t;
/**
  * @}
  */ 

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @defgroup NCV26004_Exported_Functions NCV26004 Exported Functions
  * @{
  */
int32_t NCV26004_RegisterBusIO(ncv26004_Object_t *pObj, ncv26004_IOCtx_t *ioctx);
int32_t NCV26004_Init(ncv26004_Object_t *pObj);
int32_t NCV26004_DeInit(ncv26004_Object_t *pObj);
int32_t NCV26004_SetLinkState(ncv26004_Object_t *pObj, uint32_t LinkState);
int32_t NCV26004_GetLinkState(ncv26004_Object_t *pObj);
int32_t NCV26004_EnableLoopbackMode(ncv26004_Object_t *pObj);
int32_t NCV26004_DisableLoopbackMode(ncv26004_Object_t *pObj);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif
#endif /* NCV26004_H */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
