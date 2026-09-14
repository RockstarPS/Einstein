/*
 * System Firmware NAVSS PSILCFG Library
 *
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file psilcfg.c
 *
 * \brief PSIL configuration functions
 */

#include <types/fterr.h>
#include <common_funcs.h>

#include <psilcfg.h>

/**
 * Timeout value for teardown completion
 */
#define PSILCFG_TDOWN_TIMEOUT_US              (100U)

/**
 * Timeout value for psilcfg IP busy check
 */
#define PSILCFG_BUSY_WAIT_TIMEOUT_US          (10U)

/* thread ID msb must be set to identify it as a destination thread */
#define PSILCFG_DST_THREAD     (0x8000U)

/**
 * \brief PSI-L Configuration Proxy Registers
 *
 * \param REVISION Revision Register
 * \param PSIL_TO PSI-L Proxy Timeout Register
 * \param CMDA PSI-L Configuration Proxy Command Register A
 * \param CMDB PSI-L Configuration Proxy Command Register B
 * \param WDATA PSI-L Configuration Proxy Write Data Register
 * \param RDATA PSI-L Configuration Proxy Read Data Register
 */
struct psilcfg_regs {
	volatile u32	REVISION;
	volatile u8	Resv_16[12];
	volatile u32	PSIL_TO;
	volatile u8	Resv_256[236];
	volatile u32	CMDA;
	volatile u32	CMDB;
	volatile u32	WDATA;
	volatile u8	Resv_320[52];
	volatile u32	RDATA;
};

/*
 * Register Fields
 */

/* PSIL_TO */

#define PSILCFG_PSIL_TO_TOUT_MASK                 (0x80000000U)
#define PSILCFG_PSIL_TO_TOUT_SHIFT                (0x0000001FU)
#define PSILCFG_PSIL_TO_TOUT_CNT_MASK             (0x0000FFFFU)
#define PSILCFG_PSIL_TO_TOUT_CNT_SHIFT            (0x00000000U)

/* CMDA */

#define PSILCFG_CMDA_BUSY_MASK                    (0x80000000U)
#define PSILCFG_CMDA_BUSY_SHIFT                   (0x0000001FU)
#define PSILCFG_CMDA_BUSY_VAL_FALSE               (0x0U)
#define PSILCFG_CMDA_BUSY_VAL_TRUE                (0x1U)
#define PSILCFG_CMDA_DIR_MASK                     (0x40000000U)
#define PSILCFG_CMDA_DIR_SHIFT                    (0x0000001EU)
#define PSILCFG_CMDA_DIR_VAL_WRITE                (0x0U)
#define PSILCFG_CMDA_DIR_VAL_READ                 (0x1U)
#define PSILCFG_CMDA_TO_MASK                      (0x20000000U)
#define PSILCFG_CMDA_TO_SHIFT                     (0x0000001DU)
#define PSILCFG_CMDA_TO_VAL_WRITE                 (0x0U)
#define PSILCFG_CMDA_TO_VAL_READ                  (0x1U)
#define PSILCFG_CMDA_THREAD_ID_MASK               (0x0000FFFFU)
#define PSILCFG_CMDA_THREAD_ID_SHIFT              (0x00000000U)

/* CMDB */

#define PSILCFG_CMDB_BYTEN_MASK                   (0xF0000000U)
#define PSILCFG_CMDB_BYTEN_SHIFT                  (0x0000001CU)
#define PSILCFG_CMDB_ADDRESS_MASK                 (0x0000FFFFU)
#define PSILCFG_CMDB_ADDRESS_SHIFT                (0x00000000U)

/*
 * Hardware Region  : PSI-L Configuration Registers
 *
 * Register Macros
 */
#define PSILCFG_REG_PEER_THREAD_ID  (0U)
#define PSILCFG_REG_PEER_CREDIT     (0x001U)
#define PSILCFG_REG_ENABLE          (0x002U)
#define PSILCFG_REG_CAPABILITIES    (0x040U)
#define PSILCFG_REG_RT_ENABLE       (0x408U)

/*
 * Register Fields
 */

/* PSILCFG_REG_PEER_THREAD_ID */
#define PSILCFG_REG_PEER_THREAD_ID_THREAD_ID_SHIFT      (0U)
#define PSILCFG_REG_PEER_THREAD_ID_THREAD_ID_MASK       (0xFFFFU)
#define PSILCFG_REG_PEER_THREAD_ID_THREAD_WIDTH_SHIFT   (24U)
#define PSILCFG_REG_PEER_THREAD_ID_THREAD_WIDTH_MASK    (0x1F000000U)
#define PSILCFG_REG_PEER_THREAD_ID_THREAD_PRI_SHIFT     (29U)
#define PSILCFG_REG_PEER_THREAD_ID_THREAD_PRI_MASK      (0xE0000000U)

/* PSILCFG_REG_PEER_CREDIT */
#define PSILCFG_REG_PEER_CREDIT_CNT_SHIFT               (0U)
#define PSILCFG_REG_PEER_CREDIT_CNT_MASK                (0xFFU)

/* PSILCFG_REG_ENABLE */
#define PSILCFG_REG_ENABLE_ENABLE_SHIFT                 (31U)
#define PSILCFG_REG_ENABLE_ENABLE_MASK                  (0x80000000U)

/* PSILCFG_REG_CAPABILITIES */
#define PSILCFG_REG_CAPABILITIES_CREDIT_CNT_SHIFT       (0U)
#define PSILCFG_REG_CAPABILITIES_CREDIT_CNT_MASK        (0xFFU)
#define PSILCFG_REG_CAPABILITIES_THREAD_WIDTH_SHIFT     (24U)
#define PSILCFG_REG_CAPABILITIES_THREAD_WIDTH_MASK      (0x1F000000U)

/* PSILCFG_REG_RT_ENABLE */
#define PSILCFG_REG_RT_ENABLE_IDLE_SHIFT                (1U)
#define PSILCFG_REG_RT_ENABLE_IDLE_MASK                 (0x2U)
#define PSILCFG_REG_RT_ENABLE_FLUSH_SHIFT               (28U)
#define PSILCFG_REG_RT_ENABLE_FLUSH_MASK                (0x10000000U)
#define PSILCFG_REG_RT_ENABLE_PAUSE_SHIFT               (29U)
#define PSILCFG_REG_RT_ENABLE_PAUSE_MASK                (0x20000000U)
#define PSILCFG_REG_RT_ENABLE_TDOWN_SHIFT               (30U)
#define PSILCFG_REG_RT_ENABLE_TDOWN_MASK                (0x40000000U)
#define PSILCFG_REG_RT_ENABLE_ENABLE_SHIFT              (31U)
#define PSILCFG_REG_RT_ENABLE_ENABLE_MASK               (0x80000000U)

/**
 * \brief Map a physical address over to mapped_addr
 *
 * \param phy_addr Physical address
 *
 * \param size currently unused
 *
 * \return Mapped address
 */
static inline mapped_addr_t psilcfg_map_region(
	soc_phys_addr_t phy_addr,
	u32		size __attribute__((unused)))
{
	/**
	 * TBD - we need RAT if the mapping is not available.
	 *
	 * NOTE: we will misuse pm/soc/am6/dmsc.c configuration for now:
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

	if ((phy_addr >= 0x44800000U) && (phy_addr <= 0x44FFFFFFU)) {
		return soc_phys_low_u32(phy_addr);
	}

	return soc_phys_low_u32(phy_addr) + 0x60000000U;
}

/**
 * \brief Unmap a physical address which was previously mapped
 *
 * \param phy_addr - physical address to unmap
 *
 * \param size - currently unused
 */
static inline void psilcfg_unmap_region(
	soc_phys_addr_t phy_addr __attribute__((unused)),
	u32		size __attribute__((unused)))
{
	/**
	 * TBD - we need RAT if the mapping is not available - Empty function
	 * for now.
	 */
	return;
}
/**
 * \brief helper function to write to a psil configuration register
 *
 * \param base - A mapped base register
 *
 * \param thread_id - PSIL thread ID destination for the configuration register
 *
 * \param cfg_reg - Register address to write
 *
 * \param data - Data to write
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
static fterr psilcfg_write(local_phys_addr_t base, u32 thread_id,
			   u32 cfg_reg, u32 data)
{
	fterr ret = EFTOK;
	u32 reg;
	struct psilcfg_regs *p_regs = (struct psilcfg_regs *) base;

	if (!reg_poll_timeout_us(&p_regs->CMDA, PSILCFG_CMDA_BUSY_MASK, 0U,
				 PSILCFG_BUSY_WAIT_TIMEOUT_US)) {
		ret = -ETIMEDOUT;
	}

	if (ret == EFTOK) {
		reg = (PSILCFG_CMDA_DIR_VAL_WRITE << PSILCFG_CMDA_DIR_SHIFT) &
		      PSILCFG_CMDA_DIR_MASK;

		reg |= (thread_id << PSILCFG_CMDA_THREAD_ID_SHIFT) &
		       PSILCFG_CMDA_THREAD_ID_MASK;

		ret = writel_verified(&p_regs->CMDA, reg);
	}

	if (ret == EFTOK) {
		reg = (0xFU << PSILCFG_CMDB_BYTEN_SHIFT) &
		      PSILCFG_CMDB_BYTEN_MASK;

		reg |= (cfg_reg << PSILCFG_CMDB_ADDRESS_SHIFT) &
		       PSILCFG_CMDB_ADDRESS_MASK;

		ret = writel_verified(&p_regs->CMDB, reg);
	}

	if (ret == EFTOK) {
		writel(&p_regs->WDATA, data);
	}

	return ret;
}

/**
 * \brief helper function to read to a psil configuration register
 *
 * \param base - A mapped base register
 *
 * \param thread_id - PSIL thread ID destination for the configuration register
 *
 * \param cfg_reg - Register address to read
 *
 * \param data - Data returned upon read
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
static fterr psilcfg_read(local_phys_addr_t base, u32 thread_id,
			  u32 cfg_reg, u32 *data)
{
	fterr ret = EFTOK;
	u32 reg;
	volatile u32 LOOP=500U;
	volatile u32 LOOP1=500U;
	struct psilcfg_regs *p_regs = (struct psilcfg_regs *) base;

	if (!reg_poll_timeout_us(&p_regs->CMDA, PSILCFG_CMDA_BUSY_MASK, 0U,
				 PSILCFG_BUSY_WAIT_TIMEOUT_US)) {
		ret = -ETIMEDOUT;
	}

	while(LOOP--);

	if (ret == EFTOK) {
		reg = (PSILCFG_CMDA_DIR_VAL_READ << PSILCFG_CMDA_DIR_SHIFT) &
		      PSILCFG_CMDA_DIR_MASK;

		reg |= (thread_id << PSILCFG_CMDA_THREAD_ID_SHIFT) &
		       PSILCFG_CMDA_THREAD_ID_MASK;

		ret = writel_verified(&p_regs->CMDA, reg);
	}

	if (ret == EFTOK) {
		reg = (0xFU << PSILCFG_CMDB_BYTEN_SHIFT) &
		      PSILCFG_CMDB_BYTEN_MASK;

		reg |= (cfg_reg << PSILCFG_CMDB_ADDRESS_SHIFT) &
		       PSILCFG_CMDB_ADDRESS_MASK;

		ret = writel_verified(&p_regs->CMDB, reg);
	}

	if (ret == EFTOK) {
		while(LOOP1--);
	}

	if (ret == EFTOK) {
		*data = readl(&p_regs->RDATA);
	}

	return ret;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * PSILCFG Visible APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
fterr psilcfg_create_route_and_enable(u8 id, u16 src_thread_id,
				      u16 dest_thread_id)
{
	fterr ret = EFTOK;
	u32 reg, val, thread_width, credit_cnt, src, dst;
	mapped_addr_t mapped_addr = (mapped_addr_t) 0U;

	src = (u32) src_thread_id & (~PSILCFG_DST_THREAD);
	dst = (u32) dest_thread_id | PSILCFG_DST_THREAD;

	if (id >= soc_psilcfg_instances_num) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		mapped_addr = psilcfg_map_region(
			soc_psilcfg_instances[id].cfg_proxy, 0x100U);

		/* Read destination thread capabilities */
		ret = psilcfg_read(mapped_addr, dst, PSILCFG_REG_CAPABILITIES,
				   &val);
	}
	if (ret == EFTOK) {
		thread_width = (val &
				PSILCFG_REG_CAPABILITIES_THREAD_WIDTH_MASK) >>
			       PSILCFG_REG_CAPABILITIES_THREAD_WIDTH_SHIFT;

		credit_cnt = (val &
			      PSILCFG_REG_CAPABILITIES_CREDIT_CNT_MASK) >>
			     PSILCFG_REG_CAPABILITIES_CREDIT_CNT_SHIFT;


		reg = (thread_width <<
		       PSILCFG_REG_PEER_THREAD_ID_THREAD_WIDTH_SHIFT) &
		      PSILCFG_REG_PEER_THREAD_ID_THREAD_WIDTH_MASK;

		reg |= (dst <<
			PSILCFG_REG_PEER_THREAD_ID_THREAD_ID_SHIFT) &
		       PSILCFG_REG_PEER_THREAD_ID_THREAD_ID_MASK;

		/* Configure Thread ID Register */
		ret = psilcfg_write(mapped_addr, src,
				    PSILCFG_REG_PEER_THREAD_ID, reg);
	}

	if (ret == EFTOK) {
		reg = (credit_cnt << PSILCFG_REG_PEER_CREDIT_CNT_SHIFT) &
		      PSILCFG_REG_PEER_CREDIT_CNT_MASK;

		/* Configure Credit Register */
		ret = psilcfg_write(mapped_addr, src,
				    PSILCFG_REG_PEER_CREDIT, reg);
	}

	/* Enable source thread */
	if (ret == EFTOK) {
		reg = (1U << PSILCFG_REG_ENABLE_ENABLE_SHIFT) &
		      PSILCFG_REG_ENABLE_ENABLE_MASK;

		ret = psilcfg_write(mapped_addr, src,
				    PSILCFG_REG_ENABLE, reg);
	}

	if (ret == EFTOK) {
		reg = (1U << PSILCFG_REG_RT_ENABLE_ENABLE_SHIFT) &
		      PSILCFG_REG_RT_ENABLE_ENABLE_MASK;

		ret = psilcfg_write(mapped_addr, src,
				    PSILCFG_REG_RT_ENABLE, reg);
	}

	/* Enable destination thread */
	if (ret == EFTOK) {
		reg = (1U << PSILCFG_REG_ENABLE_ENABLE_SHIFT) &
		      PSILCFG_REG_ENABLE_ENABLE_MASK;

		ret = psilcfg_write(mapped_addr, dst,
				    PSILCFG_REG_ENABLE, reg);
	}

	if (ret == EFTOK) {
		reg = (1U << PSILCFG_REG_RT_ENABLE_ENABLE_SHIFT) &
		      PSILCFG_REG_RT_ENABLE_ENABLE_MASK;

		ret = psilcfg_write(mapped_addr, dst,
				    PSILCFG_REG_RT_ENABLE, reg);
	}

	if (mapped_addr != (mapped_addr_t) 0U) {
		psilcfg_unmap_region(soc_psilcfg_instances[id].cfg_proxy,
				     0x100U);
	}

	return ret;
}

fterr psilcfg_teardown(u8 id, u16 src_thread_id)
{
	fterr ret = EFTOK;
	u32 reg;
	mapped_addr_t mapped_addr = (mapped_addr_t) 0U;
	u32 start_time, time_diff, tmout_ns;

	if (id >= soc_psilcfg_instances_num) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		mapped_addr = psilcfg_map_region(
			soc_psilcfg_instances[id].cfg_proxy, 0x100U);

		ret = psilcfg_read(mapped_addr, src_thread_id,
				   PSILCFG_REG_RT_ENABLE, &reg);
	}
	if ((ret == EFTOK) &&
	    ((reg & PSILCFG_REG_RT_ENABLE_ENABLE_MASK) != 0U)) {
		reg = (1U << PSILCFG_REG_RT_ENABLE_TDOWN_SHIFT) &
		      PSILCFG_REG_RT_ENABLE_TDOWN_MASK;

		ret = psilcfg_write(mapped_addr, src_thread_id,
				    PSILCFG_REG_RT_ENABLE, reg);
	}
	if (ret == EFTOK) {
		tmout_ns = PSILCFG_TDOWN_TIMEOUT_US * 1000U;
		time_diff = 0U;
		start_time = osal_timestamp32_core();

		do {
			ret = psilcfg_read(mapped_addr, src_thread_id,
					   PSILCFG_REG_RT_ENABLE, &reg);
			if ((ret != EFTOK) ||
			    ((reg & PSILCFG_REG_RT_ENABLE_ENABLE_MASK) ==
			     0U)) {
				break;
			}
			time_diff = osal_timestamp32_core() - start_time;
		} while (time_diff < tmout_ns);

		if ((reg & PSILCFG_REG_RT_ENABLE_ENABLE_MASK) == 0U) {
			ret = EFTOK;
		} else if (time_diff >= tmout_ns) {
			ret = -ETIMEDOUT;
		} else {
			/*
			 * Do nothing, ret is set a error value by
			 * psilcfg_read
			 */
		}
	}

	if (mapped_addr != (mapped_addr_t) 0U) {
		psilcfg_unmap_region(soc_psilcfg_instances[id].cfg_proxy,
				     0x100U);
	}
	return ret;
}

fterr psilcfg_unpair_threads(u8 id, u16 src_thread_id, u16 dest_thread_id)
{
	fterr ret = EFTOK;
	u32 reg, src, dst;
	mapped_addr_t mapped_addr = (mapped_addr_t) 0U;

	src = ((u32) src_thread_id) & (~PSILCFG_DST_THREAD);
	dst = ((u32) dest_thread_id) | PSILCFG_DST_THREAD;

	if (id >= soc_psilcfg_instances_num) {
		ret = -EINVAL;
	}

	if (ft_is_ok(ret)) {
		mapped_addr = psilcfg_map_region(
			soc_psilcfg_instances[id].cfg_proxy, 0x100U);
	}

	/* Disable source and destination threads */
	if (ft_is_ok(ret)) {
		ret = psilcfg_disable(id, src);
	}
	if (ft_is_ok(ret)) {
		ret = psilcfg_disable(id, dst);
	}

	/* Clear the peer thread ID register */
	if (ft_is_ok(ret)) {
		reg = ((u32) 0U << PSILCFG_REG_PEER_THREAD_ID_THREAD_WIDTH_SHIFT) &
		      PSILCFG_REG_PEER_THREAD_ID_THREAD_WIDTH_MASK;

		reg |= ((u32) 0U << PSILCFG_REG_PEER_THREAD_ID_THREAD_ID_SHIFT) &
		       PSILCFG_REG_PEER_THREAD_ID_THREAD_ID_MASK;

		ret = psilcfg_write(mapped_addr, src_thread_id,
				    PSILCFG_REG_PEER_THREAD_ID, reg);
	}

	/* Clear the peer credit register */
	if (ft_is_ok(ret)) {
		reg = ((u32) 0U << PSILCFG_REG_PEER_CREDIT_CNT_SHIFT) &
		      PSILCFG_REG_PEER_CREDIT_CNT_MASK;

		ret = psilcfg_write(mapped_addr, src_thread_id,
				    PSILCFG_REG_PEER_CREDIT, reg);
	}

	if (mapped_addr != (mapped_addr_t) 0U) {
		psilcfg_unmap_region(soc_psilcfg_instances[id].cfg_proxy,
				     0x100U);
	}

	return ret;
}

fterr psilcfg_disable(u8 id, u32 thread_id)
{
	fterr ret = EFTOK;
	u32 reg;
	mapped_addr_t mapped_addr = (mapped_addr_t) 0U;

	if (id >= soc_psilcfg_instances_num) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		mapped_addr = psilcfg_map_region(
			soc_psilcfg_instances[id].cfg_proxy, 0x100U);

		ret = psilcfg_read(mapped_addr, thread_id,
				   PSILCFG_REG_ENABLE, &reg);
	}
	if ((ret == EFTOK) &&
	    ((reg & PSILCFG_REG_ENABLE_ENABLE_MASK) != 0U)) {
		reg = (0U << PSILCFG_REG_ENABLE_ENABLE_SHIFT) &
		      PSILCFG_REG_ENABLE_ENABLE_MASK;

		ret = psilcfg_write(mapped_addr, thread_id,
				    PSILCFG_REG_ENABLE, reg);
	}

	if (mapped_addr != (mapped_addr_t) 0U) {
		psilcfg_unmap_region(soc_psilcfg_instances[id].cfg_proxy,
				     0x100U);
	}

	return ret;
}
