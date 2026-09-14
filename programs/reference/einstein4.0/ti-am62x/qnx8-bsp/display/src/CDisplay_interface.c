/**********************************************************************************
 **
 **  \file CDisplay_interface.h
 **
 **  \brief contains Resource Manager API's used to communicate with dio driver.
 **
 **  Component Name: resmgr_display
 **  Archive:
 **  Date: 04-MAY-2020
 **  Author: Rajasekhar
 **  | Date       | Author      |Description
 **  |------------|-------------|--------------------------------
 **  | 04-MAY-2020| Rajasekhar  | Create Initial Module.
 **  | 2023-OCT-13| Sthanga4    | updated the changes of bluelight
 **  | 2023-OCT-13| damudhar    | Added Doxygen document
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (�Materials�) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, stop or otherwise, any rights in these Materials.
 ***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <screen/screen.h>
#include <math.h>
#include "CDisplay_interface.h"
#include "CDisplay_If_Debug.h"
#include "dk_bspal_dio.h"
#include "CDisplay_Devctl.h"
#include "CDisplay.h"
#include "dk_logger.h"

#define GAMMA_NUM_STEPS						  256U
#define GAMMA_MAX_VALUE						  65535U
#define SCALING_FACTOR						  100.0f

static bool lcd_on_BOOL = false;
double g_gamma_red_u32=0;
double g_gamma_green_u32=0;
double g_gamma_blue_u32=0;
static int32_t Init_Display ( void );
static int32_t Enable_Display ( uint8_t *p_enable_display_U8 );
static int32_t Get_Display_Power ( uint8_t *p_power_U8 );
static int32_t Get_Display_Power_Devctl ( uint8_t *p_value_U8 );
static int32_t Get_Display_state ( uint8_t *p_state_U8 );
static int32_t Get_Display_state_Devctl ( uint8_t *p_value_U8 );
static int32_t Get_Display_Thermal_Temperature_Value ( uint8_t *p_value_U8 );
static int32_t Get_Display_Thermal_Temperature_Value_Devctl ( uint32_t *p_temp_U32 );
static int32_t Deinit_Display ( void );
static int32_t Set_Display_State ( uint8_t p_onflag );
static int32_t Set_Gamma_RGB_Devctl ( int32_t  p_gamma_red_S32, int32_t	 p_gamma_green_S32, int32_t	 p_gamma_blue_S32 );
static int32_t Get_Gamma_RGB_Devctl ( int32_t *p_gamma_red_S32, int32_t *p_gamma_green_S32, int32_t *p_gamma_blue_S32 );
/**************************************************
 * Display interface function pointer initialization
 **************************************************/
ts_display_funcs display_drv_entry =
{
    sizeof ( ts_display_funcs ),
    Init_Display,                                 /* init */
    Enable_Display,                               /*Enable_Display*/
    Get_Display_Power,                            /*Get_Display_power*/
    Get_Display_Power_Devctl,                     /*Get_Display_power_devctl*/
    Get_Display_state,                            /*Get_Display_state */
    Get_Display_state_Devctl,                     /*Get_Display_state_Devctl*/
    Get_Display_Thermal_Temperature_Value,        /*Get_Display_Thermal_Temperature_Value*/
    Get_Display_Thermal_Temperature_Value_Devctl, /*Get_Display_Thermal_Temperature_Value_Devctl*/
	Deinit_Display,								  /*Deinit */
	Set_Gamma_RGB_Devctl,						  /*Set_Gamma_RGB_Devctl */
	Get_Gamma_RGB_Devctl						  /*Get_Gamma_RGB_Devctl */
};

LOG_DECLARE_CONTEXT ( gDisplayLibLogContext );

/*!*******************************************************************************************************************
 *  \fn              static int32_t Init_Display ( void )
                     Function Name: Init_Display
 *  \brief           Display Gpios configuration
 *  \param[in]       void
 *  \return          int32_t    Error code to indicate success or failure
 *********************************************************************************************************************/
static int32_t Init_Display ( void )
{
    int32_t l_status_S32 = EXIT_FAILURE;

    LOG_REGISTER_CONTEXT(gDisplayLibLogContext, "DisplayLib", "Display_Lib Component", DLT_LOG_WARN);

    l_status_S32 = dk_bspal_dio_set_direction  ( ( uint8_t ) DO_DISP_RESET, e_gpio_direction_out );

    if ( EOK == l_status_S32 )
    {
        l_status_S32 = dk_bspal_dio_set_direction  ( ( uint8_t ) DO_DISP_STBY, e_gpio_direction_out );
    }
    else
    {
        LOGE (&gDisplayLibLogContext, " Display Gpio %d config fail", ( uint8_t ) DO_DISP_RESET );
    }

    if ( EOK == l_status_S32 )
    {
        l_status_S32 = dk_bspal_dio_set_direction  ( ( uint8_t ) DO_PWM_DIMMING, e_gpio_direction_out );
    }
    else
    {
        LOGE (&gDisplayLibLogContext," Display Gpio %d config fail", ( uint8_t ) DO_DISP_STBY );
    }
    if ( EOK == l_status_S32 )
    {
        l_status_S32 = dk_bspal_dio_set_value ( ( uint8_t ) DO_DISP_RESET, false );
    }
    else
    {
        LOGE (&gDisplayLibLogContext," Display Gpio %d config fail", ( uint8_t ) DO_PWM_DIMMING );
    }

    if ( EOK == l_status_S32 )
    {
        l_status_S32 = dk_bspal_dio_set_value ( ( uint8_t ) DO_DISP_STBY, false );
    }
    else
    {
        LOGE (&gDisplayLibLogContext," Display Gpio %d set value fail", ( uint8_t ) DO_DISP_RESET );
    }

    if ( EOK == l_status_S32 )
    {
        l_status_S32 = dk_bspal_dio_set_value ( ( uint8_t ) DO_PWM_DIMMING, false );
    }
    else
    {
        LOGE (&gDisplayLibLogContext," Display Gpio %d set value fail", ( uint8_t ) DO_DISP_STBY );
    }

    if ( EOK == l_status_S32 )
    {
        LOGI (&gDisplayLibLogContext, "Init Success!" );
    }
    else
    {
        LOGE (&gDisplayLibLogContext," Display Gpio %d set value fail", ( uint8_t ) DO_PWM_DIMMING );
    }

    return l_status_S32;

}

/*!*******************************************************************************************************************
 *  \fn              static int32_t Enable_Display ( uint8_t *p_enable_display_U8 )
                     Function Name: Enable_Display
 *  \brief           To enable and disable the Display Gpios configuration
 *  \param[in]       *p_enable_display_BOOL - bool indicates whether to enable or disable the display
 *  \return          int32_t    Error code to indicate success or failure
 *********************************************************************************************************************/
static int32_t Enable_Display ( uint8_t *p_enable_display_U8 )
{
    int32_t l_status_S32 = EXIT_FAILURE;

    switch ( *p_enable_display_U8 )
    {
        case DISPLAY_EPOWER_ON:

            l_status_S32 = dk_bspal_dio_set_value ( ( uint8_t ) DO_DISP_RESET, true );

            if ( EOK == l_status_S32 )
            {
                ( void ) delay ( MIN_DELAY_RST_DISP );  /*20ms, as per spec delay >= 10ms */
                l_status_S32 = Set_Display_State ( DISPLAY_EPOWER_ON );
                if ( EOK == l_status_S32 )
                {
                    ( void ) delay ( MIN_DELAY_DISP_STBY );  /*20ms, as per spec delay >= 10ms */
                    l_status_S32 = dk_bspal_dio_set_value ( ( uint8_t ) DO_DISP_STBY, true );
                    lcd_on_BOOL = true;
                    if ( EOK == l_status_S32 )
                    {
                        ( void ) delay ( MIN_DELAY_OFF_STBY_PWM_DIM );  /* delay 250 ms */
                        l_status_S32 = dk_bspal_dio_set_value ( ( uint8_t ) DO_PWM_DIMMING, true );
                        if ( EOK == l_status_S32 )
                        {
                            LOGI (&gDisplayLibLogContext, "Display DO_PWM_DIMMING %d set Success", ( uint8_t ) DO_PWM_DIMMING );
                        }
                        else
                        {
                            LOGE (&gDisplayLibLogContext,"Display DO_PWM_DIMMING %d set Fail", ( uint8_t ) DO_PWM_DIMMING );
                        }
                    }
                    else
                    {
                        LOGE (&gDisplayLibLogContext,"Display DO_DISP_STBY %d set Fail", ( uint8_t ) DO_DISP_STBY );
                    }
                }
                else
                {
                    LOGE (&gDisplayLibLogContext,"Error while setting display state to %d", DISPLAY_EPOWER_ON );
                }
            }
            else
            {
                LOGE (&gDisplayLibLogContext,"Display DO_DISP_RESET %d set Fail", ( uint8_t ) DO_DISP_RESET );
            }
            break;

        /*Power down sequence implemented as per attachment attachment 447694 (2824895_HSIS_power-up.png) in Task 1386142 */
        case DISPLAY_EPOWER_OFF:
            if ( EOK ==  Set_Display_State ( DISPLAY_EPOWER_OFF ) )
            {
                if ( 0 == dk_bspal_dio_set_value ( ( uint8_t ) DO_DISP_RESET, false ) )
                {
                        lcd_on_BOOL = false;
                        l_status_S32 = EOK;
                        LOGI (&gDisplayLibLogContext, "Display state set to %d success", DISPLAY_EPOWER_OFF );
                 }
                 else
                 {
                     LOGE (&gDisplayLibLogContext,"Display power set to %d fail", DISPLAY_EPOWER_OFF);
                 }
            }
            else
            {
				LOGE (&gDisplayLibLogContext,"Display DO_DISP_RESET %d set Fail", ( uint8_t ) DO_DISP_RESET );
            }
            break;

        default:
            LOGE (&gDisplayLibLogContext,"Invalid input %d to Enable_Display()", *p_enable_display_U8 );
            break;
    }

    return l_status_S32;
}

/*!*******************************************************************************************************************
 *  \fn              static int32_t Deinit_Display ( void )
                     Function Name: Deinit_Display
 *  \brief           To deinit display
 *  \param[in]       none
 *  \return          int32_t    Error code to indicate success or failure
 *********************************************************************************************************************/
static int32_t Deinit_Display ( void )
{
    LOGI (&gDisplayLibLogContext, "Enter" );

    LOG_UNREGISTER_CONTEXT(gDisplayLibLogContext);

    return EOK;
}

/*!*******************************************************************************************************************
 *  \fn              static int32_t Get_Display_Power ( uint8_t *p_power_U8 )
                     Function Name: Get_Display_Power
 *  \brief           To get the display power value
 *  \param[in]       *p_value_power_U8 - uint8_t power value to get
 *  \return          int32_t    Error code to indicate success or failure
 *********************************************************************************************************************/
static int32_t Get_Display_Power ( uint8_t *p_power_U8 )
{
    int32_t l_status_S32 = EOK;

    if ( true == lcd_on_BOOL )
    {
        *p_power_U8 = DISPLAY_EPOWER_ON;
    }
    else
    {
        *p_power_U8 = DISPLAY_EPOWER_OFF;
    }

    return l_status_S32;
}

/*!*******************************************************************************************************************
 *  \fn              static int32_t Get_Display_Power_Devctl ( uint8_t *p_value_U8 )
                     Function Name: Get_Display_Power_Devctl
 *  \brief           To get the display power value
 *  \param[in]       *p_value_power_U8 - uint8_t power value to get
 *  \return          int32_t    Error code to indicate success or failure
 *********************************************************************************************************************/

static int32_t Get_Display_Power_Devctl ( uint8_t *p_value_U8 )
{
    int32_t l_status_S32 = EOK;

    if ( true == lcd_on_BOOL )
    {
        *p_value_U8 = DISPLAY_EPOWER_ON;
    }
    else
    {
        *p_value_U8 = DISPLAY_EPOWER_OFF;
    }

    return l_status_S32;
}

/*!*******************************************************************************************************************
 *  \fn              static int32_t Get_Display_state ( uint8_t *p_state_U8 )
                     Function Name: Get_Display_state
 *  \brief           To get the display state
 *  \param[in]       *p_state_U8 - uint8_t power state to get
 *  \return          int32_t    Error code to indicate success or failure
 *********************************************************************************************************************/
static int32_t Get_Display_state ( uint8_t *p_state_U8 )
{
    int32_t l_status_S32 = EOK;
   
           if ( true == lcd_on_BOOL )
        {
            ( void ) snprintf ( ( char * ) p_state_U8, MAX_POWER_STATUS_LEN, "%s", DISPLAY_STATE_ON );
        }
        else
        {
            ( void ) snprintf ( ( char * ) p_state_U8, MAX_POWER_STATUS_LEN, "%s", DISPLAY_STATE_OFF );
        }

        ( void ) strncat ( ( char * ) p_state_U8, "\n", strlen ( "\n" ) );

    return l_status_S32;
}

/*!*******************************************************************************************************************
 *  \fn              static int32_t Get_Display_state_Devctl ( uint8_t *p_value_U8 )
                     Function Name: Get_Display_state_Devctl
 *  \brief           To get the display state
 *  \param[in]       *p_state_U8 - uint8_t power state to get
 *  \return          int32_t    Error code to indicate success or failure
 *********************************************************************************************************************/
static int32_t Get_Display_state_Devctl ( uint8_t *p_value_U8 )
{
    int32_t l_status_S32 = EOK;
        if ( true == lcd_on_BOOL )
        {
            *p_value_U8 = DISPLAY_ESTATE_ON;
        }
        else
        {
            *p_value_U8 = DISPLAY_ESTATE_OFF;
    }

    return l_status_S32;
}

/*!*******************************************************************************************************************
 *  \fn              static int32_t Get_Display_Thermal_Temperature_Value ( uint8_t *p_value_U8 )
                     Function Name: Get_Display_Thermal_Temperature_Value
 *  \brief           To get the display Thermal temperature value
 *  \param[in]       *p_state_U8 -uint8_t temperature value to get
 *  \return          int32_t    Error code to indicate success or failure
 *********************************************************************************************************************/
static int32_t Get_Display_Thermal_Temperature_Value ( uint8_t *p_value_U8 )
{
    int32_t l_status_S32 = EOK;
    *p_value_U8 = 0;
    return l_status_S32;
}

/*!*******************************************************************************************************************
 *  \fn              static int32_t Get_Display_Thermal_Temperature_Value_Devctl ( uint32_t *p_temp_U32 )
                     Function Name: Get_Display_Thermal_Temperature_Value_Devctl
 *  \brief           To get the display Thermal temperature value
 *  \param[in]       *p_state_U8 -uint8_t temperature value to get
 *  \return          int32_t    Error code to indicate success or failure
 *********************************************************************************************************************/
static int32_t Get_Display_Thermal_Temperature_Value_Devctl ( uint32_t *p_temp_U32 )
{
    int32_t l_status_S32 = EOK;
    *p_temp_U32 = 0;
    return l_status_S32;
}

/*!*******************************************************************************************************************
 *  \fn              static int32_t Set_Display_State ( uint8_t p_onflag )
                     Function Name: Set_Display_State
 *  \brief           control the display power and LVDS state,
 *  \param[in]       p_onflag - set to 1 to turn on, 0 for off
 *  \return          int32_t    Error code to indicate success or failure
 *********************************************************************************************************************/
static int32_t Set_Display_State ( uint8_t p_onflag )
{
    int32_t l_success_flag = EXIT_FAILURE;
    int32_t l_display_count = 1;
    int32_t l_display_num = 0;
    int32_t l_powermode = 0;
    int32_t l_powermode_current = 0;
    screen_context_t l_screen_ctx = NULL;
    screen_display_t l_display_handle[DISPLAYSERVICE_MAX_DISPLAY_COUNT] = {0};

    if ( 0 ==  screen_create_context ( &l_screen_ctx, ( SCREEN_POWER_MANAGER_CONTEXT ) ) )
    {
        if ( 0 == screen_get_context_property_iv ( l_screen_ctx, SCREEN_PROPERTY_DISPLAY_COUNT, &l_display_count ) )
        {
            if ( l_display_count > DISPLAYSERVICE_MAX_DISPLAY_COUNT )
            {
                /* more displays than we can handle */
                LOGE (&gDisplayLibLogContext,"ERROR! Way too many displays [%d]", l_display_count );
            }
            else if ( 1 == l_display_count )
            {
                if ( 0 == screen_get_context_property_pv ( l_screen_ctx, SCREEN_PROPERTY_DISPLAYS, ( void ** ) l_display_handle ) )
                {
                    /* determine the power mode value we will be setting, based on the parameter */
                    if ( p_onflag == DISPLAY_EPOWER_ON )
                    {
                        l_powermode = ( int32_t ) SCREEN_POWER_MODE_ON;
                    }
                    else /* power/LVDS will be off */
                    {
                        l_powermode = ( int32_t ) SCREEN_POWER_MODE_OFF;
                    }

                    for ( l_display_num = 0; ( l_display_num < l_display_count ); l_display_num++ )
                    {
                        /* set the power mode of the current display*/
                        if ( 0 ==  screen_set_display_property_iv ( l_display_handle[l_display_num], SCREEN_PROPERTY_POWER_MODE, &l_powermode ) )
                        {
                            if ( 0 == screen_get_display_property_iv ( l_display_handle[l_display_num], SCREEN_PROPERTY_POWER_MODE, &l_powermode_current ) )
                            {
                                if ( l_powermode_current == l_powermode )
                                {
                                    /* success. Power mode commanded and verified. */
                                    LOGI (&gDisplayLibLogContext, "display [%d] powermode is set as expected [0x%X] ", l_display_num, l_powermode );
                                    l_success_flag = EOK;
                                }
                                else /* commanded power mode does not match current power mode */
                                {
                                    /* current power mode is not what was just commanded. */
                                    LOGE (&gDisplayLibLogContext,"power mode is [0x%X] but expected [0x%X] ", l_powermode_current, l_powermode );
                                }
                            }
                            else
                            {
                                if ( __get_errno_ptr() != NULL )
                                {
                                    LOGE (&gDisplayLibLogContext,"power mode set to [0x%X] but not verified error %s ", l_powermode, strerror ( errno ) );
                                }
                            }
                        }
                        else
                        {
                            LOGE (&gDisplayLibLogContext,"Could not set display [%d] power mode to [0x%X]", l_display_num, l_powermode );
                        }
                    }
                }
                else
                {
                    LOGE (&gDisplayLibLogContext,"could not get display handles" );
                }
            }
            else  /* could not determine display count */
            {
                LOGE (&gDisplayLibLogContext,"no displays found" );
            }
        }
        else
        {
            LOGE (&gDisplayLibLogContext,"could not get display count" );
        }

        /* flush the context/buffer to ensure pending commands are completed */
        screen_flush_context ( l_screen_ctx, 0 );

        /* remove the screen connection */
        screen_destroy_context ( l_screen_ctx );
    }
    else /* could not connect to screen */
    {
        LOGE (&gDisplayLibLogContext,"could not connect to screen" );
    }

    return ( l_success_flag );
}

/*!*******************************************************************************************************************
 *  \fn             void generate_gamma_table(double gamma, int32_t resolution, int32_t size, int32_t * arr)
                    Function Name: generate_gamma_table
 *  \brief          Generate the Gamma Array of 256 for the gamma factor input
 *  \param[in]      gamma - Gamma Factor
                    resolution- Max Value for the Gamma Curve
                    size - Gamma Curve Steps
 *  \return         Null
 *********************************************************************************************************************/
void generate_gamma_table(double gamma, int32_t resolution, int32_t size, int32_t * arr)
{
	int32_t i =0;

	for ( i = 0; i < size; i++)
	{
		arr[i] = pow(i, gamma);
	}

	double max_val = 0;
	for ( i = 0; i < size; i++)
	{
		if (arr[i] > max_val)
		{
			max_val = arr[i];
		}
	}

	for ( i = 0; i < size; i++)
	{
		arr[i] = (int)fmin(resolution, round((double)((double)arr[i] / max_val) * resolution));
	}
}

/*!*******************************************************************************************************************
 *  \fn             static int32_t Set_Gamma_RGB_Devctl ( int32_t  p_gamma_red_S32, int32_t	 p_gamma_green_S32, int32_t	 p_gamma_blue_S32 )
                    Function Name:Set_Gamma_RGB_Devctl
 *  \brief          control the display Gamma Factor for RED, GREEN, BLUE,
 *  \param[in]      p_gamma_red_S32,p_gamma_green_S32,p_gamma_blue_S32 - Set the Display Property - Gamma Correction respectively for RGB
 *  \return         int32_t	  Error code to indicate success or failure
 *********************************************************************************************************************/
static int32_t Set_Gamma_RGB_Devctl ( int32_t  p_gamma_red_S32, int32_t	 p_gamma_green_S32, int32_t	 p_gamma_blue_S32 )
{
	int32_t ret=EOK;
	int32_t l_display_count=1;
	int32_t r_curve[GAMMA_NUM_STEPS];
	int32_t g_curve[GAMMA_NUM_STEPS];
	int32_t b_curve[GAMMA_NUM_STEPS];
	double l_gamma_val_u32=0;
	screen_context_t l_screen_ctx = NULL;
	screen_display_t l_display_handle[DISPLAYSERVICE_MAX_DISPLAY_COUNT] = {0};
	memset( r_curve, 0, GAMMA_NUM_STEPS );
	memset( g_curve, 0, GAMMA_NUM_STEPS );
	memset( b_curve, 0, GAMMA_NUM_STEPS );

	if( EOK == screen_create_context(&l_screen_ctx, SCREEN_DISPLAY_MANAGER_CONTEXT))
	{
		ret = screen_get_context_property_iv (l_screen_ctx, SCREEN_PROPERTY_DISPLAY_COUNT, &l_display_count);

		if( EOK != ret )
		{
			LOGE (&gDisplayLibLogContext,"screen_get_context_property_iv failed %d\n", ret);
		}
		else
		{
			LOGI (&gDisplayLibLogContext,"Number of displays %d\n", l_display_count);
		}

		if(( EOK == ret ) && (l_display_count <= DISPLAYSERVICE_MAX_DISPLAY_COUNT))
		{
			ret = screen_get_context_property_pv (l_screen_ctx, SCREEN_PROPERTY_DISPLAYS, ( void ** ) l_display_handle);

			if( EOK != ret )
			{
				LOGE (&gDisplayLibLogContext,"screen_get_context_property_iv failed %d\n", ret);
			}
			else
			{
			/*MISRA*/
			}
		} else {
			ret = -1;
			/* more displays than we can handle */
			LOGE (&gDisplayLibLogContext,"ERROR! Way too many displays [%d]", l_display_count );
		}

		if(( EOK == ret ) && ( p_gamma_red_S32 != -1 ))
		{
			l_gamma_val_u32 = (double) p_gamma_red_S32/SCALING_FACTOR;
			generate_gamma_table(l_gamma_val_u32, GAMMA_MAX_VALUE, GAMMA_NUM_STEPS, r_curve);

			/* Set Display property for GAMMA_RED */
			ret = screen_set_display_property_iv (l_display_handle[0], SCREEN_PROPERTY_RED_GAMMA_CURVE, r_curve);

			if( EOK != ret )
			{
				LOGE (&gDisplayLibLogContext," screen_set_display_property_iv failed for GAMMA_RED %s\n", strerror(errno));
			}
			else
			{
				g_gamma_red_u32 = l_gamma_val_u32;
				LOGI (&gDisplayLibLogContext, "Display Set Gamma Red %lf \n", l_gamma_val_u32 );
			}
		}

		if(( EOK == ret ) && ( p_gamma_green_S32 != -1 ))
		{
			l_gamma_val_u32 = (double) p_gamma_green_S32/SCALING_FACTOR;
			generate_gamma_table(l_gamma_val_u32, GAMMA_MAX_VALUE, GAMMA_NUM_STEPS, g_curve);

			/* Set Display property for GAMMA_GREEN	  */
			ret = screen_set_display_property_iv (l_display_handle[0], SCREEN_PROPERTY_GREEN_GAMMA_CURVE, g_curve);

			if( EOK != ret )
			{
				LOGE (&gDisplayLibLogContext," screen_set_display_property_iv failed for GAMMA_GREEN %s\n", strerror(errno));
			}
			else
			{
				g_gamma_green_u32 = l_gamma_val_u32;
				LOGI (&gDisplayLibLogContext, "Display Set Gamma Green %lf \n", l_gamma_val_u32 );
			}
		}

		if(( EOK == ret ) && ( p_gamma_blue_S32 != -1 ))
		{
			l_gamma_val_u32 = (double) p_gamma_blue_S32/SCALING_FACTOR;
			generate_gamma_table(l_gamma_val_u32, GAMMA_MAX_VALUE, GAMMA_NUM_STEPS, b_curve);

			/* Set Display property for GAMMA_BLUE	 */
			ret = screen_set_display_property_iv (l_display_handle[0], SCREEN_PROPERTY_BLUE_GAMMA_CURVE, b_curve);

			if( EOK != ret )
			{
				LOGE (&gDisplayLibLogContext,"screen_set_display_property_iv failed for GAMMA_GREEN %s\n", strerror(errno));
			}
			else
			{
				g_gamma_blue_u32 = l_gamma_val_u32;
				LOGI (&gDisplayLibLogContext, "Display Set Gamma Blue %lf \n", l_gamma_val_u32 );
			}
		}

		/* flush the context/buffer to ensure pending commands are completed */
		screen_flush_context(l_screen_ctx, SCREEN_WAIT_IDLE);

		/* remove the screen connection */
		screen_destroy_context ( l_screen_ctx );
	} else {
		LOGE (&gDisplayLibLogContext,"could not connect to screen" );
	}

	return ret;
}

/*!*******************************************************************************************************************
 *  \fn             static int32_t Get_Gamma_RGB_Devctl ( int32_t  p_gamma_red_S32, int32_t	 p_gamma_green_S32, int32_t	 p_gamma_blue_S32 )
                    Function Name:Get_Gamma_RGB_Devctl
 *  \brief          control the display Gamma Factor for RED, GREEN, BLUE,
 *  \param[in]      p_gamma_red_S32,p_gamma_green_S32,p_gamma_blue_S32 - Set the Display Property - Gamma Correction respectively for RGB
 *  \return         int32_t	  Error code to indicate success or failure
 *********************************************************************************************************************/
static int32_t Get_Gamma_RGB_Devctl ( int32_t *p_gamma_red_S32, int32_t *p_gamma_green_S32, int32_t *p_gamma_blue_S32 )
{
	*p_gamma_red_S32=(double)g_gamma_red_u32;
	*p_gamma_green_S32=(double)g_gamma_green_u32;
	*p_gamma_blue_S32=(double)g_gamma_blue_u32;
	LOGI (&gDisplayLibLogContext, "Display Get Gamma Red %lf, Green %lf, Blue %lf \n", g_gamma_red_u32, g_gamma_green_u32, g_gamma_blue_u32 );
	return EOK;
}

