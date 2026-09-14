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
#ifndef SYSTST_C
#define SYSTST_C
/*!***************************************************************************
 * @ingroup
 * @file SysTst.c
 * @brief SysTst main layer which handles the Init, Mainfunctions and APIs for SWCs
 * ****************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "Std_Types.h"
#include "SysTst.h"
#if (SECURITY_HASH_ENABLE == STD_ON)
#include "Csm.h"
#include "Csm_Types.h"
#include "CryIf.h"
#include "Csm_Cfg.h"
#endif
#if (SECURITY_VECTOR_HASH_ENABLE == STD_ON)
#include "Crypto_30_LibCv.h"
#endif
#if (SECURITY_VAUTOSAR_HASH_ENABLE == STD_ON)
#include "CryptoDrv.h"
#endif
#if (FLSTST_ENABLE == STD_ON)
#include "FlsTst_Cfg.h"
#include "FlsTst.h"
#endif
#if (RAMTST_ENABLE == STD_ON)
#include "RamTst_Cfg.h"
#include "RamTst.h"
#endif
#if (CORTST_ENABLE == STD_ON)
#include "CorTst_Cfg.h"
#include "CorTst.h"
#endif
#if (MCU_RESET_ENABLE == STD_ON)
#include "Mcu.h"
#endif
/*****************************************************************************
 *  Private Macros Definitions                                                **
 ******************************************************************************/
#if ((FLSTST_FGNDTEST_ENABLE == STD_ON) || (STARTUPTEST_ENABLE == STD_ON))
#define ECC_DOUBLEBITERROR 2UL
#endif
#if (SECURITY_HASH_ENABLE == STD_ON)
#define MAX_RETRY_COUNT 5U
typedef enum
{
    CRYPTO_STREAMSTART,
    CRYPTO_UPDATE,
    CRYPTO_FINALBLOCK_UPDATE,
    CRYPTO_FINISH
} hashstatetype;
#endif
/******************************************************************************
 *  Private Variable Definitions                                               *
 *******************************************************************************/
#define SYSTST_START_SEC_VAR_INIT_UNSPECIFIED
#include "SysTst_MemMap.h"

/**<  Initialize the status variable*/
#if (FLSTST_FGNDTEST_ENABLE == STD_ON)
static uint8 TestCounter = 0x0U;
#endif
#if (SECURITY_HASH_ENABLE == STD_ON)
static hashstatetype Nor_Checkstate = CRYPTO_STREAMSTART;
static uint8 lhash_notok_Count = 0U;
static uint8 * dataPtr = (uint8 *) ADDRESS_START;
#endif
#define SYSTST_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SysTst_MemMap.h"

/******************************************************************************
 *  Private Function Declaration                                                *
 *******************************************************************************/
#if (SECURITY_HASH_ENABLE == STD_ON)
static void SysTst_Integrity_Check(void);
#endif
/******************************************************************************
 *  Public Function Definitions                                                *
 *******************************************************************************/
#define SYSTST_START_SEC_CODE
#include "SysTst_MemMap.h"
/**
 * This method initialize the SysTst module
 * @param     none
 * @return    void
 */
void SysTst_Init(void)
{
#if (CORTST_ENABLE == STD_ON)
    CorTst_Init(CORTSTCONFIG);
#endif
#if (FLSTST_ENABLE == STD_ON)
    FlsTst_Init(FLSTSTCONFIG);
#endif
#if (RAMTST_ENABLE == STD_ON)
    RamTst_Init(RAMTSTCONFIG);
    RamTst_Allow();
#endif
#if (SECURITY_VECTOR_HASH_ENABLE == STD_ON)
    CryIf_InitMemory();
    Crypto_30_LibCv_InitMemory();
    Csm_InitMemory();
#endif
#if (SECURITY_HASH_ENABLE == STD_ON)
    Csm_Init();
    CryIf_Init();
#endif
#if (SECURITY_VECTOR_HASH_ENABLE == STD_ON)
    Crypto_30_LibCv_Init();
#endif
#if (SECURITY_VAUTOSAR_HASH_ENABLE == STD_ON)
    Crypto_Init();
#endif

}
/**
 * This method is the main function for SysTst module
 * @param     none
 * @return    void
 */
void SysTst_MainFunction(void)
{
#if (CORTST_ENABLE == STD_ON)
    CorTst_ErrOkType ErrOk ={0};
#endif
#if (FLSTST_FGNDTEST_ENABLE == STD_ON)
    FlsTst_TestResultFgndType  FlsTst_FgndResult = FLSTST_NOT_TESTED;
    FlsTst_ErrorDetailsType FlsTst_ErrorDitail;
    static FlsTst_BlockIdFgndType FlsTstBlockID = 0x0U;
    Std_ReturnType ret = E_NOT_OK;
    if (TestCounter < FLSTST_NO_OF_FGNDTEST_BLOCK)
    {
        DisableATCMECC();
        /*Tcflash testing*/
        ret = FlsTst_StartFgnd(FlsTstBlockID);
        EnableATCMECC();
        if (E_OK == ret)
        {
            FlsTst_FgndResult = FlsTst_GetTestResultFgnd();
            if( FLSTST_OK == FlsTst_FgndResult )
            {
                /*Do Nothing*/
            }
            else
            {
                FlsTst_ErrorDitail = FlsTst_GetErrorDetails();
               if (ECC_DOUBLEBITERROR == FlsTst_ErrorDitail.BitError)
                {
#if (MCU_RESET_ENABLE == STD_ON)
                    /*If it is double bit error, reset the system*/
                    Mcu_PerformReset();
#endif
                }
            }
            FlsTstBlockID++;
        }
    }
    FlsTst_ErrorDitail = FlsTst_GetErrorDetails();
  if(ECC_DOUBLEBITERROR == FlsTst_ErrorDitail.BitError)
    {
#if (MCU_RESET_ENABLE == STD_ON)
        /*If it is double bit error, reset the system*/
        Mcu_PerformReset();
#endif
    }
    if (TestCounter < FLSTST_NO_OF_FGNDTEST_BLOCK)
    {
        TestCounter++;
    }
#endif
#if (CORTST_ENABLE == STD_ON)
    ErrOk.returnvalue = CORTST_E_NOT_TESTED;
    CorTst_GetCurrentStatus(&ErrOk);
    if (CORTST_E_NOT_OK == ErrOk.returnvalue)
    {
#if (MCU_RESET_ENABLE == STD_ON)
        Mcu_PerformReset();
#endif
    }
#endif
#if (SECURITY_HASH_ENABLE == STD_ON)
    SysTst_Integrity_Check();
#endif
}
#if (SECURITY_HASH_ENABLE == STD_ON)
/**
 * This method is used the test the compute and verify SHA256
 * @param     none
 * @return    void
 */
static void SysTst_Integrity_Check(void)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 resultPtr[HASH_LENGTH] = {0};
    uint32 resultLength = HASH_LENGTH;
    uint32 dataLength= DATA_LENGHTH_ONECYCLE;
    uint32 * resultLengthPtr = &resultLength;
    uint8 * compareptr =(uint8 *) ADDRESS_END;
    uint8 index = 0u;
    uint32 lfinalblockaddress = ((ADDRESS_END + HASH_LENGTH) - DATA_LENGHTH_ONECYCLE)-1UL;
    switch(Nor_Checkstate)
    {
    case CRYPTO_STREAMSTART:
        ret = Csm_Hash(CSMJOBID_RSA_HASH,CRYPTO_OPERATIONMODE_STREAMSTART,dataPtr, dataLength, resultPtr, resultLengthPtr );
        if  (E_OK == ret)
        {
            Nor_Checkstate = CRYPTO_UPDATE;
        }
        break;
    case CRYPTO_UPDATE:
        ret = Csm_Hash(CSMJOBID_RSA_HASH,CRYPTO_OPERATIONMODE_UPDATE,dataPtr, dataLength, resultPtr, resultLengthPtr );
        break;
    case CRYPTO_FINALBLOCK_UPDATE:
        dataLength =(ADDRESS_END - ADDRESS_START )%DATA_LENGHTH_ONECYCLE ;
        if (0UL == dataLength)
        {
            dataLength = DATA_LENGHTH_ONECYCLE;
            ret = E_OK;
        }
        else
        {
            ret = Csm_Hash(CSMJOBID_RSA_HASH,CRYPTO_OPERATIONMODE_UPDATE,dataPtr, dataLength, resultPtr, resultLengthPtr );
        }
        if  (E_OK == ret)
        {
            ret = Csm_Hash(CSMJOBID_RSA_HASH,CRYPTO_OPERATIONMODE_FINISH,dataPtr, dataLength, resultPtr, resultLengthPtr );
        }
        if  (E_OK == ret)
        {
            for (index = 0; index < HASH_LENGTH; index++)
            {
                if (compareptr[index] != resultPtr[index])
                {
                    ret = E_NOT_OK;
#if (MCU_RESET_ENABLE == STD_ON)
                    Mcu_PerformReset();
#endif
                }
            }
        }
        Nor_Checkstate = CRYPTO_FINISH ;
        break;
    default:
        /*Do nothing*/
        break;
    }
    if (CRYPTO_FINISH != Nor_Checkstate )
    {
        if  (E_OK == ret)
        {
            dataPtr = dataPtr + DATA_LENGHTH_ONECYCLE;
            if ( (uint32)dataPtr > lfinalblockaddress )
            {
                Nor_Checkstate = CRYPTO_FINALBLOCK_UPDATE;
            }
        }
        else
        {
            if ( MAX_RETRY_COUNT == lhash_notok_Count )
            {
#if (MCU_RESET_ENABLE == STD_ON)
                Mcu_PerformReset();
#endif
            }
            lhash_notok_Count++;
        }
    }
}
#endif

#if (STARTUPTEST_ENABLE == STD_ON)
/**
 * This method is the Startup test function for SysTst module
 * @param     none
 * @return    void
 */
void SysTst_StartupTest(void)
{
    FlsTst_TestResultFgndType FlsTst_FgndResult = FLSTST_NOT_TESTED;
    FlsTst_ErrorDetailsType FlsTst_ErrorDitail;
    FlsTst_BlockIdFgndType FlsTstBlockID = SAFETYRAM_TESTBLOCKID;
    Std_ReturnType ret = E_NOT_OK;
    ret = FlsTst_StartFgnd(FlsTstBlockID);
    if (E_OK == ret)
    {
        FlsTst_FgndResult = FlsTst_GetTestResultFgnd();
        if( FLSTST_OK == FlsTst_FgndResult )
        {
            /*Do Nothing*/
        }
        else
        {
            FlsTst_ErrorDitail = FlsTst_GetErrorDetails();
            if(ECC_DOUBLEBITERROR == FlsTst_ErrorDitail.BitError)
            {
#if (MCU_RESET_ENABLE == STD_ON)
                /*If it is double bit error, reset the system*/
                Mcu_PerformReset();
#endif
            }
        }
    }
}
#endif
/**
 * This method De-initialize the SysTst module
 * @param     none
 * @return    void
 */
void SysTst_DeInit(void)
{

}

#define SYSTST_STOP_SEC_CODE
#include "SysTst_MemMap.h"

#endif /*SYSTST_C*/
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
 Change Description:Initial Version for SysTst implementation
 ******************************************************************************/
/*****************************************************************************
 Date              :08-Jan-2022
 By                :gpalani1
 Traceability      :RTC
 Change Description:Intialized "resultLength = HASH_LENGTH" in
 					  SysTst_Integrity_Check to avoid reset
******************************************************************************/
/*****************************************************************************
 Date              :05-May-2022
 By                :nchellap
 Traceability      :RTC
 Change Description:Coverity and Misra warning Analyse and Fix
******************************************************************************/ 

