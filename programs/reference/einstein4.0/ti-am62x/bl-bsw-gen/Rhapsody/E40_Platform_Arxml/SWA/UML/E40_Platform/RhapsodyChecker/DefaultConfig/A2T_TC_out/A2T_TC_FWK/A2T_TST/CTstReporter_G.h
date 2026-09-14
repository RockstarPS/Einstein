#ifndef __CTstReporter_G_h__
#define __CTstReporter_G_h__
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
// Entity:              CTstReporter (Class)
// Description:         The abstract call CTestContext relies on a TestReportEngine.
//                      
//                      The TestReportEngine is responsible to generate the test report. 
//                      
//                      This interface defines the operations provided by the TestReportEngine available for
//                      CTestContext. This interface creates an abstraction on the type of report (HTML, txt, doc ...).
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
#define CTstReporter_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(CTstReporter_PROTECTED_VISIBILITY))
#define CTstReporter_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define CTstReporter_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(CTstReporter_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCTstReporter_VTBL
{
    void (*Open)(tCTstReporter_Ref const); // Defined by the Class "CTstReporter" as abstract and virtual
    void (*BeginCampain)(tCTstReporter_Ref const, char* const); // Defined by the Class "CTstReporter" as abstract and virtual
    void (*NewContext)(tCTstReporter_Ref const, char* const, char* const, void * const); // Defined by the Class "CTstReporter" as abstract and virtual
    void (*NewTestCase)(tCTstReporter_Ref const, char* const); // Defined by the Class "CTstReporter" as abstract and virtual
    void (*NewTestStep)(tCTstReporter_Ref const, char* const); // Defined by the Class "CTstReporter" as abstract and virtual
    void (*ReportTestPoint)(tCTstReporter_Ref const, boolean const, char* const, uint32 const, char* const); // Defined by the Class "CTstReporter" as abstract and virtual
    void (*EndCampain)(tCTstReporter_Ref const); // Defined by the Class "CTstReporter" as abstract and virtual
    void (*Close)(tCTstReporter_Ref const); // Defined by the Class "CTstReporter" as abstract and virtual
    void (*AttachReq)(tCTstReporter_Ref const, char* const); // Defined by the Class "CTstReporter" as abstract and virtual
} tCTstReporter_VTBL;
typedef tCTstReporter_VTBL* tCTstReporter_VTBL_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCTstReporter
{
    tCTstReporter_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
} tCTstReporter;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class is abstract. It does not implement the following method(s):
//    CTstReporter_Open
//    CTstReporter_BeginCampain
//    CTstReporter_NewContext
//    CTstReporter_NewTestCase
//    CTstReporter_NewTestStep
//    CTstReporter_ReportTestPoint
//    CTstReporter_EndCampain
//    CTstReporter_Close
//    CTstReporter_AttachReq

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstReporter/<Operation>Open
// Method      :        CTstReporter_Open(tCTstReporter_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        Open the test report, shall be called before any operation.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstReporter_Open(Ref) \
        CTstReporter_VTBL_Access(Ref)->Open(Ref)
#if (defined(CTstReporter_PRIVATE_VISIBILITY))
#define mOpen() \
        CTstReporter_Open(This)
#endif // #if (defined(CTstReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstReporter/<Operation>BeginCampain
// Method      :        CTstReporter_BeginCampain(tCTstReporter_Ref const This, char* const Description)
// Visibility  :        public, virtual, abstract
// Description :        Report the begining of a new test campain.
//                      A test campain enclose context instances or other campain
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | This(In)         | Class reference
// char*              | Description(In)  | Description
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstReporter_BeginCampain(Ref, Description) \
        CTstReporter_VTBL_Access(Ref)->BeginCampain(Ref, Description)
#if (defined(CTstReporter_PRIVATE_VISIBILITY))
#define mBeginCampain(Description) \
        CTstReporter_BeginCampain(This, Description)
#endif // #if (defined(CTstReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstReporter/<Operation>NewContext
// Method      :        CTstReporter_NewContext(tCTstReporter_Ref const This, char* const InstanceDescription, char* const ClassDescription, void * const ClassVTBL)
// Visibility  :        public, virtual, abstract
// Description :        Report the test begans the execution of a  new Context.
//                      The context will finish when a new context starts, or when the campain finish.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        |     Name(Direction)      |                               Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | This(In)                 | Class reference
// char*              | InstanceDescription(In)  | Instance Description
// char*              | ClassDescription(In)     | Class Description
// void *             | ClassVTBL(In)            | Class VTBL, used to identify the context class when several instance of one class are defined.
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstReporter_NewContext(Ref, InstanceDescription, ClassDescription, ClassVTBL) \
        CTstReporter_VTBL_Access(Ref)->NewContext(Ref, InstanceDescription, ClassDescription, ClassVTBL)
#if (defined(CTstReporter_PRIVATE_VISIBILITY))
#define mNewContext(InstanceDescription, ClassDescription, ClassVTBL) \
        CTstReporter_NewContext(This, InstanceDescription, ClassDescription, ClassVTBL)
#endif // #if (defined(CTstReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstReporter/<Operation>NewTestCase
// Method      :        CTstReporter_NewTestCase(tCTstReporter_Ref const This, char* const Description)
// Visibility  :        public, virtual, abstract
// Description :        Report the test begans the execution of a test case.
//                      The  test case finish when a new test case starts, or when the context finish.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | This(In)         | Class reference
// char*              | Description(In)  | Description
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstReporter_NewTestCase(Ref, Description) \
        CTstReporter_VTBL_Access(Ref)->NewTestCase(Ref, Description)
#if (defined(CTstReporter_PRIVATE_VISIBILITY))
#define mNewTestCase(Description) \
        CTstReporter_NewTestCase(This, Description)
#endif // #if (defined(CTstReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstReporter/<Operation>NewTestStep
// Method      :        CTstReporter_NewTestStep(tCTstReporter_Ref const This, char* const Description)
// Visibility  :        public, virtual, abstract
// Description :        Report the test begans the execution of a test step.
//                      The  test step finish when a new test step starts, or when the test case finish.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | This(In)         | Class reference
// char*              | Description(In)  | Description
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstReporter_NewTestStep(Ref, Description) \
        CTstReporter_VTBL_Access(Ref)->NewTestStep(Ref, Description)
#if (defined(CTstReporter_PRIVATE_VISIBILITY))
#define mNewTestStep(Description) \
        CTstReporter_NewTestStep(This, Description)
#endif // #if (defined(CTstReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstReporter/<Operation>ReportTestPoint
// Method      :        CTstReporter_ReportTestPoint(tCTstReporter_Ref const This, boolean const IsPassed, char* const File, uint32 const Line, char* const TestedExpression)
// Visibility  :        public, virtual, abstract
// Description :        Report a single test point
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        |    Name(Direction)    |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | This(In)              | Class reference
// boolean            | IsPassed(In)          | True if the test is OK
// char*              | File(In)              | Name of the File in which the test is located
// uint32             | Line(In)              | Line of the File in which the test is located
// char*              | TestedExpression(In)  | String containing the C expression that have been checked.
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstReporter_ReportTestPoint(Ref, IsPassed, File, Line, TestedExpression) \
        CTstReporter_VTBL_Access(Ref)->ReportTestPoint(Ref, IsPassed, File, Line, TestedExpression)
#if (defined(CTstReporter_PRIVATE_VISIBILITY))
#define mReportTestPoint(IsPassed, File, Line, TestedExpression) \
        CTstReporter_ReportTestPoint(This, IsPassed, File, Line, TestedExpression)
#endif // #if (defined(CTstReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstReporter/<Operation>EndCampain
// Method      :        CTstReporter_EndCampain(tCTstReporter_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        Reports the end of the curent campain.
//                      Note that a campain can be recursive, the end of the campain do not necesseraly ends the
//                      complete test.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstReporter_EndCampain(Ref) \
        CTstReporter_VTBL_Access(Ref)->EndCampain(Ref)
#if (defined(CTstReporter_PRIVATE_VISIBILITY))
#define mEndCampain() \
        CTstReporter_EndCampain(This)
#endif // #if (defined(CTstReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstReporter/<Operation>Close
// Method      :        CTstReporter_Close(tCTstReporter_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        Close the test report, no operation expect Open can be called after the closure.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstReporter_Close(Ref) \
        CTstReporter_VTBL_Access(Ref)->Close(Ref)
#if (defined(CTstReporter_PRIVATE_VISIBILITY))
#define mClose() \
        CTstReporter_Close(This)
#endif // #if (defined(CTstReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/CTstReporter/<Operation>AttachReq
// Method      :        CTstReporter_AttachReq(tCTstReporter_Ref const This, char* const Description)
// Visibility  :        public, virtual, abstract
// Description :        Generate a basic report on a console application.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | This(In)         | Class reference
// char*              | Description(In)  | Description
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CTstReporter_AttachReq(Ref, Description) \
        CTstReporter_VTBL_Access(Ref)->AttachReq(Ref, Description)
#if (defined(CTstReporter_PRIVATE_VISIBILITY))
#define mAttachReq(Description) \
        CTstReporter_AttachReq(This, Description)
#endif // #if (defined(CTstReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __CTstReporter_G_h__
