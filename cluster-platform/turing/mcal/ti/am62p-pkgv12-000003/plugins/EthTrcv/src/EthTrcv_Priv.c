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
 *  \file     EthTrcv_Priv.c
 *
 *  \brief    This file contains Ethernet Transceiver internal driver.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "EthTrcv.h"
#if (STD_ON == ETHTRCV_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#if (ETHTRCV_DEM_EVENT_SUPPORT == STD_ON)
#include "Dem.h"
#endif
#include "Os.h"
#include "SchM_EthTrcv.h"

#include "Eth.h"
#if (STD_ON == ETH_WRAPPER_ENABLED)
#include "Eth_30_Wrapper.h"
#endif /* (STD_ON == ETH_WRAPPER_ENABLED) */
#include "EthTrcv_Priv.h"
#include "phy/Dp83867.h"
#include "Dp83867_Priv.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define DP83869_PHYID                   ((uint32) 0x2000A0F1)

#define ETHTRCV_TICK_MS                 (100U)
#define ETHTRCV_AUTONEG_LINKED_WAIT_S   (4U)
#define ETHTRCV_AUTONEG_RETRY_NUM       (320000U)
#define ETHTRCV_LINKED_RETRY_NUM        (200000U)
#define ETHTRCV_RESET_RETRY_NUM         (10000U)

#define ETHTRCV_DIV_ROUNDUP(val, div)   (((val) + (div) - 1) / (div))

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

static inline boolean EthTrcv_supportPhyId(uint32 PhyId);

static Std_ReturnType EthTrcv_getAutoNegSelfAbility(EthTrcv_Trcv *trcv,
                                                    uint32 *pAblty);

static Std_ReturnType EthTrcv_getManualSelfSpeedDuplex(EthTrcv_Trcv *trcv,
                                                       uint32 *pSpdDplx);

static Std_ReturnType EthTrcv_getAutoNegPartnerAbility(EthTrcv_Trcv *trcv,
                                                       uint32 *pPartnerAblty);

static Std_ReturnType EthTrcv_waitForAutoNeg(EthTrcv_Trcv *trcv);

static Std_ReturnType EthTrcv_waitForLinkUp(EthTrcv_Trcv *trcv);

Std_ReturnType EthTrcv_readExtReg(EthTrcv_Trcv *trcv,
                                  uint16 reg,
                                  uint16 *val);

Std_ReturnType EthTrcv_writeExtReg(EthTrcv_Trcv *trcv,
                                   uint16 reg,
                                   uint16 val);

Std_ReturnType EthTrcv_rmwExtReg(EthTrcv_Trcv *trcv,
                                 uint16 reg,
                                 uint16 mask,
                                 uint16 val);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                  Internal Function Definitions                             */
/* ========================================================================== */

static inline boolean EthTrcv_supportPhyId(uint32 phyId)
{
    boolean retVal = FALSE;
    if ((phyId == DP83867_PHYID) || (phyId == DP83869_PHYID))
    {
        retVal = TRUE;
    }

    return retVal;
}

static Std_ReturnType EthTrcv_getAutoNegSelfAbility(EthTrcv_Trcv *trcv,
                                                    uint32 *pAblty)
{
    uint16 val;
    Std_ReturnType retVal;

    *pAblty = 0U;

    /* Read the ANAR register (addr 0x04) and get the 10 and
    * 100 Mbps capabilities */
    retVal = EthTrcv_readReg(trcv, ETHTRCV_ANAR, &val);
    if (E_OK == retVal)
    {
        if (ETHTRCV_ANAR_10BASETHALFDUPLEX ==
            (val & ETHTRCV_ANAR_10BASETHALFDUPLEX))
        {
            *pAblty |= ETHERNET_ADV_10_HALF;
        }

        if (ETHTRCV_ANAR_10BASETFULLDUPLEX ==
            (val & ETHTRCV_ANAR_10BASETFULLDUPLEX))
        {
            *pAblty |= ETHERNET_ADV_10_FULL;
        }

        if (ETHTRCV_ANAR_100BASETXHALFDUPLEX ==
            (val & ETHTRCV_ANAR_100BASETXHALFDUPLEX))
        {
            *pAblty |= ETHERNET_ADV_100_HALF;
        }

        if (ETHTRCV_ANAR_100BASETXFULLDUPLEX ==
            (val & ETHTRCV_ANAR_100BASETXFULLDUPLEX))
        {
            *pAblty |= ETHERNET_ADV_100_FULL;
        }
    }

    /* Read the CFG1 register (addr 0x09) and get the 1 Gbps capabilities */
    if (E_OK == retVal)
    {
        retVal = EthTrcv_readReg(trcv, ETHTRCV_CFG1, &val);
        if (E_OK == retVal)
        {
            if (ETHTRCV_CFG1_1000BASETHALFDUPLEX ==
                (val & ETHTRCV_CFG1_1000BASETHALFDUPLEX))
            {
                *pAblty |= ETHERNET_ADV_1000_HALF;
            }

            if (ETHTRCV_CFG1_1000BASETFULLDUPLEX ==
                (val & ETHTRCV_CFG1_1000BASETFULLDUPLEX))
            {
                *pAblty |= ETHERNET_ADV_1000_FULL;
            }
        }
    }

    return retVal;
}

static Std_ReturnType EthTrcv_getManualSelfSpeedDuplex(EthTrcv_Trcv *trcv,
                                                       uint32 *pSpdDplx)
{
    uint16 val;
    Std_ReturnType retVal;

    *pSpdDplx = 0U;

    /* Read the BMCR register (addr 0x00) and get the capabilities */
    retVal = EthTrcv_readReg(trcv, ETHTRCV_BMCR, &val);
    if (E_OK == retVal)
    {
        if (ETHTRCV_BMCR_SPEED_10 ==
            (val & ETHTRCV_BMCR_SPEED_MASK))
        {
            if (ETHTRCV_BMCR_HALFDUPLEX ==
                (val & ETHTRCV_BMCR_DUPLEXMODE_MASK))
            {
                *pSpdDplx |= ETHERNET_ADV_10_HALF;
            }

            if (ETHTRCV_BMCR_FULLDUPLEX ==
                (val & ETHTRCV_BMCR_DUPLEXMODE_MASK))
            {
                *pSpdDplx |= ETHERNET_ADV_10_FULL;
            }
        }

        if (ETHTRCV_BMCR_SPEED_100 ==
            (val & ETHTRCV_BMCR_SPEED_MASK))
        {
            if (ETHTRCV_BMCR_HALFDUPLEX ==
                (val & ETHTRCV_BMCR_DUPLEXMODE_MASK))
            {
                *pSpdDplx |= ETHERNET_ADV_100_HALF;
            }

            if (ETHTRCV_BMCR_FULLDUPLEX ==
                (val & ETHTRCV_BMCR_DUPLEXMODE_MASK))
            {
                *pSpdDplx |= ETHERNET_ADV_100_FULL;
            }
        }

        if (ETHTRCV_BMCR_SPEED_1000 ==
            (val & ETHTRCV_BMCR_SPEED_MASK))
        {
            if (ETHTRCV_BMCR_HALFDUPLEX ==
                (val & ETHTRCV_BMCR_DUPLEXMODE_MASK))
            {
                *pSpdDplx |= ETHERNET_ADV_1000_HALF;
            }

            if (ETHTRCV_BMCR_FULLDUPLEX ==
                (val & ETHTRCV_BMCR_DUPLEXMODE_MASK))
            {
                *pSpdDplx |= ETHERNET_ADV_1000_FULL;
            }
        }
    }

    return retVal;
}

static Std_ReturnType EthTrcv_getAutoNegPartnerAbility(EthTrcv_Trcv *trcv,
                                                       uint32 *pPartnerAblty)
{
    uint16 val;
    Std_ReturnType retVal;

    *pPartnerAblty = 0U;

    /* Read the ANLPAR register (addr 0x05) and get the 10 and
     * 100 Mbps capabilities */
    retVal = EthTrcv_readReg(trcv, ETHTRCV_ANLPAR, &val);
    if (E_OK == retVal)
    {
        if (ETHTRCV_ANLPAR_10BASETHALFDUPLEX ==
            (val & ETHTRCV_ANLPAR_10BASETHALFDUPLEX))
        {
            *pPartnerAblty |= ETHERNET_ADV_10_HALF;
        }

        if (ETHTRCV_ANLPAR_10BASETFULLDUPLEX ==
            (val & ETHTRCV_ANLPAR_10BASETFULLDUPLEX))
        {
            *pPartnerAblty |= ETHERNET_ADV_10_FULL;
        }

        if (ETHTRCV_ANLPAR_100BASETXHALFDUPLEX ==
            (val & ETHTRCV_ANLPAR_100BASETXHALFDUPLEX))
        {
            *pPartnerAblty |= ETHERNET_ADV_100_HALF;
        }

        if (ETHTRCV_ANLPAR_100BASETXFULLDUPLEX ==
            (val & ETHTRCV_ANLPAR_100BASETXFULLDUPLEX))
        {
            *pPartnerAblty |= ETHERNET_ADV_100_FULL;
        }
    }

    /* Read the STS1 register (addr 0x0a) and get the 1 Gbps capabilities */
    if (E_OK == retVal)
    {
        retVal = EthTrcv_readReg(trcv, ETHTRCV_STS1, &val);
        if (E_OK == retVal)
        {
            if (ETHTRCV_STS1_1000BASETHALFDUPLEX ==
                (val & ETHTRCV_STS1_1000BASETHALFDUPLEX))
            {
                *pPartnerAblty |= ETHERNET_ADV_1000_HALF;
            }

            if (ETHTRCV_STS1_1000BASETFULLDUPLEX ==
                (val & ETHTRCV_STS1_1000BASETFULLDUPLEX))
            {
                *pPartnerAblty |= ETHERNET_ADV_1000_FULL;
            }
        }
    }

    return retVal;
}

static Std_ReturnType EthTrcv_waitForAutoNeg(EthTrcv_Trcv *trcv)
{
    uint16 val;
    Std_ReturnType retVal = E_OK;

    uint64 delayInSec = ETHTRCV_AUTONEG_LINKED_WAIT_S;
    TickType delayInTicks = (TickType)(delayInSec*ETH_OS_COUNTER_FREQ);
    TickType curTick = 0U;
    TickType tempCount = 0U;
    TickType elapsed = 0U;
    StatusType status;
    uint8 success = 0U;

    status = GetCounterValue(ETH_OS_COUNTER_ID, &curTick);

    while ((E_OK == status) && (delayInTicks >= elapsed))
    {
        /* Read the BMSR register (addr 0x01) */
        retVal = EthTrcv_readReg(trcv, ETHTRCV_BMSR, &val);
        if (E_OK != retVal)
        {
            break;
        }

        /* Auto-negotiation is complete when "Auto-Neg Complete" bit
         * is set */
        if (ETHTRCV_BMSR_ANEGCOMPLETE ==
            (val & ETHTRCV_BMSR_ANEGCOMPLETE_MASK))
        {
            success = 1U;
            break;
        }

        tempCount = curTick;
        status = GetElapsedValue(ETH_OS_COUNTER_ID, &tempCount, &elapsed);
    }

    if (!success)
    {
        retVal = E_NOT_OK;
    }

    return retVal;
}

static Std_ReturnType EthTrcv_waitForLinkUp(EthTrcv_Trcv *trcv)
{
    uint16 val;
    Std_ReturnType retVal = E_OK;

    uint64 delayInSec = ETHTRCV_AUTONEG_LINKED_WAIT_S;
    TickType delayInTicks = (TickType)(delayInSec*ETH_OS_COUNTER_FREQ);
    TickType curTick = 0U;
    TickType tempCount = 0U;
    TickType elapsed = 0U;
    StatusType status;
    uint8 success = 0U;

    status = GetCounterValue(ETH_OS_COUNTER_ID, &curTick);

    while ((E_OK == status) && (delayInTicks >= elapsed))
    {
        /* Read the BMSR register (addr 0x01) */
        retVal = EthTrcv_readReg(trcv, ETHTRCV_BMSR, &val);
        if (E_OK != retVal)
        {
            break;
        }

        /* Link is up when "Link Status" bit is set */
        if (ETHTRCV_BMSR_LINKVALID ==
            (val & ETHTRCV_BMSR_LINKSTATUS_MASK))
        {
            success = 1U;
            break;
        }

        tempCount = curTick;
        status = GetElapsedValue(ETH_OS_COUNTER_ID, &tempCount, &elapsed);
    }

    if (!success)
    {
        retVal = E_NOT_OK;
    }

    return retVal;
}

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define ETHTRCV_START_SEC_CODE
#include "EthTrcv_MemMap.h"

Std_ReturnType EthTrcv_reset(EthTrcv_Trcv *trcv)
{
    uint32 retry = ETHTRCV_RESET_RETRY_NUM + 1U;
    uint32 mask;
    uint16 val;
    Std_ReturnType retVal;

    /* Write the BMCR register (addr 0x00) and set the "PHY Reset" bit */
    mask = ETHTRCV_BMCR_RESET_MASK;
    val = ETHTRCV_BMCR_RESET;
    retVal = EthTrcv_rmwReg(trcv, ETHTRCV_BMCR, mask, val);

    /* Wait for reset to complete */
    if (E_OK == retVal)
    {
        while (--retry > 0U)
        {
            retVal = EthTrcv_readReg(trcv, ETHTRCV_BMCR, &val);
            if (E_OK != retVal)
            {
                break;
            }

            if (ETHTRCV_BMCR_RESET !=
                (val & ETHTRCV_BMCR_RESET_MASK))
            {
                break;
            }
        }

        if (0U == retry)
        {
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

static void EthTrcv_setClkShift(EthTrcv_Trcv *trcv,
                                boolean txShiftEnable,
                                boolean rxShiftEnable)
{
    uint16 val;

    val = DP83867_RGMIICTL_RGMIIEN;
    val |= (txShiftEnable == TRUE) ? DP83867_RGMIICTL_TXCLKDLY : 0U;
    val |= (rxShiftEnable == TRUE) ? DP83867_RGMIICTL_RXCLKDLY : 0U;

    EthTrcv_rmwExtReg(trcv, DP83867_RGMIICTL,
                      DP83867_RGMIICTL_RGMIIEN |
                      DP83867_RGMIICTL_TXCLKDLY |
                      DP83867_RGMIICTL_RXCLKDLY,
                      val);
}

static Std_ReturnType EthTrcv_setTxFifoDepth(EthTrcv_Trcv *trcv,
                                             uint8 depth)
{
    uint16 val = 0U;
    Std_ReturnType retVal = E_OK;

    switch (depth)
    {
        case 3U:
            val = DP83867_PHYCR_TXFIFODEPTH_3B;
            break;

        case 4U:
            val = DP83867_PHYCR_TXFIFODEPTH_4B;
            break;

        case 6U:
            val = DP83867_PHYCR_TXFIFODEPTH_6B;
            break;

        case 8U:
            val = DP83867_PHYCR_TXFIFODEPTH_8B;
            break;

        default:
            retVal = E_NOT_OK;
            break;
    }

    if (E_OK == retVal)
    {
        EthTrcv_rmwReg(trcv, DP83867_PHYCR, DP83867_PHYCR_TXFIFODEPTH_MASK, val);
    }

    return retVal;
}

static Std_ReturnType EthTrcv_setClkDelay(EthTrcv_Trcv *trcv,
                                          uint32 txDelay,
                                          uint32 rxDelay)
{
    uint16 val;
    uint32 delay;
    uint32 delayCtrl;
    Std_ReturnType retVal = E_OK;

    if ((txDelay <= DP83867_RGMIIDCTL_DELAY_MAX) &&
        (rxDelay <= DP83867_RGMIIDCTL_DELAY_MAX))
    {
        /* Avoids wrong value of delayCtrl if txDelay is 0 */
        delay = (txDelay > 0U) ? txDelay : 1U;
        delayCtrl = ETHTRCV_DIV_ROUNDUP(delay, DP83867_RGMIIDCTL_DELAY_STEP) - 1U;
        val = (uint16)((delayCtrl << DP83867_RGMIIDCTL_TXDLYCTRL_OFFSET) &
                       DP83867_RGMIIDCTL_TXDLYCTRL_MASK);

        /* Avoids wrong value of delayCtrl if rxDelay is 0 */
        delay = (rxDelay > 0U) ? rxDelay : 1U;
        delayCtrl = ETHTRCV_DIV_ROUNDUP(delay, DP83867_RGMIIDCTL_DELAY_STEP) - 1U;
        val |= (uint16)((delayCtrl << DP83867_RGMIIDCTL_RXDLYCTRL_OFFSET) &
                        DP83867_RGMIIDCTL_RXDLYCTRL_MASK);

        EthTrcv_writeExtReg(trcv, DP83867_RGMIIDCTL, val);
    }
    else
    {
        retVal = E_NOT_OK;
    }

    return retVal;
}

static Std_ReturnType EthTrcv_setOutputImpedance(EthTrcv_Trcv *trcv,
                                                 uint32 impedance)
{
    Std_ReturnType retVal = E_OK;
    uint32 val;

    if ((impedance >= DP83867_IOMUXCFG_IOIMPEDANCE_MIN) &&
        (impedance <= DP83867_IOMUXCFG_IOIMPEDANCE_MAX))
    {
        val = (DP83867_IOMUXCFG_IOIMPEDANCE_MAX - impedance) *
              DP83867_IOMUXCFG_IOIMPEDANCE_MASK;
        val = (val + DP83867_IOMUXCFG_IOIMPEDANCE_RANGE / 2) /
              DP83867_IOMUXCFG_IOIMPEDANCE_RANGE;

        EthTrcv_rmwExtReg(trcv, DP83867_IOMUXCFG,
                          DP83867_IOMUXCFG_IOIMPEDANCE_MASK,
                          val);
    }
    else
    {
        retVal = E_NOT_OK;
    }

    return retVal;
}

static uint32 EthTrcv_getId(EthTrcv_Trcv *trcv)
{
    Std_ReturnType retVal;
    uint16 phyId1;
    uint16 phyId2;

    retVal = EthTrcv_readReg(trcv, ETHTRCV_PHYIDR1, &phyId1);
    if (E_OK == retVal)
    {
        retVal = EthTrcv_readReg(trcv, ETHTRCV_PHYIDR2, &phyId2);
    }

    if (E_OK != retVal)
    {
        phyId1 = 0U;
        phyId2 = 0U;
    }

    return ((phyId1 << 16U) | phyId2);
}

Std_ReturnType EthTrcv_setAutoNegAdv(EthTrcv_Trcv *trcv,
                                     EthTrcv_ControllerConfigType *cfg)
{
    uint16 mask;
    uint16 val;
    Std_ReturnType retVal = E_OK;

    if (TRCV_PHYS_LAYER_TYPE_1000BASE_T == cfg->physLayerType)
    {
        /* TRCV_PHYS_LAYER_TYPE_1000BASE_T is supported */
        /* 10 or 100 MB baud rates requires ANAR register */
        mask = ETHTRCV_ANAR_10BASET_MASK |
               ETHTRCV_ANAR_100BASETX_MASK;
        val = 0U;

        /* Enable the highest baud rate approved by cfg */
        if (ETHTRCV_BAUD_RATE_10MBIT <= cfg->baudRate)
        {
            val |= ETHTRCV_ANAR_10BASETHALFDUPLEX;
            val |= ETHTRCV_ANAR_10BASETFULLDUPLEX;
        }
        if (ETHTRCV_BAUD_RATE_100MBIT <= cfg->baudRate)
        {
            val |= ETHTRCV_ANAR_100BASETXHALFDUPLEX;
            val |= ETHTRCV_ANAR_100BASETXFULLDUPLEX;
        }
        retVal |= EthTrcv_rmwReg(trcv, ETHTRCV_ANAR, mask, val);

        /* 1 GB baud rates requires CFG1 register */
        mask = ETHTRCV_CFG1_1000BASET_MASK;
        val = 0U;

        /* Enable the highest baud rate approved by cfg */
        if (ETHTRCV_BAUD_RATE_1000MBIT <= cfg->baudRate)
        {
            /* 1G Half Duplex is currently not supported */
            /* val |= ETHTRCV_CFG1_1000BASETHALFDUPLEX; */
            val |= ETHTRCV_CFG1_1000BASETFULLDUPLEX;
        }
        retVal |= EthTrcv_rmwReg(trcv, ETHTRCV_CFG1, mask, val); 
    }
    else if (TRCV_PHYS_LAYER_TYPE_1000BASE_T1 == cfg->physLayerType)
    {
        /* TRCV_PHYS_LAYER_TYPE_1000BASE_T1 is not supported */
        retVal = E_NOT_OK;
    }
    else if (TRCV_PHYS_LAYER_TYPE_100BASE_T1 == cfg->physLayerType)
    {
        /* TRCV_PHYS_LAYER_TYPE_100BASE_T1 is not supported */
        retVal = E_NOT_OK;
    }
    else if (TRCV_PHYS_LAYER_TYPE_100BASE_TX == cfg->physLayerType)
    {
        /* TRCV_PHYS_LAYER_TYPE_100BASE_TX is supported */
        /* 10 or 100 MB baud rates requires ANAR register */
        mask = ETHTRCV_ANAR_100BASETX_MASK |
               ETHTRCV_ANAR_10BASET_MASK;
        val = 0U;
        
        /* Use the highest baud rate approved by cfg */
        if (ETHTRCV_BAUD_RATE_10MBIT <= cfg->baudRate)
        {
            val |= ETHTRCV_ANAR_10BASETHALFDUPLEX;
            val |= ETHTRCV_ANAR_10BASETFULLDUPLEX;
        }
        if (ETHTRCV_BAUD_RATE_100MBIT <= cfg->baudRate)
        {
            val |= ETHTRCV_ANAR_100BASETXHALFDUPLEX;
            val |= ETHTRCV_ANAR_100BASETXFULLDUPLEX;
        }
        retVal |= EthTrcv_rmwReg(trcv, ETHTRCV_ANAR, mask, val);

        /* 1 GB baud rate is not supported */
        mask = ETHTRCV_CFG1_1000BASET_MASK;
        /* Make sure 1 GB is disabled */
        /* ~(uint16)ETHTRCV_CFG1_1000THALFDUPLEX is 0 */
        /* ~(uint16)ETHTRCV_CFG1_1000TFULLDUPLEX is 0 */
        val = 0U;

        retVal |= EthTrcv_rmwReg(trcv, ETHTRCV_CFG1, mask, val); 
    }
    else
    {
        /* Undefined physLayerType */
        retVal = E_NOT_OK;
    }

    return retVal;
}

Std_ReturnType EthTrcv_configExtendedRegs(EthTrcv_Trcv *trcv,
                                          const void *extendedCfg,
                                          boolean useRGMII)
{
    Std_ReturnType retVal = E_OK;
    uint32 phyId;

    phyId = EthTrcv_getId(trcv);

    if (TRUE == EthTrcv_supportPhyId(phyId))
    {
        const Dp83867_ConfigType *cfg =
            (const Dp83867_ConfigType *)extendedCfg;

        /* Only required in RGMII mode */
        if (TRUE == useRGMII)
        {
            /* Enable/disable RGMII clock shift and clock delay */
            EthTrcv_setClkShift(trcv, cfg->txClkShiftEnable, cfg->rxClkShiftEnable);

            /* Set RGMII clock delay */
            retVal = EthTrcv_setClkDelay(trcv, cfg->txDelayInPs, cfg->rxDelayInPs);
        }

        /* Set TX FIFO depth */
        if (E_OK == retVal)
        {
            retVal = EthTrcv_setTxFifoDepth(trcv, cfg->txFifoDepth);
        }

        /* Set output impedance */
        if (E_OK == retVal)
        {
            retVal = EthTrcv_setOutputImpedance(trcv,
                                                cfg->outputImpedanceInMilliOhms);
        }
    }
    else
    {
        /* PHY not supported by this driver */
        retVal = E_NOT_OK;
    }

    return retVal;
}

Std_ReturnType EthTrcv_configMacLayer(EthTrcv_Trcv *trcv,
                                      EthTrcv_ControllerConfigType *cfg)
{
    Std_ReturnType retVal = E_OK;

    if (TRCV_MAC_LAYER_TYPE_XGMII == cfg->portMacLayerType)
    {
        if (REDUCED == cfg->portMacLayerSubType)
        {
            /* RGMII mode */
            retVal = EthTrcv_configExtendedRegs(trcv, cfg->extendedConfig, TRUE);
        }
        else if (STANDARD == cfg->portMacLayerSubType)
        {
            /* GMII mode */
            retVal = EthTrcv_configExtendedRegs(trcv, cfg->extendedConfig, FALSE);
        }
        else
        {
            /* SGMII mode, etc. are not supported */
            retVal = E_NOT_OK;
        }
    }
    else if (TRCV_MAC_LAYER_TYPE_XMII == cfg->portMacLayerType)
    {
        if (STANDARD == cfg->portMacLayerSubType)
        {
            /* RMII mode */
            retVal = EthTrcv_configExtendedRegs(trcv, cfg->extendedConfig, FALSE);
        }
        else
        {
            /* MII mode, etc. are not supported */
            retVal = E_NOT_OK;
        }
    }
    else
    {
        /* USXGMII mode, etc. are not supported */
        retVal = E_NOT_OK;
    }

    return retVal;
}

Std_ReturnType EthTrcv_setConfigAutoNeg(EthTrcv_Trcv *trcv,
                                        EthTrcv_ControllerConfigType *cfg)
{
    uint16 mask;
    uint16 val;
    Std_ReturnType retVal = E_OK;

    /* Set Mac layer registers for PHY-related configs */
    if (NULL_PTR != cfg->extendedConfig)
    {
        retVal = EthTrcv_configMacLayer(trcv, cfg);
    }

    /* Use autonegotiation mode */
    if (E_OK == retVal)
    {
        /* Set physical layer registers for auto-negotiation capabilities */
        if (E_OK == retVal)
        {
            retVal = EthTrcv_setAutoNegAdv(trcv, cfg);
        }

        /* Enable auto-negotiation */
        if (E_OK == retVal)
        {
            mask = ETHTRCV_BMCR_ANEGENABLE_MASK;
            val = ETHTRCV_BMCR_ANEGENABLE;
            retVal = EthTrcv_rmwReg(trcv, ETHTRCV_BMCR, mask, val);
        }
    }

    return retVal;
}

Std_ReturnType EthTrcv_setConfigManual(EthTrcv_Trcv *trcv,
                                       EthTrcv_ControllerConfigType *cfg)
{
    uint16 mask;
    uint16 val;
    Std_ReturnType retVal = E_OK;

    /* Set Mac layer registers for PHY-related configs */
    if (NULL_PTR != cfg->extendedConfig)
    {
        retVal = EthTrcv_configMacLayer(trcv, cfg);
    }

    /* Use manual mode */
    if (E_OK == retVal)
    {
        /* Check if user passed in 1Gbps Half Duplex, which is not supported */
        if ((ETHTRCV_BAUD_RATE_1000MBIT == cfg->baudRate) && 
            (ETHTRCV_DUPLEX_MODE_HALF) == cfg->duplexMode)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            /* Disable auto-negotiation, set speed and duplexity */
            mask = ETHTRCV_BMCR_ANEGENABLE_MASK |
                ETHTRCV_BMCR_SPEED_MASK |
                ETHTRCV_BMCR_DUPLEXMODE_MASK;

            /* Disable auto-negotiation */
            /* ~(uint16)ETHTRCV_BMCR_ANEGENABLE is 0 */
            val = 0U;

            /* Set speed */
            if (ETHTRCV_BAUD_RATE_10MBIT == cfg->baudRate)
            {
                val |= ETHTRCV_BMCR_SPEED_10;
            }
            else if (ETHTRCV_BAUD_RATE_100MBIT == cfg->baudRate)
            {
                val |= ETHTRCV_BMCR_SPEED_100;
            }
            else if (ETHTRCV_BAUD_RATE_1000MBIT == cfg->baudRate)
            {
                val |= ETHTRCV_BMCR_SPEED_1000;
            }
            else
            {
                retVal = E_NOT_OK;
            }

            /* Set duplex mode */
            if (ETHTRCV_DUPLEX_MODE_HALF == cfg->duplexMode)
            {
                val |= ETHTRCV_BMCR_HALFDUPLEX;
            }
            else if (ETHTRCV_DUPLEX_MODE_FULL == cfg->duplexMode)
            {
                val |= ETHTRCV_BMCR_FULLDUPLEX;
            }
            else
            {
                retVal = E_NOT_OK;
            }

            if (E_OK == retVal)
            {
                retVal = EthTrcv_rmwReg(trcv, ETHTRCV_BMCR, mask, val);
            }
        }
    }

    return retVal;
}

Std_ReturnType EthTrcv_enableLoopback(EthTrcv_Trcv *trcv,
                                      boolean enable)
{
    uint16 mask;
    uint16 val;
    Std_ReturnType retVal;

    mask = ETHTRCV_BMCR_LOOPBACK_MASK;

    if (TRUE == enable)
    {
        val = ETHTRCV_BMCR_LOOPBACK;
    }
    else
    {
        val = ~(uint16)ETHTRCV_BMCR_LOOPBACK;
    }

    /* Write the BMCR register (addr 0x00) and set the "Loopback" bit
     * to enter into loopback mode */
    retVal = EthTrcv_rmwReg(trcv, ETHTRCV_BMCR, mask, val);

    return retVal;
}

Std_ReturnType EthTrcv_getAutoNegSpeed(EthTrcv_Trcv *trcv,
                                       EthTrcv_ControllerConfigType *cfg,
                                       EthTrcv_BaudRateType *speed)
{
    Std_ReturnType retVal;
    uint32 capab, selfCapab, partnerCapab;

    /* Get autonegotiation self ability */
    retVal = EthTrcv_getAutoNegSelfAbility(trcv, &selfCapab);

    if (E_OK == retVal)
    {
        /* Get partner ability in autonegotiation mode */
        retVal = EthTrcv_getAutoNegPartnerAbility(trcv, &partnerCapab);
    }

    if (E_OK == retVal)
    {
        /* See what's supported for both sides */
        capab = selfCapab & partnerCapab;
    }

    if (E_OK == retVal)
    {
        if ((0U != (capab & ETHERNET_ADV_1000_FULL)) ||
            (0U != (capab & ETHERNET_ADV_1000_HALF)))
        {
            /* 1000 Mbps */
            *speed = ETHTRCV_BAUD_RATE_1000MBIT;
        }
        else if ((0U != (capab & ETHERNET_ADV_100_FULL)) ||
                 (0U != (capab & ETHERNET_ADV_100_HALF)))
        {
            /* 100 Mbps */
            *speed = ETHTRCV_BAUD_RATE_100MBIT;
        }
        else if ((0U != (capab & ETHERNET_ADV_10_FULL)) ||
                 (0U != (capab & ETHERNET_ADV_10_HALF)))
        {
            /* 10 Mbps */
            *speed = ETHTRCV_BAUD_RATE_10MBIT;
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

Std_ReturnType EthTrcv_getManualSpeed(EthTrcv_Trcv *trcv,
                                      EthTrcv_ControllerConfigType *cfg,
                                      EthTrcv_BaudRateType *speed)
{
    Std_ReturnType retVal;
    uint16 val;

    /* Read the BMCR register (addr 0x00) and get the capabilities */
    retVal = EthTrcv_readReg(trcv, ETHTRCV_BMCR, &val);
    if (E_OK == retVal)
    {
        if (ETHTRCV_BMCR_SPEED_1000 ==
            (val & ETHTRCV_BMCR_SPEED_MASK))
        {
            /* 1000 Mbps */
            *speed = ETHTRCV_BAUD_RATE_1000MBIT;
        }
        else if (ETHTRCV_BMCR_SPEED_100 ==
                 (val & ETHTRCV_BMCR_SPEED_MASK))
        {
            /* 100 Mbps */
            *speed = ETHTRCV_BAUD_RATE_100MBIT;
        }
        else if (ETHTRCV_BMCR_SPEED_10 ==
                 (val & ETHTRCV_BMCR_SPEED_MASK))
        {
            /* 10 Mbps */
            *speed = ETHTRCV_BAUD_RATE_10MBIT;
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

Std_ReturnType EthTrcv_getAutoNegDuplex(EthTrcv_Trcv *trcv,
                                        EthTrcv_ControllerConfigType *cfg,
                                        EthTrcv_DuplexModeType *duplex)
{
    Std_ReturnType retVal;
    uint32 capab, selfCapab, partnerCapab;

    /* Get autonegotiation self ability */
    retVal = EthTrcv_getAutoNegSelfAbility(trcv, &selfCapab);

    if (E_OK == retVal)
    {
        /* Get partner ability in autonegotiation mode */
        retVal = EthTrcv_getAutoNegPartnerAbility(trcv, &partnerCapab);
    }

    if (E_OK == retVal)
    {
        /* See what's supported for both sides */
        capab = selfCapab & partnerCapab;
    }

    if (E_OK == retVal)
    {
        if ((0U != (capab & ETHERNET_ADV_1000_FULL)) ||
            (0U != (capab & ETHERNET_ADV_100_FULL)) ||
            (0U != (capab & ETHERNET_ADV_10_FULL)))
        {
            /* full-duplex */
            *duplex = ETHTRCV_DUPLEX_MODE_FULL;
        }
        else if ((0U != (capab & ETHERNET_ADV_1000_HALF)) ||
                 (0U != (capab & ETHERNET_ADV_100_HALF)) ||
                 (0U != (capab & ETHERNET_ADV_10_HALF)))
        {
            /* half-duplex */
            *duplex = ETHTRCV_DUPLEX_MODE_HALF;
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

Std_ReturnType EthTrcv_getManualDuplex(EthTrcv_Trcv *trcv,
                                       EthTrcv_ControllerConfigType *cfg,
                                       EthTrcv_DuplexModeType *duplex)
{
    Std_ReturnType retVal;
    uint16 val;

    /* Read the BMCR register (addr 0x00) and get the capabilities */
    retVal = EthTrcv_readReg(trcv, ETHTRCV_BMCR, &val);
    if (E_OK == retVal)
    {
        if (ETHTRCV_BMCR_FULLDUPLEX ==
            (val & ETHTRCV_BMCR_DUPLEXMODE_MASK))
        {
            /* full-duplex */
            *duplex = ETHTRCV_DUPLEX_MODE_FULL;
        }
        else if (ETHTRCV_BMCR_HALFDUPLEX ==
                 (val & ETHTRCV_BMCR_DUPLEXMODE_MASK))
        {
            /* half-duplex */
            *duplex = ETHTRCV_DUPLEX_MODE_HALF;
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

boolean EthTrcv_isLinked(EthTrcv_Trcv *trcv)
{
    uint16 val;
    boolean valid = FALSE;
    Std_ReturnType retVal;

    /* Read the BMCR register (addr 0x00) */
    retVal = EthTrcv_readReg(trcv, ETHTRCV_BMCR, &val);
    if (E_OK == retVal)
    {
        /* Determine loopback mode from "Loopback" field */
        if (ETHTRCV_BMCR_LOOPBACK ==
            (val & ETHTRCV_BMCR_LOOPBACK_MASK))
        {
            /* Loopback mode, link invalid */
            valid = FALSE;
        }
        else
        {
            /* Read the BMSR register (addr 0x01) */
            retVal = EthTrcv_readReg(trcv, ETHTRCV_BMSR, &val);
            if (E_OK == retVal)
            {
                /* Determine status from "Link Status" field */
                if (ETHTRCV_BMSR_LINKVALID ==
                    (val & ETHTRCV_BMSR_LINKSTATUS_MASK))
                {
                    /* Not loopback mode, link valid */
                    valid = TRUE;
                }
                else
                {
                    /* Not loopback mode, link invalid */
                    valid = FALSE;
                }
            }
        }
    }

    return valid;
}

#if (STD_ON == ETH_WRAPPER_ENABLED)
Std_ReturnType EthTrcv_readReg(EthTrcv_Trcv *trcv,
                               uint8 reg,
                               uint16 *val)
{
    Std_ReturnType retVal = E_NOT_OK;

    /* Read the PHY register */
#if (STD_ON == ETH_ENABLE_MII_API)
    retVal = Eth_30_Wrapper_ReadMii(trcv->ctrlIdx, trcv->miiIdx, reg, val);
#endif

    /* Eth_30_Wrapper_ReadMii() already wait for MDIO command completed ISR
     * No need to wait here
     */

    return retVal;
}

Std_ReturnType EthTrcv_writeReg(EthTrcv_Trcv *trcv,
                                uint8 reg,
                                uint16 val)
{
    Std_ReturnType retVal = E_NOT_OK;

#if (STD_ON == ETH_ENABLE_MII_API)
    retVal = Eth_30_Wrapper_WriteMii(trcv->ctrlIdx, trcv->miiIdx, reg, val);
#endif

    /* Eth_30_Wrapper_WriteMii() already wait for MDIO command completed ISR
     * No need to wait here
     */

    return retVal;
}

#else /* (STD_ON == ETH_WRAPPER_ENABLED) */

Std_ReturnType EthTrcv_readReg(EthTrcv_Trcv *trcv,
                               uint8 reg,
                               uint16 *val)
{
    Std_ReturnType retVal = E_OK;
    uint32 timeoutCnt = 0u;

    mdioRdCmdComplete = FALSE;

    /* Read the PHY register */
#if (STD_ON == ETH_ENABLE_MII_API)
    retVal = Eth_ReadMii(trcv->ctrlIdx, trcv->miiIdx, reg, val);
#endif

    if(E_OK == retVal)
    {
        while(FALSE == mdioRdCmdComplete)
        {
            if(ETHTRCV_TIMEOUT_DURATION == timeoutCnt)
            {
#if (ETHTRCV_DEM_EVENT_SUPPORT == STD_ON)
#if (ETHTRCV_E_HARDWARE_ERROR != ETHTRCV_DEM_NO_EVENT)
                (void)Dem_SetEventStatus(ETHTRCV_E_HARDWARE_ERROR,
                                      DEM_EVENT_STATUS_FAILED);
#endif
#endif
                retVal = E_NOT_OK;
                break;
            }
            timeoutCnt++;
        }
    }

    if (E_OK == retVal)
    {
        *val = mdioRdVal;
    }

    return retVal;
}

Std_ReturnType EthTrcv_writeReg(EthTrcv_Trcv *trcv,
                                uint8 reg,
                                uint16 val)
{
    Std_ReturnType retVal = E_OK;
    uint32 timeoutCnt = 0u;

    mdioWrCmdComplete = FALSE;

    /* Write the PHY register */
#if (STD_ON == ETH_ENABLE_MII_API)
    retVal = Eth_WriteMii(trcv->ctrlIdx, trcv->miiIdx, reg, val);
#endif

    if(E_OK == retVal)
    {
        while(FALSE == mdioWrCmdComplete)
        {
            if(ETHTRCV_TIMEOUT_DURATION == timeoutCnt)
            {
#if (ETHTRCV_DEM_EVENT_SUPPORT == STD_ON)
#if (ETHTRCV_E_HARDWARE_ERROR != ETHTRCV_DEM_NO_EVENT)
                (void)Dem_SetEventStatus(ETHTRCV_E_HARDWARE_ERROR,
                                      DEM_EVENT_STATUS_FAILED);
#endif
#endif
                retVal = E_NOT_OK;
                break;
            }
            timeoutCnt++;
        }
    }

    return retVal;
}

#endif /* (STD_ON == ETH_WRAPPER_ENABLED) */

Std_ReturnType EthTrcv_rmwReg(EthTrcv_Trcv *trcv,
                              uint8 reg,
                              uint16 mask,
                              uint16 val)
{
    Std_ReturnType retVal;
    uint16 tmp;

    retVal = EthTrcv_readReg(trcv, reg, &tmp);
    if (E_OK == retVal)
    {
        val &= mask;
        tmp &= ~mask;
        retVal = EthTrcv_writeReg(trcv, reg, tmp | val);
    }

    return retVal;
}

Std_ReturnType EthTrcv_readExtReg(EthTrcv_Trcv *trcv,
                                  uint16 reg,
                                  uint16 *val)
{
    uint16 devad = ETHTRCV_MMD_CR_DEVADDR;
    Std_ReturnType retVal;

    retVal = EthTrcv_writeReg(trcv, ETHTRCV_MMD_CR,
                              devad | ETHTRCV_MMD_CR_ADDR);
    if (E_OK == retVal)
    {
        retVal = EthTrcv_writeReg(trcv, ETHTRCV_MMD_DR, reg);
    }

    if (E_OK == retVal)
    {
        EthTrcv_writeReg(trcv, ETHTRCV_MMD_CR,
                         devad | ETHTRCV_MMD_CR_DATA_NOPOSTINC);
    }

    if (E_OK == retVal)
    {
        retVal = EthTrcv_readReg(trcv, ETHTRCV_MMD_DR, val);
    }

    return retVal;
}

Std_ReturnType EthTrcv_writeExtReg(EthTrcv_Trcv *trcv,
                                   uint16 reg,
                                   uint16 val)
{
    uint16 devad = ETHTRCV_MMD_CR_DEVADDR;
    Std_ReturnType retVal;

    retVal = EthTrcv_writeReg(trcv, ETHTRCV_MMD_CR,
                              devad | ETHTRCV_MMD_CR_ADDR);
    if (E_OK == retVal)
    {
        retVal = EthTrcv_writeReg(trcv, ETHTRCV_MMD_DR, reg);
    }

    if (E_OK == retVal)
    {
        EthTrcv_writeReg(trcv, ETHTRCV_MMD_CR,
                         devad | ETHTRCV_MMD_CR_DATA_NOPOSTINC);
    }

    if (E_OK == retVal)
    {
        retVal = EthTrcv_writeReg(trcv, ETHTRCV_MMD_DR, val);
    }

    return retVal;
}

Std_ReturnType EthTrcv_rmwExtReg(EthTrcv_Trcv *trcv,
                                 uint16 reg,
                                 uint16 mask,
                                 uint16 val)
{
    uint16 devad = ETHTRCV_MMD_CR_DEVADDR;
    uint16 data;
    Std_ReturnType retVal;

    EthTrcv_writeReg(trcv, ETHTRCV_MMD_CR,
                     devad | ETHTRCV_MMD_CR_ADDR);
    EthTrcv_writeReg(trcv, ETHTRCV_MMD_DR, reg);
    EthTrcv_writeReg(trcv, ETHTRCV_MMD_CR,
                     devad | ETHTRCV_MMD_CR_DATA_NOPOSTINC);
    retVal = EthTrcv_readReg(trcv, ETHTRCV_MMD_DR, &data);

    if (E_OK == retVal)
    {
        data = (data & ~mask) | (val & mask);
        EthTrcv_writeReg(trcv, ETHTRCV_MMD_CR,
                         devad | ETHTRCV_MMD_CR_DATA_NOPOSTINC);
        EthTrcv_writeReg(trcv, ETHTRCV_MMD_DR, data);
    }

    return retVal;
}

Std_ReturnType EthTrcv_checkTransceiverAccess(EthTrcv_Trcv *trcv)
{
    uint16 val;
    Std_ReturnType retVal;

    /* Check if Ethernet transceiver is present or not by checking
     * if BMSR register read goes through */
    retVal = EthTrcv_readReg(trcv, ETHTRCV_BMSR, &val);
    if (E_OK != retVal)
    {
#if (ETHTRCV_DEM_EVENT_SUPPORT == STD_ON)
#if (ETHTRCV_E_ACCESS != ETHTRCV_DEM_NO_EVENT)
        (void)Dem_SetEventStatus(ETHTRCV_E_ACCESS,
                              DEM_EVENT_STATUS_PREFAILED);
#endif
#endif
    }

    return retVal;
}

#if defined(ETHTRCV_DEBUG)
extern void AppUtils_printf(const char *pcString, ...);

void EthTrcv_dumpRegs(EthTrcv_Trcv *trcv)
{
    uint16 val;

    EthTrcv_readReg(trcv, ETHTRCV_BMCR, &val);
    AppUtils_printf("BMCR    = 0x%04x\n", val & 0xFFFFU);

    EthTrcv_readReg(trcv, ETHTRCV_BMSR, &val);
    AppUtils_printf("BMSR    = 0x%04x\n", val & 0xFFFFU);

    EthTrcv_readReg(trcv, ETHTRCV_PHYIDR1, &val);
    AppUtils_printf("PHYIDR1 = 0x%04x\n", val & 0xFFFFU);

    EthTrcv_readReg(trcv, ETHTRCV_PHYIDR2, &val);
    AppUtils_printf("PHYIDR2 = 0x%04x\n", val & 0xFFFFU);

    EthTrcv_readReg(trcv, ETHTRCV_ANAR, &val);
    AppUtils_printf("ANAR    = 0x%04x\n", val & 0xFFFFU);

    EthTrcv_readReg(trcv, ETHTRCV_ANLPAR, &val);
    AppUtils_printf("ANLPAR  = 0x%04x\n", val & 0xFFFFU);

    EthTrcv_readReg(trcv, ETHTRCV_ANER, &val);
    AppUtils_printf("ANER    = 0x%04x\n", val & 0xFFFFU);

    EthTrcv_readReg(trcv, ETHTRCV_ANNPTR, &val);
    AppUtils_printf("ANNPTR  = 0x%04x\n", val & 0xFFFFU);

    EthTrcv_readReg(trcv, ETHTRCV_ANNPRR, &val);
    AppUtils_printf("ANNPRR  = 0x%04x\n", val & 0xFFFFU);

    EthTrcv_readReg(trcv, ETHTRCV_CFG1, &val);
    AppUtils_printf("CFG1    = 0x%04x\n", val & 0xFFFFU);

    EthTrcv_readReg(trcv, ETHTRCV_STS1, &val);
    AppUtils_printf("STS1    = 0x%04x\n", val & 0xFFFFU);
}
#endif

#define ETHTRCV_STOP_SEC_CODE
#include "EthTrcv_MemMap.h"
