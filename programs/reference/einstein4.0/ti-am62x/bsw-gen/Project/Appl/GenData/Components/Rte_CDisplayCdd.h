/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CDisplayCdd.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CDisplayCdd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDISPLAYCDD_H
# define _RTE_CDISPLAYCDD_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CDisplayCdd_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData(P2VAR(SDisplayCurrentState, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData(P2CONST(SDisplaySetPower, AUTOMATIC, RTE_CDISPLAYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_SetDout_SetOutputGroup IoHwAb_SetOutputGroup
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_SetDout_SetOutputPin IoHwAb_SetOutputPin
#  define RTE_START_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CBACKLIGHTCDD_APPL_CODE) CBacklightCdd_NotifyDisplayPowerState(EDisplayType DeviceId, EDisplayPowerState CompletedPowerState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_Backlight_Notify_NotifyDisplayPowerState CBacklightCdd_NotifyDisplayPowerState
#  define RTE_START_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CBACKLIGHTCDD_APPL_CODE) CBacklightCdd_GetStatus(EDisplayType DeviceName, P2VAR(EDeviceStatus, AUTOMATIC, RTE_CBACKLIGHTCDD_APPL_VAR) DeviceStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_Backlight_Status_GetStatus CBacklightCdd_GetStatus


# endif /* !defined(RTE_CORE) */


# define CDisplayCdd_START_SEC_CODE
# include "CDisplayCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CDisplayCdd_GetGammaCorrectionStatus CDisplayCdd_GetGammaCorrectionStatus
#  define RTE_RUNNABLE_CDisplayCdd_GetStatus CDisplayCdd_GetStatus
#  define RTE_RUNNABLE_CDisplayCdd_I2cSeqEndCallback CDisplayCdd_I2cSeqEndCallback
#  define RTE_RUNNABLE_CDisplayCdd_Impl_MainFunction CDisplayCdd_Impl_MainFunction
#  define RTE_RUNNABLE_CDisplayCdd_Impl_OnCommand CDisplayCdd_Impl_OnCommand
#  define RTE_RUNNABLE_CDisplayCdd_SetGammaCorrection CDisplayCdd_SetGammaCorrection
#  define RTE_RUNNABLE_CDisplayCdd_SetState CDisplayCdd_SetState
# endif

FUNC(void, CDisplayCdd_CODE) CDisplayCdd_GetGammaCorrectionStatus(P2VAR(EGammaCorrectionStatus, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) GmaCrStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CDisplayCdd_CODE) CDisplayCdd_GetStatus(EDisplayType DeviceId, P2VAR(EDisplayCddStatus, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) DeviceStatus, P2VAR(EDisplayPowerState, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) DisplayPowerState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDisplayCdd_CODE) CDisplayCdd_I2cSeqEndCallback(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDisplayCdd_CODE) CDisplayCdd_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, CDisplayCdd_CODE) CDisplayCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CDisplayCdd_CODE) CDisplayCdd_SetGammaCorrection(P2VAR(UInt8, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) GmaSetPtr, UInt8 datalength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CDisplayCdd_CODE) CDisplayCdd_SetState(EDisplayType DeviceID, EDisplayPowerState PowerState); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDisplayCdd_STOP_SEC_CODE
# include "CDisplayCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_Backlight_NotifyDispaly_E_NOT_OK (1U)

#  define RTE_E_TI_Backlight_Status_E_NOT_OK (1U)

#  define RTE_E_TI_Display_GammaCorrection_E_NOT_OK (1U)

#  define RTE_E_TI_Display_Status_E_NOT_OK (1U)

#  define RTE_E_TI_IOHWAB_SetDout_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDISPLAYCDD_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
