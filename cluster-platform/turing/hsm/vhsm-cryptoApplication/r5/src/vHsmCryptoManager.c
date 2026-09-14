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
 * \file vHsmCryptoManager.c
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

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "string.h"
#include "Std_Types.h"
#include "vHsmCryptoManager.h"
#include "vHsmIpcHostManager.h"

/******************************************************************************
 *  MACROS
 *****************************************************************************/
#ifndef LOCAL
#define LOCAL static
#endif /* LOCAL */

/* As per the design this is fixed to be 8 bytes (16 in case of --no-short-enum)
 * [no_short enum => 4bytes for each enum]
 * [short enum => 1 byte for each enum])*/
#ifdef NO_SHORT_ENUM
#define CRYPTO_HEADER_SIZE           16
#else /* SHORT_ENUM */
#define CRYPTO_HEADER_SIZE           8
#endif /* NO_SHORT_ENUM */

/* Each buffer size of one IPC buffer in SRAM is */
#define CRYPTO_MAX_PAYLOAD_DATA_SIZE                ( IPC_MAX_PAYLOAD_DATA_SIZE - CRYPTO_HEADER_SIZE )

/* As per the design this is fixed to be 4 bytes (12 in case of --no-short-enum)
 * [no_short enum => 4bytes for each enum]
 * [short enum => 1 byte for each enum])*/
#ifdef NO_SHORT_ENUM
#define COMMAND_HEADER_SIZE           12
#else /* SHORT_ENUM */
#define COMMAND_HEADER_SIZE           4
#endif /* NO_SHORT_ENUM */

/* Each buffer size of one IPC buffer in SRAM is */
#define CRYPTO_COMMAND_MAX_PAYLOAD_DATA_SIZE                ( IPC_MAX_PAYLOAD_DATA_SIZE - COMMAND_HEADER_SIZE )
/******************************************************************************
 * Static type declarations
 *****************************************************************************/
typedef FUNC (void, CRY_CODE) (*crypto_message_func_t)(uint8* cryptodata_addr,uint16 payload_size);

#define ENTRY(a,b)                                     b,
crypto_message_func_t Crypto_FuncPtr_jumptable[CRYPTO_UNUSED_JOBID] = {
        CRYPTO_JOB_TABLE
};
#undef ENTRY

typedef FUNC (void, CRY_CODE) (*command_message_func_t)(uint8* commanddata_addr,uint16 payload_size);

__attribute__((used))
#define ENTRY(a,b)                                     b,
command_message_func_t Command_FuncPtr_jumptable[COMMAND_UNUSED_JOBID] = {
        COMMAND_JOB_TABLE
};
#undef ENTRY

typedef struct
{
    uint16 payloadsize;
    te_cryptojobid cryptojob;
    te_jobpriority cryptojobprio;
    uint8 cryptokeyid;
    uint8 resrv1;
    uint8 resrv2;
    uint8 resrv3;
} ts_cryptojobheader;

typedef struct
{
    ts_cryptojobheader s_crytpjobheader;
    uint8 payloaddata[CRYPTO_MAX_PAYLOAD_DATA_SIZE];
}ts_cryptodata;

typedef struct
{
    uint16 payloadsize;
    te_commandid commandjob;
    uint8 commandjobprio;
} ts_commandjobheader;

typedef struct
{
    ts_commandjobheader s_commandjobheader;
    uint8 payloaddata[CRYPTO_COMMAND_MAX_PAYLOAD_DATA_SIZE];
}ts_commanddata;

/************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/
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
FUNC (Std_ReturnType, CRY_CODE) vHsmCrypto_Manager_SendData(ts_vHsm_Cryptodata s_vHsm_Cryptodata)
{
    ts_cryptodata l_cryptodata_S = { 0 };
    uint16 l_payloadsize_U16 = 0;
    Std_ReturnType l_RetVal_E = E_NOT_OK;

    /* Packing of the data with the crypto header and sending for IPC transfer */
    if(s_vHsm_Cryptodata.payLoadSize < (CRYPTO_MAX_PAYLOAD_DATA_SIZE + 1))
    {
        if(s_vHsm_Cryptodata.jobId_E < CRYPTO_UNUSED_JOBID)
        {
            l_cryptodata_S.s_crytpjobheader.cryptojob = s_vHsm_Cryptodata.jobId_E;
            l_cryptodata_S.s_crytpjobheader.cryptojobprio = s_vHsm_Cryptodata.priority_U8;
            l_cryptodata_S.s_crytpjobheader.cryptokeyid = s_vHsm_Cryptodata.KeyId_U8;
            l_cryptodata_S.s_crytpjobheader.payloadsize = s_vHsm_Cryptodata.payLoadSize;
            (void)memcpy((uint8 *)&l_cryptodata_S.payloaddata[0],(uint8 *)s_vHsm_Cryptodata.payLoadPtr_U8P,s_vHsm_Cryptodata.payLoadSize);
            l_payloadsize_U16 = l_cryptodata_S.s_crytpjobheader.payloadsize + CRYPTO_HEADER_SIZE;
            l_RetVal_E = IpcHost_MessageSend((uint8 *)&l_cryptodata_S,l_payloadsize_U16,IPC_CRYPTO_ID);
        }
        else
        {
            l_RetVal_E = E_NOT_OK;
        }
    }
    else
    {
        l_RetVal_E = E_NOT_OK;
    }
    return(l_RetVal_E);
}

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
FUNC (Std_ReturnType, CRY_CODE) vHsmCrypto_Command_SendData(ts_vHsm_Commanddata s_vHsm_Commanddata)
{
    ts_commanddata l_commanddata_S = { 0 };
    uint16 l_payloadsize_U16 = 0;
    Std_ReturnType l_RetVal_E = E_NOT_OK;

    /* Packing of the data with the crypto header and sending for IPC transfer */
    if(s_vHsm_Commanddata.payLoadSize < (CRYPTO_COMMAND_MAX_PAYLOAD_DATA_SIZE + 1))
    {
        if(s_vHsm_Commanddata.jobId_E < COMMAND_UNUSED_JOBID)
        {
            l_commanddata_S.s_commandjobheader.commandjob=s_vHsm_Commanddata.jobId_E;
            l_commanddata_S.s_commandjobheader.commandjobprio = s_vHsm_Commanddata.priority_U8;
            l_commanddata_S.s_commandjobheader.payloadsize = s_vHsm_Commanddata.payLoadSize;
            (void)memcpy((uint8 *)&l_commanddata_S.payloaddata[0],(uint8 *)s_vHsm_Commanddata.payLoadPtr_U8P,s_vHsm_Commanddata.payLoadSize);
            l_payloadsize_U16 = l_commanddata_S.s_commandjobheader.payloadsize + COMMAND_HEADER_SIZE;
            l_RetVal_E = IpcHost_MessageSend((uint8 *)&l_commanddata_S,l_payloadsize_U16,IPC_COMMAND_ID);
        }
        else
        {
            l_RetVal_E = E_NOT_OK;
        }
    }
    else
    {
        l_RetVal_E = E_NOT_OK;
    }
    return(l_RetVal_E);
}

/**
 ******************************************************************************
 ** \fn IPC_Crypto_MessageHandler
 **
 ** Crypto Manager API to recieve the data from IPC.
 **
 ** This function returns void
 **
 ** \param [in] uint8 buffer_id
 **             uint8* buffer_add
 **             uint16 payload_size
 *****************************************************************************/
FUNC (void, CRY_CODE) IPC_Crypto_MessageHandler(uint8 buffer_id, uint8* buffer_add,uint16 payload_size)
{
    ts_cryptodata *l_cryptodata_ps = (ts_cryptodata *)NULL;
    te_cryptojobid l_cryptojobid_e = CRYPTO_UNUSED_JOBID;
    uint8 * l_cryptodataaddr_U8P = (uint8 *)NULL;
    uint16 l_cryptopayloadsize_U16 = 0;

    if(payload_size < (CRYPTO_MAX_PAYLOAD_DATA_SIZE + 1))
    {
        l_cryptodata_ps = (ts_cryptodata *)buffer_add;
        if(NULL != l_cryptodata_ps)
        {
            l_cryptojobid_e = l_cryptodata_ps->s_crytpjobheader.cryptojob;
            /* Checking if the Job ID sent is valid */
            if(l_cryptojobid_e < CRYPTO_UNUSED_JOBID)
            {
                l_cryptodataaddr_U8P = (uint8 *)&l_cryptodata_ps->payloaddata[0];
                l_cryptopayloadsize_U16 = l_cryptodata_ps->s_crytpjobheader.payloadsize;
                /* Calling the function peratining to the Job Id */
                (void) Crypto_FuncPtr_jumptable[l_cryptojobid_e](l_cryptodataaddr_U8P,l_cryptopayloadsize_U16);
            }
        }
    }
    /* Release of the buffer after copying the data */
    IpcHost_BufferReleaseCallback(buffer_id);
}

/**
 ******************************************************************************
 ** \fn IPC_Command_MessageHandler
 **
 ** Crypto Manager API to recieve the command data from IPC.
 **
 ** This function returns void
 **
 ** \param [in] uint8 buffer_id
 **             uint8* buffer_add
 **             uint16 payload_size
 *****************************************************************************/
FUNC (void, CRY_CODE) IPC_Command_MessageHandler(uint8 buffer_id, uint8* buffer_add,uint16 payload_size)
{
    ts_commanddata *l_commanddata_ps = (ts_commanddata *)NULL;
    te_commandid l_commandjobid_e = COMMAND_UNUSED_JOBID;
    uint8 * l_commanddataaddr_U8P = (uint8 *)NULL;
    uint16 l_commandpayloadsize_U16 = 0;

    if(payload_size < (CRYPTO_COMMAND_MAX_PAYLOAD_DATA_SIZE + 1))
    {
        l_commanddata_ps = (ts_commanddata *)buffer_add;
        if(NULL != l_commanddata_ps)
        {
            l_commandjobid_e = l_commanddata_ps->s_commandjobheader.commandjob;
            /* Checking if the Job ID sent is valid */
            if(l_commandjobid_e < COMMAND_UNUSED_JOBID)
            {
                l_commanddataaddr_U8P = (uint8 *)&l_commanddata_ps->payloaddata[0];
                l_commandpayloadsize_U16 = l_commanddata_ps->s_commandjobheader.payloadsize;
                /* Calling the function peratining to the Job Id */
                (void) Command_FuncPtr_jumptable[l_commandjobid_e](l_commanddataaddr_U8P,l_commandpayloadsize_U16);
            }
        }
    }
    /* Release of the buffer after copying the data */
    IpcHost_BufferReleaseCallback(buffer_id);
}

/* EOF */
