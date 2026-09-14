
#ifndef IRIS_PIXFORMAT_H_
#define IRIS_PIXFORMAT_H_


#include "iris_eng.h"

void IrisPixFormat_Convert(IRIS2_Surface* pSurf,  unsigned color, PixBufferCache* pCache, bool bCached);

#ifdef __cplusplus
extern "C" {
#endif


//void IrisPixFormat_Convert(IRIS2_Surface* pSurf, unsigned color, GLenum& oglFormat, GLenum& oglType, unsigned char*& pWork, bool& isWorkDynamic, bool bCached);

void IrisPixFormat_Init(void);

#ifdef __cplusplus
}
#endif
#endif // IRIS_PIXFORMAT_H_
