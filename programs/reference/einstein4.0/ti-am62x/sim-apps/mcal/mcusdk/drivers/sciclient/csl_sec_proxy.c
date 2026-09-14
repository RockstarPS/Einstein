/**
 * @file  csl_sec_proxy.c
 *
 * @brief
 *  Implementation file for the sec_proxy module CSL.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2017-2019, Texas Instruments, Inc.
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
 *    Neither the name of Texas Instruments Incorposec_proxyed nor the names of
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

#include <drivers/sciclient/csl_sec_proxy.h>

#define CSL_SEC_PROXY_TARGET_CHAN_SIZE  (0x1000U)

/*=============================================================================
 *  CSL-FL functions
 *===========================================================================*/

uint32_t CSL_secProxyGetRevision( const CSL_SecProxyCfg *pSecProxyCfg )
{
    return 0;
}

uint32_t CSL_secProxyGetNumThreads( const CSL_SecProxyCfg *pSecProxyCfg )
{
    return 0;
}

int32_t CSL_secProxyCfgGlobalErrEvtNum( const CSL_SecProxyCfg *pSecProxyCfg, uint32_t globalErrEvtNum )
{
    int32_t retVal = 0;
    return retVal;
}

void CSL_secProxySetBufferAccessOrderId( CSL_SecProxyCfg *pSecProxyCfg, uint32_t orderId )
{
    
}

void CSL_secProxyCfg( CSL_SecProxyCfg *pSecProxyCfg, uint64_t targetAddr, uint64_t extBufferAddr )
{
    
}

int32_t CSL_secProxyCfgThread( CSL_SecProxyCfg *pSecProxyCfg, uint32_t threadNum, const CSL_SecProxyThreadCfg *pThreadCfg )
{
    int32_t retVal = 0;
    return retVal;
}

uintptr_t CSL_secProxyGetDataAddr( const CSL_SecProxyCfg *pSecProxyCfg, uint32_t threadNum, uint32_t numBytes )
{
    return NULL;
}

void CSL_secProxyAccessTarget( CSL_SecProxyCfg *pSecProxyCfg, uint32_t threadNum, uint8_t *pData, uint32_t numBytes, CSL_SecProxyMemAccessCbFxnPtr fpMemAccess )
{
    
}

int32_t CSL_secProxyGetThreadStatus( const CSL_SecProxyCfg *pSecProxyCfg, uint32_t threadNum, CSL_SecProxyThreadStatus *pThreadStatus )
{
    int32_t retVal = 0;
    return retVal;
}
