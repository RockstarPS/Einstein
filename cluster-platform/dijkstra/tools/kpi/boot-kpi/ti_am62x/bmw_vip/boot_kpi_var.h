/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2025] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file boot_kpi_var.h
 *
 * \brief
 * Visteon KPI header file for defining variable in memory section
 *
 ******************************************************************************/

#ifndef BOOT_KPI_VAR_H
#define BOOT_KPI_VAR_H

#ifdef BOOT_KPI_LOG_EN
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "boot_kpi.h"

/******************************************************************************
 *  INTERNAL DEFINES
 *****************************************************************************/
#define SHARED_MEMORY_ADDRESS 0xA0008000
// Define a pointer to the shared memory address
KPI_LOG_t *KPI_Records = (KPI_LOG_t *)SHARED_MEMORY_ADDRESS;

#endif /*BOOT_KPI_LOG_EN*/
#endif /* BOOT_KPI_VAR_H */

