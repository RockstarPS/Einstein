/**********************************************************************************
 **
 **  \file CDisplay_interface.h
 **
 **  \brief contains Resource Manager API's used to communicate with Display driver.
 **
 **  Component Name: resmgr_display
 **  Archive:
 **  Date: 04-MAY-2020
 **  Author: Rajasekhar
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (Materials) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, stop or otherwise, any rights in these Materials.
 ***********************************************************************************/

#ifndef CDISPLAY_INTERFACE_H_
#define CDISPLAY_INTERFACE_H_

#include <stdio.h>
#include <stdint.h>



typedef struct
{
    /* size of this structure */
    size_t  size;
    int32_t ( *Init_Display ) ( void );
    int32_t ( *Enable_Display ) ( uint8_t *p_enable_display_U8 );
    int32_t ( *Get_Display_Power ) ( uint8_t *p_power_U8 );
    int32_t ( *Get_Display_Power_Devctl ) ( uint8_t *p_value_U8 );
    int32_t ( *Get_Display_state ) ( uint8_t *p_state_U8 );
    int32_t ( *Get_Display_state_Devctl ) ( uint8_t *p_value_U8 );
    int32_t ( *Get_Thermal_Temperature_Value ) ( uint8_t *p_value_U8 );
    int32_t ( *Get_Thermal_Temperature_Value_Devctl ) ( uint32_t *p_temp_U32 );
    int32_t ( *Deinit_Display ) ( void );
} ts_display_funcs;

#endif /* CDISPLAY_INTERFACE_H_ */
