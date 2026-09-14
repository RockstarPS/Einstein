#ifndef __if_SR_DmnInfo_G_h__
#define __if_SR_DmnInfo_G_h__
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
// Entity:              if_SR_DmnInfo (TransportedInterface)
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
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_SR_DmnInfo_PROVIDE_VISIBILITY))
typedef const struct sif_SR_DmnInfoProvided
{
    SysReturnType (*ReadSDmnStatus)(SDmnStatus * const); // Read operation for SDmnStatus
    SysReturnType (*WriteSDmnStatus)(SDmnStatus const); // Write operation for SDmnStatus
} tif_SR_DmnInfoProvided;
#endif // #if (defined(if_SR_DmnInfo_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_SR_DmnInfo_USAGE_VISIBILITY))
typedef const struct sif_SR_DmnInfoRequired
{
    SysReturnType (*ReadSDmnStatus)(SDmnStatus * const); // Read operation for SDmnStatus
} tif_SR_DmnInfoRequired;
#endif // #if (defined(if_SR_DmnInfo_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(if_SR_DmnInfo_PROVIDE_VISIBILITY))
#define mif_SR_DmnInfoProvided_Allocate(instanceName, itsif_SR_DmnInfo_FCTTBL) \
    tif_SR_DmnInfoProvided instanceName = itsif_SR_DmnInfo_FCTTBL;
#endif // #if (defined(if_SR_DmnInfo_PROVIDE_VISIBILITY))

#if (defined(if_SR_DmnInfo_USAGE_VISIBILITY))
#define mif_SR_DmnInfoRequired_Allocate(instanceName, itsif_SR_DmnInfo_FCTTBL) \
    tif_SR_DmnInfoRequired instanceName = itsif_SR_DmnInfo_FCTTBL;
#endif // #if (defined(if_SR_DmnInfo_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_SR_DmnInfo_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_CORE/DmnMgr/if_SR_DmnInfo/<AutoCreatedOperation>WriteSDmnStatus
// Method      :        if_SR_DmnInfo_WriteSDmnStatus(tif_SR_DmnInfo_Ref const This, SDmnStatus const SDmnStatus)
// Visibility  :        public
// Description :        Write operation for SDmnStatus
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_DmnInfo_Ref  | This(In)        | Class reference
// SDmnStatus          | SDmnStatus(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_DmnInfo_WriteSDmnStatus(Ref, SDmnStatus) \
    (SysReturnType)(Ref)->WriteSDmnStatus(SDmnStatus)

#endif // #if (defined(if_SR_DmnInfo_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                            Part for the TI provider & user
// ---------------------------------------------------------------------------------------------------------------------

#if ((defined(if_SR_DmnInfo_PROVIDE_VISIBILITY)) || (defined(if_SR_DmnInfo_USAGE_VISIBILITY)))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_CORE/DmnMgr/if_SR_DmnInfo/<AutoCreatedOperation>ReadSDmnStatus
// Method      :        if_SR_DmnInfo_ReadSDmnStatus(tif_SR_DmnInfo_Ref const This, SDmnStatus * const pSDmnStatus)
// Visibility  :        public
// Description :        Read operation for SDmnStatus
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         |  Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_DmnInfo_Ref  | This(In)          | Class reference
// SDmnStatus          | pSDmnStatus(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_DmnInfo_ReadSDmnStatus(Ref, pSDmnStatus) \
    (SysReturnType)(Ref)->ReadSDmnStatus(pSDmnStatus)

#endif // #if ((defined(if_SR_DmnInfo_PROVIDE_VISIBILITY)) || (defined(if_SR_DmnInfo_USAGE_VISIBILITY)))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __if_SR_DmnInfo_G_h__
