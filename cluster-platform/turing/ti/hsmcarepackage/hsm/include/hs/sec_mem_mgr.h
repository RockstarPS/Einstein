/*
 * Copyright (C) 2018-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sec_mem_mgr.h
 *
 * \brief A union data structure for scratch memory usage in security.
 * This will be used to allocate any required scratch memory statically
 * at build time.
 *
 */
#ifndef SEC_MEM_MGR_H
#define SEC_MEM_MGR_H

/**
 * defines memory required for certificate parsing.
 *
 * \param cert buffer to hold the certificate
 *
 * \param cert_parsed buffer to hold the parsed certificate structure.
 *
 * Current memory requirement is 5.5 KB.
 */


/**
 * Initialize the mem_mgr structure.
 */
void sec_mem_mgr_init(void);

/**
 * Return a pointer to memory that be used as scratch
 * for certificate parsing.
 *
 * This function blocks until the memory is available.
 *
 * \return pointer to scratch memory.
 */
void *get_sec_scratch_mem(void);

/**
 * Release the scratch memory being used.
 */
void release_sec_scratch_mem(void);

#endif
