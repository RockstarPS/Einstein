/*
 * Copyright (c) 2022, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
 *  \file am62px/sciclient_irq_rm.c
 *
 *  \brief File containing the AM62x specific interrupt management data for
 *         RM.
 *
 */
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <drivers/sciclient/sciclient_rm_priv.h>
#include <drivers/sciclient/soc/am62px/sciclient_irq_rm.h>

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static struct Sciclient_rmIaUsedMapping rom_usage_DMASS0_INTAGGR_0[1U] = {0};
uint8_t vint_usage_count_DMSS_AM62_0_INTAGGR_0[184U]= {0};

static struct Sciclient_rmIaUsedMapping rom_usage_DMASS1_INTAGGR_0[1U] = {0};
uint8_t vint_usage_count_DMSS_AM62_1_INTAGGR_0[8]= {0};
struct Sciclient_rmIaInst gRmIaInstances[SCICLIENT_RM_IA_NUM_INST] =
{
    0
};

struct Sciclient_rmIrInst gRmIrInstances[SCICLIENT_RM_IR_NUM_INST] =
{
    0
};

/* IRQ Tree definition */

/* Start of MAIN_GPIOMUX_INTROUTER0 interface definition */
const struct Sciclient_rmIrqIf MAIN_GPIOMUX_INTROUTER0_outp_0_15_to_GICSS0_spi_32_47 = {
	0
};
const struct Sciclient_rmIrqIf MAIN_GPIOMUX_INTROUTER0_outp_0_15_to_WKUP_R5FSS0_CORE0_intr_32_47 = {
	0
};
const struct Sciclient_rmIrqIf MAIN_GPIOMUX_INTROUTER0_outp_0_7_to_HSM0_nvic_208_215 = {
	0
};
const struct Sciclient_rmIrqIf MAIN_GPIOMUX_INTROUTER0_outp_24_31_to_DMASS0_INTAGGR_0_intaggr_levi_pend_16_23 = {
	0
};
const struct Sciclient_rmIrqIf MAIN_GPIOMUX_INTROUTER0_outp_22_23_to_DMASS0_INTAGGR_0_intaggr_levi_pend_24_25 = {
	0
};
const struct Sciclient_rmIrqIf MAIN_GPIOMUX_INTROUTER0_outp_34_35_to_MCU_R5FSS0_CORE0_cpu0_intr_32_33 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_MAIN_GPIOMUX_INTROUTER0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_MAIN_GPIOMUX_INTROUTER0 = {
	0
};

/* Start of WKUP_MCU_GPIOMUX_INTROUTER0 interface definition */
const struct Sciclient_rmIrqIf WKUP_MCU_GPIOMUX_INTROUTER0_outp_0_3_to_GICSS0_spi_104_107 = {
	0
};
const struct Sciclient_rmIrqIf WKUP_MCU_GPIOMUX_INTROUTER0_outp_0_3_to_WKUP_R5FSS0_CORE0_intr_104_107 = {
	0
};
const struct Sciclient_rmIrqIf WKUP_MCU_GPIOMUX_INTROUTER0_outp_4_7_to_MCU_R5FSS0_CORE0_cpu0_intr_104_107 = {
	0
};
const struct Sciclient_rmIrqIf WKUP_MCU_GPIOMUX_INTROUTER0_outp_4_7_to_HSM0_nvic_78_81 = {
	0
};
const struct Sciclient_rmIrqIf WKUP_MCU_GPIOMUX_INTROUTER0_outp_8_11_to_WKUP_ESM0_esm_pls_event0_88_91 = {
	0
};
const struct Sciclient_rmIrqIf WKUP_MCU_GPIOMUX_INTROUTER0_outp_8_11_to_WKUP_ESM0_esm_pls_event1_92_95 = {
	0
};
const struct Sciclient_rmIrqIf WKUP_MCU_GPIOMUX_INTROUTER0_outp_8_11_to_WKUP_ESM0_esm_pls_event2_96_99 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_WKUP_MCU_GPIOMUX_INTROUTER0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_WKUP_MCU_GPIOMUX_INTROUTER0 = {
	0
};

/* Start of TIMESYNC_EVENT_INTROUTER0 interface definition */
const struct Sciclient_rmIrqIf TIMESYNC_EVENT_INTROUTER0_outl_0_7_to_DMASS0_INTAGGR_0_intaggr_levi_pend_8_15 = {
	0
};
const struct Sciclient_rmIrqIf TIMESYNC_EVENT_INTROUTER0_outl_10_10_to_CPSW0_cpts_hw1_push_0_0 = {
	0
};
const struct Sciclient_rmIrqIf TIMESYNC_EVENT_INTROUTER0_outl_11_11_to_CPSW0_cpts_hw2_push_1_1 = {
	0
};
const struct Sciclient_rmIrqIf TIMESYNC_EVENT_INTROUTER0_outl_12_12_to_CPSW0_cpts_hw3_push_2_2 = {
	0
};
const struct Sciclient_rmIrqIf TIMESYNC_EVENT_INTROUTER0_outl_13_13_to_CPSW0_cpts_hw4_push_3_3 = {
	0
};
const struct Sciclient_rmIrqIf TIMESYNC_EVENT_INTROUTER0_outl_14_14_to_CPSW0_cpts_hw5_push_4_4 = {
	0
};
const struct Sciclient_rmIrqIf TIMESYNC_EVENT_INTROUTER0_outl_15_15_to_CPSW0_cpts_hw6_push_5_5 = {
	0
};
const struct Sciclient_rmIrqIf TIMESYNC_EVENT_INTROUTER0_outl_16_16_to_CPSW0_cpts_hw7_push_6_6 = {
	0
};
const struct Sciclient_rmIrqIf TIMESYNC_EVENT_INTROUTER0_outl_17_17_to_CPSW0_cpts_hw8_push_7_7 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_TIMESYNC_EVENT_INTROUTER0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_TIMESYNC_EVENT_INTROUTER0 = {
	0
};

/* Start of CPSW0 interface definition */
const struct Sciclient_rmIrqIf CPSW0_cpts_comp_0_0_to_DMASS0_INTAGGR_0_intaggr_levi_pend_0_0 = {
	0
};
const struct Sciclient_rmIrqIf CPSW0_cpts_genf0_1_1_to_TIMESYNC_EVENT_INTROUTER0_in_16_16 = {
	0
};
const struct Sciclient_rmIrqIf CPSW0_cpts_genf1_2_2_to_TIMESYNC_EVENT_INTROUTER0_in_17_17 = {
	0
};
const struct Sciclient_rmIrqIf CPSW0_cpts_sync_3_3_to_TIMESYNC_EVENT_INTROUTER0_in_18_18 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_CPSW0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_CPSW0 = {
	0
};

/* Start of DMASS0_INTAGGR_0 interface definition */
const struct Sciclient_rmIrqIf DMASS0_INTAGGR_0_intaggr_vintr_pend_0_39_to_GICSS0_spi_64_103 = {
	0
};
const struct Sciclient_rmIrqIf DMASS0_INTAGGR_0_intaggr_vintr_pend_72_79_to_WKUP_R5FSS0_CORE0_intr_8_15 = {
	0
};
const struct Sciclient_rmIrqIf DMASS0_INTAGGR_0_intaggr_vintr_pend_40_71_to_WKUP_R5FSS0_CORE0_intr_64_95 = {
	0
};
const struct Sciclient_rmIrqIf DMASS0_INTAGGR_0_intaggr_vintr_pend_136_151_to_HSM0_nvic_176_191 = {
	0
};
const struct Sciclient_rmIrqIf DMASS0_INTAGGR_0_intaggr_vintr_pend_168_183_to_MCU_R5FSS0_CORE0_cpu0_intr_64_79 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_DMASS0_INTAGGR_0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_DMASS0_INTAGGR_0 = {
	0
};

/* Start of MCU_TIMER0 interface definition */
const struct Sciclient_rmIrqIf MCU_TIMER0_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_170_170 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_MCU_TIMER0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_MCU_TIMER0 = {
	0
};

/* Start of TIMER0 interface definition */
const struct Sciclient_rmIrqIf TIMER0_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_162_162 = {
	0
};
const struct Sciclient_rmIrqIf TIMER0_timer_pwm_0_0_to_TIMESYNC_EVENT_INTROUTER0_in_0_0 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_TIMER0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_TIMER0 = {
	0
};

/* Start of TIMER1 interface definition */
const struct Sciclient_rmIrqIf TIMER1_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_163_163 = {
	0
};
const struct Sciclient_rmIrqIf TIMER1_timer_pwm_0_0_to_TIMESYNC_EVENT_INTROUTER0_in_1_1 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_TIMER1[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_TIMER1 = {
	0
};

/* Start of TIMER2 interface definition */
const struct Sciclient_rmIrqIf TIMER2_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_164_164 = {
	0
};
const struct Sciclient_rmIrqIf TIMER2_timer_pwm_0_0_to_TIMESYNC_EVENT_INTROUTER0_in_2_2 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_TIMER2[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_TIMER2 = {
	0
};

/* Start of TIMER3 interface definition */
const struct Sciclient_rmIrqIf TIMER3_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_165_165 = {
	0
};
const struct Sciclient_rmIrqIf TIMER3_timer_pwm_0_0_to_TIMESYNC_EVENT_INTROUTER0_in_3_3 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_TIMER3[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_TIMER3 = {
	0
};

/* Start of TIMER4 interface definition */
const struct Sciclient_rmIrqIf TIMER4_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_166_166 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_TIMER4[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_TIMER4 = {
	0
};

/* Start of TIMER5 interface definition */
const struct Sciclient_rmIrqIf TIMER5_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_167_167 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_TIMER5[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_TIMER5 = {
	0
};

/* Start of TIMER6 interface definition */
const struct Sciclient_rmIrqIf TIMER6_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_168_168 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_TIMER6[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_TIMER6 = {
	0
};

/* Start of TIMER7 interface definition */
const struct Sciclient_rmIrqIf TIMER7_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_169_169 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_TIMER7[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_TIMER7 = {
	0
};

/* Start of MCU_TIMER1 interface definition */
const struct Sciclient_rmIrqIf MCU_TIMER1_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_171_171 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_MCU_TIMER1[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_MCU_TIMER1 = {
	0
};

/* Start of MCU_TIMER2 interface definition */
const struct Sciclient_rmIrqIf MCU_TIMER2_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_172_172 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_MCU_TIMER2[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_MCU_TIMER2 = {
	0
};

/* Start of MCU_TIMER3 interface definition */
const struct Sciclient_rmIrqIf MCU_TIMER3_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_173_173 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_MCU_TIMER3[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_MCU_TIMER3 = {
	0
};

/* Start of WKUP_GTC0 interface definition */
const struct Sciclient_rmIrqIf WKUP_GTC0_gtc_push_event_0_0_to_TIMESYNC_EVENT_INTROUTER0_in_11_11 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_WKUP_GTC0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_WKUP_GTC0 = {
	0
};

/* Start of GPIO0 interface definition */
const struct Sciclient_rmIrqIf GPIO0_gpio_0_89_to_MAIN_GPIOMUX_INTROUTER0_in_0_89 = {
	0
};
const struct Sciclient_rmIrqIf GPIO0_gpio_90_91_to_MAIN_GPIOMUX_INTROUTER0_in_176_177 = {
	0
};
const struct Sciclient_rmIrqIf GPIO0_gpio_bank_92_97_to_MAIN_GPIOMUX_INTROUTER0_in_190_195 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_GPIO0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_GPIO0 = {
	0
};

/* Start of GPIO1 interface definition */
const struct Sciclient_rmIrqIf GPIO1_gpio_0_71_to_MAIN_GPIOMUX_INTROUTER0_in_90_161 = {
	0
};
const struct Sciclient_rmIrqIf GPIO1_gpio_bank_72_77_to_MAIN_GPIOMUX_INTROUTER0_in_180_185 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_GPIO1[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_GPIO1 = {
	0
};

/* Start of MCU_GPIO0 interface definition */
const struct Sciclient_rmIrqIf MCU_GPIO0_gpio_0_23_to_WKUP_MCU_GPIOMUX_INTROUTER0_in_0_23 = {
	0
};
const struct Sciclient_rmIrqIf MCU_GPIO0_gpio_bank_24_25_to_WKUP_MCU_GPIOMUX_INTROUTER0_in_30_31 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_MCU_GPIO0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_MCU_GPIO0 = {
	0
};

/* Start of GPMC0 interface definition */
const struct Sciclient_rmIrqIf GPMC0_gpmc_sdmareq_0_0_to_DMASS0_INTAGGR_0_intaggr_levi_pend_26_26 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_GPMC0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_GPMC0 = {
	0
};

/* Start of EPWM0 interface definition */
const struct Sciclient_rmIrqIf EPWM0_epwm_synco_o_0_0_to_TIMESYNC_EVENT_INTROUTER0_in_8_8 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_EPWM0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_EPWM0 = {
	0
};

/* Start of WKUP_TIMER0 interface definition */
const struct Sciclient_rmIrqIf WKUP_TIMER0_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_174_174 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_WKUP_TIMER0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_WKUP_TIMER0 = {
	0
};

/* Start of WKUP_TIMER1 interface definition */
const struct Sciclient_rmIrqIf WKUP_TIMER1_timer_pwm_0_0_to_MAIN_GPIOMUX_INTROUTER0_in_175_175 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_WKUP_TIMER1[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_WKUP_TIMER1 = {
	0
};

/* Start of MCRC64_0 interface definition */
const struct Sciclient_rmIrqIf MCRC64_0_int_mcrc_4_4_to_DMASS0_INTAGGR_0_intaggr_levi_pend_7_7 = {
	0
};
const struct Sciclient_rmIrqIf MCRC64_0_dma_event_0_3_to_DMASS0_INTAGGR_0_intaggr_levi_pend_28_31 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_MCRC64_0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_MCRC64_0 = {
	0
};

/* Start of DEBUGSS0 interface definition */
const struct Sciclient_rmIrqIf DEBUGSS0_davdma_level_0_0_to_DMASS0_INTAGGR_0_intaggr_levi_pend_27_27 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_DEBUGSS0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_DEBUGSS0 = {
	0
};

/* Start of DSS0 interface definition */
const struct Sciclient_rmIrqIf DSS0_dispc_intr_req_0_0_0_to_DMASS0_INTAGGR_0_intaggr_levi_pend_2_2 = {
	0
};
const struct Sciclient_rmIrqIf DSS0_dispc_intr_req_1_1_1_to_DMASS0_INTAGGR_0_intaggr_levi_pend_3_3 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_DSS0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_DSS0 = {
	0
};

/* Start of DMASS1_INTAGGR_0 interface definition */
const struct Sciclient_rmIrqIf DMASS1_INTAGGR_0_intaggr_vintr_pend_0_7_to_GICSS0_spi_237_244 = {
	0
};
const struct Sciclient_rmIrqIf DMASS1_INTAGGR_0_intaggr_vintr_pend_0_3_to_WKUP_R5FSS0_CORE0_intr_129_132 = {
	0
};
const struct Sciclient_rmIrqIf DMASS1_INTAGGR_0_intaggr_vintr_pend_4_4_to_WKUP_R5FSS0_CORE0_intr_150_150 = {
	0
};
const struct Sciclient_rmIrqIf DMASS1_INTAGGR_0_intaggr_vintr_pend_5_7_to_WKUP_R5FSS0_CORE0_intr_158_160 = {
	0
};
const struct Sciclient_rmIrqIf DMASS1_INTAGGR_0_intaggr_vintr_pend_0_3_to_MCU_R5FSS0_CORE0_cpu0_intr_129_132 = {
	0
};
const struct Sciclient_rmIrqIf DMASS1_INTAGGR_0_intaggr_vintr_pend_4_4_to_MCU_R5FSS0_CORE0_cpu0_intr_150_150 = {
	0
};
const struct Sciclient_rmIrqIf DMASS1_INTAGGR_0_intaggr_vintr_pend_5_7_to_MCU_R5FSS0_CORE0_cpu0_intr_158_160 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_DMASS1_INTAGGR_0[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_DMASS1_INTAGGR_0 = {
	0
};

/* Start of DSS1 interface definition */
const struct Sciclient_rmIrqIf DSS1_dispc_intr_req_0_0_0_to_DMASS0_INTAGGR_0_intaggr_levi_pend_4_4 = {
	0
};
const struct Sciclient_rmIrqIf DSS1_dispc_intr_req_1_1_1_to_DMASS0_INTAGGR_0_intaggr_levi_pend_5_5 = {
	0
};
const struct Sciclient_rmIrqIf * const tisci_if_DSS1[] = {
	NULL
};
static const struct Sciclient_rmIrqNode tisci_irq_DSS1 = {
	0
};


const struct Sciclient_rmIrqNode *const gRmIrqTree[] = {
	NULL
};

const uint32_t gRmIrqTreeCount = 0;
