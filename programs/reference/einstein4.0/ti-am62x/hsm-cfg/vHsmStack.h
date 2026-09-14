/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2025] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file vHsmStack.c
 *
 * \brief
 * TI AM62P HSM stack protection 
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Chennai, India
 ******************************************************************************/
#ifndef VHSMSTACK_H
#define VHSMSTACK_H
#include "config.h"

#ifdef HSMSTACKPROTECTION

extern void StackCorruption_Handler(void);
extern uint32 __process_stackend_marker;

#define STACK_CANARY_VALUE (0xDEADBEEFu)

#define STACK_CANARY_START() \
    volatile uint32 vHsmStackCanary = STACK_CANARY_VALUE; \
    __process_stackend_marker = STACK_CANARY_VALUE;

#define STACK_CANARY_CHECK() \
        if((vHsmStackCanary != STACK_CANARY_VALUE) || (__process_stackend_marker != STACK_CANARY_VALUE)) \
        {                                         \
            StackCorruption_Handler();            \
        }
#endif

#endif /*VHSMSTACK_H*/
