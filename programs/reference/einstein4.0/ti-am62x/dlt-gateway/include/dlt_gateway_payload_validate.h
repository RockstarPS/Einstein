//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
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
#ifndef DLT_GATEWAY_PAYLOAD_VALIDATE_H
#define DLT_GATEWAY_PAYLOAD_VALIDATE_H

#include <dlt/dlt.h>

/// @brief Minimum standard header size in bytes (HTYP + MCNT + LEN).
static const uint16_t DLT_STANDARD_HEADER_MIN_LEN  = 4u;
/// @brief Fixed extended header size in bytes (MSIN + NOAR + APID + CTID).
static const uint16_t DLT_EXTENDED_HEADER_LEN      = 10u;
/// @brief Absolute maximum DLT message length (uint16_t LEN field limit).
static const uint16_t DLT_MSG_MAX_LEN              = 65535u;
/// @brief Expected value of the version field in HTYP (version = 001).
static const uint8_t  DLT_HTYP_VERS_EXPECTED       = 0x20u;

// ============================================================
/// @defgroup validation_results Validation Result Types
/// @{
// ============================================================

/**
 * @brief Enumeration of all possible single-frame validation failure reasons.
 *
 * The @c None value is used for passing frames; all other values identify
 * exactly which check failed.
 */
enum class ValidationError : uint8_t
{
    None = 0,
    PayloadNull,           // payload pointer is null
    PayloadTooSmall,       // fewer bytes than minimum standard header
    PayloadTooLarge,       // exceeds DLT_MSG_MAX_LEN
    BadVersion,            // HTYP version bits != 001
    LengthFieldZero,       // LEN field in header is 0
    LengthFieldMismatch,   // LEN field != actual payload size
    LengthFieldTooSmall,   // LEN < computed header size (header alone overflows)
    ExtHeaderMissing,      // UEH bit set but not enough bytes for ext header
    NoarZero,              // NOAR (number of arguments) is 0 in verbose mode
    InvalidMsgType,        // MSTP value is reserved/invalid
};

/**
 * @brief Result of a single-frame validation check.
 *
 * @par Usage
 * @code{.cpp}
 * ValidationResult r = DltValidator::validate(msg);
 * if (!r.valid)
 *     LOGE(&ctx, "Bad DLT frame:", r.reason());
 * @endcode
 */
struct SValidationResult_t
{
    bool            valid {false};                 ///< @c true if the frame passed all checks.
    ValidationError error {ValidationError::None}; ///< Specific failure reason.

    const char* reason() const
    {
        switch (error)
        {
            case ValidationError::None:                return "OK";
            case ValidationError::PayloadNull:         return "Payload is null";
            case ValidationError::PayloadTooSmall:     return "Payload smaller than minimum DLT header (4 bytes)";
            case ValidationError::PayloadTooLarge:     return "Payload exceeds DLT max length (65535)";
            case ValidationError::BadVersion:          return "HTYP version bits are not 001";
            case ValidationError::LengthFieldZero:     return "LEN field in standard header is 0";
            case ValidationError::LengthFieldMismatch: return "LEN field does not match actual payload size";
            case ValidationError::LengthFieldTooSmall: return "LEN field smaller than computed header size";
            case ValidationError::ExtHeaderMissing:    return "UEH bit set but payload too small for extended header";
            case ValidationError::NoarZero:            return "Verbose message has NOAR=0 (no arguments)";
            case ValidationError::InvalidMsgType:      return "MSIN message type (MSTP) is reserved";
            default:                                   return "Unknown error";
        }
    }
};

/**
 * @brief Result of a multi-frame buffer scan performed by DltValidator::scanBuffer().
 *
 * @c valid_bytes is the key field: send exactly this many bytes to dlt-daemon
 * in a single TCP write.  dlt-daemon will parse each individual DLT frame from
 * the stream using the @c LEN field inside each frame header.
 */
struct SScanResult_t
{
    uint32_t    valid_bytes  {0};                  ///< Bytes from buffer start that are safe to send.
    uint16_t    frames_ok    {0};                  ///< Number of well-formed frames found.
    uint16_t    frames_bad   {0};                  ///< Number of invalid frames encountered (scan stopped at first).
    ValidationError error {ValidationError::None}; ///< Validation error of the first bad frame, or None.
};

/**
 * @brief Validates individual DLT frames and scans multi-frame SHM buffers.
 *
 * All methods are static and allocation-free.  The class has no state and
 * need not be instantiated.
 *
 * @par Multi-frame path (SharedMemory)
 * Used when the SHM buffer may contain multiple back-to-back DLT frames:
 * @code{.cpp}
 * ScanResult scan = DltValidator::scanBuffer(msg);
 * if (scan.valid_bytes > 0)
 *     tcpClient.sendRaw(msg.payload.data(), scan.valid_bytes);
 * @endcode
 */
class DltValidator
{
public:
    /**
     * @brief Walk a raw SHM buffer and find the contiguous valid-frame byte range.
     *
     * Iterates over DLT frames packed back-to-back using each frame's @c LEN
     * field as the stride.  Stops at the first of:
     *  - End of buffer.
     *  - @c LEN == 0 (zero-filled padding — normal at end of buffer).
     *  - @c LEN > remaining bytes (truncation or corruption).
     *  - A frame that fails @ref validateFrame() (corrupt header).
     *
     * The returned @c ScanResult::valid_bytes is the number of leading bytes
     * that form complete, valid DLT frames.
     *
     * @param data     Pointer to the start of the SHM buffer.
     * @param buf_len  Total size of the SHM buffer in bytes.
     * @return         @ref ScanResult describing the valid leading byte range.
     */
    static SScanResult_t scanBuffer(const uint8_t* data, uint32_t buf_len);

private:
    /**
     * @brief single-frame validator.
     *
     * Validates exactly @p len bytes starting at @p data as one DLT frame.
     * The @p len parameter must equal the frame's @c LEN field for the
     * @c LengthFieldMismatch check to pass.
     *
     * @param data  Pointer to the frame's first byte.
     * @param len   Claimed frame length (must match LEN field in header).
     * @return      @ref ValidationResult.
     */
    static SValidationResult_t validateFrame(const uint8_t* data, uint32_t len);
};

#endif //DLT_GATEWAY_PAYLOAD_VALIDATE_H