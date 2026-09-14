/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_RegWrite.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016 Renesas Electronics Corporation                          */
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
 * V1.0.0:  15-Feb-2016 : Initial Version
 *
 * V1.0.1:  29-Sep-2016 : Following changes are made
 *                        1. As part of JIRA ARDAAAC-724, ARDAAAA-794 and
 *                           ARDAAAB-3576, Macro functions are modified.
 *                        2. As part of ARDAAAA-1145, ARDAAAC-1007 changed the
 *                           macro definitions changed to upper case letters
 *                        3. One space is given between if, else statements.
 *                        4. Traceability to UD IDs and requirements is added.
 */
/******************************************************************************/
/* Implements EAAR_PN0034_FR_0001 */
#ifndef ADC_REGWRITE_H
#define ADC_REGWRITE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/* Dem.h inclusion to get Dem_ReportErrorStatus declaration */
#if ( ADC_USE_WRITEVERIFY_ERROR_INTERFACE == STD_OFF )
#include "Dem.h"
#else
#include "Adc_Cbk.h"
#endif

#include "Std_Types.h"
#include "Adc_Cfg.h"

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Since GetVersionInfo API is implemented as macro braces    */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-1 and                           */
/*                 END Msg(4:3458)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognized code-fragment       */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro definition as multi-line operation hence multi-line  */
/*                 macro is used                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-2 and                           */
/*                 END Msg(4:3412)-2 tags in the code.                        */
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
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                     Macro Definitions                                      **
*******************************************************************************/
/* API IDs for the private APIs */
/* Implements EAAR_PN0040_NR_0011 */

#define ADC_ISR_API_ID                              (uint8)0x88

#define ADC_CHANNELCOMPLETEMODE_API_ID              (uint8)0x8A

#define ADC_GROUPCOMPLETEMODE_API_ID                (uint8)0x8B

#define ADC_CONFIGUREGROUPFORCONVERSION_API_ID      (uint8)0x8C

#define ADC_DISABLEHWGROUP_API_ID                   (uint8)0x8F

#define ADC_ISRCONFIGUREGROUPFORCONVERSION_API_ID   (uint8)0x98

#define ADC_ERRISR_API_ID                           (uint8)0x99

/* Macro for Register readback disable */
#define ADC_WV_DISABLE                     0U
/* Macro for Register readback INIT_ONLY */
#define ADC_WV_INIT_ONLY                   1U
/* Macro for Register readback INIT_RUNTIME */
#define ADC_WV_INIT_RUNTIME                2U
/* Macro for RAM Mirror Disable */
#define ADC_MIRROR_DISABLE                 3U
/* Macro for RAM Mirror Enable */
#define ADC_MIRROR_ENABLE                  4U


/*******************************************************************************
** Macro Name            : ADC_WRITE_REG_ONLY
**
** Description           : This macro is to perform the write operation to the
**                         register which is passed.
**
** Input Parameters      : pWriteRegAddr, uiRegWriteValue
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
/*START Msg(4:3458)-1 */
#define ADC_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
}
/*END Msg(4:3458)-1 */

/*******************************************************************************
** Macro Name            : ADC_WRITE_REG_AND_MIRROR
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
/*START Msg(4:3458)-1 */
#define ADC_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, uiRegWriteValue) \
{ \
  (*(pWriteRegAddr)) = (uiRegWriteValue); \
    (*(pMirrorAddr)) = (uiRegWriteValue); \
}
/*END Msg(4:3458)-1 */



/*******************************************************************************
** Macro Name            : ADC_ADCA_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         ADCA registers. This macro shall be used for writing
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

  #if (ADC_ADCA_RAMMIRROR != ADC_MIRROR_DISABLE)
  #define ADC_ADCA_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                   uiRegWriteValue, \
                                                   pMirrorAddr) \
    { \
      ADC_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, uiRegWriteValue ) \
    }
  #else
  #define ADC_ADCA_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                   uiRegWriteValue, \
                                                   pMirrorAddr) \
    { \
      ADC_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
    }
  #endif



/*******************************************************************************
** Macro Name            : ADC_PWGA_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         PWGA registers. This macro shall be used for writing
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
** Pre-conditions        : ADC_ENABLE_DIAGNOSTIC_SUPPORT should be STD_ON
**
** Functions invoked     : None
*******************************************************************************/

  #if (ADC_PWM_DIAG_RAMMIRROR != ADC_MIRROR_DISABLE)
  #define ADC_PWGA_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                   uiRegWriteValue, \
                                                   pMirrorAddr) \
    { \
      ADC_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, uiRegWriteValue ) \
    }
  #else
  #define ADC_PWGA_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                   uiRegWriteValue, \
                                                   pMirrorAddr) \
    { \
      ADC_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
    }
  #endif


/*******************************************************************************
** Macro Name            : ADC_PWSA_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         PWSA registers. This macro shall be used for writing
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
** Pre-conditions        : ADC_ENABLE_DIAGNOSTIC_SUPPORT should be STD_ON
**
** Functions invoked     : None
*******************************************************************************/

  #if (ADC_PWM_DIAG_RAMMIRROR != ADC_MIRROR_DISABLE)
  #define ADC_PWSA_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                   uiRegWriteValue, \
                                                   pMirrorAddr) \
    { \
      ADC_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, uiRegWriteValue ) \
    }
  #else
  #define ADC_PWSA_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                   uiRegWriteValue, \
                                                   pMirrorAddr) \
    { \
      ADC_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
    }
  #endif


/*******************************************************************************
** Macro Name            : ADC_DMAC_WRITE_REG_AND_MIRROR
**
** Description           : This macro is to do the write and RAM mirroring for
**                         DMAC registers. This macro shall be used for writing
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
** Pre-conditions        : ADC_DMA_MODE_ENABLE should be STD_ON
**
** Functions invoked     : None
*******************************************************************************/

  #if (ADC_DMAC_RAMMIRROR != ADC_MIRROR_DISABLE)
  #define ADC_DMAC_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                   uiRegWriteValue, \
                                                   pMirrorAddr) \
    { \
      ADC_WRITE_REG_AND_MIRROR(pWriteRegAddr, pMirrorAddr, uiRegWriteValue ) \
    }
  #else
  #define ADC_DMAC_WRITE_REG_AND_MIRROR(pWriteRegAddr, \
                                                   uiRegWriteValue, \
                                                   pMirrorAddr) \
    { \
      ADC_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue) \
    }
  #endif



/*******************************************************************************
** Macro Name            : ADC_WV_REPORT_ERROR
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
** Functions invoked     : Dem_ReportErrorStatus,
**                         ADC_WRITEVERIFY_ERROR_INTERFACE
*******************************************************************************/
/*START Msg(4:3412)-2 */
/* Implements ADC_ESDD_UD_197 */
/* Implements EAAR_PN0034_FSR_0004 */
#if ( ADC_USE_WRITEVERIFY_ERROR_INTERFACE == STD_ON )
#define ADC_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                           ADC_WRITEVERIFY_ERROR_INTERFACE(WVErrId, uiApiId);
#else
#define ADC_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                            Dem_ReportErrorStatus(WVErrId, \
                                    (ADC_DEM_TYPE)(ErrStat));
#endif
/*END Msg(4:3412)-2 */
/*******************************************************************************
** Macro Name            : ADC_CHECK_WRITE_VERIFY
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
/*START Msg(4:3412)-2 */
/* Implements ADC_ESDD_UD_203 */
/* Implements EAAR_PN0034_FSR_0001 */
/* Implements EAAR_PN0034_FSR_0003 */
/* Implements EAAR_PN0034_FSR_0004 */
#define ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, \
                                    uiWCMaskValue, uiApiId) \
  { \
    if ((uiCheckValue) != ((*(pCompareRegAddr)) & (uiWCMaskValue))) \
    { \
        ADC_WV_REPORT_ERROR(ADC_E_REG_WRITE_VERIFY, \
                            DEM_EVENT_STATUS_FAILED, uiApiId) \
    } \
    else \
    { \
    } \
  }
/*END Msg(4:3412)-2 */


/*******************************************************************************
** Macro Name            : ADC_ADCA_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         ADC_Init API.
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
/*START Msg(4:3453)-3 */
/*START Msg(4:3412)-2 */
/* Implements ADC_ESDD_UD_195 */
/* Implements EAAR_PN0034_FSR_0001 */
  #if (ADC_ADCA_WRITE_VERIFY != ADC_WV_DISABLE)

  #define ADC_ADCA_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                        uiMaskValue, uiApiId) \
    ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
  #else
  #define ADC_ADCA_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                       uiMaskValue, uiApiId) \
    {\
    }
  #endif
/*END Msg(4:3412)-2 */
/*END Msg(4:3453)-3 */
/*******************************************************************************
** Macro Name            : ADC_PWGA_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         ADC_Init API.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ADC_ENABLE_DIAGNOSTIC_SUPPORT should be STD_ON
**
** Functions invoked     : None
*******************************************************************************/
/*START Msg(4:3453)-3 */
/*START Msg(4:3412)-2 */
/* Implements EAAR_PN0034_FSR_0001 */
  #if (ADC_PWM_DIAG_WRITE_VERIFY != ADC_WV_DISABLE)

  #define ADC_PWGA_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                        uiMaskValue, uiApiId) \
    ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
  #else
  #define ADC_PWGA_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                       uiMaskValue, uiApiId) \
    {\
    }
  #endif
/*END Msg(4:3412)-2 */
/*END Msg(4:3453)-3 */
/*******************************************************************************
** Macro Name            : ADC_PWSA_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         ADC_Init API.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ADC_ENABLE_DIAGNOSTIC_SUPPORT should be STD_ON
**
** Functions invoked     : None
*******************************************************************************/
/*START Msg(4:3453)-3 */
/*START Msg(4:3412)-2 */
/* Implements EAAR_PN0034_FSR_0001 */
  #if (ADC_PWM_DIAG_WRITE_VERIFY != ADC_WV_DISABLE)

  #define ADC_PWSA_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                        uiMaskValue, uiApiId) \
    ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
  #else
  #define ADC_PWSA_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                       uiMaskValue, uiApiId) \
    {\
    }
  #endif
/*END Msg(4:3412)-2 */
/*END Msg(4:3453)-3 */
/*******************************************************************************
** Macro Name            : ADC_DMAC_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         ADC_Init API.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ADC_DMA_MODE_ENABLE should be STD_ON
**
** Functions invoked     : None
*******************************************************************************/
/*START Msg(4:3453)-3 */
/*START Msg(4:3412)-2 */
/* Implements EAAR_PN0034_FSR_0001 */
  #if (ADC_DMAC_WRITE_VERIFY != ADC_WV_DISABLE)

  #define ADC_DMAC_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                        uiMaskValue, uiApiId) \
    ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
  #else
  #define ADC_DMAC_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                       uiMaskValue, uiApiId) \
    {\
    }
  #endif
/*END Msg(4:3412)-2 */
/*END Msg(4:3453)-3 */
/*******************************************************************************
** Macro Name            : ADC_WUF_CHECK_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify call only for
**                         ADC_Init API.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ADC_WAKEUPFACTOR_CLEAR_ISR should be STD_ON
**
** Functions invoked     : None
*******************************************************************************/
/*START Msg(4:3412)-2 */
/*START Msg(4:3453)-3 */
/* Implements EAAR_PN0034_FSR_0001 */
  #if (ADC_WUF_WRITE_VERIFY != ADC_WV_DISABLE)

  #define ADC_WUF_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                        uiMaskValue, uiApiId) \
    ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
  #else
  #define ADC_WUF_CHECK_WRITE_VERIFY_INIT(pCompareRegAddr, uiCheckValue, \
                                                       uiMaskValue, uiApiId) \
    {\
    }
  #endif
/*END Msg(4:3412)-2 */
/*END Msg(4:3453)-3 */
/*******************************************************************************
** Macro Name            : ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than ADC_Init.
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
/*START Msg(4:3412)-2 */
/*START Msg(4:3453)-3 */
/* Implements EAAR_PN0034_FSR_0001 */
  #if (ADC_ADCA_WRITE_VERIFY == ADC_WV_INIT_RUNTIME)

  #define ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                                       uiMaskValue, uiApiId)  \
    ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
  #else
  #define ADC_ADCA_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                                        uiMaskValue, uiApiId) \
    {\
    }
  #endif
/*END Msg(4:3453)-3 */
/*END Msg(4:3412)-2 */
/*******************************************************************************
** Macro Name            : ADC_PWSA_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than ADC_Init.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ADC_ENABLE_DIAGNOSTIC_SUPPORT should be STD_ON
**
** Functions invoked     : None
*******************************************************************************/
/*START Msg(4:3412)-2 */
/*START Msg(4:3453)-3 */
/* Implements EAAR_PN0034_FSR_0001 */
  #if (ADC_PWM_DIAG_WRITE_VERIFY == ADC_WV_INIT_RUNTIME)

  #define ADC_PWSA_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                                       uiMaskValue, uiApiId)  \
    ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
  #else
  #define ADC_PWSA_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                                        uiMaskValue, uiApiId) \
    {\
    }
  #endif
/*END Msg(4:3412)-2 */
/*END Msg(4:3453)-3 */
/*******************************************************************************
** Macro Name            : ADC_PWGA_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than ADC_Init.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ADC_ENABLE_DIAGNOSTIC_SUPPORT should be STD_ON
**
** Functions invoked     : None
*******************************************************************************/
/*START Msg(4:3453)-3 */
/*START Msg(4:3412)-2 */
/* Implements EAAR_PN0034_FSR_0001 */
  #if (ADC_PWM_DIAG_WRITE_VERIFY == ADC_WV_INIT_RUNTIME)

  #define ADC_PWGA_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                                       uiMaskValue, uiApiId)  \
    ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
  #else
  #define ADC_PWGA_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                                        uiMaskValue, uiApiId) \
    {\
    }
  #endif
/*END Msg(4:3412)-2 */
/*END Msg(4:3453)-3 */
/*******************************************************************************
** Macro Name            : ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than ADC_Init.
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
/*START Msg(4:3412)-2 */
/* Implements EAAR_PN0034_FSR_0001 */
  #if (ADC_DMAC_WRITE_VERIFY == ADC_WV_INIT_RUNTIME)

  #define ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                                       uiMaskValue, uiApiId)  \
    ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
  #else
  #define ADC_DMAC_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                                        uiMaskValue, uiApiId) \
    {\
    }
  #endif
/*END Msg(4:3412)-2 */
/*******************************************************************************
** Macro Name            : ADC_WUF_CHECK_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify call only for
**                         the API's other than ADC_Init.
**
** Input Parameters      : pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : ADC_WAKEUPFACTOR_CLEAR_ISR should be STD_ON
**
** Functions invoked     : None
*******************************************************************************/
/*START Msg(4:3453)-3 */
/*START Msg(4:3412)-2 */
/* Implements EAAR_PN0034_FSR_0001 */
  #if (ADC_WUF_WRITE_VERIFY == ADC_WV_INIT_RUNTIME)

  #define ADC_WUF_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                                       uiMaskValue, uiApiId)  \
    ADC_CHECK_WRITE_VERIFY(pCompareRegAddr, uiCheckValue, uiMaskValue, uiApiId)
  #else
  #define ADC_WUF_CHECK_WRITE_VERIFY_RUNTIME(pCompareRegAddr, uiCheckValue, \
                                                        uiMaskValue, uiApiId) \
    {\
    }
  #endif

#endif /* ADC_REGWRITE_H */
/*END Msg(4:3412)-2 */
/*END Msg(4:3453)-3 */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
