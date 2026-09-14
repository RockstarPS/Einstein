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
#ifndef CMPLIB_H_
#define CMPLIB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "CmpLib_Cfg.h"

#define CMPLIB_AR_RELEASE_MAJOR_VERSION       4U
#define CMPLIB_AR_RELEASE_MINOR_VERSION       2U
#define CMPLIB_AR_RELEASE_REVISION_VERSION    2U

#define CMPLIB_SW_MAJOR_VERSION              (1u)
#define CMPLIB_SW_MINOR_VERSION              (0u)
#define CMPLIB_SW_PATCH_VERSION              (5u)
//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

///@brief Enumeration of the possible component states. Zero-based sequential series.
typedef enum ECmpState_t
{
    eCmpState_Init,
    eCmpState_DeInit,
    eCmpState_Active,
    eCmpState_Activation,
    eCmpState_DeActivation,
#if (CMPLIB_WAKEUP_STATE_SUPPORT == 0x01)
	eCmpState_WakeUp,
#endif
    eCmpState_Diag,
    eCmpState_DiagReturn,
    eCmpState_InActive,
    eCmpState_Off,
    eCmpState_Count
} ECmpState;

///@brief Number of states that need periodic runnable to be processed.
#define cCMP_RUNNABLE_STATES eCmpState_InActive
///@brief State of the component.
typedef uint8 CmpStateType;

///@brief   Component context table structure to be stored in ROM
typedef struct SCmpType_t
{
    ///@brief Periodic static runnable to be called in particular state.
    Std_ReturnType ( *Process[cCMP_RUNNABLE_STATES] )(void);

    ///@brief Pointer to the state variable in RAM
    CmpStateType * const State;
} SCmpType;

#define CMPLIB_COMMON_APIS \
    static Std_ReturnType CmpInit ( void ); \
    static Std_ReturnType CmpDeInit ( void ); \
    static Std_ReturnType CmpActive ( void ); \
    static Std_ReturnType CmpActivation ( void ); \
    static Std_ReturnType CmpDeActivation ( void ); \
    static Std_ReturnType CmpDiag ( void ); \
    static Std_ReturnType CmpDiagReturn ( void ); \
    static CmpStateType CmpState = eCmpState_Off; \


///@brief   Creation of an instance of the NON-safety component
#if (CMPLIB_WAKEUP_STATE_SUPPORT == 0x01)
//This Instance should be used for the QM components(Non ASIL compliant)
#define CMPLIB_INSTANCE( name )  \
    CMPLIB_COMMON_APIS \
    static Std_ReturnType CmpWakeUp ( void ); \
    static const SCmpType oCmp = { { &CmpInit, &CmpDeInit, &CmpActive, &CmpActivation, &CmpDeActivation, &CmpWakeUp, &CmpDiag, &CmpDiagReturn}, &CmpState }; \
    extern void C##name##_Impl_MainFunction( void )  { CmpLib_Task( &oCmp ); } \
    extern Std_ReturnType C##name##_Impl_OnCommand( ECmpCmd Cmd ) { return CmpLib_Command( &oCmp, Cmd ); } // const for cmd is removed due to warnings from generated file from DaVinci tool
	
#else
//This Instance should be used for the QM components(Non ASIL compliant)
#define CMPLIB_INSTANCE( name )  \
    CMPLIB_COMMON_APIS \
    static const SCmpType oCmp = { { &CmpInit, &CmpDeInit, &CmpActive, &CmpActivation, &CmpDeActivation, &CmpDiag, &CmpDiagReturn}, &CmpState }; \
    extern void C##name##_Impl_MainFunction( void )  { CmpLib_Task( &oCmp ); } \
    extern Std_ReturnType C##name##_Impl_OnCommand( ECmpCmd Cmd ) { return CmpLib_Command( &oCmp, Cmd ); } // const for cmd is removed due to warnings from generated file from DaVinci tool

#endif


#include "Os.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
#ifndef Rte_TypeDef_ECmpCmd
///@brief Commands to control the component from outside
typedef uint8 ECmpCmd;
#endif
///@brief Commands to force initialization
#ifndef eCmpCmd_Init
# define eCmpCmd_Init		((ECmpCmd)0)
#endif
///@brief Commands to force de-initialization
#ifndef eCmpCmd_DeInit
# define eCmpCmd_DeInit 	((ECmpCmd)1u)
#endif
///@brief Commands to activate the component in ON state
# ifndef eCmpCmd_Activate
#   define eCmpCmd_Activate ((ECmpCmd)2u)
#endif
///@brief Commands to deactivate the component in ON state
#ifndef eCmpCmd_DeActivate
# define eCmpCmd_DeActivate ((ECmpCmd)3u)
#endif
///@brief Commands to reset the component  via initialization
#ifndef eCmpCmd_Reset
# define eCmpCmd_Reset ((ECmpCmd)4u)
#endif
///@brief Commands to restart the component via initialization
/// <br>    to the state where it was before ( active|inactive, diagnostic is disregarded )
# ifndef eCmpCmd_ReStart
# define eCmpCmd_ReStart ((ECmpCmd)5u)
#endif
///@brief Border between external and internal commands
#  ifndef eCmpCmd_ExternalCount
#   define eCmpCmd_ExternalCount ((ECmpCmd)6u)
#  endif
///@brief Commands to put the component in diagnostic state
#ifndef eCmpCmd_DiagStart
# define eCmpCmd_DiagStart ((ECmpCmd)7u)
#endif
///@brief Commands to stop diagnostic state and to return to normal operation
#ifndef eCmpCmd_DiagStop
# define eCmpCmd_DiagStop ((ECmpCmd)8u)
#endif

#if (CMPLIB_WAKEUP_STATE_SUPPORT == 0x01)
///@brief Commands to wake-up state initialization
#ifndef eCmpCmd_WakeUp
# define eCmpCmd_WakeUp ((ECmpCmd)9u)
#endif
#endif


//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================
extern void             CmpLib_Task    ( const SCmpType * const pObj );
extern Std_ReturnType   CmpLib_Command ( const SCmpType * const pObj, const ECmpCmd Cmd );


#ifdef __cplusplus
}
#endif

/*End of File*/
/*****************************************************************************
*  for each change to this file, be sure to record:                         *
*     1.  who made the change and when the change was made                  *
*     2.  why the change was made and the intended result                   *
*  Following block needs to be repeated for each change
******************************************************************************
*  Note: In the trace-ability column we need to trace back to the Design Doc.*
*  For the initial version it is traced to the Design Document section.     *
*  For further changes it shall trace to the source of the change which may *
*  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*  other reason                                                            *
******************************************************************************/
/*-----------------------------------------------------------------------------
Date              : 18/Dec/2018
By                : asivalin
Traceability      : RTC #1141271
Change Description: Creation of two separate instances of CmpLib for both QM & ASIL components
-------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date              : 26/02/2021
By                : praj1
Traceability      : RTC #1242926
Change Description: defect resolved 1242926 and ASIL INSTANCE #define removed
-------------------------------------------------------------------------------*/

#endif /* CMPLIB_H_ */
