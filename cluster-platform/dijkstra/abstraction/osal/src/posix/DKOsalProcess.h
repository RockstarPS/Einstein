/**********************************************************************************
 **
 **  \file Process.h
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

#ifndef SRC_DKOSALPROCESS_H_
#define SRC_DKOSALPROCESS_H_

#include <cstdint>                    /* standard datatype inclusion    */
/*!
* \fn      DKOsalErrorTypes.h
* \brief   OsalError shall have error codes to be report on any error occurrence
* \details requirement ID 751533
*/
#include "DKOsalErrorTypes.h"

namespace dk
{

namespace osal
{

class Process
{
    public:
        /** 
         * \fn      Process()
         * \brief   Default Constructor
         * \details requirement ID 751536
         */
        Process();

        /** 
         * \fn      virtual ~Process()
         * \brief   Default Destructor
         * \details requirement ID 751536
         */
        virtual ~Process();

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
        static int32_t createProcess ( const char *const file_name, char *const *const argv );

        /**
         * \fn      static uint32_t getProcessId ( void )
         * \brief   returns the process id of the current process
         * \return  process id of the current process
         * \details requirement ID 751575
         */
        static uint32_t getProcessId ( void );

        /**
         *  \fn      static Error setenv ( const char *const name, const char *const value, const bool overwrite )
         *  \brief   Set an environment variable.
         *  \param   name Name of the variable
         *  \param   value Value of the variable
         *  \param   overwrite Flag indicating whether an existing variable should be overwritten.
         *  \return  OK on success, else an error.
         *  \details requirement ID 751576
         */
        static Error setenv ( const char *const name, const char *const value, const bool overwrite );

        /**
         *  \fn     static Error unsetenv ( const char *const name )
         *  \brief  Delete an environment variable.
         *  \param  name Name of the variable
         *  \return OK on success, else an error.
         *  \details requirement ID 751577
         */
        static Error unsetenv ( const char *const name );

        /**
         *  \fn     static const char *getenv ( const char *const name )    
         *  \brief  Read an environment variable.
         *  \param  name Name of the variable.
         *  \return CString of the variables value, or NULL if the variable does not exist.
         *  \details requirement ID 751578
         */
        /* coverity[cert_dcl51_cpp_violation] : FALSE */
        static const char *getenv ( const char *const name );

};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALPROCESS_H_ */
