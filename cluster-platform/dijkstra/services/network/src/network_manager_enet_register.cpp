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
// Date: Fri Jul 16 13:23:11 IST 2021
// User: IRAJENDR
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------


#include <sys/socket.h>
#include <sys/sockio.h>
#include <net/if.h>
#include <devctl.h>
#include <iterator>     // std::back_inserter
#include <vector>
#include <dk_logger.h>
#include "dk_runtime_network_manager_component.h"
#include <network_manager_enet_register.h>
#include <spawn.h>
#include <ethernet_register_read_write.h>
#include <ethernet_register_read_writeV2.h>

namespace dk
{
namespace srvc
{
namespace platform
{

using namespace std;

LOG_IMPORT_CONTEXT(gNMLogContext);


void  CNetworkPhyEnet::pollPhyEnetStatusInMs()
{
    LOGV(&gNMLogContext, "Poll Network Status in ENET registers  ");
    readPhyLinkStatus();
    readCableQuality();
}


///
/// @brief   Read UCL link status
///
void CNetworkPhyEnet::readPhyLinkStatus( )
{
    uint16 lRespData = 0U;
    bool lTDRProcedRun = false;
    EthlinkDownStatus lEthLinkDownStatus = {0U};

    if(WRITE_STATUS_OK == MMD1_read_register(0x0001U, &lRespData) )
    {
        if(((lRespData >> 2U) & 0x01U) == 1U)
        {
            LOGV(&gNMLogContext, "Interface UP  ", "Register value at the addres[0x1001] is  : ", lRespData);
            lEthLinkDownStatus.ethernetLinkStatus = ELinkStatus_Up;
            bTDRProcedRunStatus = false;
        }
        else
        {
            LOGV(&gNMLogContext, "Interface Down  ", "Register value at the address[0x1001] is : ", lRespData);
            lEthLinkDownStatus.ethernetLinkStatus = ELinkStatus_Down;
            /*Enable flag to run TDR procedure */
            lTDRProcedRun = true;
        }

        /*Run TDR procedure only one time after link is down*/
        if((lTDRProcedRun == true) && (bTDRProcedRunStatus == false))
        {
            TdrProcedure();
            bTDRProcedRunStatus = true;
        }

        if(lEthLinkDownStatus.ethernetLinkStatus != mlinkStatus )
        {
            LOGI(&gNMLogContext, "Current Link status is  0 -> UP 1-> down  :   ", lEthLinkDownStatus.ethernetLinkStatus );
            mlinkStatus = lEthLinkDownStatus.ethernetLinkStatus ;
        }

        DK_RTE_Send_EthlinkDownStatus(lEthLinkDownStatus);
    }
    else
    {
        LOGV(&gNMLogContext, "Unable to access ethernet Registers ");
    }
}

///
/// @brief   Read Cable quality
///
void CNetworkPhyEnet::readCableQuality( )
{
    uint16 lRespData = 0U;
    NotifyNetworkEthStatus lNetworkMsg = {0x0U};
    uint8 lFaultDetected = 0x0U;

    lNetworkMsg.Fault = FaultType_NoFaultDetected;
    lNetworkMsg.FaultStatus = FaultStatusType_OK;
    lNetworkMsg.ETH_SQIValue = 0U;

    if(mlinkStatus == ELinkStatus_Down ) /*Link is Down*/
    {
        ///< Read cable quality at address 0x310
        if(WRITE_STATUS_OK == MMD1F_read_register(0x0310U, &lRespData))
        {
            LOGV(&gNMLogContext,"Register value at the address[0x0310] ,open fault", lRespData);

            lNetworkMsg.FaultStatus = FaultStatusType_NOK;
            lNetworkMsg.Fault= FaultType_BEthConnLoss_BusOff;

            if( ((( lRespData >> 7U ) & 0x1U) != 0) || ((( lRespData >> 8U ) & 0x1U) !=0))
            {
                lFaultDetected = 1U;
                LOGV(&gNMLogContext, "Fault detected at the Cable  ",   "Register value at the address[0X310] is  : ", lRespData);
            }

            if(lFaultDetected == 1U)
            {
                if( (( lRespData >> 6U ) & 0x1U) != 0)               {
                    lNetworkMsg.Fault= FaultType_BEthConnLoss_OC;
                    LOGV(&gNMLogContext, "Open Circuit Reported  ",  "Register value at the address[0X310] is  : ", lRespData);
                }
                else
                {
                    LOGV(&gNMLogContext, "Short circuit reported ",  "Register value at the address[0X310] is  : ", lRespData);
                }
            }
        }
        else
        {
            LOGV(&gNMLogContext, "Unable to access ethernet Register value at address[0x0310] ");
        }
    }
    else /*Link is UP*/
    {
        /*Read SQI level at address 0x871*/
        if(WRITE_STATUS_OK == MMD1F_read_register(0x0871U,&lRespData))
        {
            uint16_t lMask;
            lMask = createMask(1U,3U);
            lNetworkMsg.ETH_SQIValue = static_cast<uint16_t>((lRespData & lMask) >> 1U);
            LOGV(&gNMLogContext, "Current SQI value is  ","Register value at the addres[0x0871] is  : ", lNetworkMsg.ETH_SQIValue );
        }
        else
        {
            LOGV(&gNMLogContext, "Unable to access ethernet Register value at address[0x0871]");
        }
    }

    DK_RTE_Send_NotifyNetworkEthStatus(lNetworkMsg);
}

uint16_t CNetworkPhyEnet::createMask(const uint16_t left, const uint16_t right )
{
    uint16_t res = 0U;

    for (uint16_t idx=left; idx<=right; idx++)
    {
       res |= static_cast<uint16_t>(1U << idx);
    }

    return res;
}

uint16_t CNetworkPhyEnet::enetReqHandler(EnetRegReq const  & msg)
{

    ///< ENET Reg command to enable test mode
    if(msg.cmd == 0xAU)
    {
        enableEthTestModes(msg);
    }
    else if (msg.cmd == 0xBU)
    {
        enableEthernet();
        LOGI(&gNMLogContext, "Run network script   and enable ethernet interface : =>   ");

    }
    else if(msg.cmd == 0xCU)
    {
        disableEthernet();
        LOGI(&gNMLogContext, "Disable ethernet interface : =>   ");

    }
    else if(msg.cmd == 0xDU)
    {
        TdrProcedure();
        LOGI(&gNMLogContext, "Run TDR Procedure : =>   ");

    }
    else
    {
        LOGE(&gNMLogContext, "Invalid command : =>   ", msg.cmd);
    }
    return true;
}
void CNetworkPhyEnet::enableEthernet( )
{
    int ret = -1;
    int status = -1;
    pid_t tempPid = -1;
    char *cmd[1];

    cmd[0]= NULL;
    ret = posix_spawn(&tempPid, const_cast<char*>("/system/bin/network_up.sh"), NULL, NULL, cmd, environ);

    if(ret < 0)
    {
        LOGE(&gNMLogContext,"Unable to execute ethernet script");
    }

    ret = waitpid(tempPid, &status, 0);
    if(ret == -1)
    {
        LOGE(&gNMLogContext,"waitpid failure :", WEXITSTATUS ( status ));
    }
}


void CNetworkPhyEnet::disableEthernet( )
{
    int ret = -1;
    int status = -1;
    pid_t tempPid = -1;
    char *cmd[1];
    cmd[0]= NULL;

    ret = posix_spawn(&tempPid, const_cast<char*>("/system/bin/network_dn.sh"), NULL, NULL, cmd, environ);

    if(ret < 0)
    {
        LOGE(&gNMLogContext,"Unable to execute ethernet script");
    }

    ret = waitpid(tempPid, &status, 0);
    if(ret == -1)
    {
        LOGE(&gNMLogContext,"waitpid failure :", WEXITSTATUS ( status ));
    }

}

///
/// @brief Enable ethernet test  modes
///
void CNetworkPhyEnet::enableEthTestModes(EnetRegReq const  & msg )
{
    uint16 lRespData =0U;
    uint16 lRespData1 =0U;
    if( msg.mode == EnetReqMode_Write)
    {
        switch (msg.data[0] )
        {
            case 1: ///< test mode 1
            {
                (void) MMD1_read_register(0x0836U,&lRespData1);
                LOGE(&gNMLogContext,"Test Mode 1 Register value before writing   :",lRespData1);

                LOGI(&gNMLogContext, "Entered test mode 1 : =>   ");
                (void)MMD1_write_register(0x0836U,0x2000U);
                (void)MMD1_read_register(0x0836U,&lRespData);
                LOGE(&gNMLogContext,"Test Mode 1 Register value after writing   :",lRespData);
            }
            break;
            case 2:///< test mode 2
            {
                (void)MMD1_read_register(0x0001U,&lRespData1);
                LOGE(&gNMLogContext,"Link down  status value before writing   :",lRespData1);
                (void)MMD1_write_register(0x0834U,0x8001U);
                (void) sleep(1U);
                (void)MMD1_read_register(0x0001U,&lRespData1);
                LOGE(&gNMLogContext,"Link down  status value after writing   :",lRespData1);
                (void)MMD1_write_register(0x0836U,0x4000U);
                LOGI(&gNMLogContext, "Entered test mode 2 : =>   ");
            }
            break;
            case 3: ///< test mode 3
            {

                (void)MMD1_read_register(0x0001U,&lRespData1);
                LOGE(&gNMLogContext,"Link down  status value before writing   :",lRespData1);
                (void)MMD1_write_register(0x0834U,0x8001U);
                (void) sleep(1U);
                (void)MMD1_read_register(0x0001U,&lRespData1);
                LOGE(&gNMLogContext,"Link down  status value after writing   :",lRespData1);
                (void)MMD1_write_register(0x0836U,0x8000U);
                LOGI(&gNMLogContext, "Entered test mode 3 : =>   ");
            }
            break;
            case 4: ///< test mode 4
            {
                (void)MMD1_read_register(0x0001U,&lRespData1);
                LOGE(&gNMLogContext,"Link down  status value before writing   :",lRespData1);
                (void)MMD1_write_register(0x0834U,0x8001U);
                (void) sleep(1U);
                (void) MMD1_read_register(0x0001U,&lRespData1);
                LOGE(&gNMLogContext,"Link down  status value after writing   :",lRespData1);
                (void)MMD1_write_register(0x0836U,0xA000U);
                LOGI(&gNMLogContext, "Entered test mode 4 : =>   ");
            }
            break;
            default:
            {
                LOGE(&gNMLogContext, "Invalid Test mode received : =>   ", msg.data[0]);
            }
            break;
        };
    }
    else
    {
        LOGE(&gNMLogContext, "Invalid command : =>   ");
    }

}

///
/// @brief   Read TDR Procedure
///
void CNetworkPhyEnet::TdrProcedure( )
{

    LOGI(&gNMLogContext, "Run TdrProcedure  ");

    (void) MMD1_write_register(0x1834U,0x8001U);

    (void) MMD1F_write_register(0x0523U,0x0001U);

    (void) MMD1F_write_register(0x0827U,0x4800U);

    (void) MMD1F_write_register(0x0301U,0x1701U);

    (void) MMD1F_write_register(0x0303U,0x023DU);

    (void) MMD1F_write_register(0x0305U,0x0015U);

    (void) MMD1F_write_register(0x0306U,0x001AU);

    (void) MMD1F_write_register(0x001FU,0x4000U);

    (void) MMD1F_write_register(0x0523U,0x0000U);

    (void) MMD1F_write_register(0x001FU,0x0000U);

    (void) MMD1F_write_register(0x001EU,0x8000U);


}
}
}
}
