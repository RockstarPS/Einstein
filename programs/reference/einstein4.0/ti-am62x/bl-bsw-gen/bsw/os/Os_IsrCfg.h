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
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.372821600
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

#define OsNumberOfIsr                                     9U
#define osdNumberOfCat2ISRs                               9

/*****************************************************************************
*                               Isr Stack Table                              *
******************************************************************************/
#define osStackStartAddressIsr_0                (osStackPtrType)osdMcuOsGptIsr_TOP
#define osStackSizeIsr_0                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_1                (osStackPtrType)osdMcuCan0RxTxIsr_TOP
#define osStackSizeIsr_1                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_2                (osStackPtrType)osdMcuCan1RxTxIsr_TOP
#define osStackSizeIsr_2                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_3                (osStackPtrType)osdMcuI2c3IoIsr_TOP
#define osStackSizeIsr_3                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_4                (osStackPtrType)osdMcuI2c0PmicIsr_TOP
#define osStackSizeIsr_4                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_5                (osStackPtrType)osdGpt_Ch3Isr_TOP
#define osStackSizeIsr_5                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_6                (osStackPtrType)osdGpt_Ch4Isr_TOP
#define osStackSizeIsr_6                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_7                (osStackPtrType)osdPmicCdd_nINTGpioInterrupt_TOP
#define osStackSizeIsr_7                        (osStackDataType)sizeof(osLevelStackCore0Level0)

#define osStackStartAddressIsr_8                (osStackPtrType)osdCdd_IpcIrqMbxFromWKUP_R5FSS0_0_TOP
#define osStackSizeIsr_8                        (osStackDataType)sizeof(osLevelStackCore0Level0)



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
#define osIsrId_McuI2c3IoIsr                    3UL
#define osIsrPrioLevel_McuI2c3IoIsr             12UL

/********************** Isr 4***********************/
#define osIsrId_McuI2c0PmicIsr                  4UL
#define osIsrPrioLevel_McuI2c0PmicIsr           13UL

/********************** Isr 5***********************/
#define osIsrId_Gpt_Ch3Isr                      5UL
#define osIsrPrioLevel_Gpt_Ch3Isr               14UL

/********************** Isr 6***********************/
#define osIsrId_Gpt_Ch4Isr                      6UL
#define osIsrPrioLevel_Gpt_Ch4Isr               16UL

/********************** Isr 7***********************/
#define osIsrId_PmicCdd_nINTGpioInterrupt       7UL
#define osIsrPrioLevel_PmicCdd_nINTGpioInterrupt          15UL

/********************** Isr 8***********************/
#define osIsrId_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0  8UL
#define osIsrPrioLevel_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0          11UL



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

