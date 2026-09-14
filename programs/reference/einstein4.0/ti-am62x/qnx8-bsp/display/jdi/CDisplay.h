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

/*please refer attachment 447693(2824895_HSIS_power-down.png), attachment 447694 (2824895_HSIS_power-up.png) in Task 1387940*/
#define MIN_DELAY_DISPLAY_EPOWER_ON              10    /*delay 10 us Set_Display_State on  */

#define DO_DISP_RESET                            5U // XCS high - MIPI_DSI1_GPIO0_01
#define DO_DISP_STBY                             23U /* This Configration for JDI Display We are using DO_RESET_TFT and SPI Communication.
We are not using DO_DISP_STBY for JDI */
#define DO_PWM_DIMMING                           14U

#define DI_TFT_BL_FAULT							0U
#define DI_TFT_FAIL								8U


#define MAX_POWER_STATUS_LEN                    4U
#define DISPLAY_STATE_ON                        "ON"
#define DISPLAY_STATE_OFF                       "OFF"
#define DISPLAY_STATE_DISCONNECTED              "DISCONNECTED"
#define DISPLAY_STATE_ERROR                     "ERROR"

/*please refer attachment 447693(2824895_HSIS_power-down.png), attachment 447694 (2824895_HSIS_power-up.png) in Task 1386142*/
//#define MIN_DELAY_DISPLAY_ON_MS                  120
#define MIN_DELAY_DISPLAY_OFF_MS                 100
#define DISPLAYSERVICE_MAX_DISPLAY_COUNT         1
#define MIN_DELAY_ERROR_PIN_READ                 166
#define MIN_DELAY_RST_DISP                       20 /* t >= 10ms */
#define MIN_DELAY_DISP_STBY                      20 /* t >= 10ms */
#define MIN_DELAY_OFF_STBY_PWM_DIM               250

#endif /* CDISPLAY_IF_DEBUG_H_ */
