/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Type.h
 *        Config:  L21B_COM.dpa
 *   ECU-Project:  METER
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

#include "system.h"

/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/
typedef struct
{
  UINT8 sig_unit;
  UINT8 window;
} SIG_WIN_INFO_T;

typedef struct
{		  
   UINT32 crc_r;    /*!<Calculated CRC for red channel verification when en_crc = 1   */
   UINT32 crc_g;    /*!<Calculated CRC for green channel verification when en_crc = 1 */
   UINT32 crc_b;    /*!<Calculated CRC for blue channel verification when en_crc = 1  */
}SIG_WIN_CRC_RGB_T;

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

#endif /* _RTE_TYPE_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3408:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

*/
