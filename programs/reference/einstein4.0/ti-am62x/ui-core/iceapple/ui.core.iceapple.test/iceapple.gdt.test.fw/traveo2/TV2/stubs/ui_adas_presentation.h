/*============================================================================
**                                                                            
**                     CONFIDENTIAL VISTEON CORPORATION                       
**                                                                            
** This is an unpublished work of authorship, which contains trade secrets,   
** created in 2022. Visteon Corporation owns all rights to this work and      
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
**============================================================================
**                                                                            
** File Name            :   ui_digital_speed_presentation.h                 
** Description          :   Digital speed presentation macros and function prototypes                                                        
** Author               :   bhariha1                                                                                           
** Organization         :   Driver Information Software Section,                       
**                          DI Core Engineering Department                             
**                                                                            
*******************************************************************************/
/******************************************************************************
** Compiler Name        :   GHS
** Target Processor     :   Traveo 2
*******************************************************************************/

#ifndef UI_DIGITAL_SPEED_PRESENTATION_H_
#define UI_DIGITAL_SPEED_PRESENTATION_H_

/*****************************************************************************
 *                                 Global variables declaration              *
 *****************************************************************************/

/******************************************************************************
 *                                 Macro Definitions                          *
 ******************************************************************************/
#define UI_INVALID_INDEX        (UINT32)255

#define UI_UINT16_VAL_INIT		(UINT16)0
#define UI_UINT8_VAL_INIT		(UINT8)0

/*****************************************************************************
 *                                 Global Function Prototypes                *
 *****************************************************************************/

extern void ui_digital_speed_presentation_update(void);

#endif

/******************************************************************************
 *                                 Revision History                           *
 ******************************************************************************/
/*-----------------------------------------------------------------------------
Date                : 20-05-2022
CDSID               : bhariha1
Traceability        : 1667381: Toyota 38xD: [HMI] Setting up Initial files for 38XD HMI - Part 1
Change Description  : Initial Version
------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date                : 06-06-2022
CDSID               : bhariha1
Traceability        : Task 1679989: Toyota 38xD: [HMI] Setting up Initial files for 
					  38XD HMI - Code Delivery (Phase 2)
Change Description  : Change of name prefix
------------------------------------------------------------------------------*/

/* End of File */
