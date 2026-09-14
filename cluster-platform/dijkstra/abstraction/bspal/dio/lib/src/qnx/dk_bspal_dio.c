/**********************************************************************************
 **
 **  \file dk_bspal_dio_proxy.c
 **
 **  \brief contains API implementation for interaction with BSPAL DIO library
 **
 **  Component Name: bspal_dio
 **  Archive:
 **  Date: 09-06-2020
 **  Author: Shreya
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (?Materials?) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, stop or otherwise, any rights in these Materials.
 ***********************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "dk_logger.h"
#include "dk_bspal_dio.h"

#define VALUE_PATH  "/dev/gpio/gpio%d/value"
#define DIRECTION_PATH  "/dev/gpio/gpio%d/direction"
#define EXP_GPIO_PATH   "/dev/gpio/export"
#define PATH_LEN (100u)

LOG_DECLARE_CONTEXT ( g_log_bspal_dio );

static int32_t dk_bspal_dio_export_pin ( const uint32_t p_pin_id_U32 );


/**********************************************************************************
  @brief API to register context for logging.
 ***********************************************************************************/
void dk_bspal_dio_init ( void )
{
    LOG_REGISTER_CONTEXT ( g_log_bspal_dio, "DIO", "BSPAL_DIO_CONTEXT", DLT_LOG_VERBOSE );
}

/**********************************************************************************
  @brief API to unregister context.
 ***********************************************************************************/
void dk_bspal_dio_deinit ( void )
{
    LOG_UNREGISTER_CONTEXT ( g_log_bspal_dio );
}

/**********************************************************************************
  @brief API to export DIO pin
  @param[in] p_pin_id_U32    The pin which  need to be exported.

  @return EOK on Success.
 ***********************************************************************************/
static int32_t dk_bspal_dio_export_pin ( const uint32_t p_pin_id_U32 )
{
    int32_t l_status_S32 = -1;
    char l_expo_pin_id[PATH_LEN] ;
    int32_t l_fd_exp_SINT = -1;
    ssize_t  l_sz_write_SINT = -1;
    int  l_ret_spf_SINT = -1;

    l_fd_exp_SINT = open ( EXP_GPIO_PATH, O_RDWR );

    if ( l_fd_exp_SINT < 0 )
    {
        LOGE ( &g_log_bspal_dio, "GPIO pin %d export failed", p_pin_id_U32 );
        l_status_S32 = -1;
    }
    else
    {
        l_ret_spf_SINT = snprintf ( l_expo_pin_id, PATH_LEN, "%d", p_pin_id_U32 );

        if ( l_ret_spf_SINT < 0 )
        {
            LOGE ( &g_log_bspal_dio, "sprintf call failed" );
            l_status_S32 = -1;
        }
        else
        {

            l_sz_write_SINT = write ( l_fd_exp_SINT, l_expo_pin_id, strlen ( l_expo_pin_id ) );

            if ( l_sz_write_SINT < 0 )
            {
                LOGE ( &g_log_bspal_dio, "write call failed" );
                l_status_S32 = -1;
            }
            else
            {
                l_status_S32 = 0;
            }
        }

        ( void ) close ( l_fd_exp_SINT );
    }

    return l_status_S32;
}

/**********************************************************************************
  @brief API to set value of a DIO pin
  @param[in] p_pin_U32    The pin which value to be set
  @param[in] p_value_U8  The value to be set

  @return Set value status.
 ***********************************************************************************/

int32_t dk_bspal_dio_set_value ( const uint32_t p_pin_U32, const bool p_value_BOOL )
{
    char l_path_S8[PATH_LEN] ;
    int l_spf_ret_SINT = -1;
    int l_fd_SINT = -1;
    int32_t l_ret_S32 = -1;
    int l_devctl_ret_SINT = -1;
    int32_t l_export_S32 = -1;
    gpio_buffer_type l_buff_S;

    l_export_S32 = dk_bspal_dio_export_pin ( p_pin_U32 );

    if ( l_export_S32 < 0 )
    {
        l_ret_S32 = -1;
        LOGE ( &g_log_bspal_dio, "GPIO pin export failed" );
    }
    else
    {
        l_spf_ret_SINT = snprintf ( l_path_S8, PATH_LEN, VALUE_PATH, p_pin_U32 );

        if ( l_spf_ret_SINT < 0 )
        {
            l_ret_S32 = -1;
            LOGE ( &g_log_bspal_dio, "snprintf() failed" );
        }
        else
        {
            l_fd_SINT = open ( l_path_S8, O_RDWR );

            if ( l_fd_SINT < 0 )
            {
                l_ret_S32 = -1;
                LOGE ( &g_log_bspal_dio, "open() failed" );
            }
            else
            {
                l_buff_S.gpio_value = ( ( uint8_t ) p_value_BOOL );
                l_devctl_ret_SINT = devctl ( l_fd_SINT, GPIO_VALUE_WRITE, &l_buff_S, sizeof ( l_buff_S ), NULL );

                if ( l_devctl_ret_SINT == EOK )
                {
                    l_ret_S32 = 0;
                }
                else
                {
                    l_ret_S32 = -1;
                    LOGE ( &g_log_bspal_dio, "devctl() failed" );
                }

                ( void ) close ( l_fd_SINT );
            }
        }
    }

    return l_ret_S32;
}


/**********************************************************************************
  @brief API to get value of a DIO pin
  @param[in] p_pin_U32    The pin which value to be read.
  @param[in] p_value_P  pointer to the value to be read.

  @return Get value status.
 ***********************************************************************************/

int32_t dk_bspal_dio_get_value ( const uint32_t p_pin_U32, bool *const p_value_BOOLP )
{
    char l_path_S8[PATH_LEN];
    int32_t l_exp_S32 = -1;
    int32_t l_sts_S32 = -1;
    int l_spf_sts_SINT = -1;
    int l_fd_SINT = -1;
    int l_devctl_sts_SINT = -1;
    gpio_buffer_type l_buf_S;
    l_buf_S.gpio_value = 0;
    l_buf_S.e_direction = (EDirection)0;

    l_exp_S32 = dk_bspal_dio_export_pin ( p_pin_U32 );

    if ( l_exp_S32 < 0 )
    {
        l_sts_S32 = -1;
        LOGE ( &g_log_bspal_dio, "GPIO pin export failed" );
    }
    else
    {
        l_spf_sts_SINT = snprintf ( l_path_S8, PATH_LEN, VALUE_PATH, p_pin_U32 );

        if ( l_spf_sts_SINT < 0 )
        {
            l_sts_S32 = -1;
            LOGE ( &g_log_bspal_dio, "snprintf() failed" );
        }
        else
        {
            l_fd_SINT = open ( l_path_S8, O_RDWR );

            if ( l_fd_SINT < 0 )
            {
                l_sts_S32 = -1;
                LOGE ( &g_log_bspal_dio, "open() failed" );
            }
            else
            {
                l_devctl_sts_SINT = devctl ( l_fd_SINT, GPIO_VALUE_READ, &l_buf_S, sizeof ( l_buf_S ), NULL );

                if ( l_devctl_sts_SINT == EOK )
                {
                    *p_value_BOOLP = l_buf_S.gpio_value;
                    l_sts_S32 = 0;
                }
                else
                {
                    l_sts_S32 = -1;
                    LOGE ( &g_log_bspal_dio, "devctl() failed" );
                }

                ( void ) close ( l_fd_SINT );
            }
        }
    }

    return l_sts_S32;
}


/**********************************************************************************
  @brief API to set direction of a DIO pin
  @param[in] p_pin_U32    the pin which direction to be set.
  @param[in] p_direction_te  the direction to be set.

  @return set direction status.
 ***********************************************************************************/

int32_t dk_bspal_dio_set_direction ( const uint32_t p_pin_U32, const EDirection p_direction_te )
{
    char l_path_S8[PATH_LEN];
    int32_t l_expo_S32 = -1;
    int32_t l_return_S32 = -1;
    int l_spf_SINT = -1;
    int l_fd_SINT  = -1;
    int l_devctl_SINT = -1;
    gpio_buffer_type l_buf_S;

    l_expo_S32 = dk_bspal_dio_export_pin ( p_pin_U32 );

    if ( l_expo_S32 < 0 )
    {
        l_return_S32 = -1;
        LOGE ( &g_log_bspal_dio, "GPIO pin export failed" );
    }
    else
    {
        l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, DIRECTION_PATH, p_pin_U32 );

        if ( l_spf_SINT < 0 )
        {
            l_return_S32 = -1;
            LOGE ( &g_log_bspal_dio, "snprintf() failed" );
        }
        else
        {
            l_fd_SINT = open ( l_path_S8, O_RDWR );

            if ( l_fd_SINT < 0 )
            {
                l_return_S32 = -1;
                LOGE ( &g_log_bspal_dio, "open() failed" );
            }
            else
            {
                l_buf_S.e_direction = p_direction_te;
                l_devctl_SINT  = devctl ( l_fd_SINT, GPIO_DIRECTION_WRITE, &l_buf_S, sizeof ( l_buf_S ), NULL );

                if ( l_devctl_SINT == EOK )
                {
                    l_return_S32 = 0;
                }
                else
                {
                    l_return_S32 = -1;
                    LOGE ( &g_log_bspal_dio, "devctl() failed" );
                }

                ( void ) close ( l_fd_SINT );
            }
        }
    }

    return l_return_S32;
}


/**********************************************************************************
  @brief API to READ direction of a DIO pin
  @param[in] p_pin_U32    the pin which direction to be set.
  @param[in] p_direction_TEP  pointer to store the direction to be read

  @return get direction status.
 ***********************************************************************************/
int32_t dk_bspal_dio_get_direction ( const uint32_t p_pin_U32, EDirection *const p_direction_TEP )
{
    char l_path_S8[PATH_LEN];
    int32_t l_status_S32 = -1;
    int l_export_S32 = -1;
    int l_spf_SINT = -1;
    int l_fd_SINT = -1;
    int l_devctl_SINT = -1;
    gpio_buffer_type l_buff_S;
    l_buff_S.gpio_value = 0;
    l_buff_S.e_direction = (EDirection)0;

    l_export_S32 = dk_bspal_dio_export_pin ( p_pin_U32 );

    if ( l_export_S32 < 0 )
    {
        l_status_S32 = -1;
        LOGE ( &g_log_bspal_dio, "GPIO pin export failed" );
    }
    else
    {
        l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, DIRECTION_PATH, p_pin_U32 );

        if ( l_spf_SINT < 0 )
        {
            l_status_S32 = -1;
            LOGE ( &g_log_bspal_dio, "snprintf() failed" );
        }
        else
        {
            l_fd_SINT = open ( l_path_S8, O_RDWR );

            if ( l_fd_SINT < 0 )
            {
                l_status_S32 = -1;
                LOGE ( &g_log_bspal_dio, "open() failed" );
            }
            else
            {
                l_devctl_SINT = devctl ( l_fd_SINT, GPIO_DIRECTION_READ, &l_buff_S, sizeof ( l_buff_S ), NULL );

                if ( l_devctl_SINT == EOK )
                {
                    *p_direction_TEP = l_buff_S.e_direction;
                    l_status_S32 = 0;
                }
                else
                {
			l_status_S32 = -1;
                    LOGE ( &g_log_bspal_dio, "devctl() failed" );
                }
                ( void ) close ( l_fd_SINT );
            }
        }
    }

    return l_status_S32;
}
