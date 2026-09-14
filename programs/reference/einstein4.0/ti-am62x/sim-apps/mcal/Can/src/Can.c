/*
*
* Copyright (c) 2024 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
 *  \file     Can.c
 *
 *  \brief    This file contains CAN MCAL driver implementation.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "string.h"

#include "Can.h"
#include "Can_Priv.h"

/*
 * Design: MCAL-5911
 */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

const struct Can_ConfigType_s CanConfigSet;

/*
 * Design: MCAL-5959,MCAL-5923,MCAL-6033,MCAL-5938,MCAL-5933,MCAL-6074,MCAL-6138
 */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
#if (CAN_VERSION_INFO_API == STD_ON)
/*******************************************************************************
 * Can_GetVersionInfo
 ******************************************************************************/
/*! \brief      This function will return the version for this module
 *
 *  \param[in]  None
 *
 *  \param[out]    Std_VersionInfoType VersionInfo - the structure that will
 *                  contain version info after fxn call.
 *
 *  \context    App
 ******************************************************************************/
/*
 * Design: MCAL-6084
 */
FUNC(void, CAN_CODE) Can_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_APPL_DATA) VersionInfo)
{

}
#endif

/*******************************************************************************
 * Can_DisableControllerInterrupts
 ******************************************************************************/
/*! \brief      This function will Disable the interrupts for the Controller
 * desired.
 *              Basically it will Disable the CAN interrupts(reset bit 1 in CTL
 * reg(IE0=0)).
 *
 *
 *  \param[in]  uint8 Controller - CAN Controller Id
 *
 *  \context
 ******************************************************************************/
/*
 * Design: MCAL-6153,MCAL-6150,MCAL-5989,MCAL-6002
 */
FUNC(void, CAN_CODE) Can_DisableControllerInterrupts(
    uint8 Controller)
{

}

/*******************************************************************************
 * Can_EnableControllerInterrupts
 ******************************************************************************/
/*! \brief      This function will Enable the interrupts for the Controller
 *              desired. It will restore the interrupts
 *              that were defined in the configuration. Basically it will enable
 *              the CAN interrupts.
 *
 *  \param[in]  uint8 Controller - CAN Controller Id
 *
 *  \context
 ******************************************************************************/
/*
 * Design: MCAL-6068,MCAL-5948,MCAL-5919,MCAL-6030
 */
FUNC(void, CAN_CODE) Can_EnableControllerInterrupts(
    uint8 Controller)
{

}

#if (STD_ON == CAN_SET_BAUDRATE_API)
/*******************************************************************************
 * Can_SetBaudrate
 ******************************************************************************/
/*! \brief      This service shall set the baudrate of the CAN controller.
 *
 *  \param[in]  uint8 Controller -  The controller for which the Baud is to be
 *              changed
 *              BaudRateConfigID -  references a baud rate configuration by ID
 *
 *  \return     Std_ReturnType -  E_OK  - Service request accepted, setting
 *                                           of (new) baud rate started
 *
 *                                E_OK  - Service request not accepted
 *
 *  \context
 ******************************************************************************/
/*
 * Design: MCAL-6174,MCAL-6090,MCAL-5956,MCAL-6162,MCAL-5960,MCAL-5984
 */
FUNC(Std_ReturnType, CAN_CODE) Can_SetBaudrate(
    uint8 Controller, uint16 BaudRateConfigID)
{
    Std_ReturnType        status = E_OK;
    return status;
}
#endif

/*
 * Design: MCAL-6058,MCAL-6103,MCAL-6141,MCAL-6121
 */
FUNC(Std_ReturnType, CAN_CODE) Can_GetControllerErrorState(uint8 ControllerId,
    Can_ErrorStateType* ErrorStatePtr)
{
    Std_ReturnType    	  retVal = (Std_ReturnType) E_OK;
    return retVal;
}

/*******************************************************************************
 * Can_MainFunction_Write
 ******************************************************************************/
/*! \brief      This function performs the polling of TX confirmation and TX
 * cancellation confirmation
 *              when CAN_TX_PROCESSING is set to POLLING.
 *
 *  \param[in]  void
 *
 *  \context
 ******************************************************************************/
/*
 * Design: MCAL-5911,MCAL-6085,MCAL-6107,MCAL-5942,MCAL-6021
 */
FUNC(void, CAN_CODE) Can_MainFunction_Write(void)
{

}

/*******************************************************************************
 * Can_MainFunction_Read
 ******************************************************************************/
/*! \brief      This function performs the polling of CAN controller mode
 * transitions
 *
 *  \param[in]  void
 *
 *  \context
 ******************************************************************************/
/*
 * Design: MCAL-6013,MCAL-5961,MCAL-5964,MCAL-5941
 */
FUNC(void, CAN_CODE) Can_MainFunction_Read(void)
{

}

#if (CAN_LOOPBACK_ENABLE == STD_ON)
/*******************************************************************************
 * Can_TestLoopBackModeEnable
 ******************************************************************************/
/*! \brief      This function enables the Loopback
 *
 *  \param[in]  uint8 Controller for which loopback needs to be enabled
 *              uint8 Mode 0 - Enable Digital mode. 1 - Enable Analog mode.
 *
 *  \context
 ******************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
    Can_TestLoopBackModeEnable(uint8 Controller, uint8 Mode)
{

}

/*******************************************************************************
 * Can_TestLoopBackModeDisable
 ******************************************************************************/
/*! \brief      This function Disable the Loopback
 *
 *  \param[in]  uint8 Controller for which loopback needs to be Disabled
 *              uint8 Mode 0 - Disable Digital mode. 1 - Disable Analog mode.
 *
 *  \context
 ******************************************************************************/
FUNC(Std_ReturnType, CAN_CODE)
    Can_TestLoopBackModeDisable(uint8 Controller, uint8 Mode)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal;
    return (retVal);
}
#endif

/*******************************************************************************
 * Can_RegisterReadback
 ******************************************************************************/
/*! \brief      This is the function for checking the configuration registers.
 *              This APi canbe called by higher layers to check if configuration
 *              is correct.
 *
 *  \param[in]  uint8 controller - 2 controllers are there
 *
 *  \context
 ******************************************************************************/
/*
 * Design: MCAL-6028,MCAL-6088
 */
#if (STD_ON == CAN_REGISTER_READBACK_API)
Std_ReturnType Can_RegisterReadback(
    VAR(uint8, AUTOMATIC)Controller,
    P2VAR(Can_RegisterReadbackType, AUTOMATIC, CAN_APPL_DATA) RegRbPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal;
    retVal = (Std_ReturnType) E_OK;
    return (retVal);
}
#endif

/*******************************************************************************
 * Can_EnableIntr
 ******************************************************************************/
/*! \brief      This function Enables CRC,BIT-0,BIT-1,ACK,FORM,STUFF,TOO Errors.
 *
 *  \param[in]  uint8 Controller - Controller for which errors has to be enabled.
 *              uint8 CanErrVar  - CAN Error Type.
 *  \context
 ******************************************************************************/
#if (STD_ON == CAN_SAFETY_DIAGNOSTIC)
/*
 * Design: MCAL-6126,MCAL-5909,MCAL-5917,MCAL-5922,MCAL-6052,MCAL-6091
 */
Std_ReturnType Can_EnableIntr(
    VAR(uint8, AUTOMATIC)Controller,
    VAR(uint8, AUTOMATIC) CanErrVar)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal;
    retVal = (Std_ReturnType) E_OK;
    return retVal;
}

/*******************************************************************************
 * Can_DisableIntr
 ******************************************************************************/
/*! \brief      This function Disables Interrupt for  CRC,BIT-0,BIT-1,ACK,
 *              FORM,STUFF,TOO Errors.
 *
 *  \param[in]  uint8 Controller - Controller for which interrupt errors has
 *                                 to be Disabled.
 *              uint8 CanErrVar  - CAN Error Type.
 *  \context
 ******************************************************************************/
/*
 * Design: MCAL-6126,MCAL-5909,MCAL-5917,MCAL-5922,MCAL-6052,MCAL-6091
 */
Std_ReturnType Can_DisableIntr(
    VAR(uint8, AUTOMATIC)Controller,
    VAR(uint8, AUTOMATIC) CanErrVar)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal;
    retVal = (Std_ReturnType) E_OK;
    return retVal;
}

/*******************************************************************************
 * Can_GetIntrStatus
 ******************************************************************************/
/*! \brief      This function gets the interrupt status for  CRC,BIT-0,BIT-1,
 *              ACK,FORM,STUFF,TOO Errors.
 *
 *  \param[in]  uint8 Controller - Controller for which it reads the interrupt
 *                                 error status.
 *  \context
 ******************************************************************************/
/*
 * Design: MCAL-6126,MCAL-5909,MCAL-5917,MCAL-5922,MCAL-6052,MCAL-6091
 */
Can_IrqStatusType Can_GetIntrStatus(
    VAR(uint8, AUTOMATIC)Controller)
{
    Can_IrqStatusType  canIrqstatus = CAN_IRQ_NO_INTR_EVENT;
    return canIrqstatus;
}

/*******************************************************************************
 * Can_ClearIntrStatus
 ******************************************************************************/
/*! \brief      This function clears the interrupt status for  CRC,BIT-0,BIT-1,
 *              ACK,FORM,STUFF,TOO Errors.
 *
 *  \param[in]  uint8 Controller - Controller for which it clears the interrupt
 *                                 error status.
 *  \context
 ******************************************************************************/
/*
 * Design: MCAL-6126,MCAL-5909,MCAL-5917,MCAL-5922,MCAL-6052,MCAL-6091
 */
Std_ReturnType Can_ClearIntrStatus(
    VAR(uint8, AUTOMATIC)Controller)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal;
    retVal = (Std_ReturnType) E_OK;
    return retVal;
}
#endif /* (STD_ON == CAN_SAFETY_DIAGNOSTIC) */

/*
 * Design: MCAL-6055,MCAL-6124,MCAL-5958,MCAL-6151,MCAL-5996
 */
/**
 * \brief This function de-initializes the module
 */
FUNC(void, CAN_CODE) Can_DeInit(void)
{

}

/*******************************************************************************
 * INTERRUPT SERVICE ROUTINES
 ******************************************************************************/
#define CAN_START_SEC_ISR_CODE
#include "Can_MemMap.h"

FUNC(void, CAN_CODE) Can_IntISR_Fun(Can_ControllerInstance CanInstanceID)
{

}

#define CAN_STOP_SEC_ISR_CODE
#include "Can_MemMap.h"

/*******************************************************************************
 *  End of File: Can.c
 ******************************************************************************/
