/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2024] Visteon Corporation
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
 * \file vHsmIpcHostManager.c
 *
 * \brief
 * IPC Host Manager for IPC communication between cores.
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 30/Jul/'24 | kjohn    | xxxxxx  | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "string.h"
#include "Std_Types.h"
#include "vHsmIpcHostManager.h"
#include "vHsmIpc.h"
/******************************************************************************
 *  MACROS
 *****************************************************************************/
#ifndef LOCAL
#define LOCAL static
#endif /* LOCAL */

#define IPC_MESSAGE_RECEIVED                     0xAA
/******************************************************************************
 * Static type declarations
 *****************************************************************************/
typedef FUNC (void, CRY_CODE) (*ipc_message_func_t)(uint8 buffer_id, uint8* buffer_add,uint16 payload_size);
/* State machine tracking for IPC states */
typedef enum
{
    e_init = 0xAA,
    e_busy = 0x1,
    e_ready = 0x2,
    e_idle = 0x3,
    e_wait = 0x4,
    e_stateunused = 0xF,
} te_ipcsyncstate;

typedef enum
{
    e_m7 = 1,
    e_m0p = 2,
    e_coreidunused = 0xFF,
}te_ipccoreid;

#define ENTRY(a,b)                                     b,
ipc_message_func_t Ipc_FuncPtr_jumptable[IPC_UNUSED_MSGID] = {
        IPC_MESSAGE_TABLE
};
#undef ENTRY

typedef struct
{
    uint16 messageid;
    uint16 payloadsize;
    te_ipccoreid senderid;
    te_ipccoreid recvid;
    te_ipcsyncstate syncstate;
    uint8 resrv;
} ts_ipcdataheader;

typedef struct
{
    ts_ipcdataheader s_ipcdataheader;
    uint8 payloaddata[IPC_MAX_PAYLOAD_DATA_SIZE];
}ts_ipcdata;


LOCAL boolean l_IPCHostManagerInit_BOOL = FALSE;
LOCAL uint8 l_IPCHostBufferMessageRecv[IPC_MAX_NUMBER_OF_BUFFERS] = {0};
LOCAL FUNC (void, CRY_CODE) IpcHost_NotifyCallback(uint32 IpcBuffAddress);

/************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/
/**
 ******************************************************************************
 ** \fn vHsmIpc_HostManager_Init
 **
 ** IPC Host Manager initialization should be enabled at startup
 **
 ** This function returns None
 **
 ** \param [in] None
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsmIpc_HostManager_Init(void)
{
    ts_ipcdata *l_ipcdata_srambuff_ps = (ts_ipcdata *) NULL;
    uint8 l_ipcloop_U8 = 0;
    uint16 l_ipcloop_U16 = 0;

    /* Host Manager Initialization */
    if((uint8)IPC_HEADER_SIZE == (uint8)sizeof(ts_ipcdataheader))
    {
        /* Registering the notify callback function */
        (void)vHsmIpc_RegisterNotifyCallback(IpcHost_NotifyCallback);
        /* Initializing the status flag of SRAM buffers to init */
        for(l_ipcloop_U8 = 0; l_ipcloop_U8 < IPC_NUMBER_OF_BUFFERS; l_ipcloop_U8++)
        {
            l_ipcdata_srambuff_ps = (ts_ipcdata *) (IPC_SRAMADDR_M7_M0P_START + (l_ipcloop_U8 * IPC_BUFFER_SIZE_BYTES));
            if(l_ipcdata_srambuff_ps != NULL)
            {
                /* Initializing the SRAM data buffers */
                l_ipcdata_srambuff_ps->s_ipcdataheader.syncstate = e_init;
                l_ipcdata_srambuff_ps->s_ipcdataheader.messageid = 0xFF;
                l_ipcdata_srambuff_ps->s_ipcdataheader.payloadsize = 0;
                l_ipcdata_srambuff_ps->s_ipcdataheader.recvid = e_coreidunused;
                l_ipcdata_srambuff_ps->s_ipcdataheader.senderid = e_coreidunused;
                l_ipcdata_srambuff_ps->s_ipcdataheader.resrv = 0;
                for(l_ipcloop_U16 = 0; l_ipcloop_U16 < IPC_MAX_PAYLOAD_DATA_SIZE; l_ipcloop_U16++)
                {
                    l_ipcdata_srambuff_ps->payloaddata[l_ipcloop_U16] = 0;
                }
            }
            else
            {
                l_IPCHostManagerInit_BOOL = FALSE;
                break;
            }
            l_IPCHostManagerInit_BOOL = TRUE;
        }
    }
    else
    {
        l_IPCHostManagerInit_BOOL = FALSE;
    }
}

/**
 ********************************************************************************
 ** \fn vHsmIpc_HostManager_PeriodicCheck
 **
 ** IPC Host Manager periodic check called every 4ms for periodically processing the IPC
 ** messages
 **
 ** This function returns None
 **
 ** \param [in] None
 *********************************************************************************/
FUNC (void, CRY_CODE) vHsmIpc_HostManager_PeriodicCheck(void)
{
    uint8 l_ipcloop_U8 = 0;
    uint32 l_ipcsrambuffaddrecv_U32 = 0;
    ts_ipcdata *l_ipcdata_srambuff_ps = (ts_ipcdata *) NULL;
    te_ipcmessageid l_message_id_E = IPC_UNUSED_MSGID;
    uint8 l_bufferid_U8 = 0;
    uint8 *l_buffer_add_P = 0;
    uint16 l_payloadsize_U16 = 0;
    Std_ReturnType l_ipc_acquire_Ret_Val_E  = E_NOT_OK;
    if(l_IPCHostManagerInit_BOOL)
    {
        vHsmIpc_MsgPolling();
        /* Periodic check of received messages */
        for(l_ipcloop_U8 = 0; l_ipcloop_U8 < IPC_NUMBER_OF_BUFFERS; l_ipcloop_U8++)
        {
            if(IPC_MESSAGE_RECEIVED == l_IPCHostBufferMessageRecv[l_ipcloop_U8])
            {
                /* Address pointing to starting buffer of M7 to M0P */
                l_ipcsrambuffaddrecv_U32 = (uint32) (IPC_SRAMADDR_M0P_M7_START + (l_ipcloop_U8 * IPC_BUFFER_SIZE_BYTES));
                l_ipcdata_srambuff_ps = (ts_ipcdata *) (l_ipcsrambuffaddrecv_U32);
                if((e_m0p == l_ipcdata_srambuff_ps->s_ipcdataheader.senderid)
                    && (e_m7 == l_ipcdata_srambuff_ps->s_ipcdataheader.recvid)
                    && (l_ipcdata_srambuff_ps->s_ipcdataheader.payloadsize < (IPC_MAX_PAYLOAD_DATA_SIZE + 1)))
                {
                    l_message_id_E = (te_ipcmessageid)l_ipcdata_srambuff_ps->s_ipcdataheader.messageid;
                    if( l_message_id_E < IPC_UNUSED_MSGID)
                    {
                        l_ipcdata_srambuff_ps->s_ipcdataheader.syncstate = e_busy;
                        l_bufferid_U8 = l_ipcloop_U8;
                        l_buffer_add_P = &(l_ipcdata_srambuff_ps->payloaddata[0]);
                        l_payloadsize_U16 = l_ipcdata_srambuff_ps->s_ipcdataheader.payloadsize - (uint16)sizeof(ts_ipcdataheader);
                        (void) Ipc_FuncPtr_jumptable[l_message_id_E](l_bufferid_U8,l_buffer_add_P,l_payloadsize_U16);
                        /* Release that particular message recv indication */
                        l_IPCHostBufferMessageRecv[l_ipcloop_U8] = 0;
                    }
                    else
                    {
                        /* Do Nothing */
                        /* Wrong message id sent*/
                    }
                }
                else
                {
                    /* Do Nothing */
                    /* Wrong payload size, sender/receiver id */
                }
            }
            else
            {
                /* Do Nothing */
            }
        }

        /* Periodic check of messages to be sent */
        for(l_ipcloop_U8 = 0; l_ipcloop_U8 < IPC_NUMBER_OF_BUFFERS; l_ipcloop_U8++)
        {
            /* Address pointing to starting buffer of M7 to M0P */
            l_ipcsrambuffaddrecv_U32 = (uint32) (IPC_SRAMADDR_M7_M0P_START + (l_ipcloop_U8 * IPC_BUFFER_SIZE_BYTES));
            l_ipcdata_srambuff_ps = (ts_ipcdata *) (l_ipcsrambuffaddrecv_U32);
            if(e_wait == l_ipcdata_srambuff_ps->s_ipcdataheader.syncstate)
            {
                l_ipcdata_srambuff_ps->s_ipcdataheader.syncstate = e_ready;
                l_ipc_acquire_Ret_Val_E = vHsmIpc_AcquireLockUpdateData((uint8 *)l_ipcsrambuffaddrecv_U32);
                if(E_NOT_OK == l_ipc_acquire_Ret_Val_E)
                {
                    /* IPC channel not accquired */
                    l_ipcdata_srambuff_ps->s_ipcdataheader.syncstate = e_wait;
                }
                else
                {
                    /* Do Nothing */
                    /* IPC transmission successful */
                }
            }
            else
            {
                /* Do Nothing */
                /* Wrong payload size, sender/receiver id */
            }
        }
    }
    else
    {
        /* IPC Host Manager Initialization not done */
    }

}

/**
 ******************************************************************************
 ** \fn IpcHostM0pNotifyCallback
 **
 ** IPC Host Manager callback Notification when the IPC message is recieved
 **
 ** This function returns None
 ** This function is being called from the interrupt context
 **
 ** \param [in] None
 *****************************************************************************/
LOCAL FUNC (void, CRY_CODE) IpcHost_NotifyCallback(uint32 IpcBuffAddress)
{
   uint8 l_ipcloop_U8 = 0;
   uint32 l_ipcsrambuffadd_U32 = 0;
   ts_ipcdata *l_ipcdata_srambuff_ps = (ts_ipcdata *) NULL;

   if(l_IPCHostManagerInit_BOOL)
   {
       if((IpcBuffAddress < IPC_SRAMADDR_M0P_M7_END) && (IpcBuffAddress > (IPC_SRAMADDR_M0P_M7_START - 1)))
       {
           /* SRAM buffer address is in the limit */
           for(l_ipcloop_U8 = 0; l_ipcloop_U8 < IPC_NUMBER_OF_BUFFERS; l_ipcloop_U8++)
           {
               l_ipcsrambuffadd_U32 = (uint32)(IPC_SRAMADDR_M0P_M7_START + (l_ipcloop_U8 * IPC_BUFFER_SIZE_BYTES));
               if(IpcBuffAddress == l_ipcsrambuffadd_U32)
               {
                   l_ipcdata_srambuff_ps = (ts_ipcdata *)(IpcBuffAddress);
                   if(e_ready == l_ipcdata_srambuff_ps->s_ipcdataheader.syncstate)
                   {
                       l_IPCHostBufferMessageRecv[l_ipcloop_U8] = (uint8) (IPC_MESSAGE_RECEIVED);
                       l_ipcdata_srambuff_ps->s_ipcdataheader.syncstate = e_busy;
                   }
                   else
                   {
                       /* Discard the message */
                       /* Do Nothing */
                   }
                   break;
               }
               else
               {
                   /* Do Nothing */
               }
           }
       }
       else
       {
           /* Discard the message */
       }
   }
   else
   {
       /* Discard the message: Init Failed */
   }
}


/**
 ******************************************************************************
 ** \fn IpcHost_M0PMessageSend
 **
 ** IPC Host Manager API to send a message on IPC
 **
 ** This function returns Std_ReturnType
 ** This function is being called by the Application to register an IPC message
 **
 ** \param [in] None
 *****************************************************************************/
FUNC (Std_ReturnType, CRY_CODE) IpcHost_MessageSend(uint8 *Ipcdata, uint16 Ipcdatasize, uint16 MessageId)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint8 l_ipcloop_U8 = 0;
    uint32 l_ipcsrambuffadd_U32 = 0;
    ts_ipcdata *l_ipcdata_srambuff_ps = (ts_ipcdata *) NULL;

    if(l_IPCHostManagerInit_BOOL)
    {
        if(Ipcdata != NULL)
        {
            if(Ipcdatasize < (IPC_MAX_PAYLOAD_DATA_SIZE + 1))
            {
                if(MessageId < IPC_UNUSED_MSGID)
                {
                    /* SRAM buffer address to send data from M0P to M7 */
                    for(l_ipcloop_U8 = 0; l_ipcloop_U8 < IPC_NUMBER_OF_BUFFERS; l_ipcloop_U8++)
                    {
                        l_ipcsrambuffadd_U32 = (uint32)(IPC_SRAMADDR_M7_M0P_START + (l_ipcloop_U8 * IPC_BUFFER_SIZE_BYTES));
                        l_ipcdata_srambuff_ps = (ts_ipcdata *)(l_ipcsrambuffadd_U32);
                        if((e_init == l_ipcdata_srambuff_ps->s_ipcdataheader.syncstate)
                            || (e_idle == l_ipcdata_srambuff_ps->s_ipcdataheader.syncstate))
                        {
                            /* Empty Buffer Found */
                            l_ipcdata_srambuff_ps->s_ipcdataheader.syncstate = e_busy;
                            l_ipcdata_srambuff_ps->s_ipcdataheader.messageid = MessageId;
                            l_ipcdata_srambuff_ps->s_ipcdataheader.senderid = e_m7;
                            l_ipcdata_srambuff_ps->s_ipcdataheader.recvid = e_m0p;
                            l_ipcdata_srambuff_ps->s_ipcdataheader.payloadsize = Ipcdatasize + (uint16)sizeof(ts_ipcdataheader);
                            /* Copying data into SRAM */
                            memcpy((uint8 *)&(l_ipcdata_srambuff_ps->payloaddata[0]), Ipcdata, Ipcdatasize);
                            l_ipcdata_srambuff_ps->s_ipcdataheader.syncstate = e_wait;
                            l_RetVal_E = E_OK;
                            break;
                        }
                        else
                        {
                           /* Empty Buffer not found */
                            l_RetVal_E = E_NOT_OK;
                        }

                    }
                }
                else
                {
                    /* IPC Message ID out of Bound */
                    l_RetVal_E = E_NOT_OK;
                }
            }
            else
            {
                /* IPC Payload size out of Bound */
                l_RetVal_E = E_NOT_OK;
            }
        }
        else
        {
            /* IPC Payload size out of Bound */
            l_RetVal_E = E_NOT_OK;
        }
    }
    else
    {
        /* IPC Host Manager not initialized */
        l_RetVal_E = E_NOT_OK;
    }

    return l_RetVal_E;
}

/**
 ******************************************************************************
 ** \fn IpcHost_BufferReleaseCallback
 **
 ** IPC Host Manager callback to release the SRAM buffer
 **
 ** This function returns void
 ** This function is being called by the Application to release the SRAM buffer after processing
 **
 ** \param [in] None
 *****************************************************************************/
FUNC (void, CRY_CODE) IpcHost_BufferReleaseCallback(uint8 buffer_id)
{
    uint32 l_ipcsrambuffadd_U32 = 0;
    ts_ipcdata *l_ipcdata_srambuff_ps = (ts_ipcdata *) NULL;

    if(buffer_id < IPC_NUMBER_OF_BUFFERS)
    {
        l_ipcsrambuffadd_U32 = (uint32)(IPC_SRAMADDR_M0P_M7_START + (buffer_id * IPC_BUFFER_SIZE_BYTES));
        l_ipcdata_srambuff_ps = (ts_ipcdata *)l_ipcsrambuffadd_U32;
        l_ipcdata_srambuff_ps->s_ipcdataheader.syncstate = e_idle;

    }
    else
    {
        /* Wrong Buffer Id sent */
    }
}

FUNC(void, vHsmIpc_CODE) vHsmIpc_MainFunction(void)
{
    vHsmIpc_HostManager_PeriodicCheck();
}
/* EOF */
