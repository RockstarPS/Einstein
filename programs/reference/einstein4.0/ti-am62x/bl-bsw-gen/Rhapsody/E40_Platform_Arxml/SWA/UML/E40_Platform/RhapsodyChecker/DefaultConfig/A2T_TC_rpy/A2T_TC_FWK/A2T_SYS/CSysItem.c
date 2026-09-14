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
// Generated on Tue Aug 06 13:07:41 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              CSysItem (Class)
// Description:         Base class for all A2tom objects. Should have a default empty implementation of DeInit.
// Owner:               A2T_SYS (Package)
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
#define CSysItem_PRIVATE_VISIBILITY
#define CSysItem_PROTECTED_VISIBILITY

// ---------------------------------------------------------------------------------------------------------------------
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "A2T_SYS_G.h"

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual methods sub-section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/CSysItem/<Operation>DeInit
// Method      :        CSysItem_DeInit_Implementation(tCSysItem_Ref const This)
// Visibility  :        public, virtual
// Description :        De-initialization. Should act like a "destructor". I.e. the method can initialize memory,
//                      release System/OS resources, but should not call objects in other Allocatables.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//      Type      | Name(Direction) |                                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysItem_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void CSysItem_DeInit_Implementation(tCSysItem_Ref const This)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_1("CSysItem", "DeInit", This)
    {
    // The tag located on the next line should not be removed. It protects your code!
    //#[ DeInit ->|
        // TODO: Real method implementation should be placed here!
    //#] DeInit ->|
    // The tag located on the previous line should not be removed. It protects your code!
    }
    mLEAVE_METHOD("CSysItem", "DeInit")
}

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
