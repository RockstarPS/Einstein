//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2019] Visteon Corporation
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

#include "system_state.h"
#include "dk_runtime_messages.h"
#include "DKOsalProcess.h"
#include "dk_bspal_sys_shutdown.h"


LOG_IMPORT_CONTEXT(gSSMLogContext);

#define UCL_E_LINK_UP ((sint32) -50)
#define UCL_E_LINK_DOWN ((sint32) -51)

using namespace dk::runtime::core;

void SystemState::ShutdownFinalTimerListener::onTimeout ( const dk::osal::Timer &timer )
{
    int32_t l_return_S32;

    LOGW(&gSSMLogContext, "Final State");

    l_return_S32 = dk_bspal_sys_shutdown (  ESysShutdown_Shutdown, "system_shutdown" );
    if(l_return_S32 == -1)
    {
        LOGE(&gSSMLogContext, "Error while shutdown!");
    }
}

SystemState::SystemState() : mSystemState(ESystemState_Off),
                             mShutdownFinalCbk(),
                             mShutdownFinalTimer(mShutdownFinalCbk)
{

}

std::string SystemState::enumToString(int state) const {
    auto it = mEnumToStr.find(state);
    if (it != mEnumToStr.end())
        return it->second;
    return "----";
}


bool SystemState::onInit()
{
    LOGV(&gSSMLogContext, "Enter");
    
    if (loadConfiguration())
    {
        std::vector<std::string> fullRunCompList;
        std::vector<std::string> keyList;
        
        const std::string sectionName = "SystemStateConfiguration";
        mPowerStateMessagePeriodicityMs = static_cast<uint32_t>(mParserObj.getInt32Value(sectionName, "PowerStateMessagePeriodicityMs", static_cast<int32_t>(mcPowerStateMessagePeriodicityMs)));
        mDomainId = static_cast<uint32_t>(mParserObj.getInt32Value(sectionName, "DomainId", static_cast<int32_t>(mcDomainId)));
        mShutdownFinalTimeoutMs = static_cast<uint32_t>(mParserObj.getInt32Value(sectionName, "ShutdownFinalTimeoutMs", static_cast<int32_t>(mcShutdownFinalTimeoutMs)));
        
        if(true == mParserObj.getAllValuesForKey(sectionName, "FullRunComponentTransitionList", fullRunCompList))
        {
            std::stringstream fullRunCompListStream(fullRunCompList[0]);
            uint32_t idx;
            while (fullRunCompListStream >> idx)
            {
                SCompStateRecord_t compStateRecord;
                compStateRecord.compId = static_cast<uint8_t>(idx);
                compStateRecord.compState = ECompState_Init;
                mFullRunCompList.push_back(compStateRecord);
                
                if (static_cast<char>(fullRunCompListStream.peek()) == ',')
                {
                    (void)fullRunCompListStream.ignore();
                }
            }
        }
        if (mParserObj.getAllKeysFromSection("States", keyList))
        {
            for (size_t i = 0; i < keyList.size(); ++i)
            {
                // keyList[i] will be "0", "1", "2", ...
                const char* value = mParserObj.getStringValue("States", keyList[i]);
                if (value != nullptr)
                {
                    mEnumToStr[std::stoi(keyList[i])] = value;
                }
            }
        }
    }
    else
    {
        mPowerStateMessagePeriodicityMs = mcPowerStateMessagePeriodicityMs;
        mDomainId = mcDomainId;
    }
    
    mSystemStateBroadcastTimer = static_cast<int32_t>(mPowerStateMessagePeriodicityMs);
    
    LOGV(&gSSMLogContext, "PowerStateMessagePeriodicityMs: ", mPowerStateMessagePeriodicityMs);
    LOGV(&gSSMLogContext, "DomainId: ", mDomainId);
    for(uint32_t i = 0U; i < mFullRunCompList.size(); i++)
    {
        LOGV(&gSSMLogContext, "FullRunComponentTransitionList: ", std::to_string(static_cast<int32_t>(mFullRunCompList[i].compId)));
    }

    LOGV(&gSSMLogContext, "ShutdownFinalTimeoutMs: ", mShutdownFinalTimeoutMs);

    return true;
}

bool SystemState::onExit()
{

    LOGV(&gSSMLogContext, "Enter");
    return true;
}

bool SystemState::onStart()
{
    LOGV(&gSSMLogContext, "Enter");

    requestStateChange(ESystemState_Startup);
    return true;
}

bool SystemState::onStop()
{
    LOGV(&gSSMLogContext, "Enter");
    return true;
}

void SystemState::worker()
{
}

EDomainId_t SystemState::getDomainId() const
{    
    return static_cast<uint8_t>(mDomainId);
}

void SystemState::requestStateChange(const ESystemState_t state)
{
    LOGV(&gSSMLogContext, "Enter");
    LOGI(&gSSMLogContext, "Requested State: ", state , "- " ,enumToString(state).c_str());
    LOGI(&gSSMLogContext, "Current State: ", mSystemState, "- " ,enumToString(mSystemState).c_str());

    const ESystemState_t prevSystemState = mSystemState;

    switch (state)
    {
    case ESystemState_Off:
        if ( ESystemState_Shutdown == mSystemState )
        {
            mShutdownFinalTimer.stop();
            mSystemState = ESystemState_Off;
        }
        break;
    case ESystemState_Startup:
        if ( ( ESystemState_Shutdown == mSystemState ) || ( ESystemState_Off == mSystemState )  )
        {    
            if (ESystemState_Shutdown == mSystemState)
            {
                mShutdownFinalTimer.stop();
            }

            mSystemState = ESystemState_Startup;
        }
        break;
    case ESystemState_Up:
        if ( ( ESystemState_Startup == mSystemState ) || (ESystemState_Minimal == mSystemState ) || (ESystemState_Meet == mSystemState ) )
        {
            mSystemState = ESystemState_Up;
        }
        break;
    case ESystemState_FullRun:
        if ( ESystemState_Up == mSystemState )
        {
            if(true == checkIfFullRunConditionSatified())
            {
                mSystemState = ESystemState_FullRun;
            }
        }
        break;
    case ESystemState_Minimal:
        if ( ( ESystemState_Up == mSystemState ) || ( ESystemState_FullRun == mSystemState ) )
        {    
            mSystemState = ESystemState_Minimal;
        }
        break;
    case ESystemState_Meet:
        if ( ( ESystemState_Up == mSystemState ) || ( ESystemState_FullRun == mSystemState ) )
        {    
            mSystemState = ESystemState_Meet;
        }
        break;    
    case ESystemState_Shutdown:
        if ( ( ESystemState_Up == mSystemState ) || ( ESystemState_FullRun == mSystemState ) || (ESystemState_Minimal == mSystemState ) || (ESystemState_Meet == mSystemState ))
        {
            if( true == checkIfShutdownConditionSatified() )
            {
                mShutdownFinalTimer.start(mShutdownFinalTimeoutMs);
                mSystemState = ESystemState_Shutdown;   
            }
            else
            {
                mSystemState = ESystemState_PrepareShutdown;
                // Start Shutdown timer
                mSystemStateShutdownTimer = mcShutdownTimeoutMs;
            }
        }
        else if (ESystemState_PrepareShutdown == mSystemState )
        {
            if( true == checkIfShutdownConditionSatified() )
            {
                mShutdownFinalTimer.start(mShutdownFinalTimeoutMs);
                mSystemState = ESystemState_Shutdown;   
            }
        }
        else
        {
            /*DO nothing*/
        }
        break;
    default:
        break;
    }
    
    if (prevSystemState != mSystemState)
    {
        LOGI(&gSSMLogContext, "New State: ", mSystemState , "- " ,enumToString(mSystemState).c_str());
        sendCurrentSystemState();
    }
    else
    {
        LOGW(&gSSMLogContext, "Invalid State Change Request: ",state, "- " ,enumToString(state).c_str());

    }
}

void SystemState::requestWakeLock(const uint8_t compId, const uint8_t enable, const uint32_t requestedLockTimeMs)
{
    LOGV(&gSSMLogContext, "WakeLock ", enable, ", ", std::to_string(static_cast<int32_t>(compId)), ", ", requestedLockTimeMs);

    if ((mSystemState == ESystemState_Up) || (mSystemState == ESystemState_FullRun))
    {
        uint32_t numWakeLocks = getNumberOfActiveWakeLocks();
        if (enable)
        {
            if (0U < numWakeLocks)
            {
                // Remove previous wakelock owned by this component
                (void)removeWakeLockByCompId(compId);
            }
            // Add new wake lock
            numWakeLocks = addWakeLock(compId, requestedLockTimeMs);
            LOGI(&gSSMLogContext, "WakeLockCounter ", numWakeLocks);
        }
        else
        {
            if (0U < numWakeLocks)
            {
                numWakeLocks = removeWakeLockByCompId(compId);
                LOGI(&gSSMLogContext, "WakeLockCounter ", numWakeLocks);
            }
            else
            {
                LOGW(&gSSMLogContext, "No active wakelocks");
            }
        }
        
        sendKeepSystemAwake(); //Send Notification
    }
    else
    {
        LOGW(&gSSMLogContext, "Received wakelock request in state other than ESystemState_Up");
    }

    sendCurrentSystemState();
}

void SystemState::setCommLinkStatus(const sint32 linkState)
{
    LOGI(&gSSMLogContext, "Link State ", linkState);

    if (UCL_E_LINK_UP == linkState)
    {
        requestStateChange(ESystemState_Up);
    }
}

void SystemState::sendCurrentSystemState(void)
{
    PowerSystemState msg = {0U};
    msg.domainId = static_cast<uint8_t>(mDomainId);
    msg.state = mSystemState;

    DK_RTE_Send_PowerSystemState(msg);
}

void SystemState::sendExtendShutdownTime(void)
{
    PowerExtendShutdownTime msg = {0U};
    msg.domainId = static_cast<uint8_t>(mDomainId) ;
    msg.timeoutMs = static_cast<uint32_t>(mcExtendShutdownTimeoutMs);
    DK_RTE_Send_PowerExtendShutdownTime(msg);
}

void SystemState::sendKeepSystemAwake(void)
{
    uint32_t wakeLockTimeout = 0U;
    const uint64_t timeNow = static_cast<uint32_t>(std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1U));

    PowerKeepSystemAwake msg = {0U};
    msg.domainId = static_cast<uint8_t>(mDomainId) ;
    msg.timeoutMs = wakeLockTimeout;

    const std::lock_guard<std::mutex> guard(mWakeLockListMutex);
    if (mActiveWakeLockList.size() > 0U)
    {
        for (auto wakeLockRecord = mActiveWakeLockList.begin(); wakeLockRecord != mActiveWakeLockList.end(); ++wakeLockRecord)
        {
            wakeLockTimeout = static_cast<uint32_t>(wakeLockRecord->expiresAt - timeNow);
            if(msg.timeoutMs < wakeLockTimeout)
            {
                 msg.timeoutMs = wakeLockTimeout;
            }
        }
    }
    
    DK_RTE_Send_PowerKeepSystemAwake(msg);
}

void SystemState::periodicTask(const uint16_t durationMs)
{
    const uint32_t numWakeLocks = getNumberOfActiveWakeLocks();
    if (0U < numWakeLocks)
    {
        const uint64_t timeNow = static_cast<uint64_t>(std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1U));
        if (numWakeLocks != removeExpiredWakeLocks(timeNow))
        {
            sendCurrentSystemState();
        }
    }
    
    // Run PowerState Broadcast timer
    if(mSystemStateBroadcastTimer > 0)
    {
        mSystemStateBroadcastTimer -= static_cast<int32_t>(durationMs);
    }
    else
    {
        sendCurrentSystemState();
        mSystemStateBroadcastTimer = static_cast<int32_t>(mPowerStateMessagePeriodicityMs);
    }
    
    // Run PowerState Shutdown timer
    if(mSystemState == ESystemState_PrepareShutdown)
    {
        if(true == checkIfShutdownConditionSatified())
        {
            requestStateChange(ESystemState_Shutdown);
        }
        else
        {
            if(mSystemStateShutdownTimer > 0)
            {
                mSystemStateShutdownTimer -= static_cast<int32_t>(durationMs);
            }
            else
            {
                sendExtendShutdownTime();
                mSystemStateShutdownTimer = mcExtendShutdownTimeoutMs;
            }
        }
    }
}

void SystemState::sendStatusReport()
{
    HealthStatusReport msg = {0U};

    msg.timestamp = static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());

    std::string statusStr = "{";
    statusStr += "\"Component \" : \"system_state\",";
    statusStr += "\"SystemState\" : " + std::to_string(static_cast<int32_t>(mSystemState)) + ",";
    if (0U < getNumberOfActiveWakeLocks())
    {
        const std::lock_guard<std::mutex> guard(mWakeLockListMutex);
        statusStr += "\"WakeLockList\" : [";
        for (auto wakeLockRecord = mActiveWakeLockList.begin(); wakeLockRecord != mActiveWakeLockList.end(); ++wakeLockRecord)
        {
            statusStr += "{\"compId\":" + std::to_string(static_cast<int32_t>(wakeLockRecord->compId)) + ",";
            statusStr += "\"expiresAt\":" + std::to_string(wakeLockRecord->expiresAt) + "},";
        }
        statusStr.pop_back();
        statusStr += "]";
    }
    statusStr += "}";
    msg.dataLen = static_cast<uint16_t>(statusStr.length());
    (void)strncpy(reinterpret_cast<char *>(&msg.data[0]), statusStr.c_str(), static_cast<uint64_t>(msg.dataLen));

    LOGI(&gSSMLogContext, "timestamp: ", msg.timestamp);
    LOGI(&gSSMLogContext, "dataLen: ", msg.dataLen);
    const std::string str (reinterpret_cast<char *>(&msg.data[0]) , msg.dataLen);

    LOGI(&gSSMLogContext,"data: ", str);

    DK_RTE_Send_HealthStatusReport(msg);
}

uint8_t SystemState::getNumberOfActiveWakeLocks()
{
    const std::lock_guard<std::mutex> guard(mWakeLockListMutex);
    return static_cast<uint8_t>(mActiveWakeLockList.size());
}

uint8_t SystemState::removeWakeLockByCompId(const uint8_t compId)
{
    const std::lock_guard<std::mutex> guard(mWakeLockListMutex);
    if (mActiveWakeLockList.size() > 0U)
    {
        auto wakeLockRecord = mActiveWakeLockList.begin();
        while(wakeLockRecord != mActiveWakeLockList.end())
        {
            if (wakeLockRecord->compId == compId)
            {
                LOGI(&gSSMLogContext, "Removing wakelock for ", std::to_string(static_cast<int32_t>(compId)));
                wakeLockRecord = mActiveWakeLockList.erase(wakeLockRecord);
            }
            else
            {
                ++wakeLockRecord;
            }
        }
    }

    return static_cast<uint8_t>(mActiveWakeLockList.size());
}

uint8_t SystemState::removeExpiredWakeLocks(const uint64_t timeNow)
{
    const std::lock_guard<std::mutex> guard(mWakeLockListMutex);

    auto wakeLockRecord = mActiveWakeLockList.begin();
    while(wakeLockRecord != mActiveWakeLockList.end())
    {
        if (wakeLockRecord->expiresAt < timeNow)
        {
            LOGI(&gSSMLogContext, "Wakelock expired for component id ", std::to_string(static_cast<int32_t>(wakeLockRecord->compId)));
            wakeLockRecord = mActiveWakeLockList.erase(wakeLockRecord);
        }
        else
        {
            ++wakeLockRecord;
        }
    }

    return static_cast<uint8_t>(mActiveWakeLockList.size());
}

uint8_t SystemState::addWakeLock(const uint8_t compId, const uint32_t requestedLockTimeMs)
{
    const std::lock_guard<std::mutex> guard(mWakeLockListMutex);
    SWakeLockRecord_t wakeLockRecord;
    LOGI(&gSSMLogContext, "Adding wakelock for ", std::to_string(static_cast<int32_t>(compId)), " with duration ", requestedLockTimeMs);
    wakeLockRecord.compId = compId;
    wakeLockRecord.expiresAt = static_cast<uint64_t>(requestedLockTimeMs) + static_cast<uint64_t>(std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1U));
    mActiveWakeLockList.push_back(wakeLockRecord);
    return static_cast<uint8_t>(mActiveWakeLockList.size());
}

void SystemState::setCompState(const uint8_t compId, const ECompState_t compState)
{
    for(uint32_t i = 0U; i < mFullRunCompList.size(); i++)
    {
        if(mFullRunCompList[i].compId == compId)
        {
            mFullRunCompList[i].compState = compState;
            LOGV(&gSSMLogContext, "setCompState: ", std::to_string(static_cast<int32_t>(mFullRunCompList[i].compId)), " to ", std::to_string(static_cast<int32_t>(mFullRunCompList[i].compState)));
        }
    }
    
    // Check if we need to move to full run
    if(ESystemState_Up == mSystemState)
    {
        requestStateChange(ESystemState_FullRun);
    }   
}

bool SystemState::checkIfFullRunConditionSatified()
{
    bool enterFullRun = true;
    
    for(uint32_t i = 0U; i < mFullRunCompList.size(); i++)
    {
        if(mFullRunCompList[i].compState != ECompState_Run)
        {
            enterFullRun = false;
        }
    }

    return enterFullRun;
}

bool SystemState::checkIfShutdownConditionSatified()
{
    bool enterShutdown = true;
    
    for(uint32_t i = 0U; i < mFullRunCompList.size(); i++)
    {
        if(mFullRunCompList[i].compState != ECompState_Shutdown)
        {
            enterShutdown = false;
        }
    }
    
    if(0U < getNumberOfActiveWakeLocks())
    {
        enterShutdown = false;
    }

    return enterShutdown;
}

bool SystemState::loadConfiguration()
{
    bool configFound = false;

    if (mParserObj.loadConfiguration(std::string("./system_state.ini")))
    {
        configFound = true;
    }
    else if (mParserObj.loadConfiguration(std::string("/etc/system_state/system_state.ini")))
    {
        configFound = true;
    }
    else if (mParserObj.loadConfiguration(std::string("/system/etc/system_state/system_state.ini")))
    {
        configFound = true;
    }
    else
    {
        LOGE(&gSSMLogContext, "No Config file found");
    }
    
    return configFound;
}
