//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//

#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include "dk_runtime2_byte_order.h"
#include "dk_runtime2_deserializer.hpp"

using namespace dk::runtime2::core;

Deserializer::Deserializer(std::uint32_t bufferShrinkThreshold) : mPosition(mData.begin()),
                                                                  mRemaining(0),
                                                                  mBufferShrinkThreshold(bufferShrinkThreshold),
                                                                  mShrinkCount(0)
{
}

Deserializer::Deserializer(const Deserializer &pDes) : mData(pDes.mData),
                                                       mPosition(pDes.mPosition),
                                                       mRemaining(pDes.mRemaining),
                                                       mBufferShrinkThreshold(pDes.mBufferShrinkThreshold),
                                                       mShrinkCount(pDes.mShrinkCount)
{
}

Deserializer::Deserializer(byte_t *pData, std::uint32_t length, std::uint32_t bufferShrinkThreshold) : mData(pData, pData + length),
                                                                                                       mPosition(mData.begin()),
                                                                                                       mRemaining(length),
                                                                                                       mBufferShrinkThreshold(bufferShrinkThreshold),
                                                                                                       mShrinkCount(0)
{
}

Deserializer::~Deserializer()
{
}

bool Deserializer::deserialize(uint8_t &value)
{
    if (1 > mRemaining)
        return false;

    value = *mPosition++;

    mRemaining--;
    return true;
}

bool Deserializer::deserialize(uint16_t &value)
{
    if (2 > mRemaining)
        return false;

    uint8_t byte0, byte1;
    byte0 = *mPosition++;
    byte1 = *mPosition++;
    mRemaining -= 2;

    value = DK_BYTES_TO_WORD(byte0, byte1);

    return true;
}

bool Deserializer::deserialize(uint32_t &value, bool omitLastByte)
{
    if (3 > mRemaining || (!omitLastByte && 4 > mRemaining))
        return false;

    uint8_t byte0 = 0, byte1, byte2, byte3;
    if (!omitLastByte)
    {
        byte0 = *mPosition++;
        mRemaining--;
    }
    byte1 = *mPosition++;
    byte2 = *mPosition++;
    byte3 = *mPosition++;
    mRemaining -= 3;

    value = DK_BYTES_TO_LONG(byte0, byte1, byte2, byte3);

    return true;
}

bool Deserializer::deserialize(uint64_t &value)
{
    if (8 > mRemaining)
        return false;

    uint8_t byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7;

    byte0 = *mPosition++;
    byte1 = *mPosition++;
    byte2 = *mPosition++;
    byte3 = *mPosition++;
    byte4 = *mPosition++;
    byte5 = *mPosition++;
    byte6 = *mPosition++;
    byte7 = *mPosition++;

    mRemaining -= 8;

    value = DK_BYTES_TO_LONGLONG(
        byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7);

    return true;
}

bool Deserializer::deserialize(float32_t &value)
{
    bool ret;
#if DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_STRING
    uint16_t tmp;

    ret = deserialize(tmp);
    uint8_t *arr;
    arr = new uint8_t[tmp];
    ret |= deserialize(arr, tmp);
    std::string str(arr, arr + tmp);
    delete arr;
    value = std::stof(str);
#elif DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_DIRECT
    uint32_t tmp;
    ret = deserialize(tmp);
    value = *((float *)&tmp);
#elif DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_SPLIT
    int32_t exponent = 0;
    int64_t fraction = 0;
    float xf = 0;

    ret = deserialize(exponent) | deserialize(fraction);

    if (0 != (exponent & DK_SERIALIZE_FL_NAN))
    {
        value = NAN;
    }
    else if (0 != (exponent & DK_SERIALIZE_FL_PINF))
    {
        value = INFINITY;
    }
    else if (0 != (exponent & DK_SERIALIZE_FL_NINF))
    {
        value = -INFINITY;
    }
    else
    {
        if (0 == fraction)
        {
            value = 0.0;
        }
        else
        {
            xf = ((float)(llabs(fraction) - 1) / (DK_FRAC_MAX - 1)) / 2.0;
            value = ldexpf(xf + 0.5, exponent);

            if (fraction < 0)
            {
                value = -(value);
            }
        }
    }
#else
#error "DK_FLOAT_SERIALIZE not defined"
#endif
    return ret;
}

bool Deserializer::deserialize(float64_t &value)
{
    bool ret;
#if DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_STRING
    uint16_t tmp;
    ret = deserialize(tmp);
    uint8_t *arr;
    arr = new uint8_t[tmp];
    ret |= deserialize(arr, tmp);
    std::string str(arr, arr + tmp);
    delete arr;
    value = std::stod(str);
#elif DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_DIRECT
    uint64_t tmp;
    ret = deserialize(tmp);
    value = *((double *)&tmp);
#elif DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_SPLIT
    int32_t exponent = 0;
    int64_t fraction = 0;
    double xf = 0;

    ret = deserialize(exponent) | deserialize(fraction);

    if (0 != (exponent & DK_SERIALIZE_FL_NAN))
    {
        value = NAN;
    }
    else if (0 != (exponent & DK_SERIALIZE_FL_PINF))
    {
        value = INFINITY;
    }
    else if (0 != (exponent & DK_SERIALIZE_FL_NINF))
    {
        value = -INFINITY;
    }
    else
    {
        if (0 == fraction)
        {
            value = 0.0;
        }
        else
        {
            xf = ((float)(llabs(fraction) - 1) / (DK_FRAC_MAX - 1)) / 2.0;
            value = ldexp(xf + 0.5, exponent);

            if (fraction < 0)
            {
                value = -(value);
            }
        }
    }
#else
#error "DK_FLOAT_SERIALIZE not defined"
#endif
    return ret;
}

bool Deserializer::deserialize(uint8_t *pData, std::uint32_t length)
{
    if (length > mRemaining)
        return false;

    std::memcpy(pData, &mData[mPosition - mData.begin()], length);
    mPosition += length;
    mRemaining -= length;

    return true;
}

bool Deserializer::deserialize(std::vector<uint8_t> &value)
{
    if (value.capacity() > mRemaining)
        return false;

    value.assign(mPosition, mPosition + value.capacity());
    mPosition += value.capacity();
    mRemaining -= value.capacity();

    return true;
}

const byte_t *Deserializer::getData() const
{
    return mData.data();
}

std::uint32_t Deserializer::getSize() const
{
    return static_cast<std::uint32_t>(mData.size());
}

std::uint32_t Deserializer::getRemaining() const
{
    return mRemaining;
}

void Deserializer::setRemaining(std::uint32_t remaining)
{
    mRemaining = remaining;
}

void Deserializer::reset()
{
    if (mBufferShrinkThreshold)
    {
        if (mData.size() < (mData.capacity() >> 1))
        {
            mShrinkCount++;
        }
        else
        {
            mShrinkCount = 0;
        }
    }
    mData.clear();
    mPosition = mData.begin();
    mRemaining = mData.size();
    if (mBufferShrinkThreshold && mShrinkCount > mBufferShrinkThreshold)
    {
        mData.shrink_to_fit();
        mShrinkCount = 0;
    }
}
