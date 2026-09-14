/**********************************************************************************
 **
 **  \file OsalConfig.h
 **
 **  Created on: may 12, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                                              |
 **  |------------|----------|--------------------------------                          |
 **  | 2017-05-12 | VMUTHUSU | Create Initial Module.
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

#ifndef SRC_DKOSALCONFIG_H_
#define SRC_DKOSALCONFIG_H_

/*!
 * \include      cstdint
                 header_files Dependancy_headers
 * \brief        The module shall use **cstdint** (standard datatype inclusion)data types.
 * \addtogroup   header_files
 */
#include <cstdint>
/*!
 * \include      DKOsalClock.h
 * \brief        For Mutex class inclusion 
 */
#include "DKOsalMutex.h"

namespace dk
{

namespace osal
{

typedef const char *ThreadConfigID;
const ThreadConfigID THREAD_DEFAULT = static_cast<ThreadConfigID>("");

typedef uint16_t ThreadPrio;                     // type for thread priorities.
const ThreadPrio OSAL_PRIO_DEFAULT = 0U;     // OS dependent default thread priority.
const uint32_t OSAL_STACKSIZE_DEFAULT = 0U;     // OS dependent default thread stack size.

/**********************************************************************************************************************
 *  INTERNAL TYPES
 *********************************************************************************************************************/
/*!
 * \struct       OSAL_THREAD_CONFIG
 * \brief        Structure for configuring the thread 
 * 
 *  \var         OSAL_THREAD_CONFIG::ID
 *  \brief       ThreadConfigID for which this config applies. The ID's string is restricted up to 149 chars.
 *  
 *  \var         OSAL_THREAD_CONFIG::Prio
 *  \brief       priority for this thread
 * 
 *  \var         OSAL_THREAD_CONFIG::Stacksize
 *  \brief       Stack Size for this thread 
 */
struct OSAL_THREAD_CONFIG
{
    ThreadConfigID ID;  
    ThreadPrio Prio;            
    uint32_t StackSize;              
};

class OsalConfig
{
    public:
        
        /** 
         * \fn       OsalConfig()
         * \brief    Destructor of osalconfig
         */
        OsalConfig();

        /** 
         * \fn       ~OsalConfig()
         * \brief    Destructor of osalconfig
         */
        ~OsalConfig();

        /** 
         * \fn      static OsalConfig &getInstance()
         * \brief   function to get instance of OsalConfig
         * \return  reference to OsalConfig.
         * \details Requirement ID 751552
         */
        static OsalConfig &getInstance();

        /** 
         * \fn    setDefaultThreadConfigTabl
         * \brief set a default thread configuration table.
         */
        void setDefaultThreadConfigTable();
        /* **sets a user provided thread configuration table** */
        /** 
         * \fn      bool setThreadConfigTable ( const OSAL_THREAD_CONFIG configTbl[], const uint32_t size )
         * \brief   This should be called from main() before threads are created.
         * \param   configTbl a fixed array of OSAL_THREAD_CONFIG entries.
         *          The array must not be modified after this call, since OsalConfig
         *          accessess it per pointers.
         * \param   size the number of entries in the configTbl[] array
         * \return  true on sucess.
         * \details Requirement ID 751552
         */
        bool setThreadConfigTable ( const OSAL_THREAD_CONFIG configTbl[], const uint32_t size );

        /** 
         * \fn      bool getThreadConfig ( const ThreadConfigID id, ThreadPrio &prio, uint32_t &stackSize ) const  
         * \brief   search a thread configuration for the given ID.
         * \param   id the thread id for which the config is searched.
         * \param   prio a reference where the found prio is stored in.
         * \param   stackSize a reference where the found stackSize is stored in.
         * \return  true if a config for the given id was found.
         * \details Requirement ID 751552
         */
        bool getThreadConfig ( const ThreadConfigID id, ThreadPrio &prio, uint32_t &stackSize ) const;

        /** 
         * \fn       bool isPrioReserved ( const ThreadPrio prio ) const
         * \brief    if a thread configuration exists which uses the given priority value.
         * @param    prio the thread priority
         * @return   true if a config specified this priority.
         * \details  Requirement ID 751552
         */
        bool isPrioReserved ( const ThreadPrio prio ) const;

    private:
        /* Disable CopyConstructor */
        OsalConfig ( const OsalConfig & ) = delete;

        /* Disable assignment operator */
        OsalConfig &operator= ( const OsalConfig & ) = delete;

        mutable Mutex mMutex;

};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALCONFIG_H_ */
