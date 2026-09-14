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

#include <string>
#include <cstring>
#include <chrono>
#ifdef _WIN32
#include <unistd.h>
#endif
#include "dk_runtime_parserif.h"
#include "dk_logger.h"

LOG_IMPORT_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

ParserIf::ParserIf()
{
    mParserInst.SetUnicode();
    mParserInst.SetMultiKey();
    mParserInst.SetMultiLine();

    mIsConfigurationLoaded = false;
}

ParserIf::~ParserIf()
{
}

bool ParserIf::loadConfiguration ( std::string str )
{
    SI_Error rc = mParserInst.LoadFile ( str.c_str() );

    if ( rc < SI_OK )
    {
        mIsConfigurationLoaded = false;
        LOGE ( &gRTELogContext, "Loading of configuration file failed ", str );
    }
    else
    {
        mIsConfigurationLoaded = true;
    }

    return mIsConfigurationLoaded;
}

bool ParserIf::getAllSections ( std::vector<std::string> &sectionList )
{
    bool ret = true;

    if ( !mIsConfigurationLoaded )
    {
        ret = false;
    }
    else
    {
        CSimpleIniA::TNamesDepend sections;
        mParserInst.GetAllSections ( sections );

    	CSimpleIniA::TNamesDepend::const_iterator i;

    	for ( i = sections.begin(); i != sections.end(); ++i )
    	{
        	sectionList.push_back ( std::string ( i->pItem ) );
    	}
	}

    return ret;
}

bool ParserIf::getAllKeysFromSection ( std::string section, std::vector<std::string> &keyList )
{
    bool ret = false;

    if ( !mIsConfigurationLoaded )
    {
        ret = false;
    }
    else
    {
        CSimpleIniA::TNamesDepend keys;

        if ( true == mParserInst.GetAllKeys ( section.c_str(), keys ) )
        {
            CSimpleIniA::TNamesDepend::const_iterator i;

            for ( i = keys.begin(); i != keys.end(); ++i )
            {
                keyList.push_back ( std::string ( i->pItem ) );
            }

            ret = true;
        }
    }

    return ret;
}

bool ParserIf::getAllValuesForKey ( std::string section, std::string key, std::vector<std::string> &valueList )
{
    bool ret = false;

    if ( !mIsConfigurationLoaded )
    {
        ret = false;
    }
    else
    {
        CSimpleIniA::TNamesDepend values;

        if ( true == mParserInst.GetAllValues ( ( section.c_str() ), ( key.c_str() ), values ) )
        {
            CSimpleIniA::TNamesDepend::const_iterator i;

            for ( i = values.begin(); i != values.end(); ++i )
            {
                valueList.push_back ( std::string ( i->pItem ) );
            }

            ret = true;
        }
    }

    return ret;
}

bool ParserIf::getBoolValue ( std::string section, std::string key, bool defValue )
{
    bool ret = false;

    if ( !mIsConfigurationLoaded )
    {
        ret = false;
    }
    else
    {
        ret =  mParserInst.GetBoolValue ( section.c_str(), key.c_str(), defValue );

    }

    return ret;
}

int32_t ParserIf::getInt32Value ( std::string section, std::string key, int32_t defValue )
{
    int32_t ret = defValue;

    if ( !mIsConfigurationLoaded )
    {
        ret = defValue;
    }
    else
    {
        ret = mParserInst.GetLongValue ( section.c_str(), key.c_str(), defValue );

    }

    return ret;
}

float64_t ParserIf::getFloat64Value ( std::string section, std::string key, float64_t defValue )
{
    float64_t ret = defValue;

    if ( !mIsConfigurationLoaded )
    {
        ret = defValue;
    }
    else
    {
        ret = mParserInst.GetDoubleValue ( section.c_str(), key.c_str(), defValue );

    }

    return ret;
}
const char *ParserIf::getStringValue(std::string section, std::string key)
{
    if (!mIsConfigurationLoaded)
        return NULL;

    return mParserInst.GetValue(section.c_str(), key.c_str(), NULL);
}
