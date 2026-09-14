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
/// @file  rc_rdfbin_type.h
/// \brief types needed for the rdf binary file format
//  Created on  : 7-July-2021 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_rdfbin_type_h
#define rc_rdfbin_type_h

namespace rendercore_engine
{
    /// <summary>
    /// Creates a 32bit version identifier from passed major, minor and patch values
    /// </summary>
    /// <param name="p_major">Major version  8bit, Range 0 to 255</param>
    /// <param name="p_minor">Minor version  8bit, Range 0 to 255</param>
    /// <param name="p_patch">Patch version 16bit, range 0 to 65535</param>
    /// <returns>32bit version code</returns>
    inline uint32_t RcCretateVersion(const size_t p_major, const size_t p_minor, const size_t p_patch)
    {
        return(static_cast<uint32_t>(static_cast<uint32_t>(static_cast<uint32_t>((p_major)) << 24U) | static_cast<uint32_t>(static_cast<uint32_t>((p_minor)) << 16U) | (static_cast<uint32_t>((p_patch)))));
    }
    /// Gets current version of RDF binary. 
    inline uint32_t RcRdfbinGetVersion()
    {
        /// Must be updated each time this file is changed.
        return RcCretateVersion(5U, 0U, 0U);
    }
    const uint32_t RC_RDFBIN_HKEY = 0x52444642U; ///< Header key 'RDFB'
    const uint32_t RC_RDFBIN_ENDF = 0x454E4446U; ///< End of File marker 'ENDF'
    struct rdfbin_Project
    {
        uint32_t headerKey;     ///< A fixed header entry to identify the file. Its fixed to 0x4C444344
        uint32_t versionKey;    ///< File format version key 0xMMmmPPPP MM – One byte for major version, mm – One byte for minor version, PPPP – Two bytes for patch version
        uint32_t f_engine;      ///< Default font engine to be used(MdlFontEngine)
        uint32_t coordSys;      ///< Co - ordinate system(MdlCoordSystem)
        uint32_t gtrAppVersion; ///< version key 0xMMmmPPPP for generating application
        uint32_t gtrDllVersion; ///< version key 0xMMmmPPPP for the rdf.generator dll used by application
        int32_t globalasset_id; ///< global asset id
        uint32_t dflt_character;///< default character
        uint32_t num_displays;  ///< Specifies the number of displays available.
        uint32_t displaysOffset;///< Offset to Display list in rdf.bin
        uint32_t num_fonts;     ///< Number of fonts available
        uint32_t fontsOffset;   ///< Offset to Font list in rdf.bin
        uint32_t assetgrp_size; ///< Size of asset group array
        uint32_t agOffset;      ///< Offset to AssetGroup list in rdf.bin
        uint32_t flt_data_size; ///< Size of float data table
        uint32_t int_data_size; ///< Size of integer data table
        uint32_t chr_data_size; ///< Size of character data table
        uint32_t fltDataOffset; ///< Offset to float data table in rdf.bin
        uint32_t intDataOffset; ///< Offset to integer data table in rdf.bin
        uint32_t chrDataOffset; ///< Offset to character data table in rdf.bin
        uint32_t YearMonthDay;  ///< Generation time stamp1, will be used to cross check c++ script table
        uint32_t HourMinSecMSec;///< Generation time stamp2, will be used to cross check c++ script table
    };
    struct rdfbin_AssetGroup
    {
        uint32_t assetfile;     ///< Index to the StringData list, from where the URI for this assetfile can be read
        int32_t assetID;        ///< Asset ID
        int32_t assetgroupIndex;///< Asset group Index
        int32_t sharedAgIndex;  ///< Shared Asset group Index
    };
    struct rdfbin_Font
    {
        uint32_t uri;           ///< Index to the StringData list, from where the URI for this font can be read
        uint32_t family;        ///< Index to the StringData list, from where the font family name for this font can be read
        float32_t point_size;   ///< Point size for this font
        uint32_t style;         ///< Style to be used(MdlFontStyle)
        uint32_t hint;          ///< Hinting to be used(MdlFontRenderHint)
        uint32_t fontHeightCal; ///< Which font metric to use(MdlFontHeightCalc_E)
    };
    struct rdfbin_Display
    {
        float32_t x;            ///< X position of window
        float32_t y;            ///< Y position of window
        float32_t w;            ///< Width of window
        float32_t h;            ///< Height of window
        uint32_t render_target; ///< Index to the RenderTarget list entry
        uint32_t guiskin_uri;   ///< Index to the StringData list, from where the gui skin uri can be read
        uint32_t num_rtargets;  ///< Number of items in RenderTarget list
        uint32_t num_accessors; ///< Number of items Accessor list
        uint32_t num_animations;///< Number of items Animation list
        uint32_t num_buffers;   ///< Number of items Buffer list
        uint32_t num_bufferViews;   ///< Number of items BufferView list
        uint32_t num_matBases;      ///< Number of items matBases list
        uint32_t num_matDefDatas;   ///< Number of items matDefDatas list
        uint32_t num_materials;     ///< Number of items Material list
        uint32_t num_meshes;        ///< Number of items Mesh list
        uint32_t num_textures;      ///< Number of items Texture list
        uint32_t num_cmap_textures; ///< Number of items CmapTexture list
        uint32_t num_images;        ///< Number of items Image list
        uint32_t num_samplers;      ///< Number of items Sampler list
        uint32_t num_cameras;       ///< Number of items Camera list
        uint32_t num_skins;         ///< Number of items Skin list
        uint32_t num_scenes;        ///< Number of items Scene list
        uint32_t num_nodes;         ///< Number of items Node list
        uint32_t num_layoutNodes;   ///< Number of items layoutNodes list
        uint32_t num_textNodes;     ///< Number of items textNodes list
        uint32_t num_primitives;    ///< Number of items primitives list
        uint32_t num_attributes;    ///< Number of items attributes list
        uint32_t num_morphTargets;  ///< Number of items morphTargets list
        uint32_t num_rstates;       ///< Number of items rstates list
        uint32_t num_behDefData;    ///< Number of items behDefData list
        uint32_t num_animChannels;  ///< Number of items in animChannels list
        uint32_t num_animSamplers;  ///< Number of items in animSamplers list
        uint32_t num_behaviours;    ///< Number of items in behaviours list
        uint32_t num_lights;        ///< Number of items in lights list
        uint32_t num_renderPasses;  ///< Number of items in RenderPasses list
        uint32_t rtargetsOffset;        ///< Offset to RenderTarget list in rdf.bin
        uint32_t accessorsOffset;       ///< Offset to Accessor list in rdf.bin
        uint32_t animationsOffset;      ///< Offset to Animation list in rdf.bin
        uint32_t animChannelsOffset;    ///< Offset to Animation list in rdf.bin
        uint32_t animSamplersOffset;    ///< Offset to Animation list in rdf.bin
        uint32_t buffersOffset;         ///< Offset to Buffer list in rdf.bin
        uint32_t bufferViewsOffset;     ///< Offset to BufferView list in rdf.bin
        uint32_t matBasesOffset;        ///< Offset to matBases list in rdf.bin
        uint32_t matDefDatasOffset;     ///< Offset to matDefDatas list in rdf.bin
        uint32_t materialsOffset;       ///< Offset to Material list in rdf.bin
        uint32_t meshesOffset;          ///< Offset to Mesh list in rdf.bin
        uint32_t texturesOffset;        ///< Offset to Texture list in rdf.bin
        uint32_t cmap_texturesOffset;   ///< Offset to CmapTexture list in rdf.bin
        uint32_t imagesOffset;          ///< Offset to Image list in rdf.bin
        uint32_t samplersOffset;        ///< Offset to Sampler list in rdf.bin
        uint32_t camerasOffset;         ///< Offset to Camera list in rdf.bin
        uint32_t skinsOffset;           ///< Offset to Skin list in rdf.bin
        uint32_t scenesOffset;          ///< Offset to Scene list in rdf.bin
        uint32_t nodesOffset;           ///< Offset to Node list in rdf.bin
        uint32_t layoutNodesOffset;     ///< Offset to layoutNodes list in rdf.bin
        uint32_t textNodesOffset;       ///< Offset to textNodes list in rdf.bin
        uint32_t primitivesOffset;      ///< Offset to primitives list in rdf.bin
        uint32_t attributesOffset;      ///< Offset to attributes list in rdf.bin
        uint32_t morphTargetsOffset;    ///< Offset to morphTargets list in rdf.bin
        uint32_t rstatesOffset;         ///< Offset to rstates list in rdf.bin
        uint32_t behDefDataOffset;      ///< Offset to behDefData list in rdf.bin
        uint32_t behavioursOffset;      ///< Offset to behaviours list in rdf.bin
        uint32_t lightsOffset;          ///< Offset to lights list in rdf.bin
        uint32_t renderPassesOffset;    ///< Offset to RenderPasses list
        uint32_t anim_opt_list_size;    ///< Number of items AnimationOptimization list
        uint32_t animation_opt_list;    ///< int Indexes[], each item is an idex to a string in chrData table

    };
    struct rdfbin_RenderTarget
    {
        uint32_t name;          ///< index to name string
        float32_t viewport_x;   ///< X position of viewport
        float32_t viewport_y;   ///< Y position of viewport
        float32_t viewport_w;   ///< Width of viewport
        float32_t viewport_h;   ///< Height of viewport
        uint32_t msaa_level;    ///< Msaa level to be used
        uint32_t colorSize;     ///< One of rtColorDepthE
        int32_t tex_index;      ///< If it’s a render to texture / fbo, then the index to Texture list entry
        uint32_t depth_size;    ///< Depth buffer size
    };
    struct rdfbin_Animation
    {
        int32_t playbackCount;  ///< Playback count
        uint32_t num_achannels; ///< Number of items in AnimSampler list
        uint32_t num_asamplers; ///< Number of items in AnimChannel list
        uint32_t playbackMode;  ///< MdlAnimationPlaybackMode_E
        uint32_t autoPlay;      ///< True or false
        int32_t drivenNode;     ///< Index to Node list entry
        int32_t attachedNode;   ///< Index to Node list entry
        uint32_t name;          ///< Index to the StringData list, from where the name can be read
        uint32_t achannels;     ///< Index to AnimChannels list
        uint32_t asamplers;     ///< Index to AnimSampler list
        uint32_t drivenProperty;///< Index to the StringData list, from where the property name can be read
        uint32_t relative;      ///< if non zero, animation is relative
    };
    struct rdfbin_AnimSampler
    {
        int32_t input;          ///< Index to AnimChannel list entry
        int32_t output;         ///< Index to AnimChannel list entry
        uint32_t interpolation; ///< One of MdlAnimInterpol_E
    };
    struct rdfbin_AnimChannel
    {
        int32_t sampler;            ///< Index to AnimSampler list entry
        int32_t target_node;        ///< Index to Node list entry
        int32_t target_primitive;   ///< Index to primitive entry within node.mesh
        uint32_t target_path;       ///< One of MdlTargetPath_E
        uint32_t propName;          ///< Index to the StringData list, from where the property name can be read
    };
    struct rdfbin_Buffer
    {
        uint32_t name;              ///< Index to the StringData list, from where the name can be read
        uint32_t byteLength;        ///< Buffer length in bytes
        uint32_t uri;               ///< Index to the StringData list, from where the uri can be read
    };
    struct rdfbin_Light
    {
        uint32_t name;          ///< Index to the StringData list, from where the name can be read
        uint32_t cullingMask;   ///< mask used for culling objects (gfx3d_scg_light::cullingMask & gfx3d_scg_node::cullingMask) determines if this light is used on the node
        float32_t range;        ///< Distance cutoff after which lights intensity reaches zero. Range supported only for point and spot light
        float32_t intensity;    ///< Brightness of light. 
        float32_t innerCone;    ///< Falloff start angle in radians from centre of 'spot' light 
        float32_t outerCone;    ///< Falloff end angle in radians from centre of 'spot' light 
        int32_t color;          ///< Index to float data list. RGB color value of light
        uint32_t type;          ///< type of the light
        float32_t attenuation;  ///< godot property
        float32_t specular_amount;///< godot property
        float32_t size;///< godot property
        float32_t cone_attenuation;///< godot property
        uint32_t shadow_enable;
        uint32_t shadowReverseCull;
        float32_t shadowBias;
        float32_t shadowTransmittanceBias;
        float32_t shadowNormalBias;
        float32_t shadowOpacity;
        float32_t shadowBlur;
    };
    struct rdfbin_BufferView
    {
        uint32_t name;              ///< Index to the StringData list, from where the name can be read
        int32_t buffer;             ///< Index to Buffer list entry
        uint32_t byteOffset;        ///< Offset to start of data in buffer
        uint32_t byteLength;        ///< Length of data in bytes
        uint32_t byteStride;        ///< stride
        uint32_t target;            ///< One of MdlBvTgt_E
    };
    struct rdfbin_Accessor
    {
        uint32_t name;              ///< Index to the StringData list, from where the name can be read
        int32_t bufferView;         ///< Index to BufferView list entry
        uint32_t byteOffset;        ///< Offset to data
        uint32_t componentType;     ///< MdlCompType_E
        uint32_t normalized;        ///< True or false
        uint32_t count;             ///< Count value
        uint32_t type;              ///< One of MdlType_E
        int32_t  minIndex;          ///< index to minimum value of elements in the accessor
        int32_t  maxIndex;          ///< index to maximum value of elements in the accessor
    };
    struct rdfbin_MaterialBase
    {
        uint32_t isShaderUri;
        uint32_t vs_uid;
        uint32_t fs_uid;
        uint32_t po_uid;
        uint32_t lvertShader;
        uint32_t lfragShader;
        uint32_t lvertShaderLength;
        uint32_t lfragShaderLength;
        uint32_t lbProgram;
        uint32_t lbProgramLength;
        uint32_t cullMode;
        uint32_t shaderBinaryFormat;
        uint32_t srcBlendfactor;
        uint32_t dstBlendfactor;
        uint32_t aSrcBlendfactor;
        uint32_t aDstBlendfactor;
        uint32_t ablendEquation;
        uint32_t blendEquation;
    };
    struct rdfbin_MaterialDefData
    {
        uint32_t name;  		///< name of shaderdef data
        uint32_t type;			///< type of shaderdef data
        uint32_t data;
    };
    struct rdfbin_Material
    {
        uint32_t defUniformDataSize;
        uint32_t defUniformData;
        uint32_t name;
        uint32_t baseProperties;
    };
    struct rdfbin_Mesh
    {
        uint32_t weights;
        uint32_t primitives;
        uint32_t num_primitives;
        uint32_t weights_size;
    };
    struct rdfbin_Primitive
    {
        int32_t indices;
        int32_t primMaterial;
        uint32_t mode;
        uint32_t shadowCastMode;
        int32_t skinId;
        int32_t matSkinId;
        uint32_t targets_size;
        uint32_t attributes;
        uint32_t targets;
    };
    struct rdfbin_Attributes
    {
        uint32_t uid;
        int32_t position;
        int32_t normal;
        int32_t tangent;
        uint32_t textcoord_array_size;
        uint32_t color_array_size;
        uint32_t joints_array_size;
        uint32_t weights_array_size;
        uint32_t textcoord;
        uint32_t primColors;
        uint32_t joints;
        uint32_t weights;
    };
    struct rdfbin_MorphTarget
    {
        uint32_t name;
        int32_t norAccIndex;
        int32_t posAccIndex;
        int32_t tanAccIndex;
    };
    struct rdfbin_Texture
    {
        uint32_t name;
        uint32_t sampler;
        uint32_t source;
    };
    struct rdfbin_CmapTexture
    {
        uint32_t name;
        int32_t sampler;
        int32_t posx_rgt_img;
        int32_t negx_lft_img;
        int32_t posy_top_img;
        int32_t negy_btm_img;
        int32_t posz_frt_img;
        int32_t negz_bck_img;
    };
    struct rdfbin_Image
    {
        int32_t bufferView;
        uint32_t mimeType;
        uint32_t uri;
        uint32_t srgbData;
    };
    struct rdfbin_Sampler
    {
        uint32_t anisoLevel;
        uint32_t minFilter;
        uint32_t magFilter;
        uint32_t wrapS;
        uint32_t wrapT;
    }; 
    struct rdfbin_RenderStates
    {
        uint32_t cullMode;
        uint32_t depthTest;
        uint32_t depthWrite;
        uint32_t srcBlendfactor;
        uint32_t dstBlendfactor;
        uint32_t aSrcBlendfactor;
        uint32_t aDstBlendfactor;
        uint32_t ablendEquation;
        uint32_t blendEquation;
    };
    struct rdfbin_RenderPass
    {
        uint32_t render_pass_stage;
        int32_t render_target;
        int32_t camMaterial;
    };
    struct rdfbin_Camera
    {
        uint32_t name;
        float32_t xmag_aspectRatio;
        float32_t ymag_yfov;
        float32_t zfar;
        float32_t znear;
        uint32_t type;
        uint32_t cullingmask;
        int32_t  render_order;
        uint32_t clear_colorbuff;
        uint32_t clear_depthbuff;
        uint32_t renderState;
        uint32_t clearcolor_value;
        float32_t cleardepth_value;
        uint32_t viewport;
        uint32_t scissorrect;
        uint32_t sort_type;
        int32_t skinId;
        uint32_t num_render_passes;
        int32_t render_passes;
    };
    struct rdfbin_Skin
    {
        uint32_t name;
        int32_t inverseBindMatrices;
        int32_t skeleton;
        uint32_t joints_size;
        uint32_t joints;
    }; 
    struct rdfbin_Scene
    {
        uint32_t animations;
        uint32_t animationsSize;
        int32_t assetgroup_id;
        uint32_t nodes_size;
        int32_t num_behaviours;
        uint32_t behaviours;
        uint32_t name;
        uint32_t nodes;
        uint32_t renderState;
        uint32_t render_target;
        float32_t opacity;
        uint32_t visible;
    }; 
    struct rdfbin_behaviour
    {
        uint32_t name;          ///< script class name
        uint32_t defDataIndex;  ///< index to rdfbin_custpropDefData
        uint32_t scriptIndex;   ///< index to script instance array
        uint32_t defDataSize;   ///< number of def data
    };
    struct rdfbin_custpropDefData
    {
        uint32_t name;			///< name of custom property
        uint32_t type;			///< type of custom property
        uint32_t dataIndex;		///< integer Data
    };
    struct rdfbin_Node
    {
        uint32_t tnode;
        uint32_t type;
        int32_t nodeRotationIdx;
        int32_t nodeScaleIdx;
        int32_t nodeTranslationIdx;
        int32_t nodePivotIdx;
        int32_t matrix;
        float32_t opacity;
        uint32_t cullingmask;
        int32_t scissorrect;
        int32_t margin;
        int32_t flipBookIndex;
        int32_t skinId;
        uint32_t visible;
        int32_t sorder;
        uint32_t nodes_size;
        int32_t num_behaviours;
        uint32_t behaviours;
        uint32_t name;
        uint32_t nodes;
        uint32_t renderState;
        int32_t cameraIndex;
        int32_t skinIndex;
        int32_t meshIndex;
        uint32_t weights_size;
        uint32_t weights;
        int32_t lightIndex;
    };
    struct rdfbin_3dTextNode
    {
        uint32_t defText;
        uint32_t fontIndex;
        uint32_t bboxWidthPx;
        uint32_t bboxHeightPx;
        uint32_t horzAlign;
        uint32_t vertAlign;
        uint32_t drawColor;
        uint32_t oflowMode;
        int32_t charSpacing;
        uint32_t wordWrap;
        uint32_t wordBreak;
        uint32_t lineCount;
        uint32_t startLine;
        uint32_t maxLine;
        int32_t lineSpacing;
        uint32_t hardCutChar;
        int32_t skinId;
        uint32_t doTranslation;
        uint32_t outlineWidth;
        uint32_t dropShadowOffset;
        uint32_t effectColor;
        uint32_t lbForSline;
    };
    struct rdfbin_3dLayoutNode
    {
        uint32_t size;
        int32_t skinId;
        uint32_t halign;
        uint32_t valign;
        uint32_t order;
        uint32_t direction;
        uint32_t oflowmode;
    };
    class rdfbin_script_ibase
    {
    public:
        virtual rc_behaviour_getinst GetBehaviourGetinst(const uint32_t p_scriptIndex) const = 0;
        virtual uint32_t GetMSTimeStamp() const = 0;
        virtual uint32_t GetLSTimeStamp() const = 0;
    };
}
#endif
