#ifndef __CTstRootCampain_G_h__
#define __CTstRootCampain_G_h__
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
// Generated on Tue Aug 06 13:07:39 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              CTstRootCampain (Class)
// Description:         None
// Owner:               A2T_TST (Package)
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
#define CTstRootCampain_TO_CTstContext(Ref)    ((tCTstContext_Ref)(Ref))
#define CTstRootCampain_TO_CTstCampain(Ref)    ((tCTstCampain_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_TO_CTstContext",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_TO_CTstCampain",310
#endif // #ifdef _QAC_

#if (defined(CTstRootCampain_PROTECTED_VISIBILITY))
#define CTstContext_TO_CTstRootCampain(Ref)    ((tCTstRootCampain_Ref)(Ref))
#define CTstCampain_TO_CTstRootCampain(Ref)    ((tCTstRootCampain_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstContext_TO_CTstRootCampain",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstCampain_TO_CTstRootCampain",310
#endif // #ifdef _QAC_

#endif // #if (defined(CTstRootCampain_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           General access to the class data
// ---------------------------------------------------------------------------------------------------------------------
#define CTstRootCampain_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(CTstRootCampain_PROTECTED_VISIBILITY))
#define CTstRootCampain_RAM_Access(classRef,attribute) ((classRef)->pRAM->attribute)
#define CTstRootCampain_RAM_AccessTbl(classRef,idx,attribute) ((classRef)->pRAM->attribute[idx])
#define CTstRootCampain_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define CTstRootCampain_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(CTstRootCampain_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCTstRootCampain_VTBL
{
    void (*RunTests)(tCTstContext_Ref const, tCTstReporter_Ref const); // Defined by the Class "CTstContext" as virtual
    char* (*GetContextClassDescription)(tCTstContext_Ref const); // Defined by the Class "CTstContext" as abstract and virtual
    void (*Init)(tCTstContext_Ref const); // Defined by the Class "CTstContext" as virtual
    void (*TestAll)(tCTstContext_Ref const); // Defined by the Class "CTstContext" as abstract and virtual
} tCTstRootCampain_VTBL;
typedef tCTstRootCampain_VTBL* tCTstRootCampain_VTBL_Ref;

extern tCTstRootCampain_VTBL CTstRootCampain_VTBL;

// ---------------------------------------------------------------------------------------------------------------------
//                             RAM structure (Non-constant attributes are allocated in RAM)
// ---------------------------------------------------------------------------------------------------------------------
typedef struct sCTstRootCampain_RAM
{
// Attributes from the class "CTstContext"
// Pointer to manage the relation Result(association, multiplicity[0,1])
    tCTstReporter_Ref pResult; // protected
} tCTstRootCampain_RAM;
typedef tCTstRootCampain_RAM * tCTstRootCampain_RAM_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCTstRootCampain
{
    tCTstRootCampain_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
    tCTstRootCampain_RAM_Ref pRAM; // Auto-generated pointer to RAM structure
// Attributes from the class "CTstContext"
    char* Description; // public
// Attributes from the class "CTstCampain"
// Cardinality of the relation ContextList(association, multiplicity[1..*])
    t_MAX_CARD ContextList_MAX_CARD; // Auto-generated <MaxCard>
// Pointer to manage the relation ContextList(association, multiplicity[1..*])
    tCTstContext_Ref * pContextListTable; // Auto-generated <Relation Table>
// Attributes from the class "CTstRootCampain"
// Pointer to manage the relation Reporter(composition, multiplicity[1])
    tCTstReporter_Ref pReporter; // protected
} tCTstRootCampain;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================

// Standard allocator mCTstRootCampain_Allocate
// ---------------------------------------------------------------------------------------------------------------------
//                                                      Help macro
// ---------------------------------------------------------------------------------------------------------------------
#define mCTstRootCampain_RAM_Structure(instanceName) instanceName##_RAM
#define mCTstRootCampain_ContextListTableInstance(instanceName,ContextList_MAX_CARD) \
    const tCTstContext_Ref CTstCampain_pContextListTable##instanceName[ContextList_MAX_CARD]

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mCTstRootCampain_Allocate(instanceName, Description, ContextList_MAX_CARD, pContextListTable, pReporter) \
                                                                                                                        \
mCTstRootCampain_ContextListTableInstance(instanceName,ContextList_MAX_CARD) = pContextListTable; \
static tCTstRootCampain_RAM mCTstRootCampain_RAM_Structure(instanceName); \
tCTstRootCampain instanceName = {\
    &CTstRootCampain_VTBL, \
    &mCTstRootCampain_RAM_Structure(instanceName), \
    Description, \
    ContextList_MAX_CARD, \
    (tCTstContext_Ref *)CTstCampain_pContextListTable##instanceName, \
    pReporter \
}
// ---------------------------------------------------------------------------------------------------------------------

// Explicit allocator mCTstRootCampain_Allocate_Explicit

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mCTstRootCampain_Allocate_Explicit(instanceName, Description, ContextList_MAX_CARD, pContextListTable, pReporter) \
                                                                                                                        \
static tCTstRootCampain_RAM mCTstRootCampain_RAM_Structure(instanceName); \
tCTstRootCampain instanceName = {\
    &CTstRootCampain_VTBL, \
    &mCTstRootCampain_RAM_Structure(instanceName), \
    Description, \
    ContextList_MAX_CARD, \
    (tCTstContext_Ref *)pContextListTable, \
    pReporter \
}
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
//                                              Attribute accessors section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                             Attributes with public access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                    Read functions for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstContext/<AutoCreatedOperation>GetDescription
// Method      :        CTstContext_GetDescription(tCTstContext_Ref const This)
// Visibility  :        public
// Description :        Read value from Description (Multiplicity [1])
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type        | Name(Direction) |                                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstContext_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        char*
// =====================================================================================================================
#define CTstRootCampain_GetDescription(Ref) \
        CTstContext_GetDescription(CTstRootCampain_TO_CTstContext(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_GetDescription",310
#endif // #ifdef _QAC_
#if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
#define mGetDescription() \
        CTstRootCampain_GetDescription(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetDescription",310
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(CTstRootCampain_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                      Read macro for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the inherited attribute "Description" (public) with reference argument
#define mGetXDescription(Ref) CTstContext_ROM_Access(Ref,Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetXDescription",310
#endif // #ifdef _QAC_

#endif // #if (defined(CTstRootCampain_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           Attributes with protected access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(CTstRootCampain_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                Read/Write macro for protected, non-constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read/Write value from/to the inherited attribute "pResult" (protected) with reference argument
#define mSetXpResult(Ref, Data) (CTstContext_RAM_Access(Ref,pResult) = (Data))
#define mGetXpResult(Ref) CTstContext_RAM_Access(Ref,pResult)
// Read/Write value from/to the inherited attribute "pResult" (protected) without reference argument
#define mSetpResult(Data) (CTstContext_RAM_Access(This,pResult) = (Data))
#define mGetpResult() CTstContext_RAM_Access(This,pResult)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mSetXpResult",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetXpResult",310
#pragma PRQA_MACRO_MESSAGES_OFF "mSetpResult",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetpResult",310
#endif // #ifdef _QAC_

// ---------------------------------------------------------------------------------------------------------------------
//                                     Read macro for protected, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the inherited attribute "ContextList_MAX_CARD" (protected) with reference argument
#define mGetXContextList_MAX_CARD(Ref) CTstCampain_ROM_Access(Ref,ContextList_MAX_CARD)
// Read value from the inherited attribute "ContextList_MAX_CARD" (protected) without reference argument
#define mGetContextList_MAX_CARD() CTstCampain_ROM_Access(This,ContextList_MAX_CARD)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetXContextList_MAX_CARD",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetContextList_MAX_CARD",310
#endif // #ifdef _QAC_

// Read value from the inherited attribute "pContextListTable" (protected) with reference argument
#define mGetXpContextListTable(Ref) CTstCampain_ROM_Access(Ref,pContextListTable)
// Read value from the inherited attribute "pContextListTable" (protected) without reference argument
#define mGetpContextListTable() CTstCampain_ROM_Access(This,pContextListTable)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetXpContextListTable",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetpContextListTable",310
#endif // #ifdef _QAC_

// Read value from the attribute "pReporter" (protected) with reference argument
#define mGetXpReporter(Ref) CTstRootCampain_ROM_Access(Ref,pReporter)
// Read value from the attribute "pReporter" (protected) without reference argument
#define mGetpReporter() CTstRootCampain_ROM_Access(This,pReporter)

#endif // #if (defined(CTstRootCampain_PRIVATE_VISIBILITY))

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                   Inherited methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstContext/<Operation>TEST_CASE
// Method      :        CTstContext_TEST_CASE(tCTstContext_Ref const This, char* const Description)
// Visibility  :        protected
// Description :        OBSOLET METHOD, USE AddTestCase
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type        | Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstContext_Ref  | This(In)         | Class reference
// char*             | Description(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstRootCampain_TEST_CASE(Ref, Description) \
        CTstContext_TEST_CASE(CTstRootCampain_TO_CTstContext(Ref), Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_TEST_CASE",310
#endif // #ifdef _QAC_
#if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
#define mTEST_CASE(Description) \
        CTstRootCampain_TEST_CASE(This, Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mTEST_CASE",310
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstContext/<Operation>TEST_STEP
// Method      :        CTstContext_TEST_STEP(tCTstContext_Ref const This, char* const Description)
// Visibility  :        protected
// Description :        OBSOLET METHOD, USE AddTestStep
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type        | Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstContext_Ref  | This(In)         | Class reference
// char*             | Description(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstRootCampain_TEST_STEP(Ref, Description) \
        CTstContext_TEST_STEP(CTstRootCampain_TO_CTstContext(Ref), Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_TEST_STEP",310
#endif // #ifdef _QAC_
#if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
#define mTEST_STEP(Description) \
        CTstRootCampain_TEST_STEP(This, Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mTEST_STEP",310
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstContext/<Operation>AddTestCase
// Method      :        CTstContext_AddTestCase(tCTstContext_Ref const This, char* const Description)
// Visibility  :        protected
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type        | Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstContext_Ref  | This(In)         | Class reference
// char*             | Description(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstRootCampain_AddTestCase(Ref, Description) \
        CTstContext_AddTestCase(CTstRootCampain_TO_CTstContext(Ref), Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_AddTestCase",310
#endif // #ifdef _QAC_
#if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
#define mAddTestCase(Description) \
        CTstRootCampain_AddTestCase(This, Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mAddTestCase",310
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstContext/<Operation>AddTestStep
// Method      :        CTstContext_AddTestStep(tCTstContext_Ref const This, char* const Description)
// Visibility  :        protected
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type        | Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstContext_Ref  | This(In)         | Class reference
// char*             | Description(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstRootCampain_AddTestStep(Ref, Description) \
        CTstContext_AddTestStep(CTstRootCampain_TO_CTstContext(Ref), Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_AddTestStep",310
#endif // #ifdef _QAC_
#if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
#define mAddTestStep(Description) \
        CTstRootCampain_AddTestStep(This, Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mAddTestStep",310
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstCampain/<Operation>RunTests
// Method      :        CTstCampain_RunTests(tCTstCampain_Ref const parentRef, tCTstReporter_Ref const pResult)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstCampain_Ref   | parentRef(In)   | Parent class reference
// tCTstReporter_Ref  | pResult(In)     | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstRootCampain_RunTests(Ref, pResult) \
        CTstCampain_RunTests(CTstRootCampain_TO_CTstCampain(Ref), pResult)

#define CTstRootCampain_RunTests_Explicit(Ref, pResult) \
        CTstCampain_RunTests_Explicit(CTstRootCampain_TO_CTstCampain(Ref), pResult)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_RunTests",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_RunTests",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_RunTests_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_RunTests_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
#define mRunTests(pResult) \
        CTstRootCampain_RunTests(This, pResult)

#define mRunTests_Explicit(pResult) \
        CTstRootCampain_RunTests_Explicit(This, pResult)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mRunTests",310
#pragma PRQA_MACRO_MESSAGES_OFF "mRunTests",311
#pragma PRQA_MACRO_MESSAGES_OFF "mRunTests_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mRunTests_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstCampain/<Operation>GetContextClassDescription
// Method      :        CTstCampain_GetContextClassDescription(tCTstCampain_Ref const parentRef)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type        | Name(Direction) |                                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstCampain_Ref  | parentRef(In)   | Parent class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        char*
// =====================================================================================================================
#define CTstRootCampain_GetContextClassDescription(Ref) \
        CTstCampain_GetContextClassDescription(CTstRootCampain_TO_CTstCampain(Ref))

#define CTstRootCampain_GetContextClassDescription_Explicit(Ref) \
        CTstCampain_GetContextClassDescription_Explicit(CTstRootCampain_TO_CTstCampain(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_GetContextClassDescription",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_GetContextClassDescription",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_GetContextClassDescription_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_GetContextClassDescription_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
#define mGetContextClassDescription() \
        CTstRootCampain_GetContextClassDescription(This)

#define mGetContextClassDescription_Explicit() \
        CTstRootCampain_GetContextClassDescription_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetContextClassDescription",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetContextClassDescription",311
#pragma PRQA_MACRO_MESSAGES_OFF "mGetContextClassDescription_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetContextClassDescription_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstCampain/<Operation>Init
// Method      :        CTstCampain_Init(tCTstCampain_Ref const parentRef)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type        | Name(Direction) |                                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstCampain_Ref  | parentRef(In)   | Parent class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstRootCampain_Init(Ref) \
        CTstCampain_Init(CTstRootCampain_TO_CTstCampain(Ref))

#define CTstRootCampain_Init_Explicit(Ref) \
        CTstCampain_Init_Explicit(CTstRootCampain_TO_CTstCampain(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_Init",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_Init",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_Init_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_Init_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
#define mInit() \
        CTstRootCampain_Init(This)

#define mInit_Explicit() \
        CTstRootCampain_Init_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mInit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mInit",311
#pragma PRQA_MACRO_MESSAGES_OFF "mInit_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mInit_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstCampain/<Operation>TestAll
// Method      :        CTstCampain_TestAll(tCTstCampain_Ref const parentRef)
// Visibility  :        private, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type        | Name(Direction) |                                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstCampain_Ref  | parentRef(In)   | Parent class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstRootCampain_TestAll(Ref) \
        CTstCampain_TestAll(CTstRootCampain_TO_CTstCampain(Ref))

#define CTstRootCampain_TestAll_Explicit(Ref) \
        CTstCampain_TestAll_Explicit(CTstRootCampain_TO_CTstCampain(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_TestAll",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_TestAll",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_TestAll_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_TestAll_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
#define mTestAll() \
        CTstRootCampain_TestAll(This)

#define mTestAll_Explicit() \
        CTstRootCampain_TestAll_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mTestAll",310
#pragma PRQA_MACRO_MESSAGES_OFF "mTestAll",311
#pragma PRQA_MACRO_MESSAGES_OFF "mTestAll_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mTestAll_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                Public methods section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstRootCampain/<Operation>Run
// Method      :        CTstRootCampain_Run(tCTstRootCampain_Ref const This)
// Visibility  :        public
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          | Name(Direction) |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstRootCampain_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstRootCampain_Run(tCTstRootCampain_Ref const This);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
#define mRun() \
        CTstRootCampain_Run(This)
#endif // #if (defined(CTstRootCampain_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __CTstRootCampain_G_h__
