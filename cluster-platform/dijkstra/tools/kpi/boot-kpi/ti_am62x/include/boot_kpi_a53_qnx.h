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
 * \file boot_kpi_a53_qnx.h
 *
 * \brief
 * Visteon KPI header file for QNX applications
 *
 ******************************************************************************/
 
#ifndef BOOT_KPI_A53_QNX_H
#define BOOT_KPI_A53_QNX_H

#ifdef BOOT_KPI_LOG_EN
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include <sys/neutrino.h>
#include <sys/mman.h>
#include "boot_kpi.h"

/******************************************************************************
 *  FUNCTION DECLARATIONS
 *****************************************************************************/
 static inline KPI_LOG_t *boot_kpi_map(void)
{
    return (KPI_LOG_t *)mmap_device_memory(NULL, sizeof(KPI_LOG_t),
     PROT_READ | PROT_WRITE | PROT_NOCACHE, 0, SHARED_MEMORY_ADDRESS);
}

static inline void boot_kpi_unmap(KPI_LOG_t *addr)
{
    munmap_device_memory(addr, sizeof(KPI_LOG_t));
}

/******************************************************************************
 *  DEFINES
 *****************************************************************************/
#define BOOT_KPI_STRCLCPY(dest, src, size)                                                                \
    do {                                                                                                  \
        size_t i;                                                                                         \
        for (i = 0; i < ((size)-1) && ((src)[i] != '\0'); i++)                                            \
        {                                                                                                 \
            (dest)[i] = (src)[i];                                                                         \
        }                                                                                                 \
        (dest)[i] = '\0';                                                                                 \
    } while (0)

#define BOOT_KPI_COUNT_BITS(num, count)                                                                   \
    do {                                                                                                  \
        (count) = 0;                                                                                      \
        unsigned int _num = (num);                                                                        \
        while (_num > 0)                                                                                  \
        {                                                                                                 \
            (count) += _num & 1;                                                                          \
            _num >>= 1;                                                                                   \
        }                                                                                                 \
    } while (0)

#define BOOT_KPI_CLEAR()                                                                                  \
    do {                                                                                                  \
        KPI_LOG_t *pKPI_Records = boot_kpi_map();                                                         \
        if (pKPI_Records != MAP_FAILED) {                                                                 \
            memset((void *)pKPI_Records, 0x00, sizeof(KPI_LOG_t));                                        \
            boot_kpi_unmap(pKPI_Records);                                                                 \
        }                                                                                                 \
    } while (0)

#define BOOT_KPI_LOG(Id, Text)                                                                            \
    do {                                                                                                  \
        uint32_t bitCount = 0;                                                                            \
        uint32_t time_u32 = (uint32_t)( ClockCycles() / 200000U );                                            \
        if ((Id) >= KPI_ID_FIRST_INV && (Id) < KPI_ID_LAST_INV) {                                         \
            KPI_LOG_t *pKPI_Records = boot_kpi_map();                                                     \
            if (MAP_FAILED != pKPI_Records) {                                                             \
                if (pKPI_Records->record[Id].Sig_u16 == 0) {                                              \
                    pKPI_Records->record[Id].Time_u32 = time_u32 + KPI_POWERUP_OFFSET;                    \
                    BOOT_KPI_STRCLCPY(pKPI_Records->record[Id].Marker_u8A, (Text), KPI_MARKER_MAX_TEXT);  \
                    BOOT_KPI_COUNT_BITS(pKPI_Records->record[Id].Time_u32, bitCount);                     \
                    pKPI_Records->record[Id].Sig_u16 = 0x01 + (Id) + bitCount;                            \
                } else {                                                                                  \
                    /* slot already used, do nothing */                                                   \
                }                                                                                         \
                boot_kpi_unmap(pKPI_Records);                                                             \
            }                                                                                             \
        }                                                                                                 \
    } while (0)

#else
#define BOOT_KPI_CLEAR()        /* No operation */
#define BOOT_KPI_LOG(Id, Text)  /* No operation */

#endif /*BOOT_KPI_LOG_EN*/
#endif /* BOOT_KPI_A53_QNX_H */
