/* Kernbauer Version: 1.16 Konfiguration: Il_AsrComCfg5 Erzeugungsgangnummer: 3366 */

/* KB begin Com_HeaderText */
/* KB end Com_HeaderText */
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Com.h
 *        \brief  MICROSAR Communication header file
 *
 *      \details  This is the implementation of the MICROSAR Communication module.
 *                The basic software module is based on the AUTOSAR Communication specification.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Gunnar Meiss                  visms         Vector Informatik GmbH
 *  Dominik Biber                 visdbi        Vector Informatik GmbH
 *  Heiko Huebler                 vishho        Vector Informatik GmbH
 *  Sebastian Waldvogel           visswa        Vector Informatik GmbH
 *  Markus Bart                   visbms        Vector Informatik GmbH
 *  Anant Gupta                   visgut        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2011-12-07  visms   -             derived initial Cfg5 version from Il_AsrCom 3.21.00
 *            2011-12-21  visdbi  -             first version Il_AsrComCfg5
 *            2012-03-16  visdbi  ESCAN00055751 AR3-2330: Extend the CFG5 Support
 *  01.00.01  2012-03-29  visdbi  ESCAN00057998 Provide AUTOSAR data-type definitions in Com_Cfg.h
 *  02.00.00  2012-06-14  visdbi  ESCAN00058306 AR4-160 AUTOSAR 4.0.3 Support
 *                        visdbi  ESCAN00059339 Transfer property or TMS not evaluated as expected
 *                        visdbi  ESCAN00059340 Compiler warning: undefined functions
 *                        visdbi  ESCAN00059113 Compiler error: parse error near 'Com_FilterAlgoOfSigFilterInfoType'
 *                        visdbi  ESCAN00059109 Compiler error: identifier sigGrpHnd not declared
 *            2012-07-12  visdbi  ESCAN00060077 AR4-67: ASR4 Handle Concept
 *            2012-07-19  visdbi  ESCAN00060210 Linker error: Symbol Com_IsApplTypeUint8NOfSigInfo not found
 *  02.01.00  2012-09-12  visdbi  ESCAN00061351 Several features not functional
 *                        visdbi  ESCAN00061355 ASR4: Replication of Signal Transmission Requests not functional
 *            2012-11-08  visdbi  ESCAN00061792 AR4-199: Support Signal Data Invalidation
 *                        visdbi  ESCAN00061801 AR4-204: Support Update Bits
 *                        visdbi  ESCAN00062866 Support Signal Based Reception
 *            2012-11-29  visdbi  ESCAN00061807 AR4-212: Support Rx Filter
 *                        visdbi  ESCAN00063565 AR4-306: Support TRIGGERED_ON_CHANGE for uint8_N signals
 *            2012-12-05  visdbi  ESCAN00063384 Separate Misra/PcLint comments with blank
 *            2012-12-06  visdbi  ESCAN00063289 Improved Transition Mode Switch behavior
 *                        visdbi  ESCAN00063569 ASR4.0.3  compliance: Minimum Delay Timer
 *                        visdbi  ESCAN00062810 Use upper case 'U' suffix for unsigned variables / numbers
 *                        visdbi  ESCAN00062282 OS error 0x2C01 occurs
 *                        visdbi  ESCAN00063578 Copy Tx Signal Value Routine Optimization
 *            2012-12-13  visdbi  ESCAN00063708 Unexpected transmission mode behavior
 *            2012-12-18  visdbi  ESCAN00063559 Compiler error  in special configuration
 *                        visdbi  ESCAN00063496 Compiler errors occur in Tx only configuration
 *                        visdbi  ESCAN00062703 Compiler errors occur in Rx only configuration
 *                        visdbi  ESCAN00063259 Linker error: Com_IsInitModeOfTxModeInfo undefined
 *            2012-12-20  visdbi  ESCAN00063836 Use address getter macros
 *  02.02.00  2013-02-14  visms
 *                        vishho
 *                        visdbi  ESCAN00064302 AR4-325: Implement Post-Build Loadable
 *            2013-03-01  visdbi  ESCAN00065326 Exclusive Area Optimization
 *            2013-03-14  visdbi  ESCAN00064079 AR4-211: Support Signal Gateway
 *            2013-03-19  visms   ESCAN00064484 AR4-282: Export BSW DBG Data
 *            2013-04-03  visdbi  ESCAN00065565 Delayed Transmission of COM Tx I-PDU
 *            2013-04-10  visswa  ESCAN00066492 MISRA compliance
 *            2013-04-15  visdbi  ESCAN00066651 Incorrect reception of UINT8_N signals
 *                        visdbi  ESCAN00066653 Unexpected behavior after initialization
 *  03.00.00  2013-06-19  visdbi  ESCAN00067819 Cyclic transmission after triggered event with repetitions
 *                        visdbi  ESCAN00067769 ComPdu data can be modified after the call of the IPdu Trigger Transmit Callout function
 *                        visdbi  ESCAN00068097 Support AUTOSAR 4.0.3 I-PDU callout prototypes
 *                        vishho  ESCAN00068673 AR4-307: Support TP SDUs and dynamic length signals
 *            2013-07-23  vishho  ESCAN00069149 Include "SchM_Com.h" only in source files
 *            2013-07-26  vishho
 *                        visdbi  ESCAN00069359 AR4-520: Support Dynamic Rx DLC
 *            2013-08-07  visdbi  ESCAN00069650 AR4-205: Support Tx Timeout
 *            2013-08-08  visdbi  ESCAN00069677 Use generated increment/decrement macros
 *            2013-08-12  visdbi  ESCAN00069727 0-Bit signal support
 *            2013-08-16  vishho  ESCAN00069871 The prefix of VAR data shall be <Msn> followed by '_'
 *            2013-09-04  visdbi  ESCAN00070065 Compiler warning: Unreferenced parameter 'SignalDataPtr' in function Com_SendSignal
 *                        visdbi  ESCAN00069990 Compiler warning: Unreferenced parameter 'SignalId' in function Com_SendSignal
 *                        visdbi  ESCAN00069991 Compiler warning: Unreferenced parameter 'SignalGroupId' in function Com_ReceiveSignalGroup
 *                        visdbi  ESCAN00069996 Compiler warning: Unreferenced parameter 'idxFilterInfo' in function Com_Signal_EvaluateFilter
 *                        visdbi  ESCAN00069994 Compiler warning: Unreferenced parameter 'TxPduId' in function Com_TxBuffer_WriteIpduSignal
 *                        visdbi  ESCAN00069993 Compiler warning: Unreferenced parameter 'ComPduId' in function Com_LMgt_InitRxIpdu
 *                        vishho  ESCAN00069969 Compiler warning: Unreachable code in Com_ReceiveSignalGroup() API
 *                        visdbi  ESCAN00064672 Compiler warning: Unreferenced parameter 'SignalId' in function Com_ReceiveSignal
 *            2013-09-19  vishho  ESCAN00070511 AR4-307: Add Confirmation as ComTxIPduClearUpdateBit context
 *            2013-10-22  vishho  ESCAN00071307 Removed ASR3 support from single source
 *  03.01.00  2013-12-06  vishho  ESCAN00072488 Implement alive timeout behaviour according to Bugzilla 52102
 *            2013-12-11  vishho  ESCAN00071571 Remove Com_LMgt_TxIpduActive check from the API  Com_TxModeHdlr_Confirmation
 *            2013-12-13  vishho  ESCAN00072588 Make it possible to filter with negative values.
 *            2013-12-17  vishho  ESCAN00072687 AR4-569: Reset the minimum delay counter if Tx timeout occurs.
 *            2014-01-07  vishho  ESCAN00072739 Compiler error: Com.c() 'Com_PduGrpVectorEndIdxOfRxPduGrpInfoType' : undeclared identifier
 *            2014-01-14  vishho  ESCAN00072954 ComTxTimeouts initalisation writes out of bounds.
 *            2014-01-20  vishho  ESCAN00073070 Remove "is Initialized" DET check in the function Com_ClearIpduGroupVector
 *            2014-03-04  vishho  ESCAN00074050 A call of Com_TpTxConfirmation with a negative result will block the Com TP state machine
 *            2014-03-04  vishho  ESCAN00074051 Negative callout return value will block the Com TP state machine
 *  04.00.00  2014-03-12  vishho  ESCAN00070541 AR4-345: Implement PF4_PostBuildSelectable
 *            2014-03-25  vishho  ESCAN00071921 AR4-619: Support the StartOfReception API (with the PduInfoType), TxConfirmation and RxIndication according ASR4.1.2
 *            2014-04-17  vishho  ESCAN00074387 AR4-710: Support IPDUGroup relevant API like as ASR3 API
 *            2014-05-08  vishho  ESCAN00074113 AR4-642: Deleting container at post-build time
 *            2014-05-09  visbms  ESCAN00073892 AR4-601: Implement request handling
 *            2014-06-02  vishho  ESCAN00076011 Transmission of Messages is started without trigger
 *  04.00.01  2014-07-02  vishho  ESCAN00076677 ComOptimizedIPduGroupHandling not functional in variant POST-BUILD-LOADABLE
 *  04.00.02  2014-07-15  visbms  ESCAN00077100 Compiler error: Com.c: 'COM_VALIDHNDOFTXPDUINFO' is not defined as a preprocessor macro
 *  05.00.00  2014-08-18  visbms  ESCAN00077910 Missing compiler abstraction in Com_TriggerIPDUSendWithMetaData()
 *  07.00.00  2014-11-13  visms,
 *                        visgut  ESCAN00081777 FEAT-1275: SafeBSW Step 2
 *            2014-12-09  vishho  ESCAN00079731 Compiler warning: conversion from 'int' to 'Com_CycleTimeCntType', possible loss of data
 *            2015-03-25  visbms  ESCAN00081923 Lower layer is triggered with wrong SduLength if TP and IF PDUs with meta data are configured
 *            2015-05-06  vishho  ESCAN00082638 FEAT-1047: Gateway Rx signal timeout handling without update bits [AR4-894]
 *            2015-05-07  vishho  ESCAN00082891 The invalid action (notify/replace) of a Signal Group is executed although a valid value is received.
 *            2015-05-11  vishho  ESCAN00082928 FEAT-511: Support Ford SDLC: Support TxConfirmation  function calls in context of the Transmit function
 *            2015-06-24  vishho  ESCAN00079638 incorrect data is copied if a UINT8_DYN signal is copied on a BIG_ENDIAN Hardware.
 *            2015-07-15  visgut  ESCAN00084006 FEAT-77: COM Based Transformer for CONC_601_SenderReceiverSerialization incl. E2EXf [AR4-829]
**********************************************************************************************************************/
#ifndef COM_H
# define COM_H

/**********************************************************************************************************************
 * MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */
/* PRQA  S 3109 EOF */ /* MD_MSR_14.3 */
/* PRQA  S 3453 EOF */ /* MD_MSR_19.7 */
/* *INDENT-ON* */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Com_Cfg.h"
# if (COM_DEV_ERROR_DETECT == STD_ON)
#  include "Det.h"
# endif
//# include "Com_Lcfg.h"
//# include "Com_PBcfg.h"
//# include "vstdlib.h"

//# include "PduR_Com.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
# define COM_BUILD_VERSION                     3366U   /**< the Kernelbuilder build version. */
# define COM_VENDOR_ID                         30U              /**< the vendor ID of this implementation. */
# define COM_MODULE_ID                         50U              /**< the module ID of this implementation. */

/**
  \defgroup  ComARReleaseVersion Com AUTOSAR release version number
  \brief  Version number of AUTOSAR release on which the appropriate implementation is based on.
  \{
*/
# define COM_AR_RELEASE_MAJOR_VERSION          4U    /**< Major version */
# define COM_AR_RELEASE_MINOR_VERSION          0U    /**< Minor version */
# define COM_AR_RELEASE_REVISION_VERSION       3U    /**< Revision version */
/**
  \}
*/

/**
  \defgroup  ComSWVersion Com version number
  \brief  Version number of this implementation.
  \{
*/
# define COM_SW_MAJOR_VERSION                  7U    /**< Major version */
# define COM_SW_MINOR_VERSION                  0U    /**< Minor version */
# define COM_SW_PATCH_VERSION                  0U    /**< Patch level version */
/**
  \}
*/

/** compatibility define to activate error reporting if undefined */
# if !defined(COM_DEV_ERROR_REPORT)
#  define COM_DEV_ERROR_REPORT    COM_DEV_ERROR_DETECT
# endif
/** compatibility define to activate the undefined behavior sanitizer codes. */
# if !defined(COM_SANITIZE_UNDEFINED_BEHAVIOR)
#  define COM_SANITIZE_UNDEFINED_BEHAVIOR    STD_ON
# endif

/**
  \defgroup  ComCompilerAbstraction Com Compiler Abstraction
  \brief  COM compiler abstraction, which can be overriden in the COM user config file.
  \{
*/
# if !defined (COM_LOCAL)
#  define COM_LOCAL static
# endif

# if !defined (COM_INLINE)
#  define COM_INLINE INLINE
# endif

# if !defined (COM_LOCAL_INLINE)
#  define COM_LOCAL_INLINE LOCAL_INLINE
# endif
/**
  \}
*/

/**
  \defgroup  ComDetErrorCodes Com Det Error Codes
  \brief  COM development error IDs.
  \{
*/
# define COM_E_NO_ERROR                    0U /**< this code is used to detect that no error occurred. Det_ReportError() is not called.  */
# define COM_E_PARAM                       1U /**< the API service has been with a wrong parameter. */
# define COM_E_UNINIT                      2U /**< the API service has been called before COM was initialized with Com_Init() or after a call to Com_DeInit() */
# define COM_E_PARAM_POINTER               3U /**< the API service has been called with a not expected NULL pointer */
# define COM_E_INIT_FAILED                 4U /**< the API service has been called with a not expected NULL pointer */
/**
  \}
*/

# if (COM_USE_DUMMY_STATEMENT == STD_ON)
#  ifndef COM_DUMMY_STATEMENT_CONST
#   define COM_DUMMY_STATEMENT_CONST(a) (void)(a)
#  endif
#  ifndef COM_DUMMY_STATEMENT
#   define COM_DUMMY_STATEMENT(a) ((a) = (a))
#  endif
# else
#  ifndef COM_DUMMY_STATEMENT_CONST
#   define COM_DUMMY_STATEMENT_CONST(a)
#  endif
#  ifndef COM_DUMMY_STATEMENT
#   define COM_DUMMY_STATEMENT(a)
#  endif
# endif

/**
  \defgroup  ComReturnCodes Com Return Codes
  \brief  The COM module does not define a own COM return type. The API services return errors either by using the Std_ReturnType as defined Std_Types.h or with these values.
  \{
*/
# define COM_SERVICE_NOT_AVAILABLE         128U /**< the service is currently not available e.g. the corresponding I-PDU group is stopped or a development error has been detected */
# define COM_BUSY                          129U /**< Successful execution of this function is currently not possible, because a resource is currently in use. For example, the buffer of a large I-PDU is locked. */
/**
  \}
*/

/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/
///* Com GenTool Compatibility Check */
//# if ( VSTDLIB__COREHLL_VERSION < 0x0214U )
//#  error "Com: Incompatible VSTDLIB__COREHLL_VERSION with this Com Implementation!"
//# endif
//
//# if defined ( COMSTACKTYPE_VENDOR_ID )
//#  if ( COMSTACKTYPE_VENDOR_ID == COM_VENDOR_ID )
//#   if ( COMSTACKTYPE_SW_MAJOR_VERSION < 3U )
//#    error "Com: Incompatible COMSTACKTYPE_SW_MAJOR_VERSION with this Com Implementation!"
//#   else
//#    if ( COMSTACKTYPE_SW_MAJOR_VERSION == 3U )
//#     if ( COMSTACKTYPE_SW_MINOR_VERSION < 5U )
//#      error "Com: Incompatible COMSTACKTYPE_SW_MINOR_VERSION with this Com Implementation!"
//#     else
//#      if ( COMSTACKTYPE_SW_MINOR_VERSION == 5U )
//#       if ( COMSTACKTYPE_SW_PATCH_VERSION < 0U )
//#        error "Com: Incompatible COMSTACKTYPE_SW_PATCH_VERSION with this Com Implementation!"
//#       endif
//#      endif
//#     endif
//#    endif
//#   endif
//#  endif /* ( COMSTACKTYPE_VENDOR_ID == COM_VENDOR_ID ) */
//# endif /* ( COMSTACKTYPE_VENDOR_ID ) */

/**********************************************************************************************************************
  CONSISTENCY CHECK
**********************************************************************************************************************/
# if defined (_TEXAS_INSTRUMENTS_C_TMS320_)
#  error "The Target Tms320 is not supported !"
# endif

# if ((CPU_BYTE_ORDER != LOW_BYTE_FIRST) && (CPU_BYTE_ORDER != HIGH_BYTE_FIRST))
#  error "The hardware byte order is either not defined or has a not supported value"
# endif

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/* KB begin Com_LMgt_GlobalConstantMacros */
/* KB end Com_LMgt_GlobalConstantMacros */
/* KB begin Com_Signal_GlobalConstantMacros */
/* KB end Com_Signal_GlobalConstantMacros */
/* KB begin Com_Buffer_GlobalConstantMacros */
/* KB end Com_Buffer_GlobalConstantMacros */
/* KB begin Com_RxDlMon_GlobalConstantMacros */
/* KB end Com_RxDlMon_GlobalConstantMacros */
/* KB begin Com_RxLLIf_GlobalConstantMacros */
/* KB end Com_RxLLIf_GlobalConstantMacros */
/* KB begin Com_RxNHdlr_GlobalConstantMacros */
/* KB end Com_RxNHdlr_GlobalConstantMacros */
/* KB begin Com_RxSigIf_GlobalConstantMacros */
/* KB end Com_RxSigIf_GlobalConstantMacros */
/* KB begin Com_RxInv_GlobalConstantMacros */
/* KB end Com_RxInv_GlobalConstantMacros */
/* KB begin Com_TxInv_GlobalConstantMacros */
/* KB end Com_TxInv_GlobalConstantMacros */
/* KB begin Com_TxBuffer_GlobalConstantMacros */
/* KB end Com_TxBuffer_GlobalConstantMacros */
/* KB begin Com_TxDlMon_GlobalConstantMacros */
/* KB end Com_TxDlMon_GlobalConstantMacros */
/* KB begin Com_TxLLIf_GlobalConstantMacros */
/* KB end Com_TxLLIf_GlobalConstantMacros */
/* KB begin Com_TxModeHdlr_GlobalConstantMacros */
/* KB end Com_TxModeHdlr_GlobalConstantMacros */
/* KB begin Com_TxNHdlr_GlobalConstantMacros */
/* KB end Com_TxNHdlr_GlobalConstantMacros */
/* KB begin Com_TxSigIf_GlobalConstantMacros */
/* KB end Com_TxSigIf_GlobalConstantMacros */
/* KB begin Com_SignalGw_GlobalConstantMacros */
/* KB end Com_SignalGw_GlobalConstantMacros */

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/* KB begin Com_LMgt_GlobalFunctionMacros */
# define Com_LMgt_MemSet(DestPtr, Pattern, Length)             VStdMemSet((DestPtr), (Pattern), (uint16)(Length))
# define Com_LMgt_MemClr(DestPtr, Length)                      VStdMemClr((DestPtr), (uint16)(Length))
# if defined (COM_USEONLY_FARMEMCPY)
#  define Com_LMgt_MemCpyRamToRam(DestPtr, SrcPtr, Length)      VStdMemCpyFarRamToFarRam((DestPtr), (SrcPtr), (Length))
#  define Com_LMgt_MemCpyRomToRam(DestPtr, SrcPtr, Length)      VStdMemCpyFarRomToFarRam((DestPtr), (SrcPtr), (Length))
# else
#  define Com_LMgt_MemCpyRamToRam(DestPtr, SrcPtr, Length)      VStdMemCpyRamToRam((DestPtr), (SrcPtr), (Length))
#  define Com_LMgt_MemCpyRomToRam(DestPtr, SrcPtr, Length)      VStdMemCpyRomToRam((DestPtr), (SrcPtr), (Length))
# endif

# define COM_CAST2UINT8(argument)         ((uint8) (argument))

# if (COM_DEV_ERROR_REPORT == STD_ON)
#  define Com_LMgt_CheckDetErrorReturnVoid( CONDITION, API_ID, ERROR_CODE )           { if((CONDITION) == 0) { \
                                                                                          (void) Det_ReportError( (COM_MODULE_ID), 0U, ((uint8)(API_ID)), ((uint8)(ERROR_CODE))); \
                                                                                          return; } }
#  define Com_LMgt_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL )  { if((CONDITION) == 0) { \
                                                                                          (void) Det_ReportError( (COM_MODULE_ID), 0U, ((uint8)(API_ID)), ((uint8)(ERROR_CODE))); \
                                                                                          return (RET_VAL); } }
#  define Com_LMgt_CallDetErrorContinue(               API_ID, ERROR_CODE )           { (void) Det_ReportError( (COM_MODULE_ID), 0U, ((uint8)(API_ID)), ((uint8)(ERROR_CODE))); }
#  define Com_LMgt_CallFatalError(                             ERROR_CODE)              (void) Det_ReportError( (COM_MODULE_ID), 0U, ((uint8)COMServiceId_Il_AsrComCfg5Internal), ((uint8)(ERROR_CODE)))
#  define Com_LMgt_CheckFatalErrorRetVoid(  CONDITION,         ERROR_CODE )             Com_LMgt_CheckDetErrorReturnVoid((CONDITION), ((uint8)COMServiceId_Il_AsrComCfg5Internal), (ERROR_CODE))
# else
#  define Com_LMgt_CheckDetErrorReturnVoid( CONDITION, API_ID, ERROR_CODE )
#  define Com_LMgt_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL )
#  define Com_LMgt_CallDetErrorContinue(               API_ID, ERROR_CODE )
#  define Com_LMgt_CheckFatalErrorRetVoid(  CONDITION,         ERROR_CODE )
#  define Com_LMgt_CallFatalError(                             ERROR_CODE)
# endif/* (COM_DEV_ERROR_REPORT == STD_ON) */
/* KB end Com_LMgt_GlobalFunctionMacros */
/* KB begin Com_Signal_GlobalFunctionMacros */
/* KB end Com_Signal_GlobalFunctionMacros */
/* KB begin Com_Buffer_GlobalFunctionMacros */
/* KB end Com_Buffer_GlobalFunctionMacros */
/* KB begin Com_RxDlMon_GlobalFunctionMacros */
/* KB end Com_RxDlMon_GlobalFunctionMacros */
/* KB begin Com_RxLLIf_GlobalFunctionMacros */
/* KB end Com_RxLLIf_GlobalFunctionMacros */
/* KB begin Com_RxNHdlr_GlobalFunctionMacros */
/* KB end Com_RxNHdlr_GlobalFunctionMacros */
/* KB begin Com_RxSigIf_GlobalFunctionMacros */
/* KB end Com_RxSigIf_GlobalFunctionMacros */
/* KB begin Com_RxInv_GlobalFunctionMacros */
/* KB end Com_RxInv_GlobalFunctionMacros */
/* KB begin Com_TxInv_GlobalFunctionMacros */
/* KB end Com_TxInv_GlobalFunctionMacros */
/* KB begin Com_TxBuffer_GlobalFunctionMacros */
/* KB end Com_TxBuffer_GlobalFunctionMacros */
/* KB begin Com_TxDlMon_GlobalFunctionMacros */
/* KB end Com_TxDlMon_GlobalFunctionMacros */
/* KB begin Com_TxLLIf_GlobalFunctionMacros */
/* KB end Com_TxLLIf_GlobalFunctionMacros */
/* KB begin Com_TxModeHdlr_GlobalFunctionMacros */
/* KB end Com_TxModeHdlr_GlobalFunctionMacros */
/* KB begin Com_TxNHdlr_GlobalFunctionMacros */
/* KB end Com_TxNHdlr_GlobalFunctionMacros */
/* KB begin Com_TxSigIf_GlobalFunctionMacros */
/* KB end Com_TxSigIf_GlobalFunctionMacros */
/* KB begin Com_SignalGw_GlobalFunctionMacros */
/* KB end Com_SignalGw_GlobalFunctionMacros */

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/* KB begin Com_Signal_GlobalDataTypesAndStructures */
/* KB end Com_Signal_GlobalDataTypesAndStructures */
/* KB begin Com_Buffer_GlobalDataTypesAndStructures */
/* KB end Com_Buffer_GlobalDataTypesAndStructures */
/* KB begin Com_RxDlMon_GlobalDataTypesAndStructures */
/* KB end Com_RxDlMon_GlobalDataTypesAndStructures */
/* KB begin Com_RxLLIf_GlobalDataTypesAndStructures */
/* KB end Com_RxLLIf_GlobalDataTypesAndStructures */
/* KB begin Com_RxNHdlr_GlobalDataTypesAndStructures */
/* KB end Com_RxNHdlr_GlobalDataTypesAndStructures */
/* KB begin Com_RxSigIf_GlobalDataTypesAndStructures */
/* KB end Com_RxSigIf_GlobalDataTypesAndStructures */
/* KB begin Com_RxInv_GlobalDataTypesAndStructures */
/* KB end Com_RxInv_GlobalDataTypesAndStructures */
/* KB begin Com_TxInv_GlobalDataTypesAndStructures */
/* KB end Com_TxInv_GlobalDataTypesAndStructures */
/* KB begin Com_TxBuffer_GlobalDataTypesAndStructures */
/* KB end Com_TxBuffer_GlobalDataTypesAndStructures */
/* KB begin Com_TxDlMon_GlobalDataTypesAndStructures */
/* KB end Com_TxDlMon_GlobalDataTypesAndStructures */
/* KB begin Com_TxLLIf_GlobalDataTypesAndStructures */
/* KB end Com_TxLLIf_GlobalDataTypesAndStructures */
/* KB begin Com_TxModeHdlr_GlobalDataTypesAndStructures */
/* KB end Com_TxModeHdlr_GlobalDataTypesAndStructures */
/* KB begin Com_TxNHdlr_GlobalDataTypesAndStructures */
/* KB end Com_TxNHdlr_GlobalDataTypesAndStructures */
/* KB begin Com_TxSigIf_GlobalDataTypesAndStructures */
/* KB end Com_TxSigIf_GlobalDataTypesAndStructures */
/* KB begin Com_SignalGw_GlobalDataTypesAndStructures */
/* KB end Com_SignalGw_GlobalDataTypesAndStructures */
/* KB begin Com_LMgt_GlobalDataTypesAndStructures */

/**
  \defgroup  Com_StatusType Com Status Type
  \brief  This is a status value returned by the API service Com_GetStatus().
  \{
*/
typedef enum
{
  COM_UNINIT = 0x00,  /**< The COM module is not initialized or not usable. */
  COM_INIT = 0x01     /**< The COM Module is initialized and usable. */
} Com_StatusType;
/**
  \}
*/

# if (COM_DEV_ERROR_REPORT == STD_ON)
/**
  \defgroup  Com_ServiceIdType Com Service Id Type
  \brief  Unique identifier of a COM module service.
  \{
*/
typedef enum
{
  COMServiceId_Init = 0x01,
  COMServiceId_DeInit = 0x02,
  COMServiceId_IpduGroupControl = 0x03,
  COMServiceId_ReceptionDMControl = 0x06,
  COMServiceId_GetStatus = 0x07,
  COMServiceId_GetConfigurationId = 0x08,    /**< This service Id is not used in Autosar 4.2.1 */
  COMServiceId_GetVersionInfo = 0x09,
  COMServiceId_SendSignal = 0x0A,
  COMServiceId_ReceiveSignal = 0x0B,
  COMServiceId_UpdateShadowSignal = 0x0C,
  COMServiceId_SendSignalGroup = 0x0D,
  COMServiceId_ReceiveSignalGroup = 0x0E,
  COMServiceId_ReceiveShadowSignal = 0x0F,
  COMServiceId_InvalidateSignal = 0x10,
  COMServiceId_InvalidateShadowSignal = 0x16,
  COMServiceId_TriggerIPDUSend = 0x17,
  COMServiceId_MainFunctionRx = 0x18,
  COMServiceId_MainFunctionTx = 0x19,
  COMServiceId_MainFunctionRouteSignals = 0x1A,
  COMServiceId_InvalidateSignalGroup = 0x1B,
  COMServiceId_ClearIpduGroupVector = 0x1C,
  COMServiceId_SetIpduGroup = 0x1D,
  COMServiceId_SendDynSignal = 0x21,
  COMServiceId_ReceiveDynSignal = 0x22,
  COMServiceId_SendSignalGroupArray = 0x23,
  COMServiceId_ReceiveSignalGroupArray = 0x24,
  COMServiceId_SwitchIpduTxMode = 0x27,
  COMServiceId_TriggerIPDUSendWithMetaData = 0x28,
  COMServiceId_TxConfirmation = 0x40,
  COMServiceId_TriggerTransmit = 0x41,
  COMServiceId_RxIndication = 0x42,
  COMServiceId_CopyTxData = 0x43,
  COMServiceId_CopyRxData = 0x44,
  COMServiceId_TpRxIndication = 0x45,
  COMServiceId_StartOfReception = 0x46,
  COMServiceId_TpTxConfirmation = 0x48,
  COMServiceId_Il_AsrComCfg5Internal = 0x80     /**< This service Id is used to identify internal checks */
} Com_ServiceIdType;
/**
  \}
*/
# endif

# if (COM_DEV_ERROR_DETECT == STD_ON)
/**
  \defgroup  Com_FatalErrorType Com Fatal Error Types
  \brief  This enum contains all error codes, which can be used with Com_LMgt_ConditionalFatalError and Com_LMgt_FatalError.
  \{
*/
typedef enum
{
  Com_TxLLIf_Transmit_IpduIdParam = 16,                       /**< The Parameter of Com_TxLLIf_Transmit is too large. */
  Com_SanitizeUndefinedBehavior = 36                          /**< The code part shall never be executed. The behavior of the program flow is undefined. The reason for this error type is an inconsistency between the configuration data and static source code. */
} Com_LMgt_FatalErrorType;
/**
  \}
*/
# endif

/* KB end Com_LMgt_GlobalDataTypesAndStructures */

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES (Com)
**********************************************************************************************************************/
/* KB begin Com_LMgt_GlobalDataPrototypes */

# if(COM_USE_INIT_POINTER == STD_ON)
#  define COM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */

extern P2CONST(Com_ConfigType, COM_VAR_ZERO_INIT, COM_PBCFG) Com_ConfigDataPtr;

#  define COM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
# endif

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/* KB end Com_LMgt_GlobalDataPrototypes */
/* KB begin Com_Signal_GlobalDataPrototypes */
/* KB end Com_Signal_GlobalDataPrototypes */
/* KB begin Com_Buffer_GlobalDataPrototypes */
/* KB end Com_Buffer_GlobalDataPrototypes */
/* KB begin Com_RxDlMon_GlobalDataPrototypes */
/* KB end Com_RxDlMon_GlobalDataPrototypes */
/* KB begin Com_RxLLIf_GlobalDataPrototypes */
/* KB end Com_RxLLIf_GlobalDataPrototypes */
/* KB begin Com_RxNHdlr_GlobalDataPrototypes */
/* KB end Com_RxNHdlr_GlobalDataPrototypes */
/* KB begin Com_RxSigIf_GlobalDataPrototypes */
/* KB end Com_RxSigIf_GlobalDataPrototypes */
/* KB begin Com_RxInv_GlobalDataPrototypes */
/* KB end Com_RxInv_GlobalDataPrototypes */
/* KB begin Com_TxInv_GlobalDataPrototypes */
/* KB end Com_TxInv_GlobalDataPrototypes */
/* KB begin Com_TxBuffer_GlobalDataPrototypes */
/* KB end Com_TxBuffer_GlobalDataPrototypes */
/* KB begin Com_TxDlMon_GlobalDataPrototypes */
/* KB end Com_TxDlMon_GlobalDataPrototypes */
/* KB begin Com_TxLLIf_GlobalDataPrototypes */
/* KB end Com_TxLLIf_GlobalDataPrototypes */
/* KB begin Com_TxModeHdlr_GlobalDataPrototypes */
/* KB end Com_TxModeHdlr_GlobalDataPrototypes */
/* KB begin Com_TxNHdlr_GlobalDataPrototypes */
/* KB end Com_TxNHdlr_GlobalDataPrototypes */
/* KB begin Com_TxSigIf_GlobalDataPrototypes */
/* KB end Com_TxSigIf_GlobalDataPrototypes */
/* KB begin Com_SignalGw_GlobalDataPrototypes */
/* KB end Com_SignalGw_GlobalDataPrototypes */

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
# define COM_START_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_19.1 */

/* KB begin Com_LMgt_GlobalFunctionPrototypes */
/**********************************************************************************************************************
  Com_Init
**********************************************************************************************************************/
/** \brief    This service initializes internal and external interfaces and variables of the AUTOSAR COM layer
              for the further processing. After calling this function the inter-ECU communication is still disabled.
    \param    config  NULL_PTR if COM_USE_INIT_POINTER is STD_OFF
                      Pointer to the Com configuration data if COM_USE_INIT_POINTER is STD_ON
    \return   none
    \context  The function must be called on task level and has not to interrupted
              by other administrative function calls.
    \note     The function is used by the Ecu State Manager
    \warning  Com_Init shall not pre-empt any COM function.
              The rest of the system must guarantee that Com_Init is not called in such a way.
    \pre      Com_InitMemory() has to be executed previously, if the startup code does not initialise variables.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_Init(P2CONST(Com_ConfigType, AUTOMATIC, COM_INIT_DATA) config);

/**********************************************************************************************************************
  Com_InitMemory
**********************************************************************************************************************/
/** \brief    The function initialises variables, which cannot be initialised with the startup code.
    \return   none
    \context  The function must be called on task level.
    \note     The function is used by the application.
    \pre      Com_Init() is not called yet.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_InitMemory(void);

# if (COM_DE_INIT_API == STD_ON )
/**********************************************************************************************************************
  Com_DeInit
**********************************************************************************************************************/
/** \brief    This service stops the inter-ECU communication. All started I-PDU groups are stopped and have
              to be started again, if needed, after Com_Init is called. By a call to ComDeInit COM is put into an
              not initialized state.
    \return   none
    \context  The function must be called on task level and has not to interrupted
              by other administrative function calls.
    \note     The function is used by the application.
    \warning  Com_DeInit shall not pre-empt any COM function.
              The rest of the system must guarantee that Com_DeInit is not called in such a way.
    \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_DeInit(void);
# endif

# if (COM_IPDU_GROUP_CONTROL_API == STD_ON)
/**********************************************************************************************************************
  Com_IpduGroupControl
**********************************************************************************************************************/
/** \brief    This service starts I-PDU groups.
    \param    ipduGroupVector I-PDU group vector containing the activation state (stopped = 0/ started = 1)
                              for all I-PDU groups.
    \param    initialize      flag to request initialization of the I-PDUs which are newly started
    \return   none
    \context  The function must be called on task level.
    \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_IpduGroupControl(Com_IpduGroupVector ipduGroupVector, boolean initialize);
# endif/* (COM_IPDU_GROUP_CONTROL_API == STD_ON) */

# if (COM_RECEPTION_DM_CONTROL_API == STD_ON )
/**********************************************************************************************************************
  Com_ReceptionDMControl
**********************************************************************************************************************/
/** \brief    This service enables or disables I-PDU group Deadline Monitoring.
    \param    ipduGroupVector I-PDU group vector containing the requested deadline monitoring state
                              (disabled = 0/ enabled = 1) for all I-PDU groups.
    \return   none
    \context  The function must be called on task level.
    \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_ReceptionDMControl(Com_IpduGroupVector ipduGroupVector);
# endif/* (COM_RECEPTION_DM_CONTROL_API == STD_ON ) */

# if (COM_IPDU_GROUP_START_API == STD_ON)
/**********************************************************************************************************************
  Com_IpduGroupStart
**********************************************************************************************************************/
/** \brief    Starts a preconfigured I-PDU group.
              For example, cyclic I-PDUs will be sent out cyclically after the call of Com_IpduGroupStart().
              If Initialize is true all I-PDUs of the I-PDU group shall be (re-)initialized before the I-PDU group
              is started. That means they shall behave like after a start-up of COM, for example the old_value of the
              filter objects and shadow buffers of signal groups have to be (re-)initialized.
    \param    IpduGroupId ID of I-PDU group to be started
    \param    Initialize  Flag to request initialization of the data in the I-PDUs of this I-PDU group
    \return   none
    \context  The function must be called on task level and has not to interrupted
              by other Com_IpduGroupStart and Com_IpduGroupStop calls.
    \warning  A call to Com_IpduGroupStart shall not be interrupted by another call to Com_IpduGroupStart, Com_EnableReceptionDM,
              Com_DisableReceptionDM or a call to Com_IpduGroupStop.
    \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_IpduGroupStart(Com_IpduGroupIdType IpduGroupId, boolean Initialize);
# endif/* (COM_IPDU_GROUP_START_API == STD_ON) */

# if (COM_IPDU_GROUP_STOP_API == STD_ON)
/**********************************************************************************************************************
  Com_IpduGroupStop
**********************************************************************************************************************/
/** \brief    Stops a preconfigured I-PDU group.
              For example, cyclic I-PDUs will be stopped after the call of Com_IpduGroupStop().
    \param    IpduGroupId ID of I-PDU group to be stopped
    \return   none
    \context  The function must be called on task level.
    \warning  A call to Com_IpduGroupStop shall not be interrupted by another call to Com_IpduGroupStop, Com_EnableReceptionDM,
              Com_DisableReceptionDM or a call to Com_IpduGroupStart.
    \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_IpduGroupStop(Com_IpduGroupIdType IpduGroupId);
# endif/* (COM_IPDU_GROUP_STOP_API == STD_ON) */

# if (COM_ENABLE_RECEPTION_DM_API == STD_ON)
/**********************************************************************************************************************
  Com_EnableReceptionDM
**********************************************************************************************************************/
/** \brief    Enables the reception deadline monitoring for the I-PDUs within the given I-PDU group.
    \param    IpduGroupId ID of I-PDU group where reception DM shall be enabled.
    \return   none
    \context  The function must be called on task level.
    \warning  A call to Com_EnableReceptionDM shall not be interrupted by another call to Com_EnableReceptionDM, Com_IpduGroupStop,
              Com_DisableReceptionDM or a call to Com_IpduGroupStart.
    \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_EnableReceptionDM(Com_IpduGroupIdType IpduGroupId);
# endif/* (COM_ENABLE_RECEPTION_DM_API == STD_ON) */

# if (COM_DISABLE_RECEPTION_DM_API == STD_ON)
/**********************************************************************************************************************
  Com_DisableReceptionDM
**********************************************************************************************************************/
/** \brief    Disables the reception deadline monitoring for the I-PDUs within the given I-PDU group.
    \param    IpduGroupId ID of I-PDU group where reception DM shall be disabled.
    \return   none
    \context  The function must be called on task level.
    \warning  A call to Com_DisableReceptionDM shall not be interrupted by another call to Com_DisableReceptionDM, Com_IpduGroupStop,
              Com_EnableReceptionDM or a call to Com_IpduGroupStart.
    \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_DisableReceptionDM(Com_IpduGroupIdType IpduGroupId);
# endif/* (COM_DISABLE_RECEPTION_DM_API == STD_ON) */

/**********************************************************************************************************************
  Com_MainFunctionRx
**********************************************************************************************************************/
/** \brief    This function shall perform the processing of the AUTOSAR COM receive processing that are not directly
              initiated by the calls from the RTE and PDU-R.
              A call to Com_MainFunctionRx returns simply if COM was not previously initialized with
              a call to Com_Init.
    \return   none
    \context  The function must be called on task level.
    \note     The function is called by the BSW Scheduler.
    \pre      -
**********************************************************************************************************************/
/* function defined in file 'SchM_Com.h' */

/**********************************************************************************************************************
  Com_MainFunctionTx
**********************************************************************************************************************/
/** \brief    This function shall perform the processing of the AUTOSAR COM transmission activities that are not
              directly initiated by the calls from the RTE and PDU-R.
              A call to Com_MainFunctionTx returns simply if COM was not previously initialized with
              a call to Com_Init.
    \return   none
    \context  The function must be called on task level.
    \note     The function is called by the BSW Scheduler.
    \pre      -
**********************************************************************************************************************/
/* function defined in file 'SchM_Com.h' */

/**********************************************************************************************************************
  Com_GetConfigurationId
**********************************************************************************************************************/
/** \brief    Provides the unique identifier of the configuration.
    \return   uint32 Configured ConfigurationID
    \context  The function can be called on interrupt and task level.
  \pre      -
**********************************************************************************************************************/
FUNC(uint32, COM_CODE) Com_GetConfigurationId(void);

/**********************************************************************************************************************
  Com_GetStatus
**********************************************************************************************************************/
/** \brief    Returns the status of the AUTOSAR COM module.
    \return   Com_StatusType
    \context  The function can be called on interrupt and task level.
  \pre      -
**********************************************************************************************************************/
# if (COM_GET_STATUS_API == STD_ON )
FUNC(Com_StatusType, COM_CODE) Com_GetStatus(void);
# endif

# if (COM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  Com_GetVersionInfo
**********************************************************************************************************************/
/** \brief    Returns the version information of this module.
    \param    versioninfo Pointer to where to store the version information of this module.
    \return   none
    \context  The function can be called on interrupt and task level.
  \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, COM_APPL_VAR) versioninfo);
# endif/* (COM_VERSION_INFO_API == STD_ON) */

# if (COM_TRIGGER_IPDU_SEND_API == STD_ON)
/**********************************************************************************************************************
  Com_TriggerIPDUSend
**********************************************************************************************************************/
/** \brief    By a call to Com_TriggerIPDUSend the I-PDU with the given ID is triggered for transmission
    \param    PduId    ID of AUTOSAR COM Tx I-PDU.
    \return   void
    \context  The function can be called on interrupt and task level.
    \note     The function shall only be called from within an I-PDU callout.
  \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TriggerIPDUSend(PduIdType PduId);
# endif/* (COM_TRIGGER_IPDU_SEND_API == STD_ON) */

# if (COM_TRIGGER_IPDU_SEND_WITH_META_DATA_API == STD_ON)
/**********************************************************************************************************************
  Com_TriggerIPDUSendWithMetaData
**********************************************************************************************************************/
/** \brief    By a call to Com_TriggerIPDUSendWithMetaData the given meta data is appended to the I-PDU and the I-PDU
              with the given ID is triggered for transmission
    \param    PduId    ID of AUTOSAR COM Tx I-PDU.
    \param    MetaData The Meta data that shall be added to the I-PDU before sending.
    \return   void
    \context  The function can be called on interrupt and task level.
    \note     The function shall only be called from within an I-PDU callout.
  \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TriggerIPDUSendWithMetaData(PduIdType PduId,
                                                     P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaData);
# endif/* (COM_TRIGGER_IPDU_SEND_WITH_META_DATA_API == STD_ON) */

/**********************************************************************************************************************
  Com_ClearIpduGroupVector
**********************************************************************************************************************/
/** \brief    This service sets all bits of the given Com_IpduGroupVector to 0.
    \param    ipduGroupVector I-PDU group vector to be cleared
    \return   none
    \context  The function must be called on task level.
  \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_ClearIpduGroupVector(Com_IpduGroupVector ipduGroupVector);

/**********************************************************************************************************************
  Com_SetIpduGroup
**********************************************************************************************************************/
/** \brief    This service sets the value of a bit in an I-PDU group vector.
    \param    ipduGroupVector I-PDU group vector to be modified
    \param    ipduGroupId     ID used to identify the corresponding bit in the I-PDU group vector
    \param    bitval          New value of the corresponding bit
    \return   none
    \context  The function must be called on task level.
  \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_SetIpduGroup(Com_IpduGroupVector ipduGroupVector, Com_IpduGroupIdType ipduGroupId,
                                      boolean bitval);
/* KB end Com_LMgt_GlobalFunctionPrototypes */
/* KB begin Com_Signal_GlobalFunctionPrototypes */
/* KB end Com_Signal_GlobalFunctionPrototypes */
/* KB begin Com_Buffer_GlobalFunctionPrototypes */
/* KB end Com_Buffer_GlobalFunctionPrototypes */
/* KB begin Com_RxDlMon_GlobalFunctionPrototypes */
/* KB end Com_RxDlMon_GlobalFunctionPrototypes */
/* KB begin Com_RxLLIf_GlobalFunctionPrototypes */
/* KB end Com_RxLLIf_GlobalFunctionPrototypes */
/* KB begin Com_RxNHdlr_GlobalFunctionPrototypes */
/* KB end Com_RxNHdlr_GlobalFunctionPrototypes */
/* KB begin Com_RxSigIf_GlobalFunctionPrototypes */

# if ((COM_RXTPINFO == STD_ON) &&(COM_EXISTS_UINT8_DYN_APPLTYPEOFRXACCESSINFO == STD_ON))
/**********************************************************************************************************************
  Com_ReceiveDynSignal
**********************************************************************************************************************/
/** \brief    The service Com_ReceiveDynSignal updates the signal data referenced by SignalDataPtr
              with the data in the signal object identified by SignalId. The Length parameter indicates as
              "in parameter" the maximum legth that can be received and as "out parameter" the length of the written
              dynamic length signal or group signal.
              If the signal processing of the corresponding I-Pdu is configured to DEFERRED
              the last received signal value is available not until the next call to Com_MainfunctionRx.
              If a group signal is read, the data in the shadow buffer should be updated before the call
              by a call of the service Com_ReceiveSignalGroup.
    \param    SignalId                    Id of signal or group signal to be received.
    \param    SignalDataPtr               Reference to the signal data in which to store the received data.
    \param    Length                      in: maximum length that could be received
                                          out: length of the dynamic length signal
    \return   uint8
              E_OK                        service has been accepted
              E_NOT_OK                    in case the Length (as in-parameter) is smaller than
                                          the received length of the dynamic length signal
              COM_SERVICE_NOT_AVAILABLE   corresponding I-PDU group was stopped
                                          (or service failed due to development error)
              COM_BUSY                    in case the TP-Buffer is locked
    \context  The function can be called on interrupt and task level.
    \note     The function is called by the upper layer.
  \pre      -
**********************************************************************************************************************/
FUNC(uint8, COM_CODE) Com_ReceiveDynSignal(Com_SignalIdType SignalId,
                                           P2VAR(void, AUTOMATIC, COM_APPL_VAR) SignalDataPtr, P2VAR(uint16, AUTOMATIC,
                                                                                                     COM_APPL_VAR)
                                           Length);
# endif/* (COM_RXTPINFO == STD_ON) &&(COM_EXISTS_UINT8_DYN_APPLTYPEOFRXACCESSINFO == STD_ON) */

# if (COM_RXACCESSINFO == STD_ON)
/**********************************************************************************************************************
  Com_ReceiveSignal
**********************************************************************************************************************/
/** \brief    The service Com_ReceiveSignal updates the signal data referenced by SignalDataPtr
              with the data in the signal object identified by SignalId.
              If the signal processing of the corresponding I-Pdu is configured to DEFERRED
              the last received signal value is available not until the next call to Com_MainfunctionRx.
              If a group signal is read, the data in the shadow buffer should be updated before the call
              by a call of the service Com_ReceiveSignalGroup.
              For signals with a bit-size equal to 0, SignalDataPtr can be passed as NULL_PTR.
    \param    SignalId                    Id of signal or group signal to be received.
    \param    SignalDataPtr               Reference to the signal data in which to store the received data.
    \return   uint8
              E_OK                        service has been accepted
              COM_SERVICE_NOT_AVAILABLE   corresponding I-PDU group was stopped
                                          (or service failed due to development error)
    \context  The function can be called on interrupt and task level.
    \note     The function is called by the upper layer.
  \pre      -
**********************************************************************************************************************/
FUNC(uint8, COM_CODE) Com_ReceiveSignal(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_APPL_VAR) SignalDataPtr);
# endif/* (COM_RXACCESSINFO == STD_ON) */

# if ((COM_RXSIGGRPINFO == STD_ON)&&(COM_RXACCESSINFO == STD_ON))
/**********************************************************************************************************************
  Com_ReceiveShadowSignal
**********************************************************************************************************************/
/** \brief    The service Com_ReceiveShadowSignal updates the group signal data referenced by SignalDataPtr
              with the data in the shadow buffer.
              The data in the shadow buffer should be updated before the call of Com_ReceiveShadowSignal
              by a call of the service Com_ReceiveSignalGroup.
              For signals with a bit-size equal to 0, SignalDataPtr can be passed as NULL_PTR.
    \param    SignalId                    Id of group signal to be received.
    \param    SignalDataPtr               Reference to the group signal data in which to store the received data.
    \return   void
    \context  The function can be called on interrupt and task level.
  \pre      Com_Init() has been called with success.
    \note     The function is called by the upper layer.
    \deprecated This function is deprecated. Use 'Com_ReceiveSignal' instead to read group signals.
**********************************************************************************************************************/
#  define Com_ReceiveShadowSignal(SignalId, SignalDataPtr) (void) Com_ReceiveSignal((SignalId), (SignalDataPtr))
# endif/* ((COM_RXSIGGRPINFO == STD_ON)&&(COM_RXACCESSINFO == STD_ON)) */

# if (COM_RXSIGGRPINFO == STD_ON)
/**********************************************************************************************************************
  Com_ReceiveSignalGroup
**********************************************************************************************************************/
/** \brief    The service Com_ReceiveSignalGroup copies the received signal group to the shadow buffer.
              After this call, the group signals could be copied from the shadow buffer to the upper layer by
              a call of Com_ReceiveShadowSignal.
    \param    SignalGroupId               Id of signal group to be received.
    \return   uint8
              E_OK                        service has been accepted
              COM_SERVICE_NOT_AVAILABLE   corresponding I-PDU group was stopped
                                          (or service failed due to development error)
    \context  The function can be called on interrupt and task level.
              To guarantee data consistency of the whole signal group the complete reception of a signal group
              (consecutive calls of 'Com_ReceiveSignalGroup' and 'Com_ReceiveSignal')
              must not be interrupted by another reception request for the same signal group.
    \note     The function is called by the upper layer.
    \pre      -
**********************************************************************************************************************/
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId);
# endif/* (COM_RXSIGGRPINFO == STD_ON) */

# if (COM_ENABLE_SIGNAL_GROUP_ARRAY_API == STD_ON)
/**********************************************************************************************************************
  Com_ReceiveSignalGroupArray
**********************************************************************************************************************/
/** \brief    The service Com_ReceiveSignalGroupArray copies the received signal group
              array representation from the PDU to the location designated by SignalGroupArrayPtr.
    \param    SignalGroupId             Id of signal group to be received.
              SignalGroupArrayPtr       reference to the location where the received signal group
                                        array shall be stored
    \return   uint8
              E_OK                        service has been accepted
              COM_SERVICE_NOT_AVAILABLE   corresponding I-PDU group was stopped (or service failed due to development
                                          error)
              COM_BUSY                    in case the TP-Buffer is locked for large data types handling
    \context  The function can be called on interrupt and task level.
    \note     This function is called by COM transformer (RTE).
    \pre      The configuration switch ComEnableSignalGroupArrayApi has to be enabled.
**********************************************************************************************************************/
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupArray(Com_SignalGroupIdType SignalGroupId,
                                                  P2VAR(uint8, AUTOMATIC, COM_APPL_VAR) SignalGroupArrayPtr);
# endif/* (COM_ENABLE_SIGNAL_GROUP_ARRAY_API == STD_ON) */

/* KB end Com_RxSigIf_GlobalFunctionPrototypes */
/* KB begin Com_RxInv_GlobalFunctionPrototypes */
/* KB end Com_RxInv_GlobalFunctionPrototypes */
/* KB begin Com_TxInv_GlobalFunctionPrototypes */
# if (COM_INVVALUEUSEDOFTXSIGINFO == STD_ON)
/**********************************************************************************************************************
  Com_InvalidateSignal
**********************************************************************************************************************/
/** \brief    This function invalidates the signal or group signal by calling Com_SendSignal
              with the configured invalid value.
              If this function is used to invalidate a group signal, a call to Com_SendSignalGroup is needed
              to update the signal group data.

    \param    SignalId      ID of signal or group signal to be invalidated.
    \return   uint8
              E_OK                        service has been accepted
              COM_SERVICE_NOT_AVAILABLE   corresponding I-PDU group was stopped
                                          (or service failed due to development error)
    \context  The function can be called on interrupt and task level and has not to be interrupted
              by other Com_SendSignal and Com_InvalidateSignal calls for the same SignalId.
    \note     The function is called by the upper layer.
    \pre      -
**********************************************************************************************************************/
FUNC(uint8, COM_CODE) Com_InvalidateSignal(Com_SignalIdType SignalId);
# endif/* (COM_INVVALUEUSEDOFTXSIGINFO == STD_ON) */

# if (COM_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO == STD_ON)
/**********************************************************************************************************************
  Com_InvalidateSignalGroup
**********************************************************************************************************************/
/** \brief    This function invalidates the whole signal group by calling Com_SendSignal
              with the configured invalid value for all group signals of the signal group.
              After invalidation of the current signal group data Com_SendSignalGroup is performed internally.

    \param    SignalGroupId      ID of signal group to be invalidated.
    \return   uint8
              E_OK                        service has been accepted
              COM_SERVICE_NOT_AVAILABLE   corresponding I-PDU group was stopped
              (or service failed due to development error)
    \context  The function can be called on interrupt and task level and has not to be interrupted
              by other Com_InvalidateSignalGroup calls for the same SignalGroupId and
              by Com_SendSignal calls for a SignalId which is contained in the same signal group.
    \note     The function is called by the upper layer.
    \pre      -
**********************************************************************************************************************/
FUNC(uint8, COM_CODE) Com_InvalidateSignalGroup(Com_SignalGroupIdType SignalGroupId);
# endif/* (COM_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO == STD_ON) */

# if ((COM_TXSIGGRPINFOUSEDOFTXSIGINFO == STD_ON)&&(COM_INVVALUEUSEDOFTXSIGINFO == STD_ON))
/**********************************************************************************************************************
  Com_InvalidateShadowSignal
**********************************************************************************************************************/
/** \brief    This function invalidates the group signal by calling Com_SendSignal
              with the configured invalid value.
              An additional call to Com_SendSignalGroup is needed to update the signal group data.

    \param    SignalId      ID of group signal to be invalidated.
    \return   void
    \context  The function can be called on interrupt and task level and has not to be interrupted
              by other Com_SendSignal and Com_InvalidateSignal calls for the same SignalId.
    \note     The function is called by the upper layer.
    \deprecated This function is deprecated. Use 'Com_InvalidateSignal' instead to invalidate a group signals.
    \pre      -
**********************************************************************************************************************/
#  define Com_InvalidateShadowSignal(SignalId) (void) Com_InvalidateSignal((SignalId))
# endif/* ((COM_TXSIGGRPINFOUSEDOFTXSIGINFO == STD_ON)&&(COM_INVVALUEUSEDOFTXSIGINFO == STD_ON)) */
/* KB end Com_TxInv_GlobalFunctionPrototypes */
/* KB begin Com_TxBuffer_GlobalFunctionPrototypes */
/* KB end Com_TxBuffer_GlobalFunctionPrototypes */
/* KB begin Com_TxDlMon_GlobalFunctionPrototypes */
/* KB end Com_TxDlMon_GlobalFunctionPrototypes */
/* KB begin Com_TxLLIf_GlobalFunctionPrototypes */
/* KB end Com_TxLLIf_GlobalFunctionPrototypes */
/* KB begin Com_TxModeHdlr_GlobalFunctionPrototypes */
# if (COM_SWITCH_IPDU_TX_MODE_API == STD_ON)
/**********************************************************************************************************************
  Com_SwitchIpduTxMode
**********************************************************************************************************************/
/** \brief    This method sets the TX Mode of the I-PDU referenced by PduId to Mode.
              In case the TX Mode changes the new mode is immediately effective.
              In case the requested transmission mode was already active for this I-PDU, the call will have no effect.
    \param    PduId    ID of AUTOSAR COM Tx I-PDU.
    \param    Mode     TX mode of the I-PDU (TRUE/FALSE)
    \return   none
    \context  The function can be called on interrupt and task level
    \note     The function is used by the Basic Software Mode Manager.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_SwitchIpduTxMode(PduIdType PduId, boolean Mode);
# endif/* (COM_SWITCH_IPDU_TX_MODE_API == STD_ON) */

# if (COM_TXMODEINFO == STD_ON)
#  if (COM_FILTERINFOUSEDOFTXSIGINFO == STD_ON)
/**********************************************************************************************************************
  Com_TxModeHdlr_UpdateTxMode
**********************************************************************************************************************/
/** \brief    This method manages the tx signal filter states for each tx I-PDU and the transmission mode selection.
              It is called each time a tx signal filter has been evaluated.
    \param    ComTxPduId      ID of AUTOSAR COM Tx I-PDU.
    \param    FilterIdx       Index of signal filter object
    \param    FilterState     New state of the signal filter.
    \return   none
    \context  The function can be called on interrupt and task level.
    \note     The function is called by Com_TxSigIf_SendSignal and by the signal access macros.
    \pre      -
**********************************************************************************************************************/
COM_LOCAL FUNC(void, COM_CODE) Com_TxModeHdlr_UpdateTxMode(CONST(PduIdType, AUTOMATIC) ComTxPduId,
                                                           Com_TxFilterInitStateIdxOfTxSigInfoType idxTxFilterState,
                                                           boolean FilterState);
#  endif/* (COM_FILTERINFOUSEDOFTXSIGINFO == STD_ON) */

#  if (COM_TSI_TESTCODE == STD_ON)
/* ##V_TEST_CODE_START ##Ms */
/**********************************************************************************************************************
Com_TxModeHdlr_StopCyclicTransmission
**********************************************************************************************************************/
/** \brief    This method stops the cyclic transmission of an I-PDU and cancels outstanding transmission requests of
              an I-PDU and reloads the time offset counter, if the I-PDU is restarted later.
    \param    ComTxPduId    ID of AUTOSAR COM Tx I-PDU.
    \return   none
    \context  The function can be called on interrupt and task level,
              but must not interfer with Com_TxModeHdlr_MainFunction.
    \note     The function is called by the Testsuite.
    \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TxModeHdlr_StopCyclicTransmission(CONST(PduIdType, AUTOMATIC) ComTxPduId);

/**********************************************************************************************************************
  Com_TxModeHdlr_TriggerImmediateIpduSend
**********************************************************************************************************************/
/** \brief    This method sets an transmission request. The I-PDU transmit request is performed with the next tx
              task call. The time offset is not taken into account.
    \param    ComTxPduId    ID of AUTOSAR COM Tx I-PDU.
    \return   none
    \context  The function can be called on interrupt and task level,
              but must not interfer with Com_TxModeHdlr_MainFunction.
    \note     The function is called by the Testsuite.
    \pre      -
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TxModeHdlr_TriggerImmediateIpduSend(CONST(PduIdType, AUTOMATIC) ComTxPduId);
/* ##V_TEST_CODE_END ##Ms */
#  endif/* (COM_TSI_TESTCODE == STD_ON) */
# endif/* (COM_TXMODEINFO == STD_ON) */
/* KB end Com_TxModeHdlr_GlobalFunctionPrototypes */
/* KB begin Com_TxNHdlr_GlobalFunctionPrototypes */
/* KB end Com_TxNHdlr_GlobalFunctionPrototypes */
/* KB begin Com_TxSigIf_GlobalFunctionPrototypes */

# if (COM_TXSIGINFO == STD_ON)
/**********************************************************************************************************************
  Com_SendDynSignal
**********************************************************************************************************************/
/** \brief    The service Com_SendDynSignal updates the signal or group signal object identified by SignalId
              with the signal data referenced by the SignalDataPtr parameter. The Length parameter is evaluated for
              dynamic length signals.
    \param    SignalId      ID of signal or group signal to be sent.
    \param    SignalDataPtr Reference to the signal data to be transmitted.
    \param    Length        Length of the dynamic length signal.
    \return   uint8
              E_OK                        service has been accepted
              COM_SERVICE_NOT_AVAILABLE   corresponding I-PDU group was stopped
                                          (or service failed due to development error)
              COM_BUSY                    in case the TP-Buffer is locked for large data types handling
    \context  The function can be called on interrupt and task level and has not to be interrupted
              by other Com_SendSignal and Com_InvalidateSignal calls for the same SignalId.
    \note     The function is called by the upper layer.
    \warning  If the method is used on a microcontroller like the Tms320 DSP and the datatype uint8 is unsigned short
              the 8 MSB bits of the variable shall never be set.
              If the method is used on a microcontroller like the S12X and the datatype is uint16, sint16, uint32
              or sint32 the SignalDataPtr must be word aligned.
    \pre      -
**********************************************************************************************************************/
FUNC(uint8, COM_CODE) Com_SendDynSignal(Com_SignalIdType SignalId,
                                        P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr, uint16 Length);
# endif/* (COM_TXSIGINFO == STD_ON) */

# if (COM_TXSIGINFO == STD_ON)
/**********************************************************************************************************************
  Com_SendSignal
**********************************************************************************************************************/
/** \brief    The service Com_SendSignal updates the signal or group signal object identified by SignalId
              with the signal data referenced by the SignalDataPtr parameter.
              For signals with a bit-size equal to 0, SignalDataPtr can be passed as NULL_PTR.
    \param    SignalId      ID of signal or group signal to be sent.
    \param    SignalDataPtr Reference to the signal data to be transmitted.
    \return   uint8
              E_OK                        service has been accepted
              COM_SERVICE_NOT_AVAILABLE   corresponding I-PDU group was stopped
                                          (or service failed due to development error)
              COM_BUSY                    in case the TP-Buffer is locked for large data types handling
    \context  The function can be called on interrupt and task level and has not to be interrupted
              by other Com_SendSignal and Com_InvalidateSignal calls for the same SignalId.
    \note     The function is called by the upper layer.
    \warning  If the method is used on a microcontroller like the Tms320 DSP and the datatype uint8 is unsigned short
              the 8 MSB bits of the variable shall never be set.
              If the method is used on a microcontroller like the S12X and the datatype is uint16, sint16, uint32
              or sint32 the SignalDataPtr must be word aligned.
    \pre      -
**********************************************************************************************************************/
#  define Com_SendSignal(SignalId, SignalDataPtr)  Com_SendDynSignal((SignalId), (SignalDataPtr), 0)
# endif/* (COM_TXSIGINFO == STD_ON) */

# if (COM_TXSIGGRPINFO == STD_ON)
/**********************************************************************************************************************
  Com_SendSignalGroup
**********************************************************************************************************************/
/** \brief    The service Com_SendSignalGroup copies the content of the associated shadow buffer to
              the associated I-PDU buffer.
              Prior to this call, all group signals should be updated in the shadow buffer
              by the call of Com_SendSignal.
    \param    SignalGroupId      ID of signal group to be send.
    \return   uint8
              E_OK                        service has been accepted
              COM_SERVICE_NOT_AVAILABLE   corresponding I-PDU group was stopped
              (or service failed due to development error)
    \context  The function can be called on interrupt and task level and has not to be interrupted
              by other Com_SendSignalGroup calls for the same SignalGroupId.
              To guarantee data consistency of the whole signal group the complete transmission of a signal group
              (consecutive calls of 'Com_SendSignal' and 'Com_SendSignalGroup') must not be interrupted
              by another transmission request for the same signal group or by a call of 'Com_InvalidateSignalGroup'.
    \note     The function is called by the upper layer.
    \pre      -
**********************************************************************************************************************/
FUNC(uint8, COM_CODE) Com_SendSignalGroup(Com_SignalGroupIdType SignalGroupId);
# endif/* (COM_TXSIGGRPINFO == STD_ON) */

# if (COM_TXSIGINFO == STD_ON)
/**********************************************************************************************************************
  Com_UpdateShadowSignal
**********************************************************************************************************************/
/** \brief    The service Com_UpdateShadowSignal updates a group signal with the data, referenced by SignalDataPtr.
              The update of the group signal data is done in the shadow buffer, not in the I-PDU.
              To send out the shadow buffer, Com_SendSignalGroup has to be called.
              For signals with a bit-size equal to 0, SignalDataPtr can be passed as NULL_PTR.
    \param    SignalId      ID of group signal to be updated.
    \param    SignalDataPtr Reference to the group signal data to be updated.
    \return   void
    \context  The function can be called on interrupt and task level.
    \note     The function is called by the upper layer.
    \warning  If the method is used on a microcontroller like the S12X and the datatype is uint16, sint16, uint32
              or sint32 the SignalDataPtr must be word aligned.
    \deprecated This function is deprecated. Use 'Com_SendSignal' instead to send group signals.
    \pre      -
**********************************************************************************************************************/
#  define Com_UpdateShadowSignal(SignalId, SignalDataPtr) (void) Com_SendSignal((SignalId), (SignalDataPtr))
# endif/* (COM_TXSIGINFO == STD_ON) */

# if (COM_ENABLE_SIGNAL_GROUP_ARRAY_API == STD_ON)
/**********************************************************************************************************************
  Com_SendSignalGroupArray
**********************************************************************************************************************/
/** \brief    The service Com_SendSignalGroupArray copies the content of the provided SignalGroupArrayPtr to the
 *            associated I-PDU. The provided data shall correspond to the array representation of the signal group.
    \param    SignalGroupId               Id of signal group to be sent.
              SignalGroupArrayPtr         Reference to the signal group array.
    \return   uint8
              E_OK                        service has been accepted
              COM_SERVICE_NOT_AVAILABLE   corresponding I-PDU group was stopped (or service failed due to development
                                          error)
              COM_BUSY                    in case the TP-Buffer is locked for large data types handling
    \context  The function can be called on interrupt and task level.
    \note     The function is called by the COM transformer (RTE).
    \pre      The configuration switch ComEnableSignalGroupArrayApi has to be enabled.
**********************************************************************************************************************/
FUNC(uint8, COM_CODE) Com_SendSignalGroupArray(Com_SignalGroupIdType SignalGroupId,
                                               P2CONST(uint8, AUTOMATIC, COM_APPL_VAR) SignalGroupArrayPtr);
# endif/* (COM_ENABLE_SIGNAL_GROUP_ARRAY_API == STD_ON) */
/* KB end Com_TxSigIf_GlobalFunctionPrototypes */
/* KB begin Com_SignalGw_GlobalFunctionPrototypes */
# if (COM_GWINFO == STD_ON)
/**********************************************************************************************************************
  Com_MainFunctionRouteSignals
**********************************************************************************************************************/
/** \brief    Calls the signal gateway part of COM to forward received signals to be routed.
              The insertion of this call is necessary for decoupling receive interrupts and signal gateway tasks.
              A call to Com_MainFunctionRouteSignals returns simply if COM was not previously initialized with a
              call to Com_Init.
    \return   None
    \context  The function must be called on task level.
    \note     The function is called by the BSW Scheduler.
    \warning  The time between to consecutive calls (perhaps the related task/thread cycle)
              affects directly the signal gateway latency.
    \pre      -
**********************************************************************************************************************/
/* the function prototype is implemented in file 'SchM_Com.h' */
# endif
/* KB end Com_SignalGw_GlobalFunctionPrototypes */

# define COM_STOP_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_19.1 */

#endif /* COM_H */

/**********************************************************************************************************************
  END OF FILE: Com.h
**********************************************************************************************************************/
