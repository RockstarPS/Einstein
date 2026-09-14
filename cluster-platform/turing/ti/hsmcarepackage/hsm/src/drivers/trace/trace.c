/*
 * System Firmware Trace Layer
 *
 * Low level logging output main
 *
 * Copyright (C) 2022-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <boardcfg/boardcfg_data.h>
#include <lib/itoa.h>
#include <lib/trace.h>
#include <types/errno.h>
#include <types/short_types.h>
#include <trace_internal.h>
#include <lib/trace_protocol.h>

/**
 * \brief Local trace configuration during runtime
 *
 * \param level Global trace output level.
 * \param error Stores any error flags from public trace API.
 */
struct trace_local_cfg {
	u8	level;
	s32	error;
	u16	src_enables;
	u16	dst_enables;
};

static struct trace_local_cfg cfg = {
	.src_enables	= (BOARDCFG_TRACE_SRC_PM | BOARDCFG_TRACE_SRC_RM |
			   BOARDCFG_TRACE_SRC_SEC | BOARDCFG_TRACE_SRC_BASE),
	.dst_enables	= (BOARDCFG_TRACE_DST_UART0 | BOARDCFG_TRACE_DST_ITM |
			   BOARDCFG_TRACE_DST_MEM),
};

void trace_set_print_level(u8 trace_level)
{
	cfg.level = trace_level;
}

static void trace_print_internal(u8 level, const u8 *fmt)
{
	s32 ret = 0;

	if ((cfg.dst_enables != 0U) && (level <= cfg.level)) {
		if ((cfg.dst_enables & BOARDCFG_TRACE_DST_MEM) != 0U) {
			ret = trace_print_buffer_string(fmt);
		}
#if 0
		if ((ret == SUCCESS) && ((cfg.dst_enables & BOARDCFG_TRACE_DST_UART0) != 0U)) {
			ret = trace_print_uart_string(fmt);
		}
#endif
	}

	if (ret != SUCCESS) {
		cfg.error = ret;
	}
}

void trace_print_core(u8 level, const u8 *fmt)
{
	trace_print_internal(level, fmt);
}

void trace_print(u8 level, const u8 *fmt)
{
	trace_print_internal(level, fmt);
}

static void trace_print_arg_internal_hsm(u8 level, const u8 *fmt, u32 arg)
{
    u8 str[TRACE_NUM_BUFFER_CONVERSION_SIZE];

    if (level <= cfg.level) {
        trace_print_internal(level, fmt);

        lib_itoa(arg, str, 16);

        /* Output a space for ease of reading */
        trace_print_internal(level, " 0x");
        trace_print_internal(level, str);
    }
}

void trace_print_arg_core_hsm(u8 level, const u8 *fmt, u32 arg)
{
    trace_print_arg_internal_hsm(level, fmt, arg);
} 

static void trace_print_arg_internal(u8 level, const u8 *fmt, u32 arg)
{
	u8 str[TRACE_NUM_BUFFER_CONVERSION_SIZE];

	if (level <= cfg.level) {
		trace_print_internal(level, fmt);

		lib_itoa(arg, str, 16);

		/* Output a space for ease of reading */
		trace_print_internal(level, " 0x");
		trace_print_internal(level, str);
		trace_print_internal(level, "\n");
	}
}

void trace_print_arg_core(u8 level, const u8 *fmt, u32 arg)
{
	trace_print_arg_internal(level, fmt, arg);
}

void trace_print_arg(u8 level, const u8 *fmt, u32 arg)
{
	trace_print_arg_internal(level, fmt, arg);
}

static s32 trace_print_output_char_internal(u8 ch)
{
	s32 ret = SUCCESS;

	if ((cfg.dst_enables & BOARDCFG_TRACE_DST_MEM) != 0U) {
		ret = trace_print_buffer(ch);
	}
#if 0
	if ((ret == SUCCESS) && ((cfg.dst_enables & BOARDCFG_TRACE_DST_UART0) != 0U)) {
		ret = trace_print_uart(ch);
	}
#endif
	return ret;
}

s32 trace_print_output_char_core(u8 ch)
{
	return trace_print_output_char_internal(ch);
}

s32 trace_print_output_char(u8 ch)
{
	return trace_print_output_char_internal(ch);
}

static const u16 trace_debug_chan_to_boardcfg[TRACE_DEBUG_CHANNEL_COUNT] = {
	[TRACE_DEBUG_CHANNEL_BP]        = BOARDCFG_TRACE_SRC_BASE,
	[TRACE_DEBUG_CHANNEL_PM]        = BOARDCFG_TRACE_SRC_PM,
	[TRACE_DEBUG_CHANNEL_RM]        = BOARDCFG_TRACE_SRC_RM,
	[TRACE_DEBUG_CHANNEL_SEC]       = BOARDCFG_TRACE_SRC_SEC,
};


static void trace_debug_internal(u8 channel, u32 val)
{
	s32 ret = SUCCESS;
	u32 value = 0;

	if (channel >= TRACE_DEBUG_CHANNEL_COUNT) {
		ret = -EINVAL;
	}

	if ((cfg.dst_enables != 0U) &&
	    ((trace_debug_chan_to_boardcfg[channel] & cfg.src_enables) != 0U) &&
	    (ret == SUCCESS)) {
		value = val | ((channel << TRACE_DEBUG_DOMAIN_SHIFT) &
			       TRACE_DEBUG_DOMAIN_MASK);

		if ((cfg.dst_enables & BOARDCFG_TRACE_DST_MEM) != 0U) {
			ret = trace_debug_buffer(channel, value);
		}
#if 0
		if ((ret == SUCCESS) &&
		    ((cfg.dst_enables & BOARDCFG_TRACE_DST_UART0) != 0U)) {
			ret = trace_debug_uart(channel, value);
		}
#endif
	}

	if (ret != SUCCESS) {
		cfg.error = ret;
	}
}

void trace_debug_core(u8 channel, u32 val)
{
	return trace_debug_internal(channel, val);
}

void trace_debug(u8 channel, u32 val)
{
	return trace_debug_internal(channel, val);
}

s32 trace_get_error(void)
{
	return cfg.error;
}

s32 trace_init(void)
{
	s32 ret = SUCCESS;

	trace_set_print_level(TRACE_LEVEL_INFO);

	return ret;
}

void trace_reconfigure(u16 src_enables, u16 dst_enables)
{
	cfg.src_enables = src_enables;
	cfg.dst_enables = dst_enables;
}
