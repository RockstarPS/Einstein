/*
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file common_funcs.h
 *
 * \brief  Common (inline) functions
 */

#ifndef COMMON_FUNCS_H_
#define COMMON_FUNCS_H_

#include <types/short_types.h>
#include <types/sbool.h>
#include <types/fterr.h>
#include <osal/osal_clock_user.h>

/* Function prototypes for Klocwork misra checker */
static inline u32 readl(volatile u32 ptr[1]);
static inline void writel(volatile u32 ptr[1], u32 val);
static inline fterr writel_verified(volatile u32 ptr[1], u32 val);
static inline sbool reg_poll_delay(volatile u32 *raddr, u32 mask, u32 val, u32 cnt);
static inline void delay(u32 cnt);
static inline void udelay(u32 us);

/**
 * \brief Read a 32-bit register
 *
 * \param ptr  Address of the register
 * \return     Register value
 */
static inline u32 readl(volatile u32 ptr[1])
{
	return ptr[0];
}

/**
 * \brief Write a 32-bit register
 *
 * \param ptr  Address of the register to write into
 * \param val  Value to write
 */
static inline void writel(volatile u32 ptr[1], u32 val)
{
	ptr[0] = val;
}

/**
 * \brief Write a 32-bit register and read back and verify
 *
 * \param ptr  Address of the register to write into
 * \param val  Value to write
 *
 * \return EFTOK when success, -EFAILVERIFY in case of failure
 */
static inline fterr writel_verified(volatile u32 ptr[1], u32 val)
{
	fterr ret = -EFAILVERIFY;

	ptr[0] = val;
	if (ptr[0] == val) {
		ret = EFTOK;
	}
	return ret;
}

/**
 * \brief Read and register and writeback the same value into the register.
 *
 * \param ptr  Address of the register to write into
 *
 * \return EFTOK on success. -EFAILVERIFY in case the value read back
 *         is not the same as the value written.
 */
static inline fterr reg_rd_wrback(volatile u32 ptr[1])
{
	u32 val = readl(ptr);

	return writel_verified(ptr, val);
}

/**
 * \brief Poll on a register with delay specified in loop counter
 *        Poll until (*raddr) & mask == val
 *
 * \param raddr Address of the register being polled
 * \param mask  Mask to ignore bits of the register not relevant
 * \param val   Value of the register that causes polling to stop
 * \param cnt   Loop counter value for a rough time delay
 *
 * \return SFALSE if timed out, STRUE otherwise
 */
static inline sbool reg_poll_delay(volatile u32 raddr[1], u32 mask,
				   u32 val, u32 cnt)
{
	u32 delay_counter = cnt;

	while (((readl(raddr) & mask) != val) && (delay_counter != 0UL)) {
		delay_counter = delay_counter - 1U;
	}
	return (readl(raddr) & mask) == val;
}

/**
 * \brief Rough delay using a loop counter
 *
 * \param cnt   Loop counter value to count down
 */
static inline void delay(u32 cnt)
{
	u32 delay_counter = cnt;

	while (delay_counter != 0UL) {
		delay_counter = delay_counter - 1U;
	}
}

/**
 * \brief Poll on a register with timeout specified in microsecs
 *        Poll until (*raddr) & mask == val
 *
 * \param raddr Address of the register being polled
 * \param mask  Mask to ignore bits of the register not relevant
 * \param val   Value of the register that causes polling to stop
 * \param us    Timeout value in microseconds
 *
 * \return SFALSE if timed out, STRUE otherwise
 */
sbool reg_poll_timeout_us(volatile u32 raddr[1], u32 mask, u32 val, u32 us);

/**
 * \brief Delay in microsecs
 *
 * \param us    Delay value in microseconds
 */
static inline void udelay(u32 us)
{
	osal_delay((u64) us);
}
#endif /* COMMON_FUNCS_H_ */
