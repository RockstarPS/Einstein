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
 *          File:  Rte_TrustecSWC.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <TrustecSWC>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TRUSTECSWC_H
# define _RTE_TRUSTECSWC_H

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

# include "Rte_TrustecSWC_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS(P2VAR(SG_ABS, AUTOMATIC, RTE_TRUSTECSWC_APPL_VAR) data, P2VAR(Rte_TransformerError, AUTOMATIC, RTE_TRUSTECSWC_APPL_VAR) transformerError); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS(P2CONST(SG_COM_HS, AUTOMATIC, RTE_TRUSTECSWC_APPL_DATA) data, P2VAR(Rte_TransformerError, AUTOMATIC, RTE_TRUSTECSWC_APPL_VAR) transformerError); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RP_RX_SG_ABS_RP_SR_TX_SG_ABS Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PP_TX_SG_COM_HS_SG_COM_HS Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<d> (explicit S/R communication status handling)
 *********************************************************************************************************************/
#  define Rte_Feedback_PP_TX_SG_COM_HS_SG_COM_HS Rte_Feedback_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS


# endif /* !defined(RTE_CORE) */


# define TrustecSWC_START_SEC_CODE
# include "TrustecSWC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_TrustedSwc_MainFunction TrustedSwc_MainFunction
# endif

FUNC(void, TrustecSWC_CODE) TrustedSwc_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define TrustecSWC_STOP_SEC_CODE
# include "TrustecSWC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_TRUSTECSWC_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
