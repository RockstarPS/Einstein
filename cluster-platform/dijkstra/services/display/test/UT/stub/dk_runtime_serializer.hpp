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

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <vector>
#include "dk_runtime_primitive_types.h"

namespace dk
{
namespace runtime
{
namespace core
{
class Serializer
{
    public:
    public:
        Serializer ( std::uint32_t bufferShrinkThreshold );
        virtual ~Serializer();

        bool serialize ( const bool_t value );
        bool serialize ( const uint8_t value );
        bool serialize ( const uint16_t value );
        bool serialize ( const uint32_t value, bool omitLastByte = false );
        bool serialize ( const uint64_t value );
        bool serialize ( const float32_t &value );
        bool serialize ( const float64_t &value );
        bool serialize ( const uint8_t *pData, uint32_t length );
       // bool serialize ( const std::vector<byte_t> &pData );
        bool serialize ( const int8_t value )
        {
            return serialize ( ( uint8_t & ) value );
        }
        bool serialize ( const int16_t value )
        {
            return serialize ( ( uint16_t & ) value );
        }
        bool serialize ( const int32_t value, bool omitLastByte = false )
        {
            return serialize ( ( uint32_t & ) value, omitLastByte );
        }
        bool serialize ( const int64_t value )
        {
            return serialize ( ( uint64_t & ) value );
        }

        virtual const uint8_t *getData() const;
        virtual uint32_t getCapacity() const;
        virtual uint32_t getSize() const;
        void reset();

    private:
       // std::vector<byte_t> mData;
        std::uint32_t mShrinkCount;
        std::uint32_t mBufferShrinkThreshold;
};
}
}
}

#endif //SERIALIZER_HPP
