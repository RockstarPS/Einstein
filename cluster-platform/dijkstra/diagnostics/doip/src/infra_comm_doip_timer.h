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
//---------------------------------------------------------------------------------------------------------------------
///
/// @file infra_comm_doip_timer.h
/// @ingroup DOIP
///
/// @brief  CDoIPTimer Class. CDoIPTimer shall provide an interface for the CDoIPHandler for handling the DoIp timers.
///    It provides interface for adding of timer , starting and stopping of timer and status of the timer.
/// CUdsTimer provides count down timer functionality .It is used by the CDoIPHandler for handling the GeneralActivity, AliveCheck
/// resposne and InitialInactivity timers.Each should be set with an unique timer ID in the range 0-255.
/// Each timer is added with the unique ID and its time-out callback function. Then the timer can be started with the
/// time-out value. On the timer expiry the configured time-out function is called.CDoIPTimer also provides interface for
/// stopping the timer and the current status of the timer. The CDoIPTimer provides a functionality for creating a
/// different sets of timer by providing a base time tick when instantiating the timer objects.
/// It Provides infrastructure for
///         * Addition of timer with is time-out callback function.
///         * Timer start/Stop.
///         * Interface for checking status of the  timer.
///         * Timer base tick is configurable.
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef INFRA_COMM_DOIP_TIMER_H
#define INFRA_COMM_DOIP_TIMER_H
#include <cstdint>
#include <map>
#include <functional>
#include <mutex>

class CDoIPTimer
{
public:
    ///
    /// @brief Callback function type of a function which is called whenever the registered time-out occurred.
    ///
    typedef std::function<void ( void ) > timeoutCallbackfunction_t;
    ///
    /// @brief This method add a new timer with the requested timerID and a callback function.
    /// @param[in] timeoutCallbackfunction The callback function which is called on the expiry of timer.
    ///param[out] generated Timer Id for the callback function requested
    /// @note This function should be invoked before calling startTimer.
    ///
    int32_t addTimer ( const timeoutCallbackfunction_t &timeoutCallbackfunction );
    ///
    /// @brief This method starts the starts timer with requested time count.
    /// @param[in] timerId ID of the timer . It should be in the range 0-255.
    /// @param[in] timerValue Time-out value of the timer ID.Value should be in milliseconds.The value should be
    ///            greater than baseTimeTick.
    ///
    /// @note The requested timerId should be initialized using addTimer before invoking this function.
    ///
    void startTimer ( int32_t timerId, uint32_t mtimerValue );
    ///
    /// @brief This method stops
    /// @param[in] timerId ID for the timer . It should be in the range 0-255.
    ///
    /// @note The requested timerId should be initialized using addTimer before invoking this function.
    ///
    void stopTimer ( int32_t timerId );
    ///
    /// @brief This method provides the basic time tick for timer.Its periodicity is configurable.The periodicity value
    ///        should be set when creating the object of this class.
    /// @note This function should be invoked before calling startTimer.
    ///
    void timerBaseTickTask ( void );


    void ResetTimer ( void );

    CDoIPTimer()
    {
        mTimerId = 0;
    }

    ~CDoIPTimer()
    {

    }

private:
    ///
    /// @brief It indicates the properties of the timer.
    ///
    typedef struct
    {
        uint32_t mTimeCount = 0U; ///< time count value in milliseconds
        timeoutCallbackfunction_t mTimeoutCallbackfunction; ///< callback function reference of the timer. It is
        /// called on the expiry of timer.
    } STimer_t;
    ///
    /// @brief It is used for mapping the timer with its requested Id and its properties.
    ///
    std::map<int32_t, STimer_t> mTimerMap;
    int32_t  mTimerId;
    std::mutex mProtectTimerId;
};

#endif

