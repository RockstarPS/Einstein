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
 * \file vHsmIpc.h
 *
 * \brief
 * IPC driver header file for IPC communication between cores.
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

#ifndef V_HSM_IPC_H
#define V_HSM_IPC_H
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Std_Types.h"

#undef HSMIPCLINUX

/* Typedefs for Callback functions */
typedef void (*IpcNotifyCallback)(uint32 IPCData);

typedef void (*IpcReleaseCallback)(void);

#ifdef HSMIPCLINUX
typedef struct 
{
    volatile uint32 revisionReg;
    volatile uint32 reserved1[3];
    volatile uint32 sysconfig;
    volatile uint32 reserved2[11];
    volatile uint32 message[16];
    volatile uint32 fifoStatus[16];
    volatile uint32 msgStatus[16];
    volatile uint32 unused[17];
}vHsmIpcMReg_st;
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
FUNC (void, IPC_CODE) vHsmIpc_Init(void);

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
FUNC (void, IPC_CODE) vHsmIpc_DeInit(void);

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
#ifdef IPC_CHANNEL_FOR_SHARED_RAM_ACCESS_ENABLE
FUNC (Std_ReturnType, IPC_CODE) vHsmIpc_AcquireLockForSharedRamAccess(void);
#endif
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
 ** \param [in] Size             - Number of bytes to be written
 ** \param [in] SrcAdd		     - Source Address from where Data to be copied
 *****************************************************************************/
FUNC (Std_ReturnType, IPC_CODE) vHsmIpc_AcquireLockUpdateData(uint8  *SharedRamAddress);

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
 **	                                 and invoked upon release of the IPC channel
 **                                  IPC_IDX_FOR_DATA_M0P_SRC
 *****************************************************************************/
FUNC (Std_ReturnType, IPC_CODE) vHsmIpc_RegisterReleaseCallback(IpcReleaseCallback p_Fn);

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
 ** \param [in] IpcReleaseCallback - Function pointer to be registered
 **                                  and invoked upon release of the IPC channel
 **                                  IPC_IDX_FOR_DATA_M7_0_SRC
 *****************************************************************************/
FUNC (Std_ReturnType, IPC_CODE)  vHsmIpc_RegisterNotifyCallback(IpcNotifyCallback p_Fn);

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
);

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
FUNC (void, IPC_CODE)  User_CalloutIpcRelease
(
        uint32 Idx,
        uint32 Data0,
        uint32 Data1
);

#ifdef HSMIPCLINUX
FUNC (Std_ReturnType, IPC_CODE) vHsmIpc_SendLinuxMsg(uint32 p_sram);
FUNC (Std_ReturnType, IPC_CODE) vHsmIpc_RecieveLinuxMsg(void);
#endif

#endif /* V_HSM_IPC_H */
/* EOF */
