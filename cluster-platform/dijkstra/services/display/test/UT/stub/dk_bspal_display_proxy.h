/**********************************************************************************
 **
 **  \file dk_bspal_display_proxy.h
 **
 **  \brief
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

#ifndef DK_BSPAL_DISPLAY_PROXY_H_
#define DK_BSPAL_DISPLAY_PROXY_H_

#include "CDisplay_Devctl.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
typedef enum

{

    EBspalDisplayPower_Off,

    EBspalDisplayPower_On,

} EBspalDisplayPower_t;



typedef enum

{

    EBspalDisplayState_Off,

    EBspaDisplayState_On,

    EBspaDisplayState_Error,

    EBspalDisplayState_Disconnected,

} EBspalDisplayStatus_t;

//extern int32_t dk_bspal_display_set_power ( uint32_t p_id_U32, display_EPower_t p_value_S );

//extern int32_t dk_bspal_display_get_state ( uint32_t p_id_U32, display_EState_t *p_value_SP );

extern int32_t dk_bspal_display_set_power ( const uint8_t p_id_U8, const EBspalDisplayPower_t p_value_E );

extern int32_t dk_bspal_display_get_state ( const uint8_t p_id_U8, EBspalDisplayStatus_t *const p_value_EP );

extern int32_t dk_bspal_display_set_gamma_rgb ( const uint8_t p_id_U8, int32_t  p_gamma_red_S32, int32_t  p_gamma_green_S32, int32_t  p_gamma_blue_S32 );

extern int32_t dk_bspal_display_get_gamma_rgb ( const uint8_t p_id_U8, int32_t *p_gamma_red_S32, int32_t *p_gamma_green_S32, int32_t *p_gamma_blue_S32 );

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* DK_BSPAL_DISPLAY_PROXY_H_ */
