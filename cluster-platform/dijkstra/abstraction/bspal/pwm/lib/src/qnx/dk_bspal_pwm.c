/**********************************************************************************
 **
 **  \file dk_bspal_pwm.c
 **
 **  \brief contains API implementation for interaction with BSPAL PWM library
 **
 **  Component Name: bspal_pwm
 **  Archive:
 **  Date: 24-12-2021
 **  Author: skoppise
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
#include "dk_bspal_pwm.h"

#define DUTY_CYCLE_PATH  "/dev/pwm/pwm%d/duty_cycle"
#define PERIOD_PATH  "/dev/pwm/pwm%d/period"
#define ENABLE_PATH  "/dev/pwm/pwm%d/enable"
#define EXP_PWM_PATH   "/dev/pwm/export"
#define PATH_LEN (100u)

LOG_DECLARE_CONTEXT ( g_log_bspal_pwm );

static int32_t dk_bspal_pwm_export_pin ( const uint8_t p_pin_id_U8 );


/**********************************************************************************
  @brief API to register context for logging.
 ***********************************************************************************/
void dk_bspal_pwm_init ( void )
{
    LOG_REGISTER_CONTEXT ( g_log_bspal_pwm, "PWM", "BSPAL_PWM_CONTEXT", DLT_LOG_VERBOSE );
}

/**********************************************************************************
  @brief API to unregister context.
 ***********************************************************************************/
void dk_bspal_pwm_deinit ( void )
{
    LOG_UNREGISTER_CONTEXT ( g_log_bspal_pwm );
}

/**********************************************************************************
  @brief API to export PWM pin
  @param[in] p_pin_id_U8    The pin which  need to be exported.

  @return EOK on Success.
 ***********************************************************************************/
static int32_t dk_bspal_pwm_export_pin ( const uint8_t p_pin_id_U8 )
{
    int32_t l_status_S32 = -1;
    char l_expo_pin_id[PATH_LEN] ;
    int32_t l_fd_exp_SINT = -1;
    ssize_t  l_sz_write_SINT = -1;
    int  l_ret_spf_SINT = -1;

    l_fd_exp_SINT = open ( EXP_PWM_PATH, O_RDWR );

    if ( l_fd_exp_SINT < 0 )
    {
        LOGE ( &g_log_bspal_pwm, "PWM pin %d export failed", p_pin_id_U8 );
        l_status_S32 = -1;
    }
    else
    {
        l_ret_spf_SINT = snprintf ( l_expo_pin_id, PATH_LEN, "%d", p_pin_id_U8 );

        if ( l_ret_spf_SINT < 0 )
        {
            LOGE ( &g_log_bspal_pwm, "sprintf call failed" );
            l_status_S32 = -1;
        }
        else
        {

            l_sz_write_SINT = write ( l_fd_exp_SINT, l_expo_pin_id, strlen ( l_expo_pin_id ) );

            if ( l_sz_write_SINT < 0 )
            {
                LOGE ( &g_log_bspal_pwm, "write call failed" );
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
  @brief API to change duty cycle of a PWM pin
  @param[in] p_pin_U8    the pin which direction to be set.
  @param[in] dc_val_U32  the value to be set dutycycle.

  @return duty cycle change status.
 ***********************************************************************************/

int32_t dk_bspal_pwm_set_dutycycle ( const uint8_t p_pin_U8, const uint32_t dc_val_U32 )
{
    char l_path_S8[PATH_LEN];
    int32_t l_expo_S32 = -1;
    int32_t l_return_S32 = -1;
    int l_spf_SINT = -1;
    int l_fd_SINT  = -1;
    int l_devctl_SINT = -1;
    pwm_buffer_type l_buff_S = {0};

    l_expo_S32 = dk_bspal_pwm_export_pin ( p_pin_U8 );

    if ( l_expo_S32 < 0 )
    {
        l_return_S32 = -1;
        LOGE ( &g_log_bspal_pwm, "PWM pin export failed" );
    }
    else
    {
        l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, DUTY_CYCLE_PATH, p_pin_U8 );

        if ( l_spf_SINT < 0 )
        {
            l_return_S32 = -1;
            LOGE ( &g_log_bspal_pwm, "snprintf() failed" );
        }
        else
        {
            l_fd_SINT = open ( l_path_S8, O_RDWR );

            if ( l_fd_SINT < 0 )
            {
                l_return_S32 = -1;
                LOGE ( &g_log_bspal_pwm, "open() failed" );
            }
            else
            {
                l_buff_S.pwm_dc_U32 = dc_val_U32;
                l_devctl_SINT  = devctl ( l_fd_SINT, DCMD_PWM_WRITE_CH, &l_buff_S, sizeof ( l_buff_S ), NULL );
                if ( l_devctl_SINT == EOK )
                {
                    l_return_S32 = 0;
                }
                else
                {
                    l_return_S32 = -1;
                    LOGE ( &g_log_bspal_pwm, "devctl() failed" );
                }

                ( void ) close ( l_fd_SINT );
            }
        }
    }
    return l_return_S32;
}


/**********************************************************************************
  @brief API to READ duty cycle of a PWM pin
  @param[in] p_pin_U8    the pin which direction to be set.
  @param[in] dc_val_U32  pointer to store the duty cycle to be read

  @return duty cycle status.
 ***********************************************************************************/
int32_t dk_bspal_pwm_get_dutycycle ( const uint8_t p_pin_U8, uint32_t *const dc_val_U32 )
{
    char l_path_S8[PATH_LEN];
    int32_t l_status_S32 = -1;
    int l_export_S32 = -1;
    int l_spf_SINT = -1;
    int l_fd_SINT = -1;
    int l_devctl_SINT = -1;
    pwm_buffer_type l_buff_S = {0};

    l_export_S32 = dk_bspal_pwm_export_pin ( p_pin_U8 );

    if ( l_export_S32 < 0 )
    {
        l_status_S32 = -1;
        LOGE ( &g_log_bspal_pwm, "PWM pin export failed" );
    }
    else
    {
        l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, DUTY_CYCLE_PATH, p_pin_U8 );

        if ( l_spf_SINT < 0 )
        {
            l_status_S32 = -1;
            LOGE ( &g_log_bspal_pwm, "snprintf() failed" );
        }
        else
        {
            l_fd_SINT = open ( l_path_S8, O_RDWR );

            if ( l_fd_SINT < 0 )
            {
                l_status_S32 = -1;
                LOGE ( &g_log_bspal_pwm, "open() failed" );
            }
            else
            {
                l_devctl_SINT = devctl ( l_fd_SINT, DCMD_PWM_READ_CH, &l_buff_S, sizeof ( l_buff_S ), NULL );

                if ( l_devctl_SINT == EOK )
                {
                    *dc_val_U32 = l_buff_S.pwm_dc_U32;
                    l_status_S32 = 0;
                }
                else
                {
			l_status_S32 = -1;
                    LOGE ( &g_log_bspal_pwm, "devctl() failed" );
                }
                ( void ) close ( l_fd_SINT );
            }
        }
    }
    return l_status_S32;
}



/**********************************************************************************
  @brief API to change period of a PWM pin
  @param[in] p_pin_U8    the pin which period to be set.
  @param[in] dc_val_U32  the value to be set period.

  @return pwm period change status.
 ***********************************************************************************/

int32_t dk_bspal_pwm_set_period ( const uint8_t p_pin_U8, const uint32_t dc_val_U32 )
{
    char l_path_S8[PATH_LEN];
    int32_t l_expo_S32 = -1;
    int32_t l_return_S32 = -1;
    int l_spf_SINT = -1;
    int l_fd_SINT  = -1;
    int l_devctl_SINT = -1;
    pwm_buffer_type l_buff_S = {0};

    l_expo_S32 = dk_bspal_pwm_export_pin ( p_pin_U8 );

    if ( l_expo_S32 < 0 )
    {
        l_return_S32 = -1;
        LOGE ( &g_log_bspal_pwm, "PWM pin export failed" );
    }
    else
    {
        l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, PERIOD_PATH, p_pin_U8 );

        if ( l_spf_SINT < 0 )
        {
            l_return_S32 = -1;
            LOGE ( &g_log_bspal_pwm, "snprintf() failed" );
        }
        else
        {
            l_fd_SINT = open ( l_path_S8, O_RDWR );

            if ( l_fd_SINT < 0 )
            {
                l_return_S32 = -1;
                LOGE ( &g_log_bspal_pwm, "open() failed" );
            }
            else
            {
                l_buff_S.pwm_period_U32 = dc_val_U32;
                l_devctl_SINT  = devctl ( l_fd_SINT, DCMD_PWM_WRITE_CH, &l_buff_S, sizeof ( l_buff_S ), NULL );

                if ( l_devctl_SINT == EOK )
                {
                    l_return_S32 = 0;
                }
                else
                {
                    l_return_S32 = -1;
                    LOGE ( &g_log_bspal_pwm, "devctl() failed" );
                }

                ( void ) close ( l_fd_SINT );
            }
        }
    }
    return l_return_S32;
}


/**********************************************************************************
  @brief API to READ peroid of a PWM pin
  @param[in] p_pin_U8    the pin which direction to be set.
  @param[in] dc_val_U32  pointer to store the period to be read

  @return pwm period read status.
 ***********************************************************************************/
int32_t dk_bspal_pwm_get_period ( const uint8_t p_pin_U8, uint32_t *const dc_val_U32 )
{
    char l_path_S8[PATH_LEN];
    int32_t l_status_S32 = -1;
    int l_export_S32 = -1;
    int l_spf_SINT = -1;
    int l_fd_SINT = -1;
    int l_devctl_SINT = -1;
    pwm_buffer_type l_buff_S = {0};

    l_export_S32 = dk_bspal_pwm_export_pin ( p_pin_U8 );

    if ( l_export_S32 < 0 )
    {
        l_status_S32 = -1;
        LOGE ( &g_log_bspal_pwm, "PWM pin export failed" );
    }
    else
    {
        l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, PERIOD_PATH, p_pin_U8 );

        if ( l_spf_SINT < 0 )
        {
            l_status_S32 = -1;
            LOGE ( &g_log_bspal_pwm, "snprintf() failed" );
        }
        else
        {
            l_fd_SINT = open ( l_path_S8, O_RDWR );

            if ( l_fd_SINT < 0 )
            {
                l_status_S32 = -1;
                LOGE ( &g_log_bspal_pwm, "open() failed" );
            }
            else
            {
                l_devctl_SINT = devctl ( l_fd_SINT, DCMD_PWM_READ_CH, &l_buff_S, sizeof ( l_buff_S ), NULL );

                if ( l_devctl_SINT == EOK )
                {
                    *dc_val_U32 = l_buff_S.pwm_period_U32;
                    l_status_S32 = 0;
                }
                else
                {
			l_status_S32 = -1;
                    LOGE ( &g_log_bspal_pwm, "devctl() failed" );
                }
                ( void ) close ( l_fd_SINT );
            }
        }
    }
    return l_status_S32;
}

/**********************************************************************************
  @brief API to change enable of a PWM pin
  @param[in] p_pin_U8    the pin which enable to be set.
  @param[in] dc_val_U32  the value to be set enable.

  @return enable change status.
 ***********************************************************************************/

int32_t dk_bspal_pwm_set_enable ( const uint8_t p_pin_U8, const uint32_t dc_val_U32 )
{
    char l_path_S8[PATH_LEN];
    int32_t l_expo_S32 = -1;
    int32_t l_return_S32 = -1;
    int l_spf_SINT = -1;
    int l_fd_SINT  = -1;
    int l_devctl_SINT = -1;
    pwm_buffer_type l_buff_S = {0};

    l_expo_S32 = dk_bspal_pwm_export_pin ( p_pin_U8 );

    if ( l_expo_S32 < 0 )
    {
        l_return_S32 = -1;
        LOGE ( &g_log_bspal_pwm, "PWM pin export failed" );
    }
    else
    {
        l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, ENABLE_PATH, p_pin_U8 );

        if ( l_spf_SINT < 0 )
        {
            l_return_S32 = -1;
            LOGE ( &g_log_bspal_pwm, "snprintf() failed" );
        }
        else
        {
            l_fd_SINT = open ( l_path_S8, O_RDWR );

            if ( l_fd_SINT < 0 )
            {
                l_return_S32 = -1;
                LOGE ( &g_log_bspal_pwm, "open() failed" );
            }
            else
            {
                l_buff_S.pwm_enable_U32 = dc_val_U32;
                l_devctl_SINT  = devctl ( l_fd_SINT, DCMD_PWM_WRITE_CH, &l_buff_S, sizeof ( l_buff_S ), NULL );

                if ( l_devctl_SINT == EOK )
                {
                    l_return_S32 = 0;
                }
                else
                {
                    l_return_S32 = -1;
                    LOGE ( &g_log_bspal_pwm, "devctl() failed" );
                }

                ( void ) close ( l_fd_SINT );
            }
        }
    }
    return l_return_S32;
}


/**********************************************************************************
  @brief API to READ enable status of a PWM pin
  @param[in] p_pin_U8    the pin which enable to be set.
  @param[in] dc_val_U32  pointer to store the enable to be read

  @return enable status.
 ***********************************************************************************/
int32_t dk_bspal_pwm_get_enable ( const uint8_t p_pin_U8, uint32_t *const dc_val_U32 )
{
    char l_path_S8[PATH_LEN];
    int32_t l_status_S32 = -1;
    int l_export_S32 = -1;
    int l_spf_SINT = -1;
    int l_fd_SINT = -1;
    int l_devctl_SINT = -1;
    pwm_buffer_type l_buff_S = {0};

    l_export_S32 = dk_bspal_pwm_export_pin ( p_pin_U8 );

    if ( l_export_S32 < 0 )
    {
        l_status_S32 = -1;
        LOGE ( &g_log_bspal_pwm, "PWM pin export failed" );
    }
    else
    {
        l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, ENABLE_PATH, p_pin_U8 );

        if ( l_spf_SINT < 0 )
        {
            l_status_S32 = -1;
            LOGE ( &g_log_bspal_pwm, "snprintf() failed" );
        }
        else
        {
            l_fd_SINT = open ( l_path_S8, O_RDWR );

            if ( l_fd_SINT < 0 )
            {
                l_status_S32 = -1;
                LOGE ( &g_log_bspal_pwm, "open() failed" );
            }
            else
            {
                l_devctl_SINT = devctl ( l_fd_SINT, DCMD_PWM_READ_CH, &l_buff_S, sizeof ( l_buff_S ), NULL );

                if ( l_devctl_SINT == EOK )
                {
                    *dc_val_U32 = l_buff_S.pwm_enable_U32;
                    l_status_S32 = 0;
                }
                else
                {
			l_status_S32 = -1;
                    LOGE ( &g_log_bspal_pwm, "devctl() failed" );
                }
                ( void ) close ( l_fd_SINT );
            }
        }
    }
    return l_status_S32;
}
