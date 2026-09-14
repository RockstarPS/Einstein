#ifndef __CTstContext_G_h__
#define __CTstContext_G_h__
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
// Generated on Tue Aug 06 13:07:38 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              CTstContext (Class)
// Description:         CTestContext is an abstract base class. 
//                      It is supposed to be extended by classes containing the test methods an the tested instances.
//                      The method RunTests() of child class is automaticly generated.
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
//                                           General access to the class data
// ---------------------------------------------------------------------------------------------------------------------
#define CTstContext_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(CTstContext_PROTECTED_VISIBILITY))
#define CTstContext_RAM_Access(classRef,attribute) ((classRef)->pRAM->attribute)
#define CTstContext_RAM_AccessTbl(classRef,idx,attribute) ((classRef)->pRAM->attribute[idx])
#define CTstContext_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define CTstContext_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(CTstContext_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCTstContext_VTBL
{
    void (*RunTests)(tCTstContext_Ref const, tCTstReporter_Ref const); // Defined by the Class "CTstContext" as virtual
    char* (*GetContextClassDescription)(tCTstContext_Ref const); // Defined by the Class "CTstContext" as abstract and virtual
    void (*Init)(tCTstContext_Ref const); // Defined by the Class "CTstContext" as virtual
    void (*TestAll)(tCTstContext_Ref const); // Defined by the Class "CTstContext" as abstract and virtual
} tCTstContext_VTBL;
typedef tCTstContext_VTBL* tCTstContext_VTBL_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                             RAM structure (Non-constant attributes are allocated in RAM)
// ---------------------------------------------------------------------------------------------------------------------
typedef struct sCTstContext_RAM
{
// Pointer to manage the relation Result(association, multiplicity[0,1])
    tCTstReporter_Ref pResult; // protected
} tCTstContext_RAM;
typedef tCTstContext_RAM * tCTstContext_RAM_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCTstContext
{
    tCTstContext_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
    tCTstContext_RAM_Ref pRAM; // Auto-generated pointer to RAM structure
    char* Description; // public
} tCTstContext;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class is abstract. It does not implement the following method(s):
//    CTstContext_GetContextClassDescription
//    CTstContext_TestAll

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
extern char* CTstContext_GetDescription(tCTstContext_Ref const This);

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(CTstContext_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                      Read macro for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the attribute "Description" (public) with reference argument
#define mGetXDescription(Ref) CTstContext_ROM_Access(Ref,Description)
// Read value from the attribute "Description" (public) without reference argument
#define mGetDescription() CTstContext_ROM_Access(This,Description)

#endif // #if (defined(CTstContext_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           Attributes with protected access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(CTstContext_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                Read/Write macro for protected, non-constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read/Write value from/to the attribute "pResult" (protected) with reference argument
#define mSetXpResult(Ref, Data) (CTstContext_RAM_Access(Ref,pResult) = (Data))
#define mGetXpResult(Ref) CTstContext_RAM_Access(Ref,pResult)
// Read/Write value from/to the attribute "pResult" (protected) without reference argument
#define mSetpResult(Data) (CTstContext_RAM_Access(This,pResult) = (Data))
#define mGetpResult() CTstContext_RAM_Access(This,pResult)

#endif // #if (defined(CTstContext_PRIVATE_VISIBILITY))

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstContext/<Operation>RunTests
// Method      :        CTstContext_RunTests_Implementation(tCTstContext_Ref const This, tCTstReporter_Ref const pResult)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstContext_Ref   | This(In)        | Class reference
// tCTstReporter_Ref  | pResult(In)     | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstContext_RunTests_Implementation(tCTstContext_Ref const This, tCTstReporter_Ref const pResult);
// =====================================================================================================================
#define CTstContext_RunTests(Ref, pResult) \
        CTstContext_VTBL_Access(Ref)->RunTests(Ref, pResult)

#define CTstContext_RunTests_Explicit(Ref, pResult) \
        CTstContext_RunTests_Implementation(Ref, pResult)

#if (defined(CTstContext_PRIVATE_VISIBILITY))
#define mRunTests(pResult) \
        CTstContext_RunTests(This, pResult)

#define mRunTests_Explicit(pResult) \
        CTstContext_RunTests_Explicit(This, pResult)
#endif // #if (defined(CTstContext_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstContext/<Operation>GetContextClassDescription
// Method      :        CTstContext_GetContextClassDescription(tCTstContext_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type        | Name(Direction) |                                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstContext_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        char*
// =====================================================================================================================
#define CTstContext_GetContextClassDescription(Ref) \
        CTstContext_VTBL_Access(Ref)->GetContextClassDescription(Ref)
#if (defined(CTstContext_PRIVATE_VISIBILITY))
#define mGetContextClassDescription() \
        CTstContext_GetContextClassDescription(This)
#endif // #if (defined(CTstContext_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstContext/<Operation>Init
// Method      :        CTstContext_Init_Implementation(tCTstContext_Ref const This)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type        | Name(Direction) |                                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstContext_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstContext_Init_Implementation(tCTstContext_Ref const This);
// =====================================================================================================================
#define CTstContext_Init(Ref) \
        CTstContext_VTBL_Access(Ref)->Init(Ref)

#define CTstContext_Init_Explicit(Ref) \
        CTstContext_Init_Implementation(Ref)

#if (defined(CTstContext_PRIVATE_VISIBILITY))
#define mInit() \
        CTstContext_Init(This)

#define mInit_Explicit() \
        CTstContext_Init_Explicit(This)
#endif // #if (defined(CTstContext_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstContext/<Operation>TestAll
// Method      :        CTstContext_TestAll(tCTstContext_Ref const This)
// Visibility  :        private, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//       Type        | Name(Direction) |                                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstContext_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstContext_TestAll(Ref) \
        CTstContext_VTBL_Access(Ref)->TestAll(Ref)
#if (defined(CTstContext_PRIVATE_VISIBILITY))
#define mTestAll() \
        CTstContext_TestAll(This)
#endif // #if (defined(CTstContext_PRIVATE_VISIBILITY))
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                               Protected methods section
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(CTstContext_PROTECTED_VISIBILITY))
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
extern void CTstContext_TEST_CASE(tCTstContext_Ref const This, char* const Description);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(CTstContext_PRIVATE_VISIBILITY))
#define mTEST_CASE(Description) \
        CTstContext_TEST_CASE(This, Description)
#endif // #if (defined(CTstContext_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

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
extern void CTstContext_TEST_STEP(tCTstContext_Ref const This, char* const Description);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(CTstContext_PRIVATE_VISIBILITY))
#define mTEST_STEP(Description) \
        CTstContext_TEST_STEP(This, Description)
#endif // #if (defined(CTstContext_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

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
extern void CTstContext_AddTestCase(tCTstContext_Ref const This, char* const Description);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(CTstContext_PRIVATE_VISIBILITY))
#define mAddTestCase(Description) \
        CTstContext_AddTestCase(This, Description)
#endif // #if (defined(CTstContext_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

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
extern void CTstContext_AddTestStep(tCTstContext_Ref const This, char* const Description);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(CTstContext_PRIVATE_VISIBILITY))
#define mAddTestStep(Description) \
        CTstContext_AddTestStep(This, Description)
#endif // #if (defined(CTstContext_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------
#endif // #if (defined(CTstContext_PROTECTED_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __CTstContext_G_h__
