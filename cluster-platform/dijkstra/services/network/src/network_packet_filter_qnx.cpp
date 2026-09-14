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
//---------------------------------------------------------------------------------------------------------------------
///
/// @file network_packet_filter_qnx.cpp
///
//---------------------------------------------------------------------------------------------------------------------
#include <dk_logger.h>
#include "network_packet_filter_qnx.h"
#include "dk_runtime_network_manager_component.h"
#include <sys/wait.h>
#include "DKOsalProcess.h"

namespace dk
{
namespace srvc
{
namespace platform
{

using namespace dk::runtime::core;
using namespace dk::osal;

LOG_IMPORT_CONTEXT(gNMLogContext);
void CNetworkPacketFilterQnx::enableFilter(void)
{
    char* arglistPfctl[] = { const_cast<char*>("pfctl"), const_cast<char*>("-e"), NULL };
    /// Enable pfctl
    if (invokePfctl(arglistPfctl) == true)
    {
        /// If pfctl enabled successfully, update the filter status as EFilterStatus_Enabled
        mfilterStatus = CNetworkPacketFilterIf::EfilterStatus_t::EFilterStatus_Enabled;
    }
}

void CNetworkPacketFilterQnx::disableFilter(void)
{
    char *arglistPfctl[] = { const_cast<char*>("-d"), NULL };
    /// disable pfctl
    if (invokePfctl(arglistPfctl) == true)
    {
        /// If pfctl disabled successfully, update the filter status as EFilterStatus_Disabled
        mfilterStatus = CNetworkPacketFilterIf::EfilterStatus_t::EFilterStatus_Disabled;
    }
}

void CNetworkPacketFilterQnx::setFilterConfiguration(const std::string &configFile)
{
    if (configFile.length() > 0U)
    {
        /// copy the pf config file path.
        mConfigfilePath = configFile;
        /// set the config file to pfctl.
        char* arglistPfctl1[] = { const_cast<char*>("pfctl"), const_cast<char*>("-f"), &mConfigfilePath[0], NULL };
        (void)invokePfctl(arglistPfctl1);
    }
}

CNetworkPacketFilterIf::EfilterStatus_t CNetworkPacketFilterQnx::getFilterStatus(void) const
{
    /// return current filter status.
    return mfilterStatus;
}

bool CNetworkPacketFilterQnx::invokePfctl(char *const *const arglist)
{
    const std::string fileNamePfctl = "/system/sbin/pfctl";
    bool retStatus = true;

    /// Check if the pfctl binary is accessible
    if(access(fileNamePfctl.c_str(),F_OK) == 0 )
    {
        int pStatus=0;
        pid_t pid;
        /// Execute the requested command.
        pid = Process::createProcess(fileNamePfctl.c_str(), arglist);
        /// wait for the process to terminate.
        if (waitpid(pid,&pStatus,0) == -1)
        {
            retStatus = false;
        }
        else
        {
            /// check if the process is terminated normally
            if(WIFEXITED( pStatus ) != false )
            {
                retStatus = false;
                LOGE(&gNMLogContext, "Process terminate status", pStatus);
            }
        }
    }
    else
    {
        retStatus = false;
    }
    /// return command execution status.
    return retStatus;
}

} // platform
} // srvc
} // dk