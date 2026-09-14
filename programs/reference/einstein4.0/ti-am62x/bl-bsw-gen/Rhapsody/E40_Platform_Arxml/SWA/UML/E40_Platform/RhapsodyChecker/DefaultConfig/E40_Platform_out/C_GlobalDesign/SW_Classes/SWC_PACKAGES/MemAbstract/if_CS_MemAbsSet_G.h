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
// Generated on Fri Mar 22 16:34:47 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              if_CS_MemAbsSet (TransportedInterface)
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

#if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))
typedef const struct sif_CS_MemAbsSetRequired
{
    SysReturnType (*Call_Set_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL)(boolean const); // Initiate call of Set_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL
    SysReturnType (*Call_Set_NVM_Diag_config_var_5_padding_U8A)(Nvm_U8ArrType_3 * const); // Initiate call of Set_NVM_Diag_config_var_5_padding_U8A
    SysReturnType (*Call_Set_NVM_DG_16_vehicle_type_U8)(uint8 const); // Initiate call of Set_NVM_DG_16_vehicle_type_U8
    SysReturnType (*Call_Set_NVM_Diag_config_var_16_padding_U8A)(Nvm_U8ArrType_3 * const); // Initiate call of Set_NVM_Diag_config_var_16_padding_U8A
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
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL
// Method      :        if_CS_MemAbsSet_CallSet_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(tif_CS_MemAbsSet_Ref const This, boolean const NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL)
// Visibility  :        public
// Description :        Initiate call of Set_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                               | Class reference
// boolean               | NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(Ref, NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL) \
    (SysReturnType)(Ref)->Call_Set_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_NVM_Diag_config_var_5_padding_U8A
// Method      :        if_CS_MemAbsSet_CallSet_NVM_Diag_config_var_5_padding_U8A(tif_CS_MemAbsSet_Ref const This, Nvm_U8ArrType_3 * const NVM_Diag_config_var_5_padding_U8A)
// Visibility  :        public
// Description :        Initiate call of Set_NVM_Diag_config_var_5_padding_U8A
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                               | Class reference
// Nvm_U8ArrType_3       | NVM_Diag_config_var_5_padding_U8A(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_NVM_Diag_config_var_5_padding_U8A(Ref, NVM_Diag_config_var_5_padding_U8A) \
    (SysReturnType)(Ref)->Call_Set_NVM_Diag_config_var_5_padding_U8A(NVM_Diag_config_var_5_padding_U8A)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_NVM_DG_16_vehicle_type_U8
// Method      :        if_CS_MemAbsSet_CallSet_NVM_DG_16_vehicle_type_U8(tif_CS_MemAbsSet_Ref const This, uint8 const NVM_DG_16_vehicle_type_U8)
// Visibility  :        public
// Description :        Initiate call of Set_NVM_DG_16_vehicle_type_U8
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |        Name(Direction)         |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                       | Class reference
// uint8                 | NVM_DG_16_vehicle_type_U8(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_NVM_DG_16_vehicle_type_U8(Ref, NVM_DG_16_vehicle_type_U8) \
    (SysReturnType)(Ref)->Call_Set_NVM_DG_16_vehicle_type_U8(NVM_DG_16_vehicle_type_U8)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstract/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_NVM_Diag_config_var_16_padding_U8A
// Method      :        if_CS_MemAbsSet_CallSet_NVM_Diag_config_var_16_padding_U8A(tif_CS_MemAbsSet_Ref const This, Nvm_U8ArrType_3 * const NVM_Diag_config_var_16_padding_U8A)
// Visibility  :        public
// Description :        Initiate call of Set_NVM_Diag_config_var_16_padding_U8A
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                                | Class reference
// Nvm_U8ArrType_3       | NVM_Diag_config_var_16_padding_U8A(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_NVM_Diag_config_var_16_padding_U8A(Ref, NVM_Diag_config_var_16_padding_U8A) \
    (SysReturnType)(Ref)->Call_Set_NVM_Diag_config_var_16_padding_U8A(NVM_Diag_config_var_16_padding_U8A)

#endif // #if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __if_CS_MemAbsSet_G_h__
