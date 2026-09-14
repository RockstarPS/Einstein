/*
 * MutexLock.h
 *
 *  Created on: Apr 27, 2017
 *      Author: VMUTHUSU
 */

#ifndef SRC_DKOSALMUTEXLOCK_H_
#define SRC_DKOSALMUTEXLOCK_H_


namespace dk
{

namespace osal
{

#define SYNCHRONIZED(M) \
    for(dk::osal::MutexLock _osal_lock(M); _osal_lock.testFlag(); _osal_lock.clearFlag())
        
class MutexLock
{
    public:

        /** Constructor. Locks the Mutex
         * @param mutex of type Mutex
         */
        MutexLock ( Mutex &mutex );
        
        ~MutexLock();
};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALMUTEXLOCK_H_ */
