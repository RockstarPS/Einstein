/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file Mdl_SafetyAdapter.h
*    @ingroup Mdl_SafetyAdapter
*    @brief This file contains the API provided by the Mdl_SafetyAdapter.
*    Auto generated code in RPERIYAS at 2024-11-29 12:03:21.656622
********************************************************************************************************************/
#ifndef RTW_HEADER_Mdl_SafetyAdapter_h_
#define RTW_HEADER_Mdl_SafetyAdapter_h_
#ifndef Ctrl_WSS_COMMON_INCLUDES_
# define Ctrl_WSS_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_Mdl_SafetyAdapter.h"
#endif                                 /* Ctrl_WSS_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes. */
#include "Rte_Type.h"
#include "Rte_Mdl_SafetyAdapter.h"
#include "Mdl_SafetyAdapter_TxCfg.h"
#include "Mdl_SafetyAdapter_RxCfg.h"
/* Macros for accessing real-time model data structure */

/* Exported data define */

/* Definition for custom storage class: Define */
#define ACCSTATUS_OFF                  0U
#define ACCSTATUS_ON                   1U
#define ACCSTATUS_ON_VAL               1U
#define BASTATUS_OFF                   0U
#define BASTATUS_ON                    1U
#define BASTATUS_ON_VAL                1U
#define IGPSTATUS_OFF                  0U
#define IGPSTATUS_ON                   1U
#define IGPSTATUS_ON_VAL               1U

#  ifndef eSIGNAL_OK
#   define eSIGNAL_OK (0U)
#  endif

#  ifndef eSIGNAL_MISSING
#   define eSIGNAL_MISSING (1U)
#  endif

#  ifndef eSIGNAL_NEVER_RECEIVED
#   define eSIGNAL_NEVER_RECEIVED (2U)
#  endif

#  ifndef eSIGNAL_INVALID
#   define eSIGNAL_INVALID (4U)
#  endif

#if 1
#  ifndef eJust_Received
#   define eJust_Received (0U)
#  endif
#  ifndef eNot_Just_Received
#   define eNot_Just_Received (1U)
#  endif

// typedef uint16 tRxSafeSignalId;
//typedef uint8 tRxSafeSignalJustRcvdStatus;
// typedef uint8 tRxSafeSignalStatus;


#endif
/********************************************************************************************************************
*   @brief   This method is used to intialize the rx can variable
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanVarInit(void);
/********************************************************************************************************************
*   @brief     This method is used to reset the missing timer
*   @param[in] SignalId		Signal Id
********************************************************************************************************************/
void Mdl_SafetyAdapter_ReloadMissingTimer(tRxSafeSignalId SignalId);
#ifndef MDL_SAFETYADAPTER_DUMMY_STATEMENT
#define MDL_SAFETYADAPTER_DUMMY_STATEMENT(param)                  ((void)(param))
#endif

/********************************************************************************************************************
*   @brief   This method is used to set the signal confirmation status
*   @param[in] SignalId TX signal id
********************************************************************************************************************/
void Mdl_SafetyAdapter_TxCan_SetCanSignalTxConfirmation(tTxSignalId SignalId);
/********************************************************************************************************************
*   @brief   This method is used to intialize the rx can variable
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanVarInit(void);
/********************************************************************************************************************
*   @brief   This method is used to tx can variable
********************************************************************************************************************/
void Mdl_SafetyAdapter_TxCanVarInit(void);

/********************************************************************************************************************
*   @brief     This method is used to reset the missing timer
*   @param[in] SignalId		Signal Id
********************************************************************************************************************/
void Mdl_SafetyAdapter_ReloadMissingTimer(tRxSafeSignalId SignalId);

/********************************************************************************************************************
*   @brief     This method is used to reset the missing timer
*   @param[in] SignalId		Signal Id
*   @param[in] pSignalValue	 pointer to signal value
*   @param[in] pSignalLength pointer to signal length
*   @return Std_ReturnType		pSignalLength
********************************************************************************************************************/
Std_ReturnType Mdl_SafetyAdapter_RxCanSetSignalValueU8Arr(tRxSafeSignalId SignalId,uint8 * pSignalValue,uint32 *pSignalLength);

#  ifndef eCmpCmd_Init
#   define eCmpCmd_Init (0U)
#  endif

#  ifndef eCmpCmd_DeInit
#   define eCmpCmd_DeInit (1U)
#  endif

#  ifndef eCmpCmd_Activate
#   define eCmpCmd_Activate (2U)
#endif

/* Function Macros */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_Ctrl_telltale_Impl_OnCommand CCtrl_Telltale_Impl_OnCommand
#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_View_telltale_Impl_OnCommand CView_Telltale_Impl_OnCommand



#  define RTE_START_SEC_VIEW_TELLTALE_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_VIEW_TELLTALE_APPL_CODE) CView_Telltale_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_VIEW_TELLTALE_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#  define RTE_START_SEC_CTRL_TELLTALE_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CTRL_TELLTALE_APPL_CODE) CCtrl_Telltale_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CTRL_TELLTALE_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(tRxSafeSignalId SignalId);

#endif /* MDL_SAFETYADAPTER_H_ */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/



