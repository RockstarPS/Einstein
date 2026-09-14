/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2025 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file CanTrcv_Tja1145ATK.c
*    @ingroup CanTrcv
*    @brief This file implements the AUTOSAR CanTrcv module.The CAN transceiver driver abstracts
*    the CAN transceiver hardware. It offers a hardware independent interface to the higher layers.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanTrcv_Tja1145ATK.h"
#include "Spi.h"
#if (CANTRCV_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
#if (CANTRCV_DEV_ERROR_REPORT == STD_ON)
#define CanTrcv_DetReportError(ApiId, ErrorId) \
    ((void)Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_MODULE_ID, (ApiId), (ErrorId)))
#endif
#define CanTrcv_Tja1145ATK_Get_Addr_RW(addr, rw) \
    ((uint8)((uint8)(((uint8)(addr) << 1U)) | ((uint8)(rw) & 0x1U)))
/* Main control registers */
/*! @brief Mode Control Register    */
#define CANTRCV_TJA1145_ADDR_OPMODE                 0x01U 
/*! @brief Main Status Register     */                  
#define CANTRCV_TJA1145_ADDR_MS                     0x03U                   

/*Transceiver Control registers */
/*! @brief CAN Control  Register    */
#define CANTRCV_TJA1145_ADDR_CANCTRL                0X20U 
/*! @brief Transceiver Status       */                  
#define CANTRCV_TJA1145_ADDR_TS                     0x22U
/*! @brief Transceiver event capture enable register    */                   
#define CANTRCV_TJA1145_ADDR_TEE                    0x23U                   

/*! @brief Frame control register (address 2Fh)*/
#define CANTRCV_TJA1145_ADDR_FC                     0x2FU

/*Event capturing registers */
/*! @brief Event Capture Status     */
#define CANTRCV_TJA1145_ADDR_ECS                    0x60u 
/*! @brief System Event Status      */                  
#define CANTRCV_TJA1145_ADDR_SES                    0x61u  
/*! @brief Transceiver Event Status */                 
#define CANTRCV_TJA1145_ADDR_TES                    0x63u  
/*! @brief WAKE pin Event Status    */                 
#define CANTRCV_TJA1145_ADDR_WES                    0x64u                   

/*! @brief Identification Register */
#define CANTRCV_TJA1145_ADDR_ISR                    0x7EU

/*! @brief CAN partial networking  ID registers 0 to 3*/
#define CANTRCV_TJA1145_ADDR_IDREG0                 0x27U
#define CANTRCV_TJA1145_ADDR_IDREG1                 0x28U
#define CANTRCV_TJA1145_ADDR_IDREG2                 0x29U
#define CANTRCV_TJA1145_ADDR_IDREG3                 0x2AU

/*! @brief CAN partial networking ID mask registers 0 to 3*/
#define CANTRCV_TJA1145_ADDR_MASKREG2               0x2DU
#define CANTRCV_TJA1145_ADDR_MASKREG3               0x2EU

/*! @brief Transceiver status register*/
#define CANTRCV_TJA1145_ADDR_TRCVSTATUS             0x22U
/*! @brief CAN partial networking status*/
#define CANTRCV_TJA1145_TRCVSTATUS_CPNS             0x20U 

/*! @brief WAKE Pin registers - WAKE pin Status Register */
#define CANTRCV_TJA1145_ADDR_WPS                    0x4BU                   

/*! @brief  Operation modes requests */
#define CANTRCV_TJA1145_REQ_OPMODENORMAL            0x07U
#define CANTRCV_TJA1145_REQ_OPMODESTANDBY           0X04U
#define CANTRCV_TJA1145_REQ_OPMODESLEEP             0X01U

/*! @brief Can modes control requests */
#define CANTRCV_TJA1145_REQ_CANMODEACTIVE           0x01U
#define CANTRCV_TJA1145_REQ_CANMODEOFFLINE          0x00U 

/* Ts Register */
/*! @brief CAN Partial Networking Status  */
#define CANTRCV_TJA1145_ADDR_TS_CPNS                  0x20u 
/*! @brief CAN Partial Networking Error   */       
#define CANTRCV_TJA1145_ADDR_TS_CPNERR                0x40u        

/*! @brief CAN selective wake-up- enabled*/
#define CANTRCV_TJA1145_CANCTRL_CPNC                0x10U

/*! @brief partial networking registers configured successfully */
#define CANTRCV_TJA1145_CANCTRL_PNCOK               0x20U

/*! @brief TEE -CAN wake-up enable */
#define CANTRCV_TJA1145_TEE_ENABLE_CWE              0x01U

/* Ecs Register */
/*! @brief System event status            */
#define CANTRCV_TJA1145_ADDR_ECS_SYSE               0x01u 
/*! @brief Transceiver event status       */        
#define CANTRCV_TJA1145_ADDR_ECS_TRXE               0x04u
/*! @brief Wake pin event status          */         
#define CANTRCV_TJA1145_ADDR_ECS_WPE                0x08u         

/*! Ses Register */
/*! @brief SPI failure event              */
#define CANTRCV_TJA1145_ADDR_SES_SPIF               0x02u
/*! @brief Overtemperature warning event  */         
#define CANTRCV_TJA1145_ADDR_SES_OTW                0x04u
/*! @brief Power-on event                 */         
#define CANTRCV_TJA1145_ADDR_SES_PO                 0x10u         

/*! Tes Register */
/*! @brief CAN Wake-up event              */
#define CANTRCV_TJA1145_ADDR_TES_CW                 0x01u
/*! @brief CAN failure event              */         
#define CANTRCV_TJA1145_ADDR_TES_CF                 0x02u
/*! @brief CAN bus silence event          */         
#define CANTRCV_TJA1145_ADDR_TES_CBS                0x10u
/*! @brief PN Frame Detection Error event */         
#define CANTRCV_TJA1145_ADDR_TES_PNFDE              0x20u         

/* Wes Register */
/*! @brief WAKE pin falling edge event    */
#define CANTRCV_TJA1145_ADDR_WES_WPF                0x01u
/*! @brief WAKE pin rising edge event     */         
#define CANTRCV_TJA1145_ADDR_WES_WPR                0x02u         

/*! @brief Frame control register - identifier format */
#define CANTRCV_TJA1145_FC_ID_EXT                   0x80U

/*! @brief Frame control register -partial networking data mask */
#define CANTRCV_TJA1145_FC_PNDM                     0x40u

/*! @brief Identification register -TJA1145AT/FD, TJA1145ATK/FD */
#define CANTRCV_TJA1145_ISR_ID                      0X74U 

/*! @brief Dummy Value - Used During Read Operation  */
#define CANTRCV_TJA1145_READ_DUMMYVALUE             0x00U

/********************************************************************************************************************
*  PRIVATE  DEFINITIONS                                                                                         *
********************************************************************************************************************/
CanTrcv_TrcvWakeupReasonType TjaWakeUpReason;
/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
/* helper function to write a value to a TJA1145 register via SPI.*/
static Std_ReturnType CanTrcv_Tja1145ATK_SpiWriteReg(uint8 ErrorIdApi ,
    Spi_ChannelType SpiChannel, uint8 regAddr, uint8 data);
/* helper function to Read a value to a TJA1145 register via SPI.*/
static Std_ReturnType CanTrcv_Tja1145ATK_SpiReadReg(uint8 ErrorIdApi ,Spi_ChannelType SpiChannel, uint8 RegAddr);
#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
/*! @brief Defines the partial NW support enabled */
extern boolean CanTrcv_PnEnabled[CANTRCV_NUM_OF_TRCV_CHANNELS];
#endif
/********************************************************************************************************************
*   @brief      Configures Partial Networking (PN) functionality for the TJA1145ATK CAN transceiver.
*               This function enables or disables PN wakeup capability by programming the relevant registers
*               via SPI, based on the configuration for the specified transceiver channel.
*               It sets the CAN control, event capture, frame control, WUF ID, and mask registers as required.
*   @param[in]  TrcvIdx  Index of the CAN transceiver to which the API call is applied.
*   @return     Status of the request:
*                   - E_OK:      The PN configuration was successfully applied.
*                   - E_NOT_OK:  The PN configuration failed or a hardware access error occurred.
*   @ServiceID  0x0f
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
static Std_ReturnType CanTrcv_Tja1145ATK_SetPN(uint8 TrcvIdx);

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
static CanTrcv_Tja1145ATK_InitType CanTrcv_Tja1145ATK_InitStatus = CANTRCV_TJA1145ATK_INIT_STATUS_NOT_ACTIVE;

/* This array is used for storing the Tja1145ATK register write data in the SPI SrcDataBufferPtr*/
static volatile uint8 CanTrcv_Tja1145ATK_WriteBufPtr[CANTRCV_TJA1145ATK_WRITE_DATA_LENGTH] __attribute__((aligned(4)));
/* This array is used for storing the Tja1145ATK register Read data in the SPI DesDataBufferPtr*/
static volatile uint8 CanTrcv_Tja1145ATK_ReadBufPtr[CANTRCV_TJA1145ATK_READ_DATA_LENGTH] __attribute__((aligned(4)));
/*Enumeration to define read and write operations for CAN transceiver TJA1145ATK*/
typedef enum 
{
    CANTRCV_TJA1145ATK_WRITE    = 0x00U,
    CANTRCV_TJA1145ATK_READ     = 0x01U
} CanTrcv_Tja1145ATK_Register_RW;
/********************************************************************************************************************
*   @brief      Initializes the internal state and hardware interface for the TJA1145ATK CAN transceiver.
*
*   This function performs the following steps:
*     - Sets the initial wakeup reason to error.
*     - Reads the Identification Register (ISR) to verify the presence of the transceiver.
*     - If the transceiver is present, sets the internal status to active.
*     - Reads the Event Capture Status (ECS) and System Event Status (SES) registers to check for power-on events.
*     - Reads the Transceiver Status (TS) register to check for system errors.
*     - Updates the internal wakeup reason based on the register values:
*         - If a power-on event is detected, sets the wakeup reason to power-on.
*         - If a system error is detected, sets the wakeup reason to system error.
*         - Otherwise, the wakeup reason remains as error.
*
*   @param      None
*   @return     None
*   @ServiceID  0x00
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
void CanTrcv_Tja1145ATK_Init(void)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 EcsRegVal;
    uint8 SesRegVal;
    uint8 TsRegVal;
    TjaWakeUpReason = CANTRCV_WU_ERROR;
    uint8 DriverIdx;
    uint8 TrcvIdx;
    uint8 BufIdx;
    for (BufIdx = 0U; BufIdx < CANTRCV_TJA1145ATK_READ_DATA_LENGTH; BufIdx++)
    {
        CanTrcv_Tja1145ATK_ReadBufPtr[BufIdx] = 0U;
    }
    for (BufIdx = 0U; BufIdx < CANTRCV_TJA1145ATK_WRITE_DATA_LENGTH; BufIdx++)
    {
        CanTrcv_Tja1145ATK_WriteBufPtr[BufIdx] = 0U;
    }
    for (TrcvIdx=0;TrcvIdx<CANTRCV_NUM_OF_TRCV_CHANNELS;TrcvIdx++)
    {  
        DriverIdx = CanTrcv_Tja1145ATK_TrcvToDriverId[TrcvIdx];
        if ((DriverIdx != CANTRCV_TJA1145ATK_INVALID_CHANNEL_ID) &&
            (DriverIdx < CANTRCV_TJA1145ATK_NUM_OF_TRCV_CHANNELS))
        {
            Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_INIT,
                CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
                CANTRCV_TJA1145_ADDR_ISR);
            if((Status == E_OK) && (CanTrcv_Tja1145ATK_ReadBufPtr[1] == CANTRCV_TJA1145_ISR_ID))
            {
                /* To Read  System event status from Event Capture Status register*/
                Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_INIT,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
                    CANTRCV_TJA1145_ADDR_ECS);
                if(Status == E_OK)
                {
                    EcsRegVal = CanTrcv_Tja1145ATK_ReadBufPtr[1];
                    /* To Read  Power-on event from System Event Status register */
                    Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_INIT,
                        CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
                        CANTRCV_TJA1145_ADDR_SES);
                }
                if(Status == E_OK)
                {
                    SesRegVal = CanTrcv_Tja1145ATK_ReadBufPtr[1];
                    /* To Read CAN Partial Networking Error   */   
                    Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_INIT,
                        CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                        CANTRCV_TJA1145_ADDR_TS);
                }
                if(Status == E_OK)
                {
                    TsRegVal = CanTrcv_Tja1145ATK_ReadBufPtr[1];
                    if(((EcsRegVal & CANTRCV_TJA1145_ADDR_ECS_SYSE) != 0x00u ) && 
                        ((SesRegVal & CANTRCV_TJA1145_ADDR_SES_PO) != 0x00u))
                    {
                        /* Power-on event detected: set wakeup reason to power-on */
                        TjaWakeUpReason = CANTRCV_WU_POWER_ON;
                    }
                    else if((TsRegVal & CANTRCV_TJA1145_ADDR_TS_CPNERR) != 0x00u)
                    {
                        /* System error detected in transceiver status: set wakeup reason to system error */
                        TjaWakeUpReason = CANTRCV_WU_BY_SYSERR;
                    }
                    else
                    {
                        /* No power-on or system error event detected: keep default wakeup reason (error) */
                    }
                }
                CanTrcv_Tja1145ATK_InitStatus = CANTRCV_TJA1145ATK_INIT_STATUS_ACTIVE;
            }
            else
            {
                /* Do Nothing */
            }
        }
    }   
}
/********************************************************************************************************************
*   @brief      This method sets the mode of the Transceiver to the value OpMode.
*   @param[in]  TrcvIdx  CAN transceiver TJA1145ATK channed Id to which API call has to be applied.
*   @param[in]  OpMode  This parameter contains the desired operating mode
*   @return     status of the request
*               - E_OK: will be returned if the request for transceiver mode change has been accepted.
*               - E_NOT_OK: will be returned if the request for transceiver mode change has not been accepted or any
*                 parameter is out of the allowed range.
*   @ServiceID  0x01
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_Tja1145ATK_SetOpMode(uint8 TrcvIdx, CanTrcv_TrcvModeType OpMode)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    uint8 sesVal;
    uint8 ecsVal;
    if(CanTrcv_Tja1145ATK_InitStatus == CANTRCV_TJA1145ATK_INIT_STATUS_NOT_ACTIVE)
    {
      ErrorId = CANTRCV_E_UNINIT;
    }
    else
    {
        if (CANTRCV_TJA1145ATK_NUM_OF_TRCV_CHANNELS >= TrcvIdx )
        {           
            uint8 DriverIdx = CanTrcv_Tja1145ATK_TrcvToDriverId[TrcvIdx];
            switch(OpMode)
            {
            /* Mode change request to NORMAL. */
            case CANTRCV_TRCVMODE_NORMAL:
                /*Set the device to Normal mode by writing to the Mode Control Register address 0x01*/
                Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_OPMODE,CANTRCV_TJA1145_REQ_OPMODENORMAL);
                if (Status == E_OK)
                {
                    /* Enable the transceiver by writing to the Can Control Register (address 0x20)*/
                    Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                        CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                        CANTRCV_TJA1145_ADDR_CANCTRL,CANTRCV_TJA1145_REQ_CANMODEACTIVE);
                    if((Status == E_OK) && (TjaWakeUpReason == CANTRCV_WU_ERROR)) 
                    {
                        /* If the wakeup reason is still 'error' after mode change,
                        set it to 'internally' to indicate an internal wakeup event. */
                        TjaWakeUpReason = CANTRCV_WU_INTERNALLY;
                    }
                }
                else 
                {
                    /* Do Nothing */
                }
                break;
                /* Mode change request to STANDBY */
            case CANTRCV_TRCVMODE_STANDBY:
                /*Set the device to STANDBY mode by writing to the Mode Control Register address 0x01*/
                Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
                    CANTRCV_TJA1145_ADDR_OPMODE,CANTRCV_TJA1145_REQ_OPMODESTANDBY);
                if (Status == E_OK)
                {
                    /* Enable the transceiver by writing to the Can Control Register (address 0x20)*/
                    Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_CANCTRL,CANTRCV_TJA1145_REQ_CANMODEOFFLINE);
                }
#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
                if (Status == E_OK)
                {
                    /* If Partial Networking (PN) support is enabled, configure the transceiver for PN mode.
                    This sets up the hardware to support selective wake-up via CAN frames as per PN requirements. */
                    Status = CanTrcv_Tja1145ATK_SetPN(TrcvIdx);
                }
#endif
                break;
            /* Mode change request to SLEEP*/
            case CANTRCV_TRCVMODE_SLEEP:
            {
                /*Read ECS and SES*/
                (void)CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_SETOPMODE, 
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_ECS);
                ecsVal = CanTrcv_Tja1145ATK_ReadBufPtr[1];  
                Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_SETOPMODE, 
                        CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                        CANTRCV_TJA1145_ADDR_SES);
                    sesVal = CanTrcv_Tja1145ATK_ReadBufPtr[1];
                /*Write back to ECS and SES to clear all events (write 1 to clear)*/
                if ((ecsVal != 0U) && (Status == E_OK)) {
                    Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                        CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
                        CANTRCV_TJA1145_ADDR_ECS,
                        ecsVal);
                }
                if ((sesVal != 0U) && (Status == E_OK)) {
                    Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                        CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
                        CANTRCV_TJA1145_ADDR_SES,
                        sesVal);
                }
                if(Status == E_OK)
                {       
                    /*Clear all wake-up events (TES and WES), Clear CAN Failure and CAN Wake-up*/
                    Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE, 
                        CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
                        CANTRCV_TJA1145_ADDR_TES,
                        CANTRCV_TJA1145_ADDR_TES_CF | CANTRCV_TJA1145_ADDR_TES_CW);
                }
                if(Status == E_OK)
                {
                    /* Clear WAKE pin rising/falling edg*/
                    Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE, 
                        CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
                        CANTRCV_TJA1145_ADDR_WES,
                        CANTRCV_TJA1145_ADDR_WES_WPR | CANTRCV_TJA1145_ADDR_WES_WPF);
                }
                if(Status == E_OK)
                {
                    /*Enable at least one wake-up source (CAN wake-up via TEE)*/ 
                    Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE, 
                        CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
                        CANTRCV_TJA1145_ADDR_TEE,
                        CANTRCV_TJA1145_TEE_ENABLE_CWE );
                }
                if(Status == E_OK)
                {
                    /*Set CANCTRL to offline (0x00)*/
                    Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE, 
                        CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
                        CANTRCV_TJA1145_ADDR_CANCTRL,
                        0x00U );
                }
                if(Status == E_OK)
                {
                    /*Request sleep (write 0x01 to OPMODE)*/ 
                    Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE, 
                        CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
                        CANTRCV_TJA1145_ADDR_OPMODE,
                        CANTRCV_TJA1145_REQ_OPMODESLEEP);
                }
                
#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
                if (Status == E_OK)
                {
                    Status = CanTrcv_Tja1145ATK_SetPN(TrcvIdx);
                }
#endif
            }
                break;
            default:
                break;
            }
       } 
    }
#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        CanTrcv_DetReportError(CANTRCV_SID_SETOPMODE,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}
/********************************************************************************************************************
*   @brief      This method gets the mode of the Transceiver and returns it in OpMode.
*   @param[in]  TrcvIdx  CAN transceiver to which API call has to be applied.
*   @param[out] OpMode  Pointer to operation mode of the bus the API is applied to.
*   @return     status of the request
*                   - E_OK: will be returned if the operation mode was detected.
*                   - E_NOT_OK: will be returned if the operation mode was not detected.
*   @ServiceID  0x02
*   @Sync/Async synchronous
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_Tja1145ATK_GetOpMode(uint8 TrcvIdx, CanTrcv_TrcvModeType* OpMode)
{ 
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    uint8 OpModeRegVal;
    uint8 CanModeRegVal;
    if(CanTrcv_Tja1145ATK_InitStatus == CANTRCV_TJA1145ATK_INIT_STATUS_NOT_ACTIVE)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (NULL_PTR == OpMode)
    {
        ErrorId = CANTRCV_E_PARAM_POINTER;
    }
    else
    {
        if (CANTRCV_TJA1145ATK_NUM_OF_TRCV_CHANNELS >= TrcvIdx)
        {
            uint8 DriverIdx = CanTrcv_Tja1145ATK_TrcvToDriverId[TrcvIdx];
            /* Read Mode Control Register address 0x01 */
            Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_GETOPMODE,
                CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                CANTRCV_TJA1145_ADDR_OPMODE);
            if (Status == E_OK)
            {
                OpModeRegVal = CanTrcv_Tja1145ATK_ReadBufPtr[1];
                /* Read Can Control Register (address 0x20) */
                Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_GETOPMODE,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_CANCTRL);
                if (Status == E_OK)
                {
                    CanModeRegVal = CanTrcv_Tja1145ATK_ReadBufPtr[1];
                    if((CANTRCV_TJA1145_REQ_OPMODENORMAL == OpModeRegVal)  && 
                        (CANTRCV_TJA1145_REQ_CANMODEACTIVE == CanModeRegVal))
                    {
                        *OpMode = CANTRCV_TRCVMODE_NORMAL;
                        Status = E_OK;
                    }
                    else if(CANTRCV_TJA1145_REQ_OPMODESTANDBY == OpModeRegVal)
                    {
                        *OpMode = CANTRCV_TRCVMODE_STANDBY;
                        Status = E_OK;
                    }
                    else if(CANTRCV_TJA1145_REQ_OPMODESLEEP == OpModeRegVal)
                    {
                        *OpMode = CANTRCV_TRCVMODE_SLEEP;
                        Status = E_OK;
                    }
                    else
                    {
                        Status = E_NOT_OK;
                    }
                }  
                else 
                {
                    /* Do Nothing */
                }
            }
            else 
            {
                /* Do Nothing */
            }
        }
    }
#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if (CANTRCV_E_NO_ERROR != ErrorId)
    {
        CanTrcv_DetReportError(CANTRCV_SID_GETOPMODE,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}

/********************************************************************************************************************
*   @brief      This method gets the wakeup reason for the Transceiver and returns it in parameter Reason.
*   @param[in]  TrcvIdx  CAN transceiver to which API call has to be applied.
*   @param[out] Reason  Pointer to wake up reason of the bus the API is applied to.
*   @return     status of the request
*                   - E_OK: will be returned if the transceiver wakeup reason was provided.
*                   - E_NOT_OK: will be returned if no wake up reason is available or if the service request failed
*                     due to development errors.
*   @ServiceID  0x03
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_Tja1145ATK_GetBusWuReason(uint8 TrcvIdx, CanTrcv_TrcvWakeupReasonType* Reason)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    CanTrcv_TrcvModeType CurrentOpMode;
    /* Check if module is initialized */
    if(CanTrcv_Tja1145ATK_InitStatus == CANTRCV_TJA1145ATK_INIT_STATUS_NOT_ACTIVE)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    /* Check if Reason pointer is NULL */
    else if (NULL_PTR == Reason)
    {
        ErrorId = CANTRCV_E_PARAM_POINTER;
    }
    else
    {  
#if (CANTRCV_GENERAL_WAKEUP_SUPPORT != CANTRCV_WAKEUP_NOT_SUPPORTED)
        if(TjaWakeUpReason == CANTRCV_WU_ERROR)
        {
            *Reason = CANTRCV_WU_ERROR;
            (void)CanTrcv_Tja1145ATK_GetOpMode(TrcvIdx,&CurrentOpMode);
            if(CurrentOpMode != CANTRCV_TRCVMODE_NORMAL)
            {
                ErrorId = CANTRCV_E_NO_TRCV_CONTROL;
            }
        }
        else
        {
            *Reason = TjaWakeUpReason;
            Status = E_OK;
        }
#else
        *Reason = CANTRCV_WU_NOT_SUPPORTED;
#endif
    }

#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if(CANTRCV_E_NO_ERROR != ErrorId)
    {   
        CanTrcv_DetReportError(CANTRCV_SID_GETBUSWUREASON,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}
#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      Reads the TJA1145 transceiver's main status, transceiver status, and WAKE pin status registers via SPI,
*               and returns their combined value through the TrcvSysData parameter.
*               This API is available only if Partial Networking (PN) support is enabled.
*   @param[in]  TrcvIdx      Index of the CAN transceiver to which the API call is applied.
*   @param[out] TrcvSysData  Pointer to a 32-bit variable to be updated with the combined status data.
*   @return     Status of the request:
*                   - E_OK:      The transceiver status was successfully read and returned.
*                   - E_NOT_OK:  The status data is not available or a hardware access error occurred.
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_TJA1145ATK_GetTrcvSystemData(uint8 TrcvIdx, uint32* TrcvSysData)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    uint32 regVal;
    uint8 MsRegVal;
    uint8 TrcvStatusRegVal;
    uint8 WpsRegVal;
    /* Check if module is initialized */
    if(CanTrcv_Tja1145ATK_InitStatus == CANTRCV_TJA1145ATK_INIT_STATUS_NOT_ACTIVE)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    /* Check if TrcvSysData pointer is NULL */
    else if (NULL_PTR == TrcvSysData)
    {
        ErrorId = CANTRCV_E_PARAM_POINTER;
    }
    else
    {
        if (CANTRCV_TJA1145ATK_NUM_OF_TRCV_CHANNELS >= TrcvIdx)
        {
            uint8 DriverIdx = CanTrcv_Tja1145ATK_TrcvToDriverId[TrcvIdx];
            /*Read Main Status Register (0x03)*/ 
            Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_GETTRCVSYSTEMDATA,
                CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                CANTRCV_TJA1145_ADDR_MS);
            if (Status == E_OK)
            {
                MsRegVal = CanTrcv_Tja1145ATK_ReadBufPtr[1];
                /*Read Transceiver Status Register (0x22)*/ 
                Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_GETTRCVSYSTEMDATA,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_TRCVSTATUS);
            }
            if (Status == E_OK)
            {
                TrcvStatusRegVal = CanTrcv_Tja1145ATK_ReadBufPtr[1];
                /*Read WAKE pin Status Register (0x4B)*/ 
                Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_GETTRCVSYSTEMDATA,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_WPS);
                if(Status == E_OK)
                {
                    WpsRegVal = CanTrcv_Tja1145ATK_ReadBufPtr[1];
                    regVal= ((uint32)MsRegVal) |
                    ((uint32)TrcvStatusRegVal << 0x08U) |
                    ((uint32)WpsRegVal << 0x10U);

                    *TrcvSysData = regVal;
                    Status = E_OK;
                }
                else
                {
                    /* Do Nothing */
                }
            }
            else
            {
                /* Do Nothing */
            }   
        }
        else
        {
            ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
        }
    
    }
#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if(CANTRCV_E_NO_ERROR != ErrorId)
    {   
        CanTrcv_DetReportError(CANTRCV_SID_GETTRCVSYSTEMDATA,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}
/********************************************************************************************************************
*   @brief      Clears the Wake-Up Flag (WUF) in the TJA1145 transceiver hardware by writing to the appropriate event
*               status registers via SPI. This API is available only if Partial Networking (PN) support is enabled.
*   @param[in]  TrcvIdx      Index of the CAN transceiver to which the API call is applied.
*   @return     Status of the request:
*                   - E_OK:      The WUF flag was successfully cleared in the transceiver hardware.
*                   - E_NOT_OK:  The WUF flag could not be cleared or a hardware access error occurred.
*   @ServiceID  0x0a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_TJA1145ATK_ClearTrcvWufFlag(uint8 TrcvIdx)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    uint8 RegDataValue;
    Std_ReturnType Result = E_NOT_OK;

    if(CanTrcv_Tja1145ATK_InitStatus == CANTRCV_TJA1145ATK_INIT_STATUS_NOT_ACTIVE)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else if (CANTRCV_TJA1145ATK_NUM_OF_TRCV_CHANNELS >= TrcvIdx)
    {
        uint8 DriverIdx = CanTrcv_Tja1145ATK_TrcvToDriverId[TrcvIdx];
        /* Clear CAN Wake-up and CAN Failure events in the Transceiver Event Status (TES) register */
        RegDataValue = (uint8)(CANTRCV_TJA1145_ADDR_TES_CF|CANTRCV_TJA1145_ADDR_TES_CW);
        Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_CLEARTRCVWUFFLAG,
            CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
            CANTRCV_TJA1145_ADDR_TES,RegDataValue);
        if(Status == E_OK)
        {
            /* Clear WAKE pin rising and falling edge events in the WAKE Event Status (WES) register */
            RegDataValue = (uint8)(CANTRCV_TJA1145_ADDR_WES_WPR|CANTRCV_TJA1145_ADDR_WES_WPF);
            Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_CLEARTRCVWUFFLAG,
                CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                CANTRCV_TJA1145_ADDR_WES,RegDataValue);
            if(Status == E_OK)
            {
                Result = CanTrcv_TJA1145ATK_CheckWakeFlag(TrcvIdx);
                if (Result == E_OK)
                {
                    Status = E_NOT_OK;
                }
                else
                {
                    Status = E_OK;
                }
            }
            else 
            {
                /* Do Nothing */
            }
        }
        else 
        {
            /* Do Nothing */
        }  
    }
    else
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if(CANTRCV_E_NO_ERROR != ErrorId)
    {   
        CanTrcv_DetReportError(CANTRCV_SID_CLEARTRCVWUFFLAG,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}
/********************************************************************************************************************
*   @brief      Reads the status of the timeout flag from the TJA1145 transceiver hardware. For TJA1145, a dedicated
*               timeout flag is not supported and this API always returns E_NOT_OK.
*               This API shall exist only if Partial Networking (PN) support is enabled.
*   @param[in]  TrcvIdx     Index of the CAN transceiver to which the API call is applied.
*   @param[out] FlagState   Pointer to be updated with the state of the timeout flag.
*   @return     Status of the request:
*                   - E_OK:      The status of the timeout flag was successfully read (not supported for TJA1145).
*                   - E_NOT_OK:  The status of the timeout flag could not be read or is not supported.
*   @ServiceID  0x0b
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_TJA1145ATK_ReadTrcvTimeoutFlag(uint8 TrcvIdx, CanTrcv_TrcvFlagStateType* FlagState)
{
    Std_ReturnType Status = E_NOT_OK;
    /*The TJA1145 does not support a separate timeout flag except as a wakeup event.
    This function is a stub and always returns E_OK*/ 
    CANTRCV_IGNORE_UNUSED_PARAM(TrcvIdx);
    CANTRCV_IGNORE_UNUSED_PARAM(FlagState);
    Status = E_OK;
    return Status;
}
/********************************************************************************************************************
*   @brief      Clears the status of the timeout flag in the TJA1145 transceiver hardware. For TJA1145, a dedicated
*               timeout flag is not supported and this API always returns E_NOT_OK.
*               This API shall exist only if Partial Networking (PN) support is enabled.
*   @param[in]  TrcvIdx      Index of the CAN transceiver to which the API call is applied.
*   @return     Status of the request:
*                   - E_OK:      The timeout flag was successfully cleared (not supported for TJA1145).
*                   - E_NOT_OK:  The timeout flag could not be cleared or is not supported.
*   @ServiceID  0x0c
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_TJA1145ATK_ClearTrcvTimeoutFlag(uint8 TrcvIdx)
{
    Std_ReturnType Status = E_NOT_OK;
    /* The TJA1145 does not support a dedicated timeout flag.
    This function is a stub and always returns E_NOT_OK.*/
    CANTRCV_IGNORE_UNUSED_PARAM(TrcvIdx);
    Status = E_OK;
    return Status;
}
/********************************************************************************************************************
*   @brief      Reads the status of the silence flag from the TJA1145 transceiver hardware. For TJA1145, a dedicated
*               silence flag is not supported and this API always returns E_NOT_OK.
*               This API shall exist only if Partial Networking (PN) support is enabled.
*   @param[in]  TrcvIdx     Index of the CAN transceiver to which the API call is applied.
*   @param[out] FlagState   Pointer to be updated with the state of the silence flag.
*   @return     Status of the request:
*                   - E_OK:      The status of the silence flag was successfully read (not supported for TJA1145).
*                   - E_NOT_OK:  The status of the silence flag could not be read or is not supported.
*   @ServiceID  0x0d
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_TJA1145ATK_ReadTrcvSilenceFlag(uint8 TrcvIdx, CanTrcv_TrcvFlagStateType* FlagState)
{
    Std_ReturnType Status = E_NOT_OK;
    /*The TJA1145 does not support a dedicated silence flag.
    This function is a stub and always returns E_NOT_OK.*/ 
    CANTRCV_IGNORE_UNUSED_PARAM(TrcvIdx);
    CANTRCV_IGNORE_UNUSED_PARAM(FlagState);
    Status = E_OK;
    return Status;
}

/********************************************************************************************************************
*   @brief      Checks  the wakeup flag in the TJA1145 transceiver hardware by writing to the appropriate
*               event status registers via SPI. This API is available only if Partial Networking (PN) support is enabled.
*   @param[in]  TrcvIdx      Index of the CAN transceiver to which the API call is applied.
*   @return     Status of the request:
*                   - E_OK:      The wakeup flag was successfully checked and cleared in the transceiver hardware.
*                   - E_NOT_OK:  The wakeup flag could not be checked or a hardware access error occurred.
*   @ServiceID  0x0e
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_TJA1145ATK_CheckWakeFlag(uint8 TrcvIdx)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    uint8 TesRegVal;
    uint8 WesRegVal;
    uint8 DriverIdx = CanTrcv_Tja1145ATK_TrcvToDriverId[TrcvIdx];
    if (CANTRCV_TJA1145ATK_NUM_OF_TRCV_CHANNELS > DriverIdx)
    {
        /* Read the Transceiver Event Status (TES) register to check for CAN wake-up or CAN failure events */
        Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_CHECKWAKEFLAG,
            CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
            CANTRCV_TJA1145_ADDR_TES);
        if(Status == E_OK )
        {
            TesRegVal = CanTrcv_Tja1145ATK_ReadBufPtr[1];
            /* Read the WAKE Event Status (WES) register to check for WAKE pin rising or falling edge events */
            Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_CHECKWAKEFLAG,
                CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId,
                CANTRCV_TJA1145_ADDR_WES);
            if(Status == E_OK )
            {
                WesRegVal = CanTrcv_Tja1145ATK_ReadBufPtr[1];
                if(((TesRegVal & (uint8)(CANTRCV_TJA1145_ADDR_TES_CF | CANTRCV_TJA1145_ADDR_TES_CW)) != 0U) &&
                        ((WesRegVal & (uint8)(CANTRCV_TJA1145_ADDR_WES_WPR | CANTRCV_TJA1145_ADDR_WES_WPF)) != 0U))
                {
                    Status = E_OK;
                }
                else
                {
                    Status = E_NOT_OK;
                }
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            /* Do Nothing */
        }    
    }
    else
    {
        ErrorId = CANTRCV_E_INVALID_TRANSCEIVER;
    }
#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if(CANTRCV_E_NO_ERROR != ErrorId)
    {   
        CanTrcv_DetReportError(CANTRCV_SID_CHECKWAKEUP,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}
#endif
/*!******************************************************************************************************************
*   @brief      This method is the main function for the CAN transceiver driver. It checks for wakeup events on all
*               transceiver channels and handles them appropriately.
*   @return     void
********************************************************************************************************************/
void CanTrcv_Tja1145ATK_MainFunction(void)
{

}
/********************************************************************************************************************
 * @brief  helper function to write a value to a TJA1145 register via SPI.
 * @param regAddr Register address to write.
 * @param data    Data to write to the register.
 * @return E_OK if SPI operations succeed, E_NOT_OK otherwise.
 ********************************************************************************************************************/
static Std_ReturnType CanTrcv_Tja1145ATK_SpiWriteReg(uint8 ErrorIdApi ,Spi_ChannelType SpiChannel, uint8 regAddr, uint8 data)
{
    Std_ReturnType Status;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    CanTrcv_Tja1145ATK_WriteBufPtr[0] = CanTrcv_Tja1145ATK_Get_Addr_RW(regAddr, CANTRCV_TJA1145ATK_WRITE);
    CanTrcv_Tja1145ATK_WriteBufPtr[1] = data;
    Status = Spi_SetupEB(SpiChannel,(volatile uint8 *)&CanTrcv_Tja1145ATK_WriteBufPtr[0],
                                                                            NULL,CANTRCV_TJA1145ATK_WRITE_DATA_LENGTH);
    if (Status == E_OK)
    {
        Status = Spi_SyncTransmit(SpiChannel);;
    }
    else
    {
        ErrorId = CANTRCV_E_NO_TRCV_CONTROL;
    }
#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
        if(CANTRCV_E_NO_ERROR != ErrorId)
        {   
            CanTrcv_DetReportError(ErrorIdApi,ErrorId);
        }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    
    return Status;
}
/********************************************************************************************************************
 * @brief  helper function to write a value to a TJA1145 register via SPI.
 * @param regAddr Register address to write.
 * @param data    Data to write to the register.
 * @return E_OK if SPI operations succeed, E_NOT_OK otherwise.
 ********************************************************************************************************************/
static Std_ReturnType CanTrcv_Tja1145ATK_SpiReadReg(uint8 ErrorIdApi ,Spi_ChannelType SpiChannel, uint8 RegAddr)
{
    Std_ReturnType Status;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    CanTrcv_Tja1145ATK_WriteBufPtr[0] = CanTrcv_Tja1145ATK_Get_Addr_RW(RegAddr, CANTRCV_TJA1145ATK_READ);
            /*Set the second byte of the SPI write buffer to 0x00 (dummy data for a read operation)
            During the read operation, the second byte is ignored by the TJA1145A, and the device outputs the register 
            value on SDO*/
    CanTrcv_Tja1145ATK_WriteBufPtr[1] = CANTRCV_TJA1145_READ_DUMMYVALUE;
    Status = Spi_SetupEB(SpiChannel,(volatile uint8 *)&CanTrcv_Tja1145ATK_WriteBufPtr[0],
                        (volatile uint8 *)&CanTrcv_Tja1145ATK_ReadBufPtr[0],CANTRCV_TJA1145ATK_WRITE_DATA_LENGTH);
    if (Status == E_OK)
    {
        Status = Spi_SyncTransmit(SpiChannel);
    }
    else
    {
        ErrorId = CANTRCV_E_NO_TRCV_CONTROL;
    }
#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if(CANTRCV_E_NO_ERROR != ErrorId)
    {   
        CanTrcv_DetReportError(ErrorIdApi,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif

    return Status;
}
#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      Configures Partial Networking (PN) functionality for the TJA1145ATK CAN transceiver.
*               This function enables or disables PN wakeup capability by programming the relevant registers
*               via SPI, based on the configuration for the specified transceiver channel.
*               It sets the CAN control, event capture, frame control, WUF ID, and mask registers as required.
*   @param[in]  TrcvIdx  Index of the CAN transceiver to which the API call is applied.
*   @return     Status of the request:
*                   - E_OK:      The PN configuration was successfully applied.
*                   - E_NOT_OK:  The PN configuration failed or a hardware access error occurred.
*   @ServiceID  0x0f
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
static Std_ReturnType CanTrcv_Tja1145ATK_SetPN(uint8 TrcvIdx)
{
    Std_ReturnType Status = E_NOT_OK;
    uint8 ErrorId = CANTRCV_E_NO_ERROR;
    uint8 RegDataValue;
    uint8 DriverIdx = CanTrcv_Tja1145ATK_TrcvToDriverId[TrcvIdx];
#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
    if (CanTrcv_Tja1145ATK_InitStatus == CANTRCV_TJA1145ATK_INIT_STATUS_NOT_ACTIVE)
    {
        ErrorId = CANTRCV_E_UNINIT;
    }
    else
    {
        if(CanTrcv_PnEnabled[TrcvIdx]   == TRUE)
        {
            /* Set CAN control register (0x20): Enable PN (CPNC = 1, PNCOK = 1) */
            RegDataValue = (uint8)(CANTRCV_TJA1145_CANCTRL_CPNC | CANTRCV_TJA1145_CANCTRL_PNCOK);
            Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                CANTRCV_TJA1145_ADDR_CANCTRL,RegDataValue);
            if(Status == E_OK)
            {
                /* Set Transceiver event capture enable register (0x23): Enable PN (CWE =1) */
                Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_TEE,CANTRCV_TJA1145_TEE_ENABLE_CWE);
            }
            if(Status == E_OK)
            {
                /* Frame control register (0x2F): partial networking data mask( PNDM =0) &  Standard 11-bit format*/
                Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_FC,CANTRCV_TJA1145_READ_DUMMYVALUE);
            }
            if(Status == E_OK)
            {
                /* Set ID registers for WUF identifier  */
                RegDataValue = (uint8)(((CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].WufId) >> 3) & 0xFFU);/*Upper 8 bits*/
                Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_IDREG2,RegDataValue);   
            }
            if(Status == E_OK)
            {
                RegDataValue = (uint8)((CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].WufId) & 0x07U);/*Lower 3 bits*/
                Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_IDREG3,RegDataValue);
            }
            if(Status == E_OK)
            {
                /* Set Mask registers for mask 0x007 ,Mask for bits 2-0*/
                RegDataValue = (uint8)(((CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].WufMask) >> 3) & 0xFFU); 
                Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_MASKREG2,RegDataValue);
            }
            if(Status == E_OK)
            {
                /* Set MASKREG3: bits 2:0 (lower 3 bits of 11-bit mask) */
                RegDataValue = (uint8)((CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].WufMask) & 0x07U); /*Mask for lower bits*/ 
                Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_MASKREG3,RegDataValue);
            }
            if(Status == E_OK)
            {
                /* Verify PN configuration (read Transceiver Status register 0x22) */
                Status = CanTrcv_Tja1145ATK_SpiReadReg(CANTRCV_SID_SETOPMODE,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_TRCVSTATUS);
            }
            if ((CanTrcv_Tja1145ATK_ReadBufPtr[1] & CANTRCV_TJA1145_TRCVSTATUS_CPNS) != 0U)
            {
                Status = E_OK; /*PN configuration successful*/
            }
            else
            {
                /* Fall back to standard wake-up if PN configuration fails */
                Status = CanTrcv_Tja1145ATK_SpiWriteReg(CANTRCV_SID_SETOPMODE,
                    CanTrcv_Tja1145ATK_SpiCfg[DriverIdx].SpiChannelId, 
                    CANTRCV_TJA1145_ADDR_CANCTRL,CANTRCV_TJA1145_READ_DUMMYVALUE);
                ErrorId = CANTRCV_E_NO_TRCV_CONTROL;
            }
        }
        else 
        {
            Status = E_OK; 
        }
    }
#endif
#if(CANTRCV_DEV_ERROR_REPORT == STD_ON)
    if(CANTRCV_E_NO_ERROR != ErrorId)
    {   
        CanTrcv_DetReportError(CANTRCV_SID_SETPNACTIVATIONSTATE,ErrorId);
    }
#else
    CANTRCV_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return Status;
}
#endif
/*******************************************************************************************************************
*   For each change to this file, be sure to record:                                                               *
*      1.  who made the change and when the change was made                                                        *
*      2.  why the change was made and the intended result                                                         *
*   Following block needs to be repeated for each change                                                           *
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date    19-May-2025
*  @version 0.0.1
*  @author  sbaskar3
*  @brief   Initial version implementation
*******************************************************************************************************************/

