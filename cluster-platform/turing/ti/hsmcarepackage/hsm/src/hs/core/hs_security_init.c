/*
 * Copyright (C) 2019-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file hs_security_init.c
 *
 * \brief Init function for the HS specific portions of security component
 *
 */

#include <config.h>
#include <hs_security_init.h>
#include <sec_dma.h>
#include <sa2ul_sec_ctx.h>
#include <boardcfg/boardcfg.h>
#include <hosts_internal.h>
#include <sa2ul.h>
#include <sa2ul_pka.h>

extern const struct sec_dma_bootcfg sec_dma_bootcfg_data;
extern const struct sa2ul_ctx_bootcfg sec_ctx_bootcfg_data;
#

/**
 * @brief Set the dma isc to non secure state
 * The operation of AES module in the soc has a dependancy on the
 * mode the DMA ISC is configured. ROM set the DMA module in secure mode
 * TIFS uses the ISC in non secure mode. In order to configure the isc in
 * no secure mode set and reset the DMA ISC.
 */


fterr hs_security_early_init_hsm(void)
{
	fterr ret = EFTOK;


#ifdef CONFIG_SECURITY_SA2UL_SEC_CTX
	if (ret == EFTOK) {
		ret = sa2ul_sec_ctx_init_with_initial_cfg();
	}
#endif
#ifdef CONFIG_SECURITY_SA2UL
	/* Enable all SA2UL engines for instance 0 (instance used by SYSFW) */
	if (ret == EFTOK) {
		ret = sa2ul_enable_all_engines(0);
	}
#endif
#ifdef CONFIG_SECURITY_SA2UL_PKA
#if 0
     if (ret == EFTOK) {
         ret = sa2ul_pka_init();
     }
#endif
#endif
#ifdef CONFIG_SECURITY_DMA
	if (ret == EFTOK) {
		ret = sec_dma_init();
	}
#endif

#ifdef CONFIG_SECURITY_SA2UL_SEC_CTX
	if (ret == EFTOK) {
		ret = sa2ul_sec_ctx_init(&sec_ctx_bootcfg_data);
	}
#endif

	return ret;
}


