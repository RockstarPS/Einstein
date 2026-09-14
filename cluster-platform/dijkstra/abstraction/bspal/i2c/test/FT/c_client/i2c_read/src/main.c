#include "dk_bspal_i2c.h"
#include <stdlib.h>

LOG_DECLARE_CONTEXT(g_log_i2c_read);

int main(int argc, const char *argv[])
{
    uint8_t l_unit_id_U8;
    uint16_t l_addr_U16;
    uint32_t l_size_U32;
    bool l_ret_val;
    int l_idx;

    l_unit_id_U8 = (uint8_t) strtoul(argv[1], NULL, 0);
    l_addr_U16 = (uint16_t) strtoul(argv[2], NULL, 0);
    l_size_U32 = (uint16_t) strtoul(argv[3], NULL, 0);

    uint8_t l_data_U8A[l_size_U32];

    LOG_REGISTER_APP_CONSOLE("I2CA", "i2c_read test app");
    LOG_REGISTER_CONTEXT(
        g_log_i2c_read, "I2CR", "i2c_read test app ctx", DLT_LOG_VERBOSE);

    dk_bspal_i2c_init(DLT_LOG_VERBOSE);

    l_ret_val =
        dk_bspal_i2c_read(l_unit_id_U8, l_addr_U16, l_data_U8A, l_size_U32);

    LOGV(&g_log_i2c_read, "l_ret_val - %d", l_ret_val);

    if (true == l_ret_val)
    {
        for (l_idx = 0; l_idx < l_size_U32; l_idx++)
        {
            LOGV(&g_log_i2c_read,
                 "l_data_U8A[%d] - %xh",
                 l_idx,
                 l_data_U8A[l_idx]);
        }
    }

    dk_bspal_i2c_deinit();

    return 0;
}
