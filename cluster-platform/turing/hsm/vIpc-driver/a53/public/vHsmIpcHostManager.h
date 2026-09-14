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
 * \file vHsmIpcHostManager.h
 *
 * \brief
 *  IPC driver header file for IPC Host Manager between cores.
 *
 * \version 1.0.2
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 26/Nov/'20 | kgeetha  | xxxxxx  | Initial version                       |
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
#ifndef V_HSM_IPC_HOSTMANAGER_H
#define V_HSM_IPC_HOSTMANAGER_H
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "vHsmIpcMesFuncA53.h"
#include "vHsmIpcSram.h"
/******************************************************************************
 *  PUBLIC MACRO DEFINITIONS
 *****************************************************************************/
/* As per the design this is fixed to be 8 bytes (20 in case of --no-short-enum
 * [no_short enum => 4bytes for each enum]
 * [short enum => 1 byte for each enum])*/

#ifdef NO_SHORT_ENUM
#define IPC_HEADER_SIZE           20
#else  /* SHORT_ENUM */
#define IPC_HEADER_SIZE           8
#endif /* NO_SHORT_ENUM */

/* Each buffer size of one IPC buffer in SRAM is */
#define IPC_BUFFER_SIZE_BYTES                    (((IPC_SIZE_SHAREDRAM_SEGMENT) * (IPC_BYTES_PER_KB))/(IPC_NUMBER_OF_BUFFERS))
#define IPC_MAX_PAYLOAD_DATA_SIZE                ( IPC_BUFFER_SIZE_BYTES - IPC_HEADER_SIZE )

/******************************************************************************
 *  PUBLIC FUNCTION DECLARATIONS
 *****************************************************************************/
/**
 ******************************************************************************
 ** \fn IPC_MESSAGE_TABLE Functions
 **
 ** IPC Host Manager Interface to the application
 **
 ** This function returns None
 **
 ** \param [in] uint8_t buffer_id
 **        [in] uint8_t* buffer_add
 **        [in] uint16_t payload_size
 *****************************************************************************/
#define ENTRY(a,b) FUNC (void, CRY_CODE) b(uint8_t buffer_id, uint8_t* buffer_add,uint16_t payload_size);
IPC_MESSAGE_TABLE
#undef ENTRY
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
FUNC (void, CRY_CODE) vHsmIpc_HostManager_Init(void);

/**
 ******************************************************************************
 ** \fn IpcHost_MessageSend
 **
 ** IPC Host Manager API to send a message on IPC
 **
 ** This function returns Std_ReturnType
 ** This function is being called by the Application to register an IPC message
 **
 ** \param [in] None
 *****************************************************************************/
FUNC (Std_ReturnType, CRY_CODE) IpcHost_MessageSend(uint8_t *Ipcdata, uint16_t Ipcdatasize, uint16_t MessageId);

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
FUNC (void, CRY_CODE) IpcHost_BufferReleaseCallback(uint8_t buffer_id);

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
FUNC (void, CRY_CODE) vHsmIpc_HostManager_PeriodicCheck(void);

#endif /* V_HSM_IPC_HOSTMANAGER_H */
/* EOF */
