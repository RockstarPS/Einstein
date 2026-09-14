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

#include <dk_logger.h>
#include "dk_runtime_parserif.h"
#include "network_manager.h"
#include "network_manager_tja1101.h"

namespace dk
{
namespace srvc
{
namespace platform
{

LOG_IMPORT_CONTEXT(gNMLogContext);

///
/// @brief   Poll PHY status
///
void CNetworkPhyEnetTja1101::pollPhyEnetStatusInMs(void)
{
    readPhyLinkStatus();
    readCableQuality();
}

///
/// @brief   Read Link Status
///
void CNetworkPhyEnetTja1101::readPhyLinkStatus(void)
{
    std::vector<uint32_t> l_outdata;
    uint8_t lSubFcnChk;
    uint16 regValue;
    EnetRegResp lLinkStatus = {0U};

    ///< Link status is read at address 0x0001
    lSubFcnChk = mENETregisterTJA1101Class.read_register(0x00U, 0x00U, 0x01U, l_outdata);
    if(lSubFcnChk == 0U)
    {
        regValue = static_cast<uint16_t> (l_outdata.at(0U));

        lLinkStatus.respLen = 0x01U;
        lLinkStatus.cmd = EnetReqType_linkStatus ;

        if(((regValue >> 2U) & 1U) == 1U)
        {
            lLinkStatus.response[0] = ELinkStatus_Up;
            mFault = 0x00U;
            mFaultStatus = 0x00U;
        }
        else
        {
            lLinkStatus.response[0] = ELinkStatus_Down;
        }
     
        if(lLinkStatus.response[0] != mLinkStatus)
        {
            mLinkStatus = lLinkStatus.response[0];
            DK_RTE_Send_EnetRegResp(lLinkStatus);
            LOGI(&gNMLogContext,  "Current Link status is  0:UP, 1:down  -->   ", lLinkStatus.response[0]);
        }
    }
    else
    {
        LOGE(&gNMLogContext, "Unable to access ethernet Registers 0x01: Return status : =>   ", lSubFcnChk);
    }
}

///
/// @brief   Read Cable quality
///
void CNetworkPhyEnetTja1101::readCableQuality(void)
{
    std::vector<uint32_t> lOutdata;
    uint16 regValue;
    uint8_t lSubFcnChk;
    static uint8_t lFaultDetectValue = 0xFFU;

    if((mLinkStatus == ELinkStatus_Down) )
    {
        /*Run TDR procedure (Cable test)*/
        (void)runTDRprocedure(true);

        /*TDR procedure is done. Read External status register 0x19(25) to get cable fault*/
        lSubFcnChk = mENETregisterTJA1101Class.read_register(0X00U, 0x00U, 0x19U, lOutdata);
        if(lSubFcnChk == 0U)
        {
            regValue = static_cast<uint16_t> (lOutdata.at(0U));

            if(((regValue >> 7U) & 0xFFU) == 3U)
            {
                mFault = 0x00U;
                mFaultStatus = 0x00U;
                LOGV(&gNMLogContext, "Connected to active link partner");
            }
            else if(((regValue >> 7U) & 0xFFU) == 2U)
            {
                mFault = 0xBBU;
                mFaultStatus = 0x01U;
                LOGV(&gNMLogContext, "Short fault detected");
            }
            else if(((regValue >> 7U) & 0xFFU) == 1U)
            {
                mFault = 0xAAU;
                mFaultStatus = 0x01U;
                LOGV(&gNMLogContext, "Open fault detected");
            }
            else
            {
                mFault = 0x00U;
                mFaultStatus = 0x00U;
                LOGV(&gNMLogContext, "No fault detected");
            }

            if(lFaultDetectValue != ((regValue >> 7U) & 0xFFU))
            {
                lFaultDetectValue = static_cast<uint8_t>((regValue >> 7U) & 0xFFU);
                LOGI(&gNMLogContext, "Register value at address 0x19 ", regValue);
                LOGI(&gNMLogContext, "Current fault 0:No fault detected, 1:Open Fault, 2:Short Fault, 3:Connected to active link partner --> ", lFaultDetectValue);
            }
        }
        else
        {
            LOGI(&gNMLogContext, "Unable to read Register 0x19. Return status : =>   ", lSubFcnChk);
        }

        /*Stop TDR procedure (Cable test)*/
        (void)runTDRprocedure(false);   
    }
    else
    {
       /*Reset if Link is UP*/
       lFaultDetectValue = 0xFFU;
    }

    /*Read SQI value*/
    readSQIvalue();

}

///
///@brief Read SQI value
///
void CNetworkPhyEnetTja1101::readSQIvalue(void)
{
    std::vector<uint32_t> l_outdata;
    uint16 regValue;
    uint8_t lSubFcnChk;

    /*Read Communication status register 0x17(23) to get SQI value*/
    lSubFcnChk = mENETregisterTJA1101Class.read_register(0x00U, 0x00U, 0x17U, l_outdata);
    if(lSubFcnChk == 0U)
    {
        regValue = static_cast<uint16_t> (l_outdata.at(0U));
        mCurrentSQI = static_cast<uint8_t>((regValue >> 5U ) & 0x07U);

        /*Update best SQI value*/
        if(mCurrentSQI > mBestSQI)
        {
            mBestSQI = mCurrentSQI;
        }

        /*Update Worst SQI value*/
        if(mCurrentSQI < mWorstSQI)
        {
            mWorstSQI = mCurrentSQI;
        }

        LOGV(&gNMLogContext, "SQI Current Value", "Register value at the addres[0x0017] is  : ", regValue);
        LOGV(&gNMLogContext, "SQI Current Value", "Current sqi value  is  : ", mCurrentSQI);
    }
    else
    {
        LOGE(&gNMLogContext, "Unable to access SQI Register 0x17: Return status : =>   ", lSubFcnChk);
    }
}

///
///@brief Get Link status
///
void CNetworkPhyEnetTja1101::getLinkStatus(void)
{
    EnetRegResp lLinkStatus = {0U};

    lLinkStatus.respLen = 0x01U;
    lLinkStatus.cmd = EnetReqType_linkStatus ;
    lLinkStatus.response[0] = mLinkStatus;

    DK_RTE_Send_EnetRegResp(lLinkStatus);
}

///
///@brief Get Fault status
///
void CNetworkPhyEnetTja1101::getFaultStatus()
{
    EnetRegResp lFaultStatus = {0U};

    lFaultStatus.respLen = 0x02U;
    lFaultStatus.cmd = EnetReqType_FaultStatus ;

    lFaultStatus.response[0] = mFaultStatus;
    lFaultStatus.response[1] = mFault;

    DK_RTE_Send_EnetRegResp(lFaultStatus);
}

///
///@brief Get Current SQI value
///
void CNetworkPhyEnetTja1101::getSqiCurrentValue()
{   
    EnetRegResp lSqiValue = {0U};
 
    lSqiValue.respLen = 0x01U;
    lSqiValue.cmd = EnetReqType_SqiVal ;
    lSqiValue.response[0] = mCurrentSQI;

    LOGI(&gNMLogContext, "SQI Current Value is: ", mCurrentSQI);
    DK_RTE_Send_EnetRegResp(lSqiValue);
}

///
///@brief Get Worst SQI value
///
void CNetworkPhyEnetTja1101::getSqiWorstValue() 
{
    EnetRegResp lSqiWorstValue = {0U};

    lSqiWorstValue.respLen = 0x01U;
    lSqiWorstValue.cmd = EnetReqType_WorstSqiVal;
    lSqiWorstValue.response[0] = mWorstSQI;

    LOGI(&gNMLogContext, "SQI Worst Value is: ", mWorstSQI );

    DK_RTE_Send_EnetRegResp(lSqiWorstValue);
}

///
///@brief Get Best SQI value
///
void CNetworkPhyEnetTja1101::getSqiBestValue()
{
    EnetRegResp lSqiBestValue = {0U};

    lSqiBestValue.respLen = 0x01U;
    lSqiBestValue.cmd = EnetReqType_BestSqiVal;
    lSqiBestValue.response[0]= mBestSQI;

    LOGI(&gNMLogContext, "SQI Best Value is: ", mBestSQI );
    DK_RTE_Send_EnetRegResp(lSqiBestValue);
}

///
///@brief Run TDR procedure
///
bool CNetworkPhyEnetTja1101::runTDRprocedure(const bool enable)
{
    std::vector<uint32_t> lOutdata;
    uint16 regValue;
    uint8_t lSubFcnChk;
    bool lret = true;

    if(enable == true)
    {
        /*Read and write Extended Control register 0x11 (17) to start Cable test (TDR Procedure)*/
        lSubFcnChk = mENETregisterTJA1101Class.read_register(0X0U /*dummy*/,0x00U,0x11U,lOutdata); 
        if(lSubFcnChk == 0U)
        {
            regValue = static_cast<uint16_t> (lOutdata.at(0U));
            regValue |= static_cast<uint16_t>(1U << 5U);
            regValue &= static_cast<uint16_t>(~(1U << 15U));
            lSubFcnChk = mENETregisterTJA1101Class.write_register(0x0U, 0x00U, 0x11U, static_cast<uint8_t>((regValue >> 8U ) & 0xFFU), static_cast<uint8_t>(regValue & 0xFFU), 0xFFU, 0xFFU);
            if(lSubFcnChk != 0U)
            {
                LOGE(&gNMLogContext, "Unable to write to register 0x11: Return status : =>   ", lSubFcnChk);
                lret = false;
            }
        }
        else
        {
            LOGE(&gNMLogContext, "Unable to Read to register 0x11: Return status : =>   ", lSubFcnChk);
            lret = false;
        }
    }
    else
    {
        /*Read and write External control register 0x11(17) to disable cable test(TDR Procedure)*/
        lSubFcnChk = mENETregisterTJA1101Class.read_register(0X0U /*dummy*/, 0x00U, 0x11U, lOutdata);
        if(lSubFcnChk == 0U)
        {
            regValue = static_cast<uint16_t> (lOutdata.at(0U));
            regValue &= static_cast<uint16_t>(~(1U << 5U));
            regValue |= static_cast<uint16_t>(1U << 15U);

            lSubFcnChk = mENETregisterTJA1101Class.write_register(0x0U, 0x00U, 0x11U, static_cast<uint8_t>((regValue >> 8U ) & 0xFFU), static_cast<uint8_t>(regValue & 0xFFU), 0xFFU, 0xFFU);
            if(lSubFcnChk != 0U)
            {
                LOGE(&gNMLogContext, "Unable to write to register 0x11: Return status : =>   ", lSubFcnChk);
                lret = false;
            }
        }
        else
        {
            LOGE(&gNMLogContext, "Unable to read register 0x11: Return status : =>   ", lSubFcnChk);
            lret = false;
        }
    }

    return lret;
}

void CNetworkPhyEnetTja1101::getResetStatus()
{
    std::vector<uint32_t> l_outdata;
    uint8_t lSubFcnChk;
    uint16 regValue;
    EnetRegResp lResetStatus = {0U};

    ///< Reset status is read at address 0x0000
    lSubFcnChk = mENETregisterTJA1101Class.read_register(0x00U, 0x00U, 0x00U, l_outdata);
    if(lSubFcnChk == 0U)
    {
        regValue = static_cast<uint16_t> (l_outdata.at(0U));

        lResetStatus.respLen = 0x01U;
        lResetStatus.cmd = EnetReqType_Reset ;

        if(((regValue >> 15U) & 0x01U) == 1U)
        {
            LOGI(&gNMLogContext, "Reset detected  ", "Register value at the addres[0x0018] is  : ", regValue);
            lResetStatus.response[0] = 0x01U; ///PHY Reset
        }
        else
        {
            LOGI(&gNMLogContext, "Normal operation  ", "Register value at the addres[0x0018] is  : ", regValue);
            lResetStatus.response[0] = 0x00U; ///Normal operation
        }

        DK_RTE_Send_EnetRegResp(lResetStatus);
    }
    else
    {
        LOGE(&gNMLogContext, "Unable to access ethernet Registers : Return status : =>   ", lSubFcnChk);
    }

}

///
/// @brief   Master Slave Status
///
void CNetworkPhyEnetTja1101::getMasterSlaveStatus()
{
    std::vector<uint32_t> l_outdata;
    uint8_t lSubFcnChk;
    uint16 regValue;
    EnetRegResp lMasterSlaveStatus = {0U};

    ///< Master slave is read at address 0x0012
    lSubFcnChk = mENETregisterTJA1101Class.read_register(0x00U, 0x00U, 0x12U, l_outdata);
    if(lSubFcnChk == 0U)
    {
        regValue = static_cast<uint16_t> (l_outdata.at(0U));

        lMasterSlaveStatus.respLen = 0x01U;
        lMasterSlaveStatus.cmd = EnetReqType_masterSlaveStatus ;

        if(((regValue >> 15U) & 0x01U) == 1U)
        {
            LOGI(&gNMLogContext, "PHY configured as master  ", "Register value at the addres[0x0012] is  : ", regValue);
            lMasterSlaveStatus.response[0] = 0x01U;
        }
        else
        {
            LOGI(&gNMLogContext, "PHY configured as slave  ", "Register value at the addres[0x0012] is  : ", regValue);
            lMasterSlaveStatus.response[0] = 0x00U;
        }

        DK_RTE_Send_EnetRegResp(lMasterSlaveStatus);
    }
    else
    {
        LOGE(&gNMLogContext, "Unable to access ethernet Registers : Return status : =>   ", lSubFcnChk);
    }

}

void CNetworkPhyEnetTja1101::writeResetStatus()
{
    LOGE(&gNMLogContext, "Write reset status");
    EnetRegResp lWriteResetStatus = {0U};
    lWriteResetStatus.cmd = EnetReqType_Reset;
    lWriteResetStatus.respLen = 0x01U;

    (void)usleep(500U);
    // Reset Procdure for ETH_PHY
    (void)system("ifconfig fec0 down");
    LOGI(&gNMLogContext, "DOWN");
    (void)usleep(500U);
    (void)system("ifconfig fec0 up");
    LOGI(&gNMLogContext, "UP");
    lWriteResetStatus.response[0] = 0x01U; ///< reset success
    DK_RTE_Send_EnetRegResp(lWriteResetStatus);
}

///
/// @brief   Request handler to  compute Enet based requests.
///
void CNetworkPhyEnetTja1101::enetReqHandler(EnetRegReq const  & msg)
{
    if(msg.mode == EnetReqMode_Read)
    {
        switch(msg.cmd)
        {
            case EnetReqType_Reset:
                getResetStatus();
                break;
            case EnetReqType_linkStatus:
                getLinkStatus();
                break;
            case EnetReqType_SqiVal:
                getSqiCurrentValue();
                break;
            case EnetReqType_WorstSqiVal:
                getSqiWorstValue();
                break;
            case EnetReqType_BestSqiVal:
                getSqiBestValue();
                break;
            case EnetReqType_FaultStatus:
                getFaultStatus();
                break;
            case EnetReqType_CableStatus:
                LOGE(&gNMLogContext, "Support not provided for cable status in TJA1101");
                break;
            case EnetReqType_masterSlaveStatus:
                getMasterSlaveStatus();
                break;
            default:
                LOGE(&gNMLogContext, "Unsupported Command",msg.cmd);
                break;
        }
    }
    else if(msg.mode == EnetReqMode_Write)
    {
        if(msg.cmd == EnetReqType_Reset)
        {
            writeResetStatus();
        }
        else
        {
            LOGE(&gNMLogContext, "Unsupported Command",msg.cmd);
        }
    }
    else
    {
        LOGE(&gNMLogContext, "Incorrect mode",msg.mode);
    }
}

}
}
}






