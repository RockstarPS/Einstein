/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
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
*  File Name         :  LedDrv.c                                             *
*  Module Short Name :  leddrv-tlc6c5724                                     *
*  VOBName           :                                                       *
*  Author            : sdv                                                   *
*  Description       : This file contains LedDrv module handling             *
                        Functionalities                                      *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang                                                  *
* Target Hardware  :  Independent                                            *
*                                                                            *
******************************************************************************/


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "LedDrv.h"
#include "Dio.h"
#include "MemLib.h"
#include "Spi.h"

#define LED_DRIVER_CODE_SEC_START
#include "MemMap.h"
#define LED_DRIVER_CODE_SEC_START
#include "MemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define LEDDRV_LOD2_POS                    0U
#define LEDDRV_LOD1_POS                    3U
#define LEDDRV_LSD2_POS                    12U
#define LEDDRV_LSD1_POS                    15U

#define LEDDRV_FAULT_FLAG_ARRAYSIZE        ((LEDDRV_NUM_OF_LEDS >> 3U) + 1U)
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef enum
{
    LEDDRV_IDLE,
    LEDDRV_SEND_ERROR_CLEAR,
    LEDDRV_WAIT_ERROR_CLEAR,
    LEDDRV_SEND_GLOBAL_RST,
    LEDDRV_WAIT_GLOBAL_RST,
    LEDDRV_SEND_FC_BC_DC_SETTINGS,
    LEDDRV_WAIT_FC_BC_DC_SETTINGS,
    LEDDRV_SEND_GRAY_SCALE_SETTINGS,
    LEDDRV_WAIT_GRAY_SCALE_SETTINGS,
    LEDDRV_CHECK_ERR_PIN,
    LEDDRV_SEND_SID_CMD,
    LEDDRV_WAIT_SID_CMD,
    LEDDRV_READ_SID_DATA,
    LEDDRV_WAIT_SID_DATA,
} LedDrvStateMachineType;

static boolean               LedDrv_CallBackServiced;
static LedDrvStateMachineType LedDrv_StateMachine;
static boolean               LedDrv_DirtyFlag;
static boolean               DCRangeFlag;


/***************************************************************************
 * Locally used Variable Declarations
 ***************************************************************************/
/* Buffers to store the values in actual format 0 - 288 bits */
static FC_BC_DC_Reg_t LedDrv_FC_BC_DC_Buffer[LEDDRV_NUM_OF_CHIPS];

static GS_Reg_t       LedDrv_GS_Buffer[LEDDRV_NUM_OF_CHIPS];

/* Snapshot buffer for GS bytes (diagnostics). Must hold full chain size. */
static uint8          LedDrv_LedStatus[LEDDRV_DATA_LENGTH];

/* Per-chip GS dirty mask (bit i -> chip i GS changed) */
static uint8          LedDrv_GSDirtyMask = 0u;

/* Stores the reversed data of the Buffer - 288 bit needs to be sent 1st */
static uint8 LedDrv_FC_BC_DC_GlobalrstBuf_Rev[LEDDRV_DATA_LENGTH];
static uint8 LedDrv_FC_BC_DC_ErrorBuf_Rev[LEDDRV_DATA_LENGTH];
static uint8 LedDrv_FC_BC_DC_Buffer_Rev[LEDDRV_DATA_LENGTH];
static uint8 LedDrv_FC_BC_DC_SidBuff_Rev[LEDDRV_DATA_LENGTH];
static uint8 LedDrv_SpiBuffer_Rx[LEDDRV_DATA_LENGTH];

/* Driver should have default value as 0; APP SWC will set brightness values */
static uint16 LedDrv_Last_Brightness[LEDDRV_NUM_OF_LEDS] = { 0U };
/* Driver should have default value as 0; APP SWC will set current values */
static uint16 LedDrv_Last_Current[LEDDRV_NUM_OF_LEDS] = { 0U };
/* App request status ON/OFF, used to decide HW update */
static boolean LedDrv_App_Status[LEDDRV_NUM_OF_LEDS] = { FALSE };
/* Last brightness value sent to HW */
static uint16 LedDrv_Last_Brightness_To_HW[LEDDRV_NUM_OF_LEDS] = { 0U };
/* Previous fault status bitmap */
/* Store the previous error state of LED as the error was present or not */
static uint8 LedDrv_Previous_Fault_oc[LEDDRV_FAULT_FLAG_ARRAYSIZE] = { 0U };
/* Current fault status per LED */
static LedDrv_FaultStatusType LedDrv_FaultStatus[LEDDRV_NUM_OF_LEDS] = { 0U };

/* Bit position of GS Data */
static const uint16 LedDrv_GS_Position[LEDDRV_POSITION_SIZE] =
{ 288, 276, 264, 252, 240, 228, 216, 204, 192, 180, 168, 156,
  144, 132, 120, 108, 96,  84,  72,  60,  48,  36,  24,  12 };

/***************************************************************************
 * Limited Scope Prototypes
 ***************************************************************************/
static Std_ReturnType LedDrv_ErrorBufInit(void);
static Std_ReturnType LedDrv_GlobalRstBufInit(void);
static Std_ReturnType LedDrv_FCBCDCBufInit(void);
static Std_ReturnType LedDrv_SIDBufInit(void);
static void           LedDrv_StateMachineProcess(void);
static Std_ReturnType LedDrv_LED_Brightness_Update(LedDrv_LedChannelType ChannelId,
                                                   uint16 BrightnessValue,
                                                   uint16 CurrentValue);
static void           LedDrv_FCBCDCBuff_Update(uint16 LedDrv_CfgIndex, uint16 CurrentValue);
static void           LedDrv_Find_DC_BCData(float32 Currentratio, uint8_t *DC_data, uint8_t *BC_data);
static void           LedDrv_UpdateDCData(uint8 ChipPosition, uint8 BitPosition, uint16 DCData);
static void           LedDrv_GSBuff_Update(uint16 LedDrv_CfgIndex, uint16 BrightnessValue);
static void           LedDrv_FaultUpdate(void);
static void           LedDrv_FaultInform(void);
static void           LedDrv_Clear_LED_Fault(uint8 LedDrv_LedNum);
static void           LedDrv_Inform_LED_Fault(uint8 LedDrv_LedNum, uint8 Leddrv_Fault);

/* LookUp table for High DC Range */
static LedDrv_DC_LookUpTable_Type LedDrv_DC_LookUpTable[LEDDRV_DC_MAX_LEVEL] = {
    {0x00, 0xFF, 33.3f, 0.0f},
    {0x01, 0xFF, 33.9f, 0.5f},
    {0x02, 0xFF, 34.4f, 1.0f},
    {0x03, 0xFF, 34.9f, 1.6f},
    {0x04, 0xFF, 35.4f, 2.1f},
    {0x05, 0xFF, 36.0f, 2.6f},
    {0x06, 0xFF, 36.5f, 3.1f},
    {0x07, 0xFF, 37.0f, 3.7f},
    {0x08, 0xFF, 37.5f, 4.2f},
    {0x09, 0xFF, 38.0f, 4.7f},
    {0x0A, 0xFF, 38.5f, 5.3f},
    {0x0B, 0xFF, 39.0f, 5.8f},
    {0x0C, 0xFF, 39.6f, 6.3f},
    {0x0D, 0xFF, 40.1f, 6.8f},
    {0x0E, 0xFF, 40.7f, 7.3f},
    {0x0F, 0xFF, 41.2f, 7.9f},
    {0x10, 0xFF, 41.7f, 8.4f},
    {0x11, 0xFF, 42.2f, 9.0f},
    {0x12, 0xFF, 42.7f, 9.5f},
    {0x13, 0xFF, 43.3f, 10.0f},
    {0x14, 0xFF, 43.8f, 10.5f},
    {0x15, 0xFF, 44.3f, 11.0f},
    {0x16, 0xFF, 44.9f, 11.5f},
    {0x17, 0xFF, 45.4f, 12.1f},
    {0x18, 0xFF, 45.9f, 12.6f},
    {0x19, 0xFF, 46.4f, 13.1f},
    {0x1A, 0xFF, 47.0f, 13.7f},
    {0x1B, 0xFF, 47.5f, 14.2f},
    {0x1C, 0xFF, 48.0f, 14.7f},
    {0x1D, 0xFF, 48.5f, 15.2f},
    {0x1E, 0xFF, 49.0f, 15.7f},
    {0x1F, 0xFF, 49.6f, 16.3f},
    {0x20, 0xFF, 50.1f, 16.8f},
    {0x21, 0xFF, 50.6f, 17.3f},
    {0x22, 0xFF, 51.1f, 17.9f},
    {0x23, 0xFF, 51.7f, 18.4f},
    {0x24, 0xFF, 52.2f, 18.9f},
    {0x25, 0xFF, 52.7f, 19.4f},
    {0x26, 0xFF, 53.2f, 20.0f},
    {0x27, 0xFF, 53.8f, 20.5f},
    {0x28, 0xFF, 54.3f, 21.0f},
    {0x29, 0xFF, 54.8f, 21.5f},
    {0x2A, 0xFF, 55.3f, 22.0f},
    {0x2B, 0xFF, 55.9f, 22.6f},
    {0x2C, 0xFF, 56.4f, 23.1f},
    {0x2D, 0xFF, 57.0f, 23.6f},
    {0x2E, 0xFF, 57.5f, 24.1f},
    {0x2F, 0xFF, 58.0f, 24.7f},
    {0x30, 0xFF, 58.5f, 25.2f},
    {0x31, 0xFF, 59.0f, 25.7f},
    {0x32, 0xFF, 59.5f, 26.3f},
    {0x33, 0xFF, 60.1f, 26.8f},
    {0x34, 0xFF, 60.6f, 27.3f},
    {0x35, 0xFF, 61.1f, 27.8f},
    {0x36, 0xFF, 61.7f, 28.3f},
    {0x37, 0xFF, 62.2f, 28.9f},
    {0x38, 0xFF, 62.7f, 29.4f},
    {0x39, 0xFF, 63.2f, 30.0f},
    {0x3A, 0xFF, 63.7f, 30.5f},
    {0x3B, 0xFF, 64.3f, 31.0f},
    {0x3C, 0xFF, 64.8f, 31.5f},
    {0x3D, 0xFF, 65.3f, 32.0f},
    {0x3E, 0xFF, 65.8f, 32.5f},
    {0x3F, 0xFF, 66.4f, 33.1f},
    {0x40, 0xFF, 67.0f, 33.6f},
    {0x41, 0xFF, 67.4f, 34.1f},
    {0x42, 0xFF, 68.0f, 34.7f},
    {0x43, 0xFF, 68.5f, 35.2f},
    {0x44, 0xFF, 69.0f, 35.7f},
    {0x45, 0xFF, 69.5f, 36.2f},
    {0x46, 0xFF, 70.1f, 36.7f},
    {0x47, 0xFF, 70.6f, 37.3f},
    {0x48, 0xFF, 71.1f, 37.8f},
    {0x49, 0xFF, 71.6f, 38.3f},
    {0x4A, 0xFF, 72.1f, 38.8f},
    {0x4B, 0xFF, 72.7f, 39.4f},
    {0x4C, 0xFF, 73.2f, 39.9f},
    {0x4D, 0xFF, 73.7f, 40.4f},
    {0x4E, 0xFF, 74.2f, 41.0f},
    {0x4F, 0xFF, 74.8f, 41.5f},
    {0x50, 0xFF, 75.3f, 42.0f},
    {0x51, 0xFF, 75.8f, 42.5f},
    {0x52, 0xFF, 76.3f, 43.0f},
    {0x53, 0xFF, 76.9f, 43.6f},
    {0x54, 0xFF, 77.4f, 44.1f},
    {0x55, 0xFF, 78.0f, 44.6f},
    {0x56, 0xFF, 78.5f, 45.1f},
    {0x57, 0xFF, 79.0f, 45.7f},
    {0x58, 0xFF, 79.5f, 46.2f},
    {0x59, 0xFF, 80.0f, 46.7f},
    {0x5A, 0xFF, 80.5f, 47.2f},
    {0x5B, 0xFF, 81.1f, 47.8f},
    {0x5C, 0xFF, 81.6f, 48.3f},
    {0x5D, 0xFF, 82.1f, 48.8f},
    {0x5E, 0xFF, 82.7f, 49.3f},
    {0x5F, 0xFF, 83.2f, 49.9f},
    {0x60, 0xFF, 83.7f, 50.4f},
    {0x61, 0xFF, 84.2f, 51.0f},
    {0x62, 0xFF, 84.7f, 51.5f},
    {0x63, 0xFF, 85.3f, 52.0f},
    {0x64, 0xFF, 85.8f, 52.5f},
    {0x65, 0xFF, 86.3f, 53.0f},
    {0x66, 0xFF, 86.9f, 53.5f},
    {0x67, 0xFF, 87.4f, 54.1f},
    {0x68, 0xFF, 88.0f, 54.6f},
    {0x69, 0xFF, 88.4f, 55.1f},
    {0x6A, 0xFF, 89.0f, 55.7f},
    {0x6B, 0xFF, 89.5f, 56.2f},
    {0x6C, 0xFF, 90.0f, 56.7f},
    {0x6D, 0xFF, 90.5f, 57.2f},
    {0x6E, 0xFF, 91.0f, 57.7f},
    {0x6F, 0xFF, 91.6f, 58.3f},
    {0x70, 0xFF, 92.1f, 58.8f},
    {0x71, 0xFF, 92.6f, 59.3f},
    {0x72, 0xFF, 93.1f, 59.9f},
    {0x73, 0xFF, 93.7f, 60.4f},
    {0x74, 0xFF, 94.2f, 60.9f},
    {0x75, 0xFF, 94.7f, 61.4f},
    {0x76, 0xFF, 95.2f, 62.0f},
    {0x77, 0xFF, 95.8f, 62.5f},
    {0x78, 0xFF, 96.3f, 63.0f},
    {0x79, 0xFF, 96.8f, 63.5f},
    {0x7A, 0xFF, 97.3f, 64.0f},
    {0x7B, 0xFF, 97.9f, 64.6f},
    {0x7C, 0xFF, 98.4f, 65.1f},
    {0x7D, 0xFF, 99.0f, 65.6f},
    {0x7E, 0xFF, 99.5f, 66.1f},
    {0x7F, 0xFF, 100.0f, 66.7f},
};

/***************************************************************************
 * Functions
 ***************************************************************************/

/*============================================================================
**
** Function Name    :   LedDrv_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
void LedDrv_Init(void)
{
    uint8 flRetVal = E_NOT_OK;

    flRetVal = LedDrv_ErrorBufInit();
    if(flRetVal == E_OK)
    {
        flRetVal = LedDrv_GlobalRstBufInit();
        flRetVal = LedDrv_SIDBufInit();
        if(flRetVal == E_OK)
        {
            flRetVal = LedDrv_FCBCDCBufInit();
        }
    }

    if(flRetVal == E_OK)
    {
        /* Set BLANK low - GS Counter is initialized */
        Dio_WriteChannel(LEDDRV_PIN_BLANK, STD_LOW);
        LedDrv_CallBackServiced = FALSE;
        LedDrv_StateMachine      = LEDDRV_SEND_ERROR_CLEAR;
    }
}

/*============================================================================
**
** Function Name    :   LedDrv_MainFunction
**
** Visibility       :   Public
**
** Description      :   This function is invoked periodically by the oS.
**                      This function process the requested function of Error
**                      clear, Reset, FC-BC-DC write, GS write and SID read of
**                      LedDrv through Spi.
**
** Invocation       :   Os Scheduling.
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
void LedDrv_MainFunction(void)
{
    LedDrv_StateMachineProcess();
}

/*============================================================================
**
** Function Name    :   LedDrv_WriteChannel
**
** Visibility       :   Public
**
** Description      :   This function turn/off the requested Led Channel.
**
** Invocation       :   Application
**
** Inputs           :   LedDrv_LedChannelType ChannelId - Led Channel Id.
**                      boolean OutputSignal - Signal type ON/OFF (0/1)
**
** Outputs          :   E_OK - Success
**                      E_NOT_OK - Failure
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType LedDrv_WriteChannel(LedDrv_LedChannelType ChannelId, boolean OutputSignal)
{
    /* LedDrv_WriteChannel() will turn ON/OFF LEDs*/
    /* LedDrv_WriteChannel() also sets % PWM (0xxxx) for LEDs*/
    Std_ReturnType fl_RetVal = E_OK;
    uint16 fl_BrightnessValue = (uint16)0;

    if(ChannelId < LEDDRV_NUM_OF_LEDS)
    {
        if(FALSE != OutputSignal)
        {
#ifdef LEDDRV_LED_ON_WITH_LAST_SET_BRIGHTNESS
            /* Switch on LED with last set brightness */
            fl_BrightnessValue = LedDrv_Last_Brightness[ChannelId];
#else
            /* Switch on LED with 100% brightness */
            fl_BrightnessValue = LEDDRV_MAX_BRIGHTNESS;
            LedDrv_Last_Current[ChannelId] = LEDDRV_DEFAULT_CURRENT;

#endif
        }
        else
        {
            /* Switch OFF the LED - 0% brightness and 0 Current */
        }

        /* Save status so brightness update hits HW only when needed */
        LedDrv_App_Status[ChannelId] = OutputSignal;
        fl_RetVal = LedDrv_LED_Brightness_Update(ChannelId,
                                                 fl_BrightnessValue,
                                                 LedDrv_Last_Current[ChannelId]);
    }
    else
    {
        /* Invalid ChannelId */
        fl_RetVal = E_NOT_OK;
    }

    return fl_RetVal;
}

/*============================================================================
**
** Function Name    :   LedDrv_SetBrightness
**
** Visibility       :   Public
**
** Description      :   The function sets the brightness and Current for the
**                      requested Led Channel.
**
** Invocation       :   Application
**
** Inputs           :   LedDrv_LedChannelType ChannelId - Led Channel Id.
**                      uint16 BrightnessValue - Brightness Value
**                      uint16 CurrentValue - Current Value
**
** Outputs          :   E_OK - Success
**                      E_NOT_OK - Failure
**
** Critical Section :   No
**
**==========================================================================*/
extern Std_ReturnType LedDrv_SetBrightness(LedDrv_LedChannelType ChannelId, uint16 BrightnessValue, uint16 CurrentValue)
{
    Std_ReturnType fl_RetVal = E_OK;

    if((ChannelId < LEDDRV_NUM_OF_LEDS) &&
       ((BrightnessValue <= LEDDRV_MAX_BRIGHTNESS)) &&
       ((CurrentValue   <= LEDDRV_MAX_CURRENT)))
    {
        LedDrv_Last_Brightness[ChannelId] = BrightnessValue;
        LedDrv_Last_Current[ChannelId]    = CurrentValue;

        if(FALSE != LedDrv_App_Status[ChannelId])
        {
            fl_RetVal = LedDrv_LED_Brightness_Update(ChannelId,
                                                     LedDrv_Last_Brightness[ChannelId],
                                                     LedDrv_Last_Current[ChannelId]);
        }
    }
    else
    {
        fl_RetVal = E_NOT_OK;
    }
    return fl_RetVal;
}

/*============================================================================
** Function Name : LedDrv_McspiJob2EndNotification
** Visibility    : Public
** Description   : SPI sequence end callback.
**
** Invocation       :   I2C
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void LedDrv_McspiJob2EndNotification(void)
{
    LedDrv_CallBackServiced = TRUE;
    Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_LOW);
}

/***************************************************************************
 * Limited Scope APIs
 ***************************************************************************/

/*============================================================================
**
** Function Name    :   LedDrv_StateMachineProcess
**
** Visibility       :   Private
**
** Description      :   Local State Machine function to transfer data accordingly
**
** Invocation       :   static
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static void LedDrv_StateMachineProcess(void)
{
    uint8 fl_Index;
    uint8 Read_sts = 0;
    uint8 Err_pin1_lvl;
    static boolean LocalPWMFlag = FALSE;

    switch(LedDrv_StateMachine)
    {
        case LEDDRV_IDLE:
            if(FALSE != LedDrv_DirtyFlag)
            {
                LedDrv_StateMachine = LEDDRV_SEND_GRAY_SCALE_SETTINGS;
                LedDrv_DirtyFlag    = FALSE;
            }
            else
            {
                /* Copy GS → LedStatus only for chips whose GS changed */
                if (LedDrv_GSDirtyMask != 0u)
                {
                    for (fl_Index = 0u; fl_Index < LEDDRV_NUM_OF_CHIPS; fl_Index++)
                    {
                        if ((LedDrv_GSDirtyMask & (uint8)(1u << fl_Index)) != 0u)
                        {
                            /* Per-chip copy into correct offset (36 bytes/chip) */
                            MemLib_MemCpy(&LedDrv_LedStatus[fl_Index * LEDDRV_NUM_OF_BYTES_PER_CHIP],
                                          &LedDrv_GS_Buffer[fl_Index].value[0],
                                          LEDDRV_NUM_OF_BYTES_PER_CHIP);
                        }
                    }
                    /* Clear mask once snapshot done */
                    LedDrv_GSDirtyMask = 0u;
                }

                LedDrv_StateMachine = LEDDRV_CHECK_ERR_PIN;
            }
        break;

        case LEDDRV_SEND_ERROR_CLEAR:
            (void)Spi_SetupEB(LEDDRV_SPI_CHANNEL_ID,
                              (uint8 *)&LedDrv_FC_BC_DC_ErrorBuf_Rev[0], NULL,
                              LEDDRV_DATA_LENGTH);
            Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_HIGH);
            (void)Spi_AsyncTransmit(LEDDRV_SPI_CHANNEL_ID);
            LedDrv_StateMachine = LEDDRV_WAIT_ERROR_CLEAR;
        break;

        case LEDDRV_WAIT_ERROR_CLEAR:
            if(LedDrv_CallBackServiced == TRUE)
            {
                LedDrv_CallBackServiced = FALSE;
                Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_HIGH);
                LedDrv_StateMachine = LEDDRV_SEND_GLOBAL_RST;
            }
        break;

        case LEDDRV_SEND_GLOBAL_RST:
            (void)Spi_SetupEB(LEDDRV_SPI_CHANNEL_ID,
                              (uint8 *)&LedDrv_FC_BC_DC_GlobalrstBuf_Rev[0], NULL,
                              LEDDRV_DATA_LENGTH);
            Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_HIGH);
            (void)Spi_AsyncTransmit(LEDDRV_SPI_CHANNEL_ID);
            LedDrv_StateMachine = LEDDRV_WAIT_GLOBAL_RST;
        break;

        case LEDDRV_WAIT_GLOBAL_RST:
            if(LedDrv_CallBackServiced == TRUE)
            {
                LedDrv_CallBackServiced = FALSE;
                Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_HIGH);
                LedDrv_StateMachine = LEDDRV_SEND_FC_BC_DC_SETTINGS;
                Dio_WriteChannel(LEDDRV_PIN_BLANK, STD_HIGH);
            }
        break;

        case LEDDRV_SEND_FC_BC_DC_SETTINGS:
            (void)Spi_SetupEB(LEDDRV_SPI_CHANNEL_ID,
                              (uint8 *)&LedDrv_FC_BC_DC_Buffer_Rev[0], NULL,
                              LEDDRV_DATA_LENGTH);
            Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_HIGH);
            (void)Spi_AsyncTransmit(LEDDRV_SPI_CHANNEL_ID);
            LedDrv_StateMachine = LEDDRV_WAIT_FC_BC_DC_SETTINGS;
        break;

        case LEDDRV_WAIT_FC_BC_DC_SETTINGS:
            if(LedDrv_CallBackServiced == TRUE)
            {
                LedDrv_CallBackServiced = FALSE;
                Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_HIGH);
                LedDrv_StateMachine = LEDDRV_IDLE;
            }
        break;

        case LEDDRV_SEND_GRAY_SCALE_SETTINGS:
            /* Send GS as raw bytes from the union's byte view */
            (void)Spi_SetupEB(LEDDRV_SPI_CHANNEL_ID,
                              (uint8 *)&LedDrv_GS_Buffer[0].value[0], NULL,
                              LEDDRV_DATA_LENGTH);
            Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_LOW);
            (void)Spi_AsyncTransmit(LEDDRV_SPI_CHANNEL_ID);
            LedDrv_StateMachine = LEDDRV_WAIT_GRAY_SCALE_SETTINGS;
        break;

        case LEDDRV_WAIT_GRAY_SCALE_SETTINGS:
            if(LedDrv_CallBackServiced == TRUE)
            {
                LedDrv_CallBackServiced = FALSE;
                Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_HIGH);
                /*Pin Mismatch - PWM pin is not connected in hw - Turn On and Off - using GCLK - Since PWM is not there and we can't control the brightness*/
                LocalPWMFlag = TRUE;
                LedDrv_StateMachine = LEDDRV_SEND_FC_BC_DC_SETTINGS;
            }
        break;

        case LEDDRV_CHECK_ERR_PIN:
            Err_pin1_lvl = Dio_ReadChannel(Main_GPIO0_LED_ERR);
            if(Err_pin1_lvl == (uint8)STD_LOW)
            {
                LedDrv_StateMachine = LEDDRV_SEND_SID_CMD;
            }
            else
            {
                LedDrv_StateMachine = LEDDRV_IDLE;
            }
        break;

        case LEDDRV_SEND_SID_CMD:
            (void)Spi_SetupEB(LEDDRV_SPI_CHANNEL_ID,
                              (uint8 *)&LedDrv_FC_BC_DC_SidBuff_Rev[0], NULL,
                              LEDDRV_DATA_LENGTH);
            Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_HIGH);
            (void)Spi_AsyncTransmit(LEDDRV_SPI_CHANNEL_ID);
            LedDrv_StateMachine = LEDDRV_WAIT_SID_CMD;
        break;

        case LEDDRV_WAIT_SID_CMD:
            if(LedDrv_CallBackServiced == TRUE)
            {
                LedDrv_CallBackServiced = FALSE;
                Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_LOW);
                LedDrv_StateMachine = LEDDRV_READ_SID_DATA;
            }
        break;

        case LEDDRV_READ_SID_DATA:
            Read_sts = Spi_SetupEB(LEDDRV_SPI_CHANNEL_ID,
                                   (uint8 *)&LedDrv_FC_BC_DC_Buffer_Rev[0],
                                   (uint8 *)&LedDrv_SpiBuffer_Rx[0],
                                   LEDDRV_DATA_LENGTH);
            Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_HIGH);
            if(Read_sts == (uint8)E_OK)
            {
                (void)Spi_AsyncTransmit(LEDDRV_SPI_CHANNEL_ID);
                LedDrv_StateMachine = LEDDRV_WAIT_SID_DATA;
            }
            else
            {
                LedDrv_StateMachine = LEDDRV_IDLE;
            }
        break;

        case LEDDRV_WAIT_SID_DATA:
            if(LedDrv_CallBackServiced == TRUE)
            {
                LedDrv_CallBackServiced = FALSE;
                Dio_WriteChannel(LEDDRV_PIN_LATCH, STD_HIGH);
                LedDrv_FaultUpdate();
                LedDrv_FaultInform();
                LedDrv_StateMachine = LEDDRV_IDLE;
            }
        break;

        default:
            /* Do Nothing */
        break;
    }

    if(LocalPWMFlag == TRUE)
    {
        (void)Dio_FlipChannel(Main_GPIO0_LED_GCLK);
    }
}

/*============================================================================
**
** Function Name    :   LedDrv_ErrorBufInit
**
** Visibility       :   Private
**
** Description      :   This function sets the Error clear value/cmd in the
**                      assigned buffer
**
** Invocation       :   Static
**
** Inputs           :   None
**
** Outputs          :   E_OK - Initialized
**                      E_NOT_OK - Not Initialized
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType LedDrv_ErrorBufInit(void)
{
    Std_ReturnType flRetVal = E_NOT_OK;
    uint8 flChipIndex, i, j, next_i = 0;
    static FC_BC_DC_Reg_t LedDrv_FC_BC_DC_ErrorBuf[LEDDRV_NUM_OF_CHIPS];

    for(flChipIndex = 0; flChipIndex < LEDDRV_NUM_OF_CHIPS; flChipIndex++)
    {
        MemLib_MemSet((uint8*)(&(LedDrv_FC_BC_DC_ErrorBuf[LEDDRV_NUM_OF_CHIPS - flChipIndex - 1U].value[0])), 0x00U, LEDDRV_NUM_OF_BYTES_PER_CHIP);
        /* Data will be stored the data as to satisfy the daisy chain network. Ex: if we have 2 chips in daisy chain -
        LedDrv_FC_BC_DC_ErrorBuf[0].value[0] - chip 2, LedDrv_FC_BC_DC_ErrorBuf[1].value[0] - chip 1 */
        LedDrv_FC_BC_DC_ErrorBuf[LEDDRV_NUM_OF_CHIPS - flChipIndex - 1U].bits.cmd = LEDDRV_ERR_CLR;

        for (i = next_i, j = (LEDDRV_NUM_OF_BYTES_PER_CHIP - 1U ); (i < LEDDRV_DATA_LENGTH) && (j != 255U ); i++, j--)
        {
            /* Reversing the data to send the 288 bit 1st */
            LedDrv_FC_BC_DC_ErrorBuf_Rev[i] = LedDrv_FC_BC_DC_ErrorBuf[LEDDRV_NUM_OF_CHIPS - flChipIndex - 1U].value[j];
            if(j == 0U)
            {
                next_i = i + 1U;
            }
        }
        flRetVal = E_OK;
    }
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   LedDrv_GlobalRstBufInit
**
** Visibility       :   Private
**
** Description      :   This function sets the Reset clear value/cmd in the
**                      assigned buffer
**
** Invocation       :   Static
**
** Inputs           :   None
**
** Outputs          :   E_OK - Initialized
**                      E_NOT_OK - Not Initialized
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType LedDrv_GlobalRstBufInit(void)
{
    Std_ReturnType flRetVal = E_NOT_OK;
    uint8 flChipIndex, i, j, next_i = 0;
    FC_BC_DC_Reg_t LedDrv_FC_BC_DC_GlobalrstBuf[LEDDRV_NUM_OF_CHIPS];
    for(flChipIndex = 0; flChipIndex < LEDDRV_NUM_OF_CHIPS; flChipIndex++)
    {
        MemLib_MemSet((uint8*)(&(LedDrv_FC_BC_DC_GlobalrstBuf[LEDDRV_NUM_OF_CHIPS - flChipIndex - 1U].value[0])), 0x00, LEDDRV_NUM_OF_BYTES_PER_CHIP);
        /* Data will be stored the data as to satisfy the daisy chain network. Ex: if we have 2 chips in daisy chain -
        LedDrv_FC_BC_DC_GlobalrstBuf[0].value[0] - chip 2, LedDrv_FC_BC_DC_GlobalrstBuf[1].value[0] - chip 1 */
        LedDrv_FC_BC_DC_GlobalrstBuf[LEDDRV_NUM_OF_CHIPS - flChipIndex - 1U].bits.cmd = LEDDRV_GLOBAL_RST;

        for (i = next_i, j = (LEDDRV_NUM_OF_BYTES_PER_CHIP - 1U ); (i < LEDDRV_DATA_LENGTH) && (j != 255U); i++, j--)
        {
            /* Reversing the data to send the 288 bit 1st */
            LedDrv_FC_BC_DC_GlobalrstBuf_Rev[i] = LedDrv_FC_BC_DC_GlobalrstBuf[LEDDRV_NUM_OF_CHIPS - flChipIndex - 1U].value[j];
            if(j == 0U)
            {
                next_i = i + 1U;
            }
        }
        flRetVal = E_OK;
    }

    return flRetVal;
}

/*============================================================================
**
** Function Name    :   LedDrv_FCBCDCBufInit
**
** Visibility       :   Private
**
** Description      :   This function configures the FC BC DC Data with the
**                      configured value
**
** Invocation       :   Static
**
** Inputs           :   None
**
** Outputs          :   E_OK - Initialized
**                      E_NOT_OK - Not Initialized
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType LedDrv_FCBCDCBufInit(void)
{
    Std_ReturnType flRetVal = E_NOT_OK;
    uint8 flChipIndex, i, j, next_i = 0;
    uint8 fl_ChipIndex_INBuffer;

    for(flChipIndex = 0; flChipIndex < LEDDRV_NUM_OF_CHIPS; flChipIndex++)
    {
        if(flChipIndex == LedDrv_FCConfig[flChipIndex].LedDrv_ChipIndex)
        {
            /* Cascaded: last chip data stored first for SPI shift */
            fl_ChipIndex_INBuffer = LEDDRV_NUM_OF_CHIPS - LedDrv_LedConfig[flChipIndex].ChipPosition - 1U;

            /* FIX: clear only this chip's payload (36 bytes), not entire chain */
            MemLib_MemSet((uint8*)(&(LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].value[0])),
                          0x00U, LEDDRV_NUM_OF_BYTES_PER_CHIP);

            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.led_err_mask = LedDrv_FCConfig[flChipIndex].LedMask;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.slew_rate     = LedDrv_FCConfig[flChipIndex].SlewRate;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.lod_voltage   = LedDrv_FCConfig[flChipIndex].LODThresold;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.lsd_voltage   = LedDrv_FCConfig[flChipIndex].LSDThresold;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.aps_current   = LedDrv_FCConfig[flChipIndex].APSCurrent;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.aps_time      = LedDrv_FCConfig[flChipIndex].APSTime;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.gs_mode       = LedDrv_FCConfig[flChipIndex].GSCounterMode;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.timing_reset  = LedDrv_FCConfig[flChipIndex].TimingReset;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.auto_repeat   = LedDrv_FCConfig[flChipIndex].AutoRepeatMode;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.dc_range_b    = LedDrv_FCConfig[flChipIndex].DcRange_Blue;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.dc_range_g    = LedDrv_FCConfig[flChipIndex].DcRange_Green;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.dc_range_r    = LedDrv_FCConfig[flChipIndex].DcRange_Red;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.outg_bc = 0xFFU;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.outr_bc = 0xFFU;
            LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_INBuffer].bits.outb_bc = 0xFFU;

            for (i = next_i, j = (LEDDRV_NUM_OF_BYTES_PER_CHIP - 1U); (i < LEDDRV_DATA_LENGTH) && (j != 255U); i++, j--)
            {
                /* Reversing the data to send the 288 bit 1st */
                LedDrv_FC_BC_DC_Buffer_Rev[i] = LedDrv_FC_BC_DC_Buffer[LEDDRV_NUM_OF_CHIPS - flChipIndex - 1U].value[j];
                if(j == 0U)
                {
                    next_i = i + 1U;
                }
            }
            flRetVal = E_OK;
        }
    }
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   LedDrv_SIDBufInit
**
** Visibility       :   Private
**
** Description      :   This function sets the SID read value/cmd in the
**                      assigned buffer
**
** Invocation       :   Static
**
** Inputs           :   None
**
** Outputs          :   E_OK - Initialized
**                      E_NOT_OK - Not Initialized
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType LedDrv_SIDBufInit(void)
{
    Std_ReturnType flRetVal = E_NOT_OK;
    uint8 flChipIndex, i, j, next_i = 0;
    FC_BC_DC_Reg_t LedDrv_FC_BC_DC_SidBuff[LEDDRV_NUM_OF_CHIPS];

    for(flChipIndex = 0; flChipIndex < LEDDRV_NUM_OF_CHIPS; flChipIndex++)
    {
        MemLib_MemSet((uint8*)(&(LedDrv_FC_BC_DC_SidBuff[LEDDRV_NUM_OF_CHIPS - flChipIndex - 1U].value[0])), 0x00, LEDDRV_NUM_OF_BYTES_PER_CHIP);
        /* Data will be stored the data as to satisfy the daisy chain network. Ex: if we have 2 chips in daisy chain -
        LedDrv_FC_BC_DC_SidBuff[0].value[0] - chip 2, LedDrv_FC_BC_DC_SidBuff[1].value[0] - chip 1 */
        LedDrv_FC_BC_DC_SidBuff[LEDDRV_NUM_OF_CHIPS - flChipIndex - 1U].bits.cmd = LEDDRV_SID_READ;

        for (i = next_i, j = (LEDDRV_NUM_OF_BYTES_PER_CHIP - 1U); (i < LEDDRV_DATA_LENGTH) && (j != 225U); i++, j--)
        {
            /* Reversing the data to send the 288 bit 1st */
            LedDrv_FC_BC_DC_SidBuff_Rev[i] = LedDrv_FC_BC_DC_SidBuff[LEDDRV_NUM_OF_CHIPS - flChipIndex - 1U].value[j];
            if(j == 0U)
            {
                next_i = i + 1U;
            }
        }
        flRetVal = E_OK;
    }
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   LedDrv_LED_Brightness_Update
**
** Visibility       :   Private
**
** Description      :   This function sets requested Brightness and Current
**                      value for LED
**
** Invocation       :   Static
**
** Inputs           :   LedDrv_LedChannelType ChannelId - ChannelId of Led
**                      requested
**                      uint16 BrightnessValue - Brightness Value
**                      uint16 CurrentValue - Current Value
**
** Outputs          :   E_OK - Initialized
**                      E_NOT_OK - Not Initialized
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType LedDrv_LED_Brightness_Update(LedDrv_LedChannelType ChannelId,
                                                   uint16 BrightnessValue,
                                                   uint16 CurrentValue)
{
    uint8  fl_RetVal           = E_NOT_OK;
    uint16 fl_LedDrv_CfgIndex  = 0U;

    /* Find config index for ChannelId */
    for(fl_LedDrv_CfgIndex = 0U; fl_LedDrv_CfgIndex < LEDDRV_NUM_OF_LEDS; fl_LedDrv_CfgIndex++)
    {
        if(ChannelId == LedDrv_LedConfig[fl_LedDrv_CfgIndex].LedIndex)
        {
            fl_RetVal = E_OK;
            break;
        }
    }

    /* Range checks */
    if(!(BrightnessValue <= LEDDRV_MAX_BRIGHTNESS))
    {
        fl_RetVal = E_NOT_OK;
    }
    if(!(CurrentValue <= LEDDRV_MAX_CURRENT))
    {
        fl_RetVal = E_NOT_OK;
    }
    if(fl_LedDrv_CfgIndex < LEDDRV_NUM_OF_LEDS)
    {
        if((LedDrv_LedConfig[fl_LedDrv_CfgIndex].BitPosition) >= LEDDRV_NUM_OF_LEDS)
        {
            /* BitPosition must be < number of LED outputs per driver */
            fl_RetVal = E_NOT_OK;
        }
    }
    else
    {
        fl_RetVal = E_NOT_OK;
    }

    if(fl_RetVal == E_OK)
    {
        /* FIX: Update HW if either brightness OR current changed */
        if((LedDrv_Last_Brightness_To_HW[ChannelId] != BrightnessValue) ||
           (LedDrv_Last_Current[ChannelId]        != CurrentValue))
        {
            /* GS Value Update */
            LedDrv_GSBuff_Update(fl_LedDrv_CfgIndex, BrightnessValue);
            /* FC-BC-DC value Update */
            LedDrv_FCBCDCBuff_Update(fl_LedDrv_CfgIndex, CurrentValue);

            /* Mark GS frame to be sent next cycle */
            LedDrv_DirtyFlag = TRUE;
            /* Save last brightness sent to HW */
            LedDrv_Last_Brightness_To_HW[ChannelId] = BrightnessValue;
        }
        else
        {
            /* Same value; do nothing */
        }
    }
    return fl_RetVal;
}

/*============================================================================
**
** Function Name    :   LedDrv_FCBCDCBuff_Update
**
** Visibility       :   Private
**
** Description      :   This function calculates the current ratio and updates
**                      the current value.
**
** Invocation       :   Static
**
** Inputs           :   uint16 LedDrv_CfgIndex - Led Index
**                      uint16 CurrentValue - Current Value
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static void LedDrv_FCBCDCBuff_Update(uint16 LedDrv_CfgIndex, uint16 CurrentValue)
{
    uint8  fl_Group;
    uint8  fl_ChipPosition;
    uint8  fl_BitPosition;
    float32 fl_CurrentRatio;
    uint16 fl_DCData;
    uint16 fl_BCData;
    uint8 flChipIndex, i, j, next_i = 0U;

    fl_Group       = LedDrv_LedConfig[LedDrv_CfgIndex].Group;
    fl_ChipPosition= LedDrv_LedConfig[LedDrv_CfgIndex].ChipPosition;
    fl_BitPosition = LedDrv_LedConfig[LedDrv_CfgIndex].BitPosition;
    fl_CurrentRatio = ((float32)CurrentValue / LEDDRV_MAX_CURRENT) * 100.0f;

    /* Determine DC range flag per color group */
    if(fl_Group == LEDDRV_GROUPR)
    {
        DCRangeFlag = (LedDrv_FCConfig[fl_ChipPosition].DcRange_Red   == LedDrv_LowDcRange_Red);
    }
    else if(fl_Group == LEDDRV_GROUPG)
    {
        DCRangeFlag = (LedDrv_FCConfig[fl_ChipPosition].DcRange_Green == LedDrv_LowDcRange_Green);
    }
    else
    {
        DCRangeFlag = (LedDrv_FCConfig[fl_ChipPosition].DcRange_Blue  == LedDrv_LowDcRange_Blue);
    }

    /* Look-up DC/BC data */
    LedDrv_Find_DC_BCData(fl_CurrentRatio, (uint8_t *)&fl_DCData, (uint8_t *)&fl_BCData);

    /* Update DC value into FC/BC/DC register */
    LedDrv_UpdateDCData(fl_ChipPosition, fl_BitPosition, fl_DCData);

    /* Rebuild reversed chain for SPI */
    for(flChipIndex = 0; flChipIndex < LEDDRV_NUM_OF_CHIPS; flChipIndex++)
    {
        for (i = next_i, j = (LEDDRV_NUM_OF_BYTES_PER_CHIP - 1U); (i < LEDDRV_DATA_LENGTH) && (j != 255U); i++, j--)
        {
            /* Reversing the data to send the 288 bit 1st */
            LedDrv_FC_BC_DC_Buffer_Rev[i] = LedDrv_FC_BC_DC_Buffer[LEDDRV_NUM_OF_CHIPS - flChipIndex - 1U].value[j];
            if(j == 0U)
            {
                next_i = i + 1U;
            }
        }
    }
}

/*============================================================================
**
** Function Name    :   LedDrv_Find_DC_BCData
**
** Visibility       :   Private
**
** Description      :   This function finds the dc and bc value in the lookup
**                      table
**
** Invocation       :   Static
**
** Inputs           :   float32 Currentratio - Current ratio value
**                      uint8_t *DC_data - Buffer to store DC Value
**                      uint8_t *BC_data - Buffer to store BC Value
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static void LedDrv_Find_DC_BCData(float32 Currentratio, uint8_t *DC_data, uint8_t *BC_data)
{
    uint8 flClosest_Index = 0U;
    float32 flMin_Diff = LEDDRV_FLT_MAX;
    float32 flDiff;
    uint8 i;

    for (i = 0U;i < LEDDRV_DC_MAX_LEVEL; i++)
    {
        if(DCRangeFlag == TRUE)
        {
            flDiff = LedDrv_DC_LookUpTable[i].LedDrv_CurrentRatio_LowDCRange - Currentratio;
        }
        else
        {
            flDiff = LedDrv_DC_LookUpTable[i].LedDrv_CurrentRatio_HighDCRange - Currentratio;
        }

        if (flDiff < 0U) { flDiff = -flDiff; }

        if (flDiff < flMin_Diff)
        {
            flMin_Diff = flDiff;
            flClosest_Index = i;
        }
    }

    *DC_data = LedDrv_DC_LookUpTable[flClosest_Index].LedDrv_DcData;
    *BC_data = LedDrv_DC_LookUpTable[flClosest_Index].LedDrv_BcData;
}

/*============================================================================
**
** Function Name    :   LedDrv_UpdateDCData
**
** Visibility       :   Private
**
** Description      :   This function updates the DC Value in FC BC DC register
**
** Invocation       :   Static
**
** Inputs           :   uint8 ChipPosition - Chip number of the Led
**                      uint8 BitPosition - Bit position of the Led Connected
**                      uint16 DCData - Dc value
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static void LedDrv_UpdateDCData(uint8 ChipPosition, uint8 BitPosition, uint16 DCData)
{
    uint8 fl_ChipIndex_InBuffer;

    /* Cascaded order: last chip first in buffer */
    fl_ChipIndex_InBuffer = LEDDRV_NUM_OF_CHIPS - ChipPosition - 1U;

    switch (BitPosition)
    {
        case 0:  LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outr0_dc = DCData; break;
        case 1:  LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outg0_dc = DCData; break;
        case 2:  LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outb0_dc = DCData; break;
        case 3:  LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outr1_dc = DCData; break;
        case 4:  LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outg1_dc = DCData; break;
        case 5:  LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outb1_dc = DCData; break;
        case 6:  LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outr2_dc = DCData; break;
        case 7:  LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outg2_dc = DCData; break;
        case 8:  LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outb2_dc = DCData; break;
        case 9:  LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outr3_dc = DCData; break;
        case 10: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outg3_dc = DCData; break;
        case 11: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outb3_dc = DCData; break;
        case 12: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outr4_dc = DCData; break;
        case 13: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outg4_dc = DCData; break;
        case 14: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outb4_dc = DCData; break;
        case 15: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outr5_dc = DCData; break;
        case 16: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outg5_dc = DCData; break;
        case 17: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outb5_dc = DCData; break;
        case 18: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outr6_dc = DCData; break;
        case 19: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outg6_dc = DCData; break;
        case 20: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outb6_dc = DCData; break;
        case 21: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outr7_dc = DCData; break;
        case 22: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outg7_dc = DCData; break;
        case 23: LedDrv_FC_BC_DC_Buffer[fl_ChipIndex_InBuffer].bits.outb7_dc = DCData; break;
        default:
            /* out-of-range BitPosition: ignore */
        break;
    }
}

/*============================================================================
**
** Function Name    :   LedDrv_GSBuff_Update
**
** Visibility       :   Private
**
** Description      :   This function updates the GS Register value accordingly
**                      taking the brighness value
**
** Invocation       :   Static
**
** Inputs           :   uint16 LedDrv_CfgIndex - Led Index
**                      uint16 BrightnessValue - Brightness Value
**
** Outputs          :   E_OK - Initialized
**                      E_NOT_OK - Not Initialized
**
** Critical Section :   No
**
**==========================================================================*/
static void LedDrv_GSBuff_Update(uint16 LedDrv_CfgIndex, uint16 BrightnessValue)
{
    uint16 fl_StartBitOffset;
    uint16 fl_UpdateBytePosition;
    uint16 fl_UpdateBitPosition;
    uint16 fl_BitPositionTraverse;
    uint16 fl_GSValue = BrightnessValue;
    uint8  fl_BitStatus = 0U;
    uint8  fl_ChipPosition;
    uint8  fl_ChipIndex_InBuffer;

    fl_ChipPosition       = LedDrv_LedConfig[LedDrv_CfgIndex].ChipPosition;
    /* Cascaded: last chip first in buffer for SPI chain */
    fl_ChipIndex_InBuffer = LEDDRV_NUM_OF_CHIPS - fl_ChipPosition - 1U;

    /* Scale Brightness (0..1000) to GS max selected in config (10-bit => 0..1023) */
    fl_GSValue = (BrightnessValue * LEDDRV_GS_MAX_VAL) / LEDDRV_MAX_BRIGHTNESS;

    /* Element mapping: LedConfig BitPosition -> GS bit start offset */
    fl_StartBitOffset = LedDrv_GS_Position[LedDrv_LedConfig[LedDrv_CfgIndex].BitPosition] - 1U;

    /* 12-bit GS per output packed MSB-first into bytes; update per-bit */
    for(fl_BitPositionTraverse = 0; fl_BitPositionTraverse < LEDDRV_GS_CONTROL_WIDTH; fl_BitPositionTraverse++)
    {
        fl_UpdateBytePosition = ((uint16)fl_ChipIndex_InBuffer * LEDDRV_NUM_OF_BYTES_PER_CHIP)
                              + (fl_StartBitOffset / (uint16)8U);
        fl_UpdateBitPosition  = 7U - (fl_StartBitOffset % 8U);

        /* Set X% duty-cycle for LED ON */
        fl_BitStatus = (((uint16)0U != (fl_GSValue & ((uint16)1U << fl_BitPositionTraverse))) ? 1U : 0U);

        if (fl_UpdateBytePosition < (LEDDRV_DATA_LENGTH))
        {
            if(0U != fl_BitStatus)
            {
                LedDrv_GS_Buffer[fl_ChipIndex_InBuffer].value[fl_UpdateBytePosition] |= (0x01U) << fl_UpdateBitPosition;
            }
            else
            {
                LedDrv_GS_Buffer[fl_ChipIndex_InBuffer].value[fl_UpdateBytePosition] &= ~(uint8)((0x01U) << fl_UpdateBitPosition);
            }
        }

        fl_StartBitOffset--;
    }

    /* Mark this chip's GS as changed so snapshot can be done once */
    LedDrv_GSDirtyMask |= ((uint8)1u << fl_ChipIndex_InBuffer);
}

/*============================================================================
**
** Function Name    :   LedDrv_FaultUpdate
**
** Visibility       :   Private
**
** Description      :   This function updates the fault in Led
**
** Invocation       :   Static
**
** Inputs           :   void
**
** Outputs          :   void
**
** Critical Section :   No
**
**==========================================================================*/
static void LedDrv_FaultUpdate(void)
{
    uint8  fl_LOD1 = 0U;
    uint8  fl_LOD2 = 0U;
    uint8  fl_LSD1 = 0U;
    uint8  fl_LSD2 = 0U;
    uint8  fl_LedPos = 0U;
    uint16 fl_UpdateBytePosition = 0U;
    uint16 fl_Index = 0U;
    uint16 fl_LedVal = 0U;
    uint8  fl_ByteOrNib = 0U;
    uint8  fl_Byteload = 0U;
    uint8  fl_BRow = 0U;
    uint8  fl_GRow = 0U;
    uint8  fl_RRow = 0U;
    uint8  i;
    uint8  j;
    uint8  k;

    /* Parse SID flags per chip / batch BGR / output */
    for (k = 0U; k < LEDDRV_NUM_OF_CHIPS; k++)/*select chip */
    {
        for (j = 0U; j < 3U; j++)/*select batch BGR*/
        {
            for (i = 0U; i < 8U; i++)/*select individual fault data */
            {
                fl_LedPos = (uint8)(LEDDRV_NUM_OF_LEDS - 1) - ((2U - j) * 8U) - i - (k * (uint8)LEDDRV_NUM_OF_LEDS_PER_CHIP);
                if (fl_LedPos < (LEDDRV_NUM_OF_LEDS))
                {
                    fl_LOD1 = 0U;
                    fl_LOD2 = 0U;
                    fl_LSD1 = 0U;
                    fl_LSD2 = 0U;
                    fl_LOD2 = 0x01U & (LedDrv_SpiBuffer_Rx[j + LEDDRV_LOD2_POS + (((uint8)(LEDDRV_NUM_OF_CHIPS - 1U) - k) * (uint8)LEDDRV_NUM_OF_BYTES_PER_CHIP)] >> i);
                    fl_LOD1 = 0x01U & (LedDrv_SpiBuffer_Rx[j + LEDDRV_LOD1_POS + (((uint8)(LEDDRV_NUM_OF_CHIPS - 1U) - k) * (uint8)LEDDRV_NUM_OF_BYTES_PER_CHIP)] >> i);
                    fl_LSD2 = 0x01U & (LedDrv_SpiBuffer_Rx[j + LEDDRV_LSD2_POS + (((uint8)(LEDDRV_NUM_OF_CHIPS - 1U) - k) * (uint8)LEDDRV_NUM_OF_BYTES_PER_CHIP)] >> i);
                    fl_LSD1 = 0x01U & (LedDrv_SpiBuffer_Rx[j + LEDDRV_LSD1_POS + (((uint8)(LEDDRV_NUM_OF_CHIPS - 1U) - k) * (uint8)LEDDRV_NUM_OF_BYTES_PER_CHIP)] >> i);
                    if ((fl_LOD1 == 0U) && (fl_LOD2 == 0U) && (fl_LSD1 == 0U) && (fl_LSD2 == 1U))
                    {
                        LedDrv_FaultStatus[fl_LedPos] = LEDDRV_OK;
                    }
                    else if ((fl_LOD1 == 1U) && (fl_LOD2 == 0U) && (fl_LSD1 == 0U) && (fl_LSD2 == 1U))
                    {
                        LedDrv_FaultStatus[fl_LedPos] = LEDDRV_OPEN;
                    }
                    else if ((fl_LOD1 == 0U) && (fl_LOD2 == 0U) && (fl_LSD1 == 1U) && (fl_LSD2 == 1U))
                    {
                        LedDrv_FaultStatus[fl_LedPos] = LEDDRV_SHORT;
                    }
                    else if ((fl_LOD1 == 1U) && (fl_LOD2 == 1U) && (fl_LSD1 == 0U) && (fl_LSD2 == 0U))
                    {
                        LedDrv_FaultStatus[fl_LedPos] = LEDDRV_SHORT_GND;
                    }
                    else
                    {
                        /*do nothing*/
                    }
                }
            }
        }
    }
    i=0;
    j=0;
    for (j = 0; j < (uint8)LEDDRV_NUM_OF_LEDS; j++)/*Check which LED's are turned on from the GS Buffer*/
    {
        fl_LedVal = (uint16)0;
        for (fl_Byteload = 0; fl_Byteload < 2U; fl_Byteload++)/*load 12bit GS value to led_val*/
        {
            if (fl_UpdateBytePosition < (LEDDRV_DATA_LENGTH))
            {
                if (fl_ByteOrNib == 0U)
                {
                    fl_LedVal |= (LedDrv_LedStatus[fl_UpdateBytePosition] & (uint16)0xff);
                    if (fl_Byteload == 1U)
                    {
                        fl_ByteOrNib = 0U;
                    }
                    else
                    {
                        fl_ByteOrNib = 1U;
                    }
                    fl_UpdateBytePosition++;
                }
                else if (fl_ByteOrNib == 1U)
                {
                    fl_LedVal = fl_LedVal << (uint16)0x04;
                    fl_LedVal |= ((LedDrv_LedStatus[fl_UpdateBytePosition] & (uint16)0xf0) >> (uint16)4);
                    fl_ByteOrNib = 2U;
                }
                else if (fl_ByteOrNib == 2U)
                {
                    fl_LedVal |= (LedDrv_LedStatus[fl_UpdateBytePosition] & (uint16)0x0f);
                    fl_LedVal = fl_LedVal << 0x08U;
                    fl_ByteOrNib = 0U;
                    fl_UpdateBytePosition++;
                }
                else
                {
                    /*do nothing*/
                }
            }
        }

        if (i == 2U)
        {
            fl_Index = fl_RRow + (uint16)16;
            i = 0U;
            fl_RRow++;
            if (j == 23U)
            {
                fl_BRow = 0U;
                fl_GRow = 0U;
                fl_RRow = 0U;
            }
        }
        else if (i == 1U)
        {
            fl_Index = fl_GRow + (uint16)8;
            i = 2U;
            fl_GRow++;
        }
        else
        {
            fl_Index = fl_BRow;
            i = 1U;
            fl_BRow++;
        }

        if (j >= (uint8)LEDDRV_NUM_OF_LEDS_PER_CHIP)
        {
            fl_Index += (uint16)LEDDRV_NUM_OF_LEDS_PER_CHIP;
        }

        if ((fl_LedVal == 0U) && (fl_Index < (LEDDRV_NUM_OF_LEDS)))
        {
            LedDrv_FaultStatus[fl_Index] = LEDDRV_OK;
        }
    }
}

/*============================================================================
**
** Function Name    :   LedDrv_FaultInform
**
** Visibility       :   Private
**
** Description      :   This function informs and clears the fault in the led
**
** Invocation       :   Static
**
** Inputs           :   void
**
** Outputs          :   void
**
** Critical Section :   No
**
**==========================================================================*/
static void LedDrv_FaultInform(void)
{
    uint8   fl_Index;
    uint8   fl_FaultIndex;
    uint8   fl_ArrayIndex = 0;
    boolean fl_StatusUpdate_Flg = FALSE;

    for(fl_Index = 0U; fl_Index < LEDDRV_NUM_OF_LEDS; fl_Index++)
    {
        if(0U != LedDrv_FaultStatus[(uint8)(LEDDRV_NUM_OF_LEDS - 1) - fl_Index])
        {
            fl_StatusUpdate_Flg = FALSE;
            LedDrv_Inform_LED_Fault(fl_Index, (uint8)LedDrv_FaultStatus[(uint8)(LEDDRV_NUM_OF_LEDS - 1) - fl_Index]);

            /*Storing the led status as fault is detected*/
            for (fl_FaultIndex = 1U; ((fl_FaultIndex < LEDDRV_FAULT_FLAG_ARRAYSIZE) && (FALSE == fl_StatusUpdate_Flg)) ; fl_FaultIndex++)
            {
                /*Finding the index of the array to store the info.*/
                if (fl_Index < (fl_FaultIndex * LEDDRV_NUMOFBITS_IN_BYTE))
                {
                    /*Packing the fault status in bits.*/
                    LedDrv_Previous_Fault_oc[fl_FaultIndex - 1] |= (0x01U << (LEDDRV_NUMOFBITS_IN_BYTE - ((fl_FaultIndex * LEDDRV_NUMOFBITS_IN_BYTE) - fl_Index)));
                    /*The fault status is stored*/
                    fl_StatusUpdate_Flg = TRUE;
                }
            }
        }
        else
        {
            fl_ArrayIndex = (uint8)(fl_Index >> 3); //Calculate the byte number

            /*Checking if the led was in fault state before*/
            if (0x00U != ((0x01U << (LEDDRV_NUMOFBITS_IN_BYTE - (((fl_ArrayIndex + 1) * LEDDRV_NUMOFBITS_IN_BYTE) - fl_Index))) & LedDrv_Previous_Fault_oc[fl_ArrayIndex]))
            {
                /*Clearing the previous fault status flag*/
                LedDrv_Previous_Fault_oc[fl_ArrayIndex] &= (uint8)(~(0x01U << (LEDDRV_NUMOFBITS_IN_BYTE - (((fl_ArrayIndex + 1U) * LEDDRV_NUMOFBITS_IN_BYTE) - fl_Index))));
                /*Fault resolved status update to upper layer*/
                LedDrv_Clear_LED_Fault(fl_Index);
            }
        }
    }
}

/*============================================================================
**
** Function Name    :   LedDrv_Clear_LED_Fault
**
** Visibility       :   Private
**
** Description      :   This function clears the fault in Led
**
** Invocation       :   Static
**
** Inputs           :   void
**
** Outputs          :   void
**
** Critical Section :   No
**
**==========================================================================*/
static void LedDrv_Clear_LED_Fault(uint8 LedDrv_LedNum)
{
    uint16 fl_FaultStatus = 0;
    uint16 fl_LedFaultIteration;

    for(fl_LedFaultIteration = 0; fl_LedFaultIteration < LEDDRV_NUM_OF_FAULT_DETECTION_LED; fl_LedFaultIteration++)
    {
        if(LedDrv_LedNum == LedDrv_LedFault[fl_LedFaultIteration].FaultLedIndex)
        {
            if(NULL != LedDrv_LedFault[fl_LedFaultIteration].FaultDetectionCallback)
            {
                LedDrv_LedFault[fl_LedFaultIteration].FaultDetectionCallback(fl_FaultStatus);
            }
        }
    }
}

/*============================================================================
**
** Function Name    :   LedDrv_Inform_LED_Fault
**
** Visibility       :   Private
**
** Description      :   This function informs the fault in Led
**
** Invocation       :   Static
**
** Inputs           :   void
**
** Outputs          :   void
**
** Critical Section :   No
**
**==========================================================================*/
static void LedDrv_Inform_LED_Fault(uint8 LedDrv_LedNum, uint8 Leddrv_Fault)
{
    uint16 fl_FaultStatus = 0;
    uint16 fl_LedFaultIteration;

    if (Leddrv_Fault == (uint8)LEDDRV_OPEN)
    {
        fl_FaultStatus = 0x01U;
    }
    else if (Leddrv_Fault == (uint8)LEDDRV_SHORT)
    {
        fl_FaultStatus = 0x02U;
    }
    else if (Leddrv_Fault == (uint8)LEDDRV_SHORT_GND)
    {
        fl_FaultStatus = 0x04U;
    }
    else
    {
        /* Do Nothing */
    }


    for(fl_LedFaultIteration = 0U; fl_LedFaultIteration < LEDDRV_NUM_OF_FAULT_DETECTION_LED; fl_LedFaultIteration++)
    {
        if(LedDrv_LedNum == LedDrv_LedFault[fl_LedFaultIteration].FaultLedIndex)
        {
            if(NULL != LedDrv_LedFault[fl_LedFaultIteration].FaultDetectionCallback)
            {
                LedDrv_LedFault[fl_LedFaultIteration].FaultDetectionCallback(fl_FaultStatus);
            }
        }
    }
}

#define LEDDRV_LED_DRIVER_DATA_SEC_END
#include "MemMap.h"
#define LEDDRV_LED_DRIVER_SEC_END
#include "MemMap.h"

/***************************************************************************
 * REVISION HISTORY
 * Date : 21/Oct/2024  By : sdv  Change Description: Initial Version
 * Date : 19/Nov/2024  By : sdv  Change Description: Phase 1 Implementation
 * Date : 11/Dec/2025  By : rrajago2  Change Description:
 *   - Add per-chip GS dirty mask; memcpy GS snapshot only when changed
 *   - Fix GS bit setting (use |=), avoid clobbering other bits
 *   - Fix brightness/current change detection (use ||)
 *   - Fix per-chip MemSet size in FCBCDC init
 *   - Send GS via value[] raw bytes
 ***************************************************************************/
