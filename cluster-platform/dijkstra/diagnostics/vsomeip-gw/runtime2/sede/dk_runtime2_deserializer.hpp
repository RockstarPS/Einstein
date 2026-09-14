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

#ifndef DESERIALIZER_HPP
#define DESERIALIZER_HPP

#include "dk_runtime2_primitive_types.h"

namespace dk
{
namespace runtime2
{
namespace core
{
class Deserializer
{
public:
  Deserializer(std::uint32_t bufferShrinkThreshold);
  Deserializer(byte_t *pData, std::uint32_t length, std::uint32_t bufferShrinkThreshold);
  Deserializer(const Deserializer &pDes);
  ~Deserializer();

  bool deserialize(uint8_t &value);
  bool deserialize(uint16_t &value);
  bool deserialize(uint32_t &value, bool omitLastByte = false);
  bool deserialize(uint64_t &value);
  bool deserialize(float32_t &value);
  bool deserialize(float64_t &value);
  bool deserialize(uint8_t *pData, std::uint32_t length);
  bool deserialize(std::vector<uint8_t> &value);
  bool deserialize(bool &value) { return deserialize((uint8_t &)value); }
  bool deserialize(int8_t &value) { return deserialize((uint8_t &)value); }
  bool deserialize(int16_t &value) { return deserialize((uint16_t &)value); }
  bool deserialize(int32_t &value, bool omitLastByte = false) { return deserialize((uint32_t &)value, omitLastByte); }
  bool deserialize(int64_t &value) { return deserialize((uint64_t &)value); }

  virtual const uint8_t *getData() const;
  virtual std::uint32_t getSize() const;
  virtual std::uint32_t getRemaining() const;
  virtual void setRemaining(std::uint32_t length);
  virtual void reset();

protected:
  std::vector<byte_t> mData;
  std::vector<byte_t>::iterator mPosition;
  std::uint32_t mRemaining;

private:
  const std::uint32_t mBufferShrinkThreshold;
  std::uint32_t mShrinkCount;
};
}
}
}

#endif //DESERIALIZER_HPP
