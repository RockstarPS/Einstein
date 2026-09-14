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
#include "vHsmIpc_Types.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
//#include <csl_sec_proxy.h>
//#include "debug.h"
//#include "vHsmIpcHostManager.h"
/******************************************************************************
 *  MACROS
 *****************************************************************************/

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
#define RX_THREAD_ID_A53                    11U
#define TX_THREAD_ID_A53                    10U

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


#define CSL_REG32_RD(p)     *p
   

/**
 * \brief Header that prefixes all TISCI messages.
 *
 * \param type Type of message identified by a TISCI_MSG_* ID
 * \param host Host of the message.
 * \param seq Message identifier indicating a transfer sequence.
 * \param flags TISCI_MSG_FLAG_* for the message
 */
typedef struct{
	uint16_t	type;
	uint8_t	host;
	uint8_t	seq;
	uint32_t	flags;
}tisci_header;

typedef struct 
{
    tisci_header vHsmIpchdr_st;
    uint32_t SRAM_addr;
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

//LOCAL uint32_t l_DataFromM0P_U32 = 0;

#ifdef IPC_TEST_WITH_COUNTER

LOCAL uint32_t l_counter_U32 = 0;

#endif

LOCAL IpcNotifyCallback l_ptrNotifyCallBackFn;

LOCAL IpcReleaseCallback l_ptrReleaseCallBackFn;
LOCAL FUNC (Std_ReturnType, CRY_CODE) vHsm_IPC_trans_message(vHsmIpcMReg_st* p_mRegAdd, uint8_t is_rx, void *msg, uint32_t len);
//LOCAL FUNC(uint32_t,CRY_CODE)SRAM_ADDRESS_MAP(uint32_t SharedRamAddress);
LOCAL void delay_ms(uint32_t ms);
static void test_ipcmmap(void);

LOCAL vHsmIpcMReg_st vHsmIpcReg_tx_st = {0};
LOCAL vHsmIpcMReg_st vHsmIpcReg_rx_st = {0};
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
    vHsmIpcMemMap(&vHsmIpcReg_tx_st,TX_THREAD_ID_A53);
    vHsmIpcMemMap(&vHsmIpcReg_tx_st,RX_THREAD_ID_A53);
    /* Host Manager Initialization */
    //vHsmIpc_HostManager_Init();
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
#if 0
LOCAL FUNC(uint32_t,CRY_CODE)SRAM_ADDRESS_MAP(uint32_t SharedRamAddress)
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
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_AcquireLockUpdateData(uint8_t  *SharedRamAddress)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    vHsmIpc_SecProxyMsg_st vHsmIPCsend_st = {0};
    vHsmIPCsend_st.vHsmIpchdr_st.type = 0x9029;
    vHsmIPCsend_st.vHsmIpchdr_st.seq = 0;
    vHsmIPCsend_st.vHsmIpchdr_st.flags = 2;
    vHsmIPCsend_st.vHsmIpchdr_st.host = HOST_ID_MCU_0_R5_0;
    vHsmIPCsend_st.SRAM_addr = SRAM_ADDRESS_MAP((uint32_t)SharedRamAddress);
   // l_RetVal_e = vHsmIpc_SendMsg(&vHsmIPCsend_st,sizeof(vHsmIPCsend_st));
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
     uint32_t Idx   - IPC channel index
    uint32_t Data0  - Data 0 reg value
    uint32_t Data1  - Data 1 reg value
 *****************************************************************************/
FUNC (void, CRY_CODE) User_CalloutIpcNotify
(
        uint32_t Idx,
        uint32_t Data0,
        uint32_t Data1
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
     uint32_t Idx   - IPC channel index
    uint32_t Data0  - Data 0 reg value
    uint32_t Data1  - Data 1 reg value
 *****************************************************************************/
FUNC (void, CRY_CODE) User_CalloutIpcRelease
(
        uint32_t Idx,
        uint32_t Data0,
        uint32_t Data1
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
#endif
LOCAL void delay_ms(uint32_t ms) {
    uint32_t count = ms * 800000; // Calculate total ticks for the delay
    volatile uint32_t i; // Use volatile to prevent optimization
    while (count > 0) {
        for (i = 0; i < 100; i++); // A small loop to waste time
        count--; // Decrement the tick count
    }
}
/**
 ******************************************************************************
 ** \fn vHsm_IPC_trans_message
 **
 ** IPC channel only for workflash usage between cores - Acquire
 **
 ** This function returns
 ** - E_OK if Acquired IPC channel for workflash write/ erase usage
 ** - E_NOT_OK if not Acquired IPC channel for workflash  write/ erase usage
 **
 ** \param [in] None
 *****************************************************************************/
LOCAL FUNC (Std_ReturnType, CRY_CODE) vHsm_IPC_trans_message(vHsmIpcMReg_st* p_mRegAdd, uint8_t is_rx, void *msg, uint32_t len)
{
    Std_ReturnType l_Retval_E = E_OK;
    uint32_t *raw = (uint32_t *) msg;
    uint32_t status, word, mask;
    uint16_t i;

  
    /* Check if the number of transaction bytes are not too many */
    if ((p_mRegAdd->Tr_StartAdd + len + 4U) > p_mRegAdd->Tr_EndAdd) {
        printf("HSM IPC trans Address offset \n");
        l_Retval_E = E_NOT_OK;
    }


    if (l_Retval_E == E_OK) {
        for (i = 0; i < HSM_IPC_RETRY_CNT_MS; i++) {
            status = *(p_mRegAdd->Tr_Status);
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
		*(p_mRegAdd->Tr_StartAdd) = 0;
		p_mRegAdd->Tr_StartAdd += 4;
	} else {
		p_mRegAdd->Tr_StartAdd += 4;
	}

    if (l_Retval_E == E_OK) {

        for (i = 0; i < (len / 4U); i++) {
            if (is_rx) {
                *raw = *(p_mRegAdd->Tr_StartAdd);
            } else {
                *(p_mRegAdd->Tr_StartAdd) = *raw;
            }
            raw += 1U;
            p_mRegAdd->Tr_StartAdd += 4U;
        }

        if ((len % 4U) != 0U) {
            if (!is_rx) {
                mask = ~0UL >> ((4U - (len % 4U)) * 8U);
                word = (*raw) & mask;
                *(p_mRegAdd->Tr_StartAdd) = word;
            } else {
                word = *(p_mRegAdd->Tr_StartAdd);
                /* Let memcpy deal with the alignment stuff */
                memcpy(raw, &word, len % 4U);
            }
        }

        /* flush out the transfer by reading/writing the last location */
        if (is_rx) {
            (void) CSL_REG32_RD(p_mRegAdd->Tr_EndAdd);
        } else {
            *(p_mRegAdd->Tr_EndAdd) = 0x0U;
        }
    }
    return l_Retval_E;
}

FUNC (void, CRY_CODE) vHsmIpc_MsgPolling(void)
{
    Std_ReturnType fl_retVal_E = E_NOT_OK;
    vHsmIpc_SecProxyMsg_st vHsmIpc_R5Msg_st;
    if((CSL_REG32_RD(vHsmIpcReg_rx_st.Tr_Status)&SEC_PROXY_WAIT_MASK) != 0u)
    {
        printf("IPC Recieved From HSM\n");
        fl_retVal_E = vHsmIpc_RecieveMsg(&vHsmIpc_R5Msg_st,sizeof(vHsmIpc_R5Msg_st));
        if(E_OK == fl_retVal_E)
        {
            printf("Message Recieved From HSM\n");
            //User_CalloutIpcNotify(IPC_IDX_FOR_DATA_M0P_SRC,vHsmIpc_R5Msg_st.SRAM_addr,0);
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
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_SendMsg(void *msg, uint32_t len)
{
    return vHsm_IPC_trans_message(&vHsmIpcReg_tx_st, HSM_IPC_SPROXY_SEND, msg, len);
}
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_RecieveMsg(void *msg, uint32_t len)
{
    return vHsm_IPC_trans_message(&vHsmIpcReg_rx_st, HSM_IPC_SPROXY_GET, msg, len);
}

Std_ReturnType vHsmIpcMemMap(vHsmIpcMReg_st * p_MRegAddd_st, uint8_t thread_id)
{
    Std_ReturnType l_RetVal_E = E_OK;
    int32_t fd;
    uint32_t Reg_length = (HSM_IPC_SPROXY_THREAD_DATA_ADDRESS_END(HSM_IPC_SEC_PROXY_TARGET_ADDRESS, thread_id) - HSM_IPC_SPROXY_THREAD_DATA_ADDRESS(HSM_IPC_SEC_PROXY_TARGET_ADDRESS, thread_id))*sizeof(uint32_t);
    fd = open("/dev/mem", 0x02 );
    if(-1 == fd)
    {
        printf("Hsm IPC memmap open failed\n");
        l_RetVal_E = E_NOT_OK;
    }
    else
    {
        p_MRegAddd_st->Tr_StartAdd = (volatile uint32_t *)mmap( NULL_PTR, sizeof(uint32_t), PROT_WRITE | PROT_READ, MAP_SHARED, fd, HSM_IPC_SPROXY_THREAD_DATA_ADDRESS(HSM_IPC_SEC_PROXY_TARGET_ADDRESS, thread_id));
        if ( MAP_FAILED == p_MRegAddd_st->Tr_StartAdd)
        {       
            printf("Hsm IPC Start Add mapping failed\n");
            l_RetVal_E = E_NOT_OK;
        }
        if(E_OK == l_RetVal_E)
        {
            p_MRegAddd_st->Tr_EndAdd = (volatile uint32_t *)mmap( NULL_PTR, sizeof(uint32_t), PROT_WRITE | PROT_READ, MAP_SHARED, fd, HSM_IPC_SPROXY_THREAD_DATA_ADDRESS_END(HSM_IPC_SEC_PROXY_TARGET_ADDRESS, thread_id));
            if ( MAP_FAILED == p_MRegAddd_st->Tr_EndAdd)
            {       
                printf("Hsm IPC End Add mapping failed\n");
                l_RetVal_E = E_NOT_OK;
            }
            if(E_OK == l_RetVal_E)
            {
                p_MRegAddd_st->Tr_Status = (volatile uint32_t *)mmap( NULL_PTR,  sizeof(uint32_t), PROT_WRITE | PROT_READ, MAP_SHARED, fd, HSM_IPC_SPROXY_THREAD_STATUS(HSM_IPC_SEC_PROXY_RT_ADDRESS, thread_id));
                if ( MAP_FAILED == p_MRegAddd_st->Tr_Status)
                {       
                    printf("Hsm IPC Status Add mapping failed\n");
                    l_RetVal_E = E_NOT_OK;
                }
                printf("Virtual address for Reg1: %p\n",  p_MRegAddd_st->Tr_StartAdd);
                printf("Virtual address for Reg2: %p\n", p_MRegAddd_st->Tr_EndAdd);
            }
        }
        (void)close(fd);
    }
    return l_RetVal_E;
}
static void test_ipcmmap(void)
{
    int32_t fd;
    fd = open("/dev/mem", 0x02);
    if(-1 == fd)
    {
        printf("Hsm IPC memmap open failed\n");
    }
    else
    {
        
        #if 0
        volatile uint32_t * ipcshared = (volatile uint32_t *)mmap( NULL_PTR,  sizeof(uint32_t), PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0x43c30000);
        if ( MAP_FAILED == ipcshared)
        {       
            printf("Hsm IPC Start Add mapping failed\n");
         
        }
        else
        {
            printf(" HSM IPC data %d \n",*ipcshared);
            printf(" HSM IPC data+1 %d \n",*(ipcshared+1));
        }
        #endif
        volatile uint32_t * IpcThread = (volatile uint32_t *)mmap( NULL_PTR,  sizeof(uint32_t), PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0x4360A000);
        if ( MAP_FAILED == IpcThread)
        {       
            printf("Hsm IPC Start Add mapping failed\n");
         
        }
        else
        {
             printf(" HSM IPC data %d \n",*IpcThread);
        }

        
    }
   
}

int main(int argc, char *argv[])
{
    Std_ReturnType l_Ret = E_NOT_OK;
    vHsmIpc_SecProxyMsg_st vHsmIPCsend_st = {0};
    vHsmIPCsend_st.vHsmIpchdr_st.type = 0x9029;
    vHsmIPCsend_st.vHsmIpchdr_st.seq = 0;
    vHsmIPCsend_st.vHsmIpchdr_st.flags = 2;
    vHsmIPCsend_st.vHsmIpchdr_st.host = 10;
    vHsmIPCsend_st.SRAM_addr = 0x5a5a5a5a;
    int32_t fd;
    //test_ipcmmap();
    volatile uint32_t * secadd = (volatile uint32_t*)0x43600000;
    printf(" HSM IPC data dummy  %d \n",*secadd);
    #if 0
    vHsmIpc_Init();
    printf(" Sending Message to HSM\n");
    l_Ret = vHsmIpc_SendMsg(&vHsmIPCsend_st,sizeof(vHsmIPCsend_st));
    if(E_OK == l_Ret)
    {
        printf(" HSM message send\n");
        while(1)
        { 
            vHsmIpc_MsgPolling();
            usleep(10000);
        }
    }
    #endif
}

/* EOF */
