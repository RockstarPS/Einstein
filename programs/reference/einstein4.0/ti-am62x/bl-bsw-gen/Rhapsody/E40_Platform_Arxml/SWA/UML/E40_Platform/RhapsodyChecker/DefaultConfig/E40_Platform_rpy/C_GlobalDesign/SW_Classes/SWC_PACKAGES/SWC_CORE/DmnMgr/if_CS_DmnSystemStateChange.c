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
// This file is partially generated, user code reside between tags.
// Tag for the start of the user section is : // #[ <method name> ->|
// Tag for the end of the user section is   : // #] <method name> ->|
// WARNING: Any changes out of these sections will be overwritten by the generator
// ---------------------------------------------------------------------------------------------------------------------
// Generated on Tue Aug 06 13:07:35 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
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
//                                                 Disabled QAC warnings
// ---------------------------------------------------------------------------------------------------------------------
#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:3220)
#pragma PRQA_MESSAGES_OFF 3220
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:3673)
#pragma PRQA_MESSAGES_OFF 3673
#endif // #ifdef _QAC_

// ---------------------------------------------------------------------------------------------------------------------
//                                           Auto generated visibility defines
// ---------------------------------------------------------------------------------------------------------------------
#define if_CS_DmnSystemStateChange_PRIVATE_VISIBILITY
#define if_CS_DmnSystemStateChange_PROTECTED_VISIBILITY

// ---------------------------------------------------------------------------------------------------------------------
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "DmnMgr_G.h"

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                Public methods section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_CORE/DmnMgr/if_CS_DmnSystemStateChange/<Operation>DmnSystemStateChangeReq
// Method      :        if_CS_DmnSystemStateChange_DmnSystemStateChangeReq(tif_CS_DmnSystemStateChange_Ref const This, EDomainId const DmnId, ESystemState const DmnState)
// Visibility  :        public
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//               Type               | Name(Direction) |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_DmnSystemStateChange_Ref  | This(In)        | Class reference
// EDomainId                        | DmnId(In)       | None
// ESystemState                     | DmnState(In)    | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        Std_ReturnType
// =====================================================================================================================
Std_ReturnType if_CS_DmnSystemStateChange_DmnSystemStateChangeReq(tif_CS_DmnSystemStateChange_Ref const This, EDomainId const DmnId, ESystemState const DmnState)
{
    Std_ReturnType returnValue = E_NOT_OK;

    mCGAssert(NULL != This);
    mENTER_METHOD_3("if_CS_DmnSystemStateChange", "DmnSystemStateChangeReq", This, DmnId, DmnState)
    {
    // The tag located on the next line should not be removed. It protects your code!
    //#[ DmnSystemStateChangeReq ->|
        // TODO: Real method implementation should be placed here!
    //#] DmnSystemStateChangeReq ->|
    // The tag located on the previous line should not be removed. It protects your code!
    }
    mLEAVE_METHOD("if_CS_DmnSystemStateChange", "DmnSystemStateChangeReq")
    return (returnValue);
}

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/SWC_CORE/DmnMgr/if_CS_DmnSystemStateChange/<Operation>DmnSystemStateChangeStatus
// Method      :        if_CS_DmnSystemStateChange_DmnSystemStateChangeStatus(tif_CS_DmnSystemStateChange_Ref const This, EDomainId const DmnId, EDmnChangeReqStatus_t * const pDmnStatus)
// Visibility  :        public
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//               Type               | Name(Direction)  |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_DmnSystemStateChange_Ref  | This(In)         | Class reference
// EDomainId                        | DmnId(In)        | None
// EDmnChangeReqStatus_t            | pDmnStatus(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void if_CS_DmnSystemStateChange_DmnSystemStateChangeStatus(tif_CS_DmnSystemStateChange_Ref const This, EDomainId const DmnId, EDmnChangeReqStatus_t * const pDmnStatus)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_3("if_CS_DmnSystemStateChange", "DmnSystemStateChangeStatus", This, DmnId, pDmnStatus)
    {
    // The tag located on the next line should not be removed. It protects your code!
    //#[ DmnSystemStateChangeStatus ->|
        // TODO: Real method implementation should be placed here!
    //#] DmnSystemStateChangeStatus ->|
    // The tag located on the previous line should not be removed. It protects your code!
    }
    mLEAVE_METHOD("if_CS_DmnSystemStateChange", "DmnSystemStateChangeStatus")
}

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
