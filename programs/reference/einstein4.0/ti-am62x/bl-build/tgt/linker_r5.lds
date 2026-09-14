

--retain="*(.bootCode)";
--retain="*(.startupCode)";
--retain="*(.startupData)";
--retain="*(.irqStack)";
--retain="*(.fiqStack)";
--retain="*(.abortStack)";
--retain="*(.undefinedstack)";
--retain="*(.svcStack)";
--fill_value=0
-e_vectors   /* Default C RTS boot.asm   */
/* This is the stack that is used by code running within main()
 * In case of NORTOS,
 * - This means all the code outside of ISR uses this stack
 * In case of FreeRTOS
 * - This means all the code until vTaskStartScheduler() is called in main()
 *   uses this stack.
 * - After vTaskStartScheduler() each task created in FreeRTOS has its own stack
 */
--stack_size=16384
/* This is the heap size for malloc() API in NORTOS and FreeRTOS
 * This is also the heap used by pvPortMalloc in FreeRTOS
 */
--heap_size=32768
//-e_vectors  /* This is the entry of the application, _vector MUST be plabed starting address 0x0 */

/* This is the size of stack when R5 is in IRQ mode
 * In NORTOS,
 * - Here interrupt nesting is disabled as of now
 * - This is the stack used by ISRs registered as type IRQ
 * In FreeRTOS,
 * - Here interrupt nesting is enabled
 * - This is stack that is used initally when a IRQ is received
 * - But then the mode is switched to SVC mode and SVC stack is used for all user ISR callbacks
 * - Hence in FreeRTOS, IRQ stack size is less and SVC stack size is more
 */
__IRQ_STACK_SIZE = 4096;
/* This is the size of stack when R5 is in IRQ mode
 * - In both NORTOS and FreeRTOS nesting is disabled for FIQ
 */
__FIQ_STACK_SIZE = 256;
__SVC_STACK_SIZE = 4096; /* This is the size of stack when R5 is in SVC mode */
__ABORT_STACK_SIZE = 256;  /* This is the size of stack when R5 is in ABORT mode */
__UNDEFINED_STACK_SIZE = 256;  /* This is the size of stack when R5 is in UNDEF mode */

--define FILL_PATTERN=0xFEAA55EF
--define FILL_LENGTH=0x8

SECTIONS
{
    /* This has the R5F entry point and vector table, this MUST be at 0x0 */
    .vectors:{} palign(8) > TCMA_VEC_MCU
	.startupCode:{} palign(8) > TCMA_DATA_MCU
    .bootCode:{} palign(8) > TCMA_DATA_MCU
    .startupData: {} palign(8) > TCMA_DATA_MCU, type = NOINIT

    /* This has the R5F boot code until MPU is enabled,  this MUST be at a address < 0x80000000
     * i.e this cannot be placed in DDR
     */
    GROUP {
        .text.hwi: palign(8)
        .text.cache: palign(8)
        .text.mpu: palign(8)
        .text.boot: palign(8)
        .text:abort: palign(8) /* this helps in loading symbols when using XIP mode */
    } > TCMA_DATA_MCU

    #define mOS_LINK_CODE
    #define mOS_LINK_OSERROR_CODE
    #include "Os_Link.ld"
    /* This is rest of code. This can be placed in DDR if DDR is available and needed */
    GROUP {
        .text:    {
                    *(.OsCode)
                    *(.OsCORECode)
                    *(.OsERRORCode)
                  } palign(8)   /* This is where code resides */
        .rodata: {
                    *(.OsCOREConst)  
                    *(.I2cConst)
                 } palign(8)   /* This is where const's go */
    } > DDR_CODE_APP_MCU

    /* This is rest of initialized data. This can be placed in DDR if DDR is available and needed */
    GROUP {
        .data:   {} palign(8)   /* This is where initialized globals and static go */
    } > DDR_DATA_APP_MCU
    /* This is rest of uninitialized data. This can be placed in DDR if DDR is available and needed */
    GROUP {
        .bss:   {
                    *(.OsCFGData)
                     *(.common)
                     *(COMMON)
                    *(.bss_bsw)
                } palign(8)   /* This is where uninitialized globals go */
        RUN_START(__BSS_START)
        RUN_END(__BSS_END)
        .sysmem: {} palign(8)   /* This is where the malloc heap goes */
    } > DDR_DATA_APP_MCU

	GROUP {
		.safe_bss:   {
                } palign(8)   /* This is where uninitialized globals go */
        RUN_START(__BSS_SAFE_START)
        RUN_END(__BSS_SAFE_END)
        .sysmem: {} palign(8)   /* This is where the malloc heap goes */
    } > DDR_DATA_APP_MCU

    .stack      : {} align(4) > MSRAM_STACK_MCU  (HIGH) fill=FILL_PATTERN
    /* This is where the stacks for different R5F modes go */
    GROUP {
        /* Os stack initialization for Task and Isr*/
        #define LINK_INCLUDE_ALL_STACKS
        #include "osStacks.ld"
        .irqstack: {. = . + __IRQ_STACK_SIZE;} align(8)
        RUN_START(__IRQ_STACK_START)
        RUN_END(__IRQ_STACK_END)
        .fiqstack: {. = . + __FIQ_STACK_SIZE;} align(8)
        RUN_START(__FIQ_STACK_START)
        RUN_END(__FIQ_STACK_END)
        .svcstack: {. = . + __SVC_STACK_SIZE;} align(8)
        RUN_START(__SVC_STACK_START)
        RUN_END(__SVC_STACK_END)
        .abortstack: {. = . + __ABORT_STACK_SIZE;} align(8)
        RUN_START(__ABORT_STACK_START)
        RUN_END(__ABORT_STACK_END)
        .undefinedstack: {. = . + __UNDEFINED_STACK_SIZE;} align(8)
        RUN_START(__UNDEFINED_STACK_START)
        RUN_END(__UNDEFINED_STACK_END)
    } > MSRAM_STACK_MCU (HIGH)

    /* Sections needed for C++ projects */
    GROUP {
        .ARM.exidx:  {} palign(8)   /* Needed for C++ exception handling */
        .init_array: {} palign(8)   /* Contains function pointers called before main */
        .fini_array: {} palign(8)   /* Contains function pointers called after main */
    } > DDR_CODE_APP_MCU
}

/*
NOTE: Below memory is reserved for DMSC usage
 - During Boot till security handoff is complete
   0x701E0000 - 0x701FFFFF (128KB)
 - After "Security Handoff" is complete (i.e at run time)
   0x701F4000 - 0x701FFFFF (48KB)

 Security handoff is complete when this message is sent to the DMSC,
   TISCI_MSG_SEC_HANDOVER

 This should be sent once all cores are loaded and all application
 specific firewall calls are setup.
*/

MEMORY
{
    TCMA_VEC_MCU     (RWIX)   : ORIGIN = 0x00000000 LENGTH = 0x00000040 /* 64B MCU R5F Vector Table */
    TCMA_DATA_MCU    (RWIX)   : ORIGIN = 0x00000040 LENGTH = 0x00007FBF /* 32KB Keep critical feature data like MCAL, OS and etc */
    MSRAM_STACK_MCU           : ORIGIN = 0x79100000 LENGTH = 0x0001FFFF /* 128KB VIP Stack */
    DDR_DATA_SHDMEM_MCU       : ORIGIN = 0x82400000 LENGTH = 0x00200000 /* 2MB VIP & GIP shared memory for Software Update */
    DDR_CODE_APP_MCU          : ORIGIN = 0x82600000 LENGTH = 0x003FFFFF /* 5120KB VIP Application - MCU */
    DDR_DATA_APP_MCU          : ORIGIN = 0x82A00000 LENGTH = 0x000FFFFF /* 1024KB VIP Application Data Early HMI Use Case */
}

SECTIONS
{
 McalTextSection : fill=FILL_PATTERN, align=4, load > DDR_CODE_APP_MCU
 {
    .=align(4);
        __linker_gpt_text_start = .;
        . += FILL_LENGTH;
        *(GPT_TEXT_SECTION)
        *(GPT_ISR_TEXT_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_gpt_text_end = .;

	.=align(4);
        __linker_can_text_start = .;
        . += FILL_LENGTH;
        *(CAN_TEXT_SECTION)
        *(CAN_ISR_TEXT_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_can_text_end = .;

    .=align(4);
        __linker_dio_text_start = .;
        . += FILL_LENGTH;
        *(DIO_TEXT_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_dio_text_end = .;

    .=align(4);
        __linker_wdg_text_start = .;
        . += FILL_LENGTH;
        *(WDG_TEXT_SECTION)
        *(WDG_ISR_TEXT_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_wdg_text_end = .;

	.=align(4);
        __linker_cdd_ipc_text_start = .;
        . += FILL_LENGTH;
        *(CDD_IPC_TEXT_SECTION)
        *(CDD_IPC_ISR_TEXT_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_cdd_ipc_text_end = .;

	.=align(4);
        __linker_mcu_text_start = .;
        . += FILL_LENGTH;
        *(MCU_TEXT_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_mcu_text_end = .;

	}

	 McalConstSection : fill=FILL_PATTERN, align=4, load > DDR_DATA_APP_MCU
    {
        .=align(4);
        __linker_gpt_const_start = .;
        . += FILL_LENGTH;
        *(GPT_CONST_32_SECTION)
        *(GPT_CONFIG_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_gpt_const_end = .;

        .=align(4);
        __linker_dio_const_start = .;
        . += FILL_LENGTH;
        *(DIO_CONST_32_SECTION)
        *(DIO_CONST_UNSPECIFIED_SECTION)
        *(DIO_CONFIG_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_dio_const_end = .;
        .=align(4);
        __linker_can_const_start = .;
        . += FILL_LENGTH;
        *(CAN_CONST_8_SECTION)
        *(CAN_CONST_32_SECTION)
        *(CAN_CONFIG_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_can_const_end = .;

	.=align(4);
        __linker_wdg_const_start = .;
        . += FILL_LENGTH;
        *(WDG_CONST_32_SECTION)
        *(WDG_CONFIG_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_wdg_const_end = .;

	.=align(4);
        __linker_cdd_ipc_const_start = .;
        . += FILL_LENGTH;
        *(CDD_IPC_CONST_32_SECTION)
        *(CDD_IPC_CONFIG_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_cdd_ipc_const_end = .;

	.=align(4);
        __linker_mcu_const_start = .;
        . += FILL_LENGTH;
        *(MCU_CONST_8_SECTION)
        *(MCU_CONST_32_SECTION)
        *(MCU_CONFIG_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_mcu_const_end = .;
	}

	McalInitSection : fill=FILL_PATTERN, align=4, load > DDR_DATA_APP_MCU
    {
        .=align(4);
        __linker_gpt_init_start = .;
        . += FILL_LENGTH;
        *(GPT_DATA_INIT_32_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_gpt_init_end = .;
        .=align(4);
        __linker_dio_init_start = .;
        . += FILL_LENGTH;
        *(DIO_DATA_INIT_32_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_dio_init_end = .;
        .=align(4);
        __linker_can_init_start = .;
        . += FILL_LENGTH;
        *(CAN_DATA_INIT_8_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_can_init_end = .;

	.=align(4);
        __linker_wdg_init_start = .;
        . += FILL_LENGTH;
        *(WDG_DATA_INIT_UNSPECIFIED_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_wdg_init_end = .;

		.=align(4);
        __linker_cdd_ipc_init_start = .;
        . += FILL_LENGTH;
        *(CDD_IPC_DATA_INIT_UNSPECIFIED_SECTION)
        *(CDD_IPC_DATA_INIT_32_SECTION)
        *(CDD_IPC_DATA_INIT_8_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_cdd_ipc_init_end = .;

        .=align(4);
        __linker_mcu_init_start = .;
        . += FILL_LENGTH;
        *(MCU_DATA_INIT_8_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_mcu_init_end = .;

	}

	 McalNoInitSection : fill=FILL_PATTERN, align=4, load > DDR_DATA_APP_MCU, type = NOINIT
    {
        .=align(4);
        __linker_gpt_no_init_start = .;
        . += FILL_LENGTH;
        *(GPT_DATA_NO_INIT_UNSPECIFIED_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_gpt_no_init_end = .;
        .=align(4);
        __linker_dio_no_init_start = .;
        . += FILL_LENGTH;
        *(DIO_DATA_NO_INIT_UNSPECIFIED_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_dio_no_init_end = .;

        .=align(4);
        __linker_can_no_init_start = .;
        . += FILL_LENGTH;
        *(CAN_DATA_NO_INIT_UNSPECIFIED_SECTION)
        *(CAN_DATA_NO_INIT_32_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_can_no_init_end = .;

	.=align(4);
        __linker_wdg_no_init_start = .;
        . += FILL_LENGTH;
        *(WDG_DATA_NO_INIT_UNSPECIFIED_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_wdg_no_init_end = .;
	.=align(4);
	__linker_cdd_ipc_no_init_start = .;
        . += FILL_LENGTH;
        *(CDD_IPC_DATA_NO_INIT_UNSPECIFIED_SECTION)
        *(CDD_IPC_DATA_NO_INIT_8_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_cdd_ipc_no_init_end = .;

	.=align(4);
        __linker_mcu_no_init_start = .;
        . += FILL_LENGTH;
        *(MCU_DATA_NO_INIT_UNSPECIFIED_SECTION)
        *(MCU_DATA_NO_INIT_32_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_mcu_no_init_end = .;
	}
    /* Example Utility specifics */

	    VariablesAlignedNoInitSection : align=8, load > DDR_DATA_APP_MCU, type = NOINIT
    {
        .=align(8);
        __linker_cdd_ipc_no_init_align_8b_start = .;
        . += FILL_LENGTH;
        *(CDD_IPC_DATA_NO_INIT_8_ALIGN_8B_SECTION)
        .=align(8);
        . += FILL_LENGTH;
        __linker_cdd_ipc_no_init_align_8b_end = .;
    }

	.SharedMemSection : > DDR_DATA_SHDMEM_MCU
}
