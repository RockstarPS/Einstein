///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2023. Visteon Corporation owns all rights to this work and
// intends to maintain it in confidence to preserve its trade secret status.
// Visteon Corporation reserves the right, under the copyright laws of the
// United States or those of any other country that may have jurisdiction,
// to protect this work as an unpublished work, in the event of an
// inadvertent or deliberate unauthorized publication. Visteon Corporation
// also reserves its rights under all copyright laws to protect this work as
// a published work, when appropriate. Those having access to this work may
// not copy it, use it, modify it or disclose the information contained in
// it without the written authorization of Visteon Corporation.
//
//  Filename    : rc_keys.h
//  Description : Keyboard event handling APIs
//  Created on  : 31-Mar-2023 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	rc_keys.h
///	\brief 	Keyboard event handling APIs
#ifndef rc_keys_h
#define rc_keys_h

#include <queue>
#include <mutex>  

namespace rendercore_engine
{
    /// \ingroup Internal
    /// @{
    /// Captures possible mouse events
    enum class rc_key_event
    {
        keUp,         ///< Keyboard key is up or inactve
        keDownUp,     ///< Key state changed from down to up
        keDown, 	  ///< Keyboard key is down or actve
        keUpDown,     ///< Key state changed from up to down
    };
    enum class rc_key_code
    {
        kcBackspace	= 0x08, // BACKSPACE key
        kcTab       = 0x09, // TAB key
        kcReturn    = 0x0D, // ENTER key
        kcShift     = 0x10, // SHIFT key
        kcControl   = 0x11, // CTRL key
        kcAlt       = 0x12, // ALT key
        kcPause     = 0x13, // PAUSE key
        kcCapital   = 0x14, // CAPS LOCK key
        kcEscape    = 0x1B, // ESC key
        kcSpace     = 0x20, // SPACEBAR
        kcPageUp    = 0x21, // PAGE UP key
        kcPageDn    = 0x22, // PAGE DOWN key
        kcEnd       = 0x23,	// END key
        kcHome      = 0x24,	// HOME key
        kcLeftArrow = 0x25,	// LEFT ARROW key
        kcUpArrow   = 0x26,	// UP ARROW key
        kcRightArrow= 0x27,	// RIGHT ARROW key
        kcDownArrow = 0x28,	// DOWN ARROW key
        kcSnapshot  = 0x2C,	// PRINT SCREEN key
        kcInsert    = 0x2D,	// INS key
        kcDelete    = 0x2E,	// DEL key
        kcNum0      = 0x30, // 0 key
        kcNum1      = 0x31, // 1 key
        kcNum2      = 0x32, // 2 key
        kcNum3      = 0x33, // 3 key
        kcNum4      = 0x34, // 4 key
        kcNum5      = 0x35, // 5 key
        kcNum6      = 0x36, // 6 key
        kcNum7      = 0x37, // 7 key
        kcNum8      = 0x38, // 8 key
        kcNum9      = 0x39, // 9 key
        kcA         = 0x41, // A key
        kcB         = 0x42, // B key
        kcC         = 0x43, // C key
        kcD         = 0x44, // D key
        kcE         = 0x45, // E key
        kcF         = 0x46, // F key
        kcG         = 0x47, // G key
        kcH         = 0x48, // H key
        kcI         = 0x49, // I key
        kcJ         = 0x4A, // J key
        kcK         = 0x4B, // K key
        kcL         = 0x4C, // L key
        kcM         = 0x4D, // M key
        kcN         = 0x4E, // N key
        kcO         = 0x4F, // O key
        kcP         = 0x50, // P key
        kcQ         = 0x51, // Q key
        kcR         = 0x52, // R key
        kcS         = 0x53, // S key
        kcT         = 0x54, // T key
        kcU         = 0x55, // U key
        kcV         = 0x56, // V key
        kcW         = 0x57, // W key
        kcX         = 0x58, // X key
        kcY         = 0x59, // Y key
        kcZ         = 0x5A, // Z key
        kcMenu      = 0x5d, // Menu key
        kcNumpad0   = 0x60, // Numeric keypad 0 key
        kcNumpad1   = 0x61, // Numeric keypad 1 key
        kcNumpad2   = 0x62, // Numeric keypad 2 key
        kcNumpad3   = 0x63, // Numeric keypad 3 key
        kcNumpad4   = 0x64, // Numeric keypad 4 key
        kcNumpad5   = 0x65, // Numeric keypad 5 key
        kcNumpad6   = 0x66, // Numeric keypad 6 key
        kcNumpad7   = 0x67, // Numeric keypad 7 key
        kcNumpad8   = 0x68, // Numeric keypad 8 key
        kcNumpad9   = 0x69, // Numeric keypad 9 key
        kcMultiply  = 0x6A, // Multiply key
        kcAdd       = 0x6B, // Add key
        kcSeperator = 0x6C, // Separator key
        kcSubtract  = 0x6D, // Subtract key
        kcDecimal   = 0x6E, // Decimal key
        kcDivide    = 0x6F, // Divide key
        kcF1        = 0x70, // F1 key
        kcF2        = 0x71, // F2 key
        kcF3        = 0x72, // F3 key
        kcF4        = 0x73, // F4 key
        kcF5        = 0x74, // F5 key
        kcF6        = 0x75, // F6 key
        kcF7        = 0x76, // F7 key
        kcF8        = 0x77, // F8 key
        kcF9        = 0x78, // F9 key
        kcF10       = 0x79, // F10 key
        kcF11       = 0x7A, // F11 key
        kcF12       = 0x7B, // F12 key
        kcF13       = 0x7C, // F13 key
        kcF14       = 0x7D, // F14 key
        kcF15       = 0x7E, // F15 key
        kcF16       = 0x7F, // F16 key
        kcF17       = 0x80, // F17 key
        kcF18       = 0x81, // F18 key
        kcF19       = 0x82, // F19 key
        kcF20       = 0x83, // F20 key
        kcF21       = 0x84, // F21 key
        kcF22       = 0x85, // F22 key
        kcF23       = 0x86, // F23 key
        kcF24       = 0x87, // F24 key
        kcNumLock   = 0x90, // NUM LOCK key
        kcScroll    = 0x91, // SCROLL LOCK key
        kcLShift    = 0xA0, // Left SHIFT key
        kcRShift    = 0xA1, // Right SHIFT key
        kcLCtrl     = 0xA2, // Left CONTROL key
        kcRCtrl     = 0xA3, // Right CONTROL key
        kcLAlt      = 0xA4, // Left ALT key
        kcRAlt      = 0xA5, // Right ALT key
        kcVolMute   = 0xAD, // Volume Mute key
        kcVolDn     = 0xAE, // Volume Down key
        kcVolUP     = 0xAF,  // Volume Up key
        kcUnMapped  = 0xFF
    };

    /// handles keyboard events
    class rc_keys
    {
    private:
        std::map<rc_key_code, rc_key_event> keyEventQueue;
        std::map<rc_key_code, rc_key_event> keyFrameStatus;
#ifndef RDF_GEN_BUILD
        mutable std::mutex mutexKeyData;
#endif
    public:
        /// <summary>
        /// creates Keys objects
        /// </summary>
        rc_keys();
        /// <summary>
        /// destructor
        /// </summary>
        virtual ~rc_keys();
        /// <summary>
        /// Add a key evet to the list. Internally invoked
        /// </summary>
        /// <param name="p_key">Key code</param>
        /// <param name="p_pressed">true - pressed, false - released </param>
        void Add(const rc_key_code p_key, const bool p_pressed);
        /// <summary>
        /// Returns true if the key is pressed 
        /// </summary>
        /// <param name="p_key">key code</param>
        /// <returns>true or false</returns>
        bool IsKeyUp(const rc_key_code p_key) const;
        /// <summary>
        /// Returns true if the key is pressed 
        /// </summary>
        /// <param name="p_key">key code</param>
        /// <returns>true or false</returns>
        bool IsKeyDn(const rc_key_code p_key) const;
        /// <summary>
        /// Returns true if the key is pressed 
        /// </summary>
        /// <param name="p_key">key code</param>
        /// <returns>true or false</returns>
        bool IsKey(const rc_key_code p_key) const;
        /// <summary>
        /// Internally invoked
        /// </summary>
        void Process();
    };
    /// @}
}
#endif
