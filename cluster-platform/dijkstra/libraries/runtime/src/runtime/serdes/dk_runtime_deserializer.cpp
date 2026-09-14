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
#include "dk_runtime_byte_order.h"
#include "dk_runtime_deserializer.hpp"

using namespace dk::runtime::core;

Deserializer::Deserializer ( std::uint32_t bufferShrinkThreshold ) : mPosition ( mData.begin() ),
    mRemaining ( 0U ),
    mBufferShrinkThreshold ( bufferShrinkThreshold ),
    mShrinkCount ( 0U )
{
}

Deserializer::Deserializer ( const Deserializer &pDes ) : mData ( pDes.mData ),
    mPosition ( pDes.mPosition ),
    mRemaining ( pDes.mRemaining ),
    mBufferShrinkThreshold ( pDes.mBufferShrinkThreshold ),
    mShrinkCount ( pDes.mShrinkCount )
{
}

Deserializer::Deserializer ( byte_t *pData, std::uint32_t length, std::uint32_t bufferShrinkThreshold ) : mData ( pData, pData + length ),
    mPosition ( mData.begin() ),
    mRemaining ( length ),
    mBufferShrinkThreshold ( bufferShrinkThreshold ),
    mShrinkCount ( 0U )
{
}

Deserializer::~Deserializer()
{
}

bool Deserializer::deserialize ( bool_t &value )
{
    bool ret = true;

    if ( 1U > mRemaining )
    {
        ret = false;
    }

    else
    {
        if ( ( 0x01U == *mPosition ) )
        {
            value = true;
        }
        else
        {
            value = false;
        }

        *mPosition++;
        mRemaining--;
    }

    return ret;
}

bool Deserializer::deserialize ( uint8_t &value )
{
    bool ret = true;

    if ( 1U > mRemaining )
    {
        ret = false;
    }

    else
    {
        value = *mPosition++;

        mRemaining--;
    }

    return ret;
}

bool Deserializer::deserialize ( uint16_t &value )
{
    bool ret = true;

    if ( 2U > mRemaining )
    {
        ret = false;
    }

    else
    {
        uint8_t byte0;
        uint8_t byte1;

        byte0 = *mPosition++;
        byte1 = *mPosition++;
        mRemaining -= 2U;

        value = DK_BYTES_TO_WORD ( static_cast<uint16_t> ( byte0 ), static_cast<uint16_t> ( byte1 ) );

    }

    return ret;
}

bool Deserializer::deserialize ( uint32_t &value, bool omitLastByte )
{
    bool ret = true;

    if ( ( 3U > mRemaining ) || ( ( ( !omitLastByte ) && ( ( 4U ) ) > ( mRemaining ) ) ) )
    {
        ret = false;
    }

    else
    {
        uint8_t byte0 = 0;
        uint8_t byte1;
        uint8_t byte2;
        uint8_t byte3;

        if ( !omitLastByte )
        {
            byte0 = *mPosition++;
            mRemaining--;
        }

        byte1 = *mPosition++;
        byte2 = *mPosition++;
        byte3 = *mPosition++;
        mRemaining -= 3U;

        value = DK_BYTES_TO_LONG ( static_cast<uint32_t> ( byte0 ), static_cast<uint32_t> ( byte1 ), static_cast<uint32_t> ( byte2 ), static_cast<uint32_t> ( byte3 ) );
    }

    return ret;
}

bool Deserializer::deserialize ( uint64_t &value )
{
    bool ret = true;

    if ( 8U > mRemaining )
    {
        ret = false;
    }

    else
    {
        uint8_t byte0;
        uint8_t byte1;
        uint8_t byte2;
        uint8_t byte3;
        uint8_t byte4;
        uint8_t byte5;
        uint8_t byte6;
        uint8_t byte7;

        byte0 = *mPosition++;
        byte1 = *mPosition++;
        byte2 = *mPosition++;
        byte3 = *mPosition++;
        byte4 = *mPosition++;
        byte5 = *mPosition++;
        byte6 = *mPosition++;
        byte7 = *mPosition++;

        mRemaining -= 8U;

        value = DK_BYTES_TO_LONGLONG (
                        byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7 );
    }

    return ret;
}

bool Deserializer::deserialize ( float32_t &value )
{
    bool ret;
#if DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_STRING
    uint16_t tmp;

    ret = deserialize ( tmp );
    uint8_t *arr;
    arr = new uint8_t[tmp];
    ret |= deserialize ( arr, tmp );
    std::string str ( arr, arr + tmp );
    delete arr;
    value = std::stof ( str );
#elif DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_DIRECT
    uint32_t tmp = 0U;
    ret = deserialize ( tmp );
    std::memcpy(&value, &tmp, sizeof(float32_t));
#elif DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_SPLIT
    int32_t exponent = 0;
    int64_t fraction = 0;
    float xf = 0;

    ret = deserialize ( exponent ) | deserialize ( fraction );

    if ( 0 != ( exponent & DK_SERIALIZE_FL_NAN ) )
    {
        value = NAN;
    }
    else if ( 0 != ( exponent & DK_SERIALIZE_FL_PINF ) )
    {
        value = INFINITY;
    }
    else if ( 0 != ( exponent & DK_SERIALIZE_FL_NINF ) )
    {
        value = -INFINITY;
    }
    else
    {
        if ( 0 == fraction )
        {
            value = 0.0;
        }
        else
        {
            xf = ( ( float ) ( llabs ( fraction ) - 1 ) / ( DK_FRAC_MAX - 1 ) ) / 2.0;
            value = ldexpf ( xf + 0.5, exponent );

            if ( fraction < 0 )
            {
                value = - ( value );
            }
        }
    }

#else
#error "DK_FLOAT_SERIALIZE not defined"
#endif
    return ret;
}

bool Deserializer::deserialize ( float64_t &value )
{
    bool ret;
#if DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_STRING
    uint16_t tmp;
    ret = deserialize ( tmp );
    uint8_t *arr;
    arr = new uint8_t[tmp];
    ret |= deserialize ( arr, tmp );
    std::string str ( arr, arr + tmp );
    delete arr;
    value = std::stod ( str );
#elif DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_DIRECT
    uint64_t tmp = 0U;
    ret = deserialize ( tmp );
    std::memcpy(&value, &tmp, sizeof(float64_t));
#elif DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_SPLIT
    int32_t exponent = 0;
    int64_t fraction = 0;
    double xf = 0;

    ret = deserialize ( exponent ) | deserialize ( fraction );

    if ( 0 != ( exponent & DK_SERIALIZE_FL_NAN ) )
    {
        value = NAN;
    }
    else if ( 0 != ( exponent & DK_SERIALIZE_FL_PINF ) )
    {
        value = INFINITY;
    }
    else if ( 0 != ( exponent & DK_SERIALIZE_FL_NINF ) )
    {
        value = -INFINITY;
    }
    else
    {
        if ( 0 == fraction )
        {
            value = 0.0;
        }
        else
        {
            xf = ( ( float ) ( llabs ( fraction ) - 1 ) / ( DK_FRAC_MAX - 1 ) ) / 2.0;
            value = ldexp ( xf + 0.5, exponent );

            if ( fraction < 0 )
            {
                value = - ( value );
            }
        }
    }

#else
#error "DK_FLOAT_SERIALIZE not defined"
#endif
    return ret;
}

bool Deserializer::deserialize ( uint8_t *pData, std::uint32_t length )
{
    bool ret = true;

    if ( length > mRemaining )
    {
        ret = false;
    }
    else
    {
        ( void ) std::memcpy ( pData, &mData[mPosition - mData.begin()], static_cast<uint64_t> ( length ) );
        mPosition += static_cast<std::uint64_t> ( length );
        mRemaining -= length;
    }

    return ret;
}

bool Deserializer::deserialize ( std::vector<uint8_t> &value )
{
    bool ret = true;

    if ( ( value.capacity() ) > ( mRemaining ) )
    {
        ret = false;
    }
    else
    {
        value.assign ( mPosition, mPosition + value.capacity() );
        mPosition += value.capacity();
        mRemaining -= value.capacity();
    }

    return ret;
}

const byte_t *Deserializer::getData() const
{
    return mData.data();
}

std::uint32_t Deserializer::getSize() const
{
    return static_cast<std::uint32_t> ( mData.size() );
}

std::uint32_t Deserializer::getRemaining() const
{
    return mRemaining;
}

void Deserializer::setRemaining ( std::uint32_t remaining )
{
    mRemaining = remaining;
}

void Deserializer::reset()
{
    if ( mBufferShrinkThreshold )
    {
        if ( ( mData.size() ) < ( ( mData.capacity() ) >> 1U ) )
        {
            mShrinkCount++;
        }
        else
        {
            mShrinkCount = 0U;
        }
    }

    mData.clear();
    mPosition = mData.begin();
    mRemaining = mData.size();

    if ( mBufferShrinkThreshold && mShrinkCount > mBufferShrinkThreshold )
    {
        mData.shrink_to_fit();
        mShrinkCount = 0U;
    }
}
