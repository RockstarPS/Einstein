/*---------------------------------------------------------------------------------------------------------------------

VISTEON CORPORATION CONFIDENTIAL
_______________________________

[2019] Visteon Corporation
All Rights Reserved.

NOTICE: This is an unpublished work of authorship, which contains trade secrets.
Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
under all copyright laws to protect this work as a published work, when appropriate.
Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
without the written authorization of Visteon Corporation.

---------------------------------------------------------------------------------------------------------------------*/
/*!*****************************************************************************************************************
*    @file DisplayDrvCdd_Tianma.c
*    @ingroup DisplayCdd
*    @brief This file provides the Definitions of the DisplayDrvCdd_Tianma APIs. This header file should be included by other  
*    modules that use these APIs this file interacts with driver layer
********************************************************************************************************************/

/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/
#include "DisplayCdd_Cfg.h"

#include "DisplayIfCdd.h"

#include "DisplayDrvCdd_Tianma.h"

#include "DisplayDrvCdd_Cbk.h"

/*=====================================================================================================================
  CONSTANTS & TYPES
=====================================================================================================================*/

/*! @brief Defines the maximum SIZE of data Array of SPI */
#define DISPLAYCDD_TRANSFER_SIZE 			(4u)

/*! @brief Defines the maximum SIZE of data Array of SPI */
#define MAX_SET_SIZE 			(3u)
/*! @brief Defines the index for init sequence Array of SPI */
#define DISP_INIT				(0u)
/*! @brief Defines the index for On sequence Array of SPI */
#define DISP_ON					(1u)
/*! @brief Defines the index for Off sequence Array of SPI */
#define DISP_OFF				(2u)

/*! @brief Defines the maximum data length of SPI */
#define MAX_BUF_DATA_LEN        (40u)

/*! @brief Defines the maximum data length of SPI */
#define DISPLAYCDD_INIT_WAITIME        (0u)

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA
#if (cDISPLAYCDD_SPI_WORD_SIZE == DISPLAYCDD_SPIWRITE_BITS_9)
#define cDISPLAYCDD_PAGE_DATA_SIZE                  5u
#define cDISPLAYCDD_MASK_PAGE_DATA_0_9BIT(addr)     (uint32)((0xFFUL & ((uint16)(addr) >> 8U)))
#define cDISPLAYCDD_MASK_PAGE_DATA_N_9BIT(val)      (uint32)(((0xFFUL & (uint8)(val)) | 0x100U))
#define cDISPLAYCDD_MASK_CMD00_9BIT(addr)           (uint32)(((0xFFUL & (uint8)(addr)) | 0x100U) << 16U)

#elif (cDISPLAYCDD_SPI_WORD_SIZE == DISPLAYCDD_SPIWRITE_BITS_18)
#define cDISPLAYCDD_MASK_PAGE_DATA_18BIT(addr, val) (uint32)(((0xFFUL & ((uint16)(addr) >> 8U)) << 9u) | ((0xFFUL & (uint8)(val)) | 0x100U))
#define cDISPLAYCDD_MASK_CMD00_18BIT(addr)          (uint32)(((0xFFUL & (uint8)(addr)) | 0x100U))

#else
    #error SPI word size is not specified
#endif
#endif /*#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA*/
/*=====================================================================================================================
  GLOBALS & STATIC
=====================================================================================================================*/

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA
/*
Description: To hold the details related to EEPROM load 
*/
typedef struct 
{
    uint8                      DeviceID;                        /* Uinque ID of a device*/
    uint16 					   DeviceResetPin;
	uint16 					   DeviceTouchResetPin;
	uint8			   		   RequesterPowerState;				/*Hold the repective device power state as POWERON , NORMAL , FAULT , POWEROFF */
	uint16    				   FaultStatusPin;
	uint8					   SpiCommandChannel;
	uint8					   SpiPageChannel;
	uint8					   SpiWriteChannel;
	boolean				       FaultStatus;		        	    /* Hold the repective device status as ready , NotReady , Busy*/

}SDisplayDrvInfo;

#else
	
typedef struct 
{
    uint8                      DeviceID;                        /* Uinque ID of a device*/
	uint16 					   DeviceSupplyPin;
    uint16 					   DeviceResetPin;
	uint16 					   DeviceStandbyPin;
	uint8			   		   RequesterPowerState;				/*Hold the repective device power state as POWERON , NORMAL , FAULT , POWEROFF */
	uint16    				   FaultStatusPin;
	boolean				       FaultStatus;		        	    /* Hold the repective device status as ready , NotReady , Busy*/

}SDisplayDrvInfo;
	
#endif /*CDISPLAYCDD_ENABLE_DISPLAY_TIANMA*/

/*! Hold the Display driver  related information  */
static SDisplayDrvInfo DisplayDrvInfoTable[cDISPLAYCDD_MAX_DEVICE];
/*! Hold the driver state machine  related information  */
static EDisplaypowerStatesHelper DisplayDrvStateMachine[cDISPLAYCDD_MAX_DEVICE];

/*!Hold the waitime for the execution of power sequence */
static uint8 DisplayDrvCdd_Waittime;



#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA
#if (cDISPLAYCDD_SPI_WORD_SIZE == DISPLAYCDD_SPIWRITE_BITS_9)
static uint32 SpiTxCmd_9bit;
static uint16 SpiTxPageData_9bit[cDISPLAYCDD_PAGE_DATA_SIZE];
#else
static uint32 SpiTxCmd_18bit;
static uint32 SpiTxPageData_18bit;
#endif
#endif /*#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA*/ 

#ifdef CDISPLAYCDD_ENABLEBISTTEST
/*!Hold whether the driver is initialized */
static boolean DisplayDrvCdd_IsDrvInitialized[cDISPLAYCDD_MAX_DEVICE];
#endif


/*=====================================================================================================================
  LOCAL Functions
=====================================================================================================================*/

static void DisplayDrvCdd_FaultHandle(void);
static void DisplayDrvCdd_MonitorFaultStatus(uint8 deviceIndex);

/*!***************************************************************************************************************** 
*   @brief      The function initialize the displaydrvCdd layer
*   @param[in]  void
*   @return  void
********************************************************************************************************************/ 
Std_ReturnType DisplayDrvCdd_Init(void)
{
	
	Std_ReturnType status = E_NOT_OK;
	uint8 Device_No;
	
#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA
/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE; Device_No++)
	{
		DisplayDrvInfoTable[Device_No].DeviceID              = DisplayInfoDB[Device_No].DisplayDeviceId;
		DisplayDrvInfoTable[Device_No].DeviceResetPin        = DisplayInfoDB[Device_No].DisplayResetPin;
		DisplayDrvInfoTable[Device_No].DeviceTouchResetPin   = DisplayInfoDB[Device_No].DisplayTouchResetPin;	
		DisplayDrvInfoTable[Device_No].RequesterPowerState   = cDISPLAYCDD_INIT_POWER_STATE;
		DisplayDrvInfoTable[Device_No].FaultStatusPin        = DisplayInfoDB[Device_No].DisplayFaultStatusPin;
		DisplayDrvInfoTable[Device_No].SpiCommandChannel     = DisplayInfoDB[Device_No].SpiSetCommandChannel;
		DisplayDrvInfoTable[Device_No].SpiPageChannel        = DisplayInfoDB[Device_No].SpiSetpageChannel;
		DisplayDrvInfoTable[Device_No].SpiWriteChannel       = DisplayInfoDB[Device_No].SpiSequencewriteChannel;		
		DisplayDrvInfoTable[Device_No].FaultStatus           = (boolean)FALSE;

		DisplayDrvStateMachine[Device_No]					 = eDisplayIdleState;
		
		
		/*Initial setup the spi */
		#if (cDISPLAYCDD_SPI_WORD_SIZE == DISPLAYCDD_SPIWRITE_BITS_9)
			(void)Spi_SetupEB(DisplayDrvInfoTable[Device_No].SpiCommandChannel, (uint8 *)&SpiTxCmd_9bit, NULL_PTR, sizeof(SpiTxCmd_9bit));
		#else
			(void)Spi_SetupEB(DisplayDrvInfoTable[Device_No].SpiCommandChannel, (uint8 *)&SpiTxCmd_18bit, NULL_PTR, sizeof(SpiTxCmd_18bit));
		#endif
		
		#ifdef CDISPLAYCDD_ENABLEBISTTEST
			DisplayDrvCdd_IsDrvInitialized[Device_No] = (boolean)TRUE;
		#endif
		
	}


#else
	/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE; Device_No++)
	{
		DisplayDrvInfoTable[Device_No].DeviceID              = DisplayTIANMAInfoDB[Device_No].DisplayDeviceId;
		DisplayDrvInfoTable[Device_No].DeviceResetPin        = DisplayTIANMAInfoDB[Device_No].DisplayResetPin;
		DisplayDrvInfoTable[Device_No].DeviceSupplyPin       = DisplayTIANMAInfoDB[Device_No].DisplaySupplyPin;
		DisplayDrvInfoTable[Device_No].DeviceStandbyPin      = DisplayTIANMAInfoDB[Device_No].DisplayStandbyPin;	
		DisplayDrvInfoTable[Device_No].RequesterPowerState   = cDISPLAYCDD_INIT_POWER_STATE;
		DisplayDrvInfoTable[Device_No].FaultStatusPin        = DisplayTIANMAInfoDB[Device_No].DisplayFaultStatusPin;		
		DisplayDrvInfoTable[Device_No].FaultStatus           = (boolean)FALSE;
		DisplayDrvStateMachine[Device_No]					 = eDisplayIdleState;
		
		#ifdef CDISPLAYCDD_ENABLEBISTTEST
			DisplayDrvCdd_IsDrvInitialized[Device_No] = (boolean)TRUE;
		#endif
		
	}

#endif	
	
	DisplayDrvCdd_Waittime = DISPLAYCDD_INIT_WAITIME;
	
	status = E_OK;
	
	return status;
	
}
/*!***************************************************************************************************************** 
*   @brief      The function de-initialize the displaydrvCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/ 
Std_ReturnType DisplayDrvCdd_DeInit(void)
{
	Std_ReturnType DeInitResult = E_OK;
		
	return DeInitResult;	
	
}

/*!***************************************************************************************************************** 
*   @brief      The function is used to set the new power state for the particular device 
*   @param[in]  DeviceIndex - Repective Device Index
*   @param[in]  NewPowerState - Next power state
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_SetState(uint8 DeviceIndex , EDisplayPowerState NewPowerState)
{
	Std_ReturnType ret = E_NOT_OK;
	
	DisplayDrvInfoTable[DeviceIndex].RequesterPowerState = NewPowerState;
	
	if(eDisplayPowerON == NewPowerState)
	{
		
		/*Switch the state machine as per the requested power state*/
		DisplayDrvStateMachine[DeviceIndex] = eDisplayPowerONStatePinupdate;
		
	}
	else if (eDisplayPowerOFF == NewPowerState)
	{
		DisplayDrvCdd_Waittime = cDISPLAYCDD_POWEROFF_DELAY1;	
		/*Switch the state machine as per the requested power state*/
		DisplayDrvStateMachine[DeviceIndex] = eDisplayPowerOFFState;		
	}
	else
	{
		/*Do Nothing */
	}
	
	ret = E_OK;
	return ret;
}


/*!***************************************************************************************************************** 
*   @brief       This function is used to perform power handle and Fault Monitor
*   @param[in]   None
*   @return      None
********************************************************************************************************************/
void DisplayDrvCdd_MainFunction(void)
{
	Std_ReturnType SpiTransmitResult = E_NOT_OK;
	Std_ReturnType NotifyResult = E_NOT_OK;
	uint8 Device_No;
	
	IoHwAb_ErrorType GetErrorStatus;
		
	/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE; Device_No++)
	{
	
		switch(DisplayDrvStateMachine[Device_No])
		{
			case eDisplayIdleState:
			{
				/*Do nothing*/
			}
			break;
			case eDisplayPowerONStatePinupdate:
			{
#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA
				//Dio_WriteChannel(DisplayDrvInfoTable[Device_No].DeviceTouchResetPin, STD_HIGH);		
				//Dio_WriteChannel(DisplayDrvInfoTable[Device_No].DeviceResetPin, STD_HIGH);
				
				Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvInfoTable[Device_No].DeviceTouchResetPin, STD_HIGH , &GetErrorStatus);
				Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvInfoTable[Device_No].DeviceResetPin, STD_HIGH , &GetErrorStatus);
				
				DisplayDrvCdd_Waittime = cDISPLAYCDD_POWERON_DELAY1;
				DisplayDrvStateMachine[Device_No] = eDisplayPowerONState;
#else
				Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvInfoTable[Device_No].DeviceSupplyPin, STD_HIGH , &GetErrorStatus);
				DisplayDrvCdd_Waittime = cDISPLAYCDD_POWERON_DELAY1;
				DisplayDrvStateMachine[Device_No] = eDisplayPowerONState;
#endif
			}	
			break;			
			case eDisplayPowerONState:
			{				
				if(DisplayDrvCdd_Waittime >=1)
				{
					DisplayDrvCdd_Waittime--;
				}
				
				if(DisplayDrvCdd_Waittime <= 0)
				{
#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA
					if(SPI_SEQ_PENDING != Spi_GetSequenceResult(DisplayDrvInfoTable[Device_No].SpiWriteChannel))
					{
						
						#if (cDISPLAYCDD_SPI_WORD_SIZE == DISPLAYCDD_SPIWRITE_BITS_9)
							SpiTxCmd_9bit = cDISPLAYCDD_MASK_CMD00_9BIT(0x1100u);
							SpiTxPageData_9bit[0] = cDISPLAYCDD_MASK_PAGE_DATA_0_9BIT(0x1100u);
							SpiTxPageData_9bit[1] = cDISPLAYCDD_MASK_PAGE_DATA_N_9BIT(0x01u);
							(void)Spi_SetupEB(DisplayDrvInfoTable[Device_No].SpiPageChannel, (uint8 *)&SpiTxPageData_9bit, NULL_PTR, DISPLAYCDD_TRANSFER_SIZE);
						#else
							SpiTxCmd_18bit      = cDISPLAYCDD_MASK_CMD00_18BIT(0x1100u);
							SpiTxPageData_18bit = cDISPLAYCDD_MASK_PAGE_DATA_18BIT(0x1100u, 0x01u);
							(void)Spi_SetupEB(DisplayDrvInfoTable[Device_No].SpiPageChannel, (uint8 *)&SpiTxPageData_18bit, NULL_PTR, DISPLAYCDD_TRANSFER_SIZE);
						#endif
						
						SpiTransmitResult = Spi_AsyncTransmit(DisplayDrvInfoTable[Device_No].SpiWriteChannel);
						
						if(E_OK == SpiTransmitResult)
						{
							DisplayDrvCdd_Waittime = cDISPLAYCDD_POWERON_DELAY2;
							DisplayDrvStateMachine[Device_No] = eDisplayPowerOn_PhaseOneState;
						}
					}

#else
					Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvInfoTable[Device_No].DeviceResetPin, STD_HIGH , &GetErrorStatus);
					DisplayDrvCdd_Waittime = cDISPLAYCDD_POWERON_DELAY2;
					DisplayDrvStateMachine[Device_No] = eDisplayPowerOn_PhaseOneState;
					}
#endif /**/

			}
			break;
			case eDisplayPowerOn_PhaseOneState:
			{
				if(DisplayDrvCdd_Waittime >=1)
				{
					DisplayDrvCdd_Waittime--;
				}
				
				if(DisplayDrvCdd_Waittime <= 0)
				{
#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA

					#ifndef CDISPLAYCDD_ENABLEBISTTEST
						//Dio_WriteChannel(DioConf_DioChannel_DioChannel_FPGA_LVDS_OUT_EN, STD_HIGH);
						Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DioConf_DioChannel_DioChannel_FPGA_LVDS_OUT_EN, STD_HIGH , &GetErrorStatus);
					#endif 
					
					if(SPI_SEQ_PENDING != Spi_GetSequenceResult(DisplayDrvInfoTable[Device_No].SpiWriteChannel))
					{
						#if (cDISPLAYCDD_SPI_WORD_SIZE == DISPLAYCDD_SPIWRITE_BITS_9)
							SpiTxCmd_9bit = cDISPLAYCDD_MASK_CMD00_9BIT(0x2900u);
							SpiTxPageData_9bit[0] = cDISPLAYCDD_MASK_PAGE_DATA_0_9BIT(0x2900u);
							SpiTxPageData_9bit[1] = cDISPLAYCDD_MASK_PAGE_DATA_N_9BIT(0x01u);
							(void)Spi_SetupEB(DisplayDrvInfoTable[Device_No].SpiPageChannel, (uint8 *)&SpiTxPageData_9bit, NULL_PTR, DISPLAYCDD_TRANSFER_SIZE);
						#else
							SpiTxCmd_18bit      = cDISPLAYCDD_MASK_CMD00_18BIT(0x2900u);
							SpiTxPageData_18bit = cDISPLAYCDD_MASK_PAGE_DATA_18BIT(0x2900u, 0x01u);
							(void)Spi_SetupEB(DisplayDrvInfoTable[Device_No].SpiPageChannel, (uint8 *)&SpiTxPageData_18bit, NULL_PTR, DISPLAYCDD_TRANSFER_SIZE);
						#endif
						
						SpiTransmitResult = Spi_AsyncTransmit(DisplayDrvInfoTable[Device_No].SpiWriteChannel);
						if(E_OK == SpiTransmitResult)
						{
							DisplayDrvCdd_Waittime = cDISPLAYCDD_POWERON_DELAY3;
							DisplayDrvStateMachine[Device_No] = eDisplayPowerOn_PhaseTwoState;
						}
					}
#else

					Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvInfoTable[Device_No].DeviceStandbyPin, STD_HIGH , &GetErrorStatus);
					DisplayDrvCdd_Waittime = cDISPLAYCDD_POWERON_DELAY3;
					DisplayDrvStateMachine[Device_No] = eDisplayPowerNormalState;
					}
#endif /*CDISPLAYCDD_ENABLE_DISPLAY_TIANMA*/
										
						 
			}
			break;
#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA			
			case eDisplayPowerOn_PhaseTwoState:
			{	
				if(DisplayDrvCdd_Waittime >=1)
				{
					DisplayDrvCdd_Waittime--;
				}
				
				if(DisplayDrvCdd_Waittime <= 0)
				{
					DisplayDrvStateMachine[Device_No] = eDisplayPowerNormalState;
				}						
						 
			}
			break;
#endif /*CDISPLAYCDD_ENABLE_DISPLAY_TIANMA*/			
			case eDisplayPowerNormalState:
			{
				/*Notify that power state*/
				NotifyResult = DispIfCdd_NotifyDisplayStatus(Device_No , eDisplayNormal);
				
				if(E_OK == NotifyResult)
				{
					DisplayDrvStateMachine[Device_No] = eDisplayIdleState;
					DisplayDrvCdd_Waittime = DISPLAYCDD_INIT_WAITIME;
				}
			}
			break;
			case eDisplayPowerOFFState:
			{        
				if(DisplayDrvCdd_Waittime >=1)
				{
					DisplayDrvCdd_Waittime--;
				}
				
				if(DisplayDrvCdd_Waittime <= 0)
				{					
#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA
					 if(SPI_SEQ_PENDING != Spi_GetSequenceResult(DisplayDrvInfoTable[Device_No].SpiWriteChannel))
					 {
						#if (cDISPLAYCDD_SPI_WORD_SIZE == DISPLAYCDD_SPIWRITE_BITS_9)
							SpiTxCmd_9bit = cDISPLAYCDD_MASK_CMD00_9BIT(0x2900u);
							SpiTxPageData_9bit[0] = cDISPLAYCDD_MASK_PAGE_DATA_0_9BIT(0x2900u);
							SpiTxPageData_9bit[1] = cDISPLAYCDD_MASK_PAGE_DATA_N_9BIT(0x00u);
							(void)Spi_SetupEB(DisplayDrvInfoTable[Device_No].SpiPageChannel, (uint8 *)&SpiTxPageData_9bit, NULL_PTR, DISPLAYCDD_TRANSFER_SIZE);
						#else
							SpiTxCmd_18bit      = cDISPLAYCDD_MASK_CMD00_18BIT(0x2900u);
							SpiTxPageData_18bit = cDISPLAYCDD_MASK_PAGE_DATA_18BIT(0x2900u, 0x00u);
							(void)Spi_SetupEB(DisplayDrvInfoTable[Device_No].SpiPageChannel, (uint8 *)&SpiTxPageData_18bit, NULL_PTR, DISPLAYCDD_TRANSFER_SIZE);
						#endif
						
						SpiTransmitResult = Spi_AsyncTransmit(DisplayDrvInfoTable[Device_No].SpiWriteChannel);
						if(E_OK == SpiTransmitResult)
						{
							DisplayDrvStateMachine[Device_No] = eDisplayPowerOff_PhaseOneState;
						}
					}
#endif /*#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA*/					
				}						
			}
			break;
			case eDisplayPowerOff_PhaseOneState:
			{        
				if(DisplayDrvCdd_Waittime >=1)
				{
					DisplayDrvCdd_Waittime--;
				}
				
				if(DisplayDrvCdd_Waittime <= 0)
				{
#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA
					if(SPI_SEQ_PENDING != Spi_GetSequenceResult(DisplayDrvInfoTable[Device_No].SpiWriteChannel))
					{
						
						#if (cDISPLAYCDD_SPI_WORD_SIZE == DISPLAYCDD_SPIWRITE_BITS_9)
							SpiTxCmd_9bit = cDISPLAYCDD_MASK_CMD00_9BIT(0x1100u);
							SpiTxPageData_9bit[0] = cDISPLAYCDD_MASK_PAGE_DATA_0_9BIT(0x1100u);
							SpiTxPageData_9bit[1] = cDISPLAYCDD_MASK_PAGE_DATA_N_9BIT(0x00u);
							(void)Spi_SetupEB(DisplayDrvInfoTable[Device_No].SpiPageChannel, (uint8 *)&SpiTxPageData_9bit, NULL_PTR, DISPLAYCDD_TRANSFER_SIZE);
						#else
							SpiTxCmd_18bit      = cDISPLAYCDD_MASK_CMD00_18BIT(0x1100u);
							SpiTxPageData_18bit = cDISPLAYCDD_MASK_PAGE_DATA_18BIT(0x1100u, 0x00u);
							(void)Spi_SetupEB(DisplayDrvInfoTable[Device_No].SpiPageChannel, (uint8 *)&SpiTxPageData_18bit, NULL_PTR, DISPLAYCDD_TRANSFER_SIZE);
						#endif						
					
						SpiTransmitResult = Spi_AsyncTransmit(DisplayDrvInfoTable[Device_No].SpiWriteChannel);
						if(E_OK == SpiTransmitResult)
						{
							DisplayDrvCdd_Waittime = cDISPLAYCDD_POWEROFF_DELAY2;
							DisplayDrvStateMachine[Device_No] = eDisplayPowerOff_CompleteState;
						}						

					}
#endif /*#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA*/					
				}
			}				
			break;	
			case eDisplayPowerOff_CompleteState:
			{
				if(DisplayDrvCdd_Waittime >=1u)
				{
					DisplayDrvCdd_Waittime--;
				}
				
				if(DisplayDrvCdd_Waittime <= 0u)
				{
					
#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA
					/*Set the pin to Low state */
					//Dio_WriteChannel(DisplayDrvInfoTable[Device_No].DeviceTouchResetPin, STD_LOW);
					//Dio_WriteChannel(DisplayDrvInfoTable[Device_No].DeviceResetPin, STD_LOW);
					Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvInfoTable[Device_No].DeviceTouchResetPin, STD_LOW , &GetErrorStatus);
				    Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvInfoTable[Device_No].DeviceResetPin, STD_LOW , &GetErrorStatus);
					
					/*Notify that power state is complete*/
					NotifyResult = DispIfCdd_NotifyDisplayStatus(Device_No , eDisplayPowerOFF);
					
					if(E_OK == NotifyResult)
					{
						DisplayDrvStateMachine[Device_No] = eDisplayIdleState;
						DisplayDrvCdd_Waittime = DISPLAYCDD_INIT_WAITIME;
					}						
#endif 					
				}
			}				
			break;
			case eDisplayFaultState:
			{
				DisplayDrvCdd_FaultHandle();
			}				
			break;
			default:
			break;
		}
	
	}	
            
}

/*!***************************************************************************************************************** 
*   @brief        This function is used to monitor the fault status pin
*   @param[in]    Device index
*   @return   	  void
********************************************************************************************************************/
static void DisplayDrvCdd_MonitorFaultStatus(uint8 deviceIndex)
{
	uint8 FaultStatus = STD_LOW;
	
	FaultStatus = Dio_ReadChannel(DisplayDrvInfoTable[deviceIndex].FaultStatusPin);
	
	if(STD_LOW == FaultStatus)
	{
		
		DisplayDrvInfoTable[deviceIndex].FaultStatus = (boolean)FALSE;
		
	}
	else
	{
		
		DisplayDrvInfoTable[deviceIndex].FaultStatus = (boolean)TRUE;
		/*Switch  the state machine to Fault handle*/
		DisplayDrvStateMachine[deviceIndex] = eDisplayFaultState;	
		/*Notify Fault state as occured.*/
		DispIfCdd_NotifyDisplayStatus(deviceIndex , eDisplayFault);		
		
	}
	
}

/*!***************************************************************************************************************** 
*   @brief      The function is resposible for fault handling
*   @param[in]  void
*   @return  void 
********************************************************************************************************************/
static void DisplayDrvCdd_FaultHandle(void)
{
	/* To be implementation in future*/
}

#ifdef CDISPLAYCDD_ENABLEBISTTEST
/*!***************************************************************************************************************** 
*   @brief      The function is perorm the BIST test 
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_BISTTest(EDisplayType DeviceId)
{
    Std_ReturnType ret = E_NOT_OK;
	uint8 Device_No;
	uint8 Device_Index = 0;
	
	/*check the respective chip to update the status of EEPROM load*/
	for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE ; Device_No++)
	{
		if(DeviceId == DisplayDrvInfoTable[Device_No].DeviceID)
		{
			Device_Index = Device_No;
		}
			
	}
    
	if((boolean)FALSE != DisplayDrvCdd_IsDrvInitialized[Device_Index])
	{
#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA		
		if(SPI_SEQ_PENDING != Spi_GetSequenceResult(DisplayDrvInfoTable[Device_Index].SpiWriteChannel))
		{
		#if (cDISPLAYCDD_SPI_WORD_SIZE == DISPLAYCDD_SPIWRITE_BITS_9)
			SpiTxCmd_9bit = cDISPLAYCDD_MASK_CMD00_9BIT(0xf6a0u);
			SpiTxPageData_9bit[0] = cDISPLAYCDD_MASK_PAGE_DATA_0_9BIT(0xf6a0u);
			SpiTxPageData_9bit[1] = cDISPLAYCDD_MASK_PAGE_DATA_N_9BIT(0xc5u);
			(void)Spi_SetupEB(DisplayDrvInfoTable[Device_Index].SpiPageChannel, (uint8 *)&SpiTxPageData_9bit, NULL_PTR, DISPLAYCDD_TRANSFER_SIZE);
		#else
			SpiTxCmd_18bit      = cDISPLAYCDD_MASK_CMD00_18BIT(0xf6a0u);
			SpiTxPageData_18bit = cDISPLAYCDD_MASK_PAGE_DATA_18BIT(0xf6a0u, 0xc5u);
			(void)Spi_SetupEB(DisplayDrvInfoTable[Device_Index].SpiPageChannel, (uint8 *)&SpiTxPageData_18bit, NULL_PTR, DISPLAYCDD_TRANSFER_SIZE);
		#endif
		
		ret = Spi_AsyncTransmit(DisplayDrvInfoTable[Device_Index].SpiWriteChannel);
#endif		
		}
	}
    
    return ret;
}

#endif

/*!***************************************************************************************************************** 
*   @brief      Callback notification function from I2cDrv for the previously triggered sequence
********************************************************************************************************************/
void DisplayDrvCdd_I2cSeqEndCallback(void)
{
	/*do nothing */
}

/*!***************************************************************************************************************** 
*   @brief      Error Callback notification function from I2cDrv for the previously triggered sequence
********************************************************************************************************************/
void DisplayDrvCdd_I2cSeqErrorCallback(void)
{
	/*do nothing */
}


/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 6/Apr/2020
By                : sgarg1
Traceability      : RTC #
Change Description: Initial Version
-------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 22/June/2020
By                : nrajaman
Traceability      : RTC # 835355
Change Description: Added Power and SPI sequence for 12 inch tianma display. 
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 22/June/2020
By                : nrajaman
Traceability      : RTC # 835355
Change Description: Updated PR comments 
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 8/July/2020
By                : nrajaman
Traceability      : RTC # 956295
Change Description: Fixed Coverity and Misra Warnings 
-----------------------------------------------------------------------------------------*/



