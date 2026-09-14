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
 * \file boot_kpi_ti_am62x.h
 *
 * \brief
 * Visteon KPI header file for TI AM62X
 *
 ******************************************************************************/
#ifndef BOOT_KPI_TI_AM62X_H
#define BOOT_KPI_TI_AM62X_H

#ifdef BOOT_KPI_LOG_EN
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "boot_kpi.h"


/******************************************************************************
 *  FUNCTION DECLARATIONS
 *****************************************************************************/


/******************************************************************************
 *  INTERNAL DEFINES
 *****************************************************************************/
extern KPI_LOG_t *KPI_Records;

#define BOOT_KPI_STRCLCPY(dest, src, size)                                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        size_t i;                                                                                                      \
        for (i = 0; i < ((size)-1) && ((src)[i] != '\0'); i++)                                                         \
        {                                                                                                              \
            (dest)[i] = (src)[i];                                                                                      \
        }                                                                                                              \
        (dest)[i] = '\0';                                                                                              \
    } while (0)

#define BOOT_KPI_COUNT_BITS(num, count)                                                                                \
    do                                                                                                                 \
    {                                                                                                                  \
        (count)           = 0;                                                                                         \
        unsigned int _num = (num);                                                                                     \
        while (_num > 0)                                                                                               \
        {                                                                                                              \
            (count) += _num & 1;                                                                                       \
            _num >>= 1;                                                                                                \
        }                                                                                                              \
    } while (0)

#define BOOT_KPI_CLEAR()                                                                                               \
    do                                                                                                                 \
    {                                                                                                                  \
        memset((void*)KPI_Records, 0x00, sizeof(*KPI_Records));                                                        \
    } while (0)

#define BOOT_KPI_LOG(Id, Text, TextSize)                                                                               \
    do                                                                                                                 \
    {                                                                                                                  \
        uint32_t bitCount = 0;                                                                                         \
        uint64_t cpuMHz = 200000u;                                           \
        /* Get PMU count before anything else so as to not waste any cycles */                                         \
        uint64_t cycleCount = GTC_getCount64();                                                              \
        /* Read the address of previous log to get the previous CycleCount */                                          \
        uint64_t time_U32 = (cycleCount/cpuMHz);                                                                         \
        if ((Id > KPI_ENTRY_START_INV) && (Id < KPI_ENTRY_LAST_INV))                                                   \
        {                                                                                                              \
            if (KPI_Records->record[Id].Sig_u16 != 0)                                                                  \
            {                                                                                                          \
                /* slot already used, do nothing */                                                                    \
            }                                                                                                          \
            else                                                                                                       \
            {                                                                                                          \
                KPI_Records->record[Id].Time_u32 = (uint32_t)time_U32;                                                 \
                if (TextSize < KPI_MARKER_MAX_TEXT)                                                                    \
                {                                                                                                      \
                    BOOT_KPI_STRCLCPY(KPI_Records->record[Id].Marker_u8A, (Text), (TextSize));                         \
                }                                                                                                      \
                else                                                                                                   \
                {                                                                                                      \
                    BOOT_KPI_STRCLCPY(KPI_Records->record[Id].Marker_u8A, (Text), KPI_MARKER_MAX_TEXT);                \
                }                                                                                                      \
                BOOT_KPI_COUNT_BITS(KPI_Records->record[Id].Time_u32, bitCount);                                       \
                KPI_Records->record[Id].Sig_u16 = 0x01 + (Id) + bitCount;                                              \
            }                                                                                                          \
        }                                                                                                              \
    } while (0)
#else
#define BOOT_KPI_CLEAR()  /* No operation */
#define BOOT_KPI_LOG(Id, Text, TextSize)  /* No operation */
#endif /*BOOT_KPI_LOG_EN*/
#endif /* BOOT_KPI_TI_AM62X_H */
