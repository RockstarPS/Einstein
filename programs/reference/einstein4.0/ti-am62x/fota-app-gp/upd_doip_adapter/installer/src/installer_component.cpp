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
#include "installer_component.h"

/// Start of user code : Header user code for file installer_component.cpp
#include "dk_logger.h"
#include "dk_runtime_types.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <sys/socket.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <net/if.h>
#include <net/if_media.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#define AUTO_TEST    0
/// End of user code

namespace dk
{
namespace srvc
{
namespace blinstaller
{


LOG_DECLARE_CONTEXT(installerLogContext);

bool InstallerComponent::onInit()
{
    bool ret = true;

    Component::onInit();

/// Start of user code : User code for function onInit in file installer_component.cpp
    LOG_REGISTER_CONTEXT(installerLogContext, "BLIN",  "Nissan BL Installer Application", DLT_LOG_INFO);

    LOGV(&installerLogContext,"onInit");
    loadConfig();
    isoInstaller.initialize();
    mVlanOpenFailed = false;
    vlanopen();

    registerTask ( [ = ]()
    {
       poll1Sec();
    }, 2000 ); //poll 1sec
/// End of user code

    return ret;
}

bool InstallerComponent::onExit()

{
    bool ret = true;

    Component::onExit();

/// Start of user code : User code for function onExit in file installer_component.cpp
    LOGV(&installerLogContext,"onExit");
    LOG_UNREGISTER_CONTEXT(installerLogContext);
/// End of user code

    return ret;
}

bool InstallerComponent::onStart()
{
    bool ret = true;

    Component::onStart();

/// Start of user code : User code for function onStart in file installer_component.cpp
    LOGI(&installerLogContext,"onStart");
#if AUTO_TEST
    isoFilename = "/fota_cache/update_package_j32v_run1-signed.bin";
    installFlag = 1;
#endif
/// End of user code

    return ret;
}

bool InstallerComponent::onStop()
{
    bool ret = true;

    Component::onStop();

/// Start of user code : User code for function onStop in file c_bl_installer_comp.cpp
    LOGV(&installerLogContext,"onStop");
/// End of user code

    return ret;
}



void  InstallerComponent::poll1Sec()
{
   if( mVlanOpenFailed == true )
   {
       vlanopen();
       mVlanOpenFailed = false;
   }
   else
   {
       ///< do nothing
   }
}

void InstallerComponent::worker()
{
/// Start of user code : User code for function worker in file installer_component.cpp
    int32_t ret = -1;
	DoipSetParams lDkMsgDoipSetParams;
    ELinkStatus_t lLinkStatus = ELinkStatus_Down;

    if(installFlag)
    {
        isoInstallStatus = isoInstaller.getStatus();
        LOGV(&installerLogContext,"ISO Installer Status ", isoInstallStatus);

        if(ISO_Installer::Status::IDLE == isoInstallStatus)
        {
            LOGI(&installerLogContext,"Initiating Install");

            ret = isoInstaller.install(isoFilename, ISO_Installer::Slot::A);

            if(0 == ret)
            {
                LOGI(&installerLogContext,"Install Start success");
            }
            else
            {
                LOGE(&installerLogContext,"Install Start success failure");
            }
        }
        else if((ISO_Installer::Status::FAILED == isoInstallStatus) || (ISO_Installer::Status::COMPLETED == isoInstallStatus))
        {
            LOGI(&installerLogContext,"Install Completed ", isoInstallStatus);
            installFlag = 0;
            InstallerFlashStatusNotification lStatusNotification;
            lStatusNotification.status = EInstallationStatus_Passed;
            DK_RTE_Send_InstallerFlashStatusNotification(lStatusNotification);
            isoInstaller.initialize();
#if AUTO_TEST
            verifyFlag = 1;
#endif
        }
        else
        {
            // Install in progress
        }
    }

    if(verifyFlag)
    {
        verifyFlag = 0;
        LOGI(&installerLogContext,"Initiating verify");
        ret = verify();
        InstallerUdsVerifyResp lResp;
        if(0 == ret)
        {
            lResp.verifyStatus =1;
            DK_RTE_Send_InstallerUdsVerifyResp(lResp);
            LOGI(&installerLogContext,"verify success");
        }
        else
        {
            lResp.verifyStatus =0;
            DK_RTE_Send_InstallerUdsVerifyResp(lResp);
            LOGE(&installerLogContext,"verify fail");
        }
    }

    if(cancelFlag)
    {
        LOGV(&installerLogContext,"Entered for cancel thread execution");
        cancelFlag = 0;
        cancelHandler();
    }
	if(mIpVlan1set == false) 
	{
        (void) monitorVlanInterface("vlan11",  lLinkStatus );
         if(lLinkStatus == ELinkStatus_Up)
		 {
			lDkMsgDoipSetParams.isVinNumValid = false;
			lDkMsgDoipSetParams.isGidNumValid = false;
			lDkMsgDoipSetParams.isEidNumValid = false;
			lDkMsgDoipSetParams.isNetWorkConfigValid = true;
			lDkMsgDoipSetParams.isGidSyncStatusValid = false;
			lDkMsgDoipSetParams.ipConfig.ipAddressNetwork1=192;
			lDkMsgDoipSetParams.ipConfig.ipAddressNetwork2=168;
			lDkMsgDoipSetParams.ipConfig.ipAddressHost1=11;
			lDkMsgDoipSetParams.ipConfig.ipAddressHost2=2;
			lDkMsgDoipSetParams.ipConfig.portNum=13400;
			DK_RTE_Send_DoipSetParams(lDkMsgDoipSetParams); 
			mIpVlan1set = true;

		 }
	}
	
	 if(mIpVlan2set == false) 
	{
		lLinkStatus = ELinkStatus_Down;
        (void) monitorVlanInterface("vlan12",  lLinkStatus );
         if(lLinkStatus == ELinkStatus_Up)
		 {
			lDkMsgDoipSetParams.isVinNumValid = false;
			lDkMsgDoipSetParams.isGidNumValid = false;
			lDkMsgDoipSetParams.isEidNumValid = false;
			lDkMsgDoipSetParams.isNetWorkConfigValid = true;
			lDkMsgDoipSetParams.isGidSyncStatusValid = false;
			lDkMsgDoipSetParams.ipConfig.ipAddressNetwork1=192;
			lDkMsgDoipSetParams.ipConfig.ipAddressNetwork2=168;
			lDkMsgDoipSetParams.ipConfig.ipAddressHost1=12;
			lDkMsgDoipSetParams.ipConfig.ipAddressHost2=2;
			lDkMsgDoipSetParams.ipConfig.portNum=13400;
			DK_RTE_Send_DoipSetParams(lDkMsgDoipSetParams); 
			mIpVlan2set = true;
		 }
	}
/// End of user code
}

void InstallerComponent::onReceiveUdsCurrentMode(UdsCurrentMode & msg)
{
/// Start of user code : User code for function onReceiveUdsCurrentMode in file installer_component.cpp
    LOGV(&installerLogContext,"pz1aBlInstaller::onReceiveDKMsgUdsCurrentMode");
/// End of user code
}

void InstallerComponent::onReceiveUdsInstallerDidRequest(UdsInstallerDidRequest & msg)
{
/// Start of user code : User code for function onReceiveUdsInstallerDidRequest in file installer_component.cpp
    LOGV(&installerLogContext,"pz1aBlInstaller::onReceiveDkMsgUdsInstallerDidRequest");

    switch(msg.didAccessType)
    {
        case EDidAccessType_DidRead:
        {
            LOGI(&installerLogContext,"pz1aBlInstaller:Read did request received : ",msg.didId);
            switch(msg.didId)
            {
                case DID_READ_DIGEST:
                {
                    readDigestFlag = 1;
                }
                break;

                default:
                {
                    LOGE(&installerLogContext,"pz1aBlInstaller:onReceiveDkMsgUdsInstallerDidRequest unhandled did read");
                }
            }
        }
        break;

        case EDidAccessType_DidWrite:
        {
            LOGI(&installerLogContext,"pz1aBlInstaller:Write did request received : ",msg.didId);
            switch(msg.didId)
            {
                case DID_WRITE_DIGEST:
                {
                    writeDigestFlag = 1;
                }
                break;

                default:
                {
                    LOGE(&installerLogContext,"pz1aBlInstaller:onReceiveDkMsgUdsInstallerDidRequest unhandled did write");
                }
            }
        }
        break;
    }
/// End of user code
}

void InstallerComponent::onReceiveUdsInstallerFileDownloadStatus(UdsInstallerFileDownloadStatus & msg)
{
/// Start of user code : User code for function onReceiveUdsInstallerFileDownloadStatus in file installer_component.cpp
    UdsInstallerFileDownloadStatus &msg_InstallerFileDownloadStatus = (UdsInstallerFileDownloadStatus &)msg;

    LOGV(&installerLogContext,"onReceiveUdsInstallerFileDownloadStatus");

    if ((msg_InstallerFileDownloadStatus.modeOfOperation == EFileModeOfOperation_AddFile) || (msg_InstallerFileDownloadStatus.modeOfOperation == EFileModeOfOperation_ReplaceFile))
    {
        std::string reqfilename(msg_InstallerFileDownloadStatus.requestedFilenameWithPath, msg_InstallerFileDownloadStatus.requestedFilenameWithPath+msg_InstallerFileDownloadStatus.requestedFilenameWithPathLen);
        std::string tempfilename(msg_InstallerFileDownloadStatus.tempFilenameWithPath, msg_InstallerFileDownloadStatus.tempFilenameWithPath+msg_InstallerFileDownloadStatus.tempFilenameWithPathLen);
        LOGE(&installerLogContext,"temp :",tempfilename,"req :",reqfilename );
        if((access(tempfilename.c_str(), F_OK )) != -1)
        {
            isoFilename = tempfilename;
            installFlag = 1;
        }
        else
        {
            /* Access Invalid */
            LOGE(&installerLogContext,"InstallerFileDownloadStatus: Access Failure" );
        }
    }
    else
    {
        LOGE(&installerLogContext,"Unhandled mode of operation :",msg_InstallerFileDownloadStatus.modeOfOperation);
    }
/// End of user code
}

void InstallerComponent::onReceiveNetworkInterfaceStatus(NetworkInterfaceStatus & msg)
{
/// start of user code
    LOGI(&installerLogContext," Network  manager doesnt handle VLAN interfaces : ");
/// End of user code
}

void InstallerComponent::onReceiveUdsCurrentSession(UdsCurrentSession & msg)
{
/// Start of user code : User code for function onReceiveUdsCurrentSession in file installer_component.cpp
    LOGV(&installerLogContext,"pz1aBlInstaller::onReceiveDKMsgUdsCurrentSession");
/// End of user code
}

void InstallerComponent::onReceiveUdsDidPostResponseIndication(UdsDidPostResponseIndication & msg)
{
/// Start of user code : User code for function onReceiveUdsDidPostResponseIndication in file installer_component.cpp
    LOGV(&installerLogContext,"pz1aBlInstaller::onReceiveDkMsgUdsDidPostResponseIndication");
/// End of user code
}

void InstallerComponent::onReceiveUdsInstallerDigestWriteReq(UdsInstallerDigestWriteReq & msg)
{
/// Start of user code : User code for function onReceiveUdsInstallerDigestWriteReq in file installer_component.cpp
    LOGV(&installerLogContext,"pz1aBlInstaller::onReceiveDkMsgUdsInstallerDigestWriteReq");
/// End of user code
}

void InstallerComponent::onReceiveUdsInstallerDigestReadReq(UdsInstallerDigestReadReq & msg)
{
/// Start of user code : User code for function onReceiveUdsInstallerDigestReadReq in file installer_component.cpp
    LOGV(&installerLogContext,"pz1aBlInstaller::onReceiveDkMsgUdsInstallerDigestReadReq");
/// End of user code
}

void InstallerComponent::onReceiveUdsInstallerVerifyReq(UdsInstallerVerifyReq & msg)
{
/// Start of user code : User code for function onReceiveUdsInstallerVerifyReq in file installer_component.cpp
    LOGV(&installerLogContext,"pz1aBlInstaller::onReceiveDKMsgUdsInstallerVerifyReq");
    verifyFlag = 1;
/// End of user code
}

void InstallerComponent::loadConfig()
{
    uint8_t iniParserStatus = 0;
    uint8_t sectionCount = 0;

    LOGI(&installerLogContext,"Loading Installer Configurations");


    if(mIniParser.loadConfiguration(installerIniPath1))
    {

        iniParserStatus = 1;
        LOGI(&installerLogContext, "Installer ini file found in ", installerIniPath1 );
    }
    else if(mIniParser.loadConfiguration(installerIniPath2))
    {

        iniParserStatus = 1;
        LOGI(&installerLogContext, "Installer ini file found in ",  installerIniPath2);
    }

    if(iniParserStatus == 1)
    {

        std::vector<std::string> sectionsList;
        if (mIniParser.getAllSections(sectionsList))
        {
            sectionCount = sectionsList.size();
            if(sectionCount)
            {
                LOGI(&installerLogContext,"Loading configurations from ini file");
                vlanConfigDtool.name = mIniParser.getStringValue("vlan0","name");
                vlanConfigDtool.parentInterfaceName = mIniParser.getStringValue("vlan0","parentInterface");
                vlanConfigDtool.ipAddress = mIniParser.getStringValue("vlan0","ipAddress");
               vlanConfigDtool.netMask = mIniParser.getStringValue("vlan0","netmask");
                vlanConfigDtool.broadcastAddress = mIniParser.getStringValue("vlan0","broadcastAddress");
    /*uint8_t */vlanConfigDtool.priority = (uint8_t)mIniParser.getInt32Value("vlan0","priority", 0);
    /*uint16_t*/vlanConfigDtool.tag = (uint16_t)mIniParser.getInt32Value("vlan0","tag", 0);
                vlanConfigDtool.doipPort = (uint16_t)mIniParser.getInt32Value("vlan0","doipPort", 0);

                LOGI(&installerLogContext,"vlan Config name :",vlanConfigDtool.name);
                LOGI(&installerLogContext,"vlan Config parentInterfaceName :",vlanConfigDtool.parentInterfaceName);
                LOGI(&installerLogContext,"vlan Config ipAddress :",vlanConfigDtool.ipAddress);
                LOGI(&installerLogContext,"vlan Config netMask :",vlanConfigDtool.netMask);
                LOGI(&installerLogContext,"vlan Config broadcastAddress :",vlanConfigDtool.broadcastAddress);
                LOGI(&installerLogContext,"vlan Config tag :",vlanConfigDtool.tag);
                LOGI(&installerLogContext,"vlan Config priority :",vlanConfigDtool.priority);
                LOGI(&installerLogContext,"vlan Config doipPort :",vlanConfigDtool.doipPort);

                //vlan 120
                LOGI(&installerLogContext,"Loading configurations from ini file");
                vlanConfigRdiag.name = mIniParser.getStringValue("vlan1","name");
               vlanConfigRdiag.parentInterfaceName = mIniParser.getStringValue("vlan1","parentInterface");
               vlanConfigRdiag.ipAddress = mIniParser.getStringValue("vlan1","ipAddress");
                vlanConfigRdiag.netMask = mIniParser.getStringValue("vlan1","netmask");
                vlanConfigRdiag.broadcastAddress = mIniParser.getStringValue("vlan1","broadcastAddress");
    /*uint8_t */vlanConfigRdiag.priority = (uint8_t)mIniParser.getInt32Value("vlan1","priority", 0);
    /*uint16_t*/vlanConfigRdiag.tag = (uint16_t)mIniParser.getInt32Value("vlan1","tag", 0);
                vlanConfigRdiag.doipPort = (uint16_t)mIniParser.getInt32Value("vlan1","doipPort", 0);

                LOGI(&installerLogContext,"vlan Config name :",vlanConfigRdiag.name);
                LOGI(&installerLogContext,"vlan Config parentInterfaceName :",vlanConfigRdiag.parentInterfaceName);
                LOGI(&installerLogContext,"vlan Config ipAddress :",vlanConfigRdiag.ipAddress);
                LOGI(&installerLogContext,"vlan Config netMask :",vlanConfigRdiag.netMask);
                LOGI(&installerLogContext,"vlan Config broadcastAddress :",vlanConfigRdiag.broadcastAddress);
                LOGI(&installerLogContext,"vlan Config tag :",vlanConfigRdiag.tag);
                LOGI(&installerLogContext,"vlan Config priority :",vlanConfigRdiag.priority);
                LOGI(&installerLogContext,"vlan Config doipPort :",vlanConfigRdiag.doipPort);

    /*uint8_t */decryptMethod = (uint8_t)mIniParser.getInt32Value("data","decryption_method", 0);
                LOGI(&installerLogContext,"Decryption Method:",decryptMethod);


            }
            else
            {
                LOGE(&installerLogContext,"Ini File Empty");
            }
        }
    }
    else
    {
        LOGI(&installerLogContext,"Default Configuration");
    }
}

void InstallerComponent::vlanopen()
{

}

void InstallerComponent::vlanclose()
{


}

void InstallerComponent::cancelHandler()
{
    int32_t ret;;

    LOGI(&installerLogContext,"cancelHandler");

    ret = isoInstaller.abort();
    if(0 == ret)
    {
        LOGI(&installerLogContext,"Abort Success");
    }
    else
    {
        LOGE(&installerLogContext,"Abort Failed");
    }
}

int32_t InstallerComponent::verify()
{
    int32_t ret = -1;
    SSwUpdateInfo_t swUpdateInfo;
    InstallerUdsVerifyResp resp_InstallerUdsVerifyResp;

    ret = Metadata_IncrementUpdateId();
    if(0 != ret)
    {
        LOGE(&installerLogContext, "Metadata_IncrementUpdateId failed ", ret);
    }

    ret = Metadata_GetSwUpdateInfo(&swUpdateInfo);
    if(0 != ret)
    {
        LOGE(&installerLogContext, "Metadata_GetSwUpdateInfo failed ", ret);
    }

    swUpdateInfo.blUpdateTotal = swUpdateInfo.blUpdateTotal + 1;
    if(ISO_Installer::Status::COMPLETED == isoInstallStatus)
    {
        /* Make Partition A as active */
        ret = Metadata_SetActivePartition(ESwPartId_PrimaryIFS, EPartition_A, TRUE);
        if(0 != ret)
        {
            LOGE(&installerLogContext, "Metadata_SetPartitionInfo failed ", ret);
        }

        swUpdateInfo.blUpdateSuccess = swUpdateInfo.blUpdateSuccess + 1;
        resp_InstallerUdsVerifyResp.verifyStatus = true;
        DK_RTE_Send_InstallerUdsVerifyResp(resp_InstallerUdsVerifyResp);
        LOGI(&installerLogContext,"InstallerUdsVerifyResp success response sent to UDS");
    }
    else if (ISO_Installer::Status::FAILED == isoInstallStatus)
    {
        swUpdateInfo.blUpdateFail = swUpdateInfo.blUpdateFail + 1;
        resp_InstallerUdsVerifyResp.verifyStatus = false;
        DK_RTE_Send_InstallerUdsVerifyResp(resp_InstallerUdsVerifyResp);
        LOGE(&installerLogContext,"InstallerUdsVerifyResp Failure response sent to UDS");
    }
    else
    {
        LOGE(&installerLogContext, "Invalid Install status ", isoInstallStatus);
    }

    ret = Metadata_SetSwUpdateInfo(&swUpdateInfo);
    if(0 != ret)
    {
        LOGE(&installerLogContext, "Metadata_SetSwUpdateInfo failed ", ret);
    }

    return ret;
}

int8_t InstallerComponent::monitorVlanInterface(const char *pInterface, ELinkStatus_t &linkstatus )
{
	struct ifreq ifr;
	
	linkstatus = ELinkStatus_Down;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) 
	{
		LOGE(&installerLogContext, "Socket creation failed ");
    }
	else
	{
		memset(&ifr, 0, sizeof(ifr));
		strcpy(ifr.ifr_name, pInterface);

		if (ioctl(sock, SIOCGIFFLAGS, &ifr) < 0) 
		{
			LOGV(&installerLogContext, "IOCL command failed ");
		}
		else
		{
			LOGI(&installerLogContext, "IFR flags is :  ", +ifr.ifr_flags   );

			if (ifr.ifr_flags & IFF_UP )
			{
				LOGI(&installerLogContext, " VLAN interface is UP " );
				linkstatus = ELinkStatus_Up;

			} 
			else
			{
				LOGE(&installerLogContext, " VLAN interface is down" );
			}
		}	
		close(sock);
	}

    /* @smerfu - Coverity Fix */
    return 0;
}
/// Start of user code : Footer user code for file installer_component.cpp
}
}
}
/// End of user code

