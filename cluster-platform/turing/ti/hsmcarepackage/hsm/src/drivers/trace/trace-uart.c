/*
 * System Firmware Trace Layer
 *
 * Low level logging output function for UART based tracing
 *
 * Copyright (C) 2018-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <lib/itoa.h>
#include <lib/trace.h>
#include <trace_internal.h>
#include <uart_16550_transfer.h>

s32 trace_print_uart_string(const u8 *str)
{
	s32 i = 0, ret = SUCCESS;

	for (i = 0; i < TRACE_PRINT_MAX_LENGTH; i++) {
		if (str[i] != '\0') {
			ret = uart_16550_putchar(str[i]);
		}

		if ((ret != SUCCESS) || (str[i] == '\0')) {
			break;
		}
	}

	return ret;
}

/**
 * \brief Raw buffer output function for trace over UART
 *
 * \param ch Character to output over UART.
 */
s32 trace_print_uart(u8 ch)
{
	return uart_16550_putchar(ch);
}

s32 trace_debug_uart(u8 channel, u32 val)
{
	u8 str[10];
	s32 ret;

	/* This is unused for uart as we only have one channel */
	(void) channel;

	lib_itoa(val, str, 16);

	ret = trace_print_uart_string("0x");
	if (ret == SUCCESS) {
		ret = trace_print_uart_string(str);
	}
	if (ret == SUCCESS) {
		trace_print_uart((u8) '\n');
	}

	return SUCCESS;
}
