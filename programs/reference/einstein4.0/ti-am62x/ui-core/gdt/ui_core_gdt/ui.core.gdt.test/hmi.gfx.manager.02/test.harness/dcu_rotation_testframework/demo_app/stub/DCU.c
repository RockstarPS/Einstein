/**
  Copyright (c) 2009 Freescale Semiconductor
  
  \file  	  DCU.c
  \brief	  This is the DCU Driver File
  \brief	  Configures Freq. and Activates DCU and layers on xPC560xS (SPECTRUM)
  \author	  Freescale Semiconductor
  \author	  Automotive Systems Solutions Engineering
  \author	  Ioseph Martinez, b06623 - After Steve McAslan
  \version	  1.1
  \date  	  19/May/2009
  
  * History:  10/July/2008 - Initial Version
              13/May/2009 - MISRA Check 

  * MISRA VIOLATIONS:
	- [ MISRA 11.2 ]
	- [ MISRA 16.9 ]  

* Copyright (c) 2009, Freescale, Inc.  All rights reserved.
*
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*
  
*/

#include	"DCU.h"
#include 	"Ports.h"


void			TX09_setup( uint32_t  freq );
void			LQ043_setup( uint32_t	freq );
DCU_CallbackType	DCU_CallbackVSYNC;
DCU_CallbackType	DCU_CallbackVSBLANK;
DCU_CallbackType	DCU_CallbackLSBFVS;
DCU_CallbackType	DCU_CallbackPROGD;
DCU_Timing_t		DCU_TimingStatus;

/**
* \brief	DCU_Init - Initializes the DCU hw at the given frequency
* \author	IM, b06623
* \param	uint32_t freq, frequency for initialization (from 16 to 64MHz)
* \return	void
* \todo
*/
void DCU_Init( uint32_t  freq )
{								
#if 0
	/* Background colour = black */
	DCU.BGND.R	= 0x00000000u;
	CGM.AC0_SC.R = 0x03000000u;										
	DCU.DCU_MODE.R = 0x00000000;
	
	
#if (  DCU_LCD	==	DCU_HITACHI_TX09  )
	TX09_setup( freq );
#else
	LQ043_setup( freq );
#endif
	DCU.INT_MASK.R = 0xF7FFF;	
	/* VIOLATION TO THE FOLLOWING RULES  [ MISRA 11.2 ] [ MISRA 16.9 ] */
	/* Rationale: It is required to assign a values to this function that will be used as callback */
	/* the null pointer value indicates the function has not been initialized */
	DCU_CallbackVSYNC	= NULL_PTR;
	DCU_CallbackVSBLANK	= NULL_PTR;
	DCU_CallbackLSBFVS	= NULL_PTR;
	DCU_CallbackPROGD	= NULL_PTR;
	DCU_TimingStatus	= DCU_UNKNOWN;

	/* Gamma adjust disable */
	DCU.DCU_MODE.B.EN_GAMMA  = 0u;
	/* Set lines before Vertical sync value */
	DCU.THRESHOLD.B.LS_BF_VS = 0u;
	DCU.DCU_MODE.B.BLEND_ITER = 4; 		
	DCU.DCU_MODE.B.RASTER_EN = 1; 	
#endif
}

/**
* \brief	DCU_SetChroma - Sets the low and high level colors when using chroma keying
* \author	IM, b06623
* \param	DCU_Plane_t layer, Configured layer.
* \param	uint32_t max, High boundary for chroma keying.
* \param	uint32_t min, Low boundary for chroma keying.
* \return	void
* \todo
*/
void DCU_SetChroma(DCU_Plane_t layer, uint32_t max, uint32_t min)
{
#if 0
        /* Chroma setting */
	DCU.LAYER[ layer ].CTRLDESCL5.B.CKMAX_R		= (uint8_t)((0x00FF0000u & max)>>16u);				
	DCU.LAYER[ layer ].CTRLDESCL6.B.CKMIN_R		= (uint8_t)((0x00FF0000u & min)>>16u);				
	DCU.LAYER[ layer ].CTRLDESCL5.B.CKMAX_G		= (uint8_t)((0x0000FF00u & max)>>8u);				
	DCU.LAYER[ layer ].CTRLDESCL6.B.CKMIN_G		= (uint8_t)((0x0000FF00u & min)>>8u);				
	DCU.LAYER[ layer ].CTRLDESCL5.B.CKMAX_B		= (uint8_t)(0x000000FFu & max);		
	DCU.LAYER[ layer ].CTRLDESCL6.B.CKMIN_B		= (uint8_t)(0x000000FFu & min);			
#endif  
}

/************************** Private Functions *********************************************************************/

/**
* \brief	TX09_setup - Initializes a Hitachi display.
* \author	IM, b06623
* \param	uint32_t freq, frequency for initialization (from 16 to 64MHz)
* \return	void
* \todo
*/
void TX09_setup( uint32_t  freq )
{
#if 0
    uint32_t i;
    // Config port A as output (red & green)
    for(i=PA0;i<PB0;i++) SIU.PCR[i].R = 0x0600;	//Enable output buffer
	
     // Config port PG0..7 as output (blue)
    for(i=PG0;i<PG8;i++) SIU.PCR[i].R = 0x0600;	//Enable output buffer

    // Config port PG8..11 as output (control)
    for(i=PG8;i<PG12;i++) SIU.PCR[i].R = 0x0600;	//Enable output buffer

    SIU.PCR[PA14].B.SRC = 1;	/* Fast Slew Rate */
    SIU.PCR[PG6].B.SRC = 1;	/* Fast Slew Rate */

    DCU.DISP_SIZE.B.DELTA_Y = 320; // Y = 320
    DCU.DISP_SIZE.B.DELTA_X = 15; 	// X = 15 * 16 = 240
    DCU.HSYN_PARA.B.BP_H = 17;	// Horizontal back porch
    DCU.HSYN_PARA.B.PW_H = 5;	// Horizontal sync pulse
    DCU.HSYN_PARA.B.FP_H = 11;	// Horizontal front porch

    DCU.VSYN_PARA.B.BP_V = 4;	// Vertical back porch
    DCU.VSYN_PARA.B.PW_V = 1;	// Vertical sync pulse
    DCU.VSYN_PARA.B.FP_V = 0;	// Vertical front porch

    DCU.DIV_RATIO.R = (uint32_t)(freq/5.33)-1;		//Clock divider
    DCU.SYN_POL.R = 0x00000003; // Synchro neg.
#endif
}
 
/**
* \brief	TX09_setup - Initializes a Sharp display.
* \author	IM, b06623
* \param	uint32_t freq, frequency for initialization (from 16 to 64MHz)
* \return	void
* \todo
*/
void LQ043_setup( uint32_t	freq )
{
#if 0
	uint32_t i;
	
	for(i=PA0;i<PB0;i++) SIU.PCR[i].R = 0x0600;
	for(i=PG0;i<PG8;i++) SIU.PCR[i].R = 0x0600;
    	SIU.PCR[PG8].R = 0x0600;  	//Vsynch
    	SIU.PCR[PG9].R = 0x0600;	//Hsynch
    	SIU.PCR[PG10].R = 0x0003; 	//DE just pull-up - connected to display ON
    	SIU.PCR[PG11].R = 0x0600; 	//Pclk

	SIU.PCR[PA14].B.SRC = 1;	/* Fast Slew Rate */
	SIU.PCR[PG6].B.SRC = 1;		/* Fast Slew Rate */

	DCU.DISP_SIZE.B.DELTA_Y = 272u;	
	DCU.DISP_SIZE.B.DELTA_X = 30u;  								/*	X = 30 * 16 = 480							  */

	DCU.HSYN_PARA.B.BP_H	 = 2u;									/*	Horizontal back porch						  */
	DCU.HSYN_PARA.B.PW_H	 = 41u;  								/*	Horizontal sync pulse						  */
	DCU.HSYN_PARA.B.FP_H	 = 2u;									/*	Horizontal front porch						  */

	DCU.VSYN_PARA.B.BP_V	 = 2u;									/*	Vertical back porch  						  */
	DCU.VSYN_PARA.B.PW_V	 = 10u;  								/*	Vertical sync pulse  						  */
	DCU.VSYN_PARA.B.FP_V	 = 2u;									/*	Vertical front porch						  */
 
	DCU.DIV_RATIO.R = (uint32_t)(freq/8)-1;		
	DCU.SYN_POL.R		 = 0x00000003u;  						/*	Synchro neg.								  */
#endif
}


/**
* \brief	DCU_SetCallbackVSBLANK - Configures the VSBLANK callback interrupt
* \author	IM, b06623
* \param	DCU_CallbackType Callback, Callback used; NULL_PTR to turn it off.
* \return	void
* \todo
*/
void DCU_SetCallbackVSBLANK( DCU_CallbackType Callback )
{
#if 0
    if(Callback != NULL_PTR)
    {
	/* VIOLATION TO THE FOLLOWING RULE */
	/* [ MISRA 16.9 ] A function identifier shall only be used with either a preceding &, */
	/* or with a parenthesised parameter list, which may be empty. */

	/* Rationale: It is required to assign a values to this function that will be used as callback */
	DCU_CallbackVSBLANK = Callback;
	/* Enable/disable Vertical blanking interrupt */
	DCU.INT_MASK.B.M_VS_BLANK = 0u;
    }
    else
    {
	DCU.INT_MASK.B.M_VS_BLANK = 1u;
    }
#endif
}

/**
* \brief	DCU_SetCallbackLSBFVS - Configures the LSBFVS callback interrupt
* \author	IM, b06623
* \param	DCU_CallbackType Callback, Callback used; NULL_PTR to turn it off.
* \return	void
* \todo
*/
void DCU_SetCallbackLSBFVS( DCU_CallbackType Callback )
{
#if 0
    if(Callback != NULL_PTR)
    {
	/* VIOLATION TO THE FOLLOWING RULE */
	/* [ MISRA 16.9 ] A function identifier shall only be used with either a preceding &, */
	/* or with a parenthesised parameter list, which may be empty. */

	/* Rationale: It is required to assign a values to this function that will be used as callback */
	DCU_CallbackLSBFVS = Callback;
	/* Enable/disable lines before vertical sync interrupt */
	DCU.INT_MASK.B.M_LS_BF_VS  = 0u;
    }
    else
    {
	DCU.INT_MASK.B.M_LS_BF_VS  = 1u;
    }
#endif
}

/**
* \brief	DCU_SetCallbackVSYNC - Configures the VSYNC callback interrupt
* \author	IM, b06623
* \param	DCU_CallbackType Callback, Callback used; NULL_PTR to turn it off.
* \return	void
* \todo
*/
void DCU_SetCallbackVSYNC( DCU_CallbackType Callback )
{   
#if 0
    if(Callback != NULL_PTR)
    {
	/* VIOLATION TO THE FOLLOWING RULE */
	/* [ MISRA 16.9 ] A function identifier shall only be used with either a preceding &, */
	/* or with a parenthesised parameter list, which may be empty. */

	/* Rationale: It is required to assign a values to this function that will be used as callback */
	DCU_CallbackVSYNC = Callback;
	/* Enable/disable Vertical blanking interrupt */
	DCU.INT_MASK.B.M_VSYNC = 0u;
    }
    else
    {
	DCU.INT_MASK.B.M_VSYNC = 1u;
    }
#endif
}

/**
* \brief	DCU_SetCallbackProgDone - Configures the VSYNC callback interrupt
* \author	IM, b06623
* \param	DCU_CallbackType Callback, Callback used; NULL_PTR to turn it off.
* \return	void
* \todo
*/
void DCU_SetCallbackProgDone( DCU_CallbackType Callback )
{   
#if 0
    if(Callback != NULL_PTR)
    {
	/* VIOLATION TO THE FOLLOWING RULE */
	/* [ MISRA 16.9 ] A function identifier shall only be used with either a preceding &, */
	/* or with a parenthesised parameter list, which may be empty. */

	/* Rationale: It is required to assign a values to this function that will be used as callback */
	DCU_CallbackPROGD = Callback;
	/* Enable/disable Vertical blanking interrupt */
	DCU.INT_MASK.B.M_PROG_END = 0u;
    }
    else
    {
	DCU.INT_MASK.B.M_PROG_END = 1u;
    }
#endif
}

/* DCU VS_BLANK, LS_BF_VS,VSYNC */
void DCU_TIMING_ISR( void  )
{
#if 0
    if( DCU.INT_STATUS.B.LS_BF_VS != 0u )
    {
	DCU_TimingStatus = DCU_LSBFVS;
	/* VIOLATION TO THE FOLLOWING RULE */
	/* [ MISRA 16.9 ] A function identifier shall only be used with either a preceding &, */
	/* or with a parenthesised parameter list, which may be empty. */

	/* Rationale: It is required to assign a values to this function that will be used as callback */
	if (DCU_CallbackLSBFVS!= NULL_PTR)
	{
	    DCU_CallbackLSBFVS( );
	}
	DCU.INT_STATUS.R = 0x000004u;
    }
    if( DCU.INT_STATUS.B.VS_BLANK != 0u )
    {
	DCU_TimingStatus = DCU_VBLANK;
	/* VIOLATION TO THE FOLLOWING RULE */
	/* [ MISRA 16.9 ] A function identifier shall only be used with either a preceding &, */
	/* or with a parenthesised parameter list, which may be empty. */

	/* Rationale: It is required to assign a values to this function that will be used as callback */
	if (DCU_CallbackVSBLANK != NULL_PTR)
	{
	    DCU_CallbackVSBLANK( );
	}
	DCU.INT_STATUS.R = 0x000008u;
    }
    if( DCU.INT_STATUS.B.VSYNC != 0u )
    {
	DCU_TimingStatus = DCU_VSYNC;
	/* VIOLATION TO THE FOLLOWING RULE */
	/* [ MISRA 16.9 ] A function identifier shall only be used with either a preceding &, */
	/* or with a parenthesised parameter list, which may be empty. */

	/* Rationale: It is required to assign a values to this function that will be used as callback */
	if (DCU_CallbackVSYNC != NULL_PTR)
	{
	    DCU_CallbackVSYNC( );
	}
	DCU.INT_STATUS.R = 0x000001u;
    }
    
    if( DCU.INT_STATUS.B.PROG_END != 0u )
    {   
    	/* Rationale: It is required to assign a values to this function that will be used as callback */
		if (DCU_CallbackPROGD != NULL_PTR)
		{
	   		DCU_CallbackPROGD( );
		}
		DCU.INT_STATUS.R = 0x00000400u;
    }
#endif
}


