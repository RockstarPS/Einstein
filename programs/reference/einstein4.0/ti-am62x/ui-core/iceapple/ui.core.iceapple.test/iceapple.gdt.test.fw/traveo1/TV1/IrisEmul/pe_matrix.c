
#include "mm_types.h"
#include "pe_matrix.h"

static void matMultiplyXxX(MM_FLOAT *dst, const MM_FLOAT *src1, const MM_FLOAT *src2, MM_U32 nCols, MM_U32 nRows)
{
    /* We calc dst = src1 * src2
    *  If nCols > nRows, we assume idendity matrix
    */
    MM_U32 i, j, k;
    MM_FLOAT val;

    /* the calling function should take care that we have a seperate dst buffer */
    if ((dst == src1) || (dst == src2))
    {
        return;
    }

    for (i = 0; i<nRows; i++)
    {
        for (j = 0; j<nCols; j++)
        {
            val = 0.0;
            for (k = 0; k<nCols; k++)
            {
                val += src1[i + (k * nRows)] * src2[k+ (j * nRows)];
            }
            dst[i + (j * nRows)] = val;
        }
    }
}


void utMat3x3LoadIdentity(Mat3x3 m)
{
    m[ 0] = 1.0;
    m[ 1] = 0.0;
    m[ 2] = 0.0;
    m[ 3] = 0.0;
    m[ 4] = 1.0;
    m[ 5] = 0.0;
    m[ 6] = 0.0;
    m[ 7] = 0.0;
    m[ 8] = 1.0;
}

void utMat3x3Translate(Mat3x3 m, MM_FLOAT x, MM_FLOAT y)
{
    Mat3x3 tmp, dst;
    MM_U32 i;

    utMat3x3LoadIdentity(tmp);

    tmp[6 + 0] += x;
    tmp[6 + 1] += y;

    matMultiplyXxX(dst, m, tmp, 3, 3);
    for (i = 0; i < 9; i++)
    {
        m[i] = dst[i];
    }
}
