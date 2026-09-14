/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  Crc.h                                                *
*  Module Short Name :  CRC_H                                                *
*  Description       :                                                       *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef CRC_H
#define CRC_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "Crc_Cfg.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define CRC_VERSION_INFO_API              STD_ON
/*Visteon does not have VENDOR_ID*/
# define CRC_VENDOR_ID                     0x0033U 
# define CRC_MODULE_ID                     (201U)
/*MISRA RULE 2.5 VIOLATION and MISRA RULE 8.9 VIOLATION: As per autosar standards SWS_Crc_00048 CRC_AR_RELEASE_REVISON_VERSION  is used in Crclib ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
# define CRC_AR_RELEASE_MAJOR_VERSION      (4u)
/*MISRA RULE 2.5 VIOLATION and MISRA RULE 8.9 VIOLATION: As per autosar standards SWS_Crc_00048 CRC_AR_RELEASE_REVISON_VERSION  is used in Crclib ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
# define CRC_AR_RELEASE_MINOR_VERSION      (3u)
/*MISRA RULE 2.5 VIOLATION and MISRA RULE 8.9 VIOLATION: As per autosar standards SWS_Crc_00048 CRC_AR_RELEASE_REVISON_VERSION  is used in Crclib ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
# define CRC_AR_RELEASE_REVISON_VERSION    (1u)

# define CRC_SW_MAJOR_VERSION              (1u)
# define CRC_SW_MINOR_VERSION              (0u)
# define CRC_SW_PATCH_VERSION              (23u)
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
void Crc_GetVersionInfo (Std_VersionInfoType * Versioninfo);

/*============================================================================
**
** Function Name    :   Crc_CalculateCRC8
**
** Visibility       :   Public
**
** Description      :   This function calculates and returns the 8 bit CRC  
**                      (8 bit SAE J1850)for the given number of data.
**
** Invocation       :   Whoever wants to calculate the 8 bit SAE J1850 CRC
**
** Inputs           :   Crc_DataPtr: Pointer to the data for which the CRC to be calculated
**                      Crc_Length: Number of bytes to be taken for calculation.
**                      Crc_StartValue8: CRC Start value, if this is a continuation of 
**                                       previous CRC calculation. Crc_IsFirstCall shall be 
**                                       FALSE for this to be considered.
**                      Crc_IsFirstCall: TRUE if this is the first call for CRC calculation. Start Value will be 0xFF
**                                       FALSE if this is a continuation of precious CRC calculation.
**
** Outputs          :   Calculated 8 bit CRC value
**
** Critical Section :   NA
**
**==========================================================================*/
#if (CRC_CALCULATECRC8_ENABLE == STD_ON)
uint8 Crc_CalculateCRC8(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8, boolean Crc_IsFirstCall);
#endif
/*============================================================================
**
** Function Name    :   Crc_CalculateCRC8H2F
**
** Visibility       :   Public
**
** Description      :   This function calculates and returns the 8 bit CRC  
**                      (8 bit with 0x2F polynomial)for the given number of data.
**
** Invocation       :   Whoever wants to calculate the 8 bit  CRC with 0x2F polynomial.
**
** Inputs           :   Crc_DataPtr: Pointer to the data for which the CRC to be calculated
**                      Crc_Length: Number of bytes to be taken for calculation.
**                      Crc_StartValue8: CRC Start value, if this is a continuation of 
**                                       previous CRC calculation. Crc_IsFirstCall shall be 
**                                       FALSE for this to be considered.
**                      Crc_IsFirstCall: TRUE if this is the first call for CRC calculation. Start Value will be 0xFF
**                                       FALSE if this is a continuation of precious CRC calculation.
**
** Outputs          :   Calculated 8 bit CRC value
**
** Critical Section :   NA
**
**==========================================================================*/
#if (CRC_CALCULATECRC8H2F_ENABLE == STD_ON)
uint8 Crc_CalculateCRC8H2F(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8, boolean Crc_IsFirstCall);
#endif
/*============================================================================
**
** Function Name    :   Crc_CalculateCRC16
**
** Visibility       :   Public
**
** Description      :   This function calculates and returns the 16 bit CRC  
**                      (16 bit with 0x1021 polynomial)for the given number of data.
**
** Invocation       :   Whoever wants to calculate the 16 bit CRC with 0x1021 polynomial.
**
** Inputs           :   Crc_DataPtr: Pointer to the data for which the CRC to be calculated
**                      Crc_Length: Number of bytes to be taken for calculation.
**                      Crc_StartValue16: CRC Start value, if this is a continuation of 
**                                       previous CRC calculation. Crc_IsFirstCall shall be 
**                                       FALSE for this to be considered.
**                      Crc_IsFirstCall: TRUE if this is the first call for CRC calculation. Start Value will be 0xFFFF.
**                                       FALSE if this is a continuation of precious CRC calculation.
**
** Outputs          :   Calculated 16 bit CRC value
**
** Critical Section :   NA
**
**==========================================================================*/
#if (CRC_CALCULATECRC16_ENABLE == STD_ON)
uint16 Crc_CalculateCRC16(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall);
#endif

/*============================================================================
**
** Function Name    :   Crc_CalculateCRC32
**
** Visibility       :   Public
**
** Description      :   This function calculates and returns the 32 bit CRC  
**                      (32 bit Ethernet IEEE-802 with 0x04C11DB7 polynomial) for the given number of data.
**
** Invocation       :   Whoever wants to calculate the 32 bit Ethernet IEEE-802 with 0x04C11DB7 polynomial CRC.
**
** Inputs           :   Crc_DataPtr: Pointer to the data for which the CRC to be calculated
**                      Crc_Length: Number of bytes to be taken for calculation.
**                      Crc_StartValue32: CRC Start value, if this is a continuation of 
**                                       previous CRC calculation. Crc_IsFirstCall shall be 
**                                       FALSE for this to be considered.
**                      Crc_IsFirstCall: TRUE if this is the first call for CRC calculation. Start Value will be 0xFFFFFFFF.
**                                       FALSE if this is a continuation of precious CRC calculation.
**
** Outputs          :   Calculated 32 bit CRC value
**
** Critical Section :   NA
**
**==========================================================================*/
#if (CRC_CALCULATECRC32_ENABLE == STD_ON)
uint32 Crc_CalculateCRC32(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall);
#endif
/*============================================================================
**
** Function Name    :   Crc_CalculateCRC32P4
**
** Visibility       :   Public
**
** Description      :   This function calculates and returns the 32 bit CRC  
**                      (32 bit CRC with 0xF4ACFB13 polynomial) for the given number of data.
**
** Invocation       :   Whoever wants to calculate the 32 bit CRC with 0xF4ACFB13 polynomial CRC.
**
** Inputs           :   Crc_DataPtr: Pointer to the data for which the CRC to be calculated
**                      Crc_Length: Number of bytes to be taken for calculation.
**                      Crc_StartValue32: CRC Start value, if this is a continuation of 
**                                       previous CRC calculation. Crc_IsFirstCall shall be 
**                                       FALSE for this to be considered.
**                      Crc_IsFirstCall: TRUE if this is the first call for CRC calculation. Start Value will be 0xFFFFFFFF.
**                                       FALSE if this is a continuation of precious CRC calculation.
**
** Outputs          :   Calculated 32 bit CRC value
**
** Critical Section :   NA
**
**==========================================================================*/
#if (CRC_CALCULATECRC32P4_ENABLE == STD_ON)
uint32 Crc_CalculateCRC32P4(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall);
#endif
/*============================================================================
**
** Function Name    :   Crc_CalculateCRC64
**
** Visibility       :   Public
**
** Description      :   This service makes a CRC64 calculation on Crc_Length data bytes, 
**                      using the polynomial 0x42F0E1EBA9EA3693.
**
** Invocation       :   Whoever wants to calculate the 64 bit CRC with 0x42F0E1EBA9EA3693 polynomial CRC.
**
** Inputs           :   Crc_DataPtr: Pointer to the data for which the CRC to be calculated
**                      Crc_Length: Number of bytes to be taken for calculation.
**                      Crc_StartValue64: CRC Start value, if this is a continuation of 
**                                       previous CRC calculation. Crc_IsFirstCall shall be 
**                                       FALSE for this to be considered.
**                      Crc_IsFirstCall: TRUE if this is the first call for CRC calculation. Start Value will be  0xFFFFFFFFFFFFFFFFh.
**                                       FALSE if this is a continuation of precious CRC calculation.
**
** Outputs          :   Calculated 64 bit CRC value
**
** Critical Section :   NA
**
**==========================================================================*/
#if (CRC_CALCULATECRC64_ENABLE == STD_ON)
uint64 Crc_CalculateCRC64(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint64 Crc_StartValue64, boolean Crc_IsFirstCall);
#endif
#endif
/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 30-Aug-2016
CDSID              : ssebast1
Traceability       : RTC #674918
Change Description : Initial Framework version of CRC
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 04-NOV-2019
CDSID              : snaray12
Traceability       : RTC #641186
Change Description : MISRA Warning fix CRC
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 19-May-2020
CDSID              : bbaskara
Traceability       : RTC #883468
Change Description : Updated Source file as per SSR
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 10-May-2022
CDSID              : dbalasub
Traceability       : RTC #1652961
Change Description : Coverity & MISRA warning analysis and fix
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 23-May-2022
CDSID              : eganesan
Traceability       : RTC #1668701
Change Description : Bsw General Requirement supported
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/


