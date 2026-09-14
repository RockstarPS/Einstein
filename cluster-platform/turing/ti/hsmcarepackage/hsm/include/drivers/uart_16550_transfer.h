/*
 * System Firmware UART 16550 Usage API
 *
 * Copyright (C) 2018-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file uart_16550_transfer.h
 *
 * \brief Include file for UART 16550 usage routines
 */

#ifndef UART_16550_TRANSFER_H
#define UART_16550_TRANSFER_H

#include <config.h>
#include <types/errno.h>
#include <types/short_types.h>

/**
 * \brief Reinitialize the UART with the proper divider based on
 *	  PLL configuration.
 *
 * This function reinitializes the UART once the PLLs have been configured
 * as the clock coming into the IP may change so divider reconiguration must
 * happen.
 *
 * \return Error code if failure, SUCCESS otherwise.
 */
#ifdef CONFIG_UART_16550
s32 uart_16550_reinit_post_pll(void);
#else
static inline s32 uart_16550_reinit_post_pll(void)
{
	return SUCCESS;
}
#endif

/**
 * \brief Send a character on uart.
 *
 * Transmit a character using the configured uart.
 *
 * \param c - Character to send.
 *
 * \return 0 if setup to transmit, else returns error as appropriate.
 */
s32 uart_16550_putchar(u8 c);

#endif /* UART_16550_TRANSFER_H */
