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
 * \file vDLT_HSM.h
 *
 * \brief
 * Visteon DLT Logger for HSM Notification DLTExt
 *
 ******************************************************************************/
#ifndef VDLT_HSM_H
#define VDLT_HSM_H
#include "Std_Types.h"

#define DLTBUFFERONENO       (0x5u)
#define DLTBUFFERTWONO       (0x6u)

FUNC(void, CRY_CODE)DltExt_Hsm_IpcAckEvent(uint32 status);

#endif /*VDLT_HSM_H*/