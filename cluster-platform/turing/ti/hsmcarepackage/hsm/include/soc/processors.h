/*
 * Data version: 231011_130515
 *
 * Copyright (C) 2017-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef SOC_AM62PX_PROCESSOR_H
#define SOC_AM62PX_PROCESSOR_H

/**
 * AM67_MAIN_SEC_MMR_MAIN_0: (Cluster 9 Processor 0)
 */
#define PROC_ID_A53SS0_CORE_0 (0x20U)

/**
 * AM67_MAIN_SEC_MMR_MAIN_0: (Cluster 9 Processor 1)
 */
#define PROC_ID_A53SS0_CORE_1 (0x21U)

/**
 * AM67_MAIN_SEC_MMR_MAIN_0: (Cluster 9 Processor 2)
 */
#define PROC_ID_A53SS0_CORE_2 (0x22U)

/**
 * AM67_MAIN_SEC_MMR_MAIN_0: (Cluster 9 Processor 3)
 */
#define PROC_ID_A53SS0_CORE_3 (0x23U)

/**
 * SMS_MAIN_0_SECCTRL_0: (Cluster 0 Processor 1)
 */
#define PROC_ID_HSM0 (0x80U)

/**
 * AM67_MCU_SEC_MMR_MCU_0: (Cluster 0 Processor 0)
 */
#define PROC_ID_MCU_R5FSS0_CORE0 (0x03U)

/**
 * AM67_WKUP_SEC_MMR_WKUP_0: (Cluster 28 Processor 0)
 */
#define PROC_ID_WKUP_R5FSS0_CORE0 (0x01U)

/**
 * Total Number of processors in AM62PX
 */
#define SOC_NUM_PROCESSORS (0x07U)

#endif /* SOC_AM62PX_PROCESSOR_H */
