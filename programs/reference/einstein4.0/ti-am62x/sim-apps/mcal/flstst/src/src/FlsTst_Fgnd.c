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
#ifndef FLSTST_FGND_C
#define FLSTST_FGND_C
/*!***************************************************************************
 * @ingroup
 * @file FlsTst.c
 * @brief FlsTst main layer which handles the Init, Mainfunctions and APIs for SWCs
 * ****************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "FlsTst_Fgnd.h"

#define MAX_HEX_32BIT     0xFFFFFFFFU

#if (FLSTST_STARTFGND_API == STD_ON)
/*****************************************************************************
 *  Private Macros Definitions                                                **
 ******************************************************************************/

/******************************************************************************
 *  Private Variable Definitions                                               *
 *******************************************************************************/

/******************************************************************************
 *  Private Function Declaration                                                *
 *******************************************************************************/
static void FlsTst_ClearECCErrorFlg(void);
static void FlsTst_ReadECCErrorFlg(FlsTst_ErrorDetailsType *Error);

#define FLSTST_START_SEC_CODE
#include "MemMap.h"
#include "AssertLib.h"
/******************************************************************************
 *  Private Function Definitions                                                *
 *******************************************************************************/
/**
 * Clear the ECC register and Flag.
 * @param     none
 * @return    void
 */
static void FlsTst_ClearECCErrorFlg(void)
{

    /*Clear 1.the Auxiliary Data Fault Status Register
     * 2.Correctable Fault Location Register
     * */

}
/**
 * Read the ECC register and Flag.
 * @param     none
 * @return    void
 */
static void FlsTst_ReadECCErrorFlg(FlsTst_ErrorDetailsType *Error)
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
 * This method is used process foreground job.
 * @param     FgndBlockId: Number of the foreground test to be executed.
 * @return    E_OK: Foreground test processed
 *            E_NOT_OK: Foreground test not accepted
 */
Std_ReturnType FlsTst_Fgndprocess(FlsTst_BlockIdFgndType BlockID,
        const FlsTstBlocktype *FndgConfigptr)
{
    Std_ReturnType ret = E_NOT_OK;
    uint32 BlockNum = 0UL;
    FlsTstBlocktype BlockPtr;
    uint32 OffsetAddress = 0UL;
    uint32 TestAddress = 0UL;
    uint32 TestByteData = 0UL;
    FlsTst_ErrorDetailsType *Errorptr = &FlsTst_Infoptr.FgndErrorInfo;

    for (BlockNum = 0U; BlockNum < NO_OF_FNG_BLOCK; BlockNum++)
    {
        BlockPtr = (FndgConfigptr[BlockNum]);

        if (BlockID == BlockPtr.FlsTstBlockIndex)
        {
            FlsTst_Infoptr.CurrentFgndBlockID = BlockID;
            if (BlockPtr.FlsTstTestAlgorithm == FLSTST_ECC)
            {
                /*Clear the Error register before testing */
                FlsTst_ClearECCErrorFlg();

                /* Execute ECC test */
                for (OffsetAddress = 0UL;
                        OffsetAddress < BlockPtr.FlsTstBlockSize;
                        OffsetAddress += BlockPtr.Readunit)
                {
                    /* read flash memory */
					if((uint64)(BlockPtr.FlsTstBlockBaseAddress + OffsetAddress) < MAX_HEX_32BIT ) 
					{
						TestAddress = BlockPtr.FlsTstBlockBaseAddress
                            + OffsetAddress;
					}
					else
					{
						DEBUG_ASSERT( FALSE );
					}
                    TestByteData = *((volatile uint32*) TestAddress);
                }
                OffsetAddress = TestByteData;
                FlsTst_ReadECCErrorFlg(Errorptr);
                ret = E_OK;
                Errorptr->blockID = BlockID;
                if (FLSTST_RESULT_OK == Errorptr->result)
                {
                    FlsTst_Infoptr.FgndResultBuffer[BlockNum] =FLSTST_OK;
                }
                else if (FLSTST_RESULT_NOT_OK == Errorptr->result)
                {
                    FlsTst_Infoptr.FgndResultBuffer[BlockNum] =FLSTST_NOT_OK;
                }
                else
                {
                    FlsTst_Infoptr.FgndResultBuffer[BlockNum] =FLSTST_NOT_TESTED;
                }
            }
        }
    }
    return ret;
}
#define FLSTST_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (FLSTST_STARTFGND_API == STD_ON) */

#endif /* #ifndef FLSTST_C */
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
 Change Description:Cert-C warning analysis and fix 
 ******************************************************************************/
 /*****************************************************************************
 Date              :06-Jun-2022
 By                :jkanikal
 Traceability      :RTC#1654166
 Change Description:FlsTst implementation
 ******************************************************************************/
