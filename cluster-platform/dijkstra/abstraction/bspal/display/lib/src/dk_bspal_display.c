/**********************************************************************************
 **
 **  \file dk_bspal_display_proxy.c
 **
 **  \brief contains API to communicate with resmgr to set display power
 **
 **  Component Name: bspal_display
 **  Archive:
 **  Date: 22-MAY-2020
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

/*********************************************************************************
 * @file          dk_bspal_display_proxy.c
 * @ingroup       bspal_display
 * @author       Shreya
 * @brief         APIs to set display power and display state

 **********************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdint.h>

#ifdef LINUX_PLATFORM
    #include <sys/ioctl.h>
    #include "CDisplay_Ioctl.h"
#elif defined(QNX_PLATFORM)
    #include "CDisplay_Devctl.h"
#endif
#include "dk_bspal_display.h"

#define POWER_PATH "/dev/display/display%d/power"
#define DISPLAY_PATH "/dev/display/display%d/state"
#define GAMMA_PATH "/dev/display/display%d/gamma_red"
#define PATH_LEN (100u)

int32_t dk_bspal_display_set_power ( const uint8_t p_id_U8, const EBspalDisplayPower_t p_value_E )
{
    char l_path_S8[PATH_LEN];
    int l_fd_SINT = -1;
    int32_t l_ret_S32 = -1;
    int l_ret_val_SINT = -1;
    display_power_buffer_type_ts l_power_S;


    ( void ) snprintf ( l_path_S8, PATH_LEN, POWER_PATH, p_id_U8 );

    l_fd_SINT = open ( l_path_S8, O_RDWR );

    if ( l_fd_SINT < 0 )
    {
        l_ret_S32 = -1;
    }
    else
    {
        switch ( p_value_E )
        {
            case EBspalDisplayPower_On:
            {
                l_power_S.power_U8 = DISPLAY_EPOWER_ON;
                break;
            }

            case EBspalDisplayPower_Off:
            {
                l_power_S.power_U8 = DISPLAY_EPOWER_OFF;
                break;
            }
        }

#ifdef LINUX_PLATFORM
        l_ret_val_SINT = ioctl(l_fd_SINT, POWER_ID_VALUE_WRITE, &l_power_S);
#elif defined(QNX_PLATFORM)
        l_ret_val_SINT = devctl(l_fd_SINT, POWER_ID_VALUE_WRITE, &l_power_S, sizeof(l_power_S), NULL);
#endif

        if (l_ret_val_SINT == EOK) {
            l_ret_S32 = 0;
        }
        else
        {
            l_ret_S32 = -1;
        }

        ( void ) close ( l_fd_SINT );
    }

    return l_ret_S32;
}


int32_t dk_bspal_display_get_state ( const uint8_t p_id_U8, EBspalDisplayStatus_t *const p_value_EP )
{
    char l_disp_path_S8[PATH_LEN] ;
    int32_t l_return_S32 = -1;
    int l_fds_SINT = -1;
    int l_ret_val_SINT = -1;
    display_state_buffer_type_ts l_disp_S;
    l_disp_S.state = 0;

    ( void ) snprintf ( l_disp_path_S8, PATH_LEN, DISPLAY_PATH, p_id_U8 );

    l_fds_SINT = open ( l_disp_path_S8, O_RDONLY );

    if ( l_fds_SINT < 0 )
    {
        l_return_S32 = -1;
    } 
    else 
    {
#ifdef LINUX_PLATFORM
        l_ret_val_SINT = ioctl(l_fds_SINT, STATE_ID_VALUE_READ, &l_disp_S);
#elif defined(QNX_PLATFORM)
        l_ret_val_SINT = devctl(l_fds_SINT, STATE_ID_VALUE_READ, &l_disp_S, sizeof(l_disp_S), NULL);
#endif

        if ( l_ret_val_SINT == EOK )
        {
            switch ( l_disp_S.state )
            {
                case DISPLAY_ESTATE_OFF:
                {
                    *p_value_EP = EBspalDisplayState_Off;
                    break;
                }

                case DISPLAY_ESTATE_ON:
                {
                    *p_value_EP = EBspaDisplayState_On;
                    break;
                }

                case DISPLAY_ESTATE_ERROR:
                {
                    *p_value_EP = EBspaDisplayState_Error;
                    break;
                }

                case DISPLAY_ESTATE_DISCONNECTED:
                {
                    *p_value_EP = EBspalDisplayState_Disconnected;
                    break;
                }
            }

            l_return_S32 = 0;
        }
        else
        {
            l_return_S32 = -1;
        }

        ( void ) close ( l_fds_SINT );
    }

    return l_return_S32;
}


int32_t dk_bspal_display_set_gamma_rgb ( const uint8_t p_id_U8, int32_t  p_gamma_red_S32, int32_t  p_gamma_green_S32, int32_t  p_gamma_blue_S32 )
{
    char l_path_S8[PATH_LEN];
    int l_fd_SINT = -1;
    int32_t l_ret_S32 = -1;
	
    #ifdef QNX_PLATFORM
    int l_devctl_ret_SINT = -1;
    display_gamma_rgb_type_ts l_gamma_S;


    ( void ) snprintf ( l_path_S8, PATH_LEN, GAMMA_PATH, p_id_U8 );

    l_fd_SINT = open ( l_path_S8, O_RDWR );

    if ( l_fd_SINT < 0 )
    {
        l_ret_S32 = -1;
    }
    else
    {
        l_gamma_S.gamma_red = p_gamma_red_S32;
        l_gamma_S.gamma_green = p_gamma_green_S32;
        l_gamma_S.gamma_blue = p_gamma_blue_S32;

        l_devctl_ret_SINT = devctl ( l_fd_SINT, GAMMA_RGB_VALUE_WRITE, &l_gamma_S, sizeof ( l_gamma_S ), NULL );

        if ( l_devctl_ret_SINT == EOK )
        {
            l_ret_S32 = 0;
        }
        else
        {
            l_ret_S32 = -1;
        }

        ( void ) close ( l_fd_SINT );
    }
    #endif
	
    return l_ret_S32;
}

int32_t dk_bspal_display_get_gamma_rgb ( const uint8_t p_id_U8, int32_t *p_gamma_red_S32, int32_t *p_gamma_green_S32, int32_t *p_gamma_blue_S32 )
{
    char l_path_S8[PATH_LEN] ;
    int32_t l_return_S32 = -1;
	
    #ifdef QNX_PLATFORM
    int l_fds_SINT = -1;
    int l_devctl_sts_SINT = -1;
    display_gamma_rgb_type_ts l_gamma_S;
    
    l_gamma_S.gamma_red = -1;
    l_gamma_S.gamma_green = -1;
    l_gamma_S.gamma_blue = -1;

    ( void ) snprintf ( l_path_S8, PATH_LEN, GAMMA_PATH, p_id_U8 );

    l_fds_SINT = open ( l_path_S8, O_RDONLY );

    if ( l_fds_SINT < 0 )
    {
        l_return_S32 = -1;
    }
    else
    {
        l_devctl_sts_SINT = devctl ( l_fds_SINT, GAMMA_RGB_VALUE_READ, &l_gamma_S, sizeof ( l_gamma_S ), NULL );

        if ( l_devctl_sts_SINT == EOK )
        {
            *p_gamma_red_S32 = l_gamma_S.gamma_red;
            *p_gamma_green_S32 = l_gamma_S.gamma_green;
            *p_gamma_blue_S32 = l_gamma_S.gamma_blue;
            l_return_S32 = 0;
        }
        else
        {
            l_return_S32 = -1;
        }

        ( void ) close ( l_fds_SINT );
    }
    #endif
	
    return l_return_S32;

}
