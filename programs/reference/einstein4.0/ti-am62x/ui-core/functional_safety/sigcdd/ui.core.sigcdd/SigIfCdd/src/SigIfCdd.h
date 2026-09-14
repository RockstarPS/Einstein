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
 ** Name:           SigIfCdd.h
 **
 ** Description:     This hardware abstraction layer of the Signature CDD.
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/

#ifndef SIGIFCDD_H
#define SIGIFCDD_H

#include "Rte_Type.h"
#include "SigIfCdd_cfg.h"

#if defined(GFX_USE_TIDSS_DRIVER)
#include "ti_drivers_config.h"
#endif

#ifdef SIGIFCDD_C
#define EXTERN_SIGIFCDD
#else
#define EXTERN_SIGIFCDD extern
#endif

/* Signature units Instance ID */
#define SIG_UNIT0           (0U)
#define SIG_UNIT1           (1U)

/* Maximum Signature units supported */
#define MAX_SIG_UNITS       (2U)

/* Evaluation windows Instance ID */
#define WINDOW0             (0U)
#define WINDOW1             (1U)
#define WINDOW2             (2U)
#define WINDOW3             (3U)
#define WINDOW4             (4U)
#define WINDOW5             (5U)
#define WINDOW6             (6U)
#define WINDOW7             (7U)

/* Maximum Evaluation windows supported */
#ifdef GFX_USE_TIDSS_DRIVER

#if (CONFIG_DSS_NUM_SAFETY_REGIONS > 4)
#define MAX_WINDOWS                 (4U)
#else
#define MAX_WINDOWS                 CONFIG_DSS_NUM_SAFETY_REGIONS
#endif

#else
#define MAX_WINDOWS                 (8U)
#endif

#ifndef SIGCDD_UNUSED_VAR
#define SIGCDD_UNUSED_VAR(arg)          (void)arg
#endif

#ifdef GFX_USE_INFINEON_DRIVER

#define SIG_ENABLE_EVWIN       ((uint32_t)0x01)         /* Bitmask for EnEvalWin */
#define SIG_ENABLE_ALPHAMASK   ((uint32_t)0x100)        /* Bitmask for Alphamask */

#elif defined(GFX_USE_TIDSS_DRIVER)

#define SIG_EV_WIN_DISABLED     (0x00U)             /* Signature Evaluation window is disabled */
#define SIG_EV_WIN_ENABLED      (0x01U)             /* Signature Evaluation window is enabled */
#define SIG_EV_WIN_TYPE_MASK    (0x30U)             /* Signature Evaluation window Type Mask */
#define SIG_EV_WIN_VID          (0x10U)             /* Signature Evaluation window @ Video Pipeline (Pre Blending)*/
#define SIG_EV_WIN_VIDL         (0x20U)             /* Signature Evaluation window @ Video Pipeline Lite (Pre Blending) */
#define SIG_EV_WIN_VP           (0x30U)             /* Signature Evaluation window @ Video Port (Post Blending) */
#define SIG_EV_WIN_INVALID      (0x00U)             /* Signature Evaluation window type invalid configuration */

#endif

typedef enum
{
 E_OK_t,
 E_NOT_OK_t 
}Std_ReturnType_t;


/* -------------- SIG unit  -------------- */
EXTERN_SIGIFCDD void SigIf_sig_init(void);      
/*!
\brief uninitializes the Sig unit
\param uint8_t p_sig_unit --> signature unit value
\retval void
*/
EXTERN_SIGIFCDD void SigIf_sig_deinit(void);
/*
** To setup/configure the evalution windows
*/
EXTERN_SIGIFCDD Std_ReturnType_t SigIf_sig_set_ev_window(SIG_WIN_SETUP_T const *EvWindow, uint8_t p_sig_unit,  uint8_t p_window);

/*!
\brief programs the win configurations in to shadow registers of Sig unit
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\param p_sig_unit sigunit to configure
\param p_window evaluation window id
\retval void
*/
EXTERN_SIGIFCDD void SigIf_sig_setup_win(SIG_WIN_SETUP_T const * const p_swconf, uint8_t p_sig_unit, uint8_t p_window);

#if !(defined(GFX_USE_INFINEON_DRIVER) || defined(GFX_USE_TIDSS_DRIVER))
/*!
\brief trigger a load requst for window confifurations of Sig unit
\param p_sig_unit signature unit id to trigger the load request
\param p_window evaluation window id
\retval void
*/
EXTERN_SIGIFCDD void SigIf_sig_ldcfg_win(uint8_t p_sig_unit, uint8_t p_window);
#endif

/*
** Inspection APIs (neednot be invoked with in unlock() lock() pair)
*/
#if !(defined(GFX_USE_INFINEON_DRIVER) || defined(GFX_USE_TIDSS_DRIVER))
/*!
\brief 	Eval Window status of Sig unit
\param p_sw_info pointer to 	SIG_WIN_INFO_T
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGIFCDD uint32_t SigIf_sig_get_win_status(SIG_WIN_INFO_T const * const p_sw_info); 
#endif

#ifdef GFX_USE_INFINEON_DRIVER
EXTERN_SIGIFCDD uint8_t SigIf_sig_get_evaluation_status(uint8_t p_sig_unit);
#endif

#ifndef GFX_USE_TIDSS_DRIVER
/*!
\brief 	Eval Window status of Sig unit
\param p_sw_info pointer to 	SIG_WIN_INFO_T
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGIFCDD uint32_t SigIf_sig_get_windows_status(uint8_t p_sig_unit);
#endif

/*! \brief Get CRC value for red channel   
\param p_sw_info pointer to 	SIG_WIN_INFO_T
\retval p_sw_crc_rgb - CRC Value
*/
EXTERN_SIGIFCDD void SigIf_sig_get_win_crc_data(SIG_WIN_INFO_T const * p_sw_info, SIG_WIN_CRC_RGB_T * p_sw_crc_rgb);

/*! \brief Stops the evaluation
\param p_sig_unit signature unit id to stop the evaluation
\retval p_sw_crc_rgb - CRC Value
*/
EXTERN_SIGIFCDD void SigIf_sig_stop_evaluation(uint8_t p_sig_unit);

/*! \brief Stops the evaluation
\param p_sig_unit commit the changes into the driver
\retval p_sig_unit - signature unit id to trigger the load request
*/
#ifdef GFX_USE_INFINEON_DRIVER
EXTERN_SIGIFCDD uint8_t SigIf_sig_driver_commit(uint8_t p_sig_unit);
EXTERN_SIGIFCDD void SigIf_sig_driver_monitoring(void);
#endif
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
#endif  //SIGIFCDD_H

