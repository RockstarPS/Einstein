/*
*
* Copyright (C) 2024 Texas Instruments Incorporated
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
 *  \file     Pwm.c
 *
 *  \brief    This file includes services for initialization and control of the
 *            PWM unit (pulse width modulation).
 *            The PWM module generates pulses with variable pulse width.It
 *            allows the selection of the duty cycle and the signal period time.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "string.h"
/*
 * Design: MCAL-6824,MCAL-7572
 */
#include "Pwm.h"
#include "SchM_Pwm.h"
#if (STD_ON == PWM_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#include "Pwm_Irq.h"
#include "Pwm_Priv.h"


/* There are static inline functions in hw_types.h file. Map them as well */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
#include "hw_include/hw_types.h"
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* AUTOSAR version information check has to match definition in header file */
#if ((PWM_AR_RELEASE_MAJOR_VERSION != (4U)) || \
    (PWM_AR_RELEASE_MINOR_VERSION != (3U)) ||  \
    (PWM_AR_RELEASE_REVISION_VERSION != (1U)))
    #error "Pwm: AUTOSAR Version Numbers of Pwm are different!!"
#endif

/* AUTOSAR SW version information check has to match definition in header file */
#if ((PWM_SW_MAJOR_VERSION != (10U)) || \
    (PWM_SW_MINOR_VERSION != (2U)) ||  \
    (PWM_SW_PATCH_VERSION != (1U)))
    #error "Pwm: Software Version Numbers are inconsistent!!"
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#define PWM_START_SEC_VAR_INIT_32
#include "Pwm_MemMap.h"
/** \brief Pwm driver init status */
volatile VAR(uint8, PWM_VAR_INIT)
    Pwm_DrvStatus = PWM_STATUS_UNINIT;

#define PWM_STOP_SEC_VAR_INIT_32
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Pwm_MemMap.h"
/** \brief Pwm driver interrupt status flag*/
volatile VAR(Pwm_OutputStateType, PWM_VAR_NO_INIT)
    Pwm_Intrflag[PWM_MAX_NUM_CHANNELS];
/** \brief PWM driver object. */

    VAR(Pwm_ChObjType, PWM_VAR_NO_INIT) Pwm_ChObj[PWM_MAX_NUM_CHANNELS];
/* Pwm_ChObj is not static storage class, as this requires to be accessed by
    debug interface provided.  */
#define PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Pwm_MemMap.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/*
* Design: MCAL-6806,MCAL-6798,MCAL-6786,MCAL-6828,MCAL-6767,MCAL-6752,MCAL-6834,MCAL-6779,MCAL-6789,MCAL-6768,MCAL-7510,MCAL-7584
*/
/*
* Design: MCAL-7610,MCAL-7552,MCAL-7568,MCAL-7581,MCAL-7579,MCAL-7528,MCAL-7565,MCAL-7635,MCAL-7598,MCAL-7608,MCAL-7545,MCAL-7607
*/

/* Initializes PWM unit and sets default period and duty cycle values from
 * parameter ConfigPtr.
 */

FUNC(void, PWM_CODE) Pwm_Init(
                           P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_PBCFG) CfgPtr)
{

}

 /*
 * Design: MCAL-6890,MCAL-7600,MCAL-6875,MCAL-7559,MCAL-6789,MCAL-7598,MCAL-6840,MCAL-7637,MCAL-6827,MCAL-7634,MCAL-6870,MCAL-7632,MCAL-6805,MCAL-7606,MCAL-6891,MCAL-7595,MCAL-6886,MCAL-7609,MCAL-7583
 */

#if (STD_ON == PWM_DEINIT_API)
FUNC(void, PWM_CODE) Pwm_DeInit(void)
{
}
#endif /*(STD_ON == PWM_DEINIT_API)*/

#if (STD_ON == PWM_SET_DUTY_CYCLE_API)
/*  Sets parameter DutyCycle as new duty cycle for channel ChannelNumber.
 *  DutyCycle is a percentage of the period with 0x8000 being equivalent
 *  to 100%.
 */
 /*
 * Design: MCAL-6759,MCAL-7636,MCAL-6839,MCAL-7509,MCAL-6751,MCAL-7511,MCAL-6832,MCAL-7596,MCAL-6801,MCAL-7544,MCAL-6880,MCAL-7547,MCAL-6863,MCAL-7530,MCAL-6805,MCAL-7606,MCAL-6864,MCAL-7602,MCAL-6891,MCAL-7595,MCAL-6886,MCAL-7609,MCAL-6851,MCAL-7642,MCAL-6813,MCAL-7537,MCAL-7567,MCAL-7520,MCAL-7643
 */
FUNC(void, PWM_CODE) Pwm_SetDutyCycle(
    Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{
	
}

#endif /*(STD_ON == PWM_SET_DUTY_CYCLE_API)*/

#if (STD_ON == PWM_SET_PERIOD_AND_DUTY_API)
/*  Sets DutyCycle and Period of ChannelNumber. DutyCycle is a percentage of
 *  the period with 0x8000 being equivalent to 100%. */
 /*
  * Design: MCAL-6774,MCAL-7563,MCAL-6757,MCAL-7532,MCAL-6787,MCAL-7512,MCAL-6801,MCAL-7544,MCAL-6880,MCAL-7547,MCAL-6880,MCAL-7547,MCAL-6815,MCAL-7526,MCAL-6864,MCAL-7602,MCAL-6891,MCAL-7595,MCAL-6886,MCAL-7609,MCAL-6822,MCAL-7560,MCAL-6793,MCAL-7615,MCAL-6785,MCAL-7575,MCAL-6777,MCAL-7582
  */

FUNC(void, PWM_CODE) Pwm_SetPeriodAndDuty(
    Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle)
{
	
}

#endif /*(STD_ON == PWM_SET_PERIOD_AND_DUTY_API)*/

#if (STD_ON == PWM_SET_OUTPUT_TO_IDLE_API)
/* Sets output state immediately to idle level. */
 /*
 * Design: MCAL-6784,MCAL-7626,MCAL-6756,MCAL-7515,MCAL-6766,MCAL-7542,MCAL-6887,MCAL-7604,MCAL-6776MCAL-7546,MCAL-6818,MCAL-7641
 */
FUNC(void, PWM_CODE) Pwm_SetOutputToIdle(
    Pwm_ChannelType ChannelNumber)
{
	
}
#endif /*(STD_ON == PWM_SET_OUTPUT_TO_IDLE_API)*/


#if (STD_ON == PWM_GET_OUTPUT_STATE_API)
FUNC(Pwm_OutputStateType, PWM_CODE) Pwm_GetOutputState(
    Pwm_ChannelType ChannelNumber)
{
 /* Function not implmented due to hardware limitation
    Dummy Function*/
    
 return PWM_LOW;
}
#endif /*(STD_ON == PWM_GET_OUTPUT_STATE_API)*/


#if (STD_ON == PWM_NOTIFICATION_SUPPORTED)
/*
 * Design: MCAL-6807,MCAL-7539,MCAL-6848,MCAL-7627,MCAL-6830,MCAL-7594,MCAL-6780,MCAL-7517,MCAL-6882,MCAL-7521,MCAL-6805,MCAL-7606,MCAL-6864,MCAL-7602,MCAL-6891,MCAL-7595,MCAL-6886,MCAL-7609,MCAL-6773,MCAL-7619
 */
FUNC(void, PWM_CODE) Pwm_DisableNotification(
    Pwm_ChannelType ChannelNumber)
{
	
}
#endif /* #if (STD_ON == PWM_NOTIFICATION_SUPPORTED)*/

#if (STD_ON == PWM_NOTIFICATION_SUPPORTED)
    /* Enables notification for channel Channel. */
    /*
     * Design: MCAL-6800,MCAL-7586,MCAL-6889,MCAL-7554,MCAL-6865,MCAL-7593,MCAL-6765,MCAL-7624,MCAL-6882,MCAL-7521,MCAL-6805,MCAL-7606,MCAL-6864,MCAL-7602,MCAL-6891,MCAL-7595,MCAL-6886,MCAL-7609,MCAL-6823,MCAL-7525
     */
FUNC(void, PWM_CODE) Pwm_EnableNotification(
    Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification)
{
	
}
#endif

#if (STD_ON == PWM_REGISTER_READBACK_API)
/*
 * Design: MCAL-6852,MCAL-7590,MCAL-6871,MCAL-7540,MCAL-6846
 */
FUNC(Std_ReturnType, PWM_CODE) Pwm_RegisterReadback(
    Pwm_ChannelType PwmChannel,
    P2VAR(Pwm_RegisterReadbackType, AUTOMATIC, PWM_APPL_DATA) RegRbPtr)
{
    Std_ReturnType        retVal     = ((Std_ReturnType) E_NOT_OK);
    
    return (retVal);
}
#endif
/*
 * Design:MCAL-6812,MCAL-7573,MCAL-7548,MCAL-7640
 */
#if (STD_ON == PWM_VERSION_INFO_API)
FUNC(void, PWM_CODE) Pwm_GetVersionInfo(
            P2VAR(Std_VersionInfoType, AUTOMATIC, PWM_APPL_DATA) VersionInfoPtr)
{

}
#endif /* PWM_VERSION_INFO_API*/

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
