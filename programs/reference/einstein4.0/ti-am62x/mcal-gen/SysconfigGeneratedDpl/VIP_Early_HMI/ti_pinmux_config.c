/*
 *  Copyright (C) 2021 Texas Instruments Incorporated
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
 */

/*
 * Auto generated file
 */
#include "ti_drivers_config.h"
#include <drivers/pinmux.h>

static Pinmux_PerCfg_t gPinMuxMainDomainCfg[] = {
#ifdef AUTOSAR_ETH_ENABLE
    /* pchinnat : added manually for ethernet  */
    /* EthernetPHY1 -> RGMII1_RD0 -> AB16 */
    {
        PIN_RGMII1_RD0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* EthernetPHY1 -> RGMII1_RD1 -> V15 */
    {
        PIN_RGMII1_RD1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* EthernetPHY1 -> RGMII1_RD2 -> W15 */
    {
        PIN_RGMII1_RD2, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* EthernetPHY1 -> RGMII1_RD3 -> V14 */
    {
        PIN_RGMII1_RD3, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* EthernetPHY1 -> RGMII1_RXC -> AA16 */
    {
        PIN_RGMII1_RXC, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* EthernetPHY1 -> RGMII1_RX_CTL -> AA15 */
    {
        PIN_RGMII1_RX_CTL, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* EthernetPHY1 -> RGMII1_TD0 -> Y17 */
    {
        PIN_RGMII1_TD0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* EthernetPHY1 -> RGMII1_TD1 -> V16 */
    {
        PIN_RGMII1_TD1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* EthernetPHY1 -> RGMII1_TD2 -> Y16 */
    {
        PIN_RGMII1_TD2, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* EthernetPHY1 -> RGMII1_TD3 -> AA17 */
    {
        PIN_RGMII1_TD3, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* EthernetPHY1 -> RGMII1_TXC -> AB17 */
    {
        PIN_RGMII1_TXC, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* EthernetPHY1 -> RGMII1_TX_CTL -> W16 */
    {
        PIN_RGMII1_TX_CTL, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RGMII2_EXP_CONN -> RGMII2_RD0 -> AA21 */
    {
        PIN_RGMII2_RD0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RGMII2_EXP_CONN -> RGMII2_RD1 -> Y20 */
    {
        PIN_RGMII2_RD1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RGMII2_EXP_CONN -> RGMII2_RD2 -> AB21 */
    {
        PIN_RGMII2_RD2, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RGMII2_EXP_CONN -> RGMII2_RD3 -> AB20 */
    {
        PIN_RGMII2_RD3, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RGMII2_EXP_CONN -> RGMII2_RXC -> AA20 */
    {
        PIN_RGMII2_RXC, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RGMII2_EXP_CONN -> RGMII2_RX_CTL -> W18 */
    {
        PIN_RGMII2_RX_CTL, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RGMII2_EXP_CONN -> RGMII2_TD0 -> AA19 */
    {
        PIN_RGMII2_TD0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RGMII2_EXP_CONN -> RGMII2_TD1 -> Y18 */
    {
        PIN_RGMII2_TD1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RGMII2_EXP_CONN -> RGMII2_TD2 -> AA18 */
    {
        PIN_RGMII2_TD2, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RGMII2_EXP_CONN -> RGMII2_TD3 -> W17 */
    {
        PIN_RGMII2_TD3, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RGMII2_EXP_CONN -> RGMII2_TXC -> AB19 */
    {
        PIN_RGMII2_TXC, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RGMII2_EXP_CONN -> RGMII2_TX_CTL -> Y19 */
    {
        PIN_RGMII2_TX_CTL, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
#endif
            /* EHRPWM1 pin config */
        /* EHRPWM1_A -> MCASP0_AXR1 (E24) */
    {
        PIN_MCASP0_AXR1,
        ( PIN_MODE(6) | PIN_PULL_DISABLE )
    },

            /* GPIO0 pin config */
        /* GPIO0_40 -> GPMC0_DIR (P25) */
    {
        PIN_GPMC0_DIR,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_5 -> RGMII2_RD2 (E17) */
    {
        PIN_RGMII2_RD2,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_6 -> RGMII2_RD3 (C19) */
    {
        PIN_RGMII2_RD3,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
                    /* GPIO0 pin config */
        /* GPIO0_52 -> VOUT0_DATA7 (AE23) */
    {
        PIN_VOUT0_DATA7,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_45 -> MMC1_DAT0 (H21) */
    {
        PIN_MMC1_DAT0,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_41 -> GPMC0_CSn0 (T23) */
    {
        PIN_GPMC0_CSN0,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_2 -> RGMII2_RXC (D19) */
    {
        PIN_RGMII2_RXC,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
                            /* GPIO0 pin config */
        /* GPIO0_71 -> MMC2_SDCD (J25) */
    {
        PIN_MMC2_SDCD,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_56 -> VOUT0_DATA11 (AE21) */
    {
        PIN_VOUT0_DATA11,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_55 -> VOUT0_DATA10 (W22) */
    {
        PIN_VOUT0_DATA10,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_57 -> VOUT0_DATA12 (AD21) */
    {
        PIN_VOUT0_DATA12,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_58 -> VOUT0_DATA13 (AC21) */
    {
        PIN_VOUT0_DATA13,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
                    /* GPIO0 pin config */
        /* GPIO0_32 -> GPMC0_ADVn_ALE (R25) */
    {
        PIN_GPMC0_ADVN_ALE,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_42 -> GPMC0_CSn1 (U23) */
    {
        PIN_GPMC0_CSN1,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_53 -> VOUT0_DATA8 (AE22) */
    {
        PIN_VOUT0_DATA8,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_66 -> MMC2_DAT2 (L20) */
    {
        PIN_MMC2_DAT2,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_69 -> MMC2_CLK (K21) */
    {
        PIN_MMC2_CLK,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_89 -> RGMII2_TD0 (B19) */
    {
        PIN_RGMII2_TD0,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_90 -> RGMII2_TD1 (A21) */
    {
        PIN_RGMII2_TD1,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_1 -> RGMII2_RX_CTL (F19) */
    {
        PIN_RGMII2_RX_CTL,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_11 -> MCASP0_ACLKX (F24) */
    {
        PIN_MCASP0_ACLKX,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_3 -> RGMII2_RD0 (E19) */
    {
        PIN_RGMII2_RD0,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_4 -> RGMII2_RD1 (E16) */
    {
        PIN_RGMII2_RD1,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_48 -> MMC1_SDCD (D23) */
    {
        PIN_MMC1_SDCD,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
                    /* GPIO0 pin config */
        /* GPIO0_47 -> VOUT0_DATA2 (AA23) */
    {
        PIN_VOUT0_DATA2,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_48 -> VOUT0_DATA3 (Y23) */
    {
        PIN_VOUT0_DATA3,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_50 -> VOUT0_DATA5 (AD23) */
    {
        PIN_VOUT0_DATA5,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_51 -> VOUT0_DATA6 (AC23) */
    {
        PIN_VOUT0_DATA6,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_54 -> VOUT0_DATA9 (AC22) */
    {
        PIN_VOUT0_DATA9,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_60 -> VOUT0_DATA15 (Y20) */
    {
        PIN_VOUT0_DATA15,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_61 -> VOUT0_HSYNC (AC20) */
    {
        PIN_VOUT0_HSYNC,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_62 -> VOUT0_DE (W21) */
    {
        PIN_VOUT0_DE,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_63 -> VOUT0_VSYNC (W20) */
    {
        PIN_VOUT0_VSYNC,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_67 -> MMC2_DAT1 (K22) */
    {
        PIN_MMC2_DAT1,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_68 -> MMC2_DAT0 (K23) */
    {
        PIN_MMC2_DAT0,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO0 pin config */
        /* GPIO0_70 -> MMC2_CMD (K24) */
    {
        PIN_MMC2_CMD,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_0 -> RGMII2_TD3 (A19) */
    {
        PIN_RGMII2_TD3,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_12 -> MCASP0_AFSX (F25) */
    {
        PIN_MCASP0_AFSX,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_13 -> MCASP0_AFSR (G23) */
    {
        PIN_MCASP0_AFSR,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_42 -> MMC1_DAT3 (H25) */
    {
        PIN_MMC1_DAT3,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_44 -> MMC1_DAT1 (H23) */
    {
        PIN_MMC1_DAT1,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* GPIO1 pin config */
        /* GPIO1_49 -> MMC1_SDWP (D24) */
    {
        PIN_MMC1_SDWP,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
                                
                    /* I2C3 pin config */
        /* I2C3_SCL -> UART0_CTSn (A23) */
    {
        PIN_UART0_CTSN,
        ( PIN_MODE(2) | PIN_INPUT_ENABLE | PIN_PULL_DIRECTION )
    },
        /* I2C3_SDA -> UART0_RTSn (C22) */
    {
        PIN_UART0_RTSN,
        ( PIN_MODE(2) | PIN_INPUT_ENABLE | PIN_PULL_DIRECTION )
    },
            /* I2C1 pin config */
        /* I2C1_SCL -> I2C1_SCL (C24) */
    {
        PIN_I2C1_SCL,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DIRECTION )
    },
        /* I2C1_SDA -> I2C1_SDA (B24) */
    {
        PIN_I2C1_SDA,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DIRECTION )
    },

                    /* SPI2 pin config */
        /* SPI2_CLK -> MCASP0_ACLKR (G20) */
    {
        PIN_MCASP0_ACLKR,
        ( PIN_MODE(1) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        /* SPI2_D0 -> MCASP0_AXR3 (D25) */
    {
        PIN_MCASP0_AXR3,
        ( PIN_MODE(1) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        /* SPI2_D1 -> MCASP0_AXR2 (E25) */
    {
        PIN_MCASP0_AXR2,
        ( PIN_MODE(1) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* SPI0 pin config */
        /* SPI0_CLK -> SPI0_CLK (B21) */
    {
        PIN_SPI0_CLK,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        /* SPI0_D0 -> SPI0_D0 (B20) */
    {
        PIN_SPI0_D0,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        /* SPI0_D1 -> SPI0_D1 (C21) */
    {
        PIN_SPI0_D1,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },

                            /* SPI0_CS1 pin config */
    /* SPI0_CS1 -> SPI0_CS1 (E20) */
    {
        PIN_SPI0_CS1,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },

    /* MCASP1 pin config */
	/* MCASP1_ACLKX -> GPMC0_BE0n_CLE (U24) */
    {
        PIN_GPMC0_BE0N_CLE,
        ( PIN_MODE(2) | PIN_PULL_DISABLE )
    },
    /* MCASP1_AFSX -> GPMC0_WAIT0 (AA24) */
    {
        PIN_GPMC0_WAIT0,
        ( PIN_MODE(2) | PIN_PULL_DISABLE )
    },
	/* MCASP1_AXR0 -> GPMC0_WEn (T25) */
    {
        PIN_GPMC0_WEN,
        ( PIN_MODE(2) | PIN_PULL_DISABLE )
    },
	
    /* I2C1 pin config */
            /* I2C1_SCL -> I2C1_SCL (C24) */
    {
        PIN_I2C1_SCL,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* I2C1_SDA -> I2C1_SDA (B24) */
    {
        PIN_I2C1_SDA,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
	
	/* GPIO0 pin config */
            /* GPIO0_36 -> GPMC0_BE1n (T24) */
    {
        PIN_GPMC0_BE1N,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
	
    {PINMUX_END, PINMUX_END}
};

static Pinmux_PerCfg_t gPinMuxMcuDomainCfg[] = {
            /* MCU_MCAN0 pin config - Manually Added*/
        /* MCU_MCAN0_RX -> MCU_MCAN0_RX (D6) */
    {
        PIN_MCU_MCAN0_RX,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DIRECTION )
    },
        /* MCU_MCAN0_TX -> MCU_MCAN0_TX (E8) */
    {
        PIN_MCU_MCAN0_TX,
        ( PIN_MODE(0) | PIN_PULL_DIRECTION )
    },
        
                                    /* MCU_GPIO0 pin config */
        /* MCU_GPIO0_22 -> PMIC_LPM_EN0 (B9) */
    {
        PIN_PMIC_LPM_EN0,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
                                            /* MCU_GPIO0 pin config */
        /* MCU_GPIO0_7 -> MCU_UART0_CTSn (B8) */
    {
        PIN_MCU_UART0_CTSN,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* MCU_GPIO0 pin config */
        /* MCU_GPIO0_12 -> WKUP_UART0_RTSn (C6) */
    {
        PIN_WKUP_UART0_RTSN,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
                                                    /* MCU_GPIO0 pin config */
        /* MCU_GPIO0_11 -> WKUP_UART0_CTSn (C7) */
    {
        PIN_WKUP_UART0_CTSN,
        ( PIN_MODE(7) | PIN_PULL_DIRECTION )
    },
                                                                                                                    /* MCU_GPIO0 pin config */
        /* MCU_GPIO0_21 -> MCU_RESETSTATz (F14) */
    {
        PIN_MCU_RESETSTATZ,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
                                                                                                                                                                            /* MCU_GPIO0 pin config */
        /* MCU_GPIO0_23 -> WKUP_CLKOUT0 (F13) */
    {
        PIN_WKUP_CLKOUT0,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* MCU_GPIO0 pin config */
        /* MCU_GPIO0_0 -> MCU_SPI0_CS0 (B10) */
    {
        PIN_MCU_SPI0_CS0,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
            /* MCU_GPIO0 pin config */
        /* MCU_GPIO0_19 -> WKUP_I2C0_SCL (A13) */
    {
        PIN_WKUP_I2C0_SCL,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
            /* MCU_GPIO0 pin config */
        /* MCU_GPIO0_15 -> MCU_MCAN1_TX (F8) */
    {
        PIN_MCU_MCAN1_TX,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },

            /* MCU_I2C0 pin config */
        /* MCU_I2C0_SCL -> MCU_I2C0_SCL (E11) */
    {
        PIN_MCU_I2C0_SCL,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        /* MCU_I2C0_SDA -> MCU_I2C0_SDA (D11) */
    {
        PIN_MCU_I2C0_SDA,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        
            /* MCU_SPI0 pin config */
        /* MCU_SPI0_CLK -> MCU_SPI0_CLK (C10) */
    {
        PIN_MCU_SPI0_CLK,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        /* MCU_SPI0_D0 -> MCU_SPI0_D0 (B11) */
    {
        PIN_MCU_SPI0_D0,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        /* MCU_SPI0_D1 -> MCU_SPI0_D1 (D10) */
    {
        PIN_MCU_SPI0_D1,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        
            /* MCU_SPI0_CS1 pin config */
    /* MCU_SPI0_CS1 -> MCU_SPI0_CS1 (E10) */
    {
        PIN_MCU_SPI0_CS1,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        
            /* MCU_USART0 pin config */
        /* MCU_UART0_RXD -> MCU_UART0_RXD (B6) */
    {
        PIN_MCU_UART0_RXD,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        /* MCU_UART0_TXD -> MCU_UART0_TXD (C8) */
    {
        PIN_MCU_UART0_TXD,
        ( PIN_MODE(0) | PIN_PULL_DISABLE )
    },
            /* WKUP_USART0 pin config */
        /* WKUP_UART0_RXD -> WKUP_UART0_RXD (D8) */
    {
        PIN_WKUP_UART0_RXD,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        /* WKUP_UART0_TXD -> WKUP_UART0_TXD (D7) */
    {
        PIN_WKUP_UART0_TXD,
        ( PIN_MODE(0) | PIN_PULL_DISABLE )
    },

    {PINMUX_END, 0U}
};

/*
 * Pinmux
 */
void Pinmux_init(void)
{
    Pinmux_config(gPinMuxMainDomainCfg, PINMUX_DOMAIN_ID_MAIN);
    Pinmux_config(gPinMuxMcuDomainCfg, PINMUX_DOMAIN_ID_MCU);
}

