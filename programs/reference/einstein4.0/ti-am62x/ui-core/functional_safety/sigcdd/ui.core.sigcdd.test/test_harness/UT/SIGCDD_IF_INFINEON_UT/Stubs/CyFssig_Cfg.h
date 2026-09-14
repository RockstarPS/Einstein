/*******************************************************************************
*
* (c) 2017, Cypress Semiconductor Corporation. All rights reserved.
*
* Warranty and Disclaimer
*
* This software product is property of Cypress Semiconductor Corporation or
* its subsidiaries.
* Any use and/or distribution rights for this software product are provided
* only under the Cypress Software License Agreement.
* Any use and/or distribution of this software product not in accordance with
* the terms of the Cypress Software License Agreement are unauthorized and
* shall constitute an infringement of Cypress intellectual property rights.
*
*******************************************************************************/
/*******************************************************************************
 ** \file CyFssig_Cfg.h
 **
 ** \date       14-Nov-2017 10:14:25
 ** \addtogroup Interface CyFssig_Cfg
 **
*******************************************************************************/
#ifndef CYFSSIG_CFG_H
#define CYFSSIG_CFG_H


/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#if 0
#include <Appl_Cbk.h>
#include <Crc_Cbk.h>
#include <Err_Cbk.h>
#endif
/* Deviation from MISRA C:2012 Dir-4.9.
   Justification: The choice of using a function-like macro here is done in order to
                  allow an easier understanding of the code
                  without incurring the overhead of a function call.    */
/* PRQA S 3453 EOF */
/** \addtogroup CyFssigApiPreCmpCfg */
/** { */

/*****************************************************************************
 ** Global pre-processor symbols/macros ('#define')
 *****************************************************************************/
/**  Macro definition for the pre-compile time configuration of the driver. The
 macro is expected to expand to an initializer for a structure of type
 cyfssig_pc_config_type.

 The given example implements the following configuration:
 - Maximum number of used evaluation windows is 8.
 - Calculation of the checksum over the register space of the Timing Controller
 is distributed over 30 calls of the main function of this driver. This value is
 based on the assumptions that the display frame rate is 60 Hz, that the main
 function of the driver is called once per frame, and that the driver is
 expected to detect a modification of a register of the Timing Controller within
 one second. As the modification of the register may take place immediately
 after a register was read for the checksum calculation, two rounds of checksum
 calculation may be necessary to detect the modification.
 - The output of the gamma correction unit is used as the input for evaluation
 window signature calculation.

 \showinitializer
 */
#define CYFSSIG_PRE_COMPILE_CFG  {\
    .tagPcConfig_Pre    = 0x71F2A3B4UL,\
    .hardwareDerivative =  (uint8)CYFSSIG_HARDWARE_DERIVATIVE,\
    .displaySettings =\
    {\
         {\
             .dispId = (uint8)0x00u, \
             .evaluationWindowCount = (uint8)0x08u, \
             .registerReadbackPeriod = (uint8)30u, \
             .signatureSourceSelect = CYFSSIG_SIG_SOURCE_SELECT_GAMMACOR\
         }\
    },\
    .tagPcConfig_Post   = 0x4B3A2F17UL\
}


/**  The number of display settings in the pre-compile configuration. This value
 must be equal to CYFSSIG_NUMBER_OF_DISPLAY. It is limited 1. This limit is
 subject to future extension. */
#define CYFSSIG_CFG_NUMBER_OF_DISPLAY_SETTING  ((uint8)0x01u)

/**  Hardware derivative to be used. Supported values are and
 CYFSSIG_TVIIC2D4MA0 and CYFSSIG_TVIIC2D6MA0 */
#define CYFSSIG_HARDWARE_DERIVATIVE  CYFSSIG_TVIIC2D4MA0

/**  Indication to enable or disable the API functions to temporarily mask
 evaluation window error detection. Set this to TRUE to disable these functions;
 set this to FALSE to enable them. */
#define CYFSSIG_DISABLE_EVALWIN_ERROR_MASK_API  FALSE

/**  Indication to enable or disable the API functions to temporarily mask Timing
 Controller error detection. Set this to TRUE to disable these functions; set
 this to FALSE to enable them. */
#define CYFSSIG_DISABLE_TCON_ERROR_MASK_API  FALSE

/**  Indication to enable or disable DET error notification with the
 CYFSSIG_DET_ERROR_REPORT macro. Set this to TRUE to enable DET error
 notification; set this to FALSE to disable it. */
#define CYFSSIG_DEV_ERROR_DETECT  TRUE

/**  The number of used display streams. This value must be equal to
 CYFSSIG_CFG_NUMBER_OF_DISPLAY_SETTING. It is limited 1. This limit is subject
 to future extension. */
#define CYFSSIG_NUMBER_OF_DISPLAY  0x01u
/**
 * User-defined macro to define the call of a callback function that indicates the
 * completion of the commit operation of previous settings.
 * The function has the following prototype:
 * void <CyFssig_CommitCompleteCallout>(uint32 commitFlags)
 * This function must be reentrant. It is called in the context of the main
 * function of this driver for the completion of the commit operation for timing
 * controller settings. It is called in the context of an interrupt handler for
 * the completion of  the commit operation for evaluation window settings.
 */
#define CYFSSIG_COMMIT_COMPLETE_CALLOUT(GROUP) \
    Appl_CommitCompleteCallout(GROUP)
/**
 * User-defined macro to define the call of a callback function which indicates
 * the change of the evaluation status of an evaluation window.
 * The function has the following prototype:
 * void <CyFssig_EvalwinStateChangeCallout>(uint8 dispId, uint8 evalWinStatus);
 * The first parameter of the macro contains the identifier of the display stream
 * where the change of the evaluation status was detected. It is of type
 * cyfssig_disp_id_type cast to uint8. The second parameter indicates the
 * evaluation status for every window of the display stream. Bit 0, the least
 * significant bit, stands for evaluation window 0, bit 1 for evaluation window 1
 * and so on. A value of 1 indicates that a signature mismatch was detected for
 * the respective evaluation window.
 * The macro is executed in the context of an interrupt handler.
 */
#define CYFSSIG_EVALWIN_STATECHANGE_CALLOUT(DISP_ID, WIN_STAT) \
    Appl_EvalwinStateChangeCallout(DISP_ID, WIN_STAT)
/**
 * User-defined macro to define the call of a callback function which indicates
 * the state change of Timing Controller monitoring.
 * The function has the following prototype:
 * void <CyFssig_TconStateChangeCallout>(uint8 dispId, uint8 tconEvalStatus);
 * The first parameter is the identifier of the display stream where the change of
 * status of the Timing Controller monitoring took place. It is of type
 * cyfssig_disp_id_type cast to uint8. The second parameter is a value of type
 * cyfssig_tcon_checksum_result_type cast to uint8 which indicates the current
 * status of Timing Controller monitoring.
 * This macro is executed in the context of the main function of this driver.
 */
#define CYFSSIG_TCON_STATECHANGE_CALLOUT(DISP_ID, CHECK_RES) \
    Appl_TconStateChangeCallout(DISP_ID, CHECK_RES)
/**
 * User-defined macro to define the call of the checksum calculation function that
 * is used for monitoring of the register space associated with the timing
 * controller.
 * The function must be compatible with the interface of the Crc_CalculateCRC32()
 * function according to AUTOSAR_SWS_CRCLibrary.pdf.
 */
#define CYFSSIG_CHECKSUM_FUNCTION(DATA_PTR, CRC_LEN, CRC_START, IS_FIRST) \
    Crc_CalculateCRC32(DATA_PTR, CRC_LEN, CRC_START, IS_FIRST)
/**
 * User-defined function-like macro that defines the error reporting routine of
 * the driver, which is switched OFF if DET is disabled.
 * The function has the following prototype:
 * void <CyFssig_DetReportError>(uint8 apiId, uint8 errorId);
 * This function should be reentrant. It can be called in the context of API
 * functions of this driver, in the context of its main function, and in the
 * context of its interrupt handlers.
 */
#define CYFSSIG_DET_ERROR_REPORT(API_ID, ERROR_ID) \
    Err_DetReportError(API_ID, ERROR_ID)
/**
 * User-defined function-like macro that defines the error reporting routine of
 * the driver, which cannot be disabled.
 * The function has the following prototype:
 * void <CyFssig_ErrorCalloutHandler>(uint8 apiId, uint8 errorId);
 * This function should be reentrant. It can be called in the context of API
 * functions of this driver, in the context of its main function, and in the
 * context of its interrupt handlers.
 */
#define CYFSSIG_ERROR_CALLOUT_HANDLER(API_ID, ERROR_ID) \
    Err_ErrorCalloutHandler(API_ID, ERROR_ID)
/**
 * User-defined macro to define the name of a callback function which indicates
 * the completion of a Timing Controller monitoring cycle. This function can be
 * used to trigger a watchdog that verifies the operability of timing
 * controller monitoring. It shall have the following prototype:
 * void <CyFssig_SupervisionCheckpointCallout>(void).
 * It is executed in the context of the main handler function of this driver when
 * both of the following conditions are met:
 * - Timing Controller monitoring was enabled with CyFssig_TconEnableEvaluation.
 * - The last Timing Controller monitoring cycle was completed.
 * The maximum duration of a Timing Controller monitoring cycle is configured with
 * the registerReadbackPeriod element of the configuration defined with
 * CYFSSIG_PRE_COMPILE_CFG.
 */
#define CYFSSIG_SUPERVISION_CHECKPOINT_CALLOUT() \
    Appl_SupervisionCheckpointCallout()

/** } end addtogroup CyFssigApiPreCmpCfg */

/*****************************************************************************
 ** Global type definitions ('typedef')
 *****************************************************************************/

/*****************************************************************************
 ** Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/*****************************************************************************
 ** CyFssig_Cfg Global function prototypes ('extern', definition in C source)
 *****************************************************************************/



#endif /*!defined(CYFSSIG_CFG_H)*/

