/*
 * File: Mdl_Tacho.h
 *
 * Code generated for Simulink model 'Mdl_Tacho'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Aug 21 10:52:24 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Mdl_Tacho_h_
#define Mdl_Tacho_h_
#ifndef Mdl_Tacho_COMMON_INCLUDES_
#define Mdl_Tacho_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_Mdl_Tacho.h"
#endif                                 /* Mdl_Tacho_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes */
#include "Mdl_Tacho_config.cfg"
#include "Rte_Type.h"
#include "Rte_Mdl_Tacho.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define EQUIPPED_FLAG                  1U                        /* Referenced by: '<S23>/Truth Table' */
#define HV_NE                          2U                        /* Referenced by: '<S23>/Truth Table' */
#define N1                             3U                        /* Referenced by: '<Root>/Data Store Memory4' */
#define N2                             6U                        /* Referenced by: '<Root>/Data Store Memory3' */
#define NE1                            0U                        /* Referenced by: '<S23>/Truth Table' */
#define NE_AVG_INIT                    0U                        /* Referenced by:
                                                                  * '<Root>/Data Store Memory'
                                                                  * '<Root>/Data Store Memory1'
                                                                  */
#define NE_MET                         1U                        /* Referenced by: '<S23>/Truth Table' */
#define PTSYS_48V                      8U                        /* Referenced by: '<S5>/Tachometer_applicable_flag' */
#define PTSYS_CONV                     1U                        /* Referenced by: '<S5>/Tachometer_applicable_flag' */
#define PTSYS_DEFAULT                  0U                        /* Referenced by: '<S5>/Tachometer_applicable_flag' */
#define PTSYS_HV                       3U                        /* Referenced by: '<S5>/Tachometer_applicable_flag' */
#define PTSYS_MOTORHV                  6U                        /* Referenced by: '<S5>/Tachometer_applicable_flag' */
#define PTSYS_PHV                      4U                        /* Referenced by: '<S5>/Tachometer_applicable_flag' */
#define PTSYS_S_S                      2U                        /* Referenced by: '<S5>/Tachometer_applicable_flag' */
#define RZ_INIT_VAL                    52U                       /* Referenced by:
                                                                  * '<Root>/Data Store Memory8'
                                                                  * '<S16>/Constant11'
                                                                  * '<S46>/Constant10'
                                                                  */
#define SPD_THRESHOLD                  175U                      /* Referenced by: '<S27>/Constant' */
#define TACHO_COUNT_INIT               0U                        /* Referenced by:
                                                                  * '<Root>/Data Store Memory5'
                                                                  * '<S16>/Constant8'
                                                                  * '<S52>/Constant2'
                                                                  * '<S43>/Constant'
                                                                  */
#define TACHO_COUNT_INIT_U16           0U                        /* Referenced by: '<S20>/Constant' */
#define TACHO_COUNT_ONE                1U                        /* Referenced by: '<S42>/Constant' */
#define TACHO_COUNT_THREE_INT          3                         /* Referenced by: '<S44>/For Iterator' */
#define TACHO_COUNT_TWO                2U                        /* Referenced by: '<S41>/Constant1' */
#define TACHO_DEBOUNCE_TIME            120U                      /* Referenced by: '<S49>/Constant' */
#define TACHO_DISABLE                  FALSE                     /* Referenced by:
                                                                  * '<S5>/Tachometer_applicable_flag'
                                                                  * '<S10>/Constant'
                                                                  */
#define TACHO_ENABLE                   TRUE                      /* Referenced by: '<S5>/Tachometer_applicable_flag' */
#define TACHO_HYS_MAX                  6000U                     /* Referenced by: '<S32>/Constant2' */
#define TACHO_HYS_MIN                  10U                       /* Referenced by:
                                                                  * '<S34>/Constant1'
                                                                  * '<S34>/Constant2'
                                                                  * '<S36>/Constant2'
                                                                  * '<S37>/Constant2'
                                                                  */
#define TACHO_RESOLUTION               78125U                    /* Referenced by: '<S21>/Constant1' */
#define TACHO_RES_DIVIDER              10000U                    /* Referenced by: '<S21>/Constant2' */
#define TACHO_RPM_THRESHOLD            200U                      /* Referenced by:
                                                                  * '<S28>/Constant'
                                                                  * '<S32>/Constant'
                                                                  * '<S32>/Constant1'
                                                                  */
#define TACHO_TEN                      10U                       /* Referenced by:
                                                                  * '<S15>/Constant'
                                                                  * '<S15>/Constant1'
                                                                  * '<S15>/Constant2'
                                                                  * '<S15>/Constant5'
                                                                  * '<S15>/Constant8'
                                                                  * '<S47>/Constant12'
                                                                  * '<S47>/Constant13'
                                                                  * '<S47>/Constant14'
                                                                  * '<S47>/Constant15'
                                                                  * '<S47>/Constant16'
                                                                  */
#define TACHO_THRESHOLD                32768U                    /* Referenced by: '<S20>/Switch' */
#define TACHO_VAL_ONE                  1U                        /* Referenced by:
                                                                  * '<S45>/Constant'
                                                                  * '<S46>/Constant'
                                                                  */
#define TACHO_VAL_THREE                3U                        /* Referenced by: '<S44>/Constant' */
#define TACHO_VAL_ZERO                 0U                        /* Referenced by:
                                                                  * '<Root>/Data Store Memory7'
                                                                  * '<S16>/Constant4'
                                                                  */
#define TACHO_VAL_ZERO_U16             0U                        /* Referenced by:
                                                                  * '<Root>/Data Store Memory11'
                                                                  * '<S15>/Constant7'
                                                                  * '<S16>/Constant'
                                                                  * '<S16>/Constant1'
                                                                  * '<S16>/Constant10'
                                                                  * '<S16>/Constant2'
                                                                  * '<S16>/Constant3'
                                                                  * '<S16>/Constant7'
                                                                  */
#define TACHO_VAL_ZERO_U32             0U                        /* Referenced by:
                                                                  * '<Root>/Data Store Memory10'
                                                                  * '<S16>/Constant9'
                                                                  * '<S43>/Constant9'
                                                                  */
#define VAL_ONE                        1U                        /* Referenced by:
                                                                  * '<S13>/Constant'
                                                                  * '<S18>/Constant6'
                                                                  */
#define VAL_ZERO                       0U                        /* Referenced by:
                                                                  * '<Root>/Data Store Memory6'
                                                                  * '<S11>/Constant'
                                                                  */

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint32 fl_digital_odo_Sum;           /* '<Root>/Data Store Memory10' */
  uint16 NE_IN_ForDigitalTacho[3];     /* '<S40>/Assignment' */
  uint16 DataTypeConversion;           /* '<S5>/Data Type Conversion' */
  uint16 TmpSignalConversionAtrp_SPD_SP1;
  uint16 Divide;                       /* '<S44>/Divide' */
  uint16 Merge_a;                      /* '<S32>/Merge' */
  uint16 Switch;                       /* '<S21>/Switch' */
  uint16 Current_NE_AVG;               /* '<Root>/Data Store Memory' */
  uint16 Prev_NE_Out;                  /* '<Root>/Data Store Memory1' */
  uint16 DigitalTacho__Out;            /* '<Root>/Data Store Memory11' */
  uint16 N2_j;                         /* '<Root>/Data Store Memory3' */
  uint16 N1_i;                         /* '<Root>/Data Store Memory4' */
  uint8 RxCan_GetSignalValue_o2;       /* '<S6>/RxCan_GetSignalValue' */
  IgntionSubstateType TmpSignalConversionAtrpIgnSubst;
  uint8 DebounceIndex;                 /* '<S52>/DebounceIndex' */
  IgntionSubstateType PrevWUSIgnState; /* '<S14>/Unit Delay5' */
  uint8 NVM_MCUID0025;                 /* '<Root>/Data Store Memory7' */
  uint8 BURAM_RZ_MAX;                  /* '<Root>/Data Store Memory2' */
  uint8 DigtalTachoBuffIndex;          /* '<Root>/Data Store Memory5' */
  uint8 l_Tacho_init_MCUID;            /* '<Root>/Data Store Memory6' */
  uint8 RZ_ST;                         /* '<Root>/Data Store Memory8' */
  uint8 Battery_Connect_Flag;          /* '<Root>/Data Store Memory9' */
  boolean LogicalOperator11;           /* '<S14>/Logical Operator11' */
} ARID_DEF_Mdl_Tacho_T;

/* PublicStructure Variables for Internal Data */
extern VAR(ARID_DEF_Mdl_Tacho_T, Mdl_Tacho_VAR_INIT) Mdl_Tacho_ARID_DEF;

/* '<Root>/Data Store Memory10' */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S20>/Constant1' : Unused code path elimination
 * Block '<S20>/Constant2' : Unused code path elimination
 * Block '<S20>/Data Type Conversion' : Unused code path elimination
 * Block '<S20>/Switch1' : Unused code path elimination
 * Block '<S20>/Switch2' : Unused code path elimination
 * Block '<S21>/Display' : Unused code path elimination
 * Block '<S21>/Display2' : Unused code path elimination
 * Block '<S21>/Display3' : Unused code path elimination
 * Block '<S21>/Display4' : Unused code path elimination
 * Block '<S30>/Display' : Unused code path elimination
 * Block '<S31>/Display' : Unused code path elimination
 * Block '<S34>/Display' : Unused code path elimination
 * Block '<S34>/Display1' : Unused code path elimination
 * Block '<S24>/Display' : Unused code path elimination
 * Block '<S52>/Display' : Unused code path elimination
 * Block '<S52>/Display1' : Unused code path elimination
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'Mdl_Tacho'
 * '<S1>'   : 'Mdl_Tacho/Mdl_Tacho_Init'
 * '<S2>'   : 'Mdl_Tacho/Mdl_Tacho_Task_sys'
 * '<S3>'   : 'Mdl_Tacho/Mdl_Tacho_Task_sys/InputHarness'
 * '<S4>'   : 'Mdl_Tacho/Mdl_Tacho_Task_sys/OutputHarness'
 * '<S5>'   : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem'
 * '<S6>'   : 'Mdl_Tacho/Mdl_Tacho_Task_sys/InputHarness/CodeGeneration'
 * '<S7>'   : 'Mdl_Tacho/Mdl_Tacho_Task_sys/OutputHarness/CodeGeneration'
 * '<S8>'   : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/Compare To Constant'
 * '<S9>'   : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/Compare To Constant1'
 * '<S10>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/Compare To Constant2'
 * '<S11>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/Compare To Constant3'
 * '<S12>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/Compare To Constant4'
 * '<S13>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/Compare To Constant5'
 * '<S14>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/IGN_OFF_ON_Transition'
 * '<S15>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem'
 * '<S16>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem1'
 * '<S17>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/NE1_Missing_Notify'
 * '<S18>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/Subsystem'
 * '<S19>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/Tachometer_applicable_flag'
 * '<S20>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Accumulation_Processing'
 * '<S21>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation'
 * '<S22>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Compare To Constant'
 * '<S23>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Input_Determination'
 * '<S24>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Subsystem'
 * '<S25>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Accumulation_Processing/Compare To Constant'
 * '<S26>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Accumulation_Processing/Compare To Constant1'
 * '<S27>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation/Compare To Constant'
 * '<S28>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation/Compare To Constant1'
 * '<S29>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation/Compare To Constant2'
 * '<S30>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation/If Action Subsystem'
 * '<S31>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation/If Action Subsystem1'
 * '<S32>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation/Subsystem'
 * '<S33>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation/Subsystem/If Action Subsystem'
 * '<S34>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation/Subsystem/If Action Subsystem1'
 * '<S35>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation/Subsystem/If Action Subsystem2'
 * '<S36>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation/Subsystem/If Action Subsystem1/If Action Subsystem'
 * '<S37>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation/Subsystem/If Action Subsystem1/If Action Subsystem1'
 * '<S38>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Average_Calculation/Subsystem/If Action Subsystem1/If Action Subsystem2'
 * '<S39>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Input_Determination/Truth Table'
 * '<S40>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Subsystem/Subsystem'
 * '<S41>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Subsystem/Subsystem1'
 * '<S42>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Subsystem/Subsystem1/If Action Subsystem'
 * '<S43>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Subsystem/Subsystem1/If Action Subsystem1'
 * '<S44>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem/Subsystem/Subsystem1/If Action Subsystem1/For Iterator Subsystem'
 * '<S45>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem1/Compare To Constant3'
 * '<S46>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem1/Enabled Subsystem'
 * '<S47>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/If Action Subsystem1/Subsystem'
 * '<S48>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/NE1_Missing_Notify/Compare To Constant1'
 * '<S49>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/NE1_Missing_Notify/If Action Subsystem'
 * '<S50>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/NE1_Missing_Notify/If Action Subsystem1'
 * '<S51>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/NE1_Missing_Notify/If Action Subsystem/Compare To Constant'
 * '<S52>'  : 'Mdl_Tacho/Mdl_Tacho_Task_sys/Subsystem/NE1_Missing_Notify/If Action Subsystem/Debounce timer Subsystem'
 */
#endif                                 /* Mdl_Tacho_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
