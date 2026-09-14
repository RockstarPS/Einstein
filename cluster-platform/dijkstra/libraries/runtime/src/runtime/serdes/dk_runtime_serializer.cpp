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

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include "dk_runtime_byte_order.h"
#include "dk_runtime_serializer.hpp"

using namespace dk::runtime::core;

Serializer::Serializer ( std::uint32_t bufferShrinkThreshold ) : mData ( 0U ),
    mShrinkCount ( 0U ),
    mBufferShrinkThreshold ( bufferShrinkThreshold )
{
}

Serializer::~Serializer()
{
}

bool Serializer::serialize ( const bool_t value )
{
    if ( true == value )
    {
        mData.push_back ( ( uint8_t ) 0x01U );
    }
    else
    {
        mData.push_back ( ( uint8_t ) 0x00U );
    }

    return true;
}

bool Serializer::serialize ( const uint8_t value )
{
    mData.push_back ( value );
    return true;
}

bool Serializer::serialize ( const uint16_t value )
{
    mData.push_back ( DK_WORD_BYTE1 ( value ) );
    mData.push_back ( DK_WORD_BYTE0 ( value ) );
    return true;
}

bool Serializer::serialize ( const uint32_t value, bool omitLastByte )
{
    if ( !omitLastByte )
    {
        mData.push_back ( DK_LONG_BYTE3 ( value ) );
    }

    mData.push_back ( DK_LONG_BYTE2 ( value ) );
    mData.push_back ( DK_LONG_BYTE1 ( value ) );
    mData.push_back ( DK_LONG_BYTE0 ( value ) );
    return true;
}

bool Serializer::serialize ( const uint64_t value )
{
    mData.push_back ( DK_LL_BYTE7 ( value ) );
    mData.push_back ( DK_LL_BYTE6 ( value ) );
    mData.push_back ( DK_LL_BYTE5 ( value ) );
    mData.push_back ( DK_LL_BYTE4 ( value ) );
    mData.push_back ( DK_LL_BYTE3 ( value ) );
    mData.push_back ( DK_LL_BYTE2 ( value ) );
    mData.push_back ( DK_LL_BYTE1 ( value ) );
    mData.push_back ( DK_LL_BYTE0 ( value ) );
    return true;
}

bool Serializer::serialize ( const uint8_t *pData, uint32_t length )
{
    try
    {
        ( void ) mData.insert ( mData.end(), pData, pData + length );
    }
    catch ( const std::bad_alloc &e )
    {
        std::cout << "Couldn't allocate memory in serializer::serialize(*pData, length)" << e.what() << std::endl;
        return false;
    }

    return true;
}

bool Serializer::serialize ( const std::vector<byte_t> &pData )
{
    try
    {
        ( void ) mData.insert ( ( mData.end() ), ( pData.begin() ), ( pData.end() ) );
    }
    catch ( const std::bad_alloc &e )
    {
        std::cout << "Couldn't allocate memory in serializer::serialize(vector)" << e.what() << std::endl;
        return false;
    }

    return true;
}

bool Serializer::serialize ( const float32_t &value )
{
#if DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_STRING
    std::string float32str = std::to_string ( value );
    return ( serialize ( ( uint16_t ) float32str.size() ) | serialize ( ( uint8_t * ) float32str.c_str(), float32str.size() ) );
#elif DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_DIRECT
    return serialize ( ( uint32_t & ) * ( ( uint32_t * ) &value ) );
#elif DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_SPLIT
    uint32_t flags = 0;
    uint32_t exponent = 0;
    int64_t fraction = 0;
    float xf = 0;

    if ( 0 != std::isnan ( value ) )
    {
        // Data is NaN
        flags = DK_SERIALIZE_FL_NAN;
    }
    else if ( 0 != std::isinf ( value ) )
    {
        if ( INFINITY == value )
        {
            // Data is Pos Infinity
            flags = DK_SERIALIZE_FL_PINF;
        }
        else
        {
            // Data is Neg Infinity
            flags = DK_SERIALIZE_FL_NINF;
        }
    }
    else
    {
        // Valid data
        xf = fabs ( frexpf ( value, ( int * ) &exponent ) ) - 0.5;

        if ( xf < 0.0 )
        {
            fraction = 0;
        }
        else
        {
            fraction = 1 + ( int64_t ) ( xf * 2.0 * ( DK_FRAC_MAX - 1 ) );

            if ( value < 0.0 )
            {
                fraction = -fraction;
            }
        }
    }

    return ( serialize ( ( uint32_t ) ( exponent | flags ) ) | serialize ( fraction ) );
#else
#error "DK_FLOAT_SERIALIZE not defined"
#endif
}

bool Serializer::serialize ( const float64_t &value )
{
#if DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_STRING
    std::string float32str = std::to_string ( value );
    return ( serialize ( ( uint16_t ) float32str.size() ) | serialize ( ( uint8_t * ) float32str.c_str(), float32str.size() ) );
#elif DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_DIRECT
    return serialize ( ( uint64_t & ) * ( ( uint64_t * ) &value ) );
#elif DK_FLOAT_SERIALIZE == DK_FLOAT_SERIALIZE_SPLIT
    uint32_t flags = 0;
    int32_t exponent = 0;
    int64_t fraction = 0;
    double xf = 0;

    if ( 0 != std::isnan ( value ) )
    {
        // Data is NaN
        flags = DK_SERIALIZE_FL_NAN;
    }
    else if ( 0 != std::isinf ( value ) )
    {
        if ( INFINITY == value )
        {
            // Data is Pos Infinity
            flags = DK_SERIALIZE_FL_PINF;
        }
        else
        {
            // Data is Neg Infinity
            flags = DK_SERIALIZE_FL_NINF;
        }
    }
    else
    {
        // Valid data
        xf = fabs ( frexp ( value, ( int * ) &exponent ) ) - 0.5;

        if ( xf < 0.0 )
        {
            fraction = 0;
        }
        else
        {
            fraction = 1 + ( int64_t ) ( xf * 2.0 * ( DK_FRAC_MAX - 1 ) );

            if ( value < 0.0 )
            {
                fraction = -fraction;
            }
        }
    }

    return ( serialize ( ( uint32_t ) ( flags | exponent ) ) | serialize ( fraction ) );
#else
#error "DK_FLOAT_SERIALIZE not defined"
#endif
}

void Serializer::reset()
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

    if ( mBufferShrinkThreshold && mShrinkCount > mBufferShrinkThreshold )
    {
        mData.shrink_to_fit();
        mShrinkCount = 0U;
    }
}

const byte_t *Serializer::getData() const
{
    return mData.data();
}

uint32_t Serializer::getCapacity() const
{
    return static_cast<std::uint32_t> ( mData.max_size() );
}

uint32_t Serializer::getSize() const
{
    return static_cast<std::uint32_t> ( mData.size() );
}
