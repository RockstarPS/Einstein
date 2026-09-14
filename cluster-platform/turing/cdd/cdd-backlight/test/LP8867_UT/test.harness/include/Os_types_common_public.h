/**
*   @file    Os_types_common_public.h
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

#ifndef OS_TYPES_COMMON_PUBLIC_H_
#define OS_TYPES_COMMON_PUBLIC_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include "Os_types_basic.h"

#define OSFALSE         (0U)
#define OSTRUE          (1U)

/*
 *  types required by the Autosar API
 */

typedef OSBYTE OSAPPLICATIONTYPE;
typedef OSBYTE OSAPPLICATIONMASKTYPE;

/* avoid collision with MCAL */
#ifndef STATUSTYPEDEFINED
/* prescribed by OSEK/VDX */
#define STATUSTYPEDEFINED       /* required by OSEK/VDX Binding Specification */

#define E_OK                      ( (StatusType) 0 )   /* No error, successful completion  */
typedef unsigned char StatusType;       /* OSEK: Status type             */

#endif /* !defined(STATUSTYPEDEFINED) */


typedef OSWORD OSObjectType;            /* bits [15] - Core Id, bits [14..11] - ObjType, bits [10..0] - ObjId, */

typedef OSObjectType TaskType;          /* used in task, events api ... */

typedef OSDWORD TickType;               /* Type for timers ticks - use by counter, alarm, schedule table alarm */
typedef TickType  *TickRefType;         /* OSEK: Reference to counter value - use by counter and alarm */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_TYPES_COMMON_PUBLIC_H_ */

/** @} */

