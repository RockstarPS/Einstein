//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------

#include "Rte_GdtCdd.h"
#include "CmpLib.h"
#include "Os.h"
//#include "types.h"
#include "idd_driver.h"
#include "hmi_gfx_mgr02_if.h"
#include "mmd_gdc_interrupthandler.h"
#include "TmExt_Cfg.h"
#include "TmExt_Timer.h"
#include <Dio.h>

/// @brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE(GdtCdd)


//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

// @brief Enumerates the levels of GdtCDD activate and deactivate sequences
typedef enum EGdtCddActLvl_t
{
    eActLvl_Inactive,        // the component is inactive
    eActLvl_GDTStartWait,   // waiting for GDT activation
    eActLvl_TFTEnableWait,  // waiting for TFT (part of TFT enable sequence)
    eActLvl_Active,         // the component is active
    eActLvl_TFTDisableWait, // waiting for TFT (part of TFT disable sequence)
    eActLvl_GDTStopWait,    // waiting for GDT activation
    eActLvl_Count
} EGdtCddActLvl;


#define RegWrite4(addr, value) (( *((volatile unsigned long* )(addr))) = (value))
#define IDD_PORT_WPREG_PPC_CONFIG(reg, data)        \
{                                                   \
    un_ppc_keycdr_t wk;                             \
    uint32_t adr = (uint32_t)&reg;                  \
    uint8_t size_key;                               \
    wk.au16Halfword[0] = adr & 0x7FFF;              \
    size_key = (sizeof(reg) >> 1) << 4;             \
    IRQ_DISABLE_LOCAL();                            \
    wk.au8Byte[3] = size_key | (0 << 6);            \
    PPC_KEYCDR = wk.u32Register;                    \
    wk.au8Byte[3] = size_key | (1 << 6);            \
    PPC_KEYCDR = wk.u32Register;                    \
    wk.au8Byte[3] = size_key | (2 << 6);            \
    PPC_KEYCDR = wk.u32Register;                    \
    wk.au8Byte[3] = size_key | (3 << 6);            \
    PPC_KEYCDR = wk.u32Register;                    \
    reg = data;                                     \
    IRQ_RESTORE();                                  \
}

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================
static void ui_display_tft_config( void );
static void ui_display_tft_deconfig( void );
//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

static EGdtCddActLvl ActLvl = eActLvl_Inactive;

static UINT32 Tick;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit( void )
{
    ui_display_tft_config();
    hmi_gfx_mgr02_if_KSColdInit();
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit( void )
{
    ui_display_tft_deconfig();
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActivation( void )
{
    Std_ReturnType Ret;
    StatusType RetOs;

    switch(ActLvl)
    {
    case eActLvl_Inactive:
        TmExt_Timer_Start(eTimerHandleGdtCdd);

        // First call for Activatiob function. We notify the Renderer task to initialize GDT subsystem.
        // We do not initialize GDT in this task because its initialization can take big amount of time.
        RetOs = SetEvent(OsTask_Render, Gfx_Ev_RdrInit);
        if(E_OK == RetOs)
        {
            Ret = E_NOT_READY;  // Delay the activation of this component
            ActLvl = eActLvl_GDTStartWait; // move to next level of activation
        }
        else
        {
            Ret = E_NOT_OK; // Something is wrong
        }
        break;

    case eActLvl_GDTStartWait:
        {
            EventMaskType EventMask;

            // Pool the Render task until it finishes the initialization
            RetOs = GetEvent(OsTask_Render, &EventMask);
            if(E_OK == RetOs)
            {
                if((EventMask & Gfx_Ev_RdrInit) == (UINT32)0)
                { // GDT start is done

                    // Start TFT enable sequence
                    Dio_WriteChannel(DioConf_DioChannel_DIO_DSPL_POW_EN, (Dio_LevelType)STD_LOW);
                    ActLvl = eActLvl_TFTEnableWait; // move to next level of activation
                }
                Ret = E_NOT_READY;  // Delay the activation of this component
            }
            else
            {
                Ret = E_NOT_OK; // Something is wrong
            }
        }
        break;

    case eActLvl_TFTEnableWait:
        // Finish the TFT enable sequence
        Dio_WriteChannel(DioConf_DioChannel_DIO_TFT_RESET, (Dio_LevelType)STD_HIGH);

        ActLvl = eActLvl_Active;
        Ret = E_OK;  // Finish the activation
        break;

    default:
        // Should not happen
        Ret = E_NOT_OK;
    }

    return Ret;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeActivation( void )
{
    Std_ReturnType Ret;
    StatusType RetOs;

    switch(ActLvl)
    {
    case eActLvl_Active:
        // Start TFT disable sequence
        Dio_WriteChannel(DioConf_DioChannel_DIO_TFT_RESET, (Dio_LevelType)STD_LOW);

        Ret = E_NOT_READY;
        ActLvl = eActLvl_TFTDisableWait;
        break;
    case eActLvl_TFTDisableWait:
        // Finish TFT disable sequence
        Dio_WriteChannel(DioConf_DioChannel_DIO_DSPL_POW_EN, (Dio_LevelType)STD_HIGH);

        // Start GDT stop sequence
        RetOs = SetEvent(OsTask_Render, Gfx_Ev_RdrDeinit);
        if(E_OK == RetOs)
        {
            Ret = E_NOT_READY;  // Delay the activation of this component
            ActLvl = eActLvl_GDTStopWait; // move to next level of deactivation
        }
        else
        {
            Ret = E_NOT_OK; // Something is wrong
        }
        break;
    case eActLvl_GDTStopWait:
        {
            EventMaskType EventMask;

            // Pool the Render task until it finishes the stop se4quence
            RetOs = GetEvent(OsTask_Render, &EventMask);
            if(E_OK == RetOs)
            {
                Ret = E_NOT_READY;

                if((EventMask & Gfx_Ev_RdrDeinit) == (UINT32)0)
                { // GDT stop is initiated
                    UINT8 isReadyToSleep = hmi_gfx_mgr02_if_is_ready_to_sleep();

                    if(0 != isReadyToSleep)
                    {
                        // GDT stop is finished, finalize the deactivate sequence

                        TmExt_Timer_Stop(eTimerHandleGdtCdd);
                        Ret = E_OK;
                        ActLvl = eActLvl_Inactive;
                    }
                }
            }
            else
            {
                Ret = E_NOT_OK; // Something is wrong
            }
        }
        break;
    default:
        // Should not happen
        Ret = E_NOT_OK;
    }

    return Ret;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  State for normal operations
///
/// @return The return value is disregarded. Say E_OK
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive( void )
{
    hmi_gfx_mgr02_if_KSTimedTask();
#if GFX_NUM_ANIMATIONS > 0
    hmi_gfx_anim_engine_tick();
#endif
    Tick++;
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Diagnostic state
///
/// @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag( void )
{
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional state to clean up after diagnostic state. Component behaviour to be restored.
///
/// @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn( void )
{
    return E_OK;
}
//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Rendering task
///
/// @return None
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
void OsTask_Renderfunc(void)
{
    EventMaskType EventMask;

#ifndef _WINDOWS
    while(1) //This task is activated only once then waits for an event from GdtCtrl
#endif
    {
        (void)WaitEvent(Gfx_Ev_RdrStart | Gfx_Ev_RdrDeinit | Gfx_Ev_RdrInit);
        (void)GetEvent(OsTask_Render, &EventMask);

        if((UINT32)0 != (EventMask &  Gfx_Ev_RdrInit))
        {
            // Activate GDT
            (void)hmi_gfx_mgr02_if_start();

            (void)ClearEvent(EventMask & (Gfx_Ev_RdrInit));
        }
        else if((UINT32)0 != (EventMask &  Gfx_Ev_RdrDeinit))
        {
#if GFX_NUM_ANIMATIONS > 0
          // Deactivate GDT
            UINT8 NumAnimations;

            for(NumAnimations =(UINT8)0; NumAnimations < GFX_NUM_ANIMATIONS; NumAnimations++)
            {
                (void)hmi_gfx_anim_stop(0, (UINT32)NumAnimations); /* Client ID = 0; AnimationID */
            }
#endif
            hmi_gfx_mgr02_if_shutdown((UINT8)GFX_MGR02_SHUTDOWN_NORMAL);

            (void)ClearEvent(EventMask & (Gfx_Ev_RdrDeinit | Gfx_Ev_RdrStart));
        }
        else if((UINT32)0 != (EventMask &  Gfx_Ev_RdrStart))
        {
            // Render
            (void)ClearEvent(EventMask & (Gfx_Ev_RdrStart));

            hmi_gfx_mgr02_layout_build_screen();       /* Build Screen */
            Graphics_Task_Done();
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Rendering task activation
///
/// @return None
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
void KernelTriggerGraphicsTask(void)
{
    (void)SetEvent(OsTask_Render, Gfx_Ev_RdrStart);
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Timer tick. Used by Iris library function
///
/// @return None
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
uint64_t Timer_GetTickCountUs(void)
{
    return TmExt_Timer_GetElapsedTime(eTimerHandleGdtCdd) * (uint64_t)1000;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Configure Display Lines.
///
/// @return E_OK:           
///<br>     E_NOT_READY:   
//---------------------------------------------------------------------------------------------------------------------
static void ui_display_tft_config( void )
{
    IDD_PORT_WPREG_PPC(PPC_PCFGR527, 0x80C1);  //B0
    IDD_PORT_WPREG_PPC(PPC_PCFGR528, 0x80C1);  //B1  
    IDD_PORT_WPREG_PPC(PPC_PCFGR529, 0x80C1);  //B2  
    IDD_PORT_WPREG_PPC(PPC_PCFGR530, 0x80C1);  //B3  
    IDD_PORT_WPREG_PPC(PPC_PCFGR531, 0x80C1);  //B4  
    IDD_PORT_WPREG_PPC(PPC_PCFGR600, 0x80C1);  //B5  

    IDD_PORT_WPREG_PPC(PPC_PCFGR000, 0x80C1);  //G0
    IDD_PORT_WPREG_PPC(PPC_PCFGR001, 0x80C1);  //G1  
    IDD_PORT_WPREG_PPC(PPC_PCFGR002, 0x80C1);  //G2  
    IDD_PORT_WPREG_PPC(PPC_PCFGR003, 0x80C1);  //G3  
    IDD_PORT_WPREG_PPC(PPC_PCFGR004, 0x80C1);  //G4  
    IDD_PORT_WPREG_PPC(PPC_PCFGR005, 0x80C1);  //G5

    IDD_PORT_WPREG_PPC(PPC_PCFGR006, 0x80C1);  //R0
    IDD_PORT_WPREG_PPC(PPC_PCFGR007, 0x80C1);  //R1  
    IDD_PORT_WPREG_PPC(PPC_PCFGR008, 0x80C1);  //R2  
    IDD_PORT_WPREG_PPC(PPC_PCFGR009, 0x80C1);  //R3  
    IDD_PORT_WPREG_PPC(PPC_PCFGR010, 0x80C1);  //R4  
    IDD_PORT_WPREG_PPC(PPC_PCFGR011, 0x80C1);  //R5 

    IDD_PORT_WPREG_PPC(PPC_PCFGR015, 0x80C4);  //DE 
    IDD_PORT_WPREG_PPC(PPC_PCFGR016, 0x80C7);  //CLK
    IDD_PORT_WPREG_PPC(PPC_PCFGR017, 0x80C4);  //HSYNC
    IDD_PORT_WPREG_PPC(PPC_PCFGR522, 0x80C4);  //VSYNC
 }

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Configure Display Lines.
///
/// @return E_OK:           
///<br>     E_NOT_READY:   
//---------------------------------------------------------------------------------------------------------------------
static void ui_display_tft_deconfig( void )
 {
    /*Making the Display Ports as GPIO Port and make it low o/p*/
    IDD_PORT_WPREG_PPC(PPC_PCFGR527, 0x8000);  //B0
    IDD_PORT_WPREG_PPC(PPC_PCFGR528, 0x8000);  //B1  
    IDD_PORT_WPREG_PPC(PPC_PCFGR529, 0x8000);  //B2  
    IDD_PORT_WPREG_PPC(PPC_PCFGR530, 0x8000);  //B3  
    IDD_PORT_WPREG_PPC(PPC_PCFGR531, 0x8000);  //B4  
    IDD_PORT_WPREG_PPC(PPC_PCFGR600, 0x8000);  //B5  

    IDD_PORT_WPREG_PPC(PPC_PCFGR000, 0x8000);  //G0
    IDD_PORT_WPREG_PPC(PPC_PCFGR001, 0x8000);  //G1  
    IDD_PORT_WPREG_PPC(PPC_PCFGR002, 0x8000);  //G2  
    IDD_PORT_WPREG_PPC(PPC_PCFGR003, 0x8000);  //G3  
    IDD_PORT_WPREG_PPC(PPC_PCFGR004, 0x8000);  //G4  
    IDD_PORT_WPREG_PPC(PPC_PCFGR005, 0x8000);  //G5

    IDD_PORT_WPREG_PPC(PPC_PCFGR006, 0x8000);  //R0
    IDD_PORT_WPREG_PPC(PPC_PCFGR007, 0x8000);  //R1  
    IDD_PORT_WPREG_PPC(PPC_PCFGR008, 0x8000);  //R2  
    IDD_PORT_WPREG_PPC(PPC_PCFGR009, 0x8000);  //R3  
    IDD_PORT_WPREG_PPC(PPC_PCFGR010, 0x8000);  //R4  
    IDD_PORT_WPREG_PPC(PPC_PCFGR011, 0x8000);  //R5 

    IDD_PORT_WPREG_PPC(PPC_PCFGR015, 0x8000);  //DE 
    IDD_PORT_WPREG_PPC(PPC_PCFGR016, 0x8000);  //CLK
    IDD_PORT_WPREG_PPC(PPC_PCFGR017, 0x8000);  //HSYNC
    IDD_PORT_WPREG_PPC(PPC_PCFGR522, 0x8000);  //VSYNC

}
//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
UINT32 GddCddTick(void)
{
    return Tick;
}

//Stubs for the GFX interrupts and anim task
void OsTask_Animfunc(void)
{
     /* This is Dummy Function No Code is Needed. */
}

void INTERRUPTS_IRQ_DEFAULT_HANDLERfunc(void)
{

}

void GFXInterruptHandler401func(void){mmdGdcInterruptHandler();}
void GFXInterruptHandler403func(void){mmdGdcInterruptHandler();}
void GFXInterruptHandler404func(void){mmdGdcInterruptHandler();}
void GFXInterruptHandler405func(void){mmdGdcInterruptHandler();}
void GFXInterruptHandler410func(void){mmdGdcInterruptHandler();}
void GFXInterruptHandler411func(void){mmdGdcInterruptHandler();}
void GFXInterruptHandler418func(void){mmdGdcInterruptHandler();}


