//*********************************************************************************************************************
// Company:      Visteon Electronics
// --------------------------------------------------------------------------------------------------------------------
// Copyright:    This software is Visteon property.
//               Duplication or disclosure without Visteon written authorization
//               is prohibited.
// --------------------------------------------------------------------------------------------------------------------
// Project:      BMIC
// Language:     ANSI-C
// --------------------------------------------------------------------------------------------------------------------
// Component:    SwcDispMonSf VIP component checking CRC of a screen segment (SafeTT) againt a golden CRC.
// --------------------------------------------------------------------------------------------------------------------
//
//*********************************************************************************************************************

//----------------------------------------------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//----------------------------------------------------------------------------------------------------------------------

#include "Rte_Type.h"
#include "CmpLib.h"
#include "Rte_CSwcDispMonSf.h"
#include "SwcDispMonSf.h"
#include "Rte_CSwcDispMonSf_Type.h"

#define SIG_EV_CONTROL 0b00110001 // Bit 0 - Monitoring on/off. Bits 5-4 - window type (Video Port)
#define WINS_X 50U
#define WINS_Y 250U
#define WINE_X 97U
#define WINE_Y 310U

#define SAFETT_NOT_MONITORED 0U
#define SAFETT_MONITOR_OFF 1U
#define SAFETT_MONITOR_ON 2U
// BMIC29130-29087
#define SAFETT_GOLDEN_CRC_OFF 0xC9CD6ED9U
#define SAFETT_GOLDEN_CRC_ON  0xD4B75EEBU
#define DISP_MISDETECTION_TIME 15U  // 240ms Debounce = 16ms(task) * 15 BMIC29130-29074


#define SWCDISPMONSF_CORE_DATA_SEC_START
//#include "MemMap_SwcDispMonSfAsil.h"

static UInt8 u8DebounceTimer = 0U;

#define SWCDISPMONSF_CORE_DATA_SEC_END
/// Instance of life-cycle state-machine
CMPLIB_INSTANCE(SwcDispMonSf)

//======================================================================================================================
// DESCRIPTION:         Transitional initialization state
//
// PARAMETERS:          void
//
// RETURN VALUE:        Std_ReturnType: E_OK        - operation successful,
//                                      E_NOT_OK;   - operation failed,
//======================================================================================================================
static Std_ReturnType CmpInit(void)
{
    return E_OK;
}
//======================================================================================================================
// DESCRIPTION:         Transitional de-initialization state
//
// PARAMETERS:          void
//
// RETURN VALUE:        Std_ReturnType: E_OK        - operation successful,
//                                      E_NOT_OK;   - operation failed,
//======================================================================================================================
static Std_ReturnType CmpDeInit(void)
{
    return E_OK;
}

//======================================================================================================================
// DESCRIPTION:         Transitional activation state
//
// PARAMETERS:          void
//
// RETURN VALUE:        Std_ReturnType: E_OK        - operation successful,
//                                      E_NOT_OK;   - operation failed,
//======================================================================================================================
static Std_ReturnType CmpActivation(void)
{
    const SIG_WIN_SETUP_T sSigWinSetup = 
    {
        .control = SIG_EV_CONTROL,
        .winsx   = WINS_X,
        .winsy   = WINS_Y,
        .winex   = WINE_X,
        .winey   = WINE_Y,
        .ref_crc = 0U
    };
    (void)Rte_Write_pp_SigData_sig0_port(&sSigWinSetup); //BMIC29130-11025
        (void)SetEvent(SIG_OS_TASK, Sig_Ev_NewConfigReady);//Gdt Cdd CmpActivation
        return E_OK;
}

//======================================================================================================================
// DESCRIPTION:         Transitional de-activation state
//
// PARAMETERS:          void
//
// RETURN VALUE:        Std_ReturnType: E_OK        - operation successful,
//                                      E_NOT_OK;   - operation failed,
//======================================================================================================================
static Std_ReturnType CmpDeActivation(void)
{
    return E_OK;
}

//======================================================================================================================
// DESCRIPTION:         Normal operation state, runnable task.
//
// PARAMETERS:          void
//
// RETURN VALUE:        Std_ReturnType: E_OK        - operation successful,
//                                      E_NOT_OK;   - operation failed,
//======================================================================================================================
static Std_ReturnType CmpActive(void)
{
    processSafeTTCRC();//CmpActive
    return E_OK;
}

//======================================================================================================================
// DESCRIPTION:         Diagnostic state
//
// PARAMETERS:          void
//
// RETURN VALUE:        Std_ReturnType: E_OK        - Diagnostic has completed. Go to DiagReturn state.
//                                      E_NOT_OK;   - Keeps the component in this state.
//======================================================================================================================
static Std_ReturnType CmpDiag(void)
{
    return E_OK;
}

//======================================================================================================================
// DESCRIPTION:         Transitional state to clean up after diagnostic state. Component behaviour to be restored.
//
// PARAMETERS:          void
//
// RETURN VALUE:        Std_ReturnType: E_OK        - Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
//                                      E_NOT_OK;   - Keeps the component in this state.
//======================================================================================================================
static Std_ReturnType CmpDiagReturn(void)
{
    return E_OK;
}

void processSafeTTCRC(void)
{
    SIG_WIN_INFO_T  sSigWinInfo = 
    {
       .sig_unit = 0U,
       .window = 0U
    }; // Default values match with required 
    SIG_WIN_CRC_RGB_T sSigWinCRC  = {0U};
    // 0 - NOT MONITORED 
    // 1 - MONITORED OFF 
    // 2 - MONITOR ON 
    UInt8 u8SafeAbsStatus = 0U; 
    UInt32 u32GoldenSafeTTCRC = 0U; 
    UInt8 u8CRCFaultDetected = 0U;
    

    //Rte_Read_CSwcDispMonSf_rp_SafeAbsTTStatus_absTelltaleStatus(&u8SafeAbsStatus);
    // BMIC29130-11037
    u8SafeAbsStatus = SAFETT_MONITOR_ON;
    if(SAFETT_NOT_MONITORED != u8SafeAbsStatus)
    {
       Rte_Call_rp_SigCddCrc_Impl_sig_get_win_crc_data(&sSigWinInfo, &sSigWinCRC);
        #ifdef SM18_FIT //SM18 Fault Injection testing check
            sSigWinCRC.crc  += (u8SafeAbsStatus & 0b10000000U); // if the signal for FI is triggered add 128 to corrupt the CRC
            u8SafeAbsStatus ^= (u8SafeAbsStatus & 0b10000000U); // reverting the AbsStatus to valid state (removing the bit signaling for triggered FI)
        #endif

        if(SAFETT_MONITOR_OFF == u8SafeAbsStatus)
        {
            u32GoldenSafeTTCRC = SAFETT_GOLDEN_CRC_OFF; 
        }
        else if(SAFETT_MONITOR_ON == u8SafeAbsStatus)
        {
            u32GoldenSafeTTCRC = SAFETT_GOLDEN_CRC_ON; 
        }
        else
        {
            //MISRA
        }
        // BMIC29130-11027
        if(u32GoldenSafeTTCRC != sSigWinCRC.crc)
        {
            ++u8DebounceTimer;
        }
        else
        {
            u8DebounceTimer = 0U; // BMIC29130-29078
        }
        // BMIC29130-19878
        if(DISP_MISDETECTION_TIME <= u8DebounceTimer)
        {
            #ifdef SM18_FIT //SM18 Fault Injection testing FTTI
            boolean bIsStarted = FALSE;
            (void)TmExt_Timer_IsStarted(eDoorWarn_Timer, &bIsStarted);
            if (bIsStarted == (boolean)FALSE)
            {
                (void)TmExt_Timer_Start(eDoorWarn_Timer);
            }
            #endif
            u8CRCFaultDetected = 1U;
            --u8DebounceTimer;
        }
    }
    // BMIC29130-11043
    //Rte_Write_pp_AbsTTDispStatus_absTelltaleStatus(u8CRCFaultDetected);
}
