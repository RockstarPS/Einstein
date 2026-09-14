/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2018. Visteon Corporation owns all rights to this work and
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
 ** Name:           SigMgrCdd.h
 **
 ** Description:    
 **                 
 **                 
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/

#ifndef SIGMGRCDD_H
#define SIGMGRCDD_H

#include "Rte_Type.h"
#include "SigIfCdd.h"

#ifdef SIGMGRCDD_C
	#define EXTERN_SIGMGRCDD
#else
	#define EXTERN_SIGMGRCDD extern
#endif

//=====================================================================================================================
// SIgMgr
//=====================================================================================================================

/* -------------- SIG unit  -------------- */
EXTERN_SIGMGRCDD void SigMgr_sig_init(void);      
/*!
\brief uninitializes the Sig unit
\retval void
*/
EXTERN_SIGMGRCDD void SigMgr_sig_deinit(void);

EXTERN_SIGMGRCDD void SigMgr_sig_task (void);

#if !(defined(GFX_USE_INFINEON_DRIVER) || defined(GFX_USE_TIDSS_DRIVER))
/*! 
\brief 	Eval Window status of Sig unit
\param p_sw_info pointer to 	SIG_WIN_INFO_T
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGMGRCDD uint32_t SigMgr_sig_get_win_status(SIG_WIN_INFO_T const * p_sw_info);
#endif

/*! \brief Get CRC value for red channel   
\param p_sw_info pointer to 	SIG_WIN_INFO_T
\retval CRC Value
*/
EXTERN_SIGMGRCDD void SigMgr_sig_get_win_crc_data(SIG_WIN_INFO_T const * p_sw_info, SIG_WIN_CRC_RGB_T * p_sw_crc_rgb);

EXTERN_SIGMGRCDD Std_ReturnType SigMgr_sig_stop_evaluation(uint8_t p_sig_unit);

//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
// C M S    R E V I S I O N    N O T E S
//---------------------------------------------------------------------------------------------------------------------
//
// For each change to this file, be sure to record:
// 1.  Who made the change and when the change was made.
// 2.  Why the change was made and the intended result.
//
// CMS Rev #        Date            By
// CMS Rev X.X      dd-mmm-yyyy     CDSID
//
//---------------------------------------------------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
#endif  //SIGMGRCDD_H




