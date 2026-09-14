#ifndef __if_SR_JobStatus_G_h__
#define __if_SR_JobStatus_G_h__
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
// Entity:              if_SR_JobStatus (TransportedInterface)
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
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))
typedef const struct sif_SR_JobStatusProvided
{
    SysReturnType (*ReadJobStatus_SampleElement1)(uint8 * const); // Read operation for JobStatus_SampleElement1
    SysReturnType (*WriteJobStatus_SampleElement1)(uint8 const); // Write operation for JobStatus_SampleElement1
    SysReturnType (*ReadJobStatus_SampleElement2)(uint8 * const); // Read operation for JobStatus_SampleElement2
    SysReturnType (*WriteJobStatus_SampleElement2)(uint8 const); // Write operation for JobStatus_SampleElement2
} tif_SR_JobStatusProvided;
#endif // #if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_SR_JobStatus_USAGE_VISIBILITY))
typedef const struct sif_SR_JobStatusRequired
{
    SysReturnType (*ReadJobStatus_SampleElement1)(uint8 * const); // Read operation for JobStatus_SampleElement1
    SysReturnType (*ReadJobStatus_SampleElement2)(uint8 * const); // Read operation for JobStatus_SampleElement2
} tif_SR_JobStatusRequired;
#endif // #if (defined(if_SR_JobStatus_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))
#define mif_SR_JobStatusProvided_Allocate(instanceName, itsif_SR_JobStatus_FCTTBL) \
    tif_SR_JobStatusProvided instanceName = itsif_SR_JobStatus_FCTTBL;
#endif // #if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))

#if (defined(if_SR_JobStatus_USAGE_VISIBILITY))
#define mif_SR_JobStatusRequired_Allocate(instanceName, itsif_SR_JobStatus_FCTTBL) \
    tif_SR_JobStatusRequired instanceName = itsif_SR_JobStatus_FCTTBL;
#endif // #if (defined(if_SR_JobStatus_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_MemAbstract/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_SampleElement1
// Method      :        if_SR_JobStatus_WriteJobStatus_SampleElement1(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_SampleElement1)
// Visibility  :        public
// Description :        Write operation for JobStatus_SampleElement1
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |        Name(Direction)        |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                      | Class reference
// uint8                 | JobStatus_SampleElement1(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_SampleElement1(Ref, JobStatus_SampleElement1) \
    (SysReturnType)(Ref)->WriteJobStatus_SampleElement1(JobStatus_SampleElement1)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_MemAbstract/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_SampleElement2
// Method      :        if_SR_JobStatus_WriteJobStatus_SampleElement2(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_SampleElement2)
// Visibility  :        public
// Description :        Write operation for JobStatus_SampleElement2
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |        Name(Direction)        |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                      | Class reference
// uint8                 | JobStatus_SampleElement2(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_SampleElement2(Ref, JobStatus_SampleElement2) \
    (SysReturnType)(Ref)->WriteJobStatus_SampleElement2(JobStatus_SampleElement2)

#endif // #if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                            Part for the TI provider & user
// ---------------------------------------------------------------------------------------------------------------------

#if ((defined(if_SR_JobStatus_PROVIDE_VISIBILITY)) || (defined(if_SR_JobStatus_USAGE_VISIBILITY)))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_MemAbstract/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_SampleElement1
// Method      :        if_SR_JobStatus_ReadJobStatus_SampleElement1(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_SampleElement1)
// Visibility  :        public
// Description :        Read operation for JobStatus_SampleElement1
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |         Name(Direction)         |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                        | Class reference
// uint8                 | pJobStatus_SampleElement1(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_SampleElement1(Ref, pJobStatus_SampleElement1) \
    (SysReturnType)(Ref)->ReadJobStatus_SampleElement1(pJobStatus_SampleElement1)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_MemAbstract/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_SampleElement2
// Method      :        if_SR_JobStatus_ReadJobStatus_SampleElement2(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_SampleElement2)
// Visibility  :        public
// Description :        Read operation for JobStatus_SampleElement2
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |         Name(Direction)         |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                        | Class reference
// uint8                 | pJobStatus_SampleElement2(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_SampleElement2(Ref, pJobStatus_SampleElement2) \
    (SysReturnType)(Ref)->ReadJobStatus_SampleElement2(pJobStatus_SampleElement2)

#endif // #if ((defined(if_SR_JobStatus_PROVIDE_VISIBILITY)) || (defined(if_SR_JobStatus_USAGE_VISIBILITY)))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __if_SR_JobStatus_G_h__
