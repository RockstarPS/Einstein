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

/******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include <string.h>

/******************************************************************************
 *  INTERNAL DEFINES
 *****************************************************************************/
#define KPI_MARKER_MAX_TEXT             10u                         /* Mac no of Char in the KPI Marker */
#define KPI_TIMESTAMP_MAX_SIZE          sizeof(ts_KPI_Timestamp_t)
#define SHARED_MEMORY_ADDRESS           0x82384000U                 /* DDR Shared memory Address */

#define KPI_BAT_ON_TO_MCU_PORz			22                          /* KPI Log Time between BATTERY ON TO MCU POWER ON RESET*/

#ifdef BOOT_MODE_SPI
     #define KPI_MCU_PORz_TO_STAGE1_MAIN     438                         /* KPI Log Time between MCU POWER ON RESET to SBL Stage1 main Entry */
#else
     #define KPI_MCU_PORz_TO_STAGE1_MAIN	55                          /* KPI Log Time between MCU POWER ON RESET to SBL Stage1 main Entry */
#endif

#define KPI_POWERUP_OFFSET              (KPI_BAT_ON_TO_MCU_PORz + KPI_MCU_PORz_TO_STAGE1_MAIN)

/******************************************************************************
 *  INTERNAL TYPES
 *****************************************************************************/
/**
 *  \enum te_KPI_ID_t
 *  \brief Enumeration of all KPI measurement events.
 *
 *  \var te_KPI_ID_t::KPI_ID_FIRST_INV
 *  \brief This is an Invalid ID and shall be empty.
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S1_START
 *  \brief Stage 1 Start.
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S1_END
 *  \brief Stage 1 Complete
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S2_MAIN_START
 *  \brief Stage 2 Main Thread Start.
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S2_MAIN_SCISERVER_START
 *  \brief Stage 2 scisever intialisation start
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S2_MAIN_ETH_APP_START
 *  \brief Stage 2 Eth App intialisation start
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S2_MAIN_ETH_APP_TS_IPC,
 *  \brief Stage 2 ETH_APP_TS_IPC Done.
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S2_MAIN_ETH_APP_TS_ETH_PORT,
 *  \brief Stage 2  ETH_APP_TS_ETH_PORT Done.
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S2_MAIN_ETH_APP_TS_HOST_PORT,
 *  \brief Stage 2 ETH_APP_TS_HOST_PORT Done.
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S2_MAIN_ETH_APP_TS_TCPIP,
 *  \brief Stage 2 ETH_APP_TS_TCPIP Done.
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S2_MAIN_ETH_APP_TS_PTP,
 *  \brief Stage 2 ETH_APP_TS_PTP Done."
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S2_MAIN_END
 *  \brief Stage 2 Main Thread ends.
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S2_HSM_CORE_START
 *  \brief Stage 2 HSM Load image Done & CPU Start.
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S2_MCU_CORE_START
 *  \brief Stage 2 MCU Load image Done & CPU Start.
 *
 *  \var te_KPI_ID_t::KPI_ID_SBL_S2_GIP_CORE_START
 *  \brief Stage 2 GIP Load image Done & CPU Start.
 *
 *  \var te_KPI_ID_t::KPI_ID_VIP_MAIN
 *  \brief VIP Main.
 *
 *  \var te_KPI_ID_t::KPI_ID_VIP_INIT_ZERO
 *  \brief EcuM Driver Init Zero End.
 *
 *  \var te_KPI_ID_t::KPI_ID_VIP_INIT_ONE
 *  \brief EcuM Driver Init One End.
 *
 *  \var te_KPI_ID_t::KPI_ID_VIP_INIT_TWO
 *  \brief EcuM Driver Init Two End.
 *
 *  \var te_KPI_ID_t::KPI_ID_VIP_RTE_START
 *  \brief RTE Start.
 *
 *  \var te_KPI_ID_t::KPI_ID_VIP_NVM_READALL_FINISH
 *  \brief NVM ReadAll Finish.
 * 
 *  \var te_KPI_ID_t::KPI_ID_VIP_FIRST_CAN_MSGOUT
 *  \brief First CAN Message Out.
 *
 *  \var te_KPI_ID_t::KPI_ID_VIP_FIRST_CHIMES_PLAY
 *  \brief First Chimes Play.
 * 
 *  \var te_KPI_ID_t::KPI_ID_VIP_UCL_LINKUP
 *  \brief UCL Link Up.
 *
 *  \var te_KPI_ID_t::KPI_ID_VIP_EARLY_HMI
 *  \brief Early HMI.
 *
 *  \var te_KPI_ID_t::KPI_ID_VIP_ETH_PHY
 *  \brief Ethernet Communication Phy.
 * 
 *  \var te_KPI_ID_t::KPI_ID_VIP_ETH_COMM
 *  \brief Ethernet Communication Enabled.
 *
 *  \var te_KPI_ID_t::KPI_ID_GIP_KERNEL_START
 *  \brief Linux Kernel Init Start.
 *
 *  \var te_KPI_ID_t::KPI_ID_GIP_KERNEL_END
 *  \brief Linux Kernel Init End, Services Start.
 *
 *
 *  \var te_KPI_ID_t::KPI_ID_GIP_QNX_START
 *  \brief Linux Kernel Init End, Services Start.
 *
 *
 *  \var te_KPI_ID_t::KPI_ID_GIP_QNX_END
 *  \brief Linux Kernel Init End, Services Start.
 *
 *
 *  \var te_KPI_ID_t::KPI_ID_GIP_QNX_APP1_START
 *  \brief Linux Kernel Init End, Services Start.
 *
 *
 *  \var te_KPI_ID_t::KPI_ID_GIP_QNX_APP2_START
 *  \brief Linux Kernel Init End, Services Start.
  *
 *  \var te_KPI_ID_t::KPI_ID_GIP_SAFE_HMI_START
 *  \brief Safe HMI pre Start.
  *
 *  \var te_KPI_ID_t::KPI_ID_GIP_SAFE_HMI_END
 *  \brief Safe HMI Post Start.
  *
 *  \var te_KPI_ID_t::KPI_ID_GIP_FULL_HMI_START
 *  \brief Full HMI pre Start.
  *
 *  \var te_KPI_ID_t::KPI_ID_GIP_FULL_HMI
 *  \brief Full HMI Start.
 *
 *  \var te_KPI_ID_t::KPI_ID_GIP_FULL_HMI_END
 *  \brief Full HMI post Start.
 *
 *  \var te_KPI_ID_t::KPI_ID_LAST_INV
 *  \brief This is an Invalid ID and shall be empty.
 *
 */
typedef enum
{
    KPI_ID_FIRST_INV = 0,
// SBL Stage 1
    KPI_ID_SBL_S1_START,
    KPI_ID_SBL_S1_END,
// SBL Stage 2
    KPI_ID_SBL_S2_MAIN_START,
    KPI_ID_SBL_S2_MAIN_SCISERVER_START,
    KPI_ID_SBL_S2_MAIN_ETH_APP_START,
    KPI_ID_SBL_S2_MAIN_ETH_APP_TS_IPC,
    KPI_ID_SBL_S2_MAIN_ETH_APP_TS_ETH_PORT,
    KPI_ID_SBL_S2_MAIN_ETH_APP_TS_HOST_PORT,
    KPI_ID_SBL_S2_MAIN_ETH_APP_TS_TCPIP,
    KPI_ID_SBL_S2_MAIN_ETH_APP_TS_PTP,
    KPI_ID_SBL_S2_MAIN_END,
    KPI_ID_SBL_S2_HSM_CORE_START,
    KPI_ID_SBL_S2_MCU_CORE_START,
    KPI_ID_SBL_S2_GIP_CORE_START,
//  HSM Boot
    KPI_ID_HSM_MAIN = 26,
// VIP Boot
    KPI_ID_VIP_MAIN = 51,
    KPI_ID_VIP_INIT_ZERO,
    KPI_ID_VIP_INIT_ONE,
    KPI_ID_VIP_INIT_TWO,
    KPI_ID_VIP_RTE_START,
    KPI_ID_VIP_NVM_READALL_FINISH,
    KPI_ID_VIP_FIRST_CAN_MSGOUT,
    KPI_ID_VIP_FIRST_CHIMES_PLAY,
    KPI_ID_VIP_UCL_LINKUP,
    KPI_ID_VIP_EARLY_HMI,
    KPI_ID_VIP_ETH_PHY,
    KPI_ID_VIP_ETH_COMM,
// GIP Boot
    KPI_ID_GIP_KERNEL_START = 76,
    KPI_ID_GIP_KERNEL_END,
    KPI_ID_GIP_TEST_USER,
// GIP QNX
    KPI_ID_GIP_QNX_START,
    KPI_ID_GIP_QNX_END,
    KPI_ID_GIP_QNX_APP1_START,
    KPI_ID_GIP_QNX_APP2_START,
// GIP HMI
    KPI_ID_GIP_SAFE_HMI_START,
    KPI_ID_GIP_SAFE_HMI_END,
    KPI_ID_GIP_SAFEHMI_BEFORE_FIRST_RENDER,
    KPI_ID_GIP_SAFEHMI_AFTER_FIRST_RENDER,
    KPI_ID_GIP_FULL_HMI_START,
    KPI_ID_GIP_FULL_HMI,
    KPI_ID_GIP_FULL_HMI_END,
    KPI_ID_GIP_MAINHMI_BEFORE_FIRST_RENDER,
    KPI_ID_GIP_MAINHMI_AFTER_FIRST_RENDER,
    KPI_ID_GIP_MAINHMI_WAIT_FOR_RENDER_DONE,
    KPI_ID_LAST_INV,
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
    ts_KPI_Timestamp_t record[KPI_ID_LAST_INV];
} KPI_LOG_t;

#endif /* BOOT_KPI_H */

