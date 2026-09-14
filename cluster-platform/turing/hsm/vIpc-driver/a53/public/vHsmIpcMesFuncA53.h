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
 * \file vHsmIpcMessageFunctM7.h
 *
 * \brief
 *  IPC Host Manager Message functions declared for different message ids.
 *
 * \version 1.0.01
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 26/Nov/'20 | kgeetha  | xxxxxx  | Initial version                       |
 * |1.00.01 | 15/Jan/'21 | bjayara2 | 1174465 | Added Doxygen Support                 |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/

#ifndef V_HSM_IPC_MESFUNCM7_H
#define V_HSM_IPC_MESFUNCM7_H
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "vHsmIpc_Types.h"


/******************************************************************************
 *  MACROS
 *****************************************************************************/


/* X-Macro to create a jump table to map the message ID's to the corresponding Application Functions */
/*******************Message_ID*************************FunctionName**************/
#define IPC_MESSAGE_TABLE \
ENTRY(               MESSAGE_ID_0,                   IPC_Funct_Message0               )\
ENTRY(               MESSAGE_ID_1,                   IPC_Funct_Message1               )\
ENTRY(               MESSAGE_ID_2,                   IPC_Funct_Message2               )\
ENTRY(               IPC_CRYPTO_ID,                  IPC_Crypto_MessageHandler        )\
ENTRY(               IPC_COMMAND_ID,                 IPC_Command_MessageHandler       )

/******************************************************************************
 *  PUBLIC ENUM DECLARATIONS
 *****************************************************************************/
#define ENTRY(a,b)             a,
typedef enum
{
    IPC_MESSAGE_TABLE
    IPC_UNUSED_MSGID
}te_ipcmessageid;
#undef ENTRY

/******************************************************************************
 *  PUBLIC FUNCTION DECLARATIONS
 *****************************************************************************/

/*****************************************************************************
Date              :26/Nov/2020
By                :kgeethaa
Traceability      :
Change Description: Initial version
******************************************************************************/
#endif /* V_HSM_IPC_MESFUNCM7_H */
/* EOF */
