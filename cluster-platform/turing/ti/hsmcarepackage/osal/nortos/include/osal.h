/*
 * System Firmware OSAL
 *
 * Top-level OSAL full header
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef OSAL_H
#define OSAL_H

#include <clockp.h>
#include <hwip.h>
#include <semaphorep.h>
#include <taskp.h>

/**
 * \brief Call that that is invoked during OSAL idle that contains a list
 *	  of calls to make.
 *
 * The OSAL enters an idle task when no other tasks are executing. During
 * execution of the idle task this function will be called.
 *
 * NOTE: This function will be called repeatedly during idle.
 */
void osal_idle_calls(void);

#endif /* OSAL_H */
