/**********************************************************************************
 **
 **  \file MutexLock.h
 **
 **  Created on: Apr 27, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                                              |
 **  |------------|----------|--------------------------------                          |
 **  | 2017-04-27 | VMUTHUSU | Create Initial Module.
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

#ifndef SRC_DKOSALMUTEXLOCK_H_
#define SRC_DKOSALMUTEXLOCK_H_


/*!
 * \include      cstdint
 *               header_files Dependancy_headers
 * \brief        The module shall use **cstdint** (standard datatype inclusion)data types.
 * \addtogroup   header_files
 */
#include <cstdint>

/** 
 *  Macro imitating the SYNCHRONIZED keyword from Java. The code block following this macro will be
 * synchronized by a previously defined MUTEX variable.
 *
 * Mutex mTempMutex;
 *
 *  SYNCHRONIZED(mTempMutex)
 * {
 *      critical section of code here
 * }
 *
 * Reference
 * http://www.codeproject.com/Articles/12362/A-quot-synchronized-quot-statement-for-C-like-in-J
 */

#define SYNCHRONIZED(M) \
    for(dk::osal::MutexLock _osal_lock(M); _osal_lock.testFlag(); _osal_lock.clearFlag())

namespace dk
{

namespace osal
{

class Mutex;
class RecursiveMutex;
class MutexLock
{
    public:

        /** 
         * \fn      MutexLock ( Mutex &mutexPr ) 
         * \brief   Constructor. Locks the Mutex
         * \param   mutexPr of type Mutex
         * \details requirement ID 751563,751580
         */
        MutexLock ( Mutex &mutexPr );

        /** 
         * \fn      ~MutexLock() 
         * \brief   Destrcutor. unlocks the Mutex
         * \param   mutex of type Mutex
         * \details requirement ID 751583
         */
        ~MutexLock();

        /** 
         * \fn      MutexLock ( Mutex &mutexPr ) 
         * \brief   Constructor, Locks the Mutex
         * \param   mutexPr of type RecursiveMutex
         * \details requirement ID 751580
         */
        MutexLock ( RecursiveMutex &mutexPr );

        /** 
         * \fn          bool testFlag() const
         * \brief       TestFlag for implementation of SYNCHRONIZED macro
         * \return      <b>true<\b> if Mutex locked, <b>false<\b> otherwise
         */
        bool testFlag() const;

        /** 
         * \fn    void clearFlag()
         * \brief Clear flag for implementation fo SYNCHRONIZED macro. Release the Mutex
         */
        void clearFlag();

    private:
        void *mpMutex;
        int64_t mMutexType;
        bool mFlag;
};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALMUTEXLOCK_H_ */
