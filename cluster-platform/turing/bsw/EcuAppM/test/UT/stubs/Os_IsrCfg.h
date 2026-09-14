/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2025 by Visteon Corporation.       All rights reserved.         
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
*    Auto generated code in vAUTOSAR TOOL by TGUNASEK at 2025-08-04 15:28:12.905336600
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

#define OsNumberOfIsr                                     24U
#define osdNumberOfCat2ISRs                               24

/*****************************************************************************
*                               Isr Stack Table                              *
******************************************************************************/
#define osStackStartAddressIsr_0                (osStackPtrType)osdSystemTimerISR_TOP
#define osStackSizeIsr_0                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_1                (osStackPtrType)osdCAN0_ISR_TOP
#define osStackSizeIsr_1                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_2                (osStackPtrType)osdGPT_ISR_TOP
#define osStackSizeIsr_2                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_3                (osStackPtrType)osdBACKUP_TOP
#define osStackSizeIsr_3                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_4                (osStackPtrType)osdPDMA48_TOP
#define osStackSizeIsr_4                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_5                (osStackPtrType)osdPDMA49_TOP
#define osStackSizeIsr_5                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_6                (osStackPtrType)osdPDMA50_TOP
#define osStackSizeIsr_6                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_7                (osStackPtrType)osdPDMA51_TOP
#define osStackSizeIsr_7                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_8                (osStackPtrType)osdPDMA52_TOP
#define osStackSizeIsr_8                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_9                (osStackPtrType)osdcpuss_interrupts_ipc_6_IRQn_TOP
#define osStackSizeIsr_9                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_10               (osStackPtrType)osdISR_GFX2D_TOP
#define osStackSizeIsr_10                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_11               (osStackPtrType)osdISR_VIDEOIO_0_TOP
#define osStackSizeIsr_11                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_12               (osStackPtrType)osdISR_VIDEOIO_1_TOP
#define osStackSizeIsr_12                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_13               (osStackPtrType)osdISR_PDMA22_TOP
#define osStackSizeIsr_13                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_14               (osStackPtrType)osdISR_MDMA1_TOP
#define osStackSizeIsr_14                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_15               (osStackPtrType)osdISR_MDMA2_TOP
#define osStackSizeIsr_15                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_16               (osStackPtrType)osdCAN1_ISR_TOP
#define osStackSizeIsr_16                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_17               (osStackPtrType)osdSCB2_TOP
#define osStackSizeIsr_17                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_18               (osStackPtrType)osdIGN_ISR_TOP
#define osStackSizeIsr_18                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_19               (osStackPtrType)osdCAN_WAKEUP_ISR_TOP
#define osStackSizeIsr_19                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_20               (osStackPtrType)osdECC_ERROR_ISR_TOP
#define osStackSizeIsr_20                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_21               (osStackPtrType)osdMCU_LVD_ISR_TOP
#define osStackSizeIsr_21                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_22               (osStackPtrType)osdCSV_ERROR_ISR_TOP
#define osStackSizeIsr_22                       (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_23               (osStackPtrType)osdSSV_ERROR_ISR_TOP
#define osStackSizeIsr_23                       (osStackDataType)sizeof(osLevelStackCore0Level0)



/*****************************************************************************
*                               Isr Configs                                  *
******************************************************************************/
/********************** Isr 0***********************/
#define osIsrId_SystemTimerISR                  0UL
#define osIsrPrioLevel_SystemTimerISR           4UL

/********************** Isr 1***********************/
#define osIsrId_CAN0_ISR                        1UL
#define osIsrPrioLevel_CAN0_ISR                 4UL

/********************** Isr 2***********************/
#define osIsrId_GPT_ISR                         2UL
#define osIsrPrioLevel_GPT_ISR                  4UL

/********************** Isr 3***********************/
#define osIsrId_BACKUP                          3UL
#define osIsrPrioLevel_BACKUP                   4UL

/********************** Isr 4***********************/
#define osIsrId_PDMA48                          4UL
#define osIsrPrioLevel_PDMA48                   4UL

/********************** Isr 5***********************/
#define osIsrId_PDMA49                          5UL
#define osIsrPrioLevel_PDMA49                   4UL

/********************** Isr 6***********************/
#define osIsrId_PDMA50                          6UL
#define osIsrPrioLevel_PDMA50                   4UL

/********************** Isr 7***********************/
#define osIsrId_PDMA51                          7UL
#define osIsrPrioLevel_PDMA51                   4UL

/********************** Isr 8***********************/
#define osIsrId_PDMA52                          8UL
#define osIsrPrioLevel_PDMA52                   4UL

/********************** Isr 9***********************/
#define osIsrId_cpuss_interrupts_ipc_6_IRQn     9UL
#define osIsrPrioLevel_cpuss_interrupts_ipc_6_IRQn          4UL

/********************** Isr 10***********************/
#define osIsrId_ISR_GFX2D                       10UL
#define osIsrPrioLevel_ISR_GFX2D                4UL

/********************** Isr 11***********************/
#define osIsrId_ISR_VIDEOIO_0                   11UL
#define osIsrPrioLevel_ISR_VIDEOIO_0            4UL

/********************** Isr 12***********************/
#define osIsrId_ISR_VIDEOIO_1                   12UL
#define osIsrPrioLevel_ISR_VIDEOIO_1            4UL

/********************** Isr 13***********************/
#define osIsrId_ISR_PDMA22                      13UL
#define osIsrPrioLevel_ISR_PDMA22               4UL

/********************** Isr 14***********************/
#define osIsrId_ISR_MDMA1                       14UL
#define osIsrPrioLevel_ISR_MDMA1                4UL

/********************** Isr 15***********************/
#define osIsrId_ISR_MDMA2                       15UL
#define osIsrPrioLevel_ISR_MDMA2                4UL

/********************** Isr 16***********************/
#define osIsrId_CAN1_ISR                        16UL
#define osIsrPrioLevel_CAN1_ISR                 4UL

/********************** Isr 17***********************/
#define osIsrId_SCB2                            17UL
#define osIsrPrioLevel_SCB2                     4UL

/********************** Isr 18***********************/
#define osIsrId_IGN_ISR                         18UL
#define osIsrPrioLevel_IGN_ISR                  4UL

/********************** Isr 19***********************/
#define osIsrId_CAN_WAKEUP_ISR                  19UL
#define osIsrPrioLevel_CAN_WAKEUP_ISR           4UL

/********************** Isr 20***********************/
#define osIsrId_ECC_ERROR_ISR                   20UL
#define osIsrPrioLevel_ECC_ERROR_ISR            4UL

/********************** Isr 21***********************/
#define osIsrId_MCU_LVD_ISR                     21UL
#define osIsrPrioLevel_MCU_LVD_ISR              4UL

/********************** Isr 22***********************/
#define osIsrId_CSV_ERROR_ISR                   22UL
#define osIsrPrioLevel_CSV_ERROR_ISR            4UL

/********************** Isr 23***********************/
#define osIsrId_SSV_ERROR_ISR                   23UL
#define osIsrPrioLevel_SSV_ERROR_ISR            4UL



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

