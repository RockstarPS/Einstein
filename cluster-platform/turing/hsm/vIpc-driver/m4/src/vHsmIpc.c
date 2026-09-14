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
#include "tisci_protocol.h"
#include "dmsc_irq_map.h"
#include "sec_proxy_minimal.h"
#include "secure_proxy.h"
#include "vHsmIpcHostManager.h"
#include "hsm.h"
#include "hwip.h"
#include "hosts.h"
#include "sec_proxy.h"
#ifdef VHSMCRYPT_BLOBS_ENABLED 
#include "vHsmCrypt_Utilities.h"
#endif
/******************************************************************************
 *  MACROS
 *****************************************************************************/
#ifndef LOCAL
#define LOCAL static
#endif /* LOCAL */
#ifdef IPC_TEST_WITH_COUNTER
#undef IPC_TEST_WITH_COUNTER
#endif

#define UNUSED_PARAM       (void)

#define IPC_IDX_FOR_DATA_M7_0_SRC       (4)

#define IPC_IDX_FOR_DATA_M0P_SRC        (5)

#define IPC_IDX_FOR_WORKFLASH_USE       (6)

#define MASK_FOR_USER_IPC_CHANNELS      (0xfe)

#ifdef HSMIPCLINUX
#define IPC_MAILBOX_CLUSTER             (0x89030000)
#endif

#ifdef IPC_CHANNEL_FOR_SHARED_RAM_ACCESS_ENABLE
#define IPC_IDX_FOR_SHARED_RAM_ACCESS   (7)
#endif
#define IPC_INTERRUPT_PRIORITY          (255u)
#define IPC_INTERRUPT_IRQ               (NVIC_IRQ(HSM_SEC_PROXY_RX_IRQ))
#define IPC_INTERRUPT_ACK               (2)
#define IPC_HSM_MCU_TX_THREAD           (4u)
/* State machcine tracking for IPC states */
typedef enum
{
    IDLE = 0,
    INIT = 1,
    ACQUIRE = 2,
    NOTIFY = 3,
    RELEASE =4
}IpcStateMachcine;

typedef struct 
{
    struct tisci_header vHsmIpchdr_st;
    uint32 SRAM_addr[8];
}vHsmIpc_SecProxyMsg_st;

LOCAL IpcStateMachcine l_vHsmIpcCM0pSMu8 = IDLE;

LOCAL uint32 l_vHsmIpcDataFromM7U32 = 0;

LOCAL IpcNotifyCallback l_ptrNotifyCallBackFn;

LOCAL IpcReleaseCallback l_ptrReleaseCallBackFn;

LOCAL FUNC(void, IPC_CODE) vHsmSecProxy_Isr(uint32 a);
LOCAL FUNC(void, IPC_CODE) vHsmSecProxy_ItrEnable(void);
LOCAL FUNC(uint32,IPC_CODE)SRAM_ADDRESS_MAP(uint32 SharedRamAddress);
#ifdef IPC_TEST_WITH_COUNTER

LOCAL uint32 l_counter_U32 = 0;

#endif
#ifdef AUTEHENTICATED_DEBUG_ENABLE
const cy_stc_sysint_irq_t dap_ipc_irq_cfg =
{
   .sysIntSrc = (cy_en_intr_t)(cpuss_interrupts_ipc_0_IRQn + USED_DAP_IPC_INTERRUPT),
   .intIdx    = IPC_DAP_NOTIFY_CPU_IRQ_INDEX,
   .isEnabled = true
};
#endif
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
FUNC (void, IPC_CODE) vHsmIpc_Init(void)
{
    /* Interrupt setting for Secure Proxy*/
    
    l_ptrNotifyCallBackFn = NULL;
    l_ptrReleaseCallBackFn = NULL;
    l_vHsmIpcCM0pSMu8 =	INIT;
    vHsmSecProxy_ItrEnable();
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
FUNC (void, IPC_CODE) vHsmIpc_DeInit(void)
{
    l_vHsmIpcCM0pSMu8 =	IDLE;
}

#ifdef IPC_CHANNEL_FOR_SHARED_RAM_ACCESS_ENABLE
/**
 ******************************************************************************
 ** \fn vHsmIpc_AcquireLockForSharedRamAccess
 **
 ** Extra IPC channel only for shared RAM access from either cores
 **
 ** This function returns
 ** - E_OK if Acquired IPC channel for shared RAM access
 ** - E_NOT_OK if not Acquired IPC channel for shared RAM access
 **
 ** \param [in] None
 *****************************************************************************/
Std_ReturnType vHsmIpc_AcquireLockForSharedRamAccess(void)
{
    CySldIpc_un_IPC_STRUCT_ACQUIRE_t AcqStatus;
    CySldIpc_un_IPC_STRUCT_LOCK_STATUS_t LockStatus;
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    if(IDLE != l_vHsmIpcCM0pSMu8)
    {
        if(CySldIpc_GetLockStatus(IPC_IDX_FOR_SHARED_RAM_ACCESS, &LockStatus) == E_OK)
        {
            if(LockStatus.stcField.u1ACQUIRED == 0)
            {
                if(CySldIpc_Acquire(IPC_IDX_FOR_SHARED_RAM_ACCESS, &AcqStatus) == E_OK)
                {
                    if(AcqStatus.stcField.u1SUCCESS == 1)
                    {
                        l_RetVal_e = E_OK;
                    }
                }
            }
        }
    }
    else
    {
        /* Do Nothing */
    }
    return(l_RetVal_e);
}
#endif //IPC_CHANNEL_FOR_SHARED_RAM_ACCESS_ENABLE

LOCAL FUNC(uint32,IPC_CODE)SRAM_ADDRESS_MAP(uint32 SharedRamAddress)
{
#ifdef HSMIPCLINUX
    return (SharedRamAddress - 0x00030000);
#else
    return (SharedRamAddress + 0x43C00000U);
#endif
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
 ** \param [in] SharedRamAddress   target address of SharedRamAddress
 ** \param [in] Size               Number of bytes to be written
 ** \param [in] SrcAdd             Source Address from where Data to be copied
 *****************************************************************************/
FUNC (Std_ReturnType, IPC_CODE)  vHsmIpc_AcquireLockUpdateData(uint8  *SharedRamAddress)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
#ifdef HSMIPCLINUX
    l_RetVal_e = vHsmIpc_SendLinuxMsg(SRAM_ADDRESS_MAP((uint32)SharedRamAddress));
#else
    vHsmIpc_SecProxyMsg_st vHsmIPCsend_st = {0};
    vHsmIPCsend_st.vHsmIpchdr_st.type = 0xa5a5;
    vHsmIPCsend_st.vHsmIpchdr_st.seq = 0;
    vHsmIPCsend_st.vHsmIpchdr_st.flags = IPC_INTERRUPT_ACK;
    vHsmIPCsend_st.vHsmIpchdr_st.host = HOST_ID_HSM;
    vHsmIPCsend_st.SRAM_addr[0] = SRAM_ADDRESS_MAP((uint32)SharedRamAddress);
    l_RetVal_e = sproxy_send_msg(&vHsmIPCsend_st,sizeof(vHsmIPCsend_st),IPC_HSM_MCU_TX_THREAD);
#endif
    return(l_RetVal_e);
}

/**
 ******************************************************************************
 ** \fn vHsmIpc_RegisterReleaseCallback
 **
 ** Release Callback registration for IPC channel IPC_IDX_FOR_DATA_M0P_SRC
 ** which is the source channel for M0P
 **
 ** This function returns
 ** - E_OK on Callback registered
 ** - E_NOT_OK if there's a failure
 **
 ** \param [in] IpcReleaseCallback - Function pointer to be registered
 **                                  and invoked upon release of the IPC channel
 **                                  IPC_IDX_FOR_DATA_M0P_SRC
 *****************************************************************************/
FUNC (Std_ReturnType, IPC_CODE) vHsmIpc_RegisterReleaseCallback(IpcReleaseCallback p_Fn)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    if((IDLE != l_vHsmIpcCM0pSMu8) && (p_Fn != NULL))
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
 ** Notify Callback registration for IPC channel IPC_IDX_FOR_DATA_M7_0_SRC
 ** which is the destination channel for M0P
 ** This function returns
 ** - E_OK on Callback registered
 ** - E_NOT_OK if there's a failure
 **
 ** \param [in] IpcNotifyCallback - Function pointer to be registered
 **                                  and invoked upon release of the IPC channel
 **                                  IPC_IDX_FOR_DATA_M7_0_SRC
 *****************************************************************************/
FUNC (Std_ReturnType, IPC_CODE) vHsmIpc_RegisterNotifyCallback(IpcNotifyCallback p_Fn)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    if((IDLE != l_vHsmIpcCM0pSMu8) && (p_Fn != NULL))
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
FUNC (void, IPC_CODE) User_CalloutIpcNotify
(
        uint32 Idx,
        uint32 Data0,
        uint32 Data1
)
{
	UNUSED_PARAM Data1;
    if(Idx == (uint32)IPC_IDX_FOR_DATA_M7_0_SRC)
    {
        l_vHsmIpcDataFromM7U32 = Data0;
        if(l_ptrNotifyCallBackFn != NULL)
        {
            (l_ptrNotifyCallBackFn)(l_vHsmIpcDataFromM7U32);
        }
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
FUNC (void, IPC_CODE) User_CalloutIpcRelease
(
        uint32 Idx,
        uint32 Data0,
        uint32 Data1
)
{
	UNUSED_PARAM Data0;
	UNUSED_PARAM Data1;
    if(Idx == (uint32)IPC_IDX_FOR_DATA_M0P_SRC)
    {
        if (l_ptrReleaseCallBackFn  != NULL)
        {
            (l_ptrReleaseCallBackFn)();
        }
        l_vHsmIpcCM0pSMu8 = RELEASE;
    }
    else
    {
        /* Do not do anything as the channel is not meant for the configuration */
    }
}

/********************************************************************************
 ** \fn vHsmSecProxy_Isr(void)
 **
 ** Notify Callout from IPC interrupt
 **
 ** \param [in] 
     uint32 Idx   - IPC channel index
    uint32 Data0  - Data 0 reg value
    uint32 Data1  - Data 1 reg value
 *****************************************************************************/
LOCAL FUNC(void, IPC_CODE) vHsmSecProxy_Isr(uint32 a)
{
    UNUSED_PARAM(a);
    sint32 fl_retVal = HSM_FAILURE;
    vHsmIpc_SecProxyMsg_st vHsmSecProxy_Rx_st = {0};
    fl_retVal = osal_hwip_disable_interrupt(IPC_INTERRUPT_IRQ);
    if(fl_retVal == E_OK)
    {
        fl_retVal = sproxy_receive_msg(&vHsmSecProxy_Rx_st,sizeof(vHsmSecProxy_Rx_st));
        if((fl_retVal == E_OK) && (vHsmSecProxy_Rx_st.vHsmIpchdr_st.flags != 0) && (HOST_ID_MCU_0_R5_0 == vHsmSecProxy_Rx_st.vHsmIpchdr_st.host))
        {
            User_CalloutIpcNotify(IPC_IDX_FOR_DATA_M7_0_SRC,vHsmSecProxy_Rx_st.SRAM_addr[0],0);
        }
        if((fl_retVal == E_OK) && (vHsmSecProxy_Rx_st.vHsmIpchdr_st.flags != 0) && (HOST_ID_HSM == vHsmSecProxy_Rx_st.vHsmIpchdr_st.host)&& (TISCI_MSG_SA2UL_GET_DKEK == vHsmSecProxy_Rx_st.vHsmIpchdr_st.type))
        {
#ifdef VHSMCRYPT_BLOBS_ENABLED 
            vHsmCrypt_DKEK_Res(&vHsmSecProxy_Rx_st.SRAM_addr[0]);
#endif
        }
        (void)osal_hwip_enable_interrupt(IPC_INTERRUPT_IRQ);
    }
}
/**
 ******************************************************************************
 ** \fn vHsmSecProxy_ItrEnable(void)
 **
 ** Notify Callout from IPC interrupt
 **
 ** \param [in] 
     uint32 Idx   - IPC channel index
    uint32 Data0  - Data 0 reg value
    uint32 Data1  - Data 1 reg value
 *****************************************************************************/
LOCAL FUNC(void, IPC_CODE) vHsmSecProxy_ItrEnable(void)
{
    struct hwip_params vHsmSecProxyParam_st;
    uint32 err = 0;
    vHsmSecProxyParam_st.priority = IPC_INTERRUPT_PRIORITY;
    mask_interrupts();
    err = hwip_create(0,IPC_INTERRUPT_IRQ,vHsmSecProxy_Isr,&vHsmSecProxyParam_st);
    if(err != 0)
    { /* error case*/
    }
    err = hwip_clear_interrupt(IPC_INTERRUPT_IRQ);
    if(err != 0)
    {
       /*error case*/
    }
    err = hwip_enable_interrupt(IPC_INTERRUPT_IRQ,NULL);
    if(err != 0)
    {
       /*error Case*/
    }
    unmask_interrupts();
}

#ifdef HSMIPCLINUX
FUNC (Std_ReturnType, IPC_CODE) vHsmIpc_SendLinuxMsg(uint32 p_sram)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    if(INIT == l_vHsmIpcCM0pSMu8)
    {
        if(1u != vHsmIpcReg_st->fifoStatus[0])
        {
            vHsmIpcReg_st->message[0] = p_sram;
            l_RetVal_E = E_OK;
        }
    }
    return l_RetVal_E;
}

FUNC (Std_ReturnType, IPC_CODE) vHsmIpc_RecieveLinuxMsg(void)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    if(INIT == l_vHsmIpcCM0pSMu8)
    {
        if(0u != vHsmIpcReg_st->msgStatus[1])
        {
            User_CalloutIpcNotify(IPC_IDX_FOR_DATA_M7_0_SRC,vHsmIpcReg_st->message[1],0);
            l_RetVal_E = E_OK;
        }
    }
    return l_RetVal_E;
}
#endif
/* EOF */
