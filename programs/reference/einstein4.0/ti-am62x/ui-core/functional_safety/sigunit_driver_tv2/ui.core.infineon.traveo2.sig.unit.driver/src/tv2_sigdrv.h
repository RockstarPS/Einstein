/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2021. Visteon Corporation owns all rights to this work and
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
 ** Name:           tv2_sigdrv.h
 **
 ** Description:    This module will be useful to Read/Write the Signature
 **                 Unit related registers. 
 **
 ** Organization:   User Experience COC, Visteon.
 **
 **============================================================================
 **
 **==========================================================================*/

/**
 * @file tv2_sigdrv.h
 * @brief Signature unit driver for traveo2.
 */

/// \mainpage Traveo2 Signature Unit Driver API documentation
/// \section intro_sec Introduction
/// Signature unit driver for traveo2. Provides interfaces for interaction with Traveo2 Signature Unit Peripheral


#ifndef TV2_SIGDRV_H
#define TV2_SIGDRV_H

#ifdef TV2_SIGDRV_C
	#define EXTERN_SIGDRV
#else
	#define EXTERN_SIGDRV extern
#endif

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include <stdint.h>
#include "tv2_sigdrv_cfg.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
typedef struct
{		  
   uint8_t  source;          /*!< Whether ihe input is frame_gen output or Gamma Correction output or Dither output */
   uint8_t  error_threshold; /*!<number of error frames (need not be consecutive) before crc error flag is set */
   uint8_t  reset_threshold; /*!<number of consecutive frames with no crc error, to clear the error flag       */
   uint8_t  unused;          /*!<For padding */
   uint32_t panic_rgba;      /*!<RGBA color value that will be filled in entire CRC window incase of error     */
}SIG_SETUP_T;

#define SIG_SOURCE_MASK        ((uint32_t)0x03)         /*!<Bitmask for Source)*/
#define SIG_ENABLE_EVWIN       ((uint32_t)0x01)         /*!<Bitmask for EnEvalWin)*/
#define SIG_ENABLE_CRC         ((uint32_t)0x02)         /*!<Bitmask for EnCRC*/
#define SIG_ENABLE_ALPHAMASK   ((uint32_t)0x100)        /*!<Bitmask for Alphamask*/
#define SIG_ENABLE_ALPHAINV    ((uint32_t)0x200)        /*!<Bitmask for AlphaInv*/
#define SIG_ENABLE_LOCALPANIC  ((uint32_t)0x10000)      /*!<Bitmask for EnLocalPanic*/
#define SIG_PANIC_COLOR_MASK   ((uint32_t)0xFFFFFF80)   /*!< Panic Colour Register is 25bits from MSB */
#define SIG_WIN_CORDINATE_MASK ((uint16_t)0x3FFF)       /*!< 14LSBs*/
#define SIG_IDLE_STATUS_MASK   ((uint32_t)0x00100000)   /*!<Bitmask for Idle status*/
#define SIG_WIN_STATUS_MASK    ((uint32_t)0xFF)         /* LSB 8 bits indicates signature error status of a windows */
#define SIG_DISABLE_EVWIN      ((uint32_t)0xFFFFFFFE)   /*!<Bitmask to disable EvalWin)*/
#define SIG_STSSIGVALID        ((uint32_t)0x10000)

#define SIG_WIN0_BIT    ((uint8_t)0x01)
#define SIG_WIN1_BIT    ((uint8_t)0x02)
#define SIG_WIN2_BIT    ((uint8_t)0x04)
#define SIG_WIN3_BIT    ((uint8_t)0x08)
#define SIG_WIN4_BIT    ((uint8_t)0x10)
#define SIG_WIN5_BIT    ((uint8_t)0x20)
#define SIG_WIN6_BIT    ((uint8_t)0x40)
#define SIG_WIN7_BIT    ((uint8_t)0x80)
/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

#if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
/* -------------- SIG0 unit  -------------- */
/*
** Configuration APIs. To be called with in a unlock() lock() pair for proper operation
*/
/*!\fn void iris_sigdrv_sig0_unlock(void)
   \brief unlock Sig unit#0 for writing 
   \param void
   \retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_unlock(void);
/*!
\brief locks Sig unit#0 from unintended writing 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_lock(void);
/*!
\brief initializes the Sig unit#0
\param p_setup pointer to SIG_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_initialize(SIG_SETUP_T const * const p_setup);
/*!
\brief uninitializes the Sig unit#0
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_uninitialize(void); 
/*!
\brief Sets the measurement mode as Periodic measurement for Signature unit #0
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_set_cnt_mode(void); 

/*!
\brief Clears the Periodic measurement for Signature unit #1
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_clear_cnt_mode(void);

/*! 
\brief 	Eval Window status of Sig unit 0
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win_status(void);
/*! 
\brief trigger a load requst for win0 confifurations of Sig unit#0
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_ldcfg_win0(void);
/*! 
\brief programs the win0 configurations in to shadow registers of Sig unit#0
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_setup_win0(SIG_WIN_SETUP_T const * const p_swconf);

/*
** Inspection APIs (neednot be invoked with in unlock() lock() pair)
*/
/*! 
\brief 	Eval Window0 status of Sig unit#0
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win0_status(void); 
/*! \brief Get CRC value for red channel   
\param void
\retval CRC Value for window 0
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win0_crc_r(void);  
/*! \brief Get CRC value for green channel 
\param void
\retval CRC Value for window 0
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win0_crc_g(void);  
/*! \brief Get CRC value for blue channel  
\param void
\retval CRC Value for window 0
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win0_crc_b(void);  
/*! \brief trigger a load request for win1 confifurations 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_ldcfg_win1(void);
/*! \brief programs the win1 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_setup_win1(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window1 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win1_status(void);
/*! \brief Get CRC value for red channel   
\param void
\retval CRC Value for window 1
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win1_crc_r(void);
/*! \brief Get CRC value for green channel 
\param void
\retval CRC Value for window 1
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win1_crc_g(void);
/*! \brief Get CRC value for blue channel  
\param void
\retval CRC Value for window 1
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win1_crc_b(void);
/*! \brief trigger a load request for win1 confifurations 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_ldcfg_win2(void);
/*! \brief programs the win2 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_setup_win2(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window2 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win2_status(void);
/*! \brief CRC value for red channel   
\param void
\retval CRC Value for window 2
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win2_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval CRC Value for window 2
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win2_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval CRC Value for window 2
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win2_crc_b(void);
/*! \brief trigger a load request for win3 confifurations 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_ldcfg_win3(void);
/*! \brief programs the win3 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_setup_win3(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window3 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win3_status(void);
/*! \brief CRC value for red channel   
\param void
\retval CRC Value for window 3
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win3_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval CRC Value for window 3
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win3_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval CRC Value for window 3
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win3_crc_b(void);
/*! \brief trigger a load request for win4 confifurations 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_ldcfg_win4(void);
/*! \brief programs the win4 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_setup_win4(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window4 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win4_status(void);
/*! \brief CRC value for red channel   
\param void
\retval CRC Value for window 4
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win4_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval CRC Value for window 4
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win4_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval CRC Value for window 4
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win4_crc_b(void);
/*! \brief trigger a load request for win5 confifurations 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_ldcfg_win5(void);
/*! \brief programs the win5 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_setup_win5(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window5 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win5_status(void);
/*! \brief CRC value for red channel   
\param void
\retval CRC Value for window 5
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win5_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval CRC Value for window 5
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win5_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval CRC Value for window 5
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win5_crc_b(void);
/*! \brief trigger a load requst for win6 confifurations 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_ldcfg_win6(void);
/*! \brief programs the win6 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_setup_win6(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window6 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win6_status(void);
/*! \brief CRC value for red channel   
\param void
\retval CRC Value for window 6
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win6_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval CRC Value for window 6
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win6_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval CRC Value for window 6
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win6_crc_b(void);
/*! \brief trigger a load requst for win7 confifurations 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_ldcfg_win7(void);
/*! \brief programs the win7 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig0_setup_win7(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window7 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win7_status(void);
/*! \brief CRC value for red channel   
\param void
\retval CRC Value for window 7
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win7_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval CRC Value for window 7
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win7_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval CRC Value for window 7
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig0_get_win7_crc_b(void);

#endif

#if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)

/* -------------- SIG1 unit  -------------- */
/*
** Configuration APIs. To be called with in a unlock() lock() pair for proper operation
*/
/*!\fn void iris_sigdrv_sig1_unlock(void)
   \brief unlock sig unit for writing 
   \param void
   \retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_unlock(void);
/*!
\brief locks sig unit from unintended writing 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_lock(void);
/*!
\brief initializes the signature unit 
\param p_setup pointer to SIG_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_initialize(SIG_SETUP_T const * const p_setup);
/*!
\brief uninitializes the Signature unit #1
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_uninitialize(void);
/*!
\brief Sets the measurement mode as Periodic measurement for Signature unit #1
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_set_cnt_mode(void); 

/*!
\brief Clears the Periodic measurement for Signature unit #1
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_clear_cnt_mode(void);


/*! 
\brief 	Eval Window status of Sig unit 1
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win_status(void);
/*! \brief programs the win0 of Sig unit#1 configurations in to shadow registers 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_ldcfg_win0(void);
/*! \brief programs the win0 of Sig unit#1 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_setup_win0(SIG_WIN_SETUP_T const * const p_swconf);
/*
** Inspection APIs (neednot be invoked with in unlock() lock() pair)
*/
/*! \brief 	Eval Window0 of Sig unit#1 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win0_status(void);
/*! \brief CRC value for red channel   
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win0_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win0_crc_g(void);  
/*! \brief CRC value for blue channel  
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win0_crc_b(void);
/*! \brief programs the win1 of Sig unit#1 configurations in to shadow registers 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_ldcfg_win1(void);
/*! \brief programs the win1 of Sig unit#1 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_setup_win1(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window1 of Sig unit#1 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win1_status(void);
/*! \brief CRC value for red channel   
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win1_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win1_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win1_crc_b(void);
/*! \brief programs the win2 of Sig unit#1 configurations in to shadow registers 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_ldcfg_win2(void);
/*! \brief programs the win2 of Sig unit#1 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_setup_win2(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window2 of Sig unit#1 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win2_status(void);
/*! \brief CRC value for red channel   
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win2_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win2_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win2_crc_b(void);
/*! \brief programs the win3 of Sig unit#1 configurations in to shadow registers 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_ldcfg_win3(void);
/*! \brief programs the win3 of Sig unit#1 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_setup_win3(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window3 of Sig unit#1 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win3_status(void);
/*! \brief CRC value for red channel   
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win3_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win3_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win3_crc_b(void);
/*! \brief programs the win4 of Sig unit#1 configurations in to shadow registers 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_ldcfg_win4(void);
/*! \brief programs the win4 of Sig unit#1 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_setup_win4(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window4 of Sig unit#1 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win4_status(void);
/*! \brief CRC value for red channel   
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win4_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win4_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win4_crc_b(void);
/*! \brief programs the win5 of Sig unit#1 configurations in to shadow registers 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_ldcfg_win5(void);
/*! \brief programs the win5 of Sig unit#1 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_setup_win5(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window5 of Sig unit#1 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win5_status(void);
/*! \brief CRC value for red channel   
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win5_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win5_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win5_crc_b(void);
/*! \brief programs the win6 of Sig unit#1 configurations in to shadow registers 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_ldcfg_win6(void);
/*! \brief programs the win6 of Sig unit#1 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_setup_win6(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window6 of Sig unit#1 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win6_status(void);
/*! \brief CRC value for red channel   
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win6_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win6_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win6_crc_b(void);
/*! \brief programs the win7 of Sig unit#1 configurations in to shadow registers 
\param void
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_ldcfg_win7(void);
/*! \brief programs the win7 of Sig unit#1 configurations in to shadow registers 
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
EXTERN_SIGDRV void iris_sigdrv_sig1_setup_win7(SIG_WIN_SETUP_T const * const p_swconf);
/*! \brief 	Eval Window7 of Sig unit#1 status
\param void
\retval non zero if there is a CRC error, 0 when no error 
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win7_status(void);
/*! \brief CRC value for red channel   
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win7_crc_r(void);
/*! \brief CRC value for green channel 
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win7_crc_g(void);
/*! \brief CRC value for blue channel  
\param void
\retval void
*/
EXTERN_SIGDRV uint32_t iris_sigdrv_sig1_get_win7_crc_b(void);
#endif

#ifdef  __cplusplus
}
#endif
/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**

**
**==========================================================================*/

/* end of file =============================================================*/
#endif
