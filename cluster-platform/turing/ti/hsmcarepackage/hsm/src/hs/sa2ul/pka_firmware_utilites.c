/*
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file pka_firmware_utilites.c
 *
 * \brief PKA Firmware Utilitites
 */

#include <types/ftbool.h>
#include <sa2ul_pka.h>
#include <config.h>

u32 get_pka_firmware_load_addr(void)
{
	return CONFIG_SECURITY_SA2UL_PKA_FW_ROM_ADDR;
}
