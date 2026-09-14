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
 *          File:  Rte_Mdl_Linear_Interpolation.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <Mdl_Linear_Interpolation>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MDL_LINEAR_INTERPOLATION_H
# define _RTE_MDL_LINEAR_INTERPOLATION_H

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

# include "Rte_Mdl_Linear_Interpolation_Type.h"
# include "Rte_DataHandleType.h"


# define Mdl_Linear_Interpolation_START_SEC_CODE
# include "Mdl_Linear_Interpolation_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Mdl_Linear_Interpolation_Get_LinearInterpolateByte Mdl_Linear_Interpolation_Get_LinearInterpolateByte
#  define RTE_RUNNABLE_Mdl_Linear_Interpolation_Get_LinearInterpolateSByte Mdl_Linear_Interpolation_Get_LinearInterpolateSByte
#  define RTE_RUNNABLE_Mdl_Linear_Interpolation_Get_LinearInterpolateSWord Mdl_Linear_Interpolation_Get_LinearInterpolateSWord
#  define RTE_RUNNABLE_Mdl_Linear_Interpolation_Get_LinearInterpolateWord Mdl_Linear_Interpolation_Get_LinearInterpolateWord
#  define RTE_RUNNABLE_Mdl_Linear_Interpolation_Init Mdl_Linear_Interpolation_Init
#  define RTE_RUNNABLE_Mdl_Linear_Interpolation_Task Mdl_Linear_Interpolation_Task
# endif

FUNC(void, Mdl_Linear_Interpolation_CODE) Mdl_Linear_Interpolation_Get_LinearInterpolateByte(P2VAR(UInt8, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) ptr_table, UInt8 lookupvalue, P2VAR(UInt8, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) Ptr_Lin_Return); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Mdl_Linear_Interpolation_CODE) Mdl_Linear_Interpolation_Get_LinearInterpolateSByte(P2VAR(SInt8, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) ptr_table, SInt8 lookupvalue, P2VAR(SInt8, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) Ptr_Lin_Return); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Mdl_Linear_Interpolation_CODE) Mdl_Linear_Interpolation_Get_LinearInterpolateSWord(P2VAR(SInt16, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) ptr_table, SInt16 lookupvalue, P2VAR(SInt16, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) Ptr_Lin_Return); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Mdl_Linear_Interpolation_CODE) Mdl_Linear_Interpolation_Get_LinearInterpolateWord(P2VAR(UInt16, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) ptr_table, UInt16 lookupvalue, P2VAR(UInt16, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) Ptr_Lin_Return); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Mdl_Linear_Interpolation_CODE) Mdl_Linear_Interpolation_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Mdl_Linear_Interpolation_CODE) Mdl_Linear_Interpolation_Task(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define Mdl_Linear_Interpolation_STOP_SEC_CODE
# include "Mdl_Linear_Interpolation_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MDL_LINEAR_INTERPOLATION_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
