#ifndef __if_CS_MemAbsGet_G_h__
#define __if_CS_MemAbsGet_G_h__
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
// Entity:              if_CS_MemAbsGet (TransportedInterface)
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

#if (defined(if_CS_MemAbsGet_USAGE_VISIBILITY))
typedef const struct sif_CS_MemAbsGetRequired
{
    SysReturnType (*Call_Get_SampleElement1)(Arr_u8_8 * const); // Initiate call of Get_SampleElement1
    SysReturnType (*Call_Get_SampleElement2)(Arr_u8_16 * const); // Initiate call of Get_SampleElement2
} tif_CS_MemAbsGetRequired;
#endif // #if (defined(if_CS_MemAbsGet_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(if_CS_MemAbsGet_USAGE_VISIBILITY))
#define mif_CS_MemAbsGetRequired_Allocate(instanceName, itsif_CS_MemAbsGet_FCTTBL) \
    tif_CS_MemAbsGetRequired instanceName = itsif_CS_MemAbsGet_FCTTBL;
#endif // #if (defined(if_CS_MemAbsGet_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_CS_MemAbsGet_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_MemAbstract/if_CS_MemAbsGet/<AutoCreatedOperation>Call_Get_SampleElement1
// Method      :        if_CS_MemAbsGet_CallGet_SampleElement1(tif_CS_MemAbsGet_Ref const This, Arr_u8_8 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_SampleElement1
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          | Name(Direction) |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGet_Ref  | This(In)        | Class reference
// Arr_u8_8              | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGet_CallGet_SampleElement1(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_SampleElement1(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_MemAbstract/if_CS_MemAbsGet/<AutoCreatedOperation>Call_Get_SampleElement2
// Method      :        if_CS_MemAbsGet_CallGet_SampleElement2(tif_CS_MemAbsGet_Ref const This, Arr_u8_16 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_SampleElement2
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          | Name(Direction) |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGet_Ref  | This(In)        | Class reference
// Arr_u8_16             | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGet_CallGet_SampleElement2(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_SampleElement2(pPtr)

#endif // #if (defined(if_CS_MemAbsGet_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __if_CS_MemAbsGet_G_h__
