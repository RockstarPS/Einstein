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
 * \file boot_kpi_r5_asr.h
 *
 * \brief
 * Visteon KPI header file for MCU R5 Core - AUTOSAR
 *
 ******************************************************************************/
 
#ifndef BOOT_KPI_R5_ASR_H
#define BOOT_KPI_R5_ASR_H

#ifdef BOOT_KPI_LOG_EN
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "boot_kpi.h"

/******************************************************************************
 *  DEFINES
 *****************************************************************************/
 /* Assumed Timer TSR Register Base Addresses for AM62x MCU R5 */
#define TIMER_LOW_REG   (0x00A90008U)
#define TIMER_HIGH_REG  (0x00A9000CU)

#define pKPI_Records ((KPI_LOG_t*)SHARED_MEMORY_ADDRESS)

/******************************************************************************
 *  INTERNAL DEFINES
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
        memset((void*)pKPI_Records, 0x00, sizeof(KPI_LOG_t));                                             \
    } while (0)

/* Call this from task level (Autosar started) */ 
#define BOOT_KPI_LOG(Id, Text)                                                                            \
    do {                                                                                                  \
        uint32_t bitCount = 0;                                                                            \
        uint32_t lTSR = 0,hTSR = 0,time_u32 = 0;                                                          \
        SuspendAllInterrupts();                                                                           \
        lTSR = *(volatile uint32_t*)TIMER_LOW_REG;                                                        \
        hTSR = *(volatile uint32_t*)TIMER_HIGH_REG;                                                       \
        ResumeAllInterrupts();                                                                            \
        if ((Id >= KPI_ID_FIRST_INV) && (Id < KPI_ID_LAST_INV)) {                                         \
            if (pKPI_Records->record[Id].Sig_u16 == 0) {                                                  \
                time_u32 = (uint32_t)((((uint64_t)hTSR << 32) | lTSR) / 200000U );                        \
                pKPI_Records->record[Id].Time_u32 = time_u32 + KPI_POWERUP_OFFSET;                        \
                BOOT_KPI_STRCLCPY(pKPI_Records->record[Id].Marker_u8A, (Text), KPI_MARKER_MAX_TEXT);      \
                BOOT_KPI_COUNT_BITS(pKPI_Records->record[Id].Time_u32, bitCount);                         \
                pKPI_Records->record[Id].Sig_u16 = 0x01 + (Id) + bitCount;                                \
            } else {                                                                                      \
                /* slot already used, do nothing */                                                       \
            }                                                                                             \
        }                                                                                                 \
    } while (0)

/* Call this if no interrupts are enabled, i.e. from main(), before OS is started */ 
#define BOOT_KPI_LOG_NOINT(Id, Text)                                                                      \
    do {                                                                                                  \
        uint32_t bitCount = 0;                                                                            \
        uint32_t lTSR = 0,hTSR = 0,time_u32 = 0;                                                          \
        lTSR = *(volatile uint32_t*)TIMER_LOW_REG;                                                        \
        hTSR = *(volatile uint32_t*)TIMER_HIGH_REG;                                                       \
        if ((Id >= KPI_ID_FIRST_INV) && (Id < KPI_ID_LAST_INV)) {                                         \
            if (pKPI_Records->record[Id].Sig_u16 == 0) {                                                  \
                time_u32 = (uint32_t)((((uint64_t)hTSR << 32) | lTSR) / 200000U );                        \
                pKPI_Records->record[Id].Time_u32 = time_u32 + KPI_POWERUP_OFFSET;                        \
                BOOT_KPI_STRCLCPY(pKPI_Records->record[Id].Marker_u8A, (Text), KPI_MARKER_MAX_TEXT);      \
                BOOT_KPI_COUNT_BITS(pKPI_Records->record[Id].Time_u32, bitCount);                         \
                pKPI_Records->record[Id].Sig_u16 = 0x01 + (Id) + bitCount;                                \
            } else {                                                                                      \
                /* slot already used, do nothing */                                                       \
            }                                                                                             \
        }                                                                                                 \
    } while (0)

#else
#define BOOT_KPI_CLEAR()              /* No operation */
#define BOOT_KPI_LOG(Id, Text)        /* No operation */
#define BOOT_KPI_LOG_NOINT(Id, Text)  /* No operation */

#endif /*BOOT_KPI_LOG_EN*/
#endif
