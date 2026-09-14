
#include <csignal>
#include <iostream>
#include <dk_gw_cmsgvmf.hpp>
#include "srvgw_core.hpp"
#include "msg_version.hpp"
#include "msg_ids.hpp"
#include "msg_cache_ids.hpp"
#if defined(DK_CDC_WATCHDOG_ENABLED)
    #include "Health/HealthClient/inc/HealthIf.hpp"
#elif defined(DK_HAM_WATCHDOG_ENABLED) 
    #include "wdg_client.h"
#endif



const std::string AppVersion = "v2.0.0";

dk::gw::CMsgVmf *vmfBrokerPtr(nullptr);
dk::gw::CVsomeipServiceGw *srvgwPtr(nullptr);

#if defined(DK_HAM_WATCHDOG_ENABLED)
    using namespace dk::srvc::health;
#endif

#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
  LOG_DECLARE_CONTEXT(gSrvgwsomeipLogContext);
#else
  PF_TRC_LOGGER_STATIC(logger, "SRV_GATEWAY_MAIN", "SRVC");
#endif

#define WATCHDOG_TIMEOUT_MS  (5000)

void handle_signal(int _signal)
{
    if (srvgwPtr != nullptr && (_signal == SIGINT || _signal == SIGTERM))
    {
    	srvgwPtr->stop();
    }
}

int main(int argc, char **argv)
{
	int ret = 1;

	const uint32_t reqTimeoutInMs = WATCHDOG_TIMEOUT_MS;
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED

	LOG_REGISTER_APP_DLT("SVGW", "srvgw_vsomeip");
    LOG_REGISTER_CONTEXT(gSrvgwsomeipLogContext, "srvgw_vsomeip",  "srvgw_vsomeip", DLT_LOG_INFO);
	LOGI(&gSrvgwsomeipLogContext,"SVGW-Main Started",AppVersion.c_str(),msg_catalogue_version.c_str());

#else	
	PF_TRC_ERR(logger, "SRVGW - Version: %s, Catalogue Version: %s", AppVersion.c_str(), msg_catalogue_version.c_str());
#endif

	signal(SIGINT, handle_signal);
	signal(SIGTERM, handle_signal);
	
#if defined(DK_CDC_WATCHDOG_ENABLED)
	// register connection with cdc HealthManager
	int32_t status = CdcRuntime::HealthIf::Register("srvgw_vsomeip",  reqTimeoutInMs);
	if (CdcRuntime::HealthIf::HealthIfStatus::HEALTHIF_STATUS_OK == status)
	{
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGI(&gSrvgwsomeipLogContext,"CDC Watchdog register success");
#else
		PF_TRC_INFO( logger, "CDC Watchdog register success" );
#endif
	}
	else
	{
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGE(&gSrvgwsomeipLogContext,"CDC Watchdog register failed",status);
#else		
		PF_TRC_ERR( logger, "CDC Watchdog register failed. error:%ld", (int32_t)status);
#endif
	}
	
#elif defined(DK_HAM_WATCHDOG_ENABLED)
	// register connection with HAM
	int32_t lGrantedTimeoutPeriodMs = WdgClient::getInstance()->connect( (int8_t *) "srvgw_vsomeip",  reqTimeoutInMs);		
	if ( WdgClient::WDG_ERR != lGrantedTimeoutPeriodMs )
	{
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGI(&gSrvgwsomeipLogContext, "HAM Watchdog register success");
#else
		PF_TRC_INFO( logger, "HAM Watchdog register success" );
#endif
	}
	else
	{
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGE(&gSrvgwsomeipLogContext,"CDC Watchdog register failed",lGrantedTimeoutPeriodMs);
#else
		PF_TRC_ERR( logger, "HAM Watchdog register failed. error:%ld", lGrantedTimeoutPeriodMs);
#endif
	}
#else		
	// disabled the watchdog
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
    LOGI(&gSrvgwsomeipLogContext, "Watchdog is disabled");
#else
	PF_TRC_INFO( logger, "Watchdog is disabled" );
#endif
#endif
	
	dk::gw::CMsgVmf vmfBroker(&MsgIds, "srvgw_vsomeip_poc process", 3000);
	dk::gw::CVsomeipServiceGw srvgw(&MsgIds, &MsgCacheIds, &vmfBroker);

	srvgwPtr = &srvgw;
	vmfBrokerPtr = &vmfBroker;

	vmfBroker.setVsomeipServiceGw(&srvgw);
	vmfBroker.start();

	if (srvgw.init())
	{
		srvgw.start();
		ret = 0;
	}
	else
	{
		ret = 1;
	}
	
#if defined(DK_CDC_WATCHDOG_ENABLED)
	// un-register connection with cdc HealthManager
	CdcRuntime::HealthIf::Unregister();
	
#elif defined(DK_HAM_WATCHDOG_ENABLED)
	// disconnect with HAM
	WdgClient::getInstance()->disconnect();
		
#else
	// nothing
#endif

	return ret;
}

