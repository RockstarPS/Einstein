/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_CDisplayCdd.h
 *           Config:  Audi_Etron_TV2.dpa
 *      ECU-Project:  Audi_Etron_TV2
 *
 *        Generator:  MICROSAR RTE Generator Version 4.39.00
 *                    RTE Core Version 4.39.00
 *          License:  CBD2500735
 *
 *      Description:  Application header file for SW-C <CDisplayCdd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDISPLAYCDD_H
# define RTE_CDISPLAYCDD_H

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


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define CBacklightCdd_START_SEC_CODE
#  include "CBacklightCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, CBacklightCdd_CODE) CBacklightCdd_NotifyDisplayPowerState(EDisplayType DeviceId, EDisplayPowerState CompletedPowerState); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define CBacklightCdd_STOP_SEC_CODE
#  include "CBacklightCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define CBacklightCdd_START_SEC_CODE
#  include "CBacklightCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, CBacklightCdd_CODE) CBacklightCdd_GetStatus(EDisplayType DeviceName, P2VAR(EDeviceStatus, AUTOMATIC, RTE_CBACKLIGHTCDD_APPL_VAR) DeviceStatus); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define CBacklightCdd_STOP_SEC_CODE
#  include "CBacklightCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define IoHwAb_START_SEC_CODE
#  include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define IoHwAb_STOP_SEC_CODE
#  include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define IoHwAb_START_SEC_CODE
#  include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define IoHwAb_STOP_SEC_CODE
#  include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpIoHwAb_SetDout_SetOutputGroup IoHwAb_SetOutputGroup
#  define Rte_Call_rpIoHwAb_SetDout_SetOutputPin IoHwAb_SetOutputPin
#  define Rte_Call_rp_CS_Backlight_Notify_NotifyDisplayPowerState CBacklightCdd_NotifyDisplayPowerState
#  define Rte_Call_rp_CS_Backlight_Status_GetStatus CBacklightCdd_GetStatus

# endif /* !defined(RTE_CORE) */


# define CDisplayCdd_START_SEC_CODE
# include "CDisplayCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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

FUNC(void, CDisplayCdd_CODE) CDisplayCdd_GetGammaCorrectionStatus(P2VAR(EGammaCorrectionStatus, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) GmaCrStatus); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, CDisplayCdd_CODE) CDisplayCdd_GetStatus(EDisplayType DeviceId, P2VAR(EDisplayCddStatus, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) DeviceStatus, P2VAR(EDisplayPowerState, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) DisplayPowerState); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, CDisplayCdd_CODE) CDisplayCdd_I2cSeqEndCallback(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, CDisplayCdd_CODE) CDisplayCdd_Impl_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, CDisplayCdd_CODE) CDisplayCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, CDisplayCdd_CODE) CDisplayCdd_SetGammaCorrection(P2VAR(UInt8, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) GmaSetPtr, UInt8 datalength); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, CDisplayCdd_CODE) CDisplayCdd_SetState(EDisplayType DeviceID, EDisplayPowerState PowerState); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define CDisplayCdd_STOP_SEC_CODE
# include "CDisplayCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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

#endif /* RTE_CDISPLAYCDD_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
