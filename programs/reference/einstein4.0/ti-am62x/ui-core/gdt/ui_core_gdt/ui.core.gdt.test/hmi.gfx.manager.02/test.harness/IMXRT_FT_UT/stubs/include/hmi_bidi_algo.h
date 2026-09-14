#ifndef HMI_BIDI_ALGO_H
#define HMI_BIDI_ALGO_H

#include "hmi_bidi_algo.cfg"
#if HMI_MAX_STRING_CHARS > 255
	typedef UINT16	u_bidi_flocal;
#else
	typedef UINT8	u_bidi_flocal;
#endif


/******************************************************************************
 *                        External Functions
 ******************************************************************************/
    
extern void bidi_process(HMI_CHAR * InStrRead , u_bidi_flocal fl_display_count_U16);

/******************************************************************************/

#endif/* HMI_BIDI_ALGO_H */ 
