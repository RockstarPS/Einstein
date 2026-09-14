/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2025] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file vHsmDmnMgr.c
 *
 * \brief
 * Domain Manger API's for triggering HSM core graceshutdown
 *
 *
 * \version 1.0.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 16/Jun/'25 | kjohn    |         |                                       |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Banumathi Jayaram        | bjayara2  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Sudhakar Magesh          | msudhaka  | VTSC, Coimbatore, India
 ******************************************************************************/
#include "Crypto_She.h"
#include "string.h"
#include "vHsmShutdownMgr.h"
#include "Rte_Type.h"
#include "vHsmCryptoManager.h"
#include "vHsmIpcHostManager.h"
#include "vHsmCryptoMessageM7.h"

typedef enum
{
    e_DmnMgr_Uninit = 0,
    e_DmnMgr_Idle = 1,
    e_DmnMgr_Req = 2,
    e_DmnMgr_ReqWait = 3,
}vHsmDmnMgrStatusState_te;


typedef struct
{
    vHsmDmnMgrStatusState_te                 state;
    uint8                                    faultLog_U8;
    boolean                                  CallbackNeeded;
}
vHsmDmnMgrStateType_ts;

/*==[Constants with internal linkage]=========================================*/
#define DMNMGRMAXTIMEOUT    50000u

/*==[Definition of functions with external linkage]===========================*/

extern void HSM_DmnMgr_SystemChangeResponse(ESystemState  Response);

#define HSMIPSEC_FINISHNOTIFICATION HSM_DmnMgr_SystemChangeResponse


/*==[Declaration of functions with internal linkage]==========================*/

STATIC FUNC(void, CRY_CODE) vHsmDmnMgrFinish_Callback(Std_ReturnType param);
STATIC FUNC(void, CRY_CODE) vHsmDmnMgr_ResetFaultCounter(void );
STATIC FUNC(boolean, CRY_CODE) vHsmDmnMgr_CheckFaultPeriodic(void );
STATIC FUNC(void, CRY_CODE) vHsmDmnMgr_ActiononFault(void);


/*==[Variables with internal linkage]=========================================*/

STATIC vHsmDmnMgrStateType_ts vHsmDmnMgr_State_S = {0};

STATIC ts_vHsm_Commanddata vHsmDmnMgrPackedData_S;

STATIC boolean vHsmDmnMgrWrite_Completed;

STATIC boolean vHsmDmnMgrWrite_Error;

STATIC uint8 vHsmDmnMgr_Buffer[2] = {0};

STATIC uint32 l_DmnMgrFaultCounter_U32 = 0;

STATIC uint8 l_DmnMgrcallbackParam = E_NOT_OK;

/**
 *********************************************************************************************
 ** \copydoc vHsmDmnMgr_Init
 *********************************************************************************************
 */
void vHsmDmnMgr_Init(void)
{
    if(e_DmnMgr_Uninit == vHsmDmnMgr_State_S.state)
    {
        vHsmDmnMgr_State_S.CallbackNeeded = FALSE;
        vHsmDmnMgr_State_S.faultLog_U8 = 0;
        vHsmDmnMgr_State_S.state = e_DmnMgr_Idle;
        vHsmDmnMgrWrite_Completed = FALSE;
        vHsmDmnMgrWrite_Error = FALSE;
    }
}

/**
 *********************************************************************************************
 ** \copydoc HSM_DmnMgr_SystemChangeRequest
 *********************************************************************************************
 */
Std_ReturnType HSM_DmnMgr_SystemChangeRequest(ESystemState Request)
{
    Std_ReturnType retVal = E_OK;
    if(vHsmDmnMgr_State_S.state != e_DmnMgr_Idle)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        vHsmDmnMgrWrite_Completed = FALSE;
        vHsmDmnMgrWrite_Error = FALSE;
        vHsmDmnMgr_State_S.state = e_DmnMgr_Req;
        vHsmDmnMgr_State_S.CallbackNeeded = TRUE;
    }
    return retVal;
}

/**
 *********************************************************************************************
 ** \copydoc vHsmDmnMgr_MainFunction
 *********************************************************************************************
 */
void vHsmDmnMgr_MainFunction(void)
{
    switch (vHsmDmnMgr_State_S.state)
    {
        case e_DmnMgr_Req:
            vHsmDmnMgrPackedData_S.jobId_E = SID_4_DMNMGR_REQ_FN;
            vHsmDmnMgrPackedData_S.priority_U8 = 0u;
            vHsmDmnMgrPackedData_S.payLoadPtr_U8P = &vHsmDmnMgr_Buffer[0];
            vHsmDmnMgrPackedData_S.payLoadSize = 1u; /* no payload */
            vHsmDmnMgrWrite_Completed = FALSE;
            vHsmDmnMgrWrite_Error = FALSE;
            if(E_OK == vHsmCrypto_Command_SendData(vHsmDmnMgrPackedData_S))
            {
                vHsmDmnMgr_State_S.state = e_DmnMgr_ReqWait;
                vHsmDmnMgr_ResetFaultCounter();
            }
            else
            {
                vHsmDmnMgr_ActiononFault();
            }
            break;
        case e_DmnMgr_ReqWait:
            if(TRUE == vHsmDmnMgrWrite_Completed)
            {
                vHsmDmnMgr_State_S.state = e_DmnMgr_Idle;
                if(FALSE == vHsmDmnMgrWrite_Error)
                {
                    l_DmnMgrcallbackParam = E_OK;
                }
                else
                {
                    l_DmnMgrcallbackParam = E_NOT_OK;
                }
                vHsmDmnMgrFinish_Callback(l_DmnMgrcallbackParam);
            }
            else
            {
                /* Keep waiting for callback from HSM
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == vHsmDmnMgr_CheckFaultPeriodic())
                {
                    vHsmDmnMgr_ActiononFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        default:
            break;
    }
}


/******************************************************************************
 ** \fn vHsmDmnMgr_Callback
 **
 ** Callback from HSM core
 **
 ** This function returns None 
 **
 ** \param [out] p_resultBytesInSRAM_U8P
 *****************************************************************************/
__attribute__((used))
FUNC(void, CRY_CODE) vHsmDmnMgr_Callback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size)
{
    uint8 status = *p_resultBytesInSRAM_U8P;
    switch (vHsmDmnMgr_State_S.state)
    {
        case e_DmnMgr_ReqWait:
            vHsmDmnMgrWrite_Completed = TRUE;
            if((CRYPTO_JOB_DONE == status) && (1u == payload_size))
            {
               /*Do Nothing Correct condition*/
            }
            else
            {
                vHsmDmnMgrWrite_Error = TRUE;
            }
        break;
        default:
        break;
    }
}


/******************************************************************************
 ** \fn vHsmDmnMgr_ActiononFault
 **
 ** Trigger fault incase no response from HSM within Time frame
 **
 ** This function returns None 
 **
 ** \param none
 *****************************************************************************/
STATIC FUNC(void, CRY_CODE) vHsmDmnMgr_ActiononFault(void)
{
    /* Scenarios landing up here -
     * 1. IPC is not available for transfer of data
     * 2. Error in last transfer
     * 3. No callback called for more than 1sec */
    if(vHsmDmnMgr_State_S.faultLog_U8 < FALUT_LOG_MAX_VAL)
    {
        vHsmDmnMgr_State_S.faultLog_U8++;
    }
    vHsmDmnMgrWrite_Error = TRUE;
    vHsmDmnMgr_State_S.state = e_DmnMgr_Idle;
    vHsmDmnMgrFinish_Callback(E_NOT_OK);
    vHsmDmnMgr_ResetFaultCounter();
}

/******************************************************************************
 ** \fn vHsmDmnMgr_CheckFaultPeriodic
 **
 ** Checks timeout counter
 **
 ** This function returns boolean - TRUE, FALSE 
 **
 ** \param none
 *****************************************************************************/
STATIC FUNC(boolean, CRY_CODE) vHsmDmnMgr_CheckFaultPeriodic(void )
{
    boolean fl_ret_E = FALSE;
    if(l_DmnMgrFaultCounter_U32 >= DMNMGRMAXTIMEOUT)
    {
        fl_ret_E = TRUE;
    }
    else
    {
        l_DmnMgrFaultCounter_U32++;
    }
    return(fl_ret_E);
}

/******************************************************************************
 ** \fn vHsmDmnMgr_ResetFaultCounter
 **
 ** Resets the Timer for Monitoring
 **
 ** This function returns none 
 **
 ** \param none
 *****************************************************************************/
STATIC FUNC(void, CRY_CODE) vHsmDmnMgr_ResetFaultCounter(void )
{
	l_DmnMgrFaultCounter_U32 = 0;
}

/******************************************************************************
 ** \fn vHsmDmnMgrFinish_Callback
 **
 ** Callback Function to upper layer
 **
 ** This function returns None 
 **
 ** \param [out] param
 *****************************************************************************/
STATIC FUNC(void, CRY_CODE) vHsmDmnMgrFinish_Callback(Std_ReturnType param)
{
    if (TRUE == vHsmDmnMgr_State_S.CallbackNeeded)
    {
        vHsmDmnMgr_State_S.CallbackNeeded = FALSE;
        HSMIPSEC_FINISHNOTIFICATION(param);
    }
}



 /*EOF*/
