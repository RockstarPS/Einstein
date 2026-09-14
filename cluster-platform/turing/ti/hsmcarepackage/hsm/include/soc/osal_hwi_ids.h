/*
 * System Firmware Source File
 *
 * OSAL HWI ID enum for AM6 device
 *
 * Copyright (C) 2021-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file am62x/osal_hwi_ids.h
 *
 * \brief OSAL HWI ID enum for AM62 device.
 *
 * Because interrupt handlers must be statically configured we define all
 * possible interrupts here and give them an ID.
 */

#ifndef AM62X_OSAL_HWI_IDS_H
#define AM62X_OSAL_HWI_IDS_H

enum HWI_IDS {
	HWI_SEC_LO = 0,
	HWI_USER_LO = 1,
	HWI_SEC_LO_MAIN = 2,
	HWI_USER_LO_MAIN = 3,
	HWI_SEC_DEBUG_AP = 4,
	HWI_SEC_DMSC_FWL_EXCP = 5,
	HWI_SEC_CMBN_FWL_EXCP = 6,
	HWI_SEC_DM2TIFS = 7,
	HWI_USER_DM2TIFS = 8,
	HWI_MAX,
};

/** List of IRQs for Safety domain (exception is mandatory HWI_SEC_HI */
#define OSAL_ENABLE_LIST_SAFETY_DOMAIN_IRQS \
	HWI_SEC_LO,		\
	HWI_USER_LO

/**
 * List of IRQs for non Safety domain - These will be pulled to disable
 * during Safety function - to prevent any communication
 */
#define OSAL_ENABLE_LIST_NON_SAFETY_DOMAIN_IRQS	\
	HWI_SEC_LO_MAIN,	\
	HWI_USER_LO_MAIN

/** List of IRQs to enable at the point where firmware is ready to accept */
#define OSAL_ENABLE_LIST_IRQS_POST_CONFIG \
	OSAL_ENABLE_LIST_SAFETY_DOMAIN_IRQS, \
	OSAL_ENABLE_LIST_NON_SAFETY_DOMAIN_IRQS

#endif /* AM62X_OSAL_HWI_IDS_H */
