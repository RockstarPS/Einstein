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
#include "vHsmIpcHostManager.h"
#include "vHsmIpcSram.h"
#include "vHsmCryptoManager.h"
#include "vHsmCryptoMessageA53.h"
/******************************************************************************
 *  MACROS
 *****************************************************************************/

#undef IPC_TEST_WITH_COUNTER

#define IPC_IDX_FOR_DATA_M7_0_SRC  		(4)

#define IPC_IDX_FOR_DATA_M0P_SRC   		(5)

#define IPC_IDX_FOR_SHARED_RAM_ACCESS   (6)

#define IPC_IDX_FOR_WORKFLASH_USE       (3)

#define MASK_FOR_USER_IPC_CHANNELS      (0xfe)


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

LOCAL uint64_t l_DataFromM0P_U32 = 0;

#ifdef IPC_TEST_WITH_COUNTER

LOCAL uint32_t l_counter_U32 = 0;

#endif

LOCAL IpcNotifyCallback l_ptrNotifyCallBackFn;

LOCAL IpcReleaseCallback l_ptrReleaseCallBackFn;
LOCAL FUNC(uint32_t,CRY_CODE)SRAM_ADDRESS_MAP(uint32_t SharedRamAddress);
static void test_ipcmmap(void);

LOCAL vHsmIpcMReg_st * vHsmIpcReg_st = NULL_PTR;
LOCAL void * vHsmIpcSramAdd = NULL_PTR;

uint64_t vHsmIpcBuffAddr_U32 = 0;
static uint8_t l_message_flag = 0;
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
    Std_ReturnType fl_InitReturn = E_NOT_OK;
    l_ptrNotifyCallBackFn = NULL;
    l_ptrReleaseCallBackFn = NULL;
    fl_InitReturn = vHsmIpcMemMap();
    if(E_NOT_OK != fl_InitReturn)
    {
        l_vHsmIpcCM7SMu8 =	INIT;
        /* Host Manager Initialization */
        vHsmIpc_HostManager_Init();
    }
    else
    {
        printf(" Hsm IPC Init Failed \n");
    }
    
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

LOCAL FUNC(uint32_t,CRY_CODE)SRAM_ADDRESS_MAP(uint32_t SharedRamAddress)
{
    return (SharedRamAddress + 0x00030000U);
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
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_AcquireLockUpdateData(uint64_t SharedRamAddress)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    uint32_t fl_vHsmIpcSramAdd_U32 = SRAM_ADDRESS_MAP((uint32_t)SharedRamAddress);
    l_RetVal_e = vHsmIpc_SendMsg(fl_vHsmIpcSramAdd_U32);
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
    uint64_t l_sramadd_lin = 0;
    if(Idx == IPC_IDX_FOR_DATA_M0P_SRC)
    {
        l_sramadd_lin = IPC_SRAMADDR_M7_M0P_START + Data0;
        l_DataFromM0P_U32 = l_sramadd_lin;
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

FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_SendMsg(uint32_t p_sramadd)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    if(INIT == l_vHsmIpcCM7SMu8)
    {
        if(1u != vHsmIpcReg_st->fifoStatus[1])
        {
            vHsmIpcReg_st->message[1] = p_sramadd;
            l_RetVal_E = E_OK;
        }
    }
    return l_RetVal_E;
}

FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_RecieveMsg(void)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    if(INIT == l_vHsmIpcCM7SMu8)
    {
        if(0u != vHsmIpcReg_st->msgStatus[0])
        {

            User_CalloutIpcNotify(IPC_IDX_FOR_DATA_M0P_SRC,vHsmIpcReg_st->message[0],0);
            l_RetVal_E = E_OK;
        }
    }
    return l_RetVal_E;
}

Std_ReturnType vHsmIpcMemMap(void)
{
    Std_ReturnType l_RetVal_E = E_OK;
    int32_t fd;
    fd = open("/dev/mem", 0x02 );
    if(-1 == fd)
    {
        printf("Hsm IPC memmap open failed\n");
        l_RetVal_E = E_NOT_OK;
    }
    else
    {
        vHsmIpcSramAdd = mmap( NULL_PTR, 0x4000, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0x43C30000);
        if ( MAP_FAILED == vHsmIpcSramAdd)
        {       
            printf("Hsm IPC Shared Ram failed\n");
            l_RetVal_E = E_NOT_OK;
        }
        if(E_OK == l_RetVal_E)
        {
            vHsmIpcReg_st = (vHsmIpcMReg_st*)mmap(NULL_PTR, getpagesize(), PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0x29030000);
            if ( MAP_FAILED == vHsmIpcReg_st)
            {       
                printf("Hsm IPC Mailbox Registers Mapping failed\n");
                l_RetVal_E = E_NOT_OK;
            }
            vHsmIpcBuffAddr_U32 = (uint64_t)vHsmIpcSramAdd;
#if 0
            printf(" Mapped address for sram %x\n",vHsmIpcSramAdd);
            printf(" mapped address B for sram %llu\n",*((uint32_t*)IPC_SRAMADDR_START));
            printf(" mapped address end for sram %x\n",IPC_SRAMADDR_END);
#endif
        }
        (void)close(fd);
    }
    return l_RetVal_E;
}
static void test_ipcmmap(void)
{
    #if 0
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
        vHsmIpcReg_st = (vHsmIpcMReg_st*)mmap(NULL_PTR, getpagesize(), PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0x29030000);
        if ( MAP_FAILED == vHsmIpcReg_st)
        {       
            printf("Hsm IPC Mailbox Registers Mapping failed\n");
        }
        else
        {
            printf("Hsm IPC Mailbox Registers Mapped\n");
        }

        
    }
    #endif
}

int main(int argc, char *argv[])
{
    Std_ReturnType l_Ret = E_NOT_OK;
    uint8_t l_flag = 0;
    uint8_t l_cryptodata[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    test_ipcmmap();
   
    vHsmIpc_Init();
    
    l_Ret = vHsmKey_Store(&l_cryptodata[0],16);
    if(E_OK == l_Ret)
    {
        //vHsmIpc_SendMsg(0x5a5a5a5a);
        printf(" Ipc Message Sent to Hsm \n");
#if 0        
        while(l_flag == 0)
        {
            l_Ret = vHsmIpc_RecieveMsg();
            if(E_OK == l_Ret)
            {
                l_flag = 0xff;
            }
        }
#endif
        while(l_message_flag != 0xff)
        {
            vHsmIpc_HostManager_PeriodicCheck();
            usleep(100000);
        }
    }
}

void KeyStore_Callback(uint8_t * payload, uint16_t payloadsize)
{
    uint8_t status = *payload;
    uint8_t i_loop = 0;
    uint8_t l_val[17] = {0};
    if(CRYPTO_JOB_DONE == status)
    {
        (void)memcpy(&l_val[0],payload,17);
        printf("KeyStore Callback received key sotre sucessfull\n");
        printf("Values from HSM \n");
        for(i_loop = 0;i_loop<16;i_loop++)
        {
            printf(" %x",l_val[i_loop]);
        }
        printf("\n");
        l_message_flag = 0xff;
    }
    else
    {
        printf("KeyStore Callback received key sotre not sucessfull\n");
    }
}

/* EOF */
