/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2024] Visteon Corporation
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
 * \file boot_kpi_hsm.h
 *
 * \brief
 * Visteon KPI header file for TV2 HSM
 *
 ******************************************************************************/
#ifndef BOOT_KPI_HSM_H
#define BOOT_KPI_HSM_H

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "boot_kpi.h"

/******************************************************************************
 *  INTERNAL DEFINES
 *****************************************************************************/
#ifdef BOOT_KPI_LOG_EN
extern KPI_LOG_t KPI_Records;

#define vHsm_getHsmBootKPITimerMs() Cy_SwTmr_GetTickCountUs()

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
        memset((void*)&KPI_Records, 0x00, sizeof(KPI_Records));                                                        \
    } while (0)

#define BOOT_KPI_LOG(Id, Text, TextSize)                                                                               \
    do                                                                                                                 \
    {                                                                                                                  \
        uint64_t time_U64;                                                                                             \
        uint32_t bitCount = 0;                                                                                         \
        if ((Id > KPI_ENTRY_START_INV) && (Id < KPI_ENTRY_LAST_INV))                                                   \
        {                                                                                                              \
            if (KPI_Records.record[Id].Sig_u16 != 0)                                                                   \
            {                                                                                                          \
                /* slot already used, do nothing */                                                                    \
            }                                                                                                          \
            else                                                                                                       \
            {                                                                                                          \
                time_U64                        = vHsm_getHsmBootKPITimerMs();                                         \
                time_U64                        = time_U64 / 1000u; /* divide by 1000 for ms */                        \
                KPI_Records.record[Id].Time_u32 = (uint32_t)(time_U64 & 0xFFFFFFFF);                                   \
                if (TextSize < KPI_MARKER_MAX_TEXT)                                                                    \
                {                                                                                                      \
                    BOOT_KPI_STRCLCPY(KPI_Records.record[Id].Marker_u8A, (Text), (TextSize));                          \
                }                                                                                                      \
                else                                                                                                   \
                {                                                                                                      \
                    BOOT_KPI_STRCLCPY(KPI_Records.record[Id].Marker_u8A, (Text), KPI_MARKER_MAX_TEXT);                 \
                }                                                                                                      \
                BOOT_KPI_COUNT_BITS(KPI_Records.record[Id].Time_u32, bitCount);                                        \
                KPI_Records.record[Id].Sig_u16 = 0x01 + (Id) + bitCount;                                               \
            }                                                                                                          \
        }                                                                                                              \
    } while (0)
#else
#define BOOT_KPI_CLEAR()  /* No operation */
#define BOOT_KPI_LOG(Id, Text, TextSize)  /* No operation */
#endif /*BOOT_KPI_LOG_EN*/
#endif /* BOOT_KPI_HSM_H */
