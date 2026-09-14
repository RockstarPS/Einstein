/*
 * $QNXLicenseC:
 * Copyright 2019,2022 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You
 * may not reproduce, modify or distribute this software except in
 * compliance with the License. You may obtain a copy of the License
 * at: http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * This file may contain contributions from others, either as
 * contributors under the License or as licensors under other terms.
 * Please review this entire file for other proprietary rights or license
 * notices, as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */


/*
 * TI AM62A-EVM
 */
#include "startup.h"
#include "AM62A_pinmux.h"
#include <hw/omap_i2c.h>
#include "board.h"
#include "ti_sci.h"

#define AM62A_CTRLMMR_PADCONFIG 0xF4000
#define AM62A_WKUP_CTRLMMR_PADCONFIG    (0x43000000 + 0x1C000)

#define AM62A_GPIO0_BASE        0x600000
#define AM62A_GPIO_DIR(x)       (0x10 + ((x) / 32) * 0x28)
#define AM62A_GPIO_SET_DATA(x)  (0x18 + ((x) / 32) * 0x28)
#define AM62A_GPIO_BIT(x)       (1 << ((x) % 32))

/* USBx_VBP2AHB_WRAP_CONTROLLER_VBP_USB3_CORE_CAP */
#define USB0_WRAPPER_BASE   0x31000000
#define USB1_WRAPPER_BASE   0x31100000

// referenced u-boot code
/* USBx_MMR_MMRVBP_USB2SS_CFG */
#define USB0_SUBSYS_BASE    0x0F900000
#define USB1_SUBSYS_BASE    0x0F910000

/* PHY Config set register offset */
#define PHY_CONFIG_OFFSET   0x08
#define USBSS0_PHY_CONFIG    (USB0_SUBSYS_BASE + PHY_CONFIG_OFFSET)
#define USBSS1_PHY_CONFIG    (USB1_SUBSYS_BASE + PHY_CONFIG_OFFSET)
/* PHY CONFIG register bits */
#define USBSS_PHY_VBUS_SEL_SHIFT    1

/* PHY Mode control register offset */
#define MODE_CONTROL_OFFSET 0x1C
#define USBSS0_MODE_CONTROL  (USB0_SUBSYS_BASE + MODE_CONTROL_OFFSET)
#define USBSS1_MODE_CONTROL  (USB1_SUBSYS_BASE + MODE_CONTROL_OFFSET)
/* MODE CONTROL register bits */
#define USBSS_MODE_VALID        0x01  //BIT(0)

/* WKUP_MMR0_USB0_PHY_CTRL Register, TRM 6.1.1.3.1.960&961 */
#define WKUP_CTRL_MMR0_BASE 0x43000000
/* USB PHY Control Registers, set Voltage and Pll*/
#define CTRLMMR_USB0_PHY_CTRL   (WKUP_CTRL_MMR0_BASE + 0x4008)
#define CTRLMMR_USB1_PHY_CTRL   (WKUP_CTRL_MMR0_BASE + 0x4018)
#define CORE_VOLTAGE            (1 << 31)  //BIT(31), Core Voltage select: 0 - 0.85v, 1 - 0.75/0.80v

#define ARRAY_SIZE(x)       (sizeof(x) / sizeof((x)[0]))
//Referenced to Table 6-1923&6-1925 in TRM with Field USBx_PHY_CTRL_PLL_REF_SEL / USBx_PHY_CTRL[3:0]
#define USBSS_CLKCTL_MASK       0x0F  //BIT(3,0)

#define PULLUDEN_SHIFT		(16)
#define PULLTYPESEL_SHIFT	(17)
#define RXACTIVE_SHIFT		(18)

#define PULL_DISABLE		(1 << PULLUDEN_SHIFT)
#define PULL_ENABLE		(0 << PULLUDEN_SHIFT)

#define PULL_UP		(1 << PULLTYPESEL_SHIFT | PULL_ENABLE)
#define PULL_DOWN		(0 << PULLTYPESEL_SHIFT | PULL_ENABLE)

#define INPUT_EN		(1 << RXACTIVE_SHIFT)
#define INPUT_DISABLE		(0 << RXACTIVE_SHIFT)

/* Only these macros are expected be used directly in device tree files */
#define PIN_OUTPUT		(INPUT_DISABLE | PULL_DISABLE)
#define PIN_OUTPUT_PULLUP	(INPUT_DISABLE | PULL_UP)
#define PIN_OUTPUT_PULLDOWN	(INPUT_DISABLE | PULL_DOWN)
#define PIN_INPUT		(INPUT_EN | PULL_DISABLE)
#define PIN_INPUT_PULLUP	(INPUT_EN | PULL_UP)

static const uint64_t dwc3_ti_rate_table[] = {       /* in KHZ */
        9600,
        10000,
        12000,
        19200,
        20000,
        24000,
        25000,
        26000,
        38400,
        40000,
        58000,
        50000,
        52000,
};

static const uint16_t hdmi_pins[] = {
    PIN_VOUT0_VSYNC,    //offset 0x0100: (AC25) VOUT0_VSYNC
    PIN_VOUT0_HSYNC,    //offset 0x00f8: (AB24) VOUT0_HSYNC
    PIN_VOUT0_PCLK,     //offset 0x0104: (AC24) VOUT0_PCLK
    PIN_VOUT0_DE,       //offset 0x00fc:  (Y20) VOUT0_DE
    PIN_VOUT0_DATA0,    //offset 0x00b8:  (U22) VOUT0_DATA0
    PIN_VOUT0_DATA1,    //offset 0x00bc:  (V24) VOUT0_DATA1
    PIN_VOUT0_DATA2,    //offset 0x00c0:  (W25) VOUT0_DATA2
    PIN_VOUT0_DATA3,    //offset 0x00c4:  (W24) VOUT0_DATA3
    PIN_VOUT0_DATA4,    //offset 0x00c8:  (Y25) VOUT0_DATA4
    PIN_VOUT0_DATA5,    //offset 0x00cc:  (Y24) VOUT0_DATA5
    PIN_VOUT0_DATA6,    //offset 0x00d0:  (Y23) VOUT0_DATA6
    PIN_VOUT0_DATA7,    //offset 0x00d4: (AA25) VOUT0_DATA7
    PIN_VOUT0_DATA8,    //offset 0x00d8:  (V21) VOUT0_DATA8
    PIN_VOUT0_DATA9,    //offset 0x00dc:  (W21) VOUT0_DATA9
    PIN_VOUT0_DATA10,   //offset 0x00e0:  (V20) VOUT0_DATA10
    PIN_VOUT0_DATA11,   //offset 0x00e4: (AA23) VOUT0_DATA11
    PIN_VOUT0_DATA12,   //offset 0x00e8: (AB25) VOUT0_DATA12
    PIN_VOUT0_DATA13,   //offset 0x00ec: (AA24) VOUT0_DATA13
    PIN_VOUT0_DATA14,   //offset 0x00f0:  (Y22) VOUT0_DATA14
    PIN_VOUT0_DATA15,   //offset 0x00f4: (AA21) VOUT0_DATA15
    PIN_GPMC0_AD8,      //offset 0x005c:  (R24) GPMC0_AD8.VOUT0_DATA16
    PIN_GPMC0_AD9,      //offset 0x0060:  (R25) GPMC0_AD9.VOUT0_DATA17
    PIN_GPMC0_AD10,     //offset 0x0064:  (T25) GPMC0_AD10.VOUT0_DATA18
    PIN_GPMC0_AD11,     //offset 0x0068:  (R21) GPMC0_AD11.VOUT0_DATA19
    PIN_GPMC0_AD12,     //offset 0x006c:  (T22) GPMC0_AD12.VOUT0_DATA20
    PIN_GPMC0_AD13,     //offset 0x0070:  (T24) GPMC0_AD13.VOUT0_DATA21
    PIN_GPMC0_AD14,     //offset 0x0074:  (U25) GPMC0_AD14.VOUT0_DATA22
    PIN_GPMC0_AD15,     //offset 0x0078:  (U24) GPMC0_AD15.VOUT0_DATA23
 };

static int init_dss(void)
{
    // DSS power, functional clock
    if (ti_sci_set_device_state(TISCI_DEV_DSS0, 0, MSG_DEVICE_SW_STATE_ON) == -1) {
        kprintf("%s: Set DSS device state failed!\n", __func__);
        return -1;
    }
    if (ti_sci_set_clock_state(TISCI_DEV_DSS0, TISCI_DEV_DSS0_DSS_FUNC_CLK,
            0, MSG_CLOCK_SW_STATE_REQ) == -1) {
        kprintf("%s: Set DSS clock state failed!\n", __func__);
        return -1;
    }

    return 0;
}

static int init_hdmi(void)
{
    uint32_t    hdmi_pincfg = PIN_OUTPUT | PIN_MODE(0);
    uint8_t     pin;

    // Pinmux
    for (pin = 0; pin < sizeof(hdmi_pins) / sizeof(uint16_t); pin++) {
            if (pin > 19) {
                hdmi_pincfg = PIN_OUTPUT | PIN_MODE(1);
            }
        out32(AM62A_CTRLMMR_PADCONFIG + hdmi_pins[pin], hdmi_pincfg);
    }

    // Set 148.5Mhz pixel clock for 1080P output
     if (ti_sci_cmd_clk_set_freq(TISCI_DEV_DSS0, TISCI_DEV_DSS0_DPI_1_IN_CLK,
            148500000ULL, 148500000ULL, 148500000ULL) == -1) {
        kprintf("%s: Set DSS pixel clock frequency failed!\n", __func__);
        return -1;
    }

     if (ti_sci_set_clock_state(TISCI_DEV_DSS0, TISCI_DEV_DSS0_DPI_1_IN_CLK,
            0, MSG_CLOCK_SW_STATE_REQ) == -1) {
        kprintf("%s: Set DSS clock state failed!\n", __func__);
        return -1;
    }

    return 0;
}

static int init_usb_host(const int host)
{
    uint32_t    dev_id, dev_main;
    uint32_t    val, i;
    uint64_t    rate;
    paddr_t     phy_ctrl, mode_ctrl, pinmux_ctrl/*, phy_cfg*/; //'phy_cfg' is reserved for setting configs to PHY if need

    kprintf("init_usb_host: USB%d\n", host);

    // output revision information from hw
    ti_sci_init();

    if(host == 0)
    {
        dev_id = TISCI_DEV_USB0;
        dev_main = TISCI_DEV_MAIN_USB0_ISO_VD;
        // phy_cfg = USBSS0_PHY_CONFIG;  // RESERVED
        phy_ctrl = CTRLMMR_USB0_PHY_CTRL;
        mode_ctrl = USBSS0_MODE_CONTROL;
        pinmux_ctrl = AM62A_CTRLMMR_PADCONFIG + PIN_USB0_DRVVBUS;
    }
    else // host == 1
    {
        dev_id = TISCI_DEV_USB1;
        dev_main = TISCI_DEV_MAIN_USB1_ISO_VD;
        // phy_cfg = USBSS1_PHY_CONFIG;  // RESERVED
        phy_ctrl = CTRLMMR_USB1_PHY_CTRL;
        mode_ctrl = USBSS1_MODE_CONTROL;
        pinmux_ctrl = AM62A_CTRLMMR_PADCONFIG + PIN_USB1_DRVVBUS;
    }

    // Set pinmux
    out32(pinmux_ctrl, PIN_PULL_DISABLE | PIN_MODE(0));  // VBUS control

    /* For clock settings
     * Since clock ID sets of device USB0 and USB1 have the same definitions in tisci_clock.h
     * In order to simplify the routine, here use '_USB0' for both (alternate '_USB1')
     */
    // USB main clock
    if (ti_sci_set_device_state(dev_main, 0, MSG_DEVICE_SW_STATE_ON) == -1) {
        kprintf("%s: HOST %d, failed! %d\n", __func__, host, __LINE__);
        return (-1);
    }
    if (ti_sci_set_device_state(dev_main, TI_SCI_MSG_SET_MAIN_USB0,
        TISCI_DEV_USB0_BUS_CLK) == -1) {
        kprintf("%s: HOST %d, failed! %d\n", __func__, host, __LINE__);
        return (-1);
    }

    // USB sub-system clock, parent clock
    if (ti_sci_set_device_state(dev_id, 0, MSG_DEVICE_SW_STATE_ON) == -1) {
        kprintf("%s: HOST %d, failed! %d\n", __func__, host, __LINE__);
        return (-1);
    }
    if (ti_sci_cmd_set_clk_parent(dev_id, TISCI_DEV_USB0_USB2_REFCLOCK_CLK,
        TISCI_DEV_USB0_USB2_REFCLOCK_CLK_PARENT_GLUELOGIC_HFOSC0_CLKOUT) == -1) {
        kprintf("%s: HOST %d, failed! %d\n", __func__, host, __LINE__);
        return (-1);
    }
    if (ti_sci_set_clock_state(dev_id, TISCI_DEV_USB0_USB2_APB_PCLK_CLK,
        0, MSG_CLOCK_SW_STATE_AUTO) == -1) {
        kprintf("%s: HOST %d, failed! %d\n", __func__, host, __LINE__);
        return (-1);
    }
    if (ti_sci_set_clock_state(dev_id, TISCI_DEV_USB0_USB2_REFCLOCK_CLK,
        0, MSG_CLOCK_SW_STATE_AUTO) == -1) {
        kprintf("%s: HOST %d, failed! %d\n", __func__, host, __LINE__);
        return (-1);
    }

    /* PHY Core voltage enable */
    /* Set USB PHY core voltage to 0.85V */
    val = in32(phy_ctrl);
    val &= ~(CORE_VOLTAGE);
    out32(phy_ctrl, val);

    /*Get USB Rate*/
    if (ti_sci_cmd_clk_get_freq(dev_id, TISCI_DEV_USB0_USB2_REFCLOCK_CLK, &rate) == -1){
        kprintf("%s: HOST %d, failed! %d\n", __func__, host, __LINE__);
        return (-1);
    }

    /* Calcuate the rate code */
    rate /= 1000;   /* To KHz */
    for (i = 0; i < ARRAY_SIZE(dwc3_ti_rate_table); i++) {
        if (dwc3_ti_rate_table[i] == rate) {
            break;
        }
    }

    if (i == ARRAY_SIZE(dwc3_ti_rate_table)) {
        //Unsupported usb2_refclk rate
        kprintf("%s: HOST %d, failed! %d\n", __func__, host, __LINE__);
        return (-1);
    }

    /*PHY clock feq*/
    val = in32(phy_ctrl);
    val &= ~(USBSS_CLKCTL_MASK);
    val |= i;
    out32(phy_ctrl, val);

    /* VBUS divider selected */ // no divider used, RESERVED for future need
    // val = in32(phy_cfg);
    // if(divider_selected)
    //     val |= 1 << USBSS_PHY_VBUS_SEL_SHIFT;
    // out32(phy_cfg, val); // write again

    /* Set mode valid */
    val = in32(mode_ctrl);
    val |= USBSS_MODE_VALID;
    out32(mode_ctrl, val);

    return (0);
}

static void init_i2c(void)
{
    // pinmux for I2C0
    out32(AM62A_CTRLMMR_PADCONFIG + PIN_I2C0_SCL, PIN_INPUT_ENABLE | PIN_MODE(0));
    out32(AM62A_CTRLMMR_PADCONFIG + PIN_I2C0_SDA, PIN_INPUT_ENABLE | PIN_MODE(0));

    // pinmux for I2C1
    out32(AM62A_CTRLMMR_PADCONFIG + PIN_I2C1_SCL, PIN_INPUT_ENABLE | PIN_MODE(0));
    out32(AM62A_CTRLMMR_PADCONFIG + PIN_I2C1_SDA, PIN_INPUT_ENABLE | PIN_MODE(0));

    // pinmux for I2C2
    out32(AM62A_CTRLMMR_PADCONFIG +  PIN_GPMC0_CSN2, PIN_INPUT_ENABLE | PIN_MODE(1));
    out32(AM62A_CTRLMMR_PADCONFIG +  PIN_GPMC0_CSN3, PIN_INPUT_ENABLE | PIN_MODE(1));
}

#define EVM_SDIO_1V8_EN_PIN_NUM     (31U)
static void init_sdmmc(void)
{
    // pinmux for SD(MMC1)
    out32(AM62A_CTRLMMR_PADCONFIG + PIN_MMC1_DAT3, PIN_PULL_DIRECTION | PIN_INPUT_ENABLE | PIN_MODE(0));
    out32(AM62A_CTRLMMR_PADCONFIG + PIN_MMC1_DAT2, PIN_PULL_DIRECTION | PIN_INPUT_ENABLE | PIN_MODE(0));
    out32(AM62A_CTRLMMR_PADCONFIG + PIN_MMC1_DAT1, PIN_PULL_DIRECTION | PIN_INPUT_ENABLE | PIN_MODE(0));
    out32(AM62A_CTRLMMR_PADCONFIG + PIN_MMC1_DAT0, PIN_PULL_DIRECTION | PIN_INPUT_ENABLE | PIN_MODE(0));
    out32(AM62A_CTRLMMR_PADCONFIG + PIN_MMC1_CMD, PIN_PULL_DIRECTION | PIN_INPUT_ENABLE | PIN_MODE(0));
    out32(AM62A_CTRLMMR_PADCONFIG + PIN_MMC1_CLK, PIN_INPUT_ENABLE | PIN_MODE(0)); // Pull Down
    // GPIO0_31 for signal voltage switch
    out32(AM62A_CTRLMMR_PADCONFIG + PIN_GPMC0_CLK, PIN_PULL_DISABLE | PIN_MODE(7));
    // GPIO0_31 as output
    out32(AM62A_GPIO0_BASE + AM62A_GPIO_DIR(EVM_SDIO_1V8_EN_PIN_NUM),
        in32(AM62A_GPIO0_BASE + AM62A_GPIO_DIR(EVM_SDIO_1V8_EN_PIN_NUM)) & ~(AM62A_GPIO_BIT(EVM_SDIO_1V8_EN_PIN_NUM)));
    // Default signal voltage 3.3v, output high
    out32(AM62A_GPIO0_BASE + AM62A_GPIO_SET_DATA(EVM_SDIO_1V8_EN_PIN_NUM), (unsigned int)(AM62A_GPIO_BIT(EVM_SDIO_1V8_EN_PIN_NUM)));
}

/*
 * hw_init()
 *    Board specific initialization
 */
void
hw_init(void)
{
    init_i2c();
    init_sdmmc();
    init_dss();
    init_hdmi();

    init_usb_host(0);
    init_usb_host(1);
}

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/branches/7.1.0/trunk/hardware/startup/boards/am62a/evm/hw_init.c $ $Rev: 964015 $")
#endif
