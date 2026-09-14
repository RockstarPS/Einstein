/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*   @file Eth_DrvInit.c
*   @ingroup Eth
*   @brief This file handles the actions to be done for enabling Ethernet and and then calling Eth Init.
*   The functions are taken from the TI Eth examples from the mcu sdk.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "Eth.h"
#include "EthTrcv.h"
#include <drivers/sciclient.h>
#include <drivers/pinmux.h>
#include "cslr.h"
#include "app_utils.h"
#include "ComM.h"
#include "ComM_EcuMBswM.h"
#include "SoAd.h"
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
#define ETH_DEFAULT_TX_PRIORITY         (0u)
/** \brief Experimental EtherType used in test packets */
#define ETHERTYPE_EXPERIMENTAL1         (0x88b5U)

/** \brief RMII port interface (CTRLMMR_MCU_ENET_CTRL) */
#define ENET_CTRL_MODE_RMII                 (1U)

/** \brief RGMII port interface (CTRLMMR_MCU_ENET_CTRL) */
#define ENET_CTRL_MODE_RGMII                (2U)

/** \brief RGMII_ID_MODE shift value in CTRLMMR_MCU_ENET_CTRL register */
#define ENET_CTRL_RGMII_ID_SHIFT            (4U)

/** \brief Internal TX delay in RGMII interface (CTRLMMR_MCU_ENET_CTRL) */
#define ENET_CTRL_RGMII_ID_NODELAY          ((boolean)1U)
/** \brief MMR0 ENET1 control register address */
#define CTRL_MMR0_CFG0_ENET1_CTRL           (0x000104044U)

/** \brief MMR0 ENET2 control register address */
#define CTRL_MMR0_CFG0_ENET2_CTRL           (0x000104048U)

/* \brief ENET offset value for enet control register */
#define CTRL_MMR0_CFG0_ENET_OFFSET(macPort) (((macPort)-1)*0x4u)

/** \brief LOCK1_KICK0 register address  */
#define CFG0_CTRL_MMR_LOCK1_KICK0           (0x000105008U)

/** \brief LOCK1_KICK1 register address  */
#define CFG0_CTRL_MMR_LOCK1_KICK1           (0x00010500CU)

/** \brief CPSW (CPTS) Clock selection register */
#define CFG0_CTRL_MMR_CPSW_CLKSEL_REG       (0x00108140U)

/** \brief CPSW (CPTS) Clock selection value to be set
 *   Valid Values:
 *   - 3'b000 -> MAIN_PLL2_HSDIV5_CLKOUT
 *   - 3'b001 -> MAIN_PLL0_HSDIV6_CLKOUT
 *   - 3'b010 -> CP_GEMAC_CPTS0_RFT_CLK (Pin)
 *   - 3'b011 -> Reserved
 *   - 3'b100 -> MCU_EXT_REFCLK0 (Pin)
 *   - 3'b101 -> EXT_REFCLK1 (Pin)
 *   - 3'b110 -> MCU_SYSCLK0
 *   - 3'b111 -> MAIN_SYSCLK0
 */
#define MAIN_PLL0_HSDIV6_CLKOUT             (1u)

/** \brief Unlock value for lock kick 0 */
#define MMR_KICK0_UNLOCK_VAL                (0x68EF3490U)

/** \brief Unlock value for lock kick 1 */
#define MMR_KICK1_UNLOCK_VAL                (0xD172BC5AU)
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
static Pinmux_PerCfg_t MDIOPinMuxMainDomainCfg[] = {
    /* RGMII_MDIO -> MDIO0_MDC -> V12 */
    {
        PIN_MDIO0_MDC, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* RGMII_MDIO -> MDIO0_MDIO -> V13 */
    {
        PIN_MDIO0_MDIO, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END, PINMUX_END}
};
static boolean Eth_TrcvInitDone=FALSE;
/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
static void EthApp_setConnectionType(uint32 macPortNum, Eth_MacConnectionType type, boolean delay);
static void BoardUtils_setDeviceState(uint32_t moduleId,uint32_t requiredState,uint32_t appFlags);
static void BoardUtils_selectCptsClock(void);
static void BoardUtils_enableClocks(void);
static void BoardUtils_cpswMuxSel(void);
static void BoardUtils_setEnetCtrl(uint32 macPortNum, uint32 val);
/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION                                                                                   *
********************************************************************************************************************/
void Eth_DrvInit(void)
{
    Std_ReturnType RetVal;
    uint32_t moduleId = TISCI_DEV_CPSW0;
    uint32_t appFlags = 0U;
    
    /* mdio select */
    BoardUtils_cpswMuxSel();
    /* Enable clock */
    BoardUtils_setDeviceState(moduleId, TISCI_MSG_VALUE_DEVICE_SW_STATE_ON, appFlags);
    BoardUtils_selectCptsClock();
    /* set Enet type */
    if(FALSE == Eth_IsVirtualMacModeEnable(0))
    {
            EthApp_setConnectionType(Eth_GetMacPortNum(0),
            Eth_GetMiiConnectionType(0),
            ENET_CTRL_RGMII_ID_NODELAY);
    }
    /* open DMA via sci client */
    RetVal = AppUtils_EthDmaOpen(0);
    if (RetVal != E_NOT_OK)
    {
        Eth_Init(NULL_PTR);
    }
}
void Eth_DrvTrcvInit(void)
{
    Eth_ModeType EthMode=ETH_MODE_DOWN;
    (void)Eth_GetControllerMode(0,&EthMode);
    if ((EthMode == ETH_MODE_ACTIVE) && (Eth_TrcvInitDone == FALSE))
    {
        EthTrcv_Init(ETHTRCV_DRV_CONFIG_0);
        if (E_OK == EthTrcv_SetTransceiverMode(0,ETHTRCV_MODE_ACTIVE))
        {
            Eth_TrcvInitDone = TRUE;
        }
    }
}
/********************************************************************************************************************
*  PRIVATE FUNCTION IMPLEMENTATION                                                                                  *
********************************************************************************************************************/
static void EthApp_setConnectionType(uint32 macPortNum, Eth_MacConnectionType type, boolean delay)
{
    uint32 val = delay << ENET_CTRL_RGMII_ID_SHIFT;

    switch (type)
    {
        case ETH_MAC_CONN_TYPE_RMII_10:
        case ETH_MAC_CONN_TYPE_RMII_100:
            val |= ENET_CTRL_MODE_RMII;
            break;
        case ETH_MAC_CONN_TYPE_RGMII_FORCE_100_HALF:
        case ETH_MAC_CONN_TYPE_RGMII_FORCE_100_FULL:
        case ETH_MAC_CONN_TYPE_RGMII_FORCE_1000_FULL:
        case ETH_MAC_CONN_TYPE_RGMII_DETECT_INBAND:
            val |= ENET_CTRL_MODE_RGMII;
            break;
        default:
            break;
    }
    BoardUtils_setEnetCtrl(macPortNum, val);
}

static void BoardUtils_setDeviceState(uint32_t moduleId,uint32_t requiredState,uint32_t appFlags)
{
    int32_t status;
    uint32_t moduleState      = 0U;
    uint32_t resetState       = 0U;
    uint32_t contextLossState = 0U;
    Bool turnOn;
    Bool turnOff;

    status = Sciclient_pmGetModuleState(moduleId,
                                        &moduleState,
                                        &resetState,
                                        &contextLossState,
                                        SystemP_WAIT_FOREVER);

    turnOn = (moduleState == TISCI_MSG_VALUE_DEVICE_HW_STATE_OFF) &&
             (requiredState == TISCI_MSG_VALUE_DEVICE_SW_STATE_ON);
    turnOff = (moduleState == TISCI_MSG_VALUE_DEVICE_HW_STATE_ON) &&
              (requiredState == TISCI_MSG_VALUE_DEVICE_SW_STATE_AUTO_OFF);

    if (turnOn || turnOff)
    {
        status = Sciclient_pmSetModuleState(moduleId,
                                            requiredState,
                                            (appFlags |
                                             TISCI_MSG_FLAG_AOP |
                                             TISCI_MSG_FLAG_DEVICE_RESET_ISO),
                                             SystemP_WAIT_FOREVER);
        if (requiredState == TISCI_MSG_VALUE_DEVICE_SW_STATE_ON)
        {
            /* Reset if changed state to enabled */
            status = Sciclient_pmSetModuleRst(moduleId,
                                              0x0U /*resetBit*/,
                                              SystemP_WAIT_FOREVER);
            (void)status;
        }
    }
}

static void BoardUtils_selectCptsClock(void)
{
    volatile uint32_t *reg = (uint32_t*)CFG0_CTRL_MMR_CPSW_CLKSEL_REG;
    *reg = MAIN_PLL0_HSDIV6_CLKOUT;
}

static void BoardUtils_enableClocks(void)
{
    uint32_t moduleId = TISCI_DEV_CPSW0;
    uint32_t appFlags = 0U;

    BoardUtils_setDeviceState(moduleId, TISCI_MSG_VALUE_DEVICE_SW_STATE_ON, appFlags);
    BoardUtils_selectCptsClock();
}

static void BoardUtils_cpswMuxSel(void)
{
    /* MDIO0 pin config */
    Pinmux_config(MDIOPinMuxMainDomainCfg, PINMUX_DOMAIN_ID_MAIN);
    return;
}

static void BoardUtils_setEnetCtrl(uint32 macPortNum, uint32 val)
{
    uint32 *enetRegs = (uint32*)(CTRL_MMR0_CFG0_ENET1_CTRL +
                                 CTRL_MMR0_CFG0_ENET_OFFSET(macPortNum));

    CSL_REG32_WR(CFG0_CTRL_MMR_LOCK1_KICK0, MMR_KICK0_UNLOCK_VAL);
    CSL_REG32_WR(CFG0_CTRL_MMR_LOCK1_KICK1, MMR_KICK1_UNLOCK_VAL);
    CSL_REG32_WR(enetRegs, val);
}


