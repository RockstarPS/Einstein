/*
 * System Firmware UART 16550 Data descriptions
 *
 * Copyright (C) 2018-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file uart_16550_description.h
 *
 * \brief Include file for UART 16550 Data descriptions and initialization
 *	  routine
 */

#ifndef UART_16550_DESC_H
#define UART_16550_DESC_H

#include <config.h>
#include <types/address_types.h>
#include <types/errno.h>
#include <types/short_types.h>

struct uart_16550_config {
	soc_phys_addr_t base_addr;
	u32		baud_rate;
	u32		uart_clk;
};

/** SoC configurations of UART IP */
/* Boot time UART configuration */
extern const struct uart_16550_config soc_uart_16550_boot_config;

/* LPM FS Stub UART configuration for wkup uart */
#ifdef CONFIG_LPM_FS_STUB_TRACE
extern const struct uart_16550_config soc_uart_16550_stub_config;
#endif

/** Post PLL setup UART configuration */
extern const struct uart_16550_config soc_uart_16550_pll_config;

/**
 * \brief Initialize UART uart_16550_init
 *
 * Initialize the selected UART instance based on base address.
 *
 * \return 0 if all went fine, else return corresponding error.
 */
#ifdef CONFIG_UART_16550
extern s32 uart_16550_init(void);
#else
static inline s32 uart_16550_init(void);
static inline s32 uart_16550_init(void)
{
	return SUCCESS;
}
#endif

#endif /* UART_16550_DESC_H */
