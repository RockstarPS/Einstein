///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
#include <math.h>
#include <stdlib.h>

#include "UclALOs.h"
#include "UclCmnSerialize.h"

#define FRAC_MAX 9223372036854775807LL /* 2**63 - 1 */

Ucl_ReturnType UclCmnSerialize_uint8(uint8 data, uint8 *pBuffer, uint16 *pBytesCopied)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, pBuffer, (uint8 *)&data, (uint32)sizeof(uint8));
    if (UCL_E_OK == Ret)
    {
        *pBytesCopied += (uint16)sizeof(uint8);
    }
    return Ret;
}

Ucl_ReturnType UclCmnSerialize_boolean(uint8 data, uint8 *pBuffer, uint16 *pBytesCopied)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, pBuffer, (uint8 *)&data, (uint32)sizeof(uint8));
    if (UCL_E_OK == Ret)
    {
        *pBytesCopied += (uint16)sizeof(uint8);
    }
    return Ret;
}

Ucl_ReturnType UclCmnSerialize_uint16(uint16 data, uint8 *pBuffer, uint16 *pBytesCopied)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, pBuffer, (uint8 *)&data, (uint32)sizeof(uint16));
    if (UCL_E_OK == Ret)
    {
        *pBytesCopied += (uint16)sizeof(uint16);
    }
    return Ret;
}

Ucl_ReturnType UclCmnSerialize_uint32(uint32 data, uint8 *pBuffer, uint16 *pBytesCopied)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, pBuffer, (uint8 *)&data, (uint32)sizeof(uint32));
    if (UCL_E_OK == Ret)
    {
        *pBytesCopied += (uint16)sizeof(uint32);
    }
    return Ret;
}

Ucl_ReturnType UclCmnSerialize_uint64(uint64 data, uint8 *pBuffer, uint16 *pBytesCopied)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, pBuffer, (uint8 *)&data, (uint32)sizeof(uint64));
    if (UCL_E_OK == Ret)
    {
        *pBytesCopied += (uint16)sizeof(uint64);
    }
    return Ret;
}

Ucl_ReturnType UclCmnSerialize_sint8(sint8 data, uint8 *pBuffer, uint16 *pBytesCopied)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, pBuffer, (uint8 *)&data, (uint32)sizeof(sint8));
    if (UCL_E_OK == Ret)
    {
        *pBytesCopied += (uint16)sizeof(sint8);
    }
    return Ret;
}

Ucl_ReturnType UclCmnSerialize_sint16(sint16 data, uint8 *pBuffer, uint16 *pBytesCopied)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, pBuffer, (uint8 *)&data, (uint32)sizeof(sint16));
    if (UCL_E_OK == Ret)
    {
        *pBytesCopied += (uint16)sizeof(sint16);
    }
    return Ret;
}

Ucl_ReturnType UclCmnSerialize_sint32(sint32 data, uint8 *pBuffer, uint16 *pBytesCopied)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, pBuffer, (uint8 *)&data, (uint32)sizeof(sint32));
    if (UCL_E_OK == Ret)
    {
        *pBytesCopied += (uint16)sizeof(sint32);
    }
    return Ret;
}

Ucl_ReturnType UclCmnSerialize_sint64(sint64 data, uint8 *pBuffer, uint16 *pBytesCopied)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, pBuffer, (uint8 *)&data, (uint32)sizeof(sint64));
    if (UCL_E_OK == Ret)
    {
        *pBytesCopied += (uint16)sizeof(sint64);
    }
    return Ret;
}

Ucl_ReturnType UclCmnSerialize_float32(float32 data, uint8 *pBuffer, uint16 *pBytesCopied)
{
    Ucl_ReturnType Ret = UCL_E_OK;

#ifdef UCL_SERIALIZE_FLOAT_AS_EXP_FRAC
    uint16 len = 0;
    uint32 flags = 0;
    sint32 exponent = 0;
    sint64 fraction = 0;
    float32 xf = 0;

    if (0 != isnan(data))
    {
        // Data is NaN
        flags = UCLCMNSERIALIZE_FL_NAN;
    }
    else if (0 != isinf(data))
    {
        if (INFINITY == data)
        {
            // Data is Pos Infinity
            flags = UCLCMNSERIALIZE_FL_PINF;
        }
        else
        {
            // Data is Neg Infinity
            flags = UCLCMNSERIALIZE_FL_NINF;
        }
    }
    else
    {
        // Valid data
        xf = fabs(frexpf(data, (int *)&exponent)) - 0.5;

        if (xf < 0.0)
        {
            fraction = 0;
        }
        else
        {
            fraction = 1 + (sint64)(xf * 2.0 * (FRAC_MAX - 1));

            if (data < 0.0)
                fraction = -fraction;
        }
    }

    len = *pBytesCopied;
    (void)UclCmnSerialize_sint32((exponent | flags), &pBuffer[*pBytesCopied - len], pBytesCopied);
    (void)UclCmnSerialize_sint64(fraction, &pBuffer[*pBytesCopied - len], pBytesCopied);
#else

    Ret = UclALOs_Memcpy(0, pBuffer, (uint8 *)&data, sizeof(float32 ));
    if (UCL_E_OK == Ret)
    {
        *pBytesCopied += sizeof(float32);
    }
#endif

    return Ret;
}

Ucl_ReturnType UclCmnSerialize_float64(float64 data, uint8 *pBuffer, uint16 *pBytesCopied)
{
    Ucl_ReturnType Ret = UCL_E_OK;
#ifdef UCL_SERIALIZE_FLOAT_AS_EXP_FRAC
    uint16 len = 0;
    uint32 flags = 0;
    sint32 exponent = 0;
    sint64 fraction = 0;
    float64 xf = 0;

    if (0 != isnan(data))
    {
        // Data is NaN
        flags = UCLCMNSERIALIZE_FL_NAN;
    }
    else if (0 != isinf(data))
    {
        if (INFINITY == data)
        {
            // Data is Pos Infinity
            flags = UCLCMNSERIALIZE_FL_PINF;
        }
        else
        {
            // Data is Neg Infinity
            flags = UCLCMNSERIALIZE_FL_NINF;
        }
    }
    else
    {
        // Valid data
        xf = fabs(frexp(data, (int *)&exponent)) - 0.5;

        if (xf < 0.0)
        {
            fraction = 0;
        }
        else
        {
            fraction = 1 + (sint64)(xf * 2.0 * (FRAC_MAX - 1));

            if (data < 0.0)
                fraction = -fraction;
        }
    }

    len = *pBytesCopied;
    (void)UclCmnSerialize_sint32((exponent | flags), &pBuffer[*pBytesCopied - len], pBytesCopied);
    (void)UclCmnSerialize_sint64(fraction, &pBuffer[*pBytesCopied - len], pBytesCopied);
#else
    Ret = UclALOs_Memcpy(0, pBuffer, (uint8 *)&data, sizeof(float64 ));
    if (UCL_E_OK == Ret)
    {
        *pBytesCopied += sizeof(float64);
    }
#endif

    return Ret;
}

Ucl_ReturnType UclCmnDeserialize_uint8(uint8 *data, uint8 *pBuffer, uint16 *pBytesConsumed)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, data, pBuffer, (uint32)sizeof(uint8));
    if (UCL_E_OK == Ret)
    {
        *pBytesConsumed += (uint16)sizeof(uint8);
    }
    return Ret;
}

Ucl_ReturnType UclCmnDeserialize_boolean(uint8 *data, uint8 *pBuffer, uint16 *pBytesConsumed)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, data, pBuffer, (uint32)sizeof(uint8));
    if (UCL_E_OK == Ret)
    {
        *pBytesConsumed += (uint16)sizeof(uint8);
    }
    return Ret;
}

Ucl_ReturnType UclCmnDeserialize_uint16(uint16 *data, uint8 *pBuffer, uint16 *pBytesConsumed)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, (uint8 *)data, pBuffer, (uint32)sizeof(uint16));
    if (UCL_E_OK == Ret)
    {
        *pBytesConsumed += (uint16)sizeof(uint16);
    }
    return Ret;
}

Ucl_ReturnType UclCmnDeserialize_uint32(uint32 *data, uint8 *pBuffer, uint16 *pBytesConsumed)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, (uint8 *)data, pBuffer, (uint32)sizeof(uint32));
    if (UCL_E_OK == Ret)
    {
        *pBytesConsumed += (uint16)sizeof(uint32);
    }
    return Ret;
}

Ucl_ReturnType UclCmnDeserialize_uint64(uint64 *data, uint8 *pBuffer, uint16 *pBytesConsumed)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, (uint8 *)data, pBuffer, (uint32)sizeof(uint64));
    if (UCL_E_OK == Ret)
    {
        *pBytesConsumed += (uint16)sizeof(uint64);
    }
    return Ret;
}

Ucl_ReturnType UclCmnDeserialize_sint8(sint8 *data, uint8 *pBuffer, uint16 *pBytesConsumed)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, (uint8 *)data, pBuffer, (uint32)sizeof(sint8));
    if (UCL_E_OK == Ret)
    {
        *pBytesConsumed += (uint16)sizeof(sint8);
    }
    return Ret;
}

Ucl_ReturnType UclCmnDeserialize_sint16(sint16 *data, uint8 *pBuffer, uint16 *pBytesConsumed)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, (uint8 *)data, pBuffer, (uint32)sizeof(sint16));
    if (UCL_E_OK == Ret)
    {
        *pBytesConsumed += (uint16)sizeof(sint16);
    }
    return Ret;
}

Ucl_ReturnType UclCmnDeserialize_sint32(sint32 *data, uint8 *pBuffer, uint16 *pBytesConsumed)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, (uint8 *)data, pBuffer, (uint32)sizeof(sint32));
    if (UCL_E_OK == Ret)
    {
        *pBytesConsumed += (uint16)sizeof(sint32);
    }
    return Ret;
}

Ucl_ReturnType UclCmnDeserialize_sint64(sint64 *data, uint8 *pBuffer, uint16 *pBytesConsumed)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ret = UclALOs_Memcpy(0, (uint8 *)data, pBuffer, (uint32)sizeof(sint64));
    if (UCL_E_OK == Ret)
    {
        *pBytesConsumed += (uint16)sizeof(sint64);
    }
    return Ret;
}

Ucl_ReturnType UclCmnDeserialize_float32(float32 *data, uint8 *pBuffer, uint16 *pBytesConsumed)
{
    Ucl_ReturnType Ret = UCL_E_OK;
#ifdef UCL_SERIALIZE_FLOAT_AS_EXP_FRAC
    uint16 len = 0;
    sint32 exponent = 0;
    sint64 fraction = 0;
    float32 xf = 0;

    len = *pBytesConsumed;
    (void)UclCmnDeserialize_sint32(&exponent, &pBuffer[*pBytesConsumed - len], pBytesConsumed);
    (void)UclCmnDeserialize_sint64(&fraction, &pBuffer[*pBytesConsumed - len], pBytesConsumed);

    if (0 != (exponent & UCLCMNSERIALIZE_FL_NAN))
    {
        *data = NAN;
    }
    else if (0 != (exponent & UCLCMNSERIALIZE_FL_PINF))
    {
        *data = INFINITY;
    }
    else if (0 != (exponent & UCLCMNSERIALIZE_FL_NINF))
    {
        *data = -INFINITY;
    }
    else
    {
        if (0 == fraction)
        {
            *data = 0.0;
        }
        else
        {
            xf = ((float32)(llabs(fraction) - 1) / (FRAC_MAX - 1)) / 2.0;
            *data = ldexpf(xf + 0.5, exponent);

            if (fraction < 0)
            {
                *data = -(*data);
            }
        }
    }
#else
    Ret = UclALOs_Memcpy(0, (void *)data, pBuffer, sizeof(float32));
    if (UCL_E_OK == Ret)
    {
        *pBytesConsumed += sizeof(float32);
    }
#endif

    return Ret;
}

Ucl_ReturnType UclCmnDeserialize_float64(float64 *data, uint8 *pBuffer, uint16 *pBytesConsumed)
{
    Ucl_ReturnType Ret = UCL_E_OK;
#ifdef UCL_SERIALIZE_FLOAT_AS_EXP_FRAC
    uint16 len = 0;
    sint32 exponent = 0;
    sint64 fraction = 0;
    float64 xf = 0;

    len = *pBytesConsumed;
    (void)UclCmnDeserialize_sint32(&exponent, &pBuffer[*pBytesConsumed - len], pBytesConsumed);
    (void)UclCmnDeserialize_sint64(&fraction, &pBuffer[*pBytesConsumed - len], pBytesConsumed);

    if (0 != (exponent & UCLCMNSERIALIZE_FL_NAN))
    {
        *data = NAN;
    }
    else if (0 != (exponent & UCLCMNSERIALIZE_FL_PINF))
    {
        *data = INFINITY;
    }
    else if (0 != (exponent & UCLCMNSERIALIZE_FL_NINF))
    {
        *data = -INFINITY;
    }
    else
    {
        if (0 == fraction)
        {
            *data = 0.0;
        }
        else
        {
            xf = ((float32)(llabs(fraction) - 1) / (FRAC_MAX - 1)) / 2.0;
            *data = ldexp(xf + 0.5, exponent);

            if (fraction < 0)
            {
                *data = -(*data);
            }
        }
    }
#else
    Ret = UclALOs_Memcpy(0, (void *)data, pBuffer, sizeof(float64));
    if (UCL_E_OK == Ret)
    {
        *pBytesConsumed += sizeof(float64);
    }
#endif

    return Ret;
}
