//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------

#include "Std_Types.h"
#include "MemLib_Traveo.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
//----------------------------------------------------------------------------------------------------------------------
#define TCM_OFFSET1 		((uint32)0x00200000)
#define TCM_OFFSET2 		((uint32)0x00010000)

#define TCRAM_END           ((uint32)0x00020000)

#define AXI_OFFSET0 		((uint32)0x04000000)
#define AXI_OFFSET1 		((uint32)0x04A00000)
#define AXI_OFFSET2 		((uint32)0x049F0000)

#define SECTOR1 		    ((uint32)0x00A00000)
#define SECTOR2 		    ((uint32)0x01A00000)
#define SECTOR3 		    ((uint32)0x04A00000)
#define SECTOR4 		    ((uint32)0x009F0000)
#define SECTOR5 		    ((uint32)0x019F0000)
#define SECTOR6 		    ((uint32)0x049F0000)

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
/// @brief   This function converts Tightly Coupled Memory(TCM) address to Advanced eXtensible Interface(AXI)
///
/// @param  TcmRef: TCM address
/// @return         AXI address
//----------------------------------------------------------------------------------------------------------------------
#define MEMLIB_CODE_SEC_START
#include "MemMap.h"
void * Tcm2Axi(const void * const TcmRef)
{
	uint32 addr = (uint32)TcmRef;
	/* Appropriate AXI slave address cannot be found... */
	uint32 * Ret = NULL_PTR;

    /* PFLASHB */
    if((SECTOR1 <= addr) && (addr < (SECTOR1 + TCM_OFFSET1)))
    {
    	Ret = (void *)(addr - SECTOR1 + AXI_OFFSET1);
    }
    else if((SECTOR2 <= addr) && (addr < (SECTOR2 + TCM_OFFSET1)))
    {
    	Ret = (void *)(addr - SECTOR2 + AXI_OFFSET1);
    }
    else if((SECTOR3 <= addr) && (addr < (SECTOR3 + TCM_OFFSET1)))
    {
    	Ret = (void *)(addr);
    }
    /* PFLASHS */
    else if((SECTOR4 <= addr) && (addr < (SECTOR4 + TCM_OFFSET2)))
    {
    	Ret = (void *)(addr - SECTOR4 + AXI_OFFSET2);
    }
    else if((SECTOR5 <= addr) && (addr < (SECTOR5 + TCM_OFFSET2)))
    {
    	Ret = (void *)(addr - SECTOR5 + AXI_OFFSET2);
    }
    else if((SECTOR6 <= addr) && (addr < (SECTOR6 + TCM_OFFSET2)))
    {
    	Ret = (void *)(addr);
    }
    /* TCRAM remap */
    else if(addr < TCRAM_END)
    {
    	Ret = (void *)(addr + AXI_OFFSET0);
    }
    else
    {
    	//do nothing
    }

    return Ret;
}
#define MEMLIB_CODE_SEC_END
#include "MemMap.h"
