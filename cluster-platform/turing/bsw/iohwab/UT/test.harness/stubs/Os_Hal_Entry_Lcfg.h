/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR Renault SLP6 (MSR_Renault_SLP6)
 *          Customer: Visteon Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: S6J332EJB
 *    License Scope : The usage is restricted to CBD1700714_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Entry_Lcfg.h
 *   Generation Time: 2020-04-08 11:31:55
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_HAL_ENTRY_LCFG_H)                                                   /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_HAL_ENTRY_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Core_Types.h"
# include "Os_Hal_Compiler.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  EXCEPTION VECTOR TABLE CORE 0
 *********************************************************************************************************************/
#define OS_START_SEC_EXCVEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(Os_Hal_ExceptionTableEntryType, OS_CONST) OsCfg_Hal_Core_OsCore_Core0_ExceptionTable[8];
#define OS_STOP_SEC_EXCVEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  INTERRUPT VECTOR TABLE CORE 0
 *********************************************************************************************************************/
#define OS_START_SEC_INTVEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(Os_Hal_VectorTableEntryType, OS_CONST) OsCfg_Hal_Core_OsCore_Core0_VectorTable[512];

#define OS_STOP_SEC_INTVEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */





/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_INTVEC_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern uint8 _OS_INTVEC_CODE_START[]; /* PRQA S 3684 */ /* MD_Os_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CODE_END[]; /* PRQA S 3684 */ /* MD_Os_3684_LinkerSymbol */

#define OS_STOP_SEC_INTVEC_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_EXCVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern uint8 _OS_EXCVEC_CORE0_CODE_START[]; /* PRQA S 3684 */ /* MD_Os_3684_LinkerSymbol */
extern uint8 _OS_EXCVEC_CORE0_CODE_END[]; /* PRQA S 3684 */ /* MD_Os_3684_LinkerSymbol */

#define OS_STOP_SEC_EXCVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_INTVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern uint8 _OS_INTVEC_CORE0_CODE_START[]; /* PRQA S 3684 */ /* MD_Os_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CORE0_CODE_END[]; /* PRQA S 3684 */ /* MD_Os_3684_LinkerSymbol */

#define OS_STOP_SEC_INTVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_ENTRY_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Lcfg.h
 *********************************************************************************************************************/
