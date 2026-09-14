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


typedef uint8_t display_EState_t;
typedef uint8_t display_EPower_t;

#define DISPLAY_ESTATE_OFF              ((display_EState_t) 0)
#define DISPLAY_ESTATE_ON               ((display_EState_t) 1)
#define DISPLAY_ESTATE_ERROR            ((display_EState_t) 2)
#define DISPLAY_ESTATE_DISCONNECTED     ((display_EState_t) 3)

#define DISPLAY_EPOWER_OFF              ((display_EPower_t) 0)
#define DISPLAY_EPOWER_ON               ((display_EPower_t) 1)

#endif /* CDISPLAY_DEVCTL_H_ */
