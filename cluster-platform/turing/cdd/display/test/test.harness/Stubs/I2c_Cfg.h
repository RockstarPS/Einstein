/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
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
*  File Name         :  I2c_Cfg.h                                            *
*  Module Short Name :  I2c                                                  *
*  Description       :  This file contains configuration of the I2C Driver   *
*                       for Traveo II series microcontrollers.               *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Traveo II micro based Hardware Platform                *
*                                                                            *
******************************************************************************/
#ifndef I2C_CFG_H
#define I2C_CFG_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "I2c_Types.h"
#include "Port.h"
#include "Dio.h"
//#include "OsMain.h"
#include "Det.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define I2C_SYNC_OFF   0U
#define I2C_SYNC_ON    1U

/* Define the macro with proper value if SYNC Transmit is Enabled */
#define I2C_SYNC_TRANSMIT_ENABLED   I2C_SYNC_OFF
/* Timeout = Main Function Periodicity x I2C_STOP_TIMEOUT_COUNT
If the I2c_MainFunction() Periodicity is 10ms, then to achieve the 100ms timeout, the I2C_STOP_TIMEOUT_COUNT needs to be configured as 10 */
#define I2C_STOP_TIMEOUT_COUNT  10U

/* Bus Busy Timeout - TBD by the User/Application on the timeout value */
/* Timeout count now is keep as per the Main Function periodicity */
#define I2C_BUSBUSY_TIMEOUT_COUNT 10u

/* Baud rate - 100KHz -> So the time for half cycle is 5us. The bus free 'for loop' atleast takes 5instuctions */
/* eg: 240Mhz Core Clock Ticks =  5(x) = (5us * 240MHz) -> here 'x' will give your ticks to be used */
/* The clock freq generated for this free bus sequence should be made sure that it doesn't exceed the 
set baud rate */
typedef struct
{
    uint16 Freebus_IdleTicks;
}I2c_FreeBusTicksType;

/* No of clock edges to generate -> 9 clock pulses to free the bus */
#define I2C_FREEBUS_CLK_EDGES       (0x9u)   

#define I2C_NUMBER_OF_SW_CHANNELS   2U

#define I2C_NUMBER_OF_HW_CHANNELS   2U

/*Software channels*/
#define I2C_FPD_SEQ_WRITECMD   0
#define I2C_AMP_SEQ_WRITECMD   1

#define I2C_FPD_CHANNEL_WRITECMD   0
#define I2C_AMP_CHANNEL_WRITECMD   1

#define I2C_REGADDRMODE      0x01

#if((I2C_REGADDRMODE == 0) && (I2C_REGADDRMODE > 2))
    #error "Register Addressing values should be 1 byte or 2 bytes"
#endif

/* MACRO TO ENABLE REPORTING OF ERRORS */
#define I2C_ERROR_REPORT        STD_ON

#if(I2C_ERROR_REPORT == STD_ON)
#define I2C_DEVERROR_REPORT(a,b,c,d)            Det_ReportError(a,b,c,d)
#endif

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef enum
{
    I2C_STANDARD_MODE = 100000,
    I2C_FAST_MODE = 400000,
    I2C_FAST_MODE_PLUS = 1000000
} I2C_TransferModeType;

/* End Notification for sequeunce */
typedef void (*I2C_EndNotificationCallbackType)(uint8 sequence, uint8 busstate, uint8 sequencestate);
/* I2c SW Channel Configuration */
typedef struct
{
    /* I2c Sequence Priority */
    uint8 SeqPriority;
    /* I2c Hw unit associated */
    uint8 HwUnit;
    /* End notification Function Call */
    I2C_EndNotificationCallbackType   I2C_EndNotificationCallback;
    /* I2C Mode to be configured */
    I2C_TransferModeType TransferMode;
    /* High Phase Over Sampling Value for Clock generation */
    uint8 HighPhaseOvsValue;
    /* Low Phase Over Sampling Value for Clock generation */
    uint8 LowPhaseOvsValue;
} I2c_ChannelConfigType;
void I2CSeq0EndNotification(uint8 sequence, uint8 busstate, uint8 sequencestate);
void I2CSeq1EndNotification(uint8 sequence, uint8 busstate, uint8 sequencestate);

#define ClientSlaveTestCode

#ifdef ClientSlaveTestCode
void Client_I2CCbJobEnd(uint8 SlaveReqDirection);
uint8* Client_I2CCbRead (uint16 Command, uint16* Length);
uint8 Client_I2CCbAck (uint16 Command);
uint8* Client_I2CCbWrite (uint16 Command, uint16* Length);
void Client_I2CEndNotification2(uint8 sequence, uint8 busstate, uint8 sequencestate);
void Client_I2CEndNotification1(uint8 sequence, uint8 busstate, uint8 sequencestate);
#endif

/* Function pointer typedefs */ 
typedef uint8 (*I2C_RegAddressAckCallbackType)(uint16 regAddress);  // Function to notify the application whether to ACK or NACK
typedef uint8* (*I2C_GetRxBufferCallbackType)(uint16 regAddress, uint16* length);  // Function to get the write buffer pointer and length
typedef uint8* (*I2C_GetTxBufferCallbackType)(uint16 regAddress, uint16* length);  // Function to get the read buffer pointer and length
typedef void (*I2C_SeqEndNotifyCallbackType)(uint8 SlaveReqDirection);

typedef struct
{
    /* SCB Base Address*/
    I2c_RegisterPtrType BaseAddress;
    uint32 I2C_Mode;
    /* The below configuration only used for slave mode - start */
    uint8 SlaveAddress;
    uint8 SlaveAddressMask;
    uint8 RegAddrMode; /* Register Addressing values should be 1 byte or 2 bytes */
    I2C_RegAddressAckCallbackType I2C_RegAddressAckCallback;
    I2C_GetRxBufferCallbackType I2C_GetRxBufferCallback;
    I2C_GetTxBufferCallbackType I2C_GetTxBufferCallback;
    I2C_SeqEndNotifyCallbackType I2C_SeqEndNotifyCallback;
    /* The configuration only used for slave mode - end */
    /* Configure Multi Master or Single Master */
    uint8  MasterSetting;
} I2c_ConfigType;

typedef struct
{
    uint16 PortPin;
    uint8  PortPinGPIOMode;
    uint16 DioChannelId;
    uint8  PortPinPeripheralMode;
} I2c_PortConfigType;

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

extern const I2c_ChannelConfigType    I2c_ChannelConfig[I2C_NUMBER_OF_SW_CHANNELS];
extern I2c_ConfigType           I2c_Config[I2C_NUMBER_OF_HW_CHANNELS];
extern const I2c_FreeBusTicksType     I2c_FreeBusTicks;
extern const I2c_PortConfigType       I2c_SCLPortConfig[I2C_NUMBER_OF_HW_CHANNELS];
extern const I2c_PortConfigType       I2c_SDAPortConfig[I2C_NUMBER_OF_HW_CHANNELS];
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
extern void I2c_EnterCriticalSection(void);
extern void I2c_ExitCriticalSection(void);


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
Date               : 21-Oct-2025
CDSID              : vvijaya5
Traceability       : AU29610-202339
Change Description : Initial Framework version of I2c
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/



