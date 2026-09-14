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
 * \file boot_kpi.h
 *
 * \brief
 * Visteon KPI Common Header File
 *
 ******************************************************************************/
#ifndef BOOT_KPI_H
#define BOOT_KPI_H

#ifdef BOOT_KPI_LOG_EN
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "stdint.h"
#include "string.h"
#include "gtc.h"

/******************************************************************************
 *  INTERNAL DEFINES
 *****************************************************************************/
#define KPI_MARKER_MAX_TEXT    10u
#define KPI_TIMESTAMP_MAX_SIZE sizeof(ts_KPI_Timestamp_t)

/******************************************************************************
 *  INTERNAL TYPES
 *****************************************************************************/
/**
 *  \enum te_KPI_ID_t
 *  \brief Enumeration of all KPI measurement events.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_START_INV
 *  \brief This is an Invalid ID and shall be empty.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_VIP_MAIN
 *  \brief VIP Main.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_VIP_INIT_ZERO
 *  \brief EcuM Driver Init Zero End.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_VIP_INIT_ONE
 *  \brief EcuM Driver Init One End.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_VIP_INIT_TWO
 *  \brief EcuM Driver Init Two End.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_VIP_RTE_START
 *  \brief RTE Start.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_VIP_NVM_READALL_FINISH
 *  \brief NVM ReadAll Finish.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_VIP_EARLY_HMI
 *  \brief Early HMI.
 * 
 *  \var te_KPI_ID_t::KPI_ENTRY_GIP_FULL_HMI
 *  \brief Full HMI.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_VIP_ETH_PHY
 *  \brief Ethernet Communication Phy.
 * 
 *  \var te_KPI_ID_t::KPI_ENTRY_VIP_ETH_COMM
 *  \brief Ethernet Communication Enabled.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_GIP_LINUXKERNEL_INIT
 *  \brief Linux Kernel Init.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_GIP_BOOSTMODE_REQUEST
 *  \brief Boost Mode request reaction .
 * 
 *  \var te_KPI_ID_t::KPI_ENTRY_GIP_FAIL_SAFE_HMI
 *  \brief Fail Safe HMI / Main HMI Crash reaction.
 * 
 *  \var te_KPI_ID_t::KPI_ENTRY_LAST_INV
 *  \brief This is an Invalid ID and shall be empty.
 *
 */
typedef enum
{
    KPI_ENTRY_START_INV,
    KPI_ENTRY_VIP_MAIN,
    KPI_ENTRY_VIP_INIT_ZERO,
    KPI_ENTRY_VIP_INIT_ONE,
    KPI_ENTRY_VIP_INIT_TWO,
    KPI_ENTRY_VIP_RTE_START,
    KPI_ENTRY_VIP_NVM_READALL_FINISH,
    KPI_ENTRY_VIP_EARLY_HMI,
    KPI_ENTRY_GIP_FULL_HMI,
    KPI_ENTRY_VIP_ETH_PHY,
    KPI_ENTRY_VIP_ETH_COMM,
    KPI_ENTRY_GIP_LINUXKERNEL_INIT,
    KPI_ENTRY_GIP_BOOSTMODE_REQUEST,
    KPI_ENTRY_GIP_FAIL_SAFE_HMI,
    KPI_ENTRY_LAST_INV,
} te_KPI_ID_t;

/**
 *  \struct ts_KPI_Timestamp_t
 *  \brief Structure for KPI Timestamp
 *
 *  \var ts_KPI_Timestamp_t::Time_u32
 *  \brief Time in ms.
 *
 *  \var ts_KPI_Timestamp_t::Sig_u16
 *  \brief Integrity of KPI Timestamp.
 *
 *  \var ts_KPI_Timestamp_t::Marker_u8A
 *  \brief Text describing the KPI Timestamp event.
 *
 */
typedef struct
{
    uint32_t Time_u32;
    uint16_t Sig_u16;
    char     Marker_u8A[KPI_MARKER_MAX_TEXT];
} ts_KPI_Timestamp_t;

typedef struct
{
    ts_KPI_Timestamp_t record[KPI_ENTRY_LAST_INV];
} KPI_LOG_t;

#endif /*BOOT_KPI_LOG_EN*/
#endif /* BOOT_KPI_H */
