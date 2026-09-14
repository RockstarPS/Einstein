/*
 * System Firmware Source File
 *
 * Host IDs for internal use
 *
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file hosts_internal.h
 *
 * \brief Host IDs for internal use by system firmware
 */

#ifndef HOSTS_INTERNAL_H
#define HOSTS_INTERNAL_H

/* Host IDs for internal DMSC use */

/** DMSC RM: Device Management and Security Control - resource management
 *  subsystem */
#define HOST_ID_RM (240U)

/** None or a wildcard host ID, used for bookkeeping an item or resource on
 *  behalf of any processing entity - and not exclusive to one.
 */
#define HOST_ID_NONE (255U)

#ifdef HOST_ID_DMSC
/* Create name alias for HOST_ID_DMSC to enable legacy platform compatibility */
#define HOST_ID_TIFS HOST_ID_DMSC
#endif

#ifdef HOST_ID_DM2DMSC
/* Create name aliases to DM2DMSC to enable legacy platform compatibility */
#define HOST_ID_DM2TIFS HOST_ID_DM2DMSC
#define HWI_USER_DM2TIFS HWI_USER_DM2DMSC
#define HWI_SEC_DM2TIFS HWI_SEC_DM2DMSC
#endif

#endif /* HOSTS_INTERNAL_H */
