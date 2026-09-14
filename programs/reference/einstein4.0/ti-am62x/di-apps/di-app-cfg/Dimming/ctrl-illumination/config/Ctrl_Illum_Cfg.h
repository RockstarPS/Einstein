/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2017 -2018. Visteon Corporation owns all rights to this work and
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
 **==========================================================================*/
#ifndef CTRL_ILLUM_CFG_H
#define CTRL_ILLUM_CFG_H
/*==========================================================================*/
#include "Rte_Type.h"
//#include "IllumMdl_Adapter.h"
//#include "ctrl_Illumination_Extn.h"
//#include "Ctrl_Illumination.h"

/*Configure Applicable Illumination Data */
/*MSB--------LSB*/
/*7 bit --- Duty*/
/*6 bit --- Brightness*/
/*5 bit --- RGB_Dimming*/
/*4 bit --- Bulb*/
/*3 bit --- LED*/
/*2 bit --- Dial*/
/*1 bit --- Display*/
/*0 bit --- Telltale*/
#define APPL_ILLUMINATION_DATA 0x02u //0b10011111
#define BYTE_LENGTH            8u
#define ILL_OFF_MODE 3u
#define UPDATE_COUNT 100u
#define PWM_MAX 1000u  //100% - 0.1Res
/*The delay time until the brightness change is reflected on the actual dial/display for the brightness adjustment operation.*/
#define T_ILL_dl1_idx                            1u

/*P_Lights CAN In = On ($1), Delay time until switching from Daytime brightness to Nighttime brightness is reflected by illumination On CAN In = Off ($0) -> On ($1)*/
#define T_ILL_dl2_idx                            2u

/*P_Lights CAN In =On ($1), ILLumination On CAN In =On ($1) -> Off ($0) delay time until nighttime brightness changes to daytime brightness is reflected.*/
#define T_ILL_dl3_idx                            3u

/*The delay between switching the PWM output from the Daytime to the Nighttime value (100%/ illumination cancel state).*/
#define ILL_PWM_on1_idx                          4u

/*This is the delay time until the PWM output is switched from the nighttime (100%/ illumination cancel state) to the nighttime (selected luminance) value.*/
#define ILL_PWM_on2_idx                          5u

/*This is the delay time before switching the PWM output from the nighttime to the daytime value.*/
#define ILL_PWM_off_idx                          6u

/*This is the delay time until the Step of the PWM output is changed during the nighttime.*/
#define ILL_PWM_ch_idx                           7u

/*Illumination Telltale Diagnostics Routine Control*/
#define ILLUM_TT_DIAG_ROUTINE_CONTROL00     0x00u
#define ILLUM_TT_DIAG_ROUTINE_CONTROL01     0x01u
#define ILLUM_TT_DIAG_ROUTINE_CONTROL02     0x02u
#define ILLUM_TT_DIAG_ROUTINE_NOTCONTROLLED 0xFFu

/*Illumination CAN Communication*/
#define CAN_COMMUNICATION_DISABLED         0u
#define CAN_COMMUNICATION_ENABLED          1u

/*Diagnostics control Enable/Disbale*/
#define C021_ROUTINE_NOT_APPL 0xffu
#define C020_ROUTINE_NOT_APPL 0xffu

/*Illumination DAY and NIGHT Configuration*/
#define ILLUMINATION_DAY_MODE               0u
#define ILLUMINATION_NIGHT_MODE             1u

#define MODE1  ILLUMINATION_DAY_MODE
#define MODE2  ILLUMINATION_NIGHT_MODE

#define SLEW_DISABLE_MODE  4u  //ETM_MODE - uncomment after testing

#define INVALID              0u
#define VALID                1u
#define IGN_ON               2u
#define IGN_OFF              1u

/* TOTAL NO. OF ILLUMINATION MODES*/
#define TOT_ILLUM_MODE 2u

/* TOTAL NO. OF ILLUMINATION STEPS*/
#define TOT_STEP       6u

/*===============================*/
/*NO OF ILLUMINATION COMPONENTS*/
#define NO_OF_DUTY      1u
#define NO_OF_BULB      1u
#define NO_OF_LED       1u
#define NO_OF_DIAL      1u
#define NO_OF_DISPLAYS  1u
#define NO_OF_RGB       1u
#define NO_OF_BGT       1u
#define NO_OF_TELLTALES 1u
/*===============================*/

#define BULB_MAX 8u
#define LED_MAX 8u
#define DIAL_MAX 7u
#define LCD_MAX  7u
#define DUTY_MAX 7u
#define BGT_MAX  7u

#define TT_MAX_BRIGHT  100u

#define TURN_LR 0u
#define POSITION_LIGHTS 1u
#define FRONT_FOG 2u

#define TT_INDEX1 TURN_LR
#define TT_INDEX2 POSITION_LIGHTS
#define TT_INDEX3 FRONT_FOG

#define TIMER1 1u
#define TIMER2 2u
#define TIMER3 3u
#define TIMER4 4u
#define TIMER5 5u
#define TIMER6 6u
#define TIMER7 7u
#define TIMER8 8u
#define TIMER9 9u
#define TIMER10 10u
#define TIMER11 11u
#define TIMER12 12u
#define TIMER13 13u
#define TIMER14 14u
#define TIMER15 15u
#define TIMER16 16u

#define DEFAULT_MODE ILLUMINATION_DAY_MODE
#define DEFAULT_TT_MODE  {ILLUMINATION_DAY_MODE, ILLUMINATION_DAY_MODE, ILLUMINATION_DAY_MODE}
#define DEFAULT_COUNT  1u
#define DEFAULT_TT_COUNT  {1u, 1u, 1u}



//Illumination values
/*Illumination PWM CAN OUT constant values*/
#define ILL_CAN_OFF                         0u

// /*Illumination PWM Bulb constant values*/
#define ILL_PWM_BULB_OFF                    0u

// /*Illumination PWM LED constant values*/
#define ILL_PWM_LED_OFF                    0u

// /*Illumination Night Values*/
#define ILL_NI_OFF                          0u

/*Illumination PWM for max luminance */
#define T_MAX                               100u

#define TT_OFF                              0u

/*--------------------------- DUTY CONTROL PARAMETERS -------------------*/
#define DutyMode1_Timer 0u
#define DutyMode2_Timer 0u
#define DutyMode3_Timer 0u
#define DutyMode4_Timer 0u

#define DutyStep1_Timer  0u
#define DutyStep2_Timer  0u
#define DutyStep3_Timer  0u
#define DutyStep4_Timer  0u
#define DutyStep5_Timer  0u
#define DutyStep6_Timer  0u
#define DutyStep7_Timer  0u

#define DutyMode1_Slewrate  0u
#define DutyMode2_Slewrate  0u
#define DutyMode3_Slewrate  0u
#define DutyMode4_Slewrate  0u
#define DutyMode5_Slewrate  0u

#define Duty_Mode_Time {{DutyMode1_Timer, DutyMode2_Timer}}
#define Duty_Step_Time {{DutyStep1_Timer, DutyStep2_Timer, DutyStep3_Timer, DutyStep4_Timer, DutyStep5_Timer, DutyStep6_Timer}}
#define Duty_Mode_Timer_ID {{TIMER1,TIMER1}}
#define Duty_Step_Timer_ID {{TIMER9,TIMER9,TIMER9,TIMER9,TIMER9,TIMER9}}
#define DUTY_TABLE_INIT \
{\
{/*Display_1*/\
    {0, 20, 40, 60, 80, 100}, /*ILLUMINATION_DAY_MODE*/\
    {0, 15, 25, 45, 65, 85}, /*ILLUMINATION_NIGHT_MODE*/\
}\
}
                         
/*-----------------------------------------------------------------------*/
/*--------------------------- BULB CONTROL PARAMETERS -------------------*/
#define BulbMode1_Timer 0u
#define BulbMode2_Timer 0u
#define BulbMode3_Timer 0u
#define BulbMode4_Timer 0u

#define BulbStep1_Timer  0u
#define BulbStep2_Timer  0u
#define BulbStep3_Timer  0u
#define BulbStep4_Timer  0u
#define BulbStep5_Timer  0u
#define BulbStep6_Timer  0u
#define BulbStep7_Timer  0u

#define BulbMode1_Slewrate  0u
#define BulbMode2_Slewrate  0u
#define BulbMode3_Slewrate  0u
#define BulbMode4_Slewrate  0u
#define BulbMode5_Slewrate  0u

#define Bulb_Mode_Time {{BulbMode1_Timer, BulbMode2_Timer}}
#define Bulb_Step_Time {{BulbStep1_Timer, BulbStep2_Timer, BulbStep3_Timer, BulbStep4_Timer, BulbStep5_Timer, BulbStep6_Timer}}
#define Bulb_Mode_Timer_ID {{TIMER2,TIMER2}}
#define Bulb_Step_Timer_ID {{TIMER10,TIMER10,TIMER10,TIMER10,TIMER10,TIMER10}}
#define BULB_TABLE_INIT \
{\
{/*Display_1*/\
    {0, 20, 40, 60, 80, 100}, /*ILLUMINATION_DAY_MODE*/\
    {0, 15, 25, 45, 65, 85}, /*ILLUMINATION_NIGHT_MODE*/\
}\
}
/*-----------------------------------------------------------------------*/
/*--------------------------- LED CONTROL PARAMETERS -------------------*/
#define LEDMode1_Timer 0u
#define LEDMode2_Timer 0u
#define LEDMode3_Timer 0u
#define LEDMode4_Timer 0u

#define LEDStep1_Timer  0u
#define LEDStep2_Timer  0u
#define LEDStep3_Timer  0u
#define LEDStep4_Timer  0u
#define LEDStep5_Timer  0u
#define LEDStep6_Timer  0u
#define LEDStep7_Timer  0u

#define LEDMode1_Slewrate  0u
#define LEDMode2_Slewrate  0u
#define LEDMode3_Slewrate  0u
#define LEDMode4_Slewrate  0u
#define LEDMode5_Slewrate  0u

#define LED_Mode_Time {{LEDMode1_Timer, LEDMode2_Timer}}
#define LED_Step_Time {{LEDStep1_Timer, LEDStep2_Timer, LEDStep3_Timer, LEDStep4_Timer, LEDStep5_Timer, LEDStep6_Timer}}
#define LED_Mode_Timer_ID {{TIMER3,TIMER3}}
#define LED_Step_Timer_ID {{TIMER11,TIMER11,TIMER11,TIMER11,TIMER11,TIMER11}}
#define LED_TABLE_INIT \
{\
{/*Display_1*/\
    {0, 20, 40, 60, 80, 100}, /*ILLUMINATION_DAY_MODE*/\
    {0, 15, 25, 45, 65, 85}, /*ILLUMINATION_NIGHT_MODE*/\
}\
}
/*-----------------------------------------------------------------------*/
/*--------------------------- DIAL CONTROL PARAMETERS -------------------*/
#define DialMode1_Timer 0u
#define DialMode2_Timer 0u
#define DialMode3_Timer 0u
#define DialMode4_Timer 0u

#define DialStep1_Timer  0u
#define DialStep2_Timer  0u
#define DialStep3_Timer  0u
#define DialStep4_Timer  0u
#define DialStep5_Timer  0u
#define DialStep6_Timer  0u
#define DialStep7_Timer  0u

#define DialMode1_Slewrate  0u
#define DialMode2_Slewrate  0u
#define DialMode3_Slewrate  0u
#define DialMode4_Slewrate  0u
#define DialMode5_Slewrate  0u

#define Dial_Mode_Time {{DialMode1_Timer, DialMode2_Timer}}
#define Dial_Step_Time {{DialStep1_Timer, DialStep2_Timer, DialStep3_Timer, DialStep4_Timer, DialStep5_Timer, DialStep6_Timer}}
#define Dial_Mode_Timer_ID {{TIMER4,TIMER4}}
#define Dial_Step_Timer_ID {{TIMER12,TIMER12,TIMER12,TIMER12,TIMER12,TIMER12}}
#define DIAL_TABLE_INIT \
{\
{/*Display_1*/\
    {0, 20, 40, 60, 80, 100}, /*ILLUMINATION_DAY_MODE*/\
    {0, 15, 25, 45, 65, 85}, /*ILLUMINATION_NIGHT_MODE*/\
}\
}
/*-----------------------------------------------------------------------*/
/*--------------------------- LCD CONTROL PARAMETERS -------------------*/
#define DisplayMode1_Timer 0u
#define DisplayMode2_Timer 0u
#define DisplayMode3_Timer 0u
#define DisplayMode4_Timer 0u

#define DisplayStep1_Timer  0u
#define DisplayStep2_Timer  0u
#define DisplayStep3_Timer  0u
#define DisplayStep4_Timer  0u
#define DisplayStep5_Timer  0u
#define DisplayStep6_Timer  0u
#define DisplayStep7_Timer  0u

#define DisplayMode1_Slewrate  0u
#define DisplayMode2_Slewrate  0u
#define DisplayMode3_Slewrate  0u
#define DisplayMode4_Slewrate  0u
#define DisplayMode5_Slewrate  0u

#define Display_Mode_Time {{DisplayMode1_Timer, DisplayMode2_Timer}}
#define Display_Step_Time {{DisplayStep1_Timer, DisplayStep2_Timer, DisplayStep3_Timer, DisplayStep4_Timer, DisplayStep5_Timer, DisplayStep6_Timer}}
#define Display_Mode_Timer_ID {{TIMER5, TIMER5}}
#define Display_Step_Timer_ID {{TIMER13,TIMER13,TIMER13,TIMER13,TIMER13,TIMER13}}
#define DISPLAY_TABLE_INIT \
{\
{/*Display_1*/\
    {20, 40, 60, 80, 90, 100}, /*ILLUMINATION_DAY_MODE*/\
    {15, 25, 45, 65, 80, 90}, /*ILLUMINATION_NIGHT_MODE*/\
}\
}

/*-----------------------------------------------------------------------*/
/*--------------------------- BRIGHTNESS CONTROL PARAMETERS -------------------*/
#define BGTMode1_Timer 0u
#define BGTMode2_Timer 0u
#define BGTMode3_Timer 0u
#define BGTMode4_Timer 0u

#define BGTStep1_Timer  0u
#define BGTStep2_Timer  0u
#define BGTStep3_Timer  0u
#define BGTStep4_Timer  0u
#define BGTStep5_Timer  0u
#define BGTStep6_Timer  0u
#define BGTStep7_Timer  0u

#define BGTMode1_Slewrate  0u
#define BGTMode2_Slewrate  0u
#define BGTMode3_Slewrate  0u
#define BGTMode4_Slewrate  0u
#define BGTMode5_Slewrate  0u

#define BGT_Mode_Time {{BGTMode1_Timer, BGTMode2_Timer}}
#define BGT_Step_Time {{BGTStep1_Timer, BGTStep2_Timer, BGTStep3_Timer, BGTStep4_Timer, BGTStep5_Timer, BGTStep6_Timer}}
#define BGT_Mode_Timer_ID {{TIMER6,TIMER6}}
#define BGT_Step_Timer_ID {{TIMER14,TIMER14,TIMER14,TIMER14,TIMER14}}
#define BGT_TABLE_INIT \
{\
{/*Display_1*/\
    {0, 20, 40, 60, 80, 100}, /*ILLUMINATION_DAY_MODE*/\
    {0, 15, 25, 45, 65, 85}, /*ILLUMINATION_NIGHT_MODE*/\
}\
}
/*-----------------------------------------------------------------------*/
/*--------------------------- TELLTALE CONTROL PARAMETERS -------------------*/
#define TTMode1_Timer 0u
#define TTMode2_Timer 0u
#define TTMode3_Timer 0u
#define TTMode4_Timer 0u

#define TTStep1_Timer  0u
#define TTStep2_Timer  0u
#define TTStep3_Timer  0u
#define TTStep4_Timer  0u
#define TTStep5_Timer  0u
#define TTStep6_Timer  0u
#define TTStep7_Timer  0u

#define TTMode1_Slewrate  0u
#define TTMode2_Slewrate  0u
#define TTMode3_Slewrate  0u
#define TTMode4_Slewrate  0u
#define TTMode5_Slewrate  0u

#define TT_Mode_Time {{TTMode1_Timer, TTMode2_Timer}}
#define TT_Step_Time {{TTStep1_Timer, TTStep2_Timer, TTStep3_Timer, TTStep4_Timer, TTStep5_Timer, TTStep6_Timer}}
#define TT_Mode_Timer_ID {{TIMER7,TIMER7}}
#define TT_Step_Timer_ID {{TIMER15,TIMER15,TIMER15,TIMER15,TIMER15,TIMER15}}
#define TT_TABLE_INIT \
{\
{/*Display_1*/\
    {0, 20, 40, 60, 80, 100}, /*ILLUMINATION_DAY_MODE*/\
    {0, 15, 25, 45, 65, 85}, /*ILLUMINATION_NIGHT_MODE*/\
}\
}
/*-----------------------------------------------------------------------*/
/*--------------------------- RGB CONTROL PARAMETERS -------------------*/
#define RGBMode1_Timer 0u
#define RGBMode2_Timer 0u
#define RGBMode3_Timer 0u
#define RGBMode4_Timer 0u

#define RGBStep1_Timer  0u
#define RGBStep2_Timer  0u
#define RGBStep3_Timer  0u
#define RGBStep4_Timer  0u
#define RGBStep5_Timer  0u
#define RGBStep6_Timer  0u
#define RGBStep7_Timer  0u

#define RGBMode1_Slewrate  0u
#define RGBMode2_Slewrate  0u
#define RGBMode3_Slewrate  0u
#define RGBMode4_Slewrate  0u
#define RGBMode5_Slewrate  0u

#define RGB_Mode_Time {{RGBMode1_Timer, RGBMode2_Timer}}
#define RGB_Step_Time {{RGBStep1_Timer, RGBStep2_Timer, RGBStep3_Timer, RGBStep4_Timer, RGBStep5_Timer, RGBStep6_Timer}}
#define RGB_Mode_Timer_ID {{TIMER8,TIMER8}}
#define RGB_Step_Timer_ID {{TIMER16,TIMER16,TIMER16,TIMER16,TIMER16,TIMER16}}
#define RGB_TABLE_INIT \
{\
{/*Display_1*/\
    {0, 20, 40, 60, 80, 100}, /*ILLUMINATION_DAY_MODE*/\
    {0, 15, 25, 45, 65, 85}, /*ILLUMINATION_NIGHT_MODE*/\
}\
}
/*-----------------------------------------------------------------------*/

#define TT_MODE_INIT   {FALSE, FALSE, FALSE}
#define TT_STEP_INIT   {FALSE, FALSE, FALSE}




/*-----------------------------------------------------------------------*/
#endif
/*==========================================================================*/
/*============================================================================
**
** Date              : 15-05-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-17413
** Change Description: Ctrl-Illumination - Config - Inital version
**
**============================================================================*/

