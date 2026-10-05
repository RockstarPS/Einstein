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

#ifndef DK_RUNTIME_MSGDESERIALIZER_H
#define DK_RUNTIME_MSGDESERIALIZER_H

#include "dk_runtime_serializer.hpp"
#include "dk_runtime_deserializer.hpp"

namespace dk
{
namespace runtime
{
namespace core
{

///< Type definition for the message id
typedef uint16_t mid_t;

struct MsgSerializer : public Serializer
{
    public:
        uint16_t mSenderId;
        mid_t mMsgId;
        uint8_t mMsgCnt;


        MsgSerializer ( const mid_t msgId, uint16_t senderId, uint8_t msgCnt ) : Serializer ( 0U ),
            mSenderId ( senderId ),
            mMsgId ( msgId ),
            mMsgCnt ( msgCnt )
        {
        }

        MsgSerializer ( const mid_t msgId, uint16_t senderId, uint8_t msgCnt, uint8_t data ) : Serializer ( 0U ),
            mSenderId ( senderId ),
            mMsgId ( msgId ),
            mMsgCnt ( msgCnt )
        {
            ( void ) serialize ( data );
        }

        MsgSerializer ( const mid_t msgId, uint16_t senderId, uint8_t msgCnt, uint16_t data ) : Serializer ( 0U ),
            mSenderId ( senderId ),
            mMsgId ( msgId ),
            mMsgCnt ( msgCnt )
        {
            ( void ) serialize ( data );
        }

        MsgSerializer ( const mid_t msgId, uint16_t senderId, uint8_t msgCnt, uint32_t data ) : Serializer ( 0U ),
            mSenderId ( senderId ),
            mMsgId ( msgId ),
            mMsgCnt ( msgCnt )
        {
            ( void ) serialize ( data );
        }

        MsgSerializer ( const mid_t msgId, uint8_t msgCnt, const uint8_t *pData, uint32_t size ) : Serializer ( 0U ),
            mSenderId ( 0U ),
            mMsgId ( msgId ),
            mMsgCnt ( msgCnt )
        {
            ( void ) serialize ( pData, size );
        }

        MsgSerializer ( const mid_t msgId, uint16_t senderId, uint8_t msgCnt, const uint8_t *pData, uint32_t size ) : Serializer ( 0U ),
            mSenderId ( senderId ),
            mMsgId ( msgId ),
            mMsgCnt ( msgCnt )
        {
            ( void ) serialize ( pData, size );
        }

        virtual ~MsgSerializer()
        {
            reset();
        }

        bool isValid()
        {
            return ( getSize() > 0U );
        }

        const uint8_t *getSerializedData()
        {
            return getData();
        }

        uint32_t getSerializedDataSize()
        {
            return getSize();
        }
};

struct MsgDeserializer : public Deserializer
{
    public:
        uint8_t mSenderId;
        uint8_t mMsgCnt;
        mid_t mMsgId;

        MsgDeserializer ( MsgSerializer *pMsgSerializer ) : Deserializer ( ( uint8_t * ) ( pMsgSerializer->getSerializedData() ), pMsgSerializer->getSerializedDataSize(), 0U ),
            mSenderId ( pMsgSerializer->mSenderId ),
            mMsgCnt ( pMsgSerializer->mMsgCnt ),
            mMsgId ( pMsgSerializer->mMsgId )
        {
        }

        MsgDeserializer ( const mid_t msgId, const uint8_t *pData, uint32_t size ) : Deserializer ( ( uint8_t * ) ( pData ), size, 0U ),
            mSenderId ( 0U ),
            mMsgCnt ( 0U ),
            mMsgId ( msgId )
        {
        }

        MsgDeserializer ( const mid_t msgId, uint8_t senderId, uint8_t msgCnt, const uint8_t *pData, uint32_t size ) : Deserializer ( ( uint8_t * ) ( pData ), size, 0U ),
            mSenderId ( senderId ),
            mMsgCnt ( msgCnt ),
            mMsgId ( msgId )
        {
        }
        virtual ~MsgDeserializer()
        {
            reset();
        }

        bool isValid()
        {
            return ( getSize() > 0U );
        }
};
}
}
}

#endif // DK_RUNTIME_MSGDESERIALIZER_H
