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
 *  File Name         :  Rte_Dem_Type.h                                      *
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
#ifndef RTE_DEM_TYPE_H
#define RTE_DEM_TYPE_H


#include "Rte_Type.h"
#include "Dcm_Cfg.h"

#  ifndef DEM_DTC_FORMAT_OBD
#   define DEM_DTC_FORMAT_OBD (0U)
#  endif

#  ifndef DEM_DTC_FORMAT_UDS
#   define DEM_DTC_FORMAT_UDS (1U)
#  endif

#  ifndef DEM_DTC_FORMAT_J1939
#   define DEM_DTC_FORMAT_J1939 (2U)
#  endif

#  ifndef DEM_DTC_ORIGIN_PRIMARY_MEMORY
#   define DEM_DTC_ORIGIN_PRIMARY_MEMORY (1U)
#  endif

#  ifndef DEM_DTC_ORIGIN_MIRROR_MEMORY
#   define DEM_DTC_ORIGIN_MIRROR_MEMORY (2U)
#  endif

#  ifndef DEM_DTC_ORIGIN_PERMANENT_MEMORY
#   define DEM_DTC_ORIGIN_PERMANENT_MEMORY (3U)
#  endif

#  ifndef DEM_DTC_ORIGIN_SECONDARY_MEMORY
#   define DEM_DTC_ORIGIN_SECONDARY_MEMORY (4U)
#  endif

#  ifndef DEM_DEBOUNCE_STATUS_FREEZE
#   define DEM_DEBOUNCE_STATUS_FREEZE (0U)
#  endif

#  ifndef DEM_DEBOUNCE_STATUS_RESET
#   define DEM_DEBOUNCE_STATUS_RESET (1U)
#  endif

#  ifndef DEM_TEMPORARILY_DEFECTIVE
#   define DEM_TEMPORARILY_DEFECTIVE (1U)
#  endif

#  ifndef DEM_FINALLY_DEFECTIVE
#   define DEM_FINALLY_DEFECTIVE (2U)
#  endif

#  ifndef DEM_TEMPORARILY_HEALED
#   define DEM_TEMPORARILY_HEALED (4U)
#  endif

#  ifndef DEM_TEST_COMPLETE
#   define DEM_TEST_COMPLETE (8U)
#  endif

#  ifndef DEM_DTR_UPDATE
#   define DEM_DTR_UPDATE (16U)
#  endif

#  ifndef DemConf_DemEventParameter_INVALID
#   define DemConf_DemEventParameter_INVALID (0U)
#  endif

#  ifndef DemConf_DemEventParameter_DATA_BUS_DEFECT_CLASS
#   define DemConf_DemEventParameter_DATA_BUS_DEFECT_CLASS (1U)
#  endif

#  ifndef DemConf_DemEventParameter_IMMO_NO_BASIC_SETTING_CLASS
#   define DemConf_DemEventParameter_IMMO_NO_BASIC_SETTING_CLASS (2U)
#  endif

#  ifndef DemConf_DemEventParameter_IMMO_ENGINE_ECU2_CLASS
#   define DemConf_DemEventParameter_IMMO_ENGINE_ECU2_CLASS (3U)
#  endif

#  ifndef DemConf_DemEventParameter_IMMO_ENGINE_ECU3_CLASS
#   define DemConf_DemEventParameter_IMMO_ENGINE_ECU3_CLASS (4U)
#  endif

#  ifndef DemConf_DemEventParameter_IMMO_DEVMODEACT_CLASS
#   define DemConf_DemEventParameter_IMMO_DEVMODEACT_CLASS (5U)
#  endif

/* To be defined in RTE */
#ifndef Rte_TypeDef_Dcm_CommunicationModeType
# define Rte_TypeDef_Dcm_CommunicationModeType
typedef uint8 Dcm_CommunicationModeType;
#endif

#ifndef Rte_TypeDef_Dcm_ConfirmationStatusType
# define Rte_TypeDef_Dcm_ConfirmationStatusType
typedef uint8 Dcm_ConfirmationStatusType;
#endif

#ifndef Rte_TypeDef_Dcm_ControlDtcSettingType
# define Rte_TypeDef_Dcm_ControlDtcSettingType
typedef uint8 Dcm_ControlDtcSettingType;
#endif

#ifndef Rte_TypeDef_Dcm_DiagnosticSessionControlType
# define Rte_TypeDef_Dcm_DiagnosticSessionControlType
typedef uint8 Dcm_DiagnosticSessionControlType;
#endif

#ifndef Rte_TypeDef_Dcm_EcuResetType
# define Rte_TypeDef_Dcm_EcuResetType
typedef uint8 Dcm_EcuResetType;
#endif

#ifndef Rte_TypeDef_Dcm_NegativeResponseCodeType
# define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;
#endif

#ifndef Rte_TypeDef_Dcm_OpStatusType
# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;
#endif

#ifndef Rte_TypeDef_Dcm_ProtocolType
# define Rte_TypeDef_Dcm_ProtocolType
typedef uint8 Dcm_ProtocolType;
#endif

#ifndef Rte_TypeDef_Dcm_RequestKindType
# define Rte_TypeDef_Dcm_RequestKindType
typedef uint8 Dcm_RequestKindType;
#endif

#ifndef Rte_TypeDef_Dcm_SecLevelType
# define Rte_TypeDef_Dcm_SecLevelType
typedef uint8 Dcm_SecLevelType;
#endif

#ifndef Rte_TypeDef_Dcm_SesCtrlType
# define Rte_TypeDef_Dcm_SesCtrlType
typedef uint8 Dcm_SesCtrlType;
#endif

#ifndef Rte_TypeDef_Dem_EventIdType
# define Rte_TypeDef_Dem_EventIdType
typedef uint16 Dem_EventIdType;
#endif

#ifndef Rte_TypeDef_Dem_InitMonitorReasonType
# define Rte_TypeDef_Dem_InitMonitorReasonType
typedef uint8 Dem_InitMonitorReasonType;
#endif

#endif
