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
#define GFX_MGR02_ATTRIB_MASK             (0xF0000000)
#define GFX_MGR02_OBJ_TYPE_MASK           (0x0F000000)
#define GFX_MGR02_PLATFORM_MASK           (0x00F00000)
#define GFX_MGR02_OBJ_ID_MASK             (0x000FFFFF)

#define GFX_MGR02_PLATFORM_DCU            (0x00000000) /* DCU & eDMA rendering */
#define GFX_MGR02_PLATFORM_OVG            (0x00100000) /* OpenVG rendering     */
#define GFX_MGR02_PLATFORM_SWR            (0x00200000) /* Software rendering   */
#define GFX_MGR02_PLATFORM_UN1            (0x00300000)
#define GFX_MGR02_PLATFORM_UN2            (0x00400000)
#define GFX_MGR02_PLATFORM_UN3            (0x00500000)
#define GFX_MGR02_PLATFORM_UN4            (0x00600000)
#define GFX_MGR02_PLATFORM_UN5            (0x00700000)
#define GFX_MGR02_PLATFORM_UN6            (0x00800000)
#define GFX_MGR02_PLATFORM_UN7            (0x00900000)
#define GFX_MGR02_PLATFORM_UN8            (0x00A00000)
#define GFX_MGR02_PLATFORM_UN9            (0x00B00000)
#define GFX_MGR02_PLATFORM_UN10           (0x00C00000)
#define GFX_MGR02_PLATFORM_UN11           (0x00D00000)
#define GFX_MGR02_PLATFORM_UN12           (0x00E00000)
#define GFX_MGR02_PLATFORM_UN13           (0x00F00000)

#define GFX_MGR02_TYPE_SWIDGET            (0x00000000)
#define GFX_MGR02_TYPE_DWIDGET            (0x01000000)
#define GFX_MGR02_TYPE_SIMAGE             (0x02000000)
#define GFX_MGR02_TYPE_DIMAGE             (0x03000000)
#define GFX_MGR02_TYPE_STEXT              (0x04000000)
#define GFX_MGR02_TYPE_DTEXT              (0x05000000)
#define GFX_MGR02_TYPE_TILE               (0x06000000)
#define GFX_MGR02_TYPE_FILL               (0x07000000)
#define GFX_MGR02_TYPE_USER_LAYER         (0x08000000)
#define GFX_MGR02_TYPE_SCREEN             (0x09000000)
#define GFX_MGR02_TYPE_LAYER              (0x0A000000)
#define GFX_MGR02_TYPE_SVG                (0x0B000000)
#define GFX_MGR02_TYPE_UNUSED6            (0x0C000000)
#define GFX_MGR02_TYPE_UNUSED7            (0x0D000000)
#define GFX_MGR02_TYPE_UNUSED8            (0x0E000000)
#define GFX_MGR02_TYPE_UNUSED9            (0x0F000000)

#define GFX_MGR02_ATTRIB_WIDGET_ELEM      (0x80000000)
#define GFX_MGR02_ATTRIB_DYN_PROPERTY     (0x40000000)
#define GFX_MGR02_ATTRIB_UNUSED1          (0x20000000)
#define GFX_MGR02_ATTRIB_UNUSED2          (0x10000000)

#define GFX_MGR02_GET_OBJ_ID(id)            (((UINT32)id) & GFX_MGR02_OBJ_ID_MASK)
#define GFX_MGR02_GET_OBJ_TYPE(id)          (((UINT32)id) & GFX_MGR02_OBJ_TYPE_MASK)
#define GFX_MGR02_GET_OBJ_PLATFORM_TYPE(id) (((UINT32)id) & GFX_MGR02_PLATFORM_MASK)
#define GFX_MGR02_SET_OBJ(id, type)         ((type) | (id))
#define GFX_MGR02_IS_DYNAMIC_PROP(id)       (((id) & GFX_MGR02_ATTRIB_DYN_PROPERTY) != 0)
#define GFX_MGR02_IS_WDG_ELEMENT(id)        (((id) & GFX_MGR02_ATTRIB_WIDGET_ELEM)  != 0)
#define GFX_MGR02_IS_PLATFORM_DCU(id)       (GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_DCU)
#define GFX_MGR02_IS_PLATFORM_OVG(id)       (GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_OVG)
#define GFX_MGR02_IS_PLATFORM_SWR(id)       (GFX_MGR02_GET_OBJ_PLATFORM_TYPE((id)) == GFX_MGR02_PLATFORM_SWR)

/* options for pix_format element of GFX_MGR02_LAYER_DEF_T */
#define GFX_MGR02_PIX_FORMAT_INVALID  (0)
#define GFX_MGR02_PIX_FORMAT_1BPP     (1)
#define GFX_MGR02_PIX_FORMAT_2BPP     (2)
#define GFX_MGR02_PIX_FORMAT_4BPP     (3)
#define GFX_MGR02_PIX_FORMAT_8BPP     (4)
#define GFX_MGR02_PIX_FORMAT_RGB565   (5)
#define GFX_MGR02_PIX_FORMAT_ARGB4444 (6)
#define GFX_MGR02_PIX_FORMAT_ARGB1555 (7)
#define GFX_MGR02_PIX_FORMAT_RGB666   (8)
#define GFX_MGR02_PIX_FORMAT_RGB888   (9)
#define GFX_MGR02_PIX_FORMAT_ARGB8888 (10)
#define GFX_MGR02_NUM_PIX_FORMATS     (11)

/* options for target element of GFX_MGR02_LAYER_DEF_T */
#define GFX_MGR02_TARGET_DCU          (0)
#define GFX_MGR02_TARGET_DCULITE      (1)
#define GFX_MGR02_TARGET_SOFTWARE     (2)
#define GFX_MGR02_TARGET_OPENVG       (3)
#define GFX_MGR02_NUM_TARGETS         (4)

#define GFX_MGR02_SHUTDOWN_NORMAL     0
#define GFX_MGR02_SHUTDOWN_EMERGENCY  1
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
