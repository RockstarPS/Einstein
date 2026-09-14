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



#ifndef OSSTACKS_LD
#define OSSTACKS_LD


#if defined(LINK_INCLUDE_STACKS)||defined(LINK_INCLUDE_PROTECTED_STACKS)||defined(LINK_INCLUDE_ALL_STACKS)


// Stack osSystemStack
    .osSystemStack :{. = . ;} ALIGN(4096)
    RUN_START(_osSystemStackStart)
    RUN_END(_osSystemStackEnd)

// Stack OsStack_OsTask_MemSerDyn
   .OsStack_OsTask_MemSerDyn :{. = . ;} ALIGN(4096)
   RUN_START(_OsStack_OsTask_MemSerDynStart)
   RUN_END(_OsStack_OsTask_MemSerDynEnd)

// Stack OsStack_OsTask_IpcUclEvDyn
   .OsStack_OsTask_IpcUclEvDyn :{. = . ;} ALIGN(4096)
   RUN_START(_OsStack_OsTask_IpcUclEvDynStart)
   RUN_END(_OsStack_OsTask_IpcUclEvDynEnd)

// Stack OsStack_OsTaskRenderDyn
   .OsStack_OsTaskRenderDyn :{. = . ;} ALIGN(4096)
   RUN_START(_OsStack_OsTaskRenderDynStart)
   RUN_END(_OsStack_OsTaskRenderDynEnd)

// Stack OsStack_InitTaskDyn
   .OsStack_InitTaskDyn :{. = . ;} ALIGN(2048)
   RUN_START(_OsStack_InitTaskDynStart)
   RUN_END(_OsStack_InitTaskDynEnd)

// Stack OsStack_OsTask_DiagnosticsDyn
   .OsStack_OsTask_DiagnosticsDyn :{. = . ;} ALIGN(2048)
   RUN_START(_OsStack_OsTask_DiagnosticsDynStart)
   RUN_END(_OsStack_OsTask_DiagnosticsDynEnd)

// Stack OsStack_OsTask_LSH_16msDyn
   .OsStack_OsTask_LSH_16msDyn :{. = . ;} ALIGN(2048)
   RUN_START(_OsStack_OsTask_LSH_16msDynStart)
   RUN_END(_OsStack_OsTask_LSH_16msDynEnd)

// Stack OsStack_OsTask_SafeBswDyn
   .OsStack_OsTask_SafeBswDyn :{. = . ;} ALIGN(2048)
   RUN_START(_OsStack_OsTask_SafeBswDynStart)
   RUN_END(_OsStack_OsTask_SafeBswDynEnd)

// Stack OsStack_OsTaskStackSharingDyn
   .OsStack_OsTaskStackSharingDyn :{. = . ;} ALIGN(2048)
   RUN_START(_OsStack_OsTaskStackSharingDynStart)
   RUN_END(_OsStack_OsTaskStackSharingDynEnd)

// Stack osLevelStackCore0Level0
   .osLevelStackCore0Level0 :{. = . ;} ALIGN(2048)
	RUN_START(_osLevelStackCore0Level0Start)
	RUN_END(_osLevelStackCore0Level0End)

// Stack OsStack_OsTask_Can0DataRxEvDyn
   .OsStack_OsTask_Can0DataRxEvDyn :{. = . ;} ALIGN(1024)
   RUN_START(_OsStack_OsTask_Can0DataRxEvDynStart)
   RUN_END(_OsStack_OsTask_Can0DataRxEvDynEnd)

// Stack OsStack_OsTask_Can1DataRxEvDyn
   .OsStack_OsTask_Can1DataRxEvDyn :{. = . ;} ALIGN(1024)
   RUN_START(_OsStack_OsTask_Can1DataRxEvDynStart)
   RUN_END(_OsStack_OsTask_Can1DataRxEvDynEnd)

// Stack OsStack_OsTask_CANFunDyn
   .OsStack_OsTask_CANFunDyn :{. = . ;} ALIGN(1024)
   RUN_START(_OsStack_OsTask_CANFunDynStart)
   RUN_END(_OsStack_OsTask_CANFunDynEnd)

// Stack OsStack_OsTask_DispFunDyn
   .OsStack_OsTask_DispFunDyn :{. = . ;} ALIGN(1024)
   RUN_START(_OsStack_OsTask_DispFunDynStart)
   RUN_END(_OsStack_OsTask_DispFunDynEnd)

// Stack OsStack_OsTask_FotaEvDyn
   .OsStack_OsTask_FotaEvDyn :{. = . ;} ALIGN(1024)
   RUN_START(_OsStack_OsTask_FotaEvDynStart)
   RUN_END(_OsStack_OsTask_FotaEvDynEnd)

// Stack OsStack_OsTask_FotaFunDyn
   .OsStack_OsTask_FotaFunDyn :{. = . ;} ALIGN(1024)
   RUN_START(_OsStack_OsTask_FotaFunDynStart)
   RUN_END(_OsStack_OsTask_FotaFunDynEnd)

// Stack OsStack_OsTask_IdleTaskDyn
   .OsStack_OsTask_IdleTaskDyn :{. = . ;} ALIGN(1024)
   RUN_START(_OsStack_OsTask_IdleTaskDynStart)
   RUN_END(_OsStack_OsTask_IdleTaskDynEnd)

// Stack OsStack_OsTask_ModeMgtDyn
   .OsStack_OsTask_ModeMgtDyn :{. = . ;} ALIGN(1024)
   RUN_START(_OsStack_OsTask_ModeMgtDynStart)
   RUN_END(_OsStack_OsTask_ModeMgtDynEnd)

// Stack OsStack_OsTask_NvmSpeedupDyn
   .OsStack_OsTask_NvmSpeedupDyn :{. = . ;} ALIGN(1024)
   RUN_START(_OsStack_OsTask_NvmSpeedupDynStart)
   RUN_END(_OsStack_OsTask_NvmSpeedupDynEnd)


#endif   //endif LINK_INCLUDE_STACKS || LINK_INCLUDE_PROTECTED_STACKS || LINK_INCLUDE_ALL_STACKS


#if defined(LINK_INCLUDE_CAT1STACK)||defined(LINK_INCLUDE_ALL_STACKS)

// Stack osIRQCat1Stack
    .osIRQCat1Stack :{. = . ;} ALIGN(512)
    RUN_START(_osIRQCat1StackStart)
    RUN_END(_osIRQCat1StackEnd)

// Stack osFIQStack
    .osFIQStack :{. = . ;} ALIGN(256)
    RUN_START(_osFIQStackStart)
    RUN_END(_osFIQStackEnd)	
#endif //LINK_INCLUDE_CAT1_STACK || LINK_INCLUDE_ALL_STACKS



#endif    /* */


/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

