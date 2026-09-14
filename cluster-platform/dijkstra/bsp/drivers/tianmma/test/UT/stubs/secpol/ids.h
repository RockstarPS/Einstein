/*
 * $QNXLicenseC:
 * Copyright 2018-2021, QNX Software Systems. All Rights Reserved.
 *
 * You must obtain a written license from and pay applicable license fees to QNX
 * Software Systems before you may reproduce, modify or distribute this software,
 * or any work that includes all or part of this software.   Free development
 * licenses are available for evaluation and non-commercial purposes.  For more
 * information visit http://licensing.qnx.com or email licensing@qnx.com.
 *
 * This file may contain contributions from others.  Please review this entire
 * file for other proprietary rights or license notices, as well as the QNX
 * Development Suite License Guide at http://licensing.qnx.com/license-guide/
 * for other information.
 * $
 */

/**
 * @file ids.h
 * @brief This file defines the ID parsing API
 */

#ifndef _SECPOL_IDS_H_INCLUDED
#define _SECPOL_IDS_H_INCLUDED


int get_ids_from_arg(const char * __arg,
                     uid_t * __uid,
                     gid_t * __gid,
                     gid_t * __supp_gids,
                     size_t * __supp_count);

#endif /* _SECPOL_IDS_H_INCLUDED */