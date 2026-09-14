#ifndef __CObcExclusiveArea_G_h__
#define __CObcExclusiveArea_G_h__
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
// Generated on Tue Aug 06 13:07:42 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              CObcExclusiveArea (Class)
// Description:         Unique class describing the exclusive area. Defines the interface for the exclusive area
//                      managed by the RTE. User classes have to setup their relationsships with this class.
// Owner:               Osal (Package)
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
//                                      Inherited classes reference transformation
// ---------------------------------------------------------------------------------------------------------------------
#define CObcExclusiveArea_TO_CSysExclusiveArea(Ref)    ((tCSysExclusiveArea_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CObcExclusiveArea_TO_CSysExclusiveArea",310
#endif // #ifdef _QAC_

#if (defined(CObcExclusiveArea_PROTECTED_VISIBILITY))
#define CSysExclusiveArea_TO_CObcExclusiveArea(Ref)    ((tCObcExclusiveArea_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CSysExclusiveArea_TO_CObcExclusiveArea",310
#endif // #ifdef _QAC_

#endif // #if (defined(CObcExclusiveArea_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           General access to the class data
// ---------------------------------------------------------------------------------------------------------------------
#define CObcExclusiveArea_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(CObcExclusiveArea_PROTECTED_VISIBILITY))
#define CObcExclusiveArea_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define CObcExclusiveArea_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(CObcExclusiveArea_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCObcExclusiveArea_VTBL
{
    void (*EnterExclusiveArea)(tCSysExclusiveArea_Ref const); // Defined by the Class "CSysExclusiveArea" as abstract and virtual
    void (*ExitExclusiveArea)(tCSysExclusiveArea_Ref const); // Defined by the Class "CSysExclusiveArea" as abstract and virtual
    void (*Enter)(tCObcExclusiveArea_Ref const); // Defined by the Class "CObcExclusiveArea" as virtual
    void (*Exit)(tCObcExclusiveArea_Ref const); // Defined by the Class "CObcExclusiveArea" as virtual
} tCObcExclusiveArea_VTBL;
typedef tCObcExclusiveArea_VTBL* tCObcExclusiveArea_VTBL_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCObcExclusiveArea
{
    tCObcExclusiveArea_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
} tCObcExclusiveArea;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class is abstract. It does not implement the following method(s):
//    CSysExclusiveArea_EnterExclusiveArea
//    CSysExclusiveArea_ExitExclusiveArea

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/CSysExclusiveArea/<Operation>EnterExclusiveArea
// Method      :        CSysExclusiveArea_EnterExclusiveArea(tCSysExclusiveArea_Ref const parentRef)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type           | Name(Direction) |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysExclusiveArea_Ref  | parentRef(In)   | Parent class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CObcExclusiveArea_EnterExclusiveArea(Ref) \
        CSysExclusiveArea_EnterExclusiveArea(CObcExclusiveArea_TO_CSysExclusiveArea(Ref))

// CObcExclusiveArea_EnterExclusiveArea_Explicit is not generated here, because the corresponding method is abstract.
// By definition abstract methods do not provide implementation, so the explicit call is not needed and not generated.

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CObcExclusiveArea_EnterExclusiveArea",310
#pragma PRQA_MACRO_MESSAGES_OFF "CObcExclusiveArea_EnterExclusiveArea",311
#endif // #ifdef _QAC_

#if (defined(CObcExclusiveArea_PRIVATE_VISIBILITY))
#define mEnterExclusiveArea() \
        CObcExclusiveArea_EnterExclusiveArea(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mEnterExclusiveArea",310
#pragma PRQA_MACRO_MESSAGES_OFF "mEnterExclusiveArea",311
#endif // #ifdef _QAC_
#endif // #if (defined(CObcExclusiveArea_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/CSysExclusiveArea/<Operation>ExitExclusiveArea
// Method      :        CSysExclusiveArea_ExitExclusiveArea(tCSysExclusiveArea_Ref const parentRef)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type           | Name(Direction) |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysExclusiveArea_Ref  | parentRef(In)   | Parent class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CObcExclusiveArea_ExitExclusiveArea(Ref) \
        CSysExclusiveArea_ExitExclusiveArea(CObcExclusiveArea_TO_CSysExclusiveArea(Ref))

// CObcExclusiveArea_ExitExclusiveArea_Explicit is not generated here, because the corresponding method is abstract.
// By definition abstract methods do not provide implementation, so the explicit call is not needed and not generated.

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CObcExclusiveArea_ExitExclusiveArea",310
#pragma PRQA_MACRO_MESSAGES_OFF "CObcExclusiveArea_ExitExclusiveArea",311
#endif // #ifdef _QAC_

#if (defined(CObcExclusiveArea_PRIVATE_VISIBILITY))
#define mExitExclusiveArea() \
        CObcExclusiveArea_ExitExclusiveArea(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mExitExclusiveArea",310
#pragma PRQA_MACRO_MESSAGES_OFF "mExitExclusiveArea",311
#endif // #ifdef _QAC_
#endif // #if (defined(CObcExclusiveArea_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK_OBCINSTANCER/A2T_OBC/Osal/CObcExclusiveArea/<Operation>Enter
// Method      :        CObcExclusiveArea_Enter_Implementation(tCObcExclusiveArea_Ref const This)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type           | Name(Direction) |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tCObcExclusiveArea_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CObcExclusiveArea_Enter_Implementation(tCObcExclusiveArea_Ref const This);
// =====================================================================================================================
#define CObcExclusiveArea_Enter(Ref) \
        CObcExclusiveArea_VTBL_Access(Ref)->Enter(Ref)

#define CObcExclusiveArea_Enter_Explicit(Ref) \
        CObcExclusiveArea_Enter_Implementation(Ref)

#if (defined(CObcExclusiveArea_PRIVATE_VISIBILITY))
#define mEnter() \
        CObcExclusiveArea_Enter(This)

#define mEnter_Explicit() \
        CObcExclusiveArea_Enter_Explicit(This)
#endif // #if (defined(CObcExclusiveArea_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK_OBCINSTANCER/A2T_OBC/Osal/CObcExclusiveArea/<Operation>Exit
// Method      :        CObcExclusiveArea_Exit_Implementation(tCObcExclusiveArea_Ref const This)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type           | Name(Direction) |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tCObcExclusiveArea_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CObcExclusiveArea_Exit_Implementation(tCObcExclusiveArea_Ref const This);
// =====================================================================================================================
#define CObcExclusiveArea_Exit(Ref) \
        CObcExclusiveArea_VTBL_Access(Ref)->Exit(Ref)

#define CObcExclusiveArea_Exit_Explicit(Ref) \
        CObcExclusiveArea_Exit_Implementation(Ref)

#if (defined(CObcExclusiveArea_PRIVATE_VISIBILITY))
#define mExit() \
        CObcExclusiveArea_Exit(This)

#define mExit_Explicit() \
        CObcExclusiveArea_Exit_Explicit(This)
#endif // #if (defined(CObcExclusiveArea_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __CObcExclusiveArea_G_h__
