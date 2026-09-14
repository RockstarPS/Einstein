/******************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2017. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
/******************************************************************************
 *  File Name         :                                                       *
 *  Module Short Name :                                                       *
 *  Description       :                                                       *
 *                                                                            *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS Multi                                              *
 * Target Hardware  :  Platform Independent                                   *
 *                                                                            *
 ******************************************************************************/
#ifndef DLT_COMM_COM_H
#define DLT_COMM_COM_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Std_Types.h"



/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/* Dlt message buffer size */
#define DLT_MESSAGE_BUFFER_SIZE            1024U
#define DLT_CAN_TX_PDU_ID       (99U)
#define DLT_CAN_MAX_DLC         (8U)
#define DLT_MSG_BUF_SIZE        (8U)
/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

void Dlt_StartCommunicationHook_Cantp(void);
void Dlt_StopCommunicationHook_Cantp(void);
void Dlt_SendData_Cantp(uint8 data);

#endif
