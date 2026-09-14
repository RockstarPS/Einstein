/**********************************************************************************
 **
 **  \file CDisplay_Devctl.h
 **
 **  \brief contains Resource Manager API's used to communicate with display driver.
 **
 **  Component Name: resmgr_display
 **  Archive:
 **  Date: 04-MAY-2020
 **  Author: Rajasekhar
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (?Materials?) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, stop or otherwise, any rights in these Materials.
 ***********************************************************************************/

#ifndef CDISPLAY_DEVCTL_H_
#define CDISPLAY_DEVCTL_H_

#include <devctl.h>

typedef uint8_t display_EState_t;
typedef uint8_t display_EPower_t;

#define DISPLAY_ESTATE_OFF              ((display_EState_t) 0)
#define DISPLAY_ESTATE_ON               ((display_EState_t) 1)
#define DISPLAY_ESTATE_ERROR            ((display_EState_t) 2)
#define DISPLAY_ESTATE_DISCONNECTED     ((display_EState_t) 3)

#define DISPLAY_EPOWER_OFF              ((display_EPower_t) 0)
#define DISPLAY_EPOWER_ON               ((display_EPower_t) 1)

typedef struct
{
    uint8_t power_U8;
} display_power_buffer_type_ts;

typedef struct
{
    display_EState_t state;
} display_state_buffer_type_ts;

#define CMD_CODE 1
#define POWER_ID_VALUE_READ      __DIOF(_DCMD_MISC, CMD_CODE + 0, display_power_buffer_type_ts)
#define POWER_ID_VALUE_WRITE     __DIOT(_DCMD_MISC, CMD_CODE + 1, display_power_buffer_type_ts)
#define STATE_ID_VALUE_READ      __DIOF(_DCMD_MISC, CMD_CODE + 2, display_state_buffer_type_ts)

#endif /* CDISPLAY_DEVCTL_H_ */
