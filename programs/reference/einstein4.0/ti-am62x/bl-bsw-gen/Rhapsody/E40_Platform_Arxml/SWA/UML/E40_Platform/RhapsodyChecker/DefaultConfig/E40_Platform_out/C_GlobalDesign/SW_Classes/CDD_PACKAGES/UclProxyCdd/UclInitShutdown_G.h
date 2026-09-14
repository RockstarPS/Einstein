#ifndef __UclInitShutdown_G_h__
#define __UclInitShutdown_G_h__
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
//      DO NOT CHANGE THIS FILE! IT HAS BEEN GENERATED. ANY CHANGES WILL BE OVERWRITTEN AT THE NEXT GENERATION!
// ---------------------------------------------------------------------------------------------------------------------
// Generated on Fri Jul 26 12:05:08 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              UclInitShutdown (TransportedInterface)
// Description:         None
// Owner:               UclProxyCdd (Package)
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
//                                     Function table declaration (allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(UclInitShutdown_USAGE_VISIBILITY))
typedef const struct sUclInitShutdownRequired
{
    SysReturnType (*Call_Impl_Shutdown)(void); // Initiate call of Impl_Shutdown
    SysReturnType (*Call_Impl_Initialize)(void); // Initiate call of Impl_Initialize
} tUclInitShutdownRequired;
#endif // #if (defined(UclInitShutdown_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(UclInitShutdown_USAGE_VISIBILITY))
#define mUclInitShutdownRequired_Allocate(instanceName, itsUclInitShutdown_FCTTBL) \
    tUclInitShutdownRequired instanceName = itsUclInitShutdown_FCTTBL;
#endif // #if (defined(UclInitShutdown_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(UclInitShutdown_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/UclInitShutdown/<AutoCreatedOperation>Call_Impl_Shutdown
// Method      :        UclInitShutdown_CallImpl_Shutdown(tUclInitShutdown_Ref const This)
// Visibility  :        public
// Description :        Initiate call of Impl_Shutdown
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          | Name(Direction) |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tUclInitShutdown_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define UclInitShutdown_CallImpl_Shutdown(Ref) \
    (SysReturnType)(Ref)->Call_Impl_Shutdown()

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/UclInitShutdown/<AutoCreatedOperation>Call_Impl_Initialize
// Method      :        UclInitShutdown_CallImpl_Initialize(tUclInitShutdown_Ref const This)
// Visibility  :        public
// Description :        Initiate call of Impl_Initialize
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          | Name(Direction) |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tUclInitShutdown_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define UclInitShutdown_CallImpl_Initialize(Ref) \
    (SysReturnType)(Ref)->Call_Impl_Initialize()

#endif // #if (defined(UclInitShutdown_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __UclInitShutdown_G_h__
