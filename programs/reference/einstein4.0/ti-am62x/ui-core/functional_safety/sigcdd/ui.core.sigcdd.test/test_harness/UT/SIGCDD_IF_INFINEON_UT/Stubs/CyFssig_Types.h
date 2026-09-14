/*******************************************************************************
* Product: SW_TVII_SIG_DRV
*
* (c) 2017-2021,, Cypress Semiconductor Corporation. All rights reserved.
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
 ** \file CyFssig_Types.h
 **
 ** \date       12-Okt-2017 14:52:15
 ** \addtogroup Interface CyFssig_Types
 **
*******************************************************************************/
#ifndef CYFSSIG_TYPES_H
#define CYFSSIG_TYPES_H


/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include <Platform_Types.h>
#include "CyFssig_Compiler_Cfg.h"/* Module-specific memory and pointer classes */
#include "CyFssig_Cfg.h"

/*****************************************************************************
 ** Global pre-processor symbols/macros ('#define')
 *****************************************************************************/

/** \addtogroup CyFssigApiIdentifiers */
/** \{ */

/**  API ID of CyFssig_DrvInit(). */
#define CYFSSIG_ID_DRV_INIT  ((uint8)0x01u)

/**  API ID of CyFssig_DrvDeInit(). */
#define CYFSSIG_ID_DRV_DEINIT  ((uint8)0x02u)

/**  API ID of CyFssig_DrvGetVersionInfo(). */
#define CYFSSIG_ID_DRV_GETVERSIONINFO  ((uint8)0x03u)

/**  API ID of CyFssig_DrvGetConfig(). */
#define CYFSSIG_ID_DRV_GETCONFIG  ((uint8)0x04u)

/**  API ID of CyFssig_DrvCommit(). */
#define CYFSSIG_ID_DRV_COMMIT  ((uint8)0x05u)

/**  API ID of CyFssig_DrvGetCommitStatus(). */
#define CYFSSIG_ID_DRV_GETCOMMITSTATUS  ((uint8)0x06u)

/**  API ID of CyFssig_DrvMainHandling(). */
#define CYFSSIG_ID_DRV_MAINHANDLING  ((uint8)0x07u)

/**  API ID of CyFssig_DrvGetDriverInitializationStatus(). */
#define CYFSSIG_ID_DRV_GETDRIVERINITIALIZATIONSTATUS  ((uint8)0x08u)

/**  API ID of CyFssig_SigEnableWinEvaluation(). */
#define CYFSSIG_ID_SIG_ENABLEWINEVALUATION  ((uint8)0x10u)

/**  API ID of CyFssig_SigDisableWinEvaluation(). */
#define CYFSSIG_ID_SIG_DISABLEWINEVALUATION  ((uint8)0x11u)

/**  API ID of CyFssig_SigClearEvaluation(). */
#define CYFSSIG_ID_SIG_CLEAREVALUATION  ((uint8)0x12u)

/**  API ID of CyFssig_SigSetErrorThreshold(). */
#define CYFSSIG_ID_SIG_SETERRORTHRESHOLD  ((uint8)0x13u)

/**  API ID of CyFssig_SigSetErrorNotification(). */
#define CYFSSIG_ID_SIG_SETERRORNOTIFICATION  ((uint8)0x14u)

/**  API ID of CyFssig_SigGetEvaluationStatus(). */
#define CYFSSIG_ID_SIG_GETEVALUATIONSTATUS  ((uint8)0x15u)

/**  API ID of CyFssig_SigSetWinAlphaMaskMode(). */
#define CYFSSIG_ID_SIG_SETWINALPHAMASKMODE  ((uint8)0x16u)

/**  API ID of CyFssig_SigSetWinPosition(). */
#define CYFSSIG_ID_SIG_SETWINPOSITION  ((uint8)0x17u)

/**  API ID of CyFssig_SigSetWinRefSignature(). */
#define CYFSSIG_ID_SIG_SETWINREFSIGNATURE  ((uint8)0x18u)

/**  API ID of CyFssig_SigGetWinCalSignature(). */
#define CYFSSIG_ID_SIG_GETWINCALSIGNATURE  ((uint8)0x19u)

/**  API ID of CyFssig_SigGetWinAttribute(). */
#define CYFSSIG_ID_SIG_GETWINATTRIBUTE  ((uint8)0x1Au)

/**  API ID of CyFssig_SigGetCommonAttribute(). */
#define CYFSSIG_ID_SIG_GETCOMMONATTRIBUTE  ((uint8)0x1Bu)

/**  API ID of CyFssig_TconEnableEvaluation(). */
#define CYFSSIG_ID_TCON_ENABLEEVALUATION  ((uint8)0x20u)

/**  API ID of CyFssig_TconDisableEvaluation(). */
#define CYFSSIG_ID_TCON_DISABLEEVALUATION  ((uint8)0x21u)

/**  API ID of CyFssig_TconGetEvaluationStatus(). */
#define CYFSSIG_ID_TCON_GETEVALUATIONSTATUS  ((uint8)0x22u)

/**  API ID of CyFssig_TconGetCalChecksum(). */
#define CYFSSIG_ID_TCON_GETCALCHECKSUM  ((uint8)0x23u)

/**  API ID of CyFssig_TconSetErrorNotification(). */
#define CYFSSIG_ID_TCON_SETERRORNOTIFICATION  ((uint8)0x24u)

/**  API ID of CyFssig_Display_Isr_Cat2(). */
#define CYFSSIG_ID_DRV_DISPLAY_ISR  ((uint8)0x30u)

/**  ID of the evaluation process for display stream identifier 0. This ID is used
 to indicate that the event is triggered in the evaluation process, not in the
 calling of any API function. */
#define CYFSSIG_ID_DRV_DISPLAY0_EVAL  ((uint8)0x32u)

/**  ID of the evaluation process for display stream identifier 1. This ID is used
 to indicate that the event is triggered in the evaluation process, not in the
 calling of any API function. */
#define CYFSSIG_ID_DRV_DISPLAY1_EVAL  ((uint8)0x33u)

/** \} end addtogroup CyFssigApiIdentifiers */

/** \addtogroup CyFssigErrorIdentifiers */
/** \{ */

/**  API service was used before the initialization of the module was successfully
 finished. */
#define CYFSSIG_E_UNINIT  ((uint8)0x01u)

/**  API service was called with an invalid display stream identifier. */
#define CYFSSIG_E_PARAM_DISPID  ((uint8)0x02u)

/**  API service was called with an invalid evaluation window identifier. */
#define CYFSSIG_E_PARAM_WINID  ((uint8)0x03u)

/**  API service was called with a NULL pointer as parameter. */
#define CYFSSIG_E_PARAM_NULLPTR  ((uint8)0x04u)

/**  API service was called with invalid position information. */
#define CYFSSIG_E_PARAM_POSITION  ((uint8)0x05u)

/**  API service was called with an invalid commit group flag. */
#define CYFSSIG_E_PARAM_COMMITGROUPFLAG  ((uint8)0x06u)

/**  TraveoIIFsSigDrv initialization failed (already initialized). */
#define CYFSSIG_E_INIT_FAILED  ((uint8)0x07u)

/**  Basic checks of TraveoIIFsSigDrv configuration failed. */
#define CYFSSIG_E_CONFIG_ERROR  ((uint8)0x08u)

/**  An unexpected change has occurred in the registers requested by TraveoIIFsSigDrv. */
#define CYFSSIG_E_REGISTER_MISMATCH  ((uint8)0x09u)

/**  A violation of signature evaluation detected. */
#define CYFSSIG_E_SIG_VIOLATION  ((uint8)0x0Au)

/**  A violation of checksum in the Timing Controller detected. */
#define CYFSSIG_E_TCON_VIOLATION  ((uint8)0x0Bu)

/**  API services were called at the wrong signature commit state or evaluation state. */
#define CYFSSIG_E_SIG_STATE  ((uint8)0x0Cu)

/**  API services were called at the wrong Timing Controller commit state or
 evaluation state. */
#define CYFSSIG_E_TCON_STATE  ((uint8)0x0Du)

/**  Deadline supervision detected an error. The deadline has reached. The
 corresponding interrupt handler or the corresponding interrupt for shadow load
 complete is not called. */
#define CYFSSIG_E_DEADLINE_SUPERVISION  ((uint8)0x0Eu)

/**  Alive checking failed. The following events are checked:
- When an evaluation window is enabled, the signature valid interrupt handler
is called at least once within two main function calling periods.
- The frame counter changes at least once within two main function calling
periods. */
#define CYFSSIG_E_ALIVE_CHECK  ((uint8)0x0Fu)

/**  API service was called with invalid reset threshold (0xFF). */
#define CYFSSIG_E_PARAM_RESETTHRESHOLDINFRAME  ((uint8)0x10u)

/**  API service was called with an invalid boolean value. */
#define CYFSSIG_E_PARAM_BOOLEAN  ((uint8)0x11u)

/**  Hardware is busy (not in idle state) in the initialize procedure. */
#define CYFSSIG_E_HW_BUSY ((uint8)0x12u)

/** \} end addtogroup CyFssigErrorIdentifiers */

/** \addtogroup CyFssigApiGen */
/** \{ */

/**  Commit flag for evaluation windows of display stream 0.  */
#define CYFSSIG_COMMITFLAG_SIG_0  0x01UL

/**  Commit flag for evaluation windows of display stream 1. */
#define CYFSSIG_COMMITFLAG_SIG_1  0x02UL

/**  Commit flag for Timing Controller evaluation of display stream 0.  */
#define CYFSSIG_COMMITFLAG_TCON_0  0x10UL

/**  Commit flag for Timing Controller evaluation of display stream 1. */
#define CYFSSIG_COMMITFLAG_TCON_1  0x20UL

/**  Supported tviic2d4ma0 with 2D graphics core. */
#define CYFSSIG_TVIIC2D4MA0 0x00u

/** \} end addtogroup CyFssigApiGen */

/** \addtogroup CyFssigApiGen */
/** \{ */
/**  Maximum number of display streams supported by TraveoIIFsSigDrv. */
#define CYFSSIG_MAXIMUM_DISPLAY_NUMBER  ((uint8)0x02u)
/** \} end addtogroup CyFssigApiGen */

/** \addtogroup CyFssigApiWin */
/** \{ */

/**  Maximum number of evaluation windows for one display stream supported by
 TraveoIIFsSigDrv. */
#define CYFSSIG_MAXIMUM_EVALWIN_NUMBER  ((uint8)0x08u)

/** \} end addtogroup CyFssigApiWin */


/** \addtogroup CyFssigApiGen */
/** \{ */

/**  Identifier of display stream 0 supported by TraveoIIFsSigDrv. */
#define CYFSSIG_DISPLAY_STREAM_ID_0  ((uint8)0x00u)

/**  Identifier of display stream 1 supported by TraveoIIFsSigDrv. */
#define CYFSSIG_DISPLAY_STREAM_ID_1  ((uint8)0x01u)

/** \} end addtogroup CyFssigApiGen */

/** \addtogroup CyFssigApiWin */
/** \{ */

/**  Identifier of evaluation window 0 in one display stream supported by
 TraveoIIFsSigDrv. */
#define CYFSSIG_EVALUATION_WINDOW_ID_0  ((uint8)0x00u)

/**  Identifier of evaluation window 1 in one display stream supported by
 TraveoIIFsSigDrv. */
#define CYFSSIG_EVALUATION_WINDOW_ID_1  ((uint8)0x01u)

/**  Identifier of evaluation window 2 in one display stream supported by
 TraveoIIFsSigDrv. */
#define CYFSSIG_EVALUATION_WINDOW_ID_2  ((uint8)0x02u)

/**  Identifier of evaluation window 3 in one display stream supported by
 TraveoIIFsSigDrv. */
#define CYFSSIG_EVALUATION_WINDOW_ID_3  ((uint8)0x03u)

/**  Identifier of evaluation window 4 in one display stream supported by
 TraveoIIFsSigDrv. */
#define CYFSSIG_EVALUATION_WINDOW_ID_4  ((uint8)0x04u)

/**  Identifier of evaluation window 5 in one display stream supported by
 TraveoIIFsSigDrv. */
#define CYFSSIG_EVALUATION_WINDOW_ID_5  ((uint8)0x05u)

/**  Identifier of evaluation window 6 in one display stream supported by
 TraveoIIFsSigDrv. */
#define CYFSSIG_EVALUATION_WINDOW_ID_6  ((uint8)0x06u)

/**  Identifier of evaluation window 7 in one display stream supported by
 TraveoIIFsSigDrv. */
#define CYFSSIG_EVALUATION_WINDOW_ID_7  ((uint8)0x07u)

/** \} end addtogroup CyFssigApiWin */

/** \addtogroup CyFssigApiGen */
/** \{ */

/**  Fixed protection pre-tag for the post-build configuration. */
#define CYFSSIG_PB_CFG_PRE_TAG  0x65B6C7D8UL

/**  Fixed protection post-tag for the post-build configuration. */
#define CYFSSIG_PB_CFG_POST_TAG  0x8D7CB56UL

/**  Fixed protection pre-tag for the pre-compile configuration. */
#define CYFSSIG_PC_CFG_PRE_TAG  0x71F2A3B4UL

/**  Fixed protection post-tag for the pre-compile configuration. */
#define CYFSSIG_PC_CFG_POST_TAG  0x4B3A2F17UL

/** \} end addtogroup CyFssigApiGen */

/*****************************************************************************
 ** Global type definitions ('typedef')
 *****************************************************************************/

/** \addtogroup CyFssigApiGen */

/**
 ******************************************************************************
 ** \typedef cyfssig_disp_id_type
 **
 ** Type to define the display stream identifier for an operation.
 **
 ** \ingroup CyFssigApiGen
 **
 *****************************************************************************/
typedef uint8  cyfssig_disp_id_type;

/**
 ******************************************************************************
 ** \typedef cyfssig_tcon_checksum_type
 **
 ** Type to define the checksum of the Timing Controller
 **
 ** \ingroup CyFssigApiTcon
 **
 *****************************************************************************/
typedef uint32 cyfssig_tcon_checksum_type;

/**
 ******************************************************************************
 ** \typedef cyfssig_win_id_type
 **
 ** Type to define the evaluation window identifier
 **
 ** \ingroup CyFssigApiWin
 **
 *****************************************************************************/
typedef uint8  cyfssig_win_id_type;

/**
 ******************************************************************************
 ** \enum cyfssig_commit_status_type
 **
 ** Enumeration of the commit status for signature evaluation and Timing Controller
 ** evaluation.
 **
 ** \ingroup CyFssigApiGen
 **
 *****************************************************************************/
typedef enum
{
    /**  Commit request is on-going.
     For signature evaluation: the commit completion interrupt does not occur.
     For Timing Controller evaluation: the main function after the request is not
     called. */
    CYFSSIG_COMMIT_ONGOING = 0,
    /**  Commit request is already completed.  */
    CYFSSIG_COMMIT_DONE    = 1
} cyfssig_commit_status_type ;

/**
 ******************************************************************************
 ** \enum cyfssig_drv_initialization_status_type
 **
 ** Enumeration used as the initialization status of the driver.
 **
 ** \ingroup CyFssigApiGen
 **
 *****************************************************************************/
typedef enum
{
    /**  Driver is not initialized. */
    CYFSSIG_DRIVER_NOT_INITIALIZED = 0,
    /**  Driver is initialized. */
    CYFSSIG_DRIVER_INITIALIZED     = 1
} cyfssig_drv_initialization_status_type ;

/**
 ******************************************************************************
 ** \enum cyfssig_return_type
 **
 ** Enumeration used as the return value type for functions.
 **
 ** \ingroup CyFssigApiGen
 **
 *****************************************************************************/
typedef enum
{
    /**  Function is returned with failure. */
    CYFSSIG_NOT_OK = 1,
    /**  Function executed successfully. */
    CYFSSIG_OK     = 0
} cyfssig_return_type ;

/**
 ******************************************************************************
 ** \enum cyfssig_sig_evaluation_state_type
 **
 ** Enumeration of signature evaluation state.
 **
 ** \ingroup CyFssigApiSig
 **
 *****************************************************************************/
typedef enum
{
    /**  State indicates that the evaluation of each evaluation window is disabled. */
    CYFSSIG_SIG_EVAL_DISABLED    = 0,
    /**  State indicates that the evaluation of each evaluation window is on-going. */
    CYFSSIG_SIG_EVAL_CALCULATING = 1,
    /**  State indicates that the evaluation of each evaluation window is done. */
    CYFSSIG_SIG_EVAL_DONE        = 2,
    /**  State indicates that the evaluation of each evaluation window is being disabled.*/
    CYFSSIG_SIG_EVAL_DISABLING   = 3,
    /**  State indicates that an error has occurred in the evaluation of each evaluation window, and re-initialization
         is required. */
    CYFSSIG_SIG_EVAL_ERROR       = 4
} cyfssig_sig_evaluation_state_type ;

/**
 ******************************************************************************
 ** \enum cyfssig_sig_signature_result_type
 **
 ** Enumeration of the hardware signature result.
 **
 ** \ingroup CyFssigApiSig
 **
 *****************************************************************************/
typedef enum
{
    /**  Measured signature values are the same as the given reference signature. */
    CYFSSIG_SIG_SIGNATURE_NO_VIOLATION = 0,
    /**  Measured signature values are different from the given reference signature. */
    CYFSSIG_SIG_SIGNATURE_VIOLATION    = 1
} cyfssig_sig_signature_result_type ;

/**
 ******************************************************************************
 ** \enum cyfssig_sig_source_select_type
 **
 ** Enumeration of the signature source select.
 **
 ** \ingroup CyFssigApiSig
 **
 *****************************************************************************/
typedef enum
{
    /**  Signature source is from the Frame output. */
    CYFSSIG_SIG_SOURCE_SELECT_FRAMEGEN = 1,
    /**  Signature source is from the Gamma output. */
    CYFSSIG_SIG_SOURCE_SELECT_GAMMACOR = 2,
    /**  Signature source is from the Dither output. */
    CYFSSIG_SIG_SOURCE_SELECT_DITHER   = 3,
    /**  Signature source is invalid. */
    CYFSSIG_SIG_SOURCE_SELECT_INVALID  = 4
} cyfssig_sig_source_select_type ;

/**
 ******************************************************************************
 ** \enum cyfssig_tcon_checksum_result_type
 **
 ** Enumeration of the Timing Controller checksum result.
 **
 ** \ingroup CyFssigApiTcon
 **
 *****************************************************************************/
typedef enum
{
    /**  Measured checksum values are the same as the given checksum. */
    CYFSSIG_TCON_CHECKSUM_NO_VIOLATION = 0,
    /**  Measured checksum values are different from the given checksum. */
    CYFSSIG_TCON_CHECKSUM_VIOLATION    = 1
} cyfssig_tcon_checksum_result_type ;

/**
 ******************************************************************************
 ** \enum cyfssig_tcon_evaluation_state_type
 **
 ** Enumeration of the Timing Controller evaluation state.
 **
 ** \ingroup CyFssigApiTcon
 **
 *****************************************************************************/
typedef enum
{
    /**  State indicates that the evaluation of the Timing Controller is disabled. */
    CYFSSIG_TCON_EVAL_DISABLED    = 0,
    /**  State indicates that the evaluation of the Timing Controller is on-going. */
    CYFSSIG_TCON_EVAL_CALCULATING = 1,
    /**  State indicates that the evaluation of the Timing Controller is completed. */
    CYFSSIG_TCON_EVAL_DONE        = 2
} cyfssig_tcon_evaluation_state_type ;

/**
 ******************************************************************************
 ** \struct cyfssig_version_info_type
 **
 ** Structure of the TraveoIIFsSigDrv version information data.
 **
 ** \ingroup CyFssigApiGen
 **
 *****************************************************************************/
typedef struct
{
    /**  IP Identifier read from the hardware register. */
    uint32 ipIdentifier;

    /**  Software major version. */
    uint8 swMajorVersion;

    /**  Software minor version. */
    uint8 swMinorVersion;

    /**  Software patch version. */
    uint8 swPatchVersion;
}  cyfssig_version_info_type ;

/**
 ******************************************************************************
 ** \struct cyfssig_sig_win_position_type
 **
 ** Structure of the evaluation window position data.
 **
 ** \ingroup CyFssigApiWin
 **
 *****************************************************************************/
typedef struct
{
    /**  X coordinate of the top-left corner of the evaluation window. */
    uint16 topLeftX;

    /**  Y coordinate of the top-left corner of the evaluation window. */
    uint16 topLeftY;

    /**  Width of the evaluation window. */
    uint16 width;

    /**  Height of the evaluation window. */
    uint16 height;
}  cyfssig_sig_win_position_type ;

/**
 ******************************************************************************
 ** \struct cyfssig_sig_signature_type
 **
 ** Structure of the signature data.
 **
 ** \ingroup CyFssigApiWin
 **
 *****************************************************************************/
typedef struct
{
    /**  CRC values from the red channel. */
    uint32 sigRed;

    /**  CRC values from the green channel. */
    uint32 sigGreen;

    /**  CRC values from the blue channel. */
    uint32 sigBlue;
}  cyfssig_sig_signature_type ;

/**
 ******************************************************************************
 ** \struct cyfssig_sig_win_attribute_type
 **
 ** Structure of the evaluation window attribute.
 **
 ** \ingroup CyFssigApiWin
 **
 *****************************************************************************/
typedef struct
{
    /**  A flag that indicates if alpha masking is enabled for an evaluation window. */
    boolean winAlphaMaskEnabled;

    /**  Position information of an evaluation window. */
    cyfssig_sig_win_position_type winPosition;

    /**  Reference signature value of an evaluation window. */
    cyfssig_sig_signature_type winRefSignature;
}  cyfssig_sig_win_attribute_type ;

/**
 ******************************************************************************
 ** \struct cyfssig_sig_error_threshold_type
 **
 ** Structure of the signature error threshold data, which is used for the hysteresis
 ** effect for the set/reset signature error status.
 **
 ** \ingroup CyFssigApiWin
 **
 *****************************************************************************/
typedef struct
{
    /**  Number of consecutive frames without signature violation before an error is
     reset for an evaluation window. Range from 0 to 254. */
    uint8 resetThreshold;

    /**  Number of frames with signature violation before an error is set for an
     evaluation window. Range from 0 to 255. */
    uint8 setThreshold;
}  cyfssig_sig_error_threshold_type ;

/**
 ******************************************************************************
 ** \struct cyfssig_sig_attribute_type
 **
 ** Structure of common runtime attribute settings related to all evaluation
 ** windows of a display stream.
 **
 ** \ingroup CyFssigApiWin
 **
 *****************************************************************************/
typedef struct
{
    /**  Flag indicates whether error notification is currently enabled.
     TRUE: Error report about signature mismatch will be given to the
     environment.
     FALSE: Error report about signature mismatch will not be given to
     the environment. */
    boolean errorNotificationEnabled;

    /**  Structure of the current error threshold setting. */
    cyfssig_sig_error_threshold_type errorThreshold;
}  cyfssig_sig_attribute_type ;

/**
 ******************************************************************************
 ** \struct cyfssig_display_config_type
 **
 ** Structure of pre-compile configuration data for each display stream.
 **
 ** \ingroup CyFssigApiGen
 **
 *****************************************************************************/
typedef struct
{
    /**  Identifier of the display stream that the following settings are related to.
     Can be set to CYFSSIG_DISPLAY_STREAM_ID_0 or CYFSSIG_DISPLAY_STREAM_ID_1. */
    cyfssig_disp_id_type dispId;

    /**  Maximum count of evaluation windows per display stream. Range is 1 to 8. */
    uint8 evaluationWindowCount;

    /**  Number of main function calls within which the driver completely verifies
     all registers under its control. The driver uses this parameter to spread
     the register read-back operation over multiple main function calls.
     Range is 1 to 255. */
    uint8 registerReadbackPeriod;

    /**  Select the signal source for evaluation window signature calculation. */
    cyfssig_sig_source_select_type signatureSourceSelect;
}  cyfssig_display_config_type ;

/**
 ******************************************************************************
 ** \struct cyfssig_pb_config_type
 **
 ** Structure of TraveoIIFsSigDrv post-build configuration data.
 **
 ** \ingroup CyFssigApiGen
 **
 *****************************************************************************/
typedef struct
{
    /**  Pre-data tag for the post-build configuration. This tag is fixed-value
     (CYFSSIG_PB_CFG_PRE_TAG). This data tag protection is used to verify the
     validity of pointers to configuration data. */
    uint32 tagPbConfig_Pre;

    /**  Reference checksums. The number of elements is defined by
     CYFSSIG_MAXIMUM_DISPLAY_NUMBER. */
    cyfssig_tcon_checksum_type tconChecksum[CYFSSIG_MAXIMUM_DISPLAY_NUMBER];

    /**  Post-data tag for the post-build configuration. This tag is fixed-value
     (CYFSSIG_PB_CFG_POST_TAG). This data tag protection is used to verify the
     validity of pointers to configuration data. */
    uint32 tagPbConfig_Post;
}  cyfssig_pb_config_type ;

/**
 ******************************************************************************
 ** \struct cyfssig_pc_config_type
 **
 ** Structure of the TraveoIIFsSigDrv pre-compile configuration data.
 **
 ** \ingroup CyFssigApiGen
 **
 *****************************************************************************/
typedef struct
{
    /**  Pre-data tag for the pre-compile configuration. This tag is fixed-value
     (CYFSSIG_PC_CFG_PRE_TAG). This data tag protection is used to verify the
     validity of pointers to the configuration data. */
    uint32 tagPcConfig_Pre;

    /**  Supported TRAVEO T2G derivative. */
    uint8 hardwareDerivative;

    /**  Array for configuration of display streams. */
    cyfssig_display_config_type displaySettings[CYFSSIG_CFG_NUMBER_OF_DISPLAY_SETTING];

    /**  Post-data tag for the pre-compile configuration. This tag is fixed-value
     (CYFSSIG_PC_CFG_POST_TAG). This data tag protection is used to verify the
     validity of pointers to the configuration data. */
    uint32 tagPcConfig_Post;
}  cyfssig_pc_config_type ;

/**
 ******************************************************************************
 ** \struct cyfssig_config_type
 **
 ** Structure of the TraveoIIFsSigDrv configuration data.
 **
 ** \ingroup CyFssigApiGen
 **
 *****************************************************************************/
typedef struct
{
    /**  Pointer to the post-build configuration data. */
    cyfssig_pb_config_type *pbConfigPtr;

    /**  Pointer to the pre-compile configuration data. */
    cyfssig_pc_config_type *pcConfigPtr;
}  cyfssig_config_type ;

/**
 ******************************************************************************
 ** \struct cyfssig_sig_status_type
 **
 ** Structure of the signature information including the signature evaluation status and
 ** hardware signature status.
 **
 ** \ingroup CyFssigApiSig
 **
 *****************************************************************************/
typedef struct
{
    /**  Evaluation window status: one status element for each evaluation window. */
    cyfssig_sig_evaluation_state_type evaluationState[CYFSSIG_MAXIMUM_EVALWIN_NUMBER];

    /**  Hardware signature result: One result for each evaluation window reflecting the
     actual hardware status of the signatures with regard to their reference values. */
    cyfssig_sig_signature_result_type signatureResult[CYFSSIG_MAXIMUM_EVALWIN_NUMBER];
}  cyfssig_sig_status_type ;

/**
 ******************************************************************************
 ** \struct cyfssig_tcon_status_type
 **
 ** Structure of the Timing Controller status data including the evaluation status and
 ** checksum status.
 **
 ** \ingroup CyFssigApiTcon
 **
 *****************************************************************************/
typedef struct
{
    /**  The state of evaluation of the Timing Controller. */
    cyfssig_tcon_evaluation_state_type evaluationState;

    /**  Result of check between the measured checksum and given checksum for the
     Timing Controller. */
    cyfssig_tcon_checksum_result_type checksumResult;
}  cyfssig_tcon_status_type ;

/*****************************************************************************
 ** Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/*****************************************************************************
 ** CyFssig_Types Global function prototypes ('extern', definition in C source)
 *****************************************************************************/



#endif /*!defined(CYFSSIG_TYPES_H)*/
