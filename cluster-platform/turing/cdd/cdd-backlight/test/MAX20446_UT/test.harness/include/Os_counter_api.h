/**
*   @file    Os_counter_api.h
*   @version 4.0.0
*
*   @brief   AUTOSAR OS - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup [OS]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : generic
*   Dependencies         : 
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : IMX8_MCAL_4_0_0_RTM_ASR_REL_4_2_REV_0002_20201231
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc. 
*   Copyright 2017 - 2020 NXP
*   NXP Confidential. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/*==================================================================================================
==================================================================================================*/

#ifndef OS_COUNTER_API_H
#define OS_COUNTER_API_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include "Os_counter_types.h"   /* for StatusType and counter specific types */

extern StatusType GetCounterValue (CounterType ctrId, TickRefType tickRef);

extern StatusType GetElapsedValue (CounterType ctrId, TickRefType valueRef, TickRefType tickRef);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_COUNTER_API_H */

/** @} */
