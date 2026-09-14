/*************************************************************************/
/*          (c) 2010 Fujitsu Semiconductor Europe GmbH                   */
/*                                                                       */
/* ALL RIGHTS RESERVED. No part of this publication may be copied and    */
/* provided to any third party in any form or by any means without the   */
/* written permission of Fujitsu, unless expressly agreed to in written  */
/* form by Fujitsu.                                                      */
/* All trademarks used in this document are the property of their        */
/* respective owners.                                                    */
/*                                                                       */
/* For further provisions please refer to the respective License         */
/* Agreement.                                                            */
/*************************************************************************/

/*!
 * \author      Fujitsu GCC Neuried
 * \version     0.01
 * \date        2010
 * \file        util_math.c
 *              Mathematical utility functions
 *
 *
 *
 * \attention  THIS SAMPLE CODE IS PROVIDED AS IS.
 *             FUJITSU SEMICONDUCTOR ACCEPTS NO RESPONSIBILITY OR LIABILITY
 *             FOR ANY ERRORS OR OMMISSIONS.
 */

/*****************************************************************************/
/*** INCLUDES ****************************************************************/
/*****************************************************************************/

#include "iris_drv.h"
#include "util_math.h"
#include <math.h>

/*****************************************************************************/
/*** DEFINITIONS *************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** TYPES / STRUCTURES ******************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** GLOBAL VARIABLES ********************************************************/
/*****************************************************************************/

static MM_FLOAT GradToPI = (MM_FLOAT)3.14159265 / (MM_FLOAT)180; /*(atan(1.0) * 4.0 / 180)*/

/*****************************************************************************/
/*** FUNCTIONS ***************************************************************/
/*****************************************************************************/

/*
OpenGL always count matrices column first
e.g.
    1   4   7   10
    2   5   8   11
    3   6   9   12
*/
#ifdef DEBUGXXXXX_MSG
void matTrace(char *szName, MM_FLOAT *m, int nCols, int nRows)
{
    int x, y;
    if (szName)
    {
        printf(szName);
        printf(":\n");
    }
    for (y = 0; y < nRows; y++)
    {
        if (y == 0)
        {
            printf("/ ");
        }
        else if (y == nRows -1)
        {
            printf("\\ ");
        }
        else
        {
            printf("| ");
        }
        for (x = 0; x < nCols; x++)
        {
            printf("%.6f ", m[y+x*nRows]);
        }
        if (y == 0)
        {
            printf("\\\n");
        }
        else if (y == nRows -1)
        {
            printf("/\n");
        }
        else
        {
            printf("|\n");
        }
    }
}
void matTrace4x3(char *szName, MM_FLOAT *m)
{
    matTrace(szName, m, 4, 3);
}
void matTrace3x2(char *szName, MM_FLOAT *m)
{
    matTrace(szName, m, 3, 2);
}

#define MAT_4X3_TRACE(x) matTrace4x3 x
#define MAT_3X2_TRACE(x) matTrace3x2 x

#else /* DEBUG_MSG */

#define MAT_4X3_TRACE(x)
#define MAT_3X2_TRACE(x)

#endif /* DEBUG_MSG */

void Mat3x2Copy(Mat3x2 dst, const Mat3x2 src)
{
    dst[ 0] = src[ 0];
    dst[ 1] = src[ 1];
    dst[ 2] = src[ 2];
    dst[ 3] = src[ 3];
    dst[ 4] = src[ 4];
    dst[ 5] = src[ 5];
}

void Mat3x2Multiply(Mat3x2 dst, const Mat3x2 src1, const Mat3x2 src2)
{
    /* just in case dst is the same buffer ... */
    if ((dst == src1) || (dst == src2))
    {
        Mat3x2 tmp;
        Mat3x2Multiply(tmp, src1, src2);
        Mat3x2Copy(dst, tmp);
        return;
    }
    /* We calculate dst = src1 * src2
    *  we assume identity matrix for missing elements
    */
    dst[0] = (src1[0] * src2[0]) + (src1[2] * src2[1]);
    dst[1] = (src1[1] * src2[0]) + (src1[3] * src2[1]);

    dst[2] = (src1[0] * src2[2]) + (src1[2] * src2[3]);
    dst[3] = (src1[1] * src2[2]) + (src1[3] * src2[3]);

    dst[4] = (src1[0] * src2[4]) + (src1[2] * src2[5]) + src1[4];
    dst[5] = (src1[1] * src2[4]) + (src1[3] * src2[5]) + src1[5];
}

void Mat3x2LoadIdentity(Mat3x2 m)
{
    m[ 0] = 1.0F;
    m[ 1] = 0.0F;
    m[ 2] = 0.0F;
    m[ 3] = 1.0F;
    m[ 4] = 0.0F;
    m[ 5] = 0.0F;
}

/* Status: 100%
 * Test Definition: 100% */
void Mat3x2Translate(Mat3x2 m, MM_FLOAT x, MM_FLOAT y)
{
    m[4] = (m[0] * x) + (m[2] * y) + m[4];
    m[5] = (m[1] * x) + (m[3] * y) + m[5];
}

/* Status: 100%
 * Test Definition: 100% */
void Mat3x2TranslatePre(Mat3x2 m, MM_FLOAT x, MM_FLOAT y)
{
    m[4] += x;
    m[5] += y;
}

/* Status: 100%
 * Test Definition: 100% */
void Mat3x2Scale(Mat3x2 m, MM_FLOAT x, MM_FLOAT y)
{
    m[0] *= x;
    m[1] *= x;

    m[2] *= y;
    m[3] *= y;
}

/* Status: 100%
 * Test Definition: 100% */
void Mat3x2ScalePre(Mat3x2 m, MM_FLOAT x, MM_FLOAT y)
{

    m[0] *= x;
    m[1] *= y;

    m[2] *= x;
    m[3] *= y;

    m[4] *= x;
    m[5] *= y;
}

/* Status: 100%
 * Test Definition: 100% */
void Mat3x2Rot(Mat3x2 m, MM_FLOAT f)
{
    MM_FLOAT xcos, xsin, m0, m1, m2, m3;

    f *= GradToPI;
    xcos = cosf(f);
    xsin = sinf(f);

    m0 =  (m[0] * xcos) + (m[2] * xsin);
    m1 =  (m[1] * xcos) + (m[3] * xsin);
    m2 = -(m[0] * xsin) + (m[2] * xcos);
    m3 = -(m[1] * xsin) + (m[3] * xcos);

    m[0] = m0;
    m[1] = m1;
    m[2] = m2;
    m[3] = m3;
}

/* Status: 100%
 * Test Definition: 100% */
void Mat3x2RotPre(Mat3x2 m, MM_FLOAT f)
{
    MM_FLOAT xcos, xsin, m0, m1, m2, m3, m4;

    f *= GradToPI;
    xcos = cosf(f);
    xsin = sinf(f);

    m0   = (xcos * m[0]) - (xsin * m[1]);
    m1   = (xsin * m[0]) + (xcos * m[1]);
    m2   = (xcos * m[2]) - (xsin * m[3]);
    m3   = (xsin * m[2]) + (xcos * m[3]);
    m4   = (xcos * m[4]) - (xsin * m[5]);
    m[5] = (xsin * m[4]) + (xcos * m[5]);

    m[0] = m0;
    m[1] = m1;
    m[2] = m2;
    m[3] = m3;
    m[4] = m4;
}
