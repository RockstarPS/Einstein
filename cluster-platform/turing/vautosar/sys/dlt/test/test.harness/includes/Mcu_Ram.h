/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu_Ram.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the extern declarations of global RAM variables of MCU  */
/* Driver                                                                     */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        F1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  28-Sep-2012 : Initial Version
 *
 * V1.0.1: 12-Aug-2013 : As per CR 225, Copyright information is modified.
 *
 * V1.5.0: 15-Sep-2013 : As per CR 245, Following changes are made
 *                       1. Mcu_GpSeqSetting is added under
 *                          MCU_LOW_POWER_SEQUENCER precompile.
 *                       2. Memory class of pointer variable is changed from
 *                          MCU_CONST to MCU_VAR.
 *                       3. Copyright information is modified.
 * V1.5.1: 17-Dec-2013 : As per CR 342, Mcu_GucResetFlag and
 *                        Mcu_GblSeqDriverStatus is added.
 *
 * V1.5.2: 30-Jul-2014: As per Mantis #21787 the style of Mcu_GucResetFlag
 *                      is made similar to Mcu_Ram.c.
 *
 * V1.5.3: 02-Sep-2014: As per CR 597 Mcu_GblWakeUpPreparation is added.
 * V1.6.0: 19-Mar-2016: Following changes are made:
 *                      1. As per JIRA ARDAAAC-467, ARDAAAA-543, ARDAAAB-3463,
 *                         extern declaration for Mcu_32BitRegMirrorAddress,
 *                         Mcu_16BitRegMirrorAddress, Mcu_8BitRegMirrorAddress
 *                         is added.
 *                      2. Copyright information is updated.
 *                      3. As per JIRA ARDAAAC-466, ARDAAAA-526, ARDAAAB-3353,
 *                         preprocessing directive '#include MemMap.h' is
 *                         included.
 *                      4. As per JIRA ARDAAAC-454, ARDAAAA-529 and
 *                         ARDAAAB-3265, extern declaration for
 *                         'Mcu_GblLviLsRegVcc' has been added.
 * V1.6.1: 20-Sep-2016: Following changes are made:
 *                      1. As per JIRA ARDAAAA-1103, ARDAAAC-975 Memory section
 *                         is updated for Mcu_8BitRegMirrorAddress,
 *                         Mcu_16BitRegMirrorAddress, Mcu_32BitRegMirrorAddress.
 *                      2. As part of JIRA ARDAAAC-805, ARDAAAA-889 and
 *                         ARDAAAB-3677,
 *                         a) Wherever <INIT_POLICY> was missing for memory
 *                            sections, it is added.
 *                         b) <INIT_POLICY> of memory sections for Autosar
 *                            Higher version has been changed from 'NOINIT' to
 *                            'NO_INIT'.
 *                      3. As part of JIRA ARDAAAB-3904, MISRA C Rule violation
 *                         message added -(4:0828).
 * V1.6.2: 13-Feb-2017: Following changes are made:
 *                      1. As part of JIRA ARDAABL-750, Added trace for
 *                         unmapped requirements.
 *                      2. Copyright information is updated.
 */
/******************************************************************************/
#ifndef MCU_RAM_H
#define MCU_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*Implements MCU108 */
#include "Mcu_RegWrite.h"

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/* AUTOSAR specification version information */
#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)

#define MCU_RAM_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_RAM_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION
#define MCU_RAM_AR_RELEASE_REVISION_VERSION    \
                                               MCU_AR_RELEASE_REVISION_VERSION

#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
/* AUTOSAR specification version information */
#define MCU_RAM_AR_MAJOR_VERSION  MCU_AR_MAJOR_VERSION_VALUE
#define MCU_RAM_AR_MINOR_VERSION  MCU_AR_MINOR_VERSION_VALUE
#define MCU_RAM_AR_PATCH_VERSION  MCU_AR_PATCH_VERSION_VALUE
#endif /*END of MCU_AR_VERSION*/


/* File version information */
#define MCU_RAM_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION
#define MCU_RAM_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0828) More than 8 levels of nested conditional          */
/*                 inclusion - program does not conform strictly to ISO:C90.  */
/* Rule          : REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : The number of pre-processor conditions depend on the       */
/*                 configuration. Also, the pre-processor conditional         */
/*                 statement that are used are not nested.                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0828)-1 and                           */
/*                 END Msg(4:0828)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif

/* Global variable to store the config pointer */
extern P2CONST(Mcu_ConfigType, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpConfigPtr;

/* Global pointer variable for MCU Clock Setting configuration */
extern P2CONST(Mcu_ClockSetting, MCU_VAR, MCU_CONFIG_CONST)
                                                             Mcu_GpClockSetting;

/* Global pointer variable for MCU CKSC clock Setting configuration */
extern P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST)
                                                             Mcu_GpCkscSetting;

#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
extern P2CONST(Mcu_SequencerSetting, MCU_VAR, MCU_CONFIG_CONST)
                                                      Mcu_GpSeqSetting;
#endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) */

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif
/* MISRA Violation: START Msg(4:0828)-1 */
#if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE )

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_START_SEC_VAR_NO_INIT_8
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_START_SEC_VAR_NOINIT_8BIT
#endif
#include "MemMap.h"

/* Global array to store 8 bit Mirror data */
extern VAR(Mcu_8BitRegMirror, MCU_VAR) Mcu_8BitRegMirrorAddress;

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_STOP_SEC_VAR_NO_INIT_8
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_STOP_SEC_VAR_NOINIT_8BIT
#endif
#include "MemMap.h"

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_START_SEC_VAR_NO_INIT_16
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_START_SEC_VAR_NOINIT_16BIT
#endif
#include "MemMap.h"

/* Global array to store 16 bit Mirror data */
extern VAR(Mcu_16BitRegMirror, MCU_VAR) Mcu_16BitRegMirrorAddress;

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_STOP_SEC_VAR_NO_INIT_16
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_STOP_SEC_VAR_NOINIT_16BIT
#endif
#include "MemMap.h"

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_START_SEC_VAR_NO_INIT_32
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_START_SEC_VAR_NOINIT_32BIT
#endif
#include "MemMap.h"

/* Global array to store 32 bit Mirror data */
extern VAR(Mcu_32BitRegMirror, MCU_VAR) Mcu_32BitRegMirrorAddress;

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_STOP_SEC_VAR_NO_INIT_32
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_STOP_SEC_VAR_NOINIT_32BIT
#endif
#include "MemMap.h"

#endif /* (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE ) */
/* END Msg(4:0828)-1 */
#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_START_SEC_VAR_INIT_BOOLEAN
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_START_SEC_VAR_1BIT
#endif
#include "MemMap.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Global variable to store Initialization status of MCU Driver */
extern VAR(boolean, MCU_INIT_DATA) Mcu_GblDriverStatus;
/* Global variable to check WakeUp status of MCU Driver */
extern VAR(boolean, MCU_INIT_DATA) Mcu_GblWakeUpPreparation;
#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
/* Global variable to store Initialization status of MCU Driver */
extern VAR(boolean, MCU_INIT_DATA) Mcu_GblSeqDriverStatus;
#endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) */
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

extern VAR(boolean, MCU_INIT_DATA) Mcu_GucResetFlag;
/* Global variable to check WakeUp status of MCU Driver */
extern VAR(volatile boolean, MCU_INIT_DATA) Mcu_GblLviLsRegVcc;

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_STOP_SEC_VAR_INIT_BOOLEAN
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_STOP_SEC_VAR_1BIT
#endif
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_RAM_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
