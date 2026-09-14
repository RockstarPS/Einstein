#ifndef PROGRAM_CFH_H
#define PROGRAM_CFH_H

//#define ENABLE_PROFILING
#define ENABLE_AB
#define ENABLE_RECOVERY

#define ENABLE_HSM
#define ENABLE_VIP
#define ENABLE_GIP


#define DM_DLT_LOG_ENABLED

//#define KPI_GPIO
#ifdef KPI_GPIO

#define KPI_STAGE1_GPIO_PIN_NAME	PIN_OSPI0_LBCLKO	//TP12034
#define KPI_STAGE1_GPIO_PINNUM 		1
#define KPI_STAGE1_GPIO_BASE   		CSL_GPIO0_BASE

#define KPI_STAGE2_GPIO_PIN_NAME     	PIN_MMC2_SDWP		//TP12069
#define KPI_STAGE2_GPIO_PINNUM		72
#define KPI_STAGE2_GPIO_BASE   		CSL_GPIO0_BASE

#define KPI_STAGE2_NOR_GPIO_PIN_NAME	PIN_EXT_REFCLK1		//TP12071
#define KPI_STAGE2_NOR_GPIO_PINNUM	30
#define KPI_STAGE2_NOR_GPIO_BASE  	CSL_GPIO1_BASE

#define KPI_STAGE2_EMMC_GPIO_PIN_NAME	PIN_GPMC0_CLK		//TP12061
#define KPI_STAGE2_EMMC_GPIO_PINNUM	31
#define KPI_STAGE2_EMMC_GPIO_BASE 	CSL_GPIO0_BASE

#endif

#define BANK_A          0x55U
#define BANK_B          0xAAU
#define BANK_INVALID    0xFFU

#define BOOT_PRIMARY     0x55U
#define BOOT_RECOVERY    0xAAU
#define BOOT_INVALID     0xFFU

#define KERNEL_PARAM_INVALID     0xFFU
#define KERNEL_PARAM_PRIMARY_A   0U
#define KERNEL_PARAM_PRIMARY_B   1U
#define KERNEL_PARAM_RECOVERY_A  2U
#define KERNEL_PARAM_RECOVERY_B  3U

typedef struct {
    uint8_t boot_instance;
    char partition_num;
    const char *boot_mode;   // "PRI" or "REC"
} kernel_params_t;

static const kernel_params_t params_table[] = {
    {
        KERNEL_PARAM_PRIMARY_A,
        '3',
        "PRI"
    },
    {
        KERNEL_PARAM_PRIMARY_B,
        '4',
        "PRI"
    },
    {
        KERNEL_PARAM_RECOVERY_A,
        '5',
        "REC"
    },
    {
        KERNEL_PARAM_RECOVERY_B,
        '6',
        "REC"
    },
};

/*
 * Routines defined in sbl_utils.c
 */
uint8_t getBootMode(void);
uint8_t setBootMode(uint8_t flag);
uint8_t getActiveBank(void);
int32_t loadMetadata(void);
int32_t isMetadataAvaiable(void);
void board_reboot(void);

#endif
