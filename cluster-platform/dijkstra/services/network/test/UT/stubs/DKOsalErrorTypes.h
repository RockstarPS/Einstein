/*
 * types.h
 *
 *  Created on: Apr 11, 2017
 *      Author: VMUTHUSU
 */

#ifndef DKOSALERRORTYPES_H_
#define DKOSALERRORTYPES_H_

#include <cstdint>             /* standard datatype inclusion   */

//namespace DKOSAL
//{
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

const Error OK = 0;
const Error SEND_ERROR = 1;
const Error TIMEOUT = 2;
const Error OBJECT_FULL = 3;
const Error OBJECT_NOT_FOUND = 4;
const Error UNIMPLEMENTED = 5;
const Error INVALID_STATE = 6;
const Error INVALID_PARAMETER = 7;
const Error OBJECT_IN_USE = 8;
const Error FAILED = 9;
const Error WOULDBLOCK = 10;
const Error IS_CLOSED = 11;

/////////////////////////////////////////////////////////////////
//
//  Global functions
//
/////////////////////////////////////////////////////////////////
inline const char *getString ( Error error )
{
    switch ( error )
    {
#if 0

        case DKOSAL::OK:
            return "OK";

        case DKOSAL::SEND_ERROR:
            return "SEND_ERROR";

        case DKOSAL::TIMEOUT:
            return "TIMEOUT";

        case DKOSAL::OBJECT_FULL:
            return "OBJECT_FULL";

        case DKOSAL::OBJECT_NOT_FOUND:
            return "OBJECT_NOT_FOUND";

        case DKOSAL::UNIMPLEMENTED:
            return "UNIMPLEMENTED";

        case DKOSAL::INVALID_STATE:
            return "INVALID_STATE";

        case DKOSAL::INVALID_PARAMETER:
            return "INVALID_PARAMETER";

        case DKOSAL::OBJECT_IN_USE:
            return "OBJECT_IN_USE";

        case DKOSAL::FAILED:
            return "FAILED";

        case DKOSAL::WOULDBLOCK:
            return "WOULDBLOCK";

        case DKOSAL::IS_CLOSED:
            return "IS_CLOSED";

        default:
            return "INVALID";
#else

        case OK:
            return "OK";

        case SEND_ERROR:
            return "SEND_ERROR";

        case TIMEOUT:
            return "TIMEOUT";

        case OBJECT_FULL:
            return "OBJECT_FULL";

        case OBJECT_NOT_FOUND:
            return "OBJECT_NOT_FOUND";

        case UNIMPLEMENTED:
            return "UNIMPLEMENTED";

        case INVALID_STATE:
            return "INVALID_STATE";

        case INVALID_PARAMETER:
            return "INVALID_PARAMETER";

        case OBJECT_IN_USE:
            return "OBJECT_IN_USE";

        case FAILED:
            return "FAILED";

        case WOULDBLOCK:
            return "WOULDBLOCK";

        case IS_CLOSED:
            return "IS_CLOSED";

        default:
            return "INVALID";
#endif
    }
}

/////////////////////////////////////////////////////////////////
//
//  Helper macros
//
/////////////////////////////////////////////////////////////////

#define CIA_RETURN_OK return OK
#define CIA_RETURN(code) return code
#define CIA_SUCCEEDED(code) (code == OK)
#define CIA_FAILED(code) (code != OK)

//}

#endif /* ERRORTYPES_H_ */
