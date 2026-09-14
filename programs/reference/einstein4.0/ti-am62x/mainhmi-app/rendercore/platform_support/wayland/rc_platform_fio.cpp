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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "gfx3d_scg.h"

namespace rendercore_engine
{
    const CHAR8* RcReadWholeFile(const std::string& p_path, size_t& p_sizeout)
    {
        CHAR8* fl_filemem;
        const CHAR8* const fl_filepath = p_path.c_str();
		
        if (fl_filepath != nullptr)
        {
            int32_t fl_infile = open(fl_filepath, O_RDONLY);
            if (fl_infile >= 0)
            {
                struct stat fl_buf;
                const int32_t fl_fstatres = fstat(fl_infile, &fl_buf);
                if ((fl_fstatres == 0) && (fl_buf.st_size > 0))
                {
                    fl_filemem = reinterpret_cast<CHAR8*>(rc_malloc(static_cast<size_t>(fl_buf.st_size)));
                    if (fl_filemem != nullptr)
                    {
                        const ssize_t fl_readSize = read(fl_infile, static_cast<void*>(fl_filemem), static_cast<size_t>(fl_buf.st_size));
                        if (fl_readSize != fl_buf.st_size)
                        {
                            rc_free<CHAR8>(fl_filemem);
                            fl_filemem = nullptr;
                        }
                        else
                        {
                            p_sizeout = static_cast<size_t>(fl_readSize);
                        }
                    }
                }
                else
                {
                    fl_filemem = nullptr;
                }
                fl_infile = close(fl_infile);
                if(fl_infile != 0)
                {
                    ELOG("RcReadWholeFile close error\n");
                    (void)fl_infile;
                }
            }
            else
            {
                fl_filemem = nullptr;
            }
        }
        else
        {
            fl_filemem = nullptr;
        }
        return( static_cast<const CHAR8*>(fl_filemem));
    }
    bool RcFileExists(const std::string& p_path)
    {
        bool fl_sts;
        std::FILE* const fl_file = std::fopen(p_path.c_str(), "rb");
        if (fl_file == nullptr)
        {
            fl_sts = false;
        }
        else
        {
            (void)std::fclose(fl_file);
            fl_sts = true;
        }
        return(fl_sts);
    }
}
