/*****************************************************************************
*
* Copyright (c) Imagination Technologies Ltd.
* Copyright (c) 2018-22 Texas Instruments Incorporated - http://www.ti.com/
*
* The contents of this file are subject to the MIT license as set out below.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHERa
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* Alternatively, the contents of this file may be used under the terms of the
* GNU General Public License Version 2 ("GPL")in which case the provisions of
* GPL are applicable instead of those above.
*
* If you wish to allow use of your version of this file only under the terms
* of GPL, and not to allow others to use your version of this file under the
* terms of the MIT license, indicate your decision by deleting the provisions
* above and replace them with the notice and other provisions required by GPL
* as set out in the file called "GPLHEADER" included in this distribution. If
* you do not delete the provisions above, a recipient may use your version of
* this file under the terms of either the MIT license or GPL.
*
* This License is also included in this distribution in the file called
* "MIT_COPYING".
*
*****************************************************************************/
/*
 * firmware header
 */

#ifndef _MTX_FWIF_H_
#define _MTX_FWIF_H_

#include "vxe_common.h"
#include "topazscfwif.h"

//#define VXE_MEASURE_MTX_CLK_FREQ

/*
 * enum describing the MTX load method
 */
 enum mtx_load_method {
	MTX_LOADMETHOD_NONE = 0,        /* don't load MTX code */
	MTX_LOADMETHOD_BACKDOOR,        /* backdoor - writes MTX load data direct to out.res */
	MTX_LOADMETHOD_REGIF,           /* load mtx code via register interface */
	MTX_LOADMETHOD_DMA,             /* load mtx code via DMA */
	MTX_LOADMETHOD_FORCE32BITS = 0x7FFFFFFFU

};

/*
 * defines that should come from auto generated headers
 */
#define MTX_DMA_MEMORY_BASE (0x82880000)
#define PC_START_ADDRESS    (0x80900000)

#define MTX_CORE_CODE_MEM   (0x10)
#define MTX_CORE_DATA_MEM   (0x18)

#define MTX_PC              (0x05)


/*
 * MTX Firmware Context Structure
 */

/*
 * struct img_fw_int_defines_table - contains info for the fw int defines
 *
 * @length: lenth of the table
 * @names: array of names of entries
 * @values: array of values of entries
 */
struct img_fw_int_defines_table {
	uint32 length;
	osa_char** names;
	uint32 * values;
};

/*
 * struct img_fw_context - contains info for the context of the loaded firmware
 *
 * @initialized: osa_true if MTX core is initialized
 * @populated: osa_true if MTX firmware context had been populated with data
 * @active_ctx_mask: A bit mask of active encode contexts in the firmware
 * @dev_ctx: Pointer to the device context
 * @load_method: method used to load this MTX
 * @supported_codecs: Codec mask
 * @mtx_debug_val: Value in MTX Debug register (for RAM config)
 * @mtx_ram_size: Size of MTX RAM
 * @mtx_bank_size: Size of MTX RAM banks
 * @mtx_reg_mem_space_addr: Memspace ID for MTX registers
 * @topaz_reg_mem_space_addr: Memspace ID for TOPAZ registers
 * @topaz_multicore_reg_addr: Memspace ID for TOPAZ multicore control registers
 * @core_rev: Hardware core revision ID
 * @core_des1: Hardware core designer (feature bits)
 * @drv_has_mtx_ctrl: osa_true if driver (not DASH) has control of MTX
 * @access_control: Use to get read/write access to MTX
 * @hw_num_pipes: Number of pipes available in hardware
 * @num_pipes: Number of pipes supported by firmware
 * @num_contexts: Number of contexts supported by firmware
 * @mtx_context_data_copy: Copy of MTX Context Data during hibernate
 * @mtx_reg_copy: Copy of MTX Register block during hibernate
 * @mtx_topaz_fw_text_size: Size of MTX Firmware Text Section in words
 * @mtx_topaz_fw_text: Pointer to MTX Firmware Text Section
 * @mtx_topaz_fw_data_size: Size of MTX Firmware Data Section in words
 * @mtx_topaz_fw_data: Pointer to MTX Firmware Data Section
 * @mtx_topaz_fw_data_origin: Offset to location of Data section
 * @int_defines: table of int defines
 */
struct img_fw_context {
	uint16 initialized;
	uint16 populated;
	uint8  active_ctx_mask;

	void *dev_ctx;

	enum mtx_load_method load_method;

	uint32 supported_codecs;

	uint32 mtx_debug_val;
	uint32 mtx_ram_size;
	uint32 mtx_bank_size;

	void * mtx_reg_mem_space_addr;
	void * topaz_reg_mem_space_addr[TOPAZHP_MAX_NUM_PIPES];
	void * topaz_multicore_reg_addr;
	uint32 core_rev;
	uint32 core_des1;

	uint16 drv_has_mtx_ctrl;
	uint32 access_control;

	uint32 hw_num_pipes;
	uint32 num_pipes;
	uint32 num_contexts;

	struct vidio_ddbufinfo *mtx_context_data_copy[TOPAZHP_MAX_POSSIBLE_STREAMS];
	uint32 *mtx_reg_copy;

	uint32 mtx_topaz_fw_text_size;
	uint32 *mtx_topaz_fw_text;

	uint32 mtx_topaz_fw_data_size;
	uint32 *mtx_topaz_fw_data;

	uint32 mtx_topaz_fw_data_origin;

	struct img_fw_int_defines_table int_defines;
};


/*
 * Populates MTX context structure
 * @param    codec         : version of codec specific firmware to associate with this MTX
 * @param    fw_ctx       : Output context
 * @return   int32 : Standard IMG_ERRORCODE
 */
int32 mtx_populate_fw_ctx(enum img_codec codec,
			  struct img_fw_context * fw_ctx);

/*
 * Initialise the hardware using given (populated) MTX context structure
 * @param    fw_ctx       : Pointer to the context of the target MTX
 * @return   None
 */
void mtx_initialize(void * dev_ctx, struct img_fw_context * fw_ctx);

/*
 * Return the integer define used to compile given version of firmware.
 * @param    fw_ctx       : Pointer to the context of the target MTX
 * @param    name       : Name of a define (string)
 * @return   Value of define or -1 if not found.
 */
int32 mtx_get_fw_config_int(struct img_fw_context const * const fw_ctx,
			    osa_char const * const name);

/*
 * Load text and data sections onto an MTX.
 * @param    fw_ctx         : Pointer to the context of the target MTX
 * @param    load_method      : Method to use for loading code
 * @return   None
 */
void mtx_load(void * dev_ctx, struct img_fw_context *fw_ctx,
	      enum mtx_load_method load_method);

/*
 * Deinitialises MTX and MTX control structure
 */
void mtx_deinitialize(struct img_fw_context *fw_ctx);

/*
 * Saves MTX State -- Registers and Data Memory
 */
void mtx_save_state(struct img_fw_context *fw_ctx);

/*
 * Restores MTX State -- Registers and Data Memory
 */
void mtx_restore_state(void * ctx, struct img_fw_context *fw_ctx);

/*
 * mtx_start
 */
void mtx_start(struct img_fw_context *fw_ctx);

/*
 * mtx_stop
 */
void mtx_stop(struct img_fw_context * fw_ctx);

/*
 * Kicks MTX
 */
void mtx_kick(struct img_fw_context *fw_ctx, uint32 kick_count);

/*
 * Waits for MTX to halt
 */
void mtx_wait_for_completion(struct img_fw_context *fw_ctx);

#endif
