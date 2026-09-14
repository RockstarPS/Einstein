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

#ifndef DK_RUNTIME_PARSERIF_H
#define DK_RUNTIME_PARSERIF_H

#include <cstdint>
#include <string>
#include <vector>
#include "serdes/dk_runtime_primitive_types.h"
#include "ini/SimpleIni.h"

namespace dk
{
namespace runtime
{
namespace core
{
class ParserIf
{
    public:
        ParserIf();
        ~ParserIf();

        bool loadConfiguration ( std::string str );
        bool getAllSections ( std::vector<std::string> &sectionList );
        bool getAllKeysFromSection ( std::string section, std::vector<std::string> &keyList );
        bool getAllValuesForKey ( std::string section, std::string key, std::vector<std::string> &valueList );
        const char *getStringValue(std::string section, std::string key);
        bool getBoolValue ( std::string section, std::string key, bool defValue = false );
        int32_t getInt32Value ( std::string section, std::string key, int32_t defValue = 0 );
        float64_t getFloat64Value ( std::string section, std::string key, float64_t defValue = 0.0F );

    private:
        CSimpleIniA mParserInst;
        bool mIsConfigurationLoaded;
};

}
}
}

#endif //DK_RUNTIME_PARSERIF_H
