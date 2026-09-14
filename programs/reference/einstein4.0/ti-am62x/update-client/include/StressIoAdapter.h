/*
 * UPDi_FileIoAdapter.h
 *
 *  Created on: Nov 14, 2023
 *      Author: EBARBAUX
 */

#ifndef TEST_FT_STRESSIOADAPTER_H_
#define TEST_FT_STRESSIOADAPTER_H_

# include "UPDi_IoAdapter.h"

//=====================================================================================================================
//  Public function
//=====================================================================================================================

//=====================================================================================================================
//  Extern const variable - VTBL
//=====================================================================================================================
extern tUPDiIoAdapterVtbl StressIoAdapterVtbl;

//returns N times E_PENDING, 1 time E_OK
void StressIoAdapter_SetConcutivePendingStatus(uint32 _PendingCalls);
void StressIoAdapter_InjectIoError(boolean _ReadError, boolean _WriteError);

#endif /* TEST_FT_STRESSIOADAPTER_H_ */
