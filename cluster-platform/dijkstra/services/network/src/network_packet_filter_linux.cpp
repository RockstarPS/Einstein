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
//---------------------------------------------------------------------------------------------------------------------
///
/// @file network_packet_filter_qnx.cpp
///
//---------------------------------------------------------------------------------------------------------------------
#include <cstdio>
#include <sys/wait.h>
#include <dk_logger.h>
#include "network_packet_filter_linux.h"
#include "dk_runtime_network_manager_component.h"
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
void CNetworkPacketFilterLinux::enableFilter(void)
{
    char *arglistPfctl[] = {const_cast<char*>("iptables-restore"), &mConfigfilePath[0], NULL };
    char *pPath = const_cast<char*>("/usr/sbin/iptables-restore") ;
    
    /// Enable pfctl
    if (invokeIpTables(pPath, arglistPfctl) == true)
    {
        /// If pfctl enabled successfully, update the filter status as EFilterStatus_Enabled
        mfilterStatus = CNetworkPacketFilterIf::EfilterStatus_t::EFilterStatus_Enabled;
    }
}



void CNetworkPacketFilterLinux::disableFilter(void)
{
    char *arglistPfctl[4][50] = {
                                 {const_cast<char*>("iptables"), const_cast<char*>("-P"), const_cast<char*>("INPUT"), const_cast<char*>("ACCEPT"), NULL },
                                 {const_cast<char*>("iptables"), const_cast<char*>("-P"), const_cast<char*>("OUTPUT"), const_cast<char*>("ACCEPT"), NULL },
                                 {const_cast<char*>("iptables"), const_cast<char*>("-P"), const_cast<char*>("FORWARD"), const_cast<char*>("ACCEPT"), NULL },
                                 {const_cast<char*>("iptables"), const_cast<char*>("-F"), NULL }
                                };

    char *pPath = const_cast<char*>("/usr/sbin/iptables") ;
    uint8_t index ;

    for (index = 0U; index < 4U ; index ++)
    {
        if (invokeIpTables(pPath, &arglistPfctl[index][0]) != true)
        {
            break ;   
        }
    }

    if(index == 4)
    {
        /// If pfctl disabled successfully, update the filter status as EFilterStatus_Disabled
        mfilterStatus = CNetworkPacketFilterIf::EfilterStatus_t::EFilterStatus_Disabled;
    }
}

void CNetworkPacketFilterLinux::setFilterConfiguration(const std::string &configFile)
{
    if (configFile.length() > 0U)
    {
        // copy the pf config file path.
        mConfigfilePath = configFile;
        // set the config file to pfctl.
    }
}

CNetworkPacketFilterIf::EfilterStatus_t CNetworkPacketFilterLinux::getFilterStatus(void) const
{
    /// return current filter status.
    return mfilterStatus;
}

bool CNetworkPacketFilterLinux::invokeIpTables(const char * pName, char *const *const arglist)
{
    bool retStatus = true;

    /// Check if the binary is accessible
    if(access(pName,F_OK) == 0 )
    {
        int pStatus=0;
        pid_t pid;
        /// Execute the requested command.
        pid = Process::createProcess(pName, arglist);
        /// wait for the process to terminate.
        if (waitpid(pid,&pStatus,0) == -1)
        {
            retStatus = false;
        }
        else
        {
            /// check if the process is terminated normally - if non zero it termintaed properly 
            if(WIFEXITED( pStatus ) == 0)
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