/*
*
* Copyright (C) 2023 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
 *  \file     CddIpcApp.c
 *
 *  \brief    This file contains the demo application for CDD IPC
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "CddIpcAppRProcLinux.h"
#include "app_utils.h"
#include "SchM_Cdd_Ipc.h" /* Exclusive area */

#ifndef SIMULATION_BUILD
#include <hw_include/soc.h>
#endif

#if !defined(SOC_AM62X) &&  !defined(SOC_AM62AX) &&  !defined(SOC_AM62PX)

#include <hw_include/lld_intr_router.h> /* CSL for interrupt router */

/* Interrupts, Clear MCU Timer 0 */
#include <hw_include/arch/lld_arch.h>
#include <hw_include/hw_types.h>

/* SCI Client */
#include <ti/drv/sciclient/sciclient.h>
/* PM Lib */
#include <ti/drv/pm/include/pm_types.h>
#include <ti/drv/pm/include/dmsc/pmlib_sysconfig.h>
#include <ti/drv/pm/include/dmsc/pmlib_clkrate.h>

/* Interrupt Registrations */
#include <ti/osal/osal.h>

/* resource table for Linux */
#include "IpcRscTable.h"
#include <ti/drv/ipc/include/ipc_virtio.h>

#include <ti/csl/soc.h>
#include <ti/csl/cslr.h>

#include <ti/osal/osal.h>
#include <ti/osal/TaskP.h>
#include <ti/board/board.h>

#include <ti/drv/sciclient/sciserver_tirtos.h>

#include <ti/drv/sciclient/src/sciclient/sciclient_priv.h>

#endif

#define System_printf Ipc_Trace_printf
#if defined(SOC_AM62X)  ||  defined(SOC_AM62AX) || defined(SOC_AM62PX)
#ifndef SIMULATION_BUILD
#include <hw_include/soc.h>
#endif
#include <hw_include/hw_types.h>
#include <drivers/sciclient.h>
#include "IpcRscTable.h"
#include <CddIpc/ipc_baremetal_hw/include/ipc_virtio.h>
#endif


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define MSG_NORMAL      (APP_UTILS_PRINT_MSG_NORMAL)
/**< Message type */
#define MSG_STATUS      (APP_UTILS_PRINT_MSG_STATUS)
/**< Message type */
#define CDD_IPC_APP_MSG_DATA_SIZE   (20U)
/**< Size of message buffer to be transmitted */
#define CDD_IPC_APP_MSG_TX_RX_CNT   (10U)

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#define IPC_VRING_MEM_SIZE      (0x00100000u)
uint32 Cdd_IpcAppIterCntMpu10 = CDD_IPC_APP_MSG_TX_RX_CNT;
/**< Counter to track number of messages to be transmitted & received */

volatile uint32 Cdd_IpcNewMsgCountEP13 = 0;
volatile uint32 Cdd_IpcNewMsgCountEP14 = 0;

/**< Buffer used to transmit and receive messages, to/from MPU 10 */

/**< Buffer used to transmit and receive messages, to/from MPU 11 */
uint32 mpu10Bufsize = CDD_IPC_APP_MSG_DATA_SIZE;
static uint8 Cdd_IpcAppMcu11Buffer[CDD_IPC_APP_MSG_DATA_SIZE];
const char* source = "send";
#if (STD_ON == CDD_IPC_ANNOUNCE_API)
    const char announceMsg1[32U] = "ti.ipc4.ping-pong";
    const char announceMsg2[32U] = "rpmsg_chrdev";
#endif

#if (STD_ON == CDD_IPC_ANNOUNCE_API)
    const char announceMsg[32U] = "ti.ipc4.ping-pong";
#endif



/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
static volatile uint8 TestCount = 0;
void CddIpcCommunicationTestDM(void)
{
    /* Variable storing maximum channels configured for IPC communication */
    // uint32 MaxChannelsConfigured = 0;
    /* MaxChannelsConfigured variable updated according to demo configurations */
    // MaxChannelsConfigured = CddIpcConfiguraions_PC.channelCount;
    /* Pointer to channel configurations */
    // const Cdd_IpcChannelType *pCommChCfg = CddIpcConfiguraions_PC.pChCfg;
    Cdd_IpcInit();

    #if (STD_ON == CDD_IPC_ANNOUNCE_API)
    //Cdd_IpcAnnounce((const UCHAR *)announceMsg,pCommChCfg[CddIpcConf_IpcComChanId_Cdd_ipcMpu11_EP15].id);
    #endif

    mpu10Bufsize = 4;
    // Copy characters one by one
    for (uint8 i = 0; i < mpu10Bufsize && i < sizeof(Cdd_IpcAppMcu11Buffer) - 1; i++) 
    {
        Cdd_IpcAppMcu11Buffer[i] = (uint8)source[i];
    }
    // Add the null terminator
    Cdd_IpcAppMcu11Buffer[mpu10Bufsize] = '\0';
    if(TestCount == 1)
    {
        Cdd_IpcSendMsg(CddIpcConf_IpcComChanId_Cdd_ipcMpu11_EP15, &Cdd_IpcAppMcu11Buffer, mpu10Bufsize);
    }
}


void CddIpcCommunicationTest(void){


#if defined(SOC_AM62AX) || defined(SOC_AM62PX)
    

    /* Variable to keep track of current channel ID */
    uint32 ChannelId = 0;
    /* Variable storing maximum channels configured for IPC communication */
    uint32 MaxChannelsConfigured = 0;
    /* MaxChannelsConfigured variable updated according to demo configurations */
    MaxChannelsConfigured = CddIpcConfiguraions_PC.channelCount;
    /* Pointer to channel configurations */
    const Cdd_IpcChannelType *pCommChCfg = CddIpcConfiguraions_PC.pChCfg;

    /* If A53 remote core is running Linux OS, then
     * load resource table
     */
    Ipc_loadResourceTable((void*)&ti_ipc_remoteproc_ResourceTable);

    /* Wait for Linux VDev ready... */
    for(ChannelId = 0;  ChannelId < MaxChannelsConfigured;  ChannelId++)
    {
        while(!Ipc_isRemoteReady(pCommChCfg[ChannelId].remoteProcId))
        {
            /* Only checking for all channels with A53(Linux) as remote core
             * If more than one channel is configured with both Linux and 
             * Non-Linux cores as remote cores change logic to check and wait
             * only for Linux remote cores
             */
        }
    }

    /* Initialize driver */
    Cdd_IpcInit();

    /* Announce that MCAL core is ready for communication with Linux remote core
     * on EP 13, ti.ipc4.ping-pong.
     * on EP 14, rpmsg_chrdev communication
     */
    #if (STD_ON == CDD_IPC_ANNOUNCE_API)
    //Cdd_IpcAnnounce((const UCHAR *)announceMsg1,pCommChCfg[CddIpcConf_IpcComChanId_Cdd_IpcMpu10_EP13].id);
    //Cdd_IpcAnnounce((const UCHAR *)announceMsg2,pCommChCfg[CddIpcConf_IpcComChanId_Cdd_IpcMpu10_EP14].id);
    #endif


#endif

}

void TxRxIpcMessage(void)
{
    /* Check if a new message is received from the remote core on EP13*/
        if(0 != Cdd_IpcNewMsgCountEP13){
            /* Receive message */
            //Cdd_IpcReceiveMsg(CddIpcConf_IpcComChanId_Cdd_IpcMpu10_EP13, &Cdd_IpcAppMpu10Buffer[0U], &mpu10Bufsize);
            /* Disable global interrupts */
            SchM_Enter_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0();
            /* Decrement message reception variable to indicate message has been received on EP13*/
            Cdd_IpcNewMsgCountEP13--;
            /* Enable global interrupts */
            SchM_Exit_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0();
            /* Respond back with the same received message to the remote core */
            //Cdd_IpcSendMsg(CddIpcConf_IpcComChanId_Cdd_IpcMpu10_EP13, &Cdd_IpcAppMpu10Buffer[0U], mpu10Bufsize);
        }
        else if(0 != Cdd_IpcNewMsgCountEP14){
            /* Receive message */
            //Cdd_IpcReceiveMsg(CddIpcConf_IpcComChanId_Cdd_IpcMpu10_EP14, &Cdd_IpcAppMpu10Buffer[0U], &mpu10Bufsize);
            /* Disable global interrupts */
            SchM_Enter_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0();
            /* Decrement message reception variable to indicate message has been received on EP13*/
            Cdd_IpcNewMsgCountEP14--;
            /* Enable global interrupts */
            SchM_Exit_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0();
            /* Respond back with the same received message to the remote core */
            //Cdd_IpcSendMsg(CddIpcConf_IpcComChanId_Cdd_IpcMpu10_EP14, &Cdd_IpcAppMpu10Buffer[0U], mpu10Bufsize);
        }
}

/* ========================================================================== */
/*                        Application Local Functions                         */
/* ========================================================================== */


/* User implemented funtion to process a control message
 * in case of reception of a control message, usually an
 * announcement message from the remote core at end point 
 * number 53
 */

#if (STD_ON == CDD_IPC_ANNOUNCE_API)
void Cdd_IpcNewCtrlMessageNotify(uint32 remoteProcId){

    /* Intentionally left blank as the remote cores
     * do not send an announcement to the Host core
     */
}
#endif /* (STD_ON == CDD_IPC_ANNOUNCE_API) */

/* New message notify function for end point 13
 * Contains user implementation for acknowledgment
 * that a message is available through a particular
 * channel
 */
void CddIpcNewMsgEp13(void){
    Cdd_IpcNewMsgCountEP13++;
}

/* New message notify function for end point 14
 * Contains user implementation for acknowledgment
 * that a message is available through a particular
 * channel
 */
void CddIpcNewMsgEp14(void){
    Cdd_IpcNewMsgCountEP14++;
}

/* EoF */