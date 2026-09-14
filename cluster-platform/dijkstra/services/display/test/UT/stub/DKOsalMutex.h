/*
 * Mutex.h
 *
 *  Created on: Apr 27, 2017
 *      Author: VMUTHUSU
 */

#ifndef SRC_DKOSALMUTEX_H_
#define SRC_DKOSALMUTEX_H_


namespace dk
{

namespace osal
{

/** A mutual-exclusion lock.
 * Only one thread may have a Mutex locked at any one time.
 *
 */

class Mutex
{
    public:

        /** Construct a new Mutex
         */
        Mutex(); 
};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALMUTEX_H_ */
