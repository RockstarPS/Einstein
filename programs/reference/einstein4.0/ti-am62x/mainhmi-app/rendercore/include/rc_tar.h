///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2020. Visteon Corporation owns all rights to this work and
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
//  Created on  : 16-Apr-2020 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	rc_tar.h
///	\brief 	Implements the minimal verion of the GNU Tar format decoding
#ifndef rc_tar_h
#define rc_tar_h

#include <unordered_map>

/// https ://www.gnu.org/software/tar/manual/html_node/Standard.html
/// Performance data Images.tar with 4572 files, 45MB
/// Win10 : 
///  - Tar::Open() = 0.091935Sec
///  - Tar::GetFileData() for 4572 diles = Min 0.000003, Max 0.000136 Avg 0.000005
/// imx6-Qnx :
///  - Tar::Open() = 2.735Sec
///  - Tar::GetFileData() for 4572 diles = file open time Min 0.0, Max 3mSec Avg 0.000003, Total 27mSec
namespace rendercore_engine
{
    enum TarBlkType
    {
        REGTYPE = '0',           ///< regular file
        AREGTYPE = '\0',         ///< regular file
        LNKTYPE = '1',           ///< link
        SYMTYPE = '2',           ///< reserved
        CHRTYPE = '3',           ///< character special
        BLKTYPE = '4',           ///< block special
        DIRTYPE = '5',           ///< directory
        FIFOTYPE = '6',          ///< FIFO special
        CONTTYPE = '7',          ///< reserved
        XHDTYPE = 'x',           ///< Extended header referring to the  next file in the archive
        XGLTYPE = 'g',            ///< Global extended header
        LONGNAME = 'L'           ///< Long file name
    };
    struct posix_header
    {
        CHAR8 name[100];
        CHAR8 mode[8];
        CHAR8 uid[8];
        CHAR8 gid[8];
        CHAR8 size[12];
        CHAR8 pt_mtime[12];
        CHAR8 chksum[8];
        CHAR8 typeflag;
        CHAR8 linkname[100];
        CHAR8 magic[6];
        CHAR8 pt_version[2];
        CHAR8 uname[32];
        CHAR8 gname[32];
        CHAR8 devmajor[8];
        CHAR8 devminor[8];
        CHAR8 prefix[155];
    };
    struct tarfile
    {
        const CHAR8* tard = nullptr;
        size_t tsize = 0U;
        size_t tread = 0U;
    };
    struct tarblock
    {
        const posix_header* header = nullptr;
        const CHAR8* prefix = nullptr;
        const CHAR8* filename = nullptr;
        const CHAR8* fdata = nullptr;
        size_t fsize = 0U;
    };
    class rc_tar
    {
    private:
        std::string name;
        const size_t TAR_BLOCKSIZE = 512U;
        const CHAR8* TMAGIC = "ustar";
        const CHAR8* TVERSION = "00";
        bool getNextBlock(tarfile& p_tar, tarblock& p_blk, uint32_t p_linklevel);
        tarfile tar;
        std::unordered_map<std::string, tarblock> tarFiles;
        /// Number of usage instances. 
        /// A call to GetFileData() increments and a Free() call decrements.
        size_t instances = 0U;
        size_t filetypeHint = 0U;
        // returns file type guess based on extension
        static size_t getFileTypeHint(const std::string& p_path);
    public:
        ~rc_tar();
        /// Open a tar archive and add all the files to internal list
        bool Open(const std::string& p_path);
        /// Attemps to close if no one is using any files
        bool Close();
        /// Look up a file in the archive and get the file data pointer and file size
        /// each call to GetFileData() must have a Free() call once the file data is
        /// no longer needed
        tarblock * GetFileData(const std::string& p_path, const bool p_quiet = false);
        /// pass the pointer that was returned by a previous call to GetFileData()
        bool Free(const CHAR8* const p_filedata, const bool p_quiet = false);
    };
}
#endif