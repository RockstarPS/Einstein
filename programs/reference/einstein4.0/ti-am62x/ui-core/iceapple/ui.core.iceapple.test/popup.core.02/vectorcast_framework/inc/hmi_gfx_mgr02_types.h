/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2011. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_gfx_mgr02_types.h
**
** Description:    Public types definitions for the graphics manager. This
**                 shall not be included by applications. The types in this
**                 file will come via the manager public interface file
**                 hmi_gfx_mgr02.h
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_TYPES_H
#define HMI_GFX_MGR02_TYPES_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

#define GFX_MGR02_TYPE_SWIDGET        (0<<24)
#define GFX_MGR02_TYPE_DWIDGET        (1<<24)
#define GFX_MGR02_TYPE_SIMAGE         (2<<24)
#define GFX_MGR02_TYPE_DIMAGE         (3<<24)
#define GFX_MGR02_TYPE_STEXT          (4<<24)
#define GFX_MGR02_TYPE_DTEXT          (5<<24)
#define GFX_MGR02_TYPE_TILE           (6<<24)
#define GFX_MGR02_TYPE_USER_LAYER     (7<<24)
#define GFX_MGR02_TYPE_SCREEN         (8<<24)
#define GFX_MGR02_TYPE_UNUSED3        (9<<24)
#define GFX_MGR02_TYPE_UNUSED4        (10<<24)
#define GFX_MGR02_TYPE_UNUSED5        (11<<24)
#define GFX_MGR02_TYPE_UNUSED6        (12<<24)
#define GFX_MGR02_TYPE_UNUSED7        (13<<24)
#define GFX_MGR02_TYPE_UNUSED8        (14<<24)
#define GFX_MGR02_TYPE_UNUSED9        (15<<24)

#define GFX_MGR02_WDG_ELEMENT_BIT     (0x80000000)
#define GFX_MGR02_DYN_PROPERTY_BIT    (0x40000000)
#define GFX_MGR02_UNUSED_BIT1         (0x20000000)
#define GFX_MGR02_UNUSED_BIT2         (0x10000000)

#define GFX_MGR02_OBJ_ID_MASK         (0x00FFFFFF)
#define GFX_MGR02_OBJ_TYPE_MASK       (0x0F000000)
#define GFX_MGR02_OBJ_BIT_MASK        (0xF0000000)
#define GFX_MGR02_GET_OBJ_ID(id)      (id & GFX_MGR02_OBJ_ID_MASK)
#define GFX_MGR02_GET_OBJ_TYPE(id)    (id & GFX_MGR02_OBJ_TYPE_MASK)
#define GFX_MGR02_SET_OBJ(id, type)   (type|id)
#define GFX_MGR02_IS_DYNAMIC_PROP(id) ((id & GFX_MGR02_DYN_PROPERTY_BIT) != 0)
#define GFX_MGR02_IS_WDG_ELEMENT(id)  ((id & GFX_MGR02_WDG_ELEMENT_BIT) != 0)

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
  /* CLUT ptr  */ UINT32 const * CLUT;
  /* CLUT size */ UINT16 CLUTsize;
  /* Padding   */ UINT16 padding;
}GFX_MGR02_CLUT_DATA;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   UINT8  bb:1;
   UINT8  ab:2;
   UINT8  trans;
   UINT8  ck_r;
   UINT8  ck_g;
   UINT8  ck_b;
}GFX_MGR02_BLEND_DATA;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   SINT16 x;
   SINT16 y;
}GFX_MGR02_LOC_DATA;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   UINT32 address;
   UINT32 size  :24;
   UINT32 status:8;
}GFX_MGR02_GRAM_CHUNK;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   UINT16 width;
   UINT16 height;
}GFX_MGR02_SIZE_DATA;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   UINT16 hor_size;
   UINT16 ver_size;
}GFX_MGR02_TILE_DATA;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   UINT16 start_line;
   UINT16 num_lines;
}GFX_MGR02_VCLIP_DATA;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   GFX_MGR02_LOC_DATA   pos;
   GFX_MGR02_VCLIP_DATA clip;
}GFX_MGR02_WIDGET_ELEM_DATA;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   UINT16               clut;
   GFX_MGR02_VCLIP_DATA clip;
   GFX_MGR02_LOC_DATA   pos;
   GFX_MGR02_TILE_DATA  tile;
   GFX_MGR02_BLEND_DATA blend;
   UINT32               fg_color;
   UINT32               bg_color;
}GFX_MGR02_ELEM_PROP_DATA;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   UINT32              fg_color;
   UINT32              bg_color;
   GFX_MGR02_TILE_DATA tile;
}GFX_MGR02_ELEM_COLOR_TILE_DATA;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   GFX_MGR02_LOC_DATA pos;
   UINT16             color_index;
   UINT16             blend_index;
}GFX_MGR02_STATIC_PROP_DATA;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct GFX_MGR02_ELEM_LIST
{
   UINT16                             base_id;
   UINT16                             num_child_elements;
   UINT32                             obj_id;
   struct GFX_MGR02_ELEM_LIST const * child;
}GFX_MGR02_ELEM_LIST_T;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   SINT16 sx;
   SINT16 sy;
   SINT16 ex;
   SINT16 ey;
   UINT8  is_transparent;
}GFX_MGR02_ELEMENT_AREA;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   SINT16 sx;
   SINT16 sy;
   SINT16 ex;
   SINT16 ey;
}GFX_MGR02_VISIBLE_AREA;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   /*
   ** for priority only 8bits are enough but, kept as 16 to meet the 32bit packing requirement.
   ** So in future if we need another element we could always use the remaining 8bits
   */
   UINT16                        priority;
   UINT16                        num_child_elements;
   UINT32                        bg_color;
   GFX_MGR02_ELEM_LIST_T const * child;
}GFX_MGR02_SCREEN_T;

/*
** Structure to contain information about a text I/O.
** The members are:
**   - address where the image data can be found (i.e. height, width, bpp,
**     etc)
**   - pointer to the font file to be used to construct the text
**   - pointer to the text to be displayed
**   - pointer to the number of characters in the text
**   - justification of the text (i.e. left, center, right)
**   - orientation of the text (i.e. horizontal or vertical)
**   - encoding of the text (i.e. ASCII or UNICODE)
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
  /* Pointer to text   */ UINT16 string_index;
  /* Width             */ UINT16 width;
  /* Num of characters */ UINT8  num_chars;
  /* Font              */ UINT8  font_id;
  /* Justification     */ UINT8  justification:2;
  /* Orientation       */ UINT8  orientation  :2;
  /* Encoding          */ UINT8  encoding     :2;
  /* Static/Dynamic    */ UINT8  dynamic      :1;
  /* Unused            */ UINT8  unused       :1;
}GFX_MGR02_TEXT_T;

/*
** Define the structure to contain information about a graphical object.
** This information will be used when writing to the control descriptor
** registers for a layer.
**
** Generally, a graphical object is a bitmap that resides in internal
** or external flash ROM.  It may also exist in RAM.  Also, a graphical
** object may be a block of RAM into which a string of text has been
** rendered.
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
  /* Address             */  UINT32 * pixel_data;
  /* Width               */  UINT16   width;
  /* Height              */  UINT16   height;
  /* CLUT                */  UINT16   clut;
  /* Visible Area offset */  UINT8    visible_area_offset_array_index;
  /* BPP & encoding      */  UINT8    BPP_and_encoding:7;
  /* RLE encoding        */  UINT8    is_compressed   :1;
}GFX_MGR02_IMAGE_T;

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
   GFX_MGR02_LOC_DATA     pos;
   GFX_MGR02_BLEND_DATA   blend;
}GFX_MGR02_USER_IMAGE_DATA_T;

typedef void (*GFX_MGR02_GET_USER_AREA_FPTR_T)(GFX_MGR02_ELEMENT_AREA * p_elem_area, GFX_MGR02_USER_IMAGE_DATA_T * p_user_image_data);
typedef void (*GFX_MGR02_RENDER_USER_AREA_FPTR_T)(struct DCU_LAYER_tag *, struct DCU_FG_tag *);
typedef void (*GFX_MGR02_USER_AREA_RENDER_DONE_FPTR_T)(void);

/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
typedef struct
{
  GFX_MGR02_GET_USER_AREA_FPTR_T         get_area_cb;
  GFX_MGR02_RENDER_USER_AREA_FPTR_T      render_element_cb;
  GFX_MGR02_USER_AREA_RENDER_DONE_FPTR_T render_complete_cb;
}GFX_MGR02_USER_IMG_ELEMENT_T;

/*
** Value that specify that there are no vertical clipping
** (GFX_MGR02_VCLIP_DATA)
*/
#define GFX_NO_CLIP                 (0xFFFF)

/*
** Define the various BPP values to be used with the "BPP_and_encoding" member
** of the GFX_MGR02_IMAGE_T structure.
*/
#define GFX_MGR02_1BPP              (0)
#define GFX_MGR02_2BPP              (1)
#define GFX_MGR02_4BPP              (2)
#define GFX_MGR02_8BPP              (3)
#define GFX_MGR02_16BPP_RGB565      (4)
#define GFX_MGR02_24BPP             (5)
#define GFX_MGR02_32BPP             (6)
#define GFX_MGR02_4BPP_TRANSPARENCY (7)
#define GFX_MGR02_8BPP_TRANSPARENCY (8)
#define GFX_MGR02_4BPP_LUMINANCE    (9)
#define GFX_MGR02_8BPP_LUMINANCE    (10)
#define GFX_MGR02_16BPP_ARGB1555    (11)
#define GFX_MGR02_16BPP_ARGB4444    (12)
#define GFX_MGR02_16BPP_APAL8       (13)

/*
** Number of layers supported by the DCU
*/
#define GFX_MGR02_NUM_DCU_LAYERS    (16)

/*
** Possible states for the is_transparent element in GFX_MGR02_ELEMENT_AREA
** GFX_MGR02_OPEQUE       - Element is fully opeque
** GFX_MGR02_SEETHROUGH   - Element is not fully opeque
** GFX_MGR02_TRANSPARENT  - Element is fully transparent and therefore not visible.
*/
#define GFX_MGR02_OPEQUE                   (0)
#define GFX_MGR02_SEETHROUGH               (1)
#define GFX_MGR02_TRANSPARENT              (2)

/*
** Possible states for the sx element in GFX_MGR02_VISIBLE_AREA
** GFX_MGR02_OFFSET_SEETHROUGH   - Element is not fully opeque
** GFX_MGR02_OFFSET_TRANSPARENT  - Element is fully transparent and therefore not visible.
** Any other values are considered as valid values
*/
#define GFX_MGR02_OFFSET_SEETHROUGH        (-2)
#define GFX_MGR02_OFFSET_TRANSPARENT       (-1)


/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/


#ifdef  __cplusplus
}
#endif
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
** CMS Rev 1.3      24-Jul-12    EMANOJ1
** Added GFX_MGR02_OFFSET_xx definitions to support objects with semi transparent
** area offset.
**
** CMS Rev 1.2      18-Jul-12    EMANOJ1
** Warning header added to makesure that whoever modifies this file also updates
** the GDT coder to makesure that the memory usage report is correctly generated
**
** CMS Rev 1.1      10-Jul-12    EMANOJ1
** Updated the BPP_and_encoding type definitions to include the GFX_MGR02
** prefic to avoid conflict with the other (yukawa) graphics manager definitions
**
** CMS Rev 1.0      09-Jul-12    EMANOJ1
** Creation.
**==========================================================================*/

/* end of file =============================================================*/
#endif
