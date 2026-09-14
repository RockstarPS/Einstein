#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>



typedef enum {
    DO_DISP_RESET = 15,
    DO_SOC_FPDLINK3_PDB = 30,
    DO_ENET_RSTB = 36,
    DO_ENET_EN = 40,
    DO_DISP_STBY = 50,
    DO_TFT_CSB = 12,
    INVALID = -1
} gpioPin;

#define GPIO_MAPPING_TABLE \
    X(DO_DISP_RESET,        "output", false) \
    X(DO_SOC_FPDLINK3_PDB,  "output", false) \
    X(DO_ENET_RSTB,         "output", false) \
    X(DO_ENET_EN,           "output", false) \
    X(DO_DISP_STBY,         "output", false) \
    X(DO_TFT_CSB,           "output", false )

#ifdef __cplusplus
}
#endif