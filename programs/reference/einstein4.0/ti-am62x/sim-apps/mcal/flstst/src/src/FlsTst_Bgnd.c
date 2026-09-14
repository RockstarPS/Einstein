/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2018. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
#ifndef FLSTST_BGND_C
#define FLSTST_BGND_C
/*!***************************************************************************
 * @ingroup
 * @file FlsTst.c
 * @brief FlsTst main layer which handles the Init, Mainfunctions and APIs for SWCs
 * ****************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
 

#include "FlsTst_Bgnd.h"

#define VALUE_ONE_UL      1UL
#define VALUE_ONE_U       1U
#define MAX_HEX_32BIT     0xFFFFFFFFU
#if (NO_OF_BNG_BLOCK > 0)


/*****************************************************************************
 *  Private Macros Definitions                                                **
 ******************************************************************************/

/******************************************************************************
 *  Private Function Declaration                                                *
 *******************************************************************************/
static void FlsTst_BngReadECCErrorFlg(FlsTst_ErrorDetailsType *Error);

/******************************************************************************
 *  Private Variable Definitions                                               *
 *******************************************************************************/

#define FLSTST_START_SEC_CODE
#include "MemMap.h"
#include "AssertLib.h"
/******************************************************************************
 *  Private Function Definitions                                                *
 *******************************************************************************/
/**
 * Read the ECC register and Flag.
 * @param     none
 * @return    void
 */
static void FlsTst_BngReadECCErrorFlg(FlsTst_ErrorDetailsType *Error)
{
    Error->result = FLSTST_RESULT_OK;

    /*Read
     * 2.Correctable Fault Location Register
     * */

}
/******************************************************************************
 *  Public Function Definitions                                                *
 *******************************************************************************/
/**
 * This method is used process background job.
 * @param     FgndBlockId: Number of the foreground test to be executed.
 * @return    E_OK: Foreground test processed
 *            E_NOT_OK: Foreground test not accepted
 */

Std_ReturnType FlsTst_Bgndprocess(FlsTst_BlockIdFgndType BlockID,
        const FlsTstBlocktype *BgndConfigptr)
{
    FlsTst_BlockIdFgndType fl_BlockId = 0U;
    FlsTstBlocktype BlockPtr;
    uint32 OffsetAddress = 0UL;
    uint32 TestAddress = 0UL;
    uint32 TestByteData = 0UL;
    uint32 Noofcell = 0UL;
    uint32 StartAddress = 0UL;
    FlsTst_ErrorDetailsType *Errorptr = &FlsTst_Infoptr.BgndErrorInfo;
    uint32 BlockNum = 0UL;
    uint32 BlockcellCount = 0UL;
    uint32 testcellcount_refer = 0UL;
    uint32 nextstartAdress = 0x0UL;
    fl_BlockId = BlockID;
    while (FlsTst_Infoptr.BgndTestloopCount == ((boolean)1))
    {
        for (BlockNum = 0U; BlockNum < NO_OF_BNG_BLOCK; BlockNum++)
        {
            BlockPtr = (BgndConfigptr[BlockNum]);
            if (NO_OF_BNG_BLOCK < fl_BlockId)
            {
                fl_BlockId = BgndConfigptr[0].FlsTstBlockIndex;
            }
            if (fl_BlockId == BgndConfigptr[BlockNum].FlsTstBlockIndex)
            {
                if (FlsTst_Infoptr.CurrentBgndstartadress
                        == BlockPtr.FlsTstBlockBaseAddress)
                {
                    StartAddress = BlockPtr.FlsTstBlockBaseAddress;
                }
                else
                {
                    StartAddress = FlsTst_Infoptr.CurrentBgndstartadress;
                }
                FlsTst_Infoptr.CurrentBgndstartadress = StartAddress;
				if( BlockPtr.FlsTstBlockEndAddress > StartAddress ) 
				{
					Noofcell = (BlockPtr.FlsTstBlockEndAddress - StartAddress)
                        + VALUE_ONE_UL;
				}
				else
				{
					DEBUG_ASSERT( FALSE );
				}
				if( (uint64)(BlockcellCount + Noofcell) < MAX_HEX_32BIT ) 
				{
					BlockcellCount += Noofcell;
				}
				else
				{
					DEBUG_ASSERT( FALSE );
				}
                testcellcount_refer = Noofcell;
                if (BlockcellCount == FlsTstNumberOfTestedCells)
                {
                    FlsTst_Infoptr.BgndTestloopCount = (boolean)0;
                }
                else
                {
                    FlsTst_Infoptr.BgndTestloopCount = (boolean)1;
                    if (BlockcellCount > FlsTstNumberOfTestedCells)
                    {
                        nextstartAdress = (BlockcellCount
                                - FlsTstNumberOfTestedCells);
								if( BlockcellCount > nextstartAdress ) 
								{
									BlockcellCount = BlockcellCount - nextstartAdress;
								}
								else
								{
									DEBUG_ASSERT( FALSE );
								}
						if( Noofcell > nextstartAdress ) 
						{
							Noofcell -= nextstartAdress;
						}
						else
						{
							DEBUG_ASSERT( FALSE );
						}
						if( ((uint64)(StartAddress + Noofcell)) < MAX_HEX_32BIT )
						{
							FlsTst_Infoptr.CurrentBgndstartadress = StartAddress
                                + Noofcell;
						}
						else
						{
							DEBUG_ASSERT( FALSE );
						}
                        FlsTst_Infoptr.BgndTestloopCount = (boolean)0;
                    }
                }
                if (BlockPtr.FlsTstTestAlgorithm == FLSTST_ECC)
                {
                    /* Execute ECC test */
                    for (OffsetAddress = 0UL; OffsetAddress < Noofcell;
                            OffsetAddress += BlockPtr.Readunit)
                    {
                        /* read flash memory */
                        TestAddress = StartAddress + OffsetAddress;
                        TestByteData = *((volatile uint32*) TestAddress);
                    }
                    OffsetAddress = TestByteData;

                    FlsTst_BngReadECCErrorFlg(Errorptr);
                    Errorptr->blockID = fl_BlockId;
                    if(fl_BlockId < NO_OF_BNG_BLOCK)
                    {
                        FlsTst_Infoptr.BgndResultBuffer[fl_BlockId] =
                                (Errorptr->result);
                    }
                    else
                    {
                        DEBUG_ASSERT(FALSE);
                    }
                    if (FLSTST_RESULT_NOT_OK
                            != FlsTst_Infoptr.OverallBngResultBuffer)
                    {
                        FlsTst_Infoptr.OverallBngResultBuffer =
                                Errorptr->result;
                    }
                }
                if (0UL == FlsTst_Infoptr.AtomicIntervalCount)
                {
                    if (FlsTstNumberOfTestedCellsAtomic <= BlockcellCount)
                    {
                        FlsTst_Infoptr.AtomicIntervalCount++;
                    }
                }
                if (testcellcount_refer == Noofcell)
                {
                    if (FlsTst_Infoptr.CurrentBgndBlockID
                            != BgndConfigptr[NO_OF_BNG_BLOCK - VALUE_ONE_UL].FlsTstBlockIndex)
                    {
                        FlsTst_Infoptr.CurrentBgndBlockID =
                                BgndConfigptr[BlockNum + VALUE_ONE_U].FlsTstBlockIndex;
                        FlsTst_Infoptr.CurrentBgndstartadress =
                                BgndConfigptr[BlockNum + VALUE_ONE_U].FlsTstBlockBaseAddress;
                    }
                    else
                    {
                        FlsTst_Infoptr.BgndTestloopCount = (boolean)0;
                        FlsTst_Infoptr.CurrentBgndBlockID =
                                FlsTstBlockBgnd[0].FlsTstBlockIndex;
                        FlsTst_Infoptr.CurrentBgndstartadress =
                                BgndConfigptr[0].FlsTstBlockBaseAddress;
                        if (FlsTstTestIntervalIdEndValue
                                != FlsTst_Infoptr.CurrentTestIntervalId)
                        {
                            FlsTst_Infoptr.CurrentTestIntervalId++;
                        }
                        else
                        {
                            FlsTst_Infoptr.CurrentTestIntervalId = 0UL;
                            FlsTst_Infoptr.AtomicIntervalCount = 0UL;
                        }
#if (FLSTSTTESTCOMPLETEDNOTIFICATIONSUPPORTED == STD_ON)
                        /* call the callback notifications */
                        if (NULL_PTR
                                != FlsTstBlock.FlsTstTestCompletedNotification)
                        {
                            FlsTstBlock.FlsTstTestCompletedNotification();
                        }
#endif /* (FLSTSTTESTCOMPLETEDNOTIFICATIONSUPPORTED == STD_ON) */
                    }
                    fl_BlockId = FlsTst_Infoptr.CurrentBgndBlockID;

                }

            }    /* end of if (BlockID == BgndConfigptr[BlockNum].FlsTstBlockIndex) */
        }    /* end of  for (BlockNum = 0U; BlockNum < NO_OF_BNG_BLOCK; BlockNum++) */
    }    /* while (FlsTst_Infoptr.BgndTestloopCount != 1) */
    return E_OK;
}
#define FLSTST_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (NO_OF_BNG_BLOCK > 0) */
	
#endif /* FLSTST_BGND_C */

/*End of File*/
/*****************************************************************************
 *  for each change to this file, be sure to record:                         *
 *     1.  who made the change and when the change was made                  *
 *     2.  why the change was made and the intended result                   *
 *  Following block needs to be repeated for each change
 ******************************************************************************
 *  Note: In the trace-ability column we need to trace back to the Design Doc.*
 *  For the initial version it is traced to the Design Document section.     *
 *  For further changes it shall trace to the source of the change which may *
 *  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
 *  other reason                                                            *
 ******************************************************************************/
/*****************************************************************************
 Date              :16-Jul-2020
 By                :bbaskara
 Traceability      :RTC
 Change Description:Initial Version for FlsTst implementation
 ******************************************************************************/
  /*****************************************************************************
 Date              :28-Mar-2020
 By                :gthanapp
 Traceability      :RTC#1564070
 Change Description: Cert-C warning analysis and fix 
 ******************************************************************************/
 /*****************************************************************************
 Date              :05-MaY-2022
 By                :nchellap
 Traceability      :RTC#1654166
 Change Description:Coverity Misra Analyse and Fix
 ******************************************************************************/
 /*****************************************************************************
 Date              :06-Jun-2022
 By                :jkanikal
 Traceability      :RTC#1654166
 Change Description:FlsTst implementation
 ******************************************************************************/
