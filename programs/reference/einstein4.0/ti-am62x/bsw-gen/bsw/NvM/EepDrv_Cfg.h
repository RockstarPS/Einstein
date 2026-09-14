/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  EepDrv_Cfg.h
Module Short Name:  EepDrv_Cfg.h
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef EEPDRV_CFG_H
#define EEPDRV_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
//todo: need to revisit if the below header need to be here
#include "Std_Types.h"
#include "Os.h"
#include "Ea_Cbk.h"
#include "Spi.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/* Need to be removed once RTE is updated */
#define EepDrv_MainFunction Eep24xx_MainFunction

#define EEP_NUMBER_OF_DEVICES_SUPPORTED    1

/*---------------  EepDrv Critical Sections Macro  ------------------------*/
#define EEPDRV_ENTER_CRITICAL_SECTION()   SuspendAllInterrupts()
#define EEPDRV_EXIT_CRITICAL_SECTION()    ResumeAllInterrupts()


/*---------------  EepDrv User Callback Configurations Macro  -----------------*/
#define EEPDRV_JOB_END_NOTIFICATION     Ea_JobEndNotification
#define EEPDRV_JOB_ERROR_NOTIFICATION   Ea_JobErrorNotification

/*---------------  EEPROM Development Error Reporting Macro  -----------------*/
#define EEPDRV_REPORT_ERROR(API_ID, ErrorCode)

/*---------------  EEPROM Device specific Configurations  Macro  -----------------*/

#define EEPDRV_TOTAL_MEM_SIZE              32768u        // Update total memory size

//I2c24xxEepDrv internal buffer configurations - total buffer size is 17(16data bytes + 1 address byte). So data starts from 1st index of buffer.
#define EEPDRV_MAX_BUFFER_SIZE             1027u
#define EEPDRV_ADDRESS_BUFFER_MAX_SIZE     3u

//EEPROM Type Selection
#define BIG_EEPROM                          1   //Covers EEPROM size for 32K
#define SMALL_EEPROM                        2   //Covers EEPROM size from 4K to 16K

#define I2C_EEPROM          0x00
#define SPI_EEPROM          0x01


//#define I2C_EEPROM_USED
#define SPI_EEPROM_USED


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef uint16  EepDrv_AddressType;
typedef uint16  EepDrv_LengthType;

typedef uint8   Eep_DataType;

typedef struct
{
    uint8  ReadSequenceId;
    uint8  WriteSequenceId;
    uint8  ReadChannel;
    uint8  WriteChannel;
    uint8  ChipType;
    uint8  SlaveAddress;
    uint8  EraseValue;
    uint16  ReadBlockSize;
    uint8  WriteBlockSize;
    uint8  ChipPageSize;
    uint8  BufferSize;
    uint8  AddressBufferSize;
    uint8  BuffStartDataIndex;
    uint8  ChipInterfaceType;
    uint16 MemorySize;
    uint16 BaseAddress;
    uint16 DevTimeOut_ms;
}Eep_DeviceConfigType;

extern const Eep_DeviceConfigType Eep_DeviceConfig[EEP_NUMBER_OF_DEVICES_SUPPORTED];


#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.17 */
/****************************************************************
Created Time: 8/24/2024 5:22:32 PM
****************************************************************/
