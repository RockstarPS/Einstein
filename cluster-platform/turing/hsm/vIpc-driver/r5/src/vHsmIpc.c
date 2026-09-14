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
 * \file vHsmIpc.c
 *
 * \brief
 * IPC driver for IPC communication between cores.
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
#include "vHsmIpc.h"
#include "Std_Types.h"
#include "string.h"
#include "vHsmIpcHostManager.h"
#include "cslr.h"
/******************************************************************************
 *  MACROS
 *****************************************************************************/
#ifndef LOCAL
#define LOCAL static
#endif /* LOCAL */

#undef IPC_TEST_WITH_COUNTER

#define IPC_IDX_FOR_DATA_M7_0_SRC  		(4)

#define IPC_IDX_FOR_DATA_M0P_SRC   		(5)

#define IPC_IDX_FOR_SHARED_RAM_ACCESS   (6)

#define IPC_IDX_FOR_WORKFLASH_USE       (3)

#define MASK_FOR_USER_IPC_CHANNELS      (0xfe)

/* S Proxy Macros*/
#define HOST_ID_MCU_0_R5_0 (30u)
/*Macro to define how long to wait for secure proxy message till timeout*/
#define HSM_IPC_RETRY_CNT_MS                  (1000 * 10)

/* Macros to identify the type of operation send/receive operation */
#define HSM_IPC_SPROXY_SEND             0U
#define HSM_IPC_SPROXY_GET              1U

/*secure proxy thread ids for ipc with hsm*/
#define RX_THREAD_ID_MAIN_R5                    9U
#define TX_THREAD_ID_MAIN_R5                    8U
#define RX_THREAD_ID_MCU_R5                    13U
#define TX_THREAD_ID_MCU_R5                    12U

/*default flag when senging secure proxy msg to hsm*/
#define TISCI_MASK_FLAG_AOP             2U

/*mask used to check for receiving sec proxy msg from hsm*/
#define SEC_PROXY_WAIT_MASK                  1U

/*Start address of secure proxy rt region*/
#define HSM_IPC_SEC_PROXY_RT_ADDRESS        (0x44880000U)

/*base address for secure proxy target address*/
#define HSM_IPC_SEC_PROXY_TARGET_ADDRESS    (0x43600000U)

/* Relative offset of sec proxy thread */
#define HSM_IPC_SPROXY_THREAD_OFFSET(tid) (0x1000U * (tid))

#define TISCI_HOST_ID_MAIN_0_R5 35
#define TISCI_HOST_ID_MCU_0_R5 30

/* Start and end address of data for sec proxy threads */
#define HSM_IPC_SPROXY_THREAD_DATA_ADDRESS(_target_base, tid)   \
    (_target_base + HSM_IPC_SPROXY_THREAD_OFFSET(tid) + 4U)
#define HSM_IPC_SPROXY_THREAD_DATA_ADDRESS_END(_target_base, tid) \
    (HSM_IPC_SPROXY_THREAD_DATA_ADDRESS(_target_base, tid) + 14U * 4U)

/* Address of sec proxy thread status register */
#define HSM_IPC_SPROXY_THREAD_STATUS(_rt_base, tid) \
    (_rt_base + HSM_IPC_SPROXY_THREAD_OFFSET(tid))

/* Mask to detect error condition */
#define HSM_IPC_SPROXY_STATUS_ERR       0x80000000U
#define HSM_IPC_SPROXY_STATUS_CNT_MASK  0xFFU

/**
 * \brief Header that prefixes all TISCI messages.
 *
 * \param type Type of message identified by a TISCI_MSG_* ID
 * \param host Host of the message.
 * \param seq Message identifier indicating a transfer sequence.
 * \param flags TISCI_MSG_FLAG_* for the message
 */
typedef struct{
	uint16	type;
	uint8	host;
	uint8	seq;
	uint32	flags;
}tisci_header;

typedef struct 
{
    tisci_header vHsmIpchdr_st;
    uint32 SRAM_addr[8];
}vHsmIpc_SecProxyMsg_st;

/* State machcine tracking for IPC states */
typedef enum
{
    IDLE = 0,
    INIT = 1,
    ACQUIRE = 2,
    NOTIFY = 3,
    RELEASE =4
}IpcStateMachcine;

LOCAL IpcStateMachcine l_vHsmIpcCM7SMu8 = IDLE;

LOCAL uint32 l_DataFromM0P_U32 = 0;

#ifdef IPC_TEST_WITH_COUNTER

LOCAL uint32 l_counter_U32 = 0;

#endif

LOCAL IpcNotifyCallback l_ptrNotifyCallBackFn;

LOCAL IpcReleaseCallback l_ptrReleaseCallBackFn;
LOCAL FUNC (Std_ReturnType, CRY_CODE) vHsm_IPC_trans_message(uint32 target_base, uint32 rt_base, uint8 is_rx, uint8 thread_id, void *msg, uint32 len);
LOCAL FUNC(uint32,CRY_CODE)SRAM_ADDRESS_MAP(uint32 SharedRamAddress);
LOCAL void delay_ms(uint32 ms);
/******************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/
/**
 ******************************************************************************
 ** \fn vHsmIpc_Init
 **
 ** IPC driver Init, to be invoked from HsmApp before placing any IPC jobs
 **
 ** This function returns None
 **
 ** \param [in] None
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsmIpc_Init(void)
{

    l_ptrNotifyCallBackFn = NULL;
    l_ptrReleaseCallBackFn = NULL;
    l_vHsmIpcCM7SMu8 =	INIT;
    /* Host Manager Initialization */
    vHsmIpc_HostManager_Init();
}
/**
 ******************************************************************************
 ** \fn vHsmIpc_DeInit
 **
 ** IPC driver DeInit to be invoked before going to low power mode/ shutdown
 ** when access to IPC is to be stopped
 **
 ** This function returns None
 **
 ** \param [in] None
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsmIpc_DeInit(void)
{
    l_vHsmIpcCM7SMu8 =	IDLE;
}

LOCAL FUNC(uint32,CRY_CODE)SRAM_ADDRESS_MAP(uint32 SharedRamAddress)
{
    return (SharedRamAddress - 0x43C00000U);
}
/**
 ******************************************************************************
 ** \fn vHsmIpc_AcquireLockUpdateData
 **
 ** Extra IPC channel only for shared RAM access from either cores
 **
 ** This function returns
 ** - E_OK if Acquired IPC channel for Crypto job operation
 ** - E_NOT_OK if not Acquired IPC channel for Crypto job operation
 **
 ** \param [in] SharedRamAddress - target address of SharedRamAddress
 ** \param [in] Size 			 - Number of bytes to be written
 ** \param [in] SrcAdd		     - Source Address from where Data to be copied
 *****************************************************************************/
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_AcquireLockUpdateData(uint8  *SharedRamAddress)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    vHsmIpc_SecProxyMsg_st vHsmIPCsend_st = {0};
    vHsmIPCsend_st.vHsmIpchdr_st.type = 0xa5a5;
    vHsmIPCsend_st.vHsmIpchdr_st.seq = 0;
    vHsmIPCsend_st.vHsmIpchdr_st.flags = 2;
    vHsmIPCsend_st.vHsmIpchdr_st.host = HOST_ID_MCU_0_R5_0;
    vHsmIPCsend_st.SRAM_addr[0] = SRAM_ADDRESS_MAP((uint32)SharedRamAddress);
    l_RetVal_e = vHsmIpc_SendMsg(&vHsmIPCsend_st,sizeof(vHsmIPCsend_st));
    return(l_RetVal_e);
} 

/**
 ******************************************************************************
 ** \fn vHsmIpc_RegisterReleaseCallback
 **
 ** Release Callback registration for IPC channel IPC_IDX_FOR_DATA_M7_0_SRC
 ** which is the source channel for M0P
 **
 ** This function returns
 ** - E_OK on Callback registered
 ** - E_NOT_OK if there's a failure
 **
 ** \param [in] IpcReleaseCallback - Function pointer to be registered
 **                                  and invoked upon release of the IPC channel
 **                                  IPC_IDX_FOR_DATA_M7_0_SRC
 *****************************************************************************/
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_RegisterReleaseCallback(IpcReleaseCallback p_Fn)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    if((IDLE != l_vHsmIpcCM7SMu8) && (p_Fn != NULL))
    {
        l_ptrReleaseCallBackFn = p_Fn;
        l_RetVal_e = E_OK;
    }
    else
    {
        /* Do Nothing */
    }
    return(l_RetVal_e);
} 
/**
 ******************************************************************************
 ** \fn vHsmIpc_RegisterNotifyCallback
 **
 ** Notify Callback registration for IPC channel IPC_IDX_FOR_DATA_M0P_SRC
 ** which is the destination channel for M0P
 ** This function returns
 ** - E_OK on Callback registered
 ** - E_NOT_OK if there's a failure
 **
 ** \param [in] IpcReleaseCallback - Function pointer to be registered
 **                                  and invoked upon release of the IPC channel
 **                                  IPC_IDX_FOR_DATA_M0P_SRC
 *****************************************************************************/
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_RegisterNotifyCallback(IpcNotifyCallback p_Fn)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    if((IDLE != l_vHsmIpcCM7SMu8) && (p_Fn != NULL))
    {
        l_ptrNotifyCallBackFn = p_Fn;
        l_RetVal_e = E_OK;
    }
    else
    {
        /* Do Nothing */
    }
    return(l_RetVal_e);
} 

/**
 ******************************************************************************
 ** \fn User_CalloutIpcNotify
 **
 ** Notify Callout from IPC interrupt
 **
 ** \param [in] 
     uint32 Idx   - IPC channel index
    uint32 Data0  - Data 0 reg value
    uint32 Data1  - Data 1 reg value
 *****************************************************************************/
FUNC (void, CRY_CODE) User_CalloutIpcNotify
(
        uint32 Idx,
        uint32 Data0,
        uint32 Data1
)
{
    if(Idx == IPC_IDX_FOR_DATA_M0P_SRC)
    {
        l_DataFromM0P_U32 = Data0;
        if(l_ptrNotifyCallBackFn != NULL)
        {
            (l_ptrNotifyCallBackFn)(l_DataFromM0P_U32);
        }
        /* just notify all IPC Interrupt Structs,
        it is up to them to filter the non-relevant IPC structs */
    }
    else
    {
        /* Do not do anything as the channel is not meant for the configuration */
    }
}

/**
 ******************************************************************************
 ** \fn User_CalloutIpcRelease
 **
 ** Release Callout from IPC interrupt
 **
 ** \param [in] 
     uint32 Idx   - IPC channel index
    uint32 Data0  - Data 0 reg value
    uint32 Data1  - Data 1 reg value
 *****************************************************************************/
FUNC (void, CRY_CODE) User_CalloutIpcRelease
(
        uint32 Idx,
        uint32 Data0,
        uint32 Data1
)
{
    if(Idx == IPC_IDX_FOR_DATA_M7_0_SRC)
    {
        if (l_ptrReleaseCallBackFn  != NULL)
        {
            (l_ptrReleaseCallBackFn)();
        }
        l_vHsmIpcCM7SMu8 = RELEASE;
    }
    else
    {
        /* Do not do anything as the channel is not meant for the configuration */
    }
}

LOCAL void delay_ms(uint32 ms) {
    uint32 count = ms * 800000; // Calculate total ticks for the delay
    volatile uint32 i; // Use volatile to prevent optimization
    while (count > 0) {
        for (i = 0; i < 100; i++); // A small loop to waste time
        count--; // Decrement the tick count
    }
}

/**
 ******************************************************************************
 ** \fn vHsmIpc_AcquireWorkFlashLock
 **
 ** IPC channel only for workflash usage between cores - Acquire
 **
 ** This function returns
 ** - E_OK if Acquired IPC channel for workflash write/ erase usage
 ** - E_NOT_OK if not Acquired IPC channel for workflash  write/ erase usage
 **
 ** \param [in] None
 *****************************************************************************/
LOCAL FUNC (Std_ReturnType, CRY_CODE) vHsm_IPC_trans_message(uint32 target_base, uint32 rt_base, uint8 is_rx, uint8 thread_id, void *msg, uint32 len)
{
    Std_ReturnType l_Retval_E = E_OK;
    uint32 start_addr = (uint32)AddrTranslateP_getLocalAddr(HSM_IPC_SPROXY_THREAD_DATA_ADDRESS(target_base, thread_id));
    uint32 end_addr = (uint32)AddrTranslateP_getLocalAddr(HSM_IPC_SPROXY_THREAD_DATA_ADDRESS_END(target_base, thread_id));
    uint32 *raw = (uint32 *) msg;
    uint32 status, word, mask;
    uint16 i;
    /* Check if the number of transaction bytes are not too many */
    if ((start_addr + len + 4U) > end_addr) {
        l_Retval_E = E_NOT_OK;
    }


    if (l_Retval_E == E_OK) {
        for (i = 0; i < HSM_IPC_RETRY_CNT_MS; i++) {
            status = CSL_REG32_RD(HSM_IPC_SPROXY_THREAD_STATUS(rt_base, thread_id));
            if ((status & HSM_IPC_SPROXY_STATUS_ERR) != 0U) {
                l_Retval_E = E_NOT_OK;
            }

            if ((status & HSM_IPC_SPROXY_STATUS_CNT_MASK) != 0U) {
                break;
            }

            if (i < (HSM_IPC_RETRY_CNT_MS - 1U)) {
                delay_ms(1U);
            } else {
                l_Retval_E = E_NOT_OK;
            }
        }
    }


    if (!is_rx) {
		CSL_REG32_WR(start_addr, 0);
		start_addr += 4;
	} else {
		start_addr += 4;
	}

    if (l_Retval_E == E_OK) {

        for (i = 0; i < (len / 4U); i++) {
            if (is_rx) {
                *raw = CSL_REG32_RD(start_addr);
            } else {
                CSL_REG32_WR(start_addr, *raw);
            }
            raw += 1U;
            start_addr += 4U;
        }

        if ((len % 4U) != 0U) {
            if (!is_rx) {
                mask = ~0UL >> ((4U - (len % 4U)) * 8U);
                word = (*raw) & mask;
                CSL_REG32_WR(start_addr, word);
            } else {
                word = CSL_REG32_RD(start_addr);
                /* Let memcpy deal with the alignment stuff */
                memcpy(raw, &word, len % 4U);
            }
        }

        /* flush out the transfer by reading/writing the last location */
        if (is_rx) {
            (void) CSL_REG32_RD(end_addr);
        } else {
            CSL_REG32_WR(end_addr, 0x0U);
        }
    }
    
    return l_Retval_E;
}

FUNC (void, CRY_CODE) vHsmIpc_MsgPolling(void)
{
    Std_ReturnType fl_retVal_E = E_NOT_OK;
    vHsmIpc_SecProxyMsg_st vHsmIpc_R5Msg_st;
    if((CSL_REG32_RD(HSM_IPC_SPROXY_THREAD_STATUS(HSM_IPC_SEC_PROXY_RT_ADDRESS, RX_THREAD_ID_MCU_R5))&SEC_PROXY_WAIT_MASK) != 0u)
    {
        fl_retVal_E = vHsmIpc_RecieveMsg(&vHsmIpc_R5Msg_st,sizeof(vHsmIpc_R5Msg_st),RX_THREAD_ID_MCU_R5);
        if(E_OK == fl_retVal_E)
        {
            User_CalloutIpcNotify(IPC_IDX_FOR_DATA_M0P_SRC,vHsmIpc_R5Msg_st.SRAM_addr[0],0);
        }
        else
        {
            /* keep trying*/
        }
    }
    else
    {
        /*No message on Sec Proxy*/
    }
}
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_SendMsg(void *msg, uint32 len)
{
    return vHsm_IPC_trans_message(HSM_IPC_SEC_PROXY_TARGET_ADDRESS, HSM_IPC_SEC_PROXY_RT_ADDRESS, HSM_IPC_SPROXY_SEND, TX_THREAD_ID_MCU_R5, msg, len);
}
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_RecieveMsg(void *msg, uint32 len, uint32 thread_id)
{
    return vHsm_IPC_trans_message(HSM_IPC_SEC_PROXY_TARGET_ADDRESS, HSM_IPC_SEC_PROXY_RT_ADDRESS, HSM_IPC_SPROXY_GET, thread_id, msg, len);
}

/* EOF */
