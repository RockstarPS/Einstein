/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2026 by Visteon Corporation.       All rights reserved.         
*                                                                                                                    
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                   
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve              
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States     
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,             
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its       
* rights under all copyright laws to protect this work as a published work, when appropriate.                        
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it   
* without the written authorization of Visteon Corporation.                                                          
********************************************************************************************************************/

/*******************************************************************************************************************
*    @file Os_IsrCfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.371017500
********************************************************************************************************************/

#ifndef OS_ISRCFG_H
#define OS_ISRCFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/


                                                                           
                                                                              
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/

#define OsNumberOfIsr                                     43U
#define osdNumberOfCat2ISRs                               43

/*****************************************************************************
*                               Isr Stack Table                              *
******************************************************************************/
#define osStackStartAddressIsr_0                (osStackPtrType)osdMcuOsGptIsr_TOP
#define osStackSizeIsr_0                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_1                (osStackPtrType)osdMcuCan0RxTxIsr_TOP
#define osStackSizeIsr_1                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_2                (osStackPtrType)osdMcuCan1RxTxIsr_TOP
#define osStackSizeIsr_2                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_3                (osStackPtrType)osdMcuSpi0NvmRxTxIsr_TOP
#define osStackSizeIsr_3                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_4                (osStackPtrType)osdMcuDss0Isr_TOP
#define osStackSizeIsr_4                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_5                (osStackPtrType)osdMcuI2c3IoIsr_TOP
#define osStackSizeIsr_5                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_6                (osStackPtrType)osdEth_TxIrqHdlr_0_TOP
#define osStackSizeIsr_6                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_7                (osStackPtrType)osdEth_RxIrqHdlr_0_TOP
#define osStackSizeIsr_7                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_8                (osStackPtrType)osdEth_MdioIrqHdlr_TOP
#define osStackSizeIsr_8                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_9                (osStackPtrType)osdFltM_WkupEsmHiInterrupt_TOP
#define osStackSizeIsr_9                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_10               (osStackPtrType)osdMCU_IntrISR_UART0_TOP
#define osStackSizeIsr_10                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_11               (osStackPtrType)osdMcuI2c0PmicIsr_TOP
#define osStackSizeIsr_11                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_12               (osStackPtrType)osdGpt_Ch3Isr_TOP
#define osStackSizeIsr_12                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_13               (osStackPtrType)osdGpt_Ch4Isr_TOP
#define osStackSizeIsr_13                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_14               (osStackPtrType)osdSpi_IrqUnitMcspi2TxRx_TOP
#define osStackSizeIsr_14                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_15               (osStackPtrType)osdMCU_ISR_6_TOP
#define osStackSizeIsr_15                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_16               (osStackPtrType)osdMAIN_ISR_34_TOP
#define osStackSizeIsr_16                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_17               (osStackPtrType)osdMAIN_ISR_35_TOP
#define osStackSizeIsr_17                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_18               (osStackPtrType)osdMCU_ISR_7_TOP
#define osStackSizeIsr_18                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_19               (osStackPtrType)osdFltM_WkupEsmCfgInterrupt_TOP
#define osStackSizeIsr_19                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_20               (osStackPtrType)osdFltM_WkupEsmLowInterrupt_TOP
#define osStackSizeIsr_20                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_21               (osStackPtrType)osdSpi_IrqUnitMcspi0TxRx_TOP
#define osStackSizeIsr_21                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_22               (osStackPtrType)osdMainI2c2RtcIsr_TOP
#define osStackSizeIsr_22                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_23               (osStackPtrType)osdMCU_ResetIsolationReq_TOP
#define osStackSizeIsr_23                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_24               (osStackPtrType)osdFltM_FwlExceptionInterrupt_TOP
#define osStackSizeIsr_24                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_25               (osStackPtrType)osdCdd_IpcIrqMbxFromWKUP_R5FSS0_0_TOP
#define osStackSizeIsr_25                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_26               (osStackPtrType)osdMcu_Udma_Vintr64_TOP
#define osStackSizeIsr_26                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_27               (osStackPtrType)osdMcu_Udma_Vintr65_TOP
#define osStackSizeIsr_27                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_28               (osStackPtrType)osdMcu_Udma_Vintr66_TOP
#define osStackSizeIsr_28                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_29               (osStackPtrType)osdMcu_Udma_Vintr67_TOP
#define osStackSizeIsr_29                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_30               (osStackPtrType)osdMcu_Udma_Vintr68_TOP
#define osStackSizeIsr_30                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_31               (osStackPtrType)osdMcu_Udma_Vintr69_TOP
#define osStackSizeIsr_31                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_32               (osStackPtrType)osdMcu_Udma_Vintr70_TOP
#define osStackSizeIsr_32                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_33               (osStackPtrType)osdMcu_Udma_Vintr71_TOP
#define osStackSizeIsr_33                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_34               (osStackPtrType)osdMcu_Udma_Vintr72_TOP
#define osStackSizeIsr_34                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_35               (osStackPtrType)osdMcu_Udma_Vintr73_TOP
#define osStackSizeIsr_35                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_36               (osStackPtrType)osdMcu_Udma_Vintr74_TOP
#define osStackSizeIsr_36                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_37               (osStackPtrType)osdMcu_Udma_Vintr75_TOP
#define osStackSizeIsr_37                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_38               (osStackPtrType)osdMcu_Udma_Vintr76_TOP
#define osStackSizeIsr_38                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_39               (osStackPtrType)osdMcu_Udma_Vintr77_TOP
#define osStackSizeIsr_39                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_40               (osStackPtrType)osdMcu_Udma_Vintr78_TOP
#define osStackSizeIsr_40                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_41               (osStackPtrType)osdMcu_Udma_Vintr79_TOP
#define osStackSizeIsr_41                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_42               (osStackPtrType)osdMainI2c1DacIsr_TOP
#define osStackSizeIsr_42                       (osStackDataType)sizeof(osLevelStackCore0Level0)



/*****************************************************************************
*                               Isr Configs                                  *
******************************************************************************/
/********************** Isr 0***********************/
#define osIsrId_McuOsGptIsr                     0UL
#define osIsrPrioLevel_McuOsGptIsr              0UL

/********************** Isr 1***********************/
#define osIsrId_McuCan0RxTxIsr                  1UL
#define osIsrPrioLevel_McuCan0RxTxIsr           1UL

/********************** Isr 2***********************/
#define osIsrId_McuCan1RxTxIsr                  2UL
#define osIsrPrioLevel_McuCan1RxTxIsr           2UL

/********************** Isr 3***********************/
#define osIsrId_McuSpi0NvmRxTxIsr               3UL
#define osIsrPrioLevel_McuSpi0NvmRxTxIsr        6UL

/********************** Isr 4***********************/
#define osIsrId_McuDss0Isr                      4UL
#define osIsrPrioLevel_McuDss0Isr               8UL

/********************** Isr 5***********************/
#define osIsrId_McuI2c3IoIsr                    5UL
#define osIsrPrioLevel_McuI2c3IoIsr             12UL

/********************** Isr 6***********************/
#define osIsrId_Eth_TxIrqHdlr_0                 6UL
#define osIsrPrioLevel_Eth_TxIrqHdlr_0          8UL

/********************** Isr 7***********************/
#define osIsrId_Eth_RxIrqHdlr_0                 7UL
#define osIsrPrioLevel_Eth_RxIrqHdlr_0          9UL

/********************** Isr 8***********************/
#define osIsrId_Eth_MdioIrqHdlr                 8UL
#define osIsrPrioLevel_Eth_MdioIrqHdlr          12UL

/********************** Isr 9***********************/
#define osIsrId_FltM_WkupEsmHiInterrupt         9UL
#define osIsrPrioLevel_FltM_WkupEsmHiInterrupt  9UL

/********************** Isr 10***********************/
#define osIsrId_MCU_IntrISR_UART0               10UL
#define osIsrPrioLevel_MCU_IntrISR_UART0        17UL

/********************** Isr 11***********************/
#define osIsrId_McuI2c0PmicIsr                  11UL
#define osIsrPrioLevel_McuI2c0PmicIsr           13UL

/********************** Isr 12***********************/
#define osIsrId_Gpt_Ch3Isr                      12UL
#define osIsrPrioLevel_Gpt_Ch3Isr               14UL

/********************** Isr 13***********************/
#define osIsrId_Gpt_Ch4Isr                      13UL
#define osIsrPrioLevel_Gpt_Ch4Isr               16UL

/********************** Isr 14***********************/
#define osIsrId_Spi_IrqUnitMcspi2TxRx           14UL
#define osIsrPrioLevel_Spi_IrqUnitMcspi2TxRx    21UL

/********************** Isr 15***********************/
#define osIsrId_MCU_ISR_6                       15UL
#define osIsrPrioLevel_MCU_ISR_6                15UL

/********************** Isr 16***********************/
#define osIsrId_MAIN_ISR_34                     16UL
#define osIsrPrioLevel_MAIN_ISR_34              18UL

/********************** Isr 17***********************/
#define osIsrId_MAIN_ISR_35                     17UL
#define osIsrPrioLevel_MAIN_ISR_35              19UL

/********************** Isr 18***********************/
#define osIsrId_MCU_ISR_7                       18UL
#define osIsrPrioLevel_MCU_ISR_7                20UL

/********************** Isr 19***********************/
#define osIsrId_FltM_WkupEsmCfgInterrupt        19UL
#define osIsrPrioLevel_FltM_WkupEsmCfgInterrupt 10UL

/********************** Isr 20***********************/
#define osIsrId_FltM_WkupEsmLowInterrupt        20UL
#define osIsrPrioLevel_FltM_WkupEsmLowInterrupt 11UL

/********************** Isr 21***********************/
#define osIsrId_Spi_IrqUnitMcspi0TxRx           21UL
#define osIsrPrioLevel_Spi_IrqUnitMcspi0TxRx    22UL

/********************** Isr 22***********************/
#define osIsrId_MainI2c2RtcIsr                  22UL
#define osIsrPrioLevel_MainI2c2RtcIsr           23UL

/********************** Isr 23***********************/
#define osIsrId_MCU_ResetIsolationReq           23UL
#define osIsrPrioLevel_MCU_ResetIsolationReq    24UL

/********************** Isr 24***********************/
#define osIsrId_FltM_FwlExceptionInterrupt      24UL
#define osIsrPrioLevel_FltM_FwlExceptionInterrupt          25UL

/********************** Isr 25***********************/
#define osIsrId_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0  25UL
#define osIsrPrioLevel_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0          26UL

/********************** Isr 26***********************/
#define osIsrId_Mcu_Udma_Vintr64                26UL
#define osIsrPrioLevel_Mcu_Udma_Vintr64         27UL

/********************** Isr 27***********************/
#define osIsrId_Mcu_Udma_Vintr65                27UL
#define osIsrPrioLevel_Mcu_Udma_Vintr65         28UL

/********************** Isr 28***********************/
#define osIsrId_Mcu_Udma_Vintr66                28UL
#define osIsrPrioLevel_Mcu_Udma_Vintr66         29UL

/********************** Isr 29***********************/
#define osIsrId_Mcu_Udma_Vintr67                29UL
#define osIsrPrioLevel_Mcu_Udma_Vintr67         30UL

/********************** Isr 30***********************/
#define osIsrId_Mcu_Udma_Vintr68                30UL
#define osIsrPrioLevel_Mcu_Udma_Vintr68         31UL

/********************** Isr 31***********************/
#define osIsrId_Mcu_Udma_Vintr69                31UL
#define osIsrPrioLevel_Mcu_Udma_Vintr69         32UL

/********************** Isr 32***********************/
#define osIsrId_Mcu_Udma_Vintr70                32UL
#define osIsrPrioLevel_Mcu_Udma_Vintr70         33UL

/********************** Isr 33***********************/
#define osIsrId_Mcu_Udma_Vintr71                33UL
#define osIsrPrioLevel_Mcu_Udma_Vintr71         34UL

/********************** Isr 34***********************/
#define osIsrId_Mcu_Udma_Vintr72                34UL
#define osIsrPrioLevel_Mcu_Udma_Vintr72         35UL

/********************** Isr 35***********************/
#define osIsrId_Mcu_Udma_Vintr73                35UL
#define osIsrPrioLevel_Mcu_Udma_Vintr73         36UL

/********************** Isr 36***********************/
#define osIsrId_Mcu_Udma_Vintr74                36UL
#define osIsrPrioLevel_Mcu_Udma_Vintr74         37UL

/********************** Isr 37***********************/
#define osIsrId_Mcu_Udma_Vintr75                37UL
#define osIsrPrioLevel_Mcu_Udma_Vintr75         38UL

/********************** Isr 38***********************/
#define osIsrId_Mcu_Udma_Vintr76                38UL
#define osIsrPrioLevel_Mcu_Udma_Vintr76         39UL

/********************** Isr 39***********************/
#define osIsrId_Mcu_Udma_Vintr77                39UL
#define osIsrPrioLevel_Mcu_Udma_Vintr77         40UL

/********************** Isr 40***********************/
#define osIsrId_Mcu_Udma_Vintr78                40UL
#define osIsrPrioLevel_Mcu_Udma_Vintr78         41UL

/********************** Isr 41***********************/
#define osIsrId_Mcu_Udma_Vintr79                41UL
#define osIsrPrioLevel_Mcu_Udma_Vintr79         42UL

/********************** Isr 42***********************/
#define osIsrId_MainI2c1DacIsr                  42UL
#define osIsrPrioLevel_MainI2c1DacIsr           43UL



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

