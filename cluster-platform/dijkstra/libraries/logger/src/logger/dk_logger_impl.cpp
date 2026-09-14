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
#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>
#include <cstdarg>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#if __GLIBC__ == 2 && __GLIBC_MINOR__ < 30
#include <sys/syscall.h>
#define gettid() syscall(SYS_gettid)
#endif
#include "dk_logger_impl.h"

using namespace dk;

#ifdef __QNX__
    extern char *__progname;
#endif

Logger *Logger::mpDLTWrapper = nullptr;

Logger *Logger::createInstance ( const char * const pAppId,
        const char * const pDescription,
        const bool debugEnabled,
        const eLogDestination_t logDest,
        const bool silent,
        const std::string filename,
        const bool logOnlyError )
{
    if ( mpDLTWrapper == nullptr )
    {
        mpDLTWrapper = new Logger ( pAppId, pDescription, debugEnabled, logDest, silent, filename, logOnlyError );
    }

    return ( mpDLTWrapper );
}

Logger *Logger::getInstance()
{
    if ( mpDLTWrapper == nullptr )
    {
        // Logger not created, make one
        std::ostringstream description;
        char* pPath;

        pPath = getenv ( "_" );

        if((NULL != pPath))
        {
            const int32_t procID = static_cast<int32_t>(getpid());

            description << "PID=";
            description << procID ;
            description <<  " _=" ;
            description <<  pPath;
        
            mpDLTWrapper = new Logger ( "DkApp", description.str().c_str() );
            std::cout << "Application doesn't call Logger::createInstance!!!" << &std::endl;
            if(std::cout){
            std::cout << "-> Logger::getInstance registers DLT application [ DkApp | " << description.str() << " ]" << &std::endl;
        }
        }
    }

    return mpDLTWrapper;
}

std::string Logger::now() const
{
    const uint8_t time_sz = 25U;
    const auto now = std::chrono::system_clock::now();
    const time_t t ( std::chrono::system_clock::to_time_t ( now ) );
    const struct tm *const timeinfo ( localtime ( &t ) );
    char date_time_milli[time_sz] = {0};

    if ( nullptr != timeinfo )
    {
        const auto seconds = std::chrono::time_point_cast<std::chrono::seconds> ( now );
        const auto fraction = now - seconds;
        const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> ( fraction );
        (void)snprintf ( &date_time_milli[0], time_sz, "%04d.%02d.%02d.%02d.%02d.%02d.%03lld",
                timeinfo->tm_year, timeinfo->tm_mon, timeinfo->tm_mday,
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, static_cast<long long int>(milliseconds.count() ));
    }

    return ( std::string ( date_time_milli ) );
}

bool Logger::getEnabled() const 
{
    return ( mDebugEnabled );
}

std::string Logger::getFileName ( const std::string filePath, const bool withExtension, const char seperator )
{
    std::string ret = "";

    const std::size_t sepPos = filePath.rfind ( seperator );

    if ( sepPos != std::string::npos )
    {
        const std::size_t dotPos = filePath.rfind ( '.' );

        if((true == withExtension) && (dotPos != std::string::npos))
		{
		    ret = filePath.substr ( sepPos + 1U, (filePath.size() - sepPos));
		}
		else
		{
	        ret = filePath.substr ( sepPos + 1U, (dotPos - sepPos - 1U));
		}
    }

    return ret;
}

bool Logger::initNoDlt ( const DltLogLevelType loglevel, DltContext * const pContext )
{
    bool ret = false;
    mLogOn = true;
    mMsgLogLvl = loglevel;

    if ( mlogDestination == eLogDestination_Console )
    {
        if ( pContext == nullptr )
        {
            if ( loglevel <= mNoDltContextData.logLevel )
            {
                switch ( loglevel )
                {
                    case DLT_LOG_OFF:
                    case DLT_LOG_FATAL:
                    case DLT_LOG_ERROR:
                        mNoDltContextData.buffer << "\x1B[0;31m[" << mAppId << "][DEFA][Erro] \x1B[0m";
                        mLogOn = true;
                        break;

                    case DLT_LOG_WARN:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "\x1B[0;33m[" << mAppId << "][DEFA][Warn] \x1B[0m";
                        }
                        else
                        {
                            mLogOn = false;
                        }

                        break;

                    case DLT_LOG_INFO:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "\x1B[0;36m[" << mAppId << "][DEFA][Info] \x1B[0m";
                        }
                        else
                        {
                            mLogOn = false;
                        }

                        break;

                    case DLT_LOG_VERBOSE:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "\x1B[0;32m[" << mAppId << "][DEFA][Verb] \x1B[0m";
                        }
                        else
                        {
                            mLogOn = false;
                        }

                        break;

                    default:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "\x1B[0;32m[" << mAppId << "][DEFA][Defa] \x1B[0m";
                        }
                        else
                        {
                            mLogOn = false;
                        }
                        break;
                }
            }
            else
            {
                mLogOn = false;
            }
        }
        else
        {
            const std::string con ( mMapContext.at ( pContext ) );
            const DltLogLevelType lvl ( mMapContextLevel.at ( pContext ) );

            if ( loglevel <= lvl )
            {
                switch ( loglevel )
                {
                    case DLT_LOG_OFF:
                    case DLT_LOG_FATAL:
                    case DLT_LOG_ERROR:
                        mNoDltContextData.buffer << "\x1B[0;31m[" << mAppId << "][" << con << "][Erro] \x1B[0m";
                        mLogOn = true;
                        break;

                    case DLT_LOG_WARN:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "\x1B[0;33m[" << mAppId << "][" << con << "][Warn] \x1B[0m";
                        }
                        else
                        {
                            mLogOn = false;
                        }

                        break;

                    case DLT_LOG_INFO:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "\x1B[0;36m[" << mAppId << "][" << con << "][Info] \x1B[0m";
                        }
                        else
                        {
                            mLogOn = false;
                        }

                        break;

                    case DLT_LOG_VERBOSE:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "\x1B[0;32m[" << mAppId << "][" << con << "][Verb] \x1B[0m";
                        }
                        else
                        {
                            mLogOn = false;
                        }

                        break;

                    default:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "\x1B[0;32m[" << mAppId << "][" << con << "][Defa] \x1B[0m";
                        }
                        else
                        {
                            mLogOn = false;
                        }
                        break;
                }
            }
            else
            {
                mLogOn = false;
            }
        }

        ret = true;
    }
    else
    {
        if ( pContext == nullptr)
        {
            if ( loglevel <= mNoDltContextData.logLevel )
            {
                switch ( loglevel )
                {
                    case DLT_LOG_OFF:
                    case DLT_LOG_FATAL:
                    case DLT_LOG_ERROR:
                        mNoDltContextData.buffer << "[" << mAppId << "][DEFA][Erro] ";
                        mLogOn = true;
                        break;

                    case DLT_LOG_WARN:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "[" << mAppId << "][DEFA][Warn] ";
                        }
                        else
                        {
                            mLogOn = false;
                        }

                        break;

                    case DLT_LOG_INFO:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "[" << mAppId << "][DEFA][Info] ";
                        }
                        else
                        {
                            mLogOn = false;
                        }

                        break;

                    case DLT_LOG_VERBOSE:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "[" << mAppId << "][DEFA][Verb] ";
                        }
                        else
                        {
                            mLogOn = false;
                        }

                        break;

                    default:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "[" << mAppId << "][DEFA][Defa] ";
                        }
                        else
                        {
                            mLogOn = false;
                        }
                        break;
                }
            }
            else
            {
                mLogOn = false;
            }
        }
        else
        {
            const std::string con ( mMapContext.at ( pContext ) );
            const DltLogLevelType lvl ( mMapContextLevel.at ( pContext ) );

            if ( loglevel <= lvl )
            {
                switch ( loglevel )
                {
                    case DLT_LOG_OFF:
                    case DLT_LOG_FATAL:
                    case DLT_LOG_ERROR:
                        mNoDltContextData.buffer << "[" << mAppId << "][" << con << "][Erro] ";
                        mLogOn = true;
                        break;

                    case DLT_LOG_WARN:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "[" << mAppId << "][" << con << "][Warn] ";
                        }
                        else
                        {
                            mLogOn = false;
                        }

                        break;

                    case DLT_LOG_INFO:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "[" << mAppId << "][" << con << "][Info] ";
                        }
                        else
                        {
                            mLogOn = false;
                        }

                        break;

                    case DLT_LOG_VERBOSE:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "[" << mAppId << "][" << con << "][Verb] ";
                        }
                        else
                        {
                            mLogOn = false;
                        }

                        break;

                    default:
                        if ( !mLogOnlyError )
                        {
                            mNoDltContextData.buffer << "[" << mAppId << "][" << con << "][Defa] ";
                        }
                        else
                        {
                            mLogOn = false;
                        }
                        break;
                }
            }
            else
            {
                mLogOn = false;
            }
        }

        ret = true;
    }

    return ret;
}

#ifdef DK_DLT_ENABLED
Logger::Logger ( const char *const pAppId,
        const char *const pDescription,
        const bool debugEnabled,
        const eLogDestination_t logDest,
        const bool silent,
        const std::string filename,
        const bool logOnlyError ) : mDebugEnabled ( debugEnabled ),
    mlogDestination ( logDest ),
    mFilename (filename, std::ofstream::out | std::ofstream::trunc),
    mLogOnlyError ( logOnlyError ),
    mSilent ( silent ),
    mLogOn ( true )
{
    mMsgLogLvl = DLT_LOG_INFO;
    mDltContext = { 0 };
    mDltContextData = { nullptr };
    mNoDltContextData.logLevel = DLT_LOG_INFO;
    mNoDltContextData.traceStatus = DLT_TRACE_STATUS_OFF;
    mNoDltContextData.pHandle=nullptr;
    
#ifdef DK_SLOG2_ENABLED
    slog2BufferConfig = { 0 };
    slog2BufferHandle[0U] = nullptr;

    slog2BufferConfig.buffer_set_name = __progname;
    slog2BufferConfig.num_buffers = 1;
    slog2BufferConfig.buffer_config[0].buffer_name = __progname;
    slog2BufferConfig.buffer_config[0].num_pages = 8;
#endif
    if ( (true == mDebugEnabled) && (mlogDestination == eLogDestination_DLT) )
    {
        (void)dlt_register_app ( pAppId, pDescription );
        //register a default context
        (void) dlt_register_context ( &mDltContext, "DEFA", "Default Context registered by Logger Class" );
    }
    else if ( mDebugEnabled )
    {
        mAppId = std::string ( pAppId );
        mNoDltContextData.logLevel = DLT_LOG_INFO;
        mNoDltContextData.traceStatus = DLT_TRACE_STATUS_OFF;

        if ( mlogDestination == eLogDestination_Console )
        {
            if ( !mSilent )
            {
                std::cout << "\x1B[0;36m[DLT] Registering AppID " << pAppId << " , " << pDescription << "\x1B[0m" << &std::endl;
            }
        }

#ifdef DK_SLOG2_ENABLED
        else if ( mlogDestination == eLogDestination_Slog2 )
        {
            if ( -1 == slog2_register ( &slog2BufferConfig, slog2BufferHandle, 0U ) )
            {
                std::cout <<  "Error registering slogger2 buffer!" << &std::endl;
            }
            else
            {
                ( void ) slog2_set_verbosity ( slog2BufferHandle[0], static_cast<uint8_t>(SLOG2_DEBUG2) );
            }
        }

#endif
        else
        {
            if ( !mFilename.is_open() )
            {
                std::cout << "\x1B[0;31m[DLT] Cannot open file for logging! Using CommandLine\x1B[0m" << &std::endl;
                mlogDestination = eLogDestination_Console;
            }
            else
            {
                mFilename << now() << "[DLT] Registering AppID " << pAppId << " , " << pDescription << &std::endl;
            }
        }
    }
    else 
    {
        //no code
    }
}

Logger::~Logger()
{
    if ( (nullptr != mpDLTWrapper) && (true == mDebugEnabled) && ( mlogDestination == eLogDestination_DLT ) )
    {
        mpDLTWrapper->unregisterContext ( mDltContext );
        mpDLTWrapper = NULL;
    }
    else if ( (nullptr != mpDLTWrapper) && (true == mDebugEnabled) && ( mlogDestination == eLogDestination_File ) )
    {
        try {   
            mFilename.close();
        } catch(const std::bad_cast& e) {
            std::cout << e.what() << '\n';
        }
    }

#ifdef DK_SLOG2_ENABLED
    else if ( (nullptr != mpDLTWrapper) && (true == mDebugEnabled) && ( mlogDestination == eLogDestination_Slog2 ) )
    {
        ( void ) slog2_reset();
    }

#endif
    else
    {
    }
}

void Logger::unregisterContext ( DltContext &handle ) const
{
    if ( (true == mDebugEnabled) && (mlogDestination == eLogDestination_DLT ))
    {
        (void) dlt_unregister_context ( &handle );
    }
}

void Logger::deInit()
{
    if ( mDebugEnabled )
    {
        unregisterContext ( mDltContext );
    }
}

void Logger::registerContext ( DltContext &handle, const char * const pContextId, const char * const pDescription )
{
    if ( (true == mDebugEnabled) && (mlogDestination == eLogDestination_DLT ))
    {
        (void) dlt_register_context ( &handle, pContextId, pDescription );
    }
    else if ( mDebugEnabled )
    {
        (void)mMapContext.insert ( std::make_pair ( &handle, std::string ( pContextId ) ) );
        (void)mMapContextLevel.insert ( std::make_pair ( &handle, DLT_LOG_VERBOSE ) );

        if ( mlogDestination == eLogDestination_Console )
        {
            if ( !mSilent )
            {
                std::cout << "\x1B[0;36m[DLT] Registering Context " << pContextId << " , " << pDescription << "\x1B[0m" << &std::endl;
            }
        }
        else
        {
            mFilename << now() << "[DLT] Registering Context " << pContextId << " , " << pDescription << &std::endl;
        }
    }
    else
    {
        //no code
    }
}

void Logger::registerContext ( DltContext &handle, const char * const pContextId, const char * const pDescription, const DltLogLevelType level, const DltTraceStatusType status )
{
    if ( (true == mDebugEnabled) && (mlogDestination == eLogDestination_DLT ))
    {
        (void)dlt_register_context_ll_ts ( &handle, pContextId, pDescription, static_cast<int32_t>(level), static_cast<int32_t>(status) );
    }
    else if ( mDebugEnabled )
    {
        (void)mMapContext.insert ( std::make_pair ( &handle, std::string ( pContextId ) ) );
        (void)mMapContextLevel.insert ( std::make_pair ( &handle, level ) );

        if ( mlogDestination == eLogDestination_Console )
        {
            if ( !mSilent )
            {
                std::cout << "\x1B[0;36m[DLT] Registering Context " << pContextId << " , " << pDescription << "\x1B[0m" << &std::endl;
            }
        }
        else
        {
            mFilename << now() << " [DLT] Registering Context " << pContextId << " , " << pDescription << &std::endl;
        }
    }
    else 
    {
        //no code
    }
}

bool Logger::init ( const DltLogLevelType loglevel, DltContext *pContext )
{
    bool ret = true;
    mGuardMutex.lock();

    if ( mlogDestination == eLogDestination_DLT )
    {
        if ( pContext == nullptr )
        {
            pContext = &mDltContext;
        }

        if ( dlt_user_is_logLevel_enabled ( pContext, loglevel ) == DLT_RETURN_TRUE )
        {
            if ( dlt_user_log_write_start ( pContext, &mDltContextData, loglevel ) < 0 )
            {
                mGuardMutex.unlock();
                ret = false;
            }
        }
        else
        {
            mGuardMutex.unlock();
            ret = false;
        }
    }
    else
    {
        (void) initNoDlt ( loglevel, pContext );
    }

    return ret;
}

void Logger::send()
{
    if ( mlogDestination == eLogDestination_DLT )
    {
        (void) dlt_user_log_write_finish ( &mDltContextData );
    }
    else
    {
        if ( ( mlogDestination == eLogDestination_Console ) && (mLogOn == true) )
        {
            std::cout << mNoDltContextData.buffer.str().c_str() << '\n' << &std::flush;

        }

#ifdef DK_SLOG2_ENABLED
        else if ( ( mlogDestination == eLogDestination_Slog2 ) && (mLogOn == true) )
        {
            switch ( mMsgLogLvl )
            {
                case DLT_LOG_FATAL:
                    ( void ) slog2c ( slog2BufferHandle[0], 0U, static_cast<uint8_t>(SLOG2_CRITICAL), mNoDltContextData.buffer.str().c_str() );
                    break;

                case DLT_LOG_ERROR:
                    ( void ) slog2c ( slog2BufferHandle[0], 0U, static_cast<uint8_t>(SLOG2_ERROR), mNoDltContextData.buffer.str().c_str() );
                    break;

                case DLT_LOG_WARN:
                    ( void ) slog2c ( slog2BufferHandle[0], 0U, static_cast<uint8_t>(SLOG2_WARNING), mNoDltContextData.buffer.str().c_str() );
                    break;

                case DLT_LOG_INFO:
                    ( void ) slog2c ( slog2BufferHandle[0], 0U, static_cast<uint8_t>(SLOG2_INFO), mNoDltContextData.buffer.str().c_str() );
                    break;

                case DLT_LOG_DEBUG:
                    ( void ) slog2c ( slog2BufferHandle[0], 0U, static_cast<uint8_t>(SLOG2_DEBUG1), mNoDltContextData.buffer.str().c_str() );
                    break;

                case DLT_LOG_VERBOSE:
                    ( void ) slog2c ( slog2BufferHandle[0], 0U, static_cast<uint8_t>(SLOG2_DEBUG2), mNoDltContextData.buffer.str().c_str() );
                    break;

                default:
                    break;
            }
        }

#endif
        else if ( mLogOn )
        {
            mFilename << now() << mNoDltContextData.buffer.str().c_str() << &std::endl;
        }
        else 
        {
            //no code
        }

        mNoDltContextData.buffer.str ( "" );
        mNoDltContextData.buffer.clear();
    }

    mGuardMutex.unlock();
}

void Logger::append ( const int8_t value )
{
    if ( mlogDestination == eLogDestination_DLT )
    {
        (void) dlt_user_log_write_int8 ( &mDltContextData, value );
    }
    else
    {
        appendNoDLT ( value );
    }
}

void Logger::append ( const uint8_t value )
{
    if ( mlogDestination == eLogDestination_DLT )
    {
        (void) dlt_user_log_write_uint8 ( &mDltContextData, value );
    }
    else
    {
        appendNoDLT ( value );
    }
}

void Logger::append ( const int16_t value )
{
    if ( mlogDestination == eLogDestination_DLT )
    {
        (void) dlt_user_log_write_int16 ( &mDltContextData, value );
    }
    else
    {
        appendNoDLT ( value );
    }
}

void Logger::append ( const uint16_t value )
{
    if ( mlogDestination == eLogDestination_DLT )
    {
        (void) dlt_user_log_write_uint16 ( &mDltContextData, value );
    }
    else
    {
        appendNoDLT ( value );
    }
}

void Logger::append ( const int32_t value )
{
    if ( mlogDestination == eLogDestination_DLT )
    {
        (void) dlt_user_log_write_int32 ( &mDltContextData, value );
    }
    else
    {
        appendNoDLT ( value );
    }
}

void Logger::append ( const uint32_t value )
{
    if ( mlogDestination == eLogDestination_DLT )
    {
        (void) dlt_user_log_write_uint32 ( &mDltContextData, value );
    }
    else
    {
        appendNoDLT ( value );
    }
}

void Logger::append ( const std::string &value )
{
    append ( value.c_str() );
}

void Logger::append ( const bool value )
{
    if ( mlogDestination == eLogDestination_DLT )
    {
        (void) dlt_user_log_write_bool ( &mDltContextData, static_cast<uint8_t> ( value ) );
    }
    else
    {
        appendNoDLT ( value );
    }
}

void Logger::append ( const int64_t value )
{
    if ( mlogDestination == eLogDestination_DLT )
    {
        (void)dlt_user_log_write_int64 ( &mDltContextData, value );
    }
    else
    {
        appendNoDLT ( value );
    }
}

void Logger::append ( const uint64_t value )
{
    if ( mlogDestination == eLogDestination_DLT )
    {
        (void) dlt_user_log_write_uint64 ( &mDltContextData, value );
    }
    else
    {
        appendNoDLT ( value );
    }
}

void Logger::append ( const std::vector<uint8_t> &data )
{
    if ( mlogDestination == eLogDestination_DLT )
    {
        std::vector<uint8_t> nonConstdata = data;
        (void)dlt_user_log_write_raw ( &mDltContextData, static_cast<void *> (nonConstdata.data()), static_cast<uint16_t>(nonConstdata.size()) );
    }
    else
    {
        for (uint8_t n : data)
            mNoDltContextData.buffer << static_cast<uint32_t>(n);
    }
}
#else
Logger::Logger ( const char *const pAppId,
        const char * const pDescription,
        const bool debugEnabled,
        const eLogDestination_t logDest,
        const bool silent,
        const std::string filename,
        bool logOnlyError ) : mDebugEnabled ( debugEnabled ),
    mlogDestination ( logDest ),
    mFilename (filename, std::ofstream::out | std::ofstream::trunc),
    mLogOnlyError ( logOnlyError ),
    mSilent ( silent ),
    mLogOn ( true )
{
    mAppId = std::string ( pAppId );
    mDltContext = DltContext();
    mDltContextData = DltContextData();
    mNoDltContextData.logLevel = DLT_LOG_INFO;
    mNoDltContextData.traceStatus = DLT_TRACE_STATUS_OFF;
    mNoDltContextData.pHandle=nullptr;
    mMsgLogLvl = DLT_LOG_INFO;
#ifdef DK_SLOG2_ENABLED	
	slog2BufferConfig = slog2_buffer_set_config_t();
    slog2BufferHandle[0U] = nullptr;
    slog2BufferConfig.buffer_set_name = __progname;
    slog2BufferConfig.num_buffers = 1;
    slog2BufferConfig.buffer_config[0].buffer_name = __progname;
    slog2BufferConfig.buffer_config[0].num_pages = 8;
#endif
    if ( logDest == eLogDestination_DLT )
    {
        std::cout << "\x1B[0;31m[DLT] Cannot Use DLT Logging, disabled during build! Using CommandLine\x1B[0m" << std::endl;
        mlogDestination = eLogDestination_Console;
    }

    if ( mDebugEnabled )
    {
        if ( mlogDestination == eLogDestination_Console )
        {
            if ( !mSilent )
            {
                std::cout << "\x1B[0;36m[DLT] Registering AppID " << pAppId << " , " << pDescription << "\x1B[0m" << std::endl;
            }
        }

#ifdef DK_SLOG2_ENABLED
        else if ( mlogDestination == eLogDestination_Slog2 )
        {
            if ( -1 == slog2_register ( &slog2BufferConfig, slog2BufferHandle, 0 ) )
            {
                std::cout <<  "Error registering slogger2 buffer!" << std::endl;
            }
            else
            {
                ( void ) slog2_set_verbosity ( slog2BufferHandle[0], SLOG2_DEBUG2 );
            }
        }

#endif
        else
        {
            if ( !mFilename.is_open() )
            {
                std::cout << "\x1B[0;31m[DLT] Cannot open file for logging! Using CommandLine\x1B[0m" << std::endl;
                mlogDestination = eLogDestination_Console;
            }
            else
            {
                mFilename << now() << "[DLT] Registering AppID " << pAppId << " , " << pDescription << std::endl;
            }
        }
    }
}

Logger::~Logger()
{
    if ((nullptr != mpDLTWrapper) && (true == mDebugEnabled) && ( mlogDestination == eLogDestination_File ))
    {
        try {   
            mFilename.close();
        } catch(const std::bad_cast& e) {
            std::cout << e.what() << '\n';
        }
    }

#ifdef DK_SLOG2_ENABLED
    else if ((nullptr != mpDLTWrapper) && (true == mDebugEnabled) && ( mlogDestination == eLogDestination_Slog2 ))
    {
        ( void ) slog2_reset();
    }

#endif
    else
    {
    }
}

void Logger::registerContext ( DltContext &handle, const char * const pContextId, const char * const pDescription )
{
    if ( mDebugEnabled )
    {
        (void)mMapContext.insert ( std::make_pair ( &handle, std::string ( pContextId ) ) );
        (void)mMapContextLevel.insert ( std::make_pair ( &handle, DLT_LOG_VERBOSE ) );

        if ( mlogDestination == eLogDestination_Console )
        {
            if ( !mSilent )
            {
                std::cout << "\x1B[0;36m[DLT] Registering Context " << pContextId << " , " << pDescription << "\x1B[0m" << std::endl;
            }
        }
        else
        {
            mFilename << now() << "[DLT] Registering Context " << pContextId << " , " << pDescription << std::endl;
        }
    }
}

void Logger::registerContext ( DltContext &handle, const char * const pContextId, const char * const pDescription, const DltLogLevelType level, const DltTraceStatusType status )
{
    if ( mDebugEnabled )
    {
        mMapContext.insert ( std::make_pair ( &handle, std::string ( pContextId ) ) );
        (void)mMapContextLevel.insert ( std::make_pair ( &handle, level ) );

        if ( mlogDestination == eLogDestination_Console )
        {
            if ( !mSilent )
            {
                std::cout << "\x1B[0;36m[DLT] Registering Context " << pContextId << " , " << pDescription << "\x1B[0m" << std::endl;
            }
        }
        else
        {
            mFilename << now() << " [DLT] Registering Context " << pContextId << " , " << pDescription << std::endl;
        }
    }
}

void Logger::unregisterContext ( DltContext &handle ) const
{
}

bool Logger::init ( const DltLogLevelType loglevel, DltContext *pContext )
{
    mGuardMutex.lock();
    (void)initNoDlt ( loglevel, pContext );
    return true;
}

void Logger::deInit()
{
}

void Logger::send()
{
    if ( ( mlogDestination == eLogDestination_Console ) && (true == mLogOn) )
    {
        std::cout << mNoDltContextData.buffer.str().c_str() << std::endl;
    }

#ifdef DK_SLOG2_ENABLED
    else if ( ( mlogDestination == eLogDestination_Slog2 ) && (true == mLogOn) )
    {
        switch ( mMsgLogLvl )
        {
            case DLT_LOG_FATAL:
                ( void ) slog2c ( slog2BufferHandle[0], 0U, static_cast<uint8_t>(SLOG2_CRITICAL), mNoDltContextData.buffer.str().c_str() );
                break;

            case DLT_LOG_ERROR:
                ( void ) slog2c ( slog2BufferHandle[0], 0U, static_cast<uint8_t>(SLOG2_ERROR), mNoDltContextData.buffer.str().c_str() );
                break;

            case DLT_LOG_WARN:
                ( void ) slog2c ( slog2BufferHandle[0], 0U, static_cast<uint8_t>(SLOG2_WARNING), mNoDltContextData.buffer.str().c_str() );
                break;

            case DLT_LOG_INFO:
                ( void ) slog2c ( slog2BufferHandle[0], 0U, static_cast<uint8_t>(SLOG2_INFO), mNoDltContextData.buffer.str().c_str() );
                break;

            case DLT_LOG_DEBUG:
                ( void ) slog2c ( slog2BufferHandle[0], 0U, static_cast<uint8_t>(SLOG2_DEBUG1), mNoDltContextData.buffer.str().c_str() );
                break;

            case DLT_LOG_VERBOSE:
                ( void ) slog2c ( slog2BufferHandle[0], 0U, static_cast<uint8_t>(SLOG2_DEBUG2), mNoDltContextData.buffer.str().c_str() );
                break;

            default:
                break;
        }
    }

#endif
    else if ( mLogOn )
    {
        mFilename << now() << mNoDltContextData.buffer.str().c_str() << std::endl;
    }
    else
    {
        /*Do nothing*/
    }

    mNoDltContextData.buffer.str ( "" );
    mNoDltContextData.buffer.clear();
    mGuardMutex.unlock();
}

void Logger::append ( const int8_t value )
{
    appendNoDLT ( value );
}

void Logger::append ( const uint8_t value )
{
    appendNoDLT ( value );
}

void Logger::append ( const int16_t value )
{
    appendNoDLT ( value );
}

void Logger::append ( const uint16_t value )
{
    appendNoDLT ( value );
}

void Logger::append ( const int32_t value )
{
    appendNoDLT ( value );
}

void Logger::append ( const uint32_t value )
{
    appendNoDLT ( value );
}

void Logger::append ( const std::string &value )
{
    append ( value.c_str() );
}

void Logger::append ( const bool value )
{
    appendNoDLT ( value );
}

void Logger::append ( const int64_t value )
{
    appendNoDLT ( value );
}

void Logger::append ( const uint64_t value )
{
    appendNoDLT ( value );
}

void Logger::append ( const std::vector<uint8_t> &data )
{
   for (uint8_t n : data)
        mNoDltContextData.buffer << static_cast<uint32_t>(n);
}
#endif

// C Wrappers
extern "C" void dk_Logger_createInstance ( const char *const pName, const char *const pDesc, const uint8_t bEnable, const dk::Logger::eLogDestination_t dest, const uint8_t bSilent, const char *const pFile, const uint8_t bOnlyError )
{
    if ( pFile != NULL)
    {
        (void)dk::Logger::createInstance ( pName, pDesc, static_cast<bool>(bEnable), dest, static_cast<bool>(bSilent), std::string ( pFile ), static_cast<bool>(bOnlyError) );
    }
    else
    {
        (void)dk::Logger::createInstance(pName, pDesc, static_cast<bool>(bEnable), dest, static_cast<bool>(bSilent), std::string(""), static_cast<bool>(bOnlyError));
    }
}

extern "C" void dk_Logger_registerContext ( DltContext * const pHandle, const char * const pContextId, const char * const pDescription, const DltLogLevelType logLevel, const DltTraceStatusType traceStatus )
{
    dk::Logger::getInstance()->registerContext ( *pHandle, pContextId, pDescription, logLevel, traceStatus );
}

extern "C" void dk_Logger_unregisterContext ( DltContext * const pHandle )
{
    dk::Logger::getInstance()->unregisterContext ( *pHandle );
}

extern "C" void dk_Logger_log ( DltContext *const pHandle, const DltLogLevelType logLevel, const char *const pFileName, const char *const pDelim1,
        const uint32_t lineNo, const char *const pDelim2, const char *const pFuncName, const char *const pDelim3, const char *fmt, ... )
{
    std::stringstream ss;
	std::stringstream tid;
    dk::Logger *const inst ( dk::Logger::getInstance() );
    const bool init_status = inst->init ( logLevel, pHandle );

    if((true == inst->getEnabled()) && (true == init_status))
    {
        ss << getpid();
	    tid << gettid();
        const std::string pidInfo = "(" + ss.str() + "|"  + tid.str() + ") ";
        inst->append ( pidInfo );
        inst->append ( inst->getFileName ( pFileName ) );
        inst->append ( pDelim1 );
        inst->append ( lineNo );
        inst->append ( pDelim2 );
        inst->append ( pFuncName );
        inst->append ( pDelim3 );
        char buffer[1024] = {0};
        va_list ap;
        va_start ( ap, fmt );
        (void)vsnprintf ( &buffer[0], 1024U, fmt, ap );
        va_end ( ap );
        inst->append ( std::string ( buffer ) );
        inst->send();
    }
}
