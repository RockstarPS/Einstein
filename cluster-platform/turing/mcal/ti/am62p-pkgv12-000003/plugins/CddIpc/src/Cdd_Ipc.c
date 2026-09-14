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

/* AUTOSAR version information check has to match definition in header file */
#if ((CDD_IPC_AR_RELEASE_MAJOR_VERSION != (4U)) || \
    (CDD_IPC_AR_RELEASE_MINOR_VERSION != (3U)) ||  \
    (CDD_IPC_AR_RELEASE_REVISION_VERSION != (1U)))
    #error "Cdd Ipc: AUTOSAR Version Numbers of Cdd Ipc are different!!"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ((CDD_IPC_SW_MAJOR_VERSION != (11U)) || \
    (CDD_IPC_SW_MINOR_VERSION != (4U)) ||  \
    (CDD_IPC_SW_PATCH_VERSION != (0U)))
    #error "Cdd Ipc: Software Version Numbers are inconsistent!!"
#endif

#define CDD_IPC_MAX_CTRL_MSG_PER_CORE   (2U)
/**< Maximum of N messages that can queued, aps will have to drain this buffer
        Post that, the message would be lost */

/**
 * \brief Space to stored received CTRL messages.
 *      CDD_IPC_NUM_VRING_BUFF Messages
 *      Each message of size 496 bytes
 *      Size of RPMessage_MsgElem:32U
 *      RPMSG Object size, for managing message objects
 */
 #define CDD_IPC_RPMSG_CTRL_DATA_SIZE \
          ((CDD_IPC_NUM_VRING_BUFF *\
            (CDD_IPC_MAX_MSG_LENGTH + 32U)) \
          + CDD_IPC_RPMSG_OBJ_SIZE)

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

/*
 * Design: MCAL-7221,MCAL-7184
 */

#define CDD_IPC_START_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"
/** \brief CDD IPC Driver status. Can be initialized (TRUE) & uninitialized
            (FALSE) */
static volatile
            VAR(uint32, CDD_IPC_VAR_CLEARED) Cdd_IpcDrvStatus = (uint32)FALSE;

#define CDD_IPC_STOP_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"
/** \brief CDD IPC driver object */
static
            VAR(Cdd_IpcObjType, CDD_IPC_VAR_NO_INIT) Cdd_IpcDrvObj;

#define CDD_IPC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_VAR_NO_INIT_8
#include "Cdd_Ipc_MemMap.h"
static VAR(uint8, CDD_IPC_VAR_NO_INIT)
                        Cdd_IpcRpMsgCtrlBuffer[CDD_IPC_RPMSG_CTRL_DATA_SIZE];
#define CDD_IPC_STOP_SEC_VAR_NO_INIT_8
#include "Cdd_Ipc_MemMap.h"
/**
 * \brief A array of buffer pointers that describe memory allocated to local
 *          communication channels
 */
extern const struct Cdd_IpcChannelBufType_s
                            Cdd_IpcCommChanBufferPtr [CDD_IPC_MAX_CHANNEL_CFG];
/* ========================================================================== */
/*                          Local Function Prototypes                         */
/* ========================================================================== */
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_IpcCheckInitConfig(const Cdd_IpcConfigType *pCfg);
/**< Check PC configurations */
static Std_ReturnType Cdd_IpcCheckChConfig(const Cdd_IpcChannelType *pChCfgChk,
                                            uint32 channelCount);
/**< Check PC Channel Configurations */
#endif /* CDD_IPC_DEV_ERROR_DETECT */

static uint32 Cdd_IpcCriticalSectionIntEnter(void);
/**< Exclusive Area Enter */
static void Cdd_IpcCriticalSectionIntExit(uint32 keyNotUsed);
/**< Exclusive Area Exit */
static Std_ReturnType Cdd_IpcInitDepends(Cdd_IpcObjType *pDrvObj,
                                            const Cdd_IpcConfigType *pCfg);
/**< Initialize dependencies */
static Std_ReturnType Cdd_IpcInitVirtIoCtrlEp(Cdd_IpcObjType *pDrvObj,
                                            const Cdd_IpcConfigType *pCfg);
/**< Initialize, Cores, HISR and Exclusive access */
static Std_ReturnType Cdd_IpcInitRpMsgCtrl(Cdd_IpcObjType *pDrvObj);
/**< Initialize RP Messages and for control end point */

static Std_ReturnType Cdd_IpcInitEps(Cdd_IpcObjType *pDrvObj,
                                        const Cdd_IpcConfigType *pCfg);

static void Cdd_IpcNewMsgCb(uint32 srcEndPt, uint32 destEndPt, uint32 procId);
/**< New Message notification from EP and Source Processor ID */

#if defined(SOC_J722S) || defined(SOC_J721E) || defined(SOC_J721S2) ||defined(SOC_J742S2) ||defined(SOC_J784S4) ||defined(SOC_J7200)
uint32 gbShutdown = 0U;
/* Shutdown request from the remotecore */
uint8 Cdd_IpcAppMpu10Buffer[Cdd_IPC_MPU10_BUFFER_SIZE];
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

#if (STD_ON == CDD_IPC_VERSION_INFO_API)

/*
 * Design: MCAL-7206,MCAL-7179,MCAL-7157,MCAL-7160,MCAL-7179,MCAL-7206,MCAL-7207
 */

/** \brief Return the version information of this implementation */
FUNC(void, CDD_IPC_CODE) Cdd_IpcGetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_APP_DATA) VersionInfoPtr)
{
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (NULL_PTR == VersionInfoPtr)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                        CDD_IPC_SID_GETVERSIONINFO, CDD_IPC_E_PARAM_POINTER);
    }
    else
#endif  /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */
    {
        VersionInfoPtr->vendorID            = CDD_IPC_VENDOR_ID;
        VersionInfoPtr->moduleID            = CDD_IPC_MODULE_ID;
        VersionInfoPtr->sw_major_version    = (uint8) CDD_IPC_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version    = (uint8) CDD_IPC_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version    = (uint8) CDD_IPC_SW_PATCH_VERSION;
    }

    return;
}
#endif  /* #if (STD_ON == CDD_IPC_VERSION_INFO_API) */

#if defined(SOC_J722S) || defined(SOC_J721E) || defined(SOC_J721S2) ||defined(SOC_J742S2) ||defined(SOC_J784S4) ||defined(SOC_J7200)
static void Cdd_IpcRpMboxCallback(uint32 remoteCoreId, uint32 msgVal)
{

    if (msgVal == IPC_RP_MBOX_SHUTDOWN) /* Shutdown request from the remotecore */
    {
            gbShutdown = 1U;
            RPMessage_unblock((RPMessage_Handle)&Cdd_IpcAppMpu10Buffer[0]);
            #if defined(SOC_J722S)
            Ipc_resetCoreVirtIO(IPC_A53SS0_0);
            #else
            Ipc_resetCoreVirtIO(IPC_MPU1_0);
            #endif

            
            
    }
}
#endif

#if defined(SOC_J722S) || defined(SOC_J721E) || defined(SOC_J721S2) ||defined(SOC_J742S2) ||defined(SOC_J784S4) ||defined(SOC_J7200)
 FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcgbShutdownRequest(void)
 {
    Std_ReturnType rtnVal = E_NOT_OK;
    if(gbShutdown == 1U)
    {
        rtnVal = E_OK;   
    }
    return rtnVal;
 }
#endif


/*
 * Design: MCAL-7153,MCAL-7178,MCAL-7184,MCAL-7221,MCAL-7160,MCAL-7166,MCAL-7236,MCAL-7153,MCAL-7154,MCAL-7166,MCAL-7170,MCAL-7178,MCAL-7184,MCAL-7200,MCAL-7221,MCAL-7232,MCAL-7236,MCAL-7175,MCAL-7233
 */

FUNC(void, CDD_IPC_CODE) Cdd_IpcInit(void)
{
    Std_ReturnType rtnVal = E_NOT_OK;

    /* Only Pre Compile variant supported */
    const Cdd_IpcConfigType *pCfg = &CddIpcConfiguraions_PC;
    /**
     * \warning : Don't reset Mailbox IP. An entity out-side will reset and
     *              this driver is initialized.
     */



#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) != Cdd_IpcDrvStatus)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_INIT, CDD_IPC_E_ALREADY_INITIALIZED);
    }
    else
    {
        if ((Std_ReturnType)E_OK == Cdd_IpcCheckInitConfig(pCfg))
        {
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */

            /* Steps
                1. Build the required tables, proc names, etc...
                2. Initialize VirtIO, with provided VRING Address
                3. Create RP Messages for all end points
            */
            rtnVal = Cdd_IpcInitDepends(&Cdd_IpcDrvObj, pCfg);
            /**
            * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for the  'false'
            Is not achievable as Cdd_IpcInitDepends alwasy return E_OK.

            * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
            */

            if ((Std_ReturnType)E_OK == rtnVal)
            {
                rtnVal = Cdd_IpcInitVirtIoCtrlEp(&Cdd_IpcDrvObj, pCfg);
            }
            /* TI_COVERAGE_GAP_STOP */
            if ((Std_ReturnType)E_OK == rtnVal)
            {
                rtnVal = Cdd_IpcInitEps(&Cdd_IpcDrvObj, pCfg);
            }

            if ((Std_ReturnType)E_OK == rtnVal)
            {
                /* Everything went well, we are initialized now!!! */
                Cdd_IpcDrvStatus = (uint32) TRUE;
            }

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
            else
            {
                (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_INIT, CDD_IPC_E_INIT_FAILED);
            }

        }
        else
        {
            (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_INIT, CDD_IPC_E_INVALID_CONFIG);
        }
    }
#endif /* CDD_IPC_DEV_ERROR_DETECT */
    return;
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
    uint32 remoteEndPt, remoteProcId, ownEp;
    const Cdd_IpcChannelType *pChanCfg = CddIpcConfiguraions_PC.pChCfg;
    sint32 status;

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Cdd_IpcDrvStatus)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_SEND, CDD_IPC_E_UNINIT);
    }
    else if ((CddIpcConfiguraions_PC.channelCount <= chId) ||
             (NULL_PTR == pBuf))
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_SEND, CDD_IPC_E_PARAM_POINTER);
    }
    else if ((0U == bufLen) || (CDD_IPC_MAX_MSG_LEN < bufLen))
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_SEND, CDD_IPC_E_NOT_SUPPORTED);
    }
    else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */

    {

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
        /* Ensure the commId do match */
        if (chId != pChanCfg[chId].id)
        {
            (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_SEND, CDD_IPC_E_INVALID_CONFIG);
        }
        else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */
        {
            remoteProcId = pChanCfg[chId].remoteProcId;
            remoteEndPt = Cdd_IpcDrvObj.mapToCommId[remoteProcId][chId].remoteEp;
            ownEp = pChanCfg[chId].localEp;

            status = MCAL_RPMessage_send(Cdd_IpcDrvObj.rpmsgHndl[chId],
                                            remoteProcId, remoteEndPt, ownEp,
                                            (Ptr)pBuf, (uint16)bufLen);
            if (IPC_SOK == status)
            {
                rtnVal = (Std_ReturnType)E_OK;
            }
            else
            {
#ifdef CDD_IPC_E_HARDWARE_ERROR
                (void)Dem_SetEventStatus(CDD_IPC_E_HARDWARE_ERROR,
                    DEM_EVENT_STATUS_FAILED);
#endif /* CDD_IPC_E_HARDWARE_ERROR != CDD_IPC_DEM_NO_EVENT */
                rtnVal = (Std_ReturnType)(IPC_SOK - status);
            }
        }
    }
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
    uint32 remoteEndPt, remoteProcId;
    const Cdd_IpcChannelType *pChanCfg = CddIpcConfiguraions_PC.pChCfg;
    sint32 status;
    #if defined(SOC_AM62X) || defined(SOC_AM62AX) || defined(SOC_AM62DX) || defined(SOC_AM275X) || defined(SOC_AM62PX) || defined(SOC_J722S)
	uint32 allocBufLen;
	#endif
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Cdd_IpcDrvStatus)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_RECEIVE, CDD_IPC_E_UNINIT);
    }
    else if ((CddIpcConfiguraions_PC.channelCount <= chId) ||
             (NULL_PTR == pBuf))
                /* FixMe 512 should come out from the configurator */
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_RECEIVE, CDD_IPC_E_PARAM_POINTER);
    }
    else if (NULL_PTR == bufLen)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_RECEIVE, CDD_IPC_E_NOT_SUPPORTED);
    }
    else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */
    {

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
        /* Ensure the commId do match */
        if (chId != pChanCfg[chId].id)
        {
            (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_RECEIVE, CDD_IPC_E_INVALID_CONFIG);
        }
        else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */
        {
            /*
                1. Get the associated RemoteEp & RemoteProc
                2. Initiate the transfer
            */
            remoteProcId = pChanCfg[chId].remoteProcId;
            remoteEndPt = Cdd_IpcDrvObj.mapToCommId[remoteProcId][chId].remoteEp;
#if defined(SOC_AM62X) || defined(SOC_AM62AX) || defined(SOC_AM62DX) || defined(SOC_AM275X) || defined(SOC_AM62PX) || defined(SOC_J722S)
			allocBufLen  = IPC_MAX_DATA_PAYLOAD;
#endif
                status = RPMessage_recvNb(Cdd_IpcDrvObj.rpmsgHndl[chId],
                    (void*) pBuf, bufLen,
                    &remoteEndPt, &remoteProcId,FALSE);

            if (IPC_SOK == status)
            {
#if defined(SOC_AM62X) || defined(SOC_AM62AX) || defined(SOC_AM62DX) || defined(SOC_AM275X) || defined(SOC_AM62PX) || defined(SOC_J722S)
			    /* Error check added to ensure that the received
                 * message size is less than the maximum message
                 * size, i.e. 496 bytes
                 * Total message length = 496U(Message payload) + 16U(RPMsg header)
                 * https://jira.itg.ti.com/browse/MCAL-8020 */

 
                if (allocBufLen < *bufLen)
                {
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
                    (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                                    CDD_IPC_SID_RECEIVE, CDD_IPC_E_INVALID_CONFIG);
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */
                    rtnVal = (Std_ReturnType)E_NOT_OK;
                }        
                /**
                 * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage ELSE condition cannot be covered as allocBufLen is always greater than bufLen .

                * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
                */
                else
                {
#endif
				  Cdd_IpcDrvObj.mapToCommId[remoteProcId][chId].remoteEp = remoteEndPt;
                  rtnVal = (Std_ReturnType)E_OK;
#if defined(SOC_AM62X) || defined(SOC_AM62AX) || defined(SOC_AM62DX) || defined(SOC_AM275X) || defined(SOC_AM62PX) || defined(SOC_J722S)
			    }
                /* TI_COVERAGE_GAP_STOP */
#endif
            }
            /**
            * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage else condition cannot as IPC Status is always OK .

            * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
            */
            else
            {
                /* No DET required here, as apps could call this function
                    anytime after initialization */
                 /* convert returned negative error to positive 
                    Std_ReturnType */
                 rtnVal = (Std_ReturnType)(IPC_SOK - status);
            }
            /* TI_COVERAGE_GAP_STOP */
        }
    }

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
    Cdd_IpcAnnouncement ctrlMsg;

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Cdd_IpcDrvStatus)
    /**
     * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage is not achievable because Cdd_IpcDrvStatus is already initilized .
    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_CTRL_RECEIVE, CDD_IPC_E_UNINIT);
    }
    /* TI_COVERAGE_GAP_STOP */
    else if ((NULL_PTR == pBuf) || (0U == bufLen))
    /**
     * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage is not achievable because this false case are already checked previously ,so this cannot be reproduced .
     * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
     */
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_CTRL_RECEIVE, CDD_IPC_E_PARAM_POINTER);
    }
    /* TI_COVERAGE_GAP_STOP */
    else if ((NULL_PTR == pRemoteProcId) || (0U == pRemoteEndPt))
    /**
     * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage is not achievable because this false case are already checked previously ,so this cannot be reproduced .

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_CTRL_RECEIVE, CDD_IPC_E_PARAM_POINTER);
    }
    /* TI_COVERAGE_GAP_STOP */
    else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */

    /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for the function Cdd_IpcReceiveCtrlMsg() is not achievable because RPMessage_recvNb()always returns IPC_SOK in existing test/hardware configs, so the error-path else branch is not exercised.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */

    {
        if (IPC_SOK == RPMessage_recvNb(Cdd_IpcDrvObj.ctrlRpmsgHndl,
                                        (Ptr)&ctrlMsg, bufLen,
                                        pRemoteEndPt, pRemoteProcId,TRUE))
        {
            rtnVal = (Std_ReturnType)E_OK;
            memcpy((void*)pBuf, (void*)&ctrlMsg.name[0U], CDD_IPC_MAX_CTRL_MSG_LEN);
            *pRemoteEndPt = ctrlMsg.endPt;
            *bufLen = CDD_IPC_MAX_CTRL_MSG_LEN;
        }
        else
        {
            /* No DET required here, as apps could call this function
                anytime after initialization */
            rtnVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    /* TI_COVERAGE_GAP_STOP */

    return (Std_ReturnType)rtnVal;
}

#endif /* (STD_ON == CDD_IPC_ANNOUNCE_API) */


/*
 * Design: MCAL-7160,MCAL-7241,MCAL-7246,MCAL-7219,MCAL-7217,MCAL-7155,MCAL-7211,MCAL-7155,MCAL-7211,MCAL-7217,MCAL-7219,MCAL-7240,MCAL-7241,MCAL-7246,MCAL-7230,MCAL-7213,MCAL-7201,MCAL-7202
 */

#if (STD_ON == CDD_IPC_ANNOUNCE_API)
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcAnnounce(
                                    P2CONST(uint8, AUTOMATIC, CDD_APP_DATA) pBuf,
                                    VAR(uint32, AUTOMATIC) chId)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    uint32 ownEp, procId;
    const Cdd_IpcChannelType *pChanCfg = CddIpcConfiguraions_PC.pChCfg;

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Cdd_IpcDrvStatus)
    /**
     * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage is not achievable because Cdd_IpcDrvStatus is already initilized .
     * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
     */
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_ANNOUNCE, CDD_IPC_E_UNINIT);
    }
    /* TI_COVERAGE_GAP_STOP */
    else if ((NULL_PTR == pBuf))
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_ANNOUNCE, CDD_IPC_E_PARAM_POINTER);
    }
    else if (chId >= CddIpcConfiguraions_PC.channelCount)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_ANNOUNCE, CDD_IPC_E_INVALID_CONFIG);
    }
    else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */

    {
        ownEp = pChanCfg[chId].localEp;
        procId = pChanCfg[chId].remoteProcId;
        /**
         * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for the
         * function Cdd_IpcAnnounce() is not achievable because MCAL_RPMessage_announce()
         * there is no test case avaialable to cover it .
         *
         * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed
         * from inspection review. The function still behaves correctly for validated
         * error path.
         */
        if (IPC_SOK == MCAL_RPMessage_announce(procId, ownEp,
                                             (const uint8 *)pBuf))
        {
            rtnVal = (Std_ReturnType)E_OK;
        }
        /* TI_COVERAGE_GAP_STOP */
#ifdef CDD_IPC_E_HARDWARE_ERROR
        else
        /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for else can only be reproduced by real time HW faults.

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
        {
            (void)Dem_SetEventStatus(CDD_IPC_E_HARDWARE_ERROR,
                DEM_EVENT_STATUS_FAILED);
        }
        /* TI_COVERAGE_GAP_STOP */
#endif /* CDD_IPC_E_HARDWARE_ERROR != CDD_IPC_DEM_NO_EVENT */

    }
    return (rtnVal);
}
#endif /* CDD_IPC_ANNOUNCE_API */


/*
 * Design: MCAL-4452,MCAL-7224
 */

#if (STD_ON == CDD_IPC_REGISTER_READBACK_API)
FUNC(Std_ReturnType, CDD_IPC_CODE)
                    Cdd_IpcRegisterReadBack(uint32 remoteProcId,
                    P2VAR(Cdd_IpcRegRbValues, AUTOMATIC, CDD_APP_DATA) pRegArgs)
{
    Std_ReturnType     retVal = ((Std_ReturnType) E_NOT_OK);
  #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (FALSE == Cdd_IpcDrvStatus)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                          CDD_IPC_SID_REG_READBACK, CDD_IPC_E_UNINIT);
    }
    else if  (NULL_PTR == pRegArgs )
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                              CDD_IPC_SID_REG_READBACK, CDD_IPC_E_PARAM_POINTER);
    }
    else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */
      {
        /**
         * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for the function Cdd_IpcRegisterReadBack() is not covered because currently there is no test case to cover it.
         *
         * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from inspection review. 
         */
        (void) memset(pRegArgs, 0, sizeof (Cdd_IpcRegRbValues));
         retVal = IpcRegisterReadBack(remoteProcId,pRegArgs);
        /* TI_COVERAGE_GAP_STOP */
      }


    return (retVal);

}
#endif /* CDD_IPC_REGISTER_READBACK_API */


/*
 * Design: MCAL-4453
 */

#if (STD_ON == CDD_IPC_IS_INIT_DONE_API)
FUNC(boolean, CDD_IPC_CODE) Cdd_IpcIsInitDone(void)
{
    boolean ipcInitDone;

    if (TRUE == Cdd_IpcDrvStatus)
    {
        ipcInitDone = TRUE;
    }
    else
    {
        ipcInitDone = FALSE;
    }

    return ipcInitDone;
}

#endif

#if (STD_ON == CDD_IPC_GET_MAX_MSG_SIZE_API)
FUNC(uint32, CDD_IPC_CODE) Cdd_IpcGetMaxMsgSize(VAR(uint32, AUTOMATIC) chId)
{
    uint32 maxMsgSize;
    Std_ReturnType rtnVal = (Std_ReturnType)E_OK;

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (CddIpcConfiguraions_PC.channelCount <= chId)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                        CDD_IPC_SID_GET_MAX_MSG_SIZE, CDD_IPC_E_PARAM_POINTER);
        rtnVal = E_NOT_OK;
    }
#endif
    if (E_OK == rtnVal)
    {
        maxMsgSize = CddIpcConfiguraions_PC.pChCfg[chId].maxMsgSize;

    }
    else
    {
        maxMsgSize = 0;
    }
    return maxMsgSize;
}
#endif

/*
 * Design: MCAL-7150,MCAL-7163,MCAL-7164,MCAL-7173,MCAL-7215,MCAL-7223,MCAL-7214,MCAL-7210,MCAL-7234,MCAL-7180,MCAL-7237
 */

 /* This feature is not supported */
#if (STD_ON == CDD_IPC_SAFETY_DIAGNOSTIC_API)
FUNC(uint32, CDD_IPC_CODE) Cdd_IpcGetMailboxStatus(VAR(uint32, AUTOMATIC) remoteProcId)
{
      uint32 mailboxstatus = 0;

  #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
	  uint32 remote_valid = (uint32)FALSE;
      uint32 coreIdx = 0, rCoreId = 0;
      /* Ensure the commId do match */
      for (coreIdx = 0U; coreIdx < CddIpcConfiguraions_PC.coreIds.numProcs;
           coreIdx++)
      {
          rCoreId = CddIpcConfiguraions_PC.coreIds.remoteProcID[coreIdx];
          if (rCoreId == remoteProcId)
          /**
           * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for false is  not achievable because rCoreId is always valid remoteProcId in configuration .
           
           * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
           */
          {
            remote_valid = TRUE;
            break;
          }
          /* TI_COVERAGE_GAP_STOP */
      }
      if (((uint32) FALSE) == Cdd_IpcDrvStatus)
    /**
     * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage is not achievable because Cdd_IpcDrvStatus is already initilized .
     * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
     */
      {
          (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                              CDD_IPC_SID_MAILBOX_STATE, CDD_IPC_E_UNINIT);
      }
      /* TI_COVERAGE_GAP_STOP */

      else if ((remote_valid == FALSE) || (CDD_IPC_CORE_ID_MAX < remoteProcId))
      {
          (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                          CDD_IPC_SID_MAILBOX_STATE, CDD_IPC_E_INVALID_CONFIG);
      }
      else
  #endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */
      {

          mailboxstatus = Ipc_mailboxGetStatus((uint32) remoteProcId);
      }
      return (mailboxstatus);
}
#endif /* CDDIPC_SAFETY_DIAGNOSTIC */

/* ========================================================================== */
/*                 Internal Function Implementation                           */
/* ========================================================================== */

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_IpcCheckChConfig(const Cdd_IpcChannelType *pChCfgChk,
                                        uint32 channelCount)
{
    uint32 idx;
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    if (NULL_PTR != pChCfgChk)
    {
        rtnVal = (Std_ReturnType)E_OK;
        for (idx = 0U; ((idx < channelCount) &&
                        ((Std_ReturnType)E_OK == rtnVal)); idx++)
        {

            /**
             * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for the as the the function Cdd_IpcCheckChConfig() has a hardcoded value for rtnVal = E_OK. So, the MC/DC condition for rtnVal = False will never occur.

            * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
            */
            if ((CDD_IPC_RESERVED_END_POINT == pChCfgChk[idx].localEp) ||
                (CDD_IPC_RESERVED_END_POINT == pChCfgChk[idx].remoteEp))

            {
                rtnVal = (Std_ReturnType)E_NOT_OK;
            }
            /* TI_COVERAGE_GAP_STOP */
        }
    }

    return (rtnVal);
}

static Std_ReturnType Cdd_IpcCheckInitConfig(const Cdd_IpcConfigType *pCfg)
{
    /* Checks
        MP : coreIds
            1. numProcs < CDD_IPC_CORE_ID_MAX
            2. ownProcID should be < CDD_IPC_CORE_ID_MAX
        VirtIO  : vertIoCfg
            1. vertIoRingAddr is not NULL
        Comm Channels : channelCount, pChCfg
            2. localEp and remoteEp should not be 53
    */

    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    if (NULL_PTR != pCfg)
    {

        if ((CDD_IPC_CORE_ID_MAX <= pCfg->coreIds.numProcs) ||
            (CDD_IPC_CORE_ID_MAX <= pCfg->coreIds.ownProcID))
        {
            rtnVal = (Std_ReturnType)E_NOT_OK;
        }
        /**
         * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for the function Cdd_IpcCheckInitConfig() is not achievable because vertIoRingAddr is
           always provided (non-NULL) in existing test configurations, so the error-path else if branch for NULL vertIoRingAddr is not exercised.
         
         * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from inspection review.
         */
        else if (NULL_PTR == pCfg->vertIoCfg.vertIoRingAddr)
        {
            rtnVal = (Std_ReturnType)E_NOT_OK;
        }
        /* TI_COVERAGE_GAP_STOP */

        /**
         * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for the  function Cdd_IpcCheckInitConfig() is not
           achievable because pChCfg is always provided (non-NULL) in existing test configurations, so the error-path
           else if branch for NULL pChCfg is not exercised.

         * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed
           from inspection review.
        */
        else if (NULL_PTR == pCfg->pChCfg)
        {
            rtnVal = (Std_ReturnType)E_NOT_OK;
        }
        /* TI_COVERAGE_GAP_STOP */
        else
        {
            rtnVal = Cdd_IpcCheckChConfig(pCfg->pChCfg, pCfg->channelCount);
        }
    }
    return ((Std_ReturnType)rtnVal);
}
#endif /* CDD_IPC_DEV_ERROR_DETECT */

static uint32 Cdd_IpcCriticalSectionIntEnter(void)
{
    SchM_Enter_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0();
    return (uint32)1U;
}

static void Cdd_IpcCriticalSectionIntExit(uint32 keyNotUsed)
{
    SchM_Exit_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0();
}


static sint32 Cdd_IpcHIsrCreate(Ipc_OsalHIsrHandle *handle,
                                    Ipc_OsalHIsrFxn fxn, void *arg)
{
    sint32 rtnVal = IPC_EBADARGS;

    /* No HISR, HISR would be invoked in ISR context it self */

    /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for the false part as the parameters to the function Cdd_IpcHIsrCreate(Ipc_OsalHIsrHandle *handle,
         Ipc_OsalHIsrFxn fxn, void *arg) cannot be controlled. So the branch coverage for   all the conditions to be False cannot not covered./

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */

    if ((NULL != handle) && ((NULL != fxn) && (NULL != arg)))
    {
        handle->arg0    = (uint32) arg;
        handle->arg1    = (uint32) NULL;
        handle->hIsrFxn = fxn;
        handle->hLosHisrHandle = NULL;
        rtnVal = IPC_SOK;
    }
    /* TI_COVERAGE_GAP_STOP */

    return (rtnVal);
}


/**
* TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch cannot be coveraged as the  User has no access to the arguments of the function Cdd_IpcHIsrDelete(Ipc_OsalHIsrHandle *handle). There are checks for Null pointer before calling this function

* TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
*/
static void Cdd_IpcHIsrDelete(Ipc_OsalHIsrHandle *handle)
{
    if (NULL != handle)
    {
        handle->arg0    = (uint32) NULL;
        handle->arg1    = (uint32) NULL;
        handle->hIsrFxn = NULL;
        handle->hLosHisrHandle = NULL;
    }

    return;
}
/* TI_COVERAGE_GAP_STOP */

static sint32 Cdd_IpcHIsrPost(Ipc_OsalHIsrHandle *handle)
{
    sint32 rtnVal = IPC_EBADARGS;

    if (NULL != handle)
    {
        handle->hIsrFxn(handle->arg0, (uint32) NULL);
        rtnVal = IPC_SOK;
    }
    return (rtnVal);
}

/**CDD_IPC_CoverageGap_05: 1. It is a static function.
 * 2. User has no access to the arguments of the function
 * Cdd_IpcHIsrGateDelete(Ipc_OsalHIsrGateHandle *handle).
 * here are checks for Null pointer before calling this function.*/


 static void *Cdd_IpcHIsrGateCreate(void)
{
    /* Really!!, nothing required as rely on interrupt locking for exclusive
        access. */
    return (void *) 1U;
}

static void Cdd_IpcHIsrGateDelete(Ipc_OsalHIsrGateHandle *handle)
{
    /* Really!!, nothing required as rely on interrupt locking for exclusive
        access. */
    return;
}

static sint32 Cdd_IpcHIsrGateEnter(Ipc_OsalHIsrGateHandle handle)
{
    /* Really!!, nothing required as rely on interrupt locking for exclusive
        access. */
    return ((sint32)Cdd_IpcCriticalSectionIntEnter());
}

static void Cdd_IpcHIsrGateExit(Ipc_OsalHIsrGateHandle handle, sint32 key)
{
    /* Really!!, nothing required as rely on interrupt locking for exclusive
        access. */
    Cdd_IpcCriticalSectionIntExit(key);
    return;
}

static Std_ReturnType Cdd_IpcInitDepends(Cdd_IpcObjType *pDrvObj,
                                            const Cdd_IpcConfigType *pCfg)
{
    Std_ReturnType rtnVal = E_NOT_OK;
    Ipc_InitPrms initPrms;
    uint32 procIdx, commIdx;
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if ((NULL_PTR != pDrvObj) && (NULL_PTR != pCfg))
#endif /* (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */

    {
        /*  1. Init Core Names
            2. Init HISR and It's dependencies
            3. Linkup local cb for new msg notification
            4. Initialize mapToCommId to un-mapped state
        */
        if (IPC_SOK == Ipc_mpSetConfig(pCfg->coreIds.ownProcID,
                                    (uint32)pCfg->coreIds.numProcs,
                                    (uint32 *)&pCfg->coreIds.remoteProcID[0U]))
        {
            rtnVal = (Std_ReturnType)E_OK;

            IpcInitPrms_init(0U, &initPrms);

            initPrms.instId = 0U;
            initPrms.osalPrms.disableAllIntr = &Cdd_IpcCriticalSectionIntEnter;
            initPrms.osalPrms.restoreAllIntr = &Cdd_IpcCriticalSectionIntExit;

            initPrms.osalPrms.createHIsr    = &Cdd_IpcHIsrCreate;
            initPrms.osalPrms.deleteHIsr    = &Cdd_IpcHIsrDelete;
            initPrms.osalPrms.postHIsr      = &Cdd_IpcHIsrPost;
            initPrms.osalPrms.createHIsrGate = &Cdd_IpcHIsrGateCreate;
            initPrms.osalPrms.deleteHIsrGate = &Cdd_IpcHIsrGateDelete;
            initPrms.osalPrms.lockHIsrGate   = &Cdd_IpcHIsrGateEnter;
            initPrms.osalPrms.unLockHIsrGate = &Cdd_IpcHIsrGateExit;


            initPrms.newMsgFxn = &Cdd_IpcNewMsgCb;

            #if defined(SOC_J721E) || defined(SOC_J7200) || defined(SOC_J721S2) || defined(SOC_J784S4) || defined(SOC_J742S2) || defined(SOC_J722S)
            initPrms.rpMboxMsgFxn = &Cdd_IpcRpMboxCallback;
            #else
            initPrms.rpMboxMsgFxn = NULL;
            #endif
             


            /* CDD_IPC_CoverageGap_06: 1. It is a static function.
             * 2. The condition   if (IPC_SOK != Ipc_init(&initPrms))
             * is checked after the assignment of initPrms. So it will not be NULL*/
            if (IPC_SOK != Ipc_init(&initPrms))
            {
                rtnVal = E_NOT_OK;
            }
        }
        if ((Std_ReturnType)E_OK == rtnVal)
        {
            for (procIdx = 0U; procIdx < CDD_IPC_CORE_USED; procIdx++)
            {
                for (commIdx = 0U; commIdx < CDD_IPC_MAX_CHANNEL_CFG; commIdx++)
                {
                    pDrvObj->mapToCommId[procIdx][commIdx].isValid  = 0U;
                    pDrvObj->mapToCommId[procIdx][commIdx].remoteEp =
                                                    0xFFFFFFFFU;
                    pDrvObj->mapToCommId[procIdx][commIdx].commChId   =
                                                    0xFFFFFFFFU;
                }
            }
        }
    }

    return (rtnVal);
}

static Std_ReturnType Cdd_IpcInitVirtIoCtrlEp(Cdd_IpcObjType *pDrvObj,
                                            const Cdd_IpcConfigType *pCfg)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_OK;

    Ipc_VirtIoParams  vqParam;

    vqParam.vqObjBaseAddr = (void*) &Cdd_IpcDrvVertIoObj[0U];
    vqParam.vqBufSize     = CDD_IPC_VERTIO_OBJECT_SIZE;

    vqParam.vringBaseAddr = pCfg->vertIoCfg.vertIoRingAddr;
    vqParam.vringBufSize  = pCfg->vertIoCfg.vertIoRingSize;
    vqParam.timeoutCnt    = CDD_IPC_MAX_RETRY_NOTIFY;
                            /* When the MBX FIFO is full, number of iterations
                               to wait before giving up */
    if (IPC_SOK != Ipc_initVirtIO(&vqParam))
    {
        rtnVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        rtnVal = Cdd_IpcInitRpMsgCtrl(&Cdd_IpcDrvObj);
    }

    return (rtnVal);
}


static Std_ReturnType Cdd_IpcInitRpMsgCtrl(Cdd_IpcObjType *pDrvObj)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;

    /**CDD_IPC_CoverageGap_07: 1. It is a static function.
     * 2. The function Cdd_IpcInitRpMsgCtrl() is called after assignment of the
     * Cdd_IpcDrvObj so it will not have a NULL_PTR.*/
    if (NULL_PTR != pDrvObj)
    {
        RPMessage_Params ctrlParam;
        (void)RPMessageParams_init(&ctrlParam);

        /* Override the default */
        ctrlParam.numBufs     = CDD_IPC_MAX_CTRL_MSG_PER_CORE;

        ctrlParam.buf         = &Cdd_IpcRpMsgCtrlBuffer[0U];
        ctrlParam.bufSize     = CDD_IPC_RPMSG_CTRL_DATA_SIZE;
        ctrlParam.stackBuffer = NULL;
        ctrlParam.stackSize   = 0U;
        (void)MCAL_RPMessage_init(&ctrlParam);

#if (STD_ON == CDD_IPC_ANNOUNCE_API)
        ctrlParam.requestedEndpt = IPC_CTRL_ENDPOINT_ID;

        pDrvObj->ctrlRpmsgHndl = RPMessage_create(&ctrlParam, &pDrvObj->ctrlEp);
        if (NULL_PTR != pDrvObj->ctrlRpmsgHndl)
        {
            rtnVal = (Std_ReturnType)E_OK;
        }
#else
        /* Dont require the control end point */
        rtnVal = (Std_ReturnType)E_OK;
#endif /* #if (STD_ON == CDD_IPC_ANNOUNCE_API) */

    }

    return (rtnVal);
}


/*
 * Design: MCAL-7154,MCAL-7229,MCAL-7223,MCAL-7213,MCAL-7231,MCAL-7194,MCAL-7218,MCAL-7212
 */
/* CDD_IPC_CoverageGap_08: 1. It is a static function.
 * 2. The function Cdd_IpcInitEps(Cdd_IpcObjType *pDrvObj, const Cdd_IpcConfigType *pCfg)
 * is called after assignment of the Cdd_IpcDrvObj so it will not have a NULL_PTR.*/
static Std_ReturnType Cdd_IpcInitEps(Cdd_IpcObjType *pDrvObj,
                                        const Cdd_IpcConfigType *pCfg)
{
    uint32 idx;
    RPMessage_Params    params;
    uint32              myEndPt, rProcId, chId;
    const Cdd_IpcChannelType    *pChCfg = pCfg->pChCfg;
    Std_ReturnType  rtnVal = (Std_ReturnType)E_OK;

    for (idx = 0U; ((idx < pCfg->channelCount) &&
                    ((Std_ReturnType)E_OK == rtnVal)); idx++)
    {
        (void)RPMessageParams_init(&params);
        params.requestedEndpt   = pChCfg[idx].localEp;
        params.numBufs          = pChCfg[idx].numMsgQueued;
        params.buf              = Cdd_IpcCommChanBufferPtr[idx].pBuf;
        params.bufSize          = Cdd_IpcCommChanBufferPtr[idx].bufSize;

        pDrvObj->rpmsgHndl[idx] = RPMessage_create(&params, &myEndPt);
        if (NULL_PTR == pDrvObj->rpmsgHndl[idx])
        {
        /**CDD_IPC_CoverageGap_09: 1. It is a static function so cannot be covered.
         * 2. This function is called only if the arguments are not Null. There are already checks
         * for Null pointer in Cdd_IpcInitEps().*/
            rtnVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    /* Map commId to Ep */
    for (idx = 0U; ((idx < pCfg->channelCount) &&
                    ((Std_ReturnType)E_OK == rtnVal)); idx++)
    {
        rProcId     = pChCfg[idx].remoteProcId;
        chId        = pChCfg[idx].id;
        pDrvObj->mapToCommId[rProcId][chId].commChId = chId;
        pDrvObj->mapToCommId[rProcId][chId].remoteEp = pChCfg[idx].remoteEp;
        /* Some positive integer value, 0 is for invalid */
        pDrvObj->mapToCommId[rProcId][chId].isValid  = 1U;
    }

    /* Enable interrupts now */
    for (idx = 0U; idx < pCfg->coreIds.numProcs; idx++)
    {
        Ipc_mailboxEnableNewMsgInt((uint32)pCfg->coreIds.ownProcID,
                                        (uint32)pCfg->coreIds.remoteProcID[idx]);
    }

    return rtnVal;
}

#if defined(SOC_J722S) || defined(SOC_J721E) || defined(SOC_J721S2) ||defined(SOC_J742S2) ||defined(SOC_J784S4) ||defined(SOC_J7200)
FUNC(sint32, CDD_IPC_CODE) Cdd_Ipc_Send_Ack(uint32 selfId, uint32 remoteProcId, uint32 val,
                 uint32 timeoutCnt) {
  sint32 retVal = IPC_SOK;

  retVal = Ipc_mailboxSend(selfId, remoteProcId, val, timeoutCnt);
  return retVal;
}
#endif

FUNC(void, CDD_IPC_CODE) Cdd_Ipc_mailboxDisableMsg(uint16 selfId, uint16 remoteProcId)

{
  Ipc_mailboxDisableNewMsgInt(selfId, remoteProcId);
}


#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_ISR_CODE
#include "Cdd_Ipc_MemMap.h"

/*
 * Design: MCAL-7208,MCAL-7220
 */
static void Cdd_IpcNewMsgCb(uint32 srcEndPt, uint32 destEndPt, uint32 procId)
{
    uint32 idx = 0;

    if(CDD_IPC_CORE_ID_MAX > procId){
#if !defined (SOC_AM275X)
        /* If remote core is Linux perform comparison with destEndPt as
         * Linux core changes the srcEndPt during run time in the RPMsgHeader
         * and it can have any value
         */
        if(TRUE == Virtio_isRemoteLinux((uint16)procId)){
            /* Execute control message in case message is received on control
             * end point 53
             */
            if((IPC_CTRL_ENDPOINT_ID == srcEndPt) || (IPC_CTRL_ENDPOINT_ID == destEndPt)){
                #if (STD_ON == CDD_IPC_ANNOUNCE_API)
                CDD_IPC_NEW_CTRL_MSG_NTFY_FXN(procId);
                #endif
            }
            else{
                /* Loop through all the configured channels, to find the correct channel ID */
                for(idx = 0U; idx < CDD_IPC_MAX_CHANNEL_CFG; idx++){
                    /* Check if the remote proc ID of the current channel in
                     * loop matches with the remote proc ID passed as argument
                     * to the function and the remote end point of the configured
                     * channel matches the destEndPt of the argument passed in the
                     * function
                     */
                    if((procId == CddIpcConfiguraions_PC.pChCfg[idx].remoteProcId) && (destEndPt == CddIpcConfiguraions_PC.pChCfg[idx].localEp)){
                        #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
                        if(NULL_PTR == CddIpcConfiguraions_PC.pChCfg[idx].NewMessageNotify){
                            (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_RECEIVE, CDD_IPC_E_CALLBACK_NULL);
                        }
                        else
                        #endif
                        {
                            CddIpcConfiguraions_PC.pChCfg[idx].NewMessageNotify();
                            break;
                        }
                    }
                }
            }
        }
        /* If remote core is non Linux perform comparison with srcEndPt */
        else
#endif
        {
            /* Execute control message in case message is received on control
             * end point 53
             */
            if(IPC_CTRL_ENDPOINT_ID == srcEndPt){
                #if (STD_ON == CDD_IPC_ANNOUNCE_API)
                CDD_IPC_NEW_CTRL_MSG_NTFY_FXN(procId);
                #endif
            }
            else{
                /* Loop through all the configured channels, to find the correct channel ID */
                for(idx = 0U; idx < CDD_IPC_MAX_CHANNEL_CFG; idx++){
                    /* Check if the remote proc ID of the current channel in
                     * loop matches with the remote proc ID passed as argument
                     * to the function and the remote end point of the configured
                     * channel matches the destEndPt of the argument passed in the
                     * function
                     */
                    if((procId == CddIpcConfiguraions_PC.pChCfg[idx].remoteProcId) && (destEndPt == CddIpcConfiguraions_PC.pChCfg[idx].localEp)){
                        #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
                        if(NULL_PTR == CddIpcConfiguraions_PC.pChCfg[idx].NewMessageNotify){
                            (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_RECEIVE, CDD_IPC_E_CALLBACK_NULL);
                        }
                        else
                        #endif
                        {
                            CddIpcConfiguraions_PC.pChCfg[idx].NewMessageNotify();
                            break;
                        }
                    }
                }
            }
        }
    }
}

#define CDD_IPC_STOP_SEC_ISR_CODE
#include "Cdd_Ipc_MemMap.h"

/********************************* End of file ******************************/