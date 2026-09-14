/* ---------------------------------------------------------------------------------------------------------------------
 
  VISTEON CORPORATION CONFIDENTIAL
  ________________________________
 
  [2015] Visteon Corporation
  All Rights Reserved.
 
  NOTICE: This is an unpublished work of authorship, which contains trade secrets.
  Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
  its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
  or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
  in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
  under all copyright laws to protect this work as a published work, when appropriate.
  Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
  without the written authorization of Visteon Corporation.
 
---------------------------------------------------------------------------------------------------------------------*/

#include "Std_Types.h"

#include "s6j3200_SMC.h"
#include "s6j3200_PPC.h"
#include "abstract.h"

#include "TftDrv_GMCHUD_Cfg.h"
#include "TftDrv.h"
#include "TFTDrvCommon.h"


#include <Dio.h>
/*=====================================================================================================================
   CONSTANTS & TYPES
====================================================================================================================*/



/*=====================================================================================================================
   FORWARD DECLARATIONS
=====================================================================================================================*/

/*====================================================================================================================
   PRIVATE
=====================================================================================================================*/

//FIXME static const SPortValuePair ActivateTFTPorts[] = cPORTLIST_ACTIVATE;
//FIXME static const SPortValuePair DeactivateTFTPorts[] = cPORTLIST_DEACTIVATE;

/*=====================================================================================================================
   PUBLIC
=====================================================================================================================*/

/*---------------------------------------------------------------------------------------------------------------------
  brief  Transitional initialization state
---------------------------------------------------------------------------------------------------------------------*/
void TftDrv_Init(void)
{

}

/*---------------------------------------------------------------------------------------------------------------------
 brief  Transitional de-initialization state
--------------------------------------------------------------------------------------------------------------------*/
void TftDrv_Deinit(void)
{
      /* Configure Display related port here. For LVDS it is done in DispCdd */  				
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional activation state
///
/// @return boolean:
///<br>     false:    In progress. Keeps the component in this state.
///<br>     true:       finished
//---------------------------------------------------------------------------------------------------------------------
boolean  TftDrv_preActivate(void)
{
    boolean ret = cNotFinished;
    /* Configure Display related port here. For LVDS it is done in DispCdd */  				
    /* Dio_WriteChannel( DioConf_DioChannel_TFT_RESET, (Dio_LevelType)STD_HIGH );
       ConfigurePorts(ActivateTFTPorts, sizeof(ActivateTFTPorts) / sizeof(SPortValuePair));
    */
    ret = cFinished;
    return ret;
}
boolean  TftDrv_postActivate(void)
{
    boolean ret = cNotFinished;
    /* Configure Display related port here. For LVDS it is done in DispCdd */  								
    /* Dio_WriteChannel( DioConf_DioChannel_DSP_ON, (Dio_LevelType)STD_HIGH);*/
    ret = cFinished;

    return ret;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-activation state
///
/// @return boolean:
///<br>     false:    In progress. Keeps the component in this state.
///<br>     true:       finished
//---------------------------------------------------------------------------------------------------------------------
boolean TftDrv_DeActivate_Step1(void)
{
    boolean ret = cNotFinished;
    /* Configure Display related port here. For LVDS it is done in DispCdd */  												
    /* Dio_WriteChannel( DioConf_DioChannel_DSP_ON, (Dio_LevelType)STD_LOW);*/
    ret = cFinished;
    return ret;

}
boolean TftDrv_DeActivate_Step2(void)
{
    boolean ret = cNotFinished;
    /* Configure Display related port here. For LVDS it is done in DispCdd */  												
    /*
    ConfigurePorts(DeactivateTFTPorts, sizeof(DeactivateTFTPorts) / sizeof(SPortValuePair));
    Dio_WriteChannel( DioConf_DioChannel_DSP_ON, (Dio_LevelType)STD_LOW);
    */
    ret = cFinished;
    return ret;
}


