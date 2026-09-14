/*
*
* Copyright (c) 2024 Texas Instruments Incorporated
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
 *  \file     Cdd_Ipc.c
 *
 *  \brief    This file implements CDD IPC service API's and reception interrupt
 *              handler
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "string.h"
#include "Cdd_Ipc.h"

#include "Cdd_IpcCfg.h"
#include "Cdd_IpcPriv.h"

#include <CddIpc/ipc_baremetal_hw/src/ipc_virtioPrivate.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

CONST(Cdd_IpcConfigType, CDD_IPC_CONFIG_DATA)
            CddIpcConfiguraions_PC;

/* ========================================================================== */
/*                          Local Function Prototypes                         */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

#if (STD_ON == CDD_IPC_VERSION_INFO_API)

/** \brief Return the version information of this implementation */
FUNC(void, CDD_IPC_CODE) Cdd_IpcGetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_APP_DATA) VersionInfoPtr)
{

}
#endif  /* #if (STD_ON == CDD_IPC_VERSION_INFO_API) */



/*
 * Design: MCAL-7153,MCAL-7178,MCAL-7184,MCAL-7221,MCAL-7160,MCAL-7166,MCAL-7236,MCAL-7153,MCAL-7154,MCAL-7166,MCAL-7170,MCAL-7178,MCAL-7184,MCAL-7200,MCAL-7221,MCAL-7232,MCAL-7236,MCAL-7175,MCAL-7233
 */

FUNC(void, CDD_IPC_CODE) Cdd_IpcInit(void)
{

}


/*
 * Design: MCAL-7160,MCAL-7168,MCAL-7242,MCAL-7169,MCAL-7226,MCAL-7225,MCAL-7205,MCAL-7177,MCAL-7168,MCAL-7169,MCAL-7177,MCAL-7205,MCAL-7225,MCAL-7226,MCAL-7242,MCAL-7195,MCAL-7238
 */

FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcSendMsg(
                                    VAR(uint32, AUTOMATIC) chId,
                                    P2CONST(void, AUTOMATIC, CDD_APP_DATA) pBuf,
                                    VAR(uint32, AUTOMATIC) bufLen)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    return (rtnVal);
}


/*
 * Design: MCAL-7160,MCAL-7151,MCAL-7174,MCAL-7162,MCAL-7193,MCAL-7235,MCAL-7176,MCAL-7151,MCAL-7162,MCAL-7174,MCAL-7176,MCAL-7193,MCAL-7235,MCAL-7195,MCAL-7201
 */

FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcReceiveMsg (
                            VAR(uint32, AUTOMATIC) chId,
                            P2VAR(void, AUTOMATIC, CDD_APP_DATA) pBuf,
                            P2VAR(uint32, AUTOMATIC, CDD_APP_DATA) bufLen)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    return (Std_ReturnType)rtnVal;
}


/*
 *  Design: MCAL-7167,MCAL-7228,MCAL-7244,MCAL-7201,MCAL-7191,MCAL-7167,MCAL-7244,MCAL-7228,MCAL-7191,MCAL-7203
 */

#if (STD_ON == CDD_IPC_ANNOUNCE_API)
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcReceiveCtrlMsg (
                        P2VAR (uint32, AUTOMATIC, CDD_APP_DATA) pRemoteProcId,
                        P2VAR (uint32, AUTOMATIC, CDD_APP_DATA) pRemoteEndPt,
                        P2VAR (void, AUTOMATIC, CDD_APP_DATA) pBuf,
                        P2VAR (uint32, AUTOMATIC, CDD_APP_DATA) bufLen)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    return (Std_ReturnType)rtnVal;
}

#endif /* (STD_ON == CDD_IPC_ANNOUNCE_API) */


/*
 * Design: MCAL-7160,MCAL-7241,MCAL-7246,MCAL-7219,MCAL-7217,MCAL-7155,MCAL-7211,MCAL-7155,MCAL-7211,MCAL-7217,MCAL-7219,MCAL-7240,MCAL-7241,MCAL-7246,MCAL-7230,MCAL-7213,MCAL-7201,MCAL-7202
 */

#if (STD_ON == CDD_IPC_ANNOUNCE_API)
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcAnnounce(
                                    P2CONST(UCHAR, AUTOMATIC, CDD_APP_DATA) pBuf,
                                    VAR(uint32, AUTOMATIC) chId)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    return (rtnVal);
}
#endif /* CDD_IPC_ANNOUNCE_API */


/*
 * Design: MCAL-4452,MCAL-7158,MCAL-7224
 */

#if (STD_ON == CDD_IPC_REGISTER_READBACK_API)
FUNC(Std_ReturnType, CDD_IPC_CODE)
                    Cdd_IpcRegisterReadBack(uint32 remoteProcId,
                    P2VAR(Cdd_IpcRegRbValues, AUTOMATIC, CDD_APP_DATA) pRegArgs)
{
    Std_ReturnType     retVal = ((Std_ReturnType) E_NOT_OK);
    return (retVal);

}
#endif /* CDD_IPC_REGISTER_READBACK_API */


/*
 * Design: MCAL-4453
 */

#if (STD_ON == CDD_IPC_IS_INIT_DONE_API)
FUNC(boolean, CDD_IPC_CODE) Cdd_IpcIsInitDone(void)
{
    boolean ipcInitDone = FALSE;
    return ipcInitDone;
}

#endif

#if (STD_ON == CDD_IPC_GET_MAX_MSG_SIZE_API)
FUNC(uint32, CDD_IPC_CODE) Cdd_IpcGetMaxMsgSize(VAR(uint32, AUTOMATIC) chId)
{
    uint32 maxMsgSize = 0U;
    return maxMsgSize;
}
#endif

/*
 * Design: MCAL-7150,MCAL-7163,MCAL-7164,MCAL-7173,MCAL-7215,MCAL-7223,MCAL-7214,MCAL-7210,MCAL-7234,MCAL-7180,MCAL-7237
 */

#if (STD_ON == CDD_IPC_SAFETY_DIAGNOSTIC_API)
FUNC(uint32, CDD_IPC_CODE) Cdd_IpcGetMailboxStatus(VAR(uint32, AUTOMATIC) remoteProcId)
{
      uint32 mailboxstatus = 0;
      return (mailboxstatus);
}
#endif /* CDDIPC_SAFETY_DIAGNOSTIC */

/* ========================================================================== */
/*                 Internal Function Implementation                           */
/* ========================================================================== */

#define CDD_IPC_STOP_SEC_ISR_CODE
#include "Cdd_Ipc_MemMap.h"

/********************************* End of file ******************************/
