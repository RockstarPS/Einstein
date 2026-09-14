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
#define _RTE_TYPE_H
#include "system.h"

#define Os32msSafetyTask                0	/* use it as a index value */

/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

#define E_OK 1
#define E_NOT_OK 0
#define NULL 0

typedef UINT8 Std_ReturnType;
typedef UINT16 EventMaskType;

#ifndef Rte_TypeDef_SIG_WIN_SETUP_T
#define Rte_TypeDef_SIG_WIN_SETUP_T
typedef struct
{
  UINT32 control;       /*!<Bit0 (EnEvalWin)    1: Enable Safety Window, 0: Disable Safety Window */
  UINT16 winsx;         /*!<CRC window start x-14bits */
  UINT16 winsy;         /*!<CRC window start y-14bits */
  UINT16 winex;		    /*!<CRC window end x-14bits */
  UINT16 winey;		    /*!<CRC window end y-14bits */
  UINT32 ref_crc;       /*!<Reference CRC */
}SIG_WIN_SETUP_T;
#endif

#ifndef Rte_TypeDef_SIG_WIN_INFO_T
#define Rte_TypeDef_SIG_WIN_INFO_T
typedef struct
{
  UINT8 sig_unit;
  UINT8 window;
} SIG_WIN_INFO_T;
#endif

#ifndef Rte_TypeDef_SIG_WIN_CRC_RGB_T
#define Rte_TypeDef_SIG_WIN_CRC_RGB_T
typedef struct
{		  
   UINT32 crc;    
}SIG_WIN_CRC_RGB_T;
#endif

#endif /* _RTE_TYPE_H */


