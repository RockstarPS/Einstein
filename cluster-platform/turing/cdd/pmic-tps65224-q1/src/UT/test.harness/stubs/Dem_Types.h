/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2017. Visteon Corporation owns all rights to           *
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
 *  File Name         :  Dem_Types.h                                          *
 *  Module Short Name :  ErrMgr                                               *
 *  VOBName           :                                                       *
 *  Author            : msavariy                                              *
 *  Description       : This file contains the Diagnostics request and        *
 *                       response handling functionlities.                    *
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
#ifndef DEM_TYPES_H
#define DEM_TYPES_H

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Std_Types.h"
#include "Rte_Dem_Type.h"

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

#ifndef Rte_TypeDef_Dem_ComponentIdType
  typedef uint16 Dem_ComponentIdType;
#endif

/* test */
typedef uint8 Dem_ConfigType;

#ifndef Rte_TypeDef_Dem_EventIdType
typedef uint16 Dem_EventIdType;
#endif

/************************* Dem_EventStatusType ******************************/
#ifndef Rte_TypeDef_Dem_EventStatusType
typedef uint8 Dem_EventStatusType;
#endif

#ifndef DEM_EVENT_STATUS_PASSED
#define DEM_EVENT_STATUS_PASSED                 0x00U
#endif
#ifndef  DEM_EVENT_STATUS_FAILED
#define DEM_EVENT_STATUS_FAILED                 0x01U
#endif
#ifndef  DEM_EVENT_STATUS_PREPASSED
#define DEM_EVENT_STATUS_PREPASSED              0x02U
#endif
#ifndef  DEM_EVENT_STATUS_PREFAILED
#define DEM_EVENT_STATUS_PREFAILED              0x03U
#endif

/****************************************************************************/

/*************************** Dem_DebouncingStateType *************************/

#ifndef Rte_TypeDef_Dem_DebouncingStateType
typedef uint8 Dem_DebouncingStateType;
#endif

#ifndef  DEM_TEMPORARILY_DEFECTIVE
#define DEM_TEMPORARILY_DEFECTIVE      0x01U
#endif
#ifndef  DEM_FINALLY_DEFECTIVE
#define DEM_FINALLY_DEFECTIVE          0x02U
#endif
#ifndef  DEM_TEMPORARILY_HEALED
#define DEM_TEMPORARILY_HEALED         0x04U
#endif
#ifndef  DEM_TEST_COMPLETE
#define DEM_TEST_COMPLETE              0x08U
#endif
#ifndef  DEM_DTR_UPDATE
#define DEM_DTR_UPDATE                 0x10U
#endif

/****************************************************************************/

/*************************** Dem_DebounceResetStatusType *********************/

#ifndef Rte_TypeDef_Dem_DebounceResetStatusType
typedef uint8 Dem_DebounceResetStatusType;
#endif

#ifndef  DEM_DEBOUNCE_STATUS_FREEZE
#define DEM_DEBOUNCE_STATUS_FREEZE     (0x0U)
#endif
#ifndef  DEM_DEBOUNCE_STATUS_RESET
#define DEM_DEBOUNCE_STATUS_RESET      (0x01U)
#endif

/***  Dem Event Kind ***/

#ifndef DEM_CFG_EVENT_KIND_BSW
#define DEM_CFG_EVENT_KIND_BSW      (0x0U)
#endif
#ifndef DEM_CFG_EVENT_KIND_SWC
#define DEM_CFG_EVENT_KIND_SWC      (0x1U)
#endif

/*** Dem Debounce class  ***/
#ifndef DEM_CFG_DEBOUNCETYPE_COUNTER
#define DEM_CFG_DEBOUNCETYPE_COUNTER    (0x0U)
#endif
#ifndef DEM_CFG_DEBOUNCETYPE_TIMER
#define DEM_CFG_DEBOUNCETYPE_TIMER      (0x1U)
#endif
#ifndef DEM_CFG_DEBOUNCETYPE_EXTERNAL
#define DEM_CFG_DEBOUNCETYPE_EXTERNAL   (0x2U)
#endif
#ifndef DEM_CFG_DEBOUNCETYPE_INVALID
#define DEM_CFG_DEBOUNCETYPE_INVALID    (0x3U)
#endif

#ifndef DEM_DEBOUNCE_FREEZE
#define DEM_DEBOUNCE_FREEZE             (0x0U)
#endif
#ifndef DEM_DEBOUNCE_RESET
#define DEM_DEBOUNCE_RESET              (0x1U)
#endif

/****************************************************************************/

/*************************** Dem_UdsStatusByteType *************************/

#ifndef Rte_TypeDef_Dem_UdsStatusByteType
typedef uint8 Dem_UdsStatusByteType;
#endif

#ifndef   DEM_UDS_STATUS_TF
#define  DEM_UDS_STATUS_TF        (0x01U)
#endif
#ifndef   DEM_UDS_STATUS_TFTOC
#define  DEM_UDS_STATUS_TFTOC     (0x02U)
#endif
#ifndef   DEM_UDS_STATUS_PDTC
#define  DEM_UDS_STATUS_PDTC      (0x04U)
#endif
#ifndef   DEM_UDS_STATUS_CDTC
#define  DEM_UDS_STATUS_CDTC      (0x08U)
#endif
#ifndef   DEM_UDS_STATUS_TNCSLC
#define  DEM_UDS_STATUS_TNCSLC    (0x10U)
#endif
#ifndef   DEM_UDS_STATUS_TFSLC
#define  DEM_UDS_STATUS_TFSLC     (0x20U)
#endif
#ifndef   DEM_UDS_STATUS_TNCTOC
#define  DEM_UDS_STATUS_TNCTOC    (0x40U)
#endif
#ifndef   DEM_UDS_STATUS_WIR
#define  DEM_UDS_STATUS_WIR       (0x80U)
#endif

/****************************************************************************/

/*************************** Dem_OperationCycleStateType *********************/

#ifndef Rte_TypeDef_Dem_OperationCycleStateType
typedef uint8 Dem_OperationCycleStateType;
#endif

#ifndef   DEM_CYCLE_STATE_START
#define  DEM_CYCLE_STATE_START     (0x0U)
#endif
#ifndef   DEM_CYCLE_STATE_END
#define  DEM_CYCLE_STATE_END       (0x01U)
#endif

/****************************************************************************/

/*************************** Dem_IndicatorStatusType *************************/

#ifndef Rte_TypeDef_Dem_IndicatorStatusType
typedef uint8 Dem_IndicatorStatusType;
#endif

#ifndef  DEM_INDICATOR_OFF
#define DEM_INDICATOR_OFF              (0x00U)
#endif
#ifndef  DEM_INDICATOR_CONTINUOUS
#define DEM_INDICATOR_CONTINUOUS       (0x01U)
#endif
#ifndef  DEM_INDICATOR_BLINKING
#define DEM_INDICATOR_BLINKING         (0x02U)
#endif
#ifndef  DEM_INDICATOR_BLINK_CONT
#define DEM_INDICATOR_BLINK_CONT      (0x03U)
#endif
#ifndef  DEM_INDICATOR_SLOW_FLASH
#define DEM_INDICATOR_SLOW_FLASH       (0x04U)
#endif
#ifndef  DEM_INDICATOR_FAST_FLASH
#define DEM_INDICATOR_FAST_FLASH       (0x05U)
#endif
#ifndef  DEM_INDICATOR_ON_DEMAND
#define DEM_INDICATOR_ON_DEMAND        (0x06U)
#endif
#ifndef  DEM_INDICATOR_SHORT
#define DEM_INDICATOR_SHORT            (0x07U)
#endif

/****************************************************************************/

/*************************** Dem_DTCKindType *************************/

#ifndef Rte_TypeDef_Dem_DTCKindType
typedef uint8 Dem_DTCKindType;
#endif

#ifndef  DEM_DTC_KIND_ALL_DTCS
#define DEM_DTC_KIND_ALL_DTCS  (0x01U)
#endif
#ifndef  DEM_DTC_KIND_EMISSION_REL_DTCS
#define DEM_DTC_KIND_EMISSION_REL_DTCS  (0x02U)
#endif

/****************************************************************************/

/*************************** Dem_DTCFormatType *************************/

#ifndef Rte_TypeDef_Dem_DTCFormatType
typedef uint8 Dem_DTCFormatType;
#endif

#ifndef DEM_DTC_FORMAT_OBD
#define DEM_DTC_FORMAT_OBD     (0x00U)
#endif
#ifndef DEM_DTC_FORMAT_UDS
#define DEM_DTC_FORMAT_UDS     (0x01U)
#endif
#ifndef DEM_DTC_FORMAT_J1939
#define DEM_DTC_FORMAT_J1939   (0x02U)
#endif

/****************************************************************************/

/*************************** Dem_DTCOriginType *************************/

#ifndef Rte_TypeDef_Dem_DTCOriginType
typedef uint8 Dem_DTCOriginType;
#endif

#ifndef DEM_DTC_ORIGIN_PRIMARY_MEMORY
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY     (0x01U)
#endif
#ifndef DEM_DTC_ORIGIN_MIRROR_MEMORY
#define DEM_DTC_ORIGIN_MIRROR_MEMORY     (0x02U)
#endif
#ifndef DEM_DTC_ORIGIN_PERMANENT_MEMORY
#define DEM_DTC_ORIGIN_PERMANENT_MEMORY   (0x03U)
#endif
#ifndef DEM_DTC_ORIGIN_SECONDARY_MEMORY
#define DEM_DTC_ORIGIN_SECONDARY_MEMORY (0x04U)
#endif
#ifndef DEM_DTC_ORIGIN_INVALID_MEMORY
#define DEM_DTC_ORIGIN_INVALID_MEMORY (0x05U)
#endif

/****************************************************************************/

/*************************** Dem_DTCRequestType *************************/

#ifndef Rte_TypeDef_Dem_DTCRequestType
typedef uint8 Dem_DTCRequestType;
#endif

#ifndef  DEM_FIRST_FAILED_DTC
#define DEM_FIRST_FAILED_DTC       (0x01U)
#endif
#ifndef  DEM_MOST_RECENT_FAILED_DTC
#define DEM_MOST_RECENT_FAILED_DTC         (0x02U)
#endif
#ifndef  DEM_FIRST_DET_CONFIRMED_DTC
#define DEM_FIRST_DET_CONFIRMED_DTC      (0x03U)
#endif
#ifndef  DEM_MOST_REC_DET_CONFIRMED_DTC
#define DEM_MOST_REC_DET_CONFIRMED_DTC       (0x04U)
#endif

/****************************************************************************/

/*************************** Dem_DTCTranslationFormatType *******************/

#ifndef Rte_TypeDef_Dem_DTCTranslationFormatType
typedef uint8 Dem_DTCTranslationFormatType;
#endif

#ifndef  DEM_DTC_TRANSLATION_ISO15031_6
#define DEM_DTC_TRANSLATION_ISO15031_6       (0x00U)
#endif
#ifndef  DEM_DTC_TRANSLATION_ISO14229_1
#define DEM_DTC_TRANSLATION_ISO14229_1       (0x01U)
#endif
#ifndef  DEM_DTC_TRANSLATION_SAEJ1939_73
#define DEM_DTC_TRANSLATION_SAEJ1939_73      (0x02U)
#endif
#ifndef  DEM_DTC_TRANSLATION_ISO11992_4
#define DEM_DTC_TRANSLATION_ISO11992_4      (0x03U)
#endif
#ifndef  DEM_DTC_TRANSLATION_J2012DA_FORMAT_04
#define DEM_DTC_TRANSLATION_J2012DA_FORMAT_04       (0x04U)
#endif

/****************************************************************************/

/***************************  *************************/

#ifndef Rte_TypeDef_Dem_DTCSeverityType
typedef uint8 Dem_DTCSeverityType;
#endif

#ifndef  DEM_SEVERITY_NO_SEVERITY
#define DEM_SEVERITY_NO_SEVERITY              (0x00U)
#endif
#ifndef  DEM_SEVERITY_WWHOBD_CLASS_NO_CLASS
#define DEM_SEVERITY_WWHOBD_CLASS_NO_CLASS    (0x01U)
#endif
#ifndef  DEM_SEVERITY_WWHOBD_CLASS_A
#define DEM_SEVERITY_WWHOBD_CLASS_A           (0x02U)
#endif
#ifndef  DEM_SEVERITY_WWHOBD_CLASS_B1
#define DEM_SEVERITY_WWHOBD_CLASS_B1          (0x04U)
#endif
#ifndef  DEM_SEVERITY_WWHOBD_CLASS_B2
#define DEM_SEVERITY_WWHOBD_CLASS_B2          (0x08U)
#endif
#ifndef  DEM_SEVERITY_WWHOBD_CLASS_C
#define DEM_SEVERITY_WWHOBD_CLASS_C           (0x10U)
#endif
#ifndef  DEM_SEVERITY_MAINTENANCE_ONLY
#define DEM_SEVERITY_MAINTENANCE_ONLY         (0x20U)
#endif
#ifndef  DEM_SEVERITY_CHECK_AT_NEXT_HALT
#define DEM_SEVERITY_CHECK_AT_NEXT_HALT       (0x40U)
#endif
#ifndef  DEM_SEVERITY_CHECK_IMMEDIATELY
#define DEM_SEVERITY_CHECK_IMMEDIATELY        (0x80U)
#endif

#ifndef  DEM_SEVERITY_DTC_CLASS_MASK
#define DEM_SEVERITY_DTC_CLASS_MASK           (0x1FU)
#endif

/****************************************************************************/

/***************************  *************************/

#ifndef Rte_TypeDef_Dem_DTRControlType
typedef uint8 Dem_DTRControlType;
#endif

#ifndef  DEM_DTR_CTL_NORMAL
#define DEM_DTR_CTL_NORMAL    (0x00U)
#endif
#ifndef  DEM_DTR_CTL_NO_MAX
#define DEM_DTR_CTL_NO_MAX    (0x01U)
#endif
#ifndef  DTR_CTL_NO_MIN
#define DTR_CTL_NO_MIN        (0x02U)
#endif
#ifndef DEM_DTR_CTL_RESET
#define DEM_DTR_CTL_RESET     (0x03U)
#endif
#ifndef DTR_CTL_INVISIBLE
#define DTR_CTL_INVISIBLE     (0x04U)
#endif

/****************************************************************************/

/*************************** Dem_InitMonitorReasonType************************/

#ifndef Rte_TypeDef_Dem_InitMonitorReasonType
typedef uint8 Dem_InitMonitorReasonType;
#endif

#ifndef  DEM_INIT_MONITOR_CLEAR
#define DEM_INIT_MONITOR_CLEAR    (0x01U)
#endif
#ifndef  DEM_INIT_MONITOR_RESTART
#define DEM_INIT_MONITOR_RESTART    (0x02U)
#endif
#ifndef  DEM_INIT_MONITOR_REENABLED
#define DEM_INIT_MONITOR_REENABLED        (0x03U)
#endif
#ifndef DEM_INIT_MONITOR_STORAGE_REENABLED
#define DEM_INIT_MONITOR_STORAGE_REENABLED     (0x04U)
#endif

/****************************************************************************/

/*******   Dem return types  ***************/

/*************************** Dem_ReturnGetStatusOfDTCType*********************/

#ifndef Rte_TypeDef_Dem_ReturnGetStatusOfDTCType
typedef uint8 Dem_ReturnGetStatusOfDTCType;
#endif

#ifndef  DEM_STATUS_OK
#define DEM_STATUS_OK    (0x00U)
#endif
#ifndef  DEM_STATUS_WRONG_DTC
#define DEM_STATUS_WRONG_DTC    (0x01U)
#endif
#ifndef  DEM_STATUS_WRONG_DTCORIGIN
#define DEM_STATUS_WRONG_DTCORIGIN        (0x02U)
#endif
#ifndef DEM_STATUS_FAILED
#define DEM_STATUS_FAILED     (0x03U)
#endif
#ifndef DEM_STATUS_PENDING
#define DEM_STATUS_PENDING     (0x04U)
#endif

/****************************************************************************/

/*************************** Dem_ReturnGetSeverityOfDTCType *****************/

#ifndef Rte_TypeDef_Dem_ReturnGetSeverityOfDTCType
typedef uint8 Dem_ReturnGetSeverityOfDTCType;
#endif

#ifndef  DEM_GET_SEVERITYOFDTC_OK
#define DEM_GET_SEVERITYOFDTC_OK    (0x00U)
#endif
#ifndef  DEM_GET_SEVERITYOFDTC_WRONG_DTC
#define DEM_GET_SEVERITYOFDTC_WRONG_DTC    (0x01U)
#endif
#ifndef  DEM_GET_SEVERITYOFDTC_NOSEVERITY
#define DEM_GET_SEVERITYOFDTC_NOSEVERITY        (0x02U)
#endif
#ifndef DEM_GET_SEVERITYOFDTC_PENDING
#define DEM_GET_SEVERITYOFDTC_PENDING     (0x03U)
#endif

/****************************************************************************/

/*************************** Dem_ReturnGetFunctionalUnitOfDTCType **************/

#ifndef Rte_TypeDef_Dem_ReturnGetFunctionalUnitOfDTCType
typedef uint8 Dem_ReturnGetFunctionalUnitOfDTCType;
#endif

#ifndef  DEM_GET_FUNCTIONALUNITOFDTC_OK
#define DEM_GET_FUNCTIONALUNITOFDTC_OK    (0x00U)
#endif
#ifndef  DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC
#define DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC    (0x01U)
#endif

/****************************************************************************/

/*************************** Dem_ReturnSetFilterType *************************/

#ifndef Rte_TypeDef_Dem_ReturnSetFilterType
typedef uint8 Dem_ReturnSetFilterType;
#endif

#ifndef  DEM_FILTER_ACCEPTED
#define DEM_FILTER_ACCEPTED    (0x00U)
#endif
#ifndef  DEM_WRONG_FILTER
#define DEM_WRONG_FILTER    (0x01U)
#endif

/****************************************************************************/

/*************************** Dem_ReturnGetNumberOfFilteredDTCType************/

#ifndef Rte_TypeDef_Dem_ReturnGetNumberOfFilteredDTCType
typedef uint8 Dem_ReturnGetNumberOfFilteredDTCType;
#endif

#ifndef  DEM_NUMBER_OK
#define DEM_NUMBER_OK    (0x00U)
#endif
#ifndef  DEM_NUMBER_FAILED
#define DEM_NUMBER_FAILED    (0x01U)
#endif
#ifndef  DEM_NUMBER_PENDING
#define DEM_NUMBER_PENDING        (0x02U)
#endif

/****************************************************************************/

/*************************** Dem_ReturnGetNextFilteredElementType ***********/

#ifndef Rte_TypeDef_Dem_ReturnGetNextFilteredElementType
typedef uint8 Dem_ReturnGetNextFilteredElementType;
#endif

#ifndef  DEM_FILTERED_OK
#define DEM_FILTERED_OK    (0x00U)
#endif
#ifndef  DEM_NO_SUCH_ELEMENT
#define DEM_NO_SUCH_ELEMENT    (0x01U)
#endif
#ifndef  DEM_FILTERED_PENDING
#define DEM_FILTERED_PENDING        (0x02U)
#endif
#ifndef DEM_FILTERED_BUFFER_TOO_SMALL
#define DEM_FILTERED_BUFFER_TOO_SMALL     (0x03U)
#endif

/****************************************************************************/

/*************************** Dem_ReturnGetDTCByOccurrenceTimeType ***********/

#ifndef Rte_TypeDef_Dem_ReturnGetDTCByOccurrenceTimeType
typedef uint8 Dem_ReturnGetDTCByOccurrenceTimeType;
#endif

#ifndef  DEM_OCCURR_OK
#define DEM_OCCURR_OK    (0x00U)
#endif
#ifndef  DEM_OCCURR_NOT_AVAILABLE
#define DEM_OCCURR_NOT_AVAILABLE    (0x01U)
#endif

/*************************** Dem_ReturnDisableDTCRecordUpdateType ***********/

#ifndef Rte_TypeDef_Dem_ReturnDisableDTCRecordUpdateType
typedef uint8 Dem_ReturnDisableDTCRecordUpdateType;
#endif

#ifndef  DEM_DISABLE_DTCRECUP_OK
#define DEM_DISABLE_DTCRECUP_OK    (0x00U)
#endif
#ifndef  DEM_DISABLE_DTCRECUP_WRONG_DTC
#define DEM_DISABLE_DTCRECUP_WRONG_DTC    (0x01U)
#endif
#ifndef  DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN
#define DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN        (0x02U)
#endif
#ifndef DEM_DISABLE_DTCRECUP_PENDING
#define DEM_DISABLE_DTCRECUP_PENDING     (0x03U)
#endif

/****************************************************************************/

/*************************** Dem_ReturnGetFreezeFrameDataByDTCType **********/

#ifndef Rte_TypeDef_Dem_ReturnGetFreezeFrameDataByDTCType
typedef uint8 Dem_ReturnGetFreezeFrameDataByDTCType;
#endif

#ifndef  DEM_GET_FFDATABYDTC_OK
#define DEM_GET_FFDATABYDTC_OK    (0x00U)
#endif
#ifndef  DEM_GET_FFDATABYDTC_WRONG_DTC
#define DEM_GET_FFDATABYDTC_WRONG_DTC    (0x01U)
#endif
#ifndef  DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN
#define DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN        (0x02U)
#endif
#ifndef DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER
#define DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER     (0x03U)
#endif
#ifndef  DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE
#define DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE    (0x04U)
#endif
#ifndef  DEM_GET_FFDATABYDTC_PENDING
#define DEM_GET_FFDATABYDTC_PENDING    (0x05U)
#endif

/****************************************************************************/

/*************************** Dem_ReturnGetExtendedDataRecordByDTCType *******/

#ifndef Rte_TypeDef_Dem_ReturnGetExtendedDataRecordByDTCType
typedef uint8 Dem_ReturnGetExtendedDataRecordByDTCType;
#endif

#ifndef  DEM_RECORD_OK
#define DEM_RECORD_OK    (0x00U)
#endif
#ifndef  DEM_RECORD_WRONG_DTC
#define DEM_RECORD_WRONG_DTC    (0x01U)
#endif
#ifndef  DEM_RECORD_WRONG_DTCORIGIN
#define DEM_RECORD_WRONG_DTCORIGIN        (0x02U)
#endif
#ifndef DEM_RECORD_WRONG_NUMBER
#define DEM_RECORD_WRONG_NUMBER     (0x03U)
#endif
#ifndef  DEM_RECORD_WRONG_BUFFERSIZE
#define DEM_RECORD_WRONG_BUFFERSIZE    (0x04U)
#endif
#ifndef  DEM_RECORD_PENDING
#define DEM_RECORD_PENDING    (0x05U)
#endif

/****************************************************************************/

/*************************** Dem_ReturnGetSizeOfDataByDTCType ***************/

#ifndef Rte_TypeDef_Dem_ReturnGetSizeOfDataByDTCType
typedef uint8 Dem_ReturnGetSizeOfDataByDTCType;
#endif

#ifndef  DEM_GETSIZEBYDTC_OK
#define DEM_GETSIZEBYDTC_OK    (0x00U)
#endif
#ifndef  DEM_GETSIZEBYDTC_WRONG_DTC
#define DEM_GETSIZEBYDTC_WRONG_DTC    (0x01U)
#endif
#ifndef  DEM_GETSIZEBYDTC_WRONG_DTCORIGIN
#define DEM_GETSIZEBYDTC_WRONG_DTCORIGIN        (0x02U)
#endif
#ifndef DEM_GETSIZEBYDTC_WRONG_RECNUM
#define DEM_GETSIZEBYDTC_WRONG_RECNUM     (0x03U)
#endif
#ifndef  DEM_GETSIZEBYDTC_PENDING
#define DEM_GETSIZEBYDTC_PENDING    (0x04U)
#endif

/****************************************************************************/

/*************************** Dem_ReturnClearDTCType *************************/

#ifndef Rte_TypeDef_Dem_ReturnClearDTCType
typedef uint8 Dem_ReturnClearDTCType;
#endif

#ifndef  DEM_CLEAR_OK
#define DEM_CLEAR_OK    (0x00U)
#endif
#ifndef  DEM_CLEAR_WRONG_DTC
#define DEM_CLEAR_WRONG_DTC    (0x01U)
#endif
#ifndef  DEM_CLEAR_WRONG_DTCORIGIN
#define DEM_CLEAR_WRONG_DTCORIGIN        (0x02U)
#endif
#ifndef DEM_CLEAR_FAILED
#define DEM_CLEAR_FAILED     (0x03U)
#endif
#ifndef  DEM_CLEAR_PENDING
#define DEM_CLEAR_PENDING    (0x04U)
#endif
#ifndef  DEM_CLEAR_BUSY
#define DEM_CLEAR_BUSY    (0x05U)
#endif
#ifndef  DEM_CLEAR_MEMORY_ERROR
#define DEM_CLEAR_MEMORY_ERROR    (0x06U)
#endif

/*************************** Dem_ReturnControlDTCSettingType ***************/

#ifndef Dem_ReturnControlDTCSettingType
typedef uint8 Dem_ReturnControlDTCSettingType;
#endif

#ifndef  DEM_CONTROL_DTC_SETTING_OK
#define DEM_CONTROL_DTC_SETTING_OK    (0x00U)
#endif
#ifndef  DEM_CONTROL_DTC_SETTING_N_OK
#define DEM_CONTROL_DTC_SETTING_N_OK    (0x01U)
#endif
#ifndef  DEM_CONTROL_DTC_WRONG_DTCGROUP
#define DEM_CONTROL_DTC_WRONG_DTCGROUP        (0x02U)
#endif

/*************************** Dem_ClientFunctionalityType ***************/

#ifndef Dem_ReturnControlDTCSettingType
typedef uint8 Dem_ClientFunctionalityType;
#endif

#ifndef  DEM_CLIENT_USES_FULL_FUNCTIONALITY
#define  DEM_CLIENT_USES_FULL_FUNCTIONALITY     (0x00U)
#endif
#ifndef  DEM_CLIENT_ONLY_USES_EVENTOVERFLOW_INTERFACE
#define DEM_CLIENT_ONLY_USES_EVENTOVERFLOW_INTERFACE    (0x01U)
#endif


/****************************************************************************/

/****************************************************************************/

/*****************************************************************************
 *                                Globally  accessed Variable Declarations    *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

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
/**-------------------------------------------------------------------------*/
/*Date              : 10-Mar-2017                                            */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Data design And Framework , Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-Jan-2022                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1560389                                           */
/*Change Description: DCM and DEM Autosar 4.2.2 Migration                   */
/*--------------------------------------------------------------------------*/

