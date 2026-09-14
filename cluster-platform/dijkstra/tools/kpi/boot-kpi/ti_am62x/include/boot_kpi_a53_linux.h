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
 * \file boot_kpi_a53_linux.h
 *
 * \brief
 * Visteon KPI header file for TI AM62X A53 Core - Linux
 *
 ******************************************************************************/
#ifndef BOOT_KPI_A53_LINUX_H
#define BOOT_KPI_A53_LINUX_H

#ifdef BOOT_KPI_LOG_EN
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#ifdef __KERNEL__
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/types.h>
#include <linux/boot_kpi.h>
#else
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include "boot_kpi.h"
#endif

/******************************************************************************
 *  INTERNAL DEFINES
 *****************************************************************************/
#define PHY_PAGE_SIZE       0x1000      /*aligned page size - size of KPI_log_t wont work*/
#define KPI_LOG_MAP_SIZE    (((sizeof(KPI_LOG_t) + PHY_PAGE_SIZE - 1) / PHY_PAGE_SIZE) * PHY_PAGE_SIZE)

#define BOOT_KPI_STRCLCPY(dest, src, size)                                                       \
    do {                                                                                         \
        size_t i;                                                                                \
        for (i = 0; i < ((size)-1) && ((src)[i] != '\0'); i++)                                   \
        {                                                                                        \
            (dest)[i] = (src)[i];                                                                \
        }                                                                                        \
        (dest)[i] = '\0';                                                                        \
    } while (0)

#define BOOT_KPI_COUNT_BITS(num, count)                                                          \
    do {                                                                                         \
        (count) = 0;                                                                             \
        unsigned int _num = (num);                                                               \
        while (_num > 0)                                                                         \
        {                                                                                        \
            (count) += _num & 1;                                                                 \
            _num >>= 1;                                                                          \
        }                                                                                        \
    } while (0)

/* assembly code to get cycle counter */
#ifdef __KERNEL__
#define READ_CNTVCT_EL0(cnt)                                                                     \
    do {                                                                                         \
        asm volatile (                                                                           \
            "isb\n\t"                                                                            \
            "mrs %0, cntvct_el0"                                                                 \
            : "=r" (cnt)                                                                         \
        );                                                                                       \
    } while (0)

#else

#define READ_CNTVCT_EL0(cnt)                                                                     \
    do {                                                                                         \
        __asm__ __volatile__ (                                                                   \
            "isb\n\t"                                                                            \
            "mrs %0, cntvct_el0"                                                                 \
            : "=r" (cnt)                                                                         \
        );                                                                                       \
    } while (0)

#endif

/* assembly code to get frequency (Not used now, value hardcoded below)*/
#define READ_CNTFRQ_EL0(freq)                                                                    \
    do {                                                                                         \
        asm volatile("isb\n\t"                                                                   \
                     "mrs %0, cntfrq_el0"                                                        \
                     : "=r"(freq));                                                              \
    } while (0)

#ifdef __KERNEL__

#define BOOT_KPI_CLEAR()                                                                         \
    do {                                                                                         \
        KPI_LOG_t *kpiRecords = (KPI_LOG_t *)ioremap(SHARED_MEMORY_ADDRESS, KPI_LOG_MAP_SIZE);   \
        if (kpiRecords) {                                                                        \
            memset((void *)kpiRecords, 0x00, sizeof(KPI_LOG_t));                                 \
            iounmap(kpiRecords);                                                                 \
        }                                                                                        \
    } while (0)
#else

#define BOOT_KPI_CLEAR() /* NOP in user space (no ioremap) */

#endif


#ifdef __KERNEL__
#define WRITE_LOG(__offset, __map_size, __baseAddr)                                              \
    do {                                                                                         \
        void __iomem *base_ptr = ioremap(__baseAddr, __map_size);                                \
        if (base_ptr) {                                                                          \
            void __iomem *target = base_ptr + __offset;                                          \
            memcpy_toio(target, &kpiRecord, sizeof(kpiRecord));                                  \
            iounmap(base_ptr);                                                                   \
        }                                                                                        \
    } while (0)
#else
#define WRITE_LOG(__offset, __map_size, __baseAddr)                                              \
    do {                                                                                         \
        int fd = open("/dev/mem", O_RDWR | O_SYNC);                                              \
        if (fd != -1) {                                                                          \
            void *map = mmap(NULL, __map_size, PROT_READ | PROT_WRITE,                           \
                             MAP_SHARED, fd, __baseAddr);                                        \
            if (map != MAP_FAILED) {                                                             \
                void *target = (uint8_t *)map + (__offset +                                      \
                                    (SHARED_MEMORY_ADDRESS & (PHY_PAGE_SIZE - 1)));              \
                memcpy(target, &kpiRecord, sizeof(ts_KPI_Timestamp_t));                          \
                munmap(map, __map_size);                                                         \
            }                                                                                    \
            close(fd);                                                                           \
        }                                                                                        \
    } while (0)
#endif


#define BOOT_KPI_LOG(Id, Text)                                                                   \
    do {                                                                                         \
        uint32_t bitCount_u32 = 0;                                                               \
        uint64_t cycles_u64 = 0;                                                                 \
        READ_CNTVCT_EL0(cycles_u64);                                                             \
        if ((Id) >= KPI_ID_FIRST_INV && (Id) < KPI_ID_LAST_INV) {                                \
            ts_KPI_Timestamp_t kpiRecord = {0};                                                  \
            kpiRecord.Time_u32 = (uint32_t)(cycles_u64 / 200000U) + KPI_POWERUP_OFFSET;          \
            BOOT_KPI_STRCLCPY(kpiRecord.Marker_u8A, (Text), KPI_MARKER_MAX_TEXT);                \
            BOOT_KPI_COUNT_BITS(kpiRecord.Time_u32, bitCount_u32);                               \
            kpiRecord.Sig_u16 = 0x01 + (Id) + bitCount_u32;                                      \
                                                                                                 \
            size_t offset = (Id) * sizeof(ts_KPI_Timestamp_t);                                   \
            size_t map_size = KPI_LOG_MAP_SIZE;                                                  \
            off_t baseAddr = SHARED_MEMORY_ADDRESS & ~(PHY_PAGE_SIZE - 1);                       \
                                                                                                 \
            WRITE_LOG(offset, map_size, baseAddr);                                               \
        }                                                                                        \
    } while (0)


#define BOOT_KPI_LOG_CYCLES(Id, Text, cycles)                                                    \
    do {                                                                                         \
        uint32_t bitCount_u32 = 0;                                                               \
        uint64_t cycles_u64 = (cycles);                                                          \
        if ((Id) >= KPI_ID_FIRST_INV && (Id) < KPI_ID_LAST_INV) {                                \
            ts_KPI_Timestamp_t kpiRecord = {0};                                                  \
            kpiRecord.Time_u32 = (uint32_t)((cycles_u64) / 200000U) + KPI_POWERUP_OFFSET;        \
            BOOT_KPI_STRCLCPY(kpiRecord.Marker_u8A, (Text), KPI_MARKER_MAX_TEXT);                \
            BOOT_KPI_COUNT_BITS(kpiRecord.Time_u32, bitCount_u32);                               \
            kpiRecord.Sig_u16 = 0x01 + (Id) + bitCount_u32;                                      \
                                                                                                 \
            size_t offset = (Id) * sizeof(ts_KPI_Timestamp_t);                                   \
            size_t map_size = KPI_LOG_MAP_SIZE;                                                  \
            off_t baseAddr = SHARED_MEMORY_ADDRESS & ~(PHY_PAGE_SIZE - 1);                       \
                                                                                                 \
            WRITE_LOG(offset, map_size, baseAddr);                                               \
        }                                                                                        \
    } while (0)

#else
#define BOOT_KPI_CLEAR()                        /* No operation */
#define BOOT_KPI_LOG(Id, Text)                  /* No operation */
#define BOOT_KPI_LOG_CYCLES(Id, Text, cycles)   /* No operation */

#endif /*BOOT_KPI_LOG_EN*/
#endif /* BOOT_KPI_A53_LINUX_H */
