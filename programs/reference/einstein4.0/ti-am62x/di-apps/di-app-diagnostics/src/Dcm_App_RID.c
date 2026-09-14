/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2022. Visteon Corporation owns all rights to           *
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
/******************************************************************************/
/**
 * @file            Dcm_App_RID.c
 * @brief           Dcm_App_RID
 * @details         Implements routine countrol services
 * @author          pthanda1
 * Organization     Driver Information Software Section,
 *                  Visteon Corporation
 */
/******************************************************************************/

#include "Dcm_App.h"
//#include "Rte_DcmApp.h"

#define DCM_APP_RID_MAX_COUNT          ((uint8)1U)

typedef Std_ReturnType (*RID_handler_FncType)(teDiagOpStatus pOpStatus, 
		P2VAR(uint8, AUTOMATIC, RTE_DCM_APP_APPL_VAR)pData,
		P2VAR(uint16, AUTOMATIC, RTE_DCM_APP_APPL_VAR) DataLength,
		P2VAR(uint8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pNrc,
		teRoutineOperation eOperation
);
				
typedef struct
{
  uint16 l_RID_Num_U16;
  RID_handler_FncType RID_handler_Func_ptr;
}Diag_handler_RIDInfo_t;

static const Diag_handler_RIDInfo_t Dcm_App_RID_Table[DCM_APP_RID_MAX_COUNT]= 
{                             
	{0XFD90, &Dcm_App_RID_FD90_handler}  /* NVM Flashing */
};
/*************************************************************************//**
 * \brief          CDcm_App_RID_Common_Init()
 * \details        this function called from Dcm_App.c to clear  variable
 * 		           after routine timeout
 * \param [in]     void
 * \retval         void
 *
 * \note           Critical Section:  None.
 ****************************************************************************/
void CDcm_App_RID_Common_Init(void)
{

}
/*************************************************************************//**
 * \brief          CDcmApp_RID_DiagAction()
 *
 * \details        Implements Routine control - application actions.
 * \n              Invoked by DcmExt.
 *
 * \param [in]     teDiagOpStatus pOpStatus:
 * \param [in]     uint8 *pData:
 * \param [in]     uint16 *DataLength:
 * \param [in]     uint8 *pNrc:
 * \param [in]     teRoutineOperation eOperation:
 *
 * \retval         TBD:
 *
 * \note           Critical Section:  None.
 ****************************************************************************/
/*FUNC(Std_ReturnType, Dcm_App_CODE) */Std_ReturnType CDcmApp_RID_DiagAction
                ( teDiagOpStatus OpStatus, 
                  uint16 RIDNum, 
                  P2VAR(uint8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Out_RoutineInfo,
                  P2VAR(uint8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Data,
                  P2VAR(uint16, AUTOMATIC, RTE_DCM_APP_APPL_VAR) DataLength,
                  P2VAR(uint8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pNrc,
                  teRoutineOperation eOperation
                )
{
    uint8 fl_RID_Item_U8;
    uint8 fl_resp_val_U8P;
    fl_resp_val_U8P = E_OK;

    
    for (fl_RID_Item_U8 = 0U; fl_RID_Item_U8 < DCM_APP_RID_MAX_COUNT; fl_RID_Item_U8++)
    {
        if (Dcm_App_RID_Table[fl_RID_Item_U8].l_RID_Num_U16 == RIDNum)
        {
        	fl_resp_val_U8P = Dcm_App_RID_Table[fl_RID_Item_U8].RID_handler_Func_ptr(OpStatus, Data, DataLength, pNrc, eOperation);
        }
    }
    
    return fl_resp_val_U8P;
}
/*************************************************************************//**
 * \brief          Dcm_App_RID_FD90_handler()
 *
 * \details        
 * \n              
 *
 * \param [in]     teDiagOpStatus pOpStatus:
 * \param [in]     uint8 *pData:
 * \param [in]     uint16 *DataLength:
 * \param [in]     uint8 *pNrc:
 * \param [in]     teRoutineOperation eOperation:
 *
 * \retval         Std_ReturnType: E_OK:           Succeed
 * 								   E_NOT_OK:       Failed
 *
 * \note           Critical Section:  None.
 ****************************************************************************/
Std_ReturnType Dcm_App_RID_FD90_handler( teDiagOpStatus pOpStatus,
                          P2VAR(uint8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pData,
                          P2VAR(uint16, AUTOMATIC, RTE_DCM_APP_APPL_VAR) DataLength,
                          P2VAR(uint8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pNrc,
                          teRoutineOperation eOperation
                        )
{
    Std_ReturnType ret = E_NOT_OK;
   
    if(eOperation == eRoutineStart)
    {
		ret = E_OK;
	}
    else if(eOperation == eRoutineStop)
    {
    	ret = E_OK;
    }
    else if(eOperation == eRoutineResults)
    {
		ret = E_OK;
    }
    else
    {
    	ret = E_NOT_OK;
    	*pNrc = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret;
}

/*End of File*/					  
/****************************************************************************
 *   for each change to this file, be sure to record:                        *
 *      1.  who made the change and when the change was made                 *
 *      2.  why the change was made and the intended result                  *
 *   Following block needs to be repeated for each change                    *
 *****************************************************************************/
/*---------------------------------------------------------------------------
Task ID           : PE4TI29141-2510 VIP:Diag Application Implementation
Date              : 05-Nov-2024
By                : pthanda1
Change Description: Initial version
-----------------------------------------------------------------------------*/