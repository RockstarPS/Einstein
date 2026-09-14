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
 *        Config:  HyundaiSP2.dpa
 *   ECU-Project:  CLU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700619 for Visteon Corporation
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

# define Rte_TypeDef_SIG_WIN_CRC_RGB_T
typedef struct
{
  UInt32 crc_r;
  UInt32 crc_g;
  UInt32 crc_b;
} SIG_WIN_CRC_RGB_T;

# define Rte_TypeDef_SIG_WIN_INFO_T
typedef struct
{
  UInt8 sig_unit;
  UInt8 window;
} SIG_WIN_INFO_T;

# define Rte_TypeDef_SIG_WIN_SETUP_T
typedef struct
{
  UInt32 control;
  UInt16 winsx;
  UInt16 winsy;
  UInt16 winex;
  UInt16 winey;
  UInt32 crc_ref_r;
  UInt32 crc_ref_g;
  UInt32 crc_ref_b;
} SIG_WIN_SETUP_T;

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
