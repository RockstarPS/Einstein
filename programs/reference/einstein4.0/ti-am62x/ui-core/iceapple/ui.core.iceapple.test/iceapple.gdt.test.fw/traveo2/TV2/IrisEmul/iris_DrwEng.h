#ifndef IRIS_DRWENG_H
#define IRIS_DRWENG_H

#ifdef __cplusplus
extern "C"
{
#endif

void DrwEng_PrepareAddPoint(IRIS2_PECtx* pCtx, unsigned int numSegments, const unsigned char *pPathSegments, const void *pPathData);

void DrwEng_Draw(IRIS2_PECtx* ctx, float x, float y);

#ifdef __cplusplus
}
#endif

#endif