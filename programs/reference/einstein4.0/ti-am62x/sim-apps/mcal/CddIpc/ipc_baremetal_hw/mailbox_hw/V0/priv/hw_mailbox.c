/*
 *  Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/**
 *  \file  hw_mailbox.c
 *
 *  \brief Mailbox Device Abstraction Layer APIs
 *
 *   This file contains the device abstraction layer APIs for the
 *   mailbox module. These are used for IPC communication.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/** \brief This is to disable HW_SYNC_BARRIER for register access */
#define MEM_BARRIER_DISABLE

#include "stdint.h"

#if defined(SOC_AM62X)
#include <CddIpc/ipc_baremetal_hw/mailbox_hw/V0/mailbox.h>
#include <CddIpc/ipc_baremetal_hw/mailbox_hw/V0/V0_0/hw_mailbox.h>
#endif

#if defined(SOC_AM62AX) || defined(SOC_AM62PX) || defined(SOC_J722S)
#include <CddIpc/ipc_baremetal_hw/mailbox_hw/V0/mailbox.h>
#include <CddIpc/ipc_baremetal_hw/mailbox_hw/V0/V0_1/hw_mailbox.h>
#endif

/* ========================================================================== */
/*                          Function Definitions                             */
/* ========================================================================== */

#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

void MailboxReset(uint32 baseAddr)
{
    
}
uint32 MailboxGetMessage(uint32 baseAddr, uint32 queueId,
                           uint32 *msgPtr)
{
    uint32 retval = 0U;
    return retval;
}

void MailboxReadMessage(uint32 baseAddr, uint32 queueId,
                        uint32 *msgPtr)
{

}

uint32 MailboxSendMessage(uint32 baseAddr, uint32 queueId, uint32 msg)
{
    uint32 retval = 0U;
    return retval;
}

void MailboxEnableNewMsgInt(uint32 baseAddr, uint32 userId,
                            uint32 queueId)
{
    
}

void MailboxEnableQueueNotFullInt(uint32 baseAddr, uint32 userId,
                                  uint32 queueId)
{
    
}

void MailboxDisableNewMsgInt(uint32 baseAddr, uint32 userId,
                             uint32 queueId)
{
    
}

void MailboxDisableQueueNotFullInt(uint32 baseAddr, uint32 userId,
                                   uint32 queueId)
{
    
}

void MailboxClrNewMsgStatus(uint32 baseAddr, uint32 userId,
                            uint32 queueId)
{
    
}

void MailboxClrQueueNotFullStatus(uint32 baseAddr, uint32 userId,
                                  uint32 queueId)
{
    
}

uint32 MailboxGetRawNewMsgStatus(uint32 baseAddr,
                                   uint32 userId,
                                   uint32 queueId)
{
    uint32 regVal = 0U;
    return (regVal);
}

uint32 MailboxGetRawQueueNotFullStatus(uint32 baseAddr,
                                         uint32 userId,
                                         uint32 queueId)
{
    uint32 regVal = 0U;
    return (regVal >> (queueId * 2U));
}

uint32 MailboxGetIrqEnableStatus(uint32 baseAddr,
                                   uint32 userId,
                                   uint32 queueId)
{
    uint32 regVal = 0U;

    return (regVal);
}

uint32 MailboxGetMessageCount(uint32 baseAddr,
                                uint32 queueId)
{
    return 0U;
}

void MailboxWriteMessage(uint32 baseAddr, uint32 queueId, uint32 msg)
{
    
}

void MailboxWriteEOI(uint32 baseAddr, uint32 value)
{
    
}

#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

/********************************* End of file ******************************/
