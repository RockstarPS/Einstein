

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
--define FILL_LENGTH=0x100

SECTIONS
{
    /* This has the R5F entry point and vector table, this MUST be at 0x0 */
    GROUP {
    .vectors:{} palign(8)
    .text:abort: {}palign(8) /* this helps in loading symbols when using XIP mode */
    } > TCMA_VEC_MCU

    /* This has the R5F boot code until MPU is enabled,  this MUST be at a address < 0x80000000
     * i.e this cannot be placed in DDR
     */
    GROUP {
        .startupCode:{} palign(8)
        RUN_START(__TCMA_TEXTSECTION_START)
        .bootCode:{} palign(8)
        .startupData: {} palign(8), type = NOINIT
        .text.hwi: {} palign(8)
        .text.cache:{} palign(8)
        .text.mpu: {}palign(8)
        .text.boot: {}palign(8)
        RUN_END(__TCMA_TEXTSECTION_END)
    } > TCMA_DATA_MCU

    GROUP {
        .OsCOREBss_NoCache: palign(8)
        .OsCOREData: palign(8)
        .OsCOREBss: palign(8)
        .OsINTVECTBss_NoCache: palign(8)
        .OsINTVECTBss: palign(8)
        .OsCFGBss: palign(8)
        .OsCFGBss_NoCache: palign(8)
    } > TCMA_DATA_MCU

    #define mOS_LINK_CODE
    #define mOS_LINK_OSERROR_CODE
    #include "Os_Link.ld"
    /* This is rest of code. This can be placed in DDR if DDR is available and needed */
    GROUP {
        .text:  {
                    *(.oscode)
                    *(.OsCode)
                    *(.OsCORECode)
                    *(.OsERRORCode)
                    /* McalTextSection */
                    *(SPI_TEXT_SECTION)
                    *(SPI_ISR_TEXT_SECTION)
                    *(GPT_TEXT_SECTION)
                    *(GPT_ISR_TEXT_SECTION)
                    *(CAN_TEXT_SECTION)
                    *(CAN_ISR_TEXT_SECTION)
                    *(DIO_TEXT_SECTION)
                    *(CDD_IPC_TEXT_SECTION)
                    *(CDD_IPC_ISR_TEXT_SECTION)
                    *(MCU_TEXT_SECTION)
                    *(I2C_ISR_TEXT_SECTION)
                    *(PWM_TEXT_SECTION)
                    /* SafeBsw TextSection*/
                    *(PMICCDD_SEC_CODE_SECTION)
                    *(WDGMGR_SEC_CODE_SECTION)
                    *(WDGIF_SEC_CODE_SECTION)
                  } palign(8)   /* This is where code resides */
                  RUN_START(__DDR_TEXTSECTION_START)
        .rodata:{
                      *(.OsCOREConst)
                      *(.osIrqVecTab)
                      *(.osconst)
                      *(.osArmExcVecTab)
                      /* *(.SafeRoData.SafeNvM) */
                  } palign(8)   /* This is where const's go */
                  RUN_END(__DDR_TEXTSECTION_END)
              } > DDR_CODE_APP_MCU

    GROUP {
        .textchecksum :{
                        *(.textchecksum) 
                        }palign(4) 
                    }> DDR_CODE_APP_CHKSUM
    GROUP {
        .bss:   { 
             *(.ipc_vring_mem)
        }palign(8192)
    }>DDR_IPC_VRING_RTOS
       
    /* This is rest of initialized data. This can be placed in DDR if DDR is available and needed */
    GROUP {
            .os_data:
            {   
              *(.OsCFGData) 
              *(.OsCFGData_NoCache)
              *(.OsCOREData_NoCache)  
              *(.OsINTVECTData)
              *(.OsINTVECTData_NoCache)
            } palign(8)   /* This is where initialized globals and static go */
          } > TCMB_DATA_MCU
		  
    GROUP {
            .data:
            {
              *(.data)
            } palign(8)   /* This is where initialized globals and static go */
          } > MSRAM_DATA_QM_MCU

	.MSRAM_Conf.buffer  : {} > TCMB_DATA_MCU
	.DATA_Cache.buffer  : {} > DDR_CACHE

    GROUP {
        .dss_data:  {
                        *(.data.gDss*)
                        *(.data.gVp*)
                    } palign(8)
        .gdt_data:  {
                            *(.data.l_cntx_init_status)
                            *(GFX02_LAYOUT_RW_DATA)
                            *(GFX02_LAYERDEF_RW_DATA)
                            *(GFX02_DAR_RW_DATA)
                            *(GFX02_IMGDEF_RW_DATA)
                    } palign(8)
        .hmi_data:  {
                        *(.data.l_ehmi_status_flag)
                        *(.data.l_vsync_event)
                    } palign(8)
    } > DDR_DATA_APP_MCU

    GROUP {
        .gdt_ro_data: {
                            *(GFX02_IMGDEF_RO_DATA)
                            *(GFX02_LAYERDEF_RO_DATA)
                      }
    } > DDR_DATA_APP_MCU 
    
    /* This is rest of uninitialized data. This can be placed in DDR if DDR is available and needed */


GROUP {
    .bss:
      {
        .=align(8);
        *(.bss.Cdd_IpcRpMsgCtrlBuffer)
        .=align(8);
        *(.bss.Cdd_IpcAppMpu10Buffer)
        .=align(8);
        Cdd_Ipc.c.obj*(.bss.Cdd_IpcDrvObj)
        .=align(8);
        *(.bss.Cdd_Ipc)
        .=align(8);
        *(.bss_bsw)
        *(.bss)
        *(.buram)
        } palign(8)
        RUN_START(__BSS_START)
        RUN_END(__BSS_END)
        .sysmem: {} palign(8)   /* This is where the malloc heap goes */
    } > DDR_DATA_APP_MCU

    GROUP {
        .SafeBss:
                {
                  *(.SafeBss.PmicCdd)
                  *(.SafeBss.WdgMgr)
                  *(.SafeBss.WdgIf)
                  *(.SafeBss.SafeNvM*)
                  *(.SafeBss.FltM*)
                  *(.SafeBss.RstM*)
                  *(.SafeBss.ComAbsMdlSafe*)
                  *(.SafeBss.COMXF*)
                  *(.SafeBss.E2EXF*)
                  
                  *(.SafeBss.*)
                 /*(.bss.Rte_MemAbstract_Stub_Safe_BsConst*)*/
              } palign(8)   /* This is where uninitialized globals go */
        RUN_START(__BSS_SAFE_START)
        RUN_END(__BSS_SAFE_END)
        .sysmem: {} palign(8)   /* This is where the malloc heap goes */
    } > MSRAM_DATA_ASIL_MCU
	
   GROUP {
        .SafeData:
                {
                  *(.SafeData.SafeNvM)
                  *(.SafeData.FltM)
                  *(.SafeData.RstM)
                  *(.SafeData.Rte)
                  *(.SafeData.PmicCdd)
                  *(.SafeData.ComAbsMdlSafe)
                  *(.SafeData.COMXF)
                  *(.SafeData.E2EXF)
                  *(.SafeData.WdgMgr)
                  *(.SafeData.WdgIf)
                  *(.SafeData.*)
                  *(.SafeDataSegmentStart)
                 /* *(.data.Rte_MemAbstract_Stub_Safe_BsConst*)*/
              } palign(8)   /* This is where uninitialized globals go */
        RUN_START(__DATA_SAFE_START)
        RUN_END(__DATA_SAFE_END)
        .sysmem: {} palign(8)   /* This is where the malloc heap goes */
    } > MSRAM_DATA_ASIL_MCU

    .bss:ipc_vring_mem   (NOLOAD) : {} > DDR_IPC_VRING_RTOS
    
    .resource_table : {
        __RESOURCE_TABLE = .;
    } > DDR0_MCU_0_0_RSTB
    

    
    .stack      : {} align(8) > MSRAM_STACK_MCU  fill=FILL_PATTERN
    /* This is where the stacks for different R5F modes go */
    GROUP {
        /* Os stack initialization for Task and Isr*/
        #define LINK_INCLUDE_ALL_STACKS
        #include "../../bsw-gen/bsw/os/OsStacks.ld"
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
    } > MSRAM_STACK_MCU

    /* Sections needed for C++ projects */
    GROUP {
        .ARM.exidx:  {} palign(8)   /* Needed for C++ exception handling */
        .init_array: {} palign(8)   /* Contains function pointers called before main */
        .fini_array: {} palign(8)   /* Contains function pointers called after main */
    } > DDR_CODE_APP_MCU

    /* DSS frame buffer region */
    .dssFrameBuffer (NOLOAD) : {} > DDR1
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
    TCMA_VEC_MCU     (RWIX)   : ORIGIN = 0x00000000 LENGTH = 0x000000FF /* 64B MCU R5F Vector Table */
    TCMA_DATA_MCU    (RWIX)   : ORIGIN = 0x00000100 LENGTH = 0x00007FBF /* 32KB Keep critical feature data like MCAL, OS and etc */
    TCMB_DATA_MCU    (RWIX)   : ORIGIN = 0x41010400 LENGTH = 0x00007BFF /* 32KB Keep critical feature data like MCAL, OS and etc */
    MSRAM_CODE_MCU            : ORIGIN = 0x79100000 LENGTH = 0x0001FFFF /* 128KB Instruction RAM VIP Critical Application Code Execution like OS, ISRs and etc */
    MSRAM_STACK_MCU           : ORIGIN = 0x79120000 LENGTH = 0x0001FFFF /* 128KB VIP Stack */
    MSRAM_DATA_ASIL_MCU       : ORIGIN = 0x79140000 LENGTH = 0x00007FFF /* 32KB VIP Safety */
    MSRAM_DATA_QM_MCU         : ORIGIN = 0x79158000 LENGTH = 0x00026FFF /* 155KB VIP QM Software */
    MSRAM_RETENTION_MGMT_MCU  : ORIGIN = 0x7917F000 LENGTH = 0x00000020 /* 32 bytes Retention RAM management */
    MSRAM_RETENTION_GROUP1_MCU : ORIGIN = 0x7917F020 LENGTH = 0x00000FE0 /* 4064 bytes Retention RAM Group 1*/
    DDR_CODE_APP_CHKSUM       : ORIGIN = 0x82600000 LENGTH = 0x00000020 /* 32 bytes - checksum - 2 bytes only used*/
    DDR_CODE_APP_MCU          : ORIGIN = 0x82600020 LENGTH = 0x003FFFDF /* 5118KB VIP Application - MCU */
    DDR_DATA_APP_MCU          : ORIGIN = 0x82A00000 LENGTH = 0x000FFFFF /* 1024KB VIP Application Data Early HMI Use Case */
    QSPI_CODE_BM_MCU          : ORIGIN = 0x60240000 LENGTH = 0x0000FFFF /* 64KB Flash Bootloader - Boot Manger */
    QSPI_CODE_FBL_MCU         : ORIGIN = 0x60250000 LENGTH = 0x0003FFFF /* 256KB Flash Bootloader - Primary, Flash Boot Loader Application */
    QSPI_CODE_APP_DDR_MCU     : ORIGIN = 0x60B00000 LENGTH = 0x003FFFFF /* 4096KB VIP Application - DDR, VIP Application Runs from DDR */
    QSPI_CODE_APP_CAL_MCU     : ORIGIN = 0x60F00000 LENGTH = 0x0007FFFF /* 512KB VIP Application - Calibration/Cfg, OEM Speicifc Calibration/Meet Calibration */
    QSPI_CODE_APP_SRAM_MCU    : ORIGIN = 0x60F80000 LENGTH = 0x0003FFFF /* 256KB VIP Application - RAM, Crtical Application runs from RAM for perfromance */
    QSPI_CODE_APP_OEM_MCU     : ORIGIN = 0x60FC0000 LENGTH = 0x0003FFFF /* 256KB VIP Application - OEM, OEM Specific SWCs */
    QPSI_WAVE_APP_MCU         : ORIGIN = 0x61000000 LENGTH = 0x007FFFFF /* 8192KB VIP Application - WaveFiles, Sound Wave Files */
    DDR0_MCU_0_0_RSTB (RWIX)  : ORIGIN = 0x81640000 LENGTH = 0x400
    /* DSS frame buffer region in DDR (128 MiB) */
    DDR1           (RWIX)      : ORIGIN = 0x93500000 LENGTH = 0x08000000
    DDR_DATA_SHDMEM_MCU       : ORIGIN = 0x82400000 LENGTH = 0x00200000 /* 2048KB VIP & GIP shared memory for Software Update */
    DDR_DATA_SHDMEM_DLT_BANK1 : ORIGIN = 0x82385000 LENGTH = 0x00000800 /* 2KB VIP & GIP shared memory for UCL */
    DDR_DATA_SHDMEM_DLT_BANK2 : ORIGIN = 0x82385800 LENGTH = 0x00000800 /* 2KB VIP & GIP shared memory for UCL */
    DDR_RESET_HISTORY_DUMP    : ORIGIN = 0x82386000 LENGTH = 0x00001000 /* 4KB  VIP & GIP shared memory for Reset Dump */
    DDR_IPC_VRING_RTOS        : ORIGIN = 0x82B00000, LENGTH = 0x100000   /* IPC VRING for RTOS/NoRTOS */
    DDR_CACHE                 : ORIGIN = 0xA0400000, LENGTH = 0x20000   /* DDR Cache */
}

SECTIONS
{
  .Sharedata_DltAppInfoBank1 > DDR_DATA_SHDMEM_DLT_BANK1
  .Sharedata_DltAppInfoBank2 > DDR_DATA_SHDMEM_DLT_BANK2
  .Sharedata_DltResetInfo > DDR_RESET_HISTORY_DUMP 
}

SECTIONS
{
  RententionRamSection_MgMt : fill=FILL_PATTERN, align=4, load > MSRAM_RETENTION_MGMT_MCU
  {
    .=align(4);
    __NvMExt_RetRAM_MgMt_START = .;
    .=align(4);
    *(.RetentionRAM_Group0)
    __NvMExt_RetRAM_MgMt_END = .;
    __NvMExt_RetRAM_MgMt_SIZE = __NvMExt_RetRAM_MgMt_END - __NvMExt_RetRAM_MgMt_START;
  }
  RententionRamSection_Group1 : fill=FILL_PATTERN, align=4, load > MSRAM_RETENTION_GROUP1_MCU
  {
    .=align(4);
    __NvMExt_RetRAM_GP1_START = .;
    *(.RetentionRAM_Group1)
    __NvMExt_RetRAM_GP1_END = .;
    __NvMExt_RetRAM_GP1_SIZE = __NvMExt_RetRAM_GP1_END - __NvMExt_RetRAM_GP1_START;
  }
	
	 McalConstSection : fill=FILL_PATTERN, align=4, load > DDR_DATA_APP_MCU
    {
    
    	.=align(4);
        __linker_spi_const_start = .;
        . += FILL_LENGTH;
        *(SPI_CONST_32_SECTION)
        *(SPI_CONFIG_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_spi_const_end = .;
		
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
        __linker_eth_const_start = .;
        . += FILL_LENGTH;
        *(ETH_CONST_32_SECTION)
        *(ETH_CONFIG_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_eth_const_end = .;

        .=align(4);
        __linker_ethtrcv_const_start = .;
        . += FILL_LENGTH;
        *(ETHTRCV_CONST_32_SECTION)
        *(ETHTRCV_CONFIG_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_ethtrcv_const_end = .;
	
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
        __linker_spi_init_start = .;
        . += FILL_LENGTH;
        *(SPI_DATA_INIT_UNSPECIFIED_SECTION)
        *(SPI_CONST_UNSPECIFIED_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_spi_init_end = .;
       
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
        __linker_eth_init_start = .;
        . += FILL_LENGTH;
        *(ETH_DATA_INIT_UNSPECIFIED_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_eth_init_end = .;

        .=align(4);
        __linker_ethtrcv_init_start = .;
        . += FILL_LENGTH;
        *(ETHTRCV_DATA_INIT_UNSPECIFIED_SECTION)
        *(ETHTRCV_DATA_INIT_32_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_ethtrcv_init_end = .;
	
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
        *(CDD_IPC_DATA_INIT_PTR_SECTION)
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

        .=align(4);
        __linker_pwm_init_start = .;
        . += FILL_LENGTH;
        *(PWM_DATA_INIT_32_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_pwm_init_end = .;
	}
	
	 McalNoInitSection : fill=FILL_PATTERN, align=4, load > DDR_DATA_APP_MCU, type = NOINIT
    {
    
        .=align(4);
        __linker_spi_no_init_start = .;
        . += FILL_LENGTH;
        *(SPI_DATA_NO_INIT_UNSPECIFIED_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_spi_no_init_end = .;
	
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
        __linker_eth_no_init_start = .;
        . += FILL_LENGTH;
        *(ETH_DATA_NO_INIT_UNSPECIFIED_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_eth_no_init_end = .;

        .=align(128);
        __linker_eth_no_init_128_start = .;
        . += FILL_LENGTH;
        *(ETH_DATA_NO_INIT_UNSPECIFIED_SECTION_128)
        .=align(128);
        . += FILL_LENGTH;
        __linker_eth_no_init_128_end = .;

        .=align(4);
        __linker_ethtrcv_no_init_start = .;
        . += FILL_LENGTH;
        *(ETHTRCV_DATA_NO_INIT_UNSPECIFIED_SECTION)
        *(ETHTRCV_DATA_NO_INIT_16_SECTION)
        .=align(4);
        . += FILL_LENGTH;
        __linker_ethtrcv_no_init_end = .;
	
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
