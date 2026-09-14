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
 *        Config:  Traveo2.dpa
 *   ECU-Project:  IPC7TFTQ5
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H
#include "system.h"



#define Os32msSafetyTask 0	/* use it as a index value */
#define  Rte_Ev_Sig_NewConfigReady   ((EventMaskType)128uLL)

typedef struct
{
  unsigned char sig_unit;
  unsigned char window;
} SIG_WIN_INFO_T;

typedef struct
{		  
   unsigned int crc_r;    /*!<Calculated CRC for red channel verification when en_crc = 1   */
   unsigned int crc_g;    /*!<Calculated CRC for green channel verification when en_crc = 1 */
   unsigned int crc_b;    /*!<Calculated CRC for blue channel verification when en_crc = 1  */
}SIG_WIN_CRC_RGB_T;

typedef struct
{
   unsigned int control;      /*!<Bit0 (EnEvalWin)-- 1: enable the window for crc calculation, 0: disable */
                        /*!<Bit1 (EnCRC)--1: enable crc verification, 0: no crc verification   */
                        /*!<Bit8 (AlphaMask0)  */
                        /*!<Bit9 (AlphaInv0)  */
                        /*!<Bit16 (EnLocalPanic)-- 1: enable panic mode to fill crc window with panic_rgba color, 0:disable*/
   unsigned short winsx;        /*!<CRC window start x-14bits*/
   unsigned short winsy;        /*!<CRC window start y-14bits*/
   unsigned short winex;		/*!<CRC window end x-14bits */
   unsigned short winey;		/*!<CRC window end y-14bits */
   unsigned int crc_ref_r;    /*!<Reference CRC for red channel verification when en_crc = 1   */
   unsigned int crc_ref_g;    /*!<Reference CRC for green channel verification when en_crc = 1 */
   unsigned int crc_ref_b;    /*!<Reference CRC for blue channel verification when en_crc = 1  */
}SIG_WIN_SETUP_T;

/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/


# define Rte_TypeDef_SInt16
typedef signed short int SInt16;

# define Rte_TypeDef_SInt32
typedef signed long SInt32;

# define Rte_TypeDef_UInt16
typedef unsigned short int UInt16;

# define Rte_TypeDef_UInt32
typedef unsigned long UInt32;

# define Rte_TypeDef_UInt8
typedef unsigned char UInt8;



#define E_OK 1
#define E_NOT_OK 0
#define NULL 0

typedef UINT16 Std_ReturnType;
typedef UINT16 EventMaskType;

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

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 7.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
