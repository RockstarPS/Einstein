/**
 *  \file   csl_ospi.c
 *
 *  \brief  OSPI IP V0 controller hardware abstraction APIs.
 *
 *   This file contains the hardware abstraction layer APIs for OSPI.
 */

/*
 * Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdint.h>
#include <hw_include/lld_types.h>
#include <Fls/fls_hw/ospi/V0/lld_ospi.h>

/*******************************************************************************
*                        API FUNCTION DEFINITIONS
*******************************************************************************/

void CSL_ospiEnable(const CSL_ospi_flash_cfgRegs *pRegs,
                    uint32                      enable)
{
    
}

void CSL_ospiDacEnable(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32                      enable)
{
    
}

void CSL_ospiXipEnable(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32                      enable)
{
    
}

void CSL_ospiSetModeBits(const CSL_ospi_flash_cfgRegs *pRegs,
                          uint32                      flashModeVal)
{

}

void CSL_ospiPhyEnable(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32                      enable)
{
    
}

void CSL_ospiPipelinePhyEnable(const CSL_ospi_flash_cfgRegs *pRegs, uint32 enable)
{
    
}

void CSL_ospiDtrEnable(const CSL_ospi_flash_cfgRegs *pRegs, uint32 enable)
{
    
}

void CSL_ospiSetPreScaler(const CSL_ospi_flash_cfgRegs *pRegs,
                          uint32                      clkDividerVal)
{
    
}

void CSL_ospiSetClkMode(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32                      clkMode)
{

}

void CSL_ospiSetChipSelect(const CSL_ospi_flash_cfgRegs *pRegs,
                           uint32                      chipSelect,
                           uint32                      decSelect)
{

}

void CSL_ospiSetDevDelay(const CSL_ospi_flash_cfgRegs *pRegs,
                         const uint32               *delays)
{
    
}

void CSL_ospiSetDevSize(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32                      numAddrBytes,
                        uint32                      pageSize,
                        uint32                      blkSize)
{
    
}

void CSL_ospiSetIndTrigAddr(const CSL_ospi_flash_cfgRegs *pRegs,
                            uint32                      indTrigAddr)
{
    
}

void CSL_ospiSetWrCompAutoPolling(const CSL_ospi_flash_cfgRegs *pRegs,
                                  uint32                      pollingState)
{
    
}


void CSL_ospiSetPollingDummyCycles(const CSL_ospi_flash_cfgRegs *pRegs,
                                   uint32                      dummyCycles)
{
    
}


void CSL_ospiSetSramPartition(const CSL_ospi_flash_cfgRegs *pRegs,
                              uint32                      partition)
{
    LLD_REG32_WR(&pRegs->SRAM_PARTITION_CFG_REG, partition);
}

void CSL_ospiIntrEnable(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32                      intrFlag,
                        uint32                      enable)
{
    
}

uint32 CSL_ospiIntrStatus(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32 regVal = 0U;
    return (regVal);
}

void CSL_ospiIntrClear(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32                      intrFlag)
{
    
}

void CSL_ospiFlashExecCmd(const CSL_ospi_flash_cfgRegs *pRegs)
{

}

uint32 CSL_ospiFlashExecCmdComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32 retVal;
    return (retVal);
}

sint32 CSL_ospiCmdRead(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32                      cmd,
                        uint32                      rxLen)
{
    return (0);
}

sint32 CSL_ospiCmdExtRead(const CSL_ospi_flash_cfgRegs *pRegs,
                           const uint8                *cmdBuf,
                           uint32                      cmdLen,
                           uint32                      rxLen,
                           uint32                      dummyCycles)
{
    return (0);
}

sint32 CSL_ospiCmdWrite(const CSL_ospi_flash_cfgRegs *pRegs,
                         const uint8                *cmdBuf,
                         uint32                      cmdLen,
                         uint8                		*txBuf,
                         uint32                      txLen)
{
    return (0);
}

void CSL_ospiConfigRead(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32                      cmd,
                        uint32                      mode,
                        uint32                      dummyClk)
{
    
}

void CSL_ospiReadFifoData(uintptr_t indAddr, uint8 *dest, uint32 rdLen)
{
    
}

uint32 CSL_ospiGetSramLvl(const CSL_ospi_flash_cfgRegs *pRegs,
                            uint32                      read)
{
    uint32 sramLevel;
    return (sramLevel);
}

void CSL_ospiClrIndReadComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    
}

/* FLS_CoverageGap_04:Dynamic coverage for the function cannot be covered,
 * as it expects a certain value from hardware register.
 */
uint32 CSL_ospiIndReadComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32 retVal;
    return(retVal);
}

void CSL_ospiIndReadExecute(const CSL_ospi_flash_cfgRegs *pRegs,
                            uint32                      rxLen)
{
    
}

void CSL_ospiWriteSetup(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32                      cmd,
                        uint32                      mode)
{
    
}

void CSL_ospiWriteFifoData(uintptr_t indAddr, const uint8 *src, uint32 wrLen)
{
    
}

void CSL_ospiClrIndWriteComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    
}

/* FLS_CoverageGap_04:Dynamic coverage for the function cannot be covered,
 * as it expects a certain value from hardware register.
 */
uint32 CSL_ospiIsIndWriteComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32 retVal;
    return(retVal);
}


void CSL_ospiIndWriteExecute(const CSL_ospi_flash_cfgRegs *pRegs,
                             uint32                      txLen)
{
    
}

void CSL_ospiIndWriteCancel(const CSL_ospi_flash_cfgRegs *pRegs)
{
    
}

void CSL_ospiLoopbackClkEnable(const CSL_ospi_flash_cfgRegs *pRegs,
                               uint32                      enable)
{
    
}

uint32 CSL_ospiIsIdle(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32 status;
    return (status);
}

/* FLS_CoverageGap_06:Dynamic coverage for this function cannot be covered,
 * as it is never used in the driver code.
 */
void CSL_ospiConfigPhy(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32                      masterDelay,
                       const uint32               *pSlaveDelay)
{
    
}

void CSL_ospiFlashStig(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32                      cmd,
                       uint32                      addr,
                       uint32                      data)
{
    
}

void CSL_ospiIndSetStartAddr(const CSL_ospi_flash_cfgRegs *pRegs,
                             uint32                      startAddr,
                             uint32                      read)
{
    
}

void CSL_ospiSetDataReadCapDelay(const CSL_ospi_flash_cfgRegs *pRegs,
                                 uint32                      delay)
{
    
}

void CSL_ospiSetCsSotDelay(const CSL_ospi_flash_cfgRegs *pRegs,
                           uint32                      delay)
{
    
}

void CSL_ospiSetDualByteOpcodeMode(const CSL_ospi_flash_cfgRegs *pRegs,
                                   uint32                      opcodeMode)
{
    
}

uint32 CSL_ospiGetDualByteOpcodeMode(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32    opcodeMode;
    return opcodeMode;
}

void CSL_ospiExtOpcodeSet(const CSL_ospi_flash_cfgRegs *pRegs,
                          uint32                      opcodeLo,
                          uint32                      opcodeUp)
{
    
}

void CSL_ospiExtOpcodeGet(const CSL_ospi_flash_cfgRegs *pRegs,
                          uint32                     *opcodeLo,
                          uint32                     *opcodeUp)
{

}

/* FLS_CoverageGap_06:Dynamic coverage for this function cannot be covered,
 * as it is never used in the driver code.
 */
void CSL_ospiConfigPhyDLL(const CSL_ospi_flash_cfgRegs *pRegs,
                          uint32                      txDelay,
                          uint32                      rxDelay,
                          uint32                      opMode,
                          uint32                      funcClk)
{
    
}
