/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2020] Visteon Corporation
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
 * IPC driver header for IPC communication between cores.
 *
 * \version 1.0.02
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 25/Nov/'20 | bjayara2 | 1115132 | Initial version                       |
 * |1.00.01 | 15/Jan/'21 | bjayara2 | 1174465 | Added Doxygen Support                 |
 * |1.00.02 | 26/Jan/'21 | bjayara2 | 1091176 | M0+ StdTypes FUNC not working - fixed |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/
#ifndef V_HSM_IPC_H
#define V_HSM_IPC_H
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Std_Types.h"
#define FUNC(rettype, memclass) rettype 

/* Typedefs for Callback functions */
typedef void (*IpcNotifyCallback)(uint32 IPCData);

typedef void (*IpcReleaseCallback)(void);

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
FUNC (void, CRY_CODE) vHsmIpc_Init(void);

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
FUNC (void, CRY_CODE) vHsmIpc_DeInit(void);

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
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_AcquireLockForSharedRamAccess(void);

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
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_AcquireLockUpdateData(uint8  *SharedRamAddress);

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
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_RegisterReleaseCallback(IpcReleaseCallback p_Fn);

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
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_RegisterNotifyCallback(IpcNotifyCallback p_Fn);

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
FUNC (void, CRY_CODE) User_CalloutIpcRelease
(
        uint32 Idx,
        uint32 Data0,
        uint32 Data1
);
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
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_AcquireWorkFlashLock(void);
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_SendMsg(void *msg, uint32 len);
FUNC (Std_ReturnType, CRY_CODE) vHsmIpc_RecieveMsg(void *msg, uint32 len, uint32 thread_id);
FUNC (void, CRY_CODE) vHsmIpc_MsgPolling(void);
#endif /* V_HSM_IPC_H */
/* EOF */
