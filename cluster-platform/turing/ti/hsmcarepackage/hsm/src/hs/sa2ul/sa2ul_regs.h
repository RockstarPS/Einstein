/*
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_regs.h
 *
 * \brief SA2UL register definitions
 *
 */

#ifndef SA2UL_REGS_H_
#define SA2UL_REGS_H_

#include <types/sbool.h>
#include <types/short_types.h>

/**
 * \brief SA2UL top-level registers
 *
 * \param PID Version and Identification Register
 * \param EFUSE_EN Efuse Enable
 * \param ENGINE_STATUS Engine Status Readable Register
 * \param CPPI_FLOWID CPPI FlowID
 * \param CPPI_ENG_ID Default engine id
 * \param CTXCACH_CTRL context cache control
 * \param CTXCACH_SC_ID context cache SCID
 * \param CTXCACH_MISSCNT Cache miss counter
 * \param ENGINE_ENABLE Engine Enable
 * \param SCPTR_PROMOTE_LOW_RANGE_L SCPTR Promote Lower Limit
 * \param SCPTR_PROMOTE_LOW_RANGE_H SCPTR Promote Lower Limit
 * \param SCPTR_PROMOTE_HI_RANGE_L SCPTR Promote Upper Limit
 * \param SCPTR_PROMOTE_HI_RANGE_H SCPTR Promote Upper Limit
 * \param EXCEPTION_LOGGING_CONTROL Exception Logging Control
 * \param EXCEPTION_LOGGING_HEADER0 Exception Logging Header 0
 * \param EXCEPTION_LOGGING_HEADER1 Exception Logging Header 1
 * \param EXCEPTION_LOGGING_DATA0 Exception Logging Data 0
 * \param EXCEPTION_LOGGING_DATA1 Exception Logging Data 1
 * \param EXCEPTION_LOGGING_DATA2 Exception Logging Data 2
 * \param EXCEPTION_LOGGING_DATA3 Exception Logging Data 3
 * \param EXCEPTION_PEND_SET Exception Logging Pending Set
 * \param EXCEPTION_PEND_CLEAR Exception Logging Pending Clear
 * \param TRNG_INTR_SET TRNG Interrupt Set
 * \param TRNG_INTR_CLEAR TRNG Interrupt Clear
 * \param PKA_INTR_SET PKA Interrupt Set
 * \param PKA_INTR_CLEAR PKA Interrupt Clear
 * \param KEK KEK registers
 * \param KEK_LOCK Lock KEK until next por
 * \param DKEK_PRIVID KEK access permissions
 */
struct sa2ul_regs {
	/*
	 * status registers
	 */
	volatile u32	PID;
	volatile u32	EFUSE_EN;
	volatile u32	ENGINE_STATUS;
	volatile u8	Resv_20[8];
	volatile u32	CPPI_FLOWID;
	volatile u8	Resv_28[4];
	volatile u32	CPPI_ENG_ID;
	volatile u8	Resv_256[224];
	volatile u32	CTXCACH_CTRL;
	volatile u8	Resv_264[4];
	volatile u32	CTXCACH_SC_ID;
	volatile u32	CTXCACH_MISSCNT;
	volatile u8	Resv_4096[3824];
	/*
	 * control registers (secure access only), at the offset of 0x1000
	 */
	volatile u32	ENGINE_ENABLE;
	volatile u8	Resv1_16[12];
	volatile u32	SCPTR_PROMOTE_LOW_RANGE_L;
	volatile u32	SCPTR_PROMOTE_LOW_RANGE_H;
	volatile u32	SCPTR_PROMOTE_HI_RANGE_L;
	volatile u32	SCPTR_PROMOTE_HI_RANGE_H;
	volatile u32	EXCEPTION_LOGGING_CONTROL;
	volatile u32	EXCEPTION_LOGGING_HEADER0;
	volatile u32	EXCEPTION_LOGGING_HEADER1;
	volatile u32	EXCEPTION_LOGGING_DATA0;
	volatile u32	EXCEPTION_LOGGING_DATA1;
	volatile u32	EXCEPTION_LOGGING_DATA2;
	volatile u32	EXCEPTION_LOGGING_DATA3;
	volatile u8	Resv1_64[4];
	volatile u32	EXCEPTION_PEND_SET;
	volatile u32	EXCEPTION_PEND_CLEAR;
	volatile u8	Resv1_80[8];
	volatile u32	TRNG_INTR_SET;
	volatile u32	TRNG_INTR_CLEAR;
	volatile u8	Resv1_96[8];
	volatile u32	PKA_INTR_SET;
	volatile u32	PKA_INTR_CLEAR;
	volatile u8	Resv1_256[152];
	volatile u32	KEK[8];
	volatile u32	KEK_LOCK;
	volatile u32	DKEK_PRIVID;
	volatile u32	DKEK_PRIV;
	volatile u32	DKEK_SECURE;
};

/* PID */

#define SA2UL_PID_MINOR_MASK                                 (0x0000003FU)
#define SA2UL_PID_MINOR_SHIFT                                (0x00000000U)

#define SA2UL_PID_CUSTOM_MASK                                (0x000000C0U)
#define SA2UL_PID_CUSTOM_SHIFT                               (0x00000006U)

#define SA2UL_PID_MAJOR_MASK                                 (0x00000700U)
#define SA2UL_PID_MAJOR_SHIFT                                (0x00000008U)

#define SA2UL_PID_RTL_MASK                                   (0x0000F800U)
#define SA2UL_PID_RTL_SHIFT                                  (0x0000000BU)

#define SA2UL_PID_FUNC_MASK                                  (0x0FFF0000U)
#define SA2UL_PID_FUNC_SHIFT                                 (0x00000010U)

#define SA2UL_PID_BU_MASK                                    (0x30000000U)
#define SA2UL_PID_BU_SHIFT                                   (0x0000001CU)

#define SA2UL_PID_SCHEME_MASK                                (0xC0000000U)
#define SA2UL_PID_SCHEME_SHIFT                               (0x0000001EU)


/* EFUSE_EN */

#define SA2UL_EFUSE_PKA_EN_MASK                             (0x00000004U)
#define SA2UL_EFUSE_PKA_EN_SHIFT                            (0x00000002U)

#define SA2UL_EFUSE_ENCR_DRBG_EN_MASK                       (0x00000002U)
#define SA2UL_EFUSE_ENCR_DRBG_EN_SHIFT                      (0x00000001U)

#define SA2UL_EFUSE_SHA_EN_MASK                             (0x00000001U)
#define SA2UL_EFUSE_SHA_EN_SHIFT                            (0x00000000U)

#define SA2UL_EFUSE_AES_DPA_CM_EN_BIT                       (0x00000004U)


/* ENGINE_STATUS */

#define SA2UL_ENGINE_STATUS_ENCSS_EN_MASK                   (0x00000001U)
#define SA2UL_ENGINE_STATUS_ENCSS_EN_SHIFT                  (0x00000000U)

#define SA2UL_ENGINE_STATUS_AUTHSS_EN_MASK                  (0x00000002U)
#define SA2UL_ENGINE_STATUS_AUTHSS_EN_SHIFT                 (0x00000001U)

#define SA2UL_ENGINE_STATUS_TRNG_EN_MASK                    (0x00000008U)
#define SA2UL_ENGINE_STATUS_TRNG_EN_SHIFT                   (0x00000003U)

#define SA2UL_ENGINE_STATUS_PKA_EN_MASK                     (0x00000010U)
#define SA2UL_ENGINE_STATUS_PKA_EN_SHIFT                    (0x00000004U)

#define SA2UL_ENGINE_STATUS_CTXCACH_EN_MASK                 (0x00000080U)
#define SA2UL_ENGINE_STATUS_CTXCACH_EN_SHIFT                (0x00000007U)

#define SA2UL_ENGINE_STATUS_CDMA_IN_PORT_EN_MASK            (0x00000200U)
#define SA2UL_ENGINE_STATUS_CDMA_IN_PORT_EN_SHIFT           (0x00000009U)

#define SA2UL_ENGINE_STATUS_CDMA_OUT_PORT_EN_MASK           (0x00000800U)
#define SA2UL_ENGINE_STATUS_CDMA_OUT_PORT_EN_SHIFT          (0x0000000BU)

#define SA2UL_ENGINE_STATUS_ENCSS_BUSY_MASK                 (0x00010000U)
#define SA2UL_ENGINE_STATUS_ENCSS_BUSY_SHIFT                (0x00000010U)

#define SA2UL_ENGINE_STATUS_AUTHSS_BUSY_MASK                (0x00020000U)
#define SA2UL_ENGINE_STATUS_AUTHSS_BUSY_SHIFT               (0x00000011U)

#define SA2UL_ENGINE_STATUS_TRNG_BUSY_MASK                  (0x00080000U)
#define SA2UL_ENGINE_STATUS_TRNG_BUSY_SHIFT                 (0x00000013U)

#define SA2UL_ENGINE_STATUS_PKA_BUSY_MASK                   (0x00100000U)
#define SA2UL_ENGINE_STATUS_PKA_BUSY_SHIFT                  (0x00000014U)

#define SA2UL_ENGINE_STATUS_CTXCACH_BUSY_MASK               (0x00800000U)
#define SA2UL_ENGINE_STATUS_CTXCACH_BUSY_SHIFT              (0x00000017U)

#define SA2UL_ENGINE_STATUS_CDMA_IN_PORT_BUSY_MASK          (0x02000000U)
#define SA2UL_ENGINE_STATUS_CDMA_IN_PORT_BUSY_SHIFT         (0x00000019U)

#define SA2UL_ENGINE_STATUS_CDMA_OUT_PORT_BUSY_MASK         (0x08000000U)
#define SA2UL_ENGINE_STATUS_CDMA_OUT_PORT_BUSY_SHIFT        (0x0000001BU)


/* CTXCACH_CTRL */

#define SA2UL_CTXCACH_CTRL_AUTO_FETCH_EN_MASK                (0x00000001U)
#define SA2UL_CTXCACH_CTRL_AUTO_FETCH_EN_SHIFT               (0x00000000U)

#define SA2UL_CTXCACH_CTRL_CLR_CACHE_TABLE_MASK              (0x00000002U)
#define SA2UL_CTXCACH_CTRL_CLR_CACHE_TABLE_SHIFT             (0x00000001U)

#define SA2UL_CTXCACH_CTRL_CDMA_PORT_EN_MASK                 (0x00000008U)
#define SA2UL_CTXCACH_CTRL_CDMA_PORT_EN_SHIFT                (0x00000003U)

#define SA2UL_CTXCACH_CTRL_CLR_STATS_MASK                    (0x00000010U)
#define SA2UL_CTXCACH_CTRL_CLR_STATS_SHIFT                   (0x00000004U)

#define SA2UL_CTXCACH_CTRL_CTX_CNT_MASK                      (0x7F000000U)
#define SA2UL_CTXCACH_CTRL_CTX_CNT_SHIFT                     (0x00000018U)

#define SA2UL_CTXCACH_CTRL_BUSY_MASK                         (0x80000000U)
#define SA2UL_CTXCACH_CTRL_BUSY_SHIFT                        (0x0000001FU)


/* CTXCACH_SC_ID */

#define SA2UL_CTXCACH_SC_ID_SC_ID_MASK                       (0x0000FFFFU)
#define SA2UL_CTXCACH_SC_ID_SC_ID_SHIFT                      (0x00000000U)

#define SA2UL_CTXCACH_SC_ID_SC_FETCH_EVICT_MASK              (0x00010000U)
#define SA2UL_CTXCACH_SC_ID_SC_FETCH_EVICT_SHIFT             (0x00000010U)

#define SA2UL_CTXCACH_SC_ID_SC_TEAR_MASK                     (0x00020000U)
#define SA2UL_CTXCACH_SC_ID_SC_TEAR_SHIFT                    (0x00000011U)

#define SA2UL_CTXCACH_SC_ID_GO_MASK                          (0x00080000U)
#define SA2UL_CTXCACH_SC_ID_GO_SHIFT                         (0x00000013U)

#define SA2UL_CTXCACH_SC_ID_SC_RAMIDX_MASK                   (0x0FF00000U)
#define SA2UL_CTXCACH_SC_ID_SC_RAMIDX_SHIFT                  (0x00000014U)

#define SA2UL_CTXCACH_SC_ID_SC_ERRCODE_MASK                  (0x70000000U)
#define SA2UL_CTXCACH_SC_ID_SC_ERRCODE_SHIFT                 (0x0000001CU)

#define SA2UL_CTXCACH_SC_ID_DONE_MASK                        (0x80000000U)
#define SA2UL_CTXCACH_SC_ID_DONE_SHIFT                       (0x0000001FU)


/* ENGINE_ENABLE */

#define SA2UL_ENGINE_ENABLE_ENCSS_EN_MASK                 (0x00000001U)
#define SA2UL_ENGINE_ENABLE_ENCSS_EN_SHIFT                (0x00000000U)

#define SA2UL_ENGINE_ENABLE_AUTHSS_EN_MASK                (0x00000002U)
#define SA2UL_ENGINE_ENABLE_AUTHSS_EN_SHIFT               (0x00000001U)

#define SA2UL_ENGINE_ENABLE_TRNG_EN_MASK                  (0x00000008U)
#define SA2UL_ENGINE_ENABLE_TRNG_EN_SHIFT                 (0x00000003U)

#define SA2UL_ENGINE_ENABLE_PKA_EN_MASK                   (0x00000010U)
#define SA2UL_ENGINE_ENABLE_PKA_EN_SHIFT                  (0x00000004U)

#define SA2UL_ENGINE_ENABLE_CTX_EN_MASK                   (0x00000080U)
#define SA2UL_ENGINE_ENABLE_CTX_EN_SHIFT                  (0x00000007U)

#define SA2UL_ENGINE_ENABLE_CDMA_IN_EN_MASK               (0x00000200U)
#define SA2UL_ENGINE_ENABLE_CDMA_IN_EN_SHIFT              (0x00000009U)

#define SA2UL_ENGINE_ENABLE_CDMA_OUT_EN_MASK              (0x00000800U)
#define SA2UL_ENGINE_ENABLE_CDMA_OUT_EN_SHIFT             (0x0000000BU)


/* EXCEPTION_LOGGING_CONTROL */

#define SA2UL_EXCEPTION_LOGGING_CONTROL_DISABLE_LOG_MASK   (0x00000001U)
#define SA2UL_EXCEPTION_LOGGING_CONTROL_DISABLE_LOG_SHIFT  (0x00000000U)

#define SA2UL_EXCEPTION_LOGGING_CONTROL_DISABLE_PEND_MASK  (0x00000002U)
#define SA2UL_EXCEPTION_LOGGING_CONTROL_DISABLE_PEND_SHIFT (0x00000001U)


/* EXCEPTION_LOGGING_HEADER0 */

#define SA2UL_EXCEPTION_LOGGING_HEADER0_SRC_ID_MASK       (0x00FFFF00U)
#define SA2UL_EXCEPTION_LOGGING_HEADER0_SRC_ID_SHIFT      (0x00000008U)

#define SA2UL_EXCEPTION_LOGGING_HEADER0_TYPE_LOG_MASK     (0xFF000000U)
#define SA2UL_EXCEPTION_LOGGING_HEADER0_TYPE_LOG_SHIFT    (0x00000018U)


/* EXCEPTION_LOGGING_HEADER1 */

#define SA2UL_EXCEPTION_LOGGING_HEADER1_CODE_MASK         (0x00FF0000U)
#define SA2UL_EXCEPTION_LOGGING_HEADER1_CODE_SHIFT        (0x00000010U)

#define SA2UL_EXCEPTION_LOGGING_HEADER1_GROUP_MASK        (0xFF000000U)
#define SA2UL_EXCEPTION_LOGGING_HEADER1_GROUP_SHIFT       (0x00000018U)


/* EXCEPTION_LOGGING_DATA2 */

#define SA2UL_EXCEPTION_LOGGING_DATA2_SECURE_MASK         (0x00000001U)
#define SA2UL_EXCEPTION_LOGGING_DATA2_SECURE_SHIFT        (0x00000000U)

#define SA2UL_EXCEPTION_LOGGING_DATA2_PROMOTE_MASK        (0x00000020U)
#define SA2UL_EXCEPTION_LOGGING_DATA2_PROMOTE_SHIFT       (0x00000005U)

#define SA2UL_EXCEPTION_LOGGING_DATA2_DEMOTE_MASK         (0x00000040U)
#define SA2UL_EXCEPTION_LOGGING_DATA2_DEMOTE_SHIFT        (0x00000006U)

#define SA2UL_EXCEPTION_LOGGING_DATA2_ALLOWNS_MASK        (0x00000080U)
#define SA2UL_EXCEPTION_LOGGING_DATA2_ALLOWNS_SHIFT       (0x00000007U)

#define SA2UL_EXCEPTION_LOGGING_DATA2_PRIV_MASK           (0x00000300U)
#define SA2UL_EXCEPTION_LOGGING_DATA2_PRIV_SHIFT          (0x00000008U)

#define SA2UL_EXCEPTION_LOGGING_DATA2_PRIV_ID_MASK        (0x00FF0000U)
#define SA2UL_EXCEPTION_LOGGING_DATA2_PRIV_ID_SHIFT       (0x00000010U)


/* EXCEPTION_LOGGING_DATA3 */

#define SA2UL_EXCEPTION_LOGGING_DATA3_SECURE_MASK         (0x00000001U)
#define SA2UL_EXCEPTION_LOGGING_DATA3_SECURE_SHIFT        (0x00000000U)

#define SA2UL_EXCEPTION_LOGGING_DATA3_PROMOTE_MASK        (0x00000020U)
#define SA2UL_EXCEPTION_LOGGING_DATA3_PROMOTE_SHIFT       (0x00000005U)

#define SA2UL_EXCEPTION_LOGGING_DATA3_DEMOTE_MASK         (0x00000040U)
#define SA2UL_EXCEPTION_LOGGING_DATA3_DEMOTE_SHIFT        (0x00000006U)

#define SA2UL_EXCEPTION_LOGGING_DATA3_ALLOWNS_MASK        (0x00000080U)
#define SA2UL_EXCEPTION_LOGGING_DATA3_ALLOWNS_SHIFT       (0x00000007U)

#define SA2UL_EXCEPTION_LOGGING_DATA3_PRIV_MASK           (0x00000300U)
#define SA2UL_EXCEPTION_LOGGING_DATA3_PRIV_SHIFT          (0x00000008U)

#define SA2UL_EXCEPTION_LOGGING_DATA3_PRIV_ID_MASK        (0x00FF0000U)
#define SA2UL_EXCEPTION_LOGGING_DATA3_PRIV_ID_SHIFT       (0x00000010U)


/* DKEK_PRIVID */

#define SA2UL_DKEK_PRIVID_PRIVID3_MASK                    (0xFF000000U)
#define SA2UL_DKEK_PRIVID_PRIVID3_SHIFT                   (0x00000018U)

#define SA2UL_DKEK_PRIVID_PRIVID2_MASK                    (0x00FF0000U)
#define SA2UL_DKEK_PRIVID_PRIVID2_SHIFT                   (0x00000010U)

#define SA2UL_DKEK_PRIVID_PRIVID1_MASK                    (0x0000FF00U)
#define SA2UL_DKEK_PRIVID_PRIVID1_SHIFT                   (0x00000008U)

#define SA2UL_DKEK_PRIVID_PRIVID0_MASK                    (0x000000FFU)
#define SA2UL_DKEK_PRIVID_PRIVID0_SHIFT                   (0x00000000U)

#define SA2UL_TRNG_REGS_OFFSET                            (0x00010000U)

/* Number of output registers */
#define SA2UL_RNG_NUM_OUTPUT_WORDS (4U)

/* Length of the personalization string in 32 bit words */
#define SA2UL_TRNG_PS_AI_LEN (12U)

/**
 * \brief SA2UL TRNG registers
 *
 * \param TRNG_IN_OUT    Bank of four registers, Output in normal mode, input in test mode
 * \param TRNG_STATUS    Status register (R), intack reg (W)
 * \param TRNG_CONTROL   Control register
 * \param TRNG_CONFIG    Configuration register
 * \param TRNG_ALARMCNT  Alarm counter register
 * \param TRNG_FROENABLE FRO enable register
 * \param TRNG_FRODETUNE FRO de-tune register
 * \param TRNG_ALARMMASK Alarm mask register
 * \param TRNG_ALARMSTOP Alarm stop register
 * \param TRNG_RAW_L     Main shift register (low)
 * \param TRNG_RAW_H     Main shift register (high)
 * \param TRNG_SPB_TESTS SP 800-90B Tests Control/Status Register
 * \param TRNG_COUNT     Counter Access Register
 * \param TRNG_PS_AI     SP 800-90A DRBG Vector Registers
 * \param TRNG_TEST      Test Register
 * \param TRNG_BLOCKCNT  Block Count Register
 * \param TRNG_OPTIONS   HW Options Register
 * \param TRNG_EIP_REV   EIP Number and HW Revision Register
 */
struct sa2ul_trng_regs {
	volatile u32	TRNG_IN_OUT[SA2UL_RNG_NUM_OUTPUT_WORDS];
	volatile u32	TRNG_STATUS;
	volatile u32	TRNG_CONTROL;
	volatile u32	TRNG_CONFIG;
	volatile u32	TRNG_ALARMCNT;
	volatile u32	TRNG_FROENABLE;
	volatile u32	TRNG_FRODETUNE;
	volatile u32	TRNG_ALARMMASK;
	volatile u32	TRNG_ALARMSTOP;
	volatile u32	TRNG_RAW_L;
	volatile u32	TRNG_RAW_H;
	volatile u32	TRNG_SPB_TESTS;
	volatile u32	TRNG_COUNT;
	volatile u32	TRNG_PS_AI[SA2UL_TRNG_PS_AI_LEN];
	volatile u32	TRNG_TEST;
	volatile u32	TRNG_BLOCKCNT;
	volatile u32	TRNG_OPTIONS;
	volatile u32	TRNG_EIP_REV;
};

/* TRNG_STATUS */

#define TRNG_STATUS_READY_MASK                                   (0x00000001U)
#define TRNG_STATUS_READY_SHIFT                                  (0x00000000U)

#define TRNG_STATUS_SHUTDOWN_OFLO_MASK                           (0x00000002U)
#define TRNG_STATUS_SHUTDOWN_OFLO_SHIFT                          (0x00000001U)

#define TRNG_STATUS_STUCK_OUT_MASK                               (0x00000004U)
#define TRNG_STATUS_STUCK_OUT_SHIFT                              (0x00000002U)

#define TRNG_STATUS_NOISE_FAIL_MASK                              (0x00000008U)
#define TRNG_STATUS_NOISE_FAIL_SHIFT                             (0x00000003U)

#define TRNG_STATUS_RUN_FAIL_MASK                                (0x00000010U)
#define TRNG_STATUS_RUN_FAIL_SHIFT                               (0x00000004U)

#define TRNG_STATUS_LONG_RUN_FAIL_MASK                           (0x00000020U)
#define TRNG_STATUS_LONG_RUN_FAIL_SHIFT                          (0x00000005U)

#define TRNG_STATUS_POKER_FAIL_MASK                              (0x00000040U)
#define TRNG_STATUS_POKER_FAIL_SHIFT                             (0x00000006U)

#define TRNG_STATUS_MONOBIT_FAIL_MASK                            (0x00000080U)
#define TRNG_STATUS_MONOBIT_FAIL_SHIFT                           (0x00000007U)

#define TRNG_STATUS_TEST_READY_MASK                              (0x00000100U)
#define TRNG_STATUS_TEST_READY_SHIFT                             (0x00000008U)

#define TRNG_STATUS_STUCK_NRBG_MASK                              (0x00000200U)
#define TRNG_STATUS_STUCK_NRBG_SHIFT                             (0x00000009U)

#define TRNG_STATUS_RESEED_AI_MASK                               (0x00000400U)
#define TRNG_STATUS_RESEED_AI_SHIFT                              (0x0000000AU)

#define TRNG_STATUS_REPCNT_FAIL_MASK                             (0x00002000U)
#define TRNG_STATUS_REPCNT_FAIL_SHIFT                            (0x0000000DU)

#define TRNG_STATUS_APROP_FAIL_MASK                              (0x00004000U)
#define TRNG_STATUS_APROP_FAIL_SHIFT                             (0x0000000EU)

#define TRNG_STATUS_TEST_STUCK_OUT_MASK                          (0x00008000U)
#define TRNG_STATUS_TEST_STUCK_OUT_SHIFT                         (0x0000000FU)

#define TRNG_STATUS_BLOCKS_AVAILABLE_MASK                        (0x00FF0000U)
#define TRNG_STATUS_BLOCKS_AVAILABLE_SHIFT                       (0x00000010U)

#define TRNG_STATUS_BLOCKS_THRESH_MASK                           (0x7F000000U)
#define TRNG_STATUS_BLOCKS_THRESH_SHIFT                          (0x00000018U)

#define TRNG_STATUS_NEED_CLOCK_MASK                              (0x80000000U)
#define TRNG_STATUS_NEED_CLOCK_SHIFT                             (0x0000001FU)

/* TRNG_INTACK */

#define TRNG_INTACK_READY_ACK_MASK                               (0x00000001U)
#define TRNG_INTACK_READY_ACK_SHIFT                              (0x00000000U)

#define TRNG_INTACK_SHUTDOWN_OFLO_ACK_MASK                       (0x00000002U)
#define TRNG_INTACK_SHUTDOWN_OFLO_ACK_SHIFT                      (0x00000001U)

#define TRNG_INTACK_STUCK_OUT_ACK_MASK                           (0x00000004U)
#define TRNG_INTACK_STUCK_OUT_ACK_SHIFT                          (0x00000002U)

#define TRNG_INTACK_NOISE_FAIL_ACK_MASK                          (0x00000008U)
#define TRNG_INTACK_NOISE_FAIL_ACK_SHIFT                         (0x00000003U)

#define TRNG_INTACK_RUN_FAIL_ACK_MASK                            (0x00000010U)
#define TRNG_INTACK_RUN_FAIL_ACK_SHIFT                           (0x00000004U)

#define TRNG_INTACK_LONG_RUN_FAIL_ACK_MASK                       (0x00000020U)
#define TRNG_INTACK_LONG_RUN_FAIL_ACK_SHIFT                      (0x00000005U)

#define TRNG_INTACK_POKER_FAIL_ACK_MASK                          (0x00000040U)
#define TRNG_INTACK_POKER_FAIL_ACK_SHIFT                         (0x00000006U)

#define TRNG_INTACK_MONOBIT_FAIL_ACK_MASK                        (0x00000080U)
#define TRNG_INTACK_MONOBIT_FAIL_ACK_SHIFT                       (0x00000007U)

#define TRNG_INTACK_TEST_READY_ACK_MASK                          (0x00000100U)
#define TRNG_INTACK_TEST_READY_ACK_SHIFT                         (0x00000008U)

#define TRNG_INTACK_STUCK_NRBG_ACK_MASK                          (0x00000200U)
#define TRNG_INTACK_STUCK_NRBG_ACK_SHIFT                         (0x00000009U)

#define TRNG_INTACK_STUCK_OUT_ACK2_MASK                          (0x00000400U)
#define TRNG_INTACK_STUCK_OUT_ACK2_SHIFT                         (0x0000000AU)

#define TRNG_INTACK_OPEN_READ_GATE2_MASK                         (0x00001000U)
#define TRNG_INTACK_OPEN_READ_GATE2_SHIFT                        (0x0000000CU)

#define TRNG_INTACK_REPCNT_FAIL_ACK_MASK                         (0x00002000U)
#define TRNG_INTACK_REPCNT_FAIL_ACK_SHIFT                        (0x0000000DU)

#define TRNG_INTACK_APROP_FAIL_ACK_MASK                          (0x00004000U)
#define TRNG_INTACK_APROP_FAIL_ACK_SHIFT                         (0x0000000EU)

#define TRNG_INTACK_TEST_STUCK_OUT_MASK                          (0x00008000U)
#define TRNG_INTACK_TEST_STUCK_OUT_SHIFT                         (0x0000000FU)

#define TRNG_INTACK_BLOCKS_THRESH_MASK                           (0x7F000000U)
#define TRNG_INTACK_BLOCKS_THRESH_SHIFT                          (0x00000018U)

#define TRNG_INTACK_LOAD_THRESH_MASK                             (0x80000000U)
#define TRNG_INTACK_LOAD_THRESH_SHIFT                            (0x0000001FU)


/* TRNG_CONTROL */

#define TRNG_CONTROL_READY_MASK_MASK                             (0x00000001U)
#define TRNG_CONTROL_READY_MASK_SHIFT                            (0x00000000U)

#define TRNG_CONTROL_SHUTDOWN_OFLO_MASK_MASK                     (0x00000002U)
#define TRNG_CONTROL_SHUTDOWN_OFLO_MASK_SHIFT                    (0x00000001U)

#define TRNG_CONTROL_STUCK_OUT_MASK_MASK                         (0x00000004U)
#define TRNG_CONTROL_STUCK_OUT_MASK_SHIFT                        (0x00000002U)

#define TRNG_CONTROL_NOISE_FAIL_MASK_MASK                        (0x00000008U)
#define TRNG_CONTROL_NOISE_FAIL_MASK_SHIFT                       (0x00000003U)

#define TRNG_CONTROL_RUN_FAIL_MASK_MASK                          (0x00000010U)
#define TRNG_CONTROL_RUN_FAIL_MASK_SHIFT                         (0x00000004U)

#define TRNG_CONTROL_LONG_RUN_FAIL_MASK_MASK                     (0x00000020U)
#define TRNG_CONTROL_LONG_RUN_FAIL_MASK_SHIFT                    (0x00000005U)

#define TRNG_CONTROL_POKER_FAIL_MASK_MASK                        (0x00000040U)
#define TRNG_CONTROL_POKER_FAIL_MASK_SHIFT                       (0x00000006U)

#define TRNG_CONTROL_MONOBIT_FAIL_MASK_MASK                      (0x00000080U)
#define TRNG_CONTROL_MONOBIT_FAIL_MASK_SHIFT                     (0x00000007U)

#define TRNG_CONTROL_TEST_MODE_MASK                              (0x00000100U)
#define TRNG_CONTROL_TEST_MODE_SHIFT                             (0x00000008U)

#define TRNG_CONTROL_STUCK_NRBG_MASK_MASK                        (0x00000200U)
#define TRNG_CONTROL_STUCK_NRBG_MASK_SHIFT                       (0x00000009U)

#define TRNG_CONTROL_ENABLE_TRNG_MASK                            (0x00000400U)
#define TRNG_CONTROL_ENABLE_TRNG_SHIFT                           (0x0000000AU)

#define TRNG_CONTROL_NO_WHITENING_MASK                           (0x00000800U)
#define TRNG_CONTROL_NO_WHITENING_SHIFT                          (0x0000000BU)

#define TRNG_CONTROL_DRBG_EN_MASK                                (0x00001000U)
#define TRNG_CONTROL_DRBG_EN_SHIFT                               (0x0000000CU)

#define TRNG_CONTROL_REPCNT_FAIL_MASK_MASK                       (0x00002000U)
#define TRNG_CONTROL_REPCNT_FAIL_MASK_SHIFT                      (0x0000000DU)

#define TRNG_CONTROL_APROP_FAIL_MASK_MASK                        (0x00004000U)
#define TRNG_CONTROL_APROP_FAIL_MASK_SHIFT                       (0x0000000EU)

#define TRNG_CONTROL_RE_SEED_MASK                                (0x00008000U)
#define TRNG_CONTROL_RE_SEED_SHIFT                               (0x0000000FU)

#define TRNG_CONTROL_REQUEST_DATA_MASK                           (0x00010000U)
#define TRNG_CONTROL_REQUEST_DATA_SHIFT                          (0x00000010U)

#define TRNG_CONTROL_REQUEST_HOLD_MASK                           (0x00020000U)
#define TRNG_CONTROL_REQUEST_HOLD_SHIFT                          (0x00000011U)

#define TRNG_CONTROL_DATA_BLOCKS_MASK                            (0xFFF00000U)
#define TRNG_CONTROL_DATA_BLOCKS_SHIFT                           (0x00000014U)


/* TRNG_CONFIG */

/*
 * We do not use this field currently. This field varies between RNG revision
 * 2.3 and 2.4 If SYSFW needs to program this field in the future, we need to
 * handle the PG revisions using a config macro. For now, we define the field
 * width for RNG version 2.4
 */
#define TRNG_CONFIG_NOISE_BLOCKS_MASK                            (0x0000001FU)
#define TRNG_CONFIG_NOISE_BLOCKS_SHIFT                           (0x00000000U)

#define TRNG_CONFIG_SCALE_MASK                                   (0x000000C0U)
#define TRNG_CONFIG_SCALE_SHIFT                                  (0x00000006U)

#define TRNG_CONFIG_SAMPLE_DIV_MASK                              (0x00000F00U)
#define TRNG_CONFIG_SAMPLE_DIV_SHIFT                             (0x00000008U)

#define TRNG_CONFIG_READ_TIMEOUT_MASK                            (0x0000F000U)
#define TRNG_CONFIG_READ_TIMEOUT_SHIFT                           (0x0000000CU)

#define TRNG_CONFIG_SAMPLE_CYCLES_MASK                           (0xFFFF0000U)
#define TRNG_CONFIG_SAMPLE_CYCLES_SHIFT                          (0x00000010U)


/* TRNG_ALARMCNT */

#define TRNG_ALARMCNT_ALARM_THRESHOLD_MASK                       (0x000000FFU)
#define TRNG_ALARMCNT_ALARM_THRESHOLD_SHIFT                      (0x00000000U)

#define TRNG_ALARMCNT_STALL_RUN_POKER_MASK                       (0x00008000U)
#define TRNG_ALARMCNT_STALL_RUN_POKER_SHIFT                      (0x0000000FU)

#define TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_MASK                    (0x001F0000U)
#define TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_SHIFT                   (0x00000010U)

#define TRNG_ALARMCNT_SHUTDOWN_FATAL_MASK                        (0x00800000U)
#define TRNG_ALARMCNT_SHUTDOWN_FATAL_SHIFT                       (0x00000017U)

#define TRNG_ALARMCNT_SHUTDOWN_COUNT_MASK                        (0x3F000000U)
#define TRNG_ALARMCNT_SHUTDOWN_COUNT_SHIFT                       (0x00000018U)


/* TRNG_SPB_TESTS */

#define TRNG_SPB_TESTS_REPCNT_CUTOFF_MASK                        (0x0000003FU)
#define TRNG_SPB_TESTS_REPCNT_CUTOFF_SHIFT                       (0x00000000U)

#define TRNG_SPB_TESTS_APROP_64_CUTOFF_MASK                      (0x00003F00U)
#define TRNG_SPB_TESTS_APROP_64_CUTOFF_SHIFT                     (0x00000008U)

#define TRNG_SPB_TESTS_APROP_512_CUTOFF_MASK                     (0x01FF0000U)
#define TRNG_SPB_TESTS_APROP_512_CUTOFF_SHIFT                    (0x00000010U)

#define TRNG_SPB_TESTS_SHOW_COUNTERS_MASK                        (0x10000000U)
#define TRNG_SPB_TESTS_SHOW_COUNTERS_SHIFT                       (0x0000001CU)

#define TRNG_SPB_TESTS_SHOW_VALUES_MASK                          (0x20000000U)
#define TRNG_SPB_TESTS_SHOW_VALUES_SHIFT                         (0x0000001DU)

#define TRNG_SPB_TESTS_APROP_64_FAIL_MASK                        (0x40000000U)
#define TRNG_SPB_TESTS_APROP_64_FAIL_SHIFT                       (0x0000001EU)

#define TRNG_SPB_TESTS_APROP_512_FAIL_MASK                       (0x80000000U)
#define TRNG_SPB_TESTS_APROP_512_FAIL_SHIFT                      (0x0000001FU)


/* TRNG_COUNT */

#define TRNG_COUNT_SAMPLE_CYC_CNT_MASK                           (0x0000FFFFU)
#define TRNG_COUNT_SAMPLE_CYC_CNT_SHIFT                          (0x00000000U)

#define TRNG_COUNT_NOISE_BLK_CNT_MASK                            (0x003F0000U)
#define TRNG_COUNT_NOISE_BLK_CNT_SHIFT                           (0x00000010U)

#define TRNG_COUNT_SAMPLE_CYC_EXT_MASK                           (0x3F000000U)
#define TRNG_COUNT_SAMPLE_CYC_EXT_SHIFT                          (0x00000018U)


/* TRNG_TEST */

#define TRNG_TEST_TEST_EN_OUT_MASK                               (0x00000001U)
#define TRNG_TEST_TEST_EN_OUT_SHIFT                              (0x00000000U)

#define TRNG_TEST_TEST_PATT_FR_MASK                              (0x00000002U)
#define TRNG_TEST_TEST_PATT_FR_SHIFT                             (0x00000001U)

#define TRNG_TEST_TEST_PATT_DET_MASK                             (0x00000004U)
#define TRNG_TEST_TEST_PATT_DET_SHIFT                            (0x00000002U)

#define TRNG_TEST_TEST_SHIFTREG_MASK                             (0x00000008U)
#define TRNG_TEST_TEST_SHIFTREG_SHIFT                            (0x00000003U)

#define TRNG_TEST_CONT_POKER_MASK                                (0x00000010U)
#define TRNG_TEST_CONT_POKER_SHIFT                               (0x00000004U)

#define TRNG_TEST_TEST_KNOWN_NOISE_MASK                          (0x00000020U)
#define TRNG_TEST_TEST_KNOWN_NOISE_SHIFT                         (0x00000005U)

#define TRNG_TEST_TEST_AES_256_MASK                              (0x00000040U)
#define TRNG_TEST_TEST_AES_256_SHIFT                             (0x00000006U)

#define TRNG_TEST_TEST_SP_800_90_MASK                            (0x00000080U)
#define TRNG_TEST_TEST_SP_800_90_SHIFT                           (0x00000007U)

#define TRNG_TEST_TEST_SELECT_MASK                               (0x00001F00U)
#define TRNG_TEST_TEST_SELECT_SHIFT                              (0x00000008U)

#define TRNG_TEST_TEST_NOISE_MASK                                (0x00002000U)
#define TRNG_TEST_TEST_NOISE_SHIFT                               (0x0000000DU)

#define TRNG_TEST_TEST_SPB_MASK                                  (0x00004000U)
#define TRNG_TEST_TEST_SPB_SHIFT                                 (0x0000000EU)

#define TRNG_TEST_TEST_PATTERN_MASK                              (0x0FFF0000U)
#define TRNG_TEST_TEST_PATTERN_SHIFT                             (0x00000010U)

#define TRNG_TEST_FRO_TESTIN2_NOT_MASK                           (0x10000000U)
#define TRNG_TEST_FRO_TESTIN2_NOT_SHIFT                          (0x0000001CU)

#define TRNG_TEST_FRO_TESTIN3_MASK                               (0x20000000U)
#define TRNG_TEST_FRO_TESTIN3_SHIFT                              (0x0000001DU)

#define TRNG_TEST_FRO_TESTIN4_MASK                               (0x40000000U)
#define TRNG_TEST_FRO_TESTIN4_SHIFT                              (0x0000001EU)

#define TRNG_TEST_TEST_IRQ_MASK                                  (0x80000000U)
#define TRNG_TEST_TEST_IRQ_SHIFT                                 (0x0000001FU)


/* TRNG_OPTIONS */

#define TRNG_OPTIONS_POST_PROCESSOR_MASK                         (0x00000007U)
#define TRNG_OPTIONS_POST_PROCESSOR_SHIFT                        (0x00000000U)

#define TRNG_OPTIONS_NR_OF_FROS_MASK                             (0x00000FC0U)
#define TRNG_OPTIONS_NR_OF_FROS_SHIFT                            (0x00000006U)

#define TRNG_OPTIONS_BUFFER_SIZE_MASK                            (0x00007000U)
#define TRNG_OPTIONS_BUFFER_SIZE_SHIFT                           (0x0000000CU)

#define TRNG_OPTIONS_PR_TEST_MASK                                (0x00010000U)
#define TRNG_OPTIONS_PR_TEST_SHIFT                               (0x00000010U)

#define TRNG_OPTIONS_CONDITIONER_MASK                            (0x00060000U)
#define TRNG_OPTIONS_CONDITIONER_SHIFT                           (0x00000011U)

#define TRNG_OPTIONS_DETUNING_OPTION_MASK                        (0x00080000U)
#define TRNG_OPTIONS_DETUNING_OPTION_SHIFT                       (0x00000013U)

#define TRNG_OPTIONS_APROP_512_MASK                              (0x00200000U)
#define TRNG_OPTIONS_APROP_512_SHIFT                             (0x00000015U)

#define TRNG_OPTIONS_AUTO_DETUNE_MASK                            (0x00800000U)
#define TRNG_OPTIONS_AUTO_DETUNE_SHIFT                           (0x00000017U)

#define TRNG_OPTIONS_DETUNE_COUNT_MASK                           (0xFF000000U)
#define TRNG_OPTIONS_DETUNE_COUNT_SHIFT                          (0x00000018U)

/** PKA RAM size (4kbytes) in words */
#define SA2UL_PKA_RAM_SIZE_WORDS                   (1024U)

/** PKA PROGRAM RAM size (12kbytes) in words */
#define SA2UL_PKA_PROGRAM_RAM_SIZE_WORDS           (3072U)

#define SA2UL_PKA_REGS_OFFSET                      (0x00020000U)

/**
 * \brief SA2UL PKA registers
 *
 * \param PKA_APTR       PKA-RAM offset (in words) of Vector A
 * \param PKA_BPTR       PKA-RAM offset (in words) of Vector B
 * \param PKA_CPTR       PKA-RAM offset (in words) of Vector C
 * \param PKA_DPTR       PKA-RAM offset (in words) of Vector D
 * \param PKA_ALENGTH    Length (in words) of Vector A
 * \param PKA_BLENGTH    Length (in words) of Vector B
 * \param PKA_SHIFT      Shift value
 * \param PKA_FUNCTION   Operation (basic or complex), "busy" indication
 * \param PKA_COMPARE    Result of basic "compare(A, B)" op
 * \param PKA_MSW        size of the result of basic operation
 * \param PKA_DIVMSW     size of the result of divide operation
 * \param PKA_SEQ_CTRL   Sequencer control & status
 * \param PKA_OPTIONS    HW configuration
 * \param PKA_SW_REV     FW revision info
 * \param PKA_REVISION   PKA revision info
 * \param PKA_REV        EIP-29t2 revision number
 * \param PKA_CLK_CTRL   PKA clock control
 * \param PKA_SYSSCONFIG PKA Configuration (softreset)
 * \param PKA_SYSSTATUS  System Status
 * \param PKA_IRQSTATUS  Interrupt Status
 * \param PKA_IRQENABLE  Interrupt Enable
 * \param PKA_RAM PKA RAM (for operands) overlaid with PROGRAM RAM where the
 *                sequencer firmeware is loaded. The program RAM is visible
 *                when the sequencer is held in reset
 */
struct sa2ul_pka_regs {
	volatile u32	PKA_APTR;
	volatile u32	PKA_BPTR;
	volatile u32	PKA_CPTR;
	volatile u32	PKA_DPTR;
	volatile u32	PKA_ALENGTH;
	volatile u32	PKA_BLENGTH;
	volatile u32	PKA_SHIFT;
	volatile u32	PKA_FUNCTION;
	volatile u32	PKA_COMPARE;
	volatile u32	PKA_MSW;
	volatile u32	PKA_DIVMSW;
	u8		reserved0[0xC8 - 0x2C];
	volatile u32	PKA_SEQ_CTRL;
	u8		reserved1[0xF4 - 0xCC];
	volatile u32	PKA_OPTIONS;
	volatile u32	PKA_SW_REV;
	volatile u32	PKA_REVISION;
	u8		reserved2[0x1FE0 - 0x100];
	volatile u32	PKA_REV;
	u8		reserved3[0x1FE8 - 0x1FE4];
	volatile u32	PKA_CLK_CTRL;
	u8		reserved4[0x1FF0 - 0x1FEC];
	volatile u32	PKA_SYSSCONFIG;
	volatile u32	PKA_SYSSTATUS;
	volatile u32	PKA_IRQSTATUS;
	volatile u32	PKA_IRQENABLE;
	u8		reserved5[0x4000 - 0x2000];
	u32		PKA_RAM[SA2UL_PKA_PROGRAM_RAM_SIZE_WORDS];
};

/* PKA FUNCTION register bits */
#define PKA_FUNCTION_MULTIPLY_MASK                 (1UL << 0)
#define PKA_FUNCTION_MULTIPLY_SHIFT                (0)

#define PKA_FUNCTION_ADDSUB_MASK                   (1UL << 1)
#define PKA_FUNCTION_ADDSUB_SHIFT                  (1)

#define PKA_FUNCTION_MSONE_MASK                    (1UL << 3)
#define PKA_FUNCTION_MSONE_SHIFT                   (3)

#define PKA_FUNCTION_ADD_MASK                      (1UL << 4)
#define PKA_FUNCTION_ADD_SHIFT                     (4)

#define PKA_FUNCTION_SUBTRACT_MASK                 (1UL << 5)
#define PKA_FUNCTION_SUBTRACT_SHIFT                (5)

#define PKA_FUNCTION_RSHIFT_MASK                   (1UL << 6)
#define PKA_FUNCTION_RSHIFT_SHIFT                  (6)

#define PKA_FUNCTION_LSHIFT_MASK                   (1UL << 7)
#define PKA_FUNCTION_LSHIFT_SHIFT                  (7)

#define PKA_FUNCTION_DIVIDE_MASK                   (1UL << 8)
#define PKA_FUNCTION_DIVIDE_SHIFT                  (8)

#define PKA_FUNCTION_MODULO_MASK                   (1UL << 9)
#define PKA_FUNCTION_MODULO_SHIFT                  (9)

#define PKA_FUNCTION_COMPARE_MASK                  (1UL << 10)
#define PKA_FUNCTION_COMPARE_SHIFT                 (10)

#define PKA_FUNCTION_COPY_MASK                     (1UL << 11)
#define PKA_FUNCTION_COPY_SHIFT                    (11)

#define PKA_FUNCTION_RUN_MASK                      (1UL << 15)
#define PKA_FUNCTION_RUN_SHIFT                     (15)

#define PKA_FUNCTION_CMD_HI_MASK                   (7UL << 16)
#define PKA_FUNCTION_CMD_HI_SHIFT                  (16)

#define PKA_FUNCTION_CMD_LO_MASK                   (7UL << 12)
#define PKA_FUNCTION_CMD_LO_SHIFT                  (12)

/* PKA COMPARE register bits */
#define PKA_COMPARE_A_EQ_B_MASK                    (1UL << 0)
#define PKA_COMPARE_A_EQ_B_SHIFT                   (0)

#define PKA_COMPARE_A_LT_B_MASK                    (1UL << 1)
#define PKA_COMPARE_A_LT_B_SHIFT                   (1)

#define PKA_COMPARE_A_GT_B_MASK                    (1UL << 2)
#define PKA_COMPARE_A_GT_B_SHIFT                   (2)

/* PKA_SEQ_CTRL bits */
#define PKA_SEQ_CTRL_RESET_MASK                    (1UL << 31)
#define PKA_SEQ_CTRL_RESET_SHIFT                   (31)

#define PKA_SEQ_CTRL_DONE_MASK                     (1UL << 8)
#define PKA_SEQ_CTRL_DONE_SHIFT                    (8)

#define PKA_SEQ_CTRL_RESULT_MASK                   (0xffUL << 8)
#define PKA_SEQ_CTRL_RESULT_SHIFT                  (8)

/* PKA_SW_REV bits */
#define PKA_SW_REV_FIRMWARE_VERSION_MASK           (0xfffUL << 16)
#define PKA_SW_REV_FIRMWARE_VERSION_SHIFT          (16)

#define PKA_SW_REV_FIRMWARE_CAPABILITIES_MASK      (0xfUL << 28)
#define PKA_SW_REV_FIRMWARE_CAPABILITIES_SHIFT     (28)

/* PKA_CLK_CTRL bits */
#define PKA_CLK_CTRL_DATA_RAM_CLK_ON_MASK          (1UL << 6)
#define PKA_CLK_CTRL_DATA_RAM_CLK_ON_SHIFT         (6)

#define PKA_CLK_CTRL_GF2M_CLK_ON_MASK              (1UL << 5)
#define PKA_CLK_CTRL_GF2M_CLK_ON_SHIFT             (5)

#define PKA_CLK_CTRL_LNME_REG_CLK_ON_MASK          (1UL << 4)
#define PKA_CLK_CTRL_LNME_REG_CLK_ON_SHIFT         (4)

#define PKA_CLK_CTRL_LNME_CLK_ON_MASK              (1UL << 3)
#define PKA_CLK_CTRL_LNME_CLK_ON_SHIFT             (3)

#define PKA_CLK_CTRL_PKCP_CLK_ON_MASK              (1UL << 2)
#define PKA_CLK_CTRL_PKCP_CLK_ON_SHIFT             (2)

#define PKA_CLK_CTRL_SEQ_CLK_ON_MASK               (1UL << 1)
#define PKA_CLK_CTRL_SEQ_CLK_ON_SHIFT              (1)

#define PKA_CLK_CTRL_REG_CLK_ON_MASK               (1UL << 0)
#define PKA_CLK_CTRL_REG_CLK_ON_SHIFT              (0)

#define PKA_CLK_CTRL_DATA_RAM_CLK_OFF_MASK         (1UL << 14)
#define PKA_CLK_CTRL_DATA_RAM_CLK_OFF_SHIFT        (14)

#define PKA_CLK_CTRL_GF2M_CLK_OFF_MASK             (1UL << 13)
#define PKA_CLK_CTRL_GF2M_CLK_OFF_SHIFT            (13)

#define PKA_CLK_CTRL_LNME_REG_CLK_OFF_MASK         (1UL << 12)
#define PKA_CLK_CTRL_LNME_REG_CLK_OFF_SHIFT        (12)

#define PKA_CLK_CTRL_LNME_CLK_OFF_MASK             (1UL << 11)
#define PKA_CLK_CTRL_LNME_CLK_OFF_SHIFT            (11)

#define PKA_CLK_CTRL_PKCP_CLK_OFF_MASK             (1UL << 10)
#define PKA_CLK_CTRL_PKCP_CLK_OFF_SHIFT            (10)

#define PKA_CLK_CTRL_SEQ_CLK_OFF_MASK              (1UL << 9)
#define PKA_CLK_CTRL_SEQ_CLK_OFF_SHIFT             (9)

#define PKA_CLK_CTRL_REG_CLK_OFF_MASK              (1UL << 8)
#define PKA_CLK_CTRL_REG_CLK_OFF_SHIFT             (8)

#define PKA_CLK_CTRL_DATA_RAM_CLK_EN_MASK          (1UL << 22)
#define PKA_CLK_CTRL_DATA_RAM_CLK_EN_SHIFT         (22)

#define PKA_CLK_CTRL_GF2M_CLK_EN_MASK              (1UL << 21)
#define PKA_CLK_CTRL_GF2M_CLK_EN_SHIFT             (21)

#define PKA_CLK_CTRL_LNME_REG_CLK_EN_MASK          (1UL << 20)
#define PKA_CLK_CTRL_LNME_REG_CLK_EN_SHIFT         (20)

#define PKA_CLK_CTRL_LNME_CLK_EN_MASK              (1UL << 19)
#define PKA_CLK_CTRL_LNME_CLK_EN_SHIFT             (19)

#define PKA_CLK_CTRL_PKCP_CLK_EN_MASK              (1UL << 18)
#define PKA_CLK_CTRL_PKCP_CLK_EN_SHIFT             (18)

#define PKA_CLK_CTRL_SEQ_CLK_EN_MASK               (1UL << 17)
#define PKA_CLK_CTRL_SEQ_CLK_EN_SHIFT              (17)

#define PKA_CLK_CTRL_REG_CLK_EN_MASK               (1UL << 16)
#define PKA_CLK_CTRL_REG_CLK_EN_SHIFT              (16)

#endif /* SA2UL_REGS_H_ */
