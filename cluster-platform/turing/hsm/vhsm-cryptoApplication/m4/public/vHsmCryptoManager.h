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
 * \file vHsmCryptoManager.h
 *
 * \brief
 * Visteon HSM Crypto Manager for Crypto Application support in M0P.
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

#ifndef V_HSM_CRYPTO_MANAGER_H
#define V_HSM_CRYPTO_MANAGER_H
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "vHsmCryptoMessageM0P.h"
#include "Std_Types.h"

/******************************************************************************
 *  PUBLIC MACRO DEFINITIONS
 *****************************************************************************/

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
 ** \param [in] uint8 buffer_id
 **        [in] uint8* buffer_add
 **        [in] uint16 payload_size
 *****************************************************************************/
#define ENTRY(a,b) void b(uint8 keyId, uint8* const cryptodata_addr,uint16 payload_size);
CRYPTO_JOB_TABLE
#undef ENTRY

/**
 ******************************************************************************
 ** \fn IPC_MESSAGE_TABLE Functions
 **
 ** IPC Host Manager command Interface to the application
 **
 ** This function returns None
 **
 ** \param [in] uint8 buffer_id
 **        [in] uint8* buffer_add
 **        [in] uint16 payload_size
 *****************************************************************************/
#define ENTRY(a,b) void b(uint8* const commanddata_addr,uint16 payload_size);
COMMAND_JOB_TABLE
#undef ENTRY

/**
 ******************************************************************************
 ** \fn vHsmCrypto_Manager_SendData
 **
 ** Crypto Manager API to send the data on IPC.
 **
 ** This function returns Std_ReturnType - E_OK or E_NOK
 **
 ** \param [in] ts_vHsm_Cryptodata - Data from Cry If
 *****************************************************************************/
Std_ReturnType vHsmCrypto_Manager_SendData(ts_vHsm_Cryptodata s_vHsm_Cryptodata);

/**
 ******************************************************************************
 ** \fn vHsmCrypto_Command_SendData
 **
 ** Crypto General command API to send the data on IPC.
 **
 ** This function returns Std_ReturnType - E_OK or E_NOK
 **
 ** \param [in] ts_commanddata - Data from System Commands
 *****************************************************************************/
Std_ReturnType vHsmCrypto_Command_SendData(ts_vHsm_Commanddata s_vHsm_Commanddata);


/*****************************************************************************
Date              :25/Nov/2020
By                :Kgeethaa
Traceability      :
Change Description: Initial version
******************************************************************************/
#endif /* V_HSM_CRYPTO_MANAGER_H */
/* EOF */
