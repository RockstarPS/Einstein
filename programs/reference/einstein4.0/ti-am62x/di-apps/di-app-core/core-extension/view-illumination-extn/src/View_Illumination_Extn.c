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
#include "View_Illum_Cfg.h"
#include "View_Illumination_Extn.h"
#include "Rte_Type.h"

IllumCtrl_Op fl_ViewCtrl_Ip;
/*============================================================================
** Function Name:      IoHwAb_Data_Out
** Description:        This Function is used to send data to IoHwAb
** Input Parameters:   uint8 data, uint8 type  
** Outputs:            void
**==========================================================================*/
void ViewIllumination_InputAdapter(View_Ip *l_View_Ip)
{
    (void)RTE_READ_ILLUMCTRL_OP(&fl_ViewCtrl_Ip);

    l_View_Ip->Duty_Out[0u] = fl_ViewCtrl_Ip.Illumination_Duty_Out;

    l_View_Ip->Bulb_Out[0u] = fl_ViewCtrl_Ip.Bulb_PWM_Out;

    l_View_Ip->LED_Out[0u] = fl_ViewCtrl_Ip.LED_PWM_Out;

    l_View_Ip->Dial_Out[0u] = fl_ViewCtrl_Ip.Dial_Out;

    l_View_Ip->Display_Out[0u] = fl_ViewCtrl_Ip.Display_Out;

    l_View_Ip->Brightness_Out[0u] = fl_ViewCtrl_Ip.Brightness_Out;

    l_View_Ip->RGB_Out[0u] = fl_ViewCtrl_Ip.RGB_Dimming_Out;

    l_View_Ip->Telltale_Out[0u] = fl_ViewCtrl_Ip.Telltale_Out;

} 

/*============================================================================
** Function Name:      IoHwAb_Data_Out
** Description:        This Function is used to send data to IoHwAb
** Input Parameters:   uint8 data, uint8 type  
** Outputs:            void
**==========================================================================*/
// static volatile uint16 BackupResult = 0u;
void IoHwAb_Data_Out(uint16 data, uint8 type)
{
    Std_ReturnType ErrorStatus;
    uint16 Res_Data = 0U;
    Res_Data = (uint16)(data * PWM_RESOLUTION);

    ErrorStatus = Rte_Call_rp_CS_Backlight_service_SetBrightnessValue(e_Display10Inch,Res_Data);

    if (ErrorStatus != E_OK)
    {
        /*Error Handling*/
    }

}

/*============================================================================
** Function Name:      UCL_Data_Out
** Description:        This Function is used to send data to UCL
** Input Parameters:   uint8 data, uint8 type  
** Outputs:            void
**==========================================================================*/
void UCL_Data_Out(uint16 data, uint8 type)
{
    FUTILITY_UNUSED_VAR(data);
    FUTILITY_UNUSED_VAR(type);
}

/*============================================================================
** Function Name:      CAN_Data_Out
** Description:        This Function is used to send data to CAN
** Input Parameters:   uint8 data, uint8 type  
** Outputs:            void
**==========================================================================*/
void CAN_Data_Out(uint16 data, uint8 type)
{
    uint8 signaldata;
    uint8 signalID;

    signalID = type;
    FUTILITY_UNUSED_VAR(signalID);
    if(data <= 255u)
    {
        signaldata = data;
    }
    else
    {
        signaldata = 255u;
    }
    
    signaldata = CONVERT_TO_CAN_PERCENTAGE(signaldata);
    //(void)Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValue(signalID,&signaldata);
}

/*============================================================================
**
** Date              : 16-05-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-17658
** Change Description: View-Illumination-Extn - Inital version
**
**============================================================================*/
/*============================================================================
**
** Date              : 27-06-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-23936
** Change Description: View-Illumination-Extn - Version 2
**
**============================================================================*/
/*============================================================================
**
** Date              : 30-07-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-26360
** Change Description: CAN convert percentage added
**
**============================================================================*/
/*============================================================================
**
** Date              : 01-09-2025
** CDSID             : aelango6
** Traceability      : PE4TI29141-10020
** Change Description: Temp fix - Display flicker issue - due to MCAL issue
**
**============================================================================*/
/*============================================================================
**
** Date              : 03-08-2026
** CDSID             : aelango6
** Traceability      : PE4TI29141-13100
** Change Description: Set pwm interface updated for Backlight-CDD
**
**============================================================================*/

