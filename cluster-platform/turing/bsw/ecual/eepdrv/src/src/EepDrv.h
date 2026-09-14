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
#ifndef EepDrv_H
#define EepDrv_H
/*****************************************************************************
*  File Name         :  Eep.h                                                *
*  Module Short Name :  EepDrv                                               *
*  Description       :  This file contains declarations and includes for     *
*                       the External EEPROM Device based on I2C              *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  I2c Based External EEPROM device with                  *
* 						CAT24C04/08/16/32 series
*                                                                            *
******************************************************************************/
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "EepDrv_Types.h"
#include "EepDrv_Cfg.h"
#include "MemIf_Types.h"
#include "MemLib.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
//EEPROM Type Selection
#define	BIG_EEPROM                          1   //Covers EEPROM size for 32K
#define	SMALL_EEPROM                        2   //Covers EEPROM size from 4K to 16K

/*---------------  EEPROM Error Code Configurations  -----------------*/
#define EEPDRV_E_INIT_FAILED           0X10
#define EEPDRV_E_PARAM_ADDRESS         0X11
#define EEPDRV_E_PARAM_DATA            0X12
#define EEPDRV_E_PARAM_LENGTH          0X13
#define EEPDRV_E_UNINIT                0X20
#define EEPDRV_E_BUSY                  0X21
#define EEPDRV_E_PARAM_POINTER         0X23

#define EEPDRV_READ_API                0x02
#define EEPDRV_WRITE_API               0x03
#define EEPDRV_ERASE_API               0x04
#define EEPDRV_COMPARE_API             0x05


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
*                   Functions                                                *
******************************************************************************/

/*============================================================================
**
** Function Name    :   EepDrv_Init
**
** Visibility       :   Public
**
** Description      :   Service for EEPROM initialization
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   ConfigPtr
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
extern void EepDrv_Init(const EepDrv_ConfigType* ConfigPtr);
/*============================================================================
**
** Function Name    :   EepDrv_SetMode
**
** Visibility       :   Public
**
** Description      :   Service used to switch between normal and fast Eep acces
**
** Invocation       :   Function is called in task context
**
** Inputs           :   Mode - The EEPROM Opearation Mode that has to be set
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
extern void EepDrv_SetMode(MemIf_ModeType Mode);
/*============================================================================
**
** Function Name    :   EepDrv_Read
**
** Visibility       :   Public
**
** Description      :   Service reads a data block from the Eeprom
**
** Invocation       :   Function is called in task context
**
** Inputs           :   EepAddress    Address offset in Eeprom
**                      Length        Number of bytes to read
**
** Outputs          :   DataBufferPtr Pointer to destination data buffer in ram
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType EepDrv_Read(EepDrv_AddressType EepromAddress, uint8* DataBufferPtr,EepDrv_LengthType Length);
/*============================================================================
**
** Function Name    :   EepDrv_Write
**
** Visibility       :   Public
**
** Description      :   Service writes a data block to the Eeprom
**
** Invocation       :   Function is called in task context
**
** Inputs           :   EepAddress    Address offset in Eeprom
**                      DataBufferPtr Pointer to destination data buffer in ram
**                      Length        Number of bytes to write
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType EepDrv_Write(EepDrv_AddressType EepromAddress,const uint8* DataBufferPtr,EepDrv_LengthType Length);
/*============================================================================
**
** Function Name    :   EepDrv_Erase
**
** Visibility       :   Public
**
** Description      :   Service erases a data block of the Eep
**
** Invocation       :   Function is called in task context
**
** Inputs           :   EepAddress    Address offset in Eeprom
**                      Length        Number of bytes to write
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType EepDrv_Erase(EepDrv_AddressType EepromAddress, EepDrv_LengthType Length);
/*============================================================================
**
** Function Name    :   EepDrv_Compare
**
** Visibility       :   Public
**
** Description      :   Service compares an Eep data block with a data block in the ram
**
** Invocation       :   Function is called in task context
**
** Inputs           :   EepAddress    Address offset in Eeprom
**                      DataBufferPtr Pointer to destination data buffer in ram
**                      Length        Number of bytes to read
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType EepDrv_Compare(EepDrv_AddressType EepromAddress,const uint8* DataBufferPtr,EepDrv_LengthType Length);
/*============================================================================
**
** Function Name    :   EepDrv_Cancel
**
** Visibility       :   Public
**
** Description      :   Dummy API to comply with mandatory interfaces of EepDriver
**                      Autosar4.2.1
**
** Invocation       :   Should not be invoked as this functionality is not supported
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
extern void EepDrv_Cancel (void);
/*============================================================================
**
** Function Name    :   EepDrv_MainFunction
**
** Visibility       :   Public
**
** Description      :   Service to perform the processing of the
**                      EEPROM jobs (read/write/erase/compare).
**
** Invocation       :   Function is called cyclically
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
extern void EepDrv_MainFunction (void);
/*============================================================================
**
** Function Name    :   EepDrv_GetStatus
**
** Visibility       :   Public
**
** Description      :   Service returns the status of the Eeprom driver
**
** Invocation       :   Function is called in task context
**
** Inputs           :   None
**
** Outputs          :   MemIf_StatusType:   status of the driver
**
** Critical Section :
**
**==========================================================================*/
extern MemIf_StatusType EepDrv_GetStatus(void);
/*============================================================================
**
** Function Name    :   EepDrv_GetJobResult
**
** Visibility       :   Public
**
** Description      :   Service returns the result of the last accepted job,
**                      as long as no new job is accepted.
**
** Invocation       :   Function is called in task context
**
** Inputs           :   None
**
** Outputs          :   MemIf_JobResultType:    result of the last accepted Eeprom Job
**
** Critical Section :
**
**==========================================================================*/
extern MemIf_JobResultType EepDrv_GetJobResult(void);


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
Date               : 23-Nov-2015
CDSID              : ssukuma1
Traceability       : RTC #464657 EepDrv - framework for external EEPROM
Change Description : Initial Framework version of EepDrv
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 15-Feb-2016
CDSID              : ssukuma1
Traceability       : RTC #514278 EepDrv - Ea Payload data read error (defect)
Change Description : EepDrv Page Write changes for page boundary management
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/

