/*
 * Secure proxy register Offset definitions
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file secure_proxy_regs.h
 *
 * \brief Private include file for secure proxy describing the registers
 */


#ifndef SEC_PROXY_REG_OFFSETS_H
#define SEC_PROXY_REG_OFFSETS_H


/**************************************************************************
 * Register Macros
 **************************************************************************/

#define SEC_PROXY_PID                                      (0x00000000U)
#define SEC_PROXY_CONFIG                                   (0x00000004U)

/**************************************************************************
 * Field Definition Macros
 **************************************************************************/

/* PID */

#define SEC_PROXY_PID_MINOR_MASK                           (0x0000003FU)
#define SEC_PROXY_PID_MINOR_SHIFT                          (0x00000000U)
#define SEC_PROXY_PID_MINOR_RESETVAL                       (0x00000000U)
#define SEC_PROXY_PID_MINOR_MAX                            (0x0000003FU)

#define SEC_PROXY_PID_CUSTOM_MASK                          (0x000000C0U)
#define SEC_PROXY_PID_CUSTOM_SHIFT                         (0x00000006U)
#define SEC_PROXY_PID_CUSTOM_RESETVAL                      (0x00000000U)
#define SEC_PROXY_PID_CUSTOM_MAX                           (0x00000003U)

#define SEC_PROXY_PID_MAJOR_MASK                           (0x00000700U)
#define SEC_PROXY_PID_MAJOR_SHIFT                          (0x00000008U)
#define SEC_PROXY_PID_MAJOR_RESETVAL                       (0x00000001U)
#define SEC_PROXY_PID_MAJOR_MAX                            (0x00000007U)

#define SEC_PROXY_PID_RTL_MASK                             (0x0000F800U)
#define SEC_PROXY_PID_RTL_SHIFT                            (0x0000000BU)
#define SEC_PROXY_PID_RTL_RESETVAL                         (0x00000006U)
#define SEC_PROXY_PID_RTL_MAX                              (0x0000001FU)

#define SEC_PROXY_PID_FUNC_MASK                            (0x0FFF0000U)
#define SEC_PROXY_PID_FUNC_SHIFT                           (0x00000010U)
#define SEC_PROXY_PID_FUNC_RESETVAL                        (0x00000636U)
#define SEC_PROXY_PID_FUNC_MAX                             (0x00000FFFU)

#define SEC_PROXY_PID_BU_MASK                              (0x30000000U)
#define SEC_PROXY_PID_BU_SHIFT                             (0x0000001CU)
#define SEC_PROXY_PID_BU_RESETVAL                          (0x00000002U)
#define SEC_PROXY_PID_BU_MAX                               (0x00000003U)

#define SEC_PROXY_PID_SCHEME_MASK                          (0xC0000000U)
#define SEC_PROXY_PID_SCHEME_SHIFT                         (0x0000001EU)
#define SEC_PROXY_PID_SCHEME_RESETVAL                      (0x00000001U)
#define SEC_PROXY_PID_SCHEME_MAX                           (0x00000003U)

#define SEC_PROXY_PID_RESETVAL                             (0x66363100U)

/* CONFIG */

#define SEC_PROXY_CONFIG_MSG_SIZE_MASK                     (0xFFFF0000U)
#define SEC_PROXY_CONFIG_MSG_SIZE_SHIFT                    (0x00000010U)
#define SEC_PROXY_CONFIG_MSG_SIZE_RESETVAL                 (0x00000040U)
#define SEC_PROXY_CONFIG_MSG_SIZE_MAX                      (0x0000FFFFU)

#define SEC_PROXY_CONFIG_THREADS_MASK                      (0x0000FFFFU)
#define SEC_PROXY_CONFIG_THREADS_SHIFT                     (0x00000000U)
#define SEC_PROXY_CONFIG_THREADS_RESETVAL                  (0x00000400U)
#define SEC_PROXY_CONFIG_THREADS_MAX                       (0x0000FFFFU)

#define SEC_PROXY_CONFIG_RESETVAL                          (0x00400400U)

/**************************************************************************
 * Hardware Region  : Sec Proxy Secure Config
 **************************************************************************/

/**************************************************************************
 * Register Macros
 **************************************************************************/

#define SEC_PROXY_SCFG_BUFFER_L                            (0x00000000U)
#define SEC_PROXY_SCFG_BUFFER_H                            (0x00000004U)
#define SEC_PROXY_SCFG_TARGET_L                            (0x00000008U)
#define SEC_PROXY_SCFG_TARGET_H                            (0x0000000CU)
#define SEC_PROXY_SCFG_ORDERID                             (0x00000010U)

static inline soc_phys_addr_t sec_proxy_scfg_thread_ctl(u16 thread)
{
	u32 offset = (0x00001000U + (((u32) thread) * 0x1000U));

	return (soc_phys_addr_t) offset;
}
static inline soc_phys_addr_t sec_proxy_scfg_thread_evt_map(u16 thread)
{
	u32 offset = (0x00001004U + (((u32) thread) * 0x1000U));

	return (soc_phys_addr_t) offset;
}
static inline soc_phys_addr_t sec_proxy_scfg_thread_dst(u16 thread)
{
	u32 offset = (0x00001008U + (((u32) thread) * 0x1000U));

	return (soc_phys_addr_t) offset;
}

/**************************************************************************
 * Field Definition Macros
 **************************************************************************/


/* CTL */

#define SEC_PROXY_SCFG_THREAD_CTL_DIR_MASK                 (0x80000000U)
#define SEC_PROXY_SCFG_THREAD_CTL_DIR_SHIFT                (0x0000001FU)
#define SEC_PROXY_SCFG_THREAD_CTL_DIR_RESETVAL             (0x00000000U)
#define SEC_PROXY_SCFG_THREAD_CTL_DIR_MAX                  (0x00000001U)

#define SEC_PROXY_SCFG_THREAD_CTL_MAX_CNT_MASK             (0x00FF0000U)
#define SEC_PROXY_SCFG_THREAD_CTL_MAX_CNT_SHIFT            (0x00000010U)
#define SEC_PROXY_SCFG_THREAD_CTL_MAX_CNT_RESETVAL         (0x00000000U)
#define SEC_PROXY_SCFG_THREAD_CTL_MAX_CNT_MAX              (0x000000FFU)

#define SEC_PROXY_SCFG_THREAD_CTL_QUEUE_MASK               (0x0000FFFFU)
#define SEC_PROXY_SCFG_THREAD_CTL_QUEUE_SHIFT              (0x00000000U)
#define SEC_PROXY_SCFG_THREAD_CTL_QUEUE_RESETVAL           (0x00000000U)
#define SEC_PROXY_SCFG_THREAD_CTL_QUEUE_MAX                (0x0000FFFFU)

#define SEC_PROXY_SCFG_THREAD_CTL_RESETVAL                 (0x00000000U)

/* EVT_MAP */

#define SEC_PROXY_SCFG_THREAD_EVT_MAP_ERR_EVT_MASK         (0xFFFF0000U)
#define SEC_PROXY_SCFG_THREAD_EVT_MAP_ERR_EVT_SHIFT        (0x00000010U)
#define SEC_PROXY_SCFG_THREAD_EVT_MAP_ERR_EVT_RESETVAL     (0x0000FFFFU)
#define SEC_PROXY_SCFG_THREAD_EVT_MAP_ERR_EVT_MAX          (0x0000FFFFU)

#define SEC_PROXY_SCFG_THREAD_EVT_MAP_THR_EVT_MASK         (0x0000FFFFU)
#define SEC_PROXY_SCFG_THREAD_EVT_MAP_THR_EVT_SHIFT        (0x00000000U)
#define SEC_PROXY_SCFG_THREAD_EVT_MAP_THR_EVT_RESETVAL     (0x0000FFFFU)
#define SEC_PROXY_SCFG_THREAD_EVT_MAP_THR_EVT_MAX          (0x0000FFFFU)

#define SEC_PROXY_SCFG_THREAD_EVT_MAP_RESETVAL             (0xFFFFFFFFU)

/* DST */

#define SEC_PROXY_SCFG_THREAD_DST_THREAD_MASK              (0x0000FFFFU)
#define SEC_PROXY_SCFG_THREAD_DST_THREAD_SHIFT             (0x00000000U)
#define SEC_PROXY_SCFG_THREAD_DST_THREAD_RESETVAL          (0x00000000U)
#define SEC_PROXY_SCFG_THREAD_DST_THREAD_MAX               (0x0000FFFFU)

#define SEC_PROXY_SCFG_THREAD_DST_RESETVAL                 (0x00000000U)

/* BUFFER_L */

#define SEC_PROXY_SCFG_BUFFER_L_BASE_L_MASK                (0xFFFFFFFFU)
#define SEC_PROXY_SCFG_BUFFER_L_BASE_L_SHIFT               (0x00000000U)
#define SEC_PROXY_SCFG_BUFFER_L_BASE_L_RESETVAL            (0x00000000U)
#define SEC_PROXY_SCFG_BUFFER_L_BASE_L_MAX                 (0xFFFFFFFFU)

#define SEC_PROXY_SCFG_BUFFER_L_RESETVAL                   (0x00000000U)

/* BUFFER_H */

#define SEC_PROXY_SCFG_BUFFER_H_BASE_H_MASK                (0x0000FFFFU)
#define SEC_PROXY_SCFG_BUFFER_H_BASE_H_SHIFT               (0x00000000U)
#define SEC_PROXY_SCFG_BUFFER_H_BASE_H_RESETVAL            (0x00000000U)
#define SEC_PROXY_SCFG_BUFFER_H_BASE_H_MAX                 (0x0000FFFFU)

#define SEC_PROXY_SCFG_BUFFER_H_RESETVAL                   (0x00000000U)

/* TARGET_L */

#define SEC_PROXY_SCFG_TARGET_L_BASE_L_MASK                (0xFFFFFFFFU)
#define SEC_PROXY_SCFG_TARGET_L_BASE_L_SHIFT               (0x00000000U)
#define SEC_PROXY_SCFG_TARGET_L_BASE_L_RESETVAL            (0x10000000U)
#define SEC_PROXY_SCFG_TARGET_L_BASE_L_MAX                 (0xFFFFFFFFU)

#define SEC_PROXY_SCFG_TARGET_L_RESETVAL                   (0x10000000U)

/* TARGET_H */

#define SEC_PROXY_SCFG_TARGET_H_BASE_H_MASK                (0x0000FFFFU)
#define SEC_PROXY_SCFG_TARGET_H_BASE_H_SHIFT               (0x00000000U)
#define SEC_PROXY_SCFG_TARGET_H_BASE_H_RESETVAL            (0x00000000U)
#define SEC_PROXY_SCFG_TARGET_H_BASE_H_MAX                 (0x0000FFFFU)

#define SEC_PROXY_SCFG_TARGET_H_RESETVAL                   (0x00000000U)

/* ORDERID */

#define SEC_PROXY_SCFG_ORDERID_REPLACE_MASK                (0x00000010U)
#define SEC_PROXY_SCFG_ORDERID_REPLACE_SHIFT               (0x00000004U)
#define SEC_PROXY_SCFG_ORDERID_REPLACE_RESETVAL            (0x00000000U)
#define SEC_PROXY_SCFG_ORDERID_REPLACE_MAX                 (0x00000001U)

#define SEC_PROXY_SCFG_ORDERID_ORDERID_MASK                (0x0000000FU)
#define SEC_PROXY_SCFG_ORDERID_ORDERID_SHIFT               (0x00000000U)
#define SEC_PROXY_SCFG_ORDERID_ORDERID_RESETVAL            (0x00000000U)
#define SEC_PROXY_SCFG_ORDERID_ORDERID_MAX                 (0x0000000FU)

#define SEC_PROXY_SCFG_ORDERID_RESETVAL                    (0x00000000U)

/**************************************************************************
 * Hardware Region  : Sec Proxy Realtime
 **************************************************************************/


/**************************************************************************
 * Register Accessors
 **************************************************************************/
static inline soc_phys_addr_t sec_proxy_rt_thread_status(u16 thread)
{
	u32 offset = (0x00000000U + (((u32) thread) * 0x1000U));

	return (soc_phys_addr_t) offset;
}
static inline soc_phys_addr_t sec_proxy_rt_thread_thr(u16 thread)
{
	u32 offset = (0x00000004U + (((u32) thread) * 0x1000U));

	return (soc_phys_addr_t) offset;
}

/**************************************************************************
 * Field Definition Macros
 **************************************************************************/

/* STATUS */

#define SEC_PROXY_RT_THREAD_STATUS_ERROR_MASK              (0x80000000U)
#define SEC_PROXY_RT_THREAD_STATUS_ERROR_SHIFT             (0x0000001FU)
#define SEC_PROXY_RT_THREAD_STATUS_ERROR_RESETVAL          (0x00000000U)
#define SEC_PROXY_RT_THREAD_STATUS_ERROR_MAX               (0x00000001U)

#define SEC_PROXY_RT_THREAD_STATUS_CUR_CNT_MASK            (0x000000FFU)
#define SEC_PROXY_RT_THREAD_STATUS_CUR_CNT_SHIFT           (0x00000000U)
#define SEC_PROXY_RT_THREAD_STATUS_CUR_CNT_RESETVAL        (0x00000000U)
#define SEC_PROXY_RT_THREAD_STATUS_CUR_CNT_MAX             (0x000000FFU)

#define SEC_PROXY_RT_THREAD_STATUS_RESETVAL                (0x00000000U)

/* THR */

#define SEC_PROXY_RT_THREAD_THR_THR_CNT_MASK               (0x000000FFU)
#define SEC_PROXY_RT_THREAD_THR_THR_CNT_SHIFT              (0x00000000U)
#define SEC_PROXY_RT_THREAD_THR_THR_CNT_RESETVAL           (0x00000000U)
#define SEC_PROXY_RT_THREAD_THR_THR_CNT_MAX                (0x000000FFU)

#define SEC_PROXY_RT_THREAD_THR_RESETVAL                   (0x00000000U)

/**************************************************************************
 * Hardware Region  : Sec Proxy Target Data
 **************************************************************************/

#define SEC_PROXY_TARGET_MESSAGE_NUM_WORDS                 (0x0EU)
#define SEC_PROXY_TARGET_MESSAGE_NUM_BYTES		   \
	(SEC_PROXY_TARGET_MESSAGE_NUM_WORDS * (0x04U))

static inline soc_phys_addr_t sec_proxy_target_data_private(u16 thread)
{
	u32 offset = (0x00000000U + (((u32) thread) * 0x1000U));

	return (soc_phys_addr_t) offset;
}
static inline soc_phys_addr_t sec_proxy_target_message_start(u16 thread)
{
	u32 offset = (0x00000004U + (((u32) thread) * 0x1000U));

	return (soc_phys_addr_t) offset;
}
static inline soc_phys_addr_t sec_proxy_target_message_confirm(u16 thread)
{
	u32 offset = (0x0000003CU + (((u32) thread) * 0x1000U));

	return (soc_phys_addr_t) offset;
}

/**************************************************************************
 * Field Definition Macros
 **************************************************************************/

/* PRIVATE */

#define SEC_PROXY_TARGET_DATA_PRIVATE_SRC_THR_MASK         (0x000003FFU)
#define SEC_PROXY_TARGET_DATA_PRIVATE_SRC_THR_SHIFT        (0x00000000U)
#define SEC_PROXY_TARGET_DATA_PRIVATE_SRC_THR_RESETVAL     (0x00000000U)

#endif
