//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2026] Visteon Corporation
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
/**
 * @file dlt_gateway_payload_validate.cpp
 * @author dmuruge5/gsoundar
 * @brief 
 * @version 0.1
 * @date 2026-06-01
 * 
 */

#include "dlt_types.h"
#include "dlt_gateway_payload_validate.h"
#include "dk_logger.h"

LOG_IMPORT_CONTEXT ( gDLTGWLogContext );

SScanResult_t DltValidator::scanBuffer(const uint8_t* data, uint32_t buf_len)
{
    SScanResult_t result;

    if ((data != nullptr) && (buf_len >= DLT_STANDARD_HEADER_MIN_LEN))
    {
        uint32_t offset = 0;

        while (offset + DLT_STANDARD_HEADER_MIN_LEN <= buf_len)
        {
            const uint8_t* frame = data + offset;
            uint32_t remaining = buf_len - offset;

            /* Read LEN from this frame's header */
            /* LEN is big-endian uint16 at bytes [2..3] */
            const uint16_t frame_len = static_cast<uint16_t>( (static_cast<uint16_t>(frame[2]) << 8) |
                                        static_cast<uint16_t>(frame[3]));

            /* LEN == 0 means padding / end-of-data marker */
            if (frame_len == 0)
                break;

            /* LEN claims more bytes than remain in the buffer */
            if (static_cast<uint32_t>(frame_len) > remaining)
            {
                /* Treat as corruption — stop here */
                result.frames_bad++;
                result.error = ValidationError::LengthFieldMismatch;
                LOGE(&gDLTGWLogContext, "ValidationError::LengthFieldMismatch, ","Frame at offset: ", offset, ":",frame_len," remaining:",remaining);
                break;
            }

            /* Validate each frame */
            SValidationResult_t ValidationResult = validateFrame(frame, frame_len);
            if (!ValidationResult.valid)
            {
                result.frames_bad++;
                if (result.error == ValidationError::None)
                    result.error = ValidationResult.error;
                LOGE(&gDLTGWLogContext,"Frame at offset ",offset," len=",frame_len," Invalid: ",ValidationResult.reason()," — stopping scan" );
                break;
            }

            /* Frame is good — advance */
            offset += frame_len;
            result.valid_bytes = offset;
            result.frames_ok++;
        }
    }

    return result;
}

SValidationResult_t DltValidator::validateFrame(const uint8_t* data, uint32_t len)
{
    SValidationResult_t result;

    if (data == nullptr)
    {
        result.error = ValidationError::PayloadNull;
    }
    else if(len < DLT_STANDARD_HEADER_MIN_LEN)
    {
        result.error = ValidationError::PayloadTooSmall;
    }
    else if(len > DLT_MSG_MAX_LEN)
    {
        result.error = ValidationError::PayloadTooLarge;
    }
    else
    {
        const uint8_t  htyp    = data[0];
        const uint16_t dlt_len = static_cast<uint16_t>( (static_cast<uint16_t>(data[2]) << 8) |
                                     static_cast<uint16_t>(data[3]));
        if((htyp & DLT_HTYP_VERS) != DLT_HTYP_VERS_EXPECTED)
        {
            result.error = ValidationError::BadVersion;
        }
        else if(dlt_len == 0)
        {
            result.error = ValidationError::LengthFieldZero;
        }
        else if(static_cast<std::size_t>(dlt_len) != len)
        {
            result.error = ValidationError::LengthFieldMismatch;
        }
        else
        {
            uint16_t header_size = DLT_STANDARD_HEADER_MIN_LEN;
            if (htyp & DLT_HTYP_WEID)
                header_size += 4u;

            if (htyp & DLT_HTYP_WSID)
                header_size += 4u;

            if (htyp & DLT_HTYP_WTMS)
                header_size += 4u;

            if (dlt_len < header_size)
            {
                result.error = ValidationError::LengthFieldTooSmall;
            }
            else
            {
                if (htyp & DLT_HTYP_UEH)
                {
                    if (static_cast<std::size_t>(header_size) + DLT_EXTENDED_HEADER_LEN > len)
                    {
                        result.error = ValidationError::ExtHeaderMissing;
                    }
                    else
                    {
                        const uint8_t* ext  = data + header_size;
                        const uint8_t  msin = ext[0];
                        const uint8_t  noar = ext[1];

                        header_size += DLT_EXTENDED_HEADER_LEN;

                        const bool verbose = ((msin & DLT_MSIN_VERB) != 0);
                        LOGV(&gDLTGWLogContext,"MSIN ", msin," Verbose ", verbose, " NOAR ",noar);
                        if (verbose && (noar == 0))
                        {
                            result.error = ValidationError::NoarZero;
                            return result;
                        }

                        const uint8_t mstp = (msin & DLT_MSIN_MSTP) >> 1;
                        if ((mstp > 0x03u))
                        {
                            result.error = ValidationError::InvalidMsgType;
                            return result;
                        }

                        result.valid = true;
                        result.error = ValidationError::None;
                    }
                }
            }
        }
    }
    return result;
}
