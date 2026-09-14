#include <windows.h>
#include "mm_types.h"
#include "iris_api_export.h"
#include "mml_gdc_sysinit.h"
#include "mml_gdc_config.h"
#include "mml_gdc_sync.h"
#include "mml_gdc_surfman.h"
#include "mml_gdc_pixeng.h"
#include "mml_gdc_display.h"
#include "mml_gdc_interrupt.h"
#include "mml_gdc_sig.h"
#include "ut_compatibility.h"
#include "ut_memman.h"
#include "sm_util.h"
#include "mml_gdc_erp.h"

typedef struct
{
   int w;
   int h;
   int format;
   int attributes;
   void * data;
}gdc_surf;

typedef struct
{
   int x;
   int y;
   int w;
   int h;
   int stride;
   int attributes;
   int alpha;
   gdc_surf * surf;
}gdc_window;

static unsigned int i = 0;

void hmi_gfx02_dcu_sim_update(void){
}

MM_ERROR mmlGdcDispOpenDisplay( MML_GDC_DISP_PROPERTIES * mode,
                                MML_GDC_DISPLAY         * display){
   return(MML_OK);
}

MM_ERROR mmlGdcDispWinCommit( MML_GDC_DISP_WINDOW win ){
   return(MML_OK);
}

MM_ERROR mmlGdcDispCommit(MML_GDC_DISPLAY display){
  return(MML_OK);
}

MM_ERROR mmlGdcDispWinCreate( MML_GDC_DISPLAY                  display,
                              MML_GDC_DISP_WINDOW_PROPERTIES * properties,
                              MML_GDC_DISP_WINDOW            * pWin ){
   *pWin = ++i;
   return(MML_OK);
}

MM_ERROR mmlGdcDispWinDestroy( MML_GDC_DISP_WINDOW win ){
   return(MML_OK);
}

MM_ERROR mmlGdcDispWinSetAttribute( MML_GDC_DISP_WINDOW   win,
                                    MML_GDC_DISP_WIN_ATTR pname,
                                    MM_U32                param ){
   return(MML_OK);
}

MM_ERROR mmlGdcDispWinSetBlendMode( MML_GDC_DISP_WINDOW win,
                                    MM_U32              blend_mode){
   return(MML_OK);
}

MM_ERROR mmlGdcDispWinSetSurface( MML_GDC_DISP_WINDOW win,
                                  MM_U32              target,
                                  MML_GDC_SURFACE     surf ){
   return(MML_OK);
}

MM_ERROR mmlGdcDispWinSync( MML_GDC_DISP_WINDOW win,
                            MML_GDC_SYNC        sync ){
   return(MML_OK);
}

MM_ERROR mmlGdcDispWinWaitSync( MML_GDC_DISP_WINDOW win,
                                MML_GDC_SYNC sync){
   return(MML_OK);
}

MM_S32 mmlGdcPeActiveArea(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MM_S32 x, MM_S32 y, MM_U32 w, MM_U32 h){
   return(MML_OK);
}

MM_ERROR mmlGdcPeAttribute (MML_GDC_PE_CONTEXT pectx, MML_GDC_PE_CTX_ATTR pname, MM_U32 param){
   return(MML_OK);
}

MM_ERROR mmlGdcPeBindSurface(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MML_GDC_SURFACE surface){
   return(MML_OK);
}

MM_S32 mmlGdcPeBlendFunc(MML_GDC_PE_CONTEXT pectx, MML_GDC_PE_BF func_red_src, MML_GDC_PE_BF func_red_dst,
        MML_GDC_PE_BF func_green_src, MML_GDC_PE_BF func_green_dst, MML_GDC_PE_BF func_blue_src, MML_GDC_PE_BF func_blue_dst,
        MML_GDC_PE_BF func_alpha_src, MML_GDC_PE_BF func_alpha_dst){
   return(MML_OK);
}

MM_S32 mmlGdcPeBlendMode(MML_GDC_PE_CONTEXT pectx, MML_GDC_PE_BM mode_red, MML_GDC_PE_BM mode_green, MML_GDC_PE_BM mode_blue, MML_GDC_PE_BM mode_alpha){
   return(MML_OK);
}

MM_ERROR mmlGdcPeBlt(MML_GDC_PE_CONTEXT pectx, MM_FLOAT offsetx, MM_FLOAT offsety){
   return(MML_OK);
}

MM_S32 mmlGdcPeColor(MML_GDC_PE_CONTEXT pectx, MM_U08 red, MM_U08 green, MM_U08 blue, MM_U08 alpha){
   return(MML_OK);
}

MM_S32 mmlGdcPeFill(MML_GDC_PE_CONTEXT pectx, MM_U32 x, MM_U32 y, MM_U32 w, MM_U32 h){
   return(MML_OK);
}

MM_ERROR mmlGdcPeResetContext(MML_GDC_PE_CONTEXT pectx){
   return(MML_OK);
}

MM_S32 mmlGdcPeSelectArea(MML_GDC_PE_CONTEXT pectx, MM_U32 target){
   return(MML_OK);
}

MM_ERROR mmlGdcPeSetMatrix(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MML_GDC_PE_GEO_MATRIX_FORMAT format, const MM_FLOAT *fMatrix){
   return(MML_OK);
}

MM_ERROR mmlGdcPeSurfAttribute(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MML_GDC_PE_SURF_ATTR pname, MM_U32 param){
   return(MML_OK);
}

MM_ERROR mmlGdcPeSurfColor(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MM_U08 red, MM_U08 green, MM_U08 blue, MM_U08 alpha){
   return(MML_OK);
}

MM_S32 mmlGdcPeSync(MML_GDC_SYNC sync){
   return(MML_OK);
}

MM_ERROR mmlGdcSmAssignBuffer(MML_GDC_SURFACE surf, MM_U32 uWidth, MM_U32 uHeight, MML_GDC_SURF_FORMAT eFormat, void *pBufferAddress, MM_U32 uRleWords){
   return(MML_OK);
}
MM_ERROR mmlGdcSmResetSurfaceObject(MML_GDC_SURFACE surf){
   return(MML_OK);
}
MM_ERROR mmlGdcSmSetAttribute(const MML_GDC_SURFACE surf, MML_GDC_SURF_ATTR eName, MM_U32 uValue){
   return(MML_OK);
}
MM_ERROR mmlGdcSmGetAttribute(const MML_GDC_SURFACE surf, MML_GDC_SURF_ATTR eName, MM_U32 *puValue){
   return(MML_OK);
}
MM_ERROR mmlGdcSyncReset(MML_GDC_SYNC sync){
   return(MML_OK);
}
MM_ERROR mmlGdcSyncWait(MML_GDC_SYNC sync, MM_S32 timeout){
   return(MML_OK);
}
MM_ERROR mmlGdcSysInitializeDriver(MML_GDC_SYSINIT_INFO *pDriverInitInfo){
   return(MML_OK);
}
MM_ERROR mmlGdcSysSetInstructionBuffer(void* address, MM_U32 size){
   return(MML_OK);
}
void * mmlGdcVideoAlloc( MM_U32 size, MM_U32 alignment, MM_ADDR *pAddr ){
   return(malloc(size));
}
void mmlGdcVideoFree(void* addr){
   free(addr);
}
MM_ERROR utMmanReset(void){
   return(MML_OK);
}
void utSurfDeleteBuffer(MML_GDC_SURFACE surf)
{
    MM_U32 add;

    mmlGdcSmGetAttribute(surf, MML_GDC_SURF_ATTR_BASE_ADDRESS, &add);
    if (add != 0)
    {
        mmlGdcVideoFree( (void*)add);
        mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_BASE_ADDRESS, 0);
    }
    mmlGdcSmGetAttribute(surf, MML_GDC_SURF_ATTR_BASE_ADDRESS2, &add);
    if (add != 0)
    {
        mmlGdcVideoFree( (void*)add);
        mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_BASE_ADDRESS2, 0);
    }
    mmlGdcSmGetAttribute(surf, MML_GDC_SURF_ATTR_CLUTBUFFERADDRESS, &add);
    if (add != 0)
    {
        mmlGdcVideoFree( (void*)add);
        mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_CLUTBUFFERADDRESS, 0);
    }
}

void eglCopyVGtoSurface(void){
}

MM_ERROR mmlGdcSmGenSurfaceObjects(MM_U32 uCnt, MML_GDC_SURFACE *pSurfaces)
{
   *pSurfaces = ++i;
   return 0;
}

MM_ERROR mmlGdcSyncCreate(MM_U32 uCnt, MML_GDC_SYNC* pSyncObjects)
{
   *pSyncObjects = ++i;
   return 0;
}

MM_ERROR mmlGdcErpSetPrintf(MM_PRINTFUNCTION *user_print_function)
{
   return 0;
}

MM_ERROR mmlGdcConfigGetAttribute( MML_GDC_CONFIG_ATTR pname, MM_U32 *pParam )
{
   return 0;
}

void mmlGdcPeDeleteContext(MML_GDC_PE_CONTEXT pectx)
{
}

MM_ERROR mmlGdcPeGenContext(MML_GDC_PE_CONTEXT *pPectx)
{
   *pPectx = ++i;
   return 0;
}

MM_ERROR mmlGdcDispWinGetAttribute( MML_GDC_DISP_WINDOW win,
                                    MML_GDC_DISP_WIN_ATTR pname,
                                    MM_U32 *pParam ){
   return 0;
}

MM_ERROR mmlGdcDispDitherCtrl( MML_GDC_DISPLAY display,
                               MML_GDC_DISP_DITHER_ENABLE enable,
                               MML_GDC_DISP_DITHER_MODE mode,
                               MML_GDC_DISP_DITHER_RANGE range,
                               MML_GDC_DISP_DITHER_FORMAT format )
{
   return 0;
}
