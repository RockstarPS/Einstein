#ifndef __if_CS_DmnMonitoring_G_h__
#define __if_CS_DmnMonitoring_G_h__
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
// Entity:              if_CS_DmnMonitoring (TransportedInterface)
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

#if (defined(if_CS_DmnMonitoring_USAGE_VISIBILITY))
typedef const struct sif_CS_DmnMonitoringRequired
{
    SysReturnType (*Call_StopDomainMonitoring)(EDomainId const); // Initiate call of StopDomainMonitoring
    SysReturnType (*Call_StartDomainMonitoring)(EDomainId const); // Initiate call of StartDomainMonitoring
} tif_CS_DmnMonitoringRequired;
#endif // #if (defined(if_CS_DmnMonitoring_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(if_CS_DmnMonitoring_USAGE_VISIBILITY))
#define mif_CS_DmnMonitoringRequired_Allocate(instanceName, itsif_CS_DmnMonitoring_FCTTBL) \
    tif_CS_DmnMonitoringRequired instanceName = itsif_CS_DmnMonitoring_FCTTBL;
#endif // #if (defined(if_CS_DmnMonitoring_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_CS_DmnMonitoring_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_CORE/DmnMgr/if_CS_DmnMonitoring/<AutoCreatedOperation>Call_StopDomainMonitoring
// Method      :        if_CS_DmnMonitoring_CallStopDomainMonitoring(tif_CS_DmnMonitoring_Ref const This, EDomainId const DmnID)
// Visibility  :        public
// Description :        Initiate call of StopDomainMonitoring
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type            | Name(Direction) |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_DmnMonitoring_Ref  | This(In)        | Class reference
// EDomainId                 | DmnID(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_DmnMonitoring_CallStopDomainMonitoring(Ref, DmnID) \
    (SysReturnType)(Ref)->Call_StopDomainMonitoring(DmnID)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_CORE/DmnMgr/if_CS_DmnMonitoring/<AutoCreatedOperation>Call_StartDomainMonitoring
// Method      :        if_CS_DmnMonitoring_CallStartDomainMonitoring(tif_CS_DmnMonitoring_Ref const This, EDomainId const DmnID)
// Visibility  :        public
// Description :        Initiate call of StartDomainMonitoring
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type            | Name(Direction) |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_DmnMonitoring_Ref  | This(In)        | Class reference
// EDomainId                 | DmnID(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_DmnMonitoring_CallStartDomainMonitoring(Ref, DmnID) \
    (SysReturnType)(Ref)->Call_StartDomainMonitoring(DmnID)

#endif // #if (defined(if_CS_DmnMonitoring_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __if_CS_DmnMonitoring_G_h__
