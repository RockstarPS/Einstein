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
 * \file kpi_log_parser.c
 *
 * \brief
 * Visteon KPI Parser for TI AM62X - Linux
 *
 ******************************************************************************/


/******************************************************************************
 *  INCLUDES
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include "boot_kpi.h"

/******************************************************************************
 *  DEFINES
 *****************************************************************************/
#define KPI_LOG_ADDR SHARED_MEMORY_ADDRESS
#define PAGE_SIZE 0x1000                               /*aligned page size - size of KPI_log_t wont work*/
#define KPI_LOG_SIZE sizeof(KPI_LOG_t)
#define KPI_LOG_MAP_SIZE (((KPI_LOG_SIZE + PAGE_SIZE - 1) / PAGE_SIZE) * PAGE_SIZE)


/* This parser is tested for the BMW KPI points 
 * Change below API according to the new KPI points */

const char* kpi_id_to_str(te_KPI_ID_t id)
{
    switch (id)
    {
    case KPI_ID_FIRST_INV:                             return "This is an Invalid ID and shall be empty.";
    // SBL Stage 1
    case KPI_ID_SBL_S1_START:                          return "Stage 1 Start.";
    case KPI_ID_SBL_S1_END:                            return "Stage 1 Complete.";
    // SBL Stage 2
    case KPI_ID_SBL_S2_MAIN_START:                     return "Stage 2 Main Thread Start.";
    case KPI_ID_SBL_S2_MAIN_SCISERVER_START:           return "Stage 2 scisever initialisation start.";
    case KPI_ID_SBL_S2_MAIN_ETH_APP_START:             return "Stage 2 Eth App initialisation start.";
    case KPI_ID_SBL_S2_MAIN_END:                       return "Stage 2 Main Thread ends.";
    case KPI_ID_SBL_S2_HSM_CORE_START:                 return "Stage 2 HSM Load image Done & CPU Start.";
    case KPI_ID_SBL_S2_MCU_CORE_START:                 return "Stage 2 MCU Load image Done & CPU Start.";
    case KPI_ID_SBL_S2_GIP_CORE_START:                 return "Stage 2 GIP Load image Done & CPU Start.";
    // VIP Boot
    case KPI_ID_VIP_MAIN:                              return "VIP Main.";
    case KPI_ID_VIP_INIT_ZERO:                         return "EcuM Driver Init Zero End.";
    case KPI_ID_VIP_INIT_ONE:                          return "EcuM Driver Init One End.";
    case KPI_ID_VIP_INIT_TWO:                          return "EcuM Driver Init Two End.";
    case KPI_ID_VIP_RTE_START:                         return "RTE Start.";
    case KPI_ID_VIP_NVM_READALL_FINISH:                return "NVM ReadAll Finish.";
    case KPI_ID_VIP_EARLY_HMI:                         return "Early HMI.";
    case KPI_ID_VIP_ETH_PHY:                           return "Ethernet Communication Phy.";
    case KPI_ID_VIP_ETH_COMM:                          return "Ethernet Communication Enabled.";
    // GIP Boot
    case KPI_ID_GIP_KERNEL_START:                      return "Linux Kernel Init Start.";
    case KPI_ID_GIP_KERNEL_END:                        return "Linux Kernel Init End, Services Start.";
    // GIP HMI
    case KPI_ID_GIP_FULL_HMI:                          return "Full HMI Start.";
    case KPI_ID_LAST_INV:                              return "This is an Invalid ID and shall be empty.";
    default:                                           return "Unknown KPI ID.";
    }
}

int main()
{
    int fd = open("/dev/mem", O_RDONLY | O_SYNC);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    off_t base = KPI_LOG_ADDR & ~(PAGE_SIZE - 1);
    off_t offset = KPI_LOG_ADDR - base;

    void *map_base = mmap(NULL, KPI_LOG_MAP_SIZE, PROT_READ, MAP_SHARED, fd, base);
    if (map_base == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }

    KPI_LOG_t kpi;
    memcpy(&kpi, (uint8_t *)map_base + offset, sizeof(KPI_LOG_t));
    printf("---------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-10s | %-60s | %-6s  |\n", "ID","Marker", "Event", "Time" );
    printf("------+------------+--------------------------------------------------------------+---------+\n");

    for (int i = 0; i < KPI_ID_LAST_INV; ++i)
    {
        if (kpi.record[i].Sig_u16 != 0)
        {
            char marker_buf[KPI_MARKER_MAX_TEXT + 1] = {0};
            memcpy(marker_buf, kpi.record[i].Marker_u8A, KPI_MARKER_MAX_TEXT);
            printf("| %3d | %-10s | %-60s | %5ums |\n",
                   i,
                   marker_buf,
                   kpi_id_to_str((te_KPI_ID_t)i),
                   kpi.record[i].Time_u32 );
        }
    }
    printf("---------------------------------------------------------------------------------------------\n");
    printf("\n-----------------------------------------------------------------------------");
    printf("\n|                          Key KPI Points                                   |");
    printf("\n-----------------------------------------------------------------------------");
    printf("\n| %-60s | %10s |\n", "Metric", "Time (ms)");
    printf("--------------------------------------------------------------+--------------\n");
    printf("| %-60s | %8ums |\n", "Time taken for HSM Core to Start", kpi.record[KPI_ID_SBL_S2_HSM_CORE_START].Time_u32);
    printf("| %-60s | %8ums |\n", "Time taken for MCU Core to Start", kpi.record[KPI_ID_SBL_S2_MCU_CORE_START].Time_u32);
    printf("| %-60s | %8ums |\n", "Time taken for Linux Core to Start", kpi.record[KPI_ID_SBL_S2_GIP_CORE_START].Time_u32);
    printf("| %-60s | %8ums |\n", "Time taken for Kernel Initialisation", kpi.record[KPI_ID_GIP_KERNEL_END].Time_u32 - kpi.record[KPI_ID_GIP_KERNEL_START].Time_u32);
    printf("-----------------------------------------------------------------------------\n");
    munmap(map_base, KPI_LOG_MAP_SIZE);
    close(fd);
    return 0;
}
