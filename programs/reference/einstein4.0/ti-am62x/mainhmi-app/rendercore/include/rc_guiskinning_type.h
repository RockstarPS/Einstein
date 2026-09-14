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
//  Description : classes to describe the gui skinning table binary data.
//  Created on  : 02-Jan-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_guiskinning_type_h
#define rc_guiskinning_type_h

#include <cstdint>

#define RC_GSKTB_HKEY (0x534B5442U)
#define RC_GSKIN_HKEY (0x534B494EU)

namespace rendercore_engine
{
    constexpr uint32_t RC_GSKIN_VERSION(const uint32_t p_major, const uint32_t p_minor, const uint32_t p_patch)
    {
        return (static_cast<uint32_t>(p_major) << 24U)
            | (static_cast<uint32_t>(p_minor) << 16U)
            | (static_cast<uint32_t>(p_patch));
    }
    // following types for binary data encoding & decoding

    /// <summary>
    /// Type of skinning entry. Based on this the data is decoded and applied
    /// </summary>
    enum class rc_guiskin_etype
    {
        UniformInt,     ///< Data entry is to control uniform of a material
        UniformS2d,     ///< Data entry is to control uniform of a material
        UniformC2d,     ///< Data entry is to control uniform of a material
        UniformFloat,   ///< Data entry is to control uniform of a material    
        UniformVec2,    ///< Data entry is to control uniform of a material
        UniformVec3,   ///< Data entry is to control uniform of a material
        UniformVec4     ///< Data entry is to control uniform of a material
    };

    /// <summary>
    /// Specifies a GUI skinning transition
    /// </summary>
    struct rc_guiskin_transition
    {
        float32_t startDelay; ///< Starting delay to be applied in seconds
        float32_t duration;   ///< Duration of the transition in seconds. Total duration will be sum of startDelay+duration
        int8_t startSkin; ///< Index of the starting skin. -1 means any skin
        int8_t endSkin;   ///< Index of the ending skin. -1 means any skin
        uint16_t easing;  ///< Easing curve to be used (will be one of MdlEasingCurve)
    };
    /// <summary>
    /// Specifies skinning data for a node
    /// </summary>
    struct rc_guiskin_node
    {
        int32_t nodeIndex;      ///< index of the node to be controlled
        int32_t scale;          ///< Data entry is to control scaling of a node
        int32_t rotation;       ///< Data entry is to control rotation of a node
        int32_t translation;    ///< Data entry is to control translation of a node
        int16_t objOpacity;     ///< Data entry is to control opacity of a node (-1 - no control, 0-255 --> 0.0f to 1.0f)
        int8_t flipBookIndex;   ///< Data entry is to control flipbook index of a node (-2 - no control, -1 - all nodes, >=0 selected nodes)
        int8_t visibility;      ///< Data entry is to control visibility of a node (-1 - no control, 0-hide, 1-show)
    };
    /// <summary>
    /// Specifies skinning data for a text node
    /// </summary>
    struct rc_guiskin_text
    {
        int32_t nodeIndex;  ///< index of the node to be controlled
        int32_t drawColor;  ///< Data entry is to control draw color of a text node
        int16_t fontIndex;  ///< Data entry is to control font of a text node
        int8_t horzAlign;   ///< Data entry is to control horizontal alignment of a text node
        int8_t vertAlign;   ///< Data entry is to control vertical alignment of a text node
    };
    /// <summary>
    /// Specifies skinning data for a layout node
    /// </summary>
    struct rc_guiskin_layout
    {
        int32_t nodeIndex;  ///< index of the node to be controlled
        int8_t horzAlign;   ///< Data entry is to control horizontal alignment of a layout node
        int8_t vertAlign;   ///< Data entry is to control vertical alignment of a layout node
        int8_t direction;   ///< Data entry is to control direction of a layout node
        int8_t unused1;     ///< padding byte
    };
    /// <summary>
    /// Specifies skinning data for a primitive
    /// </summary>
    struct rc_guiskin_primitive
    {
        int32_t nodeIndex;  ///< index of the node to be controlled
        int16_t primitive;  ///< primitive index if applicable. -1 if not applicable
        int16_t material;   ///< Data entry is to control material of a primitive
    };
    /// <summary>
    /// Specifies skinning data for a material
    /// </summary>
    struct rc_guiskin_material
    {
        int32_t nodeIndex;      ///< index of the node to be controlled
        int16_t uniformsIndex;  ///< starting index of uniforms data in rc_guiskin_table::ufmEntries
        int8_t uniformsLength;  ///< number of entries to be applicable from uniformsIndex
        int8_t primitive;       ///< primitive index of the node to pick the material
    };
    /// <summary>
    /// Specifies a single skinning entry or cell value
    /// </summary>
    struct rc_guiskin_ufmentry
    {
        int32_t  dataValue; ///< Data value incase of int type or an index to rc_guiskin_table::fltdata incase data is of float32_t type
        uint8_t  entryType; ///< Type of entry as specified by rc_guiskin_etype
        int16_t  ufmValue;  ///< entryType = Uniform then its an index to rc_guiskin_table::ufmdata incase data is of uniform type
    };
    /// <summary>
    /// Specifies skinning data for a camera
    /// </summary>
    struct rc_guiskin_camera
    {
        int32_t camIndex;      ///< index of the camera to be controlled
        int32_t clearColor;    ///< clear color of camera 
    };
    /// <summary>
    /// Skinning master table 
    /// </summary>
    struct rc_guiskinning_header
    {
        uint32_t headerId;        ///< Fixed Header key to identify - always = RC_GSKIN_HKEY
        uint32_t gskinVersion;    ///< Version of the file encoding RC_GSKIN_VERSION(1,0,0);
        uint8_t numSkins;         ///< Number of skins in the list (maximum of 255 skins, 0-254), 255 is invalid
        uint8_t defaultSkin;      ///< Default skin 0-254 is default skin id, 255 meand invalid
        uint8_t numTransitions;   ///< number of transitions in transitions table
        uint32_t node_size;       ///< number of items in rc_guiskin_node table
        uint32_t text_size;       ///< number of items in rc_guiskin_text table
        uint32_t lout_size;       ///< number of items in rc_guiskin_layout table
        uint32_t prim_size;       ///< number of items in rc_guiskin_primitive table
        uint32_t matl_size;       ///< number of items in rc_guiskin_material table
        uint32_t cam_size;        ///< number of items in rc_guiskin_camera table
        uint32_t skinsPathSize;   ///< size of char skins[]
        //rc guiskin transitions
        //skins files table
    };
    /// <summary>
    /// A single Skinning table (coloumn of the skinning table)
    /// </summary>
    struct rc_guiskin_header
    {
        uint32_t headerId;      ///< Fixed Header key to identify - always = RC_GSKTB_HKEY
        uint32_t gskinVersion;  ///< Version of the file encoding RC_GSKIN_VERSION(1,0,0);
        CHAR8 name[100];        ///< skin name
        uint32_t fltdata_size;  ///< number of float32_t datas in fltdata table
        uint32_t ufmdata_size;  ///< number of char datas in ufmdata table
        uint32_t node_size;     ///< number of items in rc_guiskin_node table
        uint32_t text_size;     ///< number of items in rc_guiskin_text table
        uint32_t lout_size;     ///< number of items in rc_guiskin_layout table
        uint32_t prim_size;     ///< number of items in rc_guiskin_primitive table
        uint32_t matl_size;     ///< number of items in rc_guiskin_material table
        uint32_t unfm_size;     ///< number of items in rc_guiskin_ufmentry table
        uint32_t cam_size;      ///< number of items in rc_guiskin_camera table
        //Node data, Text Data, Layout Data, Primitive, Material data arrays (rc_guiskin_entries)
        //rc_guiskin_node nodeEntries[];            ///< Skinning entries table
        //rc_guiskin_text textEntries[];            ///< Skinning entries table
        //rc_guiskin_layout layoutEntries[];        ///< Skinning entries table
        //rc_guiskin_primitive primitiveEntries[];  ///< Skinning entries table
        //rc_guiskin_material materialEntries[];    ///< Skinning entries table
        //rc_guiskin_camera cameraEntries[];        ///< Skinning entries table
        //rc_guiskin_ufmentry ufmEntries[];         ///< Uniform skinning entry table
        //float32_t fltdata[];                      ///< float32_t data array which is used by entries table
        //CHAR8  ufmdata[];                          ///< uniform name string array
    };

    // Following data structs for application logic.

    /// <summary>
    /// skin data entries for rc_guiskin_table
    /// </summary>
    struct rc_guiskin_entries
    {
        rc_guiskin_node const* nodeEntries = nullptr;           ///< Node Skinning entries table
        rc_guiskin_text const* textEntries = nullptr;           ///< Text node Skinning entries table
        rc_guiskin_layout const* layoutEntries = nullptr;       ///< Layout node Skinning entries table
        rc_guiskin_primitive const* primitiveEntries = nullptr; ///< Primitive Skinning entries table
        rc_guiskin_material const* materialEntries = nullptr;   ///< Material Skinning entries table
        rc_guiskin_camera const* cameraEntries = nullptr;       ///< Camera Skinning entries table
        rc_guiskin_ufmentry const* ufmEntries = nullptr;        ///< Uniform skinning entry table
        float32_t const* fltdata = nullptr;                     ///< float32_t data array which is used by entries table
        const CHAR8* ufmdata = nullptr;                         ///< uniform name string array
    };

    struct rc_guiskin_table
    {
        const rc_guiskin_header * header = nullptr;
        rc_guiskin_entries entry;
    };

    struct rc_guiskinning
    {
        rc_guiskinning_header const * header = nullptr;
        rc_guiskin_transition const * transitions = nullptr;
        std::vector <const CHAR8*> paths;
        std::vector<rc_guiskin_table> skins;
    };
}
#endif