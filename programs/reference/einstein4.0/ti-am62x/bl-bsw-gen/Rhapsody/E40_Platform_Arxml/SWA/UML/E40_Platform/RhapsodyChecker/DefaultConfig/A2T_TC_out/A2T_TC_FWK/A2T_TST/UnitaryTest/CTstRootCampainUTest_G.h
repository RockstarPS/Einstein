#ifndef __CTstRootCampainUTest_G_h__
#define __CTstRootCampainUTest_G_h__
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
// Entity:              CTstRootCampainUTest (Class)
// Description:         None
// Owner:               UnitaryTest (Package)
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
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "UnitaryTest/CTstRootCampainUTest_Cfg.h"

// ---------------------------------------------------------------------------------------------------------------------
//                                      Inherited classes reference transformation
// ---------------------------------------------------------------------------------------------------------------------
#define CTstRootCampainUTest_TO_CTstContext(Ref)    ((tCTstContext_Ref)(Ref))
#define CTstRootCampainUTest_TO_CTstCampain(Ref)    ((tCTstCampain_Ref)(Ref))
#define CTstRootCampainUTest_TO_CTstRootCampain(Ref)    ((tCTstRootCampain_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_TO_CTstContext",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_TO_CTstCampain",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_TO_CTstRootCampain",310
#endif // #ifdef _QAC_

#if (defined(CTstRootCampainUTest_PROTECTED_VISIBILITY))
#define CTstContext_TO_CTstRootCampainUTest(Ref)    ((tCTstRootCampainUTest_Ref)(Ref))
#define CTstCampain_TO_CTstRootCampainUTest(Ref)    ((tCTstRootCampainUTest_Ref)(Ref))
#define CTstRootCampain_TO_CTstRootCampainUTest(Ref)    ((tCTstRootCampainUTest_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstContext_TO_CTstRootCampainUTest",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstCampain_TO_CTstRootCampainUTest",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampain_TO_CTstRootCampainUTest",310
#endif // #ifdef _QAC_

#endif // #if (defined(CTstRootCampainUTest_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           General access to the class data
// ---------------------------------------------------------------------------------------------------------------------
#define CTstRootCampainUTest_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(CTstRootCampainUTest_PROTECTED_VISIBILITY))
#define CTstRootCampainUTest_RAM_Access(classRef,attribute) ((classRef)->pRAM->attribute)
#define CTstRootCampainUTest_RAM_AccessTbl(classRef,idx,attribute) ((classRef)->pRAM->attribute[idx])
#define CTstRootCampainUTest_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define CTstRootCampainUTest_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(CTstRootCampainUTest_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCTstRootCampainUTest_VTBL
{
    void (*RunTests)(tCTstContext_Ref const, tCTstReporter_Ref const); // Defined by the Class "CTstContext" as virtual
    char* (*GetContextClassDescription)(tCTstContext_Ref const); // Defined by the Class "CTstContext" as abstract and virtual
    void (*Init)(tCTstContext_Ref const); // Defined by the Class "CTstContext" as virtual
    void (*TestAll)(tCTstContext_Ref const); // Defined by the Class "CTstContext" as abstract and virtual
} tCTstRootCampainUTest_VTBL;
typedef tCTstRootCampainUTest_VTBL* tCTstRootCampainUTest_VTBL_Ref;

extern tCTstRootCampainUTest_VTBL CTstRootCampainUTest_VTBL;

// ---------------------------------------------------------------------------------------------------------------------
//                             RAM structure (Non-constant attributes are allocated in RAM)
// ---------------------------------------------------------------------------------------------------------------------
typedef struct sCTstRootCampainUTest_RAM
{
// Attributes from the class "CTstContext"
// Pointer to manage the relation Result(association, multiplicity[0,1])
    tCTstReporter_Ref pResult; // protected
} tCTstRootCampainUTest_RAM;
typedef tCTstRootCampainUTest_RAM * tCTstRootCampainUTest_RAM_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCTstRootCampainUTest
{
    tCTstRootCampainUTest_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
    tCTstRootCampainUTest_RAM_Ref pRAM; // Auto-generated pointer to RAM structure
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
} tCTstRootCampainUTest;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================

// Standard allocator mCTstRootCampainUTest_Allocate
// ---------------------------------------------------------------------------------------------------------------------
//                                                      Help macro
// ---------------------------------------------------------------------------------------------------------------------
#define mCTstRootCampainUTest_RAM_Structure(instanceName) instanceName##_RAM
#define mCTstRootCampainUTest_ContextListTableInstance(instanceName,ContextList_MAX_CARD) \
    const tCTstContext_Ref CTstCampain_pContextListTable##instanceName[ContextList_MAX_CARD]

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mCTstRootCampainUTest_Allocate(instanceName, Description, ContextList_MAX_CARD, pContextListTable, pReporter) \
                                                                                                                        \
mCTstRootCampainUTest_ContextListTableInstance(instanceName,ContextList_MAX_CARD) = pContextListTable; \
static tCTstRootCampainUTest_RAM mCTstRootCampainUTest_RAM_Structure(instanceName); \
tCTstRootCampainUTest instanceName = {\
    &CTstRootCampainUTest_VTBL, \
    &mCTstRootCampainUTest_RAM_Structure(instanceName), \
    Description, \
    ContextList_MAX_CARD, \
    (tCTstContext_Ref *)CTstCampain_pContextListTable##instanceName, \
    pReporter \
}
// ---------------------------------------------------------------------------------------------------------------------

// Explicit allocator mCTstRootCampainUTest_Allocate_Explicit

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mCTstRootCampainUTest_Allocate_Explicit(instanceName, Description, ContextList_MAX_CARD, pContextListTable, pReporter) \
                                                                                                                        \
static tCTstRootCampainUTest_RAM mCTstRootCampainUTest_RAM_Structure(instanceName); \
tCTstRootCampainUTest instanceName = {\
    &CTstRootCampainUTest_VTBL, \
    &mCTstRootCampainUTest_RAM_Structure(instanceName), \
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
#define CTstRootCampainUTest_GetDescription(Ref) \
        CTstContext_GetDescription(CTstRootCampainUTest_TO_CTstContext(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_GetDescription",310
#endif // #ifdef _QAC_
#if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
#define mGetDescription() \
        CTstRootCampainUTest_GetDescription(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetDescription",310
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                      Read macro for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the inherited attribute "Description" (public) with reference argument
#define mGetXDescription(Ref) CTstContext_ROM_Access(Ref,Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetXDescription",310
#endif // #ifdef _QAC_

#endif // #if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           Attributes with protected access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))

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

// Read value from the inherited attribute "pReporter" (protected) with reference argument
#define mGetXpReporter(Ref) CTstRootCampain_ROM_Access(Ref,pReporter)
// Read value from the inherited attribute "pReporter" (protected) without reference argument
#define mGetpReporter() CTstRootCampain_ROM_Access(This,pReporter)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetXpReporter",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetpReporter",310
#endif // #ifdef _QAC_

// Read value from the attribute "cTstRootCampainUTestRef" (static, protected)
#define mGetcTstRootCampainUTestRef() (CTstRootCampainUTest_cTstRootCampainUTestRef)

#endif // #if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))

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
#define CTstRootCampainUTest_TEST_CASE(Ref, Description) \
        CTstContext_TEST_CASE(CTstRootCampainUTest_TO_CTstContext(Ref), Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_TEST_CASE",310
#endif // #ifdef _QAC_
#if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
#define mTEST_CASE(Description) \
        CTstRootCampainUTest_TEST_CASE(This, Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mTEST_CASE",310
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
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
#define CTstRootCampainUTest_TEST_STEP(Ref, Description) \
        CTstContext_TEST_STEP(CTstRootCampainUTest_TO_CTstContext(Ref), Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_TEST_STEP",310
#endif // #ifdef _QAC_
#if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
#define mTEST_STEP(Description) \
        CTstRootCampainUTest_TEST_STEP(This, Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mTEST_STEP",310
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
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
#define CTstRootCampainUTest_AddTestCase(Ref, Description) \
        CTstContext_AddTestCase(CTstRootCampainUTest_TO_CTstContext(Ref), Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_AddTestCase",310
#endif // #ifdef _QAC_
#if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
#define mAddTestCase(Description) \
        CTstRootCampainUTest_AddTestCase(This, Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mAddTestCase",310
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
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
#define CTstRootCampainUTest_AddTestStep(Ref, Description) \
        CTstContext_AddTestStep(CTstRootCampainUTest_TO_CTstContext(Ref), Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_AddTestStep",310
#endif // #ifdef _QAC_
#if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
#define mAddTestStep(Description) \
        CTstRootCampainUTest_AddTestStep(This, Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mAddTestStep",310
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
#define CTstRootCampainUTest_Run(Ref) \
        CTstRootCampain_Run(CTstRootCampainUTest_TO_CTstRootCampain(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_Run",310
#endif // #ifdef _QAC_
#if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
#define mRun() \
        CTstRootCampainUTest_Run(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mRun",310
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
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
#define CTstRootCampainUTest_RunTests(Ref, pResult) \
        CTstCampain_RunTests(CTstRootCampainUTest_TO_CTstCampain(Ref), pResult)

#define CTstRootCampainUTest_RunTests_Explicit(Ref, pResult) \
        CTstCampain_RunTests_Explicit(CTstRootCampainUTest_TO_CTstCampain(Ref), pResult)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_RunTests",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_RunTests",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_RunTests_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_RunTests_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
#define mRunTests(pResult) \
        CTstRootCampainUTest_RunTests(This, pResult)

#define mRunTests_Explicit(pResult) \
        CTstRootCampainUTest_RunTests_Explicit(This, pResult)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mRunTests",310
#pragma PRQA_MACRO_MESSAGES_OFF "mRunTests",311
#pragma PRQA_MACRO_MESSAGES_OFF "mRunTests_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mRunTests_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
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
#define CTstRootCampainUTest_GetContextClassDescription(Ref) \
        CTstCampain_GetContextClassDescription(CTstRootCampainUTest_TO_CTstCampain(Ref))

#define CTstRootCampainUTest_GetContextClassDescription_Explicit(Ref) \
        CTstCampain_GetContextClassDescription_Explicit(CTstRootCampainUTest_TO_CTstCampain(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_GetContextClassDescription",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_GetContextClassDescription",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_GetContextClassDescription_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_GetContextClassDescription_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
#define mGetContextClassDescription() \
        CTstRootCampainUTest_GetContextClassDescription(This)

#define mGetContextClassDescription_Explicit() \
        CTstRootCampainUTest_GetContextClassDescription_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetContextClassDescription",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetContextClassDescription",311
#pragma PRQA_MACRO_MESSAGES_OFF "mGetContextClassDescription_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetContextClassDescription_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
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
#define CTstRootCampainUTest_Init(Ref) \
        CTstCampain_Init(CTstRootCampainUTest_TO_CTstCampain(Ref))

#define CTstRootCampainUTest_Init_Explicit(Ref) \
        CTstCampain_Init_Explicit(CTstRootCampainUTest_TO_CTstCampain(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_Init",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_Init",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_Init_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_Init_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
#define mInit() \
        CTstRootCampainUTest_Init(This)

#define mInit_Explicit() \
        CTstRootCampainUTest_Init_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mInit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mInit",311
#pragma PRQA_MACRO_MESSAGES_OFF "mInit_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mInit_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
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
#define CTstRootCampainUTest_TestAll(Ref) \
        CTstCampain_TestAll(CTstRootCampainUTest_TO_CTstCampain(Ref))

#define CTstRootCampainUTest_TestAll_Explicit(Ref) \
        CTstCampain_TestAll_Explicit(CTstRootCampainUTest_TO_CTstCampain(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_TestAll",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_TestAll",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_TestAll_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstRootCampainUTest_TestAll_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
#define mTestAll() \
        CTstRootCampainUTest_TestAll(This)

#define mTestAll_Explicit() \
        CTstRootCampainUTest_TestAll_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mTestAll",310
#pragma PRQA_MACRO_MESSAGES_OFF "mTestAll",311
#pragma PRQA_MACRO_MESSAGES_OFF "mTestAll_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mTestAll_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstRootCampainUTest_PRIVATE_VISIBILITY))
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                Public methods section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/UnitaryTest/CTstRootCampainUTest/<Operation>main
// Method      :        CTstRootCampainUTest_main(void)
// Visibility  :        static, public
// Description :        None
// Parameters  :        None
// Return type :        void
// =====================================================================================================================
extern void main(void);
// ---------------------------------------------------------------------------------------------------------------------

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __CTstRootCampainUTest_G_h__
