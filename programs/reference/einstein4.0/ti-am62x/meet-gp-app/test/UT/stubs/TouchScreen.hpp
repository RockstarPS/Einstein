//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2024] Visteon Corporation
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

#pragma once

#include "StdDiagTypes.hpp"
#include "SystemCalls.hpp"

#include <stdint.h>
#include <vector>
#include <cstdint>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <memory>

namespace SwcDiagGP
{   
    constexpr uint8_t MAX_TOUCH_ID = 5U;
    constexpr uint8_t PIXEL_BUFFER = 6U;
    
    class TouchScreen
    {
    public:
        TouchScreen(
            const std::shared_ptr<ISystemCalls> &systemCalls);
        ~TouchScreen() noexcept;

    public:
        virtual void addTouchEvent(const input_event &touchEvent);
        virtual E_RESULT readData();
        virtual void getTouchEvents(std::vector<uint8_t> &buffer);
        virtual void resetTouchCoordinates();
        virtual void getEV_KEY(std::vector<uint8_t> &buffer);

    private:
        enum FingerState : uint8_t
        {
            touchNotDetected = 0,
            touchPresent = 1,
            touchAndDrag = 2,
            touchLifted = 3
        };
        struct Finger
        {
            Finger() : x(0xFFFF), y(0xFFFF), isXSet(false), isYSet(false), state(FingerState::touchNotDetected) {}
            uint16_t x;
            uint16_t y;
            bool isXSet, isYSet;
            FingerState state;
        };
        std::shared_ptr<ISystemCalls> _systemCalls;
        std::vector<Finger> touchCoordinates;
        int32_t fd;

    private:
        void updateState(uint16_t &oldCoord, const uint16_t newCoord, FingerState &state, const bool isXSet, const bool isYSet) const;
    };
}