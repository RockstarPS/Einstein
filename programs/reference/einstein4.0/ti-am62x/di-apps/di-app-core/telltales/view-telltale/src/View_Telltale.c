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
#include "Rte_CView_Telltale.h"
#include "Rte_CCtrl_Telltale_Type.h"
#include "View_Telltale_Cfg.h"
#include "CmpLib.h"
#include "View_Telltale.h"
#include "View_TT_Cfg.h"

#ifndef VIEW_TT_DOUT_PIN
#error "View_TT_Cfg.h: VIEW_TT_DOUT_PIN function macro definition is missing. Configure the respective Rte interface in Excel utility"
#endif

#ifndef POST_TTSTATUS_TO_HMI_THRU_RTE
#error "View_TT_Cfg.h: POST_TTSTATUS_TO_HMI_THRU_RTE function macro definition is missing. Configure the respective Rte interface in Excel utility "
#endif

#ifndef CTRL_TELLTALE_DATA
#error "View_TT_Cfg.h: CTRL_TELLTALE_DATA function macro definition is missing. Configure the respective Rte interface in Excel utility "
#endif

#ifndef RTE_READ_TT_OUTPUT_ARRAY
#error "View_TT_Cfg.h: RTE_READ_TT_OUTPUT_ARRAY function macro definition is missing. Configure the respective Rte interface in Excel utility "
#endif

#ifndef UCL_HMI_SEND
#error "View_TT_Cfg.h: UCL_HMI_SEND function macro definition is missing. Configure the respective Rte interface in Excel utility "
#endif


/// @brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE(View_Telltale)


typedef struct STtTableData_T
{
    uint8 tt_driven_type_U8;
    uint8 tt_mapped_pin_info_U8;
}STtTableData;


static STT_Status TelltaleStatusData;

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================
static STtTableData const TelltaleOutputList[TT_TOTAL_NUM_OF_TELLTALES] = cTtOutputTableList;
static uint8 TelltaleInputStatus[TT_TOTAL_NUM_OF_TELLTALES];

static void WriteTTStatus(void);


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit( void )
{
    uint8 index; 
	Std_ReturnType result = E_OK;
	for(index=0; index < TT_OUTPUT_BYTES; index++)
    {
        TelltaleStatusData.mask[index] = 0;
    }
    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit( void )
{ 
    Std_ReturnType result = E_OK;
    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActivation( void )
{
    Std_ReturnType result = E_OK;
    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeActivation( void )
{
	Std_ReturnType result = E_OK;
    return  result;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  State for normal operations
///
/// @return The return value is disregarded. Say E_OK
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive( void )
{ 
    Std_ReturnType result = E_OK;

    /*Read the Telltale status from the array TelltaleInputStatus through Rte Read Interface */
    (void)RTE_READ_TT_OUTPUT_ARRAY(TelltaleInputStatus);
   
    WriteTTStatus();
	
    return result;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Diagnostic state
///
/// @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag( void )
{
    Std_ReturnType result = E_OK;
    return result;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional state to clean up after diagnostic state. Component behaviour to be restored.
///
/// @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn( void )
{
    Std_ReturnType result = E_OK;
    return result;
}


/*============================================================================
 ** Function Name       : void ViewTelltale_SendTelltaleStatus(uint8 index, boolean TT_status)
 ** Description         : This function set the particular bit if telltale is ON
 ** Input Parameters:   : index, TT_status
 ** Outputs             : TelltaleStatusData
 **==========================================================================*/
void ViewTelltale_SendTelltaleStatus(uint8 index, uint8 TT_status)
{
    uint8 fl_byte_pos;
    uint8 fl_bit_pos;
    if(TT_TOTAL_NUM_OF_TELLTALES > index)
    {
        /* "To determine the specific byte position, we should divide each index by 1 byte. The resulting quotient will represent the byte position." */
        fl_byte_pos = (uint8)(index / BYTE);

        /* "To determine the specific bit position, we should calculate the remainder of each index by using the modulus operator, followed by right-shifting it by 1u" */
        fl_bit_pos = (uint8)((uint32)1u<<(index % BYTE));
      
        if(TT_TURN_ON == TT_status)
        {
            /* Setting a specific bit in the mask array using a calculated byte position (fl_byte_pos) and a bit position (fl_bit_pos) */
            SETBIT(TelltaleStatusData.mask[fl_byte_pos],fl_bit_pos);          
        }
        else
        {   
            /* Clearing a specific bit in the mask array using a calculated byte position (fl_byte_pos) and a bit position (fl_bit_pos) */
            CLEARBIT(TelltaleStatusData.mask[fl_byte_pos],fl_bit_pos);
        }
    }

    /*RTE Write Interface From View_telltale to UCL */
	UCL_HMI_SEND(CTRL_TELLTALE_DATA,TelltaleStatusData);
}

/*============================================================================
 ** Function Name       :void WriteTTStatus(void)
 ** Description         :This function set the telltale type of the TT.
 ** Input Parameters:   : void 
 ** Outputs             :TT status
 **==========================================================================*/
static void WriteTTStatus(void)
{
    uint8 index;
    for(index = 0; index < TT_TOTAL_NUM_OF_TELLTALES; index++)
    {
        if(TelltaleOutputList[index].tt_driven_type_U8 == (uint8)cTT_HARDWARE_DRIVEN)
        {
            /* Call the Specific Function to set ore clear the pin out through this MACRO VIEW_TT_DOUT_PIN */
            VIEW_TT_DOUT_PIN(TelltaleOutputList[index].tt_mapped_pin_info_U8,TelltaleInputStatus[index]);
        }
        else
        {
            /* Call ViewTelltaleUpdate_OutputDatas_Direct Function through this MACRO POST_TTSTATUS_TO_HMI_THRU_RTE */
            POST_TTSTATUS_TO_HMI_THRU_RTE(index, TelltaleInputStatus[index]);
        }
    }
}



/*============================================================================
 **============================================================================*/
/***  P V C S    R E V I S I O N    N O T E S**/
/**----------------------------------------------------------------------------
 **  For each change to this file, be sure to record:
 **  1.  who made the change and when the change was made
 **  2.  why the change was made and the intended result
 **
 **  Date         By      Reason for Change
 **  mmm/dd/yy    XXX
 **----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date              : 30-04-2024
CDSID             : abetager
Traceability      : HONDA28384-13930: MainScreen-TFT Telltales manager from Bookshelf
Change Description: View_Telltale file updated for Telltale manager.
-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date              : 16-08-2024
CDSID             : ckulothu
Traceability      : DICMBD-164 MainScreen-TFT Telltales manager from Bookshelf
Change Description: View_Telltale file updated for Telltale manager.
-----------------------------------------------------------------------------*/
/*Endof revision history*/
