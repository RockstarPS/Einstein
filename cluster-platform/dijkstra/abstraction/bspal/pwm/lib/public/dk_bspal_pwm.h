/**********************************************************************************
 **
 **  \file dk_bspal_pwm.h
 **
 **  \brief API for interaction with BSPAL PWM library
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

#ifndef DK_BSPAL_PWM_H_
#define DK_BSPAL_PWM_H_

#include <stdint.h>
#include <stdbool.h>

#if defined(__QNX__) || defined(__MINGW32__)
#include "pwm_devctl.h"
#else
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	extern int32_t  dk_bspal_pwm_set_brightness (unsigned int l_set_br_val );
	extern int32_t  dk_bspal_pwm_get_brightness (unsigned int *const br_val );
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

	extern void dk_bspal_pwm_init ( void );
	extern void dk_bspal_pwm_deinit ( void );

	extern int32_t dk_bspal_pwm_set_period ( const uint8_t p_pin_U8, const uint32_t dc_val_U32 );
	extern int32_t dk_bspal_pwm_get_period ( const uint8_t p_pin_U8, uint32_t *const dc_val_U32 );
	extern int32_t dk_bspal_pwm_set_dutycycle ( const uint8_t p_pin_U8, const uint32_t dc_val_U32 );
	extern int32_t dk_bspal_pwm_get_dutycycle ( const uint8_t p_pin_U8, uint32_t *const dc_val_U32 );
	extern int32_t dk_bspal_pwm_set_enable ( const uint8_t p_pin_U8, const uint32_t dc_val_U32 );
	extern int32_t dk_bspal_pwm_get_enable ( const uint8_t p_pin_U8, uint32_t *const dc_val_U32 );

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* DK_BSPAL_PWM_H_ */