/*
 * Copyright (c) 2022, BlackBerry Limited. All rights reserved.
 *
 * BlackBerry Limited and its licensors retain all intellectual property and
 * proprietary rights in and to this software and related documentation. Any
 * use, reproduction, disclosure or distribution of this software and related
 * documentation without an express license agreement from BlackBerry Limited
 * is strictly prohibited.
 */

#include <time.h>
#include <unistd.h>
#include <sys/mman.h>
#include "i2c-common.h"
#include "tca6424.h"
#include "sii9022a.h"

#define CHK(condition,...)	if ((condition) != EOK){ goto err;}

struct wfdcfg_device {
	const struct wfdcfg_keyval *ext_list;
};

struct wfdcfg_port {
	int id;
	const struct wfdcfg_keyval *ext_list;
};

struct wfdcfg_mode_list {
	const struct wfdcfg_timing_internal *first_mode;
};

/* Internal structure to keep a mode and
 * its associated extension(s).
 * */
struct wfdcfg_timing_internal {
	const struct wfdcfg_timing mode;
	const struct wfdcfg_keyval *mode_ext;
};

/* Helper function(s) */
static const struct wfdcfg_timing_internal*
cast_timing_to_timing_ext(const struct wfdcfg_timing *timing) {
	char *p = (char*)timing - offsetof(struct wfdcfg_timing_internal, mode);
	return (const struct wfdcfg_timing_internal*)p;
}

static const struct wfdcfg_keyval* get_ext_from_list(const struct wfdcfg_keyval *ext_list, const char *key) {
	while (ext_list) {
		if (!ext_list->key) {
			ext_list = NULL;
			break;
		} else if (strcmp(ext_list->key, key) == 0) {
			return ext_list;
		}
		++ext_list;
	}
	return NULL;
}

/* Bit definition for BL power channel */
#define BIT_VALUE(x)                        (1 << x)

#define GPIO_BASE_REG                       0x00600000
#define GPIO_REG_SIZE                       0x2000
#define MCU_GPIO_BASE_REG                   0x04201000
#define MCU_GPIO_REG_SIZE                   256
#define GPIO_REG_GROUP_SIZE                 0x1000
#define GPIO_REG_PORT_OFFSET                0x28
#define OLDI_PD_CTRL_REG                    0x00108700
#define OLDI_PD_CTRL_REG_SIZE               4

#define GPIO_DIR01                          0x10 /* Group 0 */
#define GPIO_OUT_DATA01                     0x14
#define GPIO_SET_DATA01                     0x18
#define GPIO_CLR_DATA01                     0x1c
#define GPIO_IN_DATA01                      0x20
#define GPIO_DIR23                          0x38 /* Group 1 */
#define GPIO_OUT_DATA23                     0x3c
#define GPIO_SET_DATA23                     0x40
#define GPIO_CLR_DATA23                     0x44
#define GPIO_IN_DATA23                      0x48
#define GPIO_DIR45                          0x60 /* Group 2 */
#define GPIO_OUT_DATA45                     0x64
#define GPIO_SET_DATA45                     0x68
#define GPIO_CLR_DATA45                     0x6c
#define GPIO_IN_DATA45                      0x70
#define GPIO_DIR67                          0x88 /* Group 3 */
#define GPIO_OUT_DATA67                     0x8c
#define GPIO_SET_DATA67                     0x90
#define GPIO_CLR_DATA67                     0x94
#define GPIO_IN_DATA67                      0x98
#define GPIO_DIR8                           0xB0 /* Group 4 */
#define GPIO_OUT_DATA8                      0xB4
#define GPIO_SET_DATA8                      0xB8
#define GPIO_CLR_DATA8                      0xBc
#define GPIO_IN_DATA8                       0xC0

#define GPIO_DIR_OFFSET                     0x00
#define GPIO_OUT_OFFSET                     0x04
#define GPIO_SET_OFFSET                     0x08
#define GPIO_CLR_OFFSET                     0x0c
#define GPIO_IN_OFFSET                      0x10


#define DO_30V0_BL_PWR                      0 /* Unknown */
#define DO_TFT_BL_EN                        1 /* WKUP_CLKOUT0 */
#define DO_DISP_STBY                        2 /* MMC1_DAT0 GPIO1_45 MUXMOD=7 */
#define DO_DISP_RESET                       3 /* VOUT0_DATA7 GPIO0_52 MUXMOD=7 */
#define DO_PWM_DIMMING                      4 /* MCASP0_AXR1 GPIO1_9 MUXMOD=7 */

#define reg_access(reg, offset)	(uint32_t volatile *)(((unsigned char volatile *)reg)+offset)

typedef struct gpio_info_ {
	uint16_t offset;
	uint16_t padcfg_num;
	uint16_t port;
	uint16_t bits;
	uint16_t group;
} GPIO_INFO;

static uint32_t *gpio_regptr = NULL;
static uint32_t *mcu_gpio_regptr = NULL;
#if 0
static char * get_gpio_name_str(int gpio_name)
{
	char     *name;
	switch(gpio_name) {
		case DO_DISP_RESET: /* Group 0 line 52 */
			name = "RESET";
			break;
		case DO_DISP_STBY: /* Group 1 line 45 */
			name = "STDBY";
			break;
		case DO_PWM_DIMMING: /* Group 1 line 9 */
			name = "PDIMM";
			break;
		default:
			name = "Unknown";
		break;
	}
	return name;
}
static bool get_gpio_offset(int gpio_name, GPIO_INFO *gpio_out)
{
	uint16_t offset = 0;
	uint16_t padcfg_num = 0;
	uint16_t port = 0;
	uint16_t bits = 0;
	uint16_t group = 0;
	bool rc = true;
	
	switch(gpio_name) {
		case DO_DISP_RESET: /* Group 0 line 52 */
			padcfg_num = 52;
			port = 1;
			bits = 20;
			group = 0;
			break;
		case DO_DISP_STBY: /* Group 1 line 45 */
			padcfg_num	 = 45;
			port = 1;
			bits = 13;
			group =1;
			break;
		case DO_PWM_DIMMING: /* Group 1 line 9 */
			padcfg_num = 9;
			port = 0;
			bits = 9;
			group = 1;
			break;
		default:
			SLOG_INFO("%s: Unknown gpio name %d", __func__, gpio_name);
			rc = false;
		break;
	}
	if (rc) {
		offset = GPIO_DIR01 + (group * GPIO_REG_GROUP_SIZE) + (port * GPIO_REG_PORT_OFFSET);
		gpio_out->port = port;
		gpio_out->padcfg_num = padcfg_num;
		gpio_out->group = group;
		gpio_out->bits = bits;
		gpio_out->offset = offset;
	}
	return rc;
}

static void gpio_set_direction(uint32_t *gpio_regptr, int gpio_name, bool input)
{
	GPIO_INFO gpio;
	bool rc = get_gpio_offset(gpio_name, &gpio);
	if (rc) {
		uint32_t val = 0;
		uint32_t readval = 0;
		uint16_t offset = gpio.offset + GPIO_DIR_OFFSET;

		val = *reg_access(gpio_regptr, offset);
		val &= ~(BIT_VALUE(gpio.bits));
		if (input) {
			val |= (BIT_VALUE(gpio.bits));
		}
		*reg_access(gpio_regptr, offset) = val;
		readval = *reg_access(gpio_regptr, offset);
		SLOG_INFO("DIR: name %s: reg 0x%08x val 0x%08x readval 0x%08x port %d group %d bits %2d offset 0x%08x padcfg_num %d", get_gpio_name_str(gpio_name), offset+GPIO_BASE_REG, val, readval,
					gpio.port, gpio.group, gpio.bits, gpio.offset, gpio.padcfg_num);
	}
}

static void gpio_set_value(uint32_t *gpio_regptr, int gpio_name)
{
	GPIO_INFO gpio;
	bool rc = get_gpio_offset(gpio_name, &gpio);
	if (rc) {
		uint32_t val = 0;
		uint32_t readval = 0;
		uint16_t offset = gpio.offset + GPIO_SET_OFFSET;

		val |= (BIT_VALUE(gpio.bits));
		*reg_access(gpio_regptr, offset) = val;
		readval = *reg_access(gpio_regptr, offset);
		SLOG_INFO("SET: name %s: reg 0x%08x val 0x%08x readval 0x%08x port %d group %d bits %2d offset 0x%08x padcfg_num %d", get_gpio_name_str(gpio_name), offset+GPIO_BASE_REG, val, readval,
					gpio.port, gpio.group, gpio.bits, gpio.offset, gpio.padcfg_num);
	}
}
static void gpio_clr_value(uint32_t *gpio_regptr, int gpio_name)
{
	GPIO_INFO gpio;
	bool rc = get_gpio_offset(gpio_name, &gpio);
	if (rc) {
		uint32_t val = 0;
		uint32_t readval = 0;
		uint16_t offset = gpio.offset + GPIO_CLR_OFFSET;

		val |= (BIT_VALUE(gpio.bits));
		*reg_access(gpio_regptr, offset) = val;
		readval = *reg_access(gpio_regptr, offset);
		SLOG_INFO("CLR: name %s: reg 0x%08x val 0x%08x readval 0x%08x port %d group %d bits %2d offset 0x%08x padcfg_num %d", get_gpio_name_str(gpio_name), offset+GPIO_BASE_REG, val, readval,
					gpio.port, gpio.group, gpio.bits, gpio.offset, gpio.padcfg_num);
	}
}

static void gpio_write_value(uint32_t *gpio_regptr, int gpio_name, int bit_val)
{
	GPIO_INFO gpio;
	bool rc = get_gpio_offset(gpio_name, &gpio);
	if (rc) {
		uint32_t val = 0;
		uint32_t readval = 0;
		uint16_t offset = gpio.offset + GPIO_OUT_OFFSET;

		val = *reg_access(gpio_regptr, offset);
		if (bit_val) {
			val |= (BIT_VALUE(gpio.bits));
		} else {
			val &= ~(BIT_VALUE(gpio.bits));
		}
		*reg_access(gpio_regptr, offset) = val;
		readval = *reg_access(gpio_regptr, offset);
		SLOG_INFO("OUT: name %s: reg 0x%08x val 0x%08x readval 0x%08x port %d group %d bits %2d offset 0x%08x padcfg_num %d", get_gpio_name_str(gpio_name), offset+GPIO_BASE_REG, val, readval,
					gpio.port, gpio.group, gpio.bits, gpio.offset, gpio.padcfg_num);
	}
}
#endif
static bool config_display(void)
{
	uint32_t *oldi_pd_ctrl_regptr = NULL;
	if ((oldi_pd_ctrl_regptr = mmap_device_memory(0, OLDI_PD_CTRL_REG_SIZE,
			PROT_READ|PROT_WRITE|PROT_NOCACHE, MAP_SHARED, OLDI_PD_CTRL_REG)) == 0) {
		SLOG_ERROR("failed to map oldi_pd_ctrl_regptr registers");
		return false;
	}
	uint32_t val = *oldi_pd_ctrl_regptr;
	SLOG_INFO("%s: READ oldi_pd_ctrl_regptr val 0x%08x", __func__, val);
	val &=~(BIT_VALUE(0) + BIT_VALUE(1) + BIT_VALUE(8));
	*oldi_pd_ctrl_regptr = val;
	SLOG_INFO("%s: WRITE oldi_pd_ctrl_regptr val 0x%08x", __func__, val);
	while (!(*oldi_pd_ctrl_regptr & BIT_VALUE(31))){
		usleep(100);
	}

	if (oldi_pd_ctrl_regptr) {
		munmap_device_memory(oldi_pd_ctrl_regptr, OLDI_PD_CTRL_REG_SIZE);
	}
#if 0
	/* Set GPIO as outputs */
	gpio_set_direction(gpio_regptr, DO_DISP_RESET, false);
	gpio_set_direction(gpio_regptr, DO_DISP_STBY, false);
	gpio_set_direction(gpio_regptr, DO_PWM_DIMMING, false);

	gpio_clr_value(gpio_regptr, DO_DISP_RESET);
	gpio_clr_value(gpio_regptr, DO_DISP_STBY);
	gpio_clr_value(gpio_regptr, DO_PWM_DIMMING);
	usleep(300*1000);
	gpio_set_value(gpio_regptr, DO_DISP_RESET);
	usleep(18*1000);
	gpio_set_value(gpio_regptr, DO_DISP_STBY);
	usleep(120*1000);
	gpio_set_value(gpio_regptr, DO_PWM_DIMMING);
	usleep(120*1000);
#endif
	return true;
}

static int lvds_set_mode(struct wfdcfg_port* port, const struct wfdcfg_timing* timings)
{
	int rc = EOK;

	SLOG_INFO("%s: starting port_id %d", __func__, port->id);

	/* Map GPIO registers */
	if ((gpio_regptr = mmap_device_memory(0, GPIO_REG_SIZE,
		PROT_READ|PROT_WRITE|PROT_NOCACHE, MAP_SHARED, GPIO_BASE_REG)) == 0) {
		SLOG_ERROR("failed to map GPIO registers");
		rc = EINVAL;
		goto done;
	}
	/* Map MCU GPIO registers */
	if ((mcu_gpio_regptr = mmap_device_memory(0, MCU_GPIO_REG_SIZE,
		PROT_READ|PROT_WRITE|PROT_NOCACHE, MAP_SHARED, MCU_GPIO_BASE_REG)) == 0) {
		SLOG_ERROR("failed to map MCU_GPIO registers");
		rc = EINVAL;
		goto done;
	}

	config_display();

done:
	if (gpio_regptr) {
		munmap_device_memory(gpio_regptr, GPIO_REG_SIZE);
	}
	if (mcu_gpio_regptr) {
		munmap_device_memory(mcu_gpio_regptr, MCU_GPIO_REG_SIZE);
	}

	return rc;
}

static int hdmi_set_mode(struct wfdcfg_port* port, const struct wfdcfg_timing* timings)
{
	if (!am62x_hdmi_reset()) {
		return 1;
	}
	return am62x_hdmi_init(timings);
}

static const struct wfdcfg_keyval lvds_port_exts[] = {
	{ WFDCFG_EXT_FN_PORT_SET_MODE2, .p = WFDCFG_FNPTR(&lvds_set_mode, wfdcfg_ext_fn_port_set_mode2_t*) },
	{
		.key = WFDCFG_EXT_PIXEL_CLOCK_KHZ,
		.i = 89456,
		.p = NULL
	},
	{
		.key = WFDCFG_EXT_LVDS_HW_ATTACH,
		.i = 1, /* Enabled */
		.p = NULL
	},
	{
		.key = WFDCFG_EXT_LVDS_CONFIG_MAP_TYPE,
		.i = 6, /* config map of type F */
		.p = NULL
	},
	{
		.key = WFDCFG_EXT_LVDS_DUALMODE_SYNC,
		.i = 1, /* dualmode sync disabled */
		.p = NULL
	},
	{ NULL },
};

static const struct wfdcfg_keyval hdmi_port_exts[] = {
	{ WFDCFG_EXT_FN_PORT_SET_MODE2, .p = WFDCFG_FNPTR(&hdmi_set_mode, wfdcfg_ext_fn_port_set_mode2_t*) },
	{
		.key = WFDCFG_EXT_PIXEL_CLOCK_KHZ,
		.i = 148500,
		.p = NULL
	},
	{ NULL },
};

static const struct wfdcfg_keyval lvds_mode_exts[] = {
	// marks end of list
	{ NULL }
};

static const struct wfdcfg_keyval hdmi_mode_exts[] = {
	// marks end of list
	{ NULL }
};

static const struct wfdcfg_timing_internal lvds_timings[] = {
	{

		 // Mode: 1920 x 720 @ 60Hz
		.mode =  {
			.pixel_clock_kHz = 89456,
			.hpixels = 1920, .hfp = 44, .hsw = 52, .hbp = 32,  // 2048 total
			.vlines  = 720, .vfp = 2,  .vsw = 2,  .vbp = 4,    // 728 total
			.flags   = WFDCFG_INVERT_HSYNC | WFDCFG_INVERT_VSYNC | WFDCFG_INVERT_HV_SYNC_RF
		},
		.mode_ext = lvds_mode_exts,
	},
	{
		// marks end of list
		.mode = {.pixel_clock_kHz =  0},
	},
};

static const struct wfdcfg_timing_internal hdmi_timings[] = {
	{
		 // Mode: 1920 x 1080p @ 60Hz 16:9
		.mode =  {
			.pixel_clock_kHz = 148500,
			.hpixels = 1920, .hfp = 88, .hsw = 44, .hbp = 148,   // 2200 total
			.vlines  = 1080, .vfp = 4,  .vsw = 5,  .vbp = 36,    // 1125 total
			.flags   = WFDCFG_INVERT_HSYNC | WFDCFG_INVERT_VSYNC | WFDCFG_INVERT_HV_SYNC_RF
		},
		.mode_ext = hdmi_mode_exts,
	},
	{
		// marks end of list
		.mode = {.pixel_clock_kHz =  0},
	},
};

static const struct wfdcfg_keyval device_ext[] = {
	{
		.key = WFDCFG_EXT_DPI0_CONNECTION,
		.i = DPI_VP1_CONNECTION,
		.p = NULL,
	},
	{
		.key = WFDCFG_EXT_DPI1_CONNECTION,
		.i = DPI_VP2_CONNECTION,
		.p = NULL,
	},
	{   /* marks end of list */
		.key = NULL,
		.i = 0,
		.p = NULL,
	},
};

int
wfdcfg_device_create(struct wfdcfg_device **device, int deviceid,
	const struct wfdcfg_keyval *opts) {
	int err = EOK;
	struct wfdcfg_device *tmp_dev = NULL;
	(void)opts;

	SLOG_DEBUG("%s: Create device id %d", __func__, deviceid);
	switch(deviceid) {
		case 1:
			tmp_dev = malloc(sizeof(*tmp_dev));
			if(!tmp_dev) {
				err = ENOMEM;
				goto end;
			}

			tmp_dev->ext_list = device_ext;
			SLOG_DEBUG("%s: Create device ext_list 0x%p", __func__, tmp_dev->ext_list);

			break;
		default:
			/* Invalid device id*/
			err = ENOENT;
			goto end;
	}

end:
	if(err) {
		free(tmp_dev);
	} else {
		*device = tmp_dev;
	}
	return err;
}

const struct wfdcfg_keyval*
wfdcfg_device_get_extension(const struct wfdcfg_device *device, const char *key) {
	if (device){
		SLOG_DEBUG("%s ext_list 0x%p key %s", __func__, device->ext_list, key);
	} else {
		SLOG_DEBUG("%s ext_list NULL key %s", __func__, key);
	}
	return get_ext_from_list(device->ext_list, key);
}

void
wfdcfg_device_destroy(struct wfdcfg_device *device) {
	free(device);
}

int
wfdcfg_port_create(struct wfdcfg_port **port, const struct wfdcfg_device *device, int portid,
	const struct wfdcfg_keyval *opts) {
	int err = EOK;
	struct wfdcfg_port *tmp_port = NULL;
	(void)opts;

	assert(device);

	SLOG_DEBUG("%s: portid %d", __func__, portid);
	switch(portid) {
		case 1:
			tmp_port = malloc(sizeof(*tmp_port));
			if(!tmp_port) {
				err = ENOMEM;
				goto end;
			}
			tmp_port->id = portid;
			tmp_port->ext_list = lvds_port_exts;
			SLOG_INFO("%s: Port->id %d LVDS", __func__, tmp_port->id);
			break;
		case 2:
			tmp_port = malloc(sizeof(*tmp_port));
			if(!tmp_port) {
				err = ENOMEM;
				goto end;
			}
			tmp_port->id = portid;
			tmp_port->ext_list = hdmi_port_exts;
			SLOG_INFO("%s: Port->id %d HDMI", __func__, tmp_port->id);
			break;
		default:
			/* Invalid port id*/
			err = ENOENT;
			goto end;
	}

end:
	if(err) {
		free(tmp_port);
	} else {
		*port = tmp_port;
	}
	SLOG_DEBUG("%s: portid %d err %d port 0x%p", __func__, portid, err, *port);
	return err;
}

const struct wfdcfg_keyval*
wfdcfg_port_get_extension(const struct wfdcfg_port *port, const char *key) {
	return get_ext_from_list(port->ext_list, key);
}

void
wfdcfg_port_destroy(struct wfdcfg_port *port) {
	free(port);
}

int
wfdcfg_mode_list_create(struct wfdcfg_mode_list **list,
	const struct wfdcfg_port* port, const struct wfdcfg_keyval *opts) {

	int err = 0;
	const struct wfdcfg_timing_internal *first_mode;
	struct wfdcfg_mode_list *tmp_mode_list = NULL;

	(void)opts;

	assert(port);

	switch (port->id) {
	case 1:
		first_mode = &lvds_timings[0];
		break;
	case 2:
		first_mode = &hdmi_timings[0];
		break;
	default:
		err = ENOENT;
		goto out;
	}

	tmp_mode_list = malloc(sizeof *tmp_mode_list);
	if (!tmp_mode_list) {
		err = ENOMEM;
		goto out;
	}
	tmp_mode_list->first_mode = first_mode;

out:
	if (err) {
		free(tmp_mode_list);
	} else {
		*list = tmp_mode_list;
	}
	return err;
}

const struct wfdcfg_keyval*
wfdcfg_mode_list_get_extension(const struct wfdcfg_mode_list *mode_list, const char *key) {
	(void)mode_list;
	(void)key;
	return NULL;
}

void
wfdcfg_mode_list_destroy(struct wfdcfg_mode_list *list) {
	free(list);
}

const struct wfdcfg_timing*
wfdcfg_mode_list_get_next(const struct wfdcfg_mode_list *list,
	const struct wfdcfg_timing *prev_mode) {

	assert(list);

	const struct wfdcfg_timing_internal *m = list->first_mode;
	if (prev_mode) {
		m = cast_timing_to_timing_ext(prev_mode) + 1;
	}

	if (m->mode.pixel_clock_kHz == 0) {
		// end of list (this is not an error)
		m = NULL;
	}
	return m ? &m->mode : NULL;
}

const struct wfdcfg_keyval*
wfdcfg_mode_get_extension(const struct wfdcfg_timing *mode,
	const char *key) {

	const struct wfdcfg_keyval *ext = cast_timing_to_timing_ext(mode)->mode_ext;
	return get_ext_from_list(ext, key);
}

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/graphics/branches/release-3.x.x/hardware/wfd/jacinto7/wfdcfg/am62x-evm/am62x-evm.c $ $Rev: 964147 $")
#endif
