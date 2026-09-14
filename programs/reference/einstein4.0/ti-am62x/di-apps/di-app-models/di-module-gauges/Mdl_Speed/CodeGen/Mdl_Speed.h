/*
 * File: Mdl_Speed.h
 *
 * Code generated for Simulink model 'Mdl_Speed'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jul  3 12:12:24 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Mdl_Speed_h_
#define Mdl_Speed_h_
#ifndef Mdl_Speed_COMMON_INCLUDES_
#define Mdl_Speed_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_Mdl_Speed.h"
#endif                                 /* Mdl_Speed_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes */
#include "Mdl_Digspeed_table_config.cfg"
#include "Rte_Type.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define AI_TEMP_ADC_COUNT_1586         1586U                     /* Referenced by: '<S13>/Speed_Update' */
#define AI_TEMP_ADC_COUNT_1727         1727U                     /* Referenced by: '<S13>/Speed_Update' */
#define AI_TEMP_ADC_COUNT_1792         1792U                     /* Referenced by: '<S13>/Speed_Update' */
#define AI_TEMP_ADC_COUNT_1891         1891U                     /* Referenced by: '<S13>/Speed_Update' */
#define CNVM_MCUID0262_DEFAULT_VAL     18000U                    /* Referenced by: '<Root>/Data Store Memory4' */
#define CNVM_MCUID0263_DEFAULT_VAL     16000U                    /* Referenced by: '<Root>/Data Store Memory44' */
#define C_ADR                          14U                       /* Referenced by: '<S12>/Truth Table' */
#define C_CANADA                       0U                        /* Referenced by:
                                                                  * '<S12>/Truth Table'
                                                                  * '<S13>/Speed_Update'
                                                                  */
#define C_EUROPE                       5U                        /* Referenced by: '<S12>/Truth Table' */
#define C_KOREA                        10U                       /* Referenced by: '<S12>/Truth Table' */
#define C_MEXICO                       2U                        /* Referenced by:
                                                                  * '<S12>/Truth Table'
                                                                  * '<S13>/Speed_Update'
                                                                  */
#define C_UK                           4U                        /* Referenced by: '<S12>/Truth Table' */
#define C_USA                          1U                        /* Referenced by:
                                                                  * '<S12>/Truth Table'
                                                                  * '<S13>/Speed_Update'
                                                                  */
#define MCUID0809                      1U                        /* Referenced by: '<S12>/Constant' */
#define MCUID0810                      1U                        /* Referenced by: '<S12>/Constant1' */
#define MIN_SPEED_VALUE                0U                        /* Referenced by: '<S7>/Constant1' */
#define RESOLUTION_VAL_100             100U                      /* Referenced by:
                                                                  * '<S21>/Constant2'
                                                                  * '<S21>/Constant3'
                                                                  * '<S22>/Constant'
                                                                  * '<S22>/Constant2'
                                                                  * '<S23>/Constant3'
                                                                  * '<S28>/Constant2'
                                                                  * '<S28>/Constant3'
                                                                  * '<S29>/Constant'
                                                                  * '<S29>/Constant2'
                                                                  * '<S31>/Constant2'
                                                                  * '<S24>/Constant2'
                                                                  * '<S25>/Constant2'
                                                                  * '<S26>/Constant2'
                                                                  * '<S27>/Constant2'
                                                                  * '<S32>/Constant2'
                                                                  * '<S33>/Constant2'
                                                                  * '<S34>/Constant2'
                                                                  * '<S35>/Constant2'
                                                                  */
#define RESOLUTION_VAL_103             103U                      /* Referenced by: '<S30>/Constant3' */
#define RESOLUTION_VAL_50              50U                       /* Referenced by:
                                                                  * '<S27>/Constant1'
                                                                  * '<S35>/Constant1'
                                                                  */
#define RESOLUTION_VAL_64              64U                       /* Referenced by: '<S30>/Constant4' */
#define RESOLUTION_VAL_MINUS_100       -100                      /* Referenced by:
                                                                  * '<S23>/Constant1'
                                                                  * '<S31>/Constant1'
                                                                  */
#define SPEED_CHECK_VALUE_ONE          1U                        /* Referenced by: '<S13>/Speed_Update' */
#define SPEED_UPDATE_0_28S             14U                       /* Referenced by: '<S13>/Speed_Update' */
#define SPEED_UPDATE_0_5S              25U                       /* Referenced by: '<S13>/Speed_Update' */
#define SPEED_UPDATE_1S                50U                       /* Referenced by: '<S13>/Speed_Update' */
#define SPEED_UPDATE_1_5S              75U                       /* Referenced by: '<S13>/Speed_Update' */
#define SPEED_ZERO                     0U                        /* Referenced by:
                                                                  * '<S6>/Constant'
                                                                  * '<S7>/Constant2'
                                                                  * '<S7>/Constant3'
                                                                  * '<S38>/Constant'
                                                                  * '<S39>/Constant1'
                                                                  * '<S39>/Constant2'
                                                                  */
#define VAL_ONE                        1U                        /* Referenced by:
                                                                  * '<Root>/Data Store Memory5'
                                                                  * '<S13>/Constant6'
                                                                  * '<S39>/Constant'
                                                                  * '<S25>/Constant1'
                                                                  * '<S33>/Constant1'
                                                                  */
#define VAL_ZERO                       0U                        /* Referenced by:
                                                                  * '<Root>/Data Store Memory2'
                                                                  * '<Root>/Data Store Memory6'
                                                                  * '<S6>/Constant1'
                                                                  */
#define eSP_ADR                        8U                        /* Referenced by:
                                                                  * '<S11>/Constant7'
                                                                  * '<S12>/Truth Table'
                                                                  */
#define eSP_CANADA                     0U                        /* Referenced by:
                                                                  * '<S11>/Constant2'
                                                                  * '<S12>/Truth Table'
                                                                  * '<S13>/Speed_Update'
                                                                  */
#define eSP_ECE                        9U                        /* Referenced by:
                                                                  * '<S11>/Constant8'
                                                                  * '<S12>/Truth Table'
                                                                  */
#define eSP_EUROPE                     5U                        /* Referenced by:
                                                                  * '<S11>/Constant5'
                                                                  * '<S12>/Truth Table'
                                                                  */
#define eSP_KOREA_FMVSS                6U                        /* Referenced by:
                                                                  * '<S11>/Constant1'
                                                                  * '<S12>/Truth Table'
                                                                  * '<S13>/Speed_Update'
                                                                  */
#define eSP_KOREA_UN_R                 7U                        /* Referenced by:
                                                                  * '<S11>/Constant9'
                                                                  * '<S12>/Truth Table'
                                                                  * '<S13>/Speed_Update'
                                                                  */
#define eSP_MEXICO_FMVSS               2U                        /* Referenced by:
                                                                  * '<S11>/Constant4'
                                                                  * '<S12>/Truth Table'
                                                                  * '<S13>/Speed_Update'
                                                                  */
#define eSP_MEXICO_UN_R                3U                        /* Referenced by:
                                                                  * '<S11>/Constant6'
                                                                  * '<S12>/Truth Table'
                                                                  * '<S13>/Speed_Update'
                                                                  */
#define eSP_UK                         4U                        /* Referenced by:
                                                                  * '<S11>/Constant3'
                                                                  * '<S12>/Truth Table'
                                                                  */
#define eSP_USA                        1U                        /* Referenced by:
                                                                  * '<S11>/Constant'
                                                                  * '<S12>/Truth Table'
                                                                  * '<S13>/Speed_Update'
                                                                  */

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint32 l_Speedin_Collect;            /* '<Root>/Data Store Memory' */
  uint16 DSpeed_Int_Ref_US_CAN_MAX[21];/* '<Root>/Data Store Memory10' */
  uint16 DSpeed_Int_Ref_Other[21];     /* '<Root>/Data Store Memory3' */
  uint16 pp_SPD_Target_Status_Spd_Target;
                           /* '<Root>/pp_SPD_Target_Status_Spd_Target_Status' */
  uint16 pp_SPD_Target2_Status_Spd_Targe;
                         /* '<Root>/pp_SPD_Target2_Status_Spd_Target2_Status' */
  uint16 Merge2_l;                     /* '<S11>/Merge2' */
  uint16 DataStoreRead;                /* '<S38>/Data Store Read' */
  uint16 Merge;                        /* '<S29>/Merge' */
  uint16 Merge_i;                      /* '<S22>/Merge' */
  uint16 LookupTableDynamic;           /* '<S36>/Lookup Table Dynamic' */
  uint16 Speed_index_count;            /* '<S39>/Unit Delay1' */
  uint16 Prev_speed_Int_km;            /* '<S23>/Unit Delay1' */
  uint16 Prev_speed_Int;               /* '<S31>/Unit Delay1' */
  uint16 Speedin_avg;                  /* '<Root>/Data Store Memory1' */
  uint16 MCUID0262;                    /* '<Root>/Data Store Memory4' */
  uint16 MCUID0263;                    /* '<Root>/Data Store Memory44' */
  uint8 l_Prev_Speed_Update_Time;      /* '<S39>/Unit Delay' */
  uint8 MCUID0809_l;                   /* '<Root>/Data Store Memory2' */
  uint8 MCUID0810_l;                   /* '<Root>/Data Store Memory5' */
  uint8 l_digital_speed_Init_MCU;      /* '<Root>/Data Store Memory6' */
} ARID_DEF_Mdl_Speed_T;

/* PublicStructure Variables for Internal Data */
extern VAR(ARID_DEF_Mdl_Speed_T, Mdl_Speed_VAR_INIT) Mdl_Speed_ARID_DEF;

/* '<Root>/Data Store Memory' */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Mdl_Speed'
 * '<S1>'   : 'Mdl_Speed/Mdl_Speed_Init'
 * '<S2>'   : 'Mdl_Speed/Mdl_Speed_Task_sys'
 * '<S3>'   : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed'
 * '<S4>'   : 'Mdl_Speed/Mdl_Speed_Task_sys/InputHarness'
 * '<S5>'   : 'Mdl_Speed/Mdl_Speed_Task_sys/OutputHarness'
 * '<S6>'   : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/If Action Subsystem'
 * '<S7>'   : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1'
 * '<S8>'   : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Compare To Constant'
 * '<S9>'   : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Compare To Constant4'
 * '<S10>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Compare To Constant5'
 * '<S11>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data'
 * '<S12>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/SpeedTable_Selection'
 * '<S13>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Speed_Update_Time_and_Avg_check'
 * '<S14>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/ADR_ECE'
 * '<S15>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/EUROPE_UK'
 * '<S16>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem'
 * '<S17>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem1'
 * '<S18>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/US_CAN_MAX'
 * '<S19>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/ADR_ECE/Subsystem'
 * '<S20>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/EUROPE_UK/Subsystem'
 * '<S21>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem/Speed_target_km'
 * '<S22>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem/Speed_trimming_KM'
 * '<S23>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem/speed_internal_km'
 * '<S24>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem/Speed_target_km/If Action Subsystem'
 * '<S25>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem/Speed_target_km/If Action Subsystem1'
 * '<S26>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem/Speed_trimming_KM/Speed_trim_Less_than_0.5'
 * '<S27>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem/Speed_trimming_KM/Speed_trim_greater_than_equal_to_0.5'
 * '<S28>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem1/Speed_target_Miles'
 * '<S29>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem1/Speed_trimming_Miles'
 * '<S30>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem1/kmtomiles_conversion1'
 * '<S31>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem1/speed_internal_Miles'
 * '<S32>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem1/Speed_target_Miles/If Action Subsystem'
 * '<S33>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem1/Speed_target_Miles/If Action Subsystem1'
 * '<S34>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem1/Speed_trimming_Miles/Speed_trim_Less_than_0.5'
 * '<S35>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/Subsystem1/Speed_trimming_Miles/Speed_trim_greater_than_equal_to_0.5'
 * '<S36>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Interpolation&Trim_data/US_CAN_MAX/Subsystem'
 * '<S37>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/SpeedTable_Selection/Truth Table'
 * '<S38>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Speed_Update_Time_and_Avg_check/Average_samples_km'
 * '<S39>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Speed_Update_Time_and_Avg_check/Gather_samples_km'
 * '<S40>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Speed_Update_Time_and_Avg_check/Speed_Update'
 * '<S41>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/Digital_speed/Subsystem1/Speed_Update_Time_and_Avg_check/Gather_samples_km/Compare To Constant'
 * '<S42>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/InputHarness/CodeGeneration'
 * '<S43>'  : 'Mdl_Speed/Mdl_Speed_Task_sys/OutputHarness/CodeGeneration'
 */
#endif                                 /* Mdl_Speed_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
