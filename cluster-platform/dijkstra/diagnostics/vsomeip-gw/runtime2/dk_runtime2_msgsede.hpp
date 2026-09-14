/**
 * VISTEON CORPORATION CONFIDENTIAL
 * ________________________________
 *
 * [2017] Visteon Corporation
 * All Rights Reserved.
 *
 * NOTICE: This is an unpublished work of authorship, which contains trade secrets.
 * Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
 * its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 * or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 * in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
 * under all copyright laws to protect this work as a published work, when appropriate.
 * Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
 * without the written authorization of Visteon Corporation.
 */

#ifndef DK_RUNTIME_MSGSEDE_H
#define DK_RUNTIME_MSGSEDE_H

#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdint>
#include <memory>
#include <math.h>
#include "dk_runtime2_serializer.hpp"
#include "dk_runtime2_deserializer.hpp"
#include <functional>
#include <map>

namespace dk{
namespace runtime2{
namespace core{

/// Message related types
typedef uint16_t mid_t;

struct MsgSerializer : public Serializer
{
public:
  uint8_t mSenderId;
  mid_t mMsgId;
  uint8_t mMsgCnt;


  MsgSerializer(const mid_t msgId, uint16_t senderId, uint8_t msgCnt) : Serializer(0),
                                                                        mSenderId(senderId),
                                                                        mMsgId(msgId),
                                                                        mMsgCnt(msgCnt)
  {
  }

  MsgSerializer(const mid_t msgId, uint16_t senderId, uint8_t msgCnt, uint8_t data) : Serializer(0),
                                                                                      mSenderId(senderId),
                                                                                      mMsgId(msgId),
                                                                                      mMsgCnt(msgCnt)
  {
    serialize(data);
  }

  MsgSerializer(const mid_t msgId, uint16_t senderId, uint8_t msgCnt, uint16_t data) : Serializer(0),
                                                                                       mSenderId(senderId),
                                                                                       mMsgId(msgId),
                                                                                       mMsgCnt(msgCnt)
  {
    serialize(data);
  }

  MsgSerializer(const mid_t msgId, uint16_t senderId, uint8_t msgCnt, uint32_t data) : Serializer(0),
                                                                                       mSenderId(senderId),
                                                                                       mMsgId(msgId),
                                                                                       mMsgCnt(msgCnt)
  {
    serialize(data);
  }

  MsgSerializer(const mid_t msgId, uint8_t msgCnt, const uint8_t *pData, uint32_t size) : Serializer(0),
                                                                                          mSenderId(0),
                                                                                          mMsgId(msgId),
                                                                                          mMsgCnt(msgCnt)
  {
    serialize(pData, size);
  }

  MsgSerializer(const mid_t msgId, uint16_t senderId, uint8_t msgCnt, const uint8_t *pData, uint32_t size) : Serializer(0),
                                                                                                             mSenderId(senderId),
                                                                                                             mMsgId(msgId),
                                                                                                             mMsgCnt(msgCnt)
  {
    serialize(pData, size);
  }

  virtual ~MsgSerializer()
  {
    reset();
  }

  bool isValid()
  {
    return (getSize() > 0);
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

  MsgDeserializer(MsgSerializer *pMsgSerializer) : Deserializer((uint8_t *)pMsgSerializer->getSerializedData(), pMsgSerializer->getSerializedDataSize(), 0),
                                                   mSenderId(0),
                                                   mMsgCnt(0),
                                                   mMsgId(pMsgSerializer->mMsgId)
  {
  }

  MsgDeserializer(const mid_t msgId, const uint8_t *pData, uint32_t size) : Deserializer((uint8_t *)pData, size, 0),
                                                                            mSenderId(0),
                                                                            mMsgCnt(0),
                                                                            mMsgId(msgId)
  {
  }

  MsgDeserializer(const mid_t msgId, uint8_t senderId, uint8_t msgCnt, const uint8_t *pData, uint32_t size) : Deserializer((uint8_t *)pData, size, 0),
                                                                                                              mSenderId(senderId),
                                                                                                              mMsgCnt(msgCnt),
                                                                                                              mMsgId(msgId)
  {
  }
  virtual ~MsgDeserializer()
  {
    reset();
  }

  bool isValid()
  {
    return (getSize() > 0);
  }
};

    typedef  std::function<void(MsgDeserializer & )> msg_cbk_t;
    typedef  std::map<mid_t, msg_cbk_t> msg_map_t;

}   // namespace dk
}   // namespace runtime2
}   // namespace core

#endif // DK_RUNTIME_MSGSEDE_H
