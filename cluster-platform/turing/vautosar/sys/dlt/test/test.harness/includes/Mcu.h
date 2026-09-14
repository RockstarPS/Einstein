/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu.h                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, MCU type definitions, structure data types and  */
/* API function prototypes of MCU Driver                                      */
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
 * V1.0.1:  07-Nov-2012 : As per SCR 038, Unused macros related to mode setting
 *                        and clock setting handles removed.
 *
 * V1.0.2:  29-Nov-2012 : As per SCR 045, Prototype of Mcu_Rram_Cyclic_Run API
 *                        is added.
 *
 * V1.1.0:  23-Jan-2013 : As per SCR 059, Following changes are made:
 *                        1. Low power sequencer operation related vendor
 *                           specific API's prototypes Mcu_SequencerInit,
 *                           Mcu_SequencerStart and Mcu_SequencerStop.
 *                        2. MCU_SEQUENCERINIT_SID, MCU_SEQUENCERSTART_SID
 *                           and MCU_SEQUENCERSTOP_SID API id's are added.
 *                        3. DET MCU_E_PARAM_SEQUENCER is added.
 *                        4. New vendor specific Api Mcu_CopyToSection prototype
 *                           is added.
 *                        5. Mcu_Intvec_CalcRange and Mcu_Code_CalcRange
 *                           function prototype added which are defined as part
 *                           of Mcu_RRamCopy_asm.850 file.
 *                        6. MCU_COPYTOSECTION_SID is added.
 *                        7. Software version macros are derived from
 *                           tool output macros.
 *
 * V1.2.0:  19-Mar-2013 : As per SCR 088, for mantis #7865 and #9586,
 *                        Mcu_CopyToSection is updated with new pre-compile
 *                        macro MCU_COPY_TO_SECTION_API.
 *
 * V1.2.1: 21-May-2013  : As per SCR 172, for Mantis #9023 , #9463 and #7377,
 *                        Mcu_PerformReset is updated with new pre-compile
 *                        parameter MCU_RESET_CALLOUT API.
 *
 * V1.4.0: 09-Jul-2013  : As per SCR 202, for Mantis 13138 the
 *                        Mcu_GetVersionInfo macro is corrected.
 *
 * V1.4.1: 12-Aug-2013 : As per CR 225, Copyright information is modified.
 *
 * V1.5.0: 15-Sep-2013 : As per CR 245 and mantis #12123, the following changes
 *                       are made:
 *                       1. Copyright information is modified.
 *                       2. Backslash('\') is removed from
 *                          the code.
 * V1.5.1: 23-Dec-2013 : As per CR 342, following changes are done
 *                       1.declaration Mcu_CbkNotification is removed.
 *                       2.declaration Mcu_SequencerDiCmpValueSet is added.
 *                       3.Service Id of Mcu_SequencerDiCmpValueSet API is
 *                         added.
 * V1.6.0: 26-Feb-2014 : As per CR 435, pre-compile option for MCU_RESET_CALLOUT
 *                       declaration is modified.
 * V1.6.1: 8-Sep-2014  : As per 597 Mcu_WakeUpFactor_Preparation is referenced.
 *
 * V1.6.2: 10-Oct-2014 : As per CR 637, following changes are done
 *                       1.MCU_E_INVALID_MODE macro is replaced to
 *                         MCU_E_INVALID_MODE_SEQUENCE.
 *                       2.MISRA C Rule Violations is updated.
 * V1.6.3: 23-Feb-2015 : As part of V4.01.06, Added justification for
 *                        Misra violations.
 * V1.6.4: 18-May-2015 : As per#26277, MCU_FEINT_ENTRY() and MCU_FEINT_LEAVE()
 *                       declarations are added to fix the issue with
 *                       FE interrupt handling.
 * V1.6.5: 10-Jun-2015 : Following changes are made:
 *                       1. As per mantis #20338, NULL_PTR checking and Det
 *                          error reporting is implemented in Mcu_GetVersionInfo
 *                          API.
 *                       2. As per mantis #21230, updated prototype declaration
 *                          of McuCopyToSection().
 *                       3. Missing MISRA Violation END Msg (4:3458)-2 is added.
 *                       4. Unused macro MCU_E_INVALID_CLK_SETTING is removed.
 * V1.6.6: 14-Oct-2015 : Corrected prototype declaration of Mcu_CopyToSection()
 * V1.7.0: 04-Mar-2016 : As per JIRA ARDAAAC-424 Following changes are made:
 *                       1. GetVersionInfo API  implemented as function.
 *                       2. Copyright information is updated.
 *                       3. Det.h is removed from include section.
 *                       4. As per JIRA ARDAAAC-467, ARDAAAA-543, ARDAAAB-3463,
 *                          MCU_CHECK_HW_CONSISTENCY_SID , DET Error Codes
 *                          MCU_E_PARAM_VALUE and extern call for
 *                          Mcu_CheckHWConsistency is added.
 * V1.7.1: 28-May-2016 : As part of JIRA ticket ARDAAAB-3653, MISRA C Rule
 *                       Violation Message (4:3458) is removed.
 * V1.7.2: 26-Sep-2016 : Following changes are made:
 *                       1. As part of JIRA ARDAAAB-3680, ARDAAAC-856 and
 *                          ARDAAAA-945, macros are updated to add integer
 *                          literals.
 *                       2. As part of JIRA ARDAAAC-805, ARDAAAA-889 and
 *                          ARDAAAB-3677, Memory section type has been changed
 *                          from 'DBTOC_DATA' to 'CONFIG_DATA'.
 * V1.7.3: 13-Feb-2017 :  Following changes are made:
 *                       1. As part of JIRA ARDAABL-750, Added trace for
 *                          unmapped requirements.
 *                       2. Copyright information is updated.
 */
/******************************************************************************/

#ifndef MCU_H
#define MCU_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* To publish the type Mcu_ConfigType */
/*Implements MCU031, EAAR_PN0034_NR_0001*/
/*Implements MCU215, MCU108 */
#include "Mcu_Types.h"
#include "Mcu_RegWrite.h"
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
/* Only in case of DET enabled, Debug variables will be available externally */
#include "Mcu_Debug.h"
#endif
#endif

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/* Implements MCU037 */
#define MCU_VENDOR_ID  MCU_VENDOR_ID_VALUE
#define MCU_MODULE_ID  MCU_MODULE_ID_VALUE
/* Implements MCU_ESDD_UD_013 */
#define MCU_INSTANCE_ID  MCU_INSTANCE_ID_VALUE

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)

/* AUTOSAR release version information */
#define MCU_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_AR_RELEASE_MINOR_VERSION    0U
#define MCU_AR_RELEASE_REVISION_VERSION 3U

#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)

/* AUTOSAR specification version information */
#define MCU_AR_MAJOR_VERSION       2U
#define MCU_AR_MINOR_VERSION       5U
#define MCU_AR_PATCH_VERSION       0U

#endif

/* Module Software version information */
#define MCU_SW_MAJOR_VERSION       MCU_SW_MAJOR_VERSION_VALUE
#define MCU_SW_MINOR_VERSION       MCU_SW_MINOR_VERSION_VALUE
#define MCU_SW_PATCH_VERSION       MCU_SW_PATCH_VERSION_VALUE
/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Service IDs */
/* Service Id of Mcu_Init API */
#define MCU_INIT_SID                        (uint8)0x00U
/* Service Id of Mcu_InitRamSection API */
#define MCU_INITRAMSECTION_SID              (uint8)0x01U
/* Service Id of Mcu_InitClock API */
#define MCU_INITCLOCK_SID                   (uint8)0x02U
/* Service Id of Mcu_DistributePllClock API */
#define MCU_DISTRIBUTEPLLCLOCK_SID          (uint8)0x03U
/* Service Id of Mcu_GetPllStatus API */
#define MCU_GETPLLSTATUS_SID                (uint8)0x04U
/* Service Id of Mcu_GetResetReason API */
#define MCU_GETRESETREASON_SID              (uint8)0x05U
/* Service Id of Mcu_GetResetRawValue API */
#define MCU_GETRESETRAWVAULE_SID            (uint8)0x06U
/* Service Id of Mcu_PerformReset API */
#define MCU_PERFORMRESET_SID                (uint8)0x07U
/* Service Id of Mcu_SetMode API */
#define MCU_SETMODE_SID                     (uint8)0x08U
/* Service Id of Mcu_GetVersionInfo API */
#define MCU_GETVERSIONINFO_SID              (uint8)0x09U

/* Service Id of Mcu_GetRamState API */
#define MCU_GETRAMSTATE_SID                 (uint8)0x0AU

/* Service Id of Mcu_SequencerInit API */
#define MCU_SEQUENCERINIT_SID               (uint8)0x0BU

/* Service Id of Mcu_SequencerStart API */
#define MCU_SEQUENCERSTART_SID              (uint8)0x0CU

/* Service Id of Mcu_SequencerStop API */
#define MCU_SEQUENCERSTOP_SID                (uint8)0x0DU

/* Service Id of Mcu_CopyToSection API */
#define MCU_COPYTOSECTION_SID                (uint8)0x0EU

/* Service Id of Mcu_SequencerDiCmpValueSet API */
#define MCU_SEQUENCERDICMPVALUESET_SID       (uint8)0x0FU

/* Service Id of Mcu_CheckHWConsistency */
#define MCU_CHECK_HW_CONSISTENCY_SID         (uint8)0x10U


/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/

/* DET Code to report NULL pointer passed to Mcu_Init API */
/*Implements MCU018*/
#define MCU_E_PARAM_CONFIG            (uint8)0x0AU

/* DET Code for invalid Clock Setting */
/*Implements MCU019*/
#define MCU_E_PARAM_CLOCK             (uint8)0x0BU

/* DET Code for invalid Operation Mode */
 /*Implements MCU020*/
#define MCU_E_PARAM_MODE              (uint8)0x0CU

/* DET Code for invalid RAM Section handle */
/*Implements MCU_021*/
#define MCU_E_PARAM_RAMSECTION        (uint8)0x0DU

/* DET Code to report that PLL Clock is not locked */
/*Implements MCU122*/
#define MCU_E_PLL_NOT_LOCKED          (uint8)0x0EU

/* DET code to report uninitialized state */
/*Implements MCU125*/
#define MCU_E_UNINIT                  (uint8)0x0FU

/* DET code to report invalid database */
#define MCU_E_INVALID_DATABASE        (uint8)0xEDU

/* DET code to report invalid mode sequence call */
#define MCU_E_INVALID_MODE_SEQUENCE   (uint8)0xEFU

/* DET code to report invalid Sequencer setting */
#define MCU_E_PARAM_SEQUENCER         (uint8)0xFAU

/* DET code to report NULL_PTR when passed as a parameter to GetVersionInfo */
#define MCU_E_PARAM_POINTER          (uint8)0x10U

/* DET code to report CheckHWConsistency call with invalid arguments */
#define MCU_E_PARAM_VALUE            (uint8)0xFBU

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

extern void MCU_FEINT_ENTRY(void);
extern void MCU_FEINT_LEAVE(void);

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_Init
(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr);

extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitRamSection
(Mcu_RamSectionType RamSection);

#if (MCU_INIT_CLOCK == STD_ON)

extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitClock
(Mcu_ClockType ClockSetting);

#endif

#if (MCU_NO_PLL == STD_OFF)

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_DistributePllClock (void);

#endif
/*Implements MCU230*/
extern FUNC(Mcu_PllStatusType, MCU_PUBLIC_CODE) Mcu_GetPllStatus (void);

extern FUNC(Mcu_ResetType, MCU_PUBLIC_CODE) Mcu_GetResetReason (void);

extern FUNC(Mcu_RawResetType, MCU_PUBLIC_CODE) Mcu_GetResetRawValue (void);

#if (MCU_PERFORM_RESET_API == STD_ON)
extern FUNC(void, MCU_PUBLIC_CODE) Mcu_PerformReset (void);
#endif

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_SetMode (Mcu_ModeType McuMode);
extern FUNC(void, MCU_PUBLIC_CODE) Mcu_WakeUpFactor_Preparation
                                               (Mcu_ModeType McuMode);

#if (MCU_VERSION_INFO_API == STD_ON)
/*Implements EAAR_PN0034_FR_0051*/
extern FUNC(void,MCU_PUBLIC_CODE) Mcu_GetVersionInfo
       (P2VAR(Std_VersionInfoType, AUTOMATIC, MCU_APPL_CONST) versioninfo);

#endif /* (MCU_VERSION_INFO_API == STD_ON) */

#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#if (MCU_GET_RAM_STATE_API == STD_ON)
extern FUNC(Mcu_RamStateType, MCU_PUBLIC_CODE) Mcu_GetRamState (void);
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */
#endif /* (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION) */

#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE)Mcu_SequencerInit(Mcu_SeqType
                           McuSequencer);
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE)Mcu_SequencerStart(
                 Mcu_SeqOperationType McuSeqMode);
extern FUNC(void, MCU_PUBLIC_CODE)Mcu_SequencerStop(void);
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_SequencerDiCmpValueSet
                                          ( uint8 ucDpinId , boolean blDpinVal);
#endif /* if (MCU_LOW_POWER_SEQUENCER == STD_ON) */

#if (MCU_SW_RESET_CALL_API == STD_ON)
    /*Implements EAAR_PN0075_FSR_0030*/
extern FUNC(void, MCU_PUBLIC_CODE)MCU_RESET_CALLOUT(void);
#endif

#if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE )

extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_CheckHWConsistency
                                  (Mcu_HWConsistencyModeType HWConsistencyMode);
#endif
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#if (MCU_RETENTIONRAM_REQ == STD_ON)
#define MCU_START_SEC_RRAM_CODE
#include "MemMap.h"
FUNC(void, MCU_PUBLIC_CODE)Mcu_Rram_Cyclic_Run(void);
#define MCU_STOP_SEC_RRAM_CODE
#include "MemMap.h"
#endif


#define MCU_START_SEC_RRAM_ROM_CODE
#include "MemMap.h"
#if (MCU_RETENTIONRAM_REQ == STD_ON)
#if (MCU_COPY_TO_SECTION_API == STD_OFF)
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE)Mcu_CopyToSection(void);
#endif
#endif
#define MCU_STOP_SEC_RRAM_ROM_CODE
#include "MemMap.h"

#define MCU_START_SEC_RRAM_CODE
#include "MemMap.h"
FUNC(void, MCU_PUBLIC_CODE)Mcu_Intvec_CalcRange(uint32 * ulIntVecSecStartAddr,
               uint32 *ulIntVecSize);

FUNC(void, MCU_PUBLIC_CODE)Mcu_Code_CalcRange(uint32 * ulCodeSecStartAddr,
               uint32 *ulCodeSize);
#define MCU_STOP_SEC_RRAM_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_START_CONFIG_DATA_UNSPECIFIED
#endif
#include "MemMap.h"
/* Implements MCU_ESDD_UD_066 */
/* Structure for MCU Init configuration */
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(Mcu_ConfigType, MCU_CONST) Mcu_GstConfiguration[];
/* END Msg(4:3684)-1 */
#if (MCU_AR_VERSION  == MCU_AR_HIGHER_VERSION)
#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#elif(MCU_AR_VERSION  == MCU_AR_LOWER_VERSION)
#define MCU_STOP_CONFIG_DATA_UNSPECIFIED
#endif
#include "MemMap.h"
#endif /* MCU_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
