/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_GdtDpConn.h
 *        Config:  Turing.dpa
 *   ECU-Project:  TuringECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Application header file for SW-C <GdtDpConn>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_GDTDPCONN_H
# define _RTE_GDTDPCONN_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_GdtDpConn_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_INIT) Rte_OdoMdl_tiSR_OdoOutMiles_Miles; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_tiSR_OdoOutMiles_Miles (0U)
#  define Rte_InitValue_tiSR_pGdt_TIGdt_Eng_Tacho (0U)
#  define Rte_InitValue_tiSR_pGdt_TIGdt_OdoKm_Miles (0U)
#  define Rte_InitValue_tiSR_pGdt_TIGdt_OdoMl_Miles (0U)
#  define Rte_InitValue_tiSR_pGdt_TIGdt_Spd_IsOverSpeed (FALSE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_GdtDpConn_tiSR_TrcOut_deTrcOut(P2VAR(sTrcOut, AUTOMATIC, RTE_GDTDPCONN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_tiSR_OdoOutMiles_Miles Rte_Read_GdtDpConn_tiSR_OdoOutMiles_Miles
#  define Rte_Read_GdtDpConn_tiSR_OdoOutMiles_Miles(data) (*(data) = Rte_OdoMdl_tiSR_OdoOutMiles_Miles, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TIEngMdl_Out_TachoF_Tacho Rte_Read_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho
#  define Rte_Read_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho(data) (*(data) = Rte_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TISpdMdl_Out_SpdF_Speed Rte_Read_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed
#  define Rte_Read_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed(data) (*(data) = Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TrcOut_deTrcOut Rte_Read_GdtDpConn_tiSR_TrcOut_deTrcOut


# endif /* !defined(RTE_CORE) */


# define GdtDpConn_START_SEC_CODE
# include "GdtDpConn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CGdtDpConn_Impl_RxOdoKm CGdtDpConn_Impl_RxOdoKm
#  define RTE_RUNNABLE_CGdtDpConn_Impl_RxOdoMl CGdtDpConn_Impl_RxOdoMl
#  define RTE_RUNNABLE_CGdtDpConn_Impl_RxSpeed CGdtDpConn_Impl_RxSpeed
#  define RTE_RUNNABLE_CGdtDpConn_Impl_RxTacho CGdtDpConn_Impl_RxTacho
#  define RTE_RUNNABLE_CGdtDpConn_Impl_RxTrip CGdtDpConn_Impl_RxTrip
# endif

FUNC(void, GdtDpConn_CODE) CGdtDpConn_Impl_RxOdoKm(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, GdtDpConn_CODE) CGdtDpConn_Impl_RxOdoMl(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, GdtDpConn_CODE) CGdtDpConn_Impl_RxSpeed(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, GdtDpConn_CODE) CGdtDpConn_Impl_RxTacho(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, GdtDpConn_CODE) CGdtDpConn_Impl_RxTrip(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define GdtDpConn_STOP_SEC_CODE
# include "GdtDpConn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_GDTDPCONN_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
