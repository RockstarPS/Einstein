///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2018. Visteon Corporation owns all rights to this work and
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
//  Filename    : rc_platform_fio.h
//  Description : Sample Platform specific file handling support for rendercore
//                engine.
//  Created on  : 20-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#if defined(WIN32)
#include "gfx3d_scg.h"
#include "rc_platform_ws.h" 

namespace rendercore_engine
{
    const CHAR8* RcReadWholeFile(const std::string& p_path, size_t& p_sizeout)
    {
        CHAR8* fl_buffer = nullptr;
        FILE* fl_file = fopen(p_path.c_str(), "rb");
        if (fl_file != nullptr)
        {
            long fl_filesz;
            fseek(fl_file, 0L, SEEK_END);
            fl_filesz = ftell(fl_file);
            rewind(fl_file);

            if (fl_filesz < 0)
            {
                RcDebugErrorLogId(rc_error_logId::elPlatFioInvalidFileSize);
                WLOG("Uri %s\n", p_path.c_str());
            }
            else if (fl_filesz == 0)
            {
                RcDebugErrorLogId(rc_error_logId::elPlatFioEmptyFIle);
                WLOG("Uri %s\n", p_path.c_str());
            }
            else
            {
                size_t fl_szread = 0;
                fl_buffer = static_cast<CHAR8*>(rc_malloc(fl_filesz));
                if (fl_buffer != nullptr)
                {
                    fl_szread = fread(fl_buffer, 1, fl_filesz, fl_file);
                    if (fl_szread != (size_t)fl_filesz)
                    {
                        rc_free<CHAR8>(fl_buffer);
                        fl_filesz = 0;
                        fl_buffer = nullptr;
                    }
                }
            }
            p_sizeout = fl_filesz;
            fclose(fl_file);
        }
        return(fl_buffer);
    }
    bool RcFileExists(const std::string& p_path)
    {
        bool fl_sts;
        FILE* fl_file = fopen(p_path.c_str(), "rb");
        if (fl_file == nullptr)
        {
            fl_sts = false;
        }
        else
        {
            fclose(fl_file);
            fl_sts = true;
        }
        return(fl_sts);
    }
}
#endif
