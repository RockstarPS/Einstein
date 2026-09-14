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
/// @defgroup system_state System State Manager
///
/// @file system_state.h
/// @ingroup system_state
///
/// @brief SystemState manages the System State of the GP/Host.
///
/// SystemState manages the system state based on the GP conditions and the requests from the VP.
/// The SystemState also accepts the WakeLock requests from the GP components and denies the shutdown
/// requests from the VP if there is an active WakeLock.
///
/// The current system state and the wakelock count is transmitted during the following situations
///   * State change is requested
///   * WakeLock is requested/released
///   * UCL Link Status goes up.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

#include <functional>
#include <chrono>
#include <future>
#include <thread>
#include <unordered_map>

#include "dk_logger.h"
#include "dk_runtime_system_state_component.h"
#include "dk_runtime_parserif.h"
#include "DKOsalTimer.h"

class SystemState
{
public:
  SystemState();

  ~SystemState()
  {
  }

  bool onInit();
  bool onExit();
  bool onStart();
  bool onStop();
  void worker(void);

  ///
  /// @brief Request the System State Change, typically done by VP
  /// @param state Requested State
  ///
  void requestStateChange(const ESystemState_t state);

  ///
  /// @brief Request the WakeLock, to prevent system shutdown
  /// @param compId Component requesting the lock
  /// @param enable true - request WakeLock, false - release WakeLock
  /// @param requestedLockTimeMs timer duration for which the lock is being requested
  ///
  void requestWakeLock(const uint8_t compId, const uint8_t enable, const uint32_t requestedLockTimeMs);

  ///
  /// @brief Set the communication link state of UCL
  /// @param linkState Link state Up / Down.
  ///
  void setCommLinkStatus(const sint32 linkState);
  
  ///
  /// @brief Set the communication running status of components 
  /// @param state will be Up / Down.
  ///
  void setCompState(const uint8_t compId, const ECompState_t compState);

  ///
  /// @brief Peridodic task to maintain the wakelock timers
  ///
  void periodicTask(const uint16_t durationMs);

  ///
  /// @brief Send system state status report
  ///
  void sendStatusReport();

  ///
  /// @brief Returns the domain id
  ///
  EDomainId_t getDomainId() const;


private:
  const uint32_t mcPowerStateMessagePeriodicityMs = 1000U;
  const uint32_t mcDomainId = 1U;
  const int32_t mcShutdownTimeoutMs = 1000;
  const int32_t mcExtendShutdownTimeoutMs = 5000;

  typedef struct SWakeLockRecord
  {
    uint8_t compId;
    uint64_t expiresAt;
  } SWakeLockRecord_t;
  
   typedef struct SCompStateRecord
  {
    uint8_t compId;
    ECompState_t compState;
  } SCompStateRecord_t;

  class ShutdownFinalTimerListener : public dk::osal::ITimerListener
  {
      public:
          virtual void onTimeout ( const dk::osal::Timer &timer );
  };

  std::mutex mWakeLockListMutex;
  std::vector<SWakeLockRecord_t>  mActiveWakeLockList; ///< List of active wakelocks
  std::vector<SCompStateRecord_t> mFullRunCompList;    ///< List of components to transition to full run
  ESystemState_t mSystemState;                         ///< Current System State
  dk::runtime::core::ParserIf mParserObj;              ///< INI File Parser
  uint32_t mPowerStateMessagePeriodicityMs = 0U;       ///< Periodicity of the Power State Message
  uint32_t mDomainId = 0U;                             ///< Domain Identifier
  int32_t mSystemStateBroadcastTimer =0;               ///< System State Broadcast timer
  int32_t mSystemStateShutdownTimer = 0;               ///< System State Shutdown timer
  ShutdownFinalTimerListener mShutdownFinalCbk;
  dk::osal::Timer mShutdownFinalTimer;
  uint32_t mShutdownFinalTimeoutMs = 0U;
  const uint32_t mcShutdownFinalTimeoutMs = 2000U;
  std::string enumToString(int state) const; 
  std::unordered_map<int, std::string> mEnumToStr;

  void sendCurrentSystemState(void);
  void sendExtendShutdownTime(void);
  void sendKeepSystemAwake(void);
  uint8_t getNumberOfActiveWakeLocks();
  uint8_t removeWakeLockByCompId(const uint8_t compId);
  uint8_t removeExpiredWakeLocks(const uint64_t timeNow);
  uint8_t addWakeLock(const uint8_t compId, const uint32_t requestedLockTimeMs);
  
  bool loadConfiguration();
  bool checkIfFullRunConditionSatified();
  bool checkIfShutdownConditionSatified();

};

#endif //SYSTEM_STATE_COMPONENT_H
