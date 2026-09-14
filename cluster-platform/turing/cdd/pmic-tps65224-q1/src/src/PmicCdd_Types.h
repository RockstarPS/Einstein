/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  IoExp_Types.h                                        *
*  Module Short Name :  IoExp_ads7138                                        *
*  VOBName           :                                                       *
*  Author            : gthanapp                                              *
*  Description       : This file contains the typedefs for nvM               *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/


#ifndef PMICCDD_TYPES_H
#define PMICCDD_TYPES_H

#include "Std_Types.h"
#include "Platform_Types.h"
#include <stdint.h>

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/
#define PMIC_WD_ERR_MASK (0xFFU)


/* Define ONE of these based on your hardware */
#define PMICCDD_VARIANT_TPS65222        (1U)
#define PMICCDD_VARIANT_TPS65224        (2U)

/* Det Api Id Definition */
#define PMICCDD_INIT                  (0x01U)
#define PMICCDD_I2C_CB                (0x02U)
#define PMICCDD_MAIN_FUNCTION         (0x03U)
#define PMICCDD_OVUV_MONITOR          (0x04U)



/* Det Error Definition */
#define PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED          (0x01U)
#define PMICCDD_ERROR_I2C_POP_SEQUENCE_FAILED           (0x02U)
#define PMICCDD_ERROR_I2C_ASYN_TRANSMIT_FAILED          (0x03U)
#define PMICCDD_ERROR_I2C_CB_SEQUENCE_FAILED            (0x04U)
#define PMICCDD_ERROR_I2C_RECEIVE_CRC_FAILED            (0x05U)
#define PMICCDD_ERROR_I2C_TRANSMIT_REG_UNLOCK_CRC_FAILED           (0x06U)

//RstM Report Erorr Macro
#define PMICCDD_ERROR_WDG_FAIL_INT_REST                 (0x07U)
#define PMICCDD_ERROR_ABIST_TEST_FAIL                   (0x08U)
#define PMICCDD_BUCK1_OVUV_FAIL                         (0x09U)
#define PMICCDD_BUCK2_OVUV_FAIL                         (0x0AU)
#define PMICCDD_BUCK3_OVUV_FAIL                         (0x0BU)
#define PMICCDD_BUCK4_OVUV_FAIL                         (0x0CU)
#define PMICCDD_LDO1_OVUV_FAIL                          (0x0DU)
#define PMICCDD_LDO2_OVUV_FAIL                          (0x0EU)
#define PMICCDD_LDO3_OVUV_FAIL                          (0x0FU)
#define PMICCDD_VCCA_OVUV_FAIL                          (0x10U)
#define PMICCDD_VMON1_OVUV_FAIL                         (0x11U)
//WDG configuration Macros
#define PMICCDD_ERROR_WDG_WINDOW_CFG_FAILS              (0x12U)

// Macros for Recovery actions taken by pmi
#define PMICCDD_ERROR_BG_XMON_FAIL                      (0x13U)
#define PMICCDD_ERROR_TSD_IMM_FAIL                      (0x14U)
#define PMICCDD_ERROR_TSD_ORD_FAIL                      (0x15U)
#define PMICCDD_ERROR_TWARN_FAIL                        (0x16U)
#define PMICCDD_ERROR_CRC_ERR_FAIL                      (0x17U)
#define PMICCDD_ERROR_NVM_CODE_MISMATCH                 (0x18U)

//Macro to indicate ABIST is completed by PMIC
#define PMICCDD_BIST_PASS                               (0x19U)

/* Slave Address */
#define PMIC_I2C_USER_DEVICE_ID                      0x48U
#define PMIC_I2C_WDG_DEVICE_ID                       0x12U 

/* User Register Address*/
#define DEV_REV_REG                                  ((uint8)0x1U)
#define NVM_CODE_1_REG                               ((uint8)0x2U)
#define NVM_CODE_2_REG                               ((uint8)0x3U)
#define BUCK1_CTRL_REG                               ((uint8)0x4U)
#define BUCK1_CONF_REG                               ((uint8)0x5U)
#define BUCK2_CTRL_REG                               ((uint8)0x6U)
#define BUCK2_CONF_REG                               ((uint8)0x7U)
#define BUCK3_CTRL_REG                               ((uint8)0x8U)
#define BUCK3_CONF_REG                               ((uint8)0x9U)
#define BUCK4_CTRL_REG                               ((uint8)0xAU)
#define BUCK4_CONF_REG                               ((uint8)0xBU)
#define BUCK1_VOUT_REG                               ((uint8)0xEU)
#define BUCK2_VOUT_REG                               ((uint8)0x10U)
#define BUCK3_VOUT_REG                               ((uint8)0x12U)
#define BUCK4_VOUT_REG                               ((uint8)0x14U)
#define BUCK1_PG_WINDOW_REG                          ((uint8)0x18U)
#define BUCK2_PG_WINDOW_REG                          ((uint8)0x19U)
#define BUCK3_PG_WINDOW_REG                          ((uint8)0x1AU)
#define BUCK4_PG_WINDOW_REG                          ((uint8)0x1BU)
#define LDO1_CTRL_REG                                ((uint8)0x1DU)
#define LDO2_CTRL_REG                                ((uint8)0x1EU)
#define LDO3_CTRL_REG                                ((uint8)0x1FU)
#define LDO1_VOUT_REG                                ((uint8)0x23U)
#define LDO2_VOUT_REG                                ((uint8)0x24U)
#define LDO3_VOUT_REG                                ((uint8)0x25U)
#define LDO1_PG_WINDOW_REG                           ((uint8)0x27U)
#define LDO2_PG_WINDOW_REG                           ((uint8)0x28U)
#define LDO3_PG_WINDOW_REG                           ((uint8)0x29U)
#define VCCA_VMON_CTRL_REG                           ((uint8)0x2BU)
#define VCCA_PG_WINDOW_REG                           ((uint8)0x2CU)
#define VMON1_PG_WINDOW_REG                          ((uint8)0x2DU)
#define VMON1_PG_LEVEL_REG                           ((uint8)0x2EU)
#define VMON2_PG_WINDOW_REG                          ((uint8)0x2FU)
#define VMON2_PG_LEVEL_REG                           ((uint8)0x30U)
#define GPIO1_CONF_REG                               (0x31U)
#define GPIO2_CONF_REG                               (0x32U)
#define GPIO3_CONF_REG                               (0x33U)
#define GPIO4_CONF_REG                               (0x34U)
#define GPIO5_CONF_REG                               (0x35U)
#define GPIO6_CONF_REG                               (0x36U)
#define POWER_ON_CONFIG_REG                          (0x3CU)
#define GPIO_OUT_1_REG                               ((uint8)0x3DU)
#define GPIO_IN_1_REG                                ((uint8)0x3FU)
#define RAIL_SEL_1_REG                               ((uint8)0x41U)
#define RAIL_SEL_2_REG                               ((uint8)0x42U)
#define RAIL_SEL_3_REG                               ((uint8)0x43U)
#define FSM_TRIG_SEL_1_REG                           ((uint8)0x44U)
#define FSM_TRIG_SEL_2_REG                           ((uint8)0x45U)
#define FSM_TRIG_MASK_1_REG                          ((uint8)0x46U)
#define FSM_TRIG_MASK_2_REG                          ((uint8)0x47U)
#define MASK_BUCK_REG                                ((uint8)0x49U)
#define MASK_LDO_VMON_REG                            ((uint8)0x4CU)
#define MASK_GPIO_FALL_REG                           ((uint8)0x4FU)
#define MASK_GPIO_RISE_REG                           ((uint8)0x50U)
#define MASK_STARTUP_REG                             ((uint8)0x52U)
#define MASK_MISC_REG                                ((uint8)0x53U)
#define MASK_MODERATE_ERR_REG                        ((uint8)0x54U)
#define MASK_FSM_ERR_REG                             ((uint8)0x56U)
#define MASK_ESM_REG                                 (0x59U)
#define INT_TOP_REG                                  (0x5AU)
#define INT_BUCK_REG                                 (0x5BU)
#define INT_LDO_VMON_REG                             (0x5FU)
#define INT_GPIO_REG                                 (0x63U)
#define INT_STARTUP_REG                              (0x65U)
#define INT_MISC_REG                                 (0x66U)
#define INT_MODERATE_ERR_REG                         (0x67U)
#define INT_SEVERE_ERR_REG                           (0x68U)
#define INT_FSM_ERR_REG                              (0x69U)
#define INT_ESM_REG                                  (0x6CU)
#define STAT_BUCK_REG                                ((uint8)0x6DU)
#define STAT_LDO_VMON_REG                            ((uint8)0x70U)
#define STAT_STARTUP_REG                             ((uint8)0x73U)
#define STAT_MISC_REG                                ((uint8)0x74U)
#define STAT_MODERATE_ERR_REG                        ((uint8)0x75U)
#define STAT_SEVERE_ERR_REG                          ((uint8)0x76U)
#define PLL_CTRL_REG                                 ((uint8)0x7CU)
#define CONFIG_1_REG                                 ((uint8)0x7DU)
#define CONFIG_2_REG                                 (0x7EU)
#define ENABLE_DRV_REG                               ((uint8)0x80U)
#define MISC_CTRL_REG                                ((uint8)0x81U)
#define ENABLE_DRV_STAT_REG                          ((uint8)0x82U)
#define RECOV_CNT_REG_1                              ((uint8)0x83U)
#define RECOV_CNT_REG_2                              ((uint8)0x84U)
#define FSM_I2C_TRIGGERS_REG                         ((uint8)0x85U)
#define FSM_NSLEEP_TRIGGERS_REG                      ((uint8)0x86U)
#define BUCK_RESET_REG                               ((uint8)0x87U)
#define SPREAD_SPECTRUM_1_REG                        ((uint8)0x88U)
#define FSM_STEP_SIZE_REG                            ((uint8)0x8BU)
#define USER_SPARE_REG                               ((uint8)0x8EU)
#define ESM_MCU_START_REG                            ((uint8)0x8FU)
#define ESM_MCU_DELAY1_REG                           ((uint8)0x90U)
#define ESM_MCU_DELAY2_REG                           ((uint8)0x91U)
#define ESM_MCU_MODE_CFG                             ((uint8)0x92U)
#define ESM_MCU_HMAX_REG                             ((uint8)0x93U)
#define ESM_MCU_HMIN_REG                             ((uint8)0x94U)
#define ESM_MCU_LMAX_REG                             ((uint8)0x95U)
#define ESM_MCU_LMIN_REG                             ((uint8)0x96U)
#define ESM_MCU_ERR_CNT_REG                          ((uint8)0x97U)
#define REGISTER_LOCK_REG                            (0xA1U)
#define SRAM_ACCESS_REG_1                            ((uint8)0xA2U)
#define SRAM_ACCESS_REG_2                            ((uint8)0xA3U)
#define SRAM_ADDR_CTRL_REG                           ((uint8)0xA4U)
#define RECOV_CNT_PFSM_INCR_REG                      ((uint8)0xA5U)
#define MANUFACTURING_VER_REG                        ((uint8)0xA6U)
#define CUSTOMER_NVM_ID_REG                          ((uint8)0xA7U)
#define SOFT_REBOOT_REG                              ((uint8)0xABU)
#if (PMICCDD_ACTIVE_VARIANT == PMICCDD_VARIANT_TPS65224)
#define ADC_CTRL_REG                                 (0xACU)
#define ADC_RESULT_REG_1                             (0xADU)
#define ADC_RESULT_REG_2                             (0xAEU)
#endif
#define STARTUP_CTRL_REG                             ((uint8)0xC3U)
#define SCRATCH_PAD_REG_1                            ((uint8)0xC9U)
#define SCRATCH_PAD_REG_2                            ((uint8)0xCAU)
#define SCRATCH_PAD_REG_3                            ((uint8)0xCBU)
#define SCRATCH_PAD_REG_4                            ((uint8)0xCCU)
#define PFSM_DELAY_REG_1                             ((uint8)0xCDU)
#define PFSM_DELAY_REG_2                             ((uint8)0xCEU)
#define PFSM_DELAY_REG_3                             ((uint8)0xCFU)
#if (PMICCDD_ACTIVE_VARIANT == PMICCDD_VARIANT_TPS65224)
#define ADC_GAIN_COMP_REG                            ((uint8)0xD0U)
#endif
#define CRC_CALC_CONTROL_REG                         ((uint8)0xEFU)
#define REGMAP_USER_CRC_LOW_REG                      ((uint8)0xF0U)
#define REGMAP_USER_CRC_HIGH_REG                     ((uint8)0xF1U)

/* Watchgog Register Address*/
#define WD_ANSWER_REG                           ((uint8)0x01U)
#define WD_QUESTION_ANSW_CNT_REG                ((uint8)0x02U) 
#define WD_WIN1_CFG_REG                         ((uint8)0x03U)
#define WD_WIN2_CFG_REG                         ((uint8)0x04U)
#define WD_LONGWIN_CFG_REG                      ((uint8)0x05U)
#define WD_MODE_REG                             (0x06U)
#define WD_QA_CFG_REG                           ((uint8)0x07U)
#define WD_ERR_STATUS_REG                       ((uint8)0x08U)
#define WD_THR_CFG_REG                          (0x09U)
#define WD_FAIL_CNT_REG                         (0x0AU)


// Register Masks for Int regs
// Buck mask
#define PMICCDD_BUCK1UVOV_INT_MASK              (0x01U)
#define PMICCDD_BUCK2UVOV_INT_MASK              (0x02U)
#define PMICCDD_BUCK3UVOV_INT_MASK              (0x04U)
#define PMICCDD_BUCK4UVOV_INT_MASK              (0x08U)

// LDO and VMON mask
#define PMICCDD_LDO1UVOV_INT_MASK               (0x01U)
#define PMICCDD_LDO2UVOV_INT_MASK               (0x02U)
#define PMICCDD_LDO3UVOV_INT_MASK               (0x04U)
#define PMICCDD_VCCAUVOV_INT_MASK               (0x10U)
#define PMICCDD_VMON1UVOV_INT_MASK              (0x20U)
#define PMICCDD_VMON2UVOV_INT_MASK              (0x40U)

// GPIO mask
#define PMICCDD_GPIO1_INT_MASK                  (0x01U)
#define PMICCDD_GPIO2_INT_MASK                  (0x02U)
#define PMICCDD_GPIO3_INT_MASK                  (0x04U)
#define PMICCDD_GPIO4_INT_MASK                  (0x08U)
#define PMICCDD_GPIO5_INT_MASK                  (0x10U)
#define PMICCDD_GPIO6_INT_MASK                  (0x20U)

// Startup mask
#define PMICCDD_VSENSE_INT_MASK                 (0x01U)
#define PMICCDD_ENABLE_INT_MASK                 (0x02U)
#define PMICCDD_PB_SHORT_INT_MASK               (0x04U)
#define PMICCDD_FSD_INT_MASK                    (0x10U)
#define PMICCDD_SOFTREBOOT_INT_MASK             (0x20U)

// Misc mask
#define PMICCDD_BISTPASS_INT_MASK               (0x01U)
#define PMICCDD_EXTCLK_INT_MASK                 (0x02U)
#define PMICCDD_REGUNLOCK_INT_MASK              (0x04U)
#define PMICCDD_TWARN_INT_MASK                  (0x08U)
#define PMICCDD_PBLONG_INT_MASK                 (0x10U)
#define PMICCDD_PBFALL_INT_MASK                 (0x20U)
#define PMICCDD_PBRISE_INT_MASK                 (0x40U)
#define PMICCDD_ADCCONVREADY_INT_MASK           (0x80U)

// Moderate error mask
#define PMICCDD_TSDORD_INT_MASK                 (0x01U)
#define PMICCDD_BISTFAIL_INT_MASK               (0x02U)
#define PMICCDD_REGCRCERR_INT_MASK              (0x04U)
#define PMICCDD_RECOVCNT_INT_MASK               (0x08U)

// Severe error mask
#define PMICCDD_TSDIMM_INT_MASK                 (0x01U)
#define PMICCDD_VCCAOVP_INT_MASK                (0x02U)
#define PMICCDD_PFSMERR_INT_MASK                (0x04U)
#define PMICCDD_BGXMON_INT_MASK                 (0x08U)

// FSM error mask
#define PMICCDD_IMMSHUTDOWN_INT_MASK            (0x01U)
#define PMICCDD_ORDSHUTDOWN_INT_MASK            (0x02U)
#define PMICCDD_MCUPWRERR_INT_MASK              (0x04U)
#define PMICCDD_SOCPWRERR_INT_MASK              (0x08U)
#define PMICCDD_COMMERR_INT_MASK                (0x10U)
#define PMICCDD_I2C2ERR_INT_MASK                (0x20U)
#define PMICCDD_ESM_INT_MASK                    (0x40U)
#define PMICCDD_WD_INT_MASK                     (0x80U)

// ESM mask
#define PMICCDD_ESMMCUPIN_INT_MASK              (0x08U)
#define PMICCDD_ESMMCUFAIL_INT_MASK             (0x10U)
#define PMICCDD_ESMMCURST_INT_MASK              (0x20U)

// Wdg mask
#define PMICCDD_LONGWINTIMEOUT_INT_MASK          (0x01U)
#define PMICCDD_WDTIMEOUT_INT_MASK               (0x02U)
#define PMICCDD_WDTRIGEARLY_INT_MASK             (0x04U)
#define PMICCDD_WDANSWEARLY_INT_MASK             (0x08U)
#define PMICCDD_WDSEQERR_INT_MASK                (0x10U)
#define PMICCDD_WDANSWERR_INT_MASK               (0x20U)
#define PMICCDD_WDFAIL_INT_MASK                  (0x40U)
#define PMICCDD_WDRST_INT_MASK                   (0x80U)

/* Hw Channel ID of GPIOS */
#define PMICCDD_GPIO1                                                      0U
#define PMICCDD_GPIO2                                                      1u
#define PMICCDD_GPIO3                                                      2u
#define PMICCDD_GPIO4                                                      3u
#define PMICCDD_GPIO5                                                      4u
#define PMICCDD_GPIO6                                                      5u

/* Hw Channel ID of BUCKS */
#define PMICCDD_BUCK1                                                      0U
#define PMICCDD_BUCK2                                                      1U
#define PMICCDD_BUCK3                                                      2U
#define PMICCDD_BUCK4                                                      3U

/* Hw Channel ID of LDOS*/
#define PMICCDD_LDO1                                                        0U
#define PMICCDD_LDO2                                                        1U
#define PMICCDD_LDO3                                                        2U

#define PMICCDD_NUMOF_GPIO_PINS                6U
#define PMICCDD_NUMOF_BUCKS                    4U
#define PMICCDD_NUMOF_LDOS                     3U

/* EN / PB / VENSE Setting Value*/

#define PMICCDD_ENABLE                                                    0x0U
#define PMICCDD_PB                                                        0x1U
#define PMICCDD_VENSE                                                     0x2U
#define PMICCDD_NOTUSED                                                   0x3U

/*nINT / EN_DRV Setting Value*/

#define PMICCDD_NINT                                                      0x0U
#define PMICCDD_ENDRV                                                     0x1U

#define PMICCDD_COMM_CRC_INITIAL_VALUE                                    0xFFU

/* Lock and Unclock the Registers macros */
#define PMICCDD_REG_LOCK_VALUE                                            0x00U
#define PMICCDD_REG_UNLOCK_VALUE                                          0x9BU

/* Enable / Disable the NINT ENDRV PU SEL */
// Pull -up resistor activated
#define PMICCDD_ENABLE_NINT_ENDRV_PU_SEL                                  0x1U
// Pull -up resistor not activated
#define PMICCDD_DISABLE_NINT_ENDRV_PU_SEL                                 0x0U

/*****************************************************************************
*                                 Enum  Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                 Typedef Definitions                       *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/* Register Bit Field Definitions */

typedef union {
    struct {
        uint8 nint_endrv_pu_sel : 1;    // NINT_ENDRV_PU_SEL
        uint8 nint_endrv_sel : 1;       // NINT_ENDRV_SEL
        uint8 reserved1 : 3;            // RESERVED
        uint8 en_pb_degl : 1;           // EN_PB_DEGL
        uint8 en_pb_vsense_config : 2;  // EN_PB_VSENSE_CONFIG
    } bits;
    uint8 value;
} PmicCdd_PowerOnConfigReg_t;

typedef union {
    struct {
        uint8 gpio1_dir : 1;      // GPIO1_DIR
        uint8 gpio1_od : 1;       // GPIO1_OD
        uint8 gpio1_pu_sel : 1;   // GPIO1_PU_SEL
        uint8 gpio1_pu_pd_en : 1; // GPIO1_PU_PD_EN
        uint8 gpio1_deglitch_en : 1; // GPIO1_DEGLITCH_EN
        uint8 gpio1_sel : 2;      // GPIO1_SEL
    } bits;
    uint8 value;
} PmicCdd_Gpio1_Reg_t;

typedef union {
    struct {
        uint8 gpio2_dir : 1;      // GPIO2_DIR
        uint8 gpio2_od : 1;       // GPIO2_OD
        uint8 gpio2_pu_sel : 1;   // GPIO2_PU_SEL
        uint8 gpio2_pu_pd_en : 1; // GPIO2_PU_PD_EN
        uint8 gpio2_deglitch_en : 1; // GPIO2_DEGLITCH_EN
        uint8 gpio2_sel : 2;      // GPIO2_SEL
    } bits;
    uint8 value;
} PmicCdd_Gpio2_Reg_t;


typedef union {
    struct {
        uint8 gpio3_dir : 1;      // GPIO3_DIR
        uint8 gpio3_od : 1;       // GPIO3_OD
        uint8 gpio3_pu_sel : 1;   // GPIO3_PU_SEL
        uint8 gpio3_pu_pd_en : 1; // GPIO3_PU_PD_EN
        uint8 gpio3_deglitch_en : 1; // GPIO3_DEGLITCH_EN
        uint8 gpio3_sel : 2;      // GPIO3_SEL
    } bits;
    uint8 value;
} PmicCdd_Gpio3_Reg_t;

typedef union {
    struct {
        uint8 gpio4_dir : 1;      // GPIO4_DIR
        uint8 gpio4_od : 1;       // GPIO4_OD
        uint8 gpio4_pu_sel : 1;   // GPIO4_PU_SEL
        uint8 gpio4_pu_pd_en : 1; // GPIO4_PU_PD_EN
        uint8 gpio4_deglitch_en : 1; // GPIO4_DEGLITCH_EN
        uint8 gpio4_sel : 2;      // GPIO4_SEL
    } bits;
    uint8 value;
} PmicCdd_Gpio4_Reg_t;

typedef union {
    struct {
        uint8 gpio5_dir : 1;      // GPIO5_DIR
        uint8 gpio5_od : 1;       // GPIO5_OD
        uint8 gpio5_pu_sel : 1;   // GPIO5_PU_SEL
        uint8 gpio5_pu_pd_en : 1; // GPIO5_PU_PD_EN
        uint8 gpio5_deglitch_en : 1; // GPIO5_DEGLITCH_EN
        uint8 gpio5_sel : 2;      // GPIO5_SEL
    } bits;
    uint8 value;
} PmicCdd_Gpio5_Reg_t;

typedef union {
    struct {
        uint8 gpio6_dir : 1;      // GPIO6_DIR
        uint8 gpio6_od : 1;       // GPIO6_OD
        uint8 gpio6_pu_sel : 1;   // GPIO6_PU_SEL
        uint8 gpio6_pu_pd_en : 1; // GPIO6_PU_PD_EN
        uint8 gpio6_deglitch_en : 1; // GPIO6_DEGLITCH_EN
        uint8 gpio6_sel : 3;      // GPIO6_SEL
    } bits;
    uint8 value;
} PmicCdd_Gpio6_Reg_t;

typedef union {
    struct {
        uint8 wd_win1 : 7;  // WD_WIN1
    } bits;
    uint8 value;
} PmicCdd_WdWin1CfgReg_t;

typedef union {
    struct {
        uint8 wd_win2 : 7;  // WD_WIN2
    } bits;
    uint8 value;
} PmicCdd_WdWin2CfgReg_t;

typedef union {
    struct {
        uint8 wd_longwin : 8;  // WD_LONGWIN
    } bits;
    uint8 value;
} PmicCdd_WdLongWinCfgReg_t;

typedef union {
    struct {
        uint8 wd_return_longwin : 1;    // WD_RETURN_LONGWIN
        uint8 wd_mode_select : 1;       // WD_MODE_SELECT
        uint8 wd_pwrhold : 1;           // WD_PWRHOLD
        uint8 reserved2 : 3;            // RESERVED
        uint8 wd_endrv_sel : 1;         // WD_ENDRV_SEL
        uint8 wd_cnt_sel : 1;           // WD_CNT_SEL
    } bits;
    uint8 value;
} PmicCdd_WdModeReg_t;

typedef union {
    struct {
        uint8 wd_longwin_timeout_int : 1;  // WD_LONGWIN_TIMEOUT_INT
        uint8 wd_timeout : 1;              // WD_TIMEOUT
        uint8 wd_trig_early : 1;           // WD_TRIG_EARLY
        uint8 wd_answ_early : 1;           // WD_ANSW_EARLY
        uint8 wd_seq_err : 1;              // WD_SEQ_ERR
        uint8 wd_answ_err : 1;             // WD_ANSW_ERR
        uint8 wd_fail_int : 1;             // WD_FAIL_INT
        uint8 wd_rst_int : 1;              // WD_RST_INT
    } bits;
    uint8 value;
} PmicCdd_WdErrStatusReg_t;

typedef union {
    struct {
        uint8 wd_rst_th : 3;    // WD_RST_TH
        uint8 wd_fail_th : 3;   // WD_FAIL_TH
        uint8 wd_en : 1;        // WD_EN
        uint8 wd_rst_en : 1;    // WD_RST_EN
    } bits;
    uint8 value;
} PmicCdd_WdThrCfgReg_t;

typedef union {
    struct {
        uint8 wd_fail_cnt : 4;  // WD_FAIL_CNT
        uint8 reserved3 : 1;    // RESERVED
        uint8 wd_first_ok : 1;  // WD_FIRST_OK
        uint8 wd_bad_event : 1; // WD_BAD_EVENT
    } bits;
    uint8 value;
} PmicCdd_WdFailCntReg_t;

#if (PMICCDD_ACTIVE_VARIANT == PMICCDD_VARIANT_TPS65224)
typedef union {
    struct {
        uint8 adc_start : 1;                // ADC_START
        uint8 adc_cont_conv : 1;            // ADC_CONT_CONV
        uint8 adc_thermal_sel : 1;          // ADC_THERMAL_SEL
        uint8 adc_rdiv_en : 1;              // ADC_RDIV_EN
        uint8 reserved38 : 3;               // RESERVED
        uint8 adc_status : 1;               // ADC_STATUS
    } bits;
    uint8 value;
} PmicCdd_AdCtrl_Reg_t;                       // 0xACU

typedef union {
    struct {
        uint8 adc_result_11_4 : 8;          // ADC_RESULT_11_4
    } bits;
    uint8 value;
} PmicCdd_AdcResultReg1_Reg_t;                // 0xADU

typedef union {
    struct {
        uint8 reserved39 : 4;               // RESERVED
        uint8 adc_result_3_0 : 4;           // ADC_RESULT_3_0
    } bits;
    uint8 value;
} PmicCdd_AdcResultReg2_Reg_t;                // 0xAEU
#endif

typedef union {
    struct {
        uint8 buck1_uvov_mask : 1;       // BUCK1_UVOV_MASK
        uint8 buck2_uvov_mask : 1;       // BUCK2_UVOV_MASK
        uint8 buck3_uvov_mask : 1;       // BUCK3_UVOV_MASK
        uint8 buck4_uvov_mask : 1;       // BUCK4_UVOV_MASK
    } bits;
    uint8 value;
} PmicCdd_MaskBuck_Reg_t;                  // 0x49U

typedef union {
    struct {
        uint8 ldo1_uvov_mask : 1;        // LDO1_UVOV_MASK
        uint8 ldo2_uvov_mask : 1;        // LDO2_UVOV_MASK
        uint8 ldo3_uvov_mask : 1;        // LDO3_UVOV_MASK
        uint8 reserved17 : 1;            // RESERVED
        uint8 vcca_uvov_mask : 1;        // VCCA_UVOV_MASK 
        uint8 vmon1_uvov_mask : 1;       // VMON1_UVOV_MASK
        uint8 vmon2_uvov_mask : 1;       // VMON2_UVOV_MASK 
    } bits;
    uint8 value;
} PmicCdd_MaskLdoVmon_Reg_t;               // 0x4C

typedef union {
    struct {
        uint8 gpio1_fall_mask : 1;       // GPIO1_FALL_MASK
        uint8 gpio2_fall_mask : 1;       // GPIO2_FALL_MASK
        uint8 gpio3_fall_mask : 1;       // GPIO3_FALL_MASK
        uint8 gpio4_fall_mask : 1;       // GPIO4_FALL_MASK
        uint8 gpio5_fall_mask : 1;       // GPIO5_FALL_MASK
        uint8 gpio6_fall_mask : 1;       // GPIO6_FALL_MASK
    } bits;
    uint8 value;
} PmicCdd_MaskGpioFall_Reg_t;              // 0x4FU

typedef union {
    struct {
        uint8 gpio1_rise_mask : 1;       // GPIO1_RISE_MASK
        uint8 gpio2_rise_mask : 1;       // GPIO2_RISE_MASK
        uint8 gpio3_rise_mask : 1;       // GPIO3_RISE_MASK
        uint8 gpio4_rise_mask : 1;       // GPIO4_RISE_MASK
        uint8 gpio5_rise_mask : 1;       // GPIO5_RISE_MAKS
        uint8 gpio6_rise_mask : 1;       // GPIO6_RISE_MASK
    } bits;
    uint8 value;
} PmicCdd_MaskGpioRise_Reg_t;              // 0x50U

typedef union {
    struct {
        uint8 vsense_mask : 1;           // VSENSE_MASK
        uint8 enable_mask : 1;           // ENABLE_MASK
        uint8 pb_short_mask : 1;         // PB_SHORT_MASK
        uint8 reserved18 : 1;            // RESERVED
        uint8 fsd_mask : 1;              // FSD_MASK
        uint8 soft_reboot_mask : 1;      // SOFT_REBOOT_MASK
    } bits;
    uint8 value;
} PmicCdd_MaskStartup_Reg_t;               // 0x52U

typedef union {
    struct {
        uint8 bist_pass_mask : 1;        // BIST_PASS_MASK
        uint8 ext_clk_mask : 1;          // EXT_CLK_MASK
        uint8 reg_unlock_mask : 1;       // REG_UNLOCK_MASK
        uint8 twarn_mask : 1;            // TWARN_MASK
        uint8 pb_long_mask : 1;          // PB_LONG_MASK
        uint8 pb_fall_mask : 1;          // PB_FALL_MASK
        uint8 pb_rise_mask : 1;          // PB_RISE_MASK
        uint8 adc_conv_ready_mask : 1;   // ADC_CONV_READY_MASK
    } bits;
} PmicCdd_MaskMisc_Reg_t;                  // 0x53U

typedef union {
    struct {
        uint8 reserved19 : 1;            // RESERVED
        uint8 bist_fail_mask : 1;        // BIST_FAIL_MASK
        uint8 reg_crc_err_mask : 1;      // REG_CRC_ERR_MASK        
    } bits;
    uint8 value;
} PmicCdd_MaskModerateErr_Reg_t;           // 0x54U

typedef union {
    struct {
        uint8 imm_shutdown_mask : 1;     // IMM_SHUTDOWN_MASK
        uint8 ord_shutdown_mask : 1;     // ORD_SHUTDOWN_MASK
        uint8 mcu_pwr_err_mask : 1;      // MCU_PWR_ERR_MASK
        uint8 soc_pwr_err_mask : 1;      // SOC_PWR_ERR_MASK
        uint8 comm_err_mask : 1;         // COMM_ERR_MASK
        uint8 i2c2_err_mask : 1;         // I2C2_ERR_MASK
    } bits;
    uint8 value;
} PmicCdd_MaskFsmErr_Reg_t;                // 0x56U

typedef union {
    struct {
        uint8 reserved20 : 3;            // RESERVED
        uint8 esm_mcu_pin_mask : 1;      // ESM_MCU_PIN_MASK
        uint8 esm_mcu_fail_mask : 1;     // ESM_MCU_FAIL_MASK
        uint8 esm_mcu_rst_mask : 1;      // ESM_MCU_RST_MASK
    } bits;
    uint8 value;
} PmicCdd_MaskEsm_Reg_t;                   // 0x59U

/* Interrupt Registers */

typedef union {
    struct {
        uint8 buck_int : 1;              // BUCK_INT
        uint8 ldo_vmon_int : 1;          // LDO_VMON_INT
        uint8 gpio_int : 1;              // GPIO_INT
        uint8 startup_int : 1;           // STRATUP_INT
        uint8 misc_int : 1;              // MISC_INT
        uint8 moderate_err_int : 1;      // MODERATE_ERR_INT
        uint8 severe_err_int : 1;        // SEVERE_ERR_INT
        uint8 fsm_err_int : 1;           // FSM_ERR_INT
    } bits;
    uint8 value;
} PmicCdd_IntTop_Reg_t;                    // 0x5AU

typedef union {
    struct {
        uint8 buck1_uvov_int : 1;        // BUCK1_UVOV_INT
        uint8 buck2_uvov_int : 1;        // BUCK2_UVOV_INT
        uint8 buck3_uvov_int : 1;        // BUCK3_UVOV_INT
        uint8 buck4_uvov_int : 1;        // BUCK4_UVOV_INT
    } bits;
    uint8 value;
} PmicCdd_IntBuck_Reg_t;                   // 0x5B

typedef union {
    struct {
        uint8 ldo1_uvov_int : 1;         // LDO1_UVOV_INT
        uint8 ldo2_uvov_int : 1;         // LDO2_UVOV_INT
        uint8 ldo3_uvov_int : 1;         // LDO3_UVOV_INT
        uint8 reserved21 : 1;            // RESERVED
        uint8 vcca_uvov_int : 1;         // VCCA_UVOV_INT
        uint8 vmon1_uvov_int : 1;        // VMON1_UVOV_INT
        uint8 vmon2_uvov_int : 1;        // VMON2_UVOV_INT
    } bits;
    uint8 value;
} PmicCdd_IntLdoVmon_Reg_t;                // 0x5FU

typedef union {
    struct {
        uint8 gpio1_int : 1;             // GPIO1_INT
        uint8 gpio2_int : 1;             // GPIO2_INT
        uint8 gpio3_int : 1;             // GPIO3_INT
        uint8 gpio4_int : 1;             // GPIO4_INT
        uint8 gpio5_int : 1;             // GPIO5_INT
        uint8 gpio6_int : 1;             // GPIO6_INT
    } bits;
    uint8 value;
} PmicCdd_IntGpio_Reg_t;                   // 0x63

typedef union {
    struct {
        uint8 vsense_int : 1;            // VSENSE_INT
        uint8 enable_int : 1;            // ENABLE_INT
        uint8 pb_short_int : 1;          // PB_SHORT_INT
        uint8 reserved22 : 1;            // RESERVED
        uint8 fsd_int : 1;               // FSD_INT
        uint8 soft_reboot_int : 1;       // SOFT_REBOOT_INT
    } bits;
    uint8 value;
} PmicCdd_IntStartup_Reg_t;                // 0x65U

typedef union {
    struct {
        uint8 bist_pass_int : 1;         // BIST_PASS_INT
        uint8 ext_clk_int : 1;           // EXT_CLK_INT
        uint8 reg_unlock_int : 1;        // REG_UNLOCK_INT
        uint8 twarn_int : 1;             // TWARN_INT
        uint8 pb_long_int : 1;           // PB_LONG_INT
        uint8 pb_fall_int : 1;           // PB_FALL_INT
        uint8 pb_rise_int : 1;           // PB_RISE_INT
        uint8 adc_conv_ready_int : 1;    // ADC_CONV_READY_INT
    } bits;
    uint8 value;
} PmicCdd_IntMisc_Reg_t;                   // 0x66U

typedef union {
    struct {
        uint8 tsd_ord_int : 1;           // TSD_ORD_INT
        uint8 bist_fail_int : 1;         // BIST_FAIL_INT
        uint8 reg_crc_err_int : 1;       // REG_CRC_ERR_INT
        uint8 recov_cnt_int : 1;         // RECOV_CNT_INT
    } bits;
    uint8 value;
} PmicCdd_IntModerate_Reg_t;               // 0x67U

typedef union {
    struct {
        uint8 tsd_imm_int : 1;           // TSD_IMM_INT
        uint8 vcca_ovp_int : 1;          // VCCA_OVP_INT
        uint8 pfsm_err_int : 1;          // PFSM_ERR_INT
        uint8 bg_xmon_int : 1;           // BG_XMON_INT
    } bits;
    uint8 value;
} PmicCdd_IntSevereErr_Reg_t;              // 0x68U

typedef union {
    struct {
        uint8 imm_shutdown_int : 1;      // IMM_SHUTDOWN_INT
        uint8 ord_shutdown_int : 1;      // ORD_SHUTDOWN_INT
        uint8 mcu_pwr_err_int : 1;       // MCU_PWR_ERR_INT
        uint8 soc_pwr_err_int : 1;       // SOC_PWR_ERR_INT
        uint8 comm_err_int : 1;          // COMM_ERR_INT
        uint8 i2c2_err_int : 1;          // I2C2_ERR_INT
        uint8 esm_int : 1;               // ESM_INT
        uint8 wd_int : 1;                // WD_INT
    } bits;
    uint8 value;
} PmicCdd_IntFsmErr_Reg_t;                 // 0x69U

typedef union {
    struct {
        uint8 reserved23 : 1;            // RESERVED
        uint8 esm_mcu_pin_int : 1;       // ESM_MCU_PIN_INT
        uint8 esm_mcu_fail_int : 1;      // ESM_MCU_FAIL_INT
        uint8 esm_mcu_rst_int : 1;       // ESM_MCU_RST_INT
    } bits;
    uint8 value;                         
} PmicCdd_IntEsm_Reg_t;                    // 0x6C

/* Esm Registes */

typedef union {
    struct {
        uint8 esm_mcu_start : 1;           // ESM_MCU_START
    } bits;
    uint8 value;
} PmicCdd_EsmMcuStart_Reg_t;                  // 0x8F

typedef union {
    struct {
        uint8 esm_mcu_delay1 : 8;          // ESM_MCU_DELAY1
    } bits;
    uint8 value;
} PmicCdd_EsmMcuDelay1_Reg_t;                // 0x90

typedef union {
    struct {
        uint8 esm_mcu_delay2 : 8;          // ESM_MCU_DELAY2
    } bits;
    uint8 value;
} PmicCdd_EsmMcuDelay2_Reg_t;                // 0x91U

typedef union {
    struct {
        uint8 esm_mcu_err_cnt_th : 4;      // ESM_MCU_ERR_CNT_TH
        uint8 reserved36 : 1;              // RESERVED
        uint8 esm_mcu_endrv : 1;           // ESM_MCU_ENDRV
        uint8 esm_mcu_en : 1;              // ESM_MCU_ENDRV
        uint8 esm_mcu_mode : 1;            // ESM_MCU_MODE
    } bits;
    uint8 value;
} PmicCdd_EsmMcuModeCfg_Reg_t;               // 0x92U

typedef union {
    struct {
        uint8 esm_mcu_hmax : 8;            // ESM_MCU_HMAX
    } bits;
    uint8 value;
} PmicCdd_EsmMcuHmax_Reg_t;                  // 0x93U

typedef union {
    struct {
        uint8 esm_mcu_hmin : 8;            // ESM_MCU_HMIN
    } bits;
    uint8 value;
} PmicCdd_EsmMcuHmin_Reg_t;                  // 0x94U

typedef union {
    struct {
        uint8 esm_mcu_lmax : 8;            // ESM_MCU_LMAX
    } bits;
    uint8 vaule;
} PmicCdd_EsmMcuLmax_Reg_t;                  // 0x95U

typedef union {
    struct {
        uint8 esm_mcu_lmin : 8;            // ESM_MCU_LMIN
    } bits;
    uint8 value;
} PmicCdd_EsmMcuLmin_Reg_t;                  // 0x96U

typedef union {
    struct {
        uint8 esm_mcu_err_cnt : 5;         // ESM_MCU_ERR_CNT
    } bits;
    uint8 value;
} PmicCdd_EsmMcuErrCnt_Reg_t;                // 0x97U

typedef union{
    struct{
        uint8 reserved : 4;                // RESERVED
        uint8 i2c1_spi_crc_en : 1;         // I2C1_SPI_CRC_EN
        uint8 i2c2_crc_en : 1;             // I2C2_CRC_EN
    } bits;
    uint8 value;
}PmicCdd_Config2_Reg_t;                      // 0x7EU

typedef union {
    struct {
        uint8 recov_cnt : 4;               // RECOV_CNT
    } bits;
    uint8 value;
} PmicCdd_Recov_Cnt_Reg1_t;                  // 0x83U

typedef union {
    struct {
        uint8 recov_cnt_thr : 4;           // RECOV_CNT_THR
        uint8 recov_cnt_clr : 1;           // RECOV_CNT_CLR
    } bits;
    uint8 value;
} PmicCdd_Recov_Cnt_Reg2_t;                  // 0x84U

typedef union {
    struct {
        uint8 ss_depth : 1;                // SS_DEPTH
        uint8 reserved : 1;                // RESERVED
        uint8 ss_en : 1;                   // SS_EN
    } bits;
    uint8 value;
} PmicCdd_Spread_Spectrum1_Reg_t;            // 0x88U

typedef union {
    struct {
        uint8 buck1_en : 1;              // BUCK1_EN
        uint8 buck1_fpwm : 1;            // BUCK1_FPWM
        uint8 reserved : 2;              // RESERVED
        uint8 buck1_vmon_en : 1;         // BUCK1_VMON_EN
        uint8 buck1_pldn : 1;            // BUCK1_PLDN
    } bits;
    uint8 value;
} PmicCdd_Buck1_Ctrl_Reg_t;                  // 0x04U

typedef union {
    struct {
        uint8 buck2_en : 1;              // BUCK2_EN
        uint8 buck2_fpwm : 1;            // BUCK2_FPWM
        uint8 reserved : 2;              // RESERVED
        uint8 buck2_vmon_en : 1;         // BUCK2_VMON_EN
        uint8 buck2_pldn : 1;            // BUCK2_PLDN
    } bits;
    uint8 value;
} PmicCdd_Buck2_Ctrl_Reg_t;                  // 0x06U

typedef union {
    struct {
        uint8 buck3_en : 1;              // BUCK3_EN
        uint8 buck3_fpwm : 1;            // BUCK3_FPWM
        uint8 reserved : 2;              // RESERVED
        uint8 buck3_vmon_en : 1;         // BUCK3_VMON_EN
        uint8 buck3_pldn : 1;            // BUCK3_PLDN
    } bits;
    uint8 value;
} PmicCdd_Buck3_Ctrl_Reg_t;                  // 0x08U

typedef union {
    struct {
        uint8 buck4_en : 1;              // BUCK4_EN
        uint8 buck4_fpwm : 1;            // BUCK4_FPWM
        uint8 reserved : 2;              // RESERVED
        uint8 buck4_vmon_en : 1;         // BUCK4_VMON_EN
        uint8 buck4_pldn : 1;            // BUCK4_PLDN
    } bits;
    uint8 value;
} PmicCdd_Buck4_Ctrl_Reg_t;                  // 0x0AU

typedef union {
    struct {
        uint8 ldo1_en : 1;               // LDO1_EN
        uint8 reserved : 3;              // RESERVED
        uint8 ldo1_vmon_en : 1;          // LDO1_VMON_EN
        uint8 ldo1_discharge_en : 1;     // LDO1_DISCHARGE_EN
    } bits;
    uint8 value;
} PmicCdd_Ldo1_Ctrl_Reg_t;                   // 0x1DU

typedef union {
    struct {
        uint8 ldo2_en : 1;               // LDO2_EN
        uint8 reserved : 3;              // RESERVED
        uint8 ldo2_vmon_en : 1;          // LDO2_VMON_EN
        uint8 ldo2_discharge_en : 1;     // LDO2_DISCHARGE_EN
    } bits;
    uint8 value;
} PmicCdd_Ldo2_Ctrl_Reg_t;                   // 0x1EU

typedef union {
    struct {
        uint8 ldo3_en : 1;               // LDO3_EN
        uint8 reserved : 3;              // RESERVED
        uint8 ldo3_vmon_en : 1;          // LDO3_VMON_EN
        uint8 ldo3_discharge_en : 1;     // LDO3_DISCHARGE_EN
    } bits;
    uint8 value;
} PmicCdd_Ldo3_Ctrl_Reg_t;                   // 0x1FU

typedef union {
    struct {
        uint8 vcca_vmon_en : 1;             // VCCA_VMON_EN
        uint8 vmon1_en : 1;                 // VMON1_EN
        uint8 reserved : 1;                 // RESERVED
        uint8 vmon2_en : 1;                 // VMON2_EN
        uint8 reserved1 : 1;                // RESERVED 1
        uint8 vmon_deglitch_sel : 1;        // VMON_DEGLITCH_SEL
    } bits;
    uint8 value;
} PmicCdd_Vcca_VmonCtrl_Reg_t;                // 0xA1U

typedef union {
    struct
    {
        uint8 register_lock_status : 1;    // REGISTER_LOCK_STATUS
    } bits;
    uint8 value;
} PmicCdd_Register_Lock_Reg_t;              // 0xA1U

/* Enum for Long Window Timing to load into the register
tLONG_WINDOW_MIN = WD_LONGWIN[7:0] � 0.95 
*/

typedef enum {
    PMICCDD_LONG_WINDOW_80MS =      0u,   // 0.08 s
    PMICCDD_LONG_WINDOW_125MS =     1u,   // 0.125 s
    PMICCDD_LONG_WINDOW_250MS =     2u,   // 0.25 s
    PMICCDD_LONG_WINDOW_375MS =     3u,   // 0.375 s
    PMICCDD_LONG_WINDOW_500MS =     4u,   // 0.50 s
    PMICCDD_LONG_WINDOW_625MS =     5u,   // 0.625 s
    PMICCDD_LONG_WINDOW_750MS =     6u,   // 0.75 s
    PMICCDD_LONG_WINDOW_875MS =     7u,   // 0.875 s
    PMICCDD_LONG_WINDOW_1000MS =     8u,   // 1.0 s
    PMICCDD_LONG_WINDOW_1125MS =    9u,   // 1.125 s
    PMICCDD_LONG_WINDOW_1250MS =    10u,   // 1.25 s
    PMICCDD_LONG_WINDOW_1375MS =    11u,   // 1.375 s
    PMICCDD_LONG_WINDOW_1500MS =    12u,   // 1.50 s
    PMICCDD_LONG_WINDOW_1625MS =    13u,   // 1.625 s
    PMICCDD_LONG_WINDOW_1750MS =    14u,   // 1.75 s
    PMICCDD_LONG_WINDOW_1875MS =    15u,   // 1.875 s
    PMICCDD_LONG_WINDOW_2000MS =     16u,   // 2.0 s
    PMICCDD_LONG_WINDOW_2125MS =    17u,   // 2.125 s
    PMICCDD_LONG_WINDOW_2250MS =    18u,   // 2.25 s
    PMICCDD_LONG_WINDOW_2375MS =    19u,   // 2.375 s
    PMICCDD_LONG_WINDOW_2500MS =    20u,   // 2.5 s
    PMICCDD_LONG_WINDOW_2625MS =    21u,   // 2.625 s
    PMICCDD_LONG_WINDOW_2750MS =    22u,   // 2.75 s
    PMICCDD_LONG_WINDOW_2875MS =    23u,   // 2.875 s
    PMICCDD_LONG_WINDOW_3000MS =     24u,   // 3.0 s
    PMICCDD_LONG_WINDOW_3125MS =    25u,   // 3.125 s
    PMICCDD_LONG_WINDOW_3250MS =    26u,   // 3.25 s
    PMICCDD_LONG_WINDOW_3375MS =    27u,   // 3.375 s
    PMICCDD_LONG_WINDOW_3500MS =    28u,   // 3.5 s
    PMICCDD_LONG_WINDOW_3625MS =    29u,   // 3.625 s
    PMICCDD_LONG_WINDOW_3750MS =    30u,   // 3.75 s
    PMICCDD_LONG_WINDOW_3875MS =    31u,   // 3.875 s
    PMICCDD_LONG_WINDOW_4000MS =    32u,   // 4.0 s
    PMICCDD_LONG_WINDOW_4125MS =    33u,   // 4.125 s
    PMICCDD_LONG_WINDOW_4250MS =    34u,   // 4.25 s
    PMICCDD_LONG_WINDOW_4375MS =    35u,   // 4.375 s
    PMICCDD_LONG_WINDOW_4500MS =    36u,   // 4.5 s
    PMICCDD_LONG_WINDOW_4625MS =    37u,   // 4.625 s
    PMICCDD_LONG_WINDOW_4750MS =    38u,   // 4.75 s
    PMICCDD_LONG_WINDOW_4875MS =    39u,   // 4.875 s
    PMICCDD_LONG_WINDOW_5000MS =     40u,   // 5.0 s
    PMICCDD_LONG_WINDOW_5125MS =    41u,   // 5.125 s
    PMICCDD_LONG_WINDOW_5250MS =    42u,   // 5.25 s
    PMICCDD_LONG_WINDOW_5375MS =    43u,   // 5.375 s
    PMICCDD_LONG_WINDOW_5500MS =    44u,   // 5.5 s
    PMICCDD_LONG_WINDOW_5625MS =    45u,   // 5.625 s
    PMICCDD_LONG_WINDOW_5750MS =    46u,   // 5.75 s
    PMICCDD_LONG_WINDOW_5875MS =    47u,   // 5.875 s
    PMICCDD_LONG_WINDOW_6000MS =     48u,   // 6.0 s
    PMICCDD_LONG_WINDOW_6125MS =    49u,   // 6.125 s
    PMICCDD_LONG_WINDOW_6250MS =    50u,   // 6.25 s
    PMICCDD_LONG_WINDOW_6375MS =    51u,   // 6.375 s
    PMICCDD_LONG_WINDOW_6500MS =    52u,   // 6.5 s
    PMICCDD_LONG_WINDOW_6625MS =    53u,   // 6.625 s
    PMICCDD_LONG_WINDOW_6750MS =    54u,   // 6.75 s
    PMICCDD_LONG_WINDOW_6875MS =    55u,   // 6.875 s
    PMICCDD_LONG_WINDOW_7000MS =    56u,   // 7.0 s
    PMICCDD_LONG_WINDOW_7125MS =    57u,   // 7.125 s
    PMICCDD_LONG_WINDOW_7250MS =    58u,   // 7.25 s
    PMICCDD_LONG_WINDOW_7375MS =    59u,   // 7.375 s
    PMICCDD_LONG_WINDOW_7500MS =    60u,   // 7.5 s
    PMICCDD_LONG_WINDOW_7625MS =    61u,   // 7.625 s
    PMICCDD_LONG_WINDOW_7750MS =    62u,   // 7.75 s
    PMICCDD_LONG_WINDOW_7875MS =    63u,   // 7.875 s
    PMICCDD_LONG_WINDOW_8000MS =     64u,   // 8.0 s
    PMICCDD_LONG_WINDOW_12000MS =   65u,   // 12.0 s
    PMICCDD_LONG_WINDOW_16000MS =   66u,   // 16.0 s
    PMICCDD_LONG_WINDOW_20000MS =   67u,   // 20.0 s
    PMICCDD_LONG_WINDOW_24000MS =   68u,   // 24.0 s
    PMICCDD_LONG_WINDOW_28000MS =   69u,   // 28.0 s
    PMICCDD_LONG_WINDOW_32000MS =   70u,   // 32.0 s
    PMICCDD_LONG_WINDOW_36000MS =   71u,   // 36.0 s
    PMICCDD_LONG_WINDOW_40000MS =   72u,   // 40.0 s
    PMICCDD_LONG_WINDOW_44000MS =   73u,   // 44.0 s
    PMICCDD_LONG_WINDOW_48000MS =   74u,   // 48.0 s
    PMICCDD_LONG_WINDOW_52000MS =   75u,   // 52.0 s
    PMICCDD_LONG_WINDOW_56000MS =   76u,   // 56.0 s
    PMICCDD_LONG_WINDOW_60000MS =   77u,   // 60.0 s
    PMICCDD_LONG_WINDOW_64000MS =   78u,   // 64.0 s
    PMICCDD_LONG_WINDOW_68000MS =   79u,   // 68.0 s
    PMICCDD_LONG_WINDOW_72000MS =   80u,   // 72.0 s
    PMICCDD_LONG_WINDOW_76000MS =   81u,   // 76.0 s
    PMICCDD_LONG_WINDOW_80000MS =   82u,   // 80.0 s
    PMICCDD_LONG_WINDOW_84000MS =   83u,   // 84.0 s
    PMICCDD_LONG_WINDOW_88000MS =   84u,   // 88.0 s
    PMICCDD_LONG_WINDOW_92000MS =   85u,   // 92.0 s
    PMICCDD_LONG_WINDOW_96000MS =   86u,   // 96.0 s
    PMICCDD_LONG_WINDOW_100000MS =  87u,   // 100.0 s
    PMICCDD_LONG_WINDOW_104000MS =  88u,   // 104.0 s
    PMICCDD_LONG_WINDOW_108000MS =  89u,   // 108.0 s
    PMICCDD_LONG_WINDOW_112000MS =  90u,   // 112.0 s
    PMICCDD_LONG_WINDOW_116000MS =  91u,   // 116.0 s
    PMICCDD_LONG_WINDOW_120000MS =  92u,   // 120.0 s
    PMICCDD_LONG_WINDOW_124000MS =  93u,   // 124.0 s
    PMICCDD_LONG_WINDOW_128000MS =  94u,   // 128.0 s
    PMICCDD_LONG_WINDOW_132000MS =  95u,   // 132.0 s
    PMICCDD_LONG_WINDOW_136000MS =  96u,   // 136.0 s
    PMICCDD_LONG_WINDOW_140000MS =  97u,   // 140.0 s
    PMICCDD_LONG_WINDOW_144000MS =  98u,   // 144.0 s
    PMICCDD_LONG_WINDOW_148000MS =  99u,   // 148.0 s
    PMICCDD_LONG_WINDOW_152000MS =  100u,  // 152.0 s
    PMICCDD_LONG_WINDOW_156000MS =  101u,  // 156.0 s
    PMICCDD_LONG_WINDOW_160000MS =  102u,  // 160.0 s
    PMICCDD_LONG_WINDOW_164000MS =  103u,  // 164.0 s
    PMICCDD_LONG_WINDOW_168000MS =  104u,  // 168.0 s
    PMICCDD_LONG_WINDOW_172000MS =  105u,  // 172.0 s
    PMICCDD_LONG_WINDOW_176000MS =  106u,  // 176.0 s
    PMICCDD_LONG_WINDOW_180000MS =  107u,  // 180.0 s
    PMICCDD_LONG_WINDOW_184000MS =  108u,  // 184.0 s
    PMICCDD_LONG_WINDOW_188000MS =  109u,  // 188.0 s
    PMICCDD_LONG_WINDOW_192000MS =  110u,  // 192.0 s
    PMICCDD_LONG_WINDOW_196000MS =  111u,  // 196.0 s
    PMICCDD_LONG_WINDOW_200000MS =  112u,  // 200.0 s
    PMICCDD_LONG_WINDOW_204000MS =  113u,  // 204.0 s
    PMICCDD_LONG_WINDOW_208000MS =  114u,  // 208.0 s
    PMICCDD_LONG_WINDOW_212000MS =  115u,  // 212.0 s
    PMICCDD_LONG_WINDOW_216000MS =  116u,  // 216.0 s
    PMICCDD_LONG_WINDOW_220000MS =  117u,  // 220.0 s
    PMICCDD_LONG_WINDOW_224000MS =  118u,  // 224.0 s
    PMICCDD_LONG_WINDOW_228000MS =  119u,  // 228.0 s
    PMICCDD_LONG_WINDOW_232000MS =  120u,  // 232.0 s
    PMICCDD_LONG_WINDOW_236000MS =  121u,  // 236.0 s
    PMICCDD_LONG_WINDOW_240000MS =  122u,  // 240.0 s
    PMICCDD_LONG_WINDOW_244000MS =  123u,  // 244.0 s
    PMICCDD_LONG_WINDOW_248000MS =  124u,  // 248.0 s
    PMICCDD_LONG_WINDOW_252000MS =  125u,  // 252.0 s
    PMICCDD_LONG_WINDOW_256000MS =  126u,  // 256.0 s
    PMICCDD_LONG_WINDOW_260000MS =  127u,  // 260.0 s
    PMICCDD_LONG_WINDOW_264000MS =  128u,  // 264.0 s
    PMICCDD_LONG_WINDOW_268000MS =  129u,  // 268.0 s
    PMICCDD_LONG_WINDOW_272000MS =  130u,  // 272.0 s
    PMICCDD_LONG_WINDOW_276000MS =  131u,  // 276.0 s
    PMICCDD_LONG_WINDOW_280000MS =  132u,  // 280.0 s
    PMICCDD_LONG_WINDOW_284000MS =  133u,  // 284.0 s
    PMICCDD_LONG_WINDOW_288000MS =  134u,  // 288.0 s
    PMICCDD_LONG_WINDOW_292000MS =  135u,  // 292.0 s
    PMICCDD_LONG_WINDOW_296000MS =  136u,  // 296.0 s
    PMICCDD_LONG_WINDOW_300000MS =  137u,  // 300.0 s
    PMICCDD_LONG_WINDOW_304000MS =  138u,  // 304.0 s
    PMICCDD_LONG_WINDOW_308000MS =  139u,  // 308.0 s
    PMICCDD_LONG_WINDOW_312000MS =  140u,  // 312.0 s
    PMICCDD_LONG_WINDOW_316000MS =  141u,  // 316.0 s
    PMICCDD_LONG_WINDOW_320000MS =  142u,  // 320.0 s
    PMICCDD_LONG_WINDOW_324000MS =  143u,  // 324.0 s
    PMICCDD_LONG_WINDOW_328000MS =  144u,  // 328.0 s
    PMICCDD_LONG_WINDOW_332000MS =  145u,  // 332.0 s
    PMICCDD_LONG_WINDOW_336000MS =  146u,  // 336.0 s
    PMICCDD_LONG_WINDOW_340000MS =  147u,  // 340.0 s
    PMICCDD_LONG_WINDOW_344000MS =  148u,  // 344.0 s
    PMICCDD_LONG_WINDOW_348000MS =  149u,  // 348.0 s
    PMICCDD_LONG_WINDOW_352000MS =  150u,  // 352.0 s
    PMICCDD_LONG_WINDOW_356000MS =  151u,  // 356.0 s
    PMICCDD_LONG_WINDOW_360000MS =  152u,  // 360.0 s
    PMICCDD_LONG_WINDOW_364000MS =  153u,  // 364.0 s
    PMICCDD_LONG_WINDOW_368000MS =  154u,  // 368.0 s
    PMICCDD_LONG_WINDOW_372000MS =  155u,  // 372.0 s
    PMICCDD_LONG_WINDOW_376000MS =  156u,  // 376.0 s
    PMICCDD_LONG_WINDOW_380000MS =  157u,  // 380.0 s
    PMICCDD_LONG_WINDOW_384000MS =  158u,  // 384.0 s
    PMICCDD_LONG_WINDOW_388000MS =  159u,  // 388.0 s
    PMICCDD_LONG_WINDOW_392000MS =  160u,  // 392.0 s
    PMICCDD_LONG_WINDOW_396000MS =  161u,  // 396.0 s
    PMICCDD_LONG_WINDOW_400000MS =  162u,  // 400.0 s
    PMICCDD_LONG_WINDOW_404000MS =  163u,  // 404.0 s
    PMICCDD_LONG_WINDOW_408000MS =  164u,  // 408.0 s
    PMICCDD_LONG_WINDOW_412000MS =  165u,  // 412.0 s
    PMICCDD_LONG_WINDOW_416000MS =  166u,  // 416.0 s
    PMICCDD_LONG_WINDOW_420000MS =  167u,  // 420.0 s
    PMICCDD_LONG_WINDOW_424000MS =  168u,  // 424.0 s
    PMICCDD_LONG_WINDOW_428000MS =  169u,  // 428.0 s
    PMICCDD_LONG_WINDOW_432000MS =  170u,  // 432.0 s
    PMICCDD_LONG_WINDOW_436000MS =  171u,  // 436.0 s
    PMICCDD_LONG_WINDOW_440000MS =  172u,  // 440.0 s
    PMICCDD_LONG_WINDOW_444000MS =  173u,  // 444.0 s
    PMICCDD_LONG_WINDOW_448000MS =  174u,  // 448.0 s
    PMICCDD_LONG_WINDOW_452000MS =  175u,  // 452.0 s
    PMICCDD_LONG_WINDOW_456000MS =  176u,  // 456.0 s
    PMICCDD_LONG_WINDOW_460000MS =  177u,  // 460.0 s
    PMICCDD_LONG_WINDOW_464000MS =  178u,  // 464.0 s
    PMICCDD_LONG_WINDOW_468000MS =  179u,  // 468.0 s
    PMICCDD_LONG_WINDOW_472000MS =  180u,  // 472.0 s
    PMICCDD_LONG_WINDOW_476000MS =  181u,  // 476.0 s
    PMICCDD_LONG_WINDOW_480000MS =  182u,  // 480.0 s
    PMICCDD_LONG_WINDOW_484000MS =  183u,  // 484.0 s
    PMICCDD_LONG_WINDOW_488000MS =  184u,  // 488.0 s
    PMICCDD_LONG_WINDOW_492000MS =  185u,  // 492.0 s
    PMICCDD_LONG_WINDOW_496000MS =  186u,  // 496.0 s
    PMICCDD_LONG_WINDOW_500000MS =  187u,  // 500.0 s
    PMICCDD_LONG_WINDOW_504000MS =  188u,  // 504.0 s
    PMICCDD_LONG_WINDOW_508000MS =  189u,  // 508.0 s
    PMICCDD_LONG_WINDOW_512000MS =  190u,  // 512.0 s
    PMICCDD_LONG_WINDOW_516000MS =  191u,  // 516.0 s
    PMICCDD_LONG_WINDOW_520000MS =  192u,  // 520.0 s
    PMICCDD_LONG_WINDOW_524000MS =  193u,  // 524.0 s
    PMICCDD_LONG_WINDOW_528000MS =  194u,  // 528.0 s
    PMICCDD_LONG_WINDOW_532000MS =  195u,  // 532.0 s
    PMICCDD_LONG_WINDOW_536000MS =  196u,  // 536.0 s
    PMICCDD_LONG_WINDOW_540000MS =  197u,  // 540.0 s
    PMICCDD_LONG_WINDOW_544000MS =  198u,  // 544.0 s
    PMICCDD_LONG_WINDOW_548000MS =  199u,  // 548.0 s
    PMICCDD_LONG_WINDOW_552000MS =  200u,  // 552.0 s
    PMICCDD_LONG_WINDOW_556000MS =  201u,  // 556.0 s
    PMICCDD_LONG_WINDOW_560000MS =  202u,  // 560.0 s
    PMICCDD_LONG_WINDOW_564000MS =  203u,  // 564.0 s
    PMICCDD_LONG_WINDOW_568000MS =  204u,  // 568.0 s
    PMICCDD_LONG_WINDOW_572000MS =  205u,  // 572.0 s
    PMICCDD_LONG_WINDOW_576000MS =  206u,  // 576.0 s
    PMICCDD_LONG_WINDOW_580000MS =  207u,  // 580.0 s
    PMICCDD_LONG_WINDOW_584000MS =  208u,  // 584.0 s
    PMICCDD_LONG_WINDOW_588000MS =  209u,  // 588.0 s
    PMICCDD_LONG_WINDOW_592000MS =  210u,  // 592.0 s
    PMICCDD_LONG_WINDOW_596000MS =  211u,  // 596.0 s
    PMICCDD_LONG_WINDOW_600000MS =  212u,  // 600.0 s
    PMICCDD_LONG_WINDOW_604000MS =  213u,  // 604.0 s
    PMICCDD_LONG_WINDOW_608000MS =  214u,  // 608.0 s
    PMICCDD_LONG_WINDOW_612000MS =  215u,  // 612.0 s
    PMICCDD_LONG_WINDOW_616000MS =  216u,  // 616.0 s
    PMICCDD_LONG_WINDOW_620000MS =  217u,  // 620.0 s
    PMICCDD_LONG_WINDOW_624000MS =  218u,  // 624.0 s
    PMICCDD_LONG_WINDOW_628000MS =  219u,  // 628.0 s
    PMICCDD_LONG_WINDOW_632000MS =  220u,  // 632.0 s
    PMICCDD_LONG_WINDOW_636000MS =  221u,  // 636.0 s
    PMICCDD_LONG_WINDOW_640000MS =  222u,  // 640.0 s
    PMICCDD_LONG_WINDOW_644000MS =  223u,  // 644.0 s
    PMICCDD_LONG_WINDOW_648000MS =  224u,  // 648.0 s
    PMICCDD_LONG_WINDOW_652000MS =  225u,  // 652.0 s
    PMICCDD_LONG_WINDOW_656000MS =  226u,  // 656.0 s
    PMICCDD_LONG_WINDOW_660000MS =  227u,  // 660.0 s
    PMICCDD_LONG_WINDOW_664000MS =  228u,  // 664.0 s
    PMICCDD_LONG_WINDOW_668000MS =  229u,  // 668.0 s
    PMICCDD_LONG_WINDOW_672000MS =  230u,  // 672.0 s
    PMICCDD_LONG_WINDOW_676000MS =  231u,  // 676.0 s
    PMICCDD_LONG_WINDOW_680000MS =  232u,  // 680.0 s
    PMICCDD_LONG_WINDOW_684000MS =  233u,  // 684.0 s
    PMICCDD_LONG_WINDOW_688000MS =  234u,  // 688.0 s
    PMICCDD_LONG_WINDOW_692000MS =  235u,  // 692.0 s
    PMICCDD_LONG_WINDOW_696000MS =  236u,  // 696.0 s
    PMICCDD_LONG_WINDOW_700000MS =  237u,  // 700.0 s
    PMICCDD_LONG_WINDOW_704000MS =  238u,  // 704.0 s
    PMICCDD_LONG_WINDOW_708000MS =  239u,  // 708.0 s
    PMICCDD_LONG_WINDOW_712000MS =  240u,  // 712.0 s
    PMICCDD_LONG_WINDOW_716000MS =  241u,  // 716.0 s
    PMICCDD_LONG_WINDOW_720000MS =  242u,  // 720.0 s
    PMICCDD_LONG_WINDOW_724000MS =  243u,  // 724.0 s
    PMICCDD_LONG_WINDOW_728000MS =  244u,  // 728.0 s
    PMICCDD_LONG_WINDOW_732000MS =  245u,  // 732.0 s
    PMICCDD_LONG_WINDOW_736000MS =  246u,  // 736.0 s
    PMICCDD_LONG_WINDOW_740000MS =  247u,  // 740.0 s
    PMICCDD_LONG_WINDOW_744000MS =  248u,  // 744.0 s
    PMICCDD_LONG_WINDOW_748000MS =  249u,  // 748.0 s
    PMICCDD_LONG_WINDOW_752000MS =  250u,  // 752.0 s
    PMICCDD_LONG_WINDOW_756000MS =  251u,  // 756.0 s
    PMICCDD_LONG_WINDOW_760000MS =  252u,  // 760.0 s
    PMICCDD_LONG_WINDOW_764000MS =  253u,  // 764.0 s
    PMICCDD_LONG_WINDOW_768000MS =  254u,  // 768.0 s
    PMICCDD_LONG_WINDOW_772000MS =  255u  // 772.0 s
}ePmicCdd_LongWindow_TimeType;


/* 
 * tWINDOW1_MIN = (WD_WIN1 + 1) × 0.55 × 0.95 ms
 * tWINDOW1_MAX = (WD_WIN1 + 1) × 0.55 × 1.05 ms
 * tWINDOW2_MIN = (WD_WIN2 + 1) × 0.55 × 0.95 ms
 * tWINDOW2_MAX = (WD_WIN2 + 1) × 0.55 × 1.05 ms
 *
 * Use tWINDOWx_MAX for earliest allowed refresh 
 * and tWINDOWx_MIN for latest allowed refresh.
 * → This ensures the watchdog service always occurs safely 
 *   within the actual hardware window (accounts for oscillator tolerance).
 */

typedef enum {
    PMICCDD_WINDOW_1_2_550US =      0u,     // 0.55 ms
    PMICCDD_WINDOW_1_2_1100US =     1u,     // 1.10 ms
    PMICCDD_WINDOW_1_2_1650US =     2u,     // 1.65 ms
    PMICCDD_WINDOW_1_2_2200US =     3u,     // 2.20 ms
    PMICCDD_WINDOW_1_2_2750US =     4u,     // 2.75 ms
    PMICCDD_WINDOW_1_2_3300US =     5u,     // 3.30 ms
    PMICCDD_WINDOW_1_2_3850US =     6u,     // 3.85 ms
    PMICCDD_WINDOW_1_2_4400US =     7u,     // 4.40 ms
    PMICCDD_WINDOW_1_2_4950US =     8u,     // 4.95 ms
    PMICCDD_WINDOW_1_2_5500US =     9u,     // 5.50 ms
    PMICCDD_WINDOW_1_2_6050US =     10u,      // 6.05 ms
    PMICCDD_WINDOW_1_2_6600US =     11u,      // 6.60 ms
    PMICCDD_WINDOW_1_2_7150US =     12u,      // 7.15 ms
    PMICCDD_WINDOW_1_2_7700US =     13u,      // 7.70 ms
    PMICCDD_WINDOW_1_2_8250US =     14u,      // 8.25 ms
    PMICCDD_WINDOW_1_2_8800US =     15u,      // 8.80 ms
    PMICCDD_WINDOW_1_2_9350US =     16u,      // 9.35 ms
    PMICCDD_WINDOW_1_2_9900US =     17u,      // 9.90 ms
    PMICCDD_WINDOW_1_2_10450US =   18u,      // 10.45 ms
    PMICCDD_WINDOW_1_2_11000US =   19u,   // 11.00 ms
    PMICCDD_WINDOW_1_2_11550US =   20u,   // 11.55 ms
    PMICCDD_WINDOW_1_2_12100US =   21u,   // 12.10 ms
    PMICCDD_WINDOW_1_2_12650US =   22u,   // 12.65 ms
    PMICCDD_WINDOW_1_2_13200US =   23u,   // 13.20 ms
    PMICCDD_WINDOW_1_2_13750US =   24u,   // 13.75 ms
    PMICCDD_WINDOW_1_2_14300US =   25u,   // 14.30 ms
    PMICCDD_WINDOW_1_2_14850US =   26u,   // 14.85 ms
    PMICCDD_WINDOW_1_2_15400US =   27u,   // 15.40 ms
    PMICCDD_WINDOW_1_2_15950US =   28u,   // 15.95 ms
    PMICCDD_WINDOW_1_2_16500US =   29u,   // 16.50 ms
    PMICCDD_WINDOW_1_2_17050US =   30u,   // 17.05 ms
    PMICCDD_WINDOW_1_2_17600US =   31u,   // 17.60 ms
    PMICCDD_WINDOW_1_2_18150US =   32u,   // 18.15 ms
    PMICCDD_WINDOW_1_2_18700US =   33u,   // 18.70 ms
    PMICCDD_WINDOW_1_2_19250US =   34u,   // 19.25 ms
    PMICCDD_WINDOW_1_2_19800US =   35u,   // 19.80 ms
    PMICCDD_WINDOW_1_2_20350US =   36u,   // 20.35 ms
    PMICCDD_WINDOW_1_2_20900US =   37u,   // 20.90 ms
    PMICCDD_WINDOW_1_2_21450US =   38u,   // 21.45 ms
    PMICCDD_WINDOW_1_2_22000US =   39u,   // 22.00 ms
    PMICCDD_WINDOW_1_2_22550US =   40u,   // 22.55 ms
    PMICCDD_WINDOW_1_2_23100US =   41u,   // 23.10 ms
    PMICCDD_WINDOW_1_2_23650US =   42u,   // 23.65 ms
    PMICCDD_WINDOW_1_2_24200US =   43u,   // 24.20 ms
    PMICCDD_WINDOW_1_2_24750US =   44u,   // 24.75 ms
    PMICCDD_WINDOW_1_2_25300US =   45u,   // 25.30 ms
    PMICCDD_WINDOW_1_2_25850US =   46u,   // 25.85 ms
    PMICCDD_WINDOW_1_2_26400US =   47u,   // 26.40 ms
    PMICCDD_WINDOW_1_2_26950US =   48u,   // 26.95 ms
    PMICCDD_WINDOW_1_2_27500US =   49u,   // 27.50 ms
    PMICCDD_WINDOW_1_2_28050US =   50u,   // 28.05 ms
    PMICCDD_WINDOW_1_2_28600US =   51u,   // 28.60 ms
    PMICCDD_WINDOW_1_2_29150US =   52u,   // 29.15 ms
    PMICCDD_WINDOW_1_2_29700US =   53u,   // 29.70 ms
    PMICCDD_WINDOW_1_2_30250US =   54u,   // 30.25 ms
    PMICCDD_WINDOW_1_2_30800US =   55u,   // 30.80 ms
    PMICCDD_WINDOW_1_2_31350US =   56u,   // 31.35 ms
    PMICCDD_WINDOW_1_2_31900US =   57u,   // 31.90 ms
    PMICCDD_WINDOW_1_2_32450US =   58u,   // 32.45 ms
    PMICCDD_WINDOW_1_2_33000US =   59u,   // 33.00 ms
    PMICCDD_WINDOW_1_2_33550US =   60u,   // 33.55 ms
    PMICCDD_WINDOW_1_2_34100US =   61u,   // 34.10 ms
    PMICCDD_WINDOW_1_2_34650US =   62u,   // 34.65 ms
    PMICCDD_WINDOW_1_2_35200US =   63u,   // 35.20 ms
    PMICCDD_WINDOW_1_2_35750US =   64u,   // 35.75 ms
    PMICCDD_WINDOW_1_2_36300US =   65u,   // 36.30 ms
    PMICCDD_WINDOW_1_2_36850US =   66u,   // 36.85 ms
    PMICCDD_WINDOW_1_2_37400US =   67u,   // 37.40 ms
    PMICCDD_WINDOW_1_2_37950US =   68u,   // 37.95 ms
    PMICCDD_WINDOW_1_2_38500US =   69u,   // 38.50 ms
    PMICCDD_WINDOW_1_2_39050US =   70u,   // 39.05 ms
    PMICCDD_WINDOW_1_2_39600US =   71u,   // 39.60 ms
    PMICCDD_WINDOW_1_2_40150US =   72u,   // 40.15 ms
    PMICCDD_WINDOW_1_2_40700US =   73u,   // 40.70 ms
    PMICCDD_WINDOW_1_2_41250US =   74u,   // 41.25 ms
    PMICCDD_WINDOW_1_2_41800US =   75u,   // 41.80 ms
    PMICCDD_WINDOW_1_2_42350US =   76u,   // 42.35 ms
    PMICCDD_WINDOW_1_2_42900US =   77u,   // 42.90 ms
    PMICCDD_WINDOW_1_2_43450US =   78u,   // 43.45 ms
    PMICCDD_WINDOW_1_2_44000US =   79u,   // 44.00 ms
    PMICCDD_WINDOW_1_2_44550US =   80u,   // 44.55 ms
    PMICCDD_WINDOW_1_2_45100US =   81u,   // 45.10 ms
    PMICCDD_WINDOW_1_2_45650US =   82u,   // 45.65 ms
    PMICCDD_WINDOW_1_2_46200US =   83u,   // 46.20 ms
    PMICCDD_WINDOW_1_2_46750US =   84u,   // 46.75 ms
    PMICCDD_WINDOW_1_2_47300US =   85u,   // 47.30 ms
    PMICCDD_WINDOW_1_2_47850US =   86u,   // 47.85 ms
    PMICCDD_WINDOW_1_2_48400US =   87u,   // 48.40 ms
    PMICCDD_WINDOW_1_2_48950US =   88u,   // 48.95 ms
    PMICCDD_WINDOW_1_2_49500US =   89u,   // 49.50 ms
    PMICCDD_WINDOW_1_2_50050US =   90u,   // 50.05 ms
    PMICCDD_WINDOW_1_2_50600US =   91u,   // 50.60 ms
    PMICCDD_WINDOW_1_2_51150US =   92u,   // 51.15 ms
    PMICCDD_WINDOW_1_2_51700US =   93u,   // 51.70 ms
    PMICCDD_WINDOW_1_2_52250US =   94u,   // 52.25 ms
    PMICCDD_WINDOW_1_2_52800US =   95u,   // 52.80 ms
    PMICCDD_WINDOW_1_2_53350US =   96u,   // 53.35 ms
    PMICCDD_WINDOW_1_2_53900US =   97u,   // 53.90 ms
    PMICCDD_WINDOW_1_2_54450US =   98u,   // 54.45 ms
    PMICCDD_WINDOW_1_2_55000US =   99u,   // 55.00 ms
    PMICCDD_WINDOW_1_2_55550US =   100u,   // 55.55 ms
    PMICCDD_WINDOW_1_2_56100US =   101u,   // 56.10 ms
    PMICCDD_WINDOW_1_2_56650US =   102u,   // 56.65 ms
    PMICCDD_WINDOW_1_2_57200US =   103u,   // 57.20 ms
    PMICCDD_WINDOW_1_2_57750US =   104u,   // 57.75 ms
    PMICCDD_WINDOW_1_2_58300US =   105u,   // 58.30 ms
    PMICCDD_WINDOW_1_2_58850US =   106u,   // 58.85 ms
    PMICCDD_WINDOW_1_2_59400US =   107u,   // 59.40 ms
    PMICCDD_WINDOW_1_2_59950US =   108u,   // 59.95 ms
    PMICCDD_WINDOW_1_2_60500US =   109u,   // 60.50 ms
    PMICCDD_WINDOW_1_2_61050US =   110u,   // 61.05 ms
    PMICCDD_WINDOW_1_2_61600US =   111u,   // 61.60 ms
    PMICCDD_WINDOW_1_2_62150US =   112u,   // 62.15 ms
    PMICCDD_WINDOW_1_2_62700US =   113u,   // 62.70 ms
    PMICCDD_WINDOW_1_2_63250US =   114u,   // 63.25 ms
    PMICCDD_WINDOW_1_2_63800US =   115u,   // 63.80 ms
    PMICCDD_WINDOW_1_2_64350US =   116u,   // 64.35 ms
    PMICCDD_WINDOW_1_2_64900US =   117u,   // 64.90 ms
    PMICCDD_WINDOW_1_2_65450US =   118u,   // 65.45 ms
    PMICCDD_WINDOW_1_2_66000US =   119u,   // 66.00 ms
    PMICCDD_WINDOW_1_2_66550US =   120u,   // 66.55 ms
    PMICCDD_WINDOW_1_2_67100US =   121u,   // 67.10 ms
    PMICCDD_WINDOW_1_2_67650US =   122u,   // 67.65 ms
    PMICCDD_WINDOW_1_2_68200US =   123u,   // 68.20 ms
    PMICCDD_WINDOW_1_2_68750US =   124u,   // 68.75 ms
    PMICCDD_WINDOW_1_2_69300US =   125u,   // 69.30 ms
    PMICCDD_WINDOW_1_2_69850US =   126u,   // 69.85 ms
    PMICCDD_WINDOW_1_2_70400US =   127u   // 70.40 ms
}ePmicCdd_Win1_2_TimeType;

/* ESM Related Timings. this follow the below MIN delay formula
Min. tDELAY-1 = (ESM_MCU_DELAY1[7:0] � 2.048 ms) � 0.95
Min. tDELAY-2 = (ESM_MCU_DELAY2[7:0] � 2.048 ms) � 0.95
*/

typedef enum {
    PMICCDD_ESM_DELAY_1_2_000MS = 0u,    // 0.000 ms
    PMICCDD_ESM_DELAY_1_2_002MS = 1u,    // 0.002 ms
    PMICCDD_ESM_DELAY_1_2_004MS = 2u,    // 0.004 ms
    PMICCDD_ESM_DELAY_1_2_006MS = 3u,    // 0.006 ms
    PMICCDD_ESM_DELAY_1_2_008MS = 4u,    // 0.008 ms
    PMICCDD_ESM_DELAY_1_2_010MS = 5u,    // 0.010 ms
    PMICCDD_ESM_DELAY_1_2_012MS = 6u,    // 0.012 ms
    PMICCDD_ESM_DELAY_1_2_014MS = 7u,    // 0.014 ms
    PMICCDD_ESM_DELAY_1_2_016MS = 8u,    // 0.016 ms
    PMICCDD_ESM_DELAY_1_2_018MS = 9u,    // 0.018 ms
    PMICCDD_ESM_DELAY_1_2_019MS = 10u,   // 0.019 ms
    PMICCDD_ESM_DELAY_1_2_021MS = 11u,   // 0.021 ms
    PMICCDD_ESM_DELAY_1_2_023MS = 12u,   // 0.023 ms
    PMICCDD_ESM_DELAY_1_2_025MS = 13u,   // 0.025 ms
    PMICCDD_ESM_DELAY_1_2_027MS = 14u,   // 0.027 ms
    PMICCDD_ESM_DELAY_1_2_029MS = 15u,   // 0.029 ms
    PMICCDD_ESM_DELAY_1_2_031MS = 16u,   // 0.031 ms
    PMICCDD_ESM_DELAY_1_2_033MS = 17u,   // 0.033 ms
    PMICCDD_ESM_DELAY_1_2_035MS = 18u,   // 0.035 ms
    PMICCDD_ESM_DELAY_1_2_037MS = 19u,   // 0.037 ms
    PMICCDD_ESM_DELAY_1_2_039MS = 20u,   // 0.039 ms
    PMICCDD_ESM_DELAY_1_2_041MS = 21u,   // 0.041 ms
    PMICCDD_ESM_DELAY_1_2_043MS = 22u,   // 0.043 ms
    PMICCDD_ESM_DELAY_1_2_045MS = 23u,   // 0.045 ms
    PMICCDD_ESM_DELAY_1_2_047MS = 24u,   // 0.047 ms
    PMICCDD_ESM_DELAY_1_2_049MS = 25u,   // 0.049 ms
    PMICCDD_ESM_DELAY_1_2_051MS = 26u,   // 0.051 ms
    PMICCDD_ESM_DELAY_1_2_053MS = 27u,   // 0.053 ms
    PMICCDD_ESM_DELAY_1_2_054MS = 28u,   // 0.054 ms
    PMICCDD_ESM_DELAY_1_2_056MS = 29u,   // 0.056 ms
    PMICCDD_ESM_DELAY_1_2_058MS = 30u,   // 0.058 ms
    PMICCDD_ESM_DELAY_1_2_060MS = 31u,   // 0.060 ms
    PMICCDD_ESM_DELAY_1_2_062MS = 32u,   // 0.062 ms
    PMICCDD_ESM_DELAY_1_2_064MS = 33u,   // 0.064 ms
    PMICCDD_ESM_DELAY_1_2_066MS = 34u,   // 0.066 ms
    PMICCDD_ESM_DELAY_1_2_068MS = 35u,   // 0.068 ms
    PMICCDD_ESM_DELAY_1_2_070MS = 36u,   // 0.070 ms
    PMICCDD_ESM_DELAY_1_2_072MS = 37u,   // 0.072 ms
    PMICCDD_ESM_DELAY_1_2_074MS = 38u,   // 0.074 ms
    PMICCDD_ESM_DELAY_1_2_076MS = 39u,   // 0.076 ms
    PMICCDD_ESM_DELAY_1_2_078MS = 40u,   // 0.078 ms
    PMICCDD_ESM_DELAY_1_2_080MS = 41u,   // 0.080 ms
    PMICCDD_ESM_DELAY_1_2_082MS = 42u,   // 0.082 ms
    PMICCDD_ESM_DELAY_1_2_084MS = 43u,   // 0.084 ms
    PMICCDD_ESM_DELAY_1_2_086MS = 44u,   // 0.086 ms
    PMICCDD_ESM_DELAY_1_2_088MS = 45u,   // 0.088 ms
    PMICCDD_ESM_DELAY_1_2_089MS = 46u,   // 0.089 ms
    PMICCDD_ESM_DELAY_1_2_091MS = 47u,   // 0.091 ms
    PMICCDD_ESM_DELAY_1_2_093MS = 48u,   // 0.093 ms
    PMICCDD_ESM_DELAY_1_2_095MS = 49u,   // 0.095 ms
    PMICCDD_ESM_DELAY_1_2_097MS = 50u,   // 0.097 ms
    PMICCDD_ESM_DELAY_1_2_099MS = 51u,   // 0.099 ms
    PMICCDD_ESM_DELAY_1_2_101MS = 52u,   // 0.101 ms
    PMICCDD_ESM_DELAY_1_2_103MS = 53u,   // 0.103 ms
    PMICCDD_ESM_DELAY_1_2_105MS = 54u,   // 0.105 ms
    PMICCDD_ESM_DELAY_1_2_107MS = 55u,   // 0.107 ms
    PMICCDD_ESM_DELAY_1_2_109MS = 56u,   // 0.109 ms
    PMICCDD_ESM_DELAY_1_2_111MS = 57u,   // 0.111 ms
    PMICCDD_ESM_DELAY_1_2_113MS = 58u,   // 0.113 ms
    PMICCDD_ESM_DELAY_1_2_115MS = 59u,   // 0.115 ms
    PMICCDD_ESM_DELAY_1_2_117MS = 60u,   // 0.117 ms
    PMICCDD_ESM_DELAY_1_2_119MS = 61u,   // 0.119 ms
    PMICCDD_ESM_DELAY_1_2_121MS = 62u,   // 0.121 ms
    PMICCDD_ESM_DELAY_1_2_123MS = 63u,   // 0.123 ms
    PMICCDD_ESM_DELAY_1_2_125MS = 64u,   // 0.125 ms
    PMICCDD_ESM_DELAY_1_2_126MS = 65u,   // 0.126 ms
    PMICCDD_ESM_DELAY_1_2_128MS = 66u,   // 0.128 ms
    PMICCDD_ESM_DELAY_1_2_130MS = 67u,   // 0.130 ms
    PMICCDD_ESM_DELAY_1_2_132MS = 68u,   // 0.132 ms
    PMICCDD_ESM_DELAY_1_2_134MS = 69u,   // 0.134 ms
    PMICCDD_ESM_DELAY_1_2_136MS = 70u,   // 0.136 ms
    PMICCDD_ESM_DELAY_1_2_138MS = 71u,   // 0.138 ms
    PMICCDD_ESM_DELAY_1_2_140MS = 72u,   // 0.140 ms
    PMICCDD_ESM_DELAY_1_2_142MS = 73u,   // 0.142 ms
    PMICCDD_ESM_DELAY_1_2_144MS = 74u,   // 0.144 ms
    PMICCDD_ESM_DELAY_1_2_146MS = 75u,   // 0.146 ms
    PMICCDD_ESM_DELAY_1_2_148MS = 76u,   // 0.148 ms
    PMICCDD_ESM_DELAY_1_2_150MS = 77u,   // 0.150 ms
    PMICCDD_ESM_DELAY_1_2_152MS = 78u,   // 0.152 ms
    PMICCDD_ESM_DELAY_1_2_154MS = 79u,   // 0.154 ms
    PMICCDD_ESM_DELAY_1_2_156MS = 80u,   // 0.156 ms
    PMICCDD_ESM_DELAY_1_2_158MS = 81u,   // 0.158 ms
    PMICCDD_ESM_DELAY_1_2_160MS = 82u,   // 0.160 ms
    PMICCDD_ESM_DELAY_1_2_161MS = 83u,   // 0.161 ms
    PMICCDD_ESM_DELAY_1_2_163MS = 84u,   // 0.163 ms
    PMICCDD_ESM_DELAY_1_2_165MS = 85u,   // 0.165 ms
    PMICCDD_ESM_DELAY_1_2_167MS = 86u,   // 0.167 ms
    PMICCDD_ESM_DELAY_1_2_169MS = 87u,   // 0.169 ms
    PMICCDD_ESM_DELAY_1_2_171MS = 88u,   // 0.171 ms
    PMICCDD_ESM_DELAY_1_2_173MS = 89u,   // 0.173 ms
    PMICCDD_ESM_DELAY_1_2_175MS = 90u,   // 0.175 ms
    PMICCDD_ESM_DELAY_1_2_177MS = 91u,   // 0.177 ms
    PMICCDD_ESM_DELAY_1_2_179MS = 92u,   // 0.179 ms
    PMICCDD_ESM_DELAY_1_2_181MS = 93u,   // 0.181 ms
    PMICCDD_ESM_DELAY_1_2_183MS = 94u,   // 0.183 ms
    PMICCDD_ESM_DELAY_1_2_185MS = 95u,   // 0.185 ms
    PMICCDD_ESM_DELAY_1_2_187MS = 96u,   // 0.187 ms
    PMICCDD_ESM_DELAY_1_2_189MS = 97u,   // 0.189 ms
    PMICCDD_ESM_DELAY_1_2_191MS = 98u,   // 0.191 ms
    PMICCDD_ESM_DELAY_1_2_193MS = 99u,   // 0.193 ms
    PMICCDD_ESM_DELAY_1_2_195MS = 100u,  // 0.195 ms
    PMICCDD_ESM_DELAY_1_2_197MS = 101u,  // 0.197 ms
    PMICCDD_ESM_DELAY_1_2_198MS = 102u,  // 0.198 ms
    PMICCDD_ESM_DELAY_1_2_200MS = 103u,  // 0.200 ms
    PMICCDD_ESM_DELAY_1_2_202MS = 104u,  // 0.202 ms
    PMICCDD_ESM_DELAY_1_2_204MS = 105u,  // 0.204 ms
    PMICCDD_ESM_DELAY_1_2_206MS = 106u,  // 0.206 ms
    PMICCDD_ESM_DELAY_1_2_208MS = 107u,  // 0.208 ms
    PMICCDD_ESM_DELAY_1_2_210MS = 108u,  // 0.210 ms
    PMICCDD_ESM_DELAY_1_2_212MS = 109u,  // 0.212 ms
    PMICCDD_ESM_DELAY_1_2_214MS = 110u,  // 0.214 ms
    PMICCDD_ESM_DELAY_1_2_216MS = 111u,  // 0.216 ms
    PMICCDD_ESM_DELAY_1_2_218MS = 112u,  // 0.218 ms
    PMICCDD_ESM_DELAY_1_2_220MS = 113u,  // 0.220 ms
    PMICCDD_ESM_DELAY_1_2_222MS = 114u,  // 0.222 ms
    PMICCDD_ESM_DELAY_1_2_224MS = 115u,  // 0.224 ms
    PMICCDD_ESM_DELAY_1_2_226MS = 116u,  // 0.226 ms
    PMICCDD_ESM_DELAY_1_2_228MS = 117u,  // 0.228 ms
    PMICCDD_ESM_DELAY_1_2_230MS = 118u,  // 0.230 ms
    PMICCDD_ESM_DELAY_1_2_232MS = 119u,  // 0.232 ms
    PMICCDD_ESM_DELAY_1_2_233MS = 120u,  // 0.233 ms
    PMICCDD_ESM_DELAY_1_2_235MS = 121u,  // 0.235 ms
    PMICCDD_ESM_DELAY_1_2_237MS = 122u,  // 0.237 ms
    PMICCDD_ESM_DELAY_1_2_239MS = 123u,  // 0.239 ms
    PMICCDD_ESM_DELAY_1_2_241MS = 124u,  // 0.241 ms
    PMICCDD_ESM_DELAY_1_2_243MS = 125u,  // 0.243 ms
    PMICCDD_ESM_DELAY_1_2_245MS = 126u,  // 0.245 ms
    PMICCDD_ESM_DELAY_1_2_247MS = 127u,  // 0.247 ms
    PMICCDD_ESM_DELAY_1_2_249MS = 128u,  // 0.249 ms
    PMICCDD_ESM_DELAY_1_2_251MS = 129u,  // 0.251 ms
    PMICCDD_ESM_DELAY_1_2_253MS = 130u,  // 0.253 ms
    PMICCDD_ESM_DELAY_1_2_255MS = 131u,  // 0.255 ms
    PMICCDD_ESM_DELAY_1_2_257MS = 132u,  // 0.257 ms
    PMICCDD_ESM_DELAY_1_2_259MS = 133u,  // 0.259 ms
    PMICCDD_ESM_DELAY_1_2_261MS = 134u,  // 0.261 ms
    PMICCDD_ESM_DELAY_1_2_263MS = 135u,  // 0.263 ms
    PMICCDD_ESM_DELAY_1_2_265MS = 136u,  // 0.265 ms
    PMICCDD_ESM_DELAY_1_2_267MS = 137u,  // 0.267 ms
    PMICCDD_ESM_DELAY_1_2_268MS = 138u,  // 0.268 ms
    PMICCDD_ESM_DELAY_1_2_270MS = 139u,  // 0.270 ms
    PMICCDD_ESM_DELAY_1_2_272MS = 140u,  // 0.272 ms
    PMICCDD_ESM_DELAY_1_2_274MS = 141u,  // 0.274 ms
    PMICCDD_ESM_DELAY_1_2_276MS = 142u,  // 0.276 ms
    PMICCDD_ESM_DELAY_1_2_278MS = 143u,  // 0.278 ms
    PMICCDD_ESM_DELAY_1_2_280MS = 144u,  // 0.280 ms
    PMICCDD_ESM_DELAY_1_2_282MS = 145u,  // 0.282 ms
    PMICCDD_ESM_DELAY_1_2_284MS = 146u,  // 0.284 ms
    PMICCDD_ESM_DELAY_1_2_286MS = 147u,  // 0.286 ms
    PMICCDD_ESM_DELAY_1_2_288MS = 148u,  // 0.288 ms
    PMICCDD_ESM_DELAY_1_2_290MS = 149u,  // 0.290 ms
    PMICCDD_ESM_DELAY_1_2_292MS = 150u,  // 0.292 ms
    PMICCDD_ESM_DELAY_1_2_294MS = 151u,  // 0.294 ms
    PMICCDD_ESM_DELAY_1_2_296MS = 152u,  // 0.296 ms
    PMICCDD_ESM_DELAY_1_2_298MS = 153u,  // 0.298 ms
    PMICCDD_ESM_DELAY_1_2_300MS = 154u,  // 0.300 ms
    PMICCDD_ESM_DELAY_1_2_302MS = 155u,  // 0.302 ms
    PMICCDD_ESM_DELAY_1_2_304MS = 156u,  // 0.304 ms
    PMICCDD_ESM_DELAY_1_2_305MS = 157u,  // 0.305 ms
    PMICCDD_ESM_DELAY_1_2_307MS = 158u,  // 0.307 ms
    PMICCDD_ESM_DELAY_1_2_309MS = 159u,  // 0.309 ms
    PMICCDD_ESM_DELAY_1_2_311MS = 160u,  // 0.311 ms
    PMICCDD_ESM_DELAY_1_2_313MS = 161u,  // 0.313 ms
    PMICCDD_ESM_DELAY_1_2_315MS = 162u,  // 0.315 ms
    PMICCDD_ESM_DELAY_1_2_317MS = 163u,  // 0.317 ms
    PMICCDD_ESM_DELAY_1_2_319MS = 164u,  // 0.319 ms
    PMICCDD_ESM_DELAY_1_2_321MS = 165u,  // 0.321 ms
    PMICCDD_ESM_DELAY_1_2_323MS = 166u,  // 0.323 ms
    PMICCDD_ESM_DELAY_1_2_325MS = 167u,  // 0.325 ms
    PMICCDD_ESM_DELAY_1_2_327MS = 168u,  // 0.327 ms
    PMICCDD_ESM_DELAY_1_2_329MS = 169u,  // 0.329 ms
    PMICCDD_ESM_DELAY_1_2_331MS = 170u,  // 0.331 ms
    PMICCDD_ESM_DELAY_1_2_333MS = 171u,  // 0.333 ms
    PMICCDD_ESM_DELAY_1_2_335MS = 172u,  // 0.335 ms
    PMICCDD_ESM_DELAY_1_2_337MS = 173u,  // 0.337 ms
    PMICCDD_ESM_DELAY_1_2_338MS = 174u,  // 0.338 ms
    PMICCDD_ESM_DELAY_1_2_340MS = 175u,  // 0.340 ms
    PMICCDD_ESM_DELAY_1_2_342MS = 176u,  // 0.342 ms
    PMICCDD_ESM_DELAY_1_2_344MS = 177u,  // 0.344 ms
    PMICCDD_ESM_DELAY_1_2_346MS = 178u,  // 0.346 ms
    PMICCDD_ESM_DELAY_1_2_348MS = 179u,  // 0.348 ms
    PMICCDD_ESM_DELAY_1_2_350MS = 180u,  // 0.350 ms
    PMICCDD_ESM_DELAY_1_2_352MS = 181u,  // 0.352 ms
    PMICCDD_ESM_DELAY_1_2_354MS = 182u,  // 0.354 ms
    PMICCDD_ESM_DELAY_1_2_356MS = 183u,  // 0.356 ms
    PMICCDD_ESM_DELAY_1_2_358MS = 184u,  // 0.358 ms
    PMICCDD_ESM_DELAY_1_2_360MS = 185u,  // 0.360 ms
    PMICCDD_ESM_DELAY_1_2_362MS = 186u,  // 0.362 ms
    PMICCDD_ESM_DELAY_1_2_364MS = 187u,  // 0.364 ms
    PMICCDD_ESM_DELAY_1_2_366MS = 188u,  // 0.366 ms
    PMICCDD_ESM_DELAY_1_2_368MS = 189u,  // 0.368 ms
    PMICCDD_ESM_DELAY_1_2_370MS = 190u,  // 0.370 ms
    PMICCDD_ESM_DELAY_1_2_372MS = 191u,  // 0.372 ms
    PMICCDD_ESM_DELAY_1_2_374MS = 192u,  // 0.374 ms
    PMICCDD_ESM_DELAY_1_2_376MS = 193u,  // 0.376 ms
    PMICCDD_ESM_DELAY_1_2_378MS = 194u,  // 0.378 ms
    PMICCDD_ESM_DELAY_1_2_380MS = 195u,  // 0.380 ms
    PMICCDD_ESM_DELAY_1_2_382MS = 196u,  // 0.382 ms
    PMICCDD_ESM_DELAY_1_2_384MS = 197u,  // 0.384 ms
    PMICCDD_ESM_DELAY_1_2_386MS = 198u,  // 0.386 ms
    PMICCDD_ESM_DELAY_1_2_387MS = 199u,  // 0.387 ms
    PMICCDD_ESM_DELAY_1_2_389MS = 200u,  // 0.389 ms
    PMICCDD_ESM_DELAY_1_2_391MS = 201u,  // 0.391 ms
    PMICCDD_ESM_DELAY_1_2_393MS = 202u,  // 0.393 ms
    PMICCDD_ESM_DELAY_1_2_395MS = 203u,  // 0.395 ms
    PMICCDD_ESM_DELAY_1_2_397MS = 204u,  // 0.397 ms
    PMICCDD_ESM_DELAY_1_2_399MS = 205u,  // 0.399 ms
    PMICCDD_ESM_DELAY_1_2_401MS = 206u,  // 0.401 ms
    PMICCDD_ESM_DELAY_1_2_403MS = 207u,  // 0.403 ms
    PMICCDD_ESM_DELAY_1_2_405MS = 208u,  // 0.405 ms
    PMICCDD_ESM_DELAY_1_2_407MS = 209u,  // 0.407 ms
    PMICCDD_ESM_DELAY_1_2_409MS = 210u,  // 0.409 ms
    PMICCDD_ESM_DELAY_1_2_411MS = 211u,  // 0.411 ms
    PMICCDD_ESM_DELAY_1_2_413MS = 212u,  // 0.413 ms
    PMICCDD_ESM_DELAY_1_2_415MS = 213u,  // 0.415 ms
    PMICCDD_ESM_DELAY_1_2_417MS = 214u,  // 0.417 ms
    PMICCDD_ESM_DELAY_1_2_419MS = 215u,  // 0.419 ms
    PMICCDD_ESM_DELAY_1_2_421MS = 216u,  // 0.421 ms
    PMICCDD_ESM_DELAY_1_2_423MS = 217u,  // 0.423 ms
    PMICCDD_ESM_DELAY_1_2_425MS = 218u,  // 0.425 ms
    PMICCDD_ESM_DELAY_1_2_426MS = 219u,  // 0.426 ms
    PMICCDD_ESM_DELAY_1_2_428MS = 220u,  // 0.428 ms
    PMICCDD_ESM_DELAY_1_2_430MS = 221u,  // 0.430 ms
    PMICCDD_ESM_DELAY_1_2_432MS = 222u,  // 0.432 ms
    PMICCDD_ESM_DELAY_1_2_434MS = 223u,  // 0.434 ms
    PMICCDD_ESM_DELAY_1_2_436MS = 224u,  // 0.436 ms
    PMICCDD_ESM_DELAY_1_2_438MS = 225u,  // 0.438 ms
    PMICCDD_ESM_DELAY_1_2_440MS = 226u,  // 0.440 ms
    PMICCDD_ESM_DELAY_1_2_442MS = 227u,  // 0.442 ms
    PMICCDD_ESM_DELAY_1_2_444MS = 228u,  // 0.444 ms
    PMICCDD_ESM_DELAY_1_2_446MS = 229u,  // 0.446 ms
    PMICCDD_ESM_DELAY_1_2_447MS = 230u,  // 0.447 ms
    PMICCDD_ESM_DELAY_1_2_449MS = 231u,  // 0.449 ms
    PMICCDD_ESM_DELAY_1_2_451MS = 232u,  // 0.451 ms
    PMICCDD_ESM_DELAY_1_2_453MS = 233u,  // 0.453 ms
    PMICCDD_ESM_DELAY_1_2_455MS = 234u,  // 0.455 ms
    PMICCDD_ESM_DELAY_1_2_457MS = 235u,  // 0.457 ms
    PMICCDD_ESM_DELAY_1_2_459MS = 236u,  // 0.459 ms
    PMICCDD_ESM_DELAY_1_2_461MS = 237u,  // 0.461 ms
    PMICCDD_ESM_DELAY_1_2_463MS = 238u,  // 0.463 ms
    PMICCDD_ESM_DELAY_1_2_465MS = 239u,  // 0.465 ms
    PMICCDD_ESM_DELAY_1_2_467MS = 240u,  // 0.467 ms
    PMICCDD_ESM_DELAY_1_2_469MS = 241u,  // 0.469 ms
    PMICCDD_ESM_DELAY_1_2_471MS = 242u,  // 0.471 ms
    PMICCDD_ESM_DELAY_1_2_473MS = 243u,  // 0.473 ms
    PMICCDD_ESM_DELAY_1_2_475MS = 244u,  // 0.475 ms
    PMICCDD_ESM_DELAY_1_2_477MS = 245u,  // 0.477 ms
    PMICCDD_ESM_DELAY_1_2_479MS = 246u,  // 0.479 ms
    PMICCDD_ESM_DELAY_1_2_481MS = 247u,  // 0.481 ms
    PMICCDD_ESM_DELAY_1_2_483MS = 248u,  // 0.483 ms
    PMICCDD_ESM_DELAY_1_2_484MS = 249u,  // 0.484 ms
    PMICCDD_ESM_DELAY_1_2_486MS = 250u,  // 0.486 ms
    PMICCDD_ESM_DELAY_1_2_488MS = 251u,  // 0.488 ms
    PMICCDD_ESM_DELAY_1_2_490MS = 252u,  // 0.490 ms
    PMICCDD_ESM_DELAY_1_2_492MS = 253u,  // 0.492 ms
    PMICCDD_ESM_DELAY_1_2_494MS = 254u,  // 0.494 ms
    PMICCDD_ESM_DELAY_1_2_496MS = 255u,  // 0.496 ms
}ePmicCdd_Esm_Delay_1_2_TimeType;

typedef enum {
        PMICCDD_ESM_H_L_MAX_MIN_0014US = 0u,  	  //  0.000014
    PMICCDD_ESM_H_L_MAX_MIN_0029US = 1u,  	  //  0.000029
    PMICCDD_ESM_H_L_MAX_MIN_0043US = 2u,  	  //  0.000043
    PMICCDD_ESM_H_L_MAX_MIN_0057US = 3u,  	  //  0.000057
    PMICCDD_ESM_H_L_MAX_MIN_0071US = 4u,  	  //  0.000071
    PMICCDD_ESM_H_L_MAX_MIN_0086US = 5u,  	  //  0.000086
    PMICCDD_ESM_H_L_MAX_MIN_0100US = 6u,  	  //  0.000100
    PMICCDD_ESM_H_L_MAX_MIN_0114US = 7u,  	  //  0.000114
    PMICCDD_ESM_H_L_MAX_MIN_0128US = 8u,  	  //  0.000128
    PMICCDD_ESM_H_L_MAX_MIN_0143US = 9u,  	  //  0.000143
    PMICCDD_ESM_H_L_MAX_MIN_0157US = 10u, 	  //  0.000157
    PMICCDD_ESM_H_L_MAX_MIN_0171US = 11u, 	  //  0.000171
    PMICCDD_ESM_H_L_MAX_MIN_0185US = 12u, 	  //  0.000185
    PMICCDD_ESM_H_L_MAX_MIN_0200US = 13u, 	  //  0.000200
    PMICCDD_ESM_H_L_MAX_MIN_0214US = 14u, 	  //  0.000214
    PMICCDD_ESM_H_L_MAX_MIN_0228US = 15u, 	  //  0.000228
    PMICCDD_ESM_H_L_MAX_MIN_0242US = 16u, 	  //  0.000242
    PMICCDD_ESM_H_L_MAX_MIN_0257US = 17u, 	  //  0.000257
    PMICCDD_ESM_H_L_MAX_MIN_0271US = 18u, 	  //  0.000271
    PMICCDD_ESM_H_L_MAX_MIN_0285US = 19u, 	  //  0.000285
    PMICCDD_ESM_H_L_MAX_MIN_0299US = 20u, 	  //  0.000299
    PMICCDD_ESM_H_L_MAX_MIN_0314US = 21u, 	  //  0.000314
    PMICCDD_ESM_H_L_MAX_MIN_0328US = 22u, 	  //  0.000328
    PMICCDD_ESM_H_L_MAX_MIN_0342US = 23u, 	  //  0.000342
    PMICCDD_ESM_H_L_MAX_MIN_0356US = 24u, 	  //  0.000356
    PMICCDD_ESM_H_L_MAX_MIN_0371US = 25u, 	  //  0.000371
    PMICCDD_ESM_H_L_MAX_MIN_0385US = 26u, 	  //  0.000385
    PMICCDD_ESM_H_L_MAX_MIN_0399US = 27u, 	  //  0.000399
    PMICCDD_ESM_H_L_MAX_MIN_0413US = 28u, 	  //  0.000413
    PMICCDD_ESM_H_L_MAX_MIN_0428US = 29u, 	  //  0.000428
    PMICCDD_ESM_H_L_MAX_MIN_0442US = 30u, 	  //  0.000442
    PMICCDD_ESM_H_L_MAX_MIN_0456US = 31u, 	  //  0.000456
    PMICCDD_ESM_H_L_MAX_MIN_0470US = 32u, 	  //  0.000470
    PMICCDD_ESM_H_L_MAX_MIN_0485US = 33u, 	  //  0.000485
    PMICCDD_ESM_H_L_MAX_MIN_0499US = 34u, 	  //  0.000499
    PMICCDD_ESM_H_L_MAX_MIN_0513US = 35u, 	  //  0.000513
    PMICCDD_ESM_H_L_MAX_MIN_0527US = 36u, 	  //  0.000527
    PMICCDD_ESM_H_L_MAX_MIN_0542US = 37u, 	  //  0.000542
    PMICCDD_ESM_H_L_MAX_MIN_0556US = 38u, 	  //  0.000556
    PMICCDD_ESM_H_L_MAX_MIN_0570US = 39u, 	  //  0.000570
    PMICCDD_ESM_H_L_MAX_MIN_0584US = 40u, 	  //  0.000584
    PMICCDD_ESM_H_L_MAX_MIN_0599US = 41u, 	  //  0.000599
    PMICCDD_ESM_H_L_MAX_MIN_0613US = 42u, 	  //  0.000613
    PMICCDD_ESM_H_L_MAX_MIN_0627US = 43u, 	  //  0.000627
    PMICCDD_ESM_H_L_MAX_MIN_0641US = 44u, 	  //  0.000641
    PMICCDD_ESM_H_L_MAX_MIN_0656US = 45u, 	  //  0.000656
    PMICCDD_ESM_H_L_MAX_MIN_0670US = 46u, 	  //  0.000670
    PMICCDD_ESM_H_L_MAX_MIN_0684US = 47u, 	  //  0.000684
    PMICCDD_ESM_H_L_MAX_MIN_0698US = 48u, 	  //  0.000698
    PMICCDD_ESM_H_L_MAX_MIN_0713US = 49u, 	  //  0.000713
    PMICCDD_ESM_H_L_MAX_MIN_0727US = 50u, 	  //  0.000727
    PMICCDD_ESM_H_L_MAX_MIN_0741US = 51u, 	  //  0.000741
    PMICCDD_ESM_H_L_MAX_MIN_0755US = 52u, 	  //  0.000755
    PMICCDD_ESM_H_L_MAX_MIN_0770US = 53u, 	  //  0.000770
    PMICCDD_ESM_H_L_MAX_MIN_0784US = 54u, 	  //  0.000784
    PMICCDD_ESM_H_L_MAX_MIN_0798US = 55u, 	  //  0.000798
    PMICCDD_ESM_H_L_MAX_MIN_0812US = 56u, 	  //  0.000812
    PMICCDD_ESM_H_L_MAX_MIN_0827US = 57u, 	  //  0.000827
    PMICCDD_ESM_H_L_MAX_MIN_0841US = 58u, 	  //  0.000841
    PMICCDD_ESM_H_L_MAX_MIN_0855US = 59u, 	  //  0.000855
    PMICCDD_ESM_H_L_MAX_MIN_0869US = 60u, 	  //  0.000869
    PMICCDD_ESM_H_L_MAX_MIN_0884US = 61u, 	  //  0.000884
    PMICCDD_ESM_H_L_MAX_MIN_0898US = 62u, 	  //  0.000898
    PMICCDD_ESM_H_L_MAX_MIN_0912US = 63u, 	  //  0.000912
    PMICCDD_ESM_H_L_MAX_MIN_0926US = 64u, 	  //  0.000926
    PMICCDD_ESM_H_L_MAX_MIN_0941US = 65u, 	  //  0.000941
    PMICCDD_ESM_H_L_MAX_MIN_0955US = 66u, 	  //  0.000955
    PMICCDD_ESM_H_L_MAX_MIN_0969US = 67u, 	  //  0.000969
    PMICCDD_ESM_H_L_MAX_MIN_0983US = 68u, 	  //  0.000983
    PMICCDD_ESM_H_L_MAX_MIN_0998US = 69u, 	  //  0.000998
    PMICCDD_ESM_H_L_MAX_MIN_1012US = 70u, 	  //  0.001012
    PMICCDD_ESM_H_L_MAX_MIN_1026US = 71u, 	  //  0.001026
    PMICCDD_ESM_H_L_MAX_MIN_1040US = 72u, 	  //  0.001040
    PMICCDD_ESM_H_L_MAX_MIN_1055US = 73u, 	  //  0.001055
    PMICCDD_ESM_H_L_MAX_MIN_1069US = 74u, 	  //  0.001069
    PMICCDD_ESM_H_L_MAX_MIN_1083US = 75u, 	  //  0.001083
    PMICCDD_ESM_H_L_MAX_MIN_1097US = 76u, 	  //  0.001097
    PMICCDD_ESM_H_L_MAX_MIN_1112US = 77u, 	  //  0.001112
    PMICCDD_ESM_H_L_MAX_MIN_1126US = 78u, 	  //  0.001126
    PMICCDD_ESM_H_L_MAX_MIN_1140US = 79u, 	  //  0.001140
    PMICCDD_ESM_H_L_MAX_MIN_1154US = 80u, 	  //  0.001154
    PMICCDD_ESM_H_L_MAX_MIN_1169US = 81u, 	  //  0.001169
    PMICCDD_ESM_H_L_MAX_MIN_1183US = 82u, 	  //  0.001183
    PMICCDD_ESM_H_L_MAX_MIN_1197US = 83u, 	  //  0.001197
    PMICCDD_ESM_H_L_MAX_MIN_1211US = 84u, 	  //  0.001211
    PMICCDD_ESM_H_L_MAX_MIN_1226US = 85u, 	  //  0.001226
    PMICCDD_ESM_H_L_MAX_MIN_1240US = 86u, 	  //  0.001240
    PMICCDD_ESM_H_L_MAX_MIN_1254US = 87u, 	  //  0.001254
    PMICCDD_ESM_H_L_MAX_MIN_1268US = 88u, 	  //  0.001268
    PMICCDD_ESM_H_L_MAX_MIN_1283US = 89u, 	  //  0.001283
    PMICCDD_ESM_H_L_MAX_MIN_1297US = 90u, 	  //  0.001297
    PMICCDD_ESM_H_L_MAX_MIN_1311US = 91u, 	  //  0.001311
    PMICCDD_ESM_H_L_MAX_MIN_1325US = 92u, 	  //  0.001325
    PMICCDD_ESM_H_L_MAX_MIN_1340US = 93u, 	  //  0.001340
    PMICCDD_ESM_H_L_MAX_MIN_1354US = 94u, 	  //  0.001354
    PMICCDD_ESM_H_L_MAX_MIN_1368US = 95u, 	  //  0.001368
    PMICCDD_ESM_H_L_MAX_MIN_1382US = 96u, 	  //  0.001382
    PMICCDD_ESM_H_L_MAX_MIN_1397US = 97u, 	  //  0.001397
    PMICCDD_ESM_H_L_MAX_MIN_1411US = 98u, 	  //  0.001411
    PMICCDD_ESM_H_L_MAX_MIN_1425US = 99u, 	  //  0.001425
    PMICCDD_ESM_H_L_MAX_MIN_1439US = 100u,	  //  0.001439
    PMICCDD_ESM_H_L_MAX_MIN_1454US = 101u,	  //  0.001454
    PMICCDD_ESM_H_L_MAX_MIN_1468US = 102u,	  //  0.001468
    PMICCDD_ESM_H_L_MAX_MIN_1482US = 103u,	  //  0.001482
    PMICCDD_ESM_H_L_MAX_MIN_1496US = 104u,	  //  0.001496
    PMICCDD_ESM_H_L_MAX_MIN_1511US = 105u,	  //  0.001511
    PMICCDD_ESM_H_L_MAX_MIN_1525US = 106u,	  //  0.001525
    PMICCDD_ESM_H_L_MAX_MIN_1539US = 107u,	  //  0.001539
    PMICCDD_ESM_H_L_MAX_MIN_1553US = 108u,	  //  0.001553
    PMICCDD_ESM_H_L_MAX_MIN_1568US = 109u,	  //  0.001568
    PMICCDD_ESM_H_L_MAX_MIN_1582US = 110u,	  //  0.001582
    PMICCDD_ESM_H_L_MAX_MIN_1596US = 111u,	  //  0.001596
    PMICCDD_ESM_H_L_MAX_MIN_1610US = 112u,	  //  0.001610
    PMICCDD_ESM_H_L_MAX_MIN_1625US = 113u,	  //  0.001625
    PMICCDD_ESM_H_L_MAX_MIN_1639US = 114u,	  //  0.001639
    PMICCDD_ESM_H_L_MAX_MIN_1653US = 115u,	  //  0.001653
    PMICCDD_ESM_H_L_MAX_MIN_1667US = 116u,	  //  0.001667
    PMICCDD_ESM_H_L_MAX_MIN_1682US = 117u,	  //  0.001682
    PMICCDD_ESM_H_L_MAX_MIN_1696US = 118u,	  //  0.001696
    PMICCDD_ESM_H_L_MAX_MIN_1710US = 119u,	  //  0.001710
    PMICCDD_ESM_H_L_MAX_MIN_1724US = 120u,	  //  0.001724
    PMICCDD_ESM_H_L_MAX_MIN_1739US = 121u,	  //  0.001739
    PMICCDD_ESM_H_L_MAX_MIN_1753US = 122u,	  //  0.001753
    PMICCDD_ESM_H_L_MAX_MIN_1767US = 123u,	  //  0.001767
    PMICCDD_ESM_H_L_MAX_MIN_1781US = 124u,	  //  0.001781
    PMICCDD_ESM_H_L_MAX_MIN_1796US = 125u,	  //  0.001796
    PMICCDD_ESM_H_L_MAX_MIN_1810US = 126u,	  //  0.001810
    PMICCDD_ESM_H_L_MAX_MIN_1824US = 127u,	  //  0.001824
    PMICCDD_ESM_H_L_MAX_MIN_1838US = 128u,	  //  0.001838
    PMICCDD_ESM_H_L_MAX_MIN_1853US = 129u,	  //  0.001853
    PMICCDD_ESM_H_L_MAX_MIN_1867US = 130u,	  //  0.001867
    PMICCDD_ESM_H_L_MAX_MIN_1881US = 131u,	  //  0.001881
    PMICCDD_ESM_H_L_MAX_MIN_1895US = 132u,	  //  0.001895
    PMICCDD_ESM_H_L_MAX_MIN_1910US = 133u,	  //  0.001910
    PMICCDD_ESM_H_L_MAX_MIN_1924US = 134u,	  //  0.001924
    PMICCDD_ESM_H_L_MAX_MIN_1938US = 135u,	  //  0.001938
    PMICCDD_ESM_H_L_MAX_MIN_1952US = 136u,	  //  0.001952
    PMICCDD_ESM_H_L_MAX_MIN_1967US = 137u,	  //  0.001967
    PMICCDD_ESM_H_L_MAX_MIN_1981US = 138u,	  //  0.001981
    PMICCDD_ESM_H_L_MAX_MIN_1995US = 139u,	  //  0.001995
    PMICCDD_ESM_H_L_MAX_MIN_2009US = 140u,	  //  0.002009
    PMICCDD_ESM_H_L_MAX_MIN_2024US = 141u,	  //  0.002024
    PMICCDD_ESM_H_L_MAX_MIN_2038US = 142u,	  //  0.002038
    PMICCDD_ESM_H_L_MAX_MIN_2052US = 143u,	  //  0.002052
    PMICCDD_ESM_H_L_MAX_MIN_2066US = 144u,	  //  0.002066
    PMICCDD_ESM_H_L_MAX_MIN_2081US = 145u,	  //  0.002081
    PMICCDD_ESM_H_L_MAX_MIN_2095US = 146u,	  //  0.002095
    PMICCDD_ESM_H_L_MAX_MIN_2109US = 147u,	  //  0.002109
    PMICCDD_ESM_H_L_MAX_MIN_2123US = 148u,	  //  0.002123
    PMICCDD_ESM_H_L_MAX_MIN_2138US = 149u,	  //  0.002138
    PMICCDD_ESM_H_L_MAX_MIN_2152US = 150u,	  //  0.002152
    PMICCDD_ESM_H_L_MAX_MIN_2166US = 151u,	  //  0.002166
    PMICCDD_ESM_H_L_MAX_MIN_2180US = 152u,	  //  0.002180
    PMICCDD_ESM_H_L_MAX_MIN_2195US = 153u,	  //  0.002195
    PMICCDD_ESM_H_L_MAX_MIN_2209US = 154u,	  //  0.002209
    PMICCDD_ESM_H_L_MAX_MIN_2223US = 155u,	  //  0.002223
    PMICCDD_ESM_H_L_MAX_MIN_2237US = 156u,	  //  0.002237
    PMICCDD_ESM_H_L_MAX_MIN_2252US = 157u,	  //  0.002252
    PMICCDD_ESM_H_L_MAX_MIN_2266US = 158u,	  //  0.002266
    PMICCDD_ESM_H_L_MAX_MIN_2280US = 159u,	  //  0.002280
    PMICCDD_ESM_H_L_MAX_MIN_2294US = 160u,	  //  0.002294
    PMICCDD_ESM_H_L_MAX_MIN_2309US = 161u,	  //  0.002309
    PMICCDD_ESM_H_L_MAX_MIN_2323US = 162u,	  //  0.002323
    PMICCDD_ESM_H_L_MAX_MIN_2337US = 163u,	  //  0.002337
    PMICCDD_ESM_H_L_MAX_MIN_2351US = 164u,	  //  0.002351
    PMICCDD_ESM_H_L_MAX_MIN_2366US = 165u,	  //  0.002366
    PMICCDD_ESM_H_L_MAX_MIN_2380US = 166u,	  //  0.002380
    PMICCDD_ESM_H_L_MAX_MIN_2394US = 167u,	  //  0.002394
    PMICCDD_ESM_H_L_MAX_MIN_2408US = 168u,	  //  0.002408
    PMICCDD_ESM_H_L_MAX_MIN_2423US = 169u,	  //  0.002423
    PMICCDD_ESM_H_L_MAX_MIN_2437US = 170u,	  //  0.002437
    PMICCDD_ESM_H_L_MAX_MIN_2451US = 171u,	  //  0.002451
    PMICCDD_ESM_H_L_MAX_MIN_2465US = 172u,	  //  0.002465
    PMICCDD_ESM_H_L_MAX_MIN_2480US = 173u,	  //  0.002480
    PMICCDD_ESM_H_L_MAX_MIN_2494US = 174u,	  //  0.002494
    PMICCDD_ESM_H_L_MAX_MIN_2508US = 175u,	  //  0.002508
    PMICCDD_ESM_H_L_MAX_MIN_2522US = 176u,	  //  0.002522
    PMICCDD_ESM_H_L_MAX_MIN_2537US = 177u,	  //  0.002537
    PMICCDD_ESM_H_L_MAX_MIN_2551US = 178u,	  //  0.002551
    PMICCDD_ESM_H_L_MAX_MIN_2565US = 179u,	  //  0.002565
    PMICCDD_ESM_H_L_MAX_MIN_2579US = 180u,	  //  0.002579
    PMICCDD_ESM_H_L_MAX_MIN_2594US = 181u,	  //  0.002594
    PMICCDD_ESM_H_L_MAX_MIN_2608US = 182u,	  //  0.002608
    PMICCDD_ESM_H_L_MAX_MIN_2622US = 183u,	  //  0.002622
    PMICCDD_ESM_H_L_MAX_MIN_2636US = 184u,	  //  0.002636
    PMICCDD_ESM_H_L_MAX_MIN_2651US = 185u,	  //  0.002651
    PMICCDD_ESM_H_L_MAX_MIN_2665US = 186u,	  //  0.002665
    PMICCDD_ESM_H_L_MAX_MIN_2679US = 187u,	  //  0.002679
    PMICCDD_ESM_H_L_MAX_MIN_2693US = 188u,	  //  0.002693
    PMICCDD_ESM_H_L_MAX_MIN_2708US = 189u,	  //  0.002708
    PMICCDD_ESM_H_L_MAX_MIN_2722US = 190u,	  //  0.002722
    PMICCDD_ESM_H_L_MAX_MIN_2736US = 191u,	  //  0.002736
    PMICCDD_ESM_H_L_MAX_MIN_2750US = 192u,	  //  0.002750
    PMICCDD_ESM_H_L_MAX_MIN_2765US = 193u,	  //  0.002765
    PMICCDD_ESM_H_L_MAX_MIN_2779US = 194u,	  //  0.002779
    PMICCDD_ESM_H_L_MAX_MIN_2793US = 195u,	  //  0.002793
    PMICCDD_ESM_H_L_MAX_MIN_2807US = 196u,	  //  0.002807
    PMICCDD_ESM_H_L_MAX_MIN_2822US = 197u,	  //  0.002822
    PMICCDD_ESM_H_L_MAX_MIN_2836US = 198u,	  //  0.002836
    PMICCDD_ESM_H_L_MAX_MIN_2850US = 199u,	  //  0.002850
    PMICCDD_ESM_H_L_MAX_MIN_2864US = 200u,	  //  0.002864
    PMICCDD_ESM_H_L_MAX_MIN_2879US = 201u,	  //  0.002879
    PMICCDD_ESM_H_L_MAX_MIN_2893US = 202u,	  //  0.002893
    PMICCDD_ESM_H_L_MAX_MIN_2907US = 203u,	  //  0.002907
    PMICCDD_ESM_H_L_MAX_MIN_2921US = 204u,	  //  0.002921
    PMICCDD_ESM_H_L_MAX_MIN_2936US = 205u,	  //  0.002936
    PMICCDD_ESM_H_L_MAX_MIN_2950US = 206u,	  //  0.002950
    PMICCDD_ESM_H_L_MAX_MIN_2964US = 207u,	  //  0.002964
    PMICCDD_ESM_H_L_MAX_MIN_2978US = 208u,	  //  0.002978
    PMICCDD_ESM_H_L_MAX_MIN_2993US = 209u,	  //  0.002993
    PMICCDD_ESM_H_L_MAX_MIN_3007US = 210u,	  //  0.003007
    PMICCDD_ESM_H_L_MAX_MIN_3021US = 211u,	  //  0.003021
    PMICCDD_ESM_H_L_MAX_MIN_3035US = 212u,	  //  0.003035
    PMICCDD_ESM_H_L_MAX_MIN_3050US = 213u,	  //  0.003050
    PMICCDD_ESM_H_L_MAX_MIN_3064US = 214u,	  //  0.003064
    PMICCDD_ESM_H_L_MAX_MIN_3078US = 215u,	  //  0.003078
    PMICCDD_ESM_H_L_MAX_MIN_3092US = 216u,	  //  0.003092
    PMICCDD_ESM_H_L_MAX_MIN_3107US = 217u,	  //  0.003107
    PMICCDD_ESM_H_L_MAX_MIN_3121US = 218u,	  //  0.003121
    PMICCDD_ESM_H_L_MAX_MIN_3135US = 219u,	  //  0.003135
    PMICCDD_ESM_H_L_MAX_MIN_3149US = 220u,	  //  0.003149
    PMICCDD_ESM_H_L_MAX_MIN_3164US = 221u,	  //  0.003164
    PMICCDD_ESM_H_L_MAX_MIN_3178US = 222u,	  //  0.003178
    PMICCDD_ESM_H_L_MAX_MIN_3192US = 223u,	  //  0.003192
    PMICCDD_ESM_H_L_MAX_MIN_3206US = 224u,	  //  0.003206
    PMICCDD_ESM_H_L_MAX_MIN_3221US = 225u,	  //  0.003221
    PMICCDD_ESM_H_L_MAX_MIN_3235US = 226u,	  //  0.003235
    PMICCDD_ESM_H_L_MAX_MIN_3249US = 227u,	  //  0.003249
    PMICCDD_ESM_H_L_MAX_MIN_3263US = 228u,	  //  0.003263
    PMICCDD_ESM_H_L_MAX_MIN_3278US = 229u,	  //  0.003278
    PMICCDD_ESM_H_L_MAX_MIN_3292US = 230u,	  //  0.003292
    PMICCDD_ESM_H_L_MAX_MIN_3306US = 231u,	  //  0.003306
    PMICCDD_ESM_H_L_MAX_MIN_3320US = 232u,	  //  0.003320
    PMICCDD_ESM_H_L_MAX_MIN_3335US = 233u,	  //  0.003335
    PMICCDD_ESM_H_L_MAX_MIN_3349US = 234u,	  //  0.003349
    PMICCDD_ESM_H_L_MAX_MIN_3363US = 235u,	  //  0.003363
    PMICCDD_ESM_H_L_MAX_MIN_3377US = 236u,	  //  0.003377
    PMICCDD_ESM_H_L_MAX_MIN_3392US = 237u,	  //  0.003392
    PMICCDD_ESM_H_L_MAX_MIN_3406US = 238u,	  //  0.003406
    PMICCDD_ESM_H_L_MAX_MIN_3420US = 239u,	  //  0.003420
    PMICCDD_ESM_H_L_MAX_MIN_3434US = 240u,	  //  0.003434
    PMICCDD_ESM_H_L_MAX_MIN_3449US = 241u,	  //  0.003449
    PMICCDD_ESM_H_L_MAX_MIN_3463US = 242u,	  //  0.003463
    PMICCDD_ESM_H_L_MAX_MIN_3477US = 243u,	  //  0.003477
    PMICCDD_ESM_H_L_MAX_MIN_3491US = 244u,	  //  0.003491
    PMICCDD_ESM_H_L_MAX_MIN_3506US = 245u,	  //  0.003506
    PMICCDD_ESM_H_L_MAX_MIN_3520US = 246u,	  //  0.003520
    PMICCDD_ESM_H_L_MAX_MIN_3534US = 247u,	  //  0.003534
    PMICCDD_ESM_H_L_MAX_MIN_3548US = 248u,	  //  0.003548
    PMICCDD_ESM_H_L_MAX_MIN_3563US = 249u,	  //  0.003563
    PMICCDD_ESM_H_L_MAX_MIN_3577US = 250u,	  //  0.003577
    PMICCDD_ESM_H_L_MAX_MIN_3591US = 251u,	  //  0.003591
    PMICCDD_ESM_H_L_MAX_MIN_3605US = 252u,	  //  0.003605
    PMICCDD_ESM_H_L_MAX_MIN_3620US = 253u,	  //  0.003620
    PMICCDD_ESM_H_L_MAX_MIN_3634US = 254u,	  //  0.003634
    PMICCDD_ESM_H_L_MAX_MIN_3648US = 255u,	  //  0.003648
}ePmicCdd_Esm_H_L_Max_Min_TimeType;


/* Error Interrupts report bit fields*/
typedef enum {
    // BUCK UV/OV Interrupts
    PMIC_INT_BUCK1_UVOV = 0x01,
    PMIC_INT_BUCK2_UVOV = 0x02,
    PMIC_INT_BUCK3_UVOV = 0x04,
    PMIC_INT_BUCK4_UVOV = 0x08,

    // LDO and VMON UV/OV Interrupts
    PMIC_INT_LDO1_UVOV = 0x10,
    PMIC_INT_LDO2_UVOV = 0x20,
    PMIC_INT_LDO3_UVOV = 0x40,
    PMIC_INT_VCCA_UVOV = 0x80,
    PMIC_INT_VMON1_UVOV = 0x100,
    PMIC_INT_VMON2_UVOV = 0x200,

    // GPIO Interrupts
    PMIC_INT_GPIO1 = 0x400,
    PMIC_INT_GPIO2 = 0x800,
    PMIC_INT_GPIO3 = 0x1000,
    PMIC_INT_GPIO4 = 0x2000,
    PMIC_INT_GPIO5 = 0x4000,
    PMIC_INT_GPIO6 = 0x8000,

    // Startup Interrupts
    PMIC_INT_VSENSE = 0x10000,
    PMIC_INT_ENABLE = 0x20000,
    PMIC_INT_PB_SHORT = 0x40000,
    PMIC_INT_FSD = 0x80000,
    PMIC_INT_SOFT_REBOOT = 0x100000,

    // Miscellaneous Interrupts
    PMIC_INT_BIST_PASS = 0x200000,
    PMIC_INT_EXT_CLK = 0x400000,
    PMIC_INT_REG_UNLOCK = 0x800000,
    PMIC_INT_TWARN = 0x1000000,
    PMIC_INT_PB_LONG = 0x2000000,
    PMIC_INT_PB_FALL = 0x4000000,
    PMIC_INT_PB_RISE = 0x8000000,
    PMIC_INT_ADC_CONV_READY = 0x10000000,

    // Moderate Error Interrupts
    PMIC_INT_TSD_ORD = 0x20000000,
    PMIC_INT_BIST_FAIL = 0x40000000,
    PMIC_INT_REG_CRC_ERR = 0x80000000U,
    PMIC_INT_RECOV_CNT = 0x100000000,

    // Severe Error Interrupts
    PMIC_INT_TSD_IMM = 0x200000000,
    PMIC_INT_VCCA_OVP = 0x400000000,
    PMIC_INT_PFSM_ERR = 0x800000000,
    PMIC_INT_BG_XMON = 0x1000000000,

    // FSM Error Interrupts
    PMIC_INT_IMM_SHUTDOWN = 0x2000000000,
    PMIC_INT_ORD_SHUTDOWN = 0x4000000000,
    PMIC_INT_MCU_PWR_ERR = 0x8000000000,
    PMIC_INT_SOC_PWR_ERR = 0x10000000000,
    PMIC_INT_COMM_ERR = 0x20000000000,
    PMIC_INT_I2C2_ERR = 0x40000000000,
    PMIC_INT_ESM = 0x80000000000,
    PMIC_INT_WD = 0x100000000000,

    // ESM Interrupts
    PMIC_INT_ESM_MCU_PIN = 0x200000000000,
    PMIC_INT_ESM_MCU_FAIL = 0x400000000000,
    PMIC_INT_ESM_MCU_RST = 0x800000000000,

    //WD Error Status
    PMIC_INT_WD_LONGWIN_TIMEOUT = 0x1000000000000,
    PMIC_INT_WD_TIMEOUT = 0x2000000000000,
    PMIC_INT_WD_TRIG_EARLY = 0x4000000000000,
    PMIC_INT_WD_ANSW_EARLY = 0x8000000000000,
    PMIC_INT_WD_SEQ_ERR = 0x10000000000000,
    PMIC_INT_WD_ANSW_ERR = 0x20000000000000,
    PMIC_INT_WD_FAIL_INT = 0x40000000000000,
    PMIC_INT_WD_RST_INT = 0x80000000000000
} ePmicCdd_ErrIntType;


/* ESM supported Modes*/

typedef enum
{
    /* Level mode - Active level of the signal*/
    Level_Mode = 0,
    /* PWM Mode - Change in period / duty cycle*/
    PWM_Mode = 1,
} PmicCdd_EsmModeType;

/*PMIC Watchdog Supported modes*/
typedef enum
{
    /*Trigger mode - Pulse signal*/
    Pmic_TriggerMode = 0,
    /*Q & A mode - Question and Answer */
    Pmic_QnAMode = 1,
} PmicCdd_WdgModeType;

/*GPIO 1 pin functionality selection*/
typedef enum 
{
    /* General Purpose Input/Output (GPIO) signal*/
    Pmic_GPIO1_Gpio = 0,
    /* Serial interface data input and output for I2C2/SPI access*/
    Pmic_GPIO1_SDAI2c_SDOSpi= 1,
    /* Sleep request signal */
    Pmic_GPIO1_Nsleep2 = 2,
    /* Open-drain interrupt output */
    Pmic_GPIO1_Nint = 3,
}PmicCdd_GPIO1ConfigType;

/*GPIO 2 pin functionality selection*/
typedef enum 
{
    /* General Purpose Input/Output (GPIO) signal*/
    Pmic_GPIO2_Gpio = 0,
    /* Serial interface clock input for I2C access / Serial interface Chip Select for SPI access */
    Pmic_GPIO2_SCLI2c_CSSpi= 1,
    /* Sleep request signal */
    Pmic_GPIO2_Nsleep1 = 2,
    /* watchdog trigger input signal for Watchdog Trigger mode. */
    Pmic_GPIO2_TrigWdog = 3,
}PmicCdd_GPIO2ConfigType;

/*GPIO 3 pin functionality selection*/
typedef enum 
{
    /* General Purpose Input/Output (GPIO) signal*/
    Pmic_GPIO3_Gpio = 0,
    /* Refeence ground for VMNON1 */
    Pmic_GPIO3_VMON1_m= 1,
    /* Sleep request signal */   
    Pmic_GPIO3_Nsleep1 = 2,
    /* Push-Button monitor input */
    Pmic_GPIO3_PB = 3,
}PmicCdd_GPIO3ConfigType;

/*GPIO 4 pin functionality selection*/
typedef enum 
{
    /* General Purpose Input/Output (GPIO) signal*/
    Pmic_GPIO4_Gpio = 0,
    /* Reference ground for VMNON1 */
    Pmic_GPIO4_VMON2= 1,
    /* Sleep request signal */   
    Pmic_GPIO4_Nsleep1 = 2,
    /* Signal input pin for the 12-bit ADC. */
    Pmic_GPIO4_ADC_In = 3,
}PmicCdd_GPIO4ConfigType;

/*GPIO 5 pin functionality selection*/
typedef enum 
{
    /* General Purpose Input/Output (GPIO) signal*/
    Pmic_GPIO5_Gpio = 0,
    /* wake-up request signal */
    Pmic_GPIO5_WKUP= 1,
    /* external switching clock signal input */   
    Pmic_GPIO5_SYNCCLKIN = 2,
    /* Signal input pin for the 12-bit ADC. */
    Pmic_GPIO5_ADC_In = 3,
}PmicCdd_GPIO5ConfigType;

/*GPIO 6 pin functionality selection*/
typedef enum 
{
    /* General Purpose Input/Output (GPIO) signal*/
    Pmic_GPIO6_Gpio = 0,
    /* Sleep request signal */
    Pmic_GPIO6_Nsleep2= 1,
    /* System error input signal */   
    Pmic_GPIO6_nErr_MCU = 2,
    /* external switching clock signal input. */
    Pmic_GPIO6_SYNCCLKIN = 3,
    /* wake-up request signal */
    Pmic_GPIO6_WKUP = 4,
}PmicCdd_GPIO6ConfigType;

/*******************************GPIO Config Common - Start *************************/
/* GPIO direction selection */
typedef enum
{
    /* Gpio Pin as Input*/
    Pmic_GpioInput = 0,
    /* Gpio Pin as Output*/
    Pmic_GpioOutput = 1,
}PmicCdd_GpioDirType;

/* GPIO signal type for Output*/
typedef enum
{
    Pmic_PushPull = 0,
    Pmic_OpenDrain = 1,
}PmicCdd_GpioOutDriveType;

/* Selection of resistor for GPIO*/
typedef enum
{
    /* Pull-down resistor selected  */
    Pmic_PullDownRes = 0,
    /* Pull-Up resistor selected  */
    Pmic_PullUpRes = 1,
}PmicCdd_GpioPuOrPdResistorSelType;

/* Control for GPIO pin pull-up/pull-down resistor */
typedef enum
{
    /* Pull-up/pull-down resistor deactivated */
    Pmic_PullUpOrDown_Deactivated = 0,
    /* Pull-up/pull-down resistor activated */
    Pmic_PullUpOrDown_Activated = 1,
}PmicCdd_GpioPuOrPdActivateType;

typedef enum 
{
    /*No deglitch*/
    Pmic_NoDeglitch = 0U,
    /*Deglitch*/
    Pmic_Deglitch = 1U,
}PmicCdd_GpioDeglitchType;
/*******************************GPIO Config Common - End *************************/


/* GPIO Output/Input Level */
typedef enum 
{
    /* Output/Input Low*/
    PmicCdd_GpioLow = 0,
    PmicCdd_GpioHigh = 1,
}Pmic_GPIOLevelType;

/* ADC Resistor divider enabling*/
typedef enum 
{
    /* Divider deactivated*/
    Pmic_Dividerdeactive = 0,
    /* Divide by 6V*/
    Pmic_Divideractive = 1,
}PmicCdd_AdcDividerType;

/* ADC Conversion source select*/
typedef enum
{
    /* ADC Input - GPIO4 or GPIO5*/
    Pmci_ADCIn = 0,
    /* Thermal Senor*/
    Pmic_ThermalSensor = 1,
}PmicCdd_AdcConvSourceType;

/* ADC Continous or Single Converions*/
typedef enum
{
    /* Single conversion*/
    Pmic_AdcSingleConv = 0,
    /* Continous Conversion*/
    Pmic_AdcContionousConv = 1,
}PmicCdd_AdcConvType;


typedef enum
{
    PMICCDD_ADC_IDLE = 0,
    PMICCDD_ADC_BUSY,
    PMICCDD_ADC_COMPLETED,
    PMICCDD_ADC_STREAM_COMPLETED
}PmicCdd_Adc_StatusType;

/* nINT pin GPIO configuration to geneate interrupt */

typedef enum
{
    PMICCDD_GPIO_TRIG_TYPE_NONE = 0,
    PMICCDD_GPIO_TRIG_TYPE_RISE_EDGE,
    PMICCDD_GPIO_TRIG_TYPE_FALL_EDGE,
    PMICCDD_GPIO_TRIG_TYPE_BOTH_EDGE,
}PmicCdd_nINTGpio_TrigType;

typedef enum
{
    PmicCdd_PowerOn_Reset = 0,
    PmicCdd_PmicWdg_Reset,
    PmicCdd_Wakeup,
    PmicCdd_Buck1_UVOV_Reset,
    PmicCdd_Buck2_UVOV_Reset,
    PmicCdd_Buck3_UVOV_Reset,
    PmicCdd_Buck4_UVOV_Reset,
    PmicCdd_Ldo1_UVOV_Reset,
    PmicCdd_Ldo2_UVOV_Reset,
    PmicCdd_Ldo3_UVOV_Reset,
    PmicCdd_Vcca_UVOV_Reset,
    PmicCdd_Vmon1_UVOV_Reset,
    PmicCdd_Power_Supply_Fault_Reset, //bg_xmon_int, tsd_imm_int, tsd_ord_imm, reg_crc_err_int and twarn_int are categorized as Power Supply Fault Reset
    PmicCdd_Abist_Fail_Reset,
    PmicCdd_Mcu_Reset,
    PmicCdd_Vmon2_UVOV_Reset,
    PmicCdd_Reset_Reason_None,
    /* Reset-reason capture is not valid until the asynchronous PMIC initialization completes. */
    PmicCdd_Reset_Reason_Not_Ready,
} PmicCdd_ResetReasonType;


typedef enum
{
    PmicCdd_WdgReset_Reason_None = 0,
    PmicCdd_WdgLongWin_Timeout,
    PmicCdd_WdgTrigger_Early,
    PmicCdd_WdgTimeout,
    PmicCdd_Wdg_Cannot_be_Identified,
} PmicCdd_WdgResetReasonType;

/* Spread spectrum */

/* Spread spectrum modulation depth */
typedef enum {
    /* 4% modulation depth */
    PmicCdd_SpreadSpectrum_4 = 0,
    /* 7% modulation depth */
    PmicCdd_SpreadSpectrum_7,
} PmicCdd_SpreadSpectrum_ModulationDepType;

/* Spread spectrum Activation */
typedef enum {
    /* Spread spectrum deactivated */
    PmicCdd_SpreadSpectrum_Deactivated = 0,
    /* Spread spectrum activated */
    PmicCdd_SpreadSpectrum_Activated = 1,
} PmicCdd_SpreadSpectrumType;

/* Buck Ctrl - Enabling/Disabling the Bucks */
typedef enum {
    /* Buck Disabled */
    PmicCdd_BuckEn_Disabled = 0,
    /* Buck Enabled */
    PmicCdd_BuckEn_Enabled = 1,
} PmicCdd_BuckEnType;

/* Buck Ctrl - Enabling/Disabling Forced PWM mode in Buck */
typedef enum {
    /* Forced PWM mode Disabled */
    PmicCdd_BuckFpwmMode_Disabled = 0,
    /* Forced PWM mode Enabled */
    PmicCdd_BuckFpwmMode_Enabled = 1,
} PmicCdd_BuckFpwmEnType;

/* Buck Ctrl - Enabling/Diabling Volatge Moniroting */
typedef enum {
    /* Voltage Monitoring Disabled */
    PmicCdd_BuckVmon_Disabled = 0,
    /* Voltage Monitoring Enabled */
    PmicCdd_BuckVmon_Enabled = 1,
} PmicCdd_BuckVmonEnType;

/* Buck Ctrl - Enabling/Disabling of pull down resistor */
typedef enum {
    /* Pull-down deactivated*/
    PmicCdd_BuckPullDown_Deactivated = 0,
    /* Pull-down activated*/
    PmicCdd_BuckPullDown_Activated = 1,
} PmicCdd_BuckPullDownType;

/* Ldo Ctrl - Enabling/Disabling the LDOs */
typedef enum {
    /* LDO Disabled */
    PmicCdd_LdoEn_Disabled = 0,
    /* LDO Enabled */
    PmicCdd_LdoEn_Enabled = 1,
} PmicCdd_LdoEnType;

/* Ldo Ctrl - Enbaling/Disabling the Volatge Monitoring */
typedef enum {
    /* Voltage Monitoring Disabled */
    PmicCdd_LdoVmon_Disabled = 0,
    /* Voltage Monitoring Enabled */
    PmicCdd_LdoVmon_Enabled = 1,
} PmicCdd_LdoVmonEnType;

/* Ldo Ctrl - Enabling/Disabling the Discharge setting */
typedef enum {
    /* Discharge Disabled */
    PmicCdd_LdoDischarge_Disabled = 0,
    /* Discharge Enabled */
    PmicCdd_LdoDischarge_Enabled = 1,
} PmicCdd_LdoDischargeType;

/* Vcca Vmon Ctrl - Enabling/Disabling the volatge monitoring of Vcca */
typedef enum {
    /* Disable OvUV */
    PmicCdd_VccaVmonDisabled = 0,
    /* Enable OvUV */
    PmicCdd_VccaVmonEnabled = 1,
} PmicCdd_VccaVmonEnType;

/* Vcca Vmon Ctrl - Enabling/Diabling the Volatge monitoring of Vmon1 */
typedef enum {
    /* Disable OvUV */
    PmicCdd_Vmon1VmonDisabled = 0,
    /* Enable OvUV */
    PmicCdd_Vmon1VmonEnabled = 1,
} PmicCdd_Vmon1VmonEnType;

/* Vcca Vmon Ctrl - Enabling/Diabling the Volatge monitoring of Vmon2 */
typedef enum {
    /* Disable OvUV */
    PmicCdd_Vmon2VmonDisabled = 0,
    /* Enable OvUV */
    PmicCdd_Vmon2VmonEnabled = 1,
} PmicCdd_Vmon2VmonEnType;

/* Vcca Vmon Ctrl - Deglitch setting */
typedef enum {
    /* Deglitch BUCK/LDO/VMON - 4us, VCCA - 4us */
    PmicCdd_deglitch_0 = 0,
    /* Deglitch BUCK/LDO/VMON - 20us, VCCA - 20us */
    PmicCdd_deglitch_1 = 1,
    /* Deglitch BUCK/LDO/VMON - 0.5us, VCCA - 0.5us*/
    PmicCdd_deglitch_2 = 2,
    /* Deglitch BUCK/LDO/VMON - 0.5us, VCCA - 4us */
    PmicCdd_deglitch_3 = 3,
    /* Deglitch BUCK/LDO/VMON - 0.5us, VCCA - 20us */
    PmicCdd_deglitch_4 = 4,
    /* Deglitch BUCK/LDO/VMON - 4us, VCCA - 0.5us */
    PmicCdd_deglicth_5 = 5,
    /* Deglitch BUCK/LDO/VMON - 4us, VCCA - 4us */
    PmicCdd_deglitch_6 = 6,
    /* Deglitch BUCK/LDO/VMON - 4us, VCCA - 20us */
    PmicCdd_deglitch_7 = 7,
} PmciCdd_DeglitchType;

typedef struct
{
  uint32 pc;      /* interrupted PC captured at nINT ISR entry (was: lr — incorrect caller LR) */
  uint32 rev;
  uint16 FaultId;
} PmicCddWdgEarlyWarning;

typedef uint8 Pmic_ChannelType;

typedef uint8 PmicCdd_AddressType;

typedef uint8 PmicCdd_I2cChannelType;

typedef uint16 PmicCdd_AdcValueType;

typedef uint16 PmicCdd_Adc_GroupType;

#endif
/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/*----------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  05-Jun-2024
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-3280
Change Description: PmicCdd initial release, Added support for WDG and ADC
        Initialization and functionalities.
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  26-Jun-2024
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-3709
Change Description: Added support for ESM configuration and Error interrupt checking,
            Reporting and clear functionalities.
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  24-Sep-2024
By                :  sdv
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-4380
Change Description: PmicCdd ADC Interrupt Mechanism Handling Implementation
-----------------------------------------------------------------------------*/