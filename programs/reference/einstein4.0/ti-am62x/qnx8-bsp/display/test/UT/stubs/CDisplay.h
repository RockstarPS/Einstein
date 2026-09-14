/**
 **
 ** \file CDisplay_If_Debug.h
 **
 ** \brief Contains Logging APIs used in tianma_display
 ** with resmgr_display driver.
 **
 **  Component Name: tianma_display
 **  Archive:
 **  Date: 03-MAR-2020 13:10:10
 **  Author: STHANGA4
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (�Materials�) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **/

#ifndef CDISPLAY_H_
#define CDISPLAY_H_

#include <sys/slog.h>
#include <sys/slogcodes.h>

#define DO_RESET_TFT                            14U
#define DO_STANDBY_MODE_TFT                     15U
#define DI_LCD_ERR                              12U
#define DI_CON_TEST                              2U

#define MAX_POWER_STATUS_LEN                    14U
#define DISPLAY_STATE_ON                        "ON"
#define DISPLAY_STATE_OFF                       "OFF"
#define DISPLAY_STATE_DISCONNECTED              "DISCONNECTED"
#define DISPLAY_STATE_ERROR                     "ERROR"

/*please refer attachment 447693(2824895_HSIS_power-down.png), attachment 447694 (2824895_HSIS_power-up.png) in Task 1013905*/
#define MIN_DELAY_DISPLAY_ON_MS                  20
#define MIN_DELAY_DISPLAY_OFF_MS                 140
#define DISPLAYSERVICE_MAX_DISPLAY_COUNT         1
#define MIN_DELAY_ERROR_PIN_READ                 166
#define MIN_DELAY_RST_STBY                       1

#endif /* CDISPLAY_IF_DEBUG_H_ */
