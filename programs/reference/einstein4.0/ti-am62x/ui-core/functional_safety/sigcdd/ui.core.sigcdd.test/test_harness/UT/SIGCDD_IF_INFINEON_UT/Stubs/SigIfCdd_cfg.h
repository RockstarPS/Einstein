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
 ** Name:           SigIfCdd_cfg.h
 **
 ** Description:    This cfg file is used to configure the static items of Signature unit.
 **                 The static items are
 **                 1. Input for Signature unit
 **                 2. Panic Colour
 **                 3. Error Threshold Value
 **                 4. Error Threshold Reset Value
 **
 ** Organization:   User Experience COC, Visteon.
 **
 **============================================================================
 **
 **==========================================================================*/
#ifndef SIG_IF_CDD_CFG_H
#define SIG_IF_CDD_CFG_H
/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

#define GFX_USE_INFINEON_DRIVER
/*
Configure the macro SIGNATURE_UNITS_TO_USE as below.
Define 
0 for SIGNATURE_UNITS_TO_USE if SigUnit 0 to use.
1 for SIGNATURE_UNITS_TO_USE if SigUnit 1 to use.
2 for SIGNATURE_UNITS_TO_USE if SigUnit 0 and 1 to use.
*/

#define SIGNATURE_UNITS_TO_USE  0 /*Cypress has 2 Signature Units*/
/*
Number of frames with signature violation before StsSigError is set for an evaluation window. 
These frames do not need to be consecutive. 
0 means that each frame with violation will set the status. 
The internal counter compared against this threshold is reset when 'ErrThreshReset' 
consecutive frames without signature violation occur.
The valid range is 0-255.
*/
#define SIG0_ERROR_THRESHOLD_VALUE              (UINT8)0
#define SIG1_ERROR_THRESHOLD_VALUE              (UINT8)0

/*
Number of consecutive frames without signature violation before StsSigError is reset for an evaluation window.
0 means that each frame without violation will reset the status. 
The internal counter compared against this threshold is reset with each frame that has violation.
The valid range is 0-255.
*/
#define SIG0_ERROR_THRESHOLD_RESET_VALUE        (UINT8)0
#define SIG1_ERROR_THRESHOLD_RESET_VALUE        (UINT8)0

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
typedef struct
{		  
   UINT8  source;          /*!< Whether ihe input is frame_gen output or Gamma Correction output or Dither output */
   UINT8  error_threshold; /*!<number of error frames (need not be consecutive) before crc error flag is set */
   UINT8  reset_threshold; /*!<number of consecutive frames with no crc error, to clear the error flag       */
   UINT8  unused;          /*!<For padding */
   UINT32 panic_rgba;      /*!<RGBA color value that will be filled in entire CRC window incase of error     */
}SIG_SETUP_T;

/*
SIG_WIN_SETUP_T is required for the driver API as well as in the application code to pass the win configuration.
If it's not defined in RTE/Application code, this can be un commented here
*/
#if 0
typedef struct
{
  UINT32 control;      /*!<Bit0 (EnEvalWin)-- 1: enable the window for crc calculation, 0: disable */
                       /*!<Bit1 (EnCRC)--1: enable crc verification, 0: no crc verification   */
                       /*!<Bit8 (AlphaMask0)  */
                       /*!<Bit9 (AlphaInv0)  */
                       /*!<Bit16 (EnLocalPanic)-- 1: enable panic mode to fill crc window with panic_rgba color, 0:disable*/
  UINT16 winsx;        /*!<CRC window start x-14bits*/
  UINT16 winsy;        /*!<CRC window start y-14bits*/
  UINT16 winex;		/*!<CRC window end x-14bits */
  UINT16 winey;		/*!<CRC window end y-14bits */
  UINT32 crc_ref_r;    /*!<Reference CRC for red channel verification when en_crc = 1   */
  UINT32 crc_ref_g;    /*!<Reference CRC for green channel verification when en_crc = 1 */
  UINT32 crc_ref_b;    /*!<Reference CRC for blue channel verification when en_crc = 1  */
}SIG_WIN_SETUP_T;
#endif



#define SIG_ENABLE_EVWIN       ((UINT32)0x01)         /*!<Bitmask for EnEvalWin)*/
#define SIG_ENABLE_ALPHAMASK   ((UINT32)0x100)        /*!<Bitmask for Alphamask*/


/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/


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
