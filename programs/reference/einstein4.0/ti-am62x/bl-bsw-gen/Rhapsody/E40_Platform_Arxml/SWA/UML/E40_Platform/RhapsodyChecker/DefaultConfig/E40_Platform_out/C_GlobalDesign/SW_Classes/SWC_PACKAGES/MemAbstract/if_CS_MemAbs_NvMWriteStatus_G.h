#ifndef __if_CS_MemAbs_NvMWriteStatus_G_h__
#define __if_CS_MemAbs_NvMWriteStatus_G_h__
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
// Generated on Fri Mar 22 16:34:47 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              if_CS_MemAbs_NvMWriteStatus (TransportedInterface)
// Description:         None
// Owner:               MemAbstract (Package)
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

#if (defined(if_CS_MemAbs_NvMWriteStatus_USAGE_VISIBILITY))
typedef const struct sif_CS_MemAbs_NvMWriteStatusRequired
{
    SysReturnType (*Call_NvmWriteStatus)(void); // Initiate call of NvmWriteStatus
} tif_CS_MemAbs_NvMWriteStatusRequired;
#endif // #if (defined(if_CS_MemAbs_NvMWriteStatus_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(if_CS_MemAbs_NvMWriteStatus_USAGE_VISIBILITY))
#define mif_CS_MemAbs_NvMWriteStatusRequired_Allocate(instanceName, itsif_CS_MemAbs_NvMWriteStatus_FCTTBL) \
    tif_CS_MemAbs_NvMWriteStatusRequired instanceName = itsif_CS_MemAbs_NvMWriteStatus_FCTTBL;
#endif // #if (defined(if_CS_MemAbs_NvMWriteStatus_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_CS_MemAbs_NvMWriteStatus_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_CS_MemAbs_NvMWriteStatus/<AutoCreatedOperation>Call_NvmWriteStatus
// Method      :        if_CS_MemAbs_NvMWriteStatus_CallNvmWriteStatus(tif_CS_MemAbs_NvMWriteStatus_Ref const This)
// Visibility  :        public
// Description :        Initiate call of NvmWriteStatus
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//               Type                | Name(Direction) |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbs_NvMWriteStatus_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbs_NvMWriteStatus_CallNvmWriteStatus(Ref) \
    (SysReturnType)(Ref)->Call_NvmWriteStatus()

#endif // #if (defined(if_CS_MemAbs_NvMWriteStatus_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __if_CS_MemAbs_NvMWriteStatus_G_h__
