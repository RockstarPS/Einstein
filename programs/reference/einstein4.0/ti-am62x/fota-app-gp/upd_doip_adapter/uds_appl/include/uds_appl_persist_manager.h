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
#ifndef UDS_APPL_PERSIST_MANAGER_H_
#define UDS_APPL_PERSIST_MANAGER_H_

#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include<string.h>
#include <cstdint>
#include <iostream>

using namespace std;
namespace dk
{
namespace app
{
namespace udsblservices
{

///
///@brief Persistent data for  GIP UDS/Diag comp
///
typedef struct
{
	uint8_t mFD0151DTC;
	uint8_t mFD0142DTC;
}SPersistUdsInfo_t;

typedef struct
{
	uint16_t delayCounter;
	uint16_t attemptCounter1;
	uint16_t attemptCounter2;
}Scounter_t;

class CUdsPersistManager
{
	public:

	 static int32_t loadGipIntegrityChkStatus(SPersistUdsInfo_t &pDiagParams );
	 static int32_t saveGipIntegrityChkStatus(SPersistUdsInfo_t lDiagParams);
	 static int32_t loadGipIntegrityChkStatus_counter(Scounter_t &lCounter );
	 static int32_t saveGipIntegrityChkStatus_counter(Scounter_t sCounter);

	///
	/// @brief Path to store the GIP verification status.
	///
	const std::string mDiagfilePath = "/fota_cache/GipUdsParams.bin";
	const std::string mDiagcounterPath = "/fota_cache/GipUdsParams_counter.bin";


};



} // udsblservices
} // app
} // dk




#endif
