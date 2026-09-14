/****************************************************************************
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2013. Visteon Corporation owns all rights to this work and
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
*****************************************************************************
**
** Name:           hmi_gfx_mgr02_tidss_dispif.c
**
** Description:    Module for defining interfaces that call tidss driver APIs
**
** Organization:   HMI Core Software Section, Visteon
**
*****************************************************************************/

/************************** Start of Module *********************************/

/*****************************************************************************
                            Module Name
*****************************************************************************/

#define HMI_GFX_MGR02_TIDSS_DISPIF_C

/*****************************************************************************
                            Include files
*****************************************************************************/

#include <stdint.h>
#include "hmi_gfx_mgr02_layout.h"

#if defined(GFX_MGR02_USE_TIDSS)
#include "ti_drivers_open_close.h"
#include "ti_drivers_config.h"
#include "hmi_gfx_mgr02_tidss_dispif.h"
#include "hmi_gfx_mgr02_context.h"

/*****************************************************************************
                            Extern Function Declarations
*****************************************************************************/

extern void framecomplete_cb(void);

/*****************************************************************************
                            Macro Definitions
*****************************************************************************/

/* Indicate maximum number of displays configured to use */
#define GFX_MGR02_MAX_NUM_DISPLAYS                        CONFIG_DSS_NUM_INSTANCES
/* Indicate maximum number of pipelines configured to use */
#define GFX_MGR02_MAX_NUM_PIPELINES                       gDssConfigPipelineParams.numTestPipes

/*****************************************************************************
                            Type Definitions
*****************************************************************************/

/*****************************************************************************
                            Static Variable Declarations
*****************************************************************************/

static bool l_IsDequeueSuccess = false;                       /* Dequeue operation success flag */
static Fvid2_FrameList l_FrameList;                           /* Frame list container */

/*****************************************************************************
                            Static Function Declarations
*****************************************************************************/

static int32_t hmi_gfx_mgr02_tidss_dispif_cb(Fvid2_Handle handle, void *appData);
static int32_t hmi_gfx_mgr02_tidss_dispif_create(uint8_t p_disp_id);
static void hmi_gfx_mgr02_tidss_dispif_init_dss_params(uint8_t p_disp_id);
static void hmi_gfx_mgr02_tidss_dispif_init_pipeline_params(uint8_t p_disp_id);
static int32_t hmi_gfx_mgr02_tidss_dispif_config_dctrl(uint8_t p_disp_id);
static int32_t hmi_gfx_mgr02_tidss_dispif_delete(uint8_t p_disp_id);

/*****************************************************************************
                            Function Definitions
*****************************************************************************/

/****************************************************************************
Function Name        : hmi_gfx_mgr02_tidss_dispif_init
Description          : To initialize dss display drivers
Invocation           : context
******************************************************************************/
int32_t hmi_gfx_mgr02_tidss_dispif_init(uint8_t p_disp_id)
{
    int32_t retVal = FVID2_SOK;
    Fvid2_InitPrms  initPrms;
  
    if(p_disp_id < GFX_MGR02_MAX_NUM_DISPLAYS)
    {
        Dss_Object *fl_DssObjPtr = &gDssObjects[p_disp_id];   /* DSS Object Pointer */
        Fvid2InitPrms_init(&initPrms);

        /* 
        ** Here return value is discarded because it is always "FVID2_SOK"
        ** due to the stubbing of Semaphore interfaces in AutoSAR 
        */

        (void) Fvid2_init(&initPrms);
        Dss_initParamsInit(&fl_DssObjPtr->initParams);
        retVal = Dss_init(&fl_DssObjPtr->initParams);

        if(retVal == FVID2_SOK)
        {
            /* Create Display Controller handle, used for common driver configuration */
            fl_DssObjPtr->dctrlHandle = Fvid2_create(
                DSS_DCTRL_DRV_ID,
                DSS_DCTRL_INST_0,
                NULL,
                NULL,
                NULL);
      
            if(NULL != fl_DssObjPtr->dctrlHandle)
            {
                if(fl_DssObjPtr->oldiParams != NULL)
                {
                    Dss_setOLDITxPowerDown(fl_DssObjPtr->oldiParams->oldiCfg.oldiMapType, true);
                }
                else
                { 
                    retVal = FVID2_EFAIL;
                }
            }
            else
            {
                retVal = FVID2_EFAIL;
            }
        }

        if(retVal == FVID2_SOK)
        {
            retVal = hmi_gfx_mgr02_tidss_dispif_create(p_disp_id);
        }
    }
    else
    {
        retVal = FVID2_EINVALID_PARAMS;
    }
    return retVal;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_tidss_dispif_dequeue
Description          : To get/dequeue completed frame buffer from display
Invocation           : context
******************************************************************************/
int32_t hmi_gfx_mgr02_tidss_dispif_dequeue(uint8_t p_disp_id)
{
  int32_t retVal = FVID2_SOK;
  uint32_t fl_pipelineId;
  Dss_InstObject *instObj;
  
  if(p_disp_id < GFX_MGR02_MAX_NUM_DISPLAYS)
  {
    Dss_Object *fl_DssObjPtr = &gDssObjects[p_disp_id];   /* DSS Object Pointer */
    
    for(fl_pipelineId = 0U; fl_pipelineId < GFX_MGR02_MAX_NUM_PIPELINES; fl_pipelineId++)
    {
      instObj = &fl_DssObjPtr->instObj[fl_pipelineId];

      retVal = Fvid2_dequeue(instObj->drvHandle, &l_FrameList, 0U, FVID2_TIMEOUT_NONE);
      
      if(FVID2_SOK == retVal)
      {
        l_IsDequeueSuccess = true;
      }
      else if (FVID2_EAGAIN == retVal)
      {
        /* No buffer available to dequeue */
        l_IsDequeueSuccess = false;
      }
      else
      {
        /* Dequeue operation Error condition */
        l_IsDequeueSuccess = false;
        break;
      }
    }
  }
  else
  {
    retVal = FVID2_EINVALID_PARAMS;
  }
  return retVal;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_tidss_dispif_update
Description          : To update new frome buffer to display
Invocation           : context
******************************************************************************/
int32_t hmi_gfx_mgr02_tidss_dispif_update(uint8_t p_disp_id)
{
  int32_t retVal = FVID2_SOK;
  uint32_t fl_pipelineId;
  Dss_InstObject *instObj; 
  
  if(p_disp_id < GFX_MGR02_MAX_NUM_DISPLAYS)
  {
    Dss_Object *fl_DssObjPtr = &gDssObjects[p_disp_id];   /* DSS Object Pointer */

    for(fl_pipelineId = 0U; fl_pipelineId < GFX_MGR02_MAX_NUM_PIPELINES; fl_pipelineId++)
    {
        instObj = &fl_DssObjPtr->instObj[fl_pipelineId];
        
        if(true == l_IsDequeueSuccess)
        {            
            retVal = Fvid2_queue(instObj->drvHandle, &l_FrameList, 0U);
            if(FVID2_SOK != retVal)
            {
              /* Queue Error */
              break;
            }
        }
        else
        {
          /* Dequeue was not success, so do not queue any buffer */
          retVal = FVID2_EFAIL;
        }
    }
  }
  else
  {
    retVal = FVID2_EINVALID_PARAMS;
  }
  return retVal;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_tidss_dispif_shutdown
Description          : To shutdown dss display drivers
Invocation           : context
******************************************************************************/
int32_t hmi_gfx_mgr02_tidss_dispif_shutdown(uint8_t p_disp_id)
{
  int32_t retVal = FVID2_SOK;
  
  if(p_disp_id < GFX_MGR02_MAX_NUM_DISPLAYS)
  {
    Dss_Object *fl_DssObjPtr = &gDssObjects[p_disp_id];   /* DSS Object Pointer */
    /* Delete driver */
    retVal = hmi_gfx_mgr02_tidss_dispif_delete(p_disp_id);
    
    if(FVID2_SOK == retVal)
    {
      /* Delete DCTRL handle */
      retVal = Fvid2_delete(fl_DssObjPtr->dctrlHandle, NULL);
      
      if(FVID2_SOK == retVal)
      {
        retVal = Dss_deInit();
        
        if(FVID2_SOK == retVal)
        {
          retVal = Fvid2_deInit(NULL);
        }
      }
    }
  }
  else
  {
    retVal = FVID2_EINVALID_PARAMS;
  }
  return retVal;
}

/****************************************************************************
@fn     hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha

@brief  To set the alpha value for dss pipeline

@param  [in] p_disp_id
        [in] p_pipeline_id
        [in] p_alpha
        
@return success: FVID2_SOK 
        failure: FVID2_EINVALID_PARAMS or driver error code
******************************************************************************/
int32_t hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha(uint8_t p_disp_id, uint8_t p_pipeline_id, uint8_t p_alpha)
{
    int32_t fl_retVal = FVID2_SOK;
    uint8_t fl_pipeInstId;
    
    if (GFX_MGR02_MAX_NUM_PIPELINES == 1U)
    {
        fl_pipeInstId = (gDssConfigPipelineParams.pipeId[0] == p_pipeline_id) ? (0U) : ((UINT8)GFX_MGR02_MAX_NUM_PIPELINES);
    }
    else if (GFX_MGR02_MAX_NUM_PIPELINES == 2U)
    {
        fl_pipeInstId = p_pipeline_id;
    }
    else
    {
        fl_pipeInstId = (UINT8)GFX_MGR02_MAX_NUM_PIPELINES;
    }
    
    if ((p_disp_id < GFX_MGR02_MAX_NUM_DISPLAYS) && (fl_pipeInstId < GFX_MGR02_MAX_NUM_PIPELINES))
    {
        Dss_Object *fl_DssObjPtr = &gDssObjects[p_disp_id];   /* DSS Object Pointer */
        Dss_InstObject *fl_instObjPtr = &fl_DssObjPtr->instObj[fl_pipeInstId]; /* DSS0, VIDL pipeline */
  
        if(fl_instObjPtr->dispParams.alphaCfg.globalAlpha != (uint32_t)p_alpha)
        {
            fl_instObjPtr->dispParams.alphaCfg.globalAlpha = (uint32_t)p_alpha;
            fl_retVal = Fvid2_control(
                      fl_instObjPtr->drvHandle,
                      IOCTL_DSS_DISP_SET_DSS_PARAMS,
                      &fl_instObjPtr->dispParams,
                      NULL);
        }
    }
    else
    {
        fl_retVal = FVID2_EINVALID_PARAMS;
    }
    return fl_retVal;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_tidss_dispif_cb
Description          : To get callback from driver
Invocation           : internal linkage
******************************************************************************/
static int32_t hmi_gfx_mgr02_tidss_dispif_cb(Fvid2_Handle handle, void *appData)
{
    framecomplete_cb();
    
    (void)handle;
    (void)appData;
    
    return FVID2_SOK;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_tidss_dispif_create
Description          : To create display handle and start driver
Invocation           : internal linkage
******************************************************************************/
static int32_t hmi_gfx_mgr02_tidss_dispif_create(uint8_t p_disp_id)
{
    int32_t retVal = FVID2_SOK;
    uint32_t fl_pipelineId;
    Dss_InstObject *instObj;
    
    Dss_Object *fl_DssObjPtr = &gDssObjects[p_disp_id];   /* DSS Object Pointer */

    /* Init VP, Overlay and Panel params */
    hmi_gfx_mgr02_tidss_dispif_init_dss_params(p_disp_id);

    /* Configure DSS pipeline params */
    hmi_gfx_mgr02_tidss_dispif_init_pipeline_params(p_disp_id);

    /* Config IOCTL for VP, Overlay and Panel */
    retVal = hmi_gfx_mgr02_tidss_dispif_config_dctrl(p_disp_id);

    if(retVal == FVID2_SOK)
    {
      for(fl_pipelineId = 0U; fl_pipelineId < GFX_MGR02_MAX_NUM_PIPELINES; fl_pipelineId++)
      {
          instObj = &fl_DssObjPtr->instObj[fl_pipelineId];

          instObj->drvHandle = Fvid2_create(
              DSS_DISP_DRV_ID,
              instObj->instId,
              &instObj->createParams,
              &instObj->createStatus,
              &instObj->cbParams);

          if((NULL == instObj->drvHandle) || (instObj->createStatus.retVal != FVID2_SOK))
          {
              retVal = instObj->createStatus.retVal;
          }

          if(FVID2_SOK == retVal)
          {
              retVal = Fvid2_control(
                  instObj->drvHandle,
                  IOCTL_DSS_DISP_SET_DSS_PARAMS,
                  &instObj->dispParams,
                  NULL);
          }
          
          if(FVID2_SOK == retVal)
          {
              retVal = Fvid2_control(
                  instObj->drvHandle,
                  IOCTL_DSS_DISP_SET_PIPE_MFLAG_PARAMS,
                  &instObj->mflagParams,
                  NULL);
          }

          if(FVID2_SOK == retVal)
          {
              uint32_t frmId, numFrames;
              Fvid2_Frame *frm;
              Fvid2_FrameList frmList;

              Fvid2FrameList_init(&frmList);
              frm = instObj->frames;
              numFrames = instObj->numFrames;
              
              /* init memory pointer for 'numFrames'  */
              for(frmId = 0U; frmId < numFrames; frmId++)
              {
                  /* init Fvid2_Frame to 0's  */
                  Fvid2Frame_init((Fvid2_Frame *)(frm + frmId));

                  frm[frmId].addr[0U] = (uint64_t) hmi_gfx_mgr02_context_get_fb_addr(frmId);
              
                  frm[frmId].fid = FVID2_FID_FRAME;
                  frm[frmId].appData = instObj;

                  /* Set number of frame in frame list - one at a time */
                  frmList.numFrames  = 1U;
                  frmList.frames[0U] = &frm[frmId];

                  /*
                   * queue the frames in frmList
                   * All allocate frames are queued here as an example.
                   * In general atleast 2 frames per channel need to queued
                   * before starting display,
                   * else frame will get dropped until frames are queued
                   */
                  
                  retVal = Fvid2_queue(instObj->drvHandle, &frmList, 0U);
                  if(FVID2_SOK != retVal)
                  {
                      break;
                  }
              }
          }

          if(FVID2_SOK != retVal)
          {
              break;
          }
      }
    }
    
    if(FVID2_SOK == retVal)
    {
      /* Start display driver */
      for(fl_pipelineId = 0U; fl_pipelineId < GFX_MGR02_MAX_NUM_PIPELINES; fl_pipelineId++)
      {
          instObj = &fl_DssObjPtr->instObj[fl_pipelineId];

          retVal = Fvid2_start(instObj->drvHandle, NULL);
          if(retVal != FVID2_SOK)
          {
              break;
          }
      }
    }
    
    return retVal;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_tidss_dispif_init_dss_params
Description          : To init dss parameters
Invocation           : internal linkage
******************************************************************************/
static void hmi_gfx_mgr02_tidss_dispif_init_dss_params(uint8_t p_disp_id)
{
    Dss_DctrlVpParams *vpParams;
    Dss_DctrlAdvVpParams *advVpParams;
    Dss_DctrlOverlayParams *overlayParams;
    Dss_DctrlOverlayLayerParams *layerParams;
    Dss_DctrlGlobalDssParams *globalDssParams;
    
    Dss_Object *fl_DssObjPtr = &gDssObjects[p_disp_id];   /* DSS Object Pointer */
      
    vpParams = &fl_DssObjPtr->vpParams;
    overlayParams = &fl_DssObjPtr->overlayParams;
    layerParams = &fl_DssObjPtr->layerParams;
    advVpParams = &fl_DssObjPtr->advVpParams;
    globalDssParams= &fl_DssObjPtr->globalDssParams;

    Dss_dctrlVpParamsInit(vpParams);
    Dss_dctrlAdvVpParamsInit(advVpParams);
    Dss_dctrlOverlayParamsInit(overlayParams);
    Dss_dctrlOverlayLayerParamsInit(layerParams);
    Dss_dctrlGlobalDssParamsInit(globalDssParams);


    /* Configure VP params */
    vpParams->vpId = gDssVpParams.vpId;
    vpParams->lcdOpTimingCfg.mInfo.standard = gDssVpParams.lcdOpTimingCfg.mInfo.standard;
    vpParams->lcdOpTimingCfg.mInfo.width = gDssVpParams.lcdOpTimingCfg.mInfo.width;
    vpParams->lcdOpTimingCfg.mInfo.height = gDssVpParams.lcdOpTimingCfg.mInfo.height;
    vpParams->lcdOpTimingCfg.mInfo.hFrontPorch = gDssVpParams.lcdOpTimingCfg.mInfo.hFrontPorch;
    vpParams->lcdOpTimingCfg.mInfo.hBackPorch = gDssVpParams.lcdOpTimingCfg.mInfo.hBackPorch;
    vpParams->lcdOpTimingCfg.mInfo.hSyncLen = gDssVpParams.lcdOpTimingCfg.mInfo.hSyncLen;
    vpParams->lcdOpTimingCfg.mInfo.vFrontPorch = gDssVpParams.lcdOpTimingCfg.mInfo.vFrontPorch;
    vpParams->lcdOpTimingCfg.mInfo.vBackPorch = gDssVpParams.lcdOpTimingCfg.mInfo.vBackPorch;
    vpParams->lcdOpTimingCfg.mInfo.vSyncLen = gDssVpParams.lcdOpTimingCfg.mInfo.vSyncLen;

    vpParams->lcdOpTimingCfg.dvoFormat = gDssVpParams.lcdOpTimingCfg.dvoFormat;
    vpParams->lcdOpTimingCfg.videoIfWidth = gDssVpParams.lcdOpTimingCfg.videoIfWidth;

    vpParams->lcdPolarityCfg.actVidPolarity =  gDssVpParams.lcdPolarityCfg.actVidPolarity;
    vpParams->lcdPolarityCfg.hsPolarity = gDssVpParams.lcdPolarityCfg.hsPolarity;
    vpParams->lcdPolarityCfg.vsPolarity = gDssVpParams.lcdPolarityCfg.vsPolarity;
    vpParams->lcdPolarityCfg.pixelClkPolarity = gDssVpParams.lcdPolarityCfg.pixelClkPolarity ;

    /* Configure VP Advance Params*/
    advVpParams->vpId = gDssAdvVpParams.vpId;
    advVpParams->lcdAdvSignalCfg.hVAlign = gDssAdvVpParams.lcdAdvSignalCfg.hVAlign;
    advVpParams->lcdAdvSignalCfg.hVClkControl = gDssAdvVpParams.lcdAdvSignalCfg.hVClkControl;

    /* Configure Overlay Params */
    overlayParams->overlayId =  gDssOverlayParams.overlayId;
    overlayParams->colorbarEnable =  gDssOverlayParams.colorbarEnable;
    overlayParams->overlayCfg.colorKeyEnable =  gDssOverlayParams.overlayCfg.colorKeyEnable;
    overlayParams->overlayCfg.colorKeySel =  gDssOverlayParams.overlayCfg.colorKeySel;
    overlayParams->overlayCfg.backGroundColor =  gDssOverlayParams.overlayCfg.backGroundColor;

    /* Configure Overlay Layer params */
    layerParams->overlayId = gDssOverlayLayerParams.overlayId;
    
    for (uint8_t i = 0U; i < CSL_DSS_VID_PIPE_ID_MAX; i++)
    {
        layerParams->pipeLayerNum[i] = gDssOverlayLayerParams.pipeLayerNum[i];
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_tidss_dispif_init_pipeline_params
Description          : To init each dss pipeline parameters
Invocation           : internal linkage
******************************************************************************/
static void hmi_gfx_mgr02_tidss_dispif_init_pipeline_params(uint8_t p_disp_id)
{
    uint32_t fl_pipelineId;
    Dss_DispParams *dispParams;
    Dss_InstObject *instObj;
    
    Dss_Object *fl_DssObjPtr = &gDssObjects[p_disp_id];   /* DSS Object Pointer */

    for(fl_pipelineId = 0U; fl_pipelineId < GFX_MGR02_MAX_NUM_PIPELINES; fl_pipelineId++)
    {
        /* Initialize video pipeline parameters */
        instObj = &fl_DssObjPtr->instObj[fl_pipelineId];
        instObj->instId = gDssConfigPipelineParams.instId[fl_pipelineId];
        
        instObj->createParams.periodicCbEnable = FALSE;
        instObj->createParams.progPipeVsyncEnable = FALSE;
        
        Fvid2CbParams_init(&instObj->cbParams);

        instObj->cbParams.cbFxn = &hmi_gfx_mgr02_tidss_dispif_cb;
        instObj->cbParams.appData = instObj;

        dispParams = &instObj->dispParams;
        Dss_dispParamsInit(dispParams);

        dispParams->pipeCfg.pipeType = gDssConfigPipelineParams.pipeType[fl_pipelineId];
        dispParams->pipeCfg.inFmt.width = gDssConfigPipelineParams.inWidth[fl_pipelineId];
        dispParams->pipeCfg.inFmt.height = gDssConfigPipelineParams.inHeight[fl_pipelineId];

        for(uint32_t count = 0U; count < FVID2_MAX_PLANES; count++)
        {
            dispParams->pipeCfg.inFmt.pitch[count] = gDssConfigPipelineParams.pitch[fl_pipelineId][count];
        }

        dispParams->pipeCfg.inFmt.dataFormat = gDssConfigPipelineParams.inDataFmt[fl_pipelineId];
        dispParams->pipeCfg.inFmt.scanFormat = gDssConfigPipelineParams.inScanFmt[fl_pipelineId];
        dispParams->pipeCfg.outWidth = gDssConfigPipelineParams.outWidth[fl_pipelineId];
        dispParams->pipeCfg.outHeight = gDssConfigPipelineParams.outHeight[fl_pipelineId];
        dispParams->pipeCfg.scEnable = gDssConfigPipelineParams.scEnable[fl_pipelineId];

        dispParams->alphaCfg.globalAlpha = gDssConfigPipelineParams.globalAlpha[fl_pipelineId];
        dispParams->alphaCfg.preMultiplyAlpha = gDssConfigPipelineParams.preMultiplyAlpha[fl_pipelineId];
        dispParams->layerPos.startX = gDssConfigPipelineParams.posx[fl_pipelineId];
        dispParams->layerPos.startY = gDssConfigPipelineParams.posy[fl_pipelineId];

        Dss_dispPipeMflagParamsInit(&instObj->mflagParams);
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_tidss_dispif_config_dctrl
Description          : configure display controller
Invocation           : internal linkage
******************************************************************************/
static int32_t hmi_gfx_mgr02_tidss_dispif_config_dctrl(uint8_t p_disp_id)
{
    int32_t retVal = FVID2_SOK;
    Dss_Object *fl_DssObjPtr = &gDssObjects[p_disp_id];   /* DSS Object Pointer */

    retVal += Fvid2_control(
      fl_DssObjPtr->dctrlHandle,
      IOCTL_DSS_DCTRL_SET_PATH,
      fl_DssObjPtr->dctrlPathInfo,
      NULL);
  
    retVal += Fvid2_control(
        fl_DssObjPtr->dctrlHandle,
        IOCTL_DSS_DCTRL_SET_ADV_VP_PARAMS,
        &fl_DssObjPtr->advVpParams,
        NULL);

    retVal += Fvid2_control(
        fl_DssObjPtr->dctrlHandle,
        IOCTL_DSS_DCTRL_SET_VP_PARAMS,
        &fl_DssObjPtr->vpParams,
        NULL);

    retVal += Fvid2_control(
        fl_DssObjPtr->dctrlHandle,
        IOCTL_DSS_DCTRL_SET_OLDI_PARAMS,
        fl_DssObjPtr->oldiParams,
        NULL);

    retVal += Fvid2_control(
        fl_DssObjPtr->dctrlHandle,
        IOCTL_DSS_DCTRL_SET_OVERLAY_PARAMS,
        &fl_DssObjPtr->overlayParams,
        NULL);

    retVal += Fvid2_control(
        fl_DssObjPtr->dctrlHandle,
        IOCTL_DSS_DCTRL_SET_LAYER_PARAMS,
        &fl_DssObjPtr->layerParams,
        NULL);

    retVal += Fvid2_control(
        fl_DssObjPtr->dctrlHandle,
        IOCTL_DSS_DCTRL_SET_GLOBAL_DSS_PARAMS,
        &fl_DssObjPtr->globalDssParams,
        NULL);
    
    return retVal;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_tidss_dispif_delete
Description          : To delete driver handle and stop driver
Invocation           : internal linkage
******************************************************************************/
static int32_t hmi_gfx_mgr02_tidss_dispif_delete(uint8_t p_disp_id)
{
    int32_t  retVal = FVID2_SOK;
    uint32_t fl_pipelineId;
    Dss_DctrlVpParams *vpParams;
    Dss_DctrlVpErrorStats *pErrorStats;
    Dss_InstObject *instObj;
    Dss_DispCurrentStatus currStatus;
    Fvid2_FrameList frmList;
    
    Dss_Object *fl_DssObjPtr = &gDssObjects[p_disp_id];   /* DSS Object Pointer */
    
    currStatus.underflowCount = 0U;
    vpParams = &fl_DssObjPtr->vpParams;
    pErrorStats = &fl_DssObjPtr->errorStats;
    
    for(fl_pipelineId=0U; fl_pipelineId<GFX_MGR02_MAX_NUM_PIPELINES; fl_pipelineId++)
    {
        instObj = &fl_DssObjPtr->instObj[fl_pipelineId];
        
        retVal = Fvid2_stop(instObj->drvHandle, NULL);
        
        if(FVID2_SOK == retVal)
        {
          /* Check for DSS underflow errors */
          retVal = Fvid2_control(
              instObj->drvHandle,
              IOCTL_DSS_DISP_GET_CURRENT_STATUS,
              &currStatus,
              NULL);
          
          if(FVID2_SOK == retVal)
          {
            if(0U != currStatus.underflowCount)
            { 
              retVal = FVID2_EFAIL;
            }
            else
            {
              /* Dequeue all the request from the driver */
              while (true)
              {
                  retVal = Fvid2_dequeue(
                      instObj->drvHandle,
                      &frmList,
                      0U,
                      FVID2_TIMEOUT_NONE);
                  
                  if(FVID2_SOK != retVal)
                  {
                      break;
                  }
              }
              
              retVal = Fvid2_delete(instObj->drvHandle, NULL);
            }
          }
        }
        
        if(FVID2_SOK != retVal)
        {
          break;
        }
    }
    
    if(FVID2_SOK == retVal)
    {
      /* Check for DSS synclost errors */
      retVal = Fvid2_control(
          fl_DssObjPtr->dctrlHandle,
          IOCTL_DSS_DCTRL_GET_VP_ERROR_STATS,
          pErrorStats,
          NULL);
      
      if(FVID2_SOK == retVal)
      {
        if(0U != pErrorStats->syncLost)
        {
           retVal = FVID2_EFAIL;
        }
        
        if(FVID2_SOK == retVal)
        {
          retVal = Fvid2_control(
              fl_DssObjPtr->dctrlHandle,
              IOCTL_DSS_DCTRL_CLEAR_PATH,
              fl_DssObjPtr->dctrlPathInfo,
              NULL);
        }
        
        if(FVID2_SOK == retVal)
        {
          retVal = Fvid2_control(
              fl_DssObjPtr->dctrlHandle,
              IOCTL_DSS_DCTRL_STOP_VP,
              vpParams,
              NULL);
        } 
      }
    }    
    return retVal;
}

#endif /* #if defined(GFX_MGR02_USE_TIDSS) */

/************************** End of Module *********************************/

