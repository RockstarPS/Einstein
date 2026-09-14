/*
 * System Firmware UART 16550 driver support
 *
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file uart_16550.c
 *
 * \brief UART transfer support
 */

#include <lib/io.h>
#include <osal_secure.h>
#include <uart_16550_transfer.h>

#include "uart_16550_description.h"
#include "uart_16550_regs.h"

#pragma DATA_SECTION(uart_mapped_base_addr, ".data_user_ro");
static mapped_addr_t uart_mapped_base_addr;

/**
 * \brief Map a physical address over to mapped_addr
 *
 * \param phy_addr Physical address
 *
 * \return Mapped address
 */
static mapped_addr_t uart_16550_map_region(soc_phys_addr_t phy_addr);
static mapped_addr_t uart_16550_map_region(soc_phys_addr_t phy_addr)
{
	/**
	 * TBD - we need RAT if the mapping is not available.
	 *
	 * NOTE: we will misuse pm/soc/k3m/dmsc.c configuration for now:
	 *
	 * ~~~
	 * Physical address | mapped address | Size
	 * ----------------------------------------
	 * 0x00000000ULL    | 0x60000000UL   | 512MB
	 * 0x20000000ULL    | 0x80000000UL   | 512MB
	 * 0x40000000ULL    | 0xa0000000UL   | 512MB
	 * ~~~
	 *
	 * *NOTE*: This wont work for firewall setup and separated ops.
	 */

	return soc_phys_low_u32(phy_addr) + 0x60000000U;
}

/**
 * \brief Unmap a physical address which was previously mapped
 *
 * \param phy_addr - physical address to unmap
 */
static void uart_16550_unmap_region(soc_phys_addr_t phy_addr);
static void uart_16550_unmap_region(soc_phys_addr_t phy_addr __attribute__((unused)))
{
	/**
	 * TBD - we need RAT if the mapping is not available - Empty function
	 * for now.
	 */
	return;
}

/**
 * \brief Write to a 32-bit UART register
 *
 * \param val Value to write
 * \param offset Offset of the register from uart base address to write to
 */
static void uart_16550_writel(u32 val, u32 offset);
static void uart_16550_writel(u32 val, u32 offset)
{
	writel(val, uart_mapped_base_addr + offset);
}

/**
 * \brief Write to a 32-bit UART register and then readback and verify
 *
 * \param val Value to write
 * \param offset Offset of the register from uart base address to write to
 *
 * \returns -EFAILVERIFY if readback value doesn't match, otherwise SUCCESS.
 */
#if defined(CONFIG_TIFS_FRAMEWORK_BUILD) || defined(CONFIG_SYSFW_FRAMEWORK_BUILD)
static s32 uart_16550_writel_verified(u32 val, u32 offset);
static s32 uart_16550_writel_verified(u32 val, u32 offset)
{
	return writel_verified(val, uart_mapped_base_addr + offset);
}
#endif
/**
 * \brief Read value from 32-bit UART register
 *
 * \param offset Offset of the register from uart base address to read
 *
 * \returns Value read from register.
 */
static u32 uart_16550_readl(u32 offset);
static u32 uart_16550_readl(u32 offset)
{
	return readl(uart_mapped_base_addr + offset);
}

static s32 uart_16550_putchar_blocking(u8 c)
{
	s32 ret = SUCCESS, i = 0;
	u32 val;

	if (uart_mapped_base_addr == 0) {
		ret = -ENODEV;
	} else {
		/*
		 * Poll the Line Status Register to ensure FIFO space is
		 * available before writing to avoid dropping chars.
		 */
		do {
			val = uart_16550_readl(UART_16550_LSR);
		} while ((i++ < 10000) &&
			 ((val & ((u32) UART_16550_LSR_TX_FIFO_E)) == 0U));

		uart_16550_writel(c, UART_16550_THR);
	}

	return ret;
}

#ifdef CONSOLE_UART_ADD_CR_TO_LINE_ENDING
s32 uart_16550_putchar(u8 c)
{
	s32 ret = SUCCESS;

	/*
	 * Add a carriage return before newline to support
	 * unflexible terminals.
	 */
	if (c == '\n') {
		ret = uart_16550_putchar_blocking('\r');
	}

	if (ret == SUCCESS) {
		ret = uart_16550_putchar_blocking(c);
	}

	return ret;
}
#else
s32 uart_16550_putchar(u8 c)
{
	return uart_16550_putchar_blocking(c);
}
#endif

static s32 uart_16550_init_internal(const struct uart_16550_config *conf)
{
	s32 ret = SUCCESS;
	
#ifdef CONFIG_LPM_FS_STUB
	val = 0;
	(void) div;
	(void) val;
#endif

	uart_mapped_base_addr = uart_16550_map_region(
		conf->base_addr);
	if (uart_mapped_base_addr == 0) {
		ret = -EINVAL;
	}

#if defined(CONFIG_TIFS_FRAMEWORK_BUILD) || defined(CONFIG_SYSFW_FRAMEWORK_BUILD)
	/* Enable divisor configuration */
	if (ret == SUCCESS) {
		val = uart_16550_readl(UART_16550_LCR);
		val |= UART_16550_LCR_DLAB;
		ret = uart_16550_writel_verified(val, UART_16550_LCR);
	}

	/* Write lower byte of divisor */
	if (ret == SUCCESS) {
		val = div & 0xFF;
		ret = uart_16550_writel_verified(val, UART_16550_DLL);
	}

	/* Write upper byte of divisor */
	if (ret == SUCCESS) {
		val = (div >> 8) & 0xFF;
		ret = uart_16550_writel_verified(val, UART_16550_DLH);
	}

	/* Disable divisor configuration */
	if (ret == SUCCESS) {
		val = uart_16550_readl(UART_16550_LCR);
		val &= (~UART_16550_LCR_DLAB);
		ret = uart_16550_writel_verified(val, UART_16550_LCR);
	}

	/* Use word length of 8n1 */
	if (ret == SUCCESS) {
		ret = uart_16550_writel_verified(UART_16550_LCR_WORDSZ_8,
						 UART_16550_LCR);
	}

	/* Disable interrupts */
	if (ret == SUCCESS) {
		ret = uart_16550_writel_verified(0, UART_16550_IER);
	}

	/* Enable the UART */
	if (ret == SUCCESS) {
		ret = uart_16550_writel_verified(0, UART_16550_MDR1);
	}

	/* Enable UART FIFO, cannot be readback */
	if (ret == SUCCESS) {
		uart_16550_writel(UART_16550_FCR_FIFOEN, UART_16550_FCR);
	}

	/* Enable DTR and RTS */
	if (ret == SUCCESS) {
		ret =
			uart_16550_writel_verified(
				(UART_16550_MCR_RTS | UART_16550_MCR_DTR),
				UART_16550_MCR);
	}
#endif

	if (ret != SUCCESS) {
		uart_mapped_base_addr = 0;
		uart_16550_unmap_region(conf->base_addr);
	}

	return ret;
}

s32 uart_16550_init(void)
{
	return uart_16550_init_internal(&soc_uart_16550_boot_config);
}

#pragma CODE_SECTION(uart_16550_reinit_post_pll, ".kernel_wrapper_funcs");
s32 uart_16550_reinit_post_pll(void)
{
	s32 ret;

	osal_enter_priv_mode();
	ret = uart_16550_init_internal(&soc_uart_16550_pll_config);
	osal_restore_priv_mode();

	return ret;
}
