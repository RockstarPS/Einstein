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

#ifndef ART_MSG_CMSGVMF_HPP
#define ART_MSG_CMSGVMF_HPP

#include <string>
#include <mutex>
#include <vector>
#include <set>
#include <chrono>
#include <thread>
#include "dk_runtime2_cmsg.hpp"
#include "dk_runtime2_cfifo.hpp"
#include "dk_runtime2_csemaphore.hpp"
#include "compat/vsomeip/primitive_types.hpp"
#include "nw_vmf.h"
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED

#else
  #include "OsalWrapperC++/Trace/inc/Tracing.hpp"
#endif

#define POWER_GROUP_VIP					220
#define POWER_SYSTEM_STATE_CHANGE_VMF	1			// ScPwSytemStateChange
#define POWER_DI_STATE_CHANGE_VMF		5			// ScPwDIDomainStateChangeReq
#define POWER_IVI_STATE_CHANGE_VMF		6			// ScPwIVIDomainStateChangeReq
#define POWER_SOC_RESTART_REQ_VMF		7			// ScPwDomainRestartReq

#define POWER_GROUP_SOC					221
#define DI_DOMAIN_ID 					1
#define IVI_DOMAIN_ID					2
#define POWER_SOC_STATE_VMF				1			// ScPwDomainStateChange
#define POWER_SOC_RESTART_RES_VMF		10			// ScPwDomainRestartResp
#define IVI_POWER_STATE_FULL_RUN		7
#define IVI_POWER_STATE_SYSTEM_IDLE		6

namespace dk{
namespace gw{

class CVsomeipServiceGw;

class  CMsgVmf : public dk::runtime2::core::CMsg
{
private:
	CMsgVmf();
	CMsgVmf(const CMsgVmf&);
	CMsgVmf& operator = (const CMsgVmf&);
public:
    CMsgVmf(std::vector<std::pair<vsomeip::service_t, vsomeip::method_t>>* _pMsgIds,const char * _prcName,uint32_t _timeout);

    virtual ~CMsgVmf();

	void printStatInfo();
    ART_EXPORT void stop();
    ART_EXPORT void start();
    ART_EXPORT void txMsg(vsomeip::byte_t *data, vsomeip::length_t size, uint8_t grId, uint8_t evId );
public:
    void setVsomeipServiceGw(CVsomeipServiceGw* _pVsomeipServiceGw);
private:
    void onRx(dk::runtime2::core::MsgDeserializer & _m);
	void registerVmf();
    void unregisterVmf();
    void rxDispatch();
    void rxProcess();
    std::shared_ptr<dk::runtime2::core::MsgDeserializer> rxVmfMessage(vmf_client_id_t vmf_client_id);

     vmf_basic_msg_big_t   rxMsgBuffer;
     vmf_client_id_t vmfCliId;
     std::string prcName;
     bool running;
     bool vmfRdy;


     dk::runtime2::core::cfifo<dk::runtime2::core::MsgDeserializer> rxq;
     dk::runtime2::core::CSemaphore sem;

     std::set<uint8_t> msgGroups;

     mutable std::mutex mutex;

     std::thread dispatch;
     std::thread pullMsg;
	 std::thread statinfo;

     std::set<uint16_t> msgIds;
     CVsomeipServiceGw* pVsomeipServiceGw;
	
	 uint64_t nNofVmfMsgReceived;
	 uint64_t nNofSomeipMsgSend;
	 uint64_t nNofSomeipMsgReceived;
	 uint64_t nNofVmfMsgSend;
	 
    // PF_TRC_LOGGER_DECLARE(logger);
     
	 uint32_t timeout;
	 
	 struct {
	 	uint8_t currentState;
	 }DIstate;
	 
	 struct {
	 	uint8_t currentState;
	 	uint8_t isTransitedForDisplayOff;
	 	uint8_t isRestarted;
	 	uint8_t isFactResetRebootReqd;
	 }IVIstate;
	 
	 struct {
	 	uint8_t oldState;
	 	uint8_t currentState;	 	
	 }VIPSystemStateChange;
	 
	 struct {
	 	uint8_t oldState;
	 	uint8_t currentState;	 	
	 }DIStateChange;
	 
	 struct {
	 	uint8_t oldState;
	 	uint8_t currentState;	 	
	 }IVIStateChange;
	 
};

}   // namespace gw
}   // namespace dk

#endif // ART_MSG_CMSGVMF_HPP
