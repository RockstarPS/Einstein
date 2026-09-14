/**********************************************************************************
 **
 **  \file types.h
 **
 **  Created on: Apr 11, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                                              |
 **  |------------|----------|--------------------------------                          |
 **  | 2017-04-11 | VMUTHUSU | Create Initial Module.
 **  | 2023-09-20 | damudhar | Added Doxygen document
 **
 ** \copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **********************************************************************************/
/**********************************************************************************************************************
 *  HEADER FILE GUARD
 *********************************************************************************************************************/
#ifndef DKOSALERRORTYPES_H_
#define DKOSALERRORTYPES_H_

/*!
 * \include      cstdint
                 header_files Dependancy_headers
 * \brief        The module shall use **cstdint** (standard datatype inclusion)data types.
 * \addtogroup   header_files
 */
#include <cstdint>

namespace dk
{

namespace osal
{
    
/////////////////////////////////////////////////////////////////
//
//  Define error type
//
/////////////////////////////////////////////////////////////////
typedef uint32_t Error;

/////////////////////////////////////////////////////////////////
//
//  Define error values
//
/////////////////////////////////////////////////////////////////

const Error OK = 0U;
/* coverity[misra_cpp_2008_rule_0_1_4_violation] : FALSE */
/* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
const Error SEND_ERROR = 1U;
/* coverity[misra_cpp_2008_rule_0_1_4_violation] : FALSE */
/* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
const Error TIMEOUT = 2U;
/* coverity[misra_cpp_2008_rule_0_1_4_violation] : FALSE */
/* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
const Error OBJECT_FULL = 3U;
const Error OBJECT_NOT_FOUND = 4U;
/* coverity[misra_cpp_2008_rule_0_1_4_violation] : FALSE */
/* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
const Error UNIMPLEMENTED = 5U;
/* coverity[misra_cpp_2008_rule_0_1_4_violation] : FALSE */
/* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
const Error INVALID_STATE = 6U;
/* coverity[misra_cpp_2008_rule_0_1_4_violation] : FALSE */
/* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
const Error INVALID_PARAMETER = 7U;
/* coverity[misra_cpp_2008_rule_0_1_4_violation] : FALSE */
/* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
const Error OBJECT_IN_USE = 8U;
const Error FAILED = 9U;
/* coverity[misra_cpp_2008_rule_0_1_4_violation] : FALSE */
/* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
const Error WOULDBLOCK = 10U;
/* coverity[misra_cpp_2008_rule_0_1_4_violation] : FALSE */
/* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
const Error IS_CLOSED = 11U;
/* coverity[misra_cpp_2008_rule_2_10_1_violation] : FALSE */
const Error INVALID = 12U;

/////////////////////////////////////////////////////////////////
//
//  Global functions
//
/////////////////////////////////////////////////////////////////
/*!
* \fn      inline const char *getString ( Error errorPr )
* \brief   OsalError shall have error codes to be report on any error occurrence
* \details requirement ID 751533
*/
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
inline const char *getString ( const Error errorPr )
{
    /* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
    static const char *const errorString[] = {"OK",                  "SEND_ERROR",       "TIMEOUT",          "OBJECT_FULL",
                                         "OBJECT_NOT_FOUND",    "UNIMPLEMENTED",    "INVALID_STATE",    "INVALID_PARAMETER",   
                                         "OBJECT_IN_USE",       "FAILED",           "WOULDBLOCK",       "IS_CLOSED" };
    static const char * retString = "INVALID";

    if ( errorPr < INVALID )
    {
        retString = errorString[errorPr];
    }

    return retString;
}

/////////////////////////////////////////////////////////////////
//
//  Helper macros
//
/////////////////////////////////////////////////////////////////

} /* namespace osal */

} /* namespace dk */

#define CIA_RETURN_OK return dk::osal::OK
#define CIA_RETURN(code) return (code)
#define CIA_SUCCEEDED(code) ((code) == dk::osal::OK)
#define CIA_FAILED(code) ((code) != dk::osal::OK)

#endif /* ERRORTYPES_H_ */
