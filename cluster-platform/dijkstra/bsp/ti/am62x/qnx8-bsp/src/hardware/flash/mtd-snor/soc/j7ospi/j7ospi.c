/*
 * Copyright (c) 2023-2024, BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You
 * may not reproduce, modify or distribute this software except in
 * compliance with the License. You may obtain a copy of the License
 * at: http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * This file may contain contributions from others, either as
 * contributors under the License or as licensors under other terms.
 * Please review this entire file for other proprietary rights or license
 * notices, as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */

#include "j7ospi.h"

#ifdef  J7OSPI_UDMA_SUPPORT // This flag tells us PSDKQA is installed
#include "ti/drv/sciclient/sciclient.h"
#include "ti/csl/csl_types.h"
#include "sciclient_fmwMsgParams.h"
#endif

static int j7ospi_map_dacmem(j7ospi_dev_t *const ospi);
static int j7ospi_wait_idle(j7ospi_dev_t *const ospi);
static int j7ospi_cfg_bus(snor_ctrl_t *const snor, snor_cfg_t *const cfg);
static int j7ospi_read(snor_ctrl_t *const snor, const snor_cmd_t *const cmd, uint8_t *const buf, const uint32_t len);

static void j7ospi_read_fifo_data(const j7ospi_dev_t *const ospi, uint8_t *const buf, const uint32_t count)
{
    uint32_t    remain = count;
    uint32_t    *dptr = (uint32_t *)buf;
    uint8_t     data[4];

	if (ospi->buscfg.cflgs & SNOR_CFGFLGS_SWAPB)
	{
		while (remain > 0) {
			uint8_t tmp;
			*(uint32_t*)data = in32(ospi->mem_vbase);

			/*  byte swapping			
			https://lore.kernel.org/lkml/d755a917-7763-764e-7030-3afd5154053c@ti.com/T/
			https://lore.kernel.org/lkml/9e0b6bde-838d-b8a4-9fe7-75c4f916fb27@microchip.com/
			*/
			tmp=data[0];
			data[0]=data[1];
			data[1]=tmp;
			tmp=data[2];
			data[2]=data[3];
			data[3]=tmp;

			if (remain >= sizeof(uint32_t)) {
				*dptr++ = *(uint32_t*)data;
				remain -= sizeof(uint32_t);
			} else {
				memcpy(dptr, &data, remain);
				break;
			}
		}
	}
	else
		while (remain > 0) {
			uint32_t data32 = in32(ospi->mem_vbase);

			if (remain >= sizeof(uint32_t)) {
				*dptr++ = data32;
				remain -= sizeof(uint32_t);
			} else {
				memcpy(dptr, &data32, remain);
				break;
			}
		}
}

static void j7ospi_write_fifo_data(const j7ospi_dev_t *const ospi, const uint8_t *const buf, const uint32_t count)
{
    uint32_t       remain = count;
    const uint32_t *dptr = (uint32_t *)buf;
    uint32_t       byte_swap = (ospi->buscfg.cflgs & SNOR_CFGFLGS_SWAPB);
    uint8_t        data[4];

    while (remain > 0) {
		uint8_t tmp;
        if (remain >= 4) {
            *(uint32_t*)data = *dptr++;
            remain -= 4;
        } else {
            memcpy(&data, dptr, remain);
            remain = 0;
        }

		if (byte_swap)
		{
			/*  byte swapping			
			https://lore.kernel.org/lkml/d755a917-7763-764e-7030-3afd5154053c@ti.com/T/
			https://lore.kernel.org/lkml/9e0b6bde-838d-b8a4-9fe7-75c4f916fb27@microchip.com/
			*/
			tmp=data[0];
			data[0]=data[1];
			data[1]=tmp;
			tmp=data[2];
			data[2]=data[3];
			data[3]=tmp;
		}

        out32(ospi->mem_vbase, *(uint32_t*)data);
    }
}

static int j7ospi_wait_for_bit(const uintptr_t reg, const uint32_t mask, const int clear)
{
    uint32_t    val;
    uint32_t    timeout = J7OSPI_TIMEOUT_NS / 100;

    while (timeout--) {
        val = in32(reg);
        if (clear) {
            val = ~val;
        }
        val &= mask;

        if (val == mask) return (EOK);

        nanospin_ns(100);
    }

    snor_slogf(_SLOG_ERROR, 0, 0,
        "%s: wait for register %x[%x:%x] %s timed out",
        __func__, reg & (uintptr_t)0xFF, in32(reg), mask, clear ? "clear" : "set");

    return (ETIMEDOUT);
}

static int j7ospi_is_idle(j7ospi_dev_t *const ospi)
{
    const  uint32_t reg = in32(ospi->ctrl_vbase + J7OSPI_CONFIG);

    return (reg & (1 << J7OSPI_CONFIG_IDLE_LSB));
}

static int j7ospi_wait_idle(j7ospi_dev_t *const ospi)
{
    unsigned long count = 0;
    unsigned long timeout = 0;

    while (1) {
        /*
         * Read few times in succession to ensure the controller
         * is indeed idle, that is, the bit does not transition
         * low again.
         */
        if (j7ospi_is_idle(ospi)) {
            if (++count >= 3) return (EOK);
        } else {
            count = 0;
        }

        // 500ms
        if (++timeout > J7OSPI_TIMEOUT_NS / 100) {
            /* Timeout, in busy mode. */
            snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: OSPI is still busy", __func__);
            return (ETIMEDOUT);
        }

        nanospin_ns(100);
    }
}

static void j7ospi_controller_enable(j7ospi_dev_t *const ospi, const int enable)
{
    uint32_t    reg;

    reg = in32(ospi->ctrl_vbase + J7OSPI_CONFIG);

    if (enable) {
        reg |= J7OSPI_CONFIG_ENABLE_MASK;
    } else {
        reg &= ~J7OSPI_CONFIG_ENABLE_MASK;
    }

    out32(ospi->ctrl_vbase + J7OSPI_CONFIG, reg);
}

static void j7ospi_chipselect(j7ospi_dev_t *const ospi, uint8_t chip_select)
{
    const uintptr_t   base = ospi->ctrl_vbase;
    uint32_t    reg;

    reg = in32(base + J7OSPI_CONFIG);
    if (ospi->is_decoded_cs) {
        reg |= J7OSPI_CONFIG_DECODE_MASK;
    } else {
        reg &= ~J7OSPI_CONFIG_DECODE_MASK;

        /* Convert CS if without decoder.
         * CS0 to 4b'1110
         * CS1 to 4b'1101
         * CS2 to 4b'1011
         * CS3 to 4b'0111
         */
        chip_select = 0xF & ~(1 << chip_select);
    }

    reg &= ~(J7OSPI_CONFIG_CHIPSELECT_MASK << J7OSPI_CONFIG_CHIPSELECT_LSB);
    reg |= (chip_select & J7OSPI_CONFIG_CHIPSELECT_MASK) << J7OSPI_CONFIG_CHIPSELECT_LSB;
    out32(base + J7OSPI_CONFIG, reg);

    ospi->current_cs = chip_select;
}

static void j7ospi_configure_sizes(const j7ospi_dev_t *const ospi, const uint32_t page_size, const uint32_t sect_size, const uint16_t addr_width)
{
    const uintptr_t base = ospi->ctrl_vbase;
    uint32_t    reg;
    uint32_t    erase_power2;

    for (erase_power2 = 0; sect_size != (uint32_t)(1 << erase_power2); erase_power2++) {
        ;
    }

    /* configure page size and block size. */
    reg = in32(base + J7OSPI_SIZE_CFG);
    reg &= ~(J7OSPI_SIZE_CFG_PAGE_MASK << J7OSPI_SIZE_CFG_PAGE_LSB);
    reg &= ~(J7OSPI_SIZE_CFG_BLOCK_MASK << J7OSPI_SIZE_CFG_BLOCK_LSB);
    reg &= ~J7OSPI_SIZE_CFG_ADDRESS_MASK;
    reg |= (page_size << J7OSPI_SIZE_CFG_PAGE_LSB);
    reg |= (erase_power2 << J7OSPI_SIZE_CFG_BLOCK_LSB);
    reg |= (addr_width - 1);
    out32(base + J7OSPI_SIZE_CFG, reg);
}

static int j7ospi_exec_flash_cmd(j7ospi_dev_t *const ospi, unsigned int reg)
{
    const uintptr_t base = ospi->ctrl_vbase;
    const uint8_t   opcode = (uint8_t)((reg >> J7OSPI_CMDCTRL_OPCODE_LSB) & J7OSPI_RD_INSTR_OPCODE_MASK);
    uint32_t        ext_reg;
    int   ret;

    /* Set OSPI_OPCODE_EXT_LOWER_REG */
    if (ospi->buscfg.cflgs & SNOR_CFGFLGS_DBOP) {
        ext_reg = in32(ospi->ctrl_vbase + J7OSPI_OPCODE_EXT_LOWER_REG);
        ext_reg &= ~(J7OSPI_RD_INSTR_OPCODE_MASK << J7OSPI_OPCODE_EXT_LOWER_STIG_LSB);
        ext_reg |= (opcode << J7OSPI_OPCODE_EXT_LOWER_STIG_LSB);
        out32(ospi->ctrl_vbase + J7OSPI_OPCODE_EXT_LOWER_REG, ext_reg);
    }
    if (ospi->buscfg.cflgs & SNOR_CFGFLGS_DBIOP) {
        ext_reg = in32(ospi->ctrl_vbase + J7OSPI_OPCODE_EXT_LOWER_REG);
        ext_reg &= ~(J7OSPI_RD_INSTR_OPCODE_MASK << J7OSPI_OPCODE_EXT_LOWER_STIG_LSB);
        ext_reg |= ((opcode^0xFF) << J7OSPI_OPCODE_EXT_LOWER_STIG_LSB);
        out32(ospi->ctrl_vbase + J7OSPI_OPCODE_EXT_LOWER_REG, ext_reg);
    }

    /* Write the CMDCTRL without start execution. */
    out32(base + J7OSPI_CMDCTRL, reg);
    /* Start execute */
    reg |= J7OSPI_CMDCTRL_EXECUTE_MASK;
    out32(base + J7OSPI_CMDCTRL, reg);

    /* Polling for completion. */
    ret = j7ospi_wait_for_bit(base + J7OSPI_CMDCTRL, J7OSPI_CMDCTRL_INPROGRESS_MASK, 1);
    if (ret != EOK) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Flash command execution timed out.", __func__);
        return (ret);
    }

    /* Polling OSPI idle status. */
    ret = j7ospi_wait_idle(ospi);
    if (ret != EOK) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Polling OSPI idle timed out.", __func__);
        return (ret);
    }

    return (EOK);
}

static void j7ospi_read_setup(j7ospi_dev_t *const ospi, const snor_cmd_t *const cmd)
{
    uint32_t       reg;
    const uint8_t  opcode = cmd->op->opcode;
    const uint8_t  alen   = cmd->op->adrlen;
    const uint8_t  dcycle = cmd->op->dcycle;
    const uint8_t  dtr    = (uint8_t)((ospi->proto & SNOR_BUSPROTO_DTR_MODE) ? 1 : 0);

    /* OSPI_DEV_INSTR_RD_CONFIG_REG */
    reg = in32(ospi->ctrl_vbase + J7OSPI_RD_INSTR);
    reg &= ~((J7OSPI_RD_INSTR_OPCODE_MASK << J7OSPI_RD_INSTR_OPCODE_LSB) |
        (J7OSPI_RD_INSTR_TYPE_INSTR_MASK << J7OSPI_RD_INSTR_TYPE_INSTR_LSB) |
        (1 << J7OSPI_RD_INSTR_DDR_EN_LSB) |
        (J7OSPI_RD_INSTR_TYPE_ADDR_MASK << J7OSPI_RD_INSTR_TYPE_ADDR_LSB) |
        (J7OSPI_RD_INSTR_TYPE_DATA_MASK << J7OSPI_RD_INSTR_TYPE_DATA_LSB) |
        (J7OSPI_RD_INSTR_DUMMY_MASK << J7OSPI_RD_INSTR_DUMMY_LSB));
    reg |= ((opcode << J7OSPI_RD_INSTR_OPCODE_LSB) |
        (ospi->inst_width << J7OSPI_RD_INSTR_TYPE_INSTR_LSB) |
        (dtr << J7OSPI_RD_INSTR_DDR_EN_LSB) |
        (ospi->addr_width << J7OSPI_RD_INSTR_TYPE_ADDR_LSB) |
        (ospi->data_width << J7OSPI_RD_INSTR_TYPE_DATA_LSB) |
        (dcycle << J7OSPI_RD_INSTR_DUMMY_LSB));
    out32(ospi->ctrl_vbase + J7OSPI_RD_INSTR, reg);

    /* Set address width */
    reg = in32(ospi->ctrl_vbase + J7OSPI_SIZE_CFG);
    reg &= ~J7OSPI_SIZE_CFG_ADDRESS_MASK;
    reg |= (alen - 1) & J7OSPI_SIZE_CFG_ADDRESS_MASK;
    out32(ospi->ctrl_vbase + J7OSPI_SIZE_CFG, reg);

    /* Set OSPI_OPCODE_EXT_LOWER_REG */
    if (ospi->buscfg.cflgs & SNOR_CFGFLGS_DBOP) {
        reg = in32(ospi->ctrl_vbase + J7OSPI_OPCODE_EXT_LOWER_REG);
        reg &= ~(J7OSPI_RD_INSTR_OPCODE_MASK << J7OSPI_OPCODE_EXT_LOWER_RD_LSB);
        reg |= (opcode << J7OSPI_OPCODE_EXT_LOWER_RD_LSB);
        out32(ospi->ctrl_vbase + J7OSPI_OPCODE_EXT_LOWER_REG, reg);
    }
    if (ospi->buscfg.cflgs & SNOR_CFGFLGS_DBIOP) {
        reg = in32(ospi->ctrl_vbase + J7OSPI_OPCODE_EXT_LOWER_REG);
        reg &= ~(J7OSPI_RD_INSTR_OPCODE_MASK << J7OSPI_OPCODE_EXT_LOWER_RD_LSB);
        reg |= ((opcode^0xFF) << J7OSPI_OPCODE_EXT_LOWER_RD_LSB);
        out32(ospi->ctrl_vbase + J7OSPI_OPCODE_EXT_LOWER_REG, reg);
    }

}

static void j7ospi_write_setup(j7ospi_dev_t *const ospi, const snor_cmd_t *const cmd)
{
    const uintptr_t  base   = ospi->ctrl_vbase;
    const uint8_t    opcode = cmd->op->opcode;
    const uint32_t   adrlen = cmd->op->adrlen;
    const uint8_t    cmd_flgs = cmd->op->flags;
    uint32_t    reg;
    const snor_ctrl_t *const ctrl = (snor_ctrl_t *)ospi;

    /* Set opcode. */
    reg = in32(base + J7OSPI_WR_INSTR);
    reg &= ~((J7OSPI_WR_INSTR_OPCODE_MASK << J7OSPI_WR_INSTR_OPCODE_LSB) |
        (J7OSPI_WR_INSTR_TYPE_ADDR_MASK << J7OSPI_WR_INSTR_TYPE_ADDR_LSB) |
        (J7OSPI_WR_INSTR_TYPE_DATA_MASK << J7OSPI_WR_INSTR_TYPE_DATA_LSB));
    reg |= ((opcode << J7OSPI_WR_INSTR_OPCODE_LSB) |
        (ospi->addr_width << J7OSPI_WR_INSTR_TYPE_ADDR_LSB) |
        (ospi->data_width << J7OSPI_WR_INSTR_TYPE_DATA_LSB));
    out32(base + J7OSPI_WR_INSTR, reg);

    /* OSPI_DEV_INSTR_RD_CONFIG_REG[INSTR_TYPE_FLD] */
    /* NOTE: if (INSTR_TYPE_FLD != 0), we don't care about
       ADDR_XFER_TYPE_STD_MODE_FLD & DATA_XFER_TYPE_EXT_MODE_FLD
       (See J7200 TRM Table 12-6327) */
    reg = in32(base + J7OSPI_RD_INSTR);
    reg &= ~(J7OSPI_RD_INSTR_TYPE_INSTR_MASK << J7OSPI_RD_INSTR_TYPE_INSTR_LSB);
    reg |= ospi->inst_width << J7OSPI_RD_INSTR_TYPE_INSTR_LSB;
    out32(base + J7OSPI_RD_INSTR, reg);

    /* Set address width */
    reg = in32(base + J7OSPI_SIZE_CFG);
    reg &= ~J7OSPI_SIZE_CFG_ADDRESS_MASK;
    reg |= (adrlen - 1) & J7OSPI_SIZE_CFG_ADDRESS_MASK;
    out32(base + J7OSPI_SIZE_CFG, reg);

    /* Set OSPI_OPCODE_EXT_LOWER_REG */
    if (ospi->buscfg.cflgs & SNOR_CFGFLGS_DBOP) {
        reg = in32(ospi->ctrl_vbase + J7OSPI_OPCODE_EXT_LOWER_REG);
        reg &= ~(J7OSPI_WR_INSTR_OPCODE_MASK << J7OSPI_OPCODE_EXT_LOWER_WR_LSB);
        reg |= (opcode << J7OSPI_OPCODE_EXT_LOWER_WR_LSB);
        out32(ospi->ctrl_vbase + J7OSPI_OPCODE_EXT_LOWER_REG, reg);
    }
    if (ospi->buscfg.cflgs & SNOR_CFGFLGS_DBIOP) {
        reg = in32(ospi->ctrl_vbase + J7OSPI_OPCODE_EXT_LOWER_REG);
        reg &= ~(J7OSPI_WR_INSTR_OPCODE_MASK << J7OSPI_OPCODE_EXT_LOWER_WR_LSB);
        reg |= ((opcode^0xFF) << J7OSPI_OPCODE_EXT_LOWER_WR_LSB);
        out32(ospi->ctrl_vbase + J7OSPI_OPCODE_EXT_LOWER_REG, reg);

      /* WEL opcode . */
		out32(base + J7OSPI_OPCODE_EXT_UPPER_REG, 0x06F90000);
	}
	else
      /* WEL opcode . */
      out32(base + J7OSPI_OPCODE_EXT_UPPER_REG, 0x06060000);


    /* Set auto WEL */
    reg = in32(base + J7OSPI_WR_INSTR);
    /* Command needs auto WEL */
    if (cmd_flgs & SNOR_OPFLGS_AWREN) {
        /* Enable auto WEL */
        if (reg & J7OSPI_WR_INSTR_WEL_DIS) {
            reg &= ~J7OSPI_WR_INSTR_WEL_DIS;
            out32(base + J7OSPI_WR_INSTR, reg);
        }
    } else {
        /* Disable auto WEL */
        if (!(reg & J7OSPI_WR_INSTR_WEL_DIS)) {
            reg |= J7OSPI_WR_INSTR_WEL_DIS;
            out32(base + J7OSPI_WR_INSTR, reg);
        }
    }

    /* Set auto status polling */
    reg = in32(base + J7OSPI_WRITE_COMPLETION_CTRL);
    /* Command needs auto status polling */
    if (cmd_flgs & SNOR_OPFLGS_ASP) {
        /* Enable auto-polling */
        if (reg & J7OSPI_WCC_DISABLE_POLLING) {
            reg &= ~J7OSPI_WCC_DISABLE_POLLING;
        }

        reg &= ~(J7OSPI_WCC_OPCODE_MASK | J7OSPI_WCC_POLLING_BIT_MASK | J7OSPI_WCC_POLLING_POLARITY);
        reg |= (ctrl->chip[cmd->cfg->cs].sp_op << 0) | (ctrl->chip[cmd->cfg->cs].sp_bit << 8) | (ctrl->chip[cmd->cfg->cs].sp_pol << 13);
        out32(base + J7OSPI_WRITE_COMPLETION_CTRL, reg);

        /* Set number of dummy cycles for auto-polling */
        reg = in32(base + J7OSPI_POLLING_FLASH_STATUS);
        if ((ospi->proto & SNOR_BUSPROTO_BUS_MASK) == SNOR_BUSPROTO_8_8_8) { /* Octal mode */
            if ((reg & J7OSPI_DEV_STATUS_NB_DUMMY_MASK) != J7OSPI_DEV_STATUS_NB_DUMMY_OCTAL) {
                reg &= ~(J7OSPI_DEV_STATUS_NB_DUMMY_MASK);
                reg |= J7OSPI_DEV_STATUS_NB_DUMMY_OCTAL;
                out32(base + J7OSPI_POLLING_FLASH_STATUS, reg);
            }
        } else {
            if ((reg & J7OSPI_DEV_STATUS_NB_DUMMY_MASK) != 0) {
                /* Clear dummy cycle field */
                reg &= ~(J7OSPI_DEV_STATUS_NB_DUMMY_MASK);
                out32(base + J7OSPI_POLLING_FLASH_STATUS, reg);
            }
        }

        if (ospi->buscfg.cflgs & SNOR_CFGFLGS_DBOP) {
            reg = in32(base + J7OSPI_OPCODE_EXT_LOWER_REG);
            reg &= ~(J7OSPI_WR_INSTR_OPCODE_MASK << J7OSPI_OPCODE_EXT_LOWER_POLL_LSB);
            reg |= (ctrl->chip[cmd->cfg->cs].sp_op << J7OSPI_OPCODE_EXT_LOWER_POLL_LSB);
            out32(base + J7OSPI_OPCODE_EXT_LOWER_REG, reg);
        }
        if (ospi->buscfg.cflgs & SNOR_CFGFLGS_DBIOP) {
            reg = in32(base + J7OSPI_OPCODE_EXT_LOWER_REG);
            reg &= ~(J7OSPI_WR_INSTR_OPCODE_MASK << J7OSPI_OPCODE_EXT_LOWER_POLL_LSB);
            reg |= ((ctrl->chip[cmd->cfg->cs].sp_op^0xFF) << J7OSPI_OPCODE_EXT_LOWER_POLL_LSB);
            out32(base + J7OSPI_OPCODE_EXT_LOWER_REG, reg);
        }

    } else {
        /* Disable auto-polling */
        if (!(reg & J7OSPI_WCC_DISABLE_POLLING)) {
            reg |= J7OSPI_WCC_DISABLE_POLLING;
            out32(base + J7OSPI_WRITE_COMPLETION_CTRL, reg);
        }
    }
}

static uint32_t calculate_ticks_for_ns(const uint32_t ref_clk_hz,
                        const uint32_t ns_val)
{
    uint32_t    ticks;

    ticks = ref_clk_hz / 1000;  /* kHz */
    ticks = (ticks * ns_val + 1000000 - 1) / 1000000;

    return (ticks);
}

static void j7ospi_readdata_capture(j7ospi_dev_t *const ospi,
                                const int bypass, const uint32_t read_delay, const uint8_t dqs_en)
{
    uint32_t    reg = in32(ospi->ctrl_vbase + J7OSPI_READCAPTURE);

    if (bypass) {
        reg |= (1 << J7OSPI_READCAPTURE_BYPASS_LSB);
    } else {
        reg &= ~(1 << J7OSPI_READCAPTURE_BYPASS_LSB);
    }

    reg |= J7OSPI_READCAPTURE_SAMPLE_EDGE;

    if (dqs_en) {
        reg |= J7OSPI_READCAPTURE_DQS;
    } else {
        reg &= ~(J7OSPI_READCAPTURE_DQS);
    }

    reg &= ~(J7OSPI_READCAPTURE_DELAY_MASK << J7OSPI_READCAPTURE_DELAY_LSB);
    reg |= (read_delay & J7OSPI_READCAPTURE_DELAY_MASK) << J7OSPI_READCAPTURE_DELAY_LSB;

    out32(ospi->ctrl_vbase + J7OSPI_READCAPTURE, reg);
}

static void j7ospi_delay(j7ospi_dev_t *const ospi)
{
    uint32_t    tshsl, tchsh, tslch, tsd2d;
    uint32_t    reg;
    uint32_t    tsclk;

    tsclk = (ospi->refclk + ospi->busclk - 1) / ospi->busclk;

    tshsl = calculate_ticks_for_ns(ospi->refclk, ospi->tshsl_ns);
    /* this particular value must be at least one sclk */
    if (tshsl < tsclk) {
        tshsl = tsclk;
    }

    tchsh = calculate_ticks_for_ns(ospi->refclk, ospi->tchsh_ns);
    tslch = calculate_ticks_for_ns(ospi->refclk, ospi->tslch_ns);
    tsd2d = calculate_ticks_for_ns(ospi->refclk, ospi->tsd2d_ns);

    reg  = (tshsl & J7OSPI_DELAY_TSHSL_MASK) << J7OSPI_DELAY_TSHSL_LSB;
    reg |= (tchsh & J7OSPI_DELAY_TCHSH_MASK) << J7OSPI_DELAY_TCHSH_LSB;
    reg |= (tslch & J7OSPI_DELAY_TSLCH_MASK) << J7OSPI_DELAY_TSLCH_LSB;
    reg |= (tsd2d & J7OSPI_DELAY_TSD2D_MASK) << J7OSPI_DELAY_TSD2D_LSB;

    out32(ospi->ctrl_vbase + J7OSPI_DELAY, reg);
}

static uint64_t j7ospi_get_refclk(const j7ospi_dev_t *const ospi)
{
#ifdef  J7OSPI_UDMA_SUPPORT // This flag tells us PSDKQA is installed
    struct tisci_msg_get_freq_req reqFreq ;
    struct tisci_msg_get_freq_resp const respFreq = {0};

    /* Fill in payload */
    snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: J7OSPI_FREQ_DEV = %d, J7OSPI_FREQ_CLK = %d", __func__, J7OSPI_FREQ_DEV, J7OSPI_FREQ_CLK);
    reqFreq.device = J7OSPI_FREQ_DEV;

    if (J7OSPI_FREQ_CLK >= 255U) {
        reqFreq.clk32 = J7OSPI_FREQ_CLK;
        reqFreq.clk   = (uint8_t) 255U;
    } else {
        reqFreq.clk   = (uint8_t) J7OSPI_FREQ_CLK;
    }

    /* Create Request message */
    const Sciclient_ReqPrm_t      reqPrm = {
        .messageType = TISCI_MSG_GET_FREQ,
        .flags = TISCI_MSG_FLAG_AOP,
        .pReqPayload = (uint8_t *) &reqFreq,
        .reqPayloadSize = sizeof(reqFreq),
        .timeout = SCICLIENT_SERVICE_WAIT_FOREVER,
        .forwardStatus = 0
    };

    /* Create response buffer */
    Sciclient_RespPrm_t           respPrm = {
        .flags = 0,
        .pRespPayload = (uint8_t *) &respFreq,
        .respPayloadSize = sizeof (respFreq)
    };

    /* Send request */
    if (Sciclient_service(&reqPrm, &respPrm) == CSL_PASS) {
        if (respPrm.flags == TISCI_MSG_FLAG_ACK) {
            return (respFreq.freq_hz);
        }
    }

    snor_slogf(_SLOG_WARNING, ospi->ctrl.verbosity, 0,
                    "%s, failed to read OSPI reference clock, use default clock rate(166.7MHz)", __func__);
#endif

    return ((uint64_t)J7OSPI_RCLK);
}

static void j7ospi_config_baudrate_div(j7ospi_dev_t *const ospi, uint32_t clk)
{
    uint32_t    reg, divisor;

    if (clk == ospi->busclk) return;
    if (clk == 0) {
        clk = ospi->busclk;
    }

    if (ospi->refclk == 0) {
        ospi->refclk = (uint32_t)j7ospi_get_refclk(ospi);
    }

    /* calculate the baudrate divisor */
    divisor = ((ospi->refclk + clk - 1) / clk) >> 1;
    if (divisor > 0) {
        if (--divisor > J7OSPI_CONFIG_BAUD_MASK) {
            divisor = J7OSPI_CONFIG_BAUD_MASK;
        }
    }

    snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 2,
                    "%s, set data rate to %dHz", __func__, ospi->refclk / (divisor + 1) / 2);

    reg = in32(ospi->ctrl_vbase + J7OSPI_CONFIG);
    reg &= ~(J7OSPI_CONFIG_BAUD_MASK << J7OSPI_CONFIG_BAUD_LSB);
    reg |= (divisor & J7OSPI_CONFIG_BAUD_MASK) << J7OSPI_CONFIG_BAUD_LSB;
    out32(ospi->ctrl_vbase + J7OSPI_CONFIG, reg);

    ospi->busclk = clk;
}

static void j7ospi_dac_enable(const j7ospi_dev_t *const ospi, const uint8_t enable)
{
    const uintptr_t base = ospi->ctrl_vbase;
    uint32_t    reg;

    reg = in32(base + J7OSPI_CONFIG);
    if (enable) {
        reg |= J7OSPI_CONFIG_ENB_DIR_ACC_CTRL;
    } else {
        reg &= ~J7OSPI_CONFIG_ENB_DIR_ACC_CTRL;
    }
    out32(base + J7OSPI_CONFIG, reg);
}

static void j7ospi_controller_init(j7ospi_dev_t *const ospi)
{
    const uintptr_t base = ospi->ctrl_vbase;
    uint32_t        reg;

    /* Disable controller */
    j7ospi_controller_enable(ospi, 0);

    /* Reset all configure bits */
    out32(ospi->ctrl_vbase + J7OSPI_CONFIG, 0x01u << J7OSPI_CONFIG_IDLE_LSB);

    /* Enable auto WEL */
    reg = in32(base + J7OSPI_WR_INSTR);
    if (reg & J7OSPI_WR_INSTR_WEL_DIS) {
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Enable auto WEL", __func__);
        reg &= ~J7OSPI_WR_INSTR_WEL_DIS;
        out32(base + J7OSPI_WR_INSTR, reg);
    }
    snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: J7OSPI_WR_INSTR: 0x%x", __func__, in32(base + J7OSPI_WR_INSTR));

    /* Enable auto status polling */
    reg = in32(base + J7OSPI_WRITE_COMPLETION_CTRL);
    if (reg & J7OSPI_WCC_DISABLE_POLLING) {
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Enable auto status polling", __func__);
        reg &= ~J7OSPI_WCC_DISABLE_POLLING;
    }

    /* Set auto status polling count */
    reg &= ~(J7OSPI_WCC_POLL_COUNT_MASK);
    reg |= J7OSPI_WCC_POLL_COUNT_MIN;
    out32(base + J7OSPI_WRITE_COMPLETION_CTRL, reg);
    snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: J7OSPI_WRITE_COMPLETION_CTRL: 0x%x", __func__, in32(base + J7OSPI_WRITE_COMPLETION_CTRL));

    /* Configure the remap address register, no remap */
    out32(base + J7OSPI_REMAP, 0);

    /* Disable all interrupts. */
    out32(base + J7OSPI_IRQMASK, 0);

    /* Configure the SRAM split to 1:1 . */
    out32(base + J7OSPI_SRAMPARTITION, ospi->fifo_depth / 2);

    /* WEL opcode . */
    if (ospi->buscfg.cflgs & SNOR_CFGFLGS_DBIOP) {
      out32(base + J7OSPI_OPCODE_EXT_UPPER_REG, 0x06F90000);
	}
	else
      out32(base + J7OSPI_OPCODE_EXT_UPPER_REG, 0x06060000);

    /* Load indirect trigger address. */
    if (ospi->dma_enable) {
        out32(base + J7OSPI_INDIRECTTRIGGER, 0x10000000);
    } else {
        out32(base + J7OSPI_INDIRECTTRIGGER, 0);
    }

    /* Program read watermark -- 1/2 of the FIFO. */
    out32(base + J7OSPI_INDIRECTRDWATERMARK, ospi->fifo_depth / 2 / 2);
    /* Program write watermark -- 1/8 of the FIFO. */
    out32(base + J7OSPI_INDIRECTWRWATERMARK, ospi->fifo_depth / 2 / 4);

    /* Enable Direct Access Controller if DMA enabled */
    j7ospi_dac_enable(ospi, ospi->dma_enable);

    /* Configure bus clock */
    j7ospi_config_baudrate_div(ospi, 0);
    j7ospi_delay(ospi);
    j7ospi_readdata_capture(ospi, !ospi->rclk_en, ospi->read_delay, ospi->dqs_en);

    j7ospi_controller_enable(ospi, 1);
}

static int j7ospi_command_read(j7ospi_dev_t *const ospi,
        const snor_cmd_t *const cmd, uint8_t *rxbuf, const uint32_t n_rx)
{
    const uintptr_t  base   = ospi->ctrl_vbase;
    const uint8_t    opcode = cmd->op->opcode;
    const uint8_t    dcycle = cmd->op->dcycle;
    uint32_t    reg;
    uint32_t    read_len;
    int         status;

    if ((n_rx == 0) || (n_rx > J7OSPI_STIG_DATA_LEN_MAX) || (rxbuf == NULL)) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "Invalid length, len %d rxbuf 0x%p", n_rx, rxbuf);
        return (EINVAL);
    }

    reg = (uint32_t)(opcode << J7OSPI_CMDCTRL_OPCODE_LSB);
    reg |= (0x1 << J7OSPI_CMDCTRL_RD_EN_LSB);
    /* 0 means 1 byte. */
    reg |= (((n_rx - 1) & J7OSPI_CMDCTRL_RD_BYTES_MASK) << J7OSPI_CMDCTRL_RD_BYTES_LSB);
    /* dummy cycle */
    reg |= (dcycle & J7OSPI_CMDCTRL_DUMMY_MASK) << J7OSPI_CMDCTRL_DUMMY_LSB;

    if (cmd->op->adrlen > 0) {
        reg |= (1 << J7OSPI_CMDCTRL_ADDR_EN_LSB);
        reg |= ((cmd->op->adrlen - 1) & J7OSPI_CMDCTRL_ADD_BYTES_MASK) << J7OSPI_CMDCTRL_ADD_BYTES_LSB;
        out32(ospi->ctrl_vbase + J7OSPI_CMDADDRESS, cmd->addr);
    }

    status = j7ospi_exec_flash_cmd(ospi, reg);
    if (status != EOK) return (status);

    reg = in32(base + J7OSPI_CMDREADDATALOWER);

    /* Put the read value into rx_buf */
    read_len = (n_rx > 4) ? 4 : n_rx;
    memcpy(rxbuf, &reg, read_len);

    if (n_rx > 4) {
        rxbuf += 4;
        reg = in32(base + J7OSPI_CMDREADDATAUPPER);

        read_len = n_rx - read_len;
        read_len = (read_len > 4) ? 4 : read_len;
        memcpy(rxbuf, &reg, read_len);
    }

    return (EOK);
}

static int j7ospi_command_write(j7ospi_dev_t *const ospi, const snor_cmd_t *const cmd,
                                   const uint8_t *const txbuf, const unsigned n_tx)
{
    const uintptr_t   base = ospi->ctrl_vbase;
    uint32_t    reg;
    uint64_t    data;

    if ((n_tx > J7OSPI_STIG_DATA_LEN_MAX) || (n_tx && !txbuf)) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "Invalid length, len %d rxbuf 0x%p", n_tx, txbuf);
        return (EINVAL);
    }

    reg = (uint32_t)(cmd->op->opcode << J7OSPI_CMDCTRL_OPCODE_LSB);
    if (cmd->op->adrlen > 0) {
        reg |= (1 << J7OSPI_CMDCTRL_ADDR_EN_LSB);
        reg |= ((cmd->op->adrlen - 1) & J7OSPI_CMDCTRL_ADD_BYTES_MASK) << J7OSPI_CMDCTRL_ADD_BYTES_LSB;
        out32(ospi->ctrl_vbase + J7OSPI_CMDADDRESS, cmd->addr);
    }
    if (n_tx) {
        reg |= (0x1 << J7OSPI_CMDCTRL_WR_EN_LSB);
        reg |= ((n_tx - 1) & J7OSPI_CMDCTRL_WR_BYTES_MASK) << J7OSPI_CMDCTRL_WR_BYTES_LSB;
        data = 0;
        memcpy(&data, txbuf, n_tx);
        out32(base + J7OSPI_CMDWRITEDATALOWER, (uint32_t)data);
        if (n_tx > 4) {
            out32(base + J7OSPI_CMDWRITEDATAUPPER, (uint32_t)(data >> 32));
        }
    }

    return j7ospi_exec_flash_cmd(ospi, reg);
}

#ifdef  J7OSPI_UDMA_SUPPORT
static int j7ospi_phy_pipeline_enable(const j7ospi_dev_t *const ospi, const int enable)
{
    uint32_t        reg;

    uintptr_t const base = ospi->ctrl_vbase;

    /* Disable PHY pipeline */
    reg = in32(base + J7OSPI_CONFIG);

    if (enable != 0) {
        reg |= J7OSPI_CONFIG_PHY_PIPELINE;
    } else {
        reg &= ~J7OSPI_CONFIG_PHY_PIPELINE;
    }

    out32(base + J7OSPI_CONFIG, reg);

    return EOK;
}

static void j7ospi_phy_enable(j7ospi_dev_t *const ospi, const int enable)
{
    const uintptr_t   base = ospi->ctrl_vbase;
    uint32_t    reg;

    if (ospi->calibrating == true) {
        return;
    }

    reg = in32(base + J7OSPI_CONFIG);

    if (enable) {
        reg |= J7OSPI_CONFIG_PHY;
    } else {
        reg &= ~(J7OSPI_CONFIG_PHY);
    }

    out32(base + J7OSPI_CONFIG, reg);

    if (ospi->dqs_en && enable) {
        j7ospi_readdata_capture(ospi, !ospi->rclk_en, ospi->read_delay, 1);
    } else {
        j7ospi_readdata_capture(ospi, !ospi->rclk_en, ospi->read_delay, 0);
    }

    if (j7ospi_wait_idle(ospi) != EOK) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: wait idle failed", __func__);
    }
}

static void j7ospi_phy_basic_config(const j7ospi_dev_t *const ospi)
{
    uintptr_t const base = ospi->ctrl_vbase;
    uint32_t        reg;

    reg = in32(base + J7OSPI_PHY_MASTER_CONTROL);

    /* Select the number of delay element to be inserted between
     * phase detect flip-flops.
     */
    reg &= ~(J7OSPI_PHY_MASTER_PHASE_DETECT_SELECTOR_MASK);
    reg |= ((OSPI_PHASE_DETECT_DLL_NUM_DELAY_ELEMENT(ospi->phase_delay) << J7OSPI_PHY_MASTER_PHASE_DETECT_SELECTOR_SHIFT) &
        J7OSPI_PHY_MASTER_PHASE_DETECT_SELECTOR_MASK);

    /* Configure PHY Control mode */
    reg &= ~(J7OSPI_PHY_MASTER_BYPASS_MODE);
    if (ospi->phy_mode == J7OSPI_PHY_MODE_BYPASS) {
        reg |= J7OSPI_PHY_MASTER_BYPASS_MODE;
    }

    out32(base + J7OSPI_PHY_MASTER_CONTROL, reg);
}

static int j7ospi_direct_read_execute_dma(j7ospi_dev_t *const ospi, uint8_t *const buf, const uint32_t from, const uint32_t len)
{
    int     ret;

    if (ospi->use_phy) {
        j7ospi_phy_enable(ospi, 1);
    }

    ret = j7ospi_wait_idle(ospi);
    if (ret == EOK) {
        // PHY pipeline needs 16B alignment
        const uint32_t align   = from & 0x0f;
        const uint32_t readlen = (len + align + 15) & 0xfffffff0;
        const paddr_t  src = ospi->mem_pbase + (from & ~0x0fu);
        ret = j7ospi_udma_xfer(ospi, src, (paddr_t)ospi->p_buf, readlen);
        if (ret == EOK) {
            memcpy(buf, (uint8_t *)ospi->v_buf + align, (size_t)len);
        }

        ret = j7ospi_wait_idle(ospi);
    }

    if (ospi->use_phy) {
        j7ospi_phy_enable(ospi, 0);
    }

    if (ret == EOK) {
        return (len);
    } else {
        return (-1);
    }
}
#endif

static void j7ospi_phy_resync_dll(j7ospi_dev_t *const ospi)
{
    uintptr_t const base = ospi->ctrl_vbase;
    uint32_t        reg;

    j7ospi_wait_idle(ospi);

    j7ospi_controller_enable(ospi, 0);

    /* Clear the delay line resync bit */
    reg = in32(base + J7OSPI_PHY_CONFIG);
    reg &= ~(J7OSPI_PHY_CONFIG_DLL_RESYNC);
    out32(base + J7OSPI_PHY_CONFIG, reg);

    /* Reset DLL in master mode */
    reg = in32(base + J7OSPI_PHY_CONFIG);
    reg &= ~(J7OSPI_PHY_CONFIG_DLL_RESET);
    out32(base + J7OSPI_PHY_CONFIG, reg);

    /* Set Initial delay for the master DLL */
    reg = in32(base + J7OSPI_PHY_MASTER_CONTROL);
    reg &= ~(J7OSPI_PHY_MASTER_CONTROL_INIT_DELAY_MASK);
    reg |= 0x10U;
    out32(base + J7OSPI_PHY_MASTER_CONTROL, reg);

    /* DLL out of reset */
    reg = in32(base + J7OSPI_PHY_CONFIG);
    reg |= J7OSPI_PHY_CONFIG_DLL_RESET;
    out32(base + J7OSPI_PHY_CONFIG, reg);

    /* Wait DLL lock done */
    j7ospi_wait_for_bit(base + J7OSPI_DLL_OBS_LOWER, J7OSPI_DLL_OBS_LOWER_DLL_LOCK, 0);

    /* Wait DLL loopback lock done */
    j7ospi_wait_for_bit(base + J7OSPI_DLL_OBS_LOWER, J7OSPI_DLL_OBS_LOWER_LOOPBACK_LOCK, 0);

    /* Resync the Slave DLLs */
    reg = in32(base + J7OSPI_PHY_CONFIG);
    reg |= J7OSPI_PHY_CONFIG_DLL_RESYNC;
    out32(base + J7OSPI_PHY_CONFIG, reg);

    j7ospi_controller_enable(ospi, 1);
}

static void j7ospi_set_tx_dll(const j7ospi_dev_t *const ospi, const uint32_t dll)
{
    uint32_t        reg;
    uintptr_t const base = ospi->ctrl_vbase;

    reg = in32(base + J7OSPI_PHY_CONFIG);
    reg &= ~(J7OSPI_PHY_CONFIG_TX_DLL_MASK);
    reg |= ((dll << J7OSPI_PHY_CONFIG_TX_DLL_SHIFT) &
        J7OSPI_PHY_CONFIG_TX_DLL_MASK);

    out32(base + J7OSPI_PHY_CONFIG, reg);
}

static void j7ospi_set_rx_dll(const j7ospi_dev_t *const ospi, const uint32_t dll)
{
    uint32_t        reg;
    uintptr_t const base = ospi->ctrl_vbase;

    reg = in32(base + J7OSPI_PHY_CONFIG);

    reg &= ~(J7OSPI_PHY_CONFIG_RX_DLL_MASK);
    reg |= (dll & J7OSPI_PHY_CONFIG_RX_DLL_MASK);

    out32(base + J7OSPI_PHY_CONFIG, reg);
}

static void j7ospi_phy_apply_setting(j7ospi_dev_t *ospi, const j7_phy_setting*const  phy)
{
    uint32_t        reg;
    uintptr_t const base = ospi->ctrl_vbase;

    /* Set the read delay */
    ospi->read_delay = phy->read_delay;
    reg = in32(base + J7OSPI_READCAPTURE);
    reg &= ~(J7OSPI_READCAPTURE_DELAY_MASK << J7OSPI_READCAPTURE_DELAY_LSB);
    reg |= (ospi->read_delay & J7OSPI_READCAPTURE_DELAY_MASK) << J7OSPI_READCAPTURE_DELAY_LSB;
    out32(base + J7OSPI_READCAPTURE, reg);

    /* Set the PHY rx_dll and tx_dll */
    const int dtr_enable = ((in32(base + J7OSPI_CONFIG) & J7OSPI_CONFIG_DTR_PROTO) == 0) ? 0 : 1;

    /* Sampled on rising edge of clock */
    reg = in32(base + J7OSPI_READCAPTURE);
    reg |= J7OSPI_READCAPTURE_SAMPLE_EDGE;
    out32(base + J7OSPI_READCAPTURE, reg);

    /* If DTR is enabled, enable DQS */
    reg = in32(base + J7OSPI_READCAPTURE);
    if (dtr_enable == 1) {
        reg |= J7OSPI_READCAPTURE_DQS;
    } else {
        reg &= ~(J7OSPI_READCAPTURE_DQS);
    }
    out32(base + J7OSPI_READCAPTURE, reg);

    if(ospi->phy_enable == J7OSPI_PHY_DDR_TUNE) {
        /* Configure PHY Control mode */
        reg = in32(base + J7OSPI_PHY_MASTER_CONTROL);
        reg &= ~(J7OSPI_PHY_MASTER_BYPASS_MODE);
        if (ospi->phy_mode == J7OSPI_PHY_MODE_BYPASS) {
            reg |= J7OSPI_PHY_MASTER_BYPASS_MODE;
        }
        out32(base + J7OSPI_PHY_MASTER_CONTROL, reg);
    }

    /* Set TX DLL delay */
    j7ospi_set_tx_dll(ospi, phy->tx_dll);

    /* Set RX DLL delay */
    j7ospi_set_rx_dll(ospi, phy->rx_dll);

    /* Re-sync DLL */
    j7ospi_phy_resync_dll(ospi);
}

static float j7ospi_phy_avg_vtm_temp(const j7ospi_dev_t *const ospi, const uint32_t vtm125)
{
    uintptr_t   vbusp_cfg1_base;
    uintptr_t   vbusp_cfg2_base;
    uintptr_t    stat_reg; /* VTM temperature sensor status register addr */
    uintptr_t    ctrl_reg; /* VTM temperature sensor control register addr */
    double      avg = 0.0;
    double      m = 0.0;
    double      b = 0.0;
    uint32_t    temp;
    uint32_t    j;
    uint32_t    reg;

    vbusp_cfg1_base = mmap_device_io(J7OSPI_WKUP_VTM0_MMR_VBUSP_CFG1_SIZE, J7OSPI_WKUP_VTM0_MMR_VBUSP_CFG1_BASE);
    if (vbusp_cfg1_base == (uintptr_t)MAP_FAILED) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "map VBUSP CFG1 failed");
        return (errno);
    }

    vbusp_cfg2_base = mmap_device_io(J7OSPI_WKUP_VTM0_MMR_VBUSP_CFG2_SIZE, J7OSPI_WKUP_VTM0_MMR_VBUSP_CFG2_BASE);
    if (vbusp_cfg2_base == (uintptr_t)MAP_FAILED) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "map VBUSP CFG2 failed");
        munmap_device_io(vbusp_cfg1_base, J7OSPI_WKUP_VTM0_MMR_VBUSP_CFG1_SIZE);
        return (errno);
    }

    stat_reg = vbusp_cfg1_base + J7OSPI_VTM_VTM_TMPSENS_STAT;
    ctrl_reg = vbusp_cfg2_base + J7OSPI_VTM_VTM_TMPSENS_CTRL;

    /* Take the average VTM value */
    for (j = 0; j < 5U; j++) {
        const uintptr_t ctrl = (uintptr_t)(ctrl_reg + (j * 0x20U));
        const uintptr_t stat_val = (uintptr_t)(stat_reg + (j * 0x20U));

        /* Setting sensor to continous readout mode. */
        reg = in32(ctrl);
        reg &= ~(J7OSPI_VTM_VTM_TMPSENS_CTRL_CONT);
        reg |= J7OSPI_VTM_VTM_TMPSENS_CTRL_CONT;
        out32(ctrl, reg);

        reg = in32(ctrl);
        reg &= ~(J7OSPI_VTM_VTM_TMPSENS_CTRL_CONT);
        reg |= J7OSPI_VTM_VTM_TMPSENS_CTRL_CONT;
        out32(ctrl, reg);

        /* Read from pStat register to get temp */
        temp = in32(stat_val) & J7OSPI_VTM_VTM_TMPSENS_STAT_DATA_OUT_MASK;

        /* Accumlate a number to average */
        avg += (double)temp;
    }

    avg = avg / 5U;

    /* Convert to a temperature */
    m = (double)(160U / (vtm125 - 43U));
    b = (125.0 / m) - (double)vtm125;
    avg = (m * (avg + b));

    if(isnan(avg)) {
        /*
         * Assume room temperature if we couldn't get it from
         * the thermal sensor.
         */
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "Unable to get temperature. Assuming room temperature %uC", J7OSPI_PHY_DEFAULT_TEMP);
        avg = (double)J7OSPI_PHY_DEFAULT_TEMP;
    }

    munmap_device_io(vbusp_cfg1_base, J7OSPI_WKUP_VTM0_MMR_VBUSP_CFG1_SIZE);
    munmap_device_io(vbusp_cfg2_base, J7OSPI_WKUP_VTM0_MMR_VBUSP_CFG2_SIZE);

    return avg;
}

static int j7ospi_phy_check_pattern(j7ospi_dev_t *const ospi)
{
    uint8_t     read_data[J7OSPI_TUNING_PATTERN_SIZE];
    int         ret = EOK;
    snor_ctrl_t *const snor = (snor_ctrl_t *)ospi;
    snor_chip_t *chip = &snor->chip[ospi->current_cs];
    snor_cmd_t  cmd;

    static const uint8_t phy_tuning_pattern[J7OSPI_TUNING_PATTERN_SIZE] = {
    0xFE, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0xFE, 0xFE, 0x01, 0x01,
    0x01, 0x01, 0x00, 0x00, 0xFE, 0xFE, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
    0x00, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFE, 0xFE, 0xFF, 0x01,
    0x01, 0x01, 0x01, 0x01, 0xFE, 0x00, 0xFE, 0xFE, 0x01, 0x01, 0x01, 0x01, 0xFE,
    0x00, 0xFE, 0xFE, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0xFE, 0xFE,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0xFE, 0xFE, 0xFF, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x00, 0xFE, 0xFE, 0xFE, 0x01, 0x01, 0x01, 0x01, 0x00, 0xFE, 0xFE, 0xFE,
    0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF,
    0xFF, 0x00, 0xFE, 0xFE, 0xFE, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFE, 0xFE,
    0xFE, 0xFE, 0x01, 0x01, 0x01, 0x01, 0xFE, 0xFE, 0xFE, 0xFE, 0x01,
    };

    SNOR_SET_CMD(cmd, &chip->op_rd, &chip->rdcfg, ospi->pattern_offset & ~1);

    if (j7ospi_read(snor, &cmd, read_data, J7OSPI_TUNING_PATTERN_SIZE) != J7OSPI_TUNING_PATTERN_SIZE) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: unaligned read failed", __func__);
        return (EIO);
    }

    if (memcmp(read_data, phy_tuning_pattern, J7OSPI_TUNING_PATTERN_SIZE)) {
        ret = EIO;
    }

    return (ret);
}

static void j7ospi_find_rx_low_otp1_tune(j7ospi_dev_t *const ospi, const j7_phy_setting *const start, j7_phy_setting *result)
{
    int ret = EOK;

    result->tx_dll = start->tx_dll;
    result->rx_dll = start->rx_dll;
    result->read_delay = start->read_delay;

    j7ospi_phy_apply_setting(ospi, result);

    ret = j7ospi_phy_check_pattern(ospi);

    while(ret != EOK) {
        result->rx_dll += J7OSPI_RX_TX_DLL_SEARCH_STEP;
        if(result->rx_dll > J7OSPI_RX_LOW_SEARCH_END) {
            result->rx_dll = J7OSPI_RX_TX_DLL_MAX_STEP;
            break;
        }
        j7ospi_phy_apply_setting(ospi, result);
        ret = j7ospi_phy_check_pattern(ospi);
    }
}

static void j7ospi_find_rx_high_otp1_tune(j7ospi_dev_t *const ospi, const j7_phy_setting *const start, j7_phy_setting *result)
{
    int ret = EOK;

    result->tx_dll = start->tx_dll;
    result->rx_dll = start->rx_dll;
    result->read_delay = start->read_delay;

    j7ospi_phy_apply_setting(ospi, result);

    ret = j7ospi_phy_check_pattern(ospi);

    while(ret != EOK) {
        result->rx_dll -= J7OSPI_RX_TX_DLL_SEARCH_STEP;
        if(result->rx_dll < J7OSPI_RX_HIGH_SEARCH_START_OTP1) {
            result->rx_dll = J7OSPI_RX_TX_DLL_MAX_STEP;
            break;
        }
        j7ospi_phy_apply_setting(ospi, result);
        ret = j7ospi_phy_check_pattern(ospi);
    }
}

static void j7ospi_find_tx_low_otp1_tune(j7ospi_dev_t *const ospi, const j7_phy_setting *const start, j7_phy_setting *result)
{
    int ret = EOK;

    result->tx_dll = start->tx_dll;
    result->rx_dll = start->rx_dll;
    result->read_delay = start->read_delay;

    j7ospi_phy_apply_setting(ospi, result);

    ret = j7ospi_phy_check_pattern(ospi);

    while(ret != EOK) {
        result->tx_dll += J7OSPI_RX_TX_DLL_SEARCH_STEP;
        if(result->tx_dll > J7OSPI_TX_LOW_SEARCH_END) {
            result->tx_dll = J7OSPI_RX_TX_DLL_MAX_STEP;
            break;
        }
        j7ospi_phy_apply_setting(ospi, result);
        ret = j7ospi_phy_check_pattern(ospi);
    }
}

static void j7ospi_find_tx_high_otp1_tune(j7ospi_dev_t *const ospi, const j7_phy_setting *const start, j7_phy_setting *result)
{
    int ret = EOK;

    result->tx_dll = start->tx_dll;
    result->rx_dll = start->rx_dll;
    result->read_delay = start->read_delay;

    j7ospi_phy_apply_setting(ospi, result);
    ret = j7ospi_phy_check_pattern(ospi);

    while(ret != EOK) {
        result->tx_dll -= J7OSPI_RX_TX_DLL_SEARCH_STEP;
        if(result->tx_dll < J7OSPI_TX_HIGH_SEARCH_START_OTP1) {
            result->tx_dll = J7OSPI_RX_TX_DLL_MAX_STEP;
            break;
        }
        j7ospi_phy_apply_setting(ospi, result);
        ret = j7ospi_phy_check_pattern(ospi);
    }
}

static int j7ospi_phy_find_otp1(j7ospi_dev_t *const ospi, j7_phy_setting *otp)
{
    int ret = EOK;
    j7_phy_setting search_point;
    j7_phy_setting bottom_left = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0}, top_right = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting gap_low = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0}, gap_high = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting rx_low = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0}, rx_high = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting tx_low = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0}, tx_high = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting backup_point = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0}, backup_corner_point = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting sec_rx_low = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0}, sec_rx_high = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    float slope;

    /*
     * Finding rx_dll fails at some of the tx_dll values based on the HW platform.
     * A window of tx_dll values is used to find the rx_dll without errors.
     * This can increase the number of CPU cycles taken for the PHY tuning
     * in the cases where more tx_dll values need to be parsed to find a stable rx_dll.
     */

    /***************************** GOLDEN Primary Rx_Low Search **************/
    /*
     * To find the rx_dll boundaries, we fix a valid tx_dll and search through rx_dll range, read_delay values
     * As we are not sure of a valid tx_dll we use a window of tx_dll values to find the rx_dll boundaries.
     */

    search_point.tx_dll = J7OSPI_TX_DLL_LOW_WINDOW_START;

    while(search_point.tx_dll <= J7OSPI_TX_DLL_LOW_WINDOW_END) {
        search_point.read_delay = J7OSPI_RD_DELAY_MIN;
        search_point.rx_dll = J7OSPI_RX_LOW_SEARCH_START;
        j7ospi_find_rx_low_otp1_tune(ospi, &search_point, &rx_low);

        while(rx_low.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            search_point.read_delay++;
            if(search_point.read_delay > J7OSPI_RD_DELAY_MAX) {
                if(search_point.tx_dll >= J7OSPI_TX_DLL_LOW_WINDOW_END) {
                    snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Primary Rx_Low", __func__);
                    return EIO;
                } else {
                    break;
                }
            }
            j7ospi_find_rx_low_otp1_tune(ospi, &search_point, &rx_low);
        }

        if(rx_low.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) {
            snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Primary Rx_Low: rx_dll:%u tx_dll:%u read_delay:%u", __func__, rx_low.rx_dll, rx_low.tx_dll, rx_low.read_delay);
            break;
        }

        search_point.tx_dll += J7OSPI_RX_TX_DLL_SEARCH_STEP;
    }

    /***************************** GOLDEN Secondary Rx_Low Search *****************************/
    /* Search for one more rx_low at different tx_dll*/
    if(search_point.tx_dll <= (J7OSPI_TX_DLL_LOW_WINDOW_END - J7OSPI_TX_DLL_SEARCH_OFFSET)) {
        search_point.tx_dll += J7OSPI_TX_DLL_SEARCH_OFFSET;
    } else {
        search_point.tx_dll = J7OSPI_TX_DLL_LOW_WINDOW_END;
    }

    search_point.read_delay = J7OSPI_RD_DELAY_MIN;
    search_point.rx_dll   = J7OSPI_RX_LOW_SEARCH_START;
    j7ospi_find_rx_low_otp1_tune(ospi, &search_point, &sec_rx_low);
    while(sec_rx_low.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
        search_point.read_delay++;  /* For each tx_dll in the window, go through all the valid read_delays until we find the rx_low */
        if(search_point.read_delay > J7OSPI_RD_DELAY_MAX) {
            if(search_point.tx_dll >= J7OSPI_TX_DLL_LOW_WINDOW_END) {
                snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Secondary Rx_Low", __func__);
                return EIO; /* Not able to find rx_low as there is no valid tx_dll in the tx_dll window */
            } else {
                break;
            }
        }
        j7ospi_find_rx_low_otp1_tune(ospi, &search_point, &sec_rx_low);
    }

    snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Secondary Rx_Low: rx_dll:%u tx_dll:%u read_delay:%u", __func__, sec_rx_low.rx_dll, sec_rx_low.tx_dll, sec_rx_low.read_delay);

    /*
     * Pick Minimum value of rx_dll between rx_low and sec_rx_low
     * Pick Minimum value of read_delay between rx_low and sec_rx_low
     */

    rx_low.rx_dll = min(rx_low.rx_dll, sec_rx_low.rx_dll);
    rx_low.read_delay = min(rx_low.read_delay, sec_rx_low.read_delay);

    /*
     * Reset the search point tx_dll to continue the Rx_High search
     */
    search_point.tx_dll = rx_low.tx_dll;

    /***************************** GOLDEN Primary Rx_High Search *********************/
    /*
     * To find rx_high we use the tx_dll values of rx_low
     * Start the read_delay (Read delay) from maximum and decrement it.
     * As these are valid values and rx_high read_delay is always >= rx_low read_delay
     */

    search_point.rx_dll = J7OSPI_RX_HIGH_SEARCH_END_OTP1;
    search_point.read_delay = J7OSPI_RD_DELAY_MAX;

    j7ospi_find_rx_high_otp1_tune(ospi, &search_point, &rx_high);

    while(rx_high.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
        search_point.read_delay--;
        if(search_point.read_delay < J7OSPI_RD_DELAY_MIN) {
            ret = EIO;
            snor_slogf(_SLOG_WARNING, ospi->ctrl.verbosity, 2, "%s: Failed to find Primary Rx_High", __func__);
            break;
        }
        j7ospi_find_rx_high_otp1_tune(ospi, &search_point, &rx_high);
    }

    if(rx_high.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) {
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Primary Rx_High: rx_dll:%u tx_dll:%u read_delay:%u", __func__, rx_high.rx_dll, rx_high.tx_dll, rx_high.read_delay);
    }

    /***************************** GOLDEN Secondary Rx_High Search *********************/
    /*
     * To find Secondary rx_high we use the tx_dll + Search_offset value of rx_low
     * Start the read_delay from maximum and decrement it.
     * As these are valid values and rx_high read_delay is always >= rx_low read_delay
     */
    if(search_point.tx_dll <= (J7OSPI_TX_DLL_LOW_WINDOW_END - J7OSPI_TX_DLL_SEARCH_OFFSET)) {
        search_point.tx_dll += J7OSPI_TX_DLL_SEARCH_OFFSET;
    } else {
        search_point.tx_dll = J7OSPI_TX_DLL_LOW_WINDOW_END;
    }

    search_point.rx_dll = J7OSPI_RX_HIGH_SEARCH_END_OTP1;
    search_point.read_delay = J7OSPI_RD_DELAY_MAX;

    j7ospi_find_rx_high_otp1_tune(ospi, &search_point, &sec_rx_high);

    while(sec_rx_high.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
        search_point.read_delay--;
        if(search_point.read_delay < J7OSPI_RD_DELAY_MIN) {
            snor_slogf(_SLOG_WARNING, ospi->ctrl.verbosity, 2, "%s: Failed to find Secondary Rx_High", __func__);
            ret = EIO;
            break;
            /*
             * If we don't find a valid Secondary Rx_High, Don't return from tuning function
             * Check whether we have a valid Primary Rx_High and then take decision.
             */
        }
        j7ospi_find_rx_high_otp1_tune(ospi, &search_point, &sec_rx_high);
    }

    if(sec_rx_high.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) {
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Secondary Rx_High: rx_dll:%u tx_dll:%u read_delay:%u", __func__, sec_rx_high.rx_dll, sec_rx_high.tx_dll, sec_rx_high.read_delay);
    }

    /*
     * Compare the Primary and Secondary point
     * Pick the point which has passing maximum rx_dll
    */
    if(sec_rx_high.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) {
        if(rx_high.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            rx_high = sec_rx_high;
        } else {
            if(sec_rx_high.rx_dll > rx_high.rx_dll) {
                rx_high = sec_rx_high;
            }
        }
    } else {
        if(rx_high.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Rx_High", __func__);
            return EIO;
        }
    }

    /*
     * Check a different point if the rx_low and rx_high are on the same read_delay.
     * This avoids mistaking the metastability gap for an rx_dll boundary
     */
    if(rx_low.read_delay == rx_high.read_delay) {
        /***************************** BACKUP Primary Rx_Low Search *********************/
        /*
         * Find the rx_dll boundaries using the tx_dll window at the higher end .
         * we start the window_end and decrement the tx_dll value until we find the valid point.
         */

        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: rx_low and rx_high at the same read delay.", __func__);
        search_point.tx_dll = J7OSPI_TX_DLL_HIGH_WINDOW_END_OTP1;

        /* Find rx_dll Min */
        while(search_point.tx_dll >= J7OSPI_TX_DLL_HIGH_WINDOW_START_OTP1) {
            search_point.read_delay = J7OSPI_RD_DELAY_MIN;
            search_point.rx_dll = J7OSPI_RX_LOW_SEARCH_START;
            j7ospi_find_rx_low_otp1_tune(ospi, &search_point, &backup_point);

            while(backup_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
                search_point.read_delay++;
                if(search_point.read_delay > J7OSPI_RD_DELAY_MAX) {
                    if(search_point.tx_dll <= J7OSPI_TX_DLL_HIGH_WINDOW_START_OTP1) {
                        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Backup Primary Rx_Low", __func__);
                        return EIO;
                    } else {
                        break;
                    }
                }
                j7ospi_find_rx_low_otp1_tune(ospi, &search_point, &backup_point);
            }

            if(backup_point.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) {
                snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Backup Primary Rx_Low: rx_dll:%u tx_dll:%u read_delay:%u", __func__, backup_point.rx_dll, backup_point.tx_dll, backup_point.read_delay);
                break;
            }

            search_point.tx_dll -= J7OSPI_RX_TX_DLL_SEARCH_STEP;
        }

        /***************************** BACKUP Secondary Rx_Low Search *********************/
        /* Search for one more rx_low at different tx_dll*/
        if (search_point.tx_dll >= (J7OSPI_TX_DLL_HIGH_WINDOW_START_OTP1 + J7OSPI_TX_DLL_SEARCH_OFFSET)) {
            search_point.tx_dll -= J7OSPI_TX_DLL_SEARCH_OFFSET;
        } else {
            search_point.tx_dll = J7OSPI_TX_DLL_HIGH_WINDOW_START_OTP1;
        }

        search_point.read_delay = J7OSPI_RD_DELAY_MIN;
        search_point.rx_dll   = J7OSPI_RX_LOW_SEARCH_START;
        j7ospi_find_rx_low_otp1_tune(ospi, &search_point, &sec_rx_low);
        while(sec_rx_low.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            search_point.read_delay++;  /* For each tx_dll in the window, go through all the valid read_delays until we find the rx_low */
            if(search_point.read_delay > J7OSPI_RD_DELAY_MAX) {
                if(search_point.tx_dll <= J7OSPI_TX_DLL_HIGH_WINDOW_START_OTP1) {
                    snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Backup Secondary Rx_Low", __func__);
                    return EIO; /* Not able to find rx_low as there is no valid tx_dll in the tx_dll window */
                } else {
                    break;
                }
            }
            j7ospi_find_rx_low_otp1_tune(ospi, &search_point, &sec_rx_low);
        }

        if(sec_rx_low.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) {
            snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Backup Secondary Rx_Low: rx_dll:%u tx_dll:%u read_delay:%u", __func__, sec_rx_low.rx_dll, sec_rx_low.tx_dll, sec_rx_low.read_delay);
        }

        backup_point.rx_dll = min(backup_point.rx_dll, sec_rx_low.rx_dll);
        backup_point.read_delay = min(backup_point.read_delay, sec_rx_low.read_delay);

        if(backup_point.rx_dll < rx_low.rx_dll) {
            rx_low = backup_point;
        }

        /*
         * Reset the search point tx_dll to continue the Rx_High search
         */
        search_point.tx_dll = backup_point.tx_dll;

        /***************************** BACKUP Primary Rx_High Search *********************/
        /*
         * Find rx_dll Max
         * Start the read_delay from maximum and decrement it.
         */

        search_point.rx_dll = J7OSPI_RX_HIGH_SEARCH_END_OTP1;
        search_point.read_delay = J7OSPI_RD_DELAY_MAX;
        j7ospi_find_rx_high_otp1_tune(ospi, &search_point, &backup_point);

        while(backup_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            search_point.read_delay--;
            if(search_point.read_delay < J7OSPI_RD_DELAY_MIN) {
                ret = EIO;
                snor_slogf(_SLOG_WARNING, ospi->ctrl.verbosity, 2, "%s: Failed to find Backup Primary Rx_High", __func__);
                break;
            }
            j7ospi_find_rx_high_otp1_tune(ospi, &search_point, &backup_point);
        }

        if(backup_point.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) {
            snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Backup Primary Rx_High: rx_dll:%u tx_dll:%u read_delay:%u", __func__, backup_point.rx_dll, backup_point.tx_dll, backup_point.read_delay);
        }

        /***************************** BACKUP Secondary Rx_High Search *********************/
        /*
         * Find rx_dll Max
         * Start the read_delay (Read delay) from maximum and decrement it.
         */

        if (search_point.tx_dll >= (J7OSPI_TX_DLL_HIGH_WINDOW_START_OTP1 + J7OSPI_TX_DLL_SEARCH_OFFSET )) {
            search_point.tx_dll -= J7OSPI_TX_DLL_SEARCH_OFFSET;
        } else {
            search_point.tx_dll = J7OSPI_TX_DLL_HIGH_WINDOW_START_OTP1;
        }

        search_point.rx_dll = J7OSPI_RX_HIGH_SEARCH_END_OTP1;
        search_point.read_delay = J7OSPI_RD_DELAY_MAX;
        j7ospi_find_rx_high_otp1_tune(ospi, &search_point, &sec_rx_high);

        while(sec_rx_high.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            search_point.read_delay--;
            if(search_point.read_delay < J7OSPI_RD_DELAY_MIN) {
                ret = EIO;
                snor_slogf(_SLOG_WARNING, ospi->ctrl.verbosity, 2, "%s: Failed to find Backup Secondary Rx_High", __func__);
                break;
            }
            j7ospi_find_rx_high_otp1_tune(ospi, &search_point, &sec_rx_high);
        }

        if(sec_rx_high.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) {
            snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Backup Secondary Rx_Low: rx_dll:%u tx_dll:%u read_delay:%u", __func__, sec_rx_high.rx_dll, sec_rx_high.tx_dll, sec_rx_high.read_delay);
        }

        /*
         * Compare the Primary and Secondary point
         * Pick the point which has passing maximum rx_dll
        */
        if(sec_rx_high.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) {
            if(backup_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
                backup_point = sec_rx_high;
            } else {
                if(sec_rx_high.rx_dll > backup_point.rx_dll) {
                    backup_point = sec_rx_high;
                }
            }
        } else {
            if(backup_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
                snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Backup Rx_High", __func__);
                return EIO;
            }
        }

        if(backup_point.rx_dll > rx_high.rx_dll) {
            rx_high = backup_point;
        }
    }

    /***************************** GOLDEN Tx_Low Search *********************/
    /*
     * Look for tx_dll boundaries at 1/4 of rx_dll window
     * Find tx_dll Min
     */

    search_point.read_delay = J7OSPI_RD_DELAY_MIN;
    search_point.rx_dll = rx_low.rx_dll+(rx_high.rx_dll-rx_low.rx_dll)/4U;
    search_point.tx_dll = J7OSPI_TX_LOW_SEARCH_START_OTP1;
    j7ospi_find_tx_low_otp1_tune(ospi, &search_point, &tx_low);

    while(tx_low.tx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
        search_point.read_delay++;
        j7ospi_find_tx_low_otp1_tune(ospi, &search_point, &tx_low);

        if(search_point.read_delay > J7OSPI_RD_DELAY_MAX) {
            snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Tx_Low", __func__);
            return EIO;
        }
    }

    if(tx_low.tx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) {
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Tx_Low: rx_dll:%u tx_dll:%u read_delay:%u", __func__, tx_low.rx_dll, tx_low.tx_dll, tx_low.read_delay);
    }

    /***************************** GOLDEN Tx_High Search *********************/
    /*
     * Find tx_dll Max
     * Start the read_delay from maximum and decrement it.
     */

    search_point.tx_dll = J7OSPI_TX_HIGH_SEARCH_END_OTP1;
    search_point.read_delay = J7OSPI_RD_DELAY_MAX;
    j7ospi_find_tx_high_otp1_tune(ospi, &search_point, &tx_high);

    while(tx_high.tx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
        search_point.read_delay--;
        j7ospi_find_tx_high_otp1_tune(ospi, &search_point, &tx_high);

        if(search_point.read_delay < J7OSPI_RD_DELAY_MIN) {
            snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Tx_High", __func__);
            return EIO;
        }
    }

    if(tx_high.tx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) {
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Tx_High: rx_dll:%u tx_dll:%u read_delay:%u", __func__, tx_high.rx_dll, tx_high.tx_dll, tx_high.read_delay);
    }

    /*
     * Check a different point if the tx_low and tx_high are on the same read_delay.
     * This avoids mistaking the metastability gap for a tx_dll boundary
     */
    if(tx_low.read_delay == tx_high.read_delay) {

        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: tx_low and tx_high at the same read delay.", __func__);
        /***************************** BACKUP Tx_Low Search *********************/
        /* Look for tx_dll boundaries at 3/4 of rx_dll window */
        /* Find tx_dll Min */

        search_point.read_delay = J7OSPI_RD_DELAY_MIN;
        search_point.rx_dll = rx_low.rx_dll + 3U*(rx_high.rx_dll-rx_low.rx_dll)/4U;
        search_point.tx_dll = J7OSPI_TX_LOW_SEARCH_START_OTP1;
        j7ospi_find_tx_low_otp1_tune(ospi, &search_point, &backup_point);
        while(backup_point.tx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            search_point.read_delay++;
            j7ospi_find_tx_low_otp1_tune(ospi, &search_point, &backup_point);
            if(search_point.read_delay > J7OSPI_RD_DELAY_MAX) {
                snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Backup Tx_Low", __func__);
                return EIO;
            }
        }
        if(backup_point.tx_dll < tx_low.tx_dll) {
            tx_low = backup_point;
        }

        /***************************** BACKUP Tx_High Search *********************/
        /*
         * Find tx_dll Max
         * Start the read_delay from maximum and decrement it.
         */

        search_point.tx_dll = J7OSPI_TX_HIGH_SEARCH_END_OTP1;
        search_point.read_delay = J7OSPI_RD_DELAY_MAX;
        j7ospi_find_tx_high_otp1_tune(ospi, &search_point, &backup_point);
        while(backup_point.tx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            search_point.read_delay--;
            j7ospi_find_tx_high_otp1_tune(ospi, &search_point, &backup_point);
            if(search_point.read_delay < J7OSPI_RD_DELAY_MIN) {
                snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Backup Tx_High", __func__);
                return EIO;
            }
        }
        if(backup_point.tx_dll > tx_high.tx_dll) {
            tx_high = backup_point;
        }
    }

    /*
     * Set bottom left and top right right corners.  These are theoretical corners. They may not actually be "good" points.
     * But the longest diagonal of the shmoo will be between these corners.
     */

    /* Bottom Left */
    bottom_left.tx_dll = tx_low.tx_dll;
    bottom_left.rx_dll = rx_low.rx_dll;

    if(tx_low.read_delay <= rx_low.read_delay) {
        bottom_left.read_delay = tx_low.read_delay;
    } else {
        bottom_left.read_delay = rx_low.read_delay;
    }

    backup_corner_point = bottom_left;
    backup_corner_point.tx_dll += 4U;
    backup_corner_point.rx_dll += 4U;

    j7ospi_phy_apply_setting(ospi, &backup_corner_point);
    ret = j7ospi_phy_check_pattern(ospi);

    if(ret != EOK) {
        backup_corner_point.read_delay--;
        j7ospi_phy_apply_setting(ospi, &backup_corner_point);
        ret = j7ospi_phy_check_pattern(ospi);
    }

    if(ret == EOK) {
        bottom_left.read_delay = backup_corner_point.read_delay;
    }

    top_right.tx_dll = tx_high.tx_dll;
    top_right.rx_dll = rx_high.rx_dll;

    if(tx_high.read_delay > rx_high.read_delay) {
        top_right.read_delay = tx_high.read_delay;
    } else {
        top_right.read_delay = rx_high.read_delay;
    }

    backup_corner_point = top_right;
    backup_corner_point.tx_dll -= 4U;
    backup_corner_point.rx_dll -= 4U;

    j7ospi_phy_apply_setting(ospi, &backup_corner_point);
    ret = j7ospi_phy_check_pattern(ospi);

    if(ret != EOK) {
        backup_corner_point.read_delay++;
        j7ospi_phy_apply_setting(ospi, &backup_corner_point);
        ret = j7ospi_phy_check_pattern(ospi);
    }

    if(ret == EOK) {
        top_right.read_delay = backup_corner_point.read_delay;
    }

    /* Find the equation of diagonal between top_right and bottom_left */

    /* Slope and Intercept*/
    slope = ((float)top_right.rx_dll - (float)bottom_left.rx_dll) / ((float)top_right.tx_dll - (float)bottom_left.tx_dll);
    /* Binary Search */
    j7_phy_setting left, right;
    /* Search along the diagonal between corners */
    left = bottom_left;
    right = top_right;
    search_point.tx_dll = left.tx_dll + ((right.tx_dll - left.tx_dll) / 2);
    search_point.rx_dll = left.rx_dll + ((right.rx_dll - left.rx_dll) / 2);
    search_point.read_delay = left.read_delay;

    do {
        j7ospi_phy_apply_setting(ospi, &search_point);
        ret = j7ospi_phy_check_pattern(ospi);

        if(ret != EOK) {
            /*
            * As the read failed, we go to the lower half for finding the gap low
            */
            right.tx_dll = search_point.tx_dll;
            right.rx_dll = search_point.rx_dll;

            search_point.tx_dll = left.tx_dll + ((search_point.tx_dll - left.tx_dll) / 2);
            search_point.rx_dll = left.rx_dll + ((search_point.rx_dll - left.rx_dll) / 2);
        } else {
            /*
            * As the read is a success we go to the upper half for finding the gap low
            */
            left.tx_dll = search_point.tx_dll;
            left.rx_dll = search_point.rx_dll;

            search_point.tx_dll = search_point.tx_dll + ((right.tx_dll - search_point.tx_dll) / 2);
            search_point.rx_dll = search_point.rx_dll + ((right.rx_dll - search_point.rx_dll) / 2);
        }
    /* Break the loop if the window has closed. */
    } while ((right.tx_dll - left.tx_dll >= 2) && (right.rx_dll - left.rx_dll >= 2));

    gap_low = search_point;

    /* If there's only one segment, put tuning point in the middle and adjust for temperature */
    if(bottom_left.read_delay == top_right.read_delay) {
        /* Start of the metastability gap is a good approximation for the top_right */
        top_right = gap_low;
        search_point.read_delay = bottom_left.read_delay;
        search_point.tx_dll = (bottom_left.tx_dll + top_right.tx_dll) / 2U;
        search_point.rx_dll = (bottom_left.rx_dll + top_right.rx_dll) / 2U;

        /* Temperature adjustment - Add support for finding temperature*/
    } else {
        /* If there are two segments, find the start and end of the second one */
        left = bottom_left;
        right = top_right;
        search_point.tx_dll = left.tx_dll + ((right.tx_dll - left.tx_dll) / 2);
        search_point.rx_dll = left.rx_dll + ((right.rx_dll - left.rx_dll) / 2);
        search_point.read_delay = right.read_delay;
        do {

            j7ospi_phy_apply_setting(ospi, &search_point);
            ret = j7ospi_phy_check_pattern(ospi);
            if(ret != EOK) {
                /*
                * As the read failed, we go to the upper half for finding the gap high
                */
                left.tx_dll = search_point.tx_dll;
                left.rx_dll = search_point.rx_dll;

                search_point.tx_dll = search_point.tx_dll + ((right.tx_dll - search_point.tx_dll) / 2);
                search_point.rx_dll = search_point.rx_dll + ((right.rx_dll - search_point.rx_dll) / 2);
            } else {
                /*
                * As the read is a success we go to the lower half for finding the gap high
                */
                right.tx_dll = search_point.tx_dll;
                right.rx_dll = search_point.rx_dll;

                search_point.tx_dll = left.tx_dll + ((search_point.tx_dll - left.tx_dll) / 2);
                search_point.rx_dll = left.rx_dll + ((search_point.rx_dll - left.rx_dll) / 2);
            }
            /* Break the loop if the window has closed. */
        } while ((right.tx_dll - left.tx_dll >= 2) && (right.rx_dll - left.rx_dll >= 2));
        gap_high = search_point;

        /* Place the final tuning point of the PHY in the corner furthest from the gap */
        const int len1 = abs((int)gap_low.tx_dll - (int)bottom_left.tx_dll) + abs((int)gap_low.rx_dll - (int)bottom_left.rx_dll);
        const int len2 = abs((int)gap_high.tx_dll - (int)top_right.tx_dll) + abs((int)gap_high.rx_dll - (int)top_right.rx_dll);

        if(len2 > len1) {
            search_point = top_right;
            search_point.tx_dll -= 16;
            search_point.rx_dll -= (uint32_t)((float)16*slope);
        } else {
            search_point = bottom_left;
            search_point.tx_dll += 16;
            search_point.rx_dll += (uint32_t)((float)16*slope);
        }
    }

    j7ospi_phy_apply_setting(ospi, &search_point);
    ret = j7ospi_phy_check_pattern(ospi);

    if(ret == EOK) {
        otp->rx_dll = search_point.rx_dll;
        otp->tx_dll = search_point.tx_dll;
        otp->read_delay = search_point.read_delay;
    } else {
        otp->rx_dll = 0;
        otp->tx_dll = 0;
        otp->read_delay = 0;
    }

    snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "Calibration Results: rx_dll: %u\ttx_dll: %u\tread_delay: %u", otp->rx_dll, otp->tx_dll, otp->read_delay);

    return ret;
}

/*
 * Searches rx_dll up from start until the tuning basis passes.
 * Does not look at the next read_delay setting. Returns rx_dll = J7OSPI_RX_TX_DLL_MAX_STEP if fail.
 */
static j7_phy_setting j7ospi_find_rx_low_ddr_tune(j7ospi_dev_t *const ospi, j7_phy_setting start)
{
    int ret = EIO;

    /*
     * Try to find PHY tuning point in the search window. The loop exits
     * either on finding such point or when search window has been exhausted.
     */
    do {
        j7ospi_phy_apply_setting(ospi, &start);
        ret = j7ospi_phy_check_pattern(ospi);

        if((ret == EOK) || (start.rx_dll + J7OSPI_RX_TX_DLL_SEARCH_STEP > J7OSPI_RX_LOW_SEARCH_END)) {
            break;
        } else {
            start.rx_dll += J7OSPI_RX_TX_DLL_SEARCH_STEP;
        }
    } while (ret != EOK);

    if(ret != EOK) {
        start.rx_dll = J7OSPI_RX_TX_DLL_MAX_STEP;
    }

    return start;
}

static j7_phy_setting j7ospi_find_rx_high_ddr_tune(j7ospi_dev_t *const ospi, j7_phy_setting start)
{
    int ret = EIO;

    /*
     * Try to find PHY tuning point in the search window. The loop exits
     * either on finding such point or when search window has been exhausted.
     */
    do {
        j7ospi_phy_apply_setting(ospi, &start);
        ret = j7ospi_phy_check_pattern(ospi);

        if((ret == EOK) || (start.rx_dll < (J7OSPI_RX_HIGH_SEARCH_END_DDR + J7OSPI_RX_TX_DLL_SEARCH_STEP))) {
            break;
        } else {
            start.rx_dll -= J7OSPI_RX_TX_DLL_SEARCH_STEP;
        }
    } while (ret != EOK);

    if(ret != EOK) {
        start.rx_dll = J7OSPI_RX_TX_DLL_MAX_STEP;
    }

    return start;
}

static j7_phy_setting j7ospi_find_tx_low_ddr_tune(j7ospi_dev_t *const ospi, j7_phy_setting start)
{
    int ret = EIO;

    /*
     * Try to find PHY tuning point in the search window. The loop exits
     * either on finding such point or when search window has been exhausted.
     */
    do {
        j7ospi_phy_apply_setting(ospi, &start);
        ret = j7ospi_phy_check_pattern(ospi);

        if((ret == EOK) || (start.tx_dll + J7OSPI_RX_TX_DLL_SEARCH_STEP > J7OSPI_TX_LOW_SEARCH_END)) {
            break;
        } else {
            start.tx_dll += J7OSPI_RX_TX_DLL_SEARCH_STEP;
        }

    } while (ret != EOK);

    if(ret != EOK) {
        start.tx_dll = J7OSPI_RX_TX_DLL_MAX_STEP;
    }

    return start;
}

static j7_phy_setting j7ospi_find_tx_high_ddr_tune(j7ospi_dev_t *const ospi, j7_phy_setting start)
{
    int ret = EIO;

    /*
     * Try to find PHY tuning point in the search window. The loop exits
     * either on finding such point or when search window has been exhausted.
     */
    do {
        j7ospi_phy_apply_setting(ospi, &start);
        ret = j7ospi_phy_check_pattern(ospi);

        if((ret == EOK) || (start.tx_dll < (J7OSPI_TX_HIGH_SEARCH_END_DDR + J7OSPI_RX_TX_DLL_SEARCH_STEP))) {
            break;
        } else {
            start.tx_dll -= J7OSPI_RX_TX_DLL_SEARCH_STEP;
        }

    } while (ret != EOK);

    if(ret != EOK) {
        start.tx_dll = J7OSPI_RX_TX_DLL_MAX_STEP;
    }

    return start;
}

static int j7ospi_spi_phy_ddr_tune(j7ospi_dev_t *const ospi)
{
    int             status = EOK;
    j7_phy_setting  search_point = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting  bottom_left = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting  top_right = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting  gap_low = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting  gap_high = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting  rx_low = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0}, rx_high = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting  tx_low = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0}, tx_high = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting  temp_search_point = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0}, temp_search_point1 = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    j7_phy_setting  left = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0}, right = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};
    float           temperature = 0.0f;
    float           length1, length2;

    /*
     * Finding rx_dll fails at some of the tx_dll values based on the HW platform.
     * A window of tx_dll values is used to find the rx_dll without errors.
     * This can increase the number of CPU cycles taken for the PHY tuning
     * in the cases where more tx_dll values need to be parsed to find a stable rx_dll.
     */

    /*
     * Loop over NOR_SPI_PHY_tx_dll_LOW_WINDOW while rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP
     *  - Loop over PHY_DDR_TUNE_RD_DELAY while rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP
     *      - Try finding rx_dll in RX_DLL_LOW_SEARCH range
     *      - if rx_dll is not J7OSPI_RX_TX_DLL_MAX_STEP or
     *        read_delay is J7OSPI_RD_DELAY_MAX break from the loop.
     *      - else continue searching rx_low at next read_delay.
     *  - if rx_dll is not J7OSPI_RX_TX_DLL_MAX_STEP or
     *    tx_dll is NOR_SPI_PHY_tx_dll_HIGH_WINDOW_END break from the loop.
     *  - else continue searching rx_low at next tx_dll
     */
    search_point.tx_dll = J7OSPI_TX_DLL_LOW_WINDOW_START;
    do {
        /* Search for rx_low with in read_delay range */
        search_point.read_delay = J7OSPI_RD_DELAY_MIN;
        do {
            search_point.rx_dll   = J7OSPI_RX_LOW_SEARCH_START;
            rx_low = j7ospi_find_rx_low_ddr_tune(ospi, search_point);

            if((rx_low.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || \
               (search_point.read_delay == J7OSPI_RD_DELAY_MAX)) {
                break;
            } else {
                search_point.read_delay++;
            }

        } while (rx_low.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

        if((rx_low.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || \
           (search_point.tx_dll + J7OSPI_RX_TX_DLL_SEARCH_STEP > J7OSPI_TX_DLL_LOW_WINDOW_END)) {
            break;
        } else {
            search_point.tx_dll += J7OSPI_RX_TX_DLL_SEARCH_STEP;
        }

    } while (rx_low.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

    if(rx_low.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Primary Rx Min", __func__);
        return EIO;
    } else {
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Primary Rx Min: rx_dll:%u tx_dll:%u read_delay:%u", __func__, rx_low.rx_dll, rx_low.tx_dll, rx_low.read_delay);
    }

    /*
    * Sometimes the first rx_low that was found may always not belong to valid region,
    * find one more rx_low at different tx_dll which is J7OSPI_TX_DLL_SEARCH_OFFSET
    * steps away from previously passing search_point.tx_dll
    */
    if((J7OSPI_TX_DLL_LOW_WINDOW_END - J7OSPI_TX_DLL_SEARCH_OFFSET) >= search_point.tx_dll) {
        /*
        * Loop while passing rx_dll is not found at previous rx_low.tx_dll + J7OSPI_TX_DLL_SEARCH_OFFSET
        * if either passing rx_dll is found or read_delay reaches J7OSPI_RD_DELAY_MAX
        * break out of the loop else continue searching for rx_dll at next read_delay
        */
        search_point.tx_dll += J7OSPI_TX_DLL_SEARCH_OFFSET;
        search_point.read_delay = J7OSPI_RD_DELAY_MIN;
        do {
            search_point.rx_dll = J7OSPI_RX_LOW_SEARCH_START;

            temp_search_point = j7ospi_find_rx_low_ddr_tune(ospi, search_point);

            if((temp_search_point.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || \
               (search_point.read_delay == J7OSPI_RD_DELAY_MAX)) {
                break;
            } else {
                search_point.read_delay++;
            }

        } while (temp_search_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

        if(temp_search_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Secondary Rx Min", __func__);
            return EIO;
        } else {
            snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Secondary Rx Min: rx_dll:%u tx_dll:%u read_delay:%u", __func__, temp_search_point.rx_dll, temp_search_point.tx_dll, temp_search_point.read_delay);
        }
        search_point.tx_dll = rx_low.tx_dll;
        rx_low.rx_dll = min(rx_low.rx_dll, temp_search_point.rx_dll);
        rx_low.read_delay = min(rx_low.read_delay, temp_search_point.read_delay);
    }

    snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Golden Rx Min: rx_dll:%u tx_dll:%u read_delay:%u", __func__, rx_low.rx_dll, rx_low.tx_dll, rx_low.read_delay);

    /*
    * Loop while passing rx_dll is not found at previous rx_low.tx_dll
    * starting from read_delay = J7OSPI_RD_DELAY_MAX by decrementing read_delay after every search
    * if either passing rx_dll is found or read_delay reaches J7OSPI_RD_DELAY_MIN
    * break out of the loop else continue searching for rx_dll at next read_delay
    */
    search_point.read_delay = J7OSPI_RD_DELAY_MAX;

    do {
        search_point.rx_dll = J7OSPI_RX_HIGH_SEARCH_START_DDR;
        rx_high = j7ospi_find_rx_high_ddr_tune(ospi, search_point);

        if((rx_high.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || \
           (search_point.read_delay == J7OSPI_RD_DELAY_MIN)) {
            break;
        } else {
            search_point.read_delay--;
        }
    } while (rx_high.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

    if(rx_high.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Warning: Unable to find RX Max", __func__);
    } else {
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Primary Rx High: rx_dll:%u tx_dll:%u read_delay:%u", __func__, rx_high.rx_dll, rx_high.tx_dll, rx_high.read_delay);
    }

    /*
    * Sometimes the first rx_high that was found may always not belong to valid region,
    * find one more rx_high at different tx_dll which is J7OSPI_TX_DLL_SEARCH_OFFSET
    * steps away from previously passing search_point.tx_dll
    */
    if((J7OSPI_TX_DLL_LOW_WINDOW_END - J7OSPI_TX_DLL_SEARCH_OFFSET) >= search_point.tx_dll) {
        /*
        * Loop while passing rx_dll is not found at previous rx_high.tx_dll + J7OSPI_TX_DLL_SEARCH_OFFSET
        * starting from read_delay = J7OSPI_RD_DELAY_MAX by decrementing read_delay after every search
        * if either passing rx_dll is found or read_delay reaches J7OSPI_RD_DELAY_MIN
        * break out of the loop else continue searching for rx_dll at next read_delay
        */
        search_point.tx_dll += J7OSPI_TX_DLL_SEARCH_OFFSET;
        search_point.read_delay = J7OSPI_RD_DELAY_MAX;
        do {
            search_point.rx_dll = J7OSPI_RX_HIGH_SEARCH_START_DDR;

            temp_search_point = j7ospi_find_rx_high_ddr_tune(ospi, search_point);

            if((temp_search_point.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || \
               (search_point.read_delay == J7OSPI_RD_DELAY_MIN)) {
                break;
            } else {
                search_point.read_delay--;
            }

        } while (temp_search_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

        search_point.tx_dll = rx_high.tx_dll;
        if(temp_search_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            if(rx_high.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
                snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Primary Rx Max", __func__);
                return EIO;
            }
        } else {
            snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Found Secondary Rx High: rx_dll:%u tx_dll:%u read_delay:%u", __func__, temp_search_point.rx_dll, temp_search_point.tx_dll, temp_search_point.read_delay);
            if(rx_high.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
                rx_high = temp_search_point;
            } else {
                if(rx_high.rx_dll < temp_search_point.rx_dll) {
                    rx_high = temp_search_point;
                }
            }
        }
    }

    /*
     * Check a different point if the rx_low and rx_high are on the same read_delay.
     * This avoids mistaking the metastability gap for an rx_dll boundary
     */
    if (rx_low.read_delay == rx_high.read_delay) {
        /*
         * Finding rx_dll fails at some of the tx_dll values based on the HW platform.
         * A window of tx_dll values is used to find the rx_dll without errors.
         * This can increase the number of CPU cycles taken for the PHY tuning
         * in the cases where more tx_dll values need to be parsed to find a stable rx_dll.
         */
        /*
        * Loop over NOR_SPI_PHY_TXDLL_HIGH_WINDOW while rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP
        *  - Loop over PHY_DDR_TUNE_RD_DELAY while rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP
        *      - Try finding rx_dll in RX_DLL_LOW_SEARCH range
        *      - if rx_dll is not J7OSPI_RX_TX_DLL_MAX_STEP or
        *        read_delay is J7OSPI_RD_DELAY_MAX break from the loop.
        *      - else continue searching rx_low at next read_delay.
        *  - if rx_dll is not J7OSPI_RX_TX_DLL_MAX_STEP or
        *    tx_dll is J7OSPI_TX_DLL_HIGH_WINDOW_END_DDR break from the loop.
        *  - else continue searching rx_low at next tx_dll
        */
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: rx_low and rx_high at the same read delay.", __func__);
        search_point.tx_dll = J7OSPI_TX_DLL_HIGH_WINDOW_START_DDR;
        do {
            search_point.read_delay = J7OSPI_RD_DELAY_MIN;
            do {
                search_point.rx_dll = J7OSPI_RX_LOW_SEARCH_START;
                temp_search_point = j7ospi_find_rx_low_ddr_tune(ospi, search_point);

                if((temp_search_point.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || \
                   (search_point.read_delay == J7OSPI_RD_DELAY_MAX)) {
                    break;
                } else {
                    search_point.read_delay++;
                }

            } while (temp_search_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

            if((temp_search_point.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || \
              (search_point.tx_dll < (J7OSPI_TX_DLL_HIGH_WINDOW_END_DDR + J7OSPI_RX_TX_DLL_SEARCH_STEP))) {
                break;
            } else {
                search_point.tx_dll -= J7OSPI_RX_TX_DLL_SEARCH_STEP;
            }

        } while (temp_search_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

        if(temp_search_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Failed to find Rx Min", __func__);
            return EIO;
        }

        /*
        * Sometimes the first rx_low that was found may always not belong to valid region,
        * find one more rx_low at different tx_dll which is J7OSPI_TX_DLL_SEARCH_OFFSET
        * steps away from previously passing search_point.tx_dll
        */
        if((J7OSPI_TX_DLL_HIGH_WINDOW_END_DDR + J7OSPI_TX_DLL_SEARCH_OFFSET) >= search_point.tx_dll) {
            /*
            * Loop while passing rx_dll is not found at previous temp_search_point.tx_dll + J7OSPI_TX_DLL_SEARCH_OFFSET
            * if either passing rx_dll is found or read_delay reaches J7OSPI_RD_DELAY_MAX
            * break out of the loop else continue searching for rx_dll at next read_delay
            */
            search_point.tx_dll -= J7OSPI_TX_DLL_SEARCH_OFFSET;
            search_point.read_delay = J7OSPI_RD_DELAY_MIN;
            do {
                search_point.rx_dll = J7OSPI_RX_LOW_SEARCH_START;
                temp_search_point1 = j7ospi_find_rx_low_ddr_tune(ospi, search_point);

                if((temp_search_point1.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || \
                   (search_point.read_delay == J7OSPI_RD_DELAY_MAX)) {
                    break;
                } else {
                    search_point.read_delay++;
                }
            } while (temp_search_point1.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

            if(temp_search_point1.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
                snor_slogf(_SLOG_WARNING, ospi->ctrl.verbosity, 0, "%s: Warning: Unable to find Rx Min", __func__);
            }
            search_point.tx_dll = temp_search_point.tx_dll;
            temp_search_point.rx_dll = min(temp_search_point.rx_dll, temp_search_point1.rx_dll);
            temp_search_point.read_delay = min(temp_search_point.read_delay, temp_search_point1.read_delay);

            if(temp_search_point.rx_dll < rx_low.rx_dll) {
                rx_low = temp_search_point;
            }
        }

        /*
        * Loop while passing rx_dll is not found at previous search_point.tx_dll
        * starting from read_delay = J7OSPI_RD_DELAY_MAX by decrementing read_delay after every search
        * if either passing rx_dll is found or read_delay reaches J7OSPI_RD_DELAY_MIN
        * break out of the loop else continue searching for rx_dll at next read_delay
        */
        search_point.read_delay = J7OSPI_RD_DELAY_MAX;
        do {
            search_point.rx_dll = J7OSPI_RX_HIGH_SEARCH_START_DDR;

            temp_search_point = j7ospi_find_rx_high_ddr_tune(ospi, search_point);

            if((temp_search_point.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || 
               (search_point.read_delay == J7OSPI_RD_DELAY_MIN)) {
                break;
            } else {
                search_point.read_delay--;
            }

        } while (temp_search_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

        if(temp_search_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            snor_slogf(_SLOG_WARNING, ospi->ctrl.verbosity, 0, "%s: Warning: Unable to find Rx Max", __func__);
        } else if(temp_search_point.rx_dll > rx_high.rx_dll) {
            rx_high = temp_search_point;
        } else {
            /* Do nothing */
        }

        /*
        * Sometimes the first rx_high that was found may always not belong to valid region,
        * find one more rx_high at different tx_dll which is J7OSPI_TX_DLL_SEARCH_OFFSET
        * steps away from previously passing search_point.tx_dll
        */
        if((J7OSPI_TX_DLL_HIGH_WINDOW_END_DDR + J7OSPI_TX_DLL_SEARCH_OFFSET) <= search_point.tx_dll) {
            /*
            * Loop while passing rx_dll is not found at previous search_point.tx_dll - J7OSPI_TX_DLL_SEARCH_OFFSET
            * starting from read_delay = J7OSPI_RD_DELAY_MAX by decrementing read_delay after every search
            * if either passing rx_dll is found or read_delay reaches J7OSPI_RD_DELAY_MIN
            * break out of the loop else continue searching for rx_dll at next read_delay
            */
            search_point.tx_dll -= J7OSPI_TX_DLL_SEARCH_OFFSET;
            search_point.read_delay = J7OSPI_RD_DELAY_MAX;
            do {
                search_point.rx_dll = J7OSPI_RX_HIGH_SEARCH_START_DDR;
                temp_search_point = j7ospi_find_rx_high_ddr_tune(ospi, search_point);

                if((temp_search_point.rx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || \
                   (search_point.read_delay == J7OSPI_RD_DELAY_MIN)) {
                    break;
                } else {
                    search_point.read_delay--;
                }

            } while (temp_search_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

            search_point.tx_dll = rx_high.tx_dll;
            if(temp_search_point.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
                if(rx_high.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
                    snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Unable to find RX Max at first & second tx_dll search point", __func__);
                    return EIO;
                }
            } else {
                if(rx_high.rx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
                    rx_high = temp_search_point;
                } else {
                    if(rx_high.rx_dll < temp_search_point.rx_dll) {
                        rx_high = temp_search_point;
                    }
                }
            }
        }
    }

    /*
    * Loop while passing tx_dll is not found at 1/4th rx_dll point between rx_low and rx_high
    * starting from read_delay = J7OSPI_RD_DELAY_MIN
    * if either passing tx_dll is found or read_delay reaches J7OSPI_RD_DELAY_MAX
    * break out of the loop else continue searching for tx_dll at next read_delay
    */
    search_point.read_delay = J7OSPI_RD_DELAY_MIN;
    search_point.rx_dll = ((rx_high.rx_dll - rx_low.rx_dll) / 4) + rx_low.rx_dll;

    do {
        search_point.tx_dll = J7OSPI_TX_LOW_SEARCH_START_DDR;
        tx_low = j7ospi_find_tx_low_ddr_tune(ospi, search_point);

        if((tx_low.tx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || (search_point.read_delay == J7OSPI_RD_DELAY_MAX)) {
            break;
        } else {
            search_point.read_delay++;
        }

    } while (tx_low.tx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

    if(tx_low.tx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Unable to find TX Min", __func__);
            return EIO;
    }

    /*
    * Loop while passing tx_dll is not found at 1/4th rx_dll point between rx_low and rx_high
    * starting from read_delay = J7OSPI_RD_DELAY_MAX by decrementing read_delay after every search
    * if either passing tx_dll is found or read_delay reaches J7OSPI_RD_DELAY_MIN
    * break out of the loop else continue searching for tx_dll at next read_delay
    */
    search_point.read_delay = J7OSPI_RD_DELAY_MAX;
    do {
        search_point.tx_dll = J7OSPI_TX_HIGH_SEARCH_START_DDR;
        tx_high = j7ospi_find_tx_high_ddr_tune(ospi, search_point);

        if((tx_high.tx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || \
           (search_point.read_delay == J7OSPI_RD_DELAY_MIN)) {
            break;
        } else {
            search_point.read_delay--;
        }

    } while (tx_high.tx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

    if(tx_high.tx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Unable to find TX Max", __func__);
        return EIO;
    }

    /*
     * Check a different point if the tx_low and tx_high are on the same read_delay.
     * This avoids mistaking the metastability gap for an rx_dll boundary
     */
    if(tx_low.read_delay == tx_high.read_delay) {
        /*
         * Loop while passing tx_dll is not found at 3/4th rx_dll point between rx_low and rx_high
         * starting from read_delay = J7OSPI_RD_DELAY_MIN
         * if either passing tx_dll is found or read_delay reaches J7OSPI_RD_DELAY_MAX
         * break out of the loop else continue searching for tx_dll at next read_delay
         */
        search_point.read_delay = J7OSPI_RD_DELAY_MIN;/* macro need to be defined as one*/
        search_point.rx_dll = 3U * (rx_high.rx_dll - rx_low.rx_dll) / 4 + rx_low.rx_dll;

        do {
            search_point.tx_dll = J7OSPI_TX_LOW_SEARCH_START_DDR;

            temp_search_point = j7ospi_find_tx_low_ddr_tune(ospi, search_point);

            if((temp_search_point.tx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || \
               (search_point.read_delay == J7OSPI_RD_DELAY_MAX)) {
                break;
            } else {
                search_point.read_delay++;
            }

        } while (temp_search_point.tx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

        if(temp_search_point.tx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Unable to find TX Min", __func__);
            return EIO;
        }
        if(temp_search_point.tx_dll < tx_low.tx_dll) {
            tx_low = temp_search_point;
        }

        /*
         * Loop while passing tx_dll is not found at 3/4th rx_dll point between rx_low and rx_high
         * starting from read_delay = J7OSPI_RD_DELAY_MAX by decrementing read_delay after every search
         * if either passing tx_dll is found or read_delay reaches J7OSPI_RD_DELAY_MIN
         * break out of the loop else continue searching for tx_dll at next read_delay
         */
        search_point.read_delay = J7OSPI_RD_DELAY_MAX;

        do {
            search_point.tx_dll = J7OSPI_TX_HIGH_SEARCH_START_DDR;

            temp_search_point = j7ospi_find_tx_high_ddr_tune(ospi, search_point);

            if((temp_search_point.tx_dll != J7OSPI_RX_TX_DLL_MAX_STEP) || \
               (search_point.read_delay == J7OSPI_RD_DELAY_MIN)) {
                break;
            } else {
                search_point.read_delay--;
            }

        } while (temp_search_point.tx_dll == J7OSPI_RX_TX_DLL_MAX_STEP);

        if(temp_search_point.tx_dll == J7OSPI_RX_TX_DLL_MAX_STEP) {
            snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Unable to find TX Max", __func__);
            return EIO;
        }
        if(temp_search_point.tx_dll > tx_high.tx_dll) {
            tx_high = temp_search_point;
        }
    }

    /*
     * Set bottom left and top right right corners.  These are theoretical corners. They may not actually be "good" points.
     * But the longest diagonal of the shmoo will be between these corners.
     */
    /* Bottom Left */
    bottom_left.tx_dll = tx_low.tx_dll;
    snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: bottom_left.tx_dll: %u", __func__, bottom_left.tx_dll);
    bottom_left.rx_dll = rx_low.rx_dll;
    if(tx_low.read_delay <= rx_low.read_delay) {
        bottom_left.read_delay = tx_low.read_delay;
    } else {
        bottom_left.read_delay = rx_low.read_delay;
    }
    temp_search_point = bottom_left;
    temp_search_point.tx_dll += 4;
    temp_search_point.rx_dll += 4;
    j7ospi_phy_apply_setting(ospi, &temp_search_point);
    status = j7ospi_phy_check_pattern(ospi);

    if(status != EOK) {
        temp_search_point.read_delay--;
        j7ospi_phy_apply_setting(ospi, &temp_search_point);
        status = j7ospi_phy_check_pattern(ospi);
    }
    if (status == EOK) {
        bottom_left.read_delay = temp_search_point.read_delay;
    }

    /* Top Right */
    top_right.tx_dll = tx_high.tx_dll;
    top_right.rx_dll = rx_high.rx_dll;
    if(tx_high.read_delay >= rx_high.read_delay) {
        top_right.read_delay = tx_high.read_delay;
    } else {
        top_right.read_delay = rx_high.read_delay;
    }
    temp_search_point = top_right;
    temp_search_point.tx_dll -= 4U;
    temp_search_point.rx_dll -= 4U;
    j7ospi_phy_apply_setting(ospi, &temp_search_point);
    status = j7ospi_phy_check_pattern(ospi);

    if(status != EOK) {
        temp_search_point.read_delay++;
        j7ospi_phy_apply_setting(ospi, &temp_search_point);
        status = j7ospi_phy_check_pattern(ospi);
    }
    if(status == EOK) {
        top_right.read_delay = temp_search_point.read_delay;
    }

    left  = bottom_left;
    right = top_right;

    search_point.tx_dll = left.tx_dll + ((right.tx_dll - left.tx_dll) / 2);
    search_point.rx_dll = left.rx_dll + ((right.rx_dll - left.rx_dll) / 2);
    search_point.read_delay = left.read_delay;

    do {
        j7ospi_phy_apply_setting(ospi, &search_point);
        status = j7ospi_phy_check_pattern(ospi);
        if(status != EOK) {
            /*
             * Since we couldn't find the pattern, we need to go the
             * the upper half.
             */
            right.tx_dll = search_point.tx_dll;
            right.rx_dll = search_point.rx_dll;

            search_point.tx_dll = left.tx_dll + ((search_point.tx_dll - left.tx_dll)/2);
            search_point.rx_dll = left.rx_dll + ((search_point.rx_dll - left.rx_dll)/2);
        } else {
            /*
             * Since we found the pattern, we need to go to the
             * lower half.
             */
            left.tx_dll = search_point.tx_dll;
            left.rx_dll = search_point.rx_dll;

            search_point.tx_dll = search_point.tx_dll + ((right.tx_dll - search_point.tx_dll)/2);
            search_point.rx_dll = search_point.rx_dll + ((right.rx_dll - search_point.rx_dll)/2);
        }
    /* Break the loop if the window has closed. */
    } while ((2U <= (right.tx_dll - left.tx_dll)) && (2U <= (right.rx_dll - left.rx_dll)));
    gap_low = search_point;

    /* If there's only one segment, put tuning point in the middle and adjust for temperature */
    if(bottom_left.read_delay==top_right.read_delay) {
        //The "true" top right corner was too small to find, so the start of the metastability gap is a good approximation
        top_right = gap_low;
        search_point.read_delay = bottom_left.read_delay;
        search_point.tx_dll = (bottom_left.tx_dll+top_right.tx_dll) / 2;
        search_point.rx_dll = (bottom_left.rx_dll+top_right.rx_dll) / 2;

        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Only one passing window found, from tx_dll,rx_dll of %u,%u to %u,%u, and a read_delay of %u", __func__,
                bottom_left.tx_dll, bottom_left.rx_dll, top_right.tx_dll, top_right.rx_dll, top_right.read_delay);

        temperature = j7ospi_phy_avg_vtm_temp(ospi, J7OSPI_PHY_VTM_TARGET);

        search_point.tx_dll += (top_right.tx_dll - bottom_left.tx_dll) * (0.5 * (temperature - 42.5) / 165.0);
        search_point.rx_dll += (top_right.rx_dll - bottom_left.rx_dll) * (0.5 * (temperature - 42.5) / 165.0);
    } else {
        /* If there are two segments, find the start and end of the second one */

        left  = bottom_left;
        right = top_right;

        search_point.tx_dll = left.tx_dll + ((right.tx_dll - left.tx_dll) / 2);
        search_point.rx_dll = left.rx_dll + ((right.rx_dll - left.rx_dll) / 2);
        search_point.read_delay = right.read_delay;

        do {
            j7ospi_phy_apply_setting(ospi, &search_point);
            status = j7ospi_phy_check_pattern(ospi);
            if(status != EOK) {
                /*
                 * Since we couldn't find the pattern, we need to go the
                 * the upper half.
                 */
                left.tx_dll = search_point.tx_dll;
                left.rx_dll = search_point.rx_dll;

                search_point.tx_dll = search_point.tx_dll + ((right.tx_dll - search_point.tx_dll)/2);
                search_point.rx_dll = search_point.rx_dll + ((right.rx_dll - search_point.rx_dll)/2);
            } else {
                /*
                 * Since we found the pattern, we need to go to the
                 * lower half.
                 */
                right.tx_dll = search_point.tx_dll;
                right.rx_dll = search_point.rx_dll;

                search_point.tx_dll = left.tx_dll + ((search_point.tx_dll - left.tx_dll)/2);
                search_point.rx_dll = left.rx_dll + ((search_point.rx_dll - left.rx_dll)/2);
            }
        /* Break the loop if the window has closed. */
        } while ((2U <= (right.tx_dll - left.tx_dll)) && (2U <= (right.rx_dll - left.rx_dll)));

        gap_high = search_point;
        /* Place the final tuning point of the PHY in the corner furthest from the gap */
        length1 = (float)abs((int32_t)gap_low.tx_dll - (int32_t)bottom_left.tx_dll) + abs((int32_t)gap_low.rx_dll - (int32_t)bottom_left.rx_dll);
        length2 = (float)abs((int32_t)gap_high.tx_dll- (int32_t)top_right.tx_dll) + abs((int32_t)gap_high.rx_dll- (int32_t)top_right.rx_dll);
        if(length2 > length1) {
            search_point = top_right;
            search_point.tx_dll -= 16U;
            search_point.rx_dll -= 16U * ((float)top_right.rx_dll - (float)bottom_left.rx_dll) / ((float)top_right.tx_dll - (float)bottom_left.tx_dll);
        } else {
            search_point = bottom_left;
            search_point.tx_dll += 16U;
            search_point.rx_dll += 16U * ((float)top_right.rx_dll-(float)bottom_left.rx_dll)/((float)top_right.tx_dll-(float)bottom_left.tx_dll);
        }
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Bottom left found at tx_dll,rx_dll of %u,%u to %u,%u, and a read_delay of %u", __func__,
                bottom_left.tx_dll, bottom_left.rx_dll,gap_low.tx_dll, gap_low.rx_dll, gap_low.read_delay);
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Top Right found at tx_dll,rx_dll of %u,%u to %u,%u, and a read_delay of %u", __func__,
                gap_high.tx_dll, gap_high.rx_dll, top_right.tx_dll, top_right.rx_dll, gap_high.read_delay);
    }

    snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 5, "%s: Tuning PHY to tx_dll,rx_dll of %u,%u and read_delay of %u", __func__,
                search_point.tx_dll, search_point.rx_dll, search_point.read_delay);

    j7ospi_phy_apply_setting(ospi, &search_point);

    return EOK;
}

static int j7ospi_calibrate_phy(j7ospi_dev_t *const ospi, const snor_cmd_t *const cmd)
{
    int ret = EOK;
    if(ospi->phy_enable == J7OSPI_PHY_OTP1_TUNE) {
        j7_phy_setting  otp = {.rx_dll = 0, .tx_dll = 0, .read_delay = 0};

#ifdef  J7OSPI_UDMA_SUPPORT
        /* Enable PHY */
        j7ospi_phy_enable(ospi, 1);
        /* Perform the Basic PHY configuration for the OSPI controller */
        j7ospi_phy_basic_config(ospi);
#endif

        ospi->calibrating = true;

        /* Use the normal algorithm */
        ret = j7ospi_phy_find_otp1(ospi, &otp);

        /* Configure phy for the optimal tuning point */
        j7ospi_phy_apply_setting(ospi, &otp);

        ospi->calibrating = false;

#ifdef  J7OSPI_UDMA_SUPPORT
         /* Disable PHY */
        j7ospi_phy_enable(ospi, 0);
#endif
    } else if (ospi->phy_enable == J7OSPI_PHY_DDR_TUNE) {
        uintptr_t const base = ospi->ctrl_vbase;
        uint32_t        reg;

        /* Reset PHY */
        reg = in32(base + J7OSPI_CONFIG);
        reg &= ~(J7OSPI_CONFIG_PHY | J7OSPI_CONFIG_PHY_PIPELINE);
        out32(base + J7OSPI_CONFIG, reg);

        j7ospi_phy_avg_vtm_temp(ospi, J7OSPI_PHY_VTM_TARGET); /* Dummy Call*/

        ret = j7ospi_spi_phy_ddr_tune(ospi);
    } else {
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 0, "%s: Invalid PHY tuning mode.", __func__);
        ret = EIO;
    }

    if(ret == EOK) {
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 0, "%s: PHY Calibration succeeded", __func__);
    } else {
        snor_slogf(_SLOG_INFO, ospi->ctrl.verbosity, 0, "%s: PHY Calibration failed", __func__);
    }

    return (ret);
}

static int j7ospi_write_reg(snor_ctrl_t *const snor, const snor_cmd_t *const cmd, uint8_t *const regs, const uint32_t len)
{
    j7ospi_dev_t *const ospi = (j7ospi_dev_t *)snor;

    if (cmd->cfg != NULL) {
        j7ospi_cfg_bus(snor, cmd->cfg);
    }

    j7ospi_write_setup(ospi, cmd);

    return j7ospi_command_write(ospi, cmd, regs, len);
}

static int j7ospi_wait_write_sram(const j7ospi_dev_t *const ospi, uint32_t *level)
{
    const uintptr_t base = ospi->ctrl_vbase;
    uint32_t  lvl;
    uint32_t  retry = 10000;

    do {
        lvl = in32(base + J7OSPI_SRAMLEVEL);
        lvl = (lvl >> J7OSPI_SRAMLEVEL_WR_LSB) & J7OSPI_SRAMLEVEL_WR_MASK;
        if (lvl < ospi->fifo_depth / 2) {
            *level = lvl;
            return (EOK);
        }
        nanospin_ns(100);
    } while (--retry > 0);

    snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: timed out", __func__);

    return (ETIMEDOUT);
}

static int j7ospi_ind_write(j7ospi_dev_t *const ospi, const snor_cmd_t *const cmd, const uint8_t *buffer, const uint32_t len)
{
    const uintptr_t  base = ospi->ctrl_vbase;
    uint32_t    remain = len;
    uint32_t    level, nbytes;
    int         ret = -1;
    const uint32_t offset = cmd->addr;

    // Set start address
    out32(base + J7OSPI_INDIRECTWRSTARTADDR, offset);
    // Set write length
    out32(base + J7OSPI_INDIRECTWRBYTES, len);
    // reset write water mark
    out32(base + J7OSPI_INDIRECTWRWATERMARK, 0);
    // set write water mark
    out32(base + J7OSPI_INDIRECTWRWATERMARK, ospi->fifo_depth / 2 / 4);

    // start indirect write xfer
    out32(base + J7OSPI_INDIRECTWR,
            in32(base + J7OSPI_INDIRECTWR) | J7OSPI_INDIRECTWR_START_MASK);

    while (remain > 0) {
        ret = j7ospi_wait_write_sram(ospi, &level);
        if (ret != EOK) {
            break;
        }
        nbytes = (ospi->fifo_depth / 2 - level) * 4;
        if (nbytes > remain) {
            nbytes = remain;
        }

        j7ospi_write_fifo_data(ospi, buffer, nbytes);
        buffer += nbytes;
        remain -= nbytes;
    }

    if (ret == EOK) {
        ret = j7ospi_wait_for_bit(base + J7OSPI_INDIRECTWR, J7OSPI_INDIRECTWR_DONE_MASK, 0);
        if (ret == EOK) {
            out32(base + J7OSPI_INDIRECTWR, J7OSPI_INDIRECTWR_DONE_MASK);

            j7ospi_wait_idle(ospi);

            return (len);
        }
    }

    out32(base + J7OSPI_INDIRECTWR, J7OSPI_INDIRECTWR_CANCEL_MASK);

    return (-1);
}

static int j7ospi_write(snor_ctrl_t *const snor, const snor_cmd_t *const cmd, uint8_t *const buf, const uint32_t len)
{
    j7ospi_dev_t *const ospi = (j7ospi_dev_t *)snor;
    int ret;

    if (len == 0) {
        ret = j7ospi_command_write(ospi, cmd, buf, len);
        if (ret != EOK) {
            errno = ret;
            return (-1);
        } else {
            return (len);
        }
    }

    ret = j7ospi_map_dacmem(ospi);
    if (ret != EOK) return (-1);

    if (cmd->cfg != NULL) {
        j7ospi_cfg_bus(snor, cmd->cfg);
    }

    j7ospi_write_setup(ospi, cmd);

#ifdef  J7OSPI_UDMA_SUPPORT
    j7ospi_phy_pipeline_enable(ospi, 0);
    if (ospi->dma_enable) {
        memcpy(ospi->v_buf, buf, len);
        const paddr_t dst = ospi->mem_pbase + cmd->addr;
        ret = j7ospi_udma_xfer(ospi, (paddr_t)ospi->p_buf, dst, len);
        if (ret != EOK) {
            snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: DMA xfer failed, offset, %x, len %x", __func__, cmd->addr, len);
            return (-1);
        }
    } else {
#else
    {
#endif
        return j7ospi_ind_write(ospi, cmd, buf, len);
    }

    ret = j7ospi_wait_idle(ospi);
    if (ret != EOK) {
        errno = ret;
        return (-1);
    }

    return (len);
}

static int j7ospi_read_reg(snor_ctrl_t *const snor, const snor_cmd_t *const cmd, uint8_t *const regs, const uint32_t len)
{
    j7ospi_dev_t  *const ospi = (j7ospi_dev_t *)snor;

    if (cmd->cfg != NULL) {
        j7ospi_cfg_bus(snor, cmd->cfg);
    }

    j7ospi_read_setup(ospi, cmd);

    return j7ospi_command_read(ospi, cmd, regs, len);
}

static int j7ospi_wait_read_sram(const j7ospi_dev_t *const ospi, uint32_t *level)
{
    const uintptr_t base = ospi->ctrl_vbase;
    uint32_t    lvl;
    uint32_t    retry = 10000;

    do {
        lvl = in32(base + J7OSPI_SRAMLEVEL) & J7OSPI_SRAMLEVEL_RD_MASK;
        if (lvl) {
            *level = lvl;
            return (EOK);
        }
        nanospin_ns(100);
    } while (--retry > 0);

    snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: timed out", __func__);

    return (ETIMEDOUT);
}

static int j7ospi_ind_read(j7ospi_dev_t *const ospi, const snor_cmd_t *const cmd, uint8_t *buffer, const uint32_t len)
{
    const uintptr_t base = ospi->ctrl_vbase;
    uint32_t    remain = len;
    uint32_t    level, nbytes;
    int         ret = -1;
    const uint32_t  offset = cmd->addr;

    // Set start address
    out32(base + J7OSPI_INDIRECTRDSTARTADDR, offset);
    // Set read length, always asks for multiple of FIFO width
    out32(base + J7OSPI_INDIRECTRDBYTES, (len + 3) & ~3);
    // Set read water mark
    out32(base + J7OSPI_INDIRECTRDWATERMARK, ospi->fifo_depth / 2 / 2);

    // start indirect read xfer
    out32(base + J7OSPI_INDIRECTRD,
            in32(base + J7OSPI_INDIRECTRD) | J7OSPI_INDIRECTRD_START_MASK);

    while (remain) {
        ret = j7ospi_wait_read_sram(ospi, &level);
        if (ret != EOK) break;
        nbytes = level * sizeof(uint32_t);
        if (nbytes > remain) {
            nbytes = remain;
        }

        j7ospi_read_fifo_data(ospi, buffer, nbytes);
        buffer += nbytes;
        remain -= nbytes;
    }

    if (ret == EOK) {
        ret = j7ospi_wait_for_bit(base + J7OSPI_INDIRECTRD, J7OSPI_INDIRECTRD_DONE_MASK, 0);
        if (ret == EOK) {
            out32(base + J7OSPI_INDIRECTRD, J7OSPI_INDIRECTRD_DONE_MASK);
            return (len);
        }
    }

    out32(base + J7OSPI_INDIRECTRD, J7OSPI_INDIRECTRD_CANCEL_MASK);

    return (-1);
}

static int j7ospi_read(snor_ctrl_t *const snor, const snor_cmd_t *const cmd, uint8_t *const buf, const uint32_t len)
{
    j7ospi_dev_t *const ospi = (j7ospi_dev_t *)snor;
    int ret;

    ret = j7ospi_map_dacmem(ospi);
    if (ret != EOK) return (-1);

    if (cmd->cfg != NULL) {
        j7ospi_cfg_bus(snor, cmd->cfg);
    }

    j7ospi_read_setup(ospi, cmd);

#ifdef  J7OSPI_UDMA_SUPPORT
    if (ospi->dma_enable) {
        j7ospi_phy_pipeline_enable(ospi, 1);
        ret =  j7ospi_direct_read_execute_dma(ospi, buf, cmd->addr, len);
        j7ospi_phy_pipeline_enable(ospi, 0);
        return ret;
    } else {
#else
    {
#endif
        return j7ospi_ind_read(ospi, cmd, buf, len);
    }
}

static int j7ospi_dinit(void *const hdl)
{
    j7ospi_dev_t  *const ospi = hdl;

    munmap_device_io(ospi->ctrl_vbase, J7_OSPIC_SIZE);
    munmap_device_io(ospi->mem_vbase, ospi->mem_size);

#ifdef  J7OSPI_UDMA_SUPPORT
    if (ospi->dma_enable) {
        j7ospi_dinit_udma(ospi);
    }
#endif

    free(hdl);

    return (EOK);
}

static void j7ospi_atexit_dinit(void)
{
#ifdef  J7OSPI_UDMA_SUPPORT
    j7ospi_dinit_udma(NULL);
#endif
}

static void j7ospi_dtr_enable(const j7ospi_dev_t *const ospi, const int enable)
{
    const uintptr_t base = ospi->ctrl_vbase;
    uint32_t    reg;

    reg = in32(base + J7OSPI_CONFIG);
    if (enable) {
        reg |= (J7OSPI_CONFIG_DTR_PROTO);
    } else {
        reg &= ~(J7OSPI_CONFIG_DTR_PROTO);
    }
    out32(base + J7OSPI_CONFIG, reg);
}

static int j7ospi_set_bus_protocol(j7ospi_dev_t *const ospi, const uint32_t proto)
{
    if (ospi->proto == proto) return (EOK);

    switch (proto & SNOR_BUSPROTO_MASK) {
        case SNOR_BUSPROTO_1_1_1:
            ospi->inst_width = J7OSPI_BUS_TYPE_SINGLE;
            ospi->addr_width = J7OSPI_BUS_TYPE_SINGLE;
            ospi->data_width = J7OSPI_BUS_TYPE_SINGLE;
            j7ospi_dtr_enable(ospi, 0);
            break;
        case SNOR_BUSPROTO_8_8_8:
            ospi->inst_width = J7OSPI_BUS_TYPE_OCTAL;
            ospi->data_width = J7OSPI_BUS_TYPE_OCTAL;
            ospi->addr_width = J7OSPI_BUS_TYPE_OCTAL;
            j7ospi_dtr_enable(ospi, 0);
            break;
        case SNOR_BUSPROTO_8_8_8_DTR:
            ospi->inst_width = J7OSPI_BUS_TYPE_OCTAL;
            ospi->data_width = J7OSPI_BUS_TYPE_OCTAL;
            ospi->addr_width = J7OSPI_BUS_TYPE_OCTAL;
            j7ospi_dtr_enable(ospi, 1);
            break;
        default:
            return (ENOTSUP);
    }

    ospi->proto = proto;

    return (EOK);
}

static int j7ospi_select_chip(snor_ctrl_t *ctrl, uint8_t cs)
{
    j7ospi_dev_t    *ospi = (j7ospi_dev_t *)ctrl;

    // use default configuration before the chip is identified
    if (ctrl->chip[cs].pagesz == 0) {
        ctrl->chip[cs].pagesz = 256;
        ctrl->chip[cs].addrsz = 4;
        ctrl->chip[cs].sectsz = 1 << 17;
    }

    // chip configuration changed?
    if (cs == ospi->current_cs) {
        if ((ospi->page_size != ctrl->chip[cs].pagesz) ||
            (ospi->sector_size != ctrl->chip[cs].sectsz) ||
            (ospi->chip_size != ctrl->chip[cs].chipsz)) {
            ospi->current_cs++;     // anything other than current_cs
        }
    }

    if (cs != ospi->current_cs) {
        j7ospi_controller_enable(ospi, 0);

        j7ospi_configure_sizes(ospi,
                ctrl->chip[cs].pagesz, ctrl->chip[cs].sectsz, ctrl->chip[cs].addrsz);
        /* configure the chip select */
        j7ospi_chipselect(ospi, cs);

        j7ospi_controller_enable(ospi, 1);

        ospi->chip_size   = ctrl->chip[cs].chipsz;
        ospi->page_size   = ctrl->chip[cs].pagesz;
        ospi->sector_size = ctrl->chip[cs].sectsz;

        ospi->current_cs  = cs;
    }

    return (EOK);
}

static int j7ospi_post_ident(snor_ctrl_t *snor, int cs)
{
    snor_chip_t  *chip = &snor->chip[cs];

    if ((chip->cfg.bus_proto & SNOR_BUSPROTO_BUS_MASK) == SNOR_BUSPROTO_8_8_8) {
        chip->align = 2;
    } else {
        chip->align = 1;
    }

    /* PHY calibration */
    j7ospi_dev_t *const ospi = (j7ospi_dev_t *)snor;
    snor_cmd_t   cmd;
    if (ospi->phy_enable != J7OSPI_PHY_OFF) {
        SNOR_SET_CMD(cmd, &chip->op_rd, &chip->rdcfg, ospi->pattern_offset & ~1);
        ospi->use_phy = 1;
        if (j7ospi_calibrate_phy(ospi, &cmd) != EOK) {
            ospi->use_phy = 0;
            snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: PHY Calibration failed", __func__);
        }
    }

    return (EOK);
}

static int j7ospi_cfg_bus(snor_ctrl_t *const snor, snor_cfg_t *const cfg)
{
    j7ospi_dev_t    *ospi = (j7ospi_dev_t *)snor;

    /* no need to re-config if there is no bus changes */
    if (memcmp(cfg, &ospi->buscfg, sizeof(*cfg)) == 0) return (EOK);

    memcpy(&ospi->buscfg, cfg, sizeof(*cfg));

    j7ospi_select_chip(snor, cfg->cs);

    if ((cfg->clk > 0) && (cfg->clk != ospi->busclk)) {
        j7ospi_controller_enable(ospi, 0);

        j7ospi_config_baudrate_div(ospi, cfg->clk);
        j7ospi_delay(ospi);

        j7ospi_controller_enable(ospi, 1);
    }

    j7ospi_set_bus_protocol(ospi, cfg->bus_proto);

    /* Set Dual-byte Opcode Mode */
    uint32_t reg;
    if (ospi->buscfg.cflgs & (SNOR_CFGFLGS_DBOP | SNOR_CFGFLGS_DBIOP)) {
        reg = in32(ospi->ctrl_vbase + J7OSPI_CONFIG);
        reg |= (1 << J7OSPI_CONFIG_DUAL_BYTE_OPCODE_LSB);
        out32(ospi->ctrl_vbase + J7OSPI_CONFIG, reg);
    } else {
        reg = in32(ospi->ctrl_vbase + J7OSPI_CONFIG);
        reg &= ~(1 << J7OSPI_CONFIG_DUAL_BYTE_OPCODE_LSB);
        out32(ospi->ctrl_vbase + J7OSPI_CONFIG, reg);
    }

    const uint8_t dqs_en = (uint8_t)((cfg->bus_proto & SNOR_BUSPROTO_DQS) ? 1 : 0);
    if (dqs_en != ospi->dqs_en) {
        ospi->dqs_en = dqs_en;
        j7ospi_readdata_capture(ospi, !ospi->rclk_en, ospi->read_delay, ospi->dqs_en);
    }

    return (EOK);
}

static int j7ospi_map_dacmem(j7ospi_dev_t *const ospi)
{
    uint32_t  mapsize;

    if (ospi->mem_size == 0) {     // default direct memory size
        mapsize = J7OSPI_DFLT_MEMSIZE;
    } else if (ospi->mem_size < ospi->chip_size) {  // remap data memory to fit in the entire flash
        munmap_device_io(ospi->mem_vbase, ospi->mem_size);
        ospi->mem_size = 0;
        mapsize = ospi->chip_size;
    } else {
        return (EOK);
    }

    ospi->mem_vbase = mmap_device_io(mapsize, ospi->mem_pbase);
    if (ospi->mem_vbase == (uintptr_t)MAP_FAILED) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: map OSPI data memory failed", __func__);
        return (errno);
    }

    ospi->mem_size = mapsize;

    return (EOK);
}

static int j7ospi_options(j7ospi_dev_t *const ospi)
{
    char    *value, *freeptr, *options;
    int     opt;
    int     ret = EOK;

    static char *supported_opts[] = {
        "rclk",     // reference clock
#define OPT_RCLK        0
        "clk",      // SPI bus clock
#define OPT_CLK         1
        "base",     // OSPI controller base address
#define OPT_BASE        2
        "data",     // OSPI data port address
#define OPT_DATA        3
        "rdelay",   // Read Delay (cycles)
#define OPT_RDLY        4
    #ifdef  J7OSPI_UDMA_SUPPORT
        "phy",      // PHY mode
#define OPT_PHY         5
        "poffset",  // PHY tuning pattern offset
#define OPT_POFF        6
        "pdelay",   // Phase Delay Element
#define OPT_PDELAY      7
        "phy_mode", // PHY Master Bypass Mode
#define OPT_PHY_MODE    8
        "dma",      // DMA mode
#define OPT_DMA         9
        "ch",       // Channel number
#define OPT_CH          10
        "mem",      // typed memory name
#define OPT_MEM         11
    #endif
        NULL
    };

    // default values
    ospi->ctrl_pbase = J7_OSPIC0_BASE;
    ospi->mem_pbase  = J7_OSPIC0_DATA_BASE;
    ospi->refclk     = 0;
    ospi->busclk     = J7OSPI_DFLT_BUSCLK;
    ospi->fifo_depth = J7OSPI_FIFO_DEPTH;
    ospi->fifo_width = J7OSPI_FIFO_WIDTH;
    ospi->tshsl_ns   = 60;
    ospi->tchsh_ns   = 60;
    ospi->tslch_ns   = 60;
    ospi->tsd2d_ns   = 60;
    ospi->rclk_en    = 0;
    ospi->read_delay = 0;
    ospi->dqs_en     = 1;
    ospi->dma_enable = 0;
    ospi->phy_enable = J7OSPI_PHY_OFF;
    ospi->use_phy = 0;
    ospi->pattern_offset = J7OSPI_TUNING_PATTERN_OFFSET;
    ospi->current_cs = 0xFFu;
    ospi->tpmfd      = NOFD;
    ospi->ch         = -1;
    ospi->calibrating = false;
    ospi->phase_delay = 3;
    ospi->phy_mode   = J7OSPI_PHY_MODE_MASTER;

    freeptr = ospi->ctrl.soc_opts;
    if (freeptr == NULL) return (ret);

    options = freeptr;
    while ((options != NULL) && (*options != '\0')) {
        opt = snor_soc_getsubopt(&options, supported_opts, &value);
        switch (opt) {
            case OPT_RCLK:
                ret = snor_options_arg_value(__func__, supported_opts[opt], value);
                if (ret == EOK) {
                    ospi->refclk = (uint32_t)strtoul(value, NULL, 0);
                }
                break;
            case OPT_CLK:
                ret = snor_options_arg_value(__func__, supported_opts[opt], value);
                if (ret == EOK) {
                    ospi->busclk = (uint32_t)strtoul(value, NULL, 0);
                }
                break;
            case OPT_BASE:
                ret = snor_options_arg_value(__func__, supported_opts[opt], value);
                if (ret == EOK) {
                    ospi->ctrl_pbase = (paddr_t)strtoul(value, NULL, 0);
                }
                break;
            case OPT_DATA:
                ret = snor_options_arg_value(__func__, supported_opts[opt], value);
                if (ret == EOK) {
                    ospi->mem_pbase = (paddr_t)strtoul(value, NULL, 0);
                }
                break;
            case OPT_RDLY:
                ret = snor_options_arg_value(__func__, supported_opts[opt], value);
                if (ret == EOK) {
                    ospi->read_delay = (uint32_t)strtoul(value, NULL, 0);
                }
                break;
#ifdef  J7OSPI_UDMA_SUPPORT
            case OPT_PHY:
                ret = snor_options_arg_value(__func__, supported_opts[opt], value);
                if (ret == EOK) {
                    if (strcmp(value, "off") == 0) {
                        ospi->phy_enable = J7OSPI_PHY_OFF;
                    } else if (strcmp(value, "ddr") == 0) {
                        ospi->phy_enable = J7OSPI_PHY_DDR_TUNE;
                    } else if (strcmp(value, "otp1") == 0) {
                        ospi->phy_enable = J7OSPI_PHY_OTP1_TUNE;
                    } else {
                        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s:unknown phy option: %s.  Default to off.", __func__, value);
                    }
                }
                break;
            case OPT_POFF:
                ret = snor_options_arg_value(__func__, supported_opts[opt], value);
                if (ret == EOK) {
                    ospi->pattern_offset = (uint32_t)strtoul(value, NULL, 0);
                }
                break;
            case OPT_PDELAY:
                ret = snor_options_arg_value(__func__, supported_opts[opt], value);
                if (ret == EOK) {
                    ospi->phase_delay = (uint32_t)strtoul(value, NULL, 0);
                }
                break;
            case OPT_PHY_MODE:
                ret = snor_options_arg_value(__func__, supported_opts[opt], value);
                if (ret == EOK) {
                    if (strcmp(value, "bypass") == 0) {
                        ospi->phy_mode = J7OSPI_PHY_MODE_BYPASS;
                    } else if (strcmp(value, "master") == 0) {
                        ospi->phy_mode = J7OSPI_PHY_MODE_MASTER;
                    } else {
                        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s:unknown phy_mode option: %s.  Default to master.", __func__, value);
                    }
                }
                break;
            case OPT_DMA:
                ret = snor_options_arg_value(__func__, supported_opts[opt], value);
                if (ret == EOK) {
                    ospi->dma_enable = (uint8_t)strtoul(value, NULL, 0);
                }
                break;
            case OPT_CH:
                ret = snor_options_arg_value(__func__, supported_opts[opt], value);
                if (ret == EOK) {
                    ospi->ch = (int)strtoul(value, NULL, 0);
                }
                break;
            case OPT_MEM:
                ret = snor_options_arg_value(__func__, supported_opts[opt], value);
                ospi->tpmfd = posix_typed_mem_open(value, O_RDWR, POSIX_TYPED_MEM_ALLOCATE_CONTIG);
                if (ospi->tpmfd == -1) {
                    snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s: Typed memory [%s] open failed", __func__, value);
                    ret = EINVAL;
                }
                break;
#endif
            default:
                snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "%s:unknown option: %s", __func__, value);
                break;
        }

        if (ret != EOK) break;
    }

    free(freeptr);

    return (ret);
}

static int j7ospi_init(j7ospi_dev_t *const ospi)
{
    static const snor_func_t j721e_ospi_func = {
        .dinit = j7ospi_dinit,
        .cfg_bus = j7ospi_cfg_bus,
        .post_ident = j7ospi_post_ident,
        .dstripe = NULL,
        .read_reg = j7ospi_read_reg,
        .write_reg = j7ospi_write_reg,
        .read = j7ospi_read,
        .write = j7ospi_write
    };

    /* check command line options */
    if (j7ospi_options(ospi) != EOK) {
        free(ospi);
        return (ENODEV);
    }

    ospi->ctrl_vbase = mmap_device_io(J7_OSPIC_SIZE, ospi->ctrl_pbase);
    if (ospi->ctrl_vbase == (uintptr_t)MAP_FAILED) {
        snor_slogf(_SLOG_ERROR, ospi->ctrl.verbosity, 0, "map OSPI controller failed");
        free(ospi);
        return (errno);
    }

    /* Temporary until JI2893371 can be fixed
     * The flash resmgr is not calling board specific close */
    atexit(j7ospi_atexit_dinit);

    if (j7ospi_map_dacmem(ospi) != EOK) {
        munmap_device_io(ospi->ctrl_vbase, J7_OSPIC_SIZE);
        free(ospi);
        return (errno);
    }

    j7ospi_wait_idle(ospi);
    j7ospi_controller_init(ospi);

    memcpy(&ospi->ctrl.funcs, &j721e_ospi_func, sizeof(snor_func_t));
    ospi->ctrl.flags  = 0;  // TBD
    ospi->ctrl.hcaps  = SNOR_HCAPS_RD_1_1_1 |
                        SNOR_HCAPS_RD_1_1_1_FAST |
                        SNOR_HCAPS_RD_8_8_8 |
                        SNOR_HCAPS_DTR |
                        SNOR_HCAPS_PP_8_8_8 |
                        SNOR_HCAPS_PP_1_1_1;
    ospi->ctrl.hcaps |= (ospi->dqs_en == 1) ? SNOR_HCAPS_DQS : 0;
    ospi->ctrl.ccaps |= SNOR_CCAPS_PPAWREN |   // controller automatically issues WREN for page program
                        SNOR_CCAPS_PPASP;      // controller automatically polls status for page program

    if (ospi->dma_enable == 0) return (EOK);

#ifdef  J7OSPI_UDMA_SUPPORT
    if (j7ospi_init_udma(ospi) == EOK) {
        return (EOK);
    }

    munmap_device_io(ospi->ctrl_vbase, J7_OSPIC_SIZE);
    munmap_device_io(ospi->mem_vbase, ospi->mem_size);

    free(ospi);
#endif

    return (ENODEV);
}

int32_t f3s_j7ospi_open(f3s_socket_t *socket, const uint32_t flags)
{
    j7ospi_dev_t *dev;

    if (socket->memory) return (EOK);

    /* Allocate driver handle */
    dev = snor_alloc_handle(socket, sizeof(j7ospi_dev_t));
    if (dev == NULL) return (ENOMEM);

    socket->name = (unsigned char*)"TI OSPI";

    return j7ospi_init(dev);
}

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL$ $Rev$")
#endif
