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
 *              File: Os_Cfg.h
 *   Generation Time: 2020-04-08 11:31:55
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_CFG_H)                                                              /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Configuration major version identification. */
# define OS_CFG_MAJOR_VERSION                    (2U)

/*! Configuration minor version identification. */
# define OS_CFG_MINOR_VERSION                    (18U)


/*! Defines which platform is used. */
# define OS_CFG_PLATFORM_ARM     (STD_ON)

/*! Defines which derivative group is configured. */
# define OS_CFG_DERIVATIVEGROUP_S6J33XX     (STD_ON)

/*! Defines which derivative is configured. */
# define OS_CFG_DERIVATIVE_S6J332EJB     (STD_ON)

/*! Defines which compiler is configured. */
# define OS_CFG_COMPILER_GREENHILLS     (STD_ON)


/*! Defines whether access macros to get context related information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_PARAMETERACCESS              (STD_ON)

/*! Defines whether access macros to get service ID information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_GETSERVICEID                 (STD_ON)

/*! Defines whether the pre-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_PRETASKHOOK                      (STD_OFF)

/*! Defines whether the post-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_POSTTASKHOOK                     (STD_OFF)

/*! Defines whether the OS shall call the panic hook (STD_ON) or not (STD_OFF). */
# define OS_CFG_PANICHOOK                        (STD_ON)

/*! Defines whether the system startup hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_STARTUPHOOK_SYSTEM               (STD_ON)

/*! Defines whether the system shutdown hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_SHUTDOWNHOOK_SYSTEM              (STD_ON)

/*! Defines whether the system error hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERRORHOOK_SYSTEM                 (STD_ON)

/*! Defines whether the system protection hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_PROTECTIONHOOK_SYSTEM            (STD_ON)

/*! Defines whether backward compatibility defines are needed (STD_ON) or not (STD_OFF). */
# define OS_CFG_PERIPHERAL_COMPATIBILITY         (STD_ON)


/* OS application modes */
# define DONOTCARE     ((AppModeType)0)
# define OS_APPMODE_NONE     ((AppModeType)0)
# define OSDEFAULTAPPMODE     ((AppModeType)1)
# define OS_APPMODE_ANY     ((AppModeType)255)


/* Event masks */
# define Rte_Ev_Cyclic2_Main_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic2_OsTask_10msCAN_0_10ms     ((EventMaskType)2ULL)
# define Rte_Ev_Cyclic2_OsTask_10msCAN_0_20ms     ((EventMaskType)4ULL)
# define Rte_Ev_Cyclic2_OsTask_10msEcuM_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic2_OsTask_NvM_Stack_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_Main_0_10ms     ((EventMaskType)8ULL)
# define Rte_Ev_Cyclic_OsTask_10msEcuM_0_10ms     ((EventMaskType)2ULL)
# define Rte_Ev_Run_EcumExt_CEcumExt_NvM_ReadAll_SpeedUp     ((EventMaskType)2ULL)
# define Rte_Ev_Run_IoHwAb_IoHwAb_MainFunction     ((EventMaskType)1ULL)
# define Rte_Ev_Run_RtcCdd_CRtcCdd_Impl_MainFunction     ((EventMaskType)2ULL)
# define Rte_Ev_WP_Main     ((EventMaskType)16ULL)


/* Software counter timing macros */
/* Counter timing macros and constants: SystemTimer */
# define OSMAXALLOWEDVALUE_SystemTimer     (2147483647UL) /* 0x7FFFFFFFUL */
# define OSMINCYCLE_SystemTimer            (1UL)
# define OSTICKSPERBASE_SystemTimer        (1UL)
# define OSTICKDURATION_SystemTimer        (1000000UL)

/* OSEK compatibility for the system timer. */
# define OSMAXALLOWEDVALUE     (OSMAXALLOWEDVALUE_SystemTimer)
# define OSMINCYCLE            (OSMINCYCLE_SystemTimer)
# define OSTICKSPERBASE        (OSTICKSPERBASE_SystemTimer)
# define OSTICKDURATION        (OSTICKDURATION_SystemTimer)

/*! Macro OS_NS2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 500000) / 1000000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2NS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_US2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 500) / 1000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2US_SystemTimer was approximated with a deviation of 1.1102230246251565E-10ppm. */
# define OS_TICKS2US_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_MS2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2MS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_SEC2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2SEC_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 500) / 1000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Cfg.h
 *********************************************************************************************************************/
