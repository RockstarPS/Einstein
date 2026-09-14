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
#define CTstBasicConsoleReporter_PRIVATE_VISIBILITY
#define CTstBasicConsoleReporter_PROTECTED_VISIBILITY
#define CTstReporter_PROTECTED_VISIBILITY

// ---------------------------------------------------------------------------------------------------------------------
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "TstReporter/TstBasicConsoleReporter/TstBasicConsoleReporter_G.h"

// =====================================================================================================================
//                                                Virtual table instance
// =====================================================================================================================
tCTstBasicConsoleReporter_VTBL CTstBasicConsoleReporter_VTBL = {
    // Operation "Open" defined by the Class "CTstReporter", implemented in the Class "CTstBasicConsoleReporter"
    &CTstBasicConsoleReporter_Open_Implementation,
    // Operation "BeginCampain" defined by the Class "CTstReporter", implemented in the Class "CTstBasicConsoleReporter"
    &CTstBasicConsoleReporter_BeginCampain_Implementation,
    // Operation "NewContext" defined by the Class "CTstReporter", implemented in the Class "CTstBasicConsoleReporter"
    &CTstBasicConsoleReporter_NewContext_Implementation,
    // Operation "NewTestCase" defined by the Class "CTstReporter", implemented in the Class "CTstBasicConsoleReporter"
    &CTstBasicConsoleReporter_NewTestCase_Implementation,
    // Operation "NewTestStep" defined by the Class "CTstReporter", implemented in the Class "CTstBasicConsoleReporter"
    &CTstBasicConsoleReporter_NewTestStep_Implementation,
    // Operation "ReportTestPoint" defined by the Class "CTstReporter", implemented in the Class "CTstBasicConsoleReporter"
    &CTstBasicConsoleReporter_ReportTestPoint_Implementation,
    // Operation "EndCampain" defined by the Class "CTstReporter", implemented in the Class "CTstBasicConsoleReporter"
    &CTstBasicConsoleReporter_EndCampain_Implementation,
    // Operation "Close" defined by the Class "CTstReporter", implemented in the Class "CTstBasicConsoleReporter"
    &CTstBasicConsoleReporter_Close_Implementation,
    // Operation "AttachReq" defined by the Class "CTstReporter", implemented in the Class "CTstBasicConsoleReporter"
    &CTstBasicConsoleReporter_AttachReq_Implementation
};

// =====================================================================================================================
//                                              Attribute accessors section
// =====================================================================================================================

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
void CTstBasicConsoleReporter_SetNbTestPoint(tCTstBasicConsoleReporter_Ref const This, uint32 const NbTestPoint)
{
    mCGAssert(NULL != This);
    mSetNbTestPoint(NbTestPoint);
}

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
uint32 CTstBasicConsoleReporter_GetNbTestPoint(tCTstBasicConsoleReporter_Ref const This)
{
    mCGAssert(NULL != This);
    return (mGetNbTestPoint());
}

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
void CTstBasicConsoleReporter_SetNbError(tCTstBasicConsoleReporter_Ref const This, uint32 const NbError)
{
    mCGAssert(NULL != This);
    mSetNbError(NbError);
}

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
uint32 CTstBasicConsoleReporter_GetNbError(tCTstBasicConsoleReporter_Ref const This)
{
    mCGAssert(NULL != This);
    return (mGetNbError());
}

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
void CTstBasicConsoleReporter_SetCurentInstanceName(tCTstBasicConsoleReporter_Ref const This, char* const CurentInstanceName)
{
    mCGAssert(NULL != This);
    mSetCurentInstanceName(CurentInstanceName);
}

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
char* CTstBasicConsoleReporter_GetCurentInstanceName(tCTstBasicConsoleReporter_Ref const This)
{
    mCGAssert(NULL != This);
    return (mGetCurentInstanceName());
}

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
