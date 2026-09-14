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
 * \file vHsmCryptoMessageR5.h
 *
 * \brief
 * Visteon HSM IPC driver header file for IPC Host Manager between cores.
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

#ifndef V_HSM_CRYPTO_MESSM0P_H
#define V_HSM_CRYPTO_MESSM0P_H
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
/*!
 * \defgroup   header_files Dependancy_headers
 */
/*!
 * \brief        The module shall use **Std_Types.h** data types.
 * \addtogroup  header_files
 */
#include "vHsmIpc_Types.h"

/******************************************************************************
 *  MACROS
 *****************************************************************************/


/* X-Macro to create a jump table to map the message ID's to the corresponding Application Functions */
/*******************Message_ID*************************FunctionName**************/
#define CRYPTO_JOB_TABLE \
ENTRY(    CID_0,                              Crypto_Dummy_Function              )\
ENTRY(    CID_1_ASYM_EXTRACT_CB,              KeyStore_Callback                  )\
ENTRY(    CID_2_ASYM_EXTRACT_FINISH,          Crypto_Dummy_Function              )\
ENTRY(    CID_3_ASYM_EXTRACT_FN,              Crypto_Dummy_Function              )\
ENTRY(    CID_4_ASYM_EXTRACT_START,           Crypto_Dummy_Function              )\
ENTRY(    CID_5_ASYM_EXTRACT_UPDATE,          Crypto_Dummy_Function              )



/* X-Macro to create a jump table to map the message ID's to the corresponding Application Functions */
/*******************Message_ID*************************FunctionName**************/
#define COMMAND_JOB_TABLE \
ENTRY(    SID_0,                              Command_Dummy_Function        )\
ENTRY(    SID_1_HARD_RESET_CMD,               Command_Dummy_Function        )\
ENTRY(    SID_2_HSM_WDG_PROXY_NOTIF,          Command_Dummy_Function        )
/******************************************************************************
 * Exported type declarations
 *****************************************************************************/
#define ENTRY(a,b)             a,
typedef enum
{
    CRYPTO_JOB_TABLE
    CRYPTO_UNUSED_JOBID
}te_cryptojobid;
#undef ENTRY

#define ENTRY(a,b)             a,
typedef enum
{
    COMMAND_JOB_TABLE
    COMMAND_UNUSED_JOBID
}te_commandid;
#undef ENTRY

typedef enum
{
    CRYPTO_JOB_DONE = 0,
    CRYPTO_JOB_NOT_DONE,
    CRYPTO_JOB_KEY_NOT_THERE
}te_cryptojobresult;

/* Priority id for the crypto job */
typedef enum
{
    e_priority0 = 0,
    e_priorityunused = 0xFF,
} te_jobpriority;

/* Crypto Job for cancellation */
typedef enum
{
    e_aescbcencrypt = 0,
    e_aescbcdecrypt,
    e_aesecbencrypt,
    e_aesecbdecrypt,
    e_aescmaccommon,
    e_hashsha256,
    e_allcancel,
    e_canceljobunused = 0xFF,
} te_canceljobid;
#pragma pack(push, 4)
typedef struct
{
    uint16_t         payLoadSize;
    uint8_t *        payLoadPtr_U8P;
    uint8_t jobId_E;
    uint8_t priority_U8;
    uint8_t          KeyId_U8;
} ts_vHsm_Cryptodata;
#pragma pack(pop)
#pragma pack(push, 4)
typedef struct
{
    uint16_t         payLoadSize;
    uint8_t          priority_U8;
    uint8_t *        payLoadPtr_U8P;
    uint8_t   jobId_E;
} ts_vHsm_Commanddata;
#pragma pack(pop)

/******************************************************************************
 *  PUBLIC FUNCTION DECLARATIONS
 *****************************************************************************/
FUNC(Std_ReturnType, CRY_CODE)vHsmKey_Store(uint8_t * p_key_pU8, uint16_t p_keySize);
#endif /* V_HSM_CRYPTO_MESSM0P_H */
/* EOF */
