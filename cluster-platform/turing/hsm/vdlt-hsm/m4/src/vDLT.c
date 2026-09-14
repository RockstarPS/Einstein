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
 * \file vDLT.c
 *
 * \brief
 * Visteon DLT Logger for HSM
 *
 ******************************************************************************/
#include "vDLT.h"
#include "strings.h"
#include "vHsmCryptoManager.h"

#ifdef VDLT_ENABLE   /*Enable DLT*/

#define UNUSED_PARAM (void)

/******************************************************************************
 *  INTERNAL TYPES
 *****************************************************************************/
/*Internal State Machine*/
typedef enum
{
    e_DLT_Uninit = 0,
    e_DLT_Idle = 1,
    e_DLT_Buffull = 2,
    e_DLT_WaitAck = 3,
}te_DLT_State_t;

/*Internal Struct to maintain two Buffers*/
typedef struct 
{
    ts_DLT_Frame_t * BuffAdd_ps;
    uint8 BufferIndex;
    boolean BufferFull;
}ts_DLT_Buffer_t;

/******************************************************************************
 *  LOCAL VARIABLES
 *****************************************************************************/
static uint8 l_MessageCounter_U8 = 0u;
static te_DLT_State_t l_DLTstate_e = e_DLT_Uninit;
static ts_DLT_Buffer_t Dlt_Buffers_st[2] = {{(ts_DLT_Frame_t*)DLTBUFFERONE, 0u, FALSE},{(ts_DLT_Frame_t*)DLTBUFFERTWO, 0u, FALSE}};
static uint8 l_ActivaBuffer_U8;
static uint8 l_NotifyBuffer_U8 = DLTBUFFERINVALID;

/******************************************************************************
 *  LOCAL FUNCTIONS
 *****************************************************************************/
static void vDLT_BufferFullNotify(uint8 bufferID);
static void vDLT_ClearBuffer(uint8 bufferID);

/******************************************************************************
 *  PUBLIC FUNCTIONS
 *****************************************************************************/

/**
 * @brief vDLT_Init
 * Initializes the HSM DLT 
 * 
 */
FUNC(void,DLT_CODE) vDLT_Init(void)
{
    l_DLTstate_e = e_DLT_Idle;
    l_MessageCounter_U8 = 0u;
    l_ActivaBuffer_U8 = 0u; /*First Buffer by default*/
}

/**
 * @brief Notifies when any of the buffer is full
 * 
 * @param[in] bufferID  ID of buffer which is full 
 */
static void vDLT_BufferFullNotify(uint8 bufferID)
{
    l_DLTstate_e = e_DLT_Buffull;
    l_NotifyBuffer_U8 = DLTBUFFERONENO;
    if(bufferID == 1u)
    {
        l_NotifyBuffer_U8 = DLTBUFFERTWONO;
    }
}

/**
 * @brief Clear the particular Buffer
 * 
 * @param[in] bufferID ID of buffer to be cleared
 */
static void vDLT_ClearBuffer(uint8 bufferID)
{
    if((bufferID == 0x1u) || (bufferID == 0x0u))
    {
        ts_DLT_Buffer_t * l_Buffer_ps = &Dlt_Buffers_st[bufferID];
        l_Buffer_ps->BufferFull = FALSE;
        l_Buffer_ps->BufferIndex = 0u;
        (void)memset((void*)&l_Buffer_ps->BuffAdd_ps[0],0,(size_t)MAXDLTSIZEPERBUFF);
    }
}

/**
 * @brief DLT log function
 * 
 * @param[in] typeInfo_pU8 typeinfo of the message
 * @param[in] appId        ApplicationID of the message
 * @param[in] ContextId    Context ID of the message
 * @param[in] data_pU8     Data to be logges
 */
FUNC(void,DLT_CODE) vDLT_LogMsg(uint8 typeInfo_pU8, uint32 appId, uint32 ContextId,const uint8 * data_pU8)
{
    Std_ReturnType l_RetVal_E = E_OK;
    ts_DLT_Buffer_t * l_Buffer_ps = &Dlt_Buffers_st[l_ActivaBuffer_U8];
    if((data_pU8 != NULL) && (l_DLTstate_e != e_DLT_Uninit))
    {
        if(l_Buffer_ps->BufferIndex > (MAXDLTMSGSTORE-1u))
        {
            l_Buffer_ps->BufferFull = TRUE;
            vDLT_BufferFullNotify(l_ActivaBuffer_U8);
            l_ActivaBuffer_U8 ^= 1u;
            l_Buffer_ps = &Dlt_Buffers_st[l_ActivaBuffer_U8];
            if(l_Buffer_ps->BufferFull == TRUE)
            {
                l_RetVal_E = E_NOT_OK; /* Both Buffer Full Discard Logging */
            }
        }
        if(E_OK == l_RetVal_E)
        {   /*Header packing*/
            l_Buffer_ps->BuffAdd_ps[l_Buffer_ps->BufferIndex].StdHeader.HTYP_U8 = DLT_HTYP;
            if(l_MessageCounter_U8 < MAXDLTMSGCOUNTER)
            {
                l_Buffer_ps->BuffAdd_ps[l_Buffer_ps->BufferIndex].StdHeader.MsgCounter_U8 = (l_MessageCounter_U8+1U);
            }
            l_Buffer_ps->BuffAdd_ps[l_Buffer_ps->BufferIndex].StdHeader.Length_U16 = DLT_FRAME_LEN;
            l_Buffer_ps->BuffAdd_ps[l_Buffer_ps->BufferIndex].StdHeader.EcuId_U32 = HSMECUID;
            l_Buffer_ps->BuffAdd_ps[l_Buffer_ps->BufferIndex].StdHeader.TimeStamp_U32 = DLT_GTC_READ;
            /*Ext Header packing*/
            l_Buffer_ps->BuffAdd_ps[l_Buffer_ps->BufferIndex].ExtHeader.Arguments_U8 = DLT_NOAR;
            l_Buffer_ps->BuffAdd_ps[l_Buffer_ps->BufferIndex].ExtHeader.MsgType_U8 = DLT_MSGTYPE(typeInfo_pU8);
            l_Buffer_ps->BuffAdd_ps[l_Buffer_ps->BufferIndex].ExtHeader.AppId_U32 = appId;
            l_Buffer_ps->BuffAdd_ps[l_Buffer_ps->BufferIndex].ExtHeader.ContextId_U32 = ContextId;
            /*Payload Header packing*/
            l_Buffer_ps->BuffAdd_ps[l_Buffer_ps->BufferIndex].Payload.TypeInfo_U32 = DLT_TYPEINFO;
            (void)memcpy(&l_Buffer_ps->BuffAdd_ps[l_Buffer_ps->BufferIndex].Payload.data_U8A[0],data_pU8,ADDONDATALENGTH);
            if (l_Buffer_ps->BufferIndex < MAXDLTMSGSTORE)
            {
                l_Buffer_ps->BufferIndex += 1u; /*Increment buffer index*/
            }
            else
            {
                /* buffer overflow */
                l_RetVal_E = E_NOT_OK;
            } 
        }
    }
    UNUSED_PARAM l_RetVal_E;
}

/**
 * @brief De init DLT
 * 
 */
FUNC(void,DLT_CODE) vDLT_deInit(void)
{
    l_DLTstate_e = e_DLT_Uninit;
}

/**
 * @brief helper Function to asynchnously Notify the DLTExt and to clear the buffer 
 *        upon acknowledgement 
 * 
 */
FUNC(void,DLT_CODE) vDLT_mainFunction(void)
{
    uint8 l_Data_U8A[2] = {0};
    ts_vHsm_Commanddata l_commanddatasend = {0};
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    switch (l_DLTstate_e)
    {
    case e_DLT_Buffull:
            l_Data_U8A[0] = l_NotifyBuffer_U8;
            l_commanddatasend.jobId_E = SID_6_DLTBUFFFULL_FN;
            l_commanddatasend.priority_U8 = e_priorityunused;
            l_commanddatasend.payLoadPtr_U8P = &l_Data_U8A[0];
            l_commanddatasend.payLoadSize = (uint16)1;
            l_RetVal_E = vHsmCrypto_Command_SendData(l_commanddatasend);
            if(E_NOT_OK == l_RetVal_E)
            {
                /* Message not sent through IPC */

            }
            else
            {
                /* Data sent through IPC */
            }
            l_DLTstate_e = e_DLT_WaitAck;
        break;
    case e_DLT_WaitAck:
        /* Wait here */
        break;
    default:
        break;
    }
}
 
/**
 * @brief Acknowledgement from DLTExt and clears the buffer
 * 
 * @param[in] commanddata_addr  buffer ID transmitted as pointer
 * @param[in] payload_size      size of the payload
 * 
 */
FUNC(void, CRY_CODE) vDLT_BufferClearNotify(uint8 *const commanddata_addr, uint16 payload_size)
{
    UNUSED_PARAM payload_size;
    uint8 status = *commanddata_addr;
    uint8 BufferId_U8 = 0u;
    if(status == DLTBUFFERTWONO)
    {
        BufferId_U8 = 1u;
    }
    vDLT_ClearBuffer(BufferId_U8);
    l_DLTstate_e = e_DLT_Idle;
}

#endif /*VDLT_ENABLE*/
/*EOF*/
