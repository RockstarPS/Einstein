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
// @file        UpdLocalUpdater.hpp
// @brief       
//
//---------------------------------------------------------------------------------------------------------------------


#ifndef __UPD_LOCAL_UPDATER_HPP__
#define __UPD_LOCAL_UPDATER_HPP__

#include <sstream>
#include <mutex>
#include "UpdUpdaterTypes.hpp"


namespace Visteon
{
	namespace Update
	{

		#define UPD_TASK_SCHEDULE_DELAY		5 //ms
		#define UPD_TASK_INIT_DELAY			3000 //ms

		typedef struct
		{
			std::string hwID;
			uint32_t    maxDataSize;
		} UpdQnxComProp;


		class UpdLocalUpdater
		{
			public:
				virtual ~UpdLocalUpdater();

				static bool create(std::string updaterName, void* localProxyPrams);

				tUPDStatus getProtocolVersion(tProtocolVersion &protocolVersion);

				tUPDStatus processPackage(std::string &packageName, std::ifstream &inStream, uint32_t size);

				tUPDStatus startUpdate(tUPDBank bank);

				tUPDStatus activate(void);

				tUPDStatus postActivate(tUPDTargets targets);

				tUPDStatus rollback(void);

				tUPDStatus commit(bool sendCommitMsg = false);

				tUPDStatus cancel(void);

				tUPDStatus suspend(void);

				tUPDStatus resume(std::string &packageName, uint32_t packageSize);

				tUPDStatus verify(const tUPDVerifyReq &verifyReq);

				tUPDStatus verify(const tUPDVerifyVerReq &verifyReq);

				tUPDStatus validate(void);

				tUPDStatus enterInMode(tModeRequest mode);

				tUPDStatus getStates(tUPDStatesInfo &statesInfo);

				tUPDStatus getMetaInfo(tUPDMetaInfo &metaInfo);

				tUPDStatus getTargetMetaInfo(tUPDTargetsInfo &targetsInfo);

				tUPDStatus getTargetMetaInfo(tUPDTargetsInfoVer &targetsInfo);

				tUPDStatus copyActiveToInactive(tUPDTargets targets);

				tUPDStatus uds_service34(std::string &packageName,uint32_t size) ;
				tUPDStatus uds_service36(uint32 readSize, uint8* buffer) ;
				tUPDStatus uds_service37() ;
				void Periodic_Task(void);

				tUPDStatus setCommunicationMode(tUPDCommMode commMode); // Not used for LocalUpdater

			//  private:
				UpdLocalUpdater(std::string updaterName);

				void autoInspectSyncTask(void);

				std::string m_updaterName;
				UpdQnxComProp m_comProp;

				std::mutex m_updater_mtx;
				std::thread m_inspectSyncThread;

				bool m_is_started;
				bool m_is_cancelled;
				bool m_is_suspended;
				bool m_is_resumed;
				bool m_is_updateInProgress;

				uint32_t m_resumeOffset;
		};

	}
}

#endif //__UPD_LOCAL_UPDATER_HPP__

