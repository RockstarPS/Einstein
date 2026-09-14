#ifndef ANDROID_HARDWARE_UCL_V2_0_UCL_H
#define ANDROID_HARDWARE_UCL_V2_0_UCL_H

#include <android/hardware/ucl/2.0/IUcl.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace ucl {
namespace V2_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;
using ::android::hidl::base::V1_0::IBase;

struct Ucl : public IUcl,hidl_death_recipient {
	
    // Methods from ::android::hardware::uclpoc::V1_0::IUcl follow.
    Return<int32_t> open(uint8_t chId, uint16_t flags) override;
    Return<int32_t> close(int32_t fd) override;
    Return<void> read(int32_t fd, read_cb _hidl_cb) override;
    Return<int32_t> write(int32_t fd, const hidl_vec<uint8_t>& data) override;
    Return<int32_t> poll(int32_t fd, uint32_t timeout) override;
    Return<int32_t> write_ex(int32_t fd, uint8_t reqId, const hidl_vec<uint8_t>& data) override;
    Return<int32_t> poll_ex(int32_t fd, uint8_t reqId, uint32_t timeout) override;
    Return<void>    ioctl(int32_t fd, uint32_t request, const hidl_vec<uint8_t>& data, ioctl_cb _hidl_cb) override;
    Return<int32_t> ioctl_register_callback(int32_t fd, const sp<::android::hardware::ucl::V2_0::IUclCallback>& callback) override;

    void serviceDied(uint64_t cookie, const wp<IBase>& /* who */) override;
    bool unregisterCallback(const sp<IBase>& cb,uint64_t cookie);

    std::vector<std::pair<int32_t, sp<IUclCallback>>> mIoctlCallbackReg;
    std::vector<int32_t> mFdList;
	std::mutex mClientRegLock;

    std::mutex mWriteLock;
    std::mutex mReadLock;
    std::mutex mWriteExLock;
    std::mutex mIoctlLock;
    std::mutex mPollLock;

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IUcl* HIDL_FETCH_IUcl(const char* name);

}  // namespace implementation
}  // namespace V2_0
}  // namespace ucl
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_UCL_V2_0_UCL_H
