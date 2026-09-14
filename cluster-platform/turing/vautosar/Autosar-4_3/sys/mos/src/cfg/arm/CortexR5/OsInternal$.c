/*-------------------------------------------------------------------------------**
**  ***************************************************************************  **
**                                                                               **
**                CONFIDENTIAL VISTEON CORPORATION                               **
**                                                                               **
**   This is an unpublished work of authorship, which contains trade             **
**   secrets, created in 2013. Visteon Corporation owns all rights to            **
**   this work and intends to maintain it in confidence to preserve              **
**   its trade secret status. Visteon Corporation reserves the right,            **
**   under the copyright laws of the United States or those of any               **
**   other country that may have jurisdiction, to protect this work              **
**   as an unpublished work, in the event of an inadvertent or                   **
**   deliberate unauthorized publication. Visteon Corporation also               **
**   reserves its rights under all copyright laws to protect this                **
**   work as a published work, when appropriate. Those having access             **
**   to this work may not copy it, use it, modify it or disclose the             **
**   information contained in it without the written authorization               **
**   of Visteon Corporation.                                                     **
**                                                                               **
**  ***************************************************************************  **
**  ***************************************************************************  **
**    File Name         :  OsInternal.c                                          **
**    Module Short Name :  OsInternal                                            **
**    Description       :  This file contains the implementation for the         **
**                         architecture specific handling supporting the         **
**                         supporting the operating system                       **
**                                                                               **
**   Organization     :  Driver Information Software Section,                    **
**                       Visteon Software Operation                              **
**                       Visteon Corporation                                     **
**                                                                               **
**   --------------------------------------------------------------------------  **
**   Compiler Name    :  GHS                                                     **
**   Target Hardware  :  ARM Core based CPU                                      **
**                                                                               **
**  ***************************************************************************  **
**-------------------------------------------------------------------------------*/
#ifndef OS_INTERNAL_C
#define OS_INTERNAL_C

#include "OsPrivate.h"
#include "OsInternal.h"


/*-----------------------------------------------------**
** const OsStackType OsStacks[OsNumberOfStack]       = **
** {                                                   **
**     {                                               **
**         osdSystemStackStartAddress,                 **
**         osdSystemStackEndAddress,                   **
**     },                                              **
**     {                                               **
**         osdIRQStackStartAddressPtr,                 **
**         osdIRQStackEndAddressPtr,                   **
**     },                                              **
**     {                                               **
**         osdFIQStackStartAddressPtr,                 **
**         osdFIQStackEndAddressPtr,                   **
**     }                                               **
** };                                                  **
**-----------------------------------------------------*/


#pragma ghs section text      =".oscode"
void osIntArchInitialize (void)
{
    osuint32 i;
    
    osSetupExceptionStacks(); /* Setup all ARM stacks except user mode stack and system mode stack */
    /* Setup ARM Exceptions (via Bootrom) */
    osdBootROM_Unlock();
    while (osdBootROM_isLocked()) 
    {
      ; /* Wait until unlock really worked */
    }

      /* Reset */
    osEXCFG_UNDEFINACT  = (osuint32)(osExceptionTable[1]);  /* Undefined */
    osEXCFG_SVCINACT    = (osuint32)(osExceptionTable[2]);  /* Supervisor */
    osEXCFG_PABORTINACT = (osuint32)(osExceptionTable[3]);  /* Prefetch Abort */ 
    osEXCFG_DABORTINACT = (osuint32)(osExceptionTable[4]);  /* Data Abort */ 

    osdBootROM_SwitchSets(); /* Switch the vector sets, make inactive set the active set */
    osdBootROM_Lock();
   
    osdIRQ_Unlock();

    /* Setup all IRQs */
    for (i=0; i<osdNumberOfIRQs; i++)
    {
        osIRQ0_IRQVA(i)       = (osuint32)osIRQTable[i];
    }
    
    for (i=0; i<osdNumberOfConfiguredIRQs; i++)
    {
        /* Set IRQPL register according to the configuration (i.e. osIRQPrioTable) */
        osIRQ0_IRQPL(osIRQPrioTable[i].osIPNumber) = osIRQPrioTable[i].osIPLevel;
    }
    
    /* Setup all FIQs/NMIs */         
      for (i=0; i<osdNumberOfFIQs; i++)
      {
         if (osFIQTable[i]!=0)
         {
            osIRQ0_NMIVA(i)       = (osuint32)osFIQTable[i]; 
         }
      }
      
    /* Setup FIQs/NMIs prios and enable the FIQs/NMIs */
    #if osdNumberOfConfiguredFIQs>0
    for (i=0; i<osdNumberOfConfiguredFIQs; i++)
    {
        /* Set NMIPL register according to the configuration (i.e. osFIQPrioTable) */
        osIRQ0_NMIPL(osFIQPrioTable[i].osIPNumber) = osFIQPrioTable[i].osIPLevel;
    }
    #endif
    osIRQ0_CSR = osdIRQ_CSR_EnableBit; /* Enable IUNIT */
   
    osdIRQ_Lock();
    /* Setup core to use High exception vectors and VIC */
   osSetBitsARMCoreSCTLR(0x01002000);  /* 'VE' = 1 == enable VIC; 'V' = 1 == High vector*/
   
   
}

void osSetupAndEnableConfiguredInterrupts (void)
{
    osEnableNMIandAborts();
   
   osSetupConfiguredInterrupts();
}


void osStartArchTimer (void)
{
    /* No need to activate the interrupt at the IUNIT, this is already 
      done in osInitISRs */
   osRLT_TMRLR(osdUsedSystemTimer) = osdReloadValue;
   osRLT_TMCSR(osdUsedSystemTimer) = osdTimerInitValue;
}


void osISRUnhandledException (void)
{
    osuint32 mode;
    
    /* osOwnCcb->LockIsNotNeeded.ossUnhandledExceptionDetail: 
      0x0000..0x01ff : IRQs
      0x1000..0x101f : NMIs/FIQs
      0x7777         : No unhandled exception yet
      0x7FFF         : Unknown case
      (all other exceptions are handled by HW or OS otherwise)
    */
    mode = osGetMode();
    switch(mode)
    {
        case osdARMModeFIQ:
        {
            /* This was an NMI */
            //todo: update the exception details
            break;
        }
        case osdARMModeIRQ:
         
         /* This was an IRQ */
         osErrParam.ExceptionDetails = (osIRQ0_IRQST & osdIRQ_IRQST_SrcMask);
         break;
         
        default:
         
         osErrParam.ExceptionDetails = 0x7fffffff;
         break;
    }
    
    while(1)
    {
        ;
    }
}

void osUnhandledException (void)
{
    osErrorHook(E_OS_SYS_ABORT);
}


void osMemProtectionFault (void)
{
    osErrorHook(E_OS_SYS_ABORT);
}

void osDataAbortHandler (void)
{
    osErrorHook(E_OS_SYS_ABORT);
}

void osUndefinedInstructionException (void)
{
    osErrorHook(E_OS_SYS_ABORT);
}

#pragma ghs section text     = default

#endif
/*----------------------------------------------------------------------------------**
**  ------------------------------------------------------------------------------- **
**   ****************************************************************************   **
**      for each change to this file, be sure to record:                            **
**         1.  who made the change and when the change was made                     **
**         2.  why the change was made and the intended result                      **
**      Following block needs to be repeated for each change                        **
**   ****************************************************************************   **
**      Note: In the traceability column we need to trace back to the Design Doc.   **
**      For the initial version it is traced to the Design Document section.        **
**      For further changes it shall trace to the source of the change which may    **
**      be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any     **
**      other reason                                                                **
**   ****************************************************************************   **
**  ------------------------------------------------------------------------------- **
**                                                                                  **
**  ------------------------------------------------------------------------------- **
**   Date              : 20-Jun-2016                                                **
**   CDSID             : ssukuma1                                                   **
**   Traceability      :------------                                                **
**   RTC Version       : ------                                                     **
**   Change Description: Initial version.                                           **
**   ------------------------------------------------------------------------------ **
**----------------------------------------------------------------------------------*/

