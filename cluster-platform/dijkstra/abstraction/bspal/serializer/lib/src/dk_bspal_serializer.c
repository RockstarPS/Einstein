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
 *  INCLUDES
 *********************************************************************************************************************/

/*!
 * \brief        Standard io header
 */
#include <stdio.h>
/*!
 * \brief        Library provides subroutines for file operations
 */
#include <fcntl.h>
/*!
 * \brief        Library provides access to the POSIX operating system API
 */
#include <unistd.h>
/*!
 * \brief        Library enables device-specific control using ioctl system calls
 */
#include <sys/ioctl.h>
/*!
 * \brief        Library defines macros for reporting and retrieving error conditions
 */
#include <errno.h>
/*!
 * \brief        Library supports string operations
 */
#include <string.h>
/*!
 * \brief        Library defines the logging levels
 */
#include "dk_logger.h"
/*!
 * \brief        Library for BSPAL API
 */
#include "dk_bspal_serializer.h"
/*!
 * \brief        IOCTL constants
 */
#ifdef LINUX_PLATFORM
#include "CSerializer_Ioctl.h"
#endif


LOG_DECLARE_CONTEXT (g_log_bspal_ser);

/**********************************************************************************************************************
 *  INTERNAL MACROS
 *********************************************************************************************************************/

/*!
 * \def          DEVICE_NAME
 * \brief        Defines the path to the CXD4951 device node
 */
#define DEVICE_NAME "/dev/video_ser"

/**********************************************************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/*!
 * \brief         API to perform an IOCTL operation on the serializer device.
 *
 * \param[in]     p_fd_SINT       File descriptor of the opened serializer device.
 * \param[in]     p_ioctl_cmd_S32 IOCTL command to be executed.
 * \param[out]    p_status_S32    Pointer to store the status if applicable (can be NULL).
 *
 * \return        (0) on success, or -1 if the IOCTL operation fails.
 */
static int32_t serializer_ioctl_handler(int32_t p_ioctl_cmd_S32, int32_t *p_status_S32);


/**********************************************************************************************************************
 *  LOCAL FUNCTION IMPLEMENTATIONS
 *********************************************************************************************************************/

static int32_t serializer_ioctl_handler(int32_t p_ioctl_cmd_S32, int32_t *p_status_S32)
{
    int32_t l_ret_S32 = -1;
    int32_t l_fd_SINT = -1 ;

    l_fd_SINT = open(DEVICE_NAME, O_RDWR);

    if (l_fd_SINT < 0)
    {
        LOGE(&g_log_bspal_ser, "Failed to open device");
        l_ret_S32 = -1;
    }
    else
    {
        switch (p_ioctl_cmd_S32)
        {
            case IOCTL_SERIALIZER_INIT:
            case IOCTL_SERIALIZER_DEINIT:
            case IOCTL_SERIALIZER_STREAMING_START:
            case IOCTL_SERIALIZER_STREAMING_STOP:
                 l_ret_S32 = ioctl(l_fd_SINT, p_ioctl_cmd_S32);
                break;

            case IOCTL_SERIALIZER_LINK_STATUS:
            case IOCTL_SERIALIZER_ERROR_STATUS:
                l_ret_S32 = ioctl(l_fd_SINT, p_ioctl_cmd_S32, p_status_S32);
                break;

            default:
                LOGE(&g_log_bspal_ser, "Invalid IOCTL request: %d", p_ioctl_cmd_S32);
                l_ret_S32 = -1;
                break;
        }
        if (l_ret_S32 < 0)
        {
            LOGE(&g_log_bspal_ser, "IOCTL command %d failed", p_ioctl_cmd_S32);
        }

        (void) close(l_fd_SINT);
    }
    return l_ret_S32;
}

/**********************************************************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *********************************************************************************************************************/

void dk_bspal_serializer_init(void)
{
    LOG_REGISTER_CONTEXT (g_log_bspal_ser, "SERIALIZER", "BSPAL_SERIALIZER_CONTEXT", DLT_LOG_VERBOSE);
}

void dk_bspal_serializer_deinit(void)
{
    LOG_UNREGISTER_CONTEXT (g_log_bspal_ser);
}

int32_t dk_bspal_serializer_configure(uint8_t p_config_cmd_U8)
{
    int32_t l_ret_S32 = -1;

    if (p_config_cmd_U8 == SERIALIZER_INIT)
    {
        l_ret_S32 = serializer_ioctl_handler(IOCTL_SERIALIZER_INIT, NULL);
    }
    else if (p_config_cmd_U8 == SERIALIZER_DEINIT)
    {
        l_ret_S32 = serializer_ioctl_handler(IOCTL_SERIALIZER_DEINIT, NULL);
    }
    else
    {
        l_ret_S32 = -1;
    }

    return l_ret_S32;
}

int32_t dk_bspal_serializer_streaming_control(uint8_t p_control_cmd_U8)
{
    int32_t l_ret_S32 = -1;

    if (p_control_cmd_U8 == SERIALIZER_START)
    {
        l_ret_S32 = serializer_ioctl_handler(IOCTL_SERIALIZER_STREAMING_START, NULL);
    }
    else if (p_control_cmd_U8 == SERIALIZER_STOP)
    {
        l_ret_S32 = serializer_ioctl_handler(IOCTL_SERIALIZER_STREAMING_STOP, NULL);
    }
    else
    {
        LOGE(&g_log_bspal_ser, "Invalid serializer streaming cmd");
        l_ret_S32 = -1;
    }

    return l_ret_S32;
}

int32_t dk_bspal_serializer_get_status(uint8_t p_status_type_U8, int32_t *p_status_val_S32)
{
    int32_t l_ret_S32 = -1;

    if (p_status_type_U8 == SERIALIZER_LINK_STATUS)
    {
        l_ret_S32 = serializer_ioctl_handler(IOCTL_SERIALIZER_LINK_STATUS, (int32_t *)p_status_val_S32);
    }
    else if (p_status_type_U8 == SERIALIZER_ERROR_STATUS)
    {
        l_ret_S32 = serializer_ioctl_handler(IOCTL_SERIALIZER_ERROR_STATUS, (int32_t *)p_status_val_S32);
    }
    else
    {
        LOGE(&g_log_bspal_ser, "Invalid status type");
        l_ret_S32 = -1;
    }

    return l_ret_S32;
}

/******************************************************************************
 *  REVISION HISTORY
 *  ---------------------------------------------------------------------------
 *  Refer to the module's public header file.
 ******************************************************************************/
