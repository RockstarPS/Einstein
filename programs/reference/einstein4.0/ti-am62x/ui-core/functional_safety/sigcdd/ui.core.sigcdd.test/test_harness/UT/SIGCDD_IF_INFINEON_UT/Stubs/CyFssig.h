/*******************************************************************************
* Product: SW_TVII_SIG_DRV
*
* (c) 2017-2021, Cypress Semiconductor Corporation. All rights reserved.
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
 ** \file CyFssig.h
 **
 ** \date       03-Nov-2017 11:04:03
 ** \addtogroup Interface CyFssig
 **
*******************************************************************************/
#ifndef CYFSSIG_H
#define CYFSSIG_H


/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "CyFssig_Cfg.h"
#include "CyFssig_Types.h"


/*****************************************************************************
 ** Global pre-processor symbols/macros ('#define')
 *****************************************************************************/


/*****************************************************************************
 ** Global type definitions ('typedef')
 *****************************************************************************/

/*****************************************************************************
 ** Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/*****************************************************************************
 ** CyFssig Global function prototypes ('extern', definition in C source)
 *****************************************************************************/
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to initialize TraveoIIFsSigDrv with the reference checksum given by the
 * parameter. This initialization function configures all hardware units of the
 * graphics engine that are under the control of this driver, and prepares the driver-
 * internal data for safe operation. This function uses pre-compile-time
 * configuration data and runtime arguments to initialize all registers of
 * hardware units under the control of this driver.
 *
 * After the environment deinitializes TraveoIIFsSigDrv with a call of
 * CyFssig_DrvDeInit, the hardware can continue to be busy for up to the duration
 * of two display frames. If CyFssig_DrvInit is called during this period, it
 * returns CYFSSIG_NOT_OK and reports a CYFSSIG_E_HW_BUSY error. In this case, the
 * environment should call CyFssig_DrvInit again after the end of the current
 * display frame.
 *
 * The function returns one of the following values:
 * - CYFSSIG_NOT_OK: Initialization is aborted with failure.
 * - CYFSSIG_OK: Initialization is successfully finished.
 *
 * In case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_INIT_FAILED
 * - CYFSSIG_E_PARAM_NULLPTR
 * - CYFSSIG_E_CONFIG_ERROR
 * - CYFSSIG_E_HW_BUSY
 * \endif
 * \ingroup CyFssigApiGen
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_DrvInit(
    const cyfssig_pb_config_type *const pbConfigPtr);

/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to deinitialize TraveoIIFsSigDrv, which puts the hardware into its
 * initial state, and resets the driver-internal data for
 * safe operation. This function can be called regardless of the driver state and can
 * be called multiple times one after another.
 *
 * The CyFssig_DrvDeInit function resets the registers used by TraveoIIFsSigDrv to
 * their initial values. The SrcSelect registers of the DisEngCfg
 * unit are exceptions. CyFssig_DrvDeInit preserves the values of these
 * registers so that the signature hardware unit continues to receive an input
 * signal and is able to finish its deinitialization. This deinitialization can
 * take up to the duration of two display frames. During this period,
 * TraveoIIFsSigDrv cannot be reinitialized.
 *
 * This function always returns CYFSSIG_OK.
 *
 * This function does not report errors.
 * \endif
 * \ingroup CyFssigApiGen
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_DrvDeInit(
    void);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to get the current TraveoIIFsSigDrv software version information and
 * graphics hardware version information. This function succeeds regardless of the
 * state of the driver. The information provided by this function comprises the
 * driver software version information and data from the VIDEOSSCFG.IPIdentifier register; this is
 * written to the location specified by the versionInfoPtr parameter.
 *
 * In the case of an error, the function reports the following error code:
 * - CYFSSIG_E_PARAM_NULLPTR
 * \endif
 * \ingroup CyFssigApiGen
 */
extern FUNC(void, CYFSSIG_CODE) CyFssig_DrvGetVersionInfo(
    cyfssig_version_info_type *const versionInfoPtr);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to get the current driver-related configuration. The configPtr
 * parameter is expected to point to a structure of cyfssig_config_type. The
 * elements of that structure are pointers to the memory areas that will be filled
 * with the configuration data by this function.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports the following error code:
 * - CYFSSIG_E_PARAM_NULLPTR
 * \endif
 * \ingroup CyFssigApiGen
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_DrvGetConfig(
    cyfssig_config_type *const configPtr);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to apply all previously "collected" settings related to one or
 * multiple function groups. This function applies the modifications related to
 * the selected function groups synchronously to each other and synchronously to
 * the frame generation of the corresponding display. This function has an
 * argument that selects the function groups to be included by the commit
 * operation.
 * There are four commit flags available now:
 * - CYFSSIG_COMMITFLAG_SIG_0 (0x01): Commit flag for evaluation windows in
 * display stream 0.
 * - CYFSSIG_COMMITFLAG_SIG_1 (0x02): Commit flag for evaluation windows in
 * display stream 1.
 * - CYFSSIG_COMMITFLAG_TCON_0 (0x10): Commit flag for Timing Controller
 * evaluation in display stream 0.
 * - CYFSSIG_COMMITFLAG_TCON_1 (0x20): Commit flag for Timing Controller
 * evaluation in display stream 1.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The corresponding settings are successfully applied.
 * - CYFSSIG_NOT_OK: This commit request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_COMMITGROUPFLAG
 * - CYFSSIG_E_SIG_STATE
 * - CYFSSIG_E_TCON_STATE
 * \endif
 * \ingroup CyFssigApiGen
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_DrvCommit(
    const uint32 commitGroupFlags);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to query the current status of a commit operation. The commit status
 * is returned in the given parameter (commitStatusPtr) according to the given
 * parameter (commitGroupFlag).
 *
 * There are four commit flags for the parameter (commitGroupFlag) available now:
 * - CYFSSIG_COMMITFLAG_SIG_0 (0x01): Commit flag for evaluation windows in
 * display stream 0.
 * - CYFSSIG_COMMITFLAG_SIG_1 (0x02): Commit flag for evaluation windows in
 * display stream 1.
 * - CYFSSIG_COMMITFLAG_TCON_0 (0x10): Commit flag for Timing Controller
 * evaluation in display stream 0.
 * - CYFSSIG_COMMITFLAG_TCON_1 (0x20): Commit flag for Timing Controller
 * evaluation in display stream 1.
 *
 * There are two commit status to return in the parameter (commitStatusPtr):
 * - CYFSSIG_COMMIT_ONGOING (0x00): Commit is still on-going.
 * - CYFSSIG_COMMIT_DONE (0x01): Commit is already completed.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_NULLPTR
 * - CYFSSIG_E_PARAM_COMMITGROUPFLAG
 * \endif
 * \ingroup CyFssigApiGen
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_DrvGetCommitStatus(
    const uint32 commitGroupFlag,
    cyfssig_commit_status_type *const commitStatusPtr);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to provide health check and hardware status monitoring.
 * This function must be called periodically. The calling period is
 * recommended to be greater than the frame rate of the display stream
 * and smaller than half of the fault-tolerant time.
 * There is no parameter and return value for this function.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_DEADLINE_SUPERVISION
 * - CYFSSIG_E_ALIVE_CHECK
 * \endif
 * \ingroup CyFssigApiGen
 */
extern FUNC(void, CYFSSIG_CODE) CyFssig_DrvMainHandling(
    void);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to enable the given evaluation window in the given display stream.
 * This function activates monitoring (calculation of signature values,
 * comparison with reference signature values, and generation of error notifications).
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_WINID
 * - CYFSSIG_E_SIG_STATE
 * \endif
 * \ingroup CyFssigApiWin
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_SigEnableWinEvaluation(
    const cyfssig_disp_id_type dispId,
    const cyfssig_win_id_type winId);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to disable the given evaluation window in the given display stream.
 * This function deactivates monitoring (including error notifications)
 * for this evaluation window.
 *
 * The function returns one of the values below:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_WINID
 * - CYFSSIG_E_SIG_STATE
 * \endif
 * \ingroup CyFssigApiWin
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_SigDisableWinEvaluation(
    const cyfssig_disp_id_type dispId,
    const cyfssig_win_id_type winId);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to clear the signature evaluation status for all evaluation windows
 * within the given display stream (while evaluation windows are enabled). As a result,
 * all calculated signatures are considered "invalid" until the end of the
 * next signature calculation cycle.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * \endif
 * \ingroup CyFssigApiWin
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_SigClearEvaluation(
    const cyfssig_disp_id_type dispId);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to set error thresholds for all evaluation windows within one display
 * stream (while all evaluation windows in that stream are disabled). Error
 * threshold is given by the errorThresholdPtr parameter.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_NULLPTR
 * - CYFSSIG_E_PARAM_RESETTHRESHOLDINFRAME
 * \endif
 * \ingroup CyFssigApiWin
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_SigSetErrorThreshold(
    const cyfssig_disp_id_type dispId,
    const cyfssig_sig_error_threshold_type *const errorThresholdPtr);

#if (CYFSSIG_DISABLE_EVALWIN_ERROR_MASK_API == FALSE)
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to disable/enable signature evaluation error detection of the
 * given display stream and stop/resume signature evaluation error
 * notification. The presence of this function is subject to a pre-compile-
 * time configuration parameter.
 * If the sigNotificationEnabled parameter is TRUE, signature evaluation error is
 * reported by the detection.
 * If the sigNotificationEnabled parameter is FALSE, signature evaluation error is
 * not reported by the detection.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_BOOLEAN
 * \endif
 * \ingroup CyFssigApiWin
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_SigSetErrorNotification(
    const cyfssig_disp_id_type dispId,
    const boolean sigNotificationEnabled);
#endif

/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to query the signature evaluation status of the given display stream.
 * Signature evaluation status is returned within the sigStatusPtr parameter.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_NULLPTR
 * \endif
 * \ingroup CyFssigApiWin
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_SigGetEvaluationStatus(
    const cyfssig_disp_id_type dispId,
    cyfssig_sig_status_type *const sigStatusPtr);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to enable or disable alpha mask mode of the given evaluation
 * window in the given display stream. Alpha mask mode is given by the
 * alphaMaskEnabled parameter.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_WINID
 * - CYFSSIG_E_PARAM_BOOLEAN
 * \endif
 * \ingroup CyFssigApiWin
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_SigSetWinAlphaMaskMode(
    const cyfssig_disp_id_type dispId,
    const cyfssig_win_id_type winId,
    const boolean alphaMaskEnabled);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to update the position and size of the given evaluation window in the
 * given display stream. The position and size are given in the
 * winPositionPtr parameter.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_WINID
 * - CYFSSIG_E_PARAM_NULLPTR
 * - CYFSSIG_E_PARAM_POSITION
 * \endif
 * \ingroup CyFssigApiWin
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_SigSetWinPosition(
    const cyfssig_disp_id_type dispId,
    const cyfssig_win_id_type winId,
    const cyfssig_sig_win_position_type *const winPositionPtr);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to set the reference signature of the given evaluation window in the given
 * display stream. Reference signatures are given by the refSignaturePtr parameter.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_WINID
 * - CYFSSIG_E_PARAM_NULLPTR
 * \endif
 * \ingroup CyFssigApiWin
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_SigSetWinRefSignature(
    const cyfssig_disp_id_type dispId,
    const cyfssig_win_id_type winId,
    const cyfssig_sig_signature_type *const refSignaturePtr);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to query the calculated signatures of the given evaluation window in the
 * given display stream. The signature is returned within the
 * calSignaturePtr parameter.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_WINID
 * - CYFSSIG_E_PARAM_NULLPTR
 * - CYFSSIG_E_SIG_STATE
 * \endif
 * \ingroup CyFssigApiWin
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_SigGetWinCalSignature(
    const cyfssig_disp_id_type dispId,
    const cyfssig_win_id_type winId,
    cyfssig_sig_signature_type *const calSignaturePtr);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to query the runtime settings of the given evaluation window in the
 * given display stream. The settings are returned within the
 * sigWinAttrPtr parameter.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_WINID
 * - CYFSSIG_E_PARAM_NULLPTR
 * \endif
 * \ingroup CyFssigApiWin
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_SigGetWinAttribute(
    const cyfssig_disp_id_type dispId,
    const cyfssig_win_id_type winId,
    cyfssig_sig_win_attribute_type *const sigWinAttrPtr);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to query the common runtime settings of the given display stream. The
 * settings are returned within the sigAttrPtr parameter.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_NULLPTR
 * \endif
 * \ingroup CyFssigApiWin
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_SigGetCommonAttribute(
    const cyfssig_disp_id_type dispId,
    cyfssig_sig_attribute_type *const sigAttrPtr);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to enable the periodic evaluation of the contents of the register
 * space that is associated with the timing controller in the given display stream.
 * The checksum is started to be calculated in the next calling of the main function,
 * and the calculated checksum is compared with the reference checksum provided as
 * post-build configuration parameter. When the calculated checksum differs from
 * the reference checksum, an error is detected and reported in the main function.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * \endif
 * \ingroup CyFssigApiTcon
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_TconEnableEvaluation(
    const cyfssig_disp_id_type dispId);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to stop the periodic evaluation of the contents of the register space
 * that is associated with the timing controller in the given display stream.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * \endif
 * \ingroup CyFssigApiTcon
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_TconDisableEvaluation(
    const cyfssig_disp_id_type dispId);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to query the timing controller evaluation status of the given display
 * stream. The status is returned within the [tconStatusPtr] parameter.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_NULLPTR
 * \endif
 * \ingroup CyFssigApiTcon
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_TconGetEvaluationStatus(
    const cyfssig_disp_id_type dispId,
    cyfssig_tcon_status_type *const tconStatusPtr);

#if (CYFSSIG_DISABLE_TCON_ERROR_MASK_API == FALSE)
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to disable/enable timing controller evaluation error detection of
 * the given display stream. As a result, the driver stops/resumes issuing
 * error notifications on checksum mismatch. The presence of this function is
 * subject to a pre-compile-time configuration parameter.
 * If the tconNotificationEnabled parameter is TRUE, timing controller evaluation
 * error is reported by the detection.
 * If the tconNotificationEnabled parameter is FALSE, timing controller evaluation
 * error is not reported by the detection.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * \endif
 * \ingroup CyFssigApiTcon
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_TconSetErrorNotification(
    const cyfssig_disp_id_type dispId,
    const boolean tconNotificationEnabled);
#endif

/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to get the current driver operational status.
 *
 * The function returns one of the values below:
 * - CYFSSIG_DRIVER_INITIALIZED: the driver is initialized
 * - CYFSSIG_DRIVER_NOT_INITIALIZED: the driver is un-initialized
 *
 * The function does not report errors.
 * \endif
 * \ingroup CyFssigApiGen
 */
extern FUNC(cyfssig_drv_initialization_status_type, CYFSSIG_CODE) CyFssig_DrvGetDriverInitializationStatus(
    void);
/**
 * \if INCLUDE_FUNCTION_DECLARATION_DESCRIPTION
 * Function to query the calculated checksum of the given display stream. The checksum
 * was calculated over the contents of the register space associated with the
 * timing controller. The checksum is returned within the
 * tconCalChecksumPtr parameter.
 *
 * The function returns one of the following values:
 * - CYFSSIG_OK: The request is successfully finished.
 * - CYFSSIG_NOT_OK: The request failed.
 *
 * In the case of an error, the function reports one of the following error codes:
 * - CYFSSIG_E_UNINIT
 * - CYFSSIG_E_PARAM_DISPID
 * - CYFSSIG_E_PARAM_NULLPTR
 * - CYFSSIG_E_TCON_STATE
 * \endif
 * \ingroup CyFssigApiTcon
 */
extern FUNC(cyfssig_return_type, CYFSSIG_CODE) CyFssig_TconGetCalChecksum(
    const cyfssig_disp_id_type dispId,
    cyfssig_tcon_checksum_type *const tconCalChecksumPtr);



#endif /*!defined(CYFSSIG_H)*/
