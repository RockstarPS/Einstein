/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Pwm_RegWrite.h                                              */
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
 * V1.0.0:  14-Jan-2016 : Initial Version
 *
 * V1.0.1:  24-May-2016 : As per Jira ARDAAAB-3638, change is made to fix QAC
 *                        warning and QAC message justifications are added.
 *
 * V1.0.2:  06-Oct-2016 : As per JIRA ARDAAAB-3576, ARDAAAA-794, ARDAAAC-724
 *                        1. Macro functions are modified.
 *                        2. Unwanted API ID's are removed
 *                        3. Requirements and UD ID's are added for traceability
 *                           with respect to the implementation.
 * V1.0.3:  03-Feb-2017 : Following changes are made:
 *                        1.As part of JIRA ARDAABL-743 Requirements and
 *                          UD ID's are added for traceability with respect to
 *                          the implementation.
 *                        2.Copyright information updated.
 *                        3.Msg(4:0857) justification added.
 */
/******************************************************************************/

#ifndef PWM_REG_WRITE_H
#define PWM_REG_WRITE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Implements PWM_ESDD_UD_057,PWM104,PWM067  */
/* Dem.h inclusion to get Dem_ReportErrorStatus declaration */
#if( PWM_USE_WV_ERROR_INTERFACE == STD_OFF )
#include "Dem.h"
#endif

#include "Std_Types.h"
#include "Pwm_Cfg.h"
// #include "Pwm_Cbk.h"

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/*Implements EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0026*/
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
/* Justification : Since API is implemented as macro, braces cannot be        */
/*                 avoided.                                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-2 and                           */
/*                 END Msg(4:3458)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : Msg(4:3453) A function could probably be used instead of   */
/*                 this function-like macro.                                  */
/* Rule          : MISRA-C:2004 19.7                                          */
/* Justification : This function macro is used here to speed up the process   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-3 and                           */
/*                 END Msg(4:3453)-3 tags in the code.                        */
/******************************************************************************/
/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024 -        */
/*                 program does not conform strictly to ISO:C90.              */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Number of macro definitions exceeds 1024,                  */
/*                 Since these much macros are are required in program        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-4 and                           */
/*                 END Msg(4:0857)-4 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                     Macro Definitions                                      **
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-4 */
/* API IDs for the private APIs */
#define PWM_HW_SETDUTY_FIXEDPERIODSHIFTED_API_ID    (uint8)0x83

#define PWM_HW_CALLBACK_API_ID                      (uint8)0x86

#define PWM_PWGA_CALLBACK_API_ID                    (uint8)0x89
/* Implements EAAR_PN0034_FSR_0001,EAAR_PN0034_FSR_0002 */
/* Macro for Register readback disable */
#define PWM_WV_DISABLE                     0U
/* Macro for Register readback INIT_ONLY */
#define PWM_WV_INIT_ONLY                   1U
/* Macro for Register readback INIT_RUNTIME */
#define PWM_WV_INIT_RUNTIME                2U
/* Macro for RAM Mirror Disable */
#define PWM_MIRROR_DISABLE                 3U
/* Macro for RAM Mirror Enable */
#define PWM_MIRROR_ENABLE                  4U

/*******************************************************************************
** Macro Name            : PWM_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to perform the write operation to the
**                         register which is passed and respective RAM mirroring
**
** Input Parameters      : pWriteRegAddr, pMirrorAddr, uiRegWriteValue
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : RAM Mirror ON
**
** Functions invoked     : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3458)-2 */
#define PWM_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
    (*(pMirrorAddr)) = (uiRegWriteValue); \
}
/*******************************************************************************
** Macro Name            : PWM_WRITE_REG_ONLY
**
** Description           : This macro is to perform the write operation to the
**                         register which is passed.
**
** Input Parameters      : pWriteRegAddr, pMirrorAddr, uiWCMaskValue,
**                         uiRegWriteValue
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
#define PWM_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue)  \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
}
/* END Msg(4:3458)-2 */
/*******************************************************************************
** Macro Name            : PWM_WV_REPORT_ERROR
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
** Functions invoked     : Dem_ReportErrorStatus, PWM_ERROR_NOTIFICATION
*******************************************************************************/
/* MISRA Violation: START Msg(4:3412)-1 */
/* Implements PWM_ESDD_UD_057,PWM066,PWM066a,PWM_ESDD_UD_061,PWM_ESDD_UD_166 */
/* Implements PWM104 */
#if ( PWM_USE_WV_ERROR_INTERFACE == STD_ON )
#define PWM_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                            PWM_ERROR_NOTIFICATION(WVErrId, uiApiId);
#else
#define PWM_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                            Dem_ReportErrorStatus(WVErrId, \
                                   (PWM_DEM_TYPE) (ErrStat));
#endif
/*******************************************************************************
** Macro Name            : PWM_CHECK_WRITE_VERIFY
**
** Description           : This macro is to do the comparison check and do
**                         the error reporting if the comparison fails.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
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
/* Implements PWM_ESDD_UD_095,EAAR_PN0034_FSR_0003,EAAR_PN0034_FSR_0004 */
#define PWM_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                uiWCMaskValue, uiApiId) \
  { \
    if ((uiCheckValue) != ((*(pCompareRegAddr)) & (uiWCMaskValue))) \
    { \
        PWM_WV_REPORT_ERROR(PWM_E_REG_WRITE_VERIFY, \
                            DEM_EVENT_STATUS_FAILED, uiApiId) \
    } \
    else \
    { \
    } \
  }
/* END Msg(4:3412)-1 */
/*******************************************************************************
** Macro Name            : PWM_PWGA_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         the PWGA unit registers.
**
** Input Parameters      : pWriteRegAddr, uiRegWriteValue, pMirrorAddr,
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : PWM_DIAG_UNIT_USED
**
** Functions invoked     : None
*******************************************************************************/
/* Implements PWM_ESDD_UD_056,PWM_ESDD_UD_041 */
#if (PWM_DIAG_UNIT_USED == STD_ON)
#if (PWM_PWGA_RAM_MIRROR != PWM_MIRROR_DISABLE)
#define PWM_PWGA_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                                              pMirrorAddr) \
  { \
     PWM_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
  }
#else
#define PWM_PWGA_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                                               pMirrorAddr) \
  { \
     PWM_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
  }
#endif
#endif

/*******************************************************************************
** Macro Name            : PWM_TAUDB_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         the TAUDB unit registers.
**
** Input Parameters      : pWriteRegAddr, uiRegWriteValue, pMirrorAddr,
**                         uiWCMaskValue
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : PWM_TAUD_UNIT_USED, PWM_TAUB_UNIT_USED
**
** Functions invoked     : None
*******************************************************************************/
/* Implements PWM_ESDD_UD_056,PWM_ESDD_UD_025,PWM_ESDD_UD_026 */
#if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
#if (PWM_TAUDB_RAM_MIRROR != PWM_MIRROR_DISABLE)
#define PWM_TAUDB_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                                              pMirrorAddr) \
  { \
     PWM_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
  }
#else
#define PWM_TAUDB_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                                               pMirrorAddr) \
  { \
     PWM_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
  }
#endif
#endif

/*******************************************************************************
** Macro Name            : PWM_TAUJ_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                          the TAUJ unit registers.
**
** Input Parameters      : pWriteRegAddr, uiRegWriteValue, pMirrorAddr,
**                         uiWCMaskValue
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : PWM_TAUJ_UNIT_USED
**
** Functions invoked     : None
*******************************************************************************/
/* Implements  PWM_ESDD_UD_056,PWM_ESDD_UD_027 */
#if (PWM_TAUJ_UNIT_USED == STD_ON)
#if (PWM_TAUJ_RAM_MIRROR != PWM_MIRROR_DISABLE)
#define PWM_TAUJ_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                                              pMirrorAddr) \
  { \
     PWM_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, pMirrorAddr) \
  }
#else
#define PWM_TAUJ_WRITE_REG_AND_MIRROR(pWriteRegAddr, uiRegWriteValue, \
                                                               pMirrorAddr) \
  { \
     PWM_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
  }
#endif
#endif
/*******************************************************************************
** Macro Name            : PWM_PWGA_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify for the PWGA
**                         unit registers.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : PWM_DIAG_UNIT_USED
**
** Functions invoked     : None
*******************************************************************************/
/* Implements PWM_ESDD_UD_055,EAAR_PN0034_FSR_0002 */
#if (PWM_DIAG_UNIT_USED == STD_ON)
#if (PWM_PWGA_WRITE_VERIFY != PWM_WV_DISABLE)
/* MISRA Violation: START Msg(4:3453)-3 */
#define PWM_PWGA_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  PWM_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define PWM_PWGA_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-1 */
#endif
#endif
/*******************************************************************************
** Macro Name            : PWM_TAUDB_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify for the TAUDB
**                         unit registers.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : PWM_TAUD_UNIT_USED, PWM_TAUB_UNIT_USED
**
** Functions invoked     : None
*******************************************************************************/
/* Implements PWM_ESDD_UD_055,PWM_ESDD_UD_025,PWM_ESDD_UD_026  */
#if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
#if (PWM_TAUDB_WRITE_VERIFY != PWM_WV_DISABLE)
/* MISRA Violation: START Msg(4:3453)-3 */
#define PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  PWM_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define PWM_TAUDB_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-1 */
#endif
#endif
/*******************************************************************************
** Macro Name            : PWM_TAUJ_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify for the TAUJ
**                         unit registers.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : PWM_TAUD_UNIT_USED, PWM_TAUB_UNIT_USED
**
** Functions invoked     : None
*******************************************************************************/
/* Implements PWM_ESDD_UD_055,PWM_ESDD_UD_027,EAAR_PN0034_FSR_0002  */
#if (PWM_TAUJ_UNIT_USED == STD_ON)
#if (PWM_TAUJ_WRITE_VERIFY != PWM_WV_DISABLE)
/* MISRA Violation: START Msg(4:3453)-3 */
#define PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  PWM_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define PWM_TAUJ_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-1 */
#endif
#endif

/*******************************************************************************
** Macro Name            : PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify for the PWGA
**                         unit registers.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : PWM_DIAG_UNIT_USED
**
** Functions invoked     : None
*******************************************************************************/
/* Implements PWM_ESDD_UD_055,PWM_ESDD_UD_041,EAAR_PN0034_FSR_0002  */
#if (PWM_DIAG_UNIT_USED == STD_ON)
#if (PWM_PWGA_WRITE_VERIFY == PWM_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-3 */
#define PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  PWM_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define PWM_PWGA_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-1 */
#endif
#endif
/*******************************************************************************
** Macro Name            : PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify for the TAUDB
**                         unit registers.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : PWM_TAUD_UNIT_USED, PWM_TAUB_UNIT_USED
**
** Functions invoked     : None
*******************************************************************************/
/* Implements PWM_ESDD_UD_055,PWM_ESDD_UD_041,PWM_ESDD_UD_025,PWM_ESDD_UD_026 */
#if ((PWM_TAUD_UNIT_USED == STD_ON) || (PWM_TAUB_UNIT_USED == STD_ON))
#if (PWM_TAUDB_WRITE_VERIFY == PWM_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-3 */
#define PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  PWM_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define PWM_TAUDB_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-1 */
#endif
#endif
/*******************************************************************************
** Macro Name            : PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify for the TAUJ
**                         unit registers.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiWCMaskValue,
**                         uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : PWM_TAUD_UNIT_USED, PWM_TAUB_UNIT_USED
**
** Functions invoked     : None
*******************************************************************************/
/* Implements PWM_ESDD_UD_027, PWM_ESDD_UD_055,EAAR_PN0034_FSR_0002  */
#if (PWM_TAUJ_UNIT_USED == STD_ON)
#if (PWM_TAUJ_WRITE_VERIFY == PWM_WV_INIT_RUNTIME)
/* MISRA Violation: START Msg(4:3453)-3 */
#define PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  PWM_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId)
/* END Msg(4:3453)-3 */
#else
/* MISRA Violation: START Msg(4:3412)-1 */
#define PWM_TAUJ_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
  }
/* END Msg(4:3412)-1 */
#endif
#endif
/* END Msg(4:0857)-4 */
#endif /* PWM_REG_WRITE_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
