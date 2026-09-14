#ifndef __A2T_OBC_Typedefs_G_h__
#define __A2T_OBC_Typedefs_G_h__
#ifndef _QAC_
// *********************************************************************************************************************
// Company:             Johnson Controls Inc.
// ---------------------------------------------------------------------------------------------------------------------
// Copyright:           This software is JCI property.
//                      Duplication or disclosure without JCI written authorization is prohibited.
// ---------------------------------------------------------------------------------------------------------------------
// Project:             E40_Platform
// Language:            C
// ---------------------------------------------------------------------------------------------------------------------
// This file contains package types definition
// ---------------------------------------------------------------------------------------------------------------------
// Generated on Tue Aug 06 13:07:42 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              A2T_OBC (DesignUnit)
// Description:         A2TOM Object Communication framework
// Owner:               A2T_TC_FWK_OBCINSTANCER (Package)
// ---------------------------------------------------------------------------------------------------------------------
// Rhapsody version:    9.0.1
// Generator version:   V3.0.27
// Generator date:      11/12/2014 12:04:26,40
// ---------------------------------------------------------------------------------------------------------------------
// PVCS section start
// PVCS Log:
// $Log: $
// PVCS section end
// *********************************************************************************************************************
#endif // #ifndef _QAC_

// ---------------------------------------------------------------------------------------------------------------------
//                                                   Types definition
// ---------------------------------------------------------------------------------------------------------------------

// Enumeration type A2TCallTrigger
#ifndef A2T_TypesProtection_A2TCallTrigger
#define A2T_TypesProtection_A2TCallTrigger
// ---------------------------------------------------------------------------------------------------------------------
// This enumerator type defines the possible events raised by a <<call>> operation defined within a
// TransportedInterface. Selectable literals are:
// 
// OpertationInvoked: A runnable entity on the client side is triggered by the RTE in response to a received request
// from the client to execute the operation. Corresponding RTE-Event is OperationInvokedEvent and is relevant for
// client-server communication.
// NB: This event is no more selectable because it is implicily put when TI server name equal to class function name
// which realize the interface.
// 
// AsynchronousServerCallReturns: A runnable entity on the client side is triggered to process the result of the
// asynchronous server call operation. Corresponding RTE-Event is AsynchronousServerCallReturnsEvent and is relevant
// for client-server communication.
// 
// Related References:
// - AUTOSAR Specification of RTE
// ---------------------------------------------------------------------------------------------------------------------
typedef enum {
    AsynchronousServerCallReturn,
    OperationInvoke
} A2TCallTrigger;
#define eAsynchronousServerCallReturn AsynchronousServerCallReturn
#define eOperationInvoke OperationInvoke
#define tA2TCallTrigger A2TCallTrigger
#endif

// Enumeration type A2TClientMode
#ifndef A2T_TypesProtection_A2TClientMode
#define A2T_TypesProtection_A2TClientMode
// ---------------------------------------------------------------------------------------------------------------------
// This enumerator type defines the possible ways to invoke a <<call>> operation defined within a TransportedInterface.
// Selectable literals are:
// 
// Asynchronous: Asynchronous invocation of the operation.
// 
// Synchronous: Synchronous invocation of the operation
// 
// Related References:
// - AUTOSAR Specification of RTE
// ---------------------------------------------------------------------------------------------------------------------
typedef enum {
    A2TAsynchronous,
    A2TSynchronous
} A2TClientMode;
#define eA2TAsynchronous A2TAsynchronous
#define eA2TSynchronous A2TSynchronous
#define tA2TClientMode A2TClientMode
#endif

// Enumeration type A2TDataTrigger
#ifndef A2T_TypesProtection_A2TDataTrigger
#define A2T_TypesProtection_A2TDataTrigger
// ---------------------------------------------------------------------------------------------------------------------
// This enumerator type defines the possible events raised by a <<data>> attribute defined within a
// TransportedInterface. Selectable literals are:
// 
// DataReceived: A runnable entity on the receiver side is triggered by the RTE to receive and process a data attribute
// defined in the TransportedInterface. Corresponding RTE-Event is DataReceivedEvent and is relevant for
// sender-receiver communication.
// 
// DataReceivedError: A runnable entity on the receiver side is triggered by the RTE to collect the error status of a
// data attribute defined in the TransportedInterface. Corresponding RTE-Event is DataReceiveErrorEvent and is relevant
// for sender-receiver communication.
// 
// DataSendCompleted: A runnable entity on the provider side is triggered by the RTE to receive transmission
// acknowledgement notifications for a data attribute defined in the TransportedInterface. Corresponding RTE-Event is
// DataSendCompletedEvent and is relevant for sender-receiver communication.
// 
// Related References:
// - AUTOSAR Specification of RTE
// ---------------------------------------------------------------------------------------------------------------------
typedef enum {
    DataReceive,
    DataReceiveError,
    DataSendComplete
} A2TDataTrigger;
#define eDataReceive DataReceive
#define eDataReceiveError DataReceiveError
#define eDataSendComplete DataSendComplete
#define tA2TDataTrigger A2TDataTrigger
#endif

// Enumeration type A2TEventTrigger
#ifndef A2T_TypesProtection_A2TEventTrigger
#define A2T_TypesProtection_A2TEventTrigger
// ---------------------------------------------------------------------------------------------------------------------
// This enumerator type defines the possible events raised by a <<event>> attribute defined within a
// TransportedInterface. Selectable literals are:
// 
// DataReceived: A runnable entity on the receiver side is triggered by the RTE to receive and process a data attribute
// defined in the TransportedInterface. Corresponding RTE-Event is DataReceivedEvent and is relevant for
// sender-receiver communication.
// 
// DataSendCompleted: A runnable entity on the provider side is triggered by the RTE to receive transmission
// acknowledgement notifications for a data attribute defined in the TransportedInterface. Corresponding RTE-Event is
// DataSendCompletedEvent and is relevant for sender-receiver communication.
// 
// Related References:
// - AUTOSAR Specification of RTE
// ---------------------------------------------------------------------------------------------------------------------
typedef enum {
    DataReceive,
    DataSendComplete
} A2TEventTrigger;
#define eDataReceive DataReceive
#define eDataSendComplete DataSendComplete
#define tA2TEventTrigger A2TEventTrigger
#endif

// Enumeration type A2TInvalidHandling
#ifndef A2T_TypesProtection_A2TInvalidHandling
#define A2T_TypesProtection_A2TInvalidHandling
// ---------------------------------------------------------------------------------------------------------------------
// This enumerator type defines the possible ways to handle the reception of an invalid data or event. Selectable
// literals are:
// 
// Keep: The invalid value is kept as it was received.
// 
// Replace: The invalid value is replaced by a valid one as defined by the user.
// 
// Related References:
// - AUTOSAR Specification of RTE
// ---------------------------------------------------------------------------------------------------------------------
typedef enum {
    A2TKeep,
    A2TReplace
} A2TInvalidHandling;
#define eA2TKeep A2TKeep
#define eA2TReplace A2TReplace
#define tA2TInvalidHandling A2TInvalidHandling
#endif

// Enumeration type A2TModeTrigger
#ifndef A2T_TypesProtection_A2TModeTrigger
#define A2T_TypesProtection_A2TModeTrigger
// ---------------------------------------------------------------------------------------------------------------------
// This enumerator type defines the possible events raised by a <<mode>> attribute defined within a
// TransportedInterface. Selectable literals are:
// 
// ModeSwitchOnEntry: A runnable entity is triggered by the RTE as result of a mode switch when the new mode is
// entered. Corresponding RTE-Event is SwcModeSwitchEvent.
// 
// ModeSwitchOnExit: A runnable entity is triggered by the RTE as result of a mode switch when the new mode is left.
// Corresponding RTE-Event is SwcModeSwitchEvent.
// 
// Related References:
// - AUTOSAR Specification of RTE
// ---------------------------------------------------------------------------------------------------------------------
typedef enum {
    ModeSwitchOnEntry,
    ModeSwitchOnExit
} A2TModeTrigger;
#define eModeSwitchOnEntry ModeSwitchOnEntry
#define eModeSwitchOnExit ModeSwitchOnExit
#define tA2TModeTrigger A2TModeTrigger
#endif

// Enumeration type A2TBoolean
#ifndef A2T_TypesProtection_A2TBoolean
#define A2T_TypesProtection_A2TBoolean
// ---------------------------------------------------------------------------------------------------------------------
// 1-bit, 0 - FALSE, otherwise TRUE, used only in meta-models
// ---------------------------------------------------------------------------------------------------------------------
typedef enum {
    A2TFalse, // Value of zero
    A2TTrue // Value different than zero
} A2TBoolean;
#define eA2TFalse A2TFalse
#define eA2TTrue A2TTrue
#define tA2TBoolean A2TBoolean
#endif

// Language type A2TDouble
#ifndef A2T_TypesProtection_A2TDouble
#define A2T_TypesProtection_A2TDouble
// ---------------------------------------------------------------------------------------------------------------------
// 64-bits floating point, used only in meta-models
// ---------------------------------------------------------------------------------------------------------------------

#endif

// Language type A2TLong
#ifndef A2T_TypesProtection_A2TLong
#define A2T_TypesProtection_A2TLong
// ---------------------------------------------------------------------------------------------------------------------
// 64-bit signed integer type, used only in meta-models
// ---------------------------------------------------------------------------------------------------------------------

#endif

// Language type A2TString
#ifndef A2T_TypesProtection_A2TString
#define A2T_TypesProtection_A2TString
// ---------------------------------------------------------------------------------------------------------------------
// Unicode text string, used only in meta-models
// ---------------------------------------------------------------------------------------------------------------------

#endif

// Enumeration type A2TUniqueAllocatable
#ifndef A2T_TypesProtection_A2TUniqueAllocatable
#define A2T_TypesProtection_A2TUniqueAllocatable
typedef enum {
    Automatic,
    True,
    False
} A2TUniqueAllocatable;
#define eAutomatic Automatic
#define eTrue True
#define eFalse False
#define tA2TUniqueAllocatable A2TUniqueAllocatable
#endif

// Enumeration type A2TPortAccess
#ifndef A2T_TypesProtection_A2TPortAccess
#define A2T_TypesProtection_A2TPortAccess
typedef enum {
    All,
    None
} A2TPortAccess;
#define eAll All
#define eNone None
#define tA2TPortAccess A2TPortAccess
#endif

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __A2T_OBC_Typedefs_G_h__
