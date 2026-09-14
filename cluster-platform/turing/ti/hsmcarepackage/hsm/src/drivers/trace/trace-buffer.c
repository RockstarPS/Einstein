/*
 * System Firmware Trace Layer
 *
 * Low level logging output function for memory buffer tracing
 *
 * Copyright (C) 2018-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <lib/itoa.h>
#include <lib/trace.h>
#include <trace_internal.h>

/* Maximum number of bytes to cleanup at initialization */
#define TRACE_LOG_MAX_NUM_CLEAN_BYTES   (100U)

extern u8 _logbuf_first;
extern u8 _logbuf_last;

#pragma DATA_SECTION(logbuf_pos, ".data_user");
static u8 *logbuf_pos;

s32 trace_print_buffer_string(const u8 *str)
{
	s32 i = 0;
	u32 ret = SUCCESS;

	for (i = 0u; i < TRACE_PRINT_MAX_LENGTH; i++) {
		if (str[i] != (u8) '\0') {
			ret = trace_print_buffer(str[i]);
		}

		if ((ret != SUCCESS) || (str[i] == (u8) '\0')) {
			break;
		}
	}

	return ret;
}

static void trace_internal_print_buffer_init(void)
{
	u8 *pos;
	u32 index;
	logbuf_pos = &_logbuf_first;
	pos = logbuf_pos;

	for (index = 0U; index < TRACE_LOG_MAX_NUM_CLEAN_BYTES; index++) {
		*pos = 0U;
		pos++;
	}
}

/**
 * \brief Raw buffer output function for trace over memory buffer
 *
 * \param ch Character to output into memory buffer.
 */
s32 trace_print_buffer(u8 ch)
{
	if (logbuf_pos == NULL) {
		trace_internal_print_buffer_init();
	}

	*logbuf_pos = ch;
	logbuf_pos++;
	if (logbuf_pos == &_logbuf_last) {
		logbuf_pos = &_logbuf_first;
	}

	return SUCCESS;
}

/**
 * \brief Raw buffer output function for trace over memory buffer
 *
 * \param channel Channel to which one should output into memory buffer.
 * \param val Value to output into memory buffer.
 */
s32 trace_debug_buffer(u8 channel, u32 val)
{
	u8 str[10];

	/* This is unused for buffer as we only have one channel */
	(void) channel;

	(void)lib_itoa(val, str, 16);

	(void)trace_print_buffer_string("0x");
	(void)trace_print_buffer_string(str);
	(void)trace_print_buffer((u8) '\n');

	return SUCCESS;
}
