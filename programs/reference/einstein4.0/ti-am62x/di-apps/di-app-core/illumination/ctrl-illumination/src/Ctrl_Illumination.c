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
#include "Rte_Ctrl_Illumination.h"
#include "CmpLib.h"
#include "Ctrl_Illumination_Cfg.h"
#include "Ctrl_Illum_Cfg.h"
#include "Ctrl_Illumination.h"
//#include "Ctrl_Illumination_TypeCfg.h"
#include "TmExt_Timer.h"

uint8 Prev_Duty_Mode[NO_OF_DUTY];
uint8 Prev_Bulb_Mode[NO_OF_BULB];
uint8 Prev_LED_Mode[NO_OF_LED];
uint8 Prev_Dial_Mode[NO_OF_DIAL];
uint8 Prev_Display_Mode[NO_OF_DISPLAYS];
uint8 Prev_BGT_Mode[NO_OF_BGT];
uint8 Prev_TT_Mode[NO_OF_TELLTALES];
uint8 Prev_RGB_Mode[NO_OF_RGB];

uint8 Prev_Duty_Step[NO_OF_DUTY];
uint8 Prev_Bulb_Step[NO_OF_BULB];
uint8 Prev_LED_Step[NO_OF_LED];
uint8 Prev_Dial_Step[NO_OF_DIAL];
uint8 Prev_Display_Step[NO_OF_DISPLAYS];
uint8 Prev_BGT_Step[NO_OF_BGT];
uint8 Prev_TT_Step[NO_OF_TELLTALES];
uint8 Prev_RGB_Step[NO_OF_RGB];

uint16 Current_Duty_PWM[NO_OF_DUTY];
uint16 Current_Brightness_PWM[NO_OF_BGT];
uint16 Current_RGB_PWM[NO_OF_RGB];
uint16 Current_Bulb_PWM[NO_OF_BULB];
uint16 Current_LED_PWM[NO_OF_LED];
uint16 Current_Dial_PWM[NO_OF_DIAL];
uint16 Current_Display_PWM[NO_OF_DISPLAYS];
uint16 Current_TT_PWM[NO_OF_TELLTALES];

uint16* Curr_PWM[COMP_MAX] = {
    Current_Duty_PWM,
    Current_Bulb_PWM,
    Current_LED_PWM,
    Current_Dial_PWM,
    Current_Display_PWM,
    Current_Brightness_PWM,
    Current_RGB_PWM,
    Current_TT_PWM
};

uint16 Duty_Table[NO_OF_DUTY][TOT_ILLUM_MODE][TOT_STEP] = DUTY_TABLE_INIT;
uint16 Bulb_Table[NO_OF_BULB][TOT_ILLUM_MODE][TOT_STEP] = BULB_TABLE_INIT;
uint16 LED_Table[NO_OF_LED][TOT_ILLUM_MODE][TOT_STEP] = LED_TABLE_INIT;
uint16 Display_Table[NO_OF_DISPLAYS][TOT_ILLUM_MODE][TOT_STEP] = DISPLAY_TABLE_INIT;
uint16 Dial_Table[NO_OF_DIAL][TOT_ILLUM_MODE][TOT_STEP] = DIAL_TABLE_INIT;
uint16 BGT_Table[NO_OF_BGT][TOT_ILLUM_MODE][TOT_STEP] = BGT_TABLE_INIT;
uint16 RGB_Table[NO_OF_RGB][TOT_ILLUM_MODE][TOT_STEP] = RGB_TABLE_INIT;
uint16 TT_Table[NO_OF_TELLTALES][TOT_ILLUM_MODE][TOT_STEP] = TT_TABLE_INIT;

uint16 (*Output_Table[COMP_MAX])[TOT_ILLUM_MODE][TOT_STEP] = {
    Duty_Table,
    Bulb_Table,
    LED_Table,
    Dial_Table,
    Display_Table,
    BGT_Table,
    RGB_Table,
    TT_Table
};

PWM_Array Prev_Mode[COMP_MAX] = {
    {Prev_Duty_Mode, NO_OF_DUTY},
    {Prev_Bulb_Mode, NO_OF_BULB},
    {Prev_LED_Mode, NO_OF_LED},
    {Prev_Dial_Mode, NO_OF_DIAL},
    {Prev_Display_Mode, NO_OF_DISPLAYS},
    {Prev_BGT_Mode, NO_OF_BGT},
    {Prev_RGB_Mode, NO_OF_RGB},
    {Prev_TT_Mode, NO_OF_TELLTALES}
};

Ctrl_Ip fl_Ctrl_Ip;
Ctrl_Op fl_Ctrl_Op;
Switch_Ctrl_Ip  fl_SwitchCtrl_Ip;
Input_Data fl_Input_Data;

/*============================================================================
** Function Name:      Switching_Control_logic
** Description:        function to determine the control action
** Input Parameters:   l_SwitchCtrl_Ip, *Ill_Pwm_Data    
** Outputs:            void       
**==========================================================================*/
void (*Switching_Control_logic[SWITCHING_ALGO_MAX])(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data) = {
    &Slicing_control,
    &Timing_control,
    &Default_control,   
    &Off_mode
};

//@brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE(Ctrl_Illumination)

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional initialization state
///
/// @return E_OK:           Succeed
///< br>     E_NOT_READY:    In progress. Keeps the component in this state.
///< br>     E_NOT_OK:       Failed
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
///< br>     E_NOT_READY:    In progress. Keeps the component in this state.
///< br>     E_NOT_OK:       Failed
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
///< br>     E_NOT_READY:    In progress
///< br>     E_NOT_OK:       Failed
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
    Process_Ctrl_Illumination();
    Output_Processing();

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Diagnostic state
///
/// @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
///< br>     E_NOT_READY:    Keeps the component in this state.
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
///< br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn(void)
{
    Std_ReturnType result = E_OK;
    return result;
}
/*============================================================================
** Function Name:      Input_Processing
** Description:        This Function is used to recieve the Input from Model
** Input Parameters:   void   
** Outputs:            void
** JIRA:               DICMBD-1331
**==========================================================================*/
static void Input_Processing(void)
{
    //RTE_READ_ILL_MDL_DATA(&fl_IllumCtrl_Ip);
    CTRL_ILLUMINATION_INPUT_ADAPTER(&fl_Input_Data);
}

/*============================================================================
** Function Name:      Input_Processing
** Description:        This Function is used to Send the Output to View
** Input Parameters:   void   
** Outputs:            void
** JIRA:               DICMBD-1332
**==========================================================================*/
static void Output_Processing(void)
{
    //RTE_WRITE_IL_CTRL_DATA(fl_IllumCtrl_Op);
    CTRL_ILLUMINATION_OUTPUT_ADAPTER(fl_Ctrl_Op);
}

/*============================================================================
** Function Name:      Process_Ctrl_Illumination
** Description:        Used to Get the updated table and data handle
** Input Parameters:   void   
** Outputs:            void
** JIRA:               DICMBD-1334
**==========================================================================*/
static void Process_Ctrl_Illumination(void)
{
    UPDATE_ILLUMINATION_TABLE(Output_Table);
    Illumination_Data_handle();

}

/*============================================================================
** Function Name:      Illumination_Data_handle
** Description:        Contains main logic function calls
** Input Parameters:   void   
** Outputs:            void
** JIRA:               DICMBD-1334
**==========================================================================*/
static void Illumination_Data_handle(void)
{
    for(uint8 index = 0; index < BYTE_LENGTH; index++)
    {
        if(APPL_ILLUMINATION_DATA & (1u << index))
        {
            switch(index)
            {
                case 7u:
                    DutyMode_Control();
                    break;
                
                case 6u:
                    BrightnessMode_Control();
                    break;
                
                case 5u:
                    RGBMode_Control();
                    break;
                
                case 4u:
                    BulbMode_Control();
                    break;
                
                case 3u:
                    LEDMode_Control();
                    break;
                
                case 2u:                
                    DialMode_Control();
                    break;
                
                case 1u:
                    DisplayMode_Control();
                    break;
                
                case 0u:
                    TelltaleMode_Control();
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
** Function Name:      Timing_control
** Description:        Controls Mode and Step timer actions
** Input Parameters:   l_SwitchCtrl_Ip, *Ill_Pwm_Data    
** Outputs:            void
** JIRA:               DICMBD-1335
**==========================================================================*/
void Timing_control(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data)
{
    uint8 Mode;
    uint8 Step;

    PWM_Array Prev_Step[COMP_MAX] = {
        {Prev_Duty_Step, NO_OF_DUTY},
        {Prev_Bulb_Step, NO_OF_BULB},
        {Prev_LED_Step, NO_OF_LED},
        {Prev_Dial_Step, NO_OF_DIAL},
        {Prev_Display_Step, NO_OF_DISPLAYS},
        {Prev_BGT_Step, NO_OF_BGT},
        {Prev_RGB_Step, NO_OF_RGB},
        {Prev_TT_Step, NO_OF_TELLTALES}
    };

    Mode = Mode_Timer_Control(l_SwitchCtrl_Ip.l_ModeCtrl_Ip);
    Step = Step_Timer_Control(l_SwitchCtrl_Ip.l_StepCtrl_Ip);
    
    if (l_SwitchCtrl_Ip.l_Index_Ip.table_index < COMP_MAX)
    {
        *Ill_Pwm_Data = Output_Table[l_SwitchCtrl_Ip.l_Index_Ip.table_index][l_SwitchCtrl_Ip.l_Index_Ip.Illum_index][Mode][Step];
        if(l_SwitchCtrl_Ip.l_Index_Ip.Illum_index < Prev_Mode[l_SwitchCtrl_Ip.l_Index_Ip.table_index].size)
        {
            Prev_Mode[l_SwitchCtrl_Ip.l_Index_Ip.table_index].array[l_SwitchCtrl_Ip.l_Index_Ip.Illum_index] = Mode;
            Prev_Step[l_SwitchCtrl_Ip.l_Index_Ip.table_index].array[l_SwitchCtrl_Ip.l_Index_Ip.Illum_index] = Step;
        }

        Curr_PWM[l_SwitchCtrl_Ip.l_Index_Ip.table_index][l_SwitchCtrl_Ip.l_Index_Ip.Illum_index] = *Ill_Pwm_Data;  
    }
    
}

/*============================================================================
** Function Name:      Mode_Timer_Control
** Description:        Controls Mode based on Timing control
** Input Parameters:   l_ModeCtrl_Ip 
** Outputs:            Previous_Mode
** JIRA:               DICMBD-1335
**==========================================================================*/
uint8 Mode_Timer_Control(Tmr_Ctrl_Ip l_ModeCtrl_Ip)
{
    uint8 Timer_ID = l_ModeCtrl_Ip.TimerID;
    uint16 Timer_Val = l_ModeCtrl_Ip.TimerVal;
    uint8 Previous_Mode = l_ModeCtrl_Ip.Prev_val;
    uint8 Current_Mode = l_ModeCtrl_Ip.Curr_val;
    
    if(Previous_Mode != Current_Mode)
    {
        if((boolean)TRUE == handle_timer(Timer_ID,Timer_Val))
        {
          Previous_Mode = Current_Mode;

        }
    }
    return Previous_Mode;

}

/*============================================================================
** Function Name:      Step_Timer_Control
** Description:        Controls Step based on Timing control
** Input Parameters:   l_StepCtrl_Ip   
** Outputs:            Previous_Step
** JIRA:               DICMBD-1335
**==========================================================================*/
uint8 Step_Timer_Control(Tmr_Ctrl_Ip l_StepCtrl_Ip)
{
    uint8 Timer_ID = l_StepCtrl_Ip.TimerID;
    uint16 Timer_Val = l_StepCtrl_Ip.TimerVal;
    uint8 Previous_Step = l_StepCtrl_Ip.Prev_val;
    uint8 Current_Step = l_StepCtrl_Ip.Curr_val;
    
    if(Previous_Step != Current_Step)
    {
        if((boolean)TRUE ==  handle_timer(Timer_ID,Timer_Val))
        {
          Previous_Step = Current_Step;

        }
    }
    return Previous_Step;

}

/*============================================================================
** Function Name:      DutyMode_Control
** Description:        Updates the control data for Duty
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void DutyMode_Control(void)
{
    Switch_Ctrl_Ip l_SwitchCtrl_Ip;
    uint16 Il_Duty_Mode_Timer[NO_OF_DUTY][TOT_ILLUM_MODE]= Duty_Mode_Time;
    uint16 Il_Duty_Step_Timer[NO_OF_DUTY][TOT_STEP]= Duty_Step_Time;
    uint8 Il_Duty_Mode_Timer_ID[NO_OF_DUTY][TOT_ILLUM_MODE] = Duty_Mode_Timer_ID;
    uint8 Il_Duty_Step_Timer_ID[NO_OF_DUTY][TOT_STEP] = Duty_Step_Timer_ID;

    for(uint8 index=0; index<NO_OF_DUTY; index++)
    {
        l_SwitchCtrl_Ip.l_Ctrl_Ip = fl_Input_Data.Duty_Control[index];
        l_SwitchCtrl_Ip.l_Index_Ip.table_index = 0u;
        l_SwitchCtrl_Ip.l_Index_Ip.Illum_index = index;
        /*Inputs for Timer control of Mode and Step */
        /*Mode*/
        //l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Timersts = Duty_Mode_TmrStatus[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerVal = Il_Duty_Mode_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerID = Il_Duty_Mode_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Prev_val = Prev_Duty_Mode[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Curr_val = fl_Input_Data.Duty_Control[index].Mode;
        /*Step*/
        //l_SwitchCtrl_Ip.l_StepCtrl_Ip.Timersts = Duty_Step_TmrStatus[index];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerVal = Il_Duty_Step_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];        
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerID = Il_Duty_Step_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Prev_val = Prev_Duty_Step[index];   
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Curr_val = fl_Input_Data.Duty_Control[index].Level;

        /*======Inputs for Slicing Control======= */
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Mode = Prev_Duty_Mode[index];
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Pwm = Current_Duty_PWM[index];

        if(fl_Input_Data.Duty_Control[index].Status == VALID)
        {
           Switching_Control_logic[fl_Input_Data.Duty_Control[index].switching_control](l_SwitchCtrl_Ip,&fl_Ctrl_Op.Duty_Out[index]);
        }
        else
        {
            Switching_Control_logic[ILL_OFF_MODE](l_SwitchCtrl_Ip,&fl_Ctrl_Op.Duty_Out[index]);
        }
    }

}

/*============================================================================
** Function Name:      BulbMode_Control
** Description:        Updates the control data for Bulb
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void BulbMode_Control(void)
{
    Switch_Ctrl_Ip l_SwitchCtrl_Ip;
    uint16 Il_Bulb_Mode_Timer[NO_OF_BULB][TOT_ILLUM_MODE]= Bulb_Mode_Time;
    uint16 Il_Bulb_Step_Timer[NO_OF_BULB][TOT_STEP]= Bulb_Step_Time;
    uint8 Il_Bulb_Mode_Timer_ID[NO_OF_BULB][TOT_ILLUM_MODE] = Bulb_Mode_Timer_ID;
    uint8 Il_Bulb_Step_Timer_ID[NO_OF_BULB][TOT_STEP] = Bulb_Step_Timer_ID;

    for(uint8 index=0; index<NO_OF_BULB; index++)
    {
        l_SwitchCtrl_Ip.l_Ctrl_Ip = fl_Input_Data.Bulb_Control[index];
        l_SwitchCtrl_Ip.l_Index_Ip.table_index = 1u;
        l_SwitchCtrl_Ip.l_Index_Ip.Illum_index = index;

        /*Inputs for Timer control of Mode and Step */
        /*Mode*/
        //l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Timersts = Bulb_Mode_TmrStatus[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerVal = Il_Bulb_Mode_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerID = Il_Bulb_Mode_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Prev_val = Prev_Bulb_Mode[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Curr_val = fl_Input_Data.Bulb_Control[index].Mode;
        /*Step*/
        //l_SwitchCtrl_Ip.l_StepCtrl_Ip.Timersts = Bulb_Step_TmrStatus[index];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerVal = Il_Bulb_Step_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];        
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerID = Il_Bulb_Step_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Prev_val = Prev_Bulb_Step[index];   
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Curr_val = fl_Input_Data.Bulb_Control[index].Level;

        /*======Inputs for Slicing Control======= */
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Mode = Prev_Bulb_Mode[index];
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Pwm = Current_Bulb_PWM[index];

        if(fl_Input_Data.Bulb_Control[index].Status == VALID)
        {
           Switching_Control_logic[fl_Input_Data.Bulb_Control[index].switching_control](l_SwitchCtrl_Ip,&fl_Ctrl_Op.Bulb_Out[index]);
        }
        else
        {
            Switching_Control_logic[ILL_OFF_MODE](l_SwitchCtrl_Ip,&fl_Ctrl_Op.Bulb_Out[index]);
        }
    }
}

/*============================================================================
** Function Name:      LEDMode_Control
** Description:        Updates the control data for LED
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void LEDMode_Control(void)
{
    Switch_Ctrl_Ip l_SwitchCtrl_Ip;
    uint16 Il_LED_Mode_Timer[NO_OF_LED][TOT_ILLUM_MODE]= LED_Mode_Time;
    uint16 Il_LED_Step_Timer[NO_OF_LED][TOT_STEP]= LED_Step_Time;
    uint8 Il_LED_Mode_Timer_ID[NO_OF_LED][TOT_ILLUM_MODE] = LED_Mode_Timer_ID;
    uint8 Il_LED_Step_Timer_ID[NO_OF_LED][TOT_STEP] = LED_Step_Timer_ID;

    for(uint8 index=0; index<NO_OF_LED; index++)
    {
        l_SwitchCtrl_Ip.l_Ctrl_Ip = fl_Input_Data.LED_Control[index];
        l_SwitchCtrl_Ip.l_Index_Ip.table_index = 2u;
        l_SwitchCtrl_Ip.l_Index_Ip.Illum_index = index;

        /*Inputs for Timer control of Mode and Step */
        /*Mode*/
        //l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Timersts = LED_Mode_TmrStatus[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerVal = Il_LED_Mode_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerID = Il_LED_Mode_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Prev_val = Prev_LED_Mode[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Curr_val = fl_Input_Data.LED_Control[index].Mode;
        /*Step*/
        //l_SwitchCtrl_Ip.l_StepCtrl_Ip.Timersts = LED_Step_TmrStatus[index];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerVal = Il_LED_Step_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];        
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerID = Il_LED_Step_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Prev_val = Prev_LED_Step[index];   
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Curr_val = fl_Input_Data.LED_Control[index].Level;

        /*======Inputs for Slicing Control======= */
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Mode = Prev_LED_Mode[index];
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Pwm = Current_LED_PWM[index];

        if(fl_Input_Data.LED_Control[index].Status == VALID)
        {
           Switching_Control_logic[fl_Input_Data.LED_Control[index].switching_control](l_SwitchCtrl_Ip,&fl_Ctrl_Op.LED_Out[index]);
        }
        else
        {
            Switching_Control_logic[ILL_OFF_MODE](l_SwitchCtrl_Ip,&fl_Ctrl_Op.LED_Out[index]);
        }
    }
}

/*============================================================================
** Function Name:      DialMode_Control
** Description:        Updates the control data for Dial
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void DialMode_Control(void)
{
    Switch_Ctrl_Ip l_SwitchCtrl_Ip;
    uint16 Il_Dial_Mode_Timer[NO_OF_DIAL][TOT_ILLUM_MODE]= Dial_Mode_Time;
    uint16 Il_Dial_Step_Timer[NO_OF_DIAL][TOT_STEP]= Dial_Step_Time;
    uint8 Il_Dial_Mode_Timer_ID[NO_OF_DIAL][TOT_ILLUM_MODE] = Dial_Mode_Timer_ID;
    uint8 Il_Dial_Step_Timer_ID[NO_OF_DIAL][TOT_STEP] = Dial_Step_Timer_ID;

    for(uint8 index=0; index<NO_OF_DIAL; index++)
    {
        l_SwitchCtrl_Ip.l_Ctrl_Ip = fl_Input_Data.Dial_Control[index];
        l_SwitchCtrl_Ip.l_Index_Ip.table_index = 3u;
        l_SwitchCtrl_Ip.l_Index_Ip.Illum_index = index;

        /*Inputs for Timer control of Mode and Step */
        /*Mode*/
        //l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Timersts = Dial_Mode_TmrStatus[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerVal = Il_Dial_Mode_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerID = Il_Dial_Mode_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Prev_val = Prev_Dial_Mode[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Curr_val = fl_Input_Data.Dial_Control[index].Mode;
        /*Step*/
        //l_SwitchCtrl_Ip.l_StepCtrl_Ip.Timersts = Dial_Step_TmrStatus[index];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerVal = Il_Dial_Step_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];        
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerID = Il_Dial_Step_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Prev_val = Prev_Dial_Step[index];   
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Curr_val =fl_Input_Data.Dial_Control[index].Level;

        /*======Inputs for Slicing Control======= */
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Mode = Prev_Dial_Mode[index];
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Pwm = Current_Dial_PWM[index];

        if(fl_Input_Data.Dial_Control[index].Status == VALID)
        {
           Switching_Control_logic[fl_Input_Data.Dial_Control[index].switching_control](l_SwitchCtrl_Ip,&fl_Ctrl_Op.Dial_Out[index]);
        }
        else
        {
            Switching_Control_logic[ILL_OFF_MODE](l_SwitchCtrl_Ip,&fl_Ctrl_Op.Dial_Out[index]);
        }
    }
}

/*============================================================================
** Function Name:      DisplayMode_Control
** Description:        Updates the control data for Display
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void DisplayMode_Control(void)
{
    Switch_Ctrl_Ip l_SwitchCtrl_Ip;

    uint16 Il_Display_Mode_Timer[NO_OF_DISPLAYS][TOT_ILLUM_MODE]= Display_Mode_Time;
    uint16 Il_Display_Step_Timer[NO_OF_DISPLAYS][TOT_STEP]= Display_Step_Time;
    uint8 Il_Display_Mode_Timer_ID[NO_OF_DISPLAYS][TOT_ILLUM_MODE] = Display_Mode_Timer_ID;
    uint8 Il_Display_Step_Timer_ID[NO_OF_DISPLAYS][TOT_STEP] = Display_Step_Timer_ID;

    for(uint8 index=0; index<NO_OF_DISPLAYS; index++)
    {
        l_SwitchCtrl_Ip.l_Ctrl_Ip = fl_Input_Data.Display_Control[index];
        l_SwitchCtrl_Ip.l_Index_Ip.table_index = 4u;
        l_SwitchCtrl_Ip.l_Index_Ip.Illum_index = index;

        /*Inputs for Timer control of Mode and Step */
        /*Mode*/
        //l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Timersts = Display_Mode_TmrStatus[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerVal = Il_Display_Mode_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerID = Il_Display_Mode_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Prev_val = Prev_Display_Mode[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Curr_val = fl_Input_Data.Display_Control[index].Mode;
        /*Step*/
        //l_SwitchCtrl_Ip.l_StepCtrl_Ip.Timersts = Display_Step_TmrStatus[index];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerVal = Il_Display_Step_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];        
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerID = Il_Display_Step_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Prev_val = Prev_Display_Step[index];   
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Curr_val = fl_Input_Data.Display_Control[index].Level;

        /*======Inputs for Slicing Control======= */
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Mode = Prev_Display_Mode[index];
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Pwm = Current_Display_PWM[index];

        //l_DispSwitchCtrl_Ip = l_SwitchCtrl_Ip;  //Need to remove

        if(fl_Input_Data.Display_Control[index].Status == VALID)
        {
           Switching_Control_logic[fl_Input_Data.Display_Control[index].switching_control](l_SwitchCtrl_Ip,&fl_Ctrl_Op.Display_Out[index]);
        }
        else
        {
            Switching_Control_logic[ILL_OFF_MODE](l_SwitchCtrl_Ip,&fl_Ctrl_Op.Display_Out[index]);
        }
    }
}

/*============================================================================
** Function Name:      BrightnessMode_Control
** Description:        Updates the control data for Brightness
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void BrightnessMode_Control(void)
{
    Switch_Ctrl_Ip l_SwitchCtrl_Ip;
    uint16 Il_BGT_Mode_Timer[NO_OF_BGT][TOT_ILLUM_MODE]= BGT_Mode_Time;
    uint16 Il_BGT_Step_Timer[NO_OF_BGT][TOT_STEP]= BGT_Step_Time;
    uint8 Il_BGT_Mode_Timer_ID[NO_OF_BGT][TOT_ILLUM_MODE] = BGT_Mode_Timer_ID;
    uint8 Il_BGT_Step_Timer_ID[NO_OF_BGT][TOT_STEP] = BGT_Step_Timer_ID;

    for(uint8 index=0; index<NO_OF_BGT; index++)
    {
        l_SwitchCtrl_Ip.l_Ctrl_Ip = fl_Input_Data.Brightness_Control[index];
        l_SwitchCtrl_Ip.l_Index_Ip.table_index = 5u;
        l_SwitchCtrl_Ip.l_Index_Ip.Illum_index = index;

        /*Inputs for Timer control of Mode and Step */
        /*Mode*/

        //l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Timersts = BGT_Mode_TmrStatus[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerVal = Il_BGT_Mode_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerID = Il_BGT_Mode_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Prev_val = Prev_BGT_Mode[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Curr_val = fl_Input_Data.Brightness_Control[index].Mode;
        /*Step*/
        //l_SwitchCtrl_Ip.l_StepCtrl_Ip.Timersts = BGT_Step_TmrStatus[index];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerVal = Il_BGT_Step_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];        
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerID = Il_BGT_Step_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Prev_val = Prev_BGT_Step[index];   
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Curr_val = fl_Input_Data.Brightness_Control[index].Level;

        /*======Inputs for Slicing Control======= */
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Mode = Prev_BGT_Mode[index];
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Pwm = Current_Brightness_PWM[index];

        if(fl_Input_Data.Brightness_Control[index].Status == VALID)
        {
           Switching_Control_logic[fl_Input_Data.Brightness_Control[index].switching_control](l_SwitchCtrl_Ip,&fl_Ctrl_Op.Brightness_Out[index]);
        }
        else
        {
            Switching_Control_logic[ILL_OFF_MODE](l_SwitchCtrl_Ip,&fl_Ctrl_Op.Brightness_Out[index]);
        }
    }
}

/*============================================================================
** Function Name:      TelltaleMode_Control
** Description:        Updates the control data for Telltale
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void TelltaleMode_Control(void)
{
    Switch_Ctrl_Ip l_SwitchCtrl_Ip;
    uint16 Il_TT_Mode_Timer[NO_OF_TELLTALES][TOT_ILLUM_MODE]= TT_Mode_Time;
    uint16 Il_TT_Step_Timer[NO_OF_TELLTALES][TOT_STEP]= TT_Step_Time;
    uint8 Il_TT_Mode_Timer_ID[NO_OF_TELLTALES][TOT_ILLUM_MODE] = TT_Mode_Timer_ID;
    uint8 Il_TT_Step_Timer_ID[NO_OF_TELLTALES][TOT_STEP] = TT_Step_Timer_ID;

    for(uint8 index=0; index<NO_OF_TELLTALES; index++)
    {
        l_SwitchCtrl_Ip.l_Ctrl_Ip = fl_Input_Data.Telltale_Control[index];
        l_SwitchCtrl_Ip.l_Index_Ip.table_index = 7u;
        l_SwitchCtrl_Ip.l_Index_Ip.Illum_index = index;

        /*Inputs for Timer control of Mode and Step */
        /*Mode*/
        //l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Timersts = TT_Mode_TmrStatus[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerVal = Il_TT_Mode_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerID = Il_TT_Mode_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Prev_val = Prev_TT_Mode[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Curr_val = fl_Input_Data.Telltale_Control[index].Mode;
        /*Step*/
        //l_SwitchCtrl_Ip.l_StepCtrl_Ip.Timersts = TT_Step_TmrStatus[index];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerVal = Il_TT_Step_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];        
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerID = Il_TT_Step_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Prev_val = Prev_TT_Step[index];   
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Curr_val = fl_Input_Data.Telltale_Control[index].Level;

        /*======Inputs for Slicing Control======= */
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Mode = Prev_TT_Mode[index];
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Pwm = Current_TT_PWM[index];

        if(fl_Input_Data.Telltale_Control[index].Status == VALID)
        {
           Switching_Control_logic[fl_Input_Data.Telltale_Control[index].switching_control](l_SwitchCtrl_Ip,&fl_Ctrl_Op.Telltale_Out[index]);
        }
        else
        {
            Switching_Control_logic[ILL_OFF_MODE](l_SwitchCtrl_Ip,&fl_Ctrl_Op.Telltale_Out[index]);
        }
    }
}

/*============================================================================
** Function Name:      RGBMode_Control
** Description:        Updates the control data for RGB
** Input Parameters:   void
** Outputs:            void
**==========================================================================*/
void RGBMode_Control(void)
{
    Switch_Ctrl_Ip l_SwitchCtrl_Ip;
    uint16 Il_RGB_Mode_Timer[NO_OF_RGB][TOT_ILLUM_MODE]= RGB_Mode_Time;
    uint16 Il_RGB_Step_Timer[NO_OF_RGB][TOT_STEP]= RGB_Step_Time;
    uint8 Il_RGB_Mode_Timer_ID[NO_OF_RGB][TOT_ILLUM_MODE] = RGB_Mode_Timer_ID;
    uint8 Il_RGB_Step_Timer_ID[NO_OF_RGB][TOT_STEP] = RGB_Step_Timer_ID;

    for(uint8 index=0; index<NO_OF_RGB; index++)
    {
        l_SwitchCtrl_Ip.l_Ctrl_Ip = fl_Input_Data.RGB_Control[index];
        l_SwitchCtrl_Ip.l_Index_Ip.table_index = 6u;
        l_SwitchCtrl_Ip.l_Index_Ip.Illum_index = index;

        /*Inputs for Timer control of Mode and Step */
        /*Mode*/
        //l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Timersts = RGB_Mode_TmrStatus[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerVal = Il_RGB_Mode_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerID = Il_RGB_Mode_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Prev_val = Prev_RGB_Mode[index];
        l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Curr_val = fl_Input_Data.RGB_Control[index].Mode;
        /*Step*/
        //l_SwitchCtrl_Ip.l_StepCtrl_Ip.Timersts = RGB_Step_TmrStatus[index];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerVal = Il_RGB_Step_Timer[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];        
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerID = Il_RGB_Step_Timer_ID[index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];    
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Prev_val = Prev_RGB_Step[index];   
        l_SwitchCtrl_Ip.l_StepCtrl_Ip.Curr_val = fl_Input_Data.RGB_Control[index].Level;

        /*======Inputs for Slicing Control======= */
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Mode = Prev_RGB_Mode[index];
        l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Pwm = Current_RGB_PWM[index];

        if(fl_Input_Data.RGB_Control[index].Status == VALID)
        {
           Switching_Control_logic[fl_Input_Data.RGB_Control[index].switching_control](l_SwitchCtrl_Ip,&fl_Ctrl_Op.RGB_Out[index]);
        }
        else
        {
            Switching_Control_logic[ILL_OFF_MODE](l_SwitchCtrl_Ip,&fl_Ctrl_Op.RGB_Out[index]);
        }
    }
}

/*============================================================================
** Function Name:      handle_timer
** Description:        Tis function is used to control timer logic
** Input Parameters:   uint8 timerId, uint32 loadtime  
** Outputs:            boolean
** JIRA:               DICMBD-1335 
**==========================================================================*/
static boolean handle_timer(uint8 timerId, uint32 loadtime)
{
    boolean isTimerStarted_b = FALSE;
    boolean isTimerCompleted_b = FALSE;
    boolean shouldreturn       = FALSE;

    /*Checking that is the timer Started*/
    TmExt_Timer_IsStarted(timerId, &isTimerStarted_b);

    if((boolean)FALSE == isTimerStarted_b) 
    {
        /*Starting the timer*/
        TmExt_Timer_Start(timerId);
        shouldreturn = (boolean)FALSE;

    }

    /*Checking that is the timer elapsed*/
    TmExt_Timer_IsElapsed(timerId, loadtime, &isTimerCompleted_b);

    if((boolean)TRUE == isTimerCompleted_b)
    {
        /*Stop the timer*/
        TmExt_Timer_Stop(timerId);
        shouldreturn = (boolean)TRUE;
       
    }

    return shouldreturn;
}

/*============================================================================
** Function Name:      Slicing_control
** Description:        Controls the PWM based on Slewrate
** Input Parameters:   l_SwitchCtrl_Ip, *Ill_Pwm_Data   
** Outputs:            void
** JIRA:               DICMBD-1336
**==========================================================================*/
void Slicing_control(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data)
{
    Sl_Ctrl_Ip l_SlCtrl_Ip;
    Sl_Ctrl_Op l_SlCtrl_Op;
    uint16 current_pwm;
    uint16 target_pwm;
    uint16 slewrate;
    uint8 prev_mode = 0u;

    l_SlCtrl_Ip.table_index = l_SwitchCtrl_Ip.l_Index_Ip.table_index;
    l_SlCtrl_Ip.Illum_index = l_SwitchCtrl_Ip.l_Index_Ip.Illum_index;
    l_SlCtrl_Ip.Curr_Mode = l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Mode;
    l_SlCtrl_Ip.l_Ctrl_Ip = l_SwitchCtrl_Ip.l_Ctrl_Ip;
    
    current_pwm = l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Pwm;
    l_SlCtrl_Ip.Curr_pwm = current_pwm;
    target_pwm = Output_Table[l_SwitchCtrl_Ip.l_Index_Ip.table_index][l_SwitchCtrl_Ip.l_Index_Ip.Illum_index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode][l_SwitchCtrl_Ip.l_Ctrl_Ip.Level];
    l_SlCtrl_Ip.tgt_pwm = target_pwm;

    for(uint8 step_index=0;step_index<TOT_STEP;step_index++)
    {
        l_SlCtrl_Ip.table_data[step_index] = Output_Table[l_SwitchCtrl_Ip.l_Index_Ip.table_index][l_SwitchCtrl_Ip.l_Index_Ip.Illum_index][l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode][step_index];
    }

 
    if(current_pwm != target_pwm)
    {
        if(l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode != SLEW_DISABLE_MODE)
        {
            l_SlCtrl_Op = SLEW_RATE_DETERMINATION(l_SlCtrl_Ip);
            slewrate = l_SlCtrl_Op.slewrate;

            current_pwm = handle_slew(current_pwm,target_pwm,slewrate);
            prev_mode = l_SlCtrl_Op.prev_mode;

        }
        else
        {
            current_pwm = target_pwm;
            prev_mode = l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode;
        }
    }
    else
    {
        prev_mode = l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode; //added newly
    }
   
    Prev_Mode[l_SwitchCtrl_Ip.l_Index_Ip.table_index].array[l_SwitchCtrl_Ip.l_Index_Ip.Illum_index] = prev_mode;
    *Ill_Pwm_Data = current_pwm;
    Curr_PWM[l_SwitchCtrl_Ip.l_Index_Ip.table_index][l_SwitchCtrl_Ip.l_Index_Ip.Illum_index] = current_pwm;

}

/*============================================================================
** Function Name:      handle_slew
** Description:        This function is used for fade-in / fade-out control
** Input Parameters:   current_val, target_val, slewrate
** Outputs:            current_pwm
** JIRA:               DICMBD-1336
**==========================================================================*/
uint16 handle_slew(uint16 current_val, uint16 target_val, uint16 slewrate)
{
    
    uint16 current_pwm = current_val;
    uint16 target_pwm =  target_val;
    uint16 slew_rate =  slewrate;

    if((current_pwm <= PWM_MAX) && (target_pwm <= PWM_MAX) && (slew_rate <= PWM_MAX))
    {
        if(target_pwm > current_pwm)
        {
            if((current_pwm + slew_rate) >= target_pwm)
            {
                current_pwm = target_pwm;
            }
            else
            {
                current_pwm = (uint16)(current_pwm + slew_rate);
            }
        
        }
        else if(target_pwm < current_pwm)
        {
            if(current_pwm > slew_rate)
            {
                if((current_pwm - slew_rate) <= target_pwm)
                {
                    current_pwm = target_pwm;
                }
                else
                {

                    current_pwm = (uint16)(current_pwm - slew_rate);
                    
                }
            }
            else
            {
                current_pwm = target_pwm;
            }
        }
        else
        {
            current_pwm = target_pwm;
        }   
    }
    else
    {
        current_pwm = PWM_MAX;
    }
    

    return current_pwm;
}

/*============================================================================
** Function Name:      Default_control
** Description:        Default control algorithm
** Input Parameters:   l_SwitchCtrl_Ip, *Ill_Pwm_Data   
** Outputs:            void
** JIRA:               DICMBD-1337
**==========================================================================*/
void Default_control(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data)
{
    DEFAULT_CONTROL(l_SwitchCtrl_Ip,Ill_Pwm_Data);
}

/*============================================================================
** Function Name:      Off_mode
** Description:        Illumination off mode
** Input Parameters:   l_SwitchCtrl_Ip, *Ill_Pwm_Data   
** Outputs:            void
**==========================================================================*/
void Off_mode(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data)
{
    ILLUMINATION_OFF(l_SwitchCtrl_Ip,Ill_Pwm_Data);
}

/*============================================================================
**
** Date              : 15-05-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-16461
** Change Description: Ctrl-Illumination - Inital version
**
**============================================================================*/
/*============================================================================
**
** Date              : 26-06-2025
** CDSID             : aelango6
** Traceability      : W61632023-78413
** Change Description: Slewrate control algorithm modified
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

