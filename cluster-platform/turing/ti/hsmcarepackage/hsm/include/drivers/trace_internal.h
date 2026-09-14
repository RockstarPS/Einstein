/*
 * System Firmware Trace Internal Functions
 *
 * Copyright (C) 2018-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file trace_internal.h
 *
 * \brief Include file for Trace init routine and trace destination calls
 *
 * At top-level include path so that tests can access.
 */

#ifndef TRACE_INTERNAL_H
#define TRACE_INTERNAL_H

#include <config.h>
#include <types/errno.h>
#include <types/short_types.h>

/**
 * \brief Initialize Trace trace_init
 *
 * Initialize the selected Trace instance based on base address.
 *
 * \return 0 if all went fine, else return corresponding error.
 */
#ifdef CONFIG_TRACE

#ifdef CONFIG_TRACE_BUFFER
s32 trace_print_buffer(u8 ch);
s32 trace_debug_buffer(u8 channel, u32 val);
s32 trace_print_buffer_string(const u8 *str);
#else
static inline s32 trace_print_buffer(u8 ch)
{
	(void) ch;
	return SUCCESS;
}
static inline s32 trace_debug_buffer(u8 channel, u32 val)
{
	(void) channel;
	(void) val;
	return SUCCESS;
}
static inline s32 trace_print_buffer_string(const u8 *str)
{
	(void) str;
	return SUCCESS;
}
#endif

#ifdef CONFIG_TRACE_UART
s32 trace_print_uart(u8 ch);
s32 trace_debug_uart(u8 channel, u32 val);
s32 trace_print_uart_string(const u8 *str);
#else
static inline s32 trace_print_uart(u8 ch)
{
	(void) ch;
	return SUCCESS;
}
static inline s32 trace_debug_uart(u8 channel, u32 val)
{
	(void) channel;
	(void) val;
	return SUCCESS;
}
static inline s32 trace_print_uart_string(const u8 *str)
{
	(void) str;
	return SUCCESS;
}
#endif


extern s32 trace_init(void);

#else
static inline s32 trace_init(void);
static inline s32 trace_init(void)
{
	return SUCCESS;
}
#endif

#endif /* TRACE_INTERNAL_H */
