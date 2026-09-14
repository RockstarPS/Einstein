/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2025. Visteon Corporation owns all rights to this work and
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
 **==========================================================================*/
#include "Rte_View_Illumination.h" 
#include "CmpLib.h"
#include "View_Illumination.h"
#include "View_Illum_Cfg.h"


static View_Ip fl_View_Ip;

//@brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE(View_Illumination)

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit(void)
{
    Std_ReturnType result = E_OK;
    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit(void)
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
static Std_ReturnType CmpActivation(void)
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
static Std_ReturnType CmpDeActivation(void)
{
    Std_ReturnType result = E_OK;
    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  State for normal operations
///
/// @return The return value is disregarded. Say E_OK
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive(void)
{
    Std_ReturnType result = E_OK;
    Input_Processing();
    Process_View_Illumination();
    return result;

}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Diagnostic state
///
/// @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag(void)
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
static Std_ReturnType CmpDiagReturn(void)
{
    Std_ReturnType result = E_OK;
    return result;
}

/*============================================================================
** Function Name:      Input_Processing
** Description:        This Function is used to recieve the Input from Ctrl
** Input Parameters:   void   
** Outputs:            void
** JIRA:               DICMBD-1340
**==========================================================================*/
static void Input_Processing(void)
{
    VIEW_ILLUMINATION_INPUT_ADAPATER(&fl_View_Ip);
}


/*============================================================================
** Function Name:      Process_View_Illumination
** Description:        This Function is used to Process all Output modes
** Input Parameters:   IllumView_Ip l_IllumView_Ip   
** Outputs:            void
** JIRA:               DICMBD-1343
**==========================================================================*/
static void Process_View_Illumination(void)
{  
   for(uint8 index = 0; index < BYTE_LENGTH; index++)
    {
        if(APPL_ILLUMINATION_DATA & (1u << index))
        {
            switch(index)
            {
                case 7u:
                    Duty_Mode_Process(fl_View_Ip.Duty_Out);
                    break;
                
                case 6u:
                    Brightness_Mode_Process(fl_View_Ip.Brightness_Out);
                    break;
                
                case 5u:
                    RGB_Mode_Process(fl_View_Ip.RGB_Out);
                    break;
                
                case 4u:
                    Bulb_Mode_Process(fl_View_Ip.Bulb_Out);
                    break;
                
                case 3u:
                    LED_Mode_Process(fl_View_Ip.LED_Out);
                    break;
                
                case 2u:                
                    Dial_Mode_Process(fl_View_Ip.Dial_Out);
                    break;
                
                case 1u:
                    Display_Mode_Process(fl_View_Ip.Display_Out);
                    break;
                
                case 0u:
                    Telltale_Mode_Process(fl_View_Ip.Telltale_Out);
                    break;
                
                default:
                    //Do nothing
                    break;
            }
        }
        else
        {
           /*The Illumination Data is not Applicable*/
        }
    } 
   
}

/*============================================================================
** Function Name:      Duty_Mode_Process
** Description:        Identify the output mode of Duty data
** Input Parameters:   l_PWMData
** Outputs:            void
** JIRA:               DICMBD-1345, DICMBD-1346, DICMBD-1347
**==========================================================================*/
void Duty_Mode_Process(uint16 l_PWMData[NO_OF_DUTY])
{
    uint8 OutMode[NO_OF_DUTY] = DUTY_OUT_TYPE;
    uint8 OutID[NO_OF_DUTY] = DUTY_ID_TYPE;
    
    for(uint8 index=0; index < NO_OF_DUTY; index++)
    {
        switch(OutMode[index])
        {
            case IOHWAB_OUT:
                    SEND_TO_IOHWAB(l_PWMData[index],OutID[index]);
                    break;

            case UCL_OUT:
                    SEND_TO_UCL(l_PWMData[index],OutID[index]);
                    break;
        
            case CAN_OUT:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;

            default:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;        
                       
        }
    }
    
}

/*============================================================================
** Function Name:      Bulb_Mode_Process
** Description:        Identify the output mode of Bulb data
** Input Parameters:   l_PWMDataa   
** Outputs:            void
** JIRA:               DICMBD-1345, DICMBD-1346, DICMBD-1347
**==========================================================================*/
void Bulb_Mode_Process(uint16 l_PWMData[NO_OF_BULB])
{
    uint8 OutMode[NO_OF_BULB] = BULB_OUT_TYPE;
    uint8 OutID[NO_OF_BULB] = BULB_ID_TYPE;
    
    for(uint8 index=0; index < NO_OF_BULB; index++)
    {
        switch(OutMode[index])
        {
            case IOHWAB_OUT:
                    SEND_TO_IOHWAB(l_PWMData[index],OutID[index]);
                    break;

            case UCL_OUT:
                    SEND_TO_UCL(l_PWMData[index],OutID[index]);
                    break;
        
            case CAN_OUT:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;

            default:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;        
                       
        }
    }
}

/*============================================================================
** Function Name:      LED_Mode_Process
** Description:        Identify the output mode of LED data
** Input Parameters:   l_PWMData   
** Outputs:            void
** JIRA:               DICMBD-1345, DICMBD-1346, DICMBD-1347
**==========================================================================*/
void LED_Mode_Process(uint16 l_PWMData[NO_OF_LED])
{
    uint8 OutMode[NO_OF_LED] = LED_OUT_TYPE;
    uint8 OutID[NO_OF_LED] = LED_ID_TYPE;
    
    for(uint8 index=0; index < NO_OF_LED; index++)
    {
        switch(OutMode[index])
        {
            case IOHWAB_OUT:
                    SEND_TO_IOHWAB(l_PWMData[index],OutID[index]);
                    break;

            case UCL_OUT:
                    SEND_TO_UCL(l_PWMData[index],OutID[index]);
                    break;
        
            case CAN_OUT:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;

            default:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;        
                       
        }
    }
}

/*============================================================================
** Function Name:      Dial_Mode_Process
** Description:        Identify the output mode of Dial data
** Input Parameters:   l_PWMData  
** Outputs:            void
** JIRA:               DICMBD-1345, DICMBD-1346, DICMBD-1347
**==========================================================================*/
void Dial_Mode_Process(uint16 l_PWMData[NO_OF_DIAL])
{
    uint8 OutMode[NO_OF_DIAL] = DIAL_OUT_TYPE;
    uint8 OutID[NO_OF_DIAL] = DIAL_ID_TYPE;
    
    for(uint8 index=0; index < NO_OF_DIAL; index++)
    {
        switch(OutMode[index])
        {
            case IOHWAB_OUT:
                    SEND_TO_IOHWAB(l_PWMData[index],OutID[index]);
                    break;

            case UCL_OUT:
                    SEND_TO_UCL(l_PWMData[index],OutID[index]);
                    break;
        
            case CAN_OUT:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;

            default:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;        
                       
        }
    }
}

/*============================================================================
** Function Name:      LCD_Mode_Process
** Description:        Identify the output mode of LCD data
** Input Parameters:   l_PWMData   
** Outputs:            void
** JIRA:               DICMBD-1345, DICMBD-1346, DICMBD-1347
**==========================================================================*/
void Display_Mode_Process(uint16 l_PWMData[NO_OF_DISPLAYS])
{
    uint8 OutMode[NO_OF_DISPLAYS] = DISPLAY_OUT_TYPE;
    uint8 OutID[NO_OF_DISPLAYS] = DISPLAY_ID_TYPE;
    
    for(uint8 index=0; index < NO_OF_DISPLAYS; index++)
    {
        switch(OutMode[index])
        {
            case IOHWAB_OUT:
                    SEND_TO_IOHWAB(l_PWMData[index],OutID[index]);
                    break;

            case UCL_OUT:
                    SEND_TO_UCL(l_PWMData[index],OutID[index]);
                    break;
        
            case CAN_OUT:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;

            default:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;        
                       
        }
    }
}

/*============================================================================
** Function Name:      Brightness_Mode_Process
** Description:        Identify the output mode of Brightness data
** Input Parameters:   l_PWMData   
** Outputs:            void
** JIRA:               DICMBD-1345, DICMBD-1346, DICMBD-1347
**==========================================================================*/
void Brightness_Mode_Process(uint16 l_PWMData[NO_OF_BGT])
{
    uint8 OutMode[NO_OF_BGT] = BGT_OUT_TYPE;
    uint8 OutID[NO_OF_BGT] = BGT_ID_TYPE;
    
    for(uint8 index=0; index < NO_OF_BGT; index++)
    {
        switch(OutMode[index])
        {
            case IOHWAB_OUT:
                    SEND_TO_IOHWAB(l_PWMData[index],OutID[index]);
                    break;

            case UCL_OUT:
                    SEND_TO_UCL(l_PWMData[index],OutID[index]);
                    break;
        
            case CAN_OUT:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;

            default:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;        
                       
        }
    }
}

/*============================================================================
** Function Name:      RGB_Mode_Process
** Description:        Identify the output mode of RGB data
** Input Parameters:   l_PWMData   
** Outputs:            void
** JIRA:               DICMBD-1345, DICMBD-1346, DICMBD-1347
**==========================================================================*/
void RGB_Mode_Process(uint16 l_PWMData[NO_OF_RGB])
{
    uint8 OutMode[NO_OF_RGB] = RGB_OUT_TYPE;
    uint8 OutID[NO_OF_RGB] = RGB_ID_TYPE;
    
    for(uint8 index=0; index < NO_OF_RGB; index++)
    {
        switch(OutMode[index])
        {
            case IOHWAB_OUT:
                    SEND_TO_IOHWAB(l_PWMData[index],OutID[index]);
                    break;

            case UCL_OUT:
                    SEND_TO_UCL(l_PWMData[index],OutID[index]);
                    break;
        
            case CAN_OUT:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;

            default:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;        
                       
        }
    }
}

/*============================================================================
** Function Name:      Telltale_Mode_Process
** Description:        Identify the output mode of each Telltale
** Input Parameters:   l_PWMData  
** Outputs:            void
** JIRA:               DICMBD-1345, DICMBD-1346, DICMBD-1347
**==========================================================================*/
void Telltale_Mode_Process(uint16 l_PWMData[NO_OF_TELLTALES])
{
    uint8 OutMode[NO_OF_TELLTALES] = TELLTALE_OUT_TYPE;
    uint8 OutID[NO_OF_TELLTALES] = TT_ID_TYPE;
    
    for(uint8 index=0; index < NO_OF_TELLTALES; index++)
    {
        switch(OutMode[index])
        {
            case IOHWAB_OUT:
                    SEND_TO_IOHWAB(l_PWMData[index],OutID[index]);
                    break;

            case UCL_OUT:
                    SEND_TO_UCL(l_PWMData[index],OutID[index]);
                    break;
        
            case CAN_OUT:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;

            default:
                    SEND_TO_CAN(l_PWMData[index],OutID[index]);
                    break;        
                       
        }
    }
}

/*============================================================================
**
** Date              : 16-05-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-16462
** Change Description: View-Illumination - Inital version
**
**============================================================================*/
/*============================================================================
**
** Date              : 28-07-2025
** CDSID             : aelango6
** Traceability      : DICMBD-1303
** Change Description: Requirement Traceability added
**
**============================================================================*/

