/*
 * Process.h
 *
 *  Created on: Apr 11, 2017
 *      Author: VMUTHUSU
 */

#ifndef SRC_DKOSALPROCESS_H_
#define SRC_DKOSALPROCESS_H_

#include <cstdint>                    /* standard datatype inclusion    */
#include "DKOsalErrorTypes.h"               /* for inclusion of our own Error data type */

namespace dk
{

namespace osal
{

class Process
{
    public:
        /** Default Constructor
         */
        Process();

        /** Default Destructor
         */
        virtual ~Process();

        /**
         * @brief function to create the process
         * @param file_name name of the process
         *        if the filename is not an absolute path, the environment variable PATH is used to locate the process.
         * @param argv[] arguments to be passed when the process starts. NULL terminated array of arguments.
         *        Important: the first entry (argv[0]) should point to the process filename.
         * @return pid of child process or -1 on error.
         */
        static int32_t createProcess ( const char *file_name, char *const argv[] );

        /**
         * @brief  returns the process id of the current process
         * @return process id of the current process
         */
        static uint32_t getProcessId ( void );

        /**
         *  @brief  Set an environment variable.
         *  @param  name Name of the variable
         *  @param  value Value of the variable
         *  @param  overwrite Flag indicating whether an existing variable should be overwritten.
         *  @return OK on success, else an error.
         */
        static Error setenv ( const char *name, const char *value, bool overwrite );

        /**
         *  @brief  Delete an environment variable.
         *  @param  name Name of the variable
         *  @return OK on success, else an error.
         */
        static Error unsetenv ( const char *name );

        /**
         *  @brief  Read an environment variable.
         *  @param  name Name of the variable.
         *  @return CString of the variables value, or NULL if the variable does not exist.
         */
        static const char *getenv ( const char *name );

};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALPROCESS_H_ */
