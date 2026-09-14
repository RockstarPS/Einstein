#ifndef DK_BSPAL_I2C_H
#define DK_BSPAL_I2C_H

/*==============================================================================
**
** Copyright 2024 Visteon Corporation.
**
** These materials and the intellectual property rights associated therewith
** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
** the Materials are reserved by Visteon Corporation. Nothing contained in
** these Materials shall grant or be deemed to grant to you or anyone else, by
** implication, estoppel or otherwise, any rights in these Materials.
**
**============================================================================*/

/*==============================================================================
** Standard Header Files
**============================================================================*/
#include <stdbool.h>
#include <stdint.h>

/*==============================================================================
** Other Header Files
**============================================================================*/
#include "dk_logger.h"

#ifdef __cplusplus
extern "C" { /* ! Inclusion of header files should NOT be inside the extern "C"
                block */
#endif       /* __cplusplus */
/*==============================================================================
** Exported Preprocessor #define Constants
**============================================================================*/

/*==============================================================================
** Exported Preprocessor #define MACROS
**============================================================================*/

/*==============================================================================
** Exported Type Declarations
**============================================================================*/

/*==============================================================================
** Exported Object Declarations
**============================================================================*/

/*==============================================================================
** Exported Function Prototypes
**============================================================================*/
extern void dk_bspal_i2c_init(const DltLogLevelType p_log_level);
extern void dk_bspal_i2c_deinit(void);
extern bool dk_bspal_i2c_read(const uint8_t p_unit_id_U8,
                              const uint16_t p_addr_U16,
                              uint8_t *const p_data_U8P,
                              const uint32_t p_size_U32);

/*==============================================================================
** Exported Inline Function Definitions and #define Function-Like Macros
**============================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
/*==============================================================================
** File Revision History (top to bottom: first revision to last revision)
**==============================================================================
**
** Date        cdsid    (Description on following lines: JIRA ISSUE #, etc.)
** ----------- --------
** 2024-07-04  asundar6
** + Created initial file.
**
**============================================================================*/

#endif /* DK_BSPAL_I2C_H */
