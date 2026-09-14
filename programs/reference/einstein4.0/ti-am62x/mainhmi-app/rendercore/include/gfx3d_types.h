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
//  Filename    : gfx3d_config.h
//  Description : Contains all generic data types (loaders & engine)
//  Created on  : 10-Aug-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	gfx3d_config.h
///	\brief		Contains all generic configurations, debug interfaces 

#ifndef gfx3d_types_h
#define gfx3d_types_h
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include <memory>

#if !defined(GLES3_RENDERER)
#define GLES3_RENDERER (0)	///< GLES3 renderer
#endif

#if !defined(GLES3_RENDERER) || (GLES3_RENDERER < 30)
#include <GLES2/gl2.h>  // Use GL ES 2.0
#include <GLES2/gl2ext.h>
#elif (GLES3_RENDERER == 30)
#include <GLES3/gl3.h>  // Use GL ES 3.0
#include <GLES2/gl2ext.h>
#elif (GLES3_RENDERER == 31)
#include <GLES3/gl31.h> // Use GL ES 3.1
#include <GLES2/gl2ext.h>
#elif (GLES3_RENDERER == 32)
#include <GLES3/gl32.h> // Use GL ES 3.2
#include <GLES2/gl2ext.h>
#else
#error "unsupported gles version specified in GLES3_RENDERER = 20/30/31 or 32 are supported\n"
#endif
#include "EGL/egl.h"
#include "EGL/eglext.h"

/// \defgroup GenericTypes Generic Types
/// <summary>
/// Data types used by engine
/// </summary>

/// \ingroup GenericTypes
/// @{

#if !defined(MAX_PATH)
/// Maximum string length to be used to store the path data
#define MAX_PATH (260)
#endif

#define RC_MTHREAD_IMGDECODE (0x01) ///< image decode thread macro
#define RC_MTHREAD_RENDERING (0x02)///< scene management thread macro
#if !defined(RC_MTHREADS)
#define RC_MTHREADS (0)	///< renderCore threads macro
#endif
/// RC_FONT_ENGINE - 0 support both monotype and freetype
/// RC_FONT_ENGINE - 1 support both freetype only
/// RC_FONT_ENGINE - 2 support both monotype only
#ifndef RC_FONT_ENGINE
#define RC_FONT_ENGINE (0)
#endif

#define RC_MAT_SHADERUID_INVALID (UINT_MAX)					///< invalid PBR mat

#ifndef GL_HALF_FLOAT
#define GL_HALF_FLOAT GL_HALF_FLOAT_OES
#endif

namespace rendercore_engine
{
    typedef char CHAR8;	            ///< typedef char
    typedef unsigned char UCHAR8;	///< typedef unsigned char as uint8
    typedef float float32_t;	    ///< typedef 32bit float
    typedef double float64_t;	    ///< typedef 64bit float
    typedef unsigned long ulong_t;
    enum class rc_agcst_e
    {
        RC_ASSET_ID_INVALID = -2,
        RC_ASSET_ID_SHARED = -1
    };
    /// @}
    /// \ingroup GenericTypes
    /// @{


    /// contains flags about how you want to clear the camera
    enum class CameraClearFlags
    {
        SolidColor,    ///<Clear with a background color
        Depth,         ///<Clear only the depth buffer.
        ColorAndDepth, ///<Clear with a background color
        Nothing        ///<Don't clear anything.
    };

    ///render target Color formats
    enum class rtColorDepthE
    {
        wcColor16bpp,	///< 16 bpp
        wcColor24bpp,	///< 24 bpp
        wcColor32bpp,	///< 32 bpp
        wcColorRGBA32F,	///< 32 bit float per component (32bitx4)
        wcColorRGB10A2	///< 10 bit per color, 2bit for alpha (32bpp)
    };

    ///texture filters & wrap modes
    enum MdlTextFilter_E
    {
        tfUnset = 0,
        tfNearest = GL_NEAREST,
        tfLinear = GL_LINEAR,
        tfNearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
        tfLinearMipmapPNearest = GL_LINEAR_MIPMAP_NEAREST,
        tfNearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
        tfLinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR,
        /// unity specific
        Point = GL_NEAREST,                 ///<  Point filtering - texture pixels become blocky up close.
        Bilinear = GL_LINEAR,               ///<  Bilinear filtering - texture samples are averaged.
        Trilinear = GL_LINEAR_MIPMAP_LINEAR,///<  Trilinear filtering - texture samples are averaged and also blended between mipmap levels.
        tfDefault = GL_NEAREST
    };

    /// typedef enum for texture wrap mode
    enum MdlTextWrap_E
    {
        twUnset = 0,
        twRepeat = GL_REPEAT,
        twClampToEdge = GL_CLAMP_TO_EDGE,
        twMirroredRepeat = GL_MIRRORED_REPEAT,
        // unity specific
        Repeat = GL_REPEAT,         ///< 	Tiles the texture, creating a repeating pattern.
        Clamp = GL_CLAMP_TO_EDGE,   ///<  Clamps the texture to the last pixel at the edge.
        Mirror = GL_MIRRORED_REPEAT,///<	Tiles the texture, creating a repeating pattern by mirroring it at every integer boundary.
        twDefault = GL_REPEAT,
    };

    /// typedef enum for image formats
    /// List all supported image formats which can be loaded.
    /// by glCompressedTexImage3D or glTexImage2D
    /// For uncompressed Refer Table 2 : https://www.khronos.org/registry/OpenGL-Refpages/es3.0/html/glTexImage2D.xhtml
    /// For compressed refer table 1 : https://www.khronos.org/registry/OpenGL-Refpages/es3.0/html/glCompressedTexImage3D.xhtml
    /// Compressed formats are avaiable only when opengl es 3.0 or above is used
    /// Except alpha, luminance, rgb & rgba remaining types needs a
    /// ktx file to make use of it. All types can be easily mapped with opengl
    // NOTE : lrc_image_map[] table depends on the ordering, so make change in sync
    // GetGLImageFormatMap() implements the search assuming that the compressed formats are 
    // towards the end.
    enum MdlImgFormat_E
    {
        // rendercore formats ..
        ifUnset=0,
        ifLuminance=1,            ///<  Luminance (8bit)
        ifLuminanceAlpha=2,       ///<  Luminance (8bit) + Alpa (8bit)
        ifAlphaExt=3,             ///<  Alpha 8 bit
        ifLuminanceAlphaExt=4,    ///<  Luminance (8bit) + Alpa (8bit)
        ifRgbOES=5,               ///<  RGB888 format
        ifRgbaOES=6,              ///<  RGBA8888 format
        ifRgb=7,                  ///<  RGB888 format
        ifRgba=8,                 ///<  RGBA8888 format
        Alpha8=9,                 ///<	Alpha - only texture format.
        RGB565=10,                ///<  A 16 bit color texture format.
        RGBA4444=11,              ///<	Color and alpha texture format, 4 bit per channel.
        RGBA5551=12,              ///<	Color and alpha texture format, 1 bit for alpha, 5 bit per color channel.
        R8=13,
        RG8=14,
        RGBA32F=15,
        RGB32F = 16,
        R32F = 17,
        SRGB8_ALPHA8=18,
        SRGB8=19,
        RGBA8UI=20,
        RGB8UI=21,
        RG8UI=22,
        R8UI=23,
        RGB10A2 = 24,
        EAC_R=25,
        EAC_RG=26,
        ETC2_RGB=27,
        ETC2_RGBA8=28,
        SRGB8_ETC2=29,
        SIGNED_R11_EAC=30,
        SIGNED_RG11_EAC=31,
        SRGB8_ALPHA8_ETC2_EAC=32,
        SRGB8_PUNCHTHROUGH_ALPHA1_ETC2=33,
        RGB8_PUNCHTHROUGH_ALPHA1_ETC2=34,
        RGBA_ASTC_4x4 = 35,
        RGBA_ASTC_5x4 = 36,
        RGBA_ASTC_5x5 = 37,
        RGBA_ASTC_6x5 = 38,
        RGBA_ASTC_6x6 = 39,
        RGBA_ASTC_8x5 = 40,
        RGBA_ASTC_8x6 = 41,
        RGBA_ASTC_8x8 = 42,
        RGBA_ASTC_10x5 = 43,
        RGBA_ASTC_10x6 = 44,
        RGBA_ASTC_10x8 = 45,
        RGBA_ASTC_10x10 = 46,
        RGBA_ASTC_12x10 = 47,
        RGBA_ASTC_12x12 = 48,
        SRGBA_ASTC_4x4 = 49,
        SRGBA_ASTC_5x4 = 50,
        SRGBA_ASTC_5x5 = 51,
        SRGBA_ASTC_6x5 = 52,
        SRGBA_ASTC_6x6 = 53,
        SRGBA_ASTC_8x5 = 54,
        SRGBA_ASTC_8x6 = 55,
        SRGBA_ASTC_8x8 = 56,
        SRGBA_ASTC_10x5 = 57,
        SRGBA_ASTC_10x6 = 58,
        SRGBA_ASTC_10x8 = 59,
        SRGBA_ASTC_10x10 = 60,
        SRGBA_ASTC_12x10 = 61,
        SRGBA_ASTC_12x12 = 62,
        SRGB_PVRTC_2BPPV1 = 63,
        SRGB_PVRTC_4BPPV1 = 64,
        SRGBA_PVRTC_2BPPV1 = 65,
        SRGBA_PVRTC_4BPPV1 = 66,
        SRGBA_PVRTC_2BPPV2 = 67,
        SRGBA_PVRTC_4BPPV2 = 68,
        RGB_PVRTC_4BPPV1 = 69,
        RGB_PVRTC_2BPPV1 = 70,
        RGBA_PVRTC_4BPPV1 = 71,
        RGBA_PVRTC_2BPPV1 = 72,
        RGBA_PVRTC_2BPPV2 = 73,
        RGBA_PVRTC_4BPPV2 = 74,
        DEPTH_COMPONENT32F = 75,
        DEPTH_COMPONENT24 = 76,
        RGB24 = ifRgb,                           ///<	Color texture format, 8 - bits per channel.
        RGBA32 = ifRgba                          ///<	Color with alpha texture format, 8 - bits per channel.
    };
    struct rcTextureInfo
    {
        uint32_t size = 0U;             ///< size of image data in bytes (for compressed its the compressed data size)
        uint32_t line_padding = 0U;     ///< padding bytes between lines
        uint32_t width = 0U;            ///< width of image
        uint32_t height = 0U;           ///< height of image
        uint32_t extended_width = 0U;   ///< width is extended if the stride in input data is large enough to accomodate a pixel
        uint8_t  alignment = 1U;         ///< GL_UNPACK_ALIGNMENT
        MdlImgFormat_E format = MdlImgFormat_E::ifUnset; ///< format of the image data
        const CHAR8* pixels = nullptr;  ///< Pixels data
    };
    /// emu, for image encoding, specifies the type of image
    enum class MdlImgEncoding_E
    {
        ieUnset,
        ieJpeg,
        iePng,
        ieKtx,
        ieRawPixels,
        ieRenderToTex,
        ieSvg
    };

    /// Specifies the possible render target destinations
    enum class MdlRTtype_E
    {
        rttWindowBuffer, ///< Render target destimation is to a window buffer
        rttFBO,           ///< Render target destination is to a framebuffer object
        rttDeferredShading,
    };

    /// specified the type of primitive to be rendered
    enum MdlPrimMode_E
    {
        pmPoints = 0,           ///<0 POINTS
        pmLine = 1,             ///<1 LINES
        pmLineLoop = 2,         ///<2 LINE_LOOP
        pmLineStrip = 3,        ///<3 LINE_STRIP
        pmTriangles = 4,        ///<4 TRIANGLES (Default)
        pmTriangleStrip = 5,    ///<5 TRIANGLE_STRIP
        pmTriangleFan = 6       ///<6 TRIANGLE_FAN
    };
    /// specified the type of primitive to be rendered
    enum MdlPrimShadowCastMode_E
    {
        pscmOff = 0,            ///<0 Casts no Shadow
        pscmOn = 1,             ///<1 Casts Shadow but consider culling
        pscmDoubleSided = 2,    ///<2 Casts Shadow but donot consider culling
        pscmShadowOnly = 3      ///<3 Only shadows rendered
    };
    /// typedef enum for morph target path
    enum class MdlMorphTargetPath_E
    {
        mtpPosition,
        mtpNormal,
        mtpTangent
    };

    /// typedef enum for PBR texture type
    enum class MatPBRTexType_E
    {
        tiBaseColorTexture,
        tiMetallicRoughnessTexture,
        tiNormalTexture,
        tiOcclusionTexture,
        tiEmissiveTexture,
        tiCustomTexture
    };

    /// typedef enum for camera type
    enum class MdlCamType_E
    {
        ctUnset,
        ctPerspective,
        ctOrthographic
    };

    /// typedef enum for buffer view type
    enum class MdlBvTgt_E
    {
        bvtArrayBuffer,
        bvtElementArrayBuffer,
        bvtUndefined,
        bvtInvalid
    };
    /// typedef enum for component of OpenGL
    enum MdlCompType_E
    {
        ctByte = GL_BYTE,
        ctUnsignedByte = GL_UNSIGNED_BYTE,
        ctShort = GL_SHORT,
        ctUnsignedShort = GL_UNSIGNED_SHORT,
        ctInt = GL_INT,
        ctUnsignedInt = GL_UNSIGNED_INT,
        ctFloat = GL_FLOAT
       ,ctHalfFloat = GL_HALF_FLOAT
    };
    /// typedef enum for datatypes
    enum class MdlType_E
    {
        dtVec2 = 2,
        dtVec3 = 3,
        dtVec4 = 4,
        dtMat2 = (32 + 2),
        dtMat3 = (32 + 3),
        dtMat4 = (32 + 4),
        dtScalar = (64 + 1),
        dtVector = (64 + 4),
        dtMatrix = (64 + 16),
    };
    /// typedef enum for animation interpolation
    enum class MdlAnimInterpol_E
    {
        aiLinear,
        aiStep,
        aiCubicHermiteSpline
    };

    /// typedef enum for state of the animation
    enum class MdlAnimationState_E
    {
        asStopped,
        asRunning,
        asPause,

        //internal states not to use 
        asStopping,
    };

    /// typedef enum for animation playback mode
    enum class MdlAnimationPlaybackMode_E
    {
        apmNormal,
        apmReverse,
        apmPingpong,
    };

    /// animation property types supported by gfx3d
    /// Used for bitwise operations so caution when adding > 32 items in to this..
    enum class MdlTargetPath_E
    {
        atpTranslation,
        atpRotation,
        atpScale,
        atpRotationEuler,
        atpTranslationX,
        atpTranslationY,
        atpTranslationZ,
        atpRotationEulerX,
        atpRotationEulerY,
        atpRotationEulerZ,
        atpScaleX,
        atpScaleY,
        atpScaleZ,
        atpWeights,
        atpAlpha,
        atpVisibility,
        atpFlipBookIndex,
        atpCustomProp,
        atpUniform,
        atpOpacity,
        atpMorphTarget,
        atpScissorRect,
        atpInvalid
    };

    /// typedef enum for type of nodes
    enum class mdl_nodeType_E
    {
        ntNode,
        nt3dNode,
        nt3dTextNode,
        nt2dSolidfillNode,
        nt2dTexfillNode,
        nt2dImageNode,
        nt2dTextNode,
        ntLayoutNode,
        ntInvalid
    };
    /// type of supported layouts
    enum class mdl_layoutType_E
    {
        ltStack     ///< stacks the items in a given direction / mdl_layoutDirection_E
    };
    /// Specifies the layout node direction
    enum class mdl_layoutDirection_E
    {
        dHorizontal,    ///< arrange items in horizontal direction
        dVertical,      ///< arrange items in vertical direction
        dDepth,         ///< arrange items one above the other
        dUnset          ///<Indicates unset condition, maintain default
    };
    /// Specifies the layout node ordering
    enum class mdl_layoutOrder_E
    {
        oNormal = 0,	///< Orders the elements normally (e.g left to right)
        oReverse = 1  ///< Orders the elements revserce (r.g right to left)
    };
    /// typedef enum for horizontal alignment
    enum class mdl_layoutHalign_E
    {
        hLeft,          ///<Item's left is anchored to the left of the bounding box
        hCenter,        ///<Item's horizontal center is anchored to the horizontal center of the bounding box
        hRight,         ///<Item's right is anchored to the right of the bounding box
        hJustification, ///<First item anchors to left, last item to right, remaining items are distributed in between
        hUnset          ///<Indicates unset condition, maintain default
    };

    /// typedef enum for vertical alignment
    enum class mdl_layoutValign_E
    {
        vTop,           ///<Item's top is anchored to the top of the bounding box
        vCenter,        ///<Item's vertical center is anchored to the vertical center of the bounding box
        vBottom,        ///<Item's bottom is anchored to the bottom of the bounding box
        vJustification, ///<First item anchors to top, last item to bottom, remaining items are distributed in between
        vUnset          ///<Indicates unset condition, maintain default
    };

    /// <summary>
    /// typedef enum for layout boundary spill
    /// option to decide what should happen when nodes are out of layout size
    /// </summary>
    enum class mdl_layoutOverflowMode_E
    {
        ovRemove,   ///<when not able to fit to layout size node will not rendered
        ovClip       ///<when not able to fit to layout size node is cropped
    };

    /// typedef enum for texture overflow mode
    enum class mdl_textOverflowMode_E
    {
        ovNone,     ///< No Overflow handling. The text gets clipped at the boundary of text box
        ovClip,     ///< Clip Overflow handling. If the string cannot be fit in text box, characters are removed from right until it can be fitted in text box. i.e. Only characters that can be fully contained in text box are rendered 
        ovEllipses, ///< Ellipses Overflow handling with U+2026. If the string cannot be fit in text box, characters are removed from right until it can be fitted in text box. Additional characters are removed further to append a ellipses or ... at the end
        ov3Dots     ///< Ellipses Overflow handling with three '.' character instead of U+2026. If the string cannot be fit in text box, characters are removed from right until it can be fitted in text box. Additional characters are removed further to append a ellipses or ... at the end
    };

    /// typedef enum for multiline word wrap
    enum class mdl_mlWordWrap_E
    {
        wwBreakWordNoWS = 0, ///< Allows breaking at only allowed break points otherthan white spaces + Allows unbreakable words to be broken
        wwBreakWord = 1      ///< Allows breaking at only allowed break points + Allows unbreakable words to be broken
    };

    /// typedef enum for multiline word break
    enum class mdl_mlWordBreak_E
    {
        wbBreakAll = 1     ///< To prevent overflow, word may be broken at any character
    };
    /// Specifies the Text line ordering for multiline text
    enum class mdl_textLineDir_E
    {
        tldAuto = 0,	///< Determines the dir internally based on camera proj matrix scale y
        tldDown = 1,   ///< Renderes the lines Downwards in Y direction
        tldUp = 2      ///< Renderes the lines Upwards in Y direction
    };
    /// Specifies the Text base direction based on bidi algo
    enum class mdl_textBidiDir_E
    {
        tbdltr = 0,	    ///< Left to Right base direction 
        tbdrtl = 1,     ///< Right to Left base direction
        tbdmixed = 2,   ///< Mixed-directional text.
        tbdneutral = 3  ///< No strongly directional text.
    };
    /// types of all the classes for RDF
    enum class rdf_classtype_e
    {
        rctype_project,
        rctype_font,
        rctype_display,
        rctype_rtarget,
        rctype_accessor,
        rctype_animation,
        rctype_buffer,
        rctype_bufferView,
        rctype_material,
        rctype_mesh,
        rctype_morphTargetsList,
        rctype_morphTargets,
        rctype_morphTarget,
        rctype_textureInfo,
        rctype_texture,
        rctype_cmap_texture,
        rctype_image,
        rctype_sampler,
        rctype_camera,
        rctype_skin,
        rctype_layoutnode,
        rctype_3dnode,
        rctype_3dtext_node,
        rctype_2dsolidfill_node,
        rctype_2dtexfill_node,
        rctype_2dimage_node,
        rctype_2dtext_node,
        rctype_node,
        rctype_scene,
        rctype_anim_sampler,
        rctype_anim_channel,
        rctype_primitive,
        rctype_attributes,
        rctype_orthographic,
        rctype_perspective,
        rctype_behaviour,
        rctype_materialBase,
        rctype_renderstates,
        rctype_assetgroup,
        rctype_guiskinning,
        rctype_guiskinningProp,
        rctype_guiskinningNode,
        rctype_guiskinningText,
        rctype_guiskinningLayout,
        rctype_guiskinningPrimitive,
        rctype_guiskinningMaterial,
        rctype_guiskinningNodeData,
        rctype_guiskinningTextData,
        rctype_guiskinningLayoutData,
        rctype_guiskinningPrimitiveData,
        rctype_guiskinningMaterialData,
        rctype_guiskinningUniformData,
        rctype_guiskinningData,
        rctype_guiskinningTransition,
        rctype_light,
        rctype_renderpass
    };

    /// typedef enum for properties type
    enum class mdl_cPropType
    {
        cptInvalid,
        cptInt,
        cptUInt,
        cptFloat,
        cptEnum,
        cptVec2,
        cptVec3,
        cptVec4,
        cptString,
        /// following types are used by the unity scripting to specify initilization value for 
        /// Transform *, Camera *, Material * and GameObject * type public variables.
        /// mdl_cPropType::cptTransformRef ::> gltf+ "type": "Transform" and the value is an index to a Node (Transform)
        cptTransformRef,
        /// mdl_cPropType::cptCameraRef ::> gltf+ "type": "Camera" and the value is an index to a Camera
        cptCameraRef,
        /// mdl_cPropType::cptMaterialRef ::> gltf+ "type": "Material" and the value is an index to a Node (Transform), whose material is to be used as default value
        cptMaterialRef,
        /// mdl_cPropType::cptGameObjRef ::> gltf+ "type": "GameObject" and the value is an index to a Node (Transform), whose gameObject is to be used as default value
        cptGameObjRef,
        /// mdl_cPropType::cptTextMeshProRef ::> gltf+ "type": "TextMeshPro" and the value is an index to a Node (Transform), whose gameObject is to be used as default value
        cptTextMeshProRef,
        /// mdl_cPropType::cptTexure2DRef ::> unity Texture2D type. Init value is a path to a texture file
        cptTexure2DRef,
        /// type for Wide string. 
        // Added at the end of the list to make it compatible with previously data
        cptWString
    };

    /// uniforms which are getting submitted to GLSL
    enum class mdl_cUniformType
    {
        cutInvalid,
        cutMat4,
        cutFloat,
        cutVec2,
        cutVec3,
        cutVec4,
        cutInt,
        cutS2d,         ///< Sampler 2D
        cutC2d,         ///< Cubemap
        cutS3d,         ///< Sampler 3D
        cutMat2,
        cutMat3
    };

    /// <summary>
    /// Depth test is inherited from "camera" to "node" to "primitive"
    /// So if the primitive has a depth test set, thats the value finally used for the primitive
    /// </summary>
    enum mdl_depthTest
    {
        dtUnset = 0,            ///<  unset, use the parents value (default values comes from gfx3d_scg_camera::depthTest)
        dtOff = 1,              ///<  Depth test is Off
        dtAlways = GL_ALWAYS,   ///<  The depth test always passes.
        dtNever = GL_NEVER,     ///<  The depth test never passes.
        dtLess = GL_LESS,       ///<  Passes if the fragment's depth value is less than the stored depth value.
        dtEqual = GL_EQUAL,     ///<  Passes if the fragment's depth value is equal to the stored depth value.
        dt_Lequal = GL_LEQUAL,  ///<  Passes if the fragment's depth value is less than or equal to the stored depth value.
        dt_Greater = GL_GREATER,///<  Passes if the fragment's depth value is greater than the stored depth value.
        dt_NEQUAL = GL_NOTEQUAL,///<  Passes if the fragment's depth value is not equal to the stored depth value.
        dt_GEqual = GL_GEQUAL   ///<  Passes if the fragment's depth value is greater than or equal to the stored depth value.
    };

    /// <summary>
    /// Depth write is inherited from "camera" to "node" to "primitive"
    /// So if the primitive has a depth write set, thats the value finally used for the primitive
    /// </summary>
    enum mdl_depthWrite
    {
        dwFalse,    ///< disabled
        dwTrue,     ///< enabled
        dwUnset     ///< unset, use the parents value (default values comes from gfx3d_scg_camera::depthWrite)
    };

    /// <summary>
    /// Cull mode is inherited from "camera" to "node" to "primitive" to "material"
    /// So if the material has a cull mode set, thats the value finally used for the primitive
    /// </summary>
    enum mdl_cullMode
    {
        cmUnset = 0,                    ///< unset, use the parents value (default values comes from gfx3d_scg_camera::cullMode)
        cmOff = 1,                      ///< cull mode is disabled..
        cmFront = GL_FRONT,             ///< cull mode is GL_FRONT
        cmBack = GL_BACK,               ///< cull mode is GL_BACK
        cmFrontBack = GL_FRONT_AND_BACK ///< cull mode is GL_FRONT_AND_BACK
    };
    /// <summary>
    /// Winding order of the mesh
    /// </summary>
    enum mdl_windingOrders
    {
        woUnset = 0,       ///< unset, use the parents value
        woCW = GL_CW,      ///< clockwise..
        woCCW = GL_CCW     ///< counter clockwise
    };

    /// style of fonts to be rendered
    enum class MdlFontStyle
    {
        fsNormal,
        fsBold,
        fsItalic,
        fsBoldAndItalic
    };

    /// hints needed for font rendering
    enum class MdlFontRenderHint
    {
        rhAntiAlias,    ///< AntiAlias + auto hinting
        rhDefault,      ///< AntiAlias + with hinting
        rhNoHinting     ///< AntiAlias + without hinting
    };

    /// font engine needed for font rendering
    enum class MdlFontEngine
    {
        feFreeType,
        feMonoType,
        feUnset
    };

    /// <summary>
    /// Blend equation is inherited from "camera" to "node" to "primitive" to "material"
    /// So if the material has a blend equation set, thats the value finally used for the primitive
    /// </summary>
    enum MdlBlendEquation
    {
        beUnset            ///< unset, use the parents value (default values comes from gfx3d_scg_camera) 
        , beAdd              ///< same as GL_FUNC_ADD
        , beSubtract         ///< same as GL_FUNC_SUBTRACT
        , beReverseSubtract  ///< same as GL_FUNC_REVERSE_SUBTRACT
        , beMin              ///< same as GL_MIN
        , beMax              ///< same as GL_MAX
    };
    /// <summary>
    /// Blend mode is inherited from "camera" to "node" to "primitive" to "material"
    /// So if the material has a blend mode set, thats the value finally used for the primitive
    /// Note:-
    ///   SrcC/DstC - source/destination(framebuffer) color components Red, Green, Blue
    ///   SrcA/DstA - source/destination(framebuffer) alpha component
    /// </summary>
    enum MdlBlendMode
    {
        /// Blend is unset, uses the parents value
        /// (default values comes from gfx3d_scg_camera::blendMode) 
        bmUnset,
        /// blend is off
        ///  - DstC = SrcC, DstA = SrcA
        bmOpaque,
        /// premultiplied 
        ///  - glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA)
        ///  - DstC = SrcC + DstC * (1-SrcA)
        bmBlendPremultiplied,
        /// nonpremultiplied
        ///  - glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
        ///  - DstC = SrcC * SrcA + DstC * (1-SrcA)
        bmBlendNonPremultiplied,
        /// mix
        ///  - glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA)
        ///  - DstC = SrcC * SrcA + DstC * DstA
        bmBlendMix,
        /// additive
        ///  - glBlendFunc(GL_ONE, GL_ONE)
        ///  - DstC = SrcC + DstC
        bmBlendAdditive,
        /// Custom  BlendEquation
        ///  - glBlendFunc(X, Y)
        bmBlendCustom
    };

    /// <summary>
    /// Optional Alpha channel blend mode control.
    /// Applicable only when MdlBlendMode is not bmOpaque
    /// </summary>
    enum MdlAlphaBlendMode
    {
        /// Blend is unset, uses the parents value
        /// (default values comes from gfx3d_scg_camera::blendMode) 
        abmUnset,
        /// Keep destination alpha unaffected.
        ///  - glBlendFuncSeparate(X, Y, GL_ZERO, GL_ONE)
        ///  - DstA = DstA (default)
        abmBlendUseDst,
        /// Replace destination alpha with source.
        ///  - glBlendFuncSeparate(X, Y, GL_ONE, GL_ZERO)
        ///  - DstA = SrcA
        abmBlendUseSrc,
        /// premultiplied
        ///  - glBlendFuncSeparate(X, Y, GL_ONE, GL_ONE_MINUS_SRC_ALPHA)
        ///  - DstA = SrcA + DstA * (1-SrcA)
        abmBlendPremultiplied,
        /// Non premultiplied
        ///  - glBlendFuncSeparate(X, Y, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
        ///  - DstA = SrcA * SrcA + DstA * (1-SrcA)
        abmBlendNonPremultiplied,
        /// Mix
        ///  - glBlendFuncSeparate(X, Y, GL_SRC_ALPHA, GL_DST_ALPHA)
        ///  - DstA = SrcA * SrcA + DstA * DstA
        abmBlendMix,
        /// Additive
        ///  - glBlendFuncSeparate(X, Y, GL_ONE, GL_ONE)
        ///  - DstA = SrcA + DstA
        abmBlendAdditive,
        /// Custom Alpha BlendEquation
        ///glBlendFuncSeparate(X, Y, Z, W)
        abmBlendCustom
    };
    /// <summary>
    /// Blend Factor Config applicable when Blend Mode is Custom
    /// </summary>
    enum MdlBlendFactor
    {
        bfUnset = 0xFFFF,
        bfZero = GL_ZERO,
        bfOne = GL_ONE,
        bfSrcColor =GL_SRC_COLOR,
        bfOneminusSrcColor = GL_ONE_MINUS_SRC_COLOR,
        bfDstColor=GL_DST_COLOR,
        bfOneminusDstColor=GL_ONE_MINUS_DST_COLOR,
        bfSrcAlpha=GL_SRC_ALPHA,
        bfOneminusSrcAlpha = GL_ONE_MINUS_SRC_ALPHA,
        bfDstAlpha = GL_DST_ALPHA,
        bfOneminusDstAlpha = GL_ONE_MINUS_DST_ALPHA,
        bfConstantColor = GL_CONSTANT_COLOR,
        bfOneminusConstantColor = GL_ONE_MINUS_CONSTANT_COLOR,
        bfConstantAlpha = GL_CONSTANT_ALPHA,
        bfOneminusConstantAlpha = GL_ONE_MINUS_CONSTANT_ALPHA,
        bfSrcAlphaSaturate = GL_SRC_ALPHA_SATURATE
    };
    /// Coordinate system used by the input (e.g RDF) model.
    /// It can be set at project level, display level and scene level to allow few displays or scenes 
    /// to have a different coordinate system than the project.. So the settings used at child level
    /// takes precedance. 
    enum class MdlCoordSystem
    {
        csUnset,    ///< Its unspecified, meaning that the co-ordinate system of parent will will prevail.
        csRHS,      ///< Right Hand co-ordinate (default), gltf+ model, gltf+ to RDF model uses this.
        csLHS       ///< Left Hand co-ordinate. Its used by unity generated RDF model.
    };

    /// Holds the version information as Major.Minor.Patch (https://semver.org/)
    struct RcVersion
    {
        int32_t rvMajor;		///< major version number
        int32_t rvMinor;		///< minor version number
        int32_t rvPatch;		///< patch version number
    };

    /// typedef enum for GPU selection
    enum class mdl_gpuSelection
    {
        gsUnset,
        gsViv_imx6q,
        gsViv_imx6p,
        gsViv_imx8qm,
        gsViv_imx8qxp,
        gsViv_imx8qxp_b0
    };
    /// Controls scene loading behaviour LoadSceneAsync
    enum class MdlSceneLoadMode
    {
        Single,  ///< Activates the requested scene. All currently active scenes are removed
        Additive ///< Activates the requested scene and currently active scenes remains active
    };
    /// Controls scene loading behaviour LoadSceneAsync
    enum class MdlAssetLoadMode
    {
        Synchronous, ///< perform operation synchronously in the call (blocking call)
        Asynchronous ///< performs operation asynchronously (non blocking), valid only when multi thread support is enabled
    };
    /// Resource Loading policy
    enum class MdlResourceLoadRule
    {
        All,      ///< Loads all resources on scene load
        OnDemand  ///< Loads all active nodes resources on scene load and remaining on demand (when the node becomes active)
    };
    /// Resource fetching policy. 
    /// Normally resources are kept in ROM and copied to RAM when a scene requires it.
    /// Keeping resources in RAM in advance will improve loading perforance of scenes.
    enum class MdlResourceFetch
    {
        Delayed,    ///< Resources are copied to RAM only when the scene requires it. Unloaded from immediately after usage (Default)
        DlResidant, ///< Resources are copied to RAM only when the scene requires it. Will remain permanantly in RAM once loaded
        Prefetch,   ///< All resources for the sene are prefetched to RAM on CreateScene(). Unloaded immediately after usage 
        PfResidant  ///< All resources for the sene are prefetched to RAM on CreateScene(). Will remain permanantly in RAM
    };
    /// \ingroup Engine
    /// @{
    /// <summary>
    /// Data types of uniform/attribute values
    /// </summary>
    enum rdf_glslDataType
    {
        MDATT_INVD = GL_NONE,       ///< invalid type
        MDATT_MAT4 = GL_FLOAT_MAT4, ///< floating point 4x4 Matrix type
        MDATT_MAT3 = GL_FLOAT_MAT3, ///< floating point 3x3 Matrix type
        MDATT_MAT2 = GL_FLOAT_MAT2, ///< floating point 2x2 Matrix type
        MDATT_FLOAT = GL_FLOAT,     ///< floating point type
        MDATT_VEC2 = GL_FLOAT_VEC2, ///< floating point Vector2 type
        MDATT_VEC3 = GL_FLOAT_VEC3, ///< floating point Vector3 type
        MDATT_VEC4 = GL_FLOAT_VEC4, ///< floating point Vector4 type
        MDATT_INT = GL_INT,         ///< integer type
        MDATT_S2D = GL_SAMPLER_2D,  ///< sampler 2d texture
        MDATT_C2D = GL_SAMPLER_CUBE ///< sampler cubemap texture
#ifdef GL_SAMPLER_EXTERNAL_OES
       ,MDATT_SE = GL_SAMPLER_EXTERNAL_OES  ///< sampler 2d texture
#endif
    };

    /// <summary>
    /// Class for generating default data by RDF C++ generator..
    /// </summary>
    struct rdf_shaderDefData
    {
        CHAR8 const* const name;				///< name of shaderdef data
        rdf_glslDataType type;					///< type of shaderdef data
        GLint vGLint;							///< int id
    };

    /// \ingroup Internal
    /// @{

    /// custom property init value data
    struct rdf_custpropDefData
    {
        CHAR8 const* name;				///< name of custom property
        mdl_cPropType type;				///< type of custom property
        int32_t intd; 					///< integer Data
        uint32_t uintd;					///< unsigned integer Data
        float32_t fld[4];				///< float32_t data
        CHAR8 const* strd;				///< string data
        char16_t const* wstrd;			///< wide string data
    };
    /// @}
    /// \ingroup Internal
    /// @{

    /// To hold an array of rdf_custpropDefData
    struct rdf_custpropDefDataArray
    {
        size_t num_custProperties; ///< number of properties present
        rdf_custpropDefData const* const defData; ///< pointer to default data array
    };

    /// Mapping RC format to GL format 
    /// e.g. {MdlImgFormat_E::ifRgba,GL_RGBA,GL_RGBA,GL_UNSIGNED_BYTE,32,false}
    struct RCglImgFormatMap
    {
        MdlImgFormat_E rcFormat;    ///< rendercore format
        GLint internalFormat;       ///< OpenGL internal format
        GLenum format;              ///< OpenGL format
        GLenum type;                ///< OpenGL type
        uint8_t bpp;                ///< OpenGL bits per pixel
        uint8_t ccomp;              ///< number of color components
        uint8_t walign;             ///< width alignment
        uint8_t halign;             ///< height alignment
        bool compressed;            ///< true if the format is of compressed OpenGL format
        bool cr_tf;                 ///< Color renderable and texture filterable (Table 8.10 of https://www.khronos.org/registry/OpenGL/specs/es/3.2/es_spec_3.2.pdf)
    };
    /// @}
    /// @}
    ///
    /// identifies user touch/mouse/keyboard event that is received from touch driver
    ///
    enum class rcwinUETypeE
    {
        ueNone,				///< no event
        ueMouseMove,			///< mouse move event
        ueMouseUp,			///< mouse up
        ueMenuEvent,			///< menu event
        ueMenuOverlayOn,		///< menu overlay on event
        ueMenuOverlayOff,	///< menu overlay off event
        ueMouseDown,			///< mouse down event
        ueMouseWheel,		///< mouse wheel event
        ueKeyUp,				///< key up event
        ueKeyDown,			///< key down event
        ueQuit				///< shutdown event
    };
    /// contains the information about the UI user event that took place
    class rcwinUserEvent
    {
    public:
        size_t rcDisplayID = static_cast<size_t>(SIZE_MAX);  ///< display / window id
        int32_t x = 0;                  ///< mouse x
        int32_t y = 0;                  ///< mouse y
        float32_t scrollDelta = 0.0F;   ///< mouse wheel delta
        size_t keyCode = 0U;            ///< keyboard key or Menu id or touch id depending on event
        rcwinUETypeE userEvent = rcwinUETypeE::ueNone; ///< event type
    };
    class gfx3d_scg_display;
    class IRcWinUserEventCbBase
    {
    public:
        virtual bool rcwin_uevent_cb(gfx3d_scg_display * const p_display, const rcwinUserEvent& p_ue) = 0;
    };
    using IRcWinUserEventCbSp = std::shared_ptr<IRcWinUserEventCbBase>;
    /// windows mouse event
    class winMEvent
    {
    public:
        float32_t clientX;	///< client x
        float32_t clientY;	///< client y 
        float32_t deltaY;	///< delta y
    };
    /// Specify how the user input positions to be considered
    enum class MdlPositioning
    {
        Absolute,    ///< (default) Positioning is Absolute, in screen coordinate.
        Relative     ///< Positioning is relative withrespect to owner object.
    };
    /// <summary>
    /// Easing curves
    /// </summary>
    enum class MdlEasingCurve
    {
        ease, 	    //slow start, then fast, then end slowly
        linear,     //same speed from start to end
        easeIn,     //Specifies a transition effect with a slow start
        easeOut,    //Specifies a transition effect with a slow end
        easeInOut,  //Specifies a transition effect with a slow start and end
        step,	    //Specifies a stepping function
        smoothStep, ///< interpolate using a smoothstep curve
        smootherStep,///< interpolate using a smootherstep curve
        sine,        ///< interpolate using a sine function
        quadratic,   ///< interpolate using a cuadratic function
        cubic,       ///< interpolate using a cubic function
        quartic,     ///< interpolate using a quartic function
        quintic      ///< interpolate using a quintic function
    };              
    struct MdlRdAllBytes
    {
        const CHAR8* bytes = nullptr; ///< Pointer to buffer read
        size_t length = 0U;           ///< Length of the buffer   
    };
    /// font height calulation methods
    /// In some of the test fonts it noted that usWinAscent > sTypoAscender
    /// this caused some of the glyphs to get clipped due to use of sTypoAscender
    /// So an option is provided to choose either type only or maximum out of two
    enum class MdlFontHeightCalc_E
    {
        /// <summary>
        /// Uses the the maximum value from either
        /// 1. sTypoAscender and sTypoDescender
        /// 2. usWinAscent and usWinDescent 
        //  for font height calculation and default line spacing (default)
        /// </summary>
        fhUseMaxOfTypoAndWin,
        /// <summary>
        /// Uses the sTypoAscender and sTypoDescender only for font height 
        /// calculation and default line spacing
        /// </summary>
        fhUseTypoOnly,
        /// <summary>
        /// Uses the usWinAscent and usWinDescent only for font height 
        /// calculation and default line spacing
        /// </summary>
        fhUseWinOnly,
        /// <summary>
        /// Uses the hheaAscent, hheaDescent and hheaLineGap only for font height 
        /// calculation and default line spacing
        /// </summary>
        fhUseHheaOnly
    };
    enum class MdlRenderPassStage
    {
        rsPreLightingDepth,  /// capture depth buffer for each light enabled for shadow (not applicable for camera)
        rsPreDepth,          /// capture depth buffer for camera
        rsNormalRendering,   /// normal rendering 
        rsPpGlowFilter,      /// Glow filtering 
        rsPpAdjust,          /// Adjustment stage Glow, Bloom, Brightness, Contrast and Tone post processing effect 
        rsPpSSAO,            /// Post process for SSAO   
        rsRenderStagesTotal
    };
}
#endif