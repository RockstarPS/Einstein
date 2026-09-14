#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

typedef enum {
    DO_SOC_EMMC_RESET = 94,
    DO_MD_GNSS_BOOT_EN = 96,
    DI_MD_GNSS_1PPS = 97,
    DO_MD_GNSS_RESETP = 99,
    DI_MD_TOUCH_INTN = 101,
    DO_MD_TOUCH_RST = 108,
    DI_MD_TOUCH_CON_CHK = 136,
    DI_MD_TOUCH_ERROR = 137,
    INVALID = -1
} gpioPin;

#define GPIO_MAPPING_TABLE \
    X(DO_SOC_EMMC_RESET,     0, "output", false) \
    X(DO_MD_GNSS_BOOT_EN,    1, "output", false) \
    X(DI_MD_GNSS_1PPS,       2, "input",  false) \
    X(DO_MD_GNSS_RESETP,     3, "output", false) \
    X(DI_MD_TOUCH_INTN,      4, "input",  true ) \
    X(DO_MD_TOUCH_RST,       5, "output", false) \
    X(DI_MD_TOUCH_CON_CHK,   6, "input",  false) \
    X(DI_MD_TOUCH_ERROR,     7, "input",  true )

#ifdef __cplusplus
}
#endif