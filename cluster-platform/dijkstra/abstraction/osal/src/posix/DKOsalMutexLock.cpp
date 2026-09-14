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
/* Related Header file */
#include "DKOsalMutexLock.h"
/*!
 * \include      DKOsalMutex.h
 *  other library includes 
 *  project includes 
 * \brief        For Mutex Class inclusion,
 *               access to SYNCHRONIZED macro
 */
#include "DKOsalMutex.h"                 
/*!
 * \include      DKOsalRecursiveMutex.h
 *  other library includes 
 *  project includes 
 * \brief        For RecursiveMutex class inclusion,
 *               access to SYNCHRONIZED macro
 */
#include "DKOsalRecursiveMutex.h" 

namespace dk
{

namespace osal
{

enum MutexType
{
    TYPE_MUTEX = 1,
    TYPE_RECURSIVEMUTEX = 2
};

/** 
 * \fn      MutexLock ( Mutex &mutexPr ) 
 * \brief   Constructor. Locks the Mutex
 * \param   mutexPr of type Mutex
 * \details requirement ID 751563,751580
 */
MutexLock::MutexLock ( Mutex &mutexPr )
    :
    mpMutex ( &mutexPr )
    ,
    mMutexType ( TYPE_MUTEX )
    ,
    mFlag ( true )
{
    mutexPr.lock();
}

/** 
 * \fn      ~MutexLock() 
 * \brief   Destrcutor. unlocks the Mutex
 * \param   mutex of type Mutex
 * \details requirement ID 751583
 */
MutexLock::~MutexLock()
{
    switch ( mMutexType )
    {
        case TYPE_MUTEX:
            /* coverity[misra_cpp_2008_rule_5_2_8_violation] : FALSE */
            static_cast<Mutex *> ( mpMutex )->unlock();
            break;

        case TYPE_RECURSIVEMUTEX:
            /* coverity[misra_cpp_2008_rule_5_2_8_violation] : FALSE */
            static_cast<RecursiveMutex *> ( mpMutex )->unlock();
            break;

        default:
            break;
    }
}

/** 
 * \fn      MutexLock ( Mutex &mutexPr ) 
 * \brief   Constructor, Locks the Mutex
 * \param   mutexPr of type RecursiveMutex
 * \details requirement ID 751580
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
MutexLock::MutexLock ( RecursiveMutex &mutexPr )
    :
    mpMutex ( &mutexPr )
    ,
    mMutexType ( TYPE_RECURSIVEMUTEX )
    ,
    mFlag ( true )
{
    mutexPr.lock();
}

/** 
 * \fn          bool testFlag()
 * \brief       TestFlag for implementation of SYNCHRONIZED macro
 * \return      <b>true<\b> if Mutex locked, <b>false<\b> otherwise
 */
bool MutexLock::testFlag() const
{
    return mFlag;
}

/** 
 * \fn    void clearFlag()
 * \brief Clear flag for implementation fo SYNCHRONIZED macro. Release the Mutex
 */
void MutexLock::clearFlag()
{
    mFlag = false;
}

} /* namespace osal */

} /* namespace dk */
