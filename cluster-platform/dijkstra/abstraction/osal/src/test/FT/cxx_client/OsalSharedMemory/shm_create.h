/*
 * shm_creator.h
 *
 *  Created on: 25-Sep-2020
 *      Author: draj5
 */

#ifndef _SHM_CREATOR_H_
#define _SHM_CREATOR_H_

#include "DKOsalSharedMemory.h"
using namespace std;
using namespace dk;
using namespace osal;

#define SHM_BLK "/entry"
#define SHM_SIZE 5196U

SharedMemory oSharedMemory;

#endif /* _SHM_CREATOR_H_ */
