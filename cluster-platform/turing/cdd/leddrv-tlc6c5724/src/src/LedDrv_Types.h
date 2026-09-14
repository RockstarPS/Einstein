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
*  File Name         :  LedDrv_Types.h                                             *
*  Module Short Name :  leddrv-tlc6c5724                                     *
*  VOBName           :                                                       *
*  Author            : sdv                                                   *
*  Description       : This file contains the typedefs for LedDrv              *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang                                                  *
* Target Hardware  :  Independent                                            *
*                                                                            *
******************************************************************************/
#ifndef LEDDRV_TYPES_H
#define LEDDRV_TYPES_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
#include <stdint.h>

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*Special Command for TLC6C5724*/
#define LEDDRV_GS_READ                     0x5AFU
#define LEDDRV_SID_READ                    0x5A3U
#define LEDDRV_FC_BC_DC_READ               0x5AC
#define LEDDRV_APS_CHECK                   0x53AU
#define LEDDRV_LOD_LSD_SELF_TEST           0x535U
#define LEDDRV_NEGBIT_TOGGLE               0x55AU
#define LEDDRV_ERR_CLR                     0xA53U
#define LEDDRV_GLOBAL_RST                  0xA5CU

/*GROUP - R,G,B*/
#define LEDDRV_GROUPR                      0
#define LEDDRV_GROUPG                      1
#define LEDDRV_GROUPB                      2

/*GS MAX VALUE*/
#define LEDDRV_8BIT_GS_MAX                   255
#define LEDDRV_10BIT_GS_MAX                  1023
#define LEDDRV_12BIT_GS_MAX                  4095


/*Dot Correction - 7 bits - 128 levels*/
#define LEDDRV_DC_MAX_LEVEL                128

/*The MAX difference while doing the linear search */
#define LEDDRV_FLT_MAX                     100

/*The position size of register in a chip - 24 Leds Controlled = 24 positions*/
#define LEDDRV_POSITION_SIZE               (uint8)24

/*The width of the GS Control in Bits*/
#define LEDDRV_GS_CONTROL_WIDTH            (uint8)12

/*The number of Bits in a Byte*/
#define LEDDRV_NUMOFBITS_IN_BYTE           (uint8)8


/*****************************************************************************
*                                 Typedef Definitions                       *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/* Register Bit Field Definitions */

/*Grayscale Register*/
typedef union{
    struct{
        uint32  OUTR0_GS : 12;             // Grayscale for OUTR0 (Bits 11-0)
        uint32 OUTG0_GS : 12;             // Grayscale for OUTG0 (Bits 23-12)
        uint32 OUTB0_GS : 12;             // Grayscale for OUTB0 (Bits 35-24)
        uint32 OUTR1_GS : 12;             // Grayscale for OUTR1 (Bits 47-36)
        uint32 OUTG1_GS : 12;             // Grayscale for OUTG1 (Bits 59-48)
        uint32 OUTB1_GS : 12;             // Grayscale for OUTB1 (Bits 71-60)
        uint32 OUTR2_GS : 12;             // Grayscale for OUTR2 (Bits 83-72)
        uint32 OUTG2_GS : 12;             // Grayscale for OUTG2 (Bits 95-84)
        uint32 OUTB2_GS : 12;             // Grayscale for OUTB2 (Bits 107-96)
        uint32 OUTR3_GS : 12;             // Grayscale for OUTR3 (Bits 119-108)
        uint32 OUTG3_GS : 12;             // Grayscale for OUTG3 (Bits 131-120)
        uint32 OUTB3_GS : 12;             // Grayscale for OUTB3 (Bits 143-132)
        uint32 OUTR4_GS : 12;             // Grayscale for OUTR4 (Bits 155-144)
        uint32 OUTG4_GS : 12;             // Grayscale for OUTG4 (Bits 167-156)
        uint32 OUTB4_GS : 12;             // Grayscale for OUTB4 (Bits 179-168)
        uint32 OUTR5_GS : 12;             // Grayscale for OUTR5 (Bits 191-180)
        uint32 OUTG5_GS : 12;             // Grayscale for OUTG5 (Bits 203-192)
        uint32 OUTB5_GS : 12;             // Grayscale for OUTB5 (Bits 215-204)
        uint32 OUTR6_GS : 12;             // Grayscale for OUTR6 (Bits 227-216)
        uint32 OUTG6_GS : 12;             // Grayscale for OUTG6 (Bits 239-228)
        uint32 OUTB6_GS : 12;             // Grayscale for OUTB6 (Bits 251-240)
        uint32 OUTR7_GS : 12;             // Grayscale for OUTR7 (Bits 263-252)
        uint32 OUTG7_GS : 12;             // Grayscale for OUTG7 (Bits 275-264)
        uint32 OUTB7_GS : 12;             // Grayscale for OUTB7 (Bits 287-276)
    } bits;
    // Full 288-bit value representation as 36 uint32_t values (8 bits each)
    uint8 value[36];  // 288 bits = 36 * 8 bits
} GS_Reg_t;

/*FC-BC-DC Register*/
typedef union {
    struct {
        uint32 outr0_dc : 7;               // Dot correction for OUTR0 (Bits 6-0)
        uint32 outg0_dc : 7;               // Dot correction for OUTG0 (Bits 13-7)
        uint32 outb0_dc : 7;               // Dot correction for OUTB0 (Bits 20-14)
        uint32 outr1_dc : 7;               // Dot correction for OUTR1 (Bits 27-21)
        uint32 outg1_dc : 7;               // Dot correction for OUTG1 (Bits 34-28)
        uint32 outb1_dc : 7;               // Dot correction for OUTB1 (Bits 41-35)
        uint32 outr2_dc : 7;               // Dot correction for OUTR2 (Bits 48-42)
        uint32 outg2_dc : 7;               // Dot correction for OUTG2 (Bits 55-49)
        uint32 outb2_dc : 7;               // Dot correction for OUTB2 (Bits 62-56)
        uint32 outr3_dc : 7;               // Dot correction for OUTR3 (Bits 69-63)
        uint32 outg3_dc : 7;               // Dot correction for OUTG3 (Bits 76-70)
        uint32 outb3_dc : 7;               // Dot correction for OUTB3 (Bits 83-77)
        uint32 outr4_dc : 7;               // Dot correction for OUTR4 (Bits 90-84)
        uint32 outg4_dc : 7;               // Dot correction for OUTG4 (Bits 97-91)
        uint32 outb4_dc : 7;               // Dot correction for OUTB4 (Bits 104-98)
        uint32 outr5_dc : 7;               // Dot correction for OUTR5 (Bits 111-105)
        uint32 outg5_dc : 7;               // Dot correction for OUTG5 (Bits 118-112)
        uint32 outb5_dc : 7;               // Dot correction for OUTB5 (Bits 125-119)
        uint32 outr6_dc : 7;               // Dot correction for OUTR6 (Bits 132-126)
        uint32 outg6_dc : 7;               // Dot correction for OUTG6 (Bits 139-133)
        uint32 outb6_dc : 7;               // Dot correction for OUTB6 (Bits 146-140)
        uint32 outr7_dc : 7;               // Dot correction for OUTR7 (Bits 153-147)
        uint32 outg7_dc : 7;               // Dot correction for OUTG7 (Bits 160-154)
        uint32 outb7_dc : 7;               // Dot correction for OUTB7 (Bits 167-161)
        uint32 outr_bc : 8;                // Brightness control for OUTR (Bits 175-168)
        uint32 outg_bc : 8;                // Brightness control for OUTG (Bits 183-176)
        uint32 outb_bc : 8;                // Brightness control for OUTB (Bits 191-184)
        uint32 dc_range_r : 1;             // Dot correction range for OUTR group (Bit 192)
        uint32 dc_range_g : 1;             // Dot correction range for OUTG group (Bit 193)
        uint32 dc_range_b : 1;             // Dot correction range for OUTB group (Bit 194)
        uint32 auto_repeat : 1;            // Auto repeat (Bit 195)
        uint32 timing_reset : 1;        // Timing reset (Bit 196)
        uint32 gs_mode : 2;                // Grayscale counter mode (Bits 198-197)
        uint32 aps_time : 1;               // Adjacent-pin short-detection time (Bit 199)
        uint32 aps_current : 1;            // Adjacent-pin short-detection sink current (Bit 200)
        uint32 lsd_voltage : 1;            // LED short-detection voltage (Bit 201)
        uint32 lod_voltage : 1;            // LED open-detection voltage (Bit 202)
        uint32 slew_rate : 1;              // Output slew-rate time (Bit 203)
        uint32 led_err_mask : 1;           // LED error mask (Bit 204)
        uint32 reserved1 : 8;              // First 8 bits of RESERVED (bits 205 - 212)
        uint32 reserved2 : 8;              // Next 8 bits of RESERVED (bits 213 - 220)
        uint32 reserved3 : 8;              // Next 8 bits of RESERVED (bits 221 - 228)
        uint32 reserved4 : 8;              // Next 8 bits of RESERVED (bits 229 - 236)
        uint32 reserved5 : 8;              // Next 8 bits of RESERVED (bits 237 - 244)
        uint32 reserved6 : 8;              // Next 8 bits of RESERVED (bits 245 - 252)
        uint32 reserved7 : 8;              // Next 8 bits of RESERVED (bits 253 - 260)
        uint32 reserved8 : 8;              // Next 8 bits of RESERVED (bits 261 - 268)
        uint32 reserved9 : 7;              // last 7 bits of RESERVED (bits 269 - 275)
        uint32 cmd : 12;                     //Command Function (Bits 276-287)
    }__attribute__((packed)) bits;
    // Full 288-bit value representation as 36 uint32_t values (8 bits each)
    uint8 value[36];  // 288 bits = 36 * 8 bits
} FC_BC_DC_Reg_t;

/*SID Register*/
typedef union 
{
    struct {
        uint32 reserved1 : 32;                 // Reserved (Bits 31-0)
        uint32 reserved2 : 32;                 // Reserved (Bits 63-32)
        uint32 reserved3 : 32;                 // Reserved (Bits 95-64)
        uint32 reserved4 : 32;                 // Reserved (Bits 127-96)
        uint32 reserved5 : 16;                 // Reserved (Bits 143-128)
        uint32 outr_lsd1 : 8;                    // LSD1 for OUTR (Bits 151-144)
        uint32 outg_lsd1 : 8;                    // LSD1 for OUTG (Bits 159-152)
        uint32 outb_lsd1 : 8;                    // LSD1 for OUTB (Bits 167-160)
        uint32 outr_lsd2 : 8;                    // LSD2 for OUTR (Bits 175-168)
        uint32 outg_lsd2 : 8;                    // LSD2 for OUTG (Bits 183-176)
        uint32 outb_lsd2 : 8;                    // LSD2 for OUTB (Bits 191-184)
        uint32 reserved6 : 12;                   // Reserved (Bits 203-192)
        uint32 neg0 : 1;                         // NEG0 (Bit 204)
        uint32 neg1 : 1;                         // NEG1 (Bit 205)
        uint32 lod_lsd_flag : 3;                 // LOD/LSD self test flag (Bits 208-206)
        uint32 iof : 1;                          // IOF (Bit 209)
        uint32 isf : 1;                          // ISF (Bit 210)
        uint32 aps_flag : 3;                     // APS flag (Bits 213-211)
        uint32 ptw : 1;                          // PTW (Bit 214)
        uint32 tef : 1;                          // TEF (Bit 215)
        uint32 outr_aps : 8;                     // APS for OUTR (Bits 223-216)
        uint32 outg_aps : 8;                     // APS for OUTG (Bits 231-224)
        uint32 outb_aps : 8;                     // APS for OUTB (Bits 239-232)
        uint32 outr_lod1 : 8;                   // LOD1 for OUTR (Bits 247-240)
        uint32 outg_lod1 : 8;                   // LOD1 for OUTG (Bits 255-248)
        uint32 outb_lod1 : 8;                   // LOD1 for OUTB (Bits 263-256)
        uint32 outr_lod2 : 8;                   // LOD2 for OUTR (Bits 271-264)
        uint32 outg_lod2 : 8;                   // LOD2 for OUTG (Bits 279-272)
        uint32 outb_lod2 : 8;                   // LOD2 for OUTB (Bits 287-280)
    } __attribute__((packed)) bits;
    // Full 288-bit value representation as 36 uint8_t values (8 bits each)
    uint8 value[36];  // 288 bits = 36 * 8 bits
} SID_Reg_t;


/*LOD - LSD failure or PWM error information Mask*/
typedef enum
{
    /*Enabling Err pin to pull down*/
    Led_Err_Mask_Enable = 0x0,
    /*Disabling Err pin to pull up*/
    Led_Err_Mask_Disable = 0x1
} LedDrv_LedMaskType;

/*Slew rate Setting*/
typedef enum
{
    /*Slew reate 100ns*/
    LedDrv_SlewwRate_100ns = 0x0,
    /*Slew rate 200ns*/
    LedDrv_SlewwRate_200ns = 0x1
} LedDrv_SlewRateType;

/*LED Open-Detecton Thresold*/
typedef enum
{
    /*LOD threshold 0.3V*/
    LedDrv_LODThresold_0_3V = 0x0,
    /*LOD thresold 0.5V*/
    LedDrv_LODThresold_0_5V = 0x1
} LedDrv_LODThresoldType;

/*LED Short-Detection Thresold*/
typedef enum
{
    /*LSD threshold Vsense - 0.3V*/
    LedDrv_LSDThresold_0_3V = 0x0,
    /*LSD threshold Vsense - 0.7V*/
    LedDrv_LSDThresold_0_7V = 0x1
} LedDrv_LSDThresoldType;

/*Adjacent Pin Short Detection sink current*/
typedef enum
{
    /*Adjacent Pin Short Detection sink current 200uA*/
    LedDrv_APSCurrent_200uA = 0x0,
    /*Adjacent Pin Short Detection sink current 400uA*/
    LedDrv_APSCurrent_400uA = 0x1
} LedDrv_APSCurrentType;

/*Adjacent Pin Short Detection Time*/
typedef enum
{
    /*Adjacent Pin Short Detection Time 10ns*/
    LedDrv_APSTime_10us = 0x0,
    /*Adjacent Pin Short Detection Time 20ns*/
    LedDrv_APSTime_20us = 0x1
} LedDrv_APSTimeType;

/*Grayscale Counter Mode Selection*/
typedef enum
{
    /*Grayscale Counter Mode Selection 12 bit*/
    LedDrv_GSMode_12bit = 0x1,
    /*Grayscale Counter Mode Selection 10 bit*/
    LedDrv_GSMode_10bit = 0x2,
    /*Grayscale Counter Mode Selection 8 bit*/
    LedDrv_GSMode_8bit = 0x3
} LedDrv_GSCounterModeType;

/*Display timing reset Mode*/
typedef enum
{
    /*Timing Reset Disabled*/
    LedDrv_TimingReset_Disable = 0x0,
    /*Timing Reset Enabled*/
    LedDrv_TimingReset_Enable = 0x1
} LedDrv_TimingResetType;

/*Auto Disaplay Repeat Mode*/
typedef enum
{
    /*Auto Disaplay Repeat Mode Disabled*/
    LedDrv_AutoRepeat_Disable = 0x0,
    /*Auto Disaplay Repeat Mode Enabled*/
    LedDrv_AutoRepeat_Enable = 0x1
} LedDrv_AutoRepeatModeType;

/*Dot Correction Adjustment Range for BLUE Color output*/
typedef enum
{
    /*Lower Range 0%-66.7%*/
    LedDrv_LowDcRange_Blue = 0x0,
    /*Upper Range 33.3%-100%*/
    LedDrv_HighDcRange_Blue = 0x1
} LedDrv_DcRange_BlueType;

/*Dot Correction Adjustment Range for GREEN Color output*/
typedef enum
{
    /*Lower Range 0%-66.7%*/
    LedDrv_LowDcRange_Green = 0x0,
    /*Upper Range 33.3%-100%*/
    LedDrv_HighDcRange_Green = 0x1
} LedDrv_DcRange_GreenType;

/*Dot Correction Adjustment Range for RED Color output*/
typedef enum
{
    /*Lower Range 0%-66.7%*/
    LedDrv_LowDcRange_Red = 0x0,
    /*Upper Range 33.3%-100%*/
    LedDrv_HighDcRange_Red = 0x1
} LedDrv_DcRange_RedType;

/*Look up Table Type for DC Data and BC Data - Table 16 and Table 17 - Data sheet*/
typedef struct { 
    /*DC Data*/
    uint8 LedDrv_DcData;
    /*BC Data*/
    uint8 LedDrv_BcData;
    /*High DC range*/
    float32 LedDrv_CurrentRatio_HighDCRange;
    /*Low DC Range*/
    float32 LedDrv_CurrentRatio_LowDCRange;
} LedDrv_DC_LookUpTable_Type;

/*Led Channel Type*/
typedef uint8 LedDrv_LedChannelType;

/*Led Fault Status Types*/
typedef enum
{
    /*Led is OK*/
    LEDDRV_OK,
    /*Led is Open*/
    LEDDRV_OPEN,
    /*Led is Short*/
    LEDDRV_SHORT,
    /*Led is Short to Ground*/
    LEDDRV_SHORT_GND,
}LedDrv_FaultStatusType;
#endif /* #ifndef LEDDRV_TYPES_H */

/*---------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 21/Oct/2024
By                : sdv
Traceability      : 
Change Description: Initial Version 
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 19/Nov/2024
By                : sdv
Traceability      : Jira Id: https://visteon.atlassian.net/browse/PE4TI29141-4872
                    https://visteon.atlassian.net/browse/PE4TI29141-4873
Change Description: Phase 1 Implementation
-----------------------------------------------------------------------------------------*/

