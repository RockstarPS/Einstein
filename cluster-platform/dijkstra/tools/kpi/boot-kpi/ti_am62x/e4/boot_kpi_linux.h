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
 * \file boot_kpi_linux.h
 *
 * \brief
 * Visteon KPI header file for QNX applications
 *
 ******************************************************************************/
 
#ifndef BOOT_KPI_LINUX_H
#define BOOT_KPI_LINUX_H

#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "boot_kpi.h"

// read the Global Timestamp Counter
static __inline__ uint64_t KPI_ReadGTC(void)
{
	uint64_t GTcnt;
	__asm__ __volatile__(
		"mrs	%[GTcnt], cntvct_el0"
		: [GTcnt] "=r"(GTcnt)
	);
	return GTcnt;
}


/******************************************************************************
 *  DEFINES
 *****************************************************************************/
#define MAP_MASK_KPI 4095
 
#define BOOT_KPI_STRCLCPY(dest, src, size) \
    do { \
        size_t i; \
        for(i=0; i<((size) - 1) && ((src)[i] != '\0'); i++) \
        { \
            (dest)[i] = (src)[i]; \
        } \
        (dest)[i] = '\0'; \
    } while (0)

#define BOOT_KPI_COUNT_BITS(num, count) \
    do { \
        (count) = 0; \
        unsigned int _num = (num); \
        while (_num > 0) { \
            (count) += _num & 1; \
            _num >>= 1; \
        } \
    } while (0)

#define BOOT_KPI_LOG(Id, Text) \
    do { \
        uint32_t bitCount = 0; \
        if ((Id >= 0) && (Id < KPI_ENTRY_LAST_INV)) { \
			int fid = open("/dev/mem",O_RDWR | O_SYNC ); \
			if (fid != -1) \
			{ \
				KPI_LOG_t* pKPI_Records = mmap(NULL,(sizeof(KPI_LOG_t)+MAP_MASK_KPI)&(~MAP_MASK_KPI),PROT_READ | PROT_WRITE, MAP_SHARED,fid, KPI_SHARED_ADDR & ~MAP_MASK_KPI); \
				if (MAP_FAILED != pKPI_Records) \
				{ \
					if (pKPI_Records->record[Id].Sig_u16 != 0) { \
						/* slot already used, do nothing */ \
					} else { \
						pKPI_Records->record[Id].Time_u32 = (uint32_t)(KPI_ReadGTC()/200000u)+KPI_POWERUP_OFFSET; \
						BOOT_KPI_STRCLCPY(pKPI_Records->record[Id].Marker_u8A, (Text), KPI_MARKER_MAX_TEXT); \
						BOOT_KPI_COUNT_BITS(pKPI_Records->record[Id].Time_u32, bitCount); \
						pKPI_Records->record[Id].Sig_u16 = 0x01 + (Id) + bitCount; \
					} \
					munmap(pKPI_Records,sizeof(KPI_LOG_t)); \
				} \
				close(fid); \
            } \
        } \
    } while (0)


#endif
