/*****************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL<br>
 *       ________________________________
 *       [2025] Visteon Corporation<br>
 *       All Rights Reserved
 *
 *       NOTICE: This is an unpublished work of authorship, which contains
 *               trade secrets. Visteon Corporation owns all rights to this
 *               work and intends to maintain it in confidence to preserve its
 *               trade secret status. Visteon Corporation reserves the right,
 *               under the copyright laws of the United States or those of any
 *               other country that may have jurisdiction, to protect this work
 *               as an unpublished work, in the event of an inadvertent or
 *               deliberate unauthorized publication. Visteon Corporation also
 *               reserves its rights under all copyright laws to protect this
 *               work as a published work, when appropriate. Those having
 *               access to this work may not copy it, use it, modify it, or
 *               disclose the information contained in it without the written
 *               authorization of Visteon Corporation.
 *
 * \authors<br>
 *   |Name                     | CDSID     | Location                  |
 *   |------------------------ | --------- | --------                  |
 *   |Srikesh P                | ssomasu1  | VTSC, Bengaluru, India    |

 * \file dk_bspal_deserializer.c
 *
 * \brief
 * Deserializer BSPAL API to start and stop the Multimedia.
 *
 *****************************************************************************/

/**********************************************************************************************************************
 *  HEADER FILE GUARD
 *********************************************************************************************************************/

#ifndef DK_BSPAL_DESERIALIZER_PROXY_H_
#define DK_BSPAL_DESERIALIZER_PROXY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/*!
 * \brief        Library provides fixed-width integer types and macros
 */
#include <stdint.h>

/*!
 * \brief        IOCTL constants
 */
#ifdef LINUX_PLATFORM
#include "CDeserializer_Ioctl.h"
#endif

/**********************************************************************************************************************
 *  MACRO
 *********************************************************************************************************************/
#define DESERIALIZER_DEINIT       ((uint8_t)0)
#define DESERIALIZER_INIT         ((uint8_t)1)
#define DESERIALIZER_STOP         ((uint8_t)0)
#define DESERIALIZER_START        ((uint8_t)1)
#define DESERIALIZER_LINK_STATUS  ((uint8_t)0)
#define DESERIALIZER_ERROR_STATUS ((uint8_t)1)
#define DESERIALIZER_TEST_PATTERN ((uint8_t)0)
/**********************************************************************************************************************
 *  PUBLIC FUNCTIONS
 *********************************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*!
 * \brief         API to register context for logging.
 */
void dk_bspal_deserializer_init(void);

/*!
 * \brief         API to unregister context.
 */
void dk_bspal_deserializer_deinit(void);

/*!
 * \brief         API to configure the deserializer device.
 *
 * \param[in]     p_config_cmd_U8  Configuration command (e.g., INIT, DEINIT).
 *
 * \return        `EOK` (0) on success, or -1 on failure.
 */
int32_t dk_bspal_deserializer_configure(uint8_t p_config_cmd_U8);

/*!
 * \brief         API to control deserializer streaming.
 *
 * \param[in]     p_control_cmd_U8  Control command (e.g., START, STOP).
 *
 * \return        `EOK` (0) on success, or -1 on failure.
 */
int32_t dk_bspal_deserializer_streaming_control(uint8_t p_control_cmd_U8);

/*!
 * \brief         API to retrieve the status of the deserializer.
 *
 * \param[in]     p_status_type_U8  Type of status to retrieve (e.g., LINK STATUS, ERROR STATUS).
 * \param[out]    p_status_val_S32  Pointer to store the retrieved status value.
 *
 * \return        `EOK` (0) on success, or -1 on failure.
 */
int32_t dk_bspal_deserializer_get_status(uint8_t p_status_type_U8, int32_t *p_status_val_S32);

/*!
 * \brief         API to start test pattern of deserializer device.
 *
 *
 * \return        `EOK` (0) on success, or -1 on failure
 */
int32_t dk_bspal_deserializer_test_pattern(uint8_t p_control_cmd_U8);

#ifdef __cplusplus
}
#endif

#endif
