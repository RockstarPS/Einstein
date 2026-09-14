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
// Generated on Fri Mar 22 16:34:47 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              if_SR_JobStatus (TransportedInterface)
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
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))
typedef const struct sif_SR_JobStatusProvided
{
    SysReturnType (*ReadJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL)(uint8 * const); // Read operation for JobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL
    SysReturnType (*WriteJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL)(uint8 const); // Write operation for JobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL
    SysReturnType (*ReadJobStatus_NVM_Diag_config_var_5_padding_U8A)(uint8 * const); // Read operation for JobStatus_NVM_Diag_config_var_5_padding_U8A
    SysReturnType (*WriteJobStatus_NVM_Diag_config_var_5_padding_U8A)(uint8 const); // Write operation for JobStatus_NVM_Diag_config_var_5_padding_U8A
    SysReturnType (*ReadJobStatus_NVM_DG_16_vehicle_type_U8)(uint8 * const); // Read operation for JobStatus_NVM_DG_16_vehicle_type_U8
    SysReturnType (*WriteJobStatus_NVM_DG_16_vehicle_type_U8)(uint8 const); // Write operation for JobStatus_NVM_DG_16_vehicle_type_U8
    SysReturnType (*ReadJobStatus_NVM_Diag_config_var_16_padding_U8A)(uint8 * const); // Read operation for JobStatus_NVM_Diag_config_var_16_padding_U8A
    SysReturnType (*WriteJobStatus_NVM_Diag_config_var_16_padding_U8A)(uint8 const); // Write operation for JobStatus_NVM_Diag_config_var_16_padding_U8A
} tif_SR_JobStatusProvided;
#endif // #if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_SR_JobStatus_USAGE_VISIBILITY))
typedef const struct sif_SR_JobStatusRequired
{
    SysReturnType (*ReadJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL)(uint8 * const); // Read operation for JobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL
    SysReturnType (*ReadJobStatus_NVM_Diag_config_var_5_padding_U8A)(uint8 * const); // Read operation for JobStatus_NVM_Diag_config_var_5_padding_U8A
    SysReturnType (*ReadJobStatus_NVM_DG_16_vehicle_type_U8)(uint8 * const); // Read operation for JobStatus_NVM_DG_16_vehicle_type_U8
    SysReturnType (*ReadJobStatus_NVM_Diag_config_var_16_padding_U8A)(uint8 * const); // Read operation for JobStatus_NVM_Diag_config_var_16_padding_U8A
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
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL
// Method      :        if_SR_JobStatus_WriteJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL)
// Visibility  :        public
// Description :        Write operation for JobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                 Name(Direction)                  |                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                         | Class reference
// uint8                 | JobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(Ref, JobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL) \
    (SysReturnType)(Ref)->WriteJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(JobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_NVM_Diag_config_var_5_padding_U8A
// Method      :        if_SR_JobStatus_WriteJobStatus_NVM_Diag_config_var_5_padding_U8A(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_NVM_Diag_config_var_5_padding_U8A)
// Visibility  :        public
// Description :        Write operation for JobStatus_NVM_Diag_config_var_5_padding_U8A
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                 Name(Direction)                  |                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                         | Class reference
// uint8                 | JobStatus_NVM_Diag_config_var_5_padding_U8A(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_NVM_Diag_config_var_5_padding_U8A(Ref, JobStatus_NVM_Diag_config_var_5_padding_U8A) \
    (SysReturnType)(Ref)->WriteJobStatus_NVM_Diag_config_var_5_padding_U8A(JobStatus_NVM_Diag_config_var_5_padding_U8A)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_NVM_DG_16_vehicle_type_U8
// Method      :        if_SR_JobStatus_WriteJobStatus_NVM_DG_16_vehicle_type_U8(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_NVM_DG_16_vehicle_type_U8)
// Visibility  :        public
// Description :        Write operation for JobStatus_NVM_DG_16_vehicle_type_U8
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                 | Class reference
// uint8                 | JobStatus_NVM_DG_16_vehicle_type_U8(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_NVM_DG_16_vehicle_type_U8(Ref, JobStatus_NVM_DG_16_vehicle_type_U8) \
    (SysReturnType)(Ref)->WriteJobStatus_NVM_DG_16_vehicle_type_U8(JobStatus_NVM_DG_16_vehicle_type_U8)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_NVM_Diag_config_var_16_padding_U8A
// Method      :        if_SR_JobStatus_WriteJobStatus_NVM_Diag_config_var_16_padding_U8A(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_NVM_Diag_config_var_16_padding_U8A)
// Visibility  :        public
// Description :        Write operation for JobStatus_NVM_Diag_config_var_16_padding_U8A
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                  Name(Direction)                  |                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                          | Class reference
// uint8                 | JobStatus_NVM_Diag_config_var_16_padding_U8A(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_NVM_Diag_config_var_16_padding_U8A(Ref, JobStatus_NVM_Diag_config_var_16_padding_U8A) \
    (SysReturnType)(Ref)->WriteJobStatus_NVM_Diag_config_var_16_padding_U8A(JobStatus_NVM_Diag_config_var_16_padding_U8A)

#endif // #if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                            Part for the TI provider & user
// ---------------------------------------------------------------------------------------------------------------------

#if ((defined(if_SR_JobStatus_PROVIDE_VISIBILITY)) || (defined(if_SR_JobStatus_USAGE_VISIBILITY)))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL
// Method      :        if_SR_JobStatus_ReadJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL)
// Visibility  :        public
// Description :        Read operation for JobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                  Name(Direction)                   |                Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                           | Class reference
// uint8                 | pJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(Ref, pJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL) \
    (SysReturnType)(Ref)->ReadJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(pJobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_NVM_Diag_config_var_5_padding_U8A
// Method      :        if_SR_JobStatus_ReadJobStatus_NVM_Diag_config_var_5_padding_U8A(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_NVM_Diag_config_var_5_padding_U8A)
// Visibility  :        public
// Description :        Read operation for JobStatus_NVM_Diag_config_var_5_padding_U8A
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                  Name(Direction)                   |                Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                           | Class reference
// uint8                 | pJobStatus_NVM_Diag_config_var_5_padding_U8A(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_NVM_Diag_config_var_5_padding_U8A(Ref, pJobStatus_NVM_Diag_config_var_5_padding_U8A) \
    (SysReturnType)(Ref)->ReadJobStatus_NVM_Diag_config_var_5_padding_U8A(pJobStatus_NVM_Diag_config_var_5_padding_U8A)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_NVM_DG_16_vehicle_type_U8
// Method      :        if_SR_JobStatus_ReadJobStatus_NVM_DG_16_vehicle_type_U8(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_NVM_DG_16_vehicle_type_U8)
// Visibility  :        public
// Description :        Read operation for JobStatus_NVM_DG_16_vehicle_type_U8
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                   | Class reference
// uint8                 | pJobStatus_NVM_DG_16_vehicle_type_U8(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_NVM_DG_16_vehicle_type_U8(Ref, pJobStatus_NVM_DG_16_vehicle_type_U8) \
    (SysReturnType)(Ref)->ReadJobStatus_NVM_DG_16_vehicle_type_U8(pJobStatus_NVM_DG_16_vehicle_type_U8)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_NVM_Diag_config_var_16_padding_U8A
// Method      :        if_SR_JobStatus_ReadJobStatus_NVM_Diag_config_var_16_padding_U8A(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_NVM_Diag_config_var_16_padding_U8A)
// Visibility  :        public
// Description :        Read operation for JobStatus_NVM_Diag_config_var_16_padding_U8A
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                   Name(Direction)                   |                Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                            | Class reference
// uint8                 | pJobStatus_NVM_Diag_config_var_16_padding_U8A(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_NVM_Diag_config_var_16_padding_U8A(Ref, pJobStatus_NVM_Diag_config_var_16_padding_U8A) \
    (SysReturnType)(Ref)->ReadJobStatus_NVM_Diag_config_var_16_padding_U8A(pJobStatus_NVM_Diag_config_var_16_padding_U8A)

#endif // #if ((defined(if_SR_JobStatus_PROVIDE_VISIBILITY)) || (defined(if_SR_JobStatus_USAGE_VISIBILITY)))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __if_SR_JobStatus_G_h__
