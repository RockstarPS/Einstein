#ifndef __CTstBasicConsoleReporter_G_h__
#define __CTstBasicConsoleReporter_G_h__
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
// Entity:              CTstBasicConsoleReporter (Class)
// Description:         Generate a basic report on a console application.
// Owner:               TstBasicConsoleReporter (Package)
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
#define CTstBasicConsoleReporter_TO_CTstReporter(Ref)    ((tCTstReporter_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_TO_CTstReporter",310
#endif // #ifdef _QAC_

#if (defined(CTstBasicConsoleReporter_PROTECTED_VISIBILITY))
#define CTstReporter_TO_CTstBasicConsoleReporter(Ref)    ((tCTstBasicConsoleReporter_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstReporter_TO_CTstBasicConsoleReporter",310
#endif // #ifdef _QAC_

#endif // #if (defined(CTstBasicConsoleReporter_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           General access to the class data
// ---------------------------------------------------------------------------------------------------------------------
#define CTstBasicConsoleReporter_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(CTstBasicConsoleReporter_PROTECTED_VISIBILITY))
#define CTstBasicConsoleReporter_RAM_Access(classRef,attribute) ((classRef)->pRAM->attribute)
#define CTstBasicConsoleReporter_RAM_AccessTbl(classRef,idx,attribute) ((classRef)->pRAM->attribute[idx])
#define CTstBasicConsoleReporter_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define CTstBasicConsoleReporter_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(CTstBasicConsoleReporter_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCTstBasicConsoleReporter_VTBL
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
} tCTstBasicConsoleReporter_VTBL;
typedef tCTstBasicConsoleReporter_VTBL* tCTstBasicConsoleReporter_VTBL_Ref;

extern tCTstBasicConsoleReporter_VTBL CTstBasicConsoleReporter_VTBL;

// ---------------------------------------------------------------------------------------------------------------------
//                             RAM structure (Non-constant attributes are allocated in RAM)
// ---------------------------------------------------------------------------------------------------------------------
typedef struct sCTstBasicConsoleReporter_RAM
{
// Count the number of test point
    uint32 NbTestPoint; // public
// Count the number of error
    uint32 NbError; // public
    char* CurentInstanceName; // public
} tCTstBasicConsoleReporter_RAM;
typedef tCTstBasicConsoleReporter_RAM * tCTstBasicConsoleReporter_RAM_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCTstBasicConsoleReporter
{
    tCTstBasicConsoleReporter_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
    tCTstBasicConsoleReporter_RAM_Ref pRAM; // Auto-generated pointer to RAM structure
} tCTstBasicConsoleReporter;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================

// Standard allocator mCTstBasicConsoleReporter_Allocate
// ---------------------------------------------------------------------------------------------------------------------
//                                                      Help macro
// ---------------------------------------------------------------------------------------------------------------------
#define mCTstBasicConsoleReporter_RAM_Structure(instanceName) instanceName##_RAM

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mCTstBasicConsoleReporter_Allocate(instanceName) \
                                                                                                                        \
static tCTstBasicConsoleReporter_RAM mCTstBasicConsoleReporter_RAM_Structure(instanceName); \
tCTstBasicConsoleReporter instanceName = {\
    &CTstBasicConsoleReporter_VTBL, \
    &mCTstBasicConsoleReporter_RAM_Structure(instanceName) \
}
// ---------------------------------------------------------------------------------------------------------------------

// Explicit allocator mCTstBasicConsoleReporter_Allocate_Explicit

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mCTstBasicConsoleReporter_Allocate_Explicit(instanceName) \
                                                                                                                        \
static tCTstBasicConsoleReporter_RAM mCTstBasicConsoleReporter_RAM_Structure(instanceName); \
tCTstBasicConsoleReporter instanceName = {\
    &CTstBasicConsoleReporter_VTBL, \
    &mCTstBasicConsoleReporter_RAM_Structure(instanceName) \
}
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
//                                              Attribute accessors section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                             Attributes with public access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                               Read/Write functions for public, non-constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<AutoCreatedOperation>SetNbTestPoint
// Method      :        CTstBasicConsoleReporter_SetNbTestPoint(tCTstBasicConsoleReporter_Ref const This, uint32 const NbTestPoint)
// Visibility  :        public
// Description :        Write value to NbTestPoint (Multiplicity [1])
//                      Count the number of test point
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type              | Name(Direction)  |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstBasicConsoleReporter_Ref  | This(In)         | Class reference
// uint32                         | NbTestPoint(In)  | Attribute value
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstBasicConsoleReporter_SetNbTestPoint(tCTstBasicConsoleReporter_Ref const This, uint32 const NbTestPoint);

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<AutoCreatedOperation>GetNbTestPoint
// Method      :        CTstBasicConsoleReporter_GetNbTestPoint(tCTstBasicConsoleReporter_Ref const This)
// Visibility  :        public
// Description :        Read value from NbTestPoint (Multiplicity [1])
//                      Count the number of test point
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type              | Name(Direction) |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstBasicConsoleReporter_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        uint32
// =====================================================================================================================
extern uint32 CTstBasicConsoleReporter_GetNbTestPoint(tCTstBasicConsoleReporter_Ref const This);

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<AutoCreatedOperation>SetNbError
// Method      :        CTstBasicConsoleReporter_SetNbError(tCTstBasicConsoleReporter_Ref const This, uint32 const NbError)
// Visibility  :        public
// Description :        Write value to NbError (Multiplicity [1])
//                      Count the number of error
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type              | Name(Direction) |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstBasicConsoleReporter_Ref  | This(In)        | Class reference
// uint32                         | NbError(In)     | Attribute value
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstBasicConsoleReporter_SetNbError(tCTstBasicConsoleReporter_Ref const This, uint32 const NbError);

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<AutoCreatedOperation>GetNbError
// Method      :        CTstBasicConsoleReporter_GetNbError(tCTstBasicConsoleReporter_Ref const This)
// Visibility  :        public
// Description :        Read value from NbError (Multiplicity [1])
//                      Count the number of error
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type              | Name(Direction) |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstBasicConsoleReporter_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        uint32
// =====================================================================================================================
extern uint32 CTstBasicConsoleReporter_GetNbError(tCTstBasicConsoleReporter_Ref const This);

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<AutoCreatedOperation>SetCurentInstanceName
// Method      :        CTstBasicConsoleReporter_SetCurentInstanceName(tCTstBasicConsoleReporter_Ref const This, char* const CurentInstanceName)
// Visibility  :        public
// Description :        Write value to CurentInstanceName (Multiplicity [1])
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type              |     Name(Direction)     |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstBasicConsoleReporter_Ref  | This(In)                | Class reference
// char*                          | CurentInstanceName(In)  | Attribute value
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstBasicConsoleReporter_SetCurentInstanceName(tCTstBasicConsoleReporter_Ref const This, char* const CurentInstanceName);

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<AutoCreatedOperation>GetCurentInstanceName
// Method      :        CTstBasicConsoleReporter_GetCurentInstanceName(tCTstBasicConsoleReporter_Ref const This)
// Visibility  :        public
// Description :        Read value from CurentInstanceName (Multiplicity [1])
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type              | Name(Direction) |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstBasicConsoleReporter_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        char*
// =====================================================================================================================
extern char* CTstBasicConsoleReporter_GetCurentInstanceName(tCTstBasicConsoleReporter_Ref const This);

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                 Read/Write macro for public, non-constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read/Write value from/to the attribute "NbTestPoint" (public) with reference argument
#define mSetXNbTestPoint(Ref, Data) (CTstBasicConsoleReporter_RAM_Access(Ref,NbTestPoint) = (Data))
#define mGetXNbTestPoint(Ref) CTstBasicConsoleReporter_RAM_Access(Ref,NbTestPoint)
// Read/Write value from/to the attribute "NbTestPoint" (public) without reference argument
#define mSetNbTestPoint(Data) (CTstBasicConsoleReporter_RAM_Access(This,NbTestPoint) = (Data))
#define mGetNbTestPoint() CTstBasicConsoleReporter_RAM_Access(This,NbTestPoint)

// Read/Write value from/to the attribute "NbError" (public) with reference argument
#define mSetXNbError(Ref, Data) (CTstBasicConsoleReporter_RAM_Access(Ref,NbError) = (Data))
#define mGetXNbError(Ref) CTstBasicConsoleReporter_RAM_Access(Ref,NbError)
// Read/Write value from/to the attribute "NbError" (public) without reference argument
#define mSetNbError(Data) (CTstBasicConsoleReporter_RAM_Access(This,NbError) = (Data))
#define mGetNbError() CTstBasicConsoleReporter_RAM_Access(This,NbError)

// Read/Write value from/to the attribute "CurentInstanceName" (public) with reference argument
#define mSetXCurentInstanceName(Ref, Data) (CTstBasicConsoleReporter_RAM_Access(Ref,CurentInstanceName) = (Data))
#define mGetXCurentInstanceName(Ref) CTstBasicConsoleReporter_RAM_Access(Ref,CurentInstanceName)
// Read/Write value from/to the attribute "CurentInstanceName" (public) without reference argument
#define mSetCurentInstanceName(Data) (CTstBasicConsoleReporter_RAM_Access(This,CurentInstanceName) = (Data))
#define mGetCurentInstanceName() CTstBasicConsoleReporter_RAM_Access(This,CurentInstanceName)

#endif // #if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<Operation>Open
// Method      :        CTstBasicConsoleReporter_Open_Implementation(tCTstReporter_Ref const parentRef)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | parentRef(In)   | Parent class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstBasicConsoleReporter_Open_Implementation(tCTstReporter_Ref const parentRef);
// =====================================================================================================================
#define CTstBasicConsoleReporter_Open(Ref) \
        CTstReporter_Open(CTstBasicConsoleReporter_TO_CTstReporter(Ref))

#define CTstBasicConsoleReporter_Open_Explicit(Ref) \
        CTstBasicConsoleReporter_Open_Implementation(CTstBasicConsoleReporter_TO_CTstReporter(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_Open",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_Open",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_Open_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_Open_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
#define mOpen() \
        CTstBasicConsoleReporter_Open(This)

#define mOpen_Implementation() \
        CTstBasicConsoleReporter_Open_Implementation(This)

#define mOpen_Explicit() \
        CTstBasicConsoleReporter_Open_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mOpen",310
#pragma PRQA_MACRO_MESSAGES_OFF "mOpen",311
#pragma PRQA_MACRO_MESSAGES_OFF "mOpen_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mOpen_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mOpen_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mOpen_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<Operation>BeginCampain
// Method      :        CTstBasicConsoleReporter_BeginCampain_Implementation(tCTstReporter_Ref const parentRef, char* const Description)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | parentRef(In)    | Parent class reference
// char*              | Description(In)  | Description
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstBasicConsoleReporter_BeginCampain_Implementation(tCTstReporter_Ref const parentRef, char* const Description);
// =====================================================================================================================
#define CTstBasicConsoleReporter_BeginCampain(Ref, Description) \
        CTstReporter_BeginCampain(CTstBasicConsoleReporter_TO_CTstReporter(Ref), Description)

#define CTstBasicConsoleReporter_BeginCampain_Explicit(Ref, Description) \
        CTstBasicConsoleReporter_BeginCampain_Implementation(CTstBasicConsoleReporter_TO_CTstReporter(Ref), Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_BeginCampain",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_BeginCampain",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_BeginCampain_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_BeginCampain_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
#define mBeginCampain(Description) \
        CTstBasicConsoleReporter_BeginCampain(This, Description)

#define mBeginCampain_Implementation(Description) \
        CTstBasicConsoleReporter_BeginCampain_Implementation(This, Description)

#define mBeginCampain_Explicit(Description) \
        CTstBasicConsoleReporter_BeginCampain_Explicit(This, Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mBeginCampain",310
#pragma PRQA_MACRO_MESSAGES_OFF "mBeginCampain",311
#pragma PRQA_MACRO_MESSAGES_OFF "mBeginCampain_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mBeginCampain_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mBeginCampain_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mBeginCampain_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<Operation>NewContext
// Method      :        CTstBasicConsoleReporter_NewContext_Implementation(tCTstReporter_Ref const parentRef, char* const InstanceDescription, char* const ClassDescription, void * const ClassVTBL)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        |     Name(Direction)      |                               Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | parentRef(In)            | Parent class reference
// char*              | InstanceDescription(In)  | Instance Description
// char*              | ClassDescription(In)     | Class Description
// void *             | ClassVTBL(In)            | Class VTBL, used to identify the context class when several instance of one class are defined.
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstBasicConsoleReporter_NewContext_Implementation(tCTstReporter_Ref const parentRef, char* const InstanceDescription, char* const ClassDescription, void * const ClassVTBL);
// =====================================================================================================================
#define CTstBasicConsoleReporter_NewContext(Ref, InstanceDescription, ClassDescription, ClassVTBL) \
        CTstReporter_NewContext(CTstBasicConsoleReporter_TO_CTstReporter(Ref), InstanceDescription, ClassDescription, ClassVTBL)

#define CTstBasicConsoleReporter_NewContext_Explicit(Ref, InstanceDescription, ClassDescription, ClassVTBL) \
        CTstBasicConsoleReporter_NewContext_Implementation(CTstBasicConsoleReporter_TO_CTstReporter(Ref), InstanceDescription, ClassDescription, ClassVTBL)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_NewContext",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_NewContext",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_NewContext_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_NewContext_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
#define mNewContext(InstanceDescription, ClassDescription, ClassVTBL) \
        CTstBasicConsoleReporter_NewContext(This, InstanceDescription, ClassDescription, ClassVTBL)

#define mNewContext_Implementation(InstanceDescription, ClassDescription, ClassVTBL) \
        CTstBasicConsoleReporter_NewContext_Implementation(This, InstanceDescription, ClassDescription, ClassVTBL)

#define mNewContext_Explicit(InstanceDescription, ClassDescription, ClassVTBL) \
        CTstBasicConsoleReporter_NewContext_Explicit(This, InstanceDescription, ClassDescription, ClassVTBL)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mNewContext",310
#pragma PRQA_MACRO_MESSAGES_OFF "mNewContext",311
#pragma PRQA_MACRO_MESSAGES_OFF "mNewContext_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mNewContext_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mNewContext_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mNewContext_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<Operation>NewTestCase
// Method      :        CTstBasicConsoleReporter_NewTestCase_Implementation(tCTstReporter_Ref const parentRef, char* const Description)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | parentRef(In)    | Parent class reference
// char*              | Description(In)  | Description
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstBasicConsoleReporter_NewTestCase_Implementation(tCTstReporter_Ref const parentRef, char* const Description);
// =====================================================================================================================
#define CTstBasicConsoleReporter_NewTestCase(Ref, Description) \
        CTstReporter_NewTestCase(CTstBasicConsoleReporter_TO_CTstReporter(Ref), Description)

#define CTstBasicConsoleReporter_NewTestCase_Explicit(Ref, Description) \
        CTstBasicConsoleReporter_NewTestCase_Implementation(CTstBasicConsoleReporter_TO_CTstReporter(Ref), Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_NewTestCase",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_NewTestCase",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_NewTestCase_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_NewTestCase_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
#define mNewTestCase(Description) \
        CTstBasicConsoleReporter_NewTestCase(This, Description)

#define mNewTestCase_Implementation(Description) \
        CTstBasicConsoleReporter_NewTestCase_Implementation(This, Description)

#define mNewTestCase_Explicit(Description) \
        CTstBasicConsoleReporter_NewTestCase_Explicit(This, Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mNewTestCase",310
#pragma PRQA_MACRO_MESSAGES_OFF "mNewTestCase",311
#pragma PRQA_MACRO_MESSAGES_OFF "mNewTestCase_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mNewTestCase_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mNewTestCase_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mNewTestCase_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<Operation>NewTestStep
// Method      :        CTstBasicConsoleReporter_NewTestStep_Implementation(tCTstReporter_Ref const parentRef, char* const Description)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | parentRef(In)    | Parent class reference
// char*              | Description(In)  | Description
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstBasicConsoleReporter_NewTestStep_Implementation(tCTstReporter_Ref const parentRef, char* const Description);
// =====================================================================================================================
#define CTstBasicConsoleReporter_NewTestStep(Ref, Description) \
        CTstReporter_NewTestStep(CTstBasicConsoleReporter_TO_CTstReporter(Ref), Description)

#define CTstBasicConsoleReporter_NewTestStep_Explicit(Ref, Description) \
        CTstBasicConsoleReporter_NewTestStep_Implementation(CTstBasicConsoleReporter_TO_CTstReporter(Ref), Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_NewTestStep",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_NewTestStep",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_NewTestStep_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_NewTestStep_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
#define mNewTestStep(Description) \
        CTstBasicConsoleReporter_NewTestStep(This, Description)

#define mNewTestStep_Implementation(Description) \
        CTstBasicConsoleReporter_NewTestStep_Implementation(This, Description)

#define mNewTestStep_Explicit(Description) \
        CTstBasicConsoleReporter_NewTestStep_Explicit(This, Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mNewTestStep",310
#pragma PRQA_MACRO_MESSAGES_OFF "mNewTestStep",311
#pragma PRQA_MACRO_MESSAGES_OFF "mNewTestStep_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mNewTestStep_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mNewTestStep_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mNewTestStep_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<Operation>ReportTestPoint
// Method      :        CTstBasicConsoleReporter_ReportTestPoint_Implementation(tCTstReporter_Ref const parentRef, boolean const IsPassed, char* const File, uint32 const Line, char* const TestedExpression)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        |    Name(Direction)    |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | parentRef(In)         | Parent class reference
// boolean            | IsPassed(In)          | True if the test is OK
// char*              | File(In)              | Name of the File in which the test is located
// uint32             | Line(In)              | Line of the File in which the test is located
// char*              | TestedExpression(In)  | String containing the C expression that have been checked.
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstBasicConsoleReporter_ReportTestPoint_Implementation(tCTstReporter_Ref const parentRef, boolean const IsPassed, char* const File, uint32 const Line, char* const TestedExpression);
// =====================================================================================================================
#define CTstBasicConsoleReporter_ReportTestPoint(Ref, IsPassed, File, Line, TestedExpression) \
        CTstReporter_ReportTestPoint(CTstBasicConsoleReporter_TO_CTstReporter(Ref), IsPassed, File, Line, TestedExpression)

#define CTstBasicConsoleReporter_ReportTestPoint_Explicit(Ref, IsPassed, File, Line, TestedExpression) \
        CTstBasicConsoleReporter_ReportTestPoint_Implementation(CTstBasicConsoleReporter_TO_CTstReporter(Ref), IsPassed, File, Line, TestedExpression)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_ReportTestPoint",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_ReportTestPoint",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_ReportTestPoint_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_ReportTestPoint_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
#define mReportTestPoint(IsPassed, File, Line, TestedExpression) \
        CTstBasicConsoleReporter_ReportTestPoint(This, IsPassed, File, Line, TestedExpression)

#define mReportTestPoint_Implementation(IsPassed, File, Line, TestedExpression) \
        CTstBasicConsoleReporter_ReportTestPoint_Implementation(This, IsPassed, File, Line, TestedExpression)

#define mReportTestPoint_Explicit(IsPassed, File, Line, TestedExpression) \
        CTstBasicConsoleReporter_ReportTestPoint_Explicit(This, IsPassed, File, Line, TestedExpression)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mReportTestPoint",310
#pragma PRQA_MACRO_MESSAGES_OFF "mReportTestPoint",311
#pragma PRQA_MACRO_MESSAGES_OFF "mReportTestPoint_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mReportTestPoint_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mReportTestPoint_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mReportTestPoint_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<Operation>EndCampain
// Method      :        CTstBasicConsoleReporter_EndCampain_Implementation(tCTstReporter_Ref const parentRef)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | parentRef(In)   | Parent class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstBasicConsoleReporter_EndCampain_Implementation(tCTstReporter_Ref const parentRef);
// =====================================================================================================================
#define CTstBasicConsoleReporter_EndCampain(Ref) \
        CTstReporter_EndCampain(CTstBasicConsoleReporter_TO_CTstReporter(Ref))

#define CTstBasicConsoleReporter_EndCampain_Explicit(Ref) \
        CTstBasicConsoleReporter_EndCampain_Implementation(CTstBasicConsoleReporter_TO_CTstReporter(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_EndCampain",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_EndCampain",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_EndCampain_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_EndCampain_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
#define mEndCampain() \
        CTstBasicConsoleReporter_EndCampain(This)

#define mEndCampain_Implementation() \
        CTstBasicConsoleReporter_EndCampain_Implementation(This)

#define mEndCampain_Explicit() \
        CTstBasicConsoleReporter_EndCampain_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mEndCampain",310
#pragma PRQA_MACRO_MESSAGES_OFF "mEndCampain",311
#pragma PRQA_MACRO_MESSAGES_OFF "mEndCampain_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mEndCampain_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mEndCampain_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mEndCampain_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<Operation>Close
// Method      :        CTstBasicConsoleReporter_Close_Implementation(tCTstReporter_Ref const parentRef)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | parentRef(In)   | Parent class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstBasicConsoleReporter_Close_Implementation(tCTstReporter_Ref const parentRef);
// =====================================================================================================================
#define CTstBasicConsoleReporter_Close(Ref) \
        CTstReporter_Close(CTstBasicConsoleReporter_TO_CTstReporter(Ref))

#define CTstBasicConsoleReporter_Close_Explicit(Ref) \
        CTstBasicConsoleReporter_Close_Implementation(CTstBasicConsoleReporter_TO_CTstReporter(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_Close",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_Close",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_Close_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_Close_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
#define mClose() \
        CTstBasicConsoleReporter_Close(This)

#define mClose_Implementation() \
        CTstBasicConsoleReporter_Close_Implementation(This)

#define mClose_Explicit() \
        CTstBasicConsoleReporter_Close_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mClose",310
#pragma PRQA_MACRO_MESSAGES_OFF "mClose",311
#pragma PRQA_MACRO_MESSAGES_OFF "mClose_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mClose_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mClose_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mClose_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_TST/TstReporter/TstBasicConsoleReporter/CTstBasicConsoleReporter/<Operation>AttachReq
// Method      :        CTstBasicConsoleReporter_AttachReq_Implementation(tCTstReporter_Ref const parentRef, char* const Description)
// Visibility  :        public, virtual
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type        | Name(Direction)  |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tCTstReporter_Ref  | parentRef(In)    | Parent class reference
// char*              | Description(In)  | Description
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CTstBasicConsoleReporter_AttachReq_Implementation(tCTstReporter_Ref const parentRef, char* const Description);
// =====================================================================================================================
#define CTstBasicConsoleReporter_AttachReq(Ref, Description) \
        CTstReporter_AttachReq(CTstBasicConsoleReporter_TO_CTstReporter(Ref), Description)

#define CTstBasicConsoleReporter_AttachReq_Explicit(Ref, Description) \
        CTstBasicConsoleReporter_AttachReq_Implementation(CTstBasicConsoleReporter_TO_CTstReporter(Ref), Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_AttachReq",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_AttachReq",311
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_AttachReq_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "CTstBasicConsoleReporter_AttachReq_Explicit",311
#endif // #ifdef _QAC_

#if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
#define mAttachReq(Description) \
        CTstBasicConsoleReporter_AttachReq(This, Description)

#define mAttachReq_Implementation(Description) \
        CTstBasicConsoleReporter_AttachReq_Implementation(This, Description)

#define mAttachReq_Explicit(Description) \
        CTstBasicConsoleReporter_AttachReq_Explicit(This, Description)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mAttachReq",310
#pragma PRQA_MACRO_MESSAGES_OFF "mAttachReq",311
#pragma PRQA_MACRO_MESSAGES_OFF "mAttachReq_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mAttachReq_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mAttachReq_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mAttachReq_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(CTstBasicConsoleReporter_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __CTstBasicConsoleReporter_G_h__
