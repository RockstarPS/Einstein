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
#include <errno.h>
#include <fcntl.h>
#include <hw/i2c.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* clang-format off */

#include <sys/types.h>
#include <unistd.h>
#include <devctl.h>

/* clang-format on */

/*==============================================================================
** Other Header Files
**============================================================================*/
#include "dk_bspal_i2c.h"

/*==============================================================================
** Local Preprocessor #define Constants
**============================================================================*/
#define DEV_NAME_PATH "/dev/i2c%d"
#define PATH_LEN (16u)
#define I2C_ADDRMASK_7BIT (0x7Fu)

/*==============================================================================
** Local Preprocessor #define MACROS
**============================================================================*/

/*==============================================================================
** Local Type Declarations
**============================================================================*/

/*==============================================================================
** Exported Object Definitions
**============================================================================*/
LOG_DECLARE_CONTEXT(g_log_bspal_i2c);

/*==============================================================================
** Local Object Definitions
**============================================================================*/

/*==============================================================================
** Local Function Prototypes
**============================================================================*/

/*==============================================================================
** Local Inline Function Definitions and Function-Like Macros
**============================================================================*/

/*==============================================================================
** Function Definitions
**============================================================================*/
/*==============================================================================
** @brief Intialize the I2C BSPAL
**
** @param[in] p_log_level    Display configuration ifs partition path pointer
**
**============================================================================*/
void dk_bspal_i2c_init(const DltLogLevelType p_log_level)
{
    LOG_REGISTER_CONTEXT(
        g_log_bspal_i2c, "I2C", "DK BSPAL I2C CONTEXT", p_log_level);
}

/*==============================================================================
** @brief De-initialize the I2C BSPAL
**
**============================================================================*/
void dk_bspal_i2c_deinit(void)
{
    LOG_UNREGISTER_CONTEXT(g_log_bspal_i2c);
}

/*==============================================================================
** @brief This method is used to read data from the I2C peripheral
**
** @param p_unit_id_U8 ID of the connection to the specified I2C
** @param p_addr_U16 Address of the I2C
** @param p_data Container of the data to be read
** @param p_size_U32 Size of the data to be read
**
** @return bool Read status
**============================================================================*/
bool dk_bspal_i2c_read(const uint8_t p_unit_id_U8,
                       const uint16_t p_addr_U16,
                       uint8_t *const p_data_U8P,
                       const uint32_t p_size_U32)
{
    bool l_ret_status_BOOL = false;
    int l_ret_INT = 0;
    int l_fd_INT = 0;
    char l_path_S8A[PATH_LEN];
    struct {
        i2c_recv_t m_info_S;
        uint8_t m_data_U8A[p_size_U32];
    } l_recv_S;

    l_ret_INT = snprintf(l_path_S8A, PATH_LEN, DEV_NAME_PATH, p_unit_id_U8);
    if (l_ret_INT < 0)
    {
        LOGE(&g_log_bspal_i2c, "snprintf() failed");
        l_ret_status_BOOL = false;
        goto func_ret;
    }

    l_fd_INT = open(l_path_S8A, O_RDWR);
    if (-1 == l_fd_INT)
    {
        LOGE(&g_log_bspal_i2c, "unable to open() %s", l_path_S8A);
        l_ret_status_BOOL = false;
        goto func_ret;
    }

    l_recv_S.m_info_S.slave.addr = p_addr_U16; /* I2C address */
    l_recv_S.m_info_S.slave.fmt =
        (p_addr_U16 <= I2C_ADDRMASK_7BIT
             ? I2C_ADDRFMT_7BIT
             : I2C_ADDRFMT_10BIT);      /* 7- or 10-bit format */
    l_recv_S.m_info_S.len = p_size_U32; /* length of receive data in bytes */
    l_recv_S.m_info_S.stop = 1; /* send stop when complete? (0=no, 1=yes) */

    l_ret_INT =
        devctl(l_fd_INT, DCMD_I2C_RECV, &l_recv_S, sizeof(l_recv_S), NULL);
    if (EOK != l_ret_INT)
    {
        LOGE(&g_log_bspal_i2c, "devctl() failed");
        l_ret_status_BOOL = false;
        goto clean_up;
    }

    (void) memcpy(p_data_U8P, l_recv_S.m_data_U8A, p_size_U32);
    l_ret_status_BOOL = true;

clean_up:
    l_ret_INT = close(l_fd_INT);
    if (-1 == l_ret_INT)
    {
        LOGE(&g_log_bspal_i2c, "unable to close()");
        l_ret_status_BOOL = false;
    }
func_ret:
    return l_ret_status_BOOL;
}

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
