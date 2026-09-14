/**
 **
 ** \file pwm_devctl.h
 **
 ** \brief Contains Resource Manager API's used to communicate with pwm driver.
 **
 **  Component Name: dk-bsp-imx8-pwm
 **  Archive:
 **  Date: 03-MAR-2020 13:10:10
 **  Author: STHANGA4
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (?Materials?) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **/

#ifndef SRC_RESMGR_PWM_DEVCTL_H_
#define SRC_RESMGR_PWM_DEVCTL_H_
#include <devctl.h>

typedef struct
{
    uint32_t pwm_enable_U32;
    uint32_t pwm_dc_U32;
    uint32_t pwm_period_U32;
} pwm_buffer_type;

// ##################### DEFINE DEVCTL COMMANDS ##############################

#define CMD_CODE 1
#define DCMD_PWM_WRITE_CH   __DIOT (_DCMD_MISC, CMD_CODE + 0U, pwm_buffer_type)
#define DCMD_PWM_READ_CH    __DIOTF(_DCMD_MISC, CMD_CODE + 1U, pwm_buffer_type)


#endif /* SRC_RESMGR_PWM_DEVCTL_H_ */
