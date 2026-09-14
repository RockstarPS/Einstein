/*=================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**==================================================================================================================
**
** Name:           SharedBootDiagcdd.c
**
** Description:    
**                 
**
**===================================================================================================================*/

#ifndef SHAREDBOOTDIAGCDD_CFG_C
#define SHAREDBOOTDIAGCDD_CFG_C

#include "os.h"
#include "Std_Types.h"
#include "abstract.h"
#include "MemLib.h"
//#include "s6j3200io.h"
#include "s6j3300io.h"
#include "SharedBootDiagcdd.h"
#include "SharedBootDiagcdd_cfg.h"
/*====================================================================================================================
** CONTROLLER SPECIFIC FUNCTIONS **
==================================================================================================================== */

#pragma ghs section text=".RamCode"

extern uint32 TS_CacheDisableAsm(void);
extern void TS_CacheRestoreAsm(uint32 CacheStatus);

static uint32 CacheStatus;
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
boolean ShareDiag_CheckFlashAccess(void)
{
	boolean ret = FALSE;

	// check write enable whether can be obtained
	if (FCFG_WRITE_EN_USED != WFCFG_WARBR_WERSTS)
	{
		ret = TRUE;
	}

	return ret;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void ShareDiag_HWRefresh(void)
{
	// Clear hardware watchdog count
	HWDG_TRG0 = HWDG_TRG0CFG;
	HWDG_TRG1 = HWDG_TRG1CFG;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
boolean ShareDiag_CheckTCFlsReady(void)
{
	boolean ret = FALSE;
	ShareDiag_HWRefresh();

	if((TCFCFG0_FSTAT_RDY==1) && (TCFCFG0_FSTAT_READ==1))
	{
		ret = TRUE;
	}
	return (ret);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void ShareDiag_TCFlsWriteDisable(void)
{
    // Unlock configuration registers for next write access
    TCFCFG0_FCPROTKEY = TCFLASH_KEY_UNLOCK;
    TCFCFG0.unFCFGR.stcField.u1WE = 0;
    TS_CacheRestoreAsm(CacheStatus);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void ShareDiag_TCFlsWriteEnable(void)
{
    // Unlock configuration registers for next write access
    TCFCFG0_FCPROTKEY = TCFLASH_KEY_UNLOCK;
    TCFCFG0.unFCFGR.stcField.u1WE = 1;
    CacheStatus = TS_CacheDisableAsm();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void ShareDiag_TCFlsWrite(uint32 Value, uint32 Address)
{
    uint32 a;
    uint32 b;

	a = (Address & 0xFFFFF000u) + CA0_OFFSET;
	b = (Address & 0xFFFFF000u) + CA1_OFFSET;

	*(volatile uint32 *)a = 0xAA;
	DSB();
	*(volatile uint32 *)b = 0x55;
	DSB();
	*(volatile uint32 *)a = 0xA0;
	DSB();
	*((volatile uint32 *)Address) = Value;
	DSB();

	while(FALSE == ShareDiag_CheckTCFlsReady());
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void ShareDiag_FlsErase(uint32 Address)
{
    uint32 a;
    uint32 b;

	a = (Address & 0xFFFFF000u) + CA0_OFFSET;
	b = (Address & 0xFFFFF000u) + CA1_OFFSET;

	SuspendAllInterrupts();
	ShareDiag_TCFlsWriteEnable();

	*(volatile uint32 *)(a) = 0xAA;
	DSB();
	*(volatile uint32 *)(b) = 0x55;
	DSB();
	*(volatile uint32 *)(a) = 0x80;
	DSB();
	*(volatile uint32 *)(a) = 0xAA;
	DSB();
	*(volatile uint32 *)(b) = 0x55;
	DSB();
	*((volatile uint32 *)(Address & 0xFFFFF000u)) = 0x30;
	DSB();

	while(FALSE == ShareDiag_CheckTCFlsReady());

	ShareDiag_TCFlsWriteDisable();
	ResumeAllInterrupts();
}

#pragma ghs section text=default

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void HWdg_Refresh(void)
{
      SuspendAllInterrupts();
      // Clear hardware watchdog count
      HWDG_TRG0 = HWDG_TRG0CFG;
      HWDG_TRG1 = HWDG_TRG1CFG;
      ResumeAllInterrupts();

}


//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void Meet_SetMpuRegions(uint32 access, uint32 address, uint32 reg_number, uint32 size, boolean enable)
{
#if 0
    uint32_t RegValue;

    SuspendAllInterrupts();

    MCR(15, 0, reg_number, 6, 2, 0);    //Select MPU region number for configuration
    MCR(15, 0, address, 6, 1, 0);       //Set region base address
    MCR(15, 0, size, 6, 1, 2);          //Set region size and enable (16k)
    MCR(15, 0, access, 6, 1, 4);        //Set region access control

    // Enable/Disable MPU
    RegValue = MRC(15, 0, 1, 0, 0);     // Read CP15 register 1
    DSB();                              // Ensure the completion of memory accesses,
    RegValue &= SHAREDIAG_MASK_RESET_MPU_ENABLE; // Reset the MPU Enable/Disable
    if(FALSE != enable)
    {
    	RegValue |= 1UL;                // Enable MPU
    }
    RegValue |= (1 << 17);              // Enable Background region
    MCR(15, 0,  RegValue, 1, 0, 0);     // Copy settings back to CP15
    ISB();                              // Instruction Synchronization Barrier.

    ResumeAllInterrupts();
	#endif
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void Meet_MemoryProtectionReapply(void)
{
	// Set code execution in TCRAM - size 4K
   /*	SHAREDIAG_MPU_REGIONS_FUNC(
            SHAREDIAG_CODE_EXECUTE_ENABLE_ACCESS,
            SHAREDIAG_CODE_EXECUTE_START_ADDRESS,
            SHAREDIAG_CODE_EXECUTE_MPU_REGION_NUM,
            SHAREDIAG_CODE_EXECUTE_MPU_REGION_SIZE,
            TRUE); */
    
    //Os_Call_Meet_SetMpuRegions(cCodeExecuteEnableAccess, cCodeExecuteStartAddress, cCodeExecuteMPURegionNum, cCodeExecuteMPURegionSize, TRUE);
}

/*====================================================================================================================
** SERVICE SPECIFIC FUNCTIONS **
==================================================================================================================== */
/*=====================================================================================================================
**  for each change to this file, be sure to record:                     
**  1.  who made the change and when the change was made                 
**  2.  why the change was made and the intended result                
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.     
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  
**   other reason                                                             
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/Mar/2020
** CDSID             :  dkasiman
** Traceability      :  RTC-811699 
** Change Description:  MPU related functions are commented.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  7/15/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1348667
** Change Description:  Microcontroller header file is updated.Accordingly some MACRO's are renamed
**====================================================================================================================*/


#endif /* SHAREDBOOTDIAGCDD_CFG_C */
