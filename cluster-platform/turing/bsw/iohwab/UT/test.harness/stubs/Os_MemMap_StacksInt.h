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
 *              File: Os_MemMap_StacksInt.h
 *   Generation Time: 2020-04-08 11:31:56
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  STACK SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_PROTECTION_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_PROTECTION_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_PROTECTION_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_PROTECTION_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_PROTECTION_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_PROTECTION_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_PROTECTION_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_PROTECTION_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_PROTECTION_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSTASK_10MSCAN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSTASK_10MSCAN_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSTASK_10MSCAN_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSTASK_10MSCAN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSTASK_10MSCAN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSTASK_10MSCAN_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSTASK_10MSCAN_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSTASK_10MSCAN_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSTASK_10MSCAN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSTASK_10MSECUM_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSTASK_10MSECUM_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSTASK_10MSECUM_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSTASK_10MSECUM_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSTASK_10MSECUM_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSTASK_10MSECUM_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSTASK_10MSECUM_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSTASK_10MSECUM_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSTASK_10MSECUM_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSTASK_30MS_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSTASK_30MS_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSTASK_30MS_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSTASK_30MS_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSTASK_30MS_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSTASK_30MS_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSTASK_30MS_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSTASK_30MS_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSTASK_30MS_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSTASK_NVM_STACK_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSTASK_NVM_STACK_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs startdata
# pragma ghs section bss = ".OS_STACK_OSTASK_NVM_STACK_VAR_NOINIT"

# undef OS_START_SEC_STACK_OSTASK_NVM_STACK_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSTASK_NVM_STACK_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSTASK_NVM_STACK_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSTASK_NVM_STACK_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSTASK_NVM_STACK_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs enddata
# undef OS_STOP_SEC_STACK_OSTASK_NVM_STACK_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


