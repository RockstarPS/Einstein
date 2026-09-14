//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2023] Visteon Corporation
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
//=============================================================================
// @file        UpdLocalUpdater.cpp
// @brief       
//
//---------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <condition_variable>
extern "C" {
	#include "UPD_ITargets.h"
	#include "UPD_IUpdate.h"
	//< Deployment includes >
	#include "UPDd.h"
}

#include "UpdLocalUpdater.hpp"
#include "UPD_MessagesTypes.h"
#include "UpdUtils.hpp"
#include "UPD_IInstallation.h"


static uint8 GIP36servicesetflag = 0;
namespace Visteon
{
namespace Update
{
	#define UPDd_REQ_FIFO_SIZE 0

bool UpdLocalUpdater::create(std::string updaterName, void* localProxyPrams)
{
	bool ret = true;

	Local_ProxyParams _localProxyPrams = *(Local_ProxyParams*) localProxyPrams;

	// UpdLocalUpdater* _localUpdater = new UpdLocalUpdater(updaterName, _localProxyPrams);
	// localUpdater.reset(_localUpdater);

	return ret;
}
UpdLocalUpdater::UpdLocalUpdater(std::string updaterName)
: m_updaterName(updaterName)
, m_is_started(false)
, m_is_cancelled(false)
, m_is_suspended(false)
, m_is_resumed(false)
, m_is_updateInProgress(false)
, m_resumeOffset(0)
{
	// m_comProp.hwID = localProxyPrams.hwID;
	// m_comProp.maxDataSize = localProxyPrams.maxDataSize;

	UPDd_Initialize();

	m_inspectSyncThread = std::thread([&]()
	{
		autoInspectSyncTask();
	});
}

UpdLocalUpdater::~UpdLocalUpdater()
{
	m_is_started = false;

	if (m_inspectSyncThread.joinable())
	{
		m_inspectSyncThread.join();
	}

	while(UPDd_Shutdown() == eUPD_Pending)
	{
		UPDd_Task();
	}
}

tUPDStatus UpdLocalUpdater::getProtocolVersion(tProtocolVersion &protocolVersion)
{
	printf("\n-------UPDATER LIBRARY VERSION : %s-------\n\n", UPD_LIB_VERSION);

	protocolVersion.major = UPD_MSG_VERSION_MAJOR;
	protocolVersion.minor = UPD_MSG_VERSION_MINOR;
	protocolVersion.patch = UPD_MSG_VERSION_PATCH;

	return eUPD_Ok;
}

tUPDStatus UpdLocalUpdater::getStates(tUPDStatesInfo &statesInfo)
{
	std::lock_guard<std::mutex> lock(m_updater_mtx);

	uint8_t iTarget;
	uint8_t targetCount = UPD_ITargetCount();

	statesInfo.updateState = UPD_IUpdate_GetState();
	statesInfo.activeBank = 0U;//UPD_IUpdate_GetActiveSlot();
	statesInfo.activeTargetsStates.clear();
	statesInfo.inactiveTargetsStates.clear();

	for (iTarget=0; iTarget<targetCount; iTarget++)
	{
		statesInfo.activeTargetsStates.push_back(UPD_ITargets_GetTargetStateById(iTarget, eUPDiUpdate_BankActive));
		statesInfo.inactiveTargetsStates.push_back(UPD_ITargets_GetTargetStateById(iTarget, eUPDiUpdate_BankInactive));
	}

	printf("\nUpdLocalUpdater::getStates - Active Targets States :\n");

	int i = 0;
	for(const auto& element : statesInfo.activeTargetsStates)
	{
		printf(" [%d]=0x%04x", i++, element);
	}

	printf("\n\nUpdLocalUpdater::getStates -Inactive Targets States :\n");

	i = 0;
	for(const auto& element : statesInfo.inactiveTargetsStates)
	{
		printf(" [%d]=0x%04X", i++, element);
	}

	printf("\n\npackageOffset = %d, packageSize = %d, updateState = 0x%04X, activeBank = %s\n",
			statesInfo.installedSize, statesInfo.packageSize, statesInfo.updateState,
			((statesInfo.activeBank==0) ? "BANK A" : ((statesInfo.activeBank==1) ? "BANK B" : "BANK UNKNOWN")));

	return eUPD_Ok;
}

tUPDStatus UpdLocalUpdater::getMetaInfo(tUPDMetaInfo &metaInfo)
{
	std::lock_guard<std::mutex> lock(m_updater_mtx);

	metaInfo.targetCount = UPD_ITargetCount();
	metaInfo.queueSize = UPDd_REQ_FIFO_SIZE;
	metaInfo.serviceName = m_updaterName;
	metaInfo.hwId = m_comProp.hwID;
	metaInfo.maxDataChunkSize = UPDd_LOAD_BUFFER_SIZE;

	printf("\nUpdLocalUpdater::getMetaInfo - targetCount : %d, queueSize : %u, serviceName : %s, hwId : %s, maxChunkSz : %u\n\n",
						metaInfo.targetCount, metaInfo.queueSize, metaInfo.serviceName.c_str(), metaInfo.hwId.c_str(), metaInfo.maxDataChunkSize);

	return eUPD_Ok;
}

tUPDStatus UpdLocalUpdater::getTargetMetaInfo(tUPDTargetsInfo &targetsInfo)
{
	std::lock_guard<std::mutex> lock(m_updater_mtx);

	tUPDStatus status = eUPD_Ok;
	uint8_t TargetCount = UPD_ITargetCount();

	targetsInfo.clear();

	for (uint8_t target=0; target<TargetCount; target++)
	{
		const char *tName = UPD_ITargets_GetTargetNameById(target);

		tUPDHashInfo activeHash, inactiveHash;

		if (UPD_ITargets_GetHash(target, &activeHash) != eUPD_Ok)
		{
			status = eUPD_NotOk;
		}

		if (UPD_ITargets_GetHash(target, &inactiveHash) != eUPD_Ok)
		{
			status = eUPD_NotOk;
		}

		// std::string actHash = bytesToHexString(activeHash.pHash, activeHash.HashSize);
		// std::string inactHash = bytesToHexString(inactiveHash.pHash, inactiveHash.HashSize);

		// targetsInfo.push_back({target, tName, activeHash.HashSize, activeHash.HashType, actHash, 
		// 								inactiveHash.HashSize, inactiveHash.HashType, inactHash});
	}

	if (eUPD_Ok == status)
	{
		for(tUPDTargetInfo targetInfo : targetsInfo)
		{
			printf("UpdGenericProxy::TargetInfoResp :\ntargetId: %u, targetName: %s,\n" \
					"  activehashSize: %u,   activeHash: %s\ninactivehashSize: %u, inactiveHash: %s\n\n",
					targetInfo.targetId, targetInfo.targetName.c_str(),
					targetInfo.activehashSize, targetInfo.activeHash.c_str(),
					targetInfo.inactivehashSize, targetInfo.inactiveHash.c_str());
		}
	}

	return status;
}

tUPDStatus UpdLocalUpdater::getTargetMetaInfo(tUPDTargetsInfoVer &targetsInfo)
{
	// Not used for LocalUpdater
	(void) targetsInfo;
	return eUPD_Ok;
}

tUPDStatus UpdLocalUpdater::verify(const tUPDVerifyReq &verifyReq)
{
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;

	tUPDStatus status = eUPD_NotOk;
	uint8_t hashBuffer[32];
	tUPDHashInfo hash;

	hash.HashSize = verifyReq.hashSize;
	hash.HashType = verifyReq.hashType;
	hash.pHash = hashBuffer;

	if ( ((32*2) != verifyReq.hash.size()))// ||
			//!hexStringToBytes(verifyReq.hash, hash.pHash) )
	{
		printf("UpdLocalUpdater::verify - ERROR!!! Invalid HASH!\n");
		return eUPD_NotOk;
	}

	while ((status = UPD_ITargets_VerifyTarget(verifyReq.target, &hash)) == eUPD_Pending)
	{
		UPDd_Task();
		wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
	}

	return status;
}

tUPDStatus UpdLocalUpdater::verify(const tUPDVerifyVerReq &verifyReq)
{
	// Not used for LocalUpdater
	(void) verifyReq;
	return eUPD_Ok;
}

tUPDStatus UpdLocalUpdater::validate(void)
{
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;

	tUPDStatus status = eUPD_NotOk;

	while ((status = UPD_IUpdate_Validate()) == eUPD_Pending)
	{
		UPDd_Task();
		wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
	}

	return status;
}

tUPDStatus UpdLocalUpdater::enterInMode(tModeRequest mode)
{
	// EnterInMode not applicable for LocalUpdater
	(void) mode;
	return eUPD_Ok;
}

tUPDStatus UpdLocalUpdater::activate(void)
{
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;

	tUPDStatus status = eUPD_NotOk;

	while ((status = UPD_IUpdate_Activate()) == eUPD_Pending)
	{
		UPDd_Task();
		wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
	}

	return status;
}

tUPDStatus UpdLocalUpdater::postActivate(tUPDTargets targets)
{
	// Not used for LocalUpdater
	(void) targets;
	return eUPD_Ok;
}

tUPDStatus UpdLocalUpdater::commit(bool sendCommitMsg)
{
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;

	(void) sendCommitMsg;
	tUPDStatus status = eUPD_NotOk;

	while ((status = UPD_IUpdate_Commit()) == eUPD_Pending)
	{
		UPDd_Task();
		wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
	}

	m_is_cancelled = false;
	m_is_suspended = false;
	m_is_resumed = false;
	m_is_updateInProgress = false;
	m_resumeOffset = 0 ;

	return status;
}

tUPDStatus UpdLocalUpdater::rollback(void)
{
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;

	tUPDStatus status = eUPD_NotOk;

	while ((status = UPD_IUpdate_Rollback()) == eUPD_Pending)
	{
		UPDd_Task();
		wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
	}

	return status;
}

tUPDStatus UpdLocalUpdater::startUpdate(tUPDBank bank)
{
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;

	tUPDStatus status = eUPD_NotOk;

	while ((status = UPD_IUpdate_StartUPDate(eUPDiUpdate_BankInactive)) == eUPD_Pending)
	{
		UPDd_Task();
		wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
	}

	return status;
}

tUPDStatus UpdLocalUpdater::cancel(void)
{
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;

	tUPDStatus status = eUPD_NotOk;

	m_is_cancelled = true;

	// TODO:: Check if the while is causing any issue
	while (m_is_updateInProgress)
	{
		wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_STATUS_CHECK_DELAY));
	}

	while ((status = UPD_IUpdate_Terminate()) == eUPD_Pending)
	{
		UPDd_Task();
		wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
	}

	m_is_cancelled = false;
	m_is_suspended = false;
	m_is_resumed = false;
	m_is_updateInProgress = false;
	m_resumeOffset = 0 ;

	return status;
}

tUPDStatus UpdLocalUpdater::suspend(void)
{
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;

	tUPDStatus status = eUPD_NotOk;

	m_is_suspended = true;

	// TODO:: Check if the while is causing any issue
	while (m_is_updateInProgress)
	{
		wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_STATUS_CHECK_DELAY));
	}

	// Suspend and shutdown are same
	// while ((status = UPD_Suspend()) == eUPD_Pending)
	{
		UPDd_Task();
		wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
	}

	m_is_resumed = false;
	m_resumeOffset = 0;

	return status;
}

tUPDStatus UpdLocalUpdater::resume(std::string &packageName, uint32_t packageSize)
{
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;

	tUPDStatus status = eUPD_NotOk;
	uint32 Offset;

	while ((status = UPD_IInstallation_Resume(packageName.c_str(), packageSize, &Offset)) == eUPD_Pending)
	{
		UPDd_Task();
		wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
	}

	if (status == eUPD_Ok)
	{
		m_is_resumed = true;
		m_resumeOffset = Offset;

		printf("UpdLocalUpdater::resume - Update resumed for package: %s, at offset: %u\n", packageName.c_str(), m_resumeOffset);
	}
	else
	{
		printf("UpdLocalUpdater::resume - Resuming update failed for package: %s\n", packageName.c_str());
	}

	return status;
}

tUPDStatus UpdLocalUpdater::copyActiveToInactive(tUPDTargets targets)
{
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;

	tUPDStatus status = eUPD_NotOk;
	bool is_failed = false;

	for (auto target : targets)
	{
		while ((status = UPD_IInstallation_CopyToInactive(target)) == eUPD_Pending)
		{
			UPDd_Task();
			wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
		}

		if (status != eUPD_Ok)
		{
			is_failed = true;
			printf("UpdLocalUpdater::copyActiveToInactive - Syncing failed for target %u\n", target);
		}
	}

	if (is_failed)
	{
		status = eUPD_NotOk;
	}

	return status;
}

#define exit_processPackage(_status_) { m_is_updateInProgress = false; return _status_; }


tUPDStatus UpdLocalUpdater::uds_service34(std::string &packageName,uint32_t size){
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;
	tUPDStatus status = eUPD_NotOk;
	//tUPDiSessionID sessionID = 0;
	status = UPD_IInstallation_TransferStart(packageName.c_str(), size);
	//if(status == E_OK)
	//{
	//	GIP36servicesetflag = 1;
	//}
	return status;
}
tUPDStatus UpdLocalUpdater::uds_service36(uint32 readSize, uint8* buffer){ //read size-> msg.len , buffer -> msg.data
	
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;
	tUPDStatus status = eUPD_NotOk;

	while ((status = UPD_IInstallation_TransferData(readSize, buffer)) == eUPD_Pending){
		UPDd_Task();
		wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
	}
		// TODO:: Add retry if one chunk write is failed
	if (status != eUPD_Ok){
		printf("ProcessPackage - ERRROR!!! Package Installation failed\n");
	}
	return status;
}
tUPDStatus UpdLocalUpdater::uds_service37(){
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;
	//tUPDiSessionID sessionID = 0;
	
	tUPDStatus status = eUPD_NotOk;
	printf("upd_TE start\n");
	status = UPD_IInstallation_TransferExit();
	printf("upd_TE end\n");

	// if (status != eUPD_Ok){
	// 	printf("ProcessPackage - ERROR!!! Exiting data tansfer failed\n");
	// 	exit_processPackage(eUPD_NotOk);
	// }
	// exit_processPackage(status);
	printf("status is :%d\n", status);
	return status;
}



tUPDStatus UpdLocalUpdater::processPackage(std::string &packageName, std::ifstream &stream, uint32_t size)
{
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;

	printf("Inside processPackage: packageName %s, size %u\n", packageName.c_str(), size);

	tUPDStatus status = eUPD_NotOk;

	if (m_is_updateInProgress)
	{
		printf("ProcessPackage - Package processing already in progress!\n");
		return eUPD_NotOk;
	}

	m_is_cancelled = false;
	m_is_suspended = false;
	m_is_updateInProgress = true;

	#define exit_processPackage(_status_) { m_is_updateInProgress = false; return _status_; }

	if (!stream.is_open())
	{
		printf("ProcessPackage - Opening stream failed!\n");
		exit_processPackage(eUPD_NotOk);
	}

	if (!size)
	{
		printf("ProcessPackage - Invalid size!\n");
		exit_processPackage(eUPD_NotOk);
	}

	const uint32_t streamStartOffset = stream.tellg();
	stream.seekg (0, stream.end);
	uint32_t endOffset = stream.tellg();
	stream.seekg(streamStartOffset);
	uint32_t streamSize = (endOffset - streamStartOffset);

	if (streamSize < size)
	{
		printf("ProcessPackage - Stream size (%u) is less than rquested size (%u)!\n", streamSize, size);
		exit_processPackage(eUPD_NotOk);
	}

	uint32_t currOffset = m_resumeOffset;
	//tUPDiSessionID sessionID = 0;
	uint8_t buffer[m_comProp.maxDataSize];
	//uint8_t *buffer = new uint8_t[m_comProp.maxDataSize];

	if (!m_is_resumed)
	{
		while ((status = UPD_IInstallation_TransferStart(packageName.c_str(), size)) == eUPD_Pending)
		{
			UPDd_Task();
			wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
		}

		if (status != eUPD_Ok)
		{
			printf("ProcessPackage - Starting data transfer failed!\n");
			exit_processPackage(eUPD_NotOk);
		}
	}

	printf("ProcessPackage - Starting data Writing\n");

	while (!m_is_suspended && !m_is_cancelled && stream.good() && currOffset < size)
	{
		uint32_t absoluteOffset = streamStartOffset + currOffset;
		uint32_t remainingSize = size - currOffset;

		stream.seekg(absoluteOffset); // Required only for resume (streamStartOffset+currOffset)

		if (!stream.good() || stream.tellg() != absoluteOffset)
		{
			printf("ProcessPackage - Setting seek position failed! (requested %u, actual %ld)\n", absoluteOffset, (long)stream.tellg());
			exit_processPackage(eUPD_NotOk);
		}

		//printf("ProcessPackage - streamStartOffset: %u, absoluteOffset: %u, currOffset: %u, remainingSize: %u, size: %u\n",
									//streamStartOffset, absoluteOffset, currOffset, remainingSize, size);

		uint32_t readSize = stream.read((char*)buffer, std::min(remainingSize, m_comProp.maxDataSize)).gcount();

		while ((status = UPD_IInstallation_TransferData(readSize, buffer)) == eUPD_Pending)
		{
			UPDd_Task();
			wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
		}

		// TODO:: Add retry if one chunk write is failed
		if (status != eUPD_Ok)
		{
			printf("ProcessPackage - ERRROR!!! Package Installation failed\n");

			// TODO:: Check to put resume false in exit process fn
			m_is_resumed = false;
			m_resumeOffset = 0;
			exit_processPackage(eUPD_NotOk);
		}

		currOffset += readSize;
	}

	// Resetting for next proces pkg call for next target
	m_is_resumed = false;
	m_resumeOffset = 0;

	printf("ProcessPackage - Finished data Writing\n");

	if ((m_is_cancelled || m_is_suspended))
	{
		printf("ProcessPackage - Installation cancelled/suspended\n");
		exit_processPackage(eUPD_Ok);
	}
	else
	{
		while ((status = UPD_IInstallation_TransferExit()) == eUPD_Pending)
		{
			UPDd_Task();
			wait_cond.wait_for(lock, std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
		}

		if (status != eUPD_Ok)
		{
			printf("ProcessPackage - ERROR!!! Exiting data tansfer failed\n");
			exit_processPackage(eUPD_NotOk);
		}
	}

	exit_processPackage(status);
}

tUPDStatus UpdLocalUpdater::setCommunicationMode(tUPDCommMode commMode)
{
	// Not used for LocalUpdater
	(void) commMode;
	return eUPD_Ok;
}

void UpdLocalUpdater::autoInspectSyncTask()
{
	m_is_started = true;
	std::this_thread::sleep_for(std::chrono::milliseconds(UPD_TASK_INIT_DELAY));

	//TODO:: Add thread priority control to lowest here with posix thread apis
	while (m_is_started)
	{
		while (true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(UPD_TASK_SCHEDULE_DELAY));
			std::lock_guard<std::mutex> lock(m_updater_mtx);

			UPDd_Task();

			/*if (eUPD_eWlIdle == UPD_GetWorkload())
			{
				break;
			}*/
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(UPDd_TASK_PERIOD_MS));
	}
}

}
}
