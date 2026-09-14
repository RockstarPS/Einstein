/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2026] Visteon Corporation
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
 * \file vDLTHSM_Cfg.h
 *
 * \brief
 * Visteon DLT Logger COnfiguration for HSM
 *
 ******************************************************************************/
#ifndef VDLTHSM_CFG_H
#define VDLTHSM_CFG_H

/******************************************************************************
 *  Configurations
 *****************************************************************************/
#define ADDONDATALENGTH  (8u)
#define HSMECUID         (0x4D5348u) /*'HSM'*/

#define DLT_HTYP_UEH     (1u << 0)   /*Extended Header*/
#define DLT_HTYP_MSBF    (1u << 1)   /*MSB first*/
#define DLT_HTYP_WEID    (1u << 2)   /*Session Id Not used*/
#define DLT_HTYP_WSID    (0u << 3)   /*Session Id Not used*/
#define DLT_HTYP_WTMS    (1u << 4)   /*Timestamp*/
#define DLT_HTYP_VERS    (1u << 5)   /*DLT Version*/

#define DLT_HTYP ((uint8)((uint8)(DLT_HTYP_UEH) | (uint8)(DLT_HTYP_MSBF) | (uint8)(DLT_HTYP_WEID) | (uint8)(DLT_HTYP_WSID) | (uint8)(DLT_HTYP_WTMS) | (uint8)(DLT_HTYP_VERS)))

#define DLT_LOG_FATAL     (0x1u)
#define DLT_LOG_DLT_ERROR (0x2u)
#define DLT_LOG_WARN      (0x3u)
#define DLT_LOGINFO       (0x4u)
#define DLT_LOG_DEBUG     (0x5u)
#define DLT_LOG_VERBOSE   (0x6u)

#define DLT_MSIN_VERB    (0x01u)   /*Verbose*/
#define DLT_MSIN_TYPE    (0x00u)   /*Message Type DLT_TYPE_LOG*/
#define DLT_MSIN_TYIN(x) ((uint8)(((uint8)(x)) << 4u))

#define DLT_MSGTYPE(x)   ((uint8)((DLT_MSIN_VERB) | (DLT_MSIN_TYPE) | (DLT_MSIN_TYIN(x))))

#define DLT_NOAR         (1u)
#define DLT_TYPEINFO     (0x0408u)    /* Raw Data of 8 Bytes*/

/* DLT Frame Physical Cfgs*/
#define DLT_FRAME_LEN    (34u)

#define DLTBUFFERONE     (0xC2387000u) /*DDR address RAT mapped*/
#define DLTBUFFERTWO     (0xC2387800u)

#define DLTBUFFERONENO   (0x5u)
#define DLTBUFFERTWONO   (0x6u)
#define DLTBUFFERINVALID (0xFFu)

#define MAXDLTMSGSTORE       (20u)
#define MAXDLTSIZEPERBUFF    (MAXDLTMSGSTORE*DLT_FRAME_LEN)
#define MAXDLTMSGCOUNTER     (0xFFu)

/*GTC TIMER*/
#define WKUP_GTC0_GTC_CFG1_BASE (0x60A90000U)
#define GTC_CFG1_CNTCV_LO       (0x00000008U)

#define DLT_GTC_READ (HW_RD_REG32(WKUP_GTC0_GTC_CFG1_BASE + GTC_CFG1_CNTCV_LO))

#endif /*VDLTHSM_CFG_H*/
