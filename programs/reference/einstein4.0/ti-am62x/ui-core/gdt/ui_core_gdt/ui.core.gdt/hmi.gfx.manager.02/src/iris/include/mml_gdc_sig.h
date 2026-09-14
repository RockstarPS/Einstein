/********************************************************************/
/*          (c) 2011 Fujitsu Semiconductor Europe GmbH              */
/*                                                                  */
/* ALL RIGHTS RESERVED. No part of this publication may be copied   */
/* and provided to any third party in any form or by any means      */
/* without the written permission of Fujitsu, unless expressly      */
/* agreed to in written form by Fujitsu.                            */
/* All trademarks used in this document are the property of their   */
/* respective owners.                                               */
/*                                                                  */
/* For further provisions please refer to the respective License    */
/* Agreement.                                                       */
/* (V1.3)                                                           */
/********************************************************************/

/*!
 * \author      Fujitsu GCC Neuried
 * \version     0.01
 * \date        2010
 * \file        mml_gdc_sig.h
 *              Signature unit API
 * \brief       High level / API functions for Iris signature unit
 *
 */


/**
 * @defgroup irissig Signature unit API
 *  The Signature unit API provides all functions to make use of the
 *  signature functionality.

 * ATTENTION:\n
 * In contradiction to other API functions, these functions are NOT routed
 * via the command sequencer, but executed immediately!\n
 * The user should be aware of this special behavior and shall take steps
 * for synchronization of signature functions with other functions, if necessary
 * (e.g. functions for blit operations).
 * @{
 **/


#ifndef MML_GDC_SIG_H
#define MML_GDC_SIG_H

#ifdef __cplusplus
    extern "C"
    {
#endif

/*****************************************************************************/
/*** INCLUDES ****************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** DEFINITIONS *************************************************************/
/*****************************************************************************/

/**
 * Error values returned from this API.
 */
#define MML_ERR_GDC_SIG_INVALID_DEVICE       MM_ERRCODE(0xC00C0D01)  /*!< Wrong device identifier */

/*****************************************************************************/
/*** TYPES / STRUCTURES ******************************************************/
/*****************************************************************************/

typedef enum
{
    MML_GDC_SIG_UNIT_0             = 0x00      /*!< Signager Unit 0 */
} MML_GDC_SIG_UNIT;                            /*!< Signager unit enum (must be MML_GDC_SIG_UNIT_0) */


typedef enum
{
    MML_GDC_SIG_STATUS_PENDING             = 0x00,     /*!< SR signature generation pending */
    MML_GDC_SIG_STATUS_ACTIVE,                         /*!< SR signature generation active */
    MML_GDC_SIG_STATUS_DIFFA_RED,                      /*!< SR signature A comparison active R with reference value */
    MML_GDC_SIG_STATUS_DIFFA_GREEN,                         /*!< SR signature A comparison active G with reference value */
    MML_GDC_SIG_STATUS_DIFFA_BLUE,                         /*!< SR signature A comparison active B with reference value */
    MML_GDC_SIG_STATUS_DIFFB_RED,                         /*!< SR signature B comparison active R with reference value */
    MML_GDC_SIG_STATUS_DIFFB_GREEN,                         /*!< SR signature B comparison active G with reference value */
    MML_GDC_SIG_STATUS_DIFFB_BLUE                          /*!< SR signature B comparison active B with reference value */
} MML_GDC_SIG_STATUS;                                    /*!< Status register fields */

typedef enum
{
    MML_GDC_SIG_MASKMODE_NOMASK            = 0x00,     /*!< Mask mode is no masking */
    MML_GDC_SIG_MASKMODE_MASKINSIDE        = 0x01,     /*!< Mask mode is mask inside mask window */
    MML_GDC_SIG_MASKMODE_MASKOUTSIDE       = 0x02      /*!< Mask mode is mask outside mask window */
} MML_GDC_SIG_MASKMODE;

typedef enum
{
    MML_GDC_SIG_SOURCE_SELECT_PRE_DITHER   = 0x00,     /*!< Signal is checked without dithering */
    MML_GDC_SIG_SOURCE_SELECT_POST_DITHER  = 0x01      /*!< Signal is checked dithering artifacts */
} MML_GDC_SIG_SOURCE_SELECT;

typedef enum
{
    MML_GDC_SIG_TRIGGER_MODE_ONCE          = 0x00,     /*!< set trigger mode (one single generation with next frame) and enable sig interrupts */
    MML_GDC_SIG_TRIGGER_MODE_CYCLIC        = 0x01,     /*!< set trigger mode (continuous generation on every frame) and enable sig interrupts */
    MML_GDC_SIG_TRIGGER_MODE_SW_NEVER      = 0x11      /*!< SW mode: set hw to trigger once and disable sig interrupts */
} MML_GDC_SIG_TRIGGER_MODE;

typedef enum
{
    MML_GDC_SIG_COLOR_CHANNEL_R            = 0x00,     /*!< color channel R */
    MML_GDC_SIG_COLOR_CHANNEL_G            = 0x01,     /*!< color channel G */
    MML_GDC_SIG_COLOR_CHANNEL_B            = 0x02      /*!< color channel B */
} MML_GDC_SIG_COLOR_CHANNEL;


/* ExtDst alpha bit output pixel value for SIG unit */
typedef enum
{
    MML_GDC_SIG_ALPHA_MODE_OFF           = 0x0,    /*!< 0x0 : alpha output is 0 */
    MML_GDC_SIG_ALPHA_MODE_ON              = 0x1,    /*!< 0x1 : alpha output is 1 */
    MML_GDC_SIG_ALPHA_MODE_OR              = 0x2,    /*!< 0x2 : alpha output is or-ed input, i.e. alpha is > 0 */
    MML_GDC_SIG_ALPHA_MODE_AND             = 0x3,    /*!< 0x3 : alpha output is and-ed input, i.e. alpha is 1 if alpha is totally opaque */
    MML_GDC_SIG_ALPHA_MODE_MSBIT           = 0x4     /*!< 0x4 : alpha output is MSB of input alpha */
} MML_GDC_SIG_ALPHA_MODE;

/*****************************************************************************/
/*** FUNCTION PROTOTYPES *****************************************************/
/*****************************************************************************/

/** @name Iris SIG Processing Functions (Normal Operation)
 * @{
 */

/**
 * [SWDD5001] Lock Unlock Key Protection SIG
 * \cond Related to SWAD000, SWAD501 \endcond
 *
 * Configure Key Protection state of signature unit.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] locked Configure the state of SIG key protection.
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSigSetKeyProtection(MML_GDC_SIG_UNIT eUnit, MM_BOOL locked);

/**
 * [SWDD5002] Check Lock State Key Protection SIG
 * \cond Related to SWAD000, SWAD501 \endcond
 *
 * Check a lock state of Key Protection of signature unit.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @return MM_TRUE, if the key protection is locked. MM_FALSE if it is unlocked.
 **/
IRIS_API MM_BOOL mmlGdcSigIsKeyProtectionLocked(MML_GDC_SIG_UNIT eUnit);

/**
 * [SWDD5010] Enables or disables SIG checksum.
 * \cond Related to SWAD000, SWAD502 \endcond
 *
 * Enables or disables SIG checksum.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] enableCrc32 Enable/disable CRC-32 checksum.
 *  @param[in] enableSum Enable/disable summation checksum.
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSigEnableChecksum(MML_GDC_SIG_UNIT eUnit, MM_BOOL enableCrc32, MM_BOOL enableSum);

/**
 * [SWDD5020] Set Reference Values
 * \cond Related to SWAD000, SWAD503 \endcond
 *
 * Set reference values.
 * The reference values have to be set per checksum generation type and per color channel.
 * The reference values will be used for monitoring the calculated signature values.
 * When a difference is detected an interrupt can be generated and the error counter will be incremented.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] ulARefR Reference value for CRC-32 checksum and red color channel
 *  @param[in] ulARefG Reference value for CRC-32 checksum and green color channel
 *  @param[in] ulARefB Reference value for CRC-32 checksum and blue color channel
 *  @param[in] ulBRefR Reference value for summation checksum and red color channel
 *  @param[in] ulBRefG Reference value for summation checksum and green color channel
 *  @param[in] ulBRefB Reference value for summation checksum and blue color channel
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSigReferenceValues(MML_GDC_SIG_UNIT eUnit, MM_U32 ulARefR, MM_U32 ulARefG, MM_U32 ulARefB,
                                  MM_U32 ulBRefR, MM_U32 ulBRefG, MM_U32 ulBRefB);

/**
 * [SWDD5030] Set Evaluation Window
 * \cond Related to SWAD000, SWAD504 \endcond
 *
 * The evaluation window has to be set for the checksum monitoring.
 * The evaluation window defines an area of the display described by the display parameters.
 * Within this area the values are monitored.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] x X value for upper left corner of evaluation window
 *  @param[in] y Y value for upper left corner of evaluation window
 *  @param[in] w Width of evaluation window
 *  @param[in] h Height of the evaluation window
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSigSetEvalWindow(MML_GDC_SIG_UNIT eUnit, MM_U32 x, MM_U32 y,
                                MM_U32 w, MM_U32 h);
/* DESIGN HINT When a difference is detected within the evaluation window an interrupt can be generated and the */
/* error counter will be incremented. */

/**
 * [SWDD5035] Set Evaluation Mask Window
 * \cond Related to SWAD000, SWAD504 \endcond
 *
 * The mask window excludes areas from evaluation window.
 * The mask parameters define borders of the evaluation window.
 * Together with the mask mode they define areas to be included in monitoring
 * and areas to be excluded from monitoring.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] x X value for upper left corner of evaluation mask window
 *  @param[in] y Y value for upper left corner of evaluation mask window
 *  @param[in] w Width of evaluation mask window
 *  @param[in] h Height of evaluation mask window
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSigSetEvalMaskWindow(MML_GDC_SIG_UNIT eUnit, MM_U32 x, MM_U32 y,
                                    MM_U32 w, MM_U32 h);
/**
 * [SWDD5036] Set Evaluation Mask Mode
 * \cond Related to SWAD000, SWAD504 \endcond
 *
 * The mask mode defines together with the evaluation window mask
 * the areas to be included in monitoring and areas to be excluded from monitoring.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] eVMaskModeType Mode defines vertical handling of mask window
 *  @param[in] eHMaskModeType Mode defines horizontal handling of mask window
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSigSetEvalMaskMode(MML_GDC_SIG_UNIT eUnit, MML_GDC_SIG_MASKMODE eVMaskModeType, MML_GDC_SIG_MASKMODE eHMaskModeType);

/**
 * [SWDD5037] Set Evaluation Pixel Mask Mode
 * \cond Related to SWAD000, SWAD504 \endcond
 *
 * The mask mode defines together with the alpha value of each pixel
 * the pixels to be included in monitoring and pixels to be excluded from monitoring.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] eAlphaOutput  Defines calculation of alpha bit.
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSigSetEvalPixelMaskMode(MML_GDC_SIG_UNIT eUnit, MML_GDC_SIG_ALPHA_MODE eAlphaOutput);

/**
 * [SWDD5038] Define signature source
 * \cond Related to SWAD000, SWAD504 \endcond
 *
 * The signature can be calculated with and without dithering artifacts.
 * Typically the application should use the default SIG_SOURCE_PRE_DITHER.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] eSource Defines the dither source
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSigSetInputSource(MML_GDC_SIG_UNIT eUnit, MML_GDC_SIG_SOURCE_SELECT eSource);

/**
 * [SWDD5040] Configure Thresholds for Summation Signature
 * \cond Related to SWAD000, SWAD505 \endcond
 *
 * Configure thresholds for the summation signature monitoring.
 * Set thresholds for each color channel for filtering error generation with summation method.
 * To reduce error generation with summation method a threshold can be set for each color channel.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] ulThreshR Threshold for red channel
 *  @param[in] ulThreshG Threshold for green channel
 *  @param[in] ulThreshB Threshold for blue channel
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSigSetThresholdTypeB(MML_GDC_SIG_UNIT eUnit, MM_U32 ulThreshR, MM_U32 ulThreshG, MM_U32 ulThreshB);

/**
 * [SWDD5045] Configure Error Threshold
 * \cond Related to SWAD000, SWAD505 \endcond
 *
 * Configure error threshold for generating interrupt.
 * Set threshold for error counter.
 * To reduce interrupt load a threshold can be set for error counter.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] ulErrThresh Threshold for error counter
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSigSetErrThreshold(MML_GDC_SIG_UNIT eUnit, MM_U32 ulErrThresh);
/* DESIGN HINT an interrupt can be enabled that indicates number of error frames higher than value configured for */
/*  ErrTresh. */

/**
 * [SWDD5050] Configure Error Reset
 * \cond Related to SWAD000, SWAD505 \endcond
 *
 * Configure error reset threshold.
 * Set threshold for error reset.
 * After a defined number of consecutive error-free frames (error reset threshold) the error counter will be reset.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] ulErrThreshReset Threshold for error reset
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSigSetErrThreshReset(MML_GDC_SIG_UNIT eUnit, MM_U32 ulErrThreshReset);


/*
 *! @}
 **/


/** @name Iris SIG Synchronization
 * @{
 */


/**
 * [SWDD5070] Get status of signature unit
 * \cond Related to SWAD000, SWAD506 \endcond
 *
 * Get status of Iris. Get them one by one.
 * For synchronizing the status of the Iris hardware needs to be known.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] eStatusType Type of requested status
 *  @return MM_TRUE if the requestet status bit is set, otherwise MM_FALSE
 **/
IRIS_API MM_BOOL mmlGdcSigGetStatus(MML_GDC_SIG_UNIT eUnit, MML_GDC_SIG_STATUS eStatusType);

/**
 * [SWDD5090] Trigger monitoring of signatures and set display output on sig error
 * \cond Related to SWAD000, SWAD507, SWR504 \endcond
 *
 * Trigger the monitoring with the previously configured values and set the trigger mode.
 * During configuration the new values are not active.
 * Sig interrupts can be enabled and disabled.
 * Only when the monitoring is triggered a new configuration will become active.
 * When the DisplayBlackOnError is enabled the sig unit will output a signal
 * that enables black screen on display when there was a sig error
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] eTriggerMode Mode for trigger;
 *  @param[in] DisplayBlackOnError output signal sig_err_stat will will enabled/disabled
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSigTriggerMonitoring(MML_GDC_SIG_UNIT eUnit, MML_GDC_SIG_TRIGGER_MODE eTriggerMode, MM_BOOL DisplayBlackOnError);

/**
 * [SWDD5080] Get signature errors
 * \cond Related to SWAD000, SWAD508 \endcond
 *
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @return Get number of frames with signature error since last trigger released.
 **/
IRIS_API MM_U32 mmlGdcSigGetErrors(MML_GDC_SIG_UNIT eUnit);

/**
 *** TBD these two might be internal functions only ***
 * [SWDD5088] Get signature A monitoring result
 * \cond Related to SWAD000, SWAD509 \endcond
 *
 * Get result of channel signature error for checksum type A.
 * Get monitoring result per color channel.
 * An error value != 0 shows an error for the color channel.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] eColourChannel Color channel, one of R, G or B
 *  @return Return the requestet result
 **/
IRIS_API MM_U32 mmlGdcSigGetTypeAMonitoringResult(MML_GDC_SIG_UNIT eUnit, MML_GDC_SIG_COLOR_CHANNEL eColourChannel);

/**
 * [SWDD5089] Get signature B monitoring result
 * \cond Related to SWAD000, SWAD509 \endcond
 *
 * Get result of channel signature error for checksum type B.
 * Get monitoring result per color channel.
 * An error value != 0 shows an error for the color channel.
 *  @param[in] eUnit Must be MML_GDC_SIG_UNIT_0
 *  @param[in] eColourChannel Color channel, one of R, G or B
 *  @return Return the requestet result
 **/
IRIS_API MM_U32 mmlGdcSigGetTypeBMonitoringResult(MML_GDC_SIG_UNIT eUnit, MML_GDC_SIG_COLOR_CHANNEL eColourChannel);

/**
 *! @}
 **/

/**
 *! @}
 **/

#ifdef __cplusplus
    }
#endif

#endif /* MML_GDC_SIG_H */
