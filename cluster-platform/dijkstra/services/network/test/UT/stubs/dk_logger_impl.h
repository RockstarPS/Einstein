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

#ifndef DK_LOGGER_IMPL_H
#define DK_LOGGER_IMPL_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdint>
#include <mutex>
#include <map>
#include <vector>
//#include "dk_logger_version.h"
#ifdef DK_SLOG2_ENABLED
    #include <sys/slog2.h>
#endif
#ifdef DK_DLT_ENABLED
#include "dlt/dlt.h"
#else

#define DLT_USER_BUF_MAX_SIZE 2048
typedef struct
{
    char contextID[4];
    int32_t log_level_pos;
    int32_t log_level_user;
} DltContext;

typedef enum
{
    DLT_LOG_DEFAULT = -1,
    DLT_LOG_OFF = 0x00,
    DLT_LOG_FATAL = 0x01,
    DLT_LOG_ERROR = 0x02,
    DLT_LOG_WARN = 0x03,
    DLT_LOG_INFO = 0x04,
    DLT_LOG_DEBUG = 0x05,
    DLT_LOG_VERBOSE = 0x06
} DltLogLevelType;

typedef enum
{
    DLT_TRACE_STATUS_DEFAULT = -1,
    DLT_TRACE_STATUS_OFF = 0x00,
    DLT_TRACE_STATUS_ON = 0x01
} DltTraceStatusType;

typedef struct
{
    DltContext *handle;
    std::stringstream buffer;
    int32_t log_level;
    int32_t trace_status;
    int32_t args_num;
    uint8_t mcnt;
    char *context_description;
} DltContextData;

#define DLT_DECLARE_CONTEXT(CONTEXT) \
    DltContext CONTEXT;

#define DLT_IMPORT_CONTEXT(CONTEXT) \
    extern DltContext CONTEXT;
#endif

namespace dk
{
class Logger
{
    public:
        typedef struct
        {
            DltContext *pHandle;
            std::stringstream buffer;
            int32_t logLevel;
            int32_t traceStatus;
            int32_t argsNum;
            uint8_t mcnt;
            char *pContextDescription;
        } NoDltContextData;

        typedef enum eLogDestination
        {
            eLogDestination_DLT = 0,     ///< Log to DLT Daemon
            eLogDestination_Console = 1, ///< Log to Console
            eLogDestination_File = 2,    ///< Log to File
            eLogDestination_Slog2 = 3    ///< Log to Slogger
        } eLogDestination_t;

        static Logger *createInstance ( const char *pAppId,
                const char *pDescription,
                const bool debugEnabled = true,
                const eLogDestination_t logDest = eLogDestination_DLT,
                bool silent = false,
                const std::string filename = "",
                bool logOnlyError = false );

        static Logger *getInstance();
        ~Logger();
        bool init ( DltLogLevelType loglevel, DltContext *pContext = NULL );
        void deInit();
        bool getEnabled();
        void registerContext ( DltContext &handle, const char *pContextId, const char *pDescription );
        void registerContext ( DltContext &handle, const char *pCcontextId, const char *pDescription, const DltLogLevelType level, const DltTraceStatusType status );
        void unregisterContext ( DltContext &handle );
        void send();
        void append ( const int8_t value );
        void append ( const uint8_t value );
        void append ( const int16_t value );
        void append ( const uint16_t value );
        void append ( const int32_t value );
        void append ( const uint32_t value );
        void append ( const uint64_t value );
        void append ( const int64_t value );
        void append ( const std::string &value );
        void append ( const bool value );
        void append ( const std::vector<uint8_t> &data );
        // specialization for const char*
        template <typename T = const char *>
        void append ( const char *value )
        {
#ifdef DK_DLT_ENABLED

            if ( mlogDestination == eLogDestination_DLT )
            {
                dlt_user_log_write_string ( &mDltContextData, value );
            }
            else
            {
                mNoDltContextData.buffer << std::string ( value );
            }

#else
            mNoDltContextData.buffer << std::string ( value );
#endif
        }
        // Template to print unknown pointer types with their address
        template <typename T>
        void append ( T *value )
        {
            std::ostringstream ss;
            ss << "0x" << std::hex << ( uint64_t ) value;
            append ( ss.str().c_str() );
        }

        // Template to print unknown types
        template <typename T>
        void append ( T value )
        {
            std::ostringstream ss;
            ss << std::dec << value;
            append ( ss.str().c_str() );
        }

        // Template parameter pack to generate recursive code
        void append ( void ) {}
        template <typename T, typename... TArgs>
        void append ( T value, TArgs... args )
        {
            this->append ( value );
            this->append ( args... );
        }
        template <class T>
        void appendNoDLT ( T value )
        {
            mNoDltContextData.buffer << +value;
            //Split into two lines to fix Coverity error
            mNoDltContextData.buffer << " ";
        }

        std::string getFileName ( std::string filePath, bool withExtension = true, char seperator = '/' );
        std::string now();

    private:
        Logger ( const char *pAppId,
                const char *pDescription,
                const bool debugEnabled = true,
                const eLogDestination_t logDest = eLogDestination_DLT,
                bool silent = false,
                const std::string filename = "",
                bool logOnlyError = false ); ///< Private because of singleton pattern

        bool initNoDlt ( DltLogLevelType loglevel, DltContext *pContext );
        static Logger *mpDLTWrapper;                   ///< Static variable to hold the instance
        std::map<DltContext *, std::string> mMapContext; ///< DLT Context Map
        std::map<DltContext *, DltLogLevelType> mMapContextLevel; ///< NoDLT Context Level Data
        DltContext mDltContext;                          ///< DLT Contenxt
        DltContextData mDltContextData;                  ///< DLT Context Data
        NoDltContextData mNoDltContextData;              ///< No DLT Context Data
        bool mDebugEnabled;                              ///< Debug Enabled Status
        eLogDestination_t mlogDestination;               ///< Log destination
        std::ofstream mFilename;                         ///< Log File
        bool mLogOnlyError;                              ///< Log Only Error Messages
        bool mSilent;                                    ///< Silent mode, minimise output in console mode
        bool mLogOn;                                     ///< Logging ON
        DltLogLevelType mMsgLogLvl;                      ///< Current Message Log Level
        std::mutex mGuardMutex;                          ///< Guard Mutex to protect APIs
        std::string mAppId;                              ///< Application Id
#ifdef DK_SLOG2_ENABLED
        slog2_buffer_set_config_t slog2BufferConfig;     ///< Slog2 buffer configuration
        slog2_buffer_t slog2BufferHandle[1U];            ///< Slog2 buffer handle
#endif
};
}

#endif //DK_LOGGER_IMPL_H
