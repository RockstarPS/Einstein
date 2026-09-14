#ifndef __if_CS_MemAbsSet_G_h__
#define __if_CS_MemAbsSet_G_h__
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
// Generated on Fri Mar 22 16:09:11 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              if_CS_MemAbsSet (TransportedInterface)
// Description:         None
// Owner:               SWC_MemAbstract (Package)
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

#if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))
typedef const struct sif_CS_MemAbsSetRequired
{
    SysReturnType (*Call_Set_SampleElement1)(Arr_u8_8 * const); // Initiate call of Set_SampleElement1
    SysReturnType (*Call_Set_SampleElement2)(Arr_u8_16 * const); // Initiate call of Set_SampleElement2
} tif_CS_MemAbsSetRequired;
#endif // #if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))
#define mif_CS_MemAbsSetRequired_Allocate(instanceName, itsif_CS_MemAbsSet_FCTTBL) \
    tif_CS_MemAbsSetRequired instanceName = itsif_CS_MemAbsSet_FCTTBL;
#endif // #if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_MemAbstract/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_SampleElement1
// Method      :        if_CS_MemAbsSet_CallSet_SampleElement1(tif_CS_MemAbsSet_Ref const This, Arr_u8_8 * const SampleElement1)
// Visibility  :        public
// Description :        Initiate call of Set_SampleElement1
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |   Name(Direction)   |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)            | Class reference
// Arr_u8_8              | SampleElement1(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_SampleElement1(Ref, SampleElement1) \
    (SysReturnType)(Ref)->Call_Set_SampleElement1(SampleElement1)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_MemAbstract/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_SampleElement2
// Method      :        if_CS_MemAbsSet_CallSet_SampleElement2(tif_CS_MemAbsSet_Ref const This, Arr_u8_16 * const SampleElement2)
// Visibility  :        public
// Description :        Initiate call of Set_SampleElement2
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |   Name(Direction)   |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)            | Class reference
// Arr_u8_16             | SampleElement2(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_SampleElement2(Ref, SampleElement2) \
    (SysReturnType)(Ref)->Call_Set_SampleElement2(SampleElement2)

#endif // #if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __if_CS_MemAbsSet_G_h__
