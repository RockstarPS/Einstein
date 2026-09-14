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
 * \file boot_kpi.h
 *
 * \brief
 * Visteon KPI Common Header File
 *
 ******************************************************************************/
#ifndef BOOT_KPI_H
#define BOOT_KPI_H

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "stdint.h"
#include "string.h"
#ifdef BOOT_KPI_LOG_EN
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
 *  \var te_KPI_ID_t::KPI_ENTRY_HSM_HSM_AUTH
 *  \brief HSM system initialization completed.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_HSM_BM_AUTH
 *  \brief HSM has completed BM authentication.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_HSM_APP_AUTH
 *  \brief HSM has completed APP authentication.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_APP_NVM_READALL_BEGIN
 *  \brief APP has started NvM Read All.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_APP_NVM_READALL
 *  \brief APP has completed NvM Read All.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_APP_CANTX
 *  \brief First CAN Message has been sent by ECU.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_APP_CANTX_ACK
 *  \brief First CAN Message has been received and acknowledged by other ECU.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_APP_GROUP0
 *  \brief Group 0 Initialisation completed.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_APP_GROUP1
 *  \brief Group 1 Initialisation completed.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_APP_DRIVER_INIT_ONE
 *  \brief Ecum Driver Init One Initialisation completed.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_APP_DRIVER_INIT_TWO
 *  \brief Ecum Fixed Driver Init Two Initialisation completed.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_APP_DRIVER_INIT_TWO_BEGIN
 *  \brief Ecum Fixed Driver Init Two Initialisation has started.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_APP_DRIVER_INIT_THREE
 *  \brief Ecum Fixed Driver Init Three Initialisation completed.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_APP_DRIVER_INIT_THREE_BEGIN
 *  \brief Ecum Fixed Driver Init Three Initialisation started.
 *
 *  \var te_KPI_ID_t::KPI_ENTRY_LAST_INV
 *  \brief This is an Invalid ID and shall be empty.
 *
 */
typedef enum
{
    KPI_ENTRY_START_INV,
    KPI_ENTRY_HSM_HSM_AUTH,
    KPI_ENTRY_HSM_BM_AUTH,
    KPI_ENTRY_HSM_APP_AUTH,
    KPI_ENTRY_APP_NVM_READALL_BEGIN,
    KPI_ENTRY_APP_NVM_READALL,
    KPI_ENTRY_APP_CANTX,
    KPI_ENTRY_APP_CANTX_ACK,
    KPI_ENTRY_APP_GROUP0,
    KPI_ENTRY_APP_GROUP1,
    KPI_ENTRY_APP_DRIVER_INIT_ONE,
    KPI_ENTRY_APP_DRIVER_INIT_TWO_BEGIN,
    KPI_ENTRY_APP_DRIVER_INIT_TWO,
    KPI_ENTRY_APP_DRIVER_INIT_THREE_BEGIN,
    KPI_ENTRY_APP_DRIVER_INIT_THREE,
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
