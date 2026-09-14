//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
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
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.3
// Date: Tue Jul 20 14:55:07 IST 2021
// User: RKRISHN8
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef INSTALLER_COMPONENT_H
#define INSTALLER_COMPONENT_H

extern "C"
{
#include "metadata.h"
}

#include <thread>
#include <map>
#include "dk_logger.h"
//#include "dk_runtime_installer_component.h"
#include "dk_runtime_types.h"
#include "dk_runtime_parserif.h"
//#include "ISO_Installer.h"

namespace dk
{
namespace srvc
{
namespace blinstaller
{
	
	
using namespace dk::runtime;

class InstallerComponent : public dk::runtime::core::Component
{
public:
    explicit InstallerComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> *pMsgMap, const char *cmpId) : Component(pMsgMap, cmpId)
    {
    }

    ~InstallerComponent()
    {
    }

    bool onInit();
    bool onExit();
    bool onStart();
    bool onStop();
    void worker(void);

    void onReceiveNetworkInterfaceStatus(NetworkInterfaceStatus & msg);

    void onReceiveUdsInstallerFileDownloadStatus(UdsInstallerFileDownloadStatus & msg);

    void onReceiveUdsInstallerDidRequest(UdsInstallerDidRequest & msg);

    void onReceiveUdsInstallerDigestWriteReq(UdsInstallerDigestWriteReq & msg);

    void onReceiveUdsInstallerDigestReadReq(UdsInstallerDigestReadReq & msg);

    void onReceiveUdsInstallerVerifyReq(UdsInstallerVerifyReq & msg);

    void onReceiveUdsCurrentMode(UdsCurrentMode & msg);

    void onReceiveUdsDidPostResponseIndication(UdsDidPostResponseIndication & msg);

    void onReceiveUdsCurrentSession(UdsCurrentSession & msg);

private:
/// Start of user code : User code for file installer_component.h
 typedef struct _vlanConfig
    {
        std::string name;
        std::string parentInterfaceName;
        std::string ipAddress;
        std::string netMask;
        std::string broadcastAddress;
        uint16_t tag;
        uint8_t priority;
        uint16_t doipPort;
    }SVlanConfig_t;

    #define DOWNLOAD_COMPLETE 1
    #define DID_READ_DIGEST 0xFD01
    #define DID_WRITE_DIGEST 0xFD01
    
    //#define FASTMODE
    //#define SKIPDL
	bool mIpVlan1set= false;
	bool mIpVlan2set= false;

    uint8_t installFlag = 0;
	uint8_t cancelFlag = 0;
    uint8_t vlanCloseFlag = 0;
    uint8_t instResReqRespFlag = 0;
	uint8_t installerFileDownload = 0;
	uint8_t writeDigestFlag = 0;
	uint8_t readDigestFlag = 0;
	uint8_t verifyFlag = 0;
    bool mVlanOpenFailed = true;
    int installBlPackage(void);
	void cancelHandler(void);
	int verify(void);
	void poll1Sec(void);
	int8_t monitorVlanInterface(const char *pInterface, ELinkStatus_t &linkstatus );

    SVlanConfig_t vlanConfigDtool;
    SVlanConfig_t vlanConfigRdiag;
    uint8_t decryptMethod = 0; /*OPENSSL by default */
    const std::string installerIniPath1 = "/etc/installer.ini";
    const std::string installerIniPath2 = "/etc/installer.ini";
    dk::runtime::core::ParserIf mIniParser;

	ISO_Installer isoInstaller;
	std::string   isoFilename;
	int32_t       isoInstallStatus;

    void loadConfig(void);
    void vlanopen();
    void vlanclose();
/// End of user code
};


} // blinstaller
} // srvc
} // dk


#endif //INSTALLER_COMPONENT_H

