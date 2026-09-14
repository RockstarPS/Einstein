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

 * \file dk_bspal_serializer.c
 *
 * \brief
 * Serializer BSPAL API to start and stop the HUD.
 *
 *****************************************************************************/

/**********************************************************************************************************************
 *  HEADER FILE GUARD
 *********************************************************************************************************************/

#ifndef DK_BSPAL_SERIALIZER_PROXY_H_
#define DK_BSPAL_SERIALIZER_PROXY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/*!
 * \brief        Library provides fixed-width integer types and macros
 */
#include <stdint.h>

/**********************************************************************************************************************
 *  MACRO
 *********************************************************************************************************************/
#define SERIALIZER_DEINIT       ((uint8_t)0)
#define SERIALIZER_INIT         ((uint8_t)1)
#define SERIALIZER_STOP         ((uint8_t)0)
#define SERIALIZER_START        ((uint8_t)1)
#define SERIALIZER_LINK_STATUS  ((uint8_t)0)
#define SERIALIZER_ERROR_STATUS ((uint8_t)1)

/**********************************************************************************************************************
 *  PUBLIC FUNCTIONS
 *********************************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*!
 * \brief         API to register context for logging.
 */
void dk_bspal_serializer_init(void);

/*!
 * \brief         API to unregister context.
 */
void dk_bspal_serializer_deinit(void);

/*!
 * \brief         API to configure the serializer device.
 *
 * \param[in]     p_config_cmd_U8  Configuration command (e.g., INIT, DEINIT).
 *
 * \return        (0) on success, or -1 on failure.
 */
int32_t dk_bspal_serializer_configure(uint8_t p_config_cmd_U8);

/*!
 * \brief         API to control serializer streaming.
 *
 * \param[in]     p_control_cmd_U8  Control command (e.g., START, STOP).
 *
 * \return        (0) on success, or -1 on failure.
 */
int32_t dk_bspal_serializer_streaming_control(uint8_t p_control_cmd_U8);

/*!
 * \brief         API to retrieve the status of the serializer.
 *
 * \param[in]     p_status_type_U8  Type of status to retrieve (e.g., LINK STATUS, ERROR STATUS).
 * \param[out]    p_status_val_S32  Pointer to store the retrieved status value.
 *
 * \return        (0) on success, or -1 on failure.
 */
int32_t dk_bspal_serializer_get_status(uint8_t p_status_type_U8, int32_t *p_status_val_S32);

/*end of file =============================================================*/

#ifdef __cplusplus
}
#endif

#endif
