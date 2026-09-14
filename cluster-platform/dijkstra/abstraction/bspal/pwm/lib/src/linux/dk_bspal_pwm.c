/**********************************************************************************
 **
 **  \file dk_bspal_pwm.c
 **
 **  \brief contains API implementation for interaction with BSPAL PWM library
 **
 **  Component Name: bspal_pwmLinux
 **  Archive:
 **  Date: 24-12-2021
 **  Author: nveerann
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

#define PATH_LEN (100u)
#define BRIGHTNESS_PATH  "/sys/class/backlight/backlight/brightness"
#define PERIOD_PATH      "/sys/class/pwm/pwmchip%d/pwm0/period"
#define DUTYCYCLE_PATH   "/sys/class/pwm/pwmchip%d/pwm0/duty_cycle"
#define ENABLE_PATH      "/sys/class/pwm/pwmchip%d/pwm0/enable"
#define IS_EXPORTED      "/sys/class/pwm/pwmchip%d/pwm0"
#define EXPORT_PATH      "/sys/class/pwm/pwmchip%d/export"

static int32_t dk_bspal_pwm_export_pin ( const uint8_t p_pin_id_U8 );

/**********************************************************************************
  @brief API to register context for logging.
 ***********************************************************************************/
void dk_bspal_pwm_init ( void )
{
	printf(" %s invoked \n",__func__);
}

/**********************************************************************************
  @brief API to unregister context.
 ***********************************************************************************/
void dk_bspal_pwm_deinit ( void )
{
	printf(" %s invoked \n",__func__);
}


/**********************************************************************************
  @brief API to checkif pwm channel is exported or not
  @param[in] p_pin_id_U8        The pwmchip interested in.

  @return enable status.
 ***********************************************************************************/
bool dk_bspal_check_if_exported(const uint8_t p_pin_id_U8 )
{

	int  l_ret_spf_SINT = -1;
	bool l_status_bool =false;
	char l_exported[PATH_LEN];

	l_ret_spf_SINT = snprintf ( l_exported, PATH_LEN, IS_EXPORTED, p_pin_id_U8 );
	if ( l_ret_spf_SINT < 0 )
	{
		printf (  "sprintf call failed\n" );
		l_status_bool = false;
	}
	else{
		printf("l_path_S8  path is =%s\n",l_exported);

		if( access( l_exported , F_OK ) == 0 )
		{

			printf("Already exported \n");
			l_status_bool = true;

		}
		else
		{
			printf(" not exported \n");
			l_status_bool = false;

		}
	}
	return l_status_bool;
}


/**********************************************************************************
  @brief API to export a PWM pin 0 ,in pwmchip which user is intersted in

  @param[in] p_pin_id_U8    The pwmchip that needs to be exported.
  @return 0 on Success.
 ***********************************************************************************/

static int32_t dk_bspal_pwm_export_pin ( const uint8_t p_pin_id_U8 )
{
	int32_t l_status_S32 = -1;
	char l_expo_pin_id[PATH_LEN] ;
	char l_pwmchip_id[PATH_LEN] ;
	int32_t l_fd_exp_SINT = -1;
	ssize_t  l_sz_write_SINT = -1;
	int  l_ret_spf_SINT = -1;

	l_ret_spf_SINT = snprintf ( l_pwmchip_id, PATH_LEN, EXPORT_PATH, p_pin_id_U8 );

	if ( l_ret_spf_SINT < 0 )
	{
		printf (  "sprintf call failed\n" );
		l_status_S32 = -1;
	}

	printf("pwmichip path is =%s\n",l_pwmchip_id);

	l_fd_exp_SINT = open ( l_pwmchip_id, O_WRONLY );

	if ( l_fd_exp_SINT < 0 )
	{
		printf (  "export  pin %d failed %d\n", p_pin_id_U8,errno );
		l_status_S32 = -1;
	}
	else
	{
		l_ret_spf_SINT = snprintf ( l_expo_pin_id, PATH_LEN, "%d", 0 );

		if ( l_ret_spf_SINT < 0 )
		{
			printf (  "sprintf call failed\n" );
			l_status_S32 = -1;
		}
		else
		{

			l_sz_write_SINT = write ( l_fd_exp_SINT, l_expo_pin_id, strlen ( l_expo_pin_id ) );

			if ( l_sz_write_SINT < 0 )
			{
				printf (  "export write call failed" );
				l_status_S32 = -1;
			}
			else
			{
				l_status_S32 = 0;
			}
		}

	}
	close(l_fd_exp_SINT);

	return l_status_S32;

}

/**********************************************************************************
  @brief API to change period of a PWM pin 0 in pwmchip user is interested in.
  @param[in] p_pin_U8        The pwmchip interested in.
  @param[in] period          The value to set period.

  @return pwm period change status.
 ***********************************************************************************/

int32_t dk_bspal_pwm_set_period (const uint8_t p_pin_U8 , const uint32_t period )
{
	char l_path_S8[PATH_LEN];
	int32_t l_expo_S32 = -1;
	int32_t l_return_S32 = -1;
	int l_spf_SINT = -1;
	int l_fd_SINT  = -1;
	char l_write_buf[PATH_LEN] ;
	ssize_t  l_sz_write_SINT = -1;
	int  l_ret_spf_SINT = -1;

	if(dk_bspal_check_if_exported( p_pin_U8 )==false)
	{
		l_expo_S32 = dk_bspal_pwm_export_pin ( p_pin_U8 );

		if ( l_expo_S32 < 0 )
		{
			printf ( "Check if the pwmchip is enabled in kernel \n" );
			exit(0);
		}
	}
	l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, PERIOD_PATH, p_pin_U8 );
	printf("l_path_S8  path is =%s\n",l_path_S8);
	if ( l_spf_SINT < 0 )
	{
		l_return_S32 = -1;
		printf (  "snprintf() failed\n" );
	}
	else
	{

		l_fd_SINT = open ( l_path_S8, O_RDWR );

		if ( l_fd_SINT < 0 )
		{
			l_return_S32 = -1;
			printf (  "setperiod open() failed \n" );
		}
		else
		{

			l_ret_spf_SINT = snprintf ( l_write_buf, PATH_LEN, "%d", period );

			printf("period is =%s\n",l_write_buf);

			if ( l_ret_spf_SINT < 0 )
			{
				printf (  "sprintf call failed\n" );
				l_return_S32 = -1;
			}
			else
			{

				l_sz_write_SINT = write ( l_fd_SINT, l_write_buf, strlen ( l_write_buf ) );

				if ( l_sz_write_SINT < 0 )
				{
					printf (  "setperiod write call failed %d\n",errno );
					l_return_S32 = -1;
				}
				else
				{
					l_return_S32 = 0;
				}


			}
			( void ) close ( l_fd_SINT );
		}
	}
	return l_return_S32;
}

/**********************************************************************************
  @brief API to read period of a PWM pin 0 in pwmchip user is interested in.
  @param[in] p_pin_U8         The pwmchip interested in.
  @param[in] pd_val          pointer to store the period to be read

  @return pwm period read status.
 ***********************************************************************************/
int32_t dk_bspal_pwm_get_period ( const uint8_t  p_pin_U8, uint32_t *const pd_val )
{
	char l_path_S8[PATH_LEN];
	int32_t l_expo_S32 = -1;
	int32_t l_return_S32 = -1;
	int l_spf_SINT = -1;
	int l_fd_SINT  = -1;
	char l_read_buf[PATH_LEN];
	ssize_t  l_sz_read_SINT = -1;
	unsigned int periodvalue;

	if(dk_bspal_check_if_exported( p_pin_U8 )==false)
	{

		l_expo_S32 = dk_bspal_pwm_export_pin ( p_pin_U8 );

		if ( l_expo_S32 < 0 )
		{
			printf ( "Check if the pwmchip is enabled in kernel \n" );
			exit(0);
		}
	}

	l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, PERIOD_PATH, p_pin_U8 );

	printf("l_path_S8  path is =%s\n",l_path_S8);

	if ( l_spf_SINT < 0 )
	{
		l_return_S32 = -1;
		printf (  "snprintf() failed\n" );
	}
	else
	{
		l_fd_SINT = open ( l_path_S8, O_RDWR );

		if ( l_fd_SINT < 0 )
		{
			l_return_S32 = -1;
			printf (  " get period open() failed\n" );
		}
		else
		{

			while ((l_sz_read_SINT = read(l_fd_SINT, l_read_buf, sizeof(l_read_buf)-1)) > 0) {
				l_read_buf[l_sz_read_SINT] = '\0';
				periodvalue = atoi(l_read_buf);
				*pd_val = periodvalue;
				printf(" period is %d \n", *pd_val);
				l_return_S32 = 0;
			}

			( void ) close ( l_fd_SINT );
		}
	}
	return l_return_S32;
}


/**********************************************************************************
  @brief API to change dutycycle of a PWM pin 0 in pwmchip user is interested in.
  @param[in] p_pin_U8        The pwmchip interested in.
  @param[in] dc_val          The value to be set dutycycle.

  @return duty cycle change status.
 ***********************************************************************************/

int32_t dk_bspal_pwm_set_dutycycle ( const uint8_t p_pin_U8, const uint32_t dc_val_U32 )
{
	char l_path_S8[PATH_LEN];
	int32_t l_expo_S32 = -1;
	int32_t l_return_S32 = -1;
	int l_spf_SINT = -1;
	int l_fd_SINT  = -1;
	char l_write_buf[PATH_LEN] ;
	ssize_t  l_sz_write_SINT = -1;
	int  l_ret_spf_SINT = -1;
	if(dk_bspal_check_if_exported(p_pin_U8)==false)
	{
		l_expo_S32 = dk_bspal_pwm_export_pin ( p_pin_U8 );

		if ( l_expo_S32 < 0 )
		{
			printf ( "Check if the pwmchip is enabled in kernel \n" );
			exit(0);
		}
	}
	l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, DUTYCYCLE_PATH, p_pin_U8 );

	printf("l_path_S8  path is =%s\n",l_path_S8);

	if ( l_spf_SINT < 0 )
	{
		l_return_S32 = -1;
		printf (  "snprintf() failed \n" );
	}
	else
	{
		l_fd_SINT = open ( l_path_S8, O_RDWR );

		if ( l_fd_SINT < 0 )
		{
			l_return_S32 = -1;
			printf (  "duty cycle open() failed\n" );
		}
		else
		{

			l_ret_spf_SINT = snprintf ( l_write_buf, PATH_LEN, "%d", dc_val_U32 );

			printf("dc_value is =%s\n",l_write_buf);

			if ( l_ret_spf_SINT < 0 )
			{
				printf (  "sprintf call failed\n" );
				l_return_S32 = -1;
			}
			else
			{

				l_sz_write_SINT = write ( l_fd_SINT, l_write_buf, strlen ( l_write_buf ) );

				if ( l_sz_write_SINT < 0 )
				{
					printf (  "dutycycle write call failed %d\n",errno );
					l_return_S32 = -1;
				}
				else
				{
					l_return_S32 = 0;
				}


			}
			( void ) close ( l_fd_SINT );
		}
	}
	return l_return_S32;
}

/**********************************************************************************
  @brief API to read dutycycle of a PWM pin 0 in pwmchip user is interested in.
  @param[in] pwmchip         The pwmchip interested in.
  @param[in] p_pin_U8        The pin which needs to be exported.
  @param[in] dc_val_U32      pointer to store the duty cycle to be read

  @return duty cycle status.
 ***********************************************************************************/

int32_t  dk_bspal_pwm_get_dutycycle ( const uint8_t p_pin_U8, uint32_t *const dc_val_U32 )
{
	char l_path_S8[PATH_LEN];
	int32_t l_expo_S32 = -1;
	int32_t l_return_S32 = -1;
	int l_spf_SINT = -1;
	int l_fd_SINT  = -1;
	char l_read_buf[PATH_LEN];
	ssize_t  l_sz_read_SINT = -1;
	unsigned int dutyvalue;

	if(dk_bspal_check_if_exported(p_pin_U8)==false)
	{

		l_expo_S32 = dk_bspal_pwm_export_pin ( p_pin_U8 );

		if ( l_expo_S32 < 0 )
		{
			printf ( "Check if the pwmchip is enabled in kernel \n" );
			exit(0);
		}
	}
	l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, DUTYCYCLE_PATH, p_pin_U8 );

	printf("l_path_S8  path is =%s\n",l_path_S8);

	if ( l_spf_SINT < 0 )
	{
		l_return_S32 = -1;
		printf (  "snprintf() failed\n" );
	}
	else
	{
		l_fd_SINT = open ( l_path_S8, O_RDWR );

		if ( l_fd_SINT < 0 )
		{
			l_return_S32 = -1;
			printf (  " get dutycycle open() failed\n" );
		}
		else
		{

			while ((l_sz_read_SINT = read(l_fd_SINT, l_read_buf, sizeof(l_read_buf)-1)) > 0) {
				l_read_buf[l_sz_read_SINT] = '\0';
				dutyvalue = atoi(l_read_buf);
				*dc_val_U32 = dutyvalue;
				printf(" duty cycle returned is %d \n", *dc_val_U32);
				l_return_S32 = 0;
			}

			( void ) close ( l_fd_SINT );
		}
	}
	return l_return_S32;
}

/**********************************************************************************
  @brief API to change enable of a PWM pin 0 in pwmchip user is interested in.
  @param[in] p_pin_U8         The pwmchip interested in.
  @param[in] en_val          The value to be set enable.

  @return enable change status.
 ***********************************************************************************/
int32_t dk_bspal_pwm_set_enable ( const uint8_t p_pin_U8, const uint32_t en_val )
{
	char l_path_S8[PATH_LEN];
	int32_t l_expo_S32 = -1;
	int32_t l_return_S32 = -1;
	int l_spf_SINT = -1;
	int l_fd_SINT  = -1;
	char l_write_buf[PATH_LEN] ;
	ssize_t  l_sz_write_SINT = -1;
	int  l_ret_spf_SINT = -1;
	if(dk_bspal_check_if_exported( p_pin_U8)==false)
	{

		l_expo_S32 = dk_bspal_pwm_export_pin ( p_pin_U8 );

		if ( l_expo_S32 < 0 )
		{
			printf ( "Check if the pwmchip is enabled in kernel \n" );
			exit(0);
		}
	}
	l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, ENABLE_PATH,p_pin_U8 );

	printf("l_path_S8  path is =%s\n",l_path_S8);

	if ( l_spf_SINT < 0 )
	{
		l_return_S32 = -1;
		printf (  "snprintf() failed\n" );
	}
	else
	{
		l_fd_SINT = open ( l_path_S8, O_RDWR );

		if ( l_fd_SINT < 0 )
		{
			l_return_S32 = -1;
			printf (  "set enable ,open() failed\n" );
		}
		else
		{

			l_ret_spf_SINT = snprintf ( l_write_buf, PATH_LEN, "%d", en_val );

			printf("pwm en_value is =%s\n",l_write_buf);

			if ( l_ret_spf_SINT < 0 )
			{
				printf (  "sprintf call failed\n" );
				l_return_S32 = -1;
			}
			else
			{

				l_sz_write_SINT = write ( l_fd_SINT, l_write_buf, strlen ( l_write_buf ) );

				if ( l_sz_write_SINT < 0 )
				{
					printf (  "setenable write call failed %d\n",errno );
					l_return_S32 = -1;
				}
				else
				{
					l_return_S32 = 0;
				}


			}
			( void ) close ( l_fd_SINT );
		}
	}
	return l_return_S32;
}


/**********************************************************************************
  @brief API to Read emable of a PWM pin 0 in pwmchip user is interested in.
  @param[in] p_pin_U8         The pwmchip interested in.
  @param[in] en_val          pointer to store the enable to be read

  @return enable status.
 ***********************************************************************************/
int32_t dk_bspal_pwm_get_enable ( const uint8_t p_pin_U8, uint32_t *const en_val )
{
	char l_path_S8[PATH_LEN];
	int32_t l_expo_S32 = -1;
	int32_t l_return_S32 = -1;
	int l_spf_SINT = -1;
	int l_fd_SINT  = -1;
	char l_read_buf[PATH_LEN];
	ssize_t  l_sz_read_SINT = -1;
	unsigned int enablevalue;

	if(dk_bspal_check_if_exported( p_pin_U8)==false)
	{
		l_expo_S32 = dk_bspal_pwm_export_pin ( p_pin_U8 );

		if ( l_expo_S32 < 0 )
		{
			printf ( "Check if the pwmchip is enabled in kernel \n" );
			exit(0);
		}
	}
	l_spf_SINT = snprintf ( l_path_S8, PATH_LEN, ENABLE_PATH, p_pin_U8 );

	printf("l_path_S8  path is =%s\n",l_path_S8);

	if ( l_spf_SINT < 0 )
	{
		l_return_S32 = -1;
		printf (  "snprintf() failed\n" );
	}
	else
	{
		l_fd_SINT = open ( l_path_S8, O_RDWR );

		if ( l_fd_SINT < 0 )
		{
			l_return_S32 = -1;
			printf (  "getenable open() failed\n" );
		}
		else
		{

			while ((l_sz_read_SINT = read(l_fd_SINT, l_read_buf, sizeof(l_read_buf)-1)) > 0) {
				l_read_buf[l_sz_read_SINT] = '\0';
				printf("read enable value  \n<%s>\n", l_read_buf);
				enablevalue = atoi(l_read_buf);
				*en_val = enablevalue;
				printf(" enable value is %d \n", *en_val);
				l_return_S32 = 0;
			}

			( void ) close ( l_fd_SINT );
		}
	}
	return l_return_S32;
}

/**********************************************************************************
  @brief API to set brightness of backlight
  @param[in] l_set_br_val        brightness value to be set.

  @return enable status.
 ***********************************************************************************/
int32_t dk_bspal_pwm_set_brightness (unsigned int l_set_br_val )
{

	char l_buf[PATH_LEN];
	int l_spf_SINT=-1;
	int l_fd_SINT=-1;
	int l_return_S32=-1;
	ssize_t l_spf_write_SINT = -1;

	l_fd_SINT = open ( BRIGHTNESS_PATH, O_RDWR );

	if ( l_fd_SINT < 0 )
	{
		l_return_S32 = -1;
		printf (  "set brightness open() failed\n" );
	}
	else
	{
		l_spf_SINT = snprintf(l_buf, sizeof(l_buf), "%d", l_set_br_val);

		printf("brigtness value passed  is %s",l_buf);
		if ( l_spf_SINT < 0 )
		{
			l_return_S32 = -1;
			printf (  "snprintf() failed" );
		}

		l_spf_write_SINT = write(l_fd_SINT, l_buf, strlen(l_buf));
		if ( l_spf_write_SINT < 0 )
		{
			printf (  "write call failed %d",errno );
			l_return_S32 = -1;
		}
		else
		{
			l_return_S32 = 0;
		}

		close(l_fd_SINT);
	}

	return l_return_S32;
}


/**********************************************************************************
  @brief API to get brightness of backlight
  @param[in] dc_val          pointer to store the backlight brightness

  @return enable status.
 ***********************************************************************************/
int32_t dk_bspal_pwm_get_brightness (unsigned int *const br_val )
{
	int32_t l_return_S32 = -1;
	int l_fd_SINT  = -1;
	char l_read_buf[PATH_LEN];
	ssize_t  l_sz_read_SINT = -1;
	unsigned int brightnessvalue;

	l_fd_SINT = open ( BRIGHTNESS_PATH, O_RDWR );

	if ( l_fd_SINT < 0 )
	{
		l_return_S32 = -1;
		printf (  "brightness open() failed\n" );
	}
	else
	{

		while ((l_sz_read_SINT = read(l_fd_SINT, l_read_buf, sizeof(l_read_buf)-1)) > 0) {
			l_read_buf[l_sz_read_SINT] = '\0';
			brightnessvalue = atoi(l_read_buf);
			*br_val = brightnessvalue;
			printf(" brightness value returned is  %d ", *br_val);
			l_return_S32 = 0;
		}

		( void ) close ( l_fd_SINT );
	}

	return l_return_S32;
}
