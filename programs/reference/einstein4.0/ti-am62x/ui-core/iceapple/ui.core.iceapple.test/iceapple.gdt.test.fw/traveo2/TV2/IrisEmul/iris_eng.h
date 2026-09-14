#ifndef IRIS_ENG_H
#define IRIS_ENG_H

struct PixBufferCache
{
  unsigned char* pBuffer;
  unsigned      timeStampLastUsed;
  unsigned      oglFormat;
  unsigned      oglType;
  unsigned char isBufferDynamic;
  unsigned      color;
};

#ifdef __cplusplus
extern "C"
{
#endif


#include "iris_DrwEngWrp.h"

#define MML_GDC_SURF_FORMAT_YUV420                      CYGFX_SM_FORMAT_YUV420
  typedef enum
  {
    eNoClut,
    eRGBClut,
    eRGBAClut
  }teClutMode;


  struct IRIS2_Display_tag;

  struct PE_CTX_Matrix {
    float mat[3][3];
    unsigned char isActive;
  };

  typedef struct IRIS2_Surface_tag
  {
    unsigned int width;
    unsigned int height;
    unsigned int stride;
    unsigned int compression;
    unsigned char* pBuffer;
    unsigned int bitperpixel;
    unsigned int colorbits;
    unsigned int colorshift;
    unsigned int colorformat;
    unsigned int imgformat;
    unsigned int colorspace;
    unsigned int sizeinbytes;
    unsigned int ClutMode;
    unsigned int ClutCount;
    unsigned int ClutFormat;
    unsigned int ClutBitPerPixel;
    unsigned int ClutColorBits;
    unsigned int ClutColorShift;
    unsigned int DispSize;
    void* pClutBufferAddress;

  } IRIS2_Surface;

  typedef struct IRIS2_PECtx_tag
  {
    struct {
      unsigned int DITHER_COLOR;
      unsigned int DITHER_ALPHA;
      unsigned int DITHER_OFFSET;
      unsigned int FILTER;
      unsigned int GAMMA;
      unsigned int ZERO_POINT;
    } attributes;

    struct {
      unsigned int COLORMULTI;
      unsigned int ALPHAMULTI;
      unsigned int TILE_MODE;
      unsigned int USE_CLIPPING;
    }
    storeSurfAttr, srcSurfAttr, dstSurfAttr, maskSurfAttr;

    struct {
      unsigned char r, g, b, a;
    } color, surfSrcColor, surfDstColor, surfStoreColor, surfMaskColor;

    struct {
      unsigned char isAcive;
      int x, y;
      unsigned w, h;
    } storeRectArea, srcRectArea, dstRectArea, maskRectArea;
    unsigned int selectedArea;

    struct {
      unsigned int func_red_src;
      unsigned int func_red_dst;
      unsigned int func_green_src;
      unsigned int func_green_dst;
      unsigned int func_blue_src;
      unsigned int func_blue_dst;
      unsigned int func_alpha_src;
      unsigned int func_alpha_dst;

      unsigned int mode_red;
      unsigned int mode_green;
      unsigned int mode_blue;
      unsigned int mode_alpha;
    } blend;

    struct {
      tDrawInstruction DrawInstruction;

    } draw_eng;

    struct PE_CTX_Matrix dstMatrix, srcMatrix, storeMatrix, maskMatrix;


    IRIS2_Surface* pSrc, * pDst, * pMask, * pStore;
    tMML_GDC_DE_DATA_FORMAT epPathDataSize;
    unsigned char SegmentType;
    tSinglePoint SinglePoint;
    /*ADDED BY BHARIHA1 FOR TV2 ->*/
    unsigned int task;
    unsigned int render_mode;
    /*<-ADDED BY BHARIHA1 FOR TV2*/
  } IRIS2_PECtx;

  typedef struct IRIS2_Window_tag
  {
    int x;
    int y;
    unsigned int width;
    unsigned int height;

    unsigned int tileMode;
    unsigned int color;
    unsigned int features;

    unsigned char layer;
    unsigned char subLayer;
    unsigned char isDisabled;

    unsigned int blendMode;

    IRIS2_Surface* pSurface;

    struct IRIS2_Window_tag* pNext;
    struct IRIS2_Display_tag* pDisplay;

  } IRIS2_Window;

  typedef struct IRIS2_Display_tag
  {
    unsigned int width;
    unsigned int height;

    IRIS2_Window* pWindowList;
  } IRIS2_Display;

  typedef struct IRIS2_Palette_tag
  {
    void * PhysAdd;                             /**< physical address palette data */
    unsigned int  ColorBits;                    /**< Color component size of one entry in bits (0xRRGGBBAA) */
    unsigned int  ColorShift;                   /**< Color component shift of one entry in bits (0xRRGGBBAA) */
    unsigned int  Count;                        /**< Number of color in the palette */
    unsigned int  BitPerPixel;                  /**< Size of one entry in bits (1, 2, 4, 8, 16, 24, 32) */
    unsigned int  Format;                /**< format of the palette */
    unsigned int  HwBitWidth;                   /**< Bits representing Count (internal value only. Will be calculated by ::CyGfx_PaletteAlloc.) */
  } IRIS2_Palette;


  void IrisEng_Init(void);
  void IrisEng_DeInit(void);
  void IrisEng_DispCtrl_Draw(void);
  void IrisEng_PixEng_Fill(IRIS2_PECtx*, int x, int y, unsigned int w, unsigned int h);
  void IrisEng_PixEng_Blit(IRIS2_PECtx*, float x, float y);

  void IrisEng_SetCurrentLayer(int p_layer_index);
  void IrisEng_SetBrontesCtx();
  void IrisEng_ReleaseBrontesCtx();
  void IrisEng_DispCtrl_Draw_Layer(int p_layer_index);
  void IrisEng_SetBrontesCtxHUD();
  void IrisEng_ReleaseBrontesCtxHUD();
  IRIS2_Display* IrisEng_CreateDsp(void* Key);
  void            IrisEng_DestroyDsp(void* Key);

  IRIS2_Window* IrisEng_CreateWnd(void* Key);
  void            IrisEng_DestroyWnd(void* Key);

  IRIS2_PECtx* IrisEng_CreatePeCtx(void* Key);
  void            IrisEng_DestroyPeCtx(void* Key);

  IRIS2_Surface* IrisEng_CreateSurf(void* Key);
  void            IrisEng_DestroySurf(void* Key);

  IRIS2_Palette* IrisEng_CreatePalette(void* Key);
  void            IrisEng_DestroyPalette(void* Key);

  void MakeActivePECtx(IRIS2_PECtx*);


#ifdef __cplusplus
}
#endif

#endif