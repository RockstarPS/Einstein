/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** Name:           hmi_gfx_mgr02_defs.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_DEFES_H
#define HMI_GFX_MGR02_DEFES_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

/*
** obj_id feild of GFX_MGR02_LAYOUT_ELEM_LIST_T structure several information relating to
** object instance.
** Bits 31-28 - is a bitfeild indicating the attributes of the object instance
**              GFX_MGR02_OBJ_ATTRIB_WIDGET_ELEM     - Indicates that the object is part of
**              of a widget children and it is not been used at screen level. This
**              is a kepler only property because in kepler the objects at screen
**              level has more animable properties than one inside a widget. So this
**              bit helps the graphics manager to correctly index in to the right 
**              property table.
**              GFX_MGR02_OBJ_ATTRIB_DYN_PROPERTY   - Indicates that the object has dynamic
**              property enabled and the properties can be changed during RUN time.
**              This basically means that the property table is placed inside RAM.
** Bits 27-24 - Indicates the platform type for the object instance.This is provided
**              to support mixing of other platform capability. For example this is
**              currently provided to include an openVG content inside a DCU project.
** Bits 23-20 - Type of the object.
** Bits 19-00 - Instance ID of the object. This will be used for indexing in to the 
**              local instance property table for the element.
*/
#define GFX_MGR02_ATTRIB_MASK             (0xF0000000U)
#define GFX_MGR02_OBJ_TYPE_MASK           (0x0F000000U)
#define GFX_MGR02_PLATFORM_MASK           (0x00F00000U)
#define GFX_MGR02_OBJ_ID_MASK             (0x000FFFFFU)

#define GFX_MGR02_PLATFORM_DCU            ((UINT32)(0x00000000)) /* DCU & eDMA rendering */
#define GFX_MGR02_PLATFORM_OVG            ((UINT32)(0x00100000)) /* OpenVG rendering     */
#define GFX_MGR02_PLATFORM_SWR            ((UINT32)(0x00200000)) /* Software rendering   */
#define GFX_MGR02_PLATFORM_FJT            ((UINT32)(0x00300000))
#define GFX_MGR02_PLATFORM_ABR            ((UINT32)(0x00400000)) /* Amber */
#define GFX_MGR02_PLATFORM_MON            ((UINT32)(0x00500000))
#define GFX_MGR02_PLATFORM_IRS            ((UINT32)(0x00600000)) /* Amber-Iris */
#define GFX_MGR02_PLATFORM_IMXRT          ((UINT32)(0x00700000)) /* IMXRT */
#define GFX_MGR02_PLATFORM_IMXRT_PXP      ((UINT32)(0x00800000)) /* IMXRT-PXP */
#define GFX_MGR02_PLATFORM_TRAVEO2        ((UINT32)(0x00900000)) /* Traveo2 */
#define GFX_MGR02_PLATFORM_VGLITE         ((UINT32)(0x00A00000)) /* VGLite rendering */
#define GFX_MGR02_PLATFORM_UN9            (0x00B00000)
#define GFX_MGR02_PLATFORM_UN10           (0x00C00000)
#define GFX_MGR02_PLATFORM_UN11           (0x00D00000)
#define GFX_MGR02_PLATFORM_UN12           (0x00E00000)
#define GFX_MGR02_PLATFORM_UN13           (0x00F00000)

#define GFX_MGR02_TYPE_SWIDGET            ((UINT32)(0x00000000))
#define GFX_MGR02_TYPE_DWIDGET            ((UINT32)(0x01000000))
#define GFX_MGR02_TYPE_SIMAGE             ((UINT32)(0x02000000))
#define GFX_MGR02_TYPE_DIMAGE             ((UINT32)(0x03000000))
#define GFX_MGR02_TYPE_STEXT              ((UINT32)(0x04000000))
#define GFX_MGR02_TYPE_DTEXT              ((UINT32)(0x05000000))
#define GFX_MGR02_TYPE_TILE               ((UINT32)(0x06000000))
#define GFX_MGR02_TYPE_FILL               ((UINT32)(0x07000000))
#define GFX_MGR02_TYPE_USER_LAYER         ((UINT32)(0x08000000))
#define GFX_MGR02_TYPE_SCREEN             ((UINT32)(0x09000000))
#define GFX_MGR02_TYPE_LAYER              ((UINT32)(0x0A000000))
#define GFX_MGR02_TYPE_SVG                ((UINT32)(0x0B000000))
#define GFX_MGR02_TYPE_3D_MDL             ((UINT32)(0x0C000000))
#define GFX_MGR02_TYPE_VIDEO_LAYER        ((UINT32)(0x0D000000))
#define GFX_MGR02_TYPE_UNUSED8            (0x0E000000)
#define GFX_MGR02_TYPE_UNUSED9            (0x0F000000)

#define GFX_MGR02_ATTRIB_WIDGET_ELEM      (0x80000000U)
#define GFX_MGR02_ATTRIB_DYN_PROPERTY     ((UINT32)(0x40000000))
#define GFX_MGR02_ATTRIB_UNUSED1          (0x20000000)
#define GFX_MGR02_ATTRIB_UNUSED2          (0x10000000)

#define GFX_MGR02_GET_OBJ_ID(id)            ((UINT32)(((UINT32)(id)) & (GFX_MGR02_OBJ_ID_MASK)))
#define GFX_MGR02_GET_OBJ_TYPE(id)          ((UINT32)(((UINT32)(id)) & (GFX_MGR02_OBJ_TYPE_MASK)))
#define GFX_MGR02_GET_OBJ_PLATFORM_TYPE(id) ((UINT32)(((UINT32)(id)) &( GFX_MGR02_PLATFORM_MASK)))
#define GFX_MGR02_SET_OBJ(id, type)         ((type) | ((UINT32)(id)))
#define GFX_MGR02_IS_DYNAMIC_PROP(id)       (((((UINT32)(id)) & (GFX_MGR02_ATTRIB_DYN_PROPERTY))) != 0x0UL)
#define GFX_MGR02_IS_WDG_ELEMENT(id)        (((id) & GFX_MGR02_ATTRIB_WIDGET_ELEM)  != 0)
#define GFX_MGR02_IS_PLATFORM_DCU(id)       ((UINT32)GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_DCU)
#define GFX_MGR02_IS_PLATFORM_OVG(id)       ((UINT32)GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_OVG)
#define GFX_MGR02_IS_PLATFORM_SWR(id)       ((UINT32)GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_SWR)
#define GFX_MGR02_IS_PLATFORM_FUJITSU(id)   ((UINT32)GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_FJT)
#define GFX_MGR02_IS_PLATFORM_AMBER(id)		((UINT32)GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_ABR)
#define GFX_MGR02_IS_PLATFORM_AMBER_IRIS(id) ((UINT32)GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_IRS)
#define GFX_MGR02_IS_PLATFORM_IMXRT(id)		((UINT32)GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_IMXRT)
#define GFX_MGR02_IS_PLATFORM_IMXRT_PXP(id) ((UINT32)GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_IMXRT_PXP)
#define GFX_MGR02_IS_PLATFORM_TRAVEO2(id)   ((UINT32)GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_TRAVEO2)
#define GFX_MGR02_IS_PLATFORM_VGLITE(id)     ((UINT32)GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_VGLITE)

/* options for pix_format element of GFX_MGR02_LAYER_DEF_T */
#define GFX_MGR02_PIX_FORMAT_INVALID  (0U)
#define GFX_MGR02_PIX_FORMAT_1BPP     (1U)
#define GFX_MGR02_PIX_FORMAT_2BPP     (2U)
#define GFX_MGR02_PIX_FORMAT_4BPP     (3U)
#define GFX_MGR02_PIX_FORMAT_8BPP     (4U)
#define GFX_MGR02_PIX_FORMAT_RGB565   (5U)
#define GFX_MGR02_PIX_FORMAT_ARGB4444 (6U)
#define GFX_MGR02_PIX_FORMAT_ARGB1555 (7U)
#define GFX_MGR02_PIX_FORMAT_YVYU422  (8U)
#define GFX_MGR02_PIX_FORMAT_RGB666   (9U)
#define GFX_MGR02_PIX_FORMAT_RGB888   (10U)
#define GFX_MGR02_PIX_FORMAT_ARGB6666 (11U)
#define GFX_MGR02_PIX_FORMAT_ARGB8888 (12U)
#define GFX_MGR02_PIX_FORMAT_A1       (13U)
#define GFX_MGR02_PIX_FORMAT_A2       (14U)
#define GFX_MGR02_PIX_FORMAT_A4       (15U)
#define GFX_MGR02_PIX_FORMAT_A8       (16U)

#define GFX_MGR02_NUM_PIX_FORMATS     (17U)

/* options for target element of GFX_MGR02_LAYER_DEF_T */
#define GFX_MGR02_TARGET_DCU          (0U)
#define GFX_MGR02_TARGET_DCULITE      (1U)
#define GFX_MGR02_TARGET_SOFTWARE     (2U)
#define GFX_MGR02_TARGET_OPENVG       (3U)
#define GFX_MGR02_TARGET_OPENGL       (4U)
#define GFX_MGR02_TARGET_FUJITSU      (5U)
#define GFX_MGR02_TARGET_AMBER	      (6U)
#define GFX_MGR02_TARGET_MONOTFT      (7U)
#define GFX_MGR02_TARGET_AMBER_IRIS   (8U)
#define GFX_MGR02_TARGET_IMXRT        (9U)
#define GFX_MGR02_TARGET_IMXRT_PXP    (10U)
#define GFX_MGR02_TARGET_TRAVEO2      (11U)
#define GFX_MGR02_TARGET_VGLITE       (12U)

#define GFX_MGR02_NUM_TARGETS         (13U)

#define GFX_MGR02_SHUTDOWN_NORMAL    ((UINT8) 0)
#define GFX_MGR02_SHUTDOWN_EMERGENCY ((UINT8) 1)
/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
** CMS Rev 1.7      1-Sep-2017    SSIGAMAN
** 912798: Different FrameBuffer configuration support in GDT required
** ARGB6666 and YUV422 widget rendering formats added.
**
** CMS Rev 1.6     21-Aug-2017    CSAKTHIV
** RTC 939063:
** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
**
** CMS Rev 1.5     06-JUL-2017    ADEVI
** RTC ID: 871825:  Changes to support MONOTFT Platform
**
** CMS Rev 1.4     04-January-2017    APERUMAL
** Ref RTC 767357 Qac warning fix for B515
**
** CMS Rev 1.3     02-Nov-2015   SSIGAMAN
** Ref RTC# 437002.
** Updated the frame buffer formats for A8, A4, A2, A1, 8BPP, 4BPP, 2BPP and 1BPP
** as per review recommendation for Amber platform
**
** CMS Rev 1.2     27-August-2015    CSAKTHIV
** Ref RTC 326037 Brontes 3d implementation.New 3d image type added
**
** CMS Rev 1.1     25-Nov-2013    CMUTHUSA
** Fujitsu Platform modifications added to changeset base rel_UI.CORE.3.12.08 version
**
** CMS Rev 1.0      08-Aug-12    EMANOJ1
** Creation.
**
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
#endif
