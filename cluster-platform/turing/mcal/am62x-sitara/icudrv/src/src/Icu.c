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
*  File Name         :  Icu.c                                                *
*  Module Short Name :  Icu                                                  *
*  Description       :  This file contains implementations of the Icu Driver *
*                       for AM62PX series microcontrollers.                  *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                         *
* Target Hardware  :  AM62PX micro based Hardware Platform                   *
*                                                                            *
******************************************************************************/
#ifndef ICU_C
#define ICU_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Icu.h"

/*****************************************************************************
*                     Locally used Variable Declarations                     *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/* Holds the ICU driver status. */
typedef enum
{
  /* Driver was not initialized. */
  ICU_S_UNINITIALIZED = 0u,
  /* Driver successfully initialized. */
  ICU_S_INITIALIZED,
} Icu_DriverStatusType;

/* Global variable for ICU configuration */
static Icu_ConfigType* Icu_ConfigPtr = NULL_PTR; 
static Icu_DriverStatusType Icu_DriverStatus = ICU_S_UNINITIALIZED;

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

static Std_ReturnType Icu_SciClient(const Icu_ConfigType* ConfigPtr, Icu_ChannelType Channel);
static boolean Icu_CheckConfigPtr(const Icu_ConfigType* ConfigPtr);
static const Icu_ConfigType* Icu_GetConfigPtr(void);
static void Icu_GPIO_setTrigType(uint32 baseAddr, uint32 pinNum, Icu_ActivationType trigType);
static void Icu_GPIO_bankIntrEnable(uint32 baseAddr, uint32 bankNum);
static void Icu_GPIO_bankIntrDisable(uint32 baseAddr, uint32 bankNum);


/*****************************************************************************
*                            Functions Implementation                         *
******************************************************************************/

/*============================================================================
**
** Function Name    :   Icu_Init
**
** Visibility       :   Public
**
** Description      :   The Init function sets up the ICU configuration based 
**                      on the provided ConfigPtr parameter.
**
** Invocation       :   EcumExt.c
**
** Inputs           :   Icu_ConfigType * ConfigPtr - Pointer to a configuration type.
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/

/* ICU driver initialization */
void Icu_Init(const Icu_ConfigType* ConfigPtr)
{
    const Icu_ChannelConfigType* ChannelPtr;
    Icu_ChannelType Channel;
    if (Icu_DriverStatus == ICU_S_INITIALIZED)
    {
        /* Icu_Init has already been called before or Icu_DeInit is not done (no REQ) */
        Icu_ReportError(ICU_API_INIT, ICU_E_ALREADY_INITIALIZED);
    }
    /* Check ConfigPtr parameter */
    else if (FALSE == Icu_CheckConfigPtr(ConfigPtr))
    {
        Icu_ReportError(ICU_API_INIT, ICU_E_INIT_FAILED);
    }
    else
    {
        for (Channel = 0; Channel < ConfigPtr->NumberOfChannels; Channel++)
        {
            ChannelPtr = &(ConfigPtr->ChannelPtr[Channel]);
            (void)Icu_SciClient(ConfigPtr,ChannelPtr->ChannelId);
            Icu_GPIO_setTrigType(ChannelPtr->GpioBaseAddress, ChannelPtr->GpioPinNumber, ChannelPtr->GpioTriggerType);
        }
        /* Store the configuration for later use */
        Icu_ConfigPtr = ConfigPtr;
        /* Set Driver status to initialized */
        Icu_DriverStatus = ICU_S_INITIALIZED;
    }
}

/*============================================================================
**
** Function Name    :   Icu_DeInit
**
** Visibility       :   Public
**
** Description      :   The DeInit function sets the module variables to default
**                      state.
**
** Invocation       :   In Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/

#if (ICU_DEINIT_API == STD_ON)

void Icu_DeInit(void) 
{
    const Icu_ConfigType* ConfigPtr = Icu_GetConfigPtr();
    const Icu_ChannelConfigType* ChPtr;
    Icu_ChannelType Channel;
    if (Icu_DriverStatus == ICU_S_UNINITIALIZED)
    {
        /* No Icu_Init was done before or Icu_DeInit already called */
        Icu_ReportError(ICU_API_DE_INIT, ICU_E_UNINIT);
    }
    else if (FALSE == Icu_CheckConfigPtr(ConfigPtr))
    {
        /* Invalid configuration pointer */
        Icu_DriverStatus = ICU_S_UNINITIALIZED;
        Icu_ReportError(ICU_API_DE_INIT, ICU_E_UNINIT);
    }
    else
    {
        for (Channel = 0; Channel < ConfigPtr->NumberOfChannels; Channel++)
        {
            Icu_DisableNotification(Channel);
            ChPtr = &(ConfigPtr->ChannelPtr[Channel]);
            Icu_GPIO_setTrigType(ChPtr->GpioBaseAddress, ChPtr->GpioPinNumber, ICU_GPIO_TRIG_TYPE_NONE);
        } 
        /* Set Driver status to uninitialized */
        Icu_DriverStatus = ICU_S_UNINITIALIZED;
        /* Set the ConfigPtr to NULL after de-initialization */
        Icu_ConfigPtr = NULL_PTR;
    }
}
#endif

/*============================================================================
**
** Function Name    :   Icu_EnableNotification
**
** Visibility       :   Public
**
** Description      :   This function enables interrupt notifications for a specific
**                      ICU channel configured for edge detection mode
**
** Invocation       :   Called when enabling ICU channel interrupts
**
** Inputs           :   Icu_ChannelType Channel - Channel index to enable
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/

void Icu_EnableNotification(Icu_ChannelType Channel)
{
    const Icu_ChannelConfigType* ChannelPtr;
    const Icu_ConfigType* ConfigPtr = Icu_GetConfigPtr();
    if (Icu_DriverStatus != ICU_S_INITIALIZED)
    {
        /* No Icu_Init was done before */
        Icu_ReportError(ICU_API_ENABLE_NOTIFICATION, ICU_E_UNINIT);
    }
    else if (FALSE == Icu_CheckConfigPtr(ConfigPtr))
    {
        /* Invalid configuration pointer */
        Icu_ReportError(ICU_API_ENABLE_NOTIFICATION, ICU_E_UNINIT);
    }
    else if (Channel >= ConfigPtr->NumberOfChannels)
    {
        /* Invalid ICU channel specified */
        Icu_ReportError(ICU_API_ENABLE_NOTIFICATION, ICU_E_PARAM_CHANNEL);
    }
    else
    {
        ChannelPtr = &(ConfigPtr->ChannelPtr[Channel]);
        if (ChannelPtr->MeasurementMode != ICU_MODE_SIGNAL_EDGE_DETECT)
        {
            /* ICU channel not configured for edge detection mode */
            Icu_ReportError(ICU_API_ENABLE_NOTIFICATION, ICU_E_PARAM_CHANNEL);
        }
        else
        {
            Icu_GPIO_bankIntrEnable(ChannelPtr->GpioBaseAddress, GPIO_GET_BANK_INDEX(ChannelPtr->GpioPinNumber));
        }
    }
}

/*============================================================================
**
** Function Name    :   Icu_DisableNotification
**
** Visibility       :   Public
**
** Description      :   This function disables interrupt notifications for a specific
**                      ICU channel configured for edge detection mode
**
** Invocation       :   Called when disabling ICU channel interrupts
**
** Inputs           :   Icu_ChannelType Channel - Channel index to disable
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/

void Icu_DisableNotification(Icu_ChannelType Channel)
{
    const Icu_ChannelConfigType* ChannelPtr;
    const Icu_ConfigType* ConfigPtr = Icu_GetConfigPtr();
    if (Icu_DriverStatus != ICU_S_INITIALIZED)
    {
        /* No Icu_Init was done before */
        Icu_ReportError(ICU_API_DISABLE_NOTIFICATION, ICU_E_UNINIT);
    }
    else if (FALSE == Icu_CheckConfigPtr(ConfigPtr))
    {
        /* Invalid configuration pointer */
        Icu_ReportError(ICU_API_DISABLE_NOTIFICATION, ICU_E_UNINIT);
    }
    else if (Channel >= ConfigPtr->NumberOfChannels)
    {
        /* Invalid ICU channel specified */
        Icu_ReportError(ICU_API_DISABLE_NOTIFICATION, ICU_E_PARAM_CHANNEL);
    }
    else
    {
        ChannelPtr = &(ConfigPtr->ChannelPtr[Channel]);
        if (ChannelPtr->MeasurementMode != ICU_MODE_SIGNAL_EDGE_DETECT)
        {
            /* ICU channel not configured for edge detection mode */
            Icu_ReportError(ICU_API_DISABLE_NOTIFICATION, ICU_E_PARAM_CHANNEL);
        }
        else
        {
            /* Disable interrupt */
            Icu_GPIO_bankIntrDisable(ChannelPtr->GpioBaseAddress, GPIO_GET_BANK_INDEX(ChannelPtr->GpioPinNumber));
        }
    }
}

/*============================================================================
**
** Function Name    :   Icu_SciClient
**
** Visibility       :   Private
**
** Description      :   This function configures the System Control Interface (SCI) by:
**                     - Setting up interrupt routing parameters
**                     - Mapping GPIO interrupts from source to destination
**                     - Configuring interrupt routing through the INTROUTER
**
** Invocation       :   Icu_Init
**
** Inputs           :   const Icu_ConfigType* ConfigPtr - Pointer to ICU configuration
**                      Icu_ChannelType Channel - Channel to configure
**
** Outputs          :   E_OK on success 
**                      E_NOT_OK on failure
**
** Critical Section :   None
**
**==========================================================================*/

static Std_ReturnType Icu_SciClient(const Icu_ConfigType* ConfigPtr,Icu_ChannelType Channel)
{
    const Icu_ChannelConfigType* ChPtr;
    Std_ReturnType retVal = E_OK;
    uint16_t src_id    = 0U;
    uint16_t src_index = 0U;
    uint16_t dst_id    = 0U;
    uint16_t dst_irq   = 0U;
    
    ChPtr = &(ConfigPtr->ChannelPtr[Channel]);
    uint32 bankNum = GPIO_GET_BANK_INDEX(ChPtr->GpioPinNumber);
    
    if (ChPtr->GpioBaseAddress == CSL_MCU_GPIO0_BASE)
    {
        src_index = Mcu_Table[bankNum];
        src_id = TISCI_DEV_WKUP_MCU_GPIOMUX_INTROUTER0;
        dst_id = TISCI_DEV_WKUP_MCU_GPIOMUX_INTROUTER0;
        if(bankNum == 0U)
        {
            dst_irq = WKUP_MCU_GPIOMUX_INTROUTER0_OUTP_6;
        }
        else
        {
            dst_irq = WKUP_MCU_GPIOMUX_INTROUTER0_OUTP_7;
        }
    }
    else if (ChPtr->GpioBaseAddress == CSL_GPIO0_BASE)
    {
        src_index = Main0_Table[bankNum];
        src_id = TISCI_DEV_MAIN_GPIOMUX_INTROUTER0;
        dst_id = TISCI_DEV_MAIN_GPIOMUX_INTROUTER0;
        dst_irq = MAIN_GPIOMUX_INTROUTER0_OUTP_34;
    }
    else if (ChPtr->GpioBaseAddress == CSL_GPIO1_BASE) 
    {
        src_index = Main1_Table[bankNum];
        src_id = TISCI_DEV_MAIN_GPIOMUX_INTROUTER0;
        dst_id = TISCI_DEV_MAIN_GPIOMUX_INTROUTER0;
        dst_irq = MAIN_GPIOMUX_INTROUTER0_OUTP_35;
    }
    else
    {
        /* Do Nothing */
    }

    struct tisci_msg_rm_irq_set_req     rmIrqReq;
    struct tisci_msg_rm_irq_set_resp    rmIrqResp;

    rmIrqReq.valid_params           = 0U;
    rmIrqReq.valid_params          |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
    rmIrqReq.valid_params          |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;
    rmIrqReq.global_event           = 0U;
    rmIrqReq.src_id                 = src_id;
    rmIrqReq.src_index              = src_index;
    rmIrqReq.dst_id                 = dst_id;
    rmIrqReq.dst_host_irq           = dst_irq;
    rmIrqReq.ia_id                  = 0U;
    rmIrqReq.vint                   = 0U;
    rmIrqReq.vint_status_bit_index  = 0U;
    rmIrqReq.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;

    retVal = Sciclient_rmIrqSetRaw(&rmIrqReq, &rmIrqResp, SystemP_WAIT_FOREVER);

    return retVal;
}

/*============================================================================
**
** Function Name    :   Icu_GPIO_bankIntrDisable
**
** Visibility       :   Private
**
** Description      :   This function disables interrupts for a specific GPIO bank by:
**                     - Getting GPIO handle from base address
**                     - Clearing the bank interrupt enable bit
**
** Invocation       :   Called from Icu_DisableNotification
**
** Inputs           :   uint32 baseAddr - GPIO base address
**                      uint32 bankNum  - GPIO bank number to disable
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/


static void Icu_GPIO_bankIntrDisable(uint32 baseAddr, uint32 bankNum)
{
    CSL_GpioHandle hGpio;
    hGpio = (CSL_GpioHandle)(baseAddr);

    /* Disable bank interrupt */
    CSL_FINSR(hGpio->BINTEN, bankNum, bankNum, 0U);

    return;
}

/*============================================================================
**
** Function Name    :   Icu_GPIO_bankIntrEnable
**
** Visibility       :   Private
**
** Description      :   This function enables interrupts for a specific GPIO bank by:
**                     - Getting GPIO handle from base address
**                     - Setting the bank interrupt enable bit
**
** Invocation       :   Called from Icu_EnableNotification
**
** Inputs           :   uint32 baseAddr - GPIO base address
**                      uint32 bankNum  - GPIO bank number to enable
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/

static void Icu_GPIO_bankIntrEnable(uint32 baseAddr, uint32 bankNum)
{
    CSL_GpioHandle hGpio;
    hGpio = (CSL_GpioHandle)(baseAddr);

    /* Enable bank interrupt */
    CSL_FINSR(hGpio->BINTEN, bankNum, bankNum, 1U);

    return;
}

/*============================================================================
**
** Function Name    :   Icu_GPIO_setTrigType
**
** Visibility       :   Private
**
** Description      :   This function configures GPIO trigger type by:
**                     - Getting GPIO handle and register indices
**                     - Setting appropriate trigger registers based on type:
**                       * None: Disables both edges
**                       * Rising: Enables rising edge only
**                       * Falling: Enables falling edge only
**                       * Both: Enables both edges
**
** Invocation       :   Called from Icu_Init
**
** Inputs           :   uint32 baseAddr - GPIO base address
**                      uint32 pinNum   - GPIO pin number
**                      uint32 trigType - Trigger type to configure
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/

static void Icu_GPIO_setTrigType(uint32 baseAddr, uint32 pinNum, Icu_ActivationType trigType)
{
    CSL_GpioHandle hGpio;
    uint32  regIndex = 0U;
    uint32 regVal = 0U;
    hGpio = (CSL_GpioHandle)(baseAddr);
    
    /* Get the register index and the bit mask for the pin number */
    regIndex = GPIO_GET_REG_INDEX(pinNum);
    regVal = GPIO_GET_BIT_MASK(pinNum);

    switch(trigType)
    {
        case ICU_GPIO_TRIG_TYPE_NONE:
        {
            /* Disable both rising and falling edge detection interrupts */
            CSL_REG32_WR(&hGpio->BANK_REGISTERS[regIndex].CLR_RIS_TRIG, regVal);
            CSL_REG32_WR(&hGpio->BANK_REGISTERS[regIndex].CLR_FAL_TRIG, regVal);
            break;
        }

        case ICU_RISING_EDGE:
        {
            /* Only enable rising edge detection interupt */
            CSL_REG32_WR(&hGpio->BANK_REGISTERS[regIndex].CLR_FAL_TRIG, regVal);
            CSL_REG32_WR(&hGpio->BANK_REGISTERS[regIndex].SET_RIS_TRIG, regVal);
            break;
        }

        case ICU_FALLING_EDGE:
        {
            /* Only enable falling edge detection interupt */
            CSL_REG32_WR(&hGpio->BANK_REGISTERS[regIndex].CLR_RIS_TRIG, regVal);
            CSL_REG32_WR(&hGpio->BANK_REGISTERS[regIndex].SET_FAL_TRIG, regVal);
            break;
        }

        case ICU_BOTH_EDGES:
        {
            /* Enable both rising and falling edge detection interrupts */
            CSL_REG32_WR(&hGpio->BANK_REGISTERS[regIndex].SET_RIS_TRIG, regVal);
            CSL_REG32_WR(&hGpio->BANK_REGISTERS[regIndex].SET_FAL_TRIG, regVal);
            break;
        }

        default:
            break;
    }

    return;
}

/*============================================================================
**
** Function Name    :   Icu_CheckConfigPtr
**
** Visibility       :   Private
**
** Description      :   This function validates the ICU configuration pointer by:
**                     - Checking for NULL pointer
**                     - Verifying number of channels is valid
**                     - Validating GPIO base addresses
**                     - Validating GPIO pin numbers
**
** Invocation       :   Called from multiple ICU driver functions to access config
**                      to validate the configuration
** Inputs           :   const Icu_ConfigType* ConfigPtr - Configuration to validate
**
** Outputs          :   boolean - TRUE if valid, FALSE if invalid
**
** Critical Section :   None
**
**==========================================================================*/

static boolean Icu_CheckConfigPtr(const Icu_ConfigType* ConfigPtr)
{
    uint32 currentbankNum = 0U;
    uint32 BankNum = 0U;
    boolean isFirstChannelMain0 = TRUE;
    boolean isFirstChannelMain1 = TRUE;
    boolean retStatus = TRUE;

    if ((ConfigPtr == NULL_PTR) || (ConfigPtr->NumberOfChannels == 0U))
    {
        retStatus = FALSE;
    }
    if(retStatus != FALSE)
    {
        for (Icu_ChannelType Channel = 0; Channel < ConfigPtr->NumberOfChannels; Channel++)
        {
            uint32 baseAddr = ConfigPtr->ChannelPtr[Channel].GpioBaseAddress;
            uint32 pinNum = ConfigPtr->ChannelPtr[Channel].GpioPinNumber;
            /* Check valid base address first */
            if ((baseAddr != CSL_MCU_GPIO0_BASE) && (baseAddr != CSL_GPIO0_BASE) && (baseAddr != CSL_GPIO1_BASE))
            {
                retStatus = FALSE;
                break;
            }
            /* Validate pin numbers for each GPIO type */
            if (((baseAddr == CSL_MCU_GPIO0_BASE) && (pinNum > 22U)) ||
                ((baseAddr == CSL_GPIO0_BASE) && (pinNum > 86U)) ||
                ((baseAddr == CSL_GPIO1_BASE) && (pinNum > 87U)))
            {
                retStatus = FALSE;
                break;
            }
            /* Check bank consistency for MAIN GPIOs */
            if (baseAddr == CSL_GPIO0_BASE)
            {
                currentbankNum = GPIO_GET_BANK_INDEX(pinNum);
                if (isFirstChannelMain0 != FALSE)
                {
                    BankNum = currentbankNum;
                    isFirstChannelMain0 = FALSE;
                }
                else if(currentbankNum != BankNum)
                {
                    retStatus = FALSE;
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }
            if (baseAddr == CSL_GPIO1_BASE)
            {
                currentbankNum = GPIO_GET_BANK_INDEX(pinNum);
                if (isFirstChannelMain1 != FALSE)
                {
                    BankNum = currentbankNum;
                    isFirstChannelMain1 = FALSE;
                }
                else if (currentbankNum != BankNum)
                {
                    retStatus = FALSE;
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
    }
    return retStatus;
}

/*============================================================================
**
** Function Name    :   Icu_GetConfigPtr
**
** Visibility       :   Private
**
** Description      :   This function retrieves the pointer to current ICU 
**                      configuration by returning the global configuration pointer
**
** Invocation       :   Called from multiple ICU driver functions to access config
**
** Inputs           :   None
**
** Outputs          :   const Icu_ConfigType* - Pointer to current ICU configuration
**
** Critical Section :   None
**
**==========================================================================*/

static const Icu_ConfigType* Icu_GetConfigPtr(void)
{
  return Icu_ConfigPtr;
}

/****************************************************************************
*     Interrupt Service Routine (ISR) for MCU GPIO0 (Bank0) interrupts      *
****************************************************************************/

void MCU_ISR_6func(void)
{
   const Icu_ConfigType* ConfigPtr = Icu_GetConfigPtr();
   const Icu_ChannelConfigType* ChPtr;
   Icu_ChannelType Channel;
   for (Channel = 0; Channel < ConfigPtr->NumberOfChannels; Channel++)
    {
        ChPtr = &(ConfigPtr->ChannelPtr[Channel]);
        if (ChPtr->GpioBaseAddress == CSL_MCU_GPIO0_BASE)
        {
            ICU_IrqHandler(Channel);
        }
    }
}

/****************************************************************************
*     Interrupt Service Routine (ISR) for MCU GPIO0 (Bank1) interrupts      *
****************************************************************************/

void MCU_ISR_7func(void)
{
   const Icu_ConfigType* ConfigPtr = Icu_GetConfigPtr();
   const Icu_ChannelConfigType* ChPtr;
   Icu_ChannelType Channel;
   for (Channel = 0; Channel < ConfigPtr->NumberOfChannels; Channel++)
    {
        ChPtr = &(ConfigPtr->ChannelPtr[Channel]);
        if (ChPtr->GpioBaseAddress == CSL_MCU_GPIO0_BASE)
        {
            ICU_IrqHandler(Channel);
        }
    }
}

/****************************************************************************
*         Interrupt Service Routine (ISR) for MAIN GPIO0 interrupts         *
****************************************************************************/

void MAIN_ISR_34func(void)
{
   const Icu_ConfigType* ConfigPtr = Icu_GetConfigPtr();
   const Icu_ChannelConfigType* ChPtr;
   Icu_ChannelType Channel;
   for (Channel = 0; Channel < ConfigPtr->NumberOfChannels; Channel++)
    {
            ChPtr = &(ConfigPtr->ChannelPtr[Channel]);
            if (ChPtr->GpioBaseAddress == CSL_GPIO0_BASE)
            {
                ICU_IrqHandler(Channel);
            }
    }
}

/****************************************************************************
*         Interrupt Service Routine (ISR) for MAIN GPIO1 interrupts         *
****************************************************************************/

void MAIN_ISR_35func(void)
{
   const Icu_ConfigType* ConfigPtr = Icu_GetConfigPtr();
   const Icu_ChannelConfigType* ChPtr;
   Icu_ChannelType Channel;
   for (Channel = 0; Channel < ConfigPtr->NumberOfChannels; Channel++)
    {
            ChPtr = &(ConfigPtr->ChannelPtr[Channel]);
            if (ChPtr->GpioBaseAddress == CSL_GPIO1_BASE)
            {
                ICU_IrqHandler(Channel);
            }
    }
}


/*============================================================================
**
** Function Name    :   Icu_IrqHandler
**
** Visibility       :   Public
**
** Description      :   This ISR handler checks the interrupt status of the 
**                      GPIO pin associated with the ICU channel and calls 
**                      the notification callback if the interrupt.
**
** Invocation       :   ISR
**
** Inputs           :   Icu_ChannelType Channel - The ICU channel number to handle
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/

void ICU_IrqHandler(Icu_ChannelType Channel)
{
    uint32 reg_Index = 0U;
    uint32 intr_Status = 0U;
    uint32 regVal = 0U;
    CSL_GpioHandle hGpio;
    const Icu_ConfigType* ConfigPtr = Icu_GetConfigPtr();
    const Icu_ChannelConfigType* ChPtr;
    ChPtr = &(ConfigPtr->ChannelPtr[Channel]);
    hGpio = (CSL_GpioHandle)(ChPtr->GpioBaseAddress);
    reg_Index = GPIO_GET_REG_INDEX(ChPtr->GpioPinNumber);
    intr_Status = hGpio->BANK_REGISTERS[reg_Index].INTSTAT;
    regVal = GPIO_GET_BIT_MASK(ChPtr->GpioPinNumber);
    if((intr_Status & regVal) != 0U)
    {
        ChPtr->NotificationCallback();
        CSL_REG32_WR(&hGpio->BANK_REGISTERS[reg_Index].INTSTAT, regVal);
    }
}

#endif /* ICU_C */

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 19-11-2024                                            */
/*Version           :                                                       */
/*By                : kporkodi                                              */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/

/**-------------------------------------------------------------------------*/
/*Date              : 02-12-2024                                            */
/*Version           :                                                       */
/*By                : kporkodi                                              */
/*Traceability      :                                                       */
/*Change Description: Initial Version Platform Release                      */
/*--------------------------------------------------------------------------*/
