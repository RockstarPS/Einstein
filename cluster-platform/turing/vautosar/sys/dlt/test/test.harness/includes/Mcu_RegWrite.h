/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Mcu_RegWrite.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016 - 2017 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file is to have macro definitions for the registers write, ram        */
/* mirroring and verification.                                                */
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
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  04-Mar-2016 : Initial Version
 * V1.0.1:  26-Sep-2016 : Following changes are made:
 *                        1. As part of JIRA ARDAAAB-3680, ARDAAAC-856 and
 *                           ARDAAAA-945, macros are updated to add integer
 *                           literals.
 *                        2. As part of JIRA ARDAAAB-3576, ARDAAAA-794 and
 *                            ARDAAAC-724,
 *                          a. Macro function MCU_REG_WRITE_AND_MIRROR is
 *                             replaced with MCU_WRITE_REG_AND_MIRROR.
 *                          b. MCU_REG_CHECK_WRITE_VERIFY is replaced with two
 *                             macro function MCU_CHECK_WRITE_VERIFY_INIT and
 *                             MCU_CHECK_WRITE_VERIFY_RUNTIME for Mcu_Init and
 *                             all other APIs respectively.
 *                          c. MCU_WRITE_REG_AND_MIRROR passes three parameters
 *                             instead of four by avoiding MASK to be passed
 *                             explicitly.
 *                          d. Unwanted API_ID are removed.
 *                          e. File guard is updated to MCU_REGWRITE_H.
 *                        3. As part of JIRA #ARDAAAA-1103, ARDAAAC-975 One
 *                           space character is added between if and the opening
 *                           parenthesis.
 *                        4. As part of JIRA ARDAAAB-3904, for QAC, placement
 *                           of message Start and End is corrected.
 *                        5. Added trace of requirements and UD Ids against each
 *                           line of code.
 * V1.0.2: 13-Feb-2017 :  Following changes are made:
 *                       1. As part of JIRA ARDAABL-750, Added trace for
 *                          unmapped requirements.
 *                       2. Copyright information is updated.
 *                       3. Missing Rules are added in MISRA C Rule Violations
 *                          section.
 */
/******************************************************************************/

#ifndef MCU_REGWRITE_H
#define MCU_REGWRITE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/* Dem.h inclusion to get Dem_ReportErrorStatus declaration */
/*Implements MCU_ESDD_UD_055, EAAR_PN0034_FR_0021, EAAR_PN0034_NR_0001, MCU108*/
#if( MCU_USE_WV_ERROR_INTERFACE == STD_OFF )
#include "Dem.h"
#endif

#include "Std_Types.h"
/*Implements MCU211*/
#include "Mcu_Cfg.h"
//#include "Mcu_Cbk.h"

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognized code-fragment       */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro definition as multi-line operation hence multi-line  */
/*                 macro is used                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-1 and                           */
/*                 END Msg(4:3412)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Since GetVersionInfo API is implemented as macro braces    */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-2 and                           */
/*                 END Msg(4:3458)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : Msg(4:3453) A function could probably be used instead of   */
/*                 this function-like macro.                                  */
/* Rule          : MISRA-C:2004 Rule 19.7                                     */
/* Justification : This function macro is used here to speed up the process   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-3 and                           */
/*                 END Msg(4:3453)-3 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                     Macro Definitions                                      **
*******************************************************************************/
/* API IDs */

/* API ID of Mcu_CkscConfigure */
#define MCU_CKSCCONFIGURE_API_ID                    (uint8)0x80U
/* API ID of Mcu_Rram_Cyclic_Run */
#define MCU_RRAM_CYCLIC_RUN_API_ID                  (uint8)0x81U
/* API ID of Mcu_WakeUpFactor_Preparation */
#define MCU_WAKEUPFACTOR_PREPARATION_API_ID         (uint8)0x82U
/* API ID of Mcu_CpuClockRestore */
#define MCU_CPUCLOCKRESTORE_API_ID                  (uint8)0x83U


/* Macro for Register readback disable */
#define MCU_WV_DISABLE                     0U
/* Macro for Register readback INIT_ONLY */
#define MCU_WV_INIT_ONLY                   1U
/* Macro for Register readback INIT_RUNTIME */
#define MCU_WV_INIT_RUNTIME                2U
/* Macro for RAM Mirror Disable */
#define MCU_MIRROR_DISABLE                 3U
/* Macro for RAM Mirror Enable */
#define MCU_MIRROR_ENABLE                  4U

/*******************************************************************************
** Macro Name            : MCU_WRITE_REG_MIRROR
**
** Description           : This macro is to perform the write operation to the
**                         register and respective RAM mirroring.
**                         This macro shall be used by the
**                         MCU_WRITE_REG_AND_MIRROR macro for writing the
**                         registers when the RAM mirroring is enabled for the
**                         respective instance.
**
** Input Parameters      : pWriteRegAddr, pMirrorAddr, uiRegWriteValue
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : MCU_RAM_MIRROR should be enabled.
**
** Functions invoked     : None
*******************************************************************************/
/*Implements MCU_ESDD_UD_076*/
/* MISRA Violation: START Msg(4:3412)-1 */
/* MISRA Violation: START Msg(4:3458)-2 */
#define MCU_WRITE_REG_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
  (*(pMirrorAddr))   = (uiRegWriteValue); \
}
/* END Msg(4:3458)-2 */
/*******************************************************************************
** Macro Name            : MCU_WRITE_REG_ONLY
**
** Description           : This macro is to perform the write operation to the
**                         register which is passed. This macro shall be used
**                         in the below case.
**                         1. This macro shall be used by
**                         MCU_WRITE_REG_AND_MIRROR macro for writing the
**                         registers when the RAM mirroring is disabled for the
**                         respective instance.
**                         2. To write the value to the register directly for
**                         which the RAM mirroring is neither possible nor
**                         required.
**
** Input Parameters      : pWriteRegAddr, uiRegWriteValue
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : MCU_RAM_MIRROR should be disabled.
**
** Functions invoked     : None
*******************************************************************************/
/*Implements MCU_ESDD_UD_076*/
/* MISRA Violation: START Msg(4:3458)-2 */
#define MCU_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
}
/* END Msg(4:3458)-2 */
/*******************************************************************************
** Macro Name            : MCU_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         MCU registers. This macro shall be used for writing
**                         the registers which need Ram Mirroring.
**
** Input Parameters      : pWriteRegAddr, uiRegWriteValue, pMirrorAddr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : None
*******************************************************************************/
/*Implements EAAR_PN0034_FSR_0006*/
#if (MCU_RAM_MIRROR != MCU_MIRROR_DISABLE)
#define MCU_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
  { \
     MCU_WRITE_REG_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
  }
#else
#define MCU_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
  { \
     MCU_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
  }
#endif
/*******************************************************************************
** Macro Name            : MCU_WV_REPORT_ERROR
**
** Description           : This macro is to report the error to respective
**                         interface.
**
** Input Parameters      : WVErrId, ErrStat, uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : Dem_ReportErrorStatus, MCU_WV_ERROR_INTERFACE
*******************************************************************************/
/*Implements MCU_ESDD_UD_076*/
/* MISRA Violation: START Msg(4:3412)-1 */
/* MISRA Violation: START Msg(4:3458)-2 */
/*Implements MCU_ESDD_UD_055*/
#if ( MCU_USE_WV_ERROR_INTERFACE == STD_ON )
#define MCU_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
             MCU_WV_ERROR_INTERFACE(WVErrId, uiApiId);
#else
#define MCU_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
              Dem_ReportErrorStatus(WVErrId, (MCU_DEM_TYPE) (ErrStat));
#endif
/* END Msg(4:3412)-1 */
/* END Msg(4:3458)-2 */
/*******************************************************************************
** Macro Name            : MCU_CHECK_WRITE_VERIFY
**
** Description           : This macro is to do the comparison check and do
**                         the error reporting if the comparison fails.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : MCU_WRITE_VERIFY should be enabled.
**
** Functions invoked     : None
*******************************************************************************/
/*Implements MCU_ESDD_UD_076*/
/* MISRA Violation: START Msg(4:3412)-1 */
#define MCU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiMaskValue, uiApiId) \
  { \
    if ((uiCheckValue) != ((*(pCompareRegAddr)) & (uiMaskValue))) \
    { \
        MCU_WV_REPORT_ERROR(MCU_E_REG_WRITE_VERIFY, \
                            DEM_EVENT_STATUS_FAILED, uiApiId) \
    } \
    else \
    { \
    } \
  }
/* END Msg(4:3412)-1 */
/*******************************************************************************
** Macro Name            : MCU_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         Mcu_Init API.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : None
*******************************************************************************/
/*Implements MCU_ESDD_UD_076, EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002*/
/*Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004*/
/* MISRA Violation: START Msg(4:3412)-1 */
/* MISRA Violation: START Msg(4:3453)-3 */
#if (MCU_WRITE_VERIFY != MCU_WV_DISABLE)

#define MCU_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                      uiMaskValue, uiApiId) \
  MCU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
#else
#define MCU_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                       uiMaskValue, uiApiId) \
  {\
  }
#endif
/* END Msg(4:3453)-3 */
/* END Msg(4:3412)-1 */

/*******************************************************************************
** Macro Name            : MCU_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than Mcu_Init.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : None
*******************************************************************************/
/*Implements MCU_ESDD_UD_076*/
/* MISRA Violation: START Msg(4:3453)-3 */
/* MISRA Violation: START Msg(4:3412)-1 */
#if (MCU_WRITE_VERIFY == MCU_WV_INIT_RUNTIME)

#define MCU_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiMaskValue, uiApiId) \
  MCU_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiMaskValue, uiApiId)
#else

#define MCU_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiMaskValue, uiApiId) \
  {\
  }
#endif
/* END Msg(4:3412)-1 */
/* END Msg(4:3453)-3 */
#endif /* MCU_REGWRITE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
