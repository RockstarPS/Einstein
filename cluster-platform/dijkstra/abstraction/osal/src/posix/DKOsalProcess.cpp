/**********************************************************************************
 **
 **  \file Process.cpp
 **
 **  Created on: Apr 11, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                   
 **  |------------|----------|-------------------------------- 
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

#ifndef _WIN32
/* Related Header file */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "DKOsalProcess.h"
/* C Library includes */
#include <unistd.h>                  /* for fork(), execv() inclusion for linux build */
/* C++ Library includes */
#include <cstring>                   /* for string related functions */
#include <cerrno>                    /* for errno inclusion */
#include <cstdlib>                   /* for environment related function access setenv,unsetenv,getenv etc */
/*!
 * \include      DKOsalTrace.h
 *  other library includes 
 *  project includes 
 * \brief        For OSAL_DBG inclusion
 */
#include "DKOsalTrace.h"             

#define DEFAULT_PATH  "/:/bin:/tmp"

namespace dk
{

namespace osal
{

/** 
 * \fn      Process()
 * \brief   Default Constructor
 * \details requirement ID 751536
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
Process::Process()
{
    OSAL_DBG ( OSAL_SCOPE_PROCESS, "Process::Process() default constructor\n" );

}

/** 
 * \fn      virtual ~Process()
 * \brief   Default Destructor
 * \details requirement ID 751536
 */
Process::~Process()
{
    OSAL_DBG ( OSAL_SCOPE_PROCESS, "Process::~Process() default destructor\n" );
}

/**
 * \fn      static int32_t createProcess ( const char *const file_name, char *const *const argv )
 * \brief   function to create the process
 * \param   file_name name of the process
 *          if the filename is not an absolute path, the environment variable PATH is used to locate the process.
 * \param   argv[] arguments to be passed when the process starts. NULL terminated array of arguments.
 *          Important: the first entry (argv[0]) should point to the process filename.
 * \return  pid of child process or -1 on error.
 * \details requirement ID 751574
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
int32_t Process::createProcess ( const char *const file_name, char *const *const argv )
{
    int32_t child;
    OSAL_DBG ( OSAL_SCOPE_PROCESS, "Process::createProcess(\"%s\",...)\n", file_name );
    child = fork();

    if ( child == 0 )
    {
        // set default PATH if not set
        const int32_t ret = ::setenv ( "PATH", DEFAULT_PATH, 0 );
        if ( ret != 0 )
        {
            OSAL_WARN ( OSAL_SCOPE_PROCESS, "Process::createProcess :setenv() failed, error= %d [%s]\n", 
                        errno, strerror ( errno ) );
        }

        (void) ::execv ( file_name, argv );

        /* execv returns only in case of error */
        OSAL_ERR ( OSAL_SCOPE_PROCESS, "Process::createProcess(): execv(\"%s\",...) failed (error = %d [%s])\n",
                file_name, errno, strerror ( errno ) );
        OSAL_ABORT()
        ;
    }

    return child;
}

/**
 * \fn      static uint32_t getProcessId ( void )
 * \brief   returns the process id of the current process
 * \return  process id of the current process
 * \details requirement ID 751575
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
uint32_t Process::getProcessId()
{
    return static_cast<uint32_t>( getpid() );
}

/**
 *  \fn      static Error setenv ( const char *const name, const char *const value, const bool overwrite )
 *  \brief   Set an environment variable.
 *  \param   name Name of the variable
 *  \param   value Value of the variable
 *  \param   overwrite Flag indicating whether an existing variable should be overwritten.
 *  \return  OK on success, else an error.
 *  \details requirement ID 751576
 */
//-----------------------------------------------------------------------------
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
Error Process::setenv ( const char *const name, const char *const value, const bool overwrite )
//-----------------------------------------------------------------------------
{
    Error retValue = OK;
    const int32_t ret = ::setenv ( name, value, ( overwrite ? static_cast<int32_t>(1) : static_cast<int32_t>(0) ) );

    if ( ret != 0 )
    {
        /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
        OSAL_WARN ( OSAL_SCOPE_PROCESS, "Process::setenv() failed, error= %d [%s]\n", errno, strerror ( errno ) );
        retValue = FAILED;
    }

    return retValue;
}

/**
 *  \fn     static Error unsetenv ( const char *name )
 *  \brief  Delete an environment variable.
 *  \param  name Name of the variable
 *  \return OK on success, else an error.
 *  \details requirement ID 751577
 */
//-----------------------------------------------------------------------------
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
Error Process::unsetenv ( const char *const name )
//-----------------------------------------------------------------------------
{
    Error retValue = OK;
    const int32_t ret = ::unsetenv ( name );

    if ( ret != 0 )
    {
        /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
        OSAL_WARN ( OSAL_SCOPE_PROCESS, "Process::unsetenv() failed, error= %d [%s]\n", errno, strerror ( errno ) );
        retValue = FAILED;
    }

    return retValue;
}

/**
 *  \fn     static const char *getenv ( const char *const name )    
 *  \brief  Read an environment variable.
 *  \param  name Name of the variable.
 *  \return CString of the variables value, or NULL if the variable does not exist.
 *  \details requirement ID 751578
 */
//-----------------------------------------------------------------------------
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
/* coverity[cert_dcl51_cpp_violation] : FALSE */
const char *Process::getenv ( const char *const name )
//-----------------------------------------------------------------------------
{
    /* coverity[misra_cpp_2008_rule_18_0_3_violation] : FALSE */
    return ::getenv ( name );
}

} /* namespace osal */

} /* namespace dk */
#endif
