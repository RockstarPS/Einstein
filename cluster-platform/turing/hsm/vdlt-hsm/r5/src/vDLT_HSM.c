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
#include "vDLT_HSM.h"
#include "vHsmCryptoManager.h"
#include "vHsmIpcHostManager.h"
#include "vHsmCryptoMessageM7.h"

#define UNUSED_PARAM (void)
#define DLTBUFFERACK (0x01u)

static uint8  buffertoRead_U8 = 0u;
extern void Hsm_DltExt_IpcLogEvent(uint32 data);

static void vDLTHSM_ClearBuffer(uint8 status);

FUNC(void, CRY_CODE) vDLTHSM_NotifyDltExt(uint8 *commanddata_addr, uint16 payload_size)
{
    UNUSED_PARAM payload_size;
    uint8 buffer = *commanddata_addr;
    uint32 DltExtstatus = 0x01u; /*DLT Buffer FULL*/
    if((buffer == DLTBUFFERONENO) || (buffer == DLTBUFFERTWONO))
    {
        buffertoRead_U8 = buffer;
        if(buffer == DLTBUFFERONENO)
        {
            DltExtstatus |= (0x01UL << 16UL); /*Buffer one full*/
        }
        else
        {
            DltExtstatus |= (0x02UL << 16UL); /*Buffer Two full*/
        }
        /*Call DLT Ext function to notify*/
        Hsm_DltExt_IpcLogEvent(DltExtstatus);
    }
}

FUNC(void, CRY_CODE)DltExt_Hsm_IpcAckEvent(uint32 status)
{
    uint8 ack = 0u;
    if((status & DLTBUFFERACK) == DLTBUFFERACK)
    {
        ack = (uint8)((status >> 16U) & 0xFFU);
        vDLTHSM_ClearBuffer(ack);
    }
}

static void vDLTHSM_ClearBuffer(uint8 status)
{
    ts_vHsm_Commanddata vDLTHSMPackedData_S;
    uint8 l_data_U8A[2] = {0};
    if((status == 0x1U) || (status == 0x2U))
    {
        /*Call DLT Ext function to notify HSM core*/
        l_data_U8A[0] = buffertoRead_U8;
        vDLTHSMPackedData_S.jobId_E = SID_5_DLTBUFFCLR_CB;
        vDLTHSMPackedData_S.priority_U8 = e_priority0;
        vDLTHSMPackedData_S.payLoadPtr_U8P = &l_data_U8A[0];
        vDLTHSMPackedData_S.payLoadSize = 1U; /* no payload */
        if(E_OK == vHsmCrypto_Command_SendData(vDLTHSMPackedData_S))
        {
            /*IPC sent succefully*/
        }
        else
        {
            /*IPC Failed*/
        }
    }
}


/*EOF*/
