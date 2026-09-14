#ifndef __if_CS_DmnSystemStateChange_G_h__
#define __if_CS_DmnSystemStateChange_G_h__
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
// Generated on Fri Jul 26 12:05:15 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              if_CS_DmnSystemStateChange (TransportedInterface)
// Description:         None
// Owner:               DmnMgr (Package)
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

#if (defined(if_CS_DmnSystemStateChange_USAGE_VISIBILITY))
typedef const struct sif_CS_DmnSystemStateChangeRequired
{
    SysReturnType (*Call_DmnSystemStateChangeReq)(EDomainId const, ESystemState const); // Initiate call of DmnSystemStateChangeReq
    SysReturnType (*Call_DmnSystemStateChangeStatus)(EDomainId const, EDmnChangeReqStatus_t * const); // Initiate call of DmnSystemStateChangeStatus
} tif_CS_DmnSystemStateChangeRequired;
#endif // #if (defined(if_CS_DmnSystemStateChange_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(if_CS_DmnSystemStateChange_USAGE_VISIBILITY))
#define mif_CS_DmnSystemStateChangeRequired_Allocate(instanceName, itsif_CS_DmnSystemStateChange_FCTTBL) \
    tif_CS_DmnSystemStateChangeRequired instanceName = itsif_CS_DmnSystemStateChange_FCTTBL;
#endif // #if (defined(if_CS_DmnSystemStateChange_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_CS_DmnSystemStateChange_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_CORE/DmnMgr/if_CS_DmnSystemStateChange/<AutoCreatedOperation>Call_DmnSystemStateChangeReq
// Method      :        if_CS_DmnSystemStateChange_CallDmnSystemStateChangeReq(tif_CS_DmnSystemStateChange_Ref const This, EDomainId const DmnId, ESystemState const DmnState)
// Visibility  :        public
// Description :        Initiate call of DmnSystemStateChangeReq
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//               Type               | Name(Direction) |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_DmnSystemStateChange_Ref  | This(In)        | Class reference
// EDomainId                        | DmnId(In)       | None
// ESystemState                     | DmnState(In)    | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_DmnSystemStateChange_CallDmnSystemStateChangeReq(Ref, DmnId, DmnState) \
    (SysReturnType)(Ref)->Call_DmnSystemStateChangeReq(DmnId, DmnState)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_CORE/DmnMgr/if_CS_DmnSystemStateChange/<AutoCreatedOperation>Call_DmnSystemStateChangeStatus
// Method      :        if_CS_DmnSystemStateChange_CallDmnSystemStateChangeStatus(tif_CS_DmnSystemStateChange_Ref const This, EDomainId const DmnId, EDmnChangeReqStatus_t * const pDmnStatus)
// Visibility  :        public
// Description :        Initiate call of DmnSystemStateChangeStatus
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//               Type               | Name(Direction)  |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_DmnSystemStateChange_Ref  | This(In)         | Class reference
// EDomainId                        | DmnId(In)        | None
// EDmnChangeReqStatus_t            | pDmnStatus(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_DmnSystemStateChange_CallDmnSystemStateChangeStatus(Ref, DmnId, pDmnStatus) \
    (SysReturnType)(Ref)->Call_DmnSystemStateChangeStatus(DmnId, pDmnStatus)

#endif // #if (defined(if_CS_DmnSystemStateChange_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __if_CS_DmnSystemStateChange_G_h__
