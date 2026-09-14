/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Adc_Types.h                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Database declaration.                                         */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  28-Aug-2012    : Initial Version
 *
 * V1.0.1:  30-Nov-2012    : As per SCR 043, the naming of CG unit is changed
 *                           to SG unit.
 *
 * V1.1.0:  16-Jan-2013    : As per SCR 064, in the Adc_ConfigType structure
 *                           new element 'pPwmDiagGroupConfig' is added.
 *
 * V1.2.0:  08-Mar-2013    : As per SCR 082 for Mantis #8153, In the
 *                           Adc_ConfigType structure new element
 *                           'pChannelToDisableEnable' and 'ucNoOfChannels' are
 *                           added.
 *
 * V1.2.1:  15-Apr-2013    : As per SCR 136 for Mantis #8153, In the
 *                           Adc_ConfigType structure new elements
 *                           'pPwmDiagIds' and 'pPwmDiagGroupRamData' are added.
 *
 * V1.3.0:  28-May-2013    : As per SCR 173 for mantis #11181 and #11415,
 *                           In the Adc_ConfigType structure new elements
 *                           pPwmTriggSrc and pResultGroupRamData
 *                           are added.
 *
 * V1.3.1:  14-Jun-2013    : As per SCR 182 for mantis #11991 and #11931,
 *                           1. The new element 'ucNoOfPwmDiagDmaChannels' is
 *                           added to structure 'Adc_ConfigType'.
 *                           2. Version Information section  is added.
 *
 * V1.4.0:  05-Jul-2013    : As per CR 211 for RS requirements, new
 *                           enumeration 'Adc_ProcessingModeType' is added.
 *
 * V1.4.1:  08-Aug-2013    : As per CR 225, Device name is updated as part of
 *                           merge activity.
 *
 * V1.4.2:  24-Sep-2013    : As per CR 246 and mantis #8421 and #14053,
 *                           following changes are made
 *                           1. New element 'pHwUnitIndex' is added to
 *                              structure'Adc_ConfigType'.
 *                           2. Adc_HwUnitType data type is added.
 *
 * V1.5.0:  06-Jan-2014    : As per CR 343 for mantis #16720 and #16722
 *                           following changes are made:
 *                           1. ADC_PRIORITY_SW is removed throughout the
 *                              file.
 *                           2. Enumeration Adc_ProcessingModeType is removed.
 *                           3. New enumeration Adc_FunctionalityModeType is
 *                              added to support the interrupt and pooling
 *                              functionality
 *                           4. Adc_HwUnitType is updated for lower version of
 *                              AUTOSAR
 *                           5. New elements pSgUnitConfig, pSgUnitIndex,
 *                              pSgUnitIndex, pChannelLimitCheck, pSgUnitRamData
 *                              and pPwmChannelCTDRVal are added.
 *                           6. Elements pPwmTriggSrc and pHwUnitRamData are
 *                              deleted.
 *
 * V1.6.0:  27-Feb-2014    : As per CR 449 and 450 for mantis #8421, #14053,
 *                           #19668 and #19509 following changes are made
 *                           1. New element 'pHwUnitIndex' is added to
 *                              structure'Adc_ConfigType'.
 *                           2. Adc_HwUnitType data type is added.
 *                           3. "Adc_ChannelRangeSelectType" is removed.
 *                           4. "Adc_ThresholdType" is added.
 *                           5. "pChannelLimitCheck" is removed for
 *                              "Adc_ConfigType"..
 *                           6. "pFlexibleChannelToGroup"
 *                              "pFlexibleLimitCheckRange" and "ucNoThresholds"
 *                              are added for
 *                              "Adc_ConfigType".
 *                           7. 'ADC_TYPES_SW_MINOR_VERSION' is updated.
 *
 * V1.7.0:  06-Jun-2014    : As per CR 499 for mantis #20739, new enumeration
 *                           'Adc_SelfDiagMode' is added.
 *
 * V1.7.1:  25-Jul-2014    : As per CR 563 the file is merged from P1x Variant.
 *
 * V1.7.2:  12-Dec-2014    : As per Mantis #23160, the Adc_ConfigType member
 *                           ucMinPwmDiagGroupId is renamed to
 *                           ucNoOfPwmDiagGroups.
 * V1.7.3:  10-Feb-2015    : As part of merge activity, following changes are
 *                           merged from P1x branch:
 *                           1. File is updated to correct the comment section.
 *                           2. "Adc_ChannelRangeSelectType" is removed.
 *                           3. "Adc_ConfigType" is updated to remove
 *                              "pChannelLimitCheck" element.
 *                           4. Copyright info updated.
 * V1.7.4:  20-Feb-2015    : As per mantis ticket #25449 following changes made:
 *                           1. Macro added for DMA selection,ADC_DMA_TYPE_TWO,
 *                              ADC_DMA_TYPE_ONE macro added.
 *                           2. ADC_TYPES_SW_MINOR_VERSION is updated.
 *
 * V1.7.5:  13-Aug-2015    : As per mantis #28091, new enumerations
 *                           'Adc_HardwareIndexType' and 'Adc_SamplingClockType'
 *                           are added.
 *
 * V1.7.6:  27-Oct-2015    : As part of JIRA ARDAAAB-1929 added types
 *                           Adc_PWSAReturnType and Adc_PWSARegisterType
 *
 * V1.8.0:  08-Feb-2016    : 1. As part JIRA ticket ARDAAAC-447, ARDAAAA-525,
 *                              and ARDAAAB-3226, Storage Specifier for
 *                              Configuration Data variables is changed from
 *                              AUTOMATIC to TYPEDEF, since it is allocated in
 *                              ROM.
 *                           2. Copy right information is updated.
 *                           3. As per JIRA ARDAAAC-467, ARDAAAA-543,
 *                              ARDAAAB-3463 and ARDAAAC-396
 *                              Type definition for Adc_HWConsistencyModeType
 *                              and Adc_HWConsistencyReturnType are added.
 *                           4. ADC_TYPES_SW_MINOR_VERSION is updated.
 * V1.8.1: 27-Sep-2016    : Following changes are made:
 *                          1. Macros updated to add integer literals as per
 *                             JIRA ARDAAAB-3680, ARDAAAA-945, ARDAAAC-856.
 *                          2.Traceability to UD IDs and requirements is added.
 * V1.8.2:  07-Feb-2017   : 1. As part of JIRA ARDAABL-709, Traceability to
 *                             requirements and design is added.
 *                          2. Copyright information is updated.
 */
/******************************************************************************/
/* Implements EAAR_PN0034_FR_0001, EAAR_PN0034_NR_0001 */
#ifndef ADC_TYPES_H
#define ADC_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for pre-compile options */
#include "Adc_Cfg.h"
/* AUTOSAR standard types */
#include "Std_Types.h"


/*******************************************************************************
**      To support different AUTOSAR releases in a single package             **
*******************************************************************************/
#define ADC_AR_FOUR_ZERO_THREE    403U
#define ADC_AR_THREE_TWO_TWO      322U

#define ADC_AR_HIGHER_VERSION     ADC_AR_FOUR_ZERO_THREE
#define ADC_AR_LOWER_VERSION      ADC_AR_THREE_TWO_TWO
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (ADC_AR_VERSION  == ADC_AR_HIGHER_VERSION)
/* AUTOSAR Release version information */
#define ADC_TYPES_AR_RELEASE_MAJOR_VERSION       4U
#define ADC_TYPES_AR_RELEASE_MINOR_VERSION       0U
#define ADC_TYPES_AR_RELEASE_REVISION_VERSION    3U
#elif (ADC_AR_VERSION  == ADC_AR_LOWER_VERSION)
/* AUTOSAR specification version information */
#define ADC_TYPES_AR_MAJOR_VERSION   3U
#define ADC_TYPES_AR_MINOR_VERSION   0U
#define ADC_TYPES_AR_PATCH_VERSION   3U
#endif
/* Module Software version information */
#define ADC_TYPES_SW_MAJOR_VERSION   1U
#define ADC_TYPES_SW_MINOR_VERSION   9U

/******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Priority Implementation values                        **
*******************************************************************************/
/* Implements ADC_ESDD_UD_117, AR_PN0076_FR_0249, AR_PN0076_FR_0054  */
#define ADC_PRIORITY_NONE     0U
#define ADC_PRIORITY_HW       1U
#define ADC_PRIORITY_HW_SW    2U

/* DMA */
/* Implements ADC_ESDD_UD_048 */
#define ADC_DMA_TYPE_ONE 0x01U
#define ADC_DMA_TYPE_TWO 0x02U

/* Numeric identifier of an ADC channel */
/* Implementation ADC_ESDD_UD_088 */
typedef uint8 Adc_ChannelType;

/* Numeric identifier of channel resolution in number of bits */
/* Implements ADC_ESDD_UD_120 */
typedef uint8 Adc_ResolutionType;

/* Numeric identifier of an ADC channel group */
typedef uint8 Adc_GroupType;

/* Type definition for Adc_HWConsistencyModeType */
/* Implements ADC_ESDD_UD_153 */
typedef enum ETag_Adc_HWConsistencyModeType
{
  ADC_STATIC = 0,
  ADC_DYNAMIC
}Adc_HWConsistencyModeType;

/* Implements ADC_ESDD_UD_173 */
/* Type definition for Adc_HWConsistencyReturnType */
typedef uint8 Adc_HWConsistencyReturnType;

#if (ADC_ADCA == STD_OFF)
/* Numeric identifier of an ADC Scan group */
typedef uint8 Adc_ScanGroupType;
#endif
/* Adc converted value type */
/* Implements ADC_ESDD_UD_128 */
typedef uint16 Adc_ValueGroupType;

/* Adc HW Trigger Timer type */
/* Implements ADC_ESDD_UD_132 */
typedef uint8 Adc_HwTriggerTimerType;

/* Number of samples of the streaming buffer group */
/* Implements ADC_ESDD_UD_123 */
typedef uint8 Adc_StreamNumSampleType;

#if ( ADC_ADCA == STD_ON )
/* Implements ADC_ESDD_UD_220 */
/* ADC Virtual Channel Register type for F1x and R1x*/
typedef uint16 AdcVirChRegisters;
#else
/* ADC Virtual Channel Register type for P1x and E1x*/
typedef uint32 AdcVirChRegisters;
#endif

#if ( ADC_ADCA == STD_ON )
/* Implements ADC_ESDD_UD_219 */
/* Adc Threshold Category type */
typedef uint8 Adc_ThresholdType;
/* Implements ADC_ESDD_UD_221 */
/* Adc Threshold Category type */
typedef uint32 Adc_AddressType;
#endif

/* Implements ADC_ESDD_UD_212, ADC_ESDD_UD_151, ADC_ESDD_UD_152 */
#if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
typedef uint32 Adc_PWSARegisterType;
typedef uint16 Adc_PWSAReturnType;
#endif

/* Current status of the conversion of the requested ADC Channel group */
/* Implements ADC_ESDD_UD_129 */
typedef enum ETag_Adc_StatusType
{
  ADC_IDLE,
  ADC_BUSY,
  ADC_COMPLETED,
  ADC_STREAM_COMPLETED
} Adc_StatusType;

/* Type for configuring the trigger source for an ADC Channel group */
/* Implements ADC_ESDD_UD_121 */
typedef enum ETag_Adc_TriggerSourceType
{
  ADC_TRIGG_SRC_SW,
  ADC_TRIGG_SRC_HW
} Adc_TriggerSourceType;

/* Type for configuring the conversion mode of an ADC Channel group */
/* Implements ADC_ESDD_UD_133 */
typedef enum ETag_Adc_GroupConvModeType
{
  ADC_CONV_MODE_ONESHOT,
  ADC_CONV_MODE_CONTINUOUS
} Adc_GroupConvModeType;

/* Type for configuring the streaming access mode buffer type. */
/* Implements ADC_ESDD_UD_124 */
typedef enum ETag_Adc_StreamBufferModeType
{
  ADC_STREAM_BUFFER_LINEAR,
  ADC_STREAM_BUFFER_CIRCULAR
} Adc_StreamBufferModeType;

/* Type for configuring the access mode to group conversion results */
/* Implements ADC_ESDD_UD_125 */
typedef enum ETag_Adc_GroupAccessModeType
{
  ADC_ACCESS_MODE_SINGLE,
  ADC_ACCESS_MODE_STREAMING
} Adc_GroupAccessModeType;

/* Type for replacement mechanism, which is used on ADC group level */
/* Implements ADC_ESDD_UD_118 */
typedef enum ETag_Adc_GroupReplacementType
{
  ADC_GROUP_REPL_ABORT_RESTART,
  ADC_GROUP_REPL_SUSPEND_RESUME
} Adc_GroupReplacementType;

/* Type for configuring on which edge of the hardware trigger signal the
 * driver should reach, i.e. start the conversion
 */
 /* Implements ADC_ESDD_UD_126 */
typedef enum ETag_Adc_HwTriggerSignalType
{
  ADC_HW_TRIG_RISING_EDGE,
  ADC_HW_TRIG_FALLING_EDGE,
  ADC_HW_TRIG_BOTH_EDGES
} Adc_HwTriggerSignalType;

/* Type for configuring the result data alignment */
/* Implements ADC_ESDD_UD_127 */
typedef enum ETag_Adc_ResultAlignmentType
{
  ADC_ALIGN_LEFT,
  ADC_ALIGN_RIGHT
} Adc_ResultAlignmentType;

/* Type of processing mode of the HW unit */
/* Implements ADC_ESDD_UD_131 */
typedef enum ETag_Adc_FunctionalityModeType
{
  ADC_INTERRUPT_MODE,
  ADC_POLLING_MODE,
  ADC_POLLING_INTERRUPT_MODE
} Adc_FunctionalityModeType;

#if ( ADC_ADCA == STD_ON )
/* Type for configuring the Self Diag for F1x and R1x. */
/* Implements ADC_ESDD_UD_130, AR_PN0076_FR_0210,  AR_PN0076_FSR_0004 */
/* Implements AR_PN0076_FSR_0006, AR_PN0076_FSR_0005, AR_PN0076_FSR_0001 */
typedef enum ETag_Adc_SelfDiagMode
{
  ADC_SELF_DIAG_OFF,
  ADC_SELF_DIAG_CONV_CKT,
  ADC_SELF_DIAG_CH_MUX,
  ADC_SELF_DIAG_OPEN_PIN
} Adc_SelfDiagMode;
#else
/* Type for configuring the Self Diag for P1x and E1x. */
typedef enum ETag_Adc_SelfDiagModetype
{
  ADC_SELF_DIAG_OFF,
  ADC_SELF_DIAG_PIN_LVL,
  ADC_SELF_DIAG_CONV_CKT,
  ADC_SELF_DIAG_WIRE_BRK
} Adc_SelfDiagModeType;
#endif

/* Priority level of the channel. Lowest priority is 0 */
/* Implements ADC_ESDD_UD_122 */
typedef uint8 Adc_GroupPriorityType;

#if (ADC_AR_VERSION  == ADC_AR_LOWER_VERSION)
/* Numeric ID of an ADC Hw Unit. */
/* Implements ADC_ESDD_UD_213 */
typedef uint8 Adc_HwUnitType;
#endif
/* Implements ADC_ESDD_UD_217 */
/* Type of the hardware unit */
typedef enum ETag_Adc_HardwareIndexType
{
  ADC_HW_ADCA0,
  ADC_HW_ADCA1
} Adc_HardwareIndexType;
/* Data Structure required for initializing the ADC unit */
/* Implements ADC_ESDD_UD_104 */
typedef struct STag_Adc_ConfigType
{
  /* Database start value - ADC_DBTOC_VALUE */
  uint32 ulStartOfDbToc;
  /* Pointer to ADC hardware unit configuration */
  /* Implements ADC_ESDD_UD_104, ADC_ESDD_UD_089 */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pHWUnitConfig;
  /* Pointer to ADC SG unit configuration */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pSgUnitConfig;
  /* Pointer to ADC group configuration */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pGroupConfig;
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Pointer to ADC PWM diagnostic group configuration */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pPwmDiagGroupConfig;
  /* Pointer to ADC PWM diagnostic group Trigger Source Ids */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pPwmDiagIds;
  #endif
  #if (ADC_HW_TRIGGER_API == STD_ON)
  /* Pointer to ADC HW trigger values */
/* Implements ADC_ESDD_UD_104 */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pGroupHWTrigg;
  #if (ADC_ADCA == STD_OFF)
  /* Pointer to ADC SG trigger values */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pGroupSGTrigg;
  #endif
  #endif
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* Pointer to Limit check range values */
  P2CONST(void, TYPEDEF, ADC_CONFIG_CONST) pLimitCheckRange;
  #endif
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /* Pointer to DMA  data */
  P2CONST(void, TYPEDEF, ADC_CONFIG_DATA) pDmaUnitConfig;
  /* Pointer to DMA HW unit array mapping */
  P2CONST(void, TYPEDEF, ADC_CONFIG_DATA) pDmaHWUnitMapping;
  /* Pointer to DMA SGm unit array mapping */
  P2CONST(void, TYPEDEF, ADC_CONFIG_DATA) pDmaSGUnitMapping;
  #endif /* #if (ADC_DMA_MODE_ENABLE == STD_ON) */
  /* Pointer to Adc_GaaChannelToGroup[] array */
  P2CONST(void, TYPEDEF, ADC_CONFIG_DATA) pChannelToGroup;
  /* Pointer to Hardware Index Mapping array */
  P2CONST(void, TYPEDEF, ADC_CONFIG_DATA) pHwUnitIndex;
  #if (ADC_ADCA == STD_ON)
  /* Pointer to SG unit Index Mapping array */
  P2CONST(void, TYPEDEF, ADC_CONFIG_DATA) pSgUnitIndex;
  #endif
  /* Pointer to channel group ram data */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pGroupRamData;
  /* Pointer to SG Unit ram data */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pSgUnitRamData;
  /* Pointer to Runtime data */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pRunTimeData;
  #if (ADC_ENABLE_DISABLE_CHANNEL == STD_ON)
  /* Pointer to Adc_GaaChannelToDisableEnable[] array */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pChannelToDisableEnable;
  #endif
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /* Pointer to PWM Diagnostic group Runtime data */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pPwmDiagGroupRamData;
  /* Pointer to RAM of CTDR array */
  P2VAR(uint16, TYPEDEF, ADC_CONFIG_DATA) pPwmChannelCTDRVal;
  #endif
  /* Implements ADC_ESDD_UD_068 */
  #if (ADC_ENABLE_BUFFER_ALLOCATION == STD_ON)
  /* Pointer to the RAM allocation for result data*/
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pResultGroupRamData;
  #endif
  /* Implements ADC_ESDD_UD_183 */
  #if ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  /* Pointer to Adc_GaaFlexibleChannelToGroup[] array */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pFlexibleChannelToGroup;
  #endif
  #if ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  /* Pointer to Adc_GaaLimitCheckRange[] array */
  P2VAR(void, TYPEDEF, ADC_CONFIG_DATA) pFlexibleLimitCheckRange;
  #endif
  /*
   * Max number of SW triggered groups configured in corresponding
   * configuration
   */
  uint8 ucMaxSwTriggGroups;
  uint8 ucNoOfGroups;
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /*
   * Generate the group Id of the least PWM diagnostic group configured in this
   * configuration set. In case if there are no PWM diagnostic group then the
   * value of this parameter should be equal to ADC_MAX_GROUPS
   */
  uint8 ucNoOfPwmDiagGroups;
  #endif
  /* Implements ADC_ESDD_UD_185 */
  #if (ADC_DMA_MODE_ENABLE == STD_ON)
  /*
   * Max number of DMA channel Ids configured in corresponding
   * configuration
   */
  uint8 ucMaxDmaChannels;
  /* Implements ADC_ESDD_UD_212 */
  #if (ADC_ENABLE_DIAGNOSTIC_SUPPORT == STD_ON)
  /*
   * No of DMA channel Ids configured for PWM Diagnostic.
   */
  uint8 ucNoOfPwmDiagDmaChannels;
  #endif
  #endif
  #if ((ADC_ENABLE_DISABLE_CHANNEL == STD_ON) || \
                 ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && \
                                            (ADC_ENABLE_LIMIT_CHECK == STD_ON)))
  /* No of channels configured in this configuration */
  uint8 ucNoOfChannels;
  #endif
  #if ((ADC_FLEXIBLE_THRESHOLD == STD_ON) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  uint8 ucNoThresholds;
  #endif
} Adc_ConfigType;

/* Type of sampling clock */
/* Implements ADC_ESDD_UD_218 */
typedef enum ETag_Adc_SamplingClockType
{
  ADC_SCLK_18,
  ADC_SCLK_24
} Adc_SamplingClockType;
#endif /* ADC_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
