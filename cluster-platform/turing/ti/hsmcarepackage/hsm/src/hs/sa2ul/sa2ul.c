/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul.c
 *
 * \brief Driver to manage SA2_UL
 */

#include <types/short_types.h>
#include <types/fterr.h>
#include<config.h>
#include <common_funcs.h>
#include <hs/sa2ul.h>
#include <socmem.h>
#include "sa2ul_regs.h"
/**
 * Timeout for register updates to take effect
 */
#define SA2UL_REG_TIMEOUT                  10U

static void sa2ul_get_engine_masks(u32 module, u32 *engine_status_mask,
				   u32 *engine_enable_mask,
				   u32 *efuse_mask)
{
	u32 e_st, e_en, efuse;

	e_st = 0U;
	e_en = 0U;
	efuse = 0U;

	if (module == SA2UL_MODULE_PKA) {
		efuse = SA2UL_EFUSE_PKA_EN_MASK;
		e_en = (1U << SA2UL_ENGINE_ENABLE_PKA_EN_SHIFT);
		e_st = (1U << SA2UL_ENGINE_STATUS_PKA_EN_SHIFT);
	} else if (module == SA2UL_MODULE_DKEK) {
		/*
		 * Does not need any engines
		 */
	} else if (module == SA2UL_MODULE_AUTH) {
		efuse = SA2UL_EFUSE_SHA_EN_MASK;

		e_en = (1U << SA2UL_ENGINE_ENABLE_AUTHSS_EN_SHIFT) |
		       (1U << SA2UL_ENGINE_ENABLE_CTX_EN_SHIFT) |
		       (1U << SA2UL_ENGINE_ENABLE_CDMA_IN_EN_SHIFT) |
		       (1U << SA2UL_ENGINE_ENABLE_CDMA_OUT_EN_SHIFT);

		e_st = (1U << SA2UL_ENGINE_STATUS_AUTHSS_EN_SHIFT) |
		       (1U << SA2UL_ENGINE_STATUS_CTXCACH_EN_SHIFT) |
		       (1U << SA2UL_ENGINE_STATUS_CDMA_IN_PORT_EN_SHIFT) |
		       (1U << SA2UL_ENGINE_STATUS_CDMA_OUT_PORT_EN_SHIFT);
	} else if (module == SA2UL_MODULE_ENCR) {
		efuse = SA2UL_EFUSE_ENCR_DRBG_EN_MASK;

		e_en = (1U << SA2UL_ENGINE_ENABLE_ENCSS_EN_SHIFT) |
		       (1U << SA2UL_ENGINE_ENABLE_CTX_EN_SHIFT) |
		       (1U << SA2UL_ENGINE_ENABLE_CDMA_IN_EN_SHIFT) |
		       (1U << SA2UL_ENGINE_ENABLE_CDMA_OUT_EN_SHIFT);

		e_st = (1U << SA2UL_ENGINE_STATUS_ENCSS_EN_SHIFT) |
		       (1U << SA2UL_ENGINE_STATUS_CTXCACH_EN_SHIFT) |
		       (1U << SA2UL_ENGINE_STATUS_CDMA_IN_PORT_EN_SHIFT) |
		       (1U << SA2UL_ENGINE_STATUS_CDMA_OUT_PORT_EN_SHIFT);
	} else if (module == SA2UL_MODULE_TRNG) {
		e_en = (1U << SA2UL_ENGINE_ENABLE_TRNG_EN_SHIFT);
		e_st = (1U << SA2UL_ENGINE_STATUS_TRNG_EN_SHIFT);
	} else if (module == SA2UL_MODULE_DRBG) {
		efuse = SA2UL_EFUSE_ENCR_DRBG_EN_MASK;
		e_en = (1U << SA2UL_ENGINE_ENABLE_TRNG_EN_SHIFT);
		e_st = (1U << SA2UL_ENGINE_STATUS_TRNG_EN_SHIFT);
	} else {
	}

	*engine_status_mask = e_st;
	*engine_enable_mask = e_en;
	*efuse_mask = efuse;
}

fterr sa2ul_enable(u32 instance, u32 module)
{
	struct sa2ul_regs *s;
	fterr ret = -EINVAL;
	u32 e_st, e_en, efuse, reg;

	/*
	 * TODO: power management
	 */
	if (instance < sa2ul_socdata.num_instances) {
		ret = EFTOK;
	}
	if (ret == EFTOK) {
		ret = socmem_to_local(sa2ul_socdata.base_addr[instance],
				      (local_phys_addr_t *) &s);
	}


	if (ret == EFTOK) {
		sa2ul_get_engine_masks(module, &e_st, &e_en, &efuse);
#if 0
		if (efuse != 0U) {
			/* Check if the module is enabled in efuse */
			if ((readl(&s->EFUSE_EN) & efuse) != efuse) {
				ret = -ENODEV;
			}

		}
#endif
	}


	if ((ret == EFTOK) && (e_en != 0U)) {
		reg = readl(&s->ENGINE_ENABLE);
		reg = reg | e_en;
        /*Check the status of the RNG if already enabled ignore*/
        if((readl(&s->ENGINE_STATUS) & e_st) != e_st)
        {    
		    writel(&s->ENGINE_ENABLE, reg);
        }

		if (!reg_poll_timeout_us(&s->ENGINE_STATUS, e_st, e_st,
					 SA2UL_REG_TIMEOUT)) {
			ret = -ETIMEDOUT;
			while(EFTOK);
		}

		while(!((readl(&s->ENGINE_STATUS) & e_st) == e_st));


	}
	return ret;
}
void sa2ul_disable(u32 instance, u32 module)
{
	struct sa2ul_regs *s;
	fterr ret = -EINVAL;
	u32 e_st, e_en, efuse, reg;

	/*
	 * TODO: power management, refcounting
	 */

	if (instance < sa2ul_socdata.num_instances) {
		ret = EFTOK;
	}


	if (ret == EFTOK) {
		ret = socmem_to_local(sa2ul_socdata.base_addr[instance],
				      (local_phys_addr_t *) &s);
	}

	if (ret == EFTOK) {
		sa2ul_get_engine_masks(module, &e_st, &e_en, &efuse);
		if (e_en != 0U) {
			reg = readl(&s->ENGINE_ENABLE);
			reg = reg & (~e_en);
			writel(&s->ENGINE_ENABLE, reg);
		}
	}
}

fterr sa2ul_enable_all_engines(u32 instance)
{
	fterr ret = -EINVAL;

#ifdef CONFIG_SECURITY_SA2UL_PKA
#if 0
    ret = sa2ul_enable(SA2UL_INSTANCE_HSM_PKA, SA2UL_MODULE_PKA);
#endif
#endif
	ret = sa2ul_enable(instance, SA2UL_MODULE_AUTH);

	ret = sa2ul_enable(instance, SA2UL_MODULE_ENCR);

	return ret;
}
