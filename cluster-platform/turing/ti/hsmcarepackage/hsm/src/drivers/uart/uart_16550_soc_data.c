/*
 * UART 16550 Data for AM62x device
 *
 * Copyright (C) 2021-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */


/**
 * \file am62x/uart_16550_soc_data.c
 *
 * \brief SoC data for 16550 compatible USART on AM62x device
 */

#include "uart_16550_description.h"

#ifdef CONFIG_PRESILICON
/*
 * HACK: Both values below are hardcoded to create divider of 0x2 for
 * presilicon.
 */

/* MAIN USART1 */
const struct uart_16550_config soc_uart_16550_boot_config = {
	.base_addr	= 0x02810000,
	.baud_rate	= 1500000,
	.uart_clk	= 48000000,
};

const struct uart_16550_config soc_uart_16550_pll_config = {
	.base_addr	= 0x02810000,
	.baud_rate	= 1500000,
	.uart_clk	= 48000000,
};

/* WKUP UART for LPM FS Stub */
#ifdef CONFIG_LPM_FS_STUB_TRACE
const struct uart_16550_config soc_uart_16550_stub_config = {
	.base_addr	= 0x2b300000,
	.baud_rate	= 1500000,
	.uart_clk	= 48000000,
};
#endif
#else

/* Please check Frequencies of USART once values once ROM configuration is available */
const struct uart_16550_config soc_uart_16550_boot_config = {
	.base_addr	= 0x02810000,
	.baud_rate	= 115200,
	.uart_clk	= 48000000,
};

const struct uart_16550_config soc_uart_16550_pll_config = {
	.base_addr	= 0x02810000,
	.baud_rate	= 115200,
	.uart_clk	= 48000000,
};

/* WKUP UART for LPM FS Stub */
#ifdef CONFIG_LPM_FS_STUB_TRACE
const struct uart_16550_config soc_uart_16550_stub_config = {
	.base_addr	= 0x2b300000,
	.baud_rate	= 115200,
	.uart_clk	= 48000000,
};
#endif

#endif
