/*
 * System Firmware NAVSS UDMAP/DMSS PKTDMA Library
 *
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file udmap.c
 *
 * \brief UDMAP channel configuration functions
 *
 * Though this file is named udmap.c, a lot of code is reused for pktdma as well.
 * Only 3 functions in file work differently between udma and pktdma.
 *
 * 1. udmap_txchan_setup_psil_pkt_mode_regs
 * 2. udmap_rxchan_setup_psil_pkt_mode_regs
 * 3. udmap_rxflow_setup_simple
 *
 * In these 3 functions, udma operation is a superset of pktdma operation.
 *
 * Only macro is different - UDMAP_TXCCFG_CHAN_TFIFO_DEPTH_FDEPTH_MASK
 */

#include <config.h>
#include <common_funcs.h>

#include "sec_dma_internal.h"
#include "udmap.h"

/**
 * Timeout value for teardown completion
 */
#define UDMAP_TDOWN_TIMEOUT_US                100U

/**
 * \brief UDMA-P Tx Channel Configuration Registers
 *
 * \param TCFG Tx Channel Configuration Register
 * \param TCREDIT Tx Channel Transfer Request Credit Register
 * \param TCQ Tx Channel Completion Queue Register
 * \param TOES Tx Channel Output Event Steering Register 0
 * \param TEOES Tx Channel Error Output Event Steering Register 0
 * \param TPRI_CTRL Tx Channel Priority Control Register
 * \param THREAD Tx Channel Destination ThreadID Mapping Register
 * \param TFIFO_DEPTH Tx Channel FIFO Depth Register
 * \param TST_SCHED Tx Channel Static Scheduler Config Register
 */
struct udmap_txccfg_regs {
	volatile u32	TCFG;
	volatile u32	TCREDIT;
	volatile u8	Resv_20[12];
	volatile u32	TCQ;
	volatile u8	Resv_32[8];
	volatile u32	TOES;
	volatile u8	Resv_96[60];
	volatile u32	TEOES;
	volatile u32	TPRI_CTRL;
	volatile u32	THREAD;
	volatile u8	Resv_112[4];
	volatile u32	TFIFO_DEPTH;
	volatile u8	Resv_128[12];
	volatile u32	TST_SCHED;
	volatile u8	Resv_256[124];
};

#define UDMAP_TXCCFG_CHAN_OFFSET                       (0x100U)
/*
 * Register Fields
 */

/* TCFG */

#define UDMAP_TXCCFG_CHAN_TCFG_PAUSE_ON_ERR_MASK       (0x80000000U)
#define UDMAP_TXCCFG_CHAN_TCFG_PAUSE_ON_ERR_SHIFT      (0x0000001FU)
#define UDMAP_TXCCFG_CHAN_TCFG_FILT_EINFO_MASK         (0x40000000U)
#define UDMAP_TXCCFG_CHAN_TCFG_FILT_EINFO_SHIFT        (0x0000001EU)
#define UDMAP_TXCCFG_CHAN_TCFG_FILT_PSWORDS_MASK       (0x20000000U)
#define UDMAP_TXCCFG_CHAN_TCFG_FILT_PSWORDS_SHIFT      (0x0000001DU)
#define UDMAP_TXCCFG_CHAN_TCFG_ATYPE_MASK              (0x03000000U)
#define UDMAP_TXCCFG_CHAN_TCFG_ATYPE_SHIFT             (0x00000018U)
#define UDMAP_TXCCFG_CHAN_TCFG_CHAN_TYPE_MASK          (0x000F0000U)
#define UDMAP_TXCCFG_CHAN_TCFG_CHAN_TYPE_SHIFT         (0x00000010U)
#define UDMAP_TXCCFG_CHAN_TCFG_NOTDPKT_MASK            (0x00000100U)
#define UDMAP_TXCCFG_CHAN_TCFG_NOTDPKT_SHIFT           (0x00000008U)
#define UDMAP_TXCCFG_CHAN_TCFG_FETCH_SIZE_MASK         (0x0000007FU)
#define UDMAP_TXCCFG_CHAN_TCFG_FETCH_SIZE_SHIFT        (0x00000000U)


/* TCREDIT */
#define UDMAP_TXCCFG_CHAN_TCREDIT_COUNT_MASK           (0x00000007U)
#define UDMAP_TXCCFG_CHAN_TCREDIT_COUNT_SHIFT          (0x00000000U)


/* TCQ */
#define UDMAP_TXCCFG_CHAN_TCQ_TXCQ_QNUM_MASK           (0x0000FFFFU)
#define UDMAP_TXCCFG_CHAN_TCQ_TXCQ_QNUM_SHIFT          (0x00000000U)


/* TOES */
#define UDMAP_TXCCFG_CHAN_TOES_EVT_NUM_MASK            (0x0000FFFFU)
#define UDMAP_TXCCFG_CHAN_TOES_EVT_NUM_SHIFT           (0x00000000U)


/* TEOES */
#define UDMAP_TXCCFG_CHAN_TEOES_EVT_NUM_MASK           (0x0000FFFFU)
#define UDMAP_TXCCFG_CHAN_TEOES_EVT_NUM_SHIFT          (0x00000000U)


/* TPRI_CTRL */
#define UDMAP_TXCCFG_CHAN_TPRI_CTRL_PRIORITY_MASK      (0x70000000U)
#define UDMAP_TXCCFG_CHAN_TPRI_CTRL_PRIORITY_SHIFT     (0x0000001CU)
#define UDMAP_TXCCFG_CHAN_TPRI_CTRL_QOS_MASK           (0x00070000U)
#define UDMAP_TXCCFG_CHAN_TPRI_CTRL_QOS_SHIFT          (0x00000010U)
#define UDMAP_TXCCFG_CHAN_TPRI_CTRL_ORDERID_MASK       (0x0000000FU)
#define UDMAP_TXCCFG_CHAN_TPRI_CTRL_ORDERID_SHIFT      (0x00000000U)


/* THREAD */
#define UDMAP_TXCCFG_CHAN_THREAD_ID_MASK               (0x0000FFFFU)
#define UDMAP_TXCCFG_CHAN_THREAD_ID_SHIFT              (0x00000000U)


/* TFIFO_DEPTH - PKTDMA has a smaller FIFO depth */
#if defined(CONFIG_SECURITY_DMA_UDMA)
#define UDMAP_TXCCFG_CHAN_TFIFO_DEPTH_FDEPTH_MASK      (0x000007FFU)
#elif defined(CONFIG_SECURITY_DMA_PKTDMA)
#define UDMAP_TXCCFG_CHAN_TFIFO_DEPTH_FDEPTH_MASK      (0x000000FFU)
#endif
#define UDMAP_TXCCFG_CHAN_TFIFO_DEPTH_FDEPTH_SHIFT     (0x00000000U)


/* TST_SCHED */
#define UDMAP_TXCCFG_CHAN_TST_SCHED_PRIORITY_MASK      (0x00000003U)
#define UDMAP_TXCCFG_CHAN_TST_SCHED_PRIORITY_SHIFT     (0x00000000U)


/**
 * \brief UDMA-P Tx Channel Realtime Registers
 *
 * \param CTL Tx Channel Realtime Control Register
 * \param SWTRIG Tx Channel Realtime Software Trigger Register
 * \param STDATA[32] Tx Channel Realtime State Data Register
 * \param PEER0 Tx Channel Real-time Remote Peer Register 0
 * \param PEER1 Tx Channel Real-time Remote Peer Register 1
 * \param PEER2 Tx Channel Real-time Remote Peer Register 2
 * \param PEER3 Tx Channel Real-time Remote Peer Register 3
 * \param PEER4 Tx Channel Real-time Remote Peer Register 4
 * \param PEER5 Tx Channel Real-time Remote Peer Register 5
 * \param PEER6 Tx Channel Real-time Remote Peer Register 6
 * \param PEER7 Tx Channel Real-time Remote Peer Register 7
 * \param PEER8 Tx Channel Real-time Remote Peer Register 8
 * \param PEER9 Tx Channel Real-time Remote Peer Register 9
 * \param PEER10 Tx Channel Real-time Remote Peer Register 10
 * \param PEER11 Tx Channel Real-time Remote Peer Register 11
 * \param PEER12 Tx Channel Real-time Remote Peer Register 12
 * \param PEER13 Tx Channel Real-time Remote Peer Register 13
 * \param PEER14 Tx Channel Real-time Remote Peer Register 14
 * \param PEER15 Tx Channel Real-time Remote Peer Register 15
 * \param PCNT Tx Channel Real-time Packet Count Statistics Register
 * \param BCNT Tx Channel Real-time Completed Byte Count Statistics Register
 * \param SBCNT Tx Channel Real-time Started Byte Count Statistics Register
 */
struct udmap_txcrt_regs {
	volatile u32	CTL;
	volatile u8	Resv_8[4];
	volatile u32	SWTRIG;
	volatile u8	Resv_128[116];
	volatile u32	STDATA[32];
	volatile u8	Resv_512[256];
	volatile u32	PEER0;
	volatile u32	PEER1;
	volatile u32	PEER2;
	volatile u32	PEER3;
	volatile u32	PEER4;
	volatile u32	PEER5;
	volatile u32	PEER6;
	volatile u32	PEER7;
	volatile u32	PEER8;
	volatile u32	PEER9;
	volatile u32	PEER10;
	volatile u32	PEER11;
	volatile u32	PEER12;
	volatile u32	PEER13;
	volatile u32	PEER14;
	volatile u32	PEER15;
	volatile u8	Resv_1024[448];
	volatile u32	PCNT;
	volatile u8	Resv_1032[4];
	volatile u32	BCNT;
	volatile u8	Resv_1040[4];
	volatile u32	SBCNT;
	volatile u8	Resv_4096[3052];
};

#define UDMAP_TXCRT_CHAN_OFFSET              (0x1000U)

/*
 * Register Fields
 */

#define UDMAP_TXCRT_CHAN_CTL_EN_MASK         (0x80000000U)
#define UDMAP_TXCRT_CHAN_CTL_EN_SHIFT        (0x0000001FU)
#define UDMAP_TXCRT_CHAN_CTL_TDOWN_MASK      (0x40000000U)
#define UDMAP_TXCRT_CHAN_CTL_TDOWN_SHIFT     (0x0000001EU)
#define UDMAP_TXCRT_CHAN_CTL_PAUSE_MASK      (0x20000000U)
#define UDMAP_TXCRT_CHAN_CTL_PAUSE_SHIFT     (0x0000001DU)
#define UDMAP_TXCRT_CHAN_CTL_FTDOWN_MASK     (0x10000000U)
#define UDMAP_TXCRT_CHAN_CTL_FTDOWN_SHIFT    (0x0000001CU)
#define UDMAP_TXCRT_CHAN_CTL_ERROR_MASK      (0x00000001U)
#define UDMAP_TXCRT_CHAN_CTL_ERROR_SHIFT     (0x00000000U)

/**
 * \brief UDMA-P Rx Flow Table Registers
 *
 * \param RFA Rx Flow Config Register A
 * \param RFB Rx Flow Config Register B
 * \param RFC Rx Flow Config Register C
 * \param RFD Rx Flow Config Register D
 * \param RFE Rx Flow Config Register E
 * \param RFF Rx Flow Config Register F
 * \param RFG Rx Flow Config Register G
 * \param RFH Rx Flow Config Register H
 */
struct udmap_rxfcfg_regs {
	volatile u32	RFA;
	volatile u32	RFB;
	volatile u32	RFC;
	volatile u32	RFD;
	volatile u32	RFE;
	volatile u32	RFF;
	volatile u32	RFG;
	volatile u32	RFH;
	volatile u8	Resv_64[32];
};

#define UDMAP_RXFCFG_FLOW_OFFSET                      (0x40U)
/*
 * Register Fields
 */

/* RFA */

#define UDMAP_RXFCFG_FLOW_RFA_EINFO_MASK             (0x40000000U)
#define UDMAP_RXFCFG_FLOW_RFA_EINFO_SHIFT            (0x0000001EU)
#define UDMAP_RXFCFG_FLOW_RFA_PSINFO_MASK            (0x20000000U)
#define UDMAP_RXFCFG_FLOW_RFA_PSINFO_SHIFT           (0x0000001DU)
#define UDMAP_RXFCFG_FLOW_RFA_ERR_HANDLING_MASK      (0x10000000U)
#define UDMAP_RXFCFG_FLOW_RFA_ERR_HANDLING_SHIFT     (0x0000001CU)
#define UDMAP_RXFCFG_FLOW_RFA_DESC_TYPE_MASK         (0x0C000000U)
#define UDMAP_RXFCFG_FLOW_RFA_DESC_TYPE_SHIFT        (0x0000001AU)
#define UDMAP_RXFCFG_FLOW_RFA_PS_LOC_MASK            (0x02000000U)
#define UDMAP_RXFCFG_FLOW_RFA_PS_LOC_SHIFT           (0x00000019U)
#define UDMAP_RXFCFG_FLOW_RFA_SOP_OFF_MASK           (0x01FF0000U)
#define UDMAP_RXFCFG_FLOW_RFA_SOP_OFF_SHIFT          (0x00000010U)
#define UDMAP_RXFCFG_FLOW_RFA_DEST_QNUM_MASK         (0x0000FFFFU)
#define UDMAP_RXFCFG_FLOW_RFA_DEST_QNUM_SHIFT        (0x00000000U)


/* RFB */

#define UDMAP_RXFCFG_FLOW_RFB_SRCTAG_HI_MASK         (0xFF000000U)
#define UDMAP_RXFCFG_FLOW_RFB_SRCTAG_HI_SHIFT        (0x00000018U)
#define UDMAP_RXFCFG_FLOW_RFB_SRCTAG_LO_MASK         (0x00FF0000U)
#define UDMAP_RXFCFG_FLOW_RFB_SRCTAG_LO_SHIFT        (0x00000010U)
#define UDMAP_RXFCFG_FLOW_RFB_DSTTAG_HI_MASK         (0x0000FF00U)
#define UDMAP_RXFCFG_FLOW_RFB_DSTTAG_HI_SHIFT        (0x00000008U)
#define UDMAP_RXFCFG_FLOW_RFB_DSTTAG_LO_MASK         (0x000000FFU)
#define UDMAP_RXFCFG_FLOW_RFB_DSTTAG_LO_SHIFT        (0x00000000U)


/* RFC */

#define UDMAP_RXFCFG_FLOW_RFC_SRCTAG_HI_SEL_MASK     (0x70000000U)
#define UDMAP_RXFCFG_FLOW_RFC_SRCTAG_HI_SEL_SHIFT    (0x0000001CU)
#define UDMAP_RXFCFG_FLOW_RFC_SRCTAG_LO_SEL_MASK     (0x07000000U)
#define UDMAP_RXFCFG_FLOW_RFC_SRCTAG_LO_SEL_SHIFT    (0x00000018U)
#define UDMAP_RXFCFG_FLOW_RFC_DSTTAG_HI_SEL_MASK     (0x00700000U)
#define UDMAP_RXFCFG_FLOW_RFC_DSTTAG_HI_SEL_SHIFT    (0x00000014U)
#define UDMAP_RXFCFG_FLOW_RFC_DSTTAG_LO_SEL_MASK     (0x00070000U)
#define UDMAP_RXFCFG_FLOW_RFC_DSTTAG_LO_SEL_SHIFT    (0x00000010U)
#define UDMAP_RXFCFG_FLOW_RFC_SIZE_THRESH_EN_MASK    (0x00000007U)
#define UDMAP_RXFCFG_FLOW_RFC_SIZE_THRESH_EN_SHIFT   (0x00000000U)


/* RFD */

#define UDMAP_RXFCFG_FLOW_RFD_FDQ0_SZ0_QNUM_MASK     (0xFFFF0000U)
#define UDMAP_RXFCFG_FLOW_RFD_FDQ0_SZ0_QNUM_SHIFT    (0x00000010U)
#define UDMAP_RXFCFG_FLOW_RFD_FDQ1_QNUM_MASK         (0x0000FFFFU)
#define UDMAP_RXFCFG_FLOW_RFD_FDQ1_QNUM_SHIFT        (0x00000000U)


/* RFE */

#define UDMAP_RXFCFG_FLOW_RFE_FDQ2_QNUM_MASK         (0xFFFF0000U)
#define UDMAP_RXFCFG_FLOW_RFE_FDQ2_QNUM_SHIFT        (0x00000010U)
#define UDMAP_RXFCFG_FLOW_RFE_FDQ3_QNUM_MASK         (0x0000FFFFU)
#define UDMAP_RXFCFG_FLOW_RFE_FDQ3_QNUM_SHIFT        (0x00000000U)


/* RFF */

#define UDMAP_RXFCFG_FLOW_RFF_SIZE_THRESH0_MASK      (0xFFFF0000U)
#define UDMAP_RXFCFG_FLOW_RFF_SIZE_THRESH0_SHIFT     (0x00000010U)
#define UDMAP_RXFCFG_FLOW_RFF_SIZE_THRESH1_MASK      (0x0000FFFFU)
#define UDMAP_RXFCFG_FLOW_RFF_SIZE_THRESH1_SHIFT     (0x00000000U)


/* RFG */

#define UDMAP_RXFCFG_FLOW_RFG_SIZE_THRESH2_MASK      (0xFFFF0000U)
#define UDMAP_RXFCFG_FLOW_RFG_SIZE_THRESH2_SHIFT     (0x00000010U)
#define UDMAP_RXFCFG_FLOW_RFG_FDQ0_SZ1_QNUM_MASK     (0x0000FFFFU)
#define UDMAP_RXFCFG_FLOW_RFG_FDQ0_SZ1_QNUM_SHIFT    (0x00000000U)


/* RFH */

#define UDMAP_RXFCFG_FLOW_RFH_FDQ0_SZ2_QNUM_MASK     (0xFFFF0000U)
#define UDMAP_RXFCFG_FLOW_RFH_FDQ0_SZ2_QNUM_SHIFT    (0x00000010U)
#define UDMAP_RXFCFG_FLOW_RFH_FDQ0_SZ3_QNUM_MASK     (0x0000FFFFU)
#define UDMAP_RXFCFG_FLOW_RFH_FDQ0_SZ3_QNUM_SHIFT    (0x00000000U)


/**
 * \brief UDMA-P Rx Channel Configuration Registers
 *
 * \param RCFG Rx Channel Configuration Register
 * \param RCQ Rx Channel Completion Queue Register
 * \param ROES[1] Rx Channel Output Event Steering Register 0
 * \param REOES[1] Rx Channel Error Output Event Steering Register 0
 * \param RPRI_CTRL Rx Channel Priority Control Register
 * \param THREAD Rx Channel Destination ThreadID Mapping Register
 * \param RST_SCHED Rx Channel Static Scheduler Config Register
 * \param RFLOW_RNG Rx Channel Flow Range Register
 */

struct udmap_rxccfg_regs {
	volatile u32	RCFG;
	volatile u8	Resv_20[16];
	volatile u32	RCQ;
	volatile u8	Resv_32[8];
	volatile u32	ROES;
	volatile u8	Resv_96[60];
	volatile u32	REOES;
	volatile u32	RPRI_CTRL;
	volatile u32	THREAD;
	volatile u8	Resv_128[20];
	volatile u32	RST_SCHED;
	volatile u8	Resv_240[108];
	volatile u32	RFLOW_RNG;
	volatile u8	Resv_256[12];
};

#define UDMAP_RXCCFG_CHAN_OFFSET                          (0x100U)

/*
 * Register Fields
 */

/* RCFG */

#define UDMAP_RXCCFG_CHAN_RCFG_PAUSE_ON_ERR_MASK         (0x80000000U)
#define UDMAP_RXCCFG_CHAN_RCFG_PAUSE_ON_ERR_SHIFT        (0x0000001FU)
#define UDMAP_RXCCFG_CHAN_RCFG_ATYPE_MASK                (0x03000000U)
#define UDMAP_RXCCFG_CHAN_RCFG_ATYPE_SHIFT               (0x00000018U)
#define UDMAP_RXCCFG_CHAN_RCFG_CHAN_TYPE_MASK            (0x000F0000U)
#define UDMAP_RXCCFG_CHAN_RCFG_CHAN_TYPE_SHIFT           (0x00000010U)
#define UDMAP_RXCCFG_CHAN_RCFG_IGNORE_SHORT_MASK         (0x00008000U)
#define UDMAP_RXCCFG_CHAN_RCFG_IGNORE_SHORT_SHIFT        (0x0000000FU)
#define UDMAP_RXCCFG_CHAN_RCFG_IGNORE_LONG_MASK          (0x00004000U)
#define UDMAP_RXCCFG_CHAN_RCFG_IGNORE_LONG_SHIFT         (0x0000000EU)
#define UDMAP_RXCCFG_CHAN_RCFG_FETCH_SIZE_MASK           (0x0000007FU)
#define UDMAP_RXCCFG_CHAN_RCFG_FETCH_SIZE_SHIFT          (0x00000000U)

/* RCQ */

#define UDMAP_RXCCFG_CHAN_RCQ_RXCQ_QNUM_MASK             (0x0000FFFFU)
#define UDMAP_RXCCFG_CHAN_RCQ_RXCQ_QNUM_SHIFT            (0x00000000U)

/* ROES */

#define UDMAP_RXCCFG_CHAN_ROES_EVT_NUM_MASK              (0x0000FFFFU)
#define UDMAP_RXCCFG_CHAN_ROES_EVT_NUM_SHIFT             (0x00000000U)

/* REOES */

#define UDMAP_RXCCFG_CHAN_REOES_EVT_NUM_MASK             (0x0000FFFFU)
#define UDMAP_RXCCFG_CHAN_REOES_EVT_NUM_SHIFT            (0x00000000U)

/* RPRI_CTRL */

#define UDMAP_RXCCFG_CHAN_RPRI_CTRL_PRIORITY_MASK        (0x70000000U)
#define UDMAP_RXCCFG_CHAN_RPRI_CTRL_PRIORITY_SHIFT       (0x0000001CU)
#define UDMAP_RXCCFG_CHAN_RPRI_CTRL_QOS_MASK             (0x00070000U)
#define UDMAP_RXCCFG_CHAN_RPRI_CTRL_QOS_SHIFT            (0x00000010U)
#define UDMAP_RXCCFG_CHAN_RPRI_CTRL_ORDERID_MASK         (0x0000000FU)
#define UDMAP_RXCCFG_CHAN_RPRI_CTRL_ORDERID_SHIFT        (0x00000000U)

/* THREAD */

#define UDMAP_RXCCFG_CHAN_THREAD_ID_MASK                 (0x0000FFFFU)
#define UDMAP_RXCCFG_CHAN_THREAD_ID_SHIFT                (0x00000000U)

/* RST_SCHED */

#define UDMAP_RXCCFG_CHAN_RST_SCHED_PRIORITY_MASK        (0x00000003U)
#define UDMAP_RXCCFG_CHAN_RST_SCHED_PRIORITY_SHIFT       (0x00000000U)

/* RFLOW_RNG */

#define UDMAP_RXCCFG_CHAN_RFLOW_RNG_FLOWID_CNT_MASK      (0x7FFF0000U)
#define UDMAP_RXCCFG_CHAN_RFLOW_RNG_FLOWID_CNT_SHIFT     (0x00000010U)
#define UDMAP_RXCCFG_CHAN_RFLOW_RNG_FLOWID_START_MASK    (0x00003FFFU)
#define UDMAP_RXCCFG_CHAN_RFLOW_RNG_FLOWID_START_SHIFT   (0x00000000U)

/*
 * \brief UDMA-P Rx Channel Realtime Registers
 *
 * \param CTL Rx Channel Realtime Control Register
 * \param SWTRIG Rx Channel Realtime Software Trigger Register
 * \param STDATA Rx Channel Realtime State Data Register
 * \param PEER0 Rx Channel Real-time Remote Peer Register 0
 * \param PEER1 Rx Channel Real-time Remote Peer Register 1
 * \param PEER2 Rx Channel Real-time Remote Peer Register 2
 * \param PEER3 Rx Channel Real-time Remote Peer Register 3
 * \param PEER4 Rx Channel Real-time Remote Peer Register 4
 * \param PEER5 Rx Channel Real-time Remote Peer Register 5
 * \param PEER6 Rx Channel Real-time Remote Peer Register 6
 * \param PEER7 Rx Channel Real-time Remote Peer Register 7
 * \param PEER8 Rx Channel Real-time Remote Peer Register 8
 * \param PEER9 Rx Channel Real-time Remote Peer Register 9
 * \param PEER10 Rx Channel Real-time Remote Peer Register 10
 * \param PEER11 Rx Channel Real-time Remote Peer Register 11
 * \param PEER12 Rx Channel Real-time Remote Peer Register 12
 * \param PEER13 Rx Channel Real-time Remote Peer Register 13
 * \param PEER14 Rx Channel Real-time Remote Peer Register 14
 * \param PEER15 Rx Channel Real-time Remote Peer Register 15
 * \param PCNT Rx Channel Real-time Packet Count Statistics Register
 * \param BCNT Rx Channel Real-time Completed Byte Count Statistics Register
 * \param SBCNT Rx Channel Real-time Started Byte Count Statistics Register
 */
struct udmap_rxcrt_regs {
	volatile u32	CTL;
	volatile u8	Resv_8[4];
	volatile u32	SWTRIG;
	volatile u8	Resv_128[116];
	volatile u32	STDATA[32];
	volatile u8	Resv_512[256];
	volatile u32	PEER0;
	volatile u32	PEER1;
	volatile u32	PEER2;
	volatile u32	PEER3;
	volatile u32	PEER4;
	volatile u32	PEER5;
	volatile u32	PEER6;
	volatile u32	PEER7;
	volatile u32	PEER8;
	volatile u32	PEER9;
	volatile u32	PEER10;
	volatile u32	PEER11;
	volatile u32	PEER12;
	volatile u32	PEER13;
	volatile u32	PEER14;
	volatile u32	PEER15;
	volatile u8	Resv_1024[448];
	volatile u32	PCNT;
	volatile u8	Resv_1032[4];
	volatile u32	BCNT;
	volatile u8	Resv_1040[4];
	volatile u32	SBCNT;
	volatile u8	Resv_4096[3052];
};

#define UDMAP_RXCRT_CHAN_OFFSET              (0x1000U)
/*
 * Register Fields
 */

/* CTL */

#define UDMAP_RXCRT_CHAN_CTL_EN_MASK         (0x80000000U)
#define UDMAP_RXCRT_CHAN_CTL_EN_SHIFT        (0x0000001FU)
#define UDMAP_RXCRT_CHAN_CTL_TDOWN_MASK      (0x40000000U)
#define UDMAP_RXCRT_CHAN_CTL_TDOWN_SHIFT     (0x0000001EU)
#define UDMAP_RXCRT_CHAN_CTL_PAUSE_MASK      (0x20000000U)
#define UDMAP_RXCRT_CHAN_CTL_PAUSE_SHIFT     (0x0000001DU)
#define UDMAP_RXCRT_CHAN_CTL_FTDOWN_MASK     (0x10000000U)
#define UDMAP_RXCRT_CHAN_CTL_FTDOWN_SHIFT    (0x0000001CU)
#define UDMAP_RXCRT_CHAN_CTL_ERROR_MASK      (0x00000001U)
#define UDMAP_RXCRT_CHAN_CTL_ERROR_SHIFT     (0x00000000U)

/**
 * \brief helper function to lookup a udmap instance and a Tx channel
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA tx channel number to be configured
 *
 * \param pudmap - Pointer to udmap structure array  (returned value)
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
static fterr udmap_lookup_tx_chan(u16 id, u16 chan, const struct udmap **pudmap)
{
	const struct udmap *u;
	fterr ret = EFTOK;

	if ((id >= soc_udmap_instances_num)) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		u = &(soc_udmap_instances[id]);
	}

	if ((ret == EFTOK) && (chan >= u->num_tx_chans)) {
		ret = -EINVAL;
	}
    if (ret== SUCCESS){
        *pudmap = u;
        ret=EFTOK;
    }
	if (ret == EFTOK) {
		*pudmap = u;
	}

	return ret;
}

/**
 * \brief helper function to lookup a udmap instance and a rx channel
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA rx channel number to be configured
 *
 * \param pudmap - Pointer to udmap structure array  (returned value)
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
static fterr udmap_lookup_rx_chan(u16 id, u16 chan, const struct udmap **pudmap)
{
	const struct udmap *u;
	fterr ret = EFTOK;

	if ((id >= soc_udmap_instances_num)) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		u = &(soc_udmap_instances[id]);
	}

	if ((ret == EFTOK) && (chan >= u->num_rx_chans)) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		*pudmap = u;
	}

	return ret;
}


/**
 * \brief helper function to lookup a udmap instance and a Rx flow
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA rx flow number to be configured
 *
 * \param pudmap - Pointer to udmap structure array  (returned value)
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
static fterr udmap_lookup_rx_flow(u16 id, u16 chan, const struct udmap **pudmap)
{
	const struct udmap *u;
	fterr ret = EFTOK;

	if ((id >= soc_udmap_instances_num)) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		u = &(soc_udmap_instances[id]);
	}

	if ((ret == EFTOK) && (chan >= u->num_rx_flows)) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		*pudmap = u;
	}

	return ret;
}

/**
 * \brief helper function to do the configuration of a udmap tx channel
 *        for packet based transfer type over PSIL
 *
 * \param base - Channel base address
 *
 * \param descr_size - Size of descriptors used for this channel in bytes
 *
 * \param qos - Channel quality-of-service params
 *
 * \param thread_id - Thread ID where the packet is sent to
 *
 * \param txcq_qnum - Completion queue number
 *
 * \param fifo_depth - FIFO depth in bytes for the channel
 *
 * The helper function does expect caller to do all required authentication
 * mapping from physical address to virtual address, etc.
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
static fterr udmap_txchan_setup_psil_pkt_mode_regs(local_phys_addr_t base,
						   u32 descr_size,
						   struct udmap_qos qos,
						   u16 thread_id, u16 txcq_qnum,
						   u16 fifo_depth)
{
	u32 reg;
	fterr ret = EFTOK;
	struct udmap_txccfg_regs *txccfg = (struct udmap_txccfg_regs *) base;

#ifndef CONFIG_SECURITY_DMA_UDMA
	(void) descr_size;
	(void) txcq_qnum;
#endif

	/* Do pause on error */
	reg = (1U << UDMAP_TXCCFG_CHAN_TCFG_PAUSE_ON_ERR_SHIFT) &
	      UDMAP_TXCCFG_CHAN_TCFG_PAUSE_ON_ERR_MASK;

	/* Packet oriented transfers using pass by reference rings */
	reg |= (2U << UDMAP_TXCCFG_CHAN_TCFG_CHAN_TYPE_SHIFT) &
	       UDMAP_TXCCFG_CHAN_TCFG_CHAN_TYPE_MASK;

#ifdef CONFIG_SECURITY_DMA_UDMA
	/* Descriptor size in 32-bit words */
	reg |= ((descr_size >> 2) << UDMAP_TXCCFG_CHAN_TCFG_FETCH_SIZE_SHIFT) &
	       UDMAP_TXCCFG_CHAN_TCFG_FETCH_SIZE_MASK;
#endif

	/* All other fields are zeros */
	ret = writel_verified(&txccfg->TCFG, reg);

#ifdef CONFIG_SECURITY_DMA_UDMA
	if (ret == EFTOK) {
		reg = 0U;
		ret = writel_verified(&txccfg->TCREDIT, reg);
	}

	if (ret == EFTOK) {
		reg = ((u32) txcq_qnum <<
		       UDMAP_TXCCFG_CHAN_TCQ_TXCQ_QNUM_SHIFT) &
		      UDMAP_TXCCFG_CHAN_TCQ_TXCQ_QNUM_MASK;
		ret = writel_verified(&txccfg->TCQ, reg);
	}

	if (ret == EFTOK) {
		reg = 0xFFFFU;
		ret = writel_verified(&txccfg->TOES, reg);
	}

	if (ret == EFTOK) {
		reg = 0xFFFFU;
		ret = writel_verified(&txccfg->TEOES, reg);
	}
#endif

	if (ret == EFTOK) {
		reg = ((u32) qos.priority <<
		       UDMAP_TXCCFG_CHAN_TPRI_CTRL_PRIORITY_SHIFT) &
		      UDMAP_TXCCFG_CHAN_TPRI_CTRL_PRIORITY_MASK;

#ifdef CONFIG_SECURITY_DMA_UDMA
		reg |= ((u32) qos.qos <<
			UDMAP_TXCCFG_CHAN_TPRI_CTRL_QOS_SHIFT) &
		       UDMAP_TXCCFG_CHAN_TPRI_CTRL_QOS_MASK;
#endif

		reg |= ((u32) qos.orderid <<
			UDMAP_TXCCFG_CHAN_TPRI_CTRL_ORDERID_SHIFT) &
		       UDMAP_TXCCFG_CHAN_TPRI_CTRL_ORDERID_MASK;
		ret = writel_verified(&txccfg->TPRI_CTRL, reg);
	}

	if (ret == EFTOK) {
		reg = ((u32) thread_id << UDMAP_TXCCFG_CHAN_THREAD_ID_SHIFT) &
		      UDMAP_TXCCFG_CHAN_THREAD_ID_MASK;
		ret = writel_verified(&txccfg->THREAD, reg);
	}

	if ((ret == EFTOK) && (fifo_depth != 0U)) {
		reg = ((u32) fifo_depth <<
		       UDMAP_TXCCFG_CHAN_TFIFO_DEPTH_FDEPTH_SHIFT) &
		      UDMAP_TXCCFG_CHAN_TFIFO_DEPTH_FDEPTH_MASK;
		ret = writel_verified(&txccfg->TFIFO_DEPTH, reg);
	}

	if (ret == EFTOK) {
		reg = ((u32) qos.sched_priority <<
		       UDMAP_TXCCFG_CHAN_TST_SCHED_PRIORITY_SHIFT) &
		      UDMAP_TXCCFG_CHAN_TST_SCHED_PRIORITY_MASK;
		ret = writel_verified(&txccfg->TST_SCHED, reg);
	}

	return ret;
}

/**
 * \brief helper function to do the configuration of a udmap rx channel
 *        for packet based transfer type over PSIL
 *
 * \param base - Channel base address
 *
 * \param descr_size - Size of descriptors used for this channel in bytes
 *
 * \param qos - Channel quality-of-service params
 *
 * \param thread_id - Thread ID using in PSIL messages
 *
 * \param rxcq_qnum - Completion queue number
 *
 * \param flowid_start - Starting index of rx flows associated with this rx
 *                     channel
 * \param flowid_count - Number of rx flows associated with this rx channel
 *
 * The helper function does expect caller to do all required authentication
 * mapping from physical address to virtual address, etc.
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
static fterr udmap_rxchan_setup_psil_pkt_mode_regs(local_phys_addr_t base,
						   u32 descr_size,
						   struct udmap_qos qos,
						   u16 thread_id, u16 rxcq_qnum,
						   u16 flowid_start,
						   u16 flowid_count)
{
	u32 reg;
	fterr ret = EFTOK;
	struct udmap_rxccfg_regs *rxccfg = (struct udmap_rxccfg_regs *) base;

#ifndef CONFIG_SECURITY_DMA_UDMA
	(void) descr_size;
	(void) rxcq_qnum;
	(void) flowid_start;
	(void) flowid_count;
#endif

	/* Do pause on error */
	reg = (1U << UDMAP_RXCCFG_CHAN_RCFG_PAUSE_ON_ERR_SHIFT) &
	      UDMAP_RXCCFG_CHAN_RCFG_PAUSE_ON_ERR_MASK;

	/* Packet oriented transfers using pass by reference rings */
	reg |= (2U << UDMAP_RXCCFG_CHAN_RCFG_CHAN_TYPE_SHIFT) &
	       UDMAP_RXCCFG_CHAN_RCFG_CHAN_TYPE_MASK;

#ifdef CONFIG_SECURITY_DMA_UDMA
	/* Descriptor size in 32-bit words */
	reg |= ((descr_size >> 2) << UDMAP_RXCCFG_CHAN_RCFG_FETCH_SIZE_SHIFT) &
	       UDMAP_RXCCFG_CHAN_RCFG_FETCH_SIZE_MASK;
#endif

	/* All other fields are zeros */
	ret = writel_verified(&rxccfg->RCFG, reg);

#ifdef CONFIG_SECURITY_DMA_UDMA
	if (ret == EFTOK) {
		reg = ((u32) rxcq_qnum <<
		       UDMAP_RXCCFG_CHAN_RCQ_RXCQ_QNUM_SHIFT) &
		      UDMAP_RXCCFG_CHAN_RCQ_RXCQ_QNUM_MASK;
		ret = writel_verified(&rxccfg->RCQ, reg);
	}

	if (ret == EFTOK) {
		reg = 0xFFFFU;
		ret = writel_verified(&rxccfg->ROES, reg);
	}

	if (ret == EFTOK) {
		reg = 0xFFFFU;
		ret = writel_verified(&rxccfg->REOES, reg);
	}
#endif

	if (ret == EFTOK) {
		reg = ((u32) qos.priority <<
		       UDMAP_RXCCFG_CHAN_RPRI_CTRL_PRIORITY_SHIFT) &
		      UDMAP_RXCCFG_CHAN_RPRI_CTRL_PRIORITY_MASK;

#ifdef CONFIG_SECURITY_DMA_UDMA
		reg |= ((u32) qos.qos <<
			UDMAP_RXCCFG_CHAN_RPRI_CTRL_QOS_SHIFT) &
		       UDMAP_RXCCFG_CHAN_RPRI_CTRL_QOS_MASK;
#endif

		reg |= ((u32) qos.orderid <<
			UDMAP_RXCCFG_CHAN_RPRI_CTRL_ORDERID_SHIFT) &
		       UDMAP_RXCCFG_CHAN_RPRI_CTRL_ORDERID_MASK;
		ret = writel_verified(&rxccfg->RPRI_CTRL, reg);
	}

	if (ret == EFTOK) {
		reg = ((u32) thread_id << UDMAP_RXCCFG_CHAN_THREAD_ID_SHIFT) &
		      UDMAP_RXCCFG_CHAN_THREAD_ID_MASK;
		ret = writel_verified(&rxccfg->THREAD, reg);
	}

	if (ret == EFTOK) {
		reg = ((u32) qos.sched_priority <<
		       UDMAP_RXCCFG_CHAN_RST_SCHED_PRIORITY_SHIFT) &
		      UDMAP_RXCCFG_CHAN_RST_SCHED_PRIORITY_MASK;
		ret = writel_verified(&rxccfg->RST_SCHED, reg);
	}

#ifdef CONFIG_SECURITY_DMA_UDMA
	if (ret == EFTOK) {
		reg = ((u32) flowid_start <<
		       UDMAP_RXCCFG_CHAN_RFLOW_RNG_FLOWID_START_SHIFT) &
		      UDMAP_RXCCFG_CHAN_RFLOW_RNG_FLOWID_START_MASK;

		reg |= ((u32) flowid_count <<
			UDMAP_RXCCFG_CHAN_RFLOW_RNG_FLOWID_CNT_SHIFT) &
		       UDMAP_RXCCFG_CHAN_RFLOW_RNG_FLOWID_CNT_MASK;

		ret = writel_verified(&rxccfg->RFLOW_RNG, reg);
	}
#endif

	return ret;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * UDMAP Visible APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
fterr udmap_rxchan_setup_psil_pkt_mode(u16 id, u16 chan, u32 descr_size,
				       struct udmap_qos qos,
				       u16 thread_id, u16 rxcq_qnum,
				       u16 flowid_start, u16 flowid_count)
{
	mapped_addr_t mapped_addr = 0;
	const struct udmap *u;
	soc_phys_addr_t base;
	fterr ret = EFTOK;

	ret = udmap_lookup_rx_chan(id, chan, &u);

	if (ret == EFTOK) {
		base = (UDMAP_RXCCFG_CHAN_OFFSET * chan) + u->cfg_rchan;
		mapped_addr = sec_dma_map_region(base, UDMAP_RXCCFG_CHAN_OFFSET);

		ret = udmap_rxchan_setup_psil_pkt_mode_regs(mapped_addr,
							    descr_size, qos,
							    thread_id,
							    rxcq_qnum,
							    flowid_start,
							    flowid_count);

		sec_dma_unmap_region(base, UDMAP_RXCCFG_CHAN_OFFSET);
	}

	return ret;
}

fterr udmap_rxrt_get_error(u16 id, u16 chan, u32 *err)
{
	mapped_addr_t mapped_addr = 0;
	const struct udmap *u;
	soc_phys_addr_t base;
	u32 reg;
	fterr ret = EFTOK;
	struct udmap_rxcrt_regs *rxcrt;

	ret = udmap_lookup_rx_chan(id, chan, &u);

	if (ret == EFTOK) {
		base = (UDMAP_RXCRT_CHAN_OFFSET * chan) + u->cfg_rchanrt;
		mapped_addr = sec_dma_map_region(base, UDMAP_RXCRT_CHAN_OFFSET);

		rxcrt = (struct udmap_rxcrt_regs *) mapped_addr;

		/* Read channel RT control register */
		reg = readl(&rxcrt->CTL);

		*err = (reg & UDMAP_RXCRT_CHAN_CTL_ERROR_MASK) >>
		       UDMAP_RXCRT_CHAN_CTL_ERROR_SHIFT;

		/* Clear the error */
		reg &= (~UDMAP_RXCRT_CHAN_CTL_ERROR_MASK);
		writel(&rxcrt->CTL, reg);

		sec_dma_unmap_region(base, UDMAP_RXCRT_CHAN_OFFSET);
	}

	return ret;
}

fterr udmap_rxrt_set_enable(u16 id, u16 chan, u8 enable)
{
	mapped_addr_t mapped_addr = 0;
	const struct udmap *u;
	soc_phys_addr_t base;
	u32 reg;
	fterr ret = EFTOK;
	struct udmap_rxcrt_regs *rxcrt;

	ret = udmap_lookup_rx_chan(id, chan, &u);

	if (ret == EFTOK) {
		base = (UDMAP_RXCRT_CHAN_OFFSET * chan) + u->cfg_rchanrt;
		mapped_addr = sec_dma_map_region(base, UDMAP_RXCRT_CHAN_OFFSET);

		rxcrt = (struct udmap_rxcrt_regs *) mapped_addr;

		/* Enable channel */
		reg = ((u32) enable << UDMAP_RXCRT_CHAN_CTL_EN_SHIFT) &
		      UDMAP_RXCRT_CHAN_CTL_EN_MASK;

		writel(&rxcrt->CTL, reg);

		sec_dma_unmap_region(base, UDMAP_RXCRT_CHAN_OFFSET);
	}

	return ret;
}

fterr udmap_rxrt_teardown(u16 id, u16 chan, ftbool force)
{
	mapped_addr_t mapped_addr = 0;
	const struct udmap *u;
	soc_phys_addr_t base;
	u32 reg;
	fterr ret = EFTOK;
	struct udmap_rxcrt_regs *rxcrt;

	ret = udmap_lookup_rx_chan(id, chan, &u);

	if (ret == EFTOK) {
		base = (UDMAP_RXCRT_CHAN_OFFSET * chan) + u->cfg_rchanrt;
		mapped_addr = sec_dma_map_region(base, UDMAP_RXCRT_CHAN_OFFSET);

		rxcrt = (struct udmap_rxcrt_regs *) mapped_addr;

		reg = readl(&rxcrt->CTL);

		if (((reg & UDMAP_RXCRT_CHAN_CTL_EN_MASK) >>
		     UDMAP_RXCRT_CHAN_CTL_EN_SHIFT) != 0U) {
			/* Teardown channel */
			reg = (1U << UDMAP_RXCRT_CHAN_CTL_TDOWN_SHIFT) &
			      UDMAP_RXCRT_CHAN_CTL_TDOWN_MASK;

			if (ft_is_true(force)) {
				/* Force teardown channel */
				reg |= (1U <<
					UDMAP_RXCRT_CHAN_CTL_FTDOWN_SHIFT) &
				       UDMAP_RXCRT_CHAN_CTL_FTDOWN_MASK;
			}

			writel(&rxcrt->CTL, reg);

			/* Poll for teardown to complete */
			if (!reg_poll_timeout_us(&rxcrt->CTL,
						 UDMAP_RXCRT_CHAN_CTL_EN_MASK,
						 0U,
						 UDMAP_TDOWN_TIMEOUT_US)) {
				ret = -ETIMEDOUT;
			}
		}

		sec_dma_unmap_region(base, UDMAP_RXCRT_CHAN_OFFSET);
	}

	return ret;
}

fterr udmap_rxrt_get_enable(u16 id, u16 chan, u8 *enable)
{
	mapped_addr_t mapped_addr = 0;
	const struct udmap *u;
	soc_phys_addr_t base;
	u32 reg;
	fterr ret = EFTOK;
	struct udmap_rxcrt_regs *rxcrt;

	ret = udmap_lookup_rx_chan(id, chan, &u);

	if (ret == EFTOK) {
		base = (UDMAP_RXCRT_CHAN_OFFSET * chan) + u->cfg_rchanrt;
		mapped_addr = sec_dma_map_region(base, UDMAP_RXCRT_CHAN_OFFSET);

		rxcrt = (struct udmap_rxcrt_regs *) mapped_addr;

		reg = readl(&rxcrt->CTL);

		*enable = (u8) ((reg & UDMAP_RXCRT_CHAN_CTL_EN_MASK) >>
				UDMAP_RXCRT_CHAN_CTL_EN_SHIFT);

		sec_dma_unmap_region(base, UDMAP_RXCRT_CHAN_OFFSET);
	}

	return ret;
}

fterr udmap_txchan_setup_psil_pkt_mode(u16 id, u16 chan, u32 descr_size,
				       struct udmap_qos qos,
				       u16 thread_id, u16 txcq_qnum,
				       u16 fifo_depth)
{
	mapped_addr_t mapped_addr = 0;
	const struct udmap *u;
	soc_phys_addr_t base;
	fterr ret = EFTOK;

	ret = udmap_lookup_tx_chan(id, chan, &u);

	if (ret == EFTOK) {
		base = (UDMAP_TXCCFG_CHAN_OFFSET * chan) + u->cfg_tchan;
		mapped_addr = sec_dma_map_region(base, UDMAP_TXCCFG_CHAN_OFFSET);

		ret = udmap_txchan_setup_psil_pkt_mode_regs(mapped_addr,
							    descr_size, qos,
							    thread_id,
							    txcq_qnum,
							    fifo_depth);

		sec_dma_unmap_region(base, UDMAP_TXCCFG_CHAN_OFFSET);
	}

	return ret;
}

fterr udmap_txrt_set_enable(u16 id, u16 chan, u8 enable)
{
	mapped_addr_t mapped_addr = 0;
	const struct udmap *u;
	soc_phys_addr_t base;
	u32 reg;
	fterr ret = EFTOK;
	struct udmap_txcrt_regs *txcrt;

	ret = udmap_lookup_tx_chan(id, chan, &u);

	if (ret == EFTOK) {
		base = (UDMAP_TXCRT_CHAN_OFFSET * chan) + u->cfg_tchanrt;
		mapped_addr = sec_dma_map_region(base, UDMAP_TXCRT_CHAN_OFFSET);

		txcrt = (struct udmap_txcrt_regs *) mapped_addr;

		/* Enable channel */
		reg = ((u32) enable << UDMAP_TXCRT_CHAN_CTL_EN_SHIFT) &
		      UDMAP_TXCRT_CHAN_CTL_EN_MASK;

		writel(&txcrt->CTL, reg);

		sec_dma_unmap_region(base, UDMAP_TXCRT_CHAN_OFFSET);
	}

	return ret;
}

fterr udmap_txrt_get_error(u16 id, u16 chan, u32 *err)
{
	mapped_addr_t mapped_addr = 0;
	const struct udmap *u;
	soc_phys_addr_t base;
	u32 reg;
	fterr ret = EFTOK;
	struct udmap_txcrt_regs *txcrt;

	ret = udmap_lookup_tx_chan(id, chan, &u);

	if (ret == EFTOK) {
		base = (UDMAP_TXCRT_CHAN_OFFSET * chan) + u->cfg_tchanrt;
		mapped_addr = sec_dma_map_region(base, UDMAP_TXCRT_CHAN_OFFSET);

		txcrt = (struct udmap_txcrt_regs *) mapped_addr;

		/* Read channel RT control register */
		reg = readl(&txcrt->CTL);

		*err = (reg & UDMAP_TXCRT_CHAN_CTL_ERROR_MASK) >>
		       UDMAP_TXCRT_CHAN_CTL_ERROR_SHIFT;

		/* Clear the error */
		reg &= (~UDMAP_TXCRT_CHAN_CTL_ERROR_MASK);
		writel(&txcrt->CTL, reg);

		sec_dma_unmap_region(base, UDMAP_TXCRT_CHAN_OFFSET);
	}

	return ret;
}

fterr udmap_txrt_teardown(u16 id, u16 chan, ftbool force)
{
	mapped_addr_t mapped_addr = 0;
	const struct udmap *u;
	soc_phys_addr_t base;
	u32 reg;
	fterr ret = EFTOK;
	struct udmap_txcrt_regs *txcrt;

	ret = udmap_lookup_tx_chan(id, chan, &u);

	if (ret == EFTOK) {
		base = (UDMAP_TXCRT_CHAN_OFFSET * chan) + u->cfg_tchanrt;
		mapped_addr = sec_dma_map_region(base, UDMAP_TXCRT_CHAN_OFFSET);

		txcrt = (struct udmap_txcrt_regs *) mapped_addr;

		reg = readl(&txcrt->CTL);

		if (((reg & UDMAP_TXCRT_CHAN_CTL_EN_MASK) >>
		     UDMAP_TXCRT_CHAN_CTL_EN_SHIFT) != 0U) {
			/* Teardown channel */
			reg = (1U << UDMAP_TXCRT_CHAN_CTL_TDOWN_SHIFT) &
			      UDMAP_TXCRT_CHAN_CTL_TDOWN_MASK;

			if (ft_is_true(force)) {
				/* Force teardown channel */
				reg |= (1U <<
					UDMAP_TXCRT_CHAN_CTL_FTDOWN_SHIFT) &
				       UDMAP_TXCRT_CHAN_CTL_FTDOWN_MASK;
			}

			writel(&txcrt->CTL, reg);

			/* Poll for teardown to complete */
			if (!reg_poll_timeout_us(&txcrt->CTL,
						 UDMAP_TXCRT_CHAN_CTL_EN_MASK,
						 0U,
						 UDMAP_TDOWN_TIMEOUT_US)) {
				ret = -ETIMEDOUT;
			}
		}

		sec_dma_unmap_region(base, UDMAP_TXCRT_CHAN_OFFSET);
	}

	return ret;
}

fterr udmap_txrt_get_enable(u16 id, u16 chan, u8 *enable)
{
	mapped_addr_t mapped_addr = 0;
	const struct udmap *u;
	soc_phys_addr_t base;
	u32 reg;
	fterr ret = EFTOK;
	struct udmap_txcrt_regs *txcrt;

	ret = udmap_lookup_tx_chan(id, chan, &u);

	if (ret == EFTOK) {
		base = (UDMAP_TXCRT_CHAN_OFFSET * chan) + u->cfg_tchanrt;
		mapped_addr = sec_dma_map_region(base, UDMAP_TXCRT_CHAN_OFFSET);

		txcrt = (struct udmap_txcrt_regs *) mapped_addr;

		reg = readl(&txcrt->CTL);

		*enable = (u8) ((reg & UDMAP_TXCRT_CHAN_CTL_EN_MASK) >>
				UDMAP_TXCRT_CHAN_CTL_EN_SHIFT);

		sec_dma_unmap_region(base, UDMAP_TXCRT_CHAN_OFFSET);
	}

	return ret;
}

fterr udmap_rxflow_setup_simple(u16 id, u16 chan, u16 free_qnum, u16 dest_qnum,
				u8 einfo_present, u8 psinfo_present)
{
	mapped_addr_t mapped_addr = 0;
	const struct udmap *u;
	soc_phys_addr_t base;
	u32 reg;
	fterr ret = EFTOK;
	struct udmap_rxfcfg_regs *rxfcfg;

#ifndef CONFIG_SECURITY_DMA_UDMA
	(void) free_qnum;
	(void) dest_qnum;
#endif

	ret = udmap_lookup_rx_flow(id, chan, &u);

	if (ret == EFTOK) {
		base = (UDMAP_RXFCFG_FLOW_OFFSET * chan) + u->cfg_rflow;
		mapped_addr = sec_dma_map_region(base, UDMAP_RXFCFG_FLOW_OFFSET);

		rxfcfg = (struct udmap_rxfcfg_regs *) mapped_addr;

		reg = ((u32) einfo_present << UDMAP_RXFCFG_FLOW_RFA_EINFO_SHIFT)
		      & UDMAP_RXFCFG_FLOW_RFA_EINFO_MASK;

		reg |= ((u32) psinfo_present <<
			UDMAP_RXFCFG_FLOW_RFA_PSINFO_SHIFT) &
		       UDMAP_RXFCFG_FLOW_RFA_PSINFO_MASK;

#ifdef CONFIG_SECURITY_DMA_UDMA
		reg |= ((u32) dest_qnum <<
			UDMAP_RXFCFG_FLOW_RFA_DEST_QNUM_SHIFT) &
		       UDMAP_RXFCFG_FLOW_RFA_DEST_QNUM_MASK;
#endif

		/* all other fields are zeros */
		ret = writel_verified(&rxfcfg->RFA, reg);

#ifdef CONFIG_SECURITY_DMA_UDMA
		if (ret == EFTOK) {
			reg = 0U;
			ret = writel_verified(&rxfcfg->RFB, reg);
		}

		if (ret == EFTOK) {
			reg = 0U;
			ret = writel_verified(&rxfcfg->RFC, reg);
		}

		if (ret == EFTOK) {
			reg = ((u32) free_qnum <<
			       UDMAP_RXFCFG_FLOW_RFD_FDQ0_SZ0_QNUM_SHIFT) &
			      UDMAP_RXFCFG_FLOW_RFD_FDQ0_SZ0_QNUM_MASK;
			ret = writel_verified(&rxfcfg->RFD, reg);
		}

		if (ret == EFTOK) {
			reg = 0U;
			ret = writel_verified(&rxfcfg->RFE, reg);
		}

		if (ret == EFTOK) {
			reg = 0U;
			ret = writel_verified(&rxfcfg->RFF, reg);
		}

		if (ret == EFTOK) {
			reg = 0U;
			ret = writel_verified(&rxfcfg->RFG, reg);
		}

		if (ret == EFTOK) {
			reg = 0U;
			ret = writel_verified(&rxfcfg->RFH, reg);
		}
#endif

		sec_dma_unmap_region(base, UDMAP_RXFCFG_FLOW_OFFSET);
	}

	return ret;
}
