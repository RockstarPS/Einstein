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
 *              File: Os_MemoryProtection_Lcfg.h
 *   Generation Time: 2020-04-08 11:31:56
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_MEMORYPROTECTION_LCFG_H)                                            /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_MEMORYPROTECTION_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_MemoryProtection_Types.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


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
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Memory protection configuration data */
extern CONST(Os_MpCoreConfigType, OS_CONST) OsCfg_Mp_OsCore_Core0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsApplication;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SystemApplication_OsCore_Core0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Bswc_App_Intrpt;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsr_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsr_5;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_60MHzFRT;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_ADC_B0_ConversionDone;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_ADC_B1_ConversionDone;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_DMA_Ch0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_DMA_Ch12;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_DMA_Ch13;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_DMA_Ch14;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_DMA_Ch15;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_DMA_Error;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_ECC_SRAM_1_Bit_Error;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_Ext_Int_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_Ext_Int_6;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_FAN_SPD;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_MFS_Error_Ch9;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_MFS_Receive_Ch9;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_MFS_Transmit_Ch9;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_RLT01_1us_1shot_delay;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_RTC;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_SystemTimer;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_TmExt;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_Wdg_TO;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsIsr_Wdg_Trg;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_AppTask_10msLP;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IdleTask_OsCore_Core0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsTask_100ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsTask_10msCAN;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsTask_10msEcuM;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsTask_10ms_Wdg;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsTask_2ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsTask_30ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsTask_30msSnd;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsTask_4ms_Ipcl;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsTask_NvM_Stack;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsTask_RteEvent;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsTask_StackMesure;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_StartupTwo;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Memory protection configuration data */
extern CONST(Os_MpSystemConfigType, OS_CONST) OsCfg_Mp_SystemMpu;

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_MEMORYPROTECTION_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_MemoryProtection_Lcfg.h
 *********************************************************************************************************************/
