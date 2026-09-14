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
//  Filename    : rc_localization.h
//  Description : Rendercore text localization object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
///@file rc_localization.h
/// \brief 			Rendercore text localization object
#ifndef rc_localization_h
#define rc_localization_h

#include <cstdint>

namespace rendercore_engine
{
    /// \ingroup Internal
    /// @{
    struct rdf_localization;
    struct rdf_lang_data;
    /// <summary>	
    /// Text localization base class
    /// < / summary>	
    class rc_lang_data
    {
    public:
        size_t langDataLength = 0U;          ///< Language file read length in bytes
        rdf_lang_data* langData = nullptr;  ///< Language file base pointer
        std::u16string langString;            ///< Language name as string
        std::uint32_t* stringMapTable = nullptr; ///< Translated string mapping table[stringArraySize]
        void* stringTable = nullptr;     ///< Translated string table[stringArraySize].
    };
    /// <summary>	
	/// Text localization base class
	/// < / summary>	
	class rc_localization
    {
    private:
        std::uint32_t curLanguage = 0U;
        size_t locnDataLength = 0U;                  ///< Localization file read length in bytes
        rdf_localization const * locnData = nullptr; ///< Localizatyion file base pointer
        std::uint32_t* tidMapTable = nullptr;       ///< Text Id to key string mapping table[numTextIDs]
        void* tidKeyTable = nullptr;                ///< Text id key table[numTextIDs].
        rc_lang_data * language = nullptr;          ///< Language data table[numLangs]
        bool locz_comp_hint = false;                ///< hints whether the loalization data is gzip compressed or not
        uint32_t assetClientId = RC_INVALID_ASSET_CLIENT_ID;        ///< Client Id to access the asset
        gfx3d_scg_project* parent = nullptr;        ///< Parent object
        /// <summary>
        /// Loads the language bin file for specified language
        /// </summary>
        /// <param name="p_basepath">base path (resource path + p_basepath is used to construct actual path). path shall end with with '/' </param>
        /// <param name="p_language">language id/index to be laoded</param>
        /// <returns>returns true on success</returns>
        bool load_language(const std::string p_basepath, const std::uint32_t p_language);
        static bool GetStdU16String(const void* const p_ichar, std::uint32_t p_icharLen, const std::uint32_t p_icharSize, std::u16string& p_out);
        static bool StringTableLookup(const void* const p_istrtable, const std::uint32_t p_itblIndex, std::uint32_t p_istrLen, const std::uint32_t p_icharSize, std::u16string& p_out);
    public:
        /// <summary>
        /// constructor
        /// </summary>
        /// <param name="p_state">data compresstion state</param>
        rc_localization(gfx3d_scg_project * const p_parent, const bool p_hint = false);
        /// <summary>
        /// distructor, releases all memory used
        /// </summary>
        virtual ~rc_localization();
        /// <summary>
        /// Returns the total languages in translation table
        /// </summary>
        /// <returns>returns the index of the selected lanuage</returns>
        std::uint32_t GetNumberOfLanguages() const;
        /// <summary>
        /// Returns the currently set language index (0 to GetNumberOfLanguages()-1)
        /// </summary>
        /// <returns>returns the index of the selected lanuage</returns>
        std::uint32_t GetCurrentLanguage() const;
        /// <summary>
        /// Sets the current lanugage by index
        /// </summary>
        /// <param name="p_lang">language index to be set as current</param>
        /// <returns>returns true if active lanuage is changed</returns>
        bool SetCurrentLanguage(const std::uint32_t p_lang);
        /// <summary>
        /// Returns the currently set language name
        /// </summary>
        /// <returns>returns the name of active lanuage</returns>
        std::u16string GetCurrentLanguageName();
        /// <summary>
        /// Returns the all language names as a list
        /// </summary>
        /// <returns>returns the names of all lanuages in translation table</returns>
        std::vector<std::u16string> GetLanguagesList();
        /// <summary>
        /// Gets the translated string by its translation ID or Key index
        /// </summary>
        /// <param name="p_tid">translation ID or Key index</param>
        /// <returns>returns the srtring corresponding to requested key in currently selected language</returns>
        std::u16string GetTranslation(const std::uint32_t p_tid);
        /// <summary>
        /// Gets the translated string by its translation ID or Key index
        /// </summary>
        /// <param name="p_tid">translation ID or Key index</param>
        /// <param name="p_lang">language index</param>
        /// <returns>returns the srtring corresponding to requested key in requested language</returns>
        std::u16string GetTranslation(const std::uint32_t p_tid, const std::uint32_t p_lang);
        /// <summary>
        /// Gets the TextID Index by a text/translation ID or Key string value
        /// </summary>
        /// <param name="p_tid">translation ID or Key value string</param>
        /// <returns>returns the TextID Index</returns>
        std::uint32_t GetTranslationKeyIndex(const std::u16string& p_tid);
        /// <summary>
        /// Translate the passed string.
        /// If the passed string has a Translation Key emedded with the help of identifier letter '%'
        /// Anything enclosed between two '%' will be treated as a translation key (%<trans key>%)
        /// and then that will be replaced by its translated value from currently selected language
        /// "%%" will be replaced with a '%' character
        /// e.g. L"Odo 987 %tid_km%" --> here L"tid_km" will identified as a embedded translation key
        /// e.g. L"Power 98%%" --> No embedded translation keys, returns the string as L"Power 98%"
        /// </summary>
        /// <param name="p_str">String with embedded translation keys</param>
        /// <returns>returns the srtring replacing all embedded keys with its translation</returns>
        std::u16string Translate(const std::u16string& p_str);
        /// <summary>
        /// Loads the localization data from default folder (same as calling Load("localization/", p_flag);)
        /// localization data will be looked at <resource path>/localization/localization.bin
        /// language data will be looked at <resource path>/localization/languageN.bin, where N changed from 0 to (Number of language -1)
        /// </summary>
        /// <param name="p_flag">0 to (Number of language -1) will restrict loading only to the language index, anyother value loads all the languages</param>
        /// <returns>returns true if load done</returns>
        bool Load(const std::uint32_t p_flag);
        /// <summary>
        /// Loads the localization data from specified basepath, rather than default "localization/"
        /// localization data will be looked at <resource path>/localization/localization.bin
        /// language data will be looked at <resource path>/localization/languageN.bin, where N changed from 0 to (Number of language -1)
        /// </summary>
        /// <param name="p_basepath">base path (resource path + p_basepath is used to construct actual path). path shall end with with '/' </param>
        /// <param name="p_flag">0 to (Number of language -1) will restrict loading only to the language index, anyother value loads all the languages</param>
        /// <returns>returns true if load done</returns>
        bool Load(const std::string p_basepath, const std::uint32_t p_flag);
        /// <summary>
        /// UnLoads the localization data
        /// </summary>
        /// <param name="p_flag">0 to (Number of language -1) unloads specified language, any other value unloads everything</param>
        /// <returns>returns true if unload done</returns>
        bool UnLoad(const std::uint32_t p_flag);
        /// <summary>
        /// Returns the alignment to be swapped for the active language or not
        /// </summary>
        /// <returns>returns true if alignment to be swapped</returns>
        bool IsSwapAlignment() const;
        /// <summary>
        /// Returns the alignment to be swapped for the passed language or not
        /// </summary>
        /// <param name="p_lang">language index</param>
        /// <returns>returns true if alignment to be swapped</returns>
        bool IsSwapAlignment(const std::uint32_t p_lang) const;
    };
    /// @}
}
#endif
