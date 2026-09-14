#include "system.h"
#include "fsl_lcdifv2.h"
#include "fsl_pxp.h"
#include "vg_lite.h"
static bool     PXP__GetStatusFlags;
static bool     PXP_Enable;
static uint32_t SetLayerBufferAddr;
static uint16_t SetLayerOffsetY;
static uint16_t SetLayerOffsetX;
static uint16_t SetLayerwidth;
static uint16_t SetLayerheight;
static bool     enable_display=0;
static bool     enable_interrupts=0;
static bool     enable_layer=0;
static          UINT8 TriggerLayerShadowLoad;
static bool     PXPEnableAlphaSurfaceOverlayColorKey;
static uint16_t PXP_SetAlphaSurfacePosition_upperLeftX;
static uint16_t PXP_SetAlphaSurfacePosition_upperLeftY;
static uint16_t PXP_SetAlphaSurfacePosition_lowerRightX;
static uint16_t PXP_SetAlphaSurfacePosition_lowerRightY;
static uint16_t PXP_SetProcessSurfacePosition_upperLeftX;
static uint16_t PXP_SetProcessSurfacePosition_upperLeftY;
static uint16_t PXP_SetProcessSurfacePosition_lowerRightX;
static uint16_t PXP_SetProcessSurfacePosition_lowerRightY;
static uint16_t PXP_SetProcessSurfacebackGroundColor;
static bool     PXP_enableOverWrittenAlpha;
static uint32_t PXP_SetAlphaSurfaceOverlayColorKey_colorKeyLow;
static uint32_t PXP_SetAlphaSurfaceOverlayColorKey_colorKeyHigh;
static uint32_t PXP_StartMemCopy_srcAddr;
static uint32_t PXP_StartMemCopy_destAddr; 
static uint32_t PXP_StartMemCopy_size;
static uint16_t PXP_setOverwrittenAlphaValue;
static lcdifv2_blend_config_t LCDIFV2__SetLayerBlendConfig={0};
static pxp_as_buffer_config_t PXP__SetAlphaSurfaceBufferConfig={0};
static pxp_porter_duff_config_t pd_Config={0};
static pxp_block_size_t PXP__SetProcessBlockSize;
static lcdifv2_display_config_t lcdifv2Config = {0};
static lcdifv2_buffer_config_t bufferConfig= {0};
static pxp_output_buffer_config_t BufferConfig={0};
static pxp_ps_buffer_config_t  ps_bufferconfig={0};
static pxp_pic_copy_config_t   PXP__StartPictureCopy={0};
//static lcdifv2_buffer_config_t LCDIFV2__SetLayerBufferConfig={0};

static bool scroll_done = 0;
/*************************** Stubbed Function Definitions **************************************/

/*********************************** LCDIFV2 Driver Functions **********************************/
void LCDIFV2_SetDisplayConfig(LCDIFV2_Type *base, const lcdifv2_display_config_t *config)
{
  lcdifv2Config.panelWidth       = config->panelWidth;
  lcdifv2Config.panelHeight      = config->panelHeight;
  lcdifv2Config.hsw              = config->hsw;
  lcdifv2Config.hfp              = config->hfp;
  lcdifv2Config.hbp              = config->hbp;
  lcdifv2Config.vsw              = config->vsw;
  lcdifv2Config.vfp              = config->vfp;
  lcdifv2Config.vbp              = config->vbp;
  lcdifv2Config.polarityFlags    = config->polarityFlags;
  lcdifv2Config.lineOrder        = config->lineOrder;
}

void LCDIFV2_EnableDisplay(LCDIFV2_Type *base, bool enable)
{
        enable_display=enable;
}

void LCDIFV2_EnableInterrupts(LCDIFV2_Type *base, uint8_t domain, uint32_t mask)
{
    enable_interrupts=mask;
}

void LCDIFV2_EnableLayer(LCDIFV2_Type *base, uint8_t layerIndex, bool enable)
{
    enable_layer=enable;
}

void LCDIFV2_TriggerLayerShadowLoad(LCDIFV2_Type *base, uint8_t layerIndex)
{
    TriggerLayerShadowLoad=layerIndex;
}

void LCDIFV2_SetLayerSize(LCDIFV2_Type *base, uint8_t layerIndex, uint16_t width, uint16_t height)
{
    SetLayerheight=height;
    SetLayerwidth=width;
}

void LCDIFV2_SetLayerOffset(LCDIFV2_Type *base, uint8_t layerIndex, uint16_t offsetX, uint16_t offsetY)
{
    SetLayerOffsetX=offsetX;
    SetLayerOffsetY=offsetY;
}

void LCDIFV2_SetLayerBufferConfig(LCDIFV2_Type *base,uint16_t p_layer_id,const lcdifv2_buffer_config_t *config)
{
  bufferConfig.strideBytes = config->strideBytes;
  bufferConfig.pixelFormat = config->pixelFormat;
}

void LCDIFV2_SetLayerBufferAddr(LCDIFV2_Type *base, uint8_t layerIndex, uint32_t *addr)
{
   SetLayerBufferAddr=addr;
}

void LCDIFV2_SetLayerBlendConfig(LCDIFV2_Type *base, uint8_t layerIndex, const lcdifv2_blend_config_t *config)
{
    LCDIFV2__SetLayerBlendConfig.globalAlpha        =config->globalAlpha;
    LCDIFV2__SetLayerBlendConfig.alphaMode          =config->alphaMode;
}

/*********************************** PXP Driver Functions *********************************/

void PXP_EnableCsc1(PXP_Type *base, bool enable)
{
    PXP_Enable=enable;
}

void PXP_SetProcessBlockSize(PXP_Type *base, pxp_block_size_t size)
{
    PXP__SetProcessBlockSize=size;
}

void PXP_SetOutputBufferConfig(PXP_Type *base, const pxp_output_buffer_config_t *config)
{
    BufferConfig.pixelFormat     =config->pixelFormat;
    BufferConfig.interlacedMode  =config->interlacedMode;
    BufferConfig.buffer0Addr     =config->buffer0Addr;
    BufferConfig.buffer1Addr     =config->buffer1Addr;
    BufferConfig.pitchBytes      =config->pitchBytes;
    BufferConfig.width           =config->width ;
    BufferConfig.height          =config->height;
}

void PXP_SetAlphaSurfacePosition(PXP_Type *base, uint16_t upperLeftX, uint16_t upperLeftY, uint16_t lowerRightX, uint16_t lowerRightY)
{
    PXP_SetAlphaSurfacePosition_upperLeftX   =upperLeftX;
    PXP_SetAlphaSurfacePosition_upperLeftY   =upperLeftY;
    PXP_SetAlphaSurfacePosition_lowerRightX  =lowerRightX;
    PXP_SetAlphaSurfacePosition_lowerRightY  =lowerRightY;
}

void PXP_SetProcessSurfacePosition(PXP_Type *base, uint16_t upperLeftX, uint16_t upperLeftY, uint16_t lowerRightX, uint16_t lowerRightY)
{
    PXP_SetProcessSurfacePosition_upperLeftX   =upperLeftX;
    PXP_SetProcessSurfacePosition_upperLeftY   =upperLeftY;
    PXP_SetProcessSurfacePosition_lowerRightX  =lowerRightX;
    PXP_SetProcessSurfacePosition_lowerRightY  =lowerRightY;
}

void PXP_SetProcessSurfaceBackGroundColor(PXP_Type *base, uint32_t backGroundColor)
{
    PXP_SetProcessSurfacebackGroundColor=backGroundColor;
}

void PXP_EnableOverWrittenAlpha(PXP_Type *base, bool enable)
{
    PXP_enableOverWrittenAlpha=enable;
}

void PXP_SetOverwrittenAlphaValue(PXP_Type *base, uint8_t alpha)
{
     PXP_setOverwrittenAlphaValue=alpha;
}

void PXP_SetPorterDuffConfig(PXP_Type *base, const pxp_porter_duff_config_t *config)
{
    pd_Config.enable             =config->enable;
    pd_Config.dstFactorMode      =config->dstFactorMode;
    pd_Config.srcFactorMode      =config->srcFactorMode;
    pd_Config.srcColorMode       =config->srcColorMode;
    pd_Config.dstColorMode       =config->dstColorMode;
    pd_Config.srcGlobalAlphaMode =config->srcGlobalAlphaMode;
    pd_Config.dstGlobalAlphaMode =config->dstGlobalAlphaMode;
    pd_Config.dstAlphaMode       =config->dstAlphaMode;
    pd_Config.srcAlphaMode       =config->srcAlphaMode;
    pd_Config.dstGlobalAlpha     =config->dstGlobalAlpha;
    pd_Config.srcGlobalAlpha     =config->srcFactorMode;
}

void PXP_SetProcessSurfaceBufferConfig(PXP_Type *base, const pxp_ps_buffer_config_t *config)
{
    ps_bufferconfig.pixelFormat      =config->pixelFormat;
    ps_bufferconfig.swapByte         =config->swapByte;                              
    ps_bufferconfig.bufferAddr       =config->bufferAddr;
    ps_bufferconfig.bufferAddrU      =config->bufferAddrU; 
    ps_bufferconfig.bufferAddrV      =config->bufferAddrV;
    ps_bufferconfig.pitchBytes       =config->pitchBytes;
}

void PXP_EnableAlphaSurfaceOverlayColorKey(PXP_Type *base, bool enable)
{
    PXPEnableAlphaSurfaceOverlayColorKey=enable;
}

void PXP_SetAlphaSurfaceOverlayColorKey(PXP_Type *base, uint32_t colorKeyLow, uint32_t colorKeyHigh)
{
    PXP_SetAlphaSurfaceOverlayColorKey_colorKeyLow  =colorKeyLow;
    PXP_SetAlphaSurfaceOverlayColorKey_colorKeyHigh =colorKeyHigh;
}

void PXP_StartPictureCopy(PXP_Type *base, const pxp_pic_copy_config_t *config)
{
    PXP__StartPictureCopy.srcPicBaseAddr  =config->srcPicBaseAddr;
    PXP__StartPictureCopy.srcPitchBytes   =config->srcPitchBytes;
    PXP__StartPictureCopy.srcOffsetX      =config->srcOffsetX;
    PXP__StartPictureCopy.srcOffsetY      =config->srcOffsetY;
    PXP__StartPictureCopy.destPicBaseAddr =config->destPicBaseAddr;
    PXP__StartPictureCopy.destPitchBytes  =config->destPitchBytes;
    PXP__StartPictureCopy.destOffsetX     =config->destOffsetX;
    PXP__StartPictureCopy.destOffsetY     =config->destOffsetY;
    PXP__StartPictureCopy.pixelFormat     =config->pixelFormat; 
    PXP__StartPictureCopy.height          =config->height;
    PXP__StartPictureCopy.width           =config->width;  
}

bool PXP_GetStatusFlags(PXP_Type *base)
{
  return(true);
}

void PXP_SetAlphaSurfaceBufferConfig(PXP_Type *base, const pxp_as_buffer_config_t *config)
{
    PXP__SetAlphaSurfaceBufferConfig.pitchBytes   =config->pitchBytes;
    PXP__SetAlphaSurfaceBufferConfig.bufferAddr   =config->bufferAddr;
    PXP__SetAlphaSurfaceBufferConfig.pixelFormat  =config->pixelFormat;
}
void eglCopyVGtoSurface(void)
{
  
}
void scroll_complete_cb(uint32_t anim_id)
{	//not recommended to call layout API
	scroll_done = 1;
}
/*********************************** VGLite Driver Functions *********************************/

