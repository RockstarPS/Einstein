#ifndef __IgnState_Q_G_h__
#define __IgnState_Q_G_h__
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
// Generated on Fri Jul 26 12:05:09 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              IgnState_Q (TransportedInterface)
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
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(IgnState_Q_PROVIDE_VISIBILITY))
typedef const struct sIgnState_QProvided
{
    SysReturnType (*SendIgnStateData)(SIgnState const); // Send operation for IgnStateData
} tIgnState_QProvided;
#endif // #if (defined(IgnState_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(IgnState_Q_USAGE_VISIBILITY))
typedef const struct sIgnState_QRequired
{
    SysReturnType (*ReceiveIgnStateData)(SIgnState * const); // Receive operation for IgnStateData
} tIgnState_QRequired;
#endif // #if (defined(IgnState_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(IgnState_Q_PROVIDE_VISIBILITY))
#define mIgnState_QProvided_Allocate(instanceName, itsIgnState_Q_FCTTBL) \
    tIgnState_QProvided instanceName = itsIgnState_Q_FCTTBL;
#endif // #if (defined(IgnState_Q_PROVIDE_VISIBILITY))

#if (defined(IgnState_Q_USAGE_VISIBILITY))
#define mIgnState_QRequired_Allocate(instanceName, itsIgnState_Q_FCTTBL) \
    tIgnState_QRequired instanceName = itsIgnState_Q_FCTTBL;
#endif // #if (defined(IgnState_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(IgnState_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/IgnState_Q/<AutoCreatedOperation>SendIgnStateData
// Method      :        IgnState_Q_SendIgnStateData(tIgnState_Q_Ref const This, SIgnState const IgnStateData)
// Visibility  :        public
// Description :        Send operation for IgnStateData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type       |  Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tIgnState_Q_Ref  | This(In)          | Class reference
// SIgnState        | IgnStateData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define IgnState_Q_SendIgnStateData(Ref, IgnStateData) \
    (SysReturnType)(Ref)->SendIgnStateData(IgnStateData)

#endif // #if (defined(IgnState_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(IgnState_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/IgnState_Q/<AutoCreatedOperation>ReceiveIgnStateData
// Method      :        IgnState_Q_ReceiveIgnStateData(tIgnState_Q_Ref const This, SIgnState * const pdata)
// Visibility  :        public
// Description :        Receive operation for IgnStateData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type       | Name(Direction) |                                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tIgnState_Q_Ref  | This(In)        | Class reference
// SIgnState        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define IgnState_Q_ReceiveIgnStateData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceiveIgnStateData(pdata)

#endif // #if (defined(IgnState_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __IgnState_Q_G_h__
