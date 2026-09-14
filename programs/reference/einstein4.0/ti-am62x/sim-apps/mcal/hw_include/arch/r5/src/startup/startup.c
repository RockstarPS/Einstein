/**
 * @file  startup.c
 *
 * @brief
 *  ARM R5 start-up code
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2024, Texas Instruments, Inc.
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
#include <startup.h>

/*  Declarations    */

__attribute__((section(".startupCode"))) void __mpu_init(void);
__attribute__((section(".startupCode"))) int _system_pre_init(void);
__attribute__((section(".startupCode")))  __attribute__((weak)) void _system_post_cinit(void);
__attribute__((section(".startupCode"))) void CSL_armR5MPUCfg(void);

__attribute__((section(".startupCode"))) static void _enable_mpu()
{
    
}

__attribute__((section(".startupCode"))) static void _enable_cache()
{

}

__attribute__((section(".startupCode"))) void CSL_armR5MPUCfg(void)
{
    
}

/*****************************************************************************/
/* \brief __MPU_INIT() - __mpu_init() is called in the C/C++ startup routine,*/
/* _c_int00(), and provides a mechanism for tailoring mpu init by device     */
/* prior to calling main().                                                  */
/*                                                                           */
/*****************************************************************************/
/*  Usage notes:
    On entry to this function from boot, R5F must be in System (privileged) mode. */
__attribute__((section(".startupCode")))  __attribute__((weak)) void __mpu_init(void)
{
    
}

/*****************************************************************************/
/* _SYSTEM_PRE_INIT() - _system_pre_init() is called in the C/C++ startup    */
/* routine (_c_int00()) and provides a mechanism for the user to             */
/* insert application specific low level initialization instructions prior   */
/* to calling main().  The return value of _system_pre_init() is used to     */
/* determine whether or not C/C++ global data initialization will be         */
/* performed (return value of 0 to bypass C/C++ auto-initialization).        */
/*                                                                           */
/* PLEASE NOTE THAT BYPASSING THE C/C++ AUTO-INITIALIZATION ROUTINE MAY      */
/* RESULT IN PROGRAM FAILURE.                                                */
/*                                                                           */
/*****************************************************************************/
extern uint32_t __BSS_START;
extern uint32_t __BSS_END;
__attribute__((section(".startupCode"))) int _system_pre_init(void)
{
    return 1;
}

/*****************************************************************************/
/* _SYSTEM_POST_CINIT() - _system_post_cinit() is a hook function called in  */
/* the C/C++ auto-initialization function after cinit() and before pinit().  */
/*                                                                           */
/*****************************************************************************/
__attribute__((section(".startupCode")))  __attribute__((weak)) void _system_post_cinit(void)
{

}

__attribute__((section(".startupCode"))) void CSL_armR5StartupGetCpuID( CSL_ArmR5CPUInfo *cpuInfo )
{

}

__attribute__((section(".startupCode"))) int32_t CSL_startupVimSetIntrEnable( CSL_vimRegs *pRegs, uint32_t intrNum, bool bEnable )
{
    int32_t  retVal = 0;
    return retVal;
}

__attribute__((section(".startupCode"))) int32_t CSL_startupVimClrIntrPending( CSL_vimRegs *pRegs, uint32_t intrNum )
{
    int32_t  retVal = 0;
    return retVal;
}
