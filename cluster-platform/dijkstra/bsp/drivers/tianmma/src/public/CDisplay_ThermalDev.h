/**********************************************************************************
 **
 **  \file CDisplay_ThermalDev.h
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
 ** (�Materials�) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, stop or otherwise, any rights in these Materials.
 ***********************************************************************************/
#ifndef CDISPLAY_THERMALDEV_H_
#define CDISPLAY_THERMALDEV_H_

#include <devctl.h>
///
/// @brief struct thermal_temperature_buffer used by devctl
///
/// @param temperature_value; [in] temperature  value
///
#define THERMAL_TYPE_MAX 10U
typedef struct
{
    uint32_t temperature_value;
} thermal_temperature_buffer;

typedef struct
{
    char thermal_type[THERMAL_TYPE_MAX];
} thermal_type_buffer;

#define THERMAL_TEMPERATURE_READ  __DIOF(_DCMD_MISC, 1, thermal_temperature_buffer)
#define THERMAL_TYPE_READ         __DIOF(_DCMD_MISC, 2, thermal_type_buffer)


#endif /* CLP8860_THERMALDEV_H_ */
