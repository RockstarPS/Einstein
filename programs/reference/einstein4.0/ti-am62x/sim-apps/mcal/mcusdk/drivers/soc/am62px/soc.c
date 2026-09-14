/*
 *  Copyright (C) 2023-2024 Texas Instruments Incorporated
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
 *    documentation and/or other materials provided with the distribution.
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
 */

#include <drivers/soc.h>
#include <drivers/pinmux.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <string.h>

int32_t SOC_moduleClockEnable(uint32_t moduleId, uint32_t enable)
{
    return SystemP_SUCCESS;
}

int32_t SOC_moduleSetClockFrequency(uint32_t moduleId, uint32_t clkId, uint64_t clkRate)
{
    return SystemP_SUCCESS;
}

const char *SOC_getCoreName(uint16_t coreId)
{
    return "unknown";
}

uint32_t SOC_getCoreId(const char * coreName)
{
    return CSL_CORE_ID_INVALID;
}

uint64_t SOC_getSelfCpuClk(void)
{
    return 0;
}

void SOC_controlModuleLockMMR(uint32_t domainId, uint32_t partition)
{

}

void SOC_controlModuleUnlockMMR(uint32_t domainId, uint32_t partition)
{
    
}

void SOC_setEpwmTbClk(uint32_t epwmInstance, uint32_t enable)
{
    
}

void SOC_unlockAllMMR(void)
{
    
}

int32_t SOC_moduleGetClockFrequency(uint32_t moduleId, uint32_t clkId, uint64_t *clkRate)
{
    if (clkRate != NULL)
    {
        *clkRate = 0;
    }
    return SystemP_SUCCESS;
}

void SOC_setDevStat(uint32_t bootMode)
{
    
}

void SOC_generateSwWarmResetMainDomain(void)
{
    
}

void SOC_generateSwPORResetMainDomain(void)
{
    
}

uint32_t SOC_getWarmResetCauseMainDomain(void)
{
    return 0;
}

void SOC_generateSwWarmResetMcuDomain(void)
{
    
}

void SOC_generateSwWarmResetMainDomainFromMcuDomain(void)
{
    
}

void SOC_generateSwPORResetMainDomainFromMcuDomain(void)
{
    
}

void SOC_triggerMcuLpmWakeup(void)
{
    
}

uint32_t SOC_getWarmResetCauseMcuDomain(void)
{
    return 0;
}

void SOC_clearResetCauseMainMcuDomain(uint32_t resetCause)
{
    
}

int32_t SOC_getPSCState(uint32_t instNum, uint32_t domainNum, uint32_t moduleNum,
                    uint32_t *domainState, uint32_t *moduleState)
{
    if (domainState != NULL)
    {
        *domainState = 0;
    }
    if (moduleState != NULL)
    {
        *moduleState = 0;
    }
    return SystemP_SUCCESS;
}

int32_t SOC_setPSCState(uint32_t instNum, uint32_t domainNum, uint32_t moduleNum, uint32_t pscState)
{
    return SystemP_SUCCESS;
}

int32_t SOC_enableResetIsolation(uint32_t main2McuIsolation,
                                uint32_t dm2McuIsolation,
                                uint32_t mcu2dmIsolation,
                                uint32_t debugIsolationEnable)
{
    return SystemP_SUCCESS;
}

void SOC_setMCUResetIsolationDone(uint32_t value)
{
    
}

void SOC_waitMainDomainReset(void)
{
    
}

void SOC_setFSSCtrlFlashBootSize(void)
{
    
}