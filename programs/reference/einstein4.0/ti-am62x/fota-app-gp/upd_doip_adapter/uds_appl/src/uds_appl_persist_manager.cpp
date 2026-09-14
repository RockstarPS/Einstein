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

#include <stdio.h>
#include <stdlib.h>
#include "uds_appl_persist_manager.h"
#include "dk_runtime_uds_appl_component.h"

using namespace std;

namespace dk
{
namespace app
{
namespace udsblservices
{


LOG_IMPORT_CONTEXT(gUdsBlServicesLogContext);


CUdsPersistManager oCUdsPersistManagerInst;
///
/// @brief This method saves GIP Integrity  Check Status.
///         '10' - Not tested
///         '00' - Tested and verification is OK
///			'01' - Tested and verification failed
/// @param[in] lDiagParams-> Send diag params to store in persistent memory.

 int32_t CUdsPersistManager::loadGipIntegrityChkStatus(SPersistUdsInfo_t &pDiagParams )
 {
		FILE *fp;
		int32_t count = 0;

		if((fp = fopen((const char *)oCUdsPersistManagerInst.mDiagfilePath.c_str(), "rb")) != NULL)
		{
			count = fread(static_cast<void*> (&pDiagParams), sizeof(SPersistUdsInfo_t), 1, fp);
			LOGI(&gUdsBlServicesLogContext,"read elements: ", count);
			fclose(fp);
		}
		else
		{
			LOGW(&gUdsBlServicesLogContext,"fopen failed ", oCUdsPersistManagerInst.mDiagfilePath.c_str());
		}

		return count;

 }
 ///
 /// @brief This method loads GIP Integrity
 ///
 /// @param[in/out] pDiagParams load diagparams from persistent memory.
 /// @param[in] serviceId requested service identifier.

 int32_t CUdsPersistManager::saveGipIntegrityChkStatus(SPersistUdsInfo_t lDiagParams)
 {
	FILE *fp;
	int32_t count = 0;

	if( (fp = fopen((const char *)oCUdsPersistManagerInst.mDiagfilePath.c_str(), "wb")) != NULL)
	{
		count = fwrite(static_cast<const void*>(&lDiagParams), sizeof(SPersistUdsInfo_t), 1, fp);
		if(1 == count)
		{
			LOGI(&gUdsBlServicesLogContext,"fwrite successful for ", oCUdsPersistManagerInst.mDiagfilePath.c_str());
		}
		else
		{
			LOGE(&gUdsBlServicesLogContext,"fwrite failed for ", oCUdsPersistManagerInst.mDiagfilePath.c_str());
		}
		fclose(fp);
	}
	else
	{
		LOGE(&gUdsBlServicesLogContext,"fopen error for ", oCUdsPersistManagerInst.mDiagfilePath.c_str());
	}

	return count;
 }

int32_t CUdsPersistManager::loadGipIntegrityChkStatus_counter(Scounter_t &lCounter )
{
		FILE *fp;
		int32_t count = 0;

		if((fp = fopen((const char *)oCUdsPersistManagerInst.mDiagcounterPath.c_str(), "rb")) != NULL)
		{
			count = fread(static_cast<void*> (&lCounter), sizeof(Scounter_t), 1, fp);
			LOGI(&gUdsBlServicesLogContext,"read elements: ", count);
			fclose(fp);
		}
		else
		{
			LOGW(&gUdsBlServicesLogContext,"fopen failed ", oCUdsPersistManagerInst.mDiagcounterPath.c_str());
		}

		return count;


}
 int32_t CUdsPersistManager::saveGipIntegrityChkStatus_counter(Scounter_t sCounter)
{
	FILE *fp;
	int32_t count = 0;

	if( (fp = fopen((const char *)oCUdsPersistManagerInst.mDiagcounterPath.c_str(), "wb")) != NULL)
	{
		count = fwrite(static_cast<const void*>(&sCounter), sizeof(Scounter_t), 1, fp);
		if(1 == count)
		{
			LOGI(&gUdsBlServicesLogContext,"fwrite successful for ", oCUdsPersistManagerInst.mDiagcounterPath.c_str());
		}
		else
		{
			LOGE(&gUdsBlServicesLogContext,"fwrite failed for ", oCUdsPersistManagerInst.mDiagcounterPath.c_str());
		}
		fclose(fp);
	}
	else
	{
		LOGE(&gUdsBlServicesLogContext,"fopen error for ", oCUdsPersistManagerInst.mDiagcounterPath.c_str());
	}

	return count;


}




} // udsblservices
} // app
} // dk

