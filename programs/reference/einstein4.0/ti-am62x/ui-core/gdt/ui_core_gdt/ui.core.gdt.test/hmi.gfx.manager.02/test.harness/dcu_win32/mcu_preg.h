/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2008. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** Name:           mcu_preg.h
**
** Description:    Peripheral register descriptors for the MPC5602S,
**                 MPC5604S, and MPC5606S.
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#ifndef MCU_PREG_H
#define MCU_PREG_H


/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "MPC560xS.h"


/*
** An example of how to use the above header file is as follows.  Assume
** a register is defined as below:
**
**      union { 
**          vuint16_t R;
**          extern struct {
**              vuint16_t:1;
**              vuint16_t SME:1;
**              vuint16_t APC:1;
**              vuint16_t:1;
**              vuint16_t PA:2;
**              vuint16_t OBE:1;
**              vuint16_t IBE:1;
**              vuint16_t DCS:2;
**              vuint16_t ODE:1;
**              vuint16_t HYS:1;
**              vuint16_t SRC:2;
**              vuint16_t WPE:1;
**              vuint16_t WPS:1;
**          } B;
**      } PCR[512];
**
** Now assume you have a line of code as shown below:
**   SIU.PCR[i].R = 0x0200;	//Enable output buffer, select I/O
**
** The value of 0x0200 is binary 00000010_00000000.
**
** Mapping bit by bit, starting from the first bit in the structure
** shows that only OBE is being set to a 1.
*/

extern struct ADC_tag        adc_0_reg;
extern struct FLEXCAN_tag        can_0_reg;
extern struct FLEXCAN_tag        can_1_reg;
extern struct CANSP_tag        cansp_reg;
extern struct CFLASH_tag        cflash0_reg;
extern struct CGM_tag        cgm_reg;
extern struct DCU_tag        dcu_reg;
extern struct RLE_tag           rle_reg;
extern struct DFLASH_tag        dflash_reg;
extern struct DMAMUX_tag        dmamux_reg;
extern struct DSPI_tag        dspi_0_reg;
extern struct DSPI_tag        dspi_1_reg;
extern struct EDMA_tag        edma_reg;
extern struct EMIOS_tag        emios_0_reg;
extern struct EMIOS_tag        emios_1_reg;
extern struct I2C_tag        i2c_0_reg;
extern struct I2C_tag        i2c_1_reg;
extern struct I2C_tag        i2c_2_reg;
extern struct I2C_tag        i2c_3_reg;
extern struct INTC_tag        intc_reg;
extern struct LCD_tag        lcd_reg;
extern struct LINFLEX_tag        linflex_0_reg;
extern struct LINFLEX_tag        linflex_1_reg;
extern struct ME_tag        me_reg;
extern struct MPU_tag        mpu_reg;
extern struct PCU_tag        pcu_reg;
extern struct PIT_tag        pit_reg;
extern struct RGM_tag        rgm_reg;
extern struct RTC_tag        rtc_reg;
extern struct SIU_tag        siu_reg;
extern struct SMC_tag        smc_reg;
extern struct SSCM_tag        sscm_reg;
extern struct SSD_tag        ssd_0_reg;
extern struct SSD_tag        ssd_1_reg;
extern struct SSD_tag        ssd_2_reg;
extern struct SSD_tag        ssd_3_reg;
extern struct SSD_tag        ssd_4_reg;
extern struct SSD_tag        ssd_5_reg;
extern struct STM_tag        stm_reg;
extern struct SWT_tag        swt_reg;
extern struct WKUP_tag        wkup_reg;
extern struct CFLASH_tag        cflash1_reg;
extern struct SGL_tag        sgl_reg;
extern struct LCD_tag        lcd_reg;
extern struct ECSM_tag        ecsm_reg;
extern struct QUADSPI_tag        quadspi_0_reg;

#define ADC_0         adc_0_reg
#define CAN_0             can_0_reg
#define CAN_1             can_1_reg
#define CANSP           cansp_reg
#define CFLASH           cflash0_reg
#define CGM           cgm_reg
#define DCU           dcu_reg
#define RLE           rle_reg
#define DFLASH           dflash_reg
#define DMAMUX           dmamux_reg
#define DSPI_0         dspi_0_reg
#define DSPI_1         dspi_1_reg
#define EDMA           edma_reg
#define EMIOS_0         emios_0_reg
#define EMIOS_1         emios_1_reg
#define I2C_0         i2c_0_reg
#define I2C_1         i2c_1_reg
#define I2C_2         i2c_2_reg
#define I2C_3         i2c_3_reg
#define INTC           intc_reg
#define LCD           lcd_reg
#define LINFLEX_0         linflex_0_reg
#define LINFLEX_1         linflex_1_reg
#define ME           me_reg
#define MPU           mpu_reg
#define PCU           pcu_reg
#define PIT           pit_reg
#define RGM           rgm_reg
#define RTC           rtc_reg
#define SIU           siu_reg
#define SMC           smc_reg
#define SSCM           sscm_reg
#define SSD_0         ssd_0_reg
#define SSD_1         ssd_1_reg
#define SSD_2         ssd_2_reg
#define SSD_3         ssd_3_reg
#define SSD_4         ssd_4_reg
#define SSD_5         ssd_5_reg
#define STM           stm_reg
#define SWT           swt_reg
#define WKUP           wkup_reg

#define CFLASH1        cflash1_reg

#define SGL        sgl_reg

#define LCD        lcd_reg

#define ECSM        ecsm_reg

#define QUADSPI_0        quadspi_0_reg

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

/*
** The following definitions are used to map GPIO pins used by the SIUL
** to the SIU.PCR[], SIU.GPDO[], and SIU.GPDI[] registers.  Use the #defines
** as indexes (for example SIU.GPDO[x]) to gain control of the GPIO pin.
**
** NOTE:  The 144 pin configuration ends at PH5.  The 176 pin configuration
**        goes to PIxxx
*/
#define PA0  0
#define PA1  1
#define PA2  2
#define PA3  3
#define PA4  4
#define PA5  5
#define PA6  6
#define PA7  7
#define PA8  8
#define PA9  9
#define PA10 10
#define PA11 11
#define PA12 12
#define PA13 13
#define PA14 14
#define PA15 15

#define PB0  16
#define PB1  17
#define PB2  18
#define PB3  19
#define PB4  20
#define PB5  21
#define PB6  22
#define PB7  23
#define PB8  24
#define PB9  25
#define PB10 26
#define PB11 27
#define PB12 28
#define PB13 29

#define PC0  30
#define PC1  31
#define PC2  32
#define PC3  33
#define PC4  34
#define PC5  35
#define PC6  36
#define PC7  37
#define PC8  38
#define PC9  39
#define PC10 40
#define PC11 41
#define PC12 42
#define PC13 43
#define PC14 44
#define PC15 45

#define PD0  46
#define PD1  47
#define PD2  48
#define PD3  49
#define PD4  50
#define PD5  51
#define PD6  52
#define PD7  53
#define PD8  54
#define PD9  55
#define PD10 56
#define PD11 57
#define PD12 58
#define PD13 59
#define PD14 60
#define PD15 61

#define PE0  62
#define PE1  63
#define PE2  64
#define PE3  65
#define PE4  66
#define PE5  67
#define PE6  68
#define PE7  69

#define PF0  70
#define PF1  71
#define PF2  72
#define PF3  73
#define PF4  74
#define PF5  75
#define PF6  76
#define PF7  77
#define PF8  78
#define PF9  79
#define PF10 80
#define PF11 81
#define PF12 82
#define PF13 83
#define PF14 84
#define PF15 85

#define PG0  86
#define PG1  87
#define PG2  88
#define PG3  89
#define PG4  90
#define PG5  91
#define PG6  92
#define PG7  93
#define PG8  94
#define PG9  95
#define PG10 96
#define PG11 97
#define PG12 98

#define PH0  99
#define PH1  100
#define PH2  101
#define PH3  102
#define PH4  103
#define PH5  104

#define PJ0  105
#define PJ1  106
#define PJ2  107
#define PJ3  108
#define PJ4  109
#define PJ5  110
#define PJ6  111
#define PJ7  112
#define PJ8  113
#define PJ9  114
#define PJ10 115
#define PJ11 116
#define PJ12 117
#define PJ13 118
#define PJ14 119
#define PJ15 120

#define PK0  121
#define PK1  122
#define PK2  123
#define PK3  124
#define PK4  125
#define PK5  126
#define PK6  127
#define PK7  128
#define PK8  129
#define PK9  130
#define PK10 131
#define PK11 132



/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/


/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**
** CMS Rev main/1   11/11/08     JKANOZA
** Initial revision.
**
**==========================================================================*/

/* end of file =============================================================*/

#endif


