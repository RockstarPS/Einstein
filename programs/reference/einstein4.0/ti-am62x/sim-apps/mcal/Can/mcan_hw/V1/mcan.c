/********************************************************************
 *   Copyright (C) Texas Instruments Incorporated 2019-2020
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
 *  \file     mcan.c
 *
 *  \brief    This file contains the implementation of the APIs present in the
 *            device abstraction layer file of MCAN.
 *            This also contains some related macros.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/**
 * \brief This is to disable HW_SYNC_BARRIER for J7 due to performance
 *        requirement
 */

#define MEM_BARRIER_DISABLE

#include "Std_Types.h"
#include <stdint.h>
#include <string.h>
#include "Can_Cfg.h"
#include "mcan.h"
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */


uint32 MCAN_isMemInitDone(uint32 baseAddr)
{
    uint32 state;
    return state;
}

void MCAN_setOpMode(uint32 baseAddr, uint32 mode)
{

}

uint32 MCAN_getOpMode(uint32 baseAddr)
{

}

int32_t MCAN_init(uint32 baseAddr, const MCAN_InitParams *initParams)
{
    int32_t  status;
    return status;
}

int32_t MCAN_config(uint32 baseAddr, const MCAN_ConfigParams *configParams)
{
    int32_t status;
    return status;
}

void MCAN_eccConfig(uint32                    baseAddr,
                    const MCAN_ECCConfigParams *configParams)
{

}

int32_t MCAN_setBitTime(uint32                    baseAddr,
                        const MCAN_BitTimingParams *configParams)
{
    int32_t status;
    return status;
}

int32_t MCAN_msgRAMConfig(uint32                       baseAddr,
                          const MCAN_MsgRAMConfigParams *msgRAMConfigParams)
{
    int32_t  status;
    return status;
}


void MCAN_writeMsgRamNoCpy(uint32                 baseAddr,
                      uint32                 memType,
                      uint32                 bufNum,
                      const MCAN_TxBufElementNoCpy *elem)
{
    
}

int32_t MCAN_txBufAddReq(uint32 baseAddr, uint32 bufNum)
{
    int32_t  status;
    return status;
}

void  MCAN_getNewDataStatus(uint32              baseAddr,
                            MCAN_RxNewDataStatus *newDataStatus)
{

}

void  MCAN_clearNewDataStatus(uint32                    baseAddr,
                              const MCAN_RxNewDataStatus *newDataStatus)
{

}


void MCAN_readMsgRamNoCpy(uint32           baseAddr,
                     uint32           memType,
                     uint32           bufNum,
                     uint32           fifoNum,
                     MCAN_RxBufElementNoCpy *elem)
{
    
}


void MCAN_addStdMsgIDFilter(uint32                          baseAddr,
                            uint32                          filtNum,
                            const MCAN_StdMsgIDFilterElement *elem)
{
    
}

void MCAN_addExtMsgIDFilter(uint32                          baseAddr,
                            uint32                          filtNum,
                            const MCAN_ExtMsgIDFilterElement *elem)
{
    
}

void MCAN_lpbkModeEnable(uint32 baseAddr,
                         uint32 lpbkMode,
                         uint32 enable)
{
    
}


void  MCAN_getProtocolStatus(uint32             baseAddr,
                             MCAN_ProtocolStatus *protStatus)
{
    
}

void MCAN_enableIntr(uint32 baseAddr, uint32 intrMask, uint32 enable)
{
    
}

void MCAN_selectIntrLine(uint32 baseAddr,
                         uint32 intrMask,
                         uint32 lineNum)
{
    
}


void MCAN_enableIntrLine(uint32 baseAddr,
                         uint32 lineNum,
                         uint32 enable)
{
    
}

uint32 MCAN_getIntrStatus(uint32 baseAddr)
{

}

void MCAN_clearIntrStatus(uint32 baseAddr, uint32 intrMask)
{

}


void MCAN_getRxFIFOStatus(uint32           baseAddr,
                          MCAN_RxFIFOStatus *fifoStatus)
{

}

int32_t MCAN_writeRxFIFOAck(uint32 baseAddr,
                            uint32 fifoNum,
                            uint32 idx)
{
    int32_t  status;
    return status;
}


uint32 MCAN_getTxBufReqPend(uint32 baseAddr)
{

}

int32_t MCAN_txBufCancellationReq(uint32 baseAddr, uint32 buffNum)
{
    int32_t  status;
    return status;
}

uint32 MCAN_getTxBufTransmissionStatus(uint32 baseAddr)
{

}

uint32 MCAN_txBufCancellationStatus(uint32 baseAddr)
{

}

int32_t MCAN_txBufTransIntrEnable(uint32 baseAddr,
                                  uint32 bufNum,
                                  uint32 enable)
{
    int32_t  status;
    return status;
}

/* ========================================================================== */
/*                          Advance Functions                                 */
/* ========================================================================== */

uint32 MCAN_getClkStopAck(uint32 baseAddr)
{

}

/* ========================================================================== */
/*                          Internal Functions                                */
/* ========================================================================== */
