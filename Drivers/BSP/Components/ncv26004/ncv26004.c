/**
  ******************************************************************************
  * @file    ncv26004.c
  * @author  MCD Application Team
  * @brief   This file provides a set of functions to interface with the ncv26004
  *          device.
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
#include "ncv26004.h"
#include "stdio.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Component
  * @{
  */

/** @defgroup NCV26004 NCV26004
  * @{
  */

/** @defgroup NCV26004_Private_Types NCV26004 Private Types
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup NCV26004_Private_Defines NCV26004 Private Defines
  * @{
  */

/* Default Organizationally Unique Identifier value for NCV26004 PHY ID0 register */
#ifndef NCV26004_PHYID0_OUI
#define NCV26004_PHYID0_OUI     ((uint16_t)0x180FU)
#endif

#define NCV26004_MAX_DEV_ADDR   ((uint32_t)31U)
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup NCV26004_Private_Functions NCV26004 Private Functions
  * @{
  */

/**
  * @brief  Register IO functions to component object
  * @param  pObj: device object  of NCV26004Object_t.
  * @param  ioctx: holds device IO functions.
  * @retval NCV26004_STATUS_OK  if OK
  *         NCV26004_STATUS_ERROR if missing mandatory function
  */
int32_t NCV26004_RegisterBusIO (ncv26004_Object_t *pObj, ncv26004_IOCtx_t *ioctx)
{
  if (pObj == NULL || ioctx->Init == NULL || ioctx->ReadReg == NULL || ioctx->WriteReg == NULL || ioctx->GetTick == NULL)
  {
    return NCV26004_STATUS_ERROR;
  }

  pObj->IO.Init = ioctx->Init;
  pObj->IO.DeInit = ioctx->DeInit;
  pObj->IO.ReadReg = ioctx->ReadReg;
  pObj->IO.WriteReg = ioctx->WriteReg;

  return NCV26004_STATUS_OK;
}

/**
  * @brief  Initializes the NCV26004 component.
  * @param  pObj  NCV26004 object
  * @retval NCV26004_STATUS_OK  if OK
  *         NCV26004_STATUS_ERROR if missing mandatory function
  *         NCV26004_STATUS_ADDRESS_ERROR if cannot find device address
  *         NCV26004_STATUS_READ_ERROR if cannot read register
  */
int32_t NCV26004_Init(ncv26004_Object_t *pObj)
{
   uint32_t regvalue = 0, addr = 0;
   int32_t status = NCV26004_STATUS_OK;

   if (pObj == NULL)
   {
     return NCV26004_STATUS_ERROR;
   }

   if(pObj->Is_Initialized == 0)
   {
     if(pObj->IO.Init != 0)
     {
       /* GPIO and Clocks initialization */
       pObj->IO.Init();
     }

     /* for later check */
     pObj->DevAddr = NCV26004_MAX_DEV_ADDR + 1;

     /* Get the device address from special mode register */
     for(addr = 0; addr <= NCV26004_MAX_DEV_ADDR; addr ++)
     {
       if(pObj->IO.ReadReg(addr, NCV26004_PHYID0, &regvalue) < 0)
       {
         status = NCV26004_STATUS_READ_ERROR;
         /* Can't read from this device address
            continue with next address */
         continue;
       }

       if(regvalue == NCV26004_PHYID0_OUI)
       {
         pObj->DevAddr = addr;
         status = NCV26004_STATUS_OK;
         break;
       }
     }

     if(pObj->DevAddr > NCV26004_MAX_DEV_ADDR)
     {
       status = NCV26004_STATUS_ADDRESS_ERROR;
     }
   }

   if(status == NCV26004_STATUS_OK)
   {
     pObj->Is_Initialized = 1;
   }

   return status;
 }

/**
  * @brief  De-Initialize the ncv26004 and it's hardware resources
  * @param  pObj: device object NCV26004_Object_t.
  * @retval NCV26004_STATUS_OK  if OK
  *         NCV26004_STATUS_ERROR if missing mandatory function
  */
int32_t NCV26004_DeInit(ncv26004_Object_t *pObj)
{
  if (pObj == NULL)
  {
    return NCV26004_STATUS_ERROR;
  }

  if(pObj->Is_Initialized)
  {
    if(pObj->IO.DeInit != 0)
    {
      if(pObj->IO.DeInit() < 0)
      {
        return NCV26004_STATUS_ERROR;
      }
    }

    pObj->Is_Initialized = 0;
  }

  return NCV26004_STATUS_OK;
}

/**
  * @brief  Set the link state of NCV26004 device.
  * @param  pObj: Pointer to device object.
  * @param  LinkState: link state can be one of the following
  *         NCV26004_STATUS_FULLDUPLEX
  *         NCV26004_STATUS_HALFDUPLEX
  * @retval NCV26004_STATUS_OK  if OK
  *         NCV26004_STATUS_ERROR  if parameter error
  *         NCV26004_STATUS_READ_ERROR if cannot read register
  *         NCV26004_STATUS_WRITE_ERROR if cannot write to register
  */
int32_t NCV26004_SetLinkState(ncv26004_Object_t *pObj, uint32_t LinkState)
{
  uint32_t pmdctlvalue = 0;
  int32_t status = NCV26004_STATUS_OK;

  if (pObj == NULL)
  {
    return NCV26004_STATUS_ERROR;
  }

  if(pObj->IO.ReadReg(pObj->DevAddr, NCV26004_PMDCTL, &pmdctlvalue) >= 0)
  {
    /* Disable link config duplex */
    pmdctlvalue &= ~(NCV26004_PMDCTL_FDCAP | NCV26004_PMDCTL_HDCAP);

    if(LinkState == NCV26004_STATUS_FULLDUPLEX)
    {
      pmdctlvalue |= NCV26004_PMDCTL_FDCAP;
    }
    else if (LinkState == NCV26004_STATUS_HALFDUPLEX)
    {
      pmdctlvalue |= NCV26004_PMDCTL_HDCAP;
    }
    else
    {
      /* Wrong link status parameter */
      status = NCV26004_STATUS_ERROR;
    }
  }
  else
  {
    status = NCV26004_STATUS_READ_ERROR;
  }

  if(status == NCV26004_STATUS_OK)
  {
    /* Apply configuration */
    if(pObj->IO.WriteReg(pObj->DevAddr, NCV26004_PMDCTL, pmdctlvalue) < 0)
    {
      status = NCV26004_STATUS_WRITE_ERROR;
    }
  }

  return status;
}

/**
  * @brief  Get the link state of NCV26004 device.
  * @param  pObj: Pointer to device object.
  * @retval NCV26004_STATUS_HALFDUPLEX
  *         NCV26004_STATUS_FULLDUPLEX
  *         NCV26004_STATUS_READ_ERROR if cannot read register
  */
int32_t NCV26004_GetLinkState(ncv26004_Object_t *pObj)
{
  uint32_t readval = 0;

  if (pObj == NULL)
  {
    return NCV26004_STATUS_ERROR;
  }

  if(pObj->IO.ReadReg(pObj->DevAddr, NCV26004_PMDCTL, &readval) < 0)
  {
    return NCV26004_STATUS_READ_ERROR;
  }

  if((readval & NCV26004_PMDCTL_HDCAP) == NCV26004_PMDCTL_HDCAP)
  {
    return NCV26004_STATUS_HALFDUPLEX;
  }
  else
  {
    return NCV26004_STATUS_FULLDUPLEX;
  }

}

/**
  * @brief  Enable loopback mode.
  * @param  pObj: Pointer to device object.
  * @retval NCV26004_STATUS_OK  if OK
  *         NCV26004_STATUS_READ_ERROR if cannot read register
  *         NCV26004_STATUS_WRITE_ERROR if cannot write to register
  */
int32_t NCV26004_EnableLoopbackMode(ncv26004_Object_t *pObj)
{
  uint32_t readval = 0;
  int32_t status = NCV26004_STATUS_OK;

  if (pObj == NULL)
  {
    return NCV26004_STATUS_ERROR;
  }

  if(pObj->IO.ReadReg(pObj->DevAddr, NCV26004_MIIMCTL, &readval) >= 0)
  {
    readval |= NCV26004_MIIMCTL_LOOPBACK;

    /* Apply configuration */
    if(pObj->IO.WriteReg(pObj->DevAddr, NCV26004_MIIMCTL, readval) < 0)
    {
      status = NCV26004_STATUS_WRITE_ERROR;
    }
  }
  else
  {
    status = NCV26004_STATUS_READ_ERROR;
  }

  return status;
}

/**
  * @brief  Disable loopback mode.
  * @param  pObj: Pointer to device object.
  * @retval NCV26004_STATUS_OK  if OK
  *         NCV26004_STATUS_READ_ERROR if cannot read register
  *         NCV26004_STATUS_WRITE_ERROR if cannot write to register
  */
int32_t NCV26004_DisableLoopbackMode(ncv26004_Object_t *pObj)
{
  uint32_t readval = 0;
  int32_t status = NCV26004_STATUS_OK;

  if (pObj == NULL)
  {
    return NCV26004_STATUS_ERROR;
  }

  if(pObj->IO.ReadReg(pObj->DevAddr, NCV26004_MIIMCTL, &readval) >= 0)
  {
    readval &= ~NCV26004_MIIMCTL_LOOPBACK;

    /* Apply configuration */
    if(pObj->IO.WriteReg(pObj->DevAddr, NCV26004_MIIMCTL, readval) < 0)
    {
      status =  NCV26004_STATUS_WRITE_ERROR;
    }
  }
  else
  {
    status = NCV26004_STATUS_READ_ERROR;
  }

  return status;
}

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
