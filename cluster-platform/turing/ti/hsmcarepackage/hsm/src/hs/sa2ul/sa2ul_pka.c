/*
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_pka.c
 *
 * \brief SA2UL PKA driver
 */

#include <string.h>
#include <common_funcs.h>
#include "eip29t2_firmware.h"
#include <sa2ul_pka.h>
#include <socmem.h>
#include <types/ftbool.h>
#include <crypto_types.h>
#include <keystore.h>
#include <sec_dma.h>
#include <hosts.h>
#include <sec_mem_mgr.h>
#include <config.h>
#include<lib/trace.h>
#include "sa2ul_regs.h"

/*
 * Timeout values in microsecs
 */
/**
 * Timeout for register updates to take effect
 */
#define SA2UL_PKA_REG_TIMEOUT                  10U

/**
 * Timeout for compare of 2 bignums
 */
#define SA2UL_PKA_COMPARE_TIMEOUT              100U

/**
 * Timeout for modexp CRT operation - 50ms
 */
#define SA2UL_PKA_MODEXP_CRT_TIMEOUT           50000U

/**
 * Timeout for modexp operation - 10ms
 */
#define SA2UL_PKA_MODEXP_TIMEOUT               10000U

/**
 * Timeout for ECDSA verify operation - 10ms
 */
#define SA2UL_PKA_ECDSA_VERIFY_TIMEOUT         10000U

/**
 * Timeout for ECDSA sign operation - 10ms
 */
#define SA2UL_PKA_ECDSA_SIGN_TIMEOUT           10000U


/* Function prototypes */
static fterr sa2ul_pka_load_firmware(u32 inst);
static fterr sa2ul_pka_acquire_instance(u32 *inst);
static void sa2ul_pka_release_instance(u32 inst);
static ftbool sa2ul_pka_is_bigint_zero(const u32 bn[PKA_BIGINT_MAX]);
static u32 sa2ul_pka_bigint_bitlen(const u32 bn[PKA_EC_BIGINT_MAX]);
static void sa2ul_pka_cpyz(u32 dest[PKA_EC_BIGINT_MAX], u32 dest_len, const u32 bn[PKA_EC_BIGINT_MAX]);
static void sa2ul_pka_disable(u32 inst);
static fterr sa2ul_pka_enable(u32 inst);
static inline u32 dwalign(u32 size);

/** Get a double-word aligned number for bigints used by PKA */
static inline u32 dwalign(u32 size)
{
	return size + (size & 1U);
}

/** Firmware load successfUL status */
#define FIRMWARE_LOADED     0xa5U

/** Command to PKA firmware - MODEXP_CRT */
#define PKA_MODEXP_CRT_CMD   (((u32) 0x0U) << PKA_FUNCTION_CMD_HI_SHIFT) | \
	(((u32) 0x1U) << PKA_FUNCTION_CMD_LO_SHIFT)

/** Command to PKA firmware - MODEXP */
#define PKA_MODEXP_CMD   (((u32) 0x0U) << PKA_FUNCTION_CMD_HI_SHIFT) |	\
	(((u32) 0x6U) << PKA_FUNCTION_CMD_LO_SHIFT)

/** Command to PKA firmware - ECDSA SIGN */
#define PKA_ECDSA_SIGN_CMD   (((u32) 0x2U) << PKA_FUNCTION_CMD_HI_SHIFT) | \
	(((u32) 0x2U) << PKA_FUNCTION_CMD_LO_SHIFT)

/** Command to PKA firmware - ECDSA VERIFY */
#define PKA_ECDSA_VERIFY_CMD   (((u32) 0x2U) << PKA_FUNCTION_CMD_HI_SHIFT) | \
	(((u32) 0x3U) << PKA_FUNCTION_CMD_LO_SHIFT)

/** Result code when a PKA firmware command was successfUL */
#define PKA_COMMAND_RESULT_SUCCESS    0x1U

/**
 * \brief PKA module global state
 *
 * \param firmware_status Status whether firmware load was done or not
 * \param SA2UL_REGS Pointer to SA2UL top-level registers
 * \param PKA_REGS Pointer to SA2UL PKA registers
 */
static struct {
	u8			firmware_status;
	soc_phys_addr_t		base_address;
	struct sa2ul_pka_regs	*PKA_REGS;
} sa2ul_pka_state[SA2UL_MAX_INSTANCES];

/**
 * \brief Load fimrware on a SA2UL PKA instance
 *
 * \param inst   Instance number of the PKA module
 *
 * \return EFTOK if successful
 */
static fterr sa2ul_pka_load_firmware(u32 inst)
{
	fterr ret = -EFAIL;
	s32 i;
	struct sa2ul_pka_regs *r;

	r = sa2ul_pka_state[inst].PKA_REGS;

#ifndef CONFIG_SECURITY_SA2UL_PKA_FW_IMAGE_BUILD
	eip29t2_fw_image = (u32 *) get_pka_firmware_load_addr();
#endif


	/* Put EIP-29t2 (PKA) in reset, set bit 31 of PKA_SEQ_CTRL */
	writel(&r->PKA_SEQ_CTRL, ((u32) 1U) << PKA_SEQ_CTRL_RESET_SHIFT);

	/*
	 * Copy firmware to PKA program memory, which is aliased at the PKA_RAM
	 * location when then PKA is in reset
	 */
	for (i = 0; i < EIP29T2_FW_IMAGE_LEN_WORDS; i++) {
		r->PKA_RAM[i] = eip29t2_fw_image[i];
	}

	/* Take EIP-29t2 (PKA) out of reset */
	writel(&r->PKA_SEQ_CTRL, ((u32) 0U) << PKA_SEQ_CTRL_RESET_SHIFT);

	/* Check status in PKA_SEQ_CTRL for a few iterations*/
	if (reg_poll_delay(&r->PKA_SEQ_CTRL,
			   PKA_SEQ_CTRL_RESULT_MASK,
			   ((u32) 1U) << PKA_SEQ_CTRL_RESULT_SHIFT,
			   10)) {
		/* Put EIP-29t2 (PKA) back into reset */
		writel(&r->PKA_SEQ_CTRL, ((u32) 1U) << PKA_SEQ_CTRL_RESET_SHIFT);

		/* Verify the firmware content in the PKA program RAM */
		for (i = 0; i < EIP29T2_FW_IMAGE_LEN_WORDS; i++) {
			if (r->PKA_RAM[i] != eip29t2_fw_image[i]) {
				break;
			}
		}

		if (i == EIP29T2_FW_IMAGE_LEN_WORDS) {
			/* Take EIP-29t2 (PKA) out of reset */
			writel(&r->PKA_SEQ_CTRL,
			       ((u32) 0U) << PKA_SEQ_CTRL_RESET_SHIFT);

			/* Wait for a few cycles */

			/* Check status in PKA_SEQ_CTRL, wait for a few cycles */
			if (reg_poll_delay(&r->PKA_SEQ_CTRL,
					   PKA_SEQ_CTRL_RESULT_MASK,
					   ((u32) 1U) << PKA_SEQ_CTRL_RESULT_SHIFT,
					   10)) {
				ret = EFTOK;
			}
		}
	}

	return ret;
}

/**
 * \brief Disable clocks
 *
 * \param inst instance number
 */
static void sa2ul_pka_disable(u32 inst)
{
	struct sa2ul_pka_regs *r;

	r = sa2ul_pka_state[inst].PKA_REGS;

	/* Disable internal clocks */
	writel(&r->PKA_CLK_CTRL,
	       (((u32) 1U) << PKA_CLK_CTRL_REG_CLK_OFF_SHIFT) |
	       (((u32) 1U) << PKA_CLK_CTRL_SEQ_CLK_OFF_SHIFT) |
	       (((u32) 1U) << PKA_CLK_CTRL_PKCP_CLK_OFF_SHIFT) |
	       (((u32) 1U) << PKA_CLK_CTRL_LNME_CLK_OFF_SHIFT) |
	       (((u32) 1U) << PKA_CLK_CTRL_LNME_REG_CLK_OFF_SHIFT) |
	       (((u32) 1U) << PKA_CLK_CTRL_GF2M_CLK_OFF_SHIFT) |
	       (((u32) 1U) << PKA_CLK_CTRL_DATA_RAM_CLK_OFF_SHIFT));

	sa2ul_pka_state[inst].firmware_status = 0;
}

/**
 * \brief Enable clocks and load firmware
 *
 * \param inst instance number
 *
 * \return EFTOK if successful
 */
static fterr sa2ul_pka_enable(u32 inst)
{
	fterr ret;
	sbool cond;
	u32 reg;
	struct sa2ul_pka_regs *r;

	/* Get local addresses */
	ret = socmem_to_local(sa2ul_pka_state[inst].base_address +
			      SA2UL_PKA_REGS_OFFSET,
			      (local_phys_addr_t *) &r);
	if ((sa2ul_pka_state[inst].firmware_status != FIRMWARE_LOADED) &&
	    ft_is_ok(ret)) {
		sa2ul_pka_state[inst].PKA_REGS = r;

		/* SA2UL PKA engine is already enabled from init */

		/* Enable internal clocks */
		writel(&r->PKA_CLK_CTRL,
		       (((u32) 1U) << PKA_CLK_CTRL_REG_CLK_ON_SHIFT) |
		       (((u32) 1U) << PKA_CLK_CTRL_SEQ_CLK_ON_SHIFT) |
		       (((u32) 1U) << PKA_CLK_CTRL_PKCP_CLK_ON_SHIFT) |
		       (((u32) 1U) << PKA_CLK_CTRL_LNME_CLK_ON_SHIFT) |
		       (((u32) 1U) << PKA_CLK_CTRL_LNME_REG_CLK_ON_SHIFT) |
		       (((u32) 1U) << PKA_CLK_CTRL_GF2M_CLK_ON_SHIFT) |
		       (((u32) 1U) << PKA_CLK_CTRL_DATA_RAM_CLK_ON_SHIFT));

		reg = (((u32) 1U) << PKA_CLK_CTRL_REG_CLK_EN_SHIFT) |
		      (((u32) 1U) << PKA_CLK_CTRL_SEQ_CLK_EN_SHIFT) |
		      (((u32) 1U) << PKA_CLK_CTRL_PKCP_CLK_EN_SHIFT) |
		      (((u32) 1U) << PKA_CLK_CTRL_LNME_CLK_EN_SHIFT) |
		      (((u32) 1U) << PKA_CLK_CTRL_LNME_REG_CLK_EN_SHIFT) |
		      (((u32) 1U) << PKA_CLK_CTRL_GF2M_CLK_EN_SHIFT) |
		      (((u32) 1U) << PKA_CLK_CTRL_DATA_RAM_CLK_EN_SHIFT);

		ret = -ETIMEDOUT;

		/* Wait for PKA internal clocks to be active, 1us */
		cond = reg_poll_timeout_us(&r->PKA_CLK_CTRL,
					   reg, reg,
					   SA2UL_PKA_REG_TIMEOUT);
		if (cond) {
			ret = sa2ul_pka_load_firmware(inst);
			if (ret == EFTOK) {
				sa2ul_pka_state[inst].firmware_status =
					FIRMWARE_LOADED;
			}
		}
		if (ret != EFTOK) {
			/* Something went wrong, disable clocks back
			 * to original state */
			sa2ul_pka_disable(inst);
		}
	} else if ((sa2ul_pka_state[inst].firmware_status == FIRMWARE_LOADED) &&
		   ft_is_ok(ret)) {
		/*
		 * If firmware is already marked as loaded, check the PKA internal
		 * clocks are active as a sanity check.
		 */
		reg = (((u32) 1U) << PKA_CLK_CTRL_REG_CLK_EN_SHIFT) |
		      (((u32) 1U) << PKA_CLK_CTRL_SEQ_CLK_EN_SHIFT) |
		      (((u32) 1U) << PKA_CLK_CTRL_PKCP_CLK_EN_SHIFT) |
		      (((u32) 1U) << PKA_CLK_CTRL_LNME_CLK_EN_SHIFT) |
		      (((u32) 1U) << PKA_CLK_CTRL_LNME_REG_CLK_EN_SHIFT) |
		      (((u32) 1U) << PKA_CLK_CTRL_GF2M_CLK_EN_SHIFT) |
		      (((u32) 1U) << PKA_CLK_CTRL_DATA_RAM_CLK_EN_SHIFT);

		ret = -ETIMEDOUT;

		/* Wait for PKA internal clocks to be active, 1us */
		cond = reg_poll_timeout_us(&r->PKA_CLK_CTRL,
					   reg, reg,
					   SA2UL_PKA_REG_TIMEOUT);
		if (cond) {
			ret = EFTOK;
		}
	} else {
		ret = -EFAIL;
	}
	return ret;
}

/**
 * \brief Acquire a SA2UL instance for own use
 *
 * \return EFTOK if successful
 */
static fterr sa2ul_pka_acquire_instance(u32 *inst)
{
	fterr ret;

	/* FIXME: always uses inst 0, TODO: Power management, etc */

	ret = sa2ul_pka_enable(SA2UL_INSTANCE_HSM_PKA);
	if (ret == EFTOK) {
		*inst = SA2UL_INSTANCE_HSM_PKA;
	}
	return ret;
}

/**
 * \brief Release a SA2UL instance for using PKA HWA
 *
 * \param inst  sa2UL instance number to release
 */
static void sa2ul_pka_release_instance(u32 inst)
{
	sa2ul_pka_disable(inst);
	/* TODO: power management */
}

/**
 * \brief Check if the bigint is zero
 *
 * \param bn Input number
 *
 * \return FT_TRUE if the number if zero
 */
static ftbool sa2ul_pka_is_bigint_zero(const u32 bn[PKA_BIGINT_MAX])
{
	u32 i;
	ftbool ret = FT_TRUE;

	/* 0 */
	if (bn[0] == 0U) {
		ret = FT_TRUE;
	} else {
		/* BigInt Zero: x 0 0 .. 0(x times) */
		for (i = 1U; i <= bn[0]; i++) {
			if (bn[i] != 0U) {
				ret = FT_FALSE;
				break;
			}
		}
	}
	return ret;
}

/**
 * \brief Return the size in bits of a bigint
 *
 * \param bn Input number
 *
 * \return Length in bits of the big number
 */
static u32 sa2ul_pka_bigint_bitlen(const u32 bn[PKA_EC_BIGINT_MAX])
{
	u32 i;

	for (i = bn[0]; i > 0U; i--) {
		if (bn[i] != 0U) {
			break;
		}
	}
	if (i == 0U) {
		return 0U;
	}
	return (i * 32U) - __clz((s32) bn[i]);
}

/**
 * \brief Copy to destination with zero padding if necessary
 *
 * Copy with zero padding, userful to copy bigint operands to PKA RAM
 *
 * \param dest Destination address to copy to
 * \param dest_len Length of the destination buffer
 * \param bn Bigint to copy from
 */
static void sa2ul_pka_cpyz(u32 dest[PKA_EC_BIGINT_MAX],
			   u32 dest_len, const u32 bn[PKA_EC_BIGINT_MAX])
{
	u32 i;

	for (i = 0U; (i < bn[0]) && (i < dest_len); i++) {
		dest[i] = bn[i + 1U];
	}
	for (; i < dest_len; i++) {
		dest[i] = 0U;
	}
}

fterr sa2ul_pka_modexp_crt(const u32			m[PKA_BIGINT_MAX],
			   const struct rsa_privkey	*k,
			   u32				result[PKA_BIGINT_MAX])
{
	u32 inst;
	u32 offset, reg, size, wssize, tmp, shift;
	struct sa2ul_pka_regs *r;
	sbool cond;
	fterr ret = -EINVAL;

	size = k->p[0];

	/* check sizes, sizes of s and n must match. */
	if ((!((size <= 1U) || (size > ((PKA_BIGINT_MAX - 1U) >> 1)) ||
	       (k->q[0] > size) || (k->dp[0] > size) || (k->dq[0] > size) ||
	       (k->coefficient[0] > size) || (m[0] > (size * 2U))))) {
		ret = sa2ul_pka_acquire_instance(&inst);
	}
	if (ret == EFTOK) {
		r = sa2ul_pka_state[inst].PKA_REGS;

		writel(&r->PKA_ALENGTH, size);
		writel(&r->PKA_BLENGTH, size);

		/* Vectors A has Dp[Alen], [pad], Dq[Alen] */
		offset = 0U;
		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size, k->dp);
		offset += dwalign(size);
		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size, k->dq);
		offset += dwalign(size);

		/* Vectors B has p[Blen], [1], [pad] q[Blen], [1] */
		writel(&r->PKA_BPTR, offset);
		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 1U, k->p);
		offset += dwalign(size + 1U);

		/* Temporarily set A offset to compare */
		writel(&r->PKA_APTR, offset);
		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 1U, k->q);
		offset += dwalign(size + 1U);

		/* Compare and check if p > q */
		writel(&r->PKA_FUNCTION,
		       (((u32) 1U) << PKA_FUNCTION_COMPARE_SHIFT) |
		       (((u32) 1U) << PKA_FUNCTION_RUN_SHIFT));

		/* Wait for completion, wait for 10us */
		cond = reg_poll_timeout_us(&r->PKA_FUNCTION,
					   PKA_FUNCTION_RUN_MASK, 0U,
					   SA2UL_PKA_COMPARE_TIMEOUT);
		if (cond) {
			reg = readl(&r->PKA_COMPARE);
			if ((reg & PKA_COMPARE_A_LT_B_MASK) != 0U) {
				/* Restore A offset to zero */
				writel(&r->PKA_APTR, 0U);

				/* Vectors C has qInv[Blen] */
				writel(&r->PKA_CPTR, offset);
				sa2ul_pka_cpyz(&r->PKA_RAM[offset],
					       size, k->coefficient);
				offset += dwalign(size);

				/* Vectors D has M [2*Blen], [1], [pad]
				 * WorkSpace */
				writel(&r->PKA_DPTR, offset);
				sa2ul_pka_cpyz(&r->PKA_RAM[offset],
					       size * 2U, m);

				/*
				 * Higher shift value will increase number of
				 * pre-computed odd powers and speed up
				 * exponentiation operation.
				 *
				 * Need workspace size of at least max of
				 * {3 x (BLen + 2 - (BLen MOD 2)) + 10,
				 * (shift + 1) x (BLen + 2 - (BLen MOD 2))} for
				 * computation.
				 *
				 * With PKA_RAM size of 4KB, shift value of 4
				 * will always fit, so latter expression will
				 * always be greater. Shift is determined based
				 * on that.
				 */

				/* Ger the free workspace size available for
				 * computation */
				wssize = SA2UL_PKA_RAM_SIZE_WORDS -
					 (offset + dwalign((size * 2U) + 1U));

				tmp = size + (2U - (size & 1U));

				/* Compute best shift for fast computation */
				shift = (wssize / tmp) - 1U;

				/* Maximum shift value is 16 but restrict to 8
				 * max due to diminishing returns on performance
				 * for addidional odd powers */
				if (shift > 8U) {
					shift = 8U;
				}

				writel(&r->PKA_SHIFT, shift);

				writel(&r->PKA_FUNCTION, PKA_MODEXP_CRT_CMD |
				       (((u32) 1U) << PKA_FUNCTION_RUN_SHIFT));

				/* Wait for completion */
				cond = reg_poll_timeout_us(
					&r->PKA_SEQ_CTRL,
					PKA_SEQ_CTRL_DONE_MASK,
					((u32) 1U) <<
					PKA_SEQ_CTRL_DONE_SHIFT,
					SA2UL_PKA_MODEXP_CRT_TIMEOUT);
				if (cond) {
					reg = readl(&r->PKA_SEQ_CTRL);
					if ((reg & PKA_SEQ_CTRL_RESULT_MASK) ==
					    (PKA_COMMAND_RESULT_SUCCESS <<
					     PKA_SEQ_CTRL_RESULT_SHIFT)) {
						/* Copy result vector from dptr
						 */
						result[0] = size * 2U;
						memcpy(&result[1],
						       &r->PKA_RAM[offset],
						       size * 8U);
						ret = EFTOK;
					} else {
						ret = -EFAIL;
					}
				} else {
					ret = -ETIMEDOUT;
				}
			}
		} else {
			ret = -ETIMEDOUT;
		}
		sa2ul_pka_release_instance(inst);
	}
	return ret;
}

fterr sa2ul_pka_modexp(const u32		m[PKA_BIGINT_MAX],
		       const struct rsa_pubkey	*k,
		       u32			result[PKA_BIGINT_MAX])
{
	u32 inst;
	u32 offset, reg, size;
	struct sa2ul_pka_regs *r;
	sbool cond;
	fterr ret = -EINVAL;

	size = k->n[0];

	/* check sizes, sizes of s and n must match. */
	if ((!((size <= 1U) || (size > (PKA_BIGINT_MAX - 1U)) ||
	       (m[0] != size) || (k->e[0] > (PKA_BIGINT_MAX - 1U))))) {
		ret = sa2ul_pka_acquire_instance(&inst);
	}
	if (ret == EFTOK) {
		r = sa2ul_pka_state[inst].PKA_REGS;

		offset = 0U;
		memcpy(&r->PKA_RAM[offset], &k->e[1], k->e[0] * 4U);

		offset += dwalign(k->e[0]);
		writel(&r->PKA_BPTR, offset);
		memcpy(&r->PKA_RAM[offset], &k->n[1], k->n[0] * 4U);
		writel(&r->PKA_BLENGTH, k->n[0]);

		/* Vectors B and C must be followed by an empty 32-bit buffer
		 * word */
		offset += dwalign(k->n[0] + 1U);

		writel(&r->PKA_CPTR, offset);
		memcpy(&r->PKA_RAM[offset], &m[1], m[0] * 4U);

		/* check if m is less than n. temporarily use Aptr and Asize */
		writel(&r->PKA_APTR, offset);
		writel(&r->PKA_ALENGTH, m[0]);

		writel(&r->PKA_FUNCTION,
		       (((u32) 1U) << PKA_FUNCTION_COMPARE_SHIFT) |
		       (((u32) 1U) << PKA_FUNCTION_RUN_SHIFT));

		/* Wait for completion, wait for 10us */
		cond = reg_poll_timeout_us(
			&r->PKA_FUNCTION,
			PKA_FUNCTION_RUN_MASK, 0U,
			SA2UL_PKA_COMPARE_TIMEOUT);
		if (cond) {
			reg = readl(&r->PKA_COMPARE);
			if ((reg & PKA_COMPARE_A_LT_B_MASK) != 0U) {
				/* Restore the value of Aptr and Aoffset to
				 *point to E */
				writel(&r->PKA_APTR, 0U);
				writel(&r->PKA_ALENGTH, k->e[0]);

				/* To save PKA-RAM space, the MODEXP operation
				 * allows the input (M) to be located at the
				 * start of the workspace.
				 * So PKA_CPTR and PKA_DPTR  are allowed to be
				 * identical
				 */
				writel(&r->PKA_DPTR, offset);
				writel(&r->PKA_SHIFT, 1U);

				writel(&r->PKA_FUNCTION, PKA_MODEXP_CMD |
				       (((u32) 1U) << PKA_FUNCTION_RUN_SHIFT));

				/* Wait for completion */
				cond = reg_poll_timeout_us(
					&r->PKA_SEQ_CTRL,
					PKA_SEQ_CTRL_DONE_MASK,
					((u32) 1U) << PKA_SEQ_CTRL_DONE_SHIFT,
					SA2UL_PKA_MODEXP_TIMEOUT);
				if (cond) {
					reg = readl(&r->PKA_SEQ_CTRL);
					if ((reg & PKA_SEQ_CTRL_RESULT_MASK) ==
					    (PKA_COMMAND_RESULT_SUCCESS <<
					     PKA_SEQ_CTRL_RESULT_SHIFT)) {
						/*
						 * Success
						 * Copy result vector from dptr
						 */
						result[0] = size;
						memcpy(&result[1],
						       &r->PKA_RAM[offset],
						       size * 4U);
						ret = EFTOK;
					} else {
						ret = -EFAIL;
					}
				} else {
					ret = -ETIMEDOUT;
				}
			}
		} else {
			ret = -ETIMEDOUT;
		}
		sa2ul_pka_release_instance(inst);
	}
	return ret;
}

fterr sa2ul_pka_ecdsa_sign(
	const struct ec_prime_curve_p	*cp,
	const u32			priv[
		PKA_EC_BIGINT_MAX],
	const u32			k[
		PKA_EC_BIGINT_MAX],
	const u32			h[
		PKA_EC_BIGINT_MAX],
	struct ecdsa_sig		*sig)
{
	u32 inst;
	u32 offset, reg, size;
	struct sa2ul_pka_regs *r;
	sbool cond;
	fterr ret = -EINVAL;
	u32 bn_one[2] = { 1U, 1U };

	size = cp->prime[0];
	/* check sizes */
	if ((!((size <= 2U) || (size > (PKA_EC_BIGINT_MAX - 1U)) ||
	       (size != cp->order[0]) || (size < cp->a[0]) ||
	       (size < cp->b[0]) || (size < cp->g.x[0]) ||
	       (size < cp->g.y[0]) || (size < priv[0]) ||
	       (size < h[0]) || (size < k[0]))) &&
	    (sa2ul_pka_bigint_bitlen(cp->order) >=
	     sa2ul_pka_bigint_bitlen(h))) {
		ret = sa2ul_pka_acquire_instance(&inst);
	}
	if (ret == EFTOK) {
		r = sa2ul_pka_state[inst].PKA_REGS;

		writel(&r->PKA_BLENGTH, size);
		writel(&r->PKA_ALENGTH, size);

		offset = 0U;
		/* Vector B has p, a, b, gz, gy and Rz (must be 1) */
		writel(&r->PKA_BPTR, offset);
		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, cp->prime);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, cp->a);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, cp->b);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, cp->order);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, cp->g.x);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, cp->g.y);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, bn_one);
		offset += dwalign(size + 2U);

		/* Vector C has h */
		writel(&r->PKA_CPTR, offset);
		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, h);
		offset += dwalign(size + 2U);

		/* Vector A has priv */
		writel(&r->PKA_APTR, offset);
		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, priv);
		offset += dwalign(size + 2U);

		/* Vector D has k */
		writel(&r->PKA_DPTR, offset);
		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, k);

		writel(&r->PKA_FUNCTION,
		       PKA_ECDSA_SIGN_CMD | (((u32) 1U) << PKA_FUNCTION_RUN_SHIFT));

		/* Wait for completion */
		cond = reg_poll_timeout_us(
			&r->PKA_SEQ_CTRL,
			PKA_SEQ_CTRL_DONE_MASK,
			((u32) 1U) << PKA_SEQ_CTRL_DONE_SHIFT,
			SA2UL_PKA_ECDSA_SIGN_TIMEOUT);
		if (cond) {
			reg = readl(&r->PKA_SEQ_CTRL);
			if ((reg & PKA_SEQ_CTRL_RESULT_MASK) ==
			    (PKA_COMMAND_RESULT_SUCCESS <<
			     PKA_SEQ_CTRL_RESULT_SHIFT)) {
				sig->r[0] = size;
				memcpy(&sig->r[1], &r->PKA_RAM[offset],
				       size * 4U);
				offset += dwalign(size + 2U);

				sig->s[0] = size;
				memcpy(&sig->s[1], &r->PKA_RAM[offset],
				       size * 4U);

				ret = EFTOK;
			} else {
				ret = -EFAIL;
			}
		} else {
			ret = -ETIMEDOUT;
		}
		sa2ul_pka_release_instance(inst);
	}

	return ret;
}

fterr sa2ul_pka_ecdsa_verify(
	const struct ec_prime_curve_p	*cp,
	const struct ec_point		*pub,
	const struct ecdsa_sig		*sig,
	const u32			h[PKA_EC_BIGINT_MAX])
{
	u32 inst;
	u32 offset, reg, size;
	struct sa2ul_pka_regs *r;
	sbool cond;
	fterr ret = -EINVAL;
	u32 bn_one[2] = { 1U, 1U };

	size = cp->prime[0];
	/* check sizes */
	if ((!((size <= 2U) || (size > (PKA_EC_BIGINT_MAX - 1U)) ||
	       (size != cp->order[0]) || (size < cp->a[0]) ||
	       (size < cp->b[0]) || (size < cp->g.x[0]) ||
	       (size < cp->g.y[0]) || (size < pub->x[0]) ||
	       (size < pub->y[0]) || (size < sig->r[0]) ||
	       (size < sig->s[0]) || (size < h[0]))) &&
	    (sa2ul_pka_bigint_bitlen(cp->order) >=
	     sa2ul_pka_bigint_bitlen(h)) &&
	    (ft_is_false(sa2ul_pka_is_bigint_zero(sig->r))) &&
	    (ft_is_false(sa2ul_pka_is_bigint_zero(sig->s)))) {
		ret = sa2ul_pka_acquire_instance(&inst);
	}
	if (ret == EFTOK) {
		r = sa2ul_pka_state[inst].PKA_REGS;

		writel(&r->PKA_BLENGTH, size);
		writel(&r->PKA_ALENGTH, size);

		offset = 0;
		/* Vector B has p, a, b, gz, gy and Rz (must be 1) */
		writel(&r->PKA_BPTR, offset);
		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, cp->prime);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, cp->a);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, cp->b);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, cp->order);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, cp->g.x);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, cp->g.y);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, bn_one);
		offset += dwalign(size + 2U);

		/* Vector C has h */
		writel(&r->PKA_CPTR, offset);
		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, h);
		offset += dwalign(size + 2U);

		/* Vector A has px, py and R'z (must be 1) */
		writel(&r->PKA_APTR, offset);
		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, pub->x);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, pub->y);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, bn_one);
		offset += dwalign(size + 2U);

		/* Vector D has r and s */
		writel(&r->PKA_DPTR, offset);
		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, sig->r);
		offset += dwalign(size + 2U);

		sa2ul_pka_cpyz(&r->PKA_RAM[offset], size + 2U, sig->s);

		writel(&r->PKA_FUNCTION,
		       PKA_ECDSA_VERIFY_CMD | (((u32) 1U) << PKA_FUNCTION_RUN_SHIFT));

		/* Wait for completion */
		cond = reg_poll_timeout_us(&r->PKA_SEQ_CTRL,
					   PKA_SEQ_CTRL_DONE_MASK,
					   ((u32) 1U) << PKA_SEQ_CTRL_DONE_SHIFT,
					   SA2UL_PKA_ECDSA_VERIFY_TIMEOUT);
		if (cond) {
			reg = readl(&r->PKA_SEQ_CTRL);
			if ((reg & PKA_SEQ_CTRL_RESULT_MASK) ==
			    (PKA_COMMAND_RESULT_SUCCESS <<
			     PKA_SEQ_CTRL_RESULT_SHIFT)) {
				/* Success */
				ret = EFTOK;
			} else {
				ret = -EFAIL;
			}
		} else {
			ret = -ETIMEDOUT;
		}
		sa2ul_pka_release_instance(inst);
	}
	return ret;
}

fterr sa2ul_pka_init(void)
{
	u32 i;

	for (i = 0U; i < sa2ul_socdata.num_instances; i++) {
		sa2ul_pka_state[i].firmware_status = 0U;
		sa2ul_pka_state[i].base_address = sa2ul_socdata.base_addr[i];
	}
	return EFTOK;
}
