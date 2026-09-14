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
#include "Rte_Type.h"
#include "Rte_Ctrl_Illumination.h"
#include "Ctrl_Illumination_Cfg.h"
#include "Ctrl_Illumination_TypeCfg.h"
//#include "Ctrl_Illum_Cfg.h"
#include "ctrl_Illumination_Extn.h"
#include "string.h"

uint8 IllumMdl_Bulb_Value[BULB_MAX];
uint8 IllumMdl_LED_Value[LED_MAX];
uint16 IllumMdl_Dial_Value[DIAL_MAX];
uint16 IllumMdl_Display_Value[LCD_MAX];  
uint8 IllumMdl_Duty_Value[DUTY_MAX];
uint16 IllumMdl_BGT_Value[BGT_MAX];
uint16 IllumMdl_Telltale[NO_OF_TELLTALES];

IllumCtrl_Ip fl_IllumCtrl_Ip;

/*============================================================================
** Function Name:      Ctrl_Illumination_Adapter
** Description:        This Function is to process the Input data
** Input Parameters:   Ctrl_Ip *l_Ctrl_Ip 
** Outputs:            void
**==========================================================================*/
void Ctrl_Illumination_InputAdapter(Input_Data *l_Input_Data)
{
    (void)RTE_READ_ILL_MDL_DATA(&fl_IllumCtrl_Ip);

    //Display control Inputs
    l_Input_Data->Display_Control[0].Mode = fl_IllumCtrl_Ip.Illumination_Mode;
    l_Input_Data->Display_Control[0].Level = fl_IllumCtrl_Ip.step_value;
    l_Input_Data->Display_Control[0].Status = fl_IllumCtrl_Ip.Illumination_Sts;
    l_Input_Data->Display_Control[0].switching_control = fl_IllumCtrl_Ip.switch_type;

    //Led control Inputs
    l_Input_Data->LED_Control[0].Mode = fl_IllumCtrl_Ip.Illumination_Mode;
    l_Input_Data->LED_Control[0].Level = fl_IllumCtrl_Ip.step_value;
    l_Input_Data->LED_Control[0].Status = fl_IllumCtrl_Ip.Illumination_Sts;
    l_Input_Data->LED_Control[0].switching_control = fl_IllumCtrl_Ip.switch_type;

    //Bulb control Inputs
    l_Input_Data->Bulb_Control[0].Mode = fl_IllumCtrl_Ip.Illumination_Mode;
    l_Input_Data->Bulb_Control[0].Level = fl_IllumCtrl_Ip.step_value;
    l_Input_Data->Bulb_Control[0].Status = fl_IllumCtrl_Ip.Illumination_Sts;
    l_Input_Data->Bulb_Control[0].switching_control = fl_IllumCtrl_Ip.switch_type;

    //Dial control Inputs
    l_Input_Data->Dial_Control[0].Mode = fl_IllumCtrl_Ip.Illumination_Mode;
    l_Input_Data->Dial_Control[0].Level = fl_IllumCtrl_Ip.step_value;
    l_Input_Data->Dial_Control[0].Status = fl_IllumCtrl_Ip.Illumination_Sts;
    l_Input_Data->Dial_Control[0].switching_control = fl_IllumCtrl_Ip.switch_type;

    //Duty control Inputs
    l_Input_Data->Duty_Control[0].Mode = fl_IllumCtrl_Ip.Illumination_Mode;
    l_Input_Data->Duty_Control[0].Level = fl_IllumCtrl_Ip.step_value;
    l_Input_Data->Duty_Control[0].Status = fl_IllumCtrl_Ip.Illumination_Sts;
    l_Input_Data->Duty_Control[0].switching_control = fl_IllumCtrl_Ip.switch_type;

    //Telltale control Inputs
    l_Input_Data->Telltale_Control[0].Mode = fl_IllumCtrl_Ip.Illumination_Mode;
    l_Input_Data->Telltale_Control[0].Level = fl_IllumCtrl_Ip.step_value;
    l_Input_Data->Telltale_Control[0].Status = fl_IllumCtrl_Ip.Illumination_Sts;
    l_Input_Data->Telltale_Control[0].switching_control = fl_IllumCtrl_Ip.switch_type;

}

/*============================================================================
** Function Name:      Ctrl_Illumination_Adapter
** Description:        This Function is to process the Input data
** Input Parameters:   Ctrl_Ip *l_Ctrl_Ip 
** Outputs:            void
**==========================================================================*/
void Ctrl_Illumination_OutputAdapter(Ctrl_Op l_Ctrl_Op)
{
    IllumCtrl_Op fl_IllumCtrl_Op;
  
    fl_IllumCtrl_Op.Illumination_Duty_Out = l_Ctrl_Op.Duty_Out[0u];

    fl_IllumCtrl_Op.Bulb_PWM_Out = l_Ctrl_Op.Bulb_Out[0u];

    fl_IllumCtrl_Op.LED_PWM_Out = l_Ctrl_Op.LED_Out[0u];

    fl_IllumCtrl_Op.Dial_Out = l_Ctrl_Op.Dial_Out[0u];

    fl_IllumCtrl_Op.Display_Out = l_Ctrl_Op.Display_Out[0u];

    fl_IllumCtrl_Op.Brightness_Out = l_Ctrl_Op.Brightness_Out[0u];

    fl_IllumCtrl_Op.RGB_Dimming_Out = l_Ctrl_Op.RGB_Out[0u];

    fl_IllumCtrl_Op.Telltale_Out = l_Ctrl_Op.Telltale_Out[0u];
     
    (void)RTE_WRITE_IL_CTRL_DATA(&fl_IllumCtrl_Op);

}

/*============================================================================
** Function Name:      Illumination_Table_Update
** Description:        This Function is to update the Illumination data table
** Input Parameters:   IllumCtrl_Ip l_IllumCtrl_Ip 
** Outputs:            void
**==========================================================================*/
void Illumination_Table_Update(uint16 (*outputTable[])[TOT_ILLUM_MODE][TOT_STEP])
{
 
    /* Get Illumination Data*/
    for(uint8 index = 0; index < BYTE_LENGTH; index++)
    {
        if(APPL_ILLUMINATION_DATA & (1u << index))
        {
            switch(index)
            {
                case 7u:
                    Get_Duty_Data();
                    break;
                
                case 6u:
                    Get_Brightness_Data();
                    break;
                
                case 5u:
                    Get_RGB_Data();
                    break;
                
                case 4u:
                    Get_Bulb_Data();
                    break;
                
                case 3u:
                    Get_LED_Data();
                    break;
                
                case 2u:                
                    Get_Dial_Data();
                    break;
                
                case 1u:
                    Get_Display_Data();
                    break;
                
                case 0u:
                    Get_Telltale_Data();
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
    
    if(fl_IllumCtrl_Ip.power_mode == IGN_ON)
    {      
        Ign_On_Data_handle(outputTable,fl_IllumCtrl_Ip);
             
    }

    if(fl_IllumCtrl_Ip.power_mode == IGN_OFF)
    {
        Ign_Off_Data_handle(outputTable,fl_IllumCtrl_Ip);
        
    }
}

/*============================================================================
** Function Name:      Get_Duty_Data
** Description:        Get_Duty_Data
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void Get_Duty_Data(void)
{
    /*Get the Duty PWM Data*/

}

/*============================================================================
** Function Name:      Get_Bulb_Data
** Description:        Get_Bulb_Data
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void Get_Bulb_Data(void)
{
    /*Get the Bulb PWM Data*/
}

/*============================================================================
** Function Name:      Get_LED_Data
** Description:        Get_LED_Data
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void Get_LED_Data(void)
{
    /*Get the LED PWM Data*/

}

/*============================================================================
** Function Name:      Get_Dial_Data
** Description:        Get_Dial_Data
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void Get_Dial_Data(void)
{
    /*Get the Dial PWM Data*/

}


/*============================================================================
** Function Name:      Get_LCD_Data
** Description:        Get_LCD_Data
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void Get_Display_Data(void)
{
    /*Get the LCD PWM Data*/

}

/*============================================================================
** Function Name:      Get_Brightness_Data
** Description:        Get_Brightness_Data
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void Get_Brightness_Data(void)
{
    /*Get the Brighntess PWM Data*/

}

/*============================================================================
** Function Name:      Get_Telltale_Data
** Description:        Get_Telltale_Data
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void Get_Telltale_Data(void)
{

}

/*============================================================================
** Function Name:      Get_RGB_Data
** Description:        Get_RGB_Data
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void Get_RGB_Data(void)
{

}

/*Configuration of Output Table
Index-->Table
0------>Duty_Table
1------>Bulb_Table
2------>LED_Table
3------>Dial_Table
4------>Display_Table
5------>BGT_Table
6------>RGB_Table
7------>TT_Table
*/
/*============================================================================
** Function Name:      Ign_On_Data_handle
** Description:        Ign_On_Data_handle
** Input Parameters:   IllumCtrl_Ip l_IllumCtrl_Ip
** Outputs:            void
**==========================================================================*/
void Ign_On_Data_handle(uint16 (*outputTable[])[TOT_ILLUM_MODE][TOT_STEP],IllumCtrl_Ip l_IllumCtrl_Ip)
{

}

/*============================================================================
** Function Name:      Ign_Off_Data_handle
** Description:        Ign_Off_Data_handle
** Input Parameters:   IllumCtrl_Ip l_IllumCtrl_Ip
** Outputs:            void
**==========================================================================*/
void Ign_Off_Data_handle(uint16 (*outputTable[])[TOT_ILLUM_MODE][TOT_STEP],IllumCtrl_Ip l_IllumCtrl_Ip)
{

}


/*============================================================================
** Function Name:      Set_PWM_to_Default
** Description:        This Function is to update Init values
** Input Parameters:   IllumCtrl_Ip l_illumctrl_ip, IllumCtrl_Op_Ptr l_illumctrl_op
** Outputs:            void
**==========================================================================*/
void Set_PWM_to_Default(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data)
{

  
}

/*============================================================================
** Function Name:      Set_PWM_to_Off
** Description:        This Function is to set Illumination off
** Input Parameters:   IllumCtrl_Ip l_illumctrl_ip, IllumCtrl_Op_Ptr l_illumctrl_op 
** Outputs:            void
**==========================================================================*/
void Set_PWM_to_Off(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data)
{
    
    *Ill_Pwm_Data = 10u;

}

/*============================================================================
** Function Name:      Slew_Rate_Determination
** Description:        This Function is to determine the slewrate
** Input Parameters:   Sl_Ctrl_Ip l_Sl_Ctrl_Ip
** Outputs:            Sl_Ctrl_Op
**==========================================================================*/
Sl_Ctrl_Op Slew_Rate_Determination(Sl_Ctrl_Ip l_Sl_Ctrl_Ip)
{
  uint16 current_val;
  uint16 target_val;
  //uint8 update_count;

  static uint16 slew_rate;
  uint8 prevmode = 0u;
  uint16 max_val;
  uint16 min_val;
  Sl_Ctrl_Op l_SlCtrl_Op;
  
  GET_MIN_MAX_VAL_OF_TABLE(l_Sl_Ctrl_Ip.table_data, TOT_STEP, &max_val, &min_val);

  current_val = l_Sl_Ctrl_Ip.Curr_pwm;
  target_val  = l_Sl_Ctrl_Ip.tgt_pwm;
  //update_count = UPDATE_COUNT;

    if(l_Sl_Ctrl_Ip.Curr_Mode != l_Sl_Ctrl_Ip.l_Ctrl_Ip.Mode)
    {
        if(current_val > target_val)
        {
            slew_rate = 1u;//(current_val - target_val)/update_count;
            prevmode = l_Sl_Ctrl_Ip.l_Ctrl_Ip.Mode;
        }
        else if(current_val < target_val)
        {
            slew_rate = 1u;//(target_val - current_val)/update_count;
            prevmode = l_Sl_Ctrl_Ip.l_Ctrl_Ip.Mode;
        }
        else
        {
            slew_rate = 0u;
            prevmode = l_Sl_Ctrl_Ip.l_Ctrl_Ip.Mode;
        }
    }
    else
    {
        slew_rate = 1u;//(max_val - min_val)/update_count;
        prevmode = l_Sl_Ctrl_Ip.l_Ctrl_Ip.Mode;
    }

  l_SlCtrl_Op.slewrate = slew_rate;
  l_SlCtrl_Op.prev_mode = prevmode;
  return l_SlCtrl_Op;

}

/*===================================================================================
** Function Name:      Get_Min_Max_Data
** Description:        This Function is to determine the min and max value of table
** Input Parameters:   uint16 pwm_table[TOT_STEP]
** Outputs:            pwm_sort
**==================================================================================*/
void Get_Min_Max_Data(uint16 arr[], uint8 n, uint16 *max, uint16 *min)
{
    *max = arr[0];
    *min = arr[0];

    for (uint8 i = 1u; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }

}

/* Stub functions -  can be removed once RTE is available*/
void X(uint8 *data){}
void Y(uint8 data){}
/*============================================================================
**
** Date              : 15-05-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-17658
** Change Description: Ctrl-Illumination-Extn - Inital version
**
**============================================================================*/
/*============================================================================
**
** Date              : 27-06-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-23936
** Change Description: Ctrl-Illumination-Extn - Version 2
**
**============================================================================*/
/*============================================================================
**
** Date              : 30-07-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-26360
** Change Description: MSIL req - Warning & Diag req added
**
**============================================================================*/

