/*
 *  \file cred.h
 *
 * \brief functions to read/write credential registers
 *
 * Copyright (C) 2020-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef CRED_H
#define CRED_H
#include <types/ftbool.h>
#include <types/fterr.h>
#include <masters.h>

/*  Bit fields for the credentials register on K3LC */
#define CRED_PRIVID_START (16U)
#define CRED_PRIVID_END (23U)

#define CRED_PRIV_START (24U)
#define CRED_PRIV_END (25U)

#define CRED_SEC_START (26U)
#define CRED_SEC_END (26U)

/*  This field is only valid for PKTDMA */
#define CRED_CHECK_SEC_START (31U)
#define CRED_CHECK_SEC_END (31U)

/* This is CRED Channel/ring offser address */
#define CRED_RING_ADDR_OFFSET (16U)


/**
 * \brief Format the Ring credential control word
 *
 * \param creds master credentials used to insert values to the control word
 *
 * \return Formatted control word to be used for cred programming
 */
u32 cred_format_ctrl_word(struct master_creds *creds);

fterr cred_get_region(u8 host_id, u32 isc_id, u32 ring_id, u32 *control);

fterr cred_set_region(u8 host_id, u32 isc_id, u32 ring_id, u32 control);


#endif
