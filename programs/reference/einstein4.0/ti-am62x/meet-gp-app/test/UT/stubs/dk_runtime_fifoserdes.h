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

#ifndef DK_RUNTIME_FIFOSERDES_H
#define DK_RUNTIME_FIFOSERDES_H

#include <queue>
#include <mutex>

#include "dk_logger.h"
//#include "dk_runtime_msgserdes.h"
//#include "dk_runtime_msgcmn.h"

LOG_IMPORT_CONTEXT ( gRTELogContext );

namespace dk
{
namespace runtime
{
namespace core
{
class FifoSerializer : protected std::queue<MsgSerializer *>
{
    public:
        FifoSerializer ( const uint32_t maxCount )
        {
            mMaxCount = maxCount;
        }

        virtual ~FifoSerializer()
        {
        }

        
        

    protected:
        uint32_t mMaxCount;
        //std::mutex mMutex;
};

class FifoDeserializer : protected std::queue<MsgDeserializer *>
{
    public:
        FifoDeserializer ( const uint32_t maxCount )
        {
            mMaxCount = maxCount;
        }

        virtual ~FifoDeserializer()
        {
        }

        

    protected:
        uint32_t mMaxCount;
        //std::mutex mMutex;
};
} // namespace core
} // namespace runtime
} // namespace dk
#endif // DK_RUNTIME_FIFOSERDES_H
