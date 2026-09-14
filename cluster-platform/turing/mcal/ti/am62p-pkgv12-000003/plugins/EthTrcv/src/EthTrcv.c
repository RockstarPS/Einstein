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
 *  \file     EthTrcv.c
 *
 *  \brief    This file contains the implementation of the main APIs
 *            of the Ethernet Transceiver driver.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "Std_Types.h"
#include "EthTrcv.h"
#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#if (ETHTRCV_DEM_EVENT_SUPPORT == STD_ON)
#include "Dem.h"
#endif
#include "SchM_EthTrcv.h"
#include "EthTrcv_Priv.h"
#include ETHTRCV_ETHIF_CBK_HEADER

#define ETHTRCV_START_SEC_CODE
#include "EthTrcv_MemMap.h"
#define ETHTRCV_STOP_SEC_CODE
#include "EthTrcv_MemMap.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* Consistency check of the EthTrcv Driver release version with header file */
#if ((ETHTRCV_AR_RELEASE_MAJOR_VERSION != (4U)) || \
     (ETHTRCV_AR_RELEASE_MINOR_VERSION != (3U)) || \
     (ETHTRCV_AR_RELEASE_REVISION_VERSION != (1U)))
#error "EthTrcv: AUTOSAR Version Numbers of EthTrcv are different"
#endif

/* Consistency check of the EthTrcv Driver software version with header file */
#if ((ETHTRCV_SW_MAJOR_VERSION != (11U)) || \
     (ETHTRCV_SW_MINOR_VERSION != (0U)) || \
     (ETHTRCV_SW_PATCH_VERSION != (2U)))
#error "EthTrcv: Software Version Numbers are inconsistent"
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

inline EthTrcv_Trcv *EthTrcv_getCtrl(uint8 trcvIdx);

inline EthTrcv_ControllerConfigType *EthTrcv_getCtrlConfig(uint8 trcvIdx);

#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)

LOCAL_INLINE void EthTrcv_reportDetError(uint8 apiId, uint8 errorId);

static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkInitErrors(uint8 trcvIdx);

#if (STD_ON == ETHTRCV_SETTRANSCEIVERMODE_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkSetTransceiverModeErrors(uint8 trcvIdx,
                                      EthTrcv_ModeType ctrlMode);
#endif /* (STD_ON == ETHTRCV_SETTRANSCEIVERMODE_API) */

#if (STD_ON == ETHTRCV_GETTRANSCEIVERMODE_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkGetTransceiverModeErrors(uint8 trcvIdx,
                                      EthTrcv_ModeType *ctrlMode);
#endif /* ETHTRCV_GETTRANSCEIVERMODE_API */

#if (STD_ON == ETHTRCV_STARTAUTONEGOTIATION_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkStartAutoNegotiationErrors(uint8 trcvIdx);
#endif /* (STD_ON == ETHTRCV_STARTAUTONEGOTIATION_API) */

#if (STD_ON == ETHTRCV_GETLINKSTATE_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkGetLinkStateErrors(uint8 trcvIdx,
                                EthTrcv_LinkStateType *linkStatePtr);
#endif /* (STD_ON == ETHTRCV_GETLINKSTATE_API) */

#if (STD_ON == ETHTRCV_GETBAUDRATE_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkGetBaudRateErrors(uint8 trcvIdx,
                               EthTrcv_BaudRateType *baudRatePtr);
#endif /* (STD_ON == ETHTRCV_GETBAUDRATE_API) */

#if (STD_ON == ETHTRCV_GETDUPLEXMODE_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkGetDuplexModeErrors(uint8 trcvIdx,
                                 EthTrcv_DuplexModeType *duplexModePtr);
#endif /* (STD_ON == ETHTRCV_GETDUPLEXMODE_API) */

#if (STD_ON == ETHTRCV_SETPHYLOOPBACKMODE_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkSetPhyLoopbackModeErrors(uint8 trcvIdx,
                                      EthTrcv_PhyLoopbackModeType Mode);
#endif /* (STD_ON == ETHTRCV_SETPHYLOOPBACKMODE_API) */

#endif /* (STD_ON == ETHTRCV_DEV_ERROR_DETECT) */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#define ETHTRCV_START_SEC_VAR_INIT_UNSPECIFIED
#include "EthTrcv_MemMap.h"

VAR(volatile EthTrcv_StateType, ETHTRCV_VAR_CLEARED)
    gEthTrcvDrvStatus = ETHTRCV_STATE_UNINIT;

#define ETHTRCV_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "EthTrcv_MemMap.h"

#if (STD_OFF == ETH_WRAPPER_ENABLED)
#define ETHTRCV_START_SEC_VAR_INIT_32
#include "EthTrcv_MemMap.h"

VAR(volatile boolean, ETHTRCV_VAR_CLEARED)
    mdioRdCmdComplete = FALSE;

VAR(volatile boolean, ETHTRCV_VAR_CLEARED)
    mdioWrCmdComplete = FALSE;

#define ETHTRCV_STOP_SEC_VAR_INIT_32
#include "EthTrcv_MemMap.h"
#endif /* (STD_OFF == ETH_WRAPPER_ENABLED) */

#define ETHTRCV_START_SEC_VAR_NO_INIT_16
#include "EthTrcv_MemMap.h"

VAR(volatile uint16, ETHTRCV_VAR_CLEARED) mdioRdVal;

#define ETHTRCV_STOP_SEC_VAR_NO_INIT_16
#include "EthTrcv_MemMap.h"
#define ETHTRCV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthTrcv_MemMap.h"

/** \brief Ethernet TRANCEIVER driver object */
/** \brief The default configuration will be set in EthTrcv_TransceiverInit
 *   function */
VAR(EthTrcv_Drv, ETHTRCV_VAR_CLEARED) gEthTrcvDrv;

#define ETHTRCV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthTrcv_MemMap.h"

/* Organization Unique Number, Vendor Model Number, Model Revision Number */
VAR(uint32, ETHTRCV_VAR_CLEARED) gOUINumber;
VAR(uint8, ETHTRCV_VAR_CLEARED) gVendorModelNumber;
VAR(uint8, ETHTRCV_VAR_CLEARED) gModelRevisionNumber;

/* ========================================================================== */
/*                  Internal Function Definitions                             */
/* ========================================================================== */

#define ETHTRCV_START_SEC_CODE
#include "EthTrcv_MemMap.h"

static inline EthTrcv_Trcv *EthTrcv_getTrcv(uint8 trcvIdx)
{
    return &(gEthTrcvDrv.trcv[trcvIdx]);
}

static inline EthTrcv_ControllerConfigType *EthTrcv_getTrcvConfig(uint8 trcvIdx)
{
    return &(gEthTrcvDrv.trcv[trcvIdx].ethTrcvCfg);
}

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*
 * Requirements: MCAL-1765, MCAL-1766, MCAL-1767,
 *               MCAL-1768, MCAL-1769, MCAL-1770,
 *               MCAL-1771, MCAL-1772, MCAL-1773,
 *               MCAL-1774, MCAL-1775, MCAL-1776,
 *               MCAL-1845
 */
/* SWS_EthTrcv_00028 */
FUNC(void, ETHTRCV_CODE)
EthTrcv_Init(P2CONST(EthTrcv_ConfigType, AUTOMATIC, ETHTRCV_PBCFG) CfgPtr)
{
    EthTrcv_Trcv *trcv;
    uint8 trcvIdx;
    Std_ReturnType retVal = E_OK;
    const EthTrcv_ConfigType *cfg = CfgPtr;

#if (STD_ON == ETHTRCV_PRE_COMPILE_VARIANT)
    if (NULL_PTR == CfgPtr)
    {
        cfg = ETHTRCV_DRV_CONFIG_0;
    }
#endif  /* (STD_ON == ETHTRCV_PRE_COMPILE_VARIANT) */

    if (E_OK == retVal)
    {
        for(trcvIdx = 0u; trcvIdx < ETHTRCV_MAX_CONTROLLER; ++trcvIdx)
        {
            /* SWS_EthTrcv_00029 */
            trcv = EthTrcv_getTrcv(trcvIdx);
            trcv->mode = ETHTRCV_MODE_DOWN;
            trcv->modeChanged = FALSE;
            trcv->isInit = FALSE;
            trcv->trcvIdx = trcvIdx;

            /* Copy port configuration into driver object */
            /* Requirements: MCAL-1766 */
            /* SWS_EthTrcv_00035 */
            trcv->ctrlIdx                   = cfg->pController[trcvIdx]->ctrlIdx;
            trcv->miiIdx                    = cfg->pController[trcvIdx]->miiIdx;
            trcv->ethTrcvCfg.ctrlIdx        = cfg->pController[trcvIdx]->ctrlIdx;
            trcv->ethTrcvCfg.trcvIdx        = cfg->pController[trcvIdx]->trcvIdx;
            trcv->ethTrcvCfg.miiIdx         = cfg->pController[trcvIdx]->miiIdx;
            trcv->ethTrcvCfg.macType        = cfg->pController[trcvIdx]->macType;
            trcv->ethTrcvCfg.connNeg        = cfg->pController[trcvIdx]->connNeg;
            trcv->ethTrcvCfg.physLayerType  = cfg->pController[trcvIdx]->physLayerType;
            trcv->ethTrcvCfg.portMacLayerSpeed = cfg->pController[trcvIdx]->portMacLayerSpeed;
            trcv->ethTrcvCfg.portMacLayerSubType = cfg->pController[trcvIdx]->portMacLayerSubType;
            trcv->ethTrcvCfg.portMacLayerType = cfg->pController[trcvIdx]->portMacLayerType;
            trcv->ethTrcvCfg.enableAutoNeg  = cfg->pController[trcvIdx]->enableAutoNeg;
            trcv->ethTrcvCfg.baudRate       = cfg->pController[trcvIdx]->baudRate;
            trcv->ethTrcvCfg.duplexMode     = cfg->pController[trcvIdx]->duplexMode;
            trcv->ethTrcvCfg.phyId          = cfg->pController[trcvIdx]->phyId;
            trcv->ethTrcvCfg.extendedConfig = cfg->pController[trcvIdx]->extendedConfig;

            retVal |= EthTrcv_TransceiverInit(trcvIdx);
        }
    }

    /* Requirements: MCAL-1767 */
    if (E_OK == retVal)
    {
        /* SWS_EthTrcv_00030 */
        gEthTrcvDrvStatus = ETHTRCV_STATE_INIT;
    }

    return;
}

FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_TransceiverInit(uint8 TrcvIdx)
{
    EthTrcv_Trcv *trcv;
    EthTrcv_ControllerConfigType *cfg;
    Std_ReturnType retVal = E_OK;

#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
    retVal = EthTrcv_checkInitErrors(TrcvIdx);
#endif

    if(E_OK == retVal)
    {
        trcv = EthTrcv_getTrcv(TrcvIdx);
        cfg = EthTrcv_getTrcvConfig(TrcvIdx);

        /* SWS_EthTrcv_00040 */
        EthTrcv_checkTransceiverAccess(trcv);

        if(trcv->isInit == FALSE)
        {
            /* Configure the transceiver */
            if (E_OK == retVal)
            {
                if (TRUE == cfg->enableAutoNeg)
                {
                    /* Auto-negotiation mode */
                    retVal = EthTrcv_setConfigAutoNeg(trcv, cfg);
                }
                else
                {
                    /* Manual mode */
                    retVal = EthTrcv_setConfigManual(trcv, cfg);
                }
            }

            /* Requirements: MCAL-1767 */
            if (E_OK == retVal)
            {
                trcv->isInit = TRUE;
            }
        }
    }

    return retVal;
}

/* SWS_EthTrcv_00046 */
#if (STD_ON == ETHTRCV_SETTRANSCEIVERMODE_API)
/*
 * Requirements: MCAL-1777, MCAL-1778, MCAL-1779
 *               MCAL-1780, MCAL-1781, MCAL-1824
 *               MCAL-1833, MCAL-1782
 */
/* SWS_EthTrcv_00042 */
FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_SetTransceiverMode(uint8 TrcvIdx,
                           EthTrcv_ModeType CtrlMode)
{
    EthTrcv_Trcv *trcv;
    Std_ReturnType retVal = E_OK;

#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
    /* SWS_EthTrcv_00044 */
    /* SWS_EthTrcv_00045 */
    /* SWS_EthTrcv_00047 */
    retVal = EthTrcv_checkSetTransceiverModeErrors(TrcvIdx, CtrlMode);
#endif

    if (E_OK == retVal)
    {
        trcv = EthTrcv_getTrcv(TrcvIdx);

        /* Requirements: MCAL-1833 */
        /* SWS_EthTrcv_00104 */
        retVal = EthTrcv_checkTransceiverAccess(trcv);
    }

    if (E_OK == retVal)
    {
        if (CtrlMode != trcv->mode)
        {
            /* SWS_EthTrcv_00043 */
            if (E_OK == retVal)
            {
                trcv->mode = CtrlMode;
                trcv->modeChanged = TRUE;
            }
        }
        else
        {
            /* Requirements: MCAL-1824 */
            /* SWS_EthTrcv_00094 */
            trcv->modeChanged = FALSE;
            retVal = E_OK;
        }
    }

    return retVal;
}
#endif

/* SWS_EthTrcv_00053 */
#if (STD_ON == ETHTRCV_GETTRANSCEIVERMODE_API)
/*
 * Requirements: MCAL-1783, MCAL-1784, MCAL-1785
 *               MCAL-1786, MCAL-1787, MCAL-1788
 *               MCAL-1789
 */
/* SWS_EthTrcv_00048 */
FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_GetTransceiverMode(uint8 TrcvIdx,
                           EthTrcv_ModeType *TrcvModePtr)
{
    Std_ReturnType retVal = E_OK;

#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
    /* SWS_EthTrcv_00050 */
    /* SWS_EthTrcv_00051 */
    /* SWS_EthTrcv_00052 */
    /* SWS_EthTrcv_00054 */
    retVal = EthTrcv_checkGetTransceiverModeErrors(TrcvIdx, TrcvModePtr);
#endif

    if (E_OK == retVal)
    {
        /* SWS_EthTrcv_00049 */
        *TrcvModePtr = gEthTrcvDrv.trcv[TrcvIdx].mode;
    }

    return retVal;
}
#endif

/* SWS_EthTrcv_00059 */
#if (STD_ON == ETHTRCV_STARTAUTONEGOTIATION_API)
/*
 * Requirements: MCAL-1790, MCAL-1791, MCAL-1792
 *               MCAL-1793, MCAL-1794, MCAL-1795
 *               MCAL-1820
 */
/* SWS_EthTrcv_00055 */
FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_StartAutoNegotiation(uint8 TrcvIdx)
{
    EthTrcv_Trcv *trcv;
    Std_ReturnType retVal = E_OK;
    uint16 mask;
    uint16 val;

#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
    /* SWS_EthTrcv_00057 */
    /* SWS_EthTrcv_00058 */
    /* SWS_EthTrcv_00060 */
    retVal = EthTrcv_checkStartAutoNegotiationErrors(TrcvIdx);
#endif

    if (E_OK == retVal)
    {
        trcv = EthTrcv_getTrcv(TrcvIdx);

        /* SWS_EthTrcv_00056 */
        /* Start auto-negotiation */
        if (E_OK == retVal)
        {
            mask = ETHTRCV_BMCR_RESTARTANEG_MASK;
            val = ETHTRCV_BMCR_RESTARTANEG;
            retVal = EthTrcv_rmwReg(trcv, ETHTRCV_BMCR, mask, val);
        }
    }

    return retVal;
}
#endif

/* SWS_EthTrcv_00066 */
#if (STD_ON == ETHTRCV_GETLINKSTATE_API)
/*
 * Requirements: MCAL-1796, MCAL-1797, MCAL-1798
 *               MCAL-1799, MCAL-1800, MCAL-1801
 *               MCAL-1802
 */
/* SWS_EthTrcv_00061 */
FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_GetLinkState(uint8 TrcvIdx,
                     EthTrcv_LinkStateType *LinkStatePtr)
{
    EthTrcv_Trcv *trcv;
    boolean valid;
    Std_ReturnType retVal = E_OK;

#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
    /* SWS_EthTrcv_00063 */
    /* SWS_EthTrcv_00064 */
    /* SWS_EthTrcv_00065 */
    /* SWS_EthTrcv_00067 */
    retVal = EthTrcv_checkGetLinkStateErrors(TrcvIdx, LinkStatePtr);
#endif

    if (E_OK == retVal)
    {
        trcv = EthTrcv_getTrcv(TrcvIdx);

        /* SWS_EthTrcv_00062 */
        valid = EthTrcv_isLinked(trcv);
        if (TRUE == valid)
        {
            *LinkStatePtr = ETHTRCV_LINK_STATE_ACTIVE;
        }
        else
        {
            *LinkStatePtr = ETHTRCV_LINK_STATE_DOWN;
        }
    }

    return retVal;
}
#endif

/* SWS_EthTrcv_00073 */
#if (STD_ON == ETHTRCV_GETBAUDRATE_API)
/*
 * Requirements: MCAL-1803, MCAL-1804, MCAL-1805
 *               MCAL-1806, MCAL-1807, MCAL-1808
 *               MCAL-1809, MCAL-1821
 */
/* SWS_EthTrcv_00068 */
FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_GetBaudRate(uint8 TrcvIdx,
                    EthTrcv_BaudRateType *BaudRatePtr)
{
    EthTrcv_Trcv *trcv;
    EthTrcv_ControllerConfigType *cfg;
    uint16 val;
    Std_ReturnType retVal = E_OK;

#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
    /* SWS_EthTrcv_00070 */
    /* SWS_EthTrcv_00071 */
    /* SWS_EthTrcv_00072 */
    /* SWS_EthTrcv_00074 */
    retVal = EthTrcv_checkGetBaudRateErrors(TrcvIdx, BaudRatePtr);
#endif

    if (E_OK == retVal)
    {
        trcv = EthTrcv_getTrcv(TrcvIdx);
        cfg = EthTrcv_getTrcvConfig(TrcvIdx);
    }

    if (E_OK == retVal)
    {
        /* Read the BMCR register (addr 0x00) and get the mode */
        retVal = EthTrcv_readReg(trcv, ETHTRCV_BMCR, &val);
        if (E_OK == retVal)
        {
            /* SWS_EthTrcv_00069 */
            /* Get the baud rate after updating capabilities */
            if (ETHTRCV_BMCR_ANEGENABLE ==
                (val & ETHTRCV_BMCR_ANEGENABLE_MASK))
            {
                /* Autonegotiation mode */
                retVal = EthTrcv_getAutoNegSpeed(trcv, cfg, BaudRatePtr);
            }
            else
            {
                /* Manual mode */
                retVal = EthTrcv_getManualSpeed(trcv, cfg, BaudRatePtr);
            }
        }
    }

    return retVal;
}
#endif

/* SWS_EthTrcv_00080 */
#if (STD_ON == ETHTRCV_GETDUPLEXMODE_API)
/*
 * Requirements: MCAL-1810, MCAL-1811, MCAL-1812
 *               MCAL-1813, MCAL-1814, MCAL-1815
 *               MCAL-1816, MCAL-1822
 */
/* SWS_EthTrcv_00075 */
FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_GetDuplexMode(uint8 TrcvIdx,
                      EthTrcv_DuplexModeType *DuplexModePtr)
{
    EthTrcv_Trcv *trcv;
    EthTrcv_ControllerConfigType *cfg;
    uint16 val;
    Std_ReturnType retVal = E_OK;

#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
    /* SWS_EthTrcv_00077 */
    /* SWS_EthTrcv_00078 */
    /* SWS_EthTrcv_00079 */
    /* SWS_EthTrcv_00081 */
    retVal = EthTrcv_checkGetDuplexModeErrors(TrcvIdx, DuplexModePtr);
#endif

    if (E_OK == retVal)
    {
        trcv = EthTrcv_getTrcv(TrcvIdx);
        cfg = EthTrcv_getTrcvConfig(TrcvIdx);
    }

    if (E_OK == retVal)
    {
        /* Read the BMCR register (addr 0x00) and get the mode */
        retVal = EthTrcv_readReg(trcv, ETHTRCV_BMCR, &val);
        if (E_OK == retVal)
        {
            /* SWS_EthTrcv_00076 */
            /* Get the duplexity after updating capabilities */
            if (ETHTRCV_BMCR_ANEGENABLE ==
                (val & ETHTRCV_BMCR_ANEGENABLE_MASK))
            {
                /* Autonegotiation mode */
                retVal = EthTrcv_getAutoNegDuplex(trcv, cfg, DuplexModePtr);
            }
            else
            {
                /* Manual mode */
                retVal = EthTrcv_getManualDuplex(trcv, cfg, DuplexModePtr);
            }
        }
    }

    return retVal;
}
#endif

#if (STD_ON == ETHTRCV_GETPHYIDENTIFIER_API)
FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_GetPhyIdentifier(uint8 TrcvIdx,
                        uint32* OrgUniqueIdPtr,
                        uint8* ModelNrPtr,
                        uint8* RevisionNrPtr)
{
    EthTrcv_Trcv *trcv;
    uint16 val1, val2;
    Std_ReturnType retVal = E_OK;

#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
    if (ETHTRCV_MAX_CONTROLLER <= TrcvIdx)
    {
        /* Requirements: MCAL-1813 */
        EthTrcv_reportDetError(ETHTRCV_GETPHYIDENTIFIER_ID, ETHTRCV_E_INV_TRCV_IDX);
    }
#endif
    if (E_OK == retVal)
    {
        trcv = EthTrcv_getTrcv(TrcvIdx);

        /* Read the PHYIDR1 register (addr 0x02) and get the OUI_MSB */
        retVal = EthTrcv_readReg(trcv, ETHTRCV_PHYIDR1, &val1);
        if (E_OK == retVal)
        {
            retVal = EthTrcv_readReg(trcv, ETHTRCV_PHYIDR2, &val2);
        }
        if (E_OK == retVal)
        {
            gOUINumber = 0;
            gVendorModelNumber = 0;
            gModelRevisionNumber = 0;
            /* Bits 3 to 18 of 24-bit OUI */
            gOUINumber |= ((uint32)val1 & ETHTRCV_PHYIDR1_OUIMSB_MASK) << (24 - 18);
            /* Bits 19 to 24 of 24-bit OUI */
            gOUINumber |= ((uint32)val2 & ETHTRCV_PHYIDR2_OUILSB_MASK) >> 10;
            /* 6 bits of vendor model number */
            gVendorModelNumber |= (uint8)((val2 & ETHTRCV_PHYIDR2_VNDLMDL_MASK) >> 4);
            /* 4 bit s of model revision number */
            gModelRevisionNumber |= (uint8)(val2 & ETHTRCV_PHYIDR2_MDLREV_MASK);
            
            OrgUniqueIdPtr = &gOUINumber;
            ModelNrPtr = &gVendorModelNumber;
            RevisionNrPtr = &gModelRevisionNumber;
        }
    }
    return retVal;
}
#endif

#if (STD_ON == ETHTRCV_VERSION_INFO_API)
/*
 * Requirements: MCAL-1817, MCAL-1823
 */
/* SWS_EthTrcv_00082 */
FUNC(void, ETHTRCV_CODE)
EthTrcv_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, ETHTRCV_APPL_DATA) VersionInfoPtr)
{
#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
    if (VersionInfoPtr == NULL_PTR)
    {
        /* Requirements: MCAL-1823 */
        EthTrcv_reportDetError(ETHTRCV_VERSION_ID, ETHTRCV_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfoPtr->vendorID         = (uint16) ETHTRCV_VENDOR_ID;
        VersionInfoPtr->moduleID         = (uint16) ETHTRCV_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8) ETHTRCV_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8) ETHTRCV_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8) ETHTRCV_SW_PATCH_VERSION;
    }
}
#endif

/*
 * Requirements: MCAL-1835, MCAL-1836, MCAL-1871
 */
/* SWS_EthTrcv_00106 */
FUNC(void, ETHTRCV_CODE)
EthTrcv_MainFunction(void)
{
#if (STD_ON == ETHTRCV_GETTRANSCEIVERMODE_API)
    EthTrcv_Trcv *trcv;
    EthTrcv_ModeType ctrlMode;
    uint8 i;
#endif
    Std_ReturnType retVal = E_OK;

#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
    /* SWS_EthTrcv_00142 */
    if (ETHTRCV_STATE_INIT != gEthTrcvDrvStatus)
    {
        /* Requirements: MCAL-1871 */
        EthTrcv_reportDetError(ETHTRCV_MAINFCT_WRITE_ID,
                               ETHTRCV_E_UNINIT);
        retVal = E_NOT_OK;
    }
#endif

    if (E_OK == retVal)
    {
#if (STD_ON == ETHTRCV_GETTRANSCEIVERMODE_API)
        for (i = 0U; i < ETHTRCV_MAX_CONTROLLER; i++)
        {
            trcv = EthTrcv_getTrcv(i);
            /* SWS_EthTrcv_00107 */
            if (TRUE == trcv->modeChanged)
            {
                retVal = EthTrcv_GetTransceiverMode(i, &ctrlMode);
                if (E_OK == retVal)
                {
                    /* Requirements: MCAL-17513, MCAL-1836 */
                    EthIf_TrcvModeIndication(i, ctrlMode);
                    trcv->modeChanged = FALSE;
                }
            }
        }
#endif
    }
}

#if (STD_OFF == ETH_WRAPPER_ENABLED)
/*
 * Requirements: MCAL-1837
 */
/* SWS_EthTrcv_00108 */
FUNC(void, ETHTRCV_CODE)
EthTrcv_ReadMiiIndication(uint8 CtrlIdx,
                          uint8 TrcvIdx,
                          uint8 RegIdx,
                          uint16 RegVal)
{
    mdioRdVal = RegVal;
    mdioRdCmdComplete = TRUE;
}

/*
 * Requirements: MCAL-1838
 */
/* SWS_EthTrcv_00109 */
FUNC(void, ETHTRCV_CODE)
EthTrcv_WriteMiiIndication(uint8 CtrlIdx,
                           uint8 TrcvIdx,
                           uint8 RegId)
{
    mdioWrCmdComplete = TRUE;
}
#endif /* (STD_OFF == ETH_WRAPPER_ENABLED) */

#if (STD_ON == ETHTRCV_GETCABLEDIAGNOSTICSRESULT_API)
FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_GetCableDiagnosticsResult(uint8 TrcvIdx,
                      EthTrcv_CableDiagResultType * ResultPtr)
{
    (void)TrcvIdx;
    (void)ResultPtr;
    return E_NOT_OK;
}
#endif

#if (STD_ON == ETHTRCV_GETPHYSIGNALQUALITY_API)
FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_GetPhySignalQuality(uint8 TrcvIdx,
                      uint32* SignalQualityPtr)
{
    (void)TrcvIdx;
    (void)SignalQualityPtr;
    return E_NOT_OK;
}
#endif

#if (STD_ON == ETHTRCV_SETPHYLOOPBACKMODE_API)
/* SWS_EthTrcv_91005 */
FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_SetPhyLoopbackMode(uint8 TrcvIdx,
                      EthTrcv_PhyLoopbackModeType Mode)
{
    EthTrcv_Trcv *trcv;
    Std_ReturnType retVal = E_OK;

#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
    /* SWS_EthTrcv_00149 */
    retVal = EthTrcv_checkSetPhyLoopbackModeErrors(TrcvIdx, Mode);
#endif

    if(E_OK == retVal)
    {
        trcv = EthTrcv_getTrcv(TrcvIdx);

        if (ETHTRCV_PHYLOOPBACK_NONE == Mode)
        {
            retVal = EthTrcv_enableLoopback(trcv, FALSE);
        }
        else if (ETHTRCV_PHYLOOPBACK_INTERNAL == Mode)
        {
            retVal = EthTrcv_enableLoopback(trcv, TRUE);
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}
#endif

#if (STD_ON == ETHTRCV_SETPHYTESTMODE_API)
FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_SetPhyTestMode(uint8 TrcvIdx,
                      EthTrcv_PhyTestModeType Mode)
{
    (void)TrcvIdx;
    (void)Mode;
    return E_NOT_OK;
}
#endif

#if (STD_ON == ETHTRCV_SETPHYTXMODE_API)
FUNC(Std_ReturnType, ETHTRCV_CODE)
 EthTrcv_SetPhyTxMode(uint8 TrcvIdx,
                      EthTrcv_PhyTxModeType Mode)
{
    (void)TrcvIdx;
    (void)Mode;
    return E_NOT_OK;
}
#endif

/* ========================================================================== */
/*                           static functions                                 */
/* ========================================================================== */

#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)

LOCAL_INLINE void EthTrcv_reportDetError(uint8 apiId, uint8 errorId)
{
    (void) Det_ReportError(ETHTRCV_MODULE_ID, ETHTRCV_INSTANCE_ID, apiId, errorId);
}

static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkInitErrors(uint8 trcvIdx)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (ETHTRCV_MAX_CONTROLLER <= trcvIdx)
    {
        /* Requirements: MCAL-1773 */
        EthTrcv_reportDetError(ETHTRCV_INIT_ID, ETHTRCV_E_INV_TRCV_IDX);
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}

#if (STD_ON == ETHTRCV_SETTRANSCEIVERMODE_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkSetTransceiverModeErrors(uint8 trcvIdx,
                                      EthTrcv_ModeType ctrlMode)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (ETHTRCV_STATE_INIT != gEthTrcvDrvStatus)
    {
        /* Requirements: MCAL-1779 */
        EthTrcv_reportDetError(ETHTRCV_SETTRCVMODE_ID, ETHTRCV_E_UNINIT);
    }
    else if (ETHTRCV_MAX_CONTROLLER <= trcvIdx)
    {
        /* Requirements: MCAL-1780 */
        EthTrcv_reportDetError(ETHTRCV_SETTRCVMODE_ID, ETHTRCV_E_INV_TRCV_IDX);
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}
#endif /* (STD_ON == ETHTRCV_SETTRANSCEIVERMODE_API) */

#if (STD_ON == ETHTRCV_GETTRANSCEIVERMODE_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkGetTransceiverModeErrors(uint8 trcvIdx,
                                      EthTrcv_ModeType *ctrlMode)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (ETHTRCV_STATE_INIT != gEthTrcvDrvStatus)
    {
        /* Requirements: MCAL-1785 */
        EthTrcv_reportDetError(ETHTRCV_GETTRCVMODE_ID, ETHTRCV_E_UNINIT);
    }
    else if (ETHTRCV_MAX_CONTROLLER <= trcvIdx)
    {
        /* Requirements: MCAL-1786 */
        EthTrcv_reportDetError(ETHTRCV_GETTRCVMODE_ID, ETHTRCV_E_INV_TRCV_IDX);
    }
    else if (NULL_PTR == ctrlMode)
    {
        /* Requirements: MCAL-1787 */
        EthTrcv_reportDetError(ETHTRCV_GETTRCVMODE_ID, ETHTRCV_E_PARAM_POINTER);
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}
#endif /* ETHTRCV_GETTRANSCEIVERMODE_API */

#if (STD_ON == ETHTRCV_STARTAUTONEGOTIATION_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkStartAutoNegotiationErrors(uint8 trcvIdx)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (ETHTRCV_STATE_INIT != gEthTrcvDrvStatus)
    {
        /* Requirements: MCAL-1792 */
        EthTrcv_reportDetError(ETHTRCV_SRTAUTONEGOTIA_ID, ETHTRCV_E_UNINIT);
    }
    else if (ETHTRCV_MAX_CONTROLLER <= trcvIdx)
    {
        /* Requirements: MCAL-1793 */
        EthTrcv_reportDetError(ETHTRCV_SRTAUTONEGOTIA_ID, ETHTRCV_E_INV_TRCV_IDX);
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}
#endif /* (STD_ON == ETHTRCV_STARTAUTONEGOTIATION_API) */

#if (STD_ON == ETHTRCV_GETLINKSTATE_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkGetLinkStateErrors(uint8 trcvIdx,
                                EthTrcv_LinkStateType *linkStatePtr)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (ETHTRCV_STATE_INIT != gEthTrcvDrvStatus)
    {
        /* Requirements: MCAL-1798 */
        EthTrcv_reportDetError(ETHTRCV_GETLNKSTATE_ID, ETHTRCV_E_UNINIT);
    }
    else if (ETHTRCV_MAX_CONTROLLER <= trcvIdx)
    {
        /* Requirements: MCAL-1799 */
        EthTrcv_reportDetError(ETHTRCV_GETLNKSTATE_ID, ETHTRCV_E_INV_TRCV_IDX);
    }
    else if (NULL_PTR == linkStatePtr)
    {
        /* Requirements: MCAL-1800 */
        EthTrcv_reportDetError(ETHTRCV_GETLNKSTATE_ID, ETHTRCV_E_PARAM_POINTER);
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}
#endif /* (STD_ON == ETHTRCV_GETLINKSTATE_API) */

#if (STD_ON == ETHTRCV_GETBAUDRATE_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkGetBaudRateErrors(uint8 trcvIdx,
                               EthTrcv_BaudRateType *baudRatePtr)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (ETHTRCV_STATE_INIT != gEthTrcvDrvStatus)
    {
        /* Requirements: MCAL-1805 */
        EthTrcv_reportDetError(ETHTRCV_GETBAUD_ID, ETHTRCV_E_UNINIT);
    }
    else if (ETHTRCV_MAX_CONTROLLER <= trcvIdx)
    {
        /* Requirements: MCAL-1806 */
        EthTrcv_reportDetError(ETHTRCV_GETBAUD_ID, ETHTRCV_E_INV_TRCV_IDX);
    }
    else if (NULL_PTR == baudRatePtr)
    {
        /* Requirements: MCAL-1807 */
        EthTrcv_reportDetError(ETHTRCV_GETBAUD_ID, ETHTRCV_E_PARAM_POINTER);
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}
#endif /* (STD_ON == ETHTRCV_GETBAUDRATE_API) */

#if (STD_ON == ETHTRCV_GETDUPLEXMODE_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkGetDuplexModeErrors(uint8 trcvIdx,
                                 EthTrcv_DuplexModeType *duplexModePtr)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (ETHTRCV_STATE_INIT != gEthTrcvDrvStatus)
    {
        /* Requirements: MCAL-1812 */
        EthTrcv_reportDetError(ETHTRCV_GETDPLXMODE_ID, ETHTRCV_E_UNINIT);
    }
    else if (ETHTRCV_MAX_CONTROLLER <= trcvIdx)
    {
        /* Requirements: MCAL-1813 */
        EthTrcv_reportDetError(ETHTRCV_GETDPLXMODE_ID, ETHTRCV_E_INV_TRCV_IDX);
    }
    else if (NULL_PTR == duplexModePtr)
    {
        /* Requirements: MCAL-1814 */
        EthTrcv_reportDetError(ETHTRCV_GETDPLXMODE_ID, ETHTRCV_E_PARAM_POINTER);
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}
#endif /* (STD_ON == ETHTRCV_GETDUPLEXMODE_API) */

#if (STD_ON == ETHTRCV_SETPHYLOOPBACKMODE_API)
static FUNC(Std_ReturnType, ETHTRCV_CODE)
EthTrcv_checkSetPhyLoopbackModeErrors(uint8 trcvIdx,
                                      EthTrcv_PhyLoopbackModeType Mode)
{
    Std_ReturnType retVal = E_NOT_OK;
    if (ETHTRCV_STATE_INIT != gEthTrcvDrvStatus)
    {
        EthTrcv_reportDetError(ETHTRCV_SETPHYLOOPBACKMODE_ID, ETHTRCV_E_UNINIT);
    }
    else if (ETHTRCV_MAX_CONTROLLER <= trcvIdx)
    {
        EthTrcv_reportDetError(ETHTRCV_SETPHYLOOPBACKMODE_ID, ETHTRCV_E_INV_TRCV_IDX);
    }
    else if (!((ETHTRCV_PHYLOOPBACK_NONE == Mode) || (ETHTRCV_PHYLOOPBACK_INTERNAL == Mode)))
    {
        EthTrcv_reportDetError(ETHTRCV_SETPHYLOOPBACKMODE_ID, ETHTRCV_E_NOT_SUPPORTED);
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}
#endif /* (STD_ON == ETHTRCV_SETPHYLOOPBACKMODE_API) */

#endif /* (STD_ON == ETHTRCV_DEV_ERROR_DETECT) */

#define ETHTRCV_STOP_SEC_CODE
#include "EthTrcv_MemMap.h"
