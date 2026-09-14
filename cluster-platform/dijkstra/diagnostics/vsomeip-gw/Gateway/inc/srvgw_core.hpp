#ifndef SRVGW_CORE_HPP
#define SRVGW_CORE_HPP
#include <mutex>
#include <condition_variable>
#include <compat/vsomeip/vsomeip.hpp>
#include <dk_gw_cmsgvmf.hpp>
#include <thread>
#include <vector>
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
#include "dk_logger.h"
#else
  #include "OsalWrapperC++/Trace/inc/Tracing.hpp"
#endif

namespace dk{
namespace gw{

class CVsomeipServiceGw
{
public:
    CVsomeipServiceGw(std::vector<std::pair<vsomeip::service_t, vsomeip::method_t>>* _pMsgIds,
    		std::map< vsomeip::service_t, std::map< vsomeip::event_t, uint8_t > >* _pMsgCacheIds,dk::gw::CMsgVmf* _pMsgVmf);

    virtual ~CVsomeipServiceGw();

    bool init();

    void start();

    void stop();

    void on_state_cbk(vsomeip::state_type_e _state);
    
    bool syncCacheMessages(uint32_t counter);

    void subscriptionSyncHandler();

    void sendMsg(vsomeip::service_t srvId, vsomeip::event_t eventId, const byte_t *pData, uint32_t sz);
 
    void sendCachedMsg(uint32_t counter);

    void onMsg(const std::shared_ptr<vsomeip::message> &_response);

private:

    void sendMsg(vsomeip::service_t srvId, vsomeip::event_t eventId, std::shared_ptr<vsomeip::payload> payload);

    std::shared_ptr<vsomeip::runtime> rtm_;
    std::shared_ptr<vsomeip::application> app_;
    bool stop_;
    std::mutex mxCache;
    std::mutex mxStop;
    std::thread mthreadCache;
    std::condition_variable mcvCacheNotify;

    std::vector<std::pair<vsomeip::service_t, vsomeip::method_t>>* pMsgIds;
    std::map< vsomeip::service_t, std::map< vsomeip::event_t, uint8_t > > * pMsgCacheIds;
    std::queue<vsomeip::client_t> subcriberQueue;

    std::set<uint16_t> msgIds;
    std::map< vsomeip::service_t, std::map< vsomeip::event_t, std::shared_ptr<vsomeip::payload> > > msgCache;
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
#else
    PF_TRC_LOGGER_DECLARE(logger);
#endif
    dk::gw::CMsgVmf* pMsgVmf;
};
}   // namespace gw
}   // namespace dk

#endif  //SRVGW_CORE_HPP
