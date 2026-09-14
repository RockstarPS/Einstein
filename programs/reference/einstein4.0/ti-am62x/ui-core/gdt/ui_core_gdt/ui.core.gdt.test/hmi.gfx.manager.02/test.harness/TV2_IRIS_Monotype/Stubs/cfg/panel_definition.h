
#ifndef __PANEL_DEFINITION_H__
#define __PANEL_DEFINITION_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/
static CYGFX_DISP_TCON_PROPERTIES_S tconConfig[] =
{
        { 0x0408, 0x00000108}, /* CTRL (ENLVDS | BYPASS) */	
        { 0x0410, 0x03040508}, /* MapBit3_0   ( R3, R4, R5, G0)     */
        { 0x0414, 0x11000102}, /* MapBit7_4   ( B1, R0, R1, R2)     */
        { 0x0418, 0x0B0C0D10}, /* MapBit11_8  ( G3, G4, G5, B0)     */
        { 0x041c, 0x191A090A}, /* MapBit15_12 ( VSYNC, EN, G1, G2)  */
        { 0x0420, 0x13141518}, /* MapBit19_16 ( B3, B4, B5, HSYNC)  */
        { 0x0424, 0x16171B12}, /* MapBit23_20 ( B6, B7, RES, B2)    */
        { 0x0428, 0x06070E0F}, /* MapBit27_24 ( R6, R7, G6, G7)     */    
};

const CYGFX_DISP_PROPERTIES_S l_mml_gdc_dispParams[1] = {
      CYGFX_DISP_CONTROLLER_0,
      CYGFX_DISP_MODE_SINGLE_SCREEN, 
      CYGFX_DISP_SYNC_MODE_NONE,
      {
		29.0f,                             /* pixelClock */               
		800,                                /* Hact */               
		480,                                /* Vact */              
		923,                                /* Htot */              
		524,                                /* Vtot */              
		48,                                 /* Hsbp */              
		20,                                 /* Vsbp */              
		4,                                 /* Hsync */              
		4,                                  /* Vsync */               
		0,                                  /* HtotMin */              
		0,                                  /* VtotMin */  
		0,                                  /* HtotMax */  
		0,                                  /* VtotMax */  
		CYGFX_DISP_DCK_INVERT_OFF,          /* DCKInvertEnable */  
		CYGFX_GEN_POLARITY_HIGH,            /* polEn */
		CYGFX_GEN_POLARITY_LOW,             /* polHs */
		CYGFX_GEN_POLARITY_LOW,             /* polVs */
		CYGFX_DISP_RGB_LOW                  /* pixInv */
      },
      tconConfig,
      sizeof(tconConfig)/sizeof(CYGFX_DISP_TCON_PROPERTIES_S)
};

#ifdef __cplusplus
}
#endif

#endif /* __PANEL_DEFINITION_H__ */


