#ifndef __A2T_TST_Typedefs_G_h__
#define __A2T_TST_Typedefs_G_h__
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
// This file contains package types definition
// ---------------------------------------------------------------------------------------------------------------------
// Generated on Tue Aug 06 13:07:38 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              A2T_TST (DesignUnit)
// Description:         A2TOM Unit Test Framework
// Owner:               A2T_TC_FWK (Package)
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
//                                                   Types definition
// ---------------------------------------------------------------------------------------------------------------------

// Language type mCheck
#ifndef A2T_TypesProtection_mCheck
#define A2T_TypesProtection_mCheck
// ---------------------------------------------------------------------------------------------------------------------
// This item is not a type.
// UML Autocode do not support the usage of marco.
// 
// In that particular case, for the test puprose, we need to use symbols __FILE _LINE, that cannot be used in a regular
// method. By using a macro we are able to retreive the line of code that generate the call.
// ---------------------------------------------------------------------------------------------------------------------
#define mCheck(expression)  CTstReporter_ReportTestPoint(mGetpResult(), (expression)!=0, __FILE__, __LINE__, #expression)
#define mCHECK(expression)  mCheck(expression)
#endif

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __A2T_TST_Typedefs_G_h__
