/**********************************************************************************
 **
 **  \file dk_bspal_dio_proxy.h
 **
 **  \brief API for interaction with BSPAL DIO library
 **
 **  Component Name: bspal_dio
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (?Materials?) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, stop or otherwise, any rights in these Materials.
 ***********************************************************************************/

#include <stdint.h>
#include <stdbool.h>

#ifndef DK_BSPAL_DIO_PROXY_H_
#define DK_BSPAL_DIO_PROXY_H_

#if defined(__QNX__) || defined(__MINGW32__)
//#include "CDio_Devctl.h"
#else
#ifdef __cplusplus
extern "C" {
#endif
	typedef enum
	{
		e_gpio_direction_in = 0,
		e_gpio_direction_out
	} EDirection;

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	extern void dk_bspal_dio_init ( void );
	extern void dk_bspal_dio_deinit ( void );
	extern int32_t dk_bspal_dio_set_value ( const uint32_t p_pin_U32, const bool p_value_BOOL );
	extern int32_t dk_bspal_dio_get_value ( const uint32_t p_pin_U32, bool *const p_value_BOOLP );
	//extern int32_t dk_bspal_dio_set_direction ( const uint32_t p_pin_U32, const EDirection p_direction_te );
	//extern int32_t dk_bspal_dio_get_direction ( const uint32_t p_pin_U32, EDirection *const p_direction_TEP );
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
#endif // DK_BSPAL_DIO_PROXY_H_
