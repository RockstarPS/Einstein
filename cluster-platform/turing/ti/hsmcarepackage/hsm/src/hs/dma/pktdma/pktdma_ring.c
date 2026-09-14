/*
 * System Firmware pktdma ring Library
 *
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file pktdma_ring.c
 *
 * \brief PKTDMA Ring Library.
 */

#include <config.h>
#include <lib/container_of.h>
#include <types/errno.h>
#include <types/short_types.h>
#include <types/address_types.h>
#include <types/sbool.h>
#include "pktdma_ring.h"
#include "socmem.h"
#include "common_funcs.h"

/*
 * Register Macros
 */
#define PKT_RING_CFG_RING_BASE(RING)                     ((RING) * 0x100U)//+0x11a000
#define PKT_RING_CFG_RING_BA_LO                          (0x00000040U)
#define PKT_RING_CFG_RING_BA_HI                          (0x00000044U)
#define PKT_RING_CFG_RING_SIZE                           (0x00000048U)
#define PKT_RING_CFG_RING_EVENT                          (0x0000004CU)
#define PKT_RING_CFG_RING_ORDERID                        (0x00000050U)

/* SIZE Fields */

#define PKT_RING_CFG_RING_SIZE_QMODE_MASK                (0xE0000000U)
#define PKT_RING_CFG_RING_SIZE_QMODE_SHIFT               (0x0000001DU)
#define PKT_RING_CFG_RING_SIZE_QMODE_RESETVAL            (0x00000000U)
#define PKT_RING_CFG_RING_SIZE_QMODE_MAX                 (0x00000003U)
#define PKT_RING_CFG_RING_SIZE_ELSIZE_MASK               (0x07000000U)
#define PKT_RING_CFG_RING_SIZE_ELSIZE_SHIFT              (0x00000018U)
#define PKT_RING_CFG_RING_SIZE_ELSIZE_RESETVAL           (0x00000000U)
#define PKT_RING_CFG_RING_SIZE_ELSIZE_MAX                (0x00000007U)

#define PKT_RING_CFG_RING_SIZE_ELCNT_MASK                (0x000FFFFFU)
#define PKT_RING_CFG_RING_SIZE_ELCNT_SHIFT               (0x00000000U)
#define PKT_RING_CFG_RING_SIZE_ELCNT_RESETVAL            (0x00000000U)
#define PKT_RING_CFG_RING_SIZE_ELCNT_MAX                 (0x000FFFFFU)

#define PKT_RING_CFG_RING_SIZE_RESETVAL                  (0x00000000U)

/* Element size for indirect mode (value 1 = 8 bytes) */
#define RING_CFG_RING_SIZE_ELSIZE_INDIRECT              (0x00000001U)

#define PKT_RING_CFG_RING_EVENT_EVT_MASK                 (0x0000FFFFU)
#define PKT_RING_CFG_RING_EVENT_EVT_SHIFT                (0x00000000U)
#define PKT_RING_CFG_RING_EVENT_EVT_RESETVAL             (0x0000FFFFU)

/*
 * Register Macros - RT registers
 */
#define PKT_RING_RT_RINGRT_BASE(RINGRT)                  ((RINGRT) * 0x2000U)
#define PKT_RING_RT_RINGRT_DB                            (0x00000010U)
#define PKT_RING_RT_RINGRT_OCC                           (0x00000018U)
#define PKT_RING_RT_RINGRT_INDX                          (0x0000001CU)
#define PKT_RING_RT_RINGRT_HWOCC                         (0x00000020U)
#define PKT_RING_RT_RINGRT_HWINDX                        (0x00000024U)

/* Occupancy fields */
#define PKT_RING_RT_RINGRT_OCC_RINGOCC_MASK              (0x001FFFFFU)
#define PKT_RING_RT_RINGRT_OCC_RINGOCC_SHIFT             (0x00000000U)

/* Doorbells */
#define PKT_RING_RT_RINGRT_DB_INCR                       (0x00000001U)
#define PKT_RING_RT_RINGRT_DB_DECR                       (0x000000FFU)

/**
 * \brief Map a physical address over to mapped_addr
 *
 * \param phy_addr Physical address
 *
 * \return Mapped address
 */
static mapped_addr_t pkt_ring_map_region(soc_phys_addr_t phy_addr)
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

	/*
	 * On SMS sub-systems, the below address range is a local window into
	 * the DMSS_HSM region and does not require RAT mapping. Check the
	 * window to enable un-mapped view of the PktDMA regions for this
	 * instance.
	 *
	 * On DMSC, this region is reserved in the local memory map and no
	 * peripheral should be placed in the address space.
	 */
	if ((soc_phys_low_u32(phy_addr) < (0x45000000U)) &&
	    (soc_phys_low_u32(phy_addr) >= (0x44800000U))) {
		return soc_phys_low_u32(phy_addr);
	} else {
		return soc_phys_low_u32(phy_addr) + 0x60000000U;
	}
}

/**
 * \brief Unmap a physical address which was previously mapped
 *
 * \param phy_addr - physical address to unmap
 */
static void pkt_ring_unmap_region(soc_phys_addr_t phy_addr __attribute__((unused)))
{
	/**
	 * TBD - we need RAT if the mapping is not available - Empty function
	 * for now.
	 */
	return;
}

/**
 * \brief helper function to do the configuration of the ring
 *
 * \param cfg_cfg_addr - Ring Accelerator's cfg_cfg address (mapped address)
 *
 * \param rid - Ring ID
 *
 * \param rmode - Ring Mode to configure
 *
 * \param buff_addr - Backing Data buffer address for the Ring
 *
 * \param elsize - Element size of the Ring
 *
 * \param num_el - Number of elements in the ring.
 *
 * The helper function does expect caller to do all required authentication
 * mapping from physical address to virtual address, etc.
 *
 * \return 0 if all went fine, else return corresponding error
 */
s32 _pkt_ring_setup_ring(mapped_addr_t cfg_cfg_addr, u16 rid, u8 rmode,
			 soc_phys_addr_t buff_addr, u8 elsize, u16 num_el)
{
	u32 ring_base = PKT_RING_CFG_RING_BASE(rid) + cfg_cfg_addr;
	u32 buffer_low = soc_phys_low_u32(buff_addr);
	u32 buffer_high = soc_phys_high_u32(buff_addr);
	u32 size_reg;
	fterr ftret;

	ftret = writel_verified((volatile u32 *) (ring_base + PKT_RING_CFG_RING_BA_LO), buffer_low);

	if (ft_is_ok(ftret)) {
		ftret = writel_verified((volatile u32 *) (
						ring_base + PKT_RING_CFG_RING_BA_HI), buffer_high);
	}

	size_reg =
		(rmode <<
		 PKT_RING_CFG_RING_SIZE_QMODE_SHIFT) &
		PKT_RING_CFG_RING_SIZE_QMODE_MASK;
	size_reg |=
		(elsize <<
		 PKT_RING_CFG_RING_SIZE_ELSIZE_SHIFT) &
		PKT_RING_CFG_RING_SIZE_ELSIZE_MASK;
	size_reg |=
		(num_el <<
		 PKT_RING_CFG_RING_SIZE_ELCNT_SHIFT) &
		PKT_RING_CFG_RING_SIZE_ELCNT_MASK;

	if (ft_is_ok(ftret)) {
		ftret = writel_verified((volatile u32 *) (
						ring_base + PKT_RING_CFG_RING_SIZE), size_reg);
	}


	return fterr_to_common(ftret);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * PKT_RING Visible APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
s32 pkt_ring_setup_ring_ba(const struct pktdma_ring_config *rconfig, soc_phys_addr_t buffer_baseaddr)
{
	const struct pktdma_ring *ra;
	mapped_addr_t mapped_addr = 0;
	s32 ret = SUCCESS;

	/* check for basic invalid pointer */
	if (rconfig == NULL) {
		ret = -EINVAL;
	}

	/* Do I have valid base address? */
	if (buffer_baseaddr == 0) {
		ret = -EINVAL;
	}

	/* Do I have a valid Ring accelerator? */
	if ((ret == SUCCESS) &&
	    (rconfig->ra_idx >= soc_pktdma_ring_instances_num)) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		ra = &(soc_pktdma_ring_instances[rconfig->ra_idx]);
	}

	if ((ret == SUCCESS) && (rconfig->num_entries == 0)) {
		ret = -EINVAL;
	}

	if ((ret == SUCCESS) && (rconfig->ring_index > ra->num_rings)) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		mapped_addr = pkt_ring_map_region(ra->baseaddr_cfg__cfg);

		ret = _pkt_ring_setup_ring(mapped_addr, rconfig->ring_index,
					   rconfig->ring_mode,
					   buffer_baseaddr,
					   rconfig->elsize,
					   rconfig->num_entries);

		/* we need this only for initial configuration */
		pkt_ring_unmap_region(ra->baseaddr_cfg__cfg);
	}

	return ret;
}

s32 pkt_ring_wait_for_mesg(u8 ra_idx, u16 ring_index, u32 tmout_us)
{
	const struct pktdma_ring *ra;
	mapped_addr_t mapped_addr = 0;
	u32 ringrt_base;
	s32 ret = SUCCESS;
	volatile u32 HOLD=5000;
	/* Do I have a valid Ring accelerator? */
	if (ra_idx >= soc_pktdma_ring_instances_num) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		ra = &(soc_pktdma_ring_instances[ra_idx]);

		if (ring_index > ra->num_rings) {
			ret = -EINVAL;
		}
	}

	if (ret == SUCCESS) {
		volatile u32 ringacc_rt;
		sbool msg_avail;
		mapped_addr = pkt_ring_map_region(ra->baseaddr_cfg__rt);

		/*  Forward and reverse occupancy are both part of the same ring */
		ringrt_base = PKT_RING_RT_RINGRT_BASE(ring_index) + 0x1000U + mapped_addr;
		ringacc_rt = (ringrt_base + PKT_RING_RT_RINGRT_OCC);

		/*
		 *  NOTE: If we ever queue multiple packets to SA2UL from DMSC, this
		 *  check has to be modified to check for non-zero values instead of
		 *  checking for 0x1
		 */
		msg_avail = reg_poll_timeout_us((u32 *) ringacc_rt, PKT_RING_RT_RINGRT_OCC_RINGOCC_MASK,
						0x1U, tmout_us);
		if (msg_avail) {
			ret = SUCCESS;
		} else {
			while(HOLD);
			ret = -ETIMEDOUT;
		}
		pkt_ring_unmap_region(ra->baseaddr_cfg__rt);
	}
	return ret;
}

s32 pkt_ring_push(u8 ra_idx, u16 ring_index, u16 *elem_index, soc_phys_addr_t data)
{
	const struct pktdma_ring *ra;
	mapped_addr_t mapped_addr = 0;
	local_phys_addr_t insptr;
	u32 size_reg;
	u32 buffer_low;
	u32 buffer_high;
	volatile u8 rmode;
	volatile u8 elsize;
	volatile u16 num_el;
	u32 occ;
	soc_phys_addr_t buffer_base;
	u32 buffer_offset;
	u32 ringrt_base;
	u32 ringcfg_base;
	s32 ret = SUCCESS;
	fterr ftret;

	/* Do I have a valid Ring accelerator? */
	if (ra_idx >= soc_pktdma_ring_instances_num) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		ra = &(soc_pktdma_ring_instances[ra_idx]);

		if (ring_index > ra->num_rings) {
			ret = -EINVAL;
		}
	}

	if (ret == SUCCESS) {
		if (elem_index == NULL) {
			ret = -EINVAL;
		}
	}

	if (ret == SUCCESS) {
		/* First read back the geometry of the ring */
		mapped_addr = pkt_ring_map_region(ra->baseaddr_cfg__cfg);
		ringcfg_base = PKT_RING_CFG_RING_BASE(ring_index) + mapped_addr;

		size_reg = readl((volatile u32 *) (ringcfg_base + PKT_RING_CFG_RING_SIZE));
		rmode = (size_reg & PKT_RING_CFG_RING_SIZE_QMODE_MASK) >>
			PKT_RING_CFG_RING_SIZE_QMODE_SHIFT;
		elsize = (size_reg & PKT_RING_CFG_RING_SIZE_ELSIZE_MASK) >>
			 PKT_RING_CFG_RING_SIZE_ELSIZE_SHIFT;
		num_el = (size_reg & PKT_RING_CFG_RING_SIZE_ELCNT_MASK) >>
			 PKT_RING_CFG_RING_SIZE_ELCNT_SHIFT;

		buffer_low = readl((volatile u32 *) (ringcfg_base + PKT_RING_CFG_RING_BA_LO));
		buffer_high = readl((volatile u32 *) (ringcfg_base + PKT_RING_CFG_RING_BA_HI));

		if ((rmode != 1 /*RING_MODE_EXPOSED_RING*/) ||
		    (elsize != RING_CFG_RING_SIZE_ELSIZE_INDIRECT) ||
		    (*elem_index >= num_el)) {
			/* This driver only works in indirect mode with
			 * exposed ring and elem size = 8. */
			ret = -EINVAL;
			while(1);
		}

		pkt_ring_unmap_region(ra->baseaddr_cfg__cfg);
	}

	if (ret == SUCCESS) {
		/* Next map RT area and read occupancy to see if full */
		mapped_addr = pkt_ring_map_region(ra->baseaddr_cfg__rt);
		ringrt_base = PKT_RING_RT_RINGRT_BASE(ring_index) + mapped_addr;

		occ = readl((volatile u32 *) (ringrt_base + PKT_RING_RT_RINGRT_OCC));

		if (occ >= num_el) {
			/* Ring is full */
			ret = -EINVAL;
		}

		pkt_ring_unmap_region(ra->baseaddr_cfg__rt);
	}


	if (ret == SUCCESS) {
		buffer_base = soc_phys_create(buffer_low, buffer_high);
		buffer_offset = *elem_index * sizeof(soc_phys_addr_t);

		/* Next map the ring's data area and insert element */
		ftret = socmem_to_local(buffer_base, &insptr);
		if (ftret != EFTOK) {
			ret = -EINVAL;
		}
	}

	if (ret == SUCCESS) {
		/* write pointer to ring memory using writel for fence */
		writel((volatile u32 *) (insptr + buffer_offset), soc_phys_low_u32(data));
		writel((volatile u32 *) (insptr + buffer_offset + sizeof(u32)), soc_phys_high_u32(data));

		/* bump index for next insertion */
		(*elem_index)++;
		if (*elem_index >= num_el) {
			/* wraparound */
			*elem_index = 0U;
		}

		/* Map RT to do doorbell */
		mapped_addr = pkt_ring_map_region(ra->baseaddr_cfg__rt);
		ringrt_base = PKT_RING_RT_RINGRT_BASE(ring_index) + mapped_addr;
		/* Writing doorbell with writel vs writel_verified because its wo
		 * on some devices */
		writel((volatile u32 *) (ringrt_base + PKT_RING_RT_RINGRT_DB), PKT_RING_RT_RINGRT_DB_INCR);

		pkt_ring_unmap_region(ra->baseaddr_cfg__rt);
	}

	return ret;
}

s32 pkt_ring_pop(u8 ra_idx, u16 ring_index, u16 *elem_index, soc_phys_addr_t *data)
{
	const struct pktdma_ring *ra;
	mapped_addr_t mapped_addr = 0;
	local_phys_addr_t remptr;
	u32 size_reg;
	u32 buffer_low;
	u32 buffer_high;
	u32 data_low;
	u32 data_high;
	u8 rmode;
	u8 elsize;
	u16 num_el;
	u32 occ;
	soc_phys_addr_t buffer_base;
	u32 buffer_offset;
	u32 ringrt_base;
	u32 ringcfg_base;
	s32 ret = SUCCESS;
	fterr ftret;

	/* Do I have a valid Ring accelerator? */
	if (ra_idx >= soc_pktdma_ring_instances_num) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		ra = &(soc_pktdma_ring_instances[ra_idx]);

		if (ring_index > ra->num_rings) {
			ret = -EINVAL;
		}
	}

	if (ret == SUCCESS) {
		if ((elem_index == NULL) || (data == NULL)) {
			ret = -EINVAL;
		}
	}

	if (ret == SUCCESS) {
		/* First read back the geometry of the ring */
		mapped_addr = pkt_ring_map_region(ra->baseaddr_cfg__cfg);
		ringcfg_base = PKT_RING_CFG_RING_BASE(ring_index) + mapped_addr;
		size_reg = readl((volatile u32 *) (ringcfg_base + PKT_RING_CFG_RING_SIZE));
		rmode = (size_reg & PKT_RING_CFG_RING_SIZE_QMODE_MASK) >>
			PKT_RING_CFG_RING_SIZE_QMODE_SHIFT;
		elsize = (size_reg & PKT_RING_CFG_RING_SIZE_ELSIZE_MASK) >>
			 PKT_RING_CFG_RING_SIZE_ELSIZE_SHIFT;
		num_el = (size_reg & PKT_RING_CFG_RING_SIZE_ELCNT_MASK) >>
			 PKT_RING_CFG_RING_SIZE_ELCNT_SHIFT;

		buffer_low = readl((volatile u32 *) (ringcfg_base + PKT_RING_CFG_RING_BA_LO));
		buffer_high = readl((volatile u32 *) (ringcfg_base + PKT_RING_CFG_RING_BA_HI));

		if ((rmode != 1 /*RING_MODE_EXPOSED_RING*/) ||
		    (elsize != RING_CFG_RING_SIZE_ELSIZE_INDIRECT) ||
		    (*elem_index >= num_el)) {
			/* This driver only works in indirect mode with
			 * exposed ring and elem size = 8. */
			ret = -EINVAL;
			while(1);
		}

		pkt_ring_unmap_region(ra->baseaddr_cfg__cfg);
	}

	if (ret == SUCCESS) {
		/* Next map RT area and read occupancy to see if empty */
		mapped_addr = pkt_ring_map_region(ra->baseaddr_cfg__rt);
		ringrt_base = PKT_RING_RT_RINGRT_BASE(ring_index) + 0x1000U + mapped_addr;
		occ = readl((volatile u32 *) (ringrt_base + PKT_RING_RT_RINGRT_OCC));
		pkt_ring_unmap_region(ra->baseaddr_cfg__rt);

		if (occ == 0U) {
			/* Ring is empty */
			*data = NULL;
		} else {
			buffer_base = soc_phys_create(buffer_low, buffer_high);
			buffer_offset = *elem_index * sizeof(soc_phys_addr_t);

			/* Next map the ring's data area and read element */
			ftret = socmem_to_local(buffer_base, &remptr);
			if (ftret != EFTOK) {
				/* Couldn't access data buffer via local/rat */
				ret = -EINVAL;
			} else {
				/* read pointer from ring memory using readl for fence */
				data_low = readl((volatile u32 *) (remptr + buffer_offset));
				data_high = readl((volatile u32 *) (remptr + buffer_offset + sizeof(u32)));
				*data = soc_phys_create(data_low, data_high);

				/* bump index for next pop */
				(*elem_index)++;
				if (*elem_index >= num_el) {
					/* wraparound */
					*elem_index = 0U;
				}

				/* Map RT to do doorbell */
				mapped_addr = pkt_ring_map_region(ra->baseaddr_cfg__rt);
				ringrt_base = PKT_RING_RT_RINGRT_BASE(ring_index) + 0x1000U + mapped_addr;
				/* Writing doorbell with writel vs writel_verified because its wo
				 * on some devices */
				writel((volatile u32 *) (ringrt_base + PKT_RING_RT_RINGRT_DB), PKT_RING_RT_RINGRT_DB_DECR);

				pkt_ring_unmap_region(ra->baseaddr_cfg__rt);
			}
		}
	}

	return ret;
}
