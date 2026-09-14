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

#ifndef _TOPAZSCFWIF_H_
#define _TOPAZSCFWIF_H_

#include "coreflags.h"
#include "osal/inc/osa_types.h"

#define MAX_QP_H264			(51)
#define WRONG_QP			(255)

/*
 * The number of bytes used by each MVEA MV param & above param region
 */
#define MVEA_MV_PARAM_REGION_SIZE 16
#define MVEA_ABOVE_PARAM_REGION_SIZE 96

/*
 * Macros to align to the correct number of bytes
 */
#define ALIGN_4(X)  (((X)+3) &~3)
#define ALIGN_8(X)  (((X)+7) &~7)
#define ALIGN_16(X)  (((X)+15) &~15)
#define ALIGN_32(X)  (((X)+31) &~31)
#define ALIGN_64(X)  (((X)+63) &~63)
#define ALIGN_128(X)  (((X)+127) &~127)
#define ALIGN_256(X)  (((X)+255) &~255)
#define ALIGN_1024(X)	(((X)+1023) &~1023)

/*
 * Minimum number of bytes required in a buffer
 */
#define CODED_BUFFER_MARGIN_H264 10000
#define CODED_BUFFER_MARGIN_H263 768000

/*
 * Context size allocated from host application
 */
#define MTX_CONTEXT_SIZE (13 * 1024)

/*
 * SEI (Buffering Period and Picture Timing) Constants shared
 * between host and firmware
 */
#define BPH_SEI_NAL_INITIAL_CPB_REMOVAL_DELAY_SIZE 23
#define PTH_SEI_NAL_CPB_REMOVAL_DELAY_SIZE 23
#define PTH_SEI_NAL_DPB_OUTPUT_DELAY_SIZE 7

/*
 * Size of Inter/Intra & Coded/Skipped tables
 */
#define SCALE_TBL_SZ                    (8)

/*
 * Size of the header in output coded buffer. This varies based on
 *              whether data logging is enabled/disabled
 */
#if defined (INCLUDE_CRC_REGISTER_CHECKS)
#define CRC_REGISTER_FEEDBACK_SIZE	(80*4)
#else
#define CRC_REGISTER_FEEDBACK_SIZE	0
#endif

#define CODED_BUFFER_HEADER_SIZE    64 // MUST be aligned to the DMA 64 byte boundary condition (CRC data is DMA'd after the coded buffer header)
#define CODED_BUFFER_INFO_SECTION_SIZE (CODED_BUFFER_HEADER_SIZE + CRC_REGISTER_FEEDBACK_SIZE)

/*
 * Mask defines for the -ui8EnableSelStatsFlags variable
 */
#define ESF_FIRST_STAGE_STATS 1
#define ESF_MP_BEST_MB_DECISION_STATS 2
#define ESF_MP_BEST_MOTION_VECTOR_STATS 4


#define CUSTOM_QUANT_PARAMSIZE_8x8 2

#define CUSTOM_QUANT_TABLESIZE_8x8 (6+CUSTOM_QUANT_PARAMSIZE_8x8)

/*
 * Combined size of H.264 quantization lists (6 * 16 + {2 or 6} * 64)
 */
#define QUANT_LISTS_SIZE		(6 * 16 + CUSTOM_QUANT_PARAMSIZE_8x8 * 64)

/*
 * JPEG input quantization table size
 */
#define QUANT_TABLE_SIZE_BYTES	(64)

/*
 * JPEG input parameter sizes
 */
#define MTX_MAX_COMPONENTS		(3)

/*
 * Size in bytes and words of memory to transfer partially coded header data
 */
#define MAX_HEADERSIZEBYTES		(128)
#define MAX_HEADERSIZEWORDS		(32)

/*
 * Maximum number of slices per field
 */
#define MAX_SLICESPERPIC		(128)

/*
 * Picture parameter flags used in the PIC_PARAM structure
 */
#define ISINTERP_FLAGS					(0x00000001)
#define ISRC_FLAGS						(0x00000010)
#define ISRC_I16BIAS					(0x00000020)
#define ISINTERB_FLAGS					(0x00000080)
#define ISSCENE_DISABLED				(0x00000100)
#define ISMULTIREF_FLAGS				(0x00000200)
#define SPATIALDIRECT_FLAGS				(0x00000400)

/*
 * Enum describing contents of scratch registers
 */
enum mtx_scratch_regdata {
	MTX_SCRATCHREG_BOOTSTATUS = 0,
	MTX_SCRATCHREG_UNUSED = 0,
	MTX_SCRATCHREG_TOHOST,			//!< Reg for MTX->Host data
	MTX_SCRATCHREG_TOMTX,			//!< Reg for Host->MTX data

	MTX_SCRATCHREG_SIZE,				//!< End marker for enum
	MTX_SCRATCHREG_FORCE32BITS = 0x7FFFFFFFU
};

/*
	`MTX_SCRATCHREG_IDLE` register that is used for synchronous communication and debug.

	Current register usage:
	<bits, inclusive boundaries> : <usage>
	2-10 : Number of executed commands (mod 255)
	0-1 : FW idle status
*/
#define MTX_SCRATCHREG_IDLE			TOPAZHP_TOP_CR_FIRMWARE_REG_4 //!< Reg for firmware IDLE status

/*
	`FW_LINE_COUNTER` register that is used for low-latency encoding

	Current register usage:
	<bits, inclusive boundaries> : <usage>
	31-16	: Frame counter
	11-0	: Line counter
*/
#define FW_LINE_COUNTER				TOPAZHP_TOP_CR_FIRMWARE_REG_5 //!< Reg for firmware line counter

/* Flags relating to MTX_SCRATCHREG_IDLE */
#define SHIFT_FW_IDLE_REG_LINE_REQUESTED	(10)										/* Bits [10-22] are used for the line information */
#define MASK_FW_IDLE_REG_LINE_REQUESTED		(0xFFF << SHIFT_FW_IDLE_REG_LINE_REQUESTED)	/* TOPAZHP_LINE_COUNTER (see TRM 8.1.1) uses 12 bits for the line count */
#define SHIFT_FW_IDLE_REG_RECEIVED_COMMANDS	(2)
#define MASK_FW_IDLE_REG_RECEIVED_COMMANDS	(0x3FC)
#define SHIFT_FW_IDLE_REG_STATUS			(0)
#define MASK_FW_IDLE_REG_STATUS				(3)

#define FW_IDLE_STATUS_LINE_COUNTER		(0)				/* New line counter information */
#define FW_IDLE_STATUS_IDLE				(1)
#define FW_IDLE_STATUS_HW_ACTIVE		(2)
#define FW_IDLE_STATUS_BUSY				(3)


#define FW_DEBUG_TRACKING		TOPAZHP_TOP_CR_FIRMWARE_REG_6  //!< Reg for fw debug

/* Flags relating to MTX_SCRATCHREG_FWTRACE */
#define SHIFT_FW_DEBUG_TRACKING_PIPE(x)		((x)*4)
#define MASK_FW_DEBUG_TRACKING_PIPE(x)		(0xf << SHIFT_FW_DEBUG_TRACKING_PIPE(x))
#define SHIFT_FW_DEBUG_TRACKING_PIPE0		(0)
#define MASK_FW_DEBUG_TRACKING_PIPE0		(0xf << MASK_FW_DEBUG_TRACKING_PIPE0)
#define SHIFT_FW_DEBUG_TRACKING_PIPE1		(4)
#define MASK_FW_DEBUG_TRACKING_PIPE1		(0xf << MASK_FW_DEBUG_TRACKING_PIPE1)
#define SHIFT_FW_DEBUG_TRACKING_CMD_CTXT	(16)
#define MASK_FW_DEBUG_TRACKING_CMD_CTXT		(0xf << SHIFT_FW_DEBUG_TRACKING_CMD_CTXT)
#define SHIFT_FW_DEBUG_TRACKING_CMD_ID		(24)
#define MASK_FW_DEBUG_TRACKING_CMD_ID		(0xff << SHIFT_FW_DEBUG_TRACKING_CMD_ID)


#define MTX_SCRATCHREG_FWTRACE		TOPAZHP_TOP_CR_FIRMWARE_REG_7  //!< Reg for fw debug trace

/*
 * In secure FW mode the first value written to the command FIFO is copied to MMU_CONTROL_0 by the firmware.
 * When we don't want that to happen we can write this value instead.  The firmware will know to ignore it as
 * long as it is written BEFORE the firmware starts up
 */
 #define TOPAZHP_NON_SECURE_FW_MARKER	(0xffffffff)

/*
 * This value is an arbitrary value that the firmware will write to TOPAZHP_TOP_CR_FIRMWARE_REG_1 (MTX_SCRATCHREG_BOOTSTATUS)
 * when it has completed the boot process to indicate that it is ready
 */
 #define TOPAZHP_FW_BOOT_SIGNAL		(0x12345678)

/*
 * Sizes for arrays that depend on reference usage pattern
 */
#define MAX_REF_B_LEVELS		3
#define MAX_REF_SPACING			1
#define MAX_REF_I_OR_P_LEVELS	(MAX_REF_SPACING + 2)
#define MAX_REF_LEVELS			(MAX_REF_B_LEVELS + MAX_REF_I_OR_P_LEVELS)
#define MAX_PIC_NODES			(MAX_REF_LEVELS + 2)
#define MAX_MV					(MAX_PIC_NODES * 2)

#define MAX_BFRAMES				7                    //B-frame count limit for Hierarchical mode
#define MAX_BFRAMES_FLAT_MODE   3                    //B-frame count limit for Flat mode
#define MAX_GOP_SIZE			(MAX_BFRAMES + 1)
#define MAX_SOURCE_SLOTS_SL		(MAX_GOP_SIZE + 1)

#define MV_ROW_STRIDE (ALIGN_64(sizeof(struct img_mv_settings) * MAX_BFRAMES))

/*
 * Enable the firmware to patch reference and reconstructed buffers
 */
#define FORCED_REFERENCE 1
#define LTREFHEADER 1

/*
 * MTX -> host message FIFO
 */
#define LOG2_WB_FIFO_SIZE	( 5 )

#define WB_FIFO_SIZE		( 1 << (LOG2_WB_FIFO_SIZE) )

#define SHIFT_WB_PRODUCER	( 0 )
#define MASK_WB_PRODUCER	( ((1 << LOG2_WB_FIFO_SIZE) - 1) << SHIFT_WB_PRODUCER )

#define SHIFT_WB_CONSUMER	( 0 )
#define MASK_WB_CONSUMER	( ((1 << LOG2_WB_FIFO_SIZE) - 1) << SHIFT_WB_CONSUMER )

/*
 * Number of buffers per encode task (default: 2 - double bufferring)
 */
#define CODED_BUFFERING_CNT 2 //default to double-buffering

/*
 * Calculates the ideal minimun coded buffers for a frame level encode
 */
#define CALC_OPTIMAL_CODED_PACKAGES_FRAME_ENCODE(numcores, isinterlaced) ((((isinterlaced) ? 2 : 1) * (numcores)) * CODED_BUFFERING_CNT)

/*
 * Calculates the ideal minimum coded buffers for a slice level encode
 */
#define CALC_OPTIMAL_CODED_PACKAGES_SLICE_ENCODE(slicesperpic) (slicesperpic * CODED_BUFFERING_CNT)

/*
 * Calculates the ideal minimum coded buffers for an encode
 */
#define CALC_OPTIMAL_CODED_PACKAGES_ENCODE(bisSliceLevel, slicesperpic, numcores, isinterlaced) \
	(bisSliceLevel ? CALC_OPTIMAL_CODED_PACKAGES_SLICE_ENCODE(slicesperpic) : CALC_OPTIMAL_CODED_PACKAGES_FRAME_ENCODE(numcores, isinterlaced))

/*
 * Calculates the actual number of coded buffers that can be used for an encode
 */
#define CALC_NUM_CODED_PACKAGES_ENCODE(bisSliceLevel, slicesperpic, numcores, isinterlaced) \
	(CALC_OPTIMAL_CODED_PACKAGES_ENCODE(bisSliceLevel, slicesperpic, numcores, isinterlaced))

/*
 * Maximum number of coded packages
 */
#define MAX_CODED_PACKAGES	CALC_NUM_CODED_PACKAGES_ENCODE(0,0, TOPAZHP_MAX_NUM_PIPES, 1)

/*
 * DMA configuration parameters
 */
#define MTX_DMA_BURSTSIZE_BYTES 32
#define MTX_DMA_ALIGNMENT_BYTES 64

/*
 * types that should be in DMAC header file
 */
enum dmac_acc_del {
	DMAC_ACC_DEL_0 = 0x0,			//!< Access delay zero clock cycles
	DMAC_ACC_DEL_256 = 0x1,			//!< Access delay 256 clock cycles
	DMAC_ACC_DEL_512 = 0x2,			//!< Access delay 512 clock cycles
	DMAC_ACC_DEL_768 = 0x3,			//!< Access delay 768 clock cycles
	DMAC_ACC_DEL_1024 = 0x4,		//!< Access delay 1024 clock cycles
	DMAC_ACC_DEL_1280 = 0x5,		//!< Access delay 1280 clock cycles
	DMAC_ACC_DEL_1536 = 0x6,		//!< Access delay 1536 clock cycles
	DMAC_ACC_DEL_1792 = 0x7,		//!< Access delay 1792 clock cycles
	DMAC_ACC_FORCE32BITS = 0x7FFFFFFFU
};

enum dmac_bswap {
	DMAC_BSWAP_NO_SWAP = 0x0,		//!< No byte swapping will be performed.
	DMAC_BSWAP_REVERSE = 0x1,		//!< Byte order will be reversed.
	DMAC_BSWAP_FORCE32BITS = 0x7FFFFFFFU
};

enum dmac_burst {
	DMAC_BURST_0 = 0x0,				//!< burst size of 0
	DMAC_BURST_1 = 0x1,				//!< burst size of 1
	DMAC_BURST_2 = 0x2,				//!< burst size of 2
	DMAC_BURST_3 = 0x3,				//!< burst size of 3
	DMAC_BURST_4 = 0x4,				//!< burst size of 4
	DMAC_BURST_5 = 0x5,				//!< burst size of 5
	DMAC_BURST_6 = 0x6,				//!< burst size of 6
	DMAC_BURST_7 = 0x7,				//!< burst size of 7
	DMAC_BURST_FORCE32BITS = 0x7FFFFFFFU
};

enum dmac_dir {
	DMAC_DIR_MEM_TO_PERIPH = 0x0,	//!< Data from memory to peripheral.
	DMAC_DIR_PERIPH_TO_MEM = 0x1,	//!< Data from peripheral to memory.
	DMAC_DIR_FORCE32BITS = 0x7FFFFFFFU
};

#define DMAC_VALUE_COUNT(BSWAP,PW,DIR,PERIPH_INCR,COUNT)			 \
    (((BSWAP)		<< SHIFT_IMG_SOC_BSWAP)	& MASK_IMG_SOC_BSWAP)	|\
	(((PW)			<< SHIFT_IMG_SOC_PW)	& MASK_IMG_SOC_PW)		|\
	(((DIR)			<< SHIFT_IMG_SOC_DIR)	& MASK_IMG_SOC_DIR)		|\
	(((PERIPH_INCR)	<< SHIFT_IMG_SOC_PI)	& MASK_IMG_SOC_PI)		|\
	(((COUNT)		<< SHIFT_IMG_SOC_CNT)	& MASK_IMG_SOC_CNT)
#define DMAC_VALUE_PERIPH_PARAM(ACC_DEL,INCR,BURST)					 \
	(((ACC_DEL)	<< SHIFT_IMG_SOC_ACC_DEL)	& MASK_IMG_SOC_ACC_DEL)	|\
	(((INCR)	<< SHIFT_IMG_SOC_INCR)		& MASK_IMG_SOC_INCR)	|\
	(((BURST)	<< SHIFT_IMG_SOC_BURST)		& MASK_IMG_SOC_BURST)

enum dmac_pw {
	DMAC_PWIDTH_32_BIT = 0x0,		//!< Peripheral width 32-bit.
	DMAC_PWIDTH_16_BIT = 0x1,		//!< Peripheral width 16-bit.
	DMAC_PWIDTH_8_BIT = 0x2,		//!< Peripheral width 8-bit.
	DMAC_PWIDTH_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Enum describing Command IDs.  Some commands require data to be DMA'd in
 * from the Host, with the base address of the data specified in the Command
 * Data Address word of the command.  The data required is specific to each
 * command type.
 */
enum mtx_cmd_id {
	// Common Commands
	MTX_CMDID_NULL,						//!< (no data)\n Null command does nothing\n
	MTX_CMDID_SHUTDOWN,					//!< (no data)\n shutdown the MTX\n

	// Video Commands
	MTX_CMDID_DO_HEADER,				//!< (extra data: #MTX_HEADER_PARAMS)\n Command for Sequence, Picture and Slice headers\n
	MTX_CMDID_ENCODE_FRAME,				//!< (data: low latency encode activation, HBI usage)\n Encode frame data\n
	MTX_CMDID_START_FRAME,				//!< (no data)\n Prepare to encode frame\n
	MTX_CMDID_ENCODE_SLICE,				//!< (no data)\n Encode slice data\n
	MTX_CMDID_END_FRAME,				//!< (no data)\n Complete frame encoding\n
	MTX_CMDID_SETVIDEO,					//!< (data: pipe number, extra data: #IMG_MTX_VIDEO_CONTEXT)\n Set MTX Video Context\n
	MTX_CMDID_GETVIDEO,					//!< (data: pipe number, extra data: #IMG_MTX_VIDEO_CONTEXT)\n Get MTX Video Context\n
	MTX_CMDID_DO_CHANGE_PIPEWORK,		//!< (data: new pipe allocations for the context)\n Change pipe allocation for a Video Context\n
#if SECURE_IO_PORTS
	MTX_CMDID_SECUREIO,					//!< (data: )\n Change IO security\n
#endif
	MTX_CMDID_PICMGMT,					//!< (data: subtype and parameters, extra data: #IMG_PICMGMT_CUSTOM_QUANT_DATA (optional))\n Change encoding parameters\n
	MTX_CMDID_RC_UPDATE,				//!< (data: QP and bitrate)\n Change encoding parameters\n
	MTX_CMDID_PROVIDE_SOURCE_BUFFER,	//!< (extra data: #IMG_SOURCE_BUFFER_PARAMS)\n Transfer source buffer from host\n
	MTX_CMDID_PROVIDE_REF_BUFFER,		//!< (data: buffer parameters, extra data: reference buffer)\n Transfer reference buffer from host\n
	MTX_CMDID_PROVIDE_CODEDPACKAGE_BUFFER,	//!< (data: slot and size, extra data: coded package)\n Transfer coded package from host (coded package contains addresses of header and coded output buffers/1st linked list node)\n
	MTX_CMDID_ABORT,					//!< (no data)\n Stop encoding and release all buffers\n

	// JPEG commands
	MTX_CMDID_SETQUANT,					//!< (extra data: #JPEG_MTX_QUANT_TABLE)\n
	MTX_CMDID_SETUP_INTERFACE,			//!< (extra data: #JPEG WRITEBACK POINTERS)\n
	MTX_CMDID_ISSUEBUFF,				//!< (extra data: #MTX_ISSUE_BUFFERS)\n
	MTX_CMDID_SETUP,					//!< (extra data: #JPEG_MTX_DMA_SETUP)\n\n

	MTX_CMDID_UPDATE_SOURCE_FORMAT,		//!< (extra data: #IMG_VXE_SCALER_SETUP)\nChange source pixel format after context creation\n
	MTX_CMDID_UPDATE_CSC,				//!< (extra data: #IMG_VXE_CSC_SETUP)\nChange Colour Space Conversion setup dynamically\n

	MTX_CMDID_ENDMARKER,					//!< end marker for enum
	MTX_CMDID_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Priority for the command.
 * Each Command ID will only work with the correct priority.
 */
#define MTX_CMDID_PRIORITY 0x80

/*
 * Indicates whether or not to issue an interrupt when the firmware sends the
 * command's writeback message.
 */
#define MTX_CMDID_WB_INTERRUPT 0x8000

/*
 * Enum describing response IDs
 */
enum mtx_message_id {
	MTX_MESSAGE_ACK,
	MTX_MESSAGE_CODED,
	MTX_MESSAGE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Mask and shift values for command word
 */
#define SHIFT_MTX_MSG_CMD_ID		(0)
#define MASK_MTX_MSG_CMD_ID			(0x7f << SHIFT_MTX_MSG_CMD_ID)
#define SHIFT_MTX_MSG_PRIORITY		(7)
#define MASK_MTX_MSG_PRIORITY		(0x1 << SHIFT_MTX_MSG_PRIORITY)
#define SHIFT_MTX_MSG_CORE			(8)
#define MASK_MTX_MSG_CORE			(0x7f << SHIFT_MTX_MSG_CORE)
#define SHIFT_MTX_MSG_WB_INTERRUPT	(15)
#define MASK_MTX_MSG_WB_INTERRUPT	(0x1 << SHIFT_MTX_MSG_WB_INTERRUPT)
#define SHIFT_MTX_MSG_COUNT			(16)
#define MASK_MTX_MSG_COUNT			(0xffffU << SHIFT_MTX_MSG_COUNT)
#define SHIFT_MTX_MSG_MESSAGE_ID	(16)
#define MASK_MTX_MSG_MESSAGE_ID		(0xff << SHIFT_MTX_MSG_MESSAGE_ID)

/*
 * Mask and shift values for data word
 */
#define SHIFT_MTX_MSG_ENCODE_CODED_INTERRUPT		(0)
#define MASK_MTX_MSG_ENCODE_CODED_INTERRUPT			(0xff << SHIFT_MTX_MSG_ENCODE_CODED_INTERRUPT)
#define SHIFT_MTX_MSG_ENCODE_USE_LINE_COUNTER		(20)
#define MASK_MTX_MSG_ENCODE_USE_LINE_COUNTER		(0x1 << SHIFT_MTX_MSG_ENCODE_USE_LINE_COUNTER)

#define SHIFT_MTX_MSG_PICMGMT_SUBTYPE				(0)
#define MASK_MTX_MSG_PICMGMT_SUBTYPE				(0xff << SHIFT_MTX_MSG_PICMGMT_SUBTYPE)
#define SHIFT_MTX_MSG_PICMGMT_DATA					(8)
#define MASK_MTX_MSG_PICMGMT_DATA					(0xffffffU << SHIFT_MTX_MSG_PICMGMT_DATA)
#define SHIFT_MTX_MSG_PICMGMT_STRIDE_Y				(0)
#define MASK_MTX_MSG_PICMGMT_STRIDE_Y				(0x3ff << SHIFT_MTX_MSG_PICMGMT_STRIDE_Y)
#define SHIFT_MTX_MSG_PICMGMT_STRIDE_UV				(10)
#define MASK_MTX_MSG_PICMGMT_STRIDE_UV				(0x3ff << SHIFT_MTX_MSG_PICMGMT_STRIDE_UV)

/*Values for updating bitrate when Rate Control is enabled*/
#define SHIFT_MTX_MSG_RC_UPDATE_QP					(0)
#define MASK_MTX_MSG_RC_UPDATE_QP					(0xff << SHIFT_MTX_MSG_RC_UPDATE_QP)
#define SHIFT_MTX_MSG_RC_UPDATE_BITRATE				(8)
#define MASK_MTX_MSG_RC_UPDATE_BITRATE				(0x00ffffff << SHIFT_MTX_MSG_RC_UPDATE_BITRATE)
#define UPDATE_BITRATE_MULTIPLIER					(3)

/* New message for updating min/max qp. using the same mesage as above*/
#define SHIFT_MTX_MSG_RC_UPDATE_MINQP				(8)
#define MASK_MTX_MSG_RC_UPDATE_MINQP				(0xff << SHIFT_MTX_MSG_RC_UPDATE_MINQP)
#define SHIFT_MTX_MSG_RC_UPDATE_MAXQP				(16)
#define MASK_MTX_MSG_RC_UPDATE_MAXQP				(0xff << SHIFT_MTX_MSG_RC_UPDATE_MAXQP)

/*Values for updating static Qp values when Rate Control is disabled*/
#define SHIFT_MTX_MSG_STATIC_UPDATE_QPI				(0)
#define MASK_MTX_MSG_STATIC_UPDATE_QPI				(0xff << SHIFT_MTX_MSG_STATIC_UPDATE_QPI)
#define SHIFT_MTX_MSG_STATIC_UPDATE_QPP				(8)
#define MASK_MTX_MSG_STATIC_UPDATE_QPP				(0xff << SHIFT_MTX_MSG_STATIC_UPDATE_QPP)
#define SHIFT_MTX_MSG_STATIC_UPDATE_QPB				(16)
#define MASK_MTX_MSG_STATIC_UPDATE_QPB				(0xff << SHIFT_MTX_MSG_STATIC_UPDATE_QPB)

#define SHIFT_MTX_MSG_PROVIDE_REF_BUFFER_USE		(0)
#define MASK_MTX_MSG_PROVIDE_REF_BUFFER_USE			(0xff << SHIFT_MTX_MSG_PROVIDE_REF_BUFFER_USE)
#define SHIFT_MTX_MSG_PROVIDE_REF_BUFFER_SLOT		(8)
#define MASK_MTX_MSG_PROVIDE_REF_BUFFER_SLOT		(0xff << SHIFT_MTX_MSG_PROVIDE_REF_BUFFER_SLOT)
#define SHIFT_MTX_MSG_PROVIDE_REF_BUFFER_LT			(16)
#define MASK_MTX_MSG_PROVIDE_REF_BUFFER_LT			(0xff << SHIFT_MTX_MSG_PROVIDE_REF_BUFFER_LT)

#define SHIFT_MTX_MSG_NUM_CODED_BUFFERS_PER_HEADER			(5)
#define MASK_MTX_MSG_NUM_CODED_BUFFERS_PER_HEADER			(0xf << SHIFT_MTX_MSG_NUM_CODED_BUFFERS_PER_HEADER)
#define SHIFT_MTX_MSG_PROVIDE_LIST_SEGMENT_SIZE				(10)
#define MASK_MTX_MSG_PROVIDE_LIST_SEGMENT_SIZE				(0x3fffff << SHIFT_MTX_MSG_PROVIDE_LIST_SEGMENT_SIZE)

#define SHIFT_MTX_MSG_PROVIDE_CODEDPACKAGE_BUFFER_SLOT	(0)
#define MASK_MTX_MSG_PROVIDE_CODEDPACKAGE_BUFFER_SLOT		(0x0f << SHIFT_MTX_MSG_PROVIDE_CODEDPACKAGE_BUFFER_SLOT)
#define SHIFT_MTX_MSG_PROVIDE_CODED_BUFFER_SIZE		(4)
#define MASK_MTX_MSG_PROVIDE_CODED_BUFFER_SIZE		(0x3fffff << SHIFT_MTX_MSG_PROVIDE_CODED_BUFFER_SIZE)

/*
 * Mask and shift values for Source format data word
 */
#define SHIFT_MTX_UPDATE_SOURCE_FORMAT_SC_ENABLE (0)
#define MASK_MTX_UPDATE_SOURCE_FORMAT_SC_ENABLE	(0x1 << SHIFT_MTX_UPDATE_SOURCE_FORMAT_SC_ENABLE)

#if SECURE_IO_PORTS
#define SHIFT_MTX_MSG_SECUREIO_OUTPUT				(0)
#define MASK_MTX_MSG_SECUREIO_OUTPUT				(0x1 << SHIFT_MTX_MSG_SECUREIO_OUTPUT)
#define SHIFT_MTX_MSG_SECUREIO_INPUT				(8)
#define MASK_MTX_MSG_SECUREIO_INPUT				(0x1 << SHIFT_MTX_MSG_SECUREIO_INPUT)
#endif

/*
 * Enum describing partially coded header element types
 */
enum header_element_type {
	ELEMENT_STARTCODE_RAWDATA = 0,					//!< Raw data that includes a start code
	ELEMENT_STARTCODE_MIDHDR,						//!< Raw data that includes a start code in the middle of the header
	ELEMENT_RAWDATA,								//!< Raw data
	ELEMENT_QP,										//!< Insert the H264 Picture Header QP parameter
	ELEMENT_SQP,									//!< Insert the H264 Slice Header QP parameter
	ELEMENT_FRAMEQSCALE,							//!< Insert the H263/MPEG4 Frame Q_scale parameter (vob_quant field)
	ELEMENT_SLICEQSCALE,							//!< Insert the H263/MPEG4 Slice Q_scale parameter (quant_scale field)
	ELEMENT_INSERTBYTEALIGN_H264,					//!< Insert the byte alignment bits for H264
	ELEMENT_INSERTBYTEALIGN_MPG4,					//!< Insert the byte alignment bits for MPEG4
	ELEMENT_INSERTBYTEALIGN_MPG2,					//!< Insert the byte alignment bits for MPEG2
	ELEMENT_VBV_MPG2,
	ELEMENT_TEMPORAL_REF_MPG2,
	ELEMENT_CURRMBNR,								//!< Insert the current macrloblock number for a slice.

	ELEMENT_FRAME_NUM,								//!< Insert frame_num field (used as ID for ref. pictures in H264)
	ELEMENT_TEMPORAL_REFERENCE,						//!< Insert Temporal Reference field (used as ID for ref. pictures in H263)
	ELEMENT_EXTENDED_TR,							//!< Insert Extended Temporal Reference field
	ELEMENT_IDR_PIC_ID,								//!< Insert idr_pic_id field (used to distinguish consecutive IDR frames)
	ELEMENT_PIC_ORDER_CNT,							//!< Insert pic_order_cnt_lsb field (used for display ordering in H264)
	ELEMENT_GOB_FRAME_ID,							//!< Insert gob_frame_id field (used for display ordering in H263)
	ELEMENT_VOP_TIME_INCREMENT,						//!< Insert vop_time_increment field (used for display ordering in MPEG4)

	ELEMENT_MODULO_TIME_BASE,						//!< Insert modulo_time_base used in MPEG4 (depends on vop_time_increment_resolution)

	ELEMENT_BOTTOM_FIELD,							//!< Insert bottom_field flag
	ELEMENT_SLICE_NUM,								//!< Insert slice num (used for GOB headers in H263)
	ELEMENT_MPEG2_SLICE_VERTICAL_POS,				//!< Insert slice vertical pos (MPEG2 slice header)
	ELEMENT_MPEG2_IS_INTRA_SLICE,					//!< Insert 1 bit flag indicating if slice is Intra or not (MPEG2 slice header)
	ELEMENT_MPEG2_PICTURE_STRUCTURE,				//!< Insert 2 bit field indicating if the current header is for a frame picture (11), top field (01) or bottom field (10) - (MPEG2 picture header)
	ELEMENT_REFERENCE,								//!< Insert flag indicating whether or not this picture is a reference
	ELEMENT_ADAPTIVE,								//!< Insert reference picture marking
	ELEMENT_DIRECT_SPATIAL_MV_FLAG,					//!< Insert spatial direct mode flag
	ELEMENT_NUM_REF_IDX_ACTIVE,						//!< Insert number of active references
	ELEMENT_REORDER_L0,								//!< Insert reference list 0 reordering
	ELEMENT_REORDER_L1,								//!< Insert reference list 1 reordering
	ELEMENT_TEMPORAL_ID,							//!< Insert temporal ID of the picture, used for MVC header
	ELEMENT_ANCHOR_PIC_FLAG,						//!< Insert flag indicating whether or not this picture is an anchor picture

	BPH_SEI_NAL_INITIAL_CPB_REMOVAL_DELAY,			//!< Insert nal_initial_cpb_removal_delay
	BPH_SEI_NAL_INITIAL_CPB_REMOVAL_DELAY_OFFSET,	//!< Insert nal_initial_cpb_removal_delay_offset
	PTH_SEI_NAL_CPB_REMOVAL_DELAY,					//!< Insert cpb_removal_delay
	PTH_SEI_NAL_DPB_OUTPUT_DELAY,					//!< Insert dpb_output_delay

	ELEMENT_SLICEWEIGHTEDPREDICTIONSTRUCT,			//!< Insert weighted prediciton parameters
	ELEMENT_CUSTOM_QUANT,							//!< Insert custom quantization values
	ELEMENT_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Struct describing a partially coded header element
 */
struct mtx_header_element {
	enum header_element_type element_type;	//!< Element type
	uint8			size;		//!< Number of bits of coded data to be inserted
	uint8			bits;		//!< Raw data to be inserted.
};

/*
 * Struct describing partially coded header parameters
 */
struct mtx_header_params {
	uint32			elements;				//!< Number of header elements
	struct mtx_header_element element_stream[MAX_HEADERSIZEWORDS - 1];	//!< array of element data
};

/*
 * Enum describing threshold values for skipped MB biasing
 */
enum th_skip_scale {
	TH_SKIP_0 = 0,		//!< Bias threshold for QP 0 to 12
	TH_SKIP_12 = 1,		//!< Bias threshold for QP 12 to 24
	TH_SKIP_24 = 2,		//!< Bias threshold for QP 24 and above
	TH_SKIP_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Struct describing rate control input parameters
 */
struct in_rc_params {
	uint32	mb_per_frm;		//!< Number of MBs Per Frame
	uint32	mb_per_bu;		//!< Number of MBs Per BU
	uint16	bu_per_frm;		//!< Number of BUs Per Frame

	uint16	intra_period;	//!< Intra frame frequency
	uint16	bframes;		//!< B frame frequency

	int32	bits_per_frm;		//!< Bits Per Frame
	int32	bits_per_bu;		//!< Bits Per BU

	int32	bit_rate;			//!< Bit Rate (bps)
	int32	buffer_size;		//!< Size of Buffer in bits
	int32	buffer_size_frames;//!< Size of Buffer in frames, to be used in VCM
	int32	initial_level;	//!< Initial Level of Buffer
	int32	initial_delay;	//!< Initial Delay of Buffer

	uint16	frm_skip_disable;	//!< Disable Frame skipping

	uint8	se_init_qp_i;		//!< Initial QP for sequence (I frames)
	uint8	se_init_qp_p;		//!< Initial QP for sequence (P frames)
	uint8	se_init_qp_b;		//!< Initial QP for sequence (B frames)

	uint8	min_qp;		//!< Minimum QP value to use
	uint8	max_qp;		//!< Maximum QP value to use

	uint8	scale_factor;		//!< Scale Factor used to limit the range of arithmetic with high resolutions and bitrates
	uint16	mb_per_row;		//!< Number of MBs Per Row

	uint16	disable_vcm_hardware; //!< Disable using vcm hardware in RC modes.

	union
	{
		struct
		{
			int32	transfer_rate;	//!< Rate at which bits are sent from encoder to the output after each frame finished encoding
			uint16	sc_detect_disable;	//!< Disable Scene Change detection
			uint16	hierarchical_mode;	//!< Flag indicating Hierarchical B Pic or Flat mode rate control
			uint32	rc_scale_factor;	//!< Constant used in rate control = (GopSize/(BufferSize-InitialLevel))*256
			uint16	enable_slice_bob;	//!< Enable movement of slice boundary when Qp is high
			uint8  max_slice_bob;     //!< Maximum number of rows the slice boundary can be moved
			uint8  slice_bob_qp;		//!< Minimum Qp at which slice bobbing should take place
		} h264;
		struct
		{
			uint8	half_framerate;	//!< Half Frame Rate (MP4 only)
			uint8	f_code;			//!< F Code (MP4 only)
			int32	bits_pergop;		//!< Bits Per GOP (MP4 only)
			uint16	bu_skip_disable;		//!< Disable BU skipping
			int32	bits_per_mb;		//!< Bits Per MB
			uint16	avg_qp_val;		//!< Average QP in Current Picture
			uint16	initial_qp;		//!< Initial Quantizer
		} other;
	} mode;
};

/*
 * Enum describing MTX firmware version (codec and rate control)
 */
enum img_codec {
	IMG_CODEC_NONE = 0,			//!< There is no FW in MTX memory
	IMG_CODEC_JPEG,				//!< JPEG
	IMG_CODEC_H264_NO_RC,		//!< H264 with no rate control
	IMG_CODEC_H264_VBR,			//!< H264 variable bitrate
	IMG_CODEC_H264_CBR,			//!< H264 constant bitrate
	IMG_CODEC_H264_VCM,			//!< H264 video conferance mode
	IMG_CODEC_H263_NO_RC,		//!< H263 with no rate control
	IMG_CODEC_H263_VBR,			//!< H263 variable bitrate
	IMG_CODEC_H263_CBR,			//!< H263 constant bitrate
	IMG_CODEC_MPEG4_NO_RC,		//!< MPEG4 with no rate control
	IMG_CODEC_MPEG4_VBR,		//!< MPEG4 variable bitrate
	IMG_CODEC_MPEG4_CBR,		//!< MPEG4 constant bitrate
	IMG_CODEC_MPEG2_NO_RC,		//!< MPEG2 with no rate control
	IMG_CODEC_MPEG2_VBR,		//!< MPEG2 variable bitrate
	IMG_CODEC_MPEG2_CBR,		//!< MPEG2 constant bitrate
	IMG_CODEC_H264_ERC,			//!< H264 example rate control
	IMG_CODEC_H263_ERC,			//!< H263 example rate control
	IMG_CODEC_MPEG4_ERC,		//!< MPEG4 example rate control
	IMG_CODEC_MPEG2_ERC,		//!< MPEG2 example rate control
	IMG_CODEC_H264MVC_NO_RC,	//!< MVC H264 with no rate control
	IMG_CODEC_H264MVC_CBR,		//!< MVC H264 constant bitrate
	IMG_CODEC_H264MVC_VBR,		//!< MVC H264 variable bitrate
	IMG_CODEC_H264MVC_ERC,		//!< MVC H264 example rate control
	IMG_CODEC_H264_ALL_RC,		//!< H264 with multiple rate control modes
	IMG_CODEC_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Enum describing encoding standard (codec)
 */
enum img_standard {
	IMG_STANDARD_NONE = 0,	//!< There is no FW in MTX memory
	IMG_STANDARD_JPEG,		//!< JPEG
	IMG_STANDARD_H264,		//!< H264 with no rate control
	IMG_STANDARD_H263,		//!< H263 with no rate control
	IMG_STANDARD_MPEG4,		//!< MPEG4 with no rate control
	IMG_STANDARD_MPEG2,		//!< MPEG2 with no rate control
	IMG_STANDARD_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Enum describing image surface format types
 */
enum img_format {
	IMG_CODEC_420_YUV=100,			//!< Planar Y U V
	IMG_CODEC_420_YV12=44,			//!< YV12 format Data
	IMG_CODEC_420_IMC2=36,			//!< IMC2 format Data
	IMG_CODEC_420_PL8=47,			//!< PL8 format YUV data
	IMG_CODEC_420_PL12=101,			//!< PL12 format YUV data
	IMG_CODEC_420_PL12_PACKED=25,   //|< PL12 format packed into a single plane (not currently supported by JPEG)
	IMG_CODEC_420_PL21_PACKED=26,   //!< PL21 format packed into a single plane (not currently supported by JPEG)
	IMG_CODEC_422_YUV=102,		//!< YUV format 4:2:2 data  // start the incrementing auto enumeration values after the last ones we have used.
	IMG_CODEC_422_YV12,			//!< YV12 format 4:2:2 data
	IMG_CODEC_422_PL8,			//!< PL8 format 4:2:2 data
	IMG_CODEC_422_IMC2,			//!< IMC2 format 4:2:2 data
	IMG_CODEC_422_PL12,			//!< PL12 format 4:2:2 data
	IMG_CODEC_Y0UY1V_8888,		//!< 4:2:2 YUYV data
	IMG_CODEC_Y0VY1U_8888,		//!< 4:2:2 YVYU data
	IMG_CODEC_UY0VY1_8888,		//!< 4:2:2 UYVY data
	IMG_CODEC_VY0UY1_8888,		//!< 4:2:2 VYUY data
	IMG_CODEC_444_YUV,		//!< YUV format 4:4:4 data (not currently supported by JPEG)
	IMG_CODEC_444_YV12,		//!< YV12 format 4:4:4 data (not currently supported by JPEG)
	IMG_CODEC_444_PL8,		//!< PL8 format 4:4:4 data (not currently supported by JPEG)
	IMG_CODEC_444_IMC2,		//!< PL8 format 4:4:4 data (not currently supported by JPEG)
	IMG_CODEC_444_PL12,		//!< PL12 format 4:4:4 data (not currently supported by JPEG)
	IMG_CODEC_ABCX,			//!< Interleaved 4:4:4 data (not currently supported by JPEG)
	IMG_CODEC_XBCA,			//!< Interleaved 4:4:4 data (not currently supported by JPEG)
	IMG_CODEC_ABC565,		//!< Packed 4:4:4 data (not currently supported by JPEG)

	IMG_CODEC_420_PL21,				//!< PL21 format YUV data
	IMG_CODEC_422_PL21,			//!< 4:2:2 PL21 format YUV data
	IMG_CODEC_444_PL21,				//!< 4:4:4 PL21 format YUV data (not currently supported by JPEG)

	PVR_SURF_UNSPECIFIED,		//!< End of the enum
	IMG_CODEC_FORMAT_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Enum describing presets for source image colour space conversion
 */
enum img_csc_preset {
	IMG_CSC_NONE,			//!< No colour space conversion
	IMG_CSC_709_TO_601,		//!< ITU BT.709 YUV to be converted to ITU BT.601 YUV
	IMG_CSC_601_TO_709,		//!< ITU BT.601 YUV to be converted to ITU BT.709 YUV
	IMG_CSC_RGB_TO_601_ANALOG,	//!< RGB to be converted to ITU BT.601 YUV
	IMG_CSC_RGB_TO_601_DIGITAL,	//!< RGB to be converted to ITU BT.601 YCbCr for SDTV (reduced scale - 16-235)
	IMG_CSC_RGB_TO_601_DIGITAL_FS,	//!< RGB to be converted to ITU BT.601 YCbCr for HDTV (full range - 0-255)
	IMG_CSC_RGB_TO_709,		//!< RGB to be converted to ITU BT.709 YUV
	IMG_CSC_YIQ_TO_601,		//!< YIQ to be converted to ITU BT.601 YUV
	IMG_CSC_YIQ_TO_709,		//!< YIQ to be converted to ITU BT.709 YUV
	IMG_CSC_BRG_TO_601,		//!< BRG to be converted to ITU BT.601 YUV (for XRGB format)
	IMG_CSC_RBG_TO_601,		//!< RBG to be converted to ITU BT.601 YUV (for XBGR format)
	IMG_CSC_BGR_TO_601,     //!< BGR to be converted to ITU BT.601 YUV (for BGRX format)
	IMG_CSC_UYV_TO_YUV,     //!< UYV to be converted to YUV (BT.601 or BT.709)
	IMG_CSC_PRESETS,			//!< End of the enum
	IMG_CSC_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * GOP structure information
 */
#define SHIFT_GOP_FRAMETYPE		(0)
#define MASK_GOP_FRAMETYPE		(0x3 << SHIFT_GOP_FRAMETYPE)
#define SHIFT_GOP_REFERENCE		(2)
#define MASK_GOP_REFERENCE		(0x1 << SHIFT_GOP_REFERENCE)
#define SHIFT_GOP_POS			(3)
#define MASK_GOP_POS			(0x1f << SHIFT_GOP_POS)
#define SHIFT_GOP_LEVEL			(4)
#define MASK_GOP_LEVEL			(0xF << SHIFT_GOP_LEVEL)
#define SHIFT_GOP_REF0			(0 + 8)
#define MASK_GOP_REF0			(0xf << SHIFT_GOP_REF0)
#define SHIFT_GOP_REF1			(4 + 8)
#define MASK_GOP_REF1			(0xf << SHIFT_GOP_REF1)

/*
 * Frame types
 */
enum img_frame_type {
	IMG_INTRA_IDR = 0,
	IMG_INTRA_FRAME,
	IMG_INTER_P,
	IMG_INTER_B,
	IMG_INTER_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Motion vector calculation register settings
 */
struct img_mv_settings {
	uint32	mv_calc_below;
	uint32	mv_calc_colocated;
	uint32	mv_calc_config;
};

/*
 * Frame template types
 */
enum img_frame_template_type {
	IMG_FRAME_IDR = 0,
	IMG_FRAME_INTRA,
	IMG_FRAME_INTER_P,
	IMG_FRAME_INTER_B,
	IMG_FRAME_INTER_P_IDR,
	IMG_FRAME_UNDEFINED,
	IMG_FRAME_TYPE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Rate control modes
 */
enum img_rcmode {
	IMG_RCMODE_NONE = 0,
	IMG_RCMODE_CBR,
	IMG_RCMODE_VBR,
	IMG_RCMODE_ERC,			// Example Rate Control
	IMG_RCMODE_VCM,
	IMG_RCMODE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Video Conferencing Mode (VCM) rate control method's sub modes
 */
enum img_rc_vcm_mode {
	IMG_RC_VCM_MODE_DEFAULT = 0,
	IMG_RC_VCM_MODE_CFS_NONIFRAMES,
	IMG_RC_VCM_MODE_CFS_ALLFRAMES,
	IMG_RC_VCM_MODE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Weighted prediction values
 */
struct weighted_prediction_values {
	uint8			frameType;
	osa_bool		weighted_pred_flag;			// Corresponds to field in the pps
	uint8			weighted_bipred_idc;
	uint32			luma_log2_weight_denom;
	uint32			chroma_log2_weight_denom;
	osa_bool		weight_flag[3][2];			// Y, Cb, Cr Support for 2 ref pictures on P, or 1 pic in each direction on B.
	int32			weight[3][2];
	int32			offset[3][2];
};

enum weighted_bipred_idc {
	WBI_NONE = 0x0,
	WBI_EXPLICIT,
	WBI_IMPLICIT,
	WBI_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Registers required to configure input scaler
 */
struct img_vxe_scaler_setup {
	uint32		input_scaler_control;
	uint32		scaler_input_size_reg;
	uint32		scaler_crop_reg;
	uint32		scaler_pitch_reg;
	uint32		scaler_control;
	uint32		hor_scaler_coeff_regs[4];
	uint32		ver_scaler_coeff_regs[4];
};

/*
 * Registers required to configure input Colour Space conversion
 */
struct img_vxe_csc_setup {
	uint32		csc_source_y[3];
	uint32		csc_output_clip[2];
	uint32		csc_source_cbcr[3];
};

/*
 * SETVIDEO & GETVIDEO - Video encode context
 */
struct img_mtx_video_context {
	uint64		clock_div_bitrate; // keep this at the top as it has alignment issues

	uint32		width_in_mbs;							//!< target output width
	uint32		picture_height_in_mbs;					//!< target output height

	uint32		tmp_reconstructed[MAX_PIC_NODES];
	uint32		reconstructed[MAX_PIC_NODES];
	uint32		colocated[MAX_PIC_NODES];
	uint32		mv[MAX_MV];
	uint32		inter_view_mv[2];

	uint32		debug_crcs;							//!< Send debug information from Register CRCs to Host with the coded buffer

	uint32		writeback_regions[WB_FIFO_SIZE];		//!< Data section

	uint32		initial_cpb_removal_delayoffset;
	uint32		max_buffer_mult_clock_div_bitrate;
	uint32		sei_buffering_period_template;
	uint32		sei_picture_timing_template;

	uint16		enable_mvc;
	uint16		mvc_view_idx;
	uint32		slice_params_templates[5];
	uint32		pichdr_templates[4];

	uint32		seq_header;
	uint32		subset_seq_header;
	uint16		no_sequence_headers;

	uint32		slice_map[MAX_SOURCE_SLOTS_SL];		//!< Slice map of the source picture

	uint32		flat_gop_struct;						//!< Address of Flat MiniGop structure

	osa_bool	weighted_prediction_enabled;
	uint8		mtx_weighted_implicit_bi_pred;
	uint32		weighted_prediction_virt_addr[MAX_SOURCE_SLOTS_SL];

	uint32		hierar_gop_struct;					//!< Address of hierarchical MiniGop structure

	uint32		firstpass_out_param_addr[MAX_SOURCE_SLOTS_SL];				//!< Output Parameters of the First Pass

	uint32		firstpass_out_best_multipass_param_addr[MAX_SOURCE_SLOTS_SL];	//!< Selectable Output Best MV Parameters data of the First Pass

	uint32		mb_ctrl_in_params_addr[MAX_SOURCE_SLOTS_SL];					//!< Input Parameters to the second pass

	uint32		pic_row_stride_bytes;						//!< Strides of source Y data and chroma data

	uint32		above_params[TOPAZHP_MAX_NUM_PIPES];		//!< Picture level parameters (supplied by driver)


	uint32		idr_period;
	uint32		intra_loop_cnt;
	uint32		bframe_count;
	osa_bool	hierarchical;
	uint8		mpeg2_intra_dc_precision;				//!< Only used in MPEG2, 2 bit field (0 = 8 bit, 1 = 9 bit, 2 = 10 bit and 3=11 bit precision). Set to zero for other encode standards.
	uint8		pic_on_level[MAX_REF_LEVELS];

	uint32		vop_time_resolution;

	uint16		kick_size;							//!< Number of Macroblocks per kick
	uint16		kicks_per_bu;							//!< Number of kicks per BU
	uint16		kicks_per_picture;					//!< Number of kicks per picture

	struct img_mv_settings mv_settings_idr;

	struct img_mv_settings mv_settings_non_b[MAX_BFRAMES + 1];

	uint32		mv_settings_b_table;
	uint32		mv_settings_hierarchical;

	enum img_format format;								//!< Pixel format of the source surface
	enum img_standard standard;								//!< Encoder standard (H264 / H263 / MPEG4 / JPEG)
	enum img_rcmode rc_mode;								//!< RC flavour
	enum img_rc_vcm_mode rc_vcm_mode;								//!< RC VCM flavour
	uint32		rc_cfs_max_margin_perc;					//!< RC VCM maximum frame size percentage allowed to exceed in CFS

	osa_bool		first_pic;
	osa_bool		is_interlaced;
	osa_bool		top_field_first;
	osa_bool		arbitrary_so;
	osa_bool		output_reconstructed;

	osa_bool		disable_bit_stuffing;

	osa_bool		insert_hrd_params;

	uint8		max_slices_per_picture;

	uint32		f_code;

	/* Contents Adaptive Rate Control parameters*/
	uint32		jmcomp_rc_reg0;
	uint32		jmcomp_rc_reg1;

	uint32		mv_clip_config;						//!< Value to use for MVClip_Config  register
	uint32		pred_comb_control;					//!< Value to use for Predictor combiner register
	uint32		lritc_cache_chunk_config;			//!< Value to use for LRITC_Cache_Chunk_Config register
	uint32		ipe_vector_clipping;					//!< Value to use for IPEVectorClipping register
	uint32		h264_comp_control;					//!< Value to use for H264CompControl register
	uint32		h264_comp_intra_pred_modes;				//!< Value to use for H264CompIntraPredMode register
	uint32		ipcm_0_config;						//!< Value to use for IPCM_0 Config register
	uint32		ipcm_1_config;						//!< Value to use for IPCM_1 Config register
	uint32		spe_mvd_clip_range;					//!< Value to use for SPEMvdClipRange register
	uint32		mb_host_ctrl;							//!< Value to use for MB_HOST_CONTROL register
	uint32		deblock_ctrl;						//!< Value for the CR_DB_DISABLE_DEBLOCK_IDC register
	uint32		skip_coded_inter_intra;				//!< Value for the CR_DB_DISABLE_DEBLOCK_IDC register

	uint32		vlc_control;
	uint32		vlc_slice_control;					//!< Slice control register value. Configures the size of a slice
	uint32		vlc_slice_mb_control;					//!< Slice control register value. Configures the size of a slice
	uint16		cqp_offset;							//!< Chroma QP offset to use (when PPS id = 0)

	osa_bool	coded_header_per_slice;

	uint8		initial_qp_i;							//!< Initial QP I frames
	uint8		initial_qp_p;							//!< Initial QP P frames
	uint8		initial_qp_b;							//!< Initial QP B frames

	uint32		first_pic_flags;
	uint32		non_first_pic_flags;

	osa_bool	mc_adaptive_rounding_disable;

#define AR_REG_SIZE	18
#define AR_DELTA_SIZE 7
	uint16		mc_adaptive_rounding_offsets[AR_REG_SIZE][4];
	int16		mc_adaptive_rounding_offsets_delta[AR_DELTA_SIZE][4];

	uint32		patched_recon_address;				//!< Reconstructed address to allow host picture management
	uint32		patched_ref0_address;					//!< Reference 0 address to allow host picture management
	uint32		patched_ref1_address;					//!< Reference 1 address to allow host picture management

	uint32		ltref_header[MAX_SOURCE_SLOTS_SL];
	int8		slice_header_slot_num;
	osa_bool	recon_is_longterm;
	osa_bool	ref0_is_longterm;
	osa_bool	ref1_is_longterm;
	uint8		ref_spacing;

	uint8		fw_num_pipes;
	uint8		fw_first_pipe;
	uint8		fw_last_pipe;
	uint8		fw_pipes_to_use_flags;

#if SECURE_IO_PORTS
	uint32	secure_io_control;
#endif
	struct img_vxe_scaler_setup scaler_setup;
	struct img_vxe_csc_setup csc_setup;

	struct in_rc_params in_params;
};

/*
 * PICMGMT - Command sub-type
 */
enum img_picmgmt_type {
	IMG_PICMGMT_REF_TYPE = 0,
	IMG_PICMGMT_GOP_STRUCT,
	IMG_PICMGMT_SKIP_FRAME,
	IMG_PICMGMT_EOS,
	IMG_PICMGMT_FLUSH,
	IMG_PICMGMT_QUANT,
	IMG_PICMGMT_STRIDE,
	IMG_PICMGMT_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * PROVIDE_REF_BUFFER - Purpose of the reference buffer
 */
enum img_ref_buffer_type {
	IMG_BUFFER_REF0 = 0,
	IMG_BUFFER_REF1,
	IMG_BUFFER_RECON,
	IMG_BUFFER_RECON_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * RC_UPDATE - IMG_V_RCUpdate parameters
 */
struct img_picmgmt_rc_update_data {
	uint32		bits_per_frame;		//!< Number of bits in a frame
	uint8		vcm_i_frame_qp;			//!< VCM I frame QP
	uint8		min_qp;				//!< Min QP
	uint8		max_qp;				//!< Max QP
};

/*
 * PIC_MGMT - IMG_V_SetCustomScalingValues parameters
 */
struct img_picmgmt_custom_quant_data {
	uint32	values;			//!< Address of custom quantization values
	uint32	regs_4x4_sp;		//!< Address of custom quantization register values for 4x4 Sp
	uint32	regs_8x8_sp;		//!< Address of custom quantization register values for 8x8 Sp
	uint32	regs_4x4_q;		//!< Address of custom quantization register values for 4x4 Q
	uint32	regs_8x8_q;		//!< Address of custom quantization register values for 8x8 Q
};

/*
 * MTX- > host message structure
 */
struct img_writeback_msg {
	uint32 cmd_word;
	union
	{
		struct
		{
			uint32	data;
			uint32	extra_data;
			uint32	writeback_val;
		};
		uint32	coded_package_consumed_idx;
	};
};

/*
 * PROVIDE_SOURCE_BUFFER - Details of the source picture buffer
 */
struct img_source_buffer_params {
	uint64	host_context;			//!< Host context value. Keep at start for alignment.
	uint32	phys_addr_y_plane_field_0;	//!< Source pic phys addr (Y plane, Field 0)
	uint32	phys_addr_u_plane_field_0;	//!< Source pic phys addr (U plane, Field 0)
	uint32	phys_addr_v_plane_field_0;	//!< Source pic phys addr (V plane, Field 0)
	uint32	phys_addr_y_plane_field_1;	//!< Source pic phys addr (Y plane, Field 1)
	uint32	phys_addr_u_plane_field_1;	//!< Source pic phys addr (U plane, Field 1)
	uint32	phys_addr_v_plane_field_1;	//!< Source pic phys addr (V plane, Field 1)
	uint8	display_order_num;			//!< Number of frames in the stream (incl. skipped)
	uint8	slot_num;					//!< Source slot number
	uint8   reserved1;
	uint8   reserved2;
};

/*
 * Struct describing input parameters to encode a video slice
 */
struct slice_params {
	uint32	flags;					//!< Flags for slice encode

	// Config registers. These are passed straight through from drivers to hardware.
	uint32	slice_config;			//!< Value to use for Slice Config register
	uint32	ipe_control;				//!< Value to use for IPEControl register
	uint32	seq_config;				//!< Value to use for Sequencer Config register

	enum img_frame_template_type template_type;	//!< Slice header template type
	struct mtx_header_params slice_hdr_tmpl;		//!< Template of corresponding slice header
};

/*
 * Struct describing Minimum Coded Unit information for a single JPEG component plane.
 * Details the size of blocks to be taken from the plane and the maximum block positions.
 * Send to firmware in the MTX_CMDID_SETUP command as part of the JPEG_MTX_DMA_SETUP structure
 */
struct mcu_component {
	uint32	width_blocks;	//!< Width in pixels, shall be a multiple of 8
	uint32	height_blocks;	//!< Height in pixels, shall be a multiple of 8
	uint32	x_limit;			//!< Blocks will not be encoded beyond this
	uint32	y_limit;			//!< Blocks will not be encoded beyond this
};

/*
 * Struct describing essential information about a single JPEG component plane, defines the
 * Physical address of the colour plane, its stride and its height.
 * Send to firmware in the MTX_CMDID_SETUP command as part of the JPEG_MTX_DMA_SETUP structure.
 */
struct component_plane {
	uint32	phys_addr;	//!< Physical address Component plane in shared memory
	uint32	stride;		//!< Stride of source plane */
	uint32	height;		//!< Height of avaliable data in plane.  shall be a minumum of one MCU high
};

/*
 * Struct sent with the MTX_CMDID_ISSUEBUFF command detailing
 * where a scan encode should begin (calculated from the total count of MCUs)
 * and how many MCU's should be processed in this scan.
 */
struct mtx_issue_buffers {
	uint32	mcu_position_of_scan_and_index;	//!< Scan start position in MCUs
	uint32	mcu_cnt_and_reset_flag;			//!< [32:2] Number of MCU's to encode or decode, [1] Reset predictors (1=Reset, 0=No Reset)
};

/*
 * Struct describing JPEG encode output header
 */
struct buffer_header {
	uint32	bytes_used;		//!<
	uint32	bytes_encoded;		//!<
	uint32	bytes_to_encode;	//!<
	uint32	reserved3;		//!<
};

/*
 * Structure describing coded header data returned by the firmware.
 *             The size of the structure should not be more than 64 bytes (needs to have 64 byte alignment)
 *              (i.e. CODED_BUFFER_HEADER_SIZE)
 */
struct coded_data_hdr {
	uint64	host_ctx;		//!< Host context value. Keep at top for alignment.
	uint32	bytes_written;	//!< Bytes in this coded buffer excluding this header
	uint32	feedback;		//!< Feedback word for this coded buffers
	uint32	extra_feedback;	//!< Extra feedback word for this coded buffers

	uint16	i_mb_cnt;		//!< Number of MBs coded as I-macroblocks in this slice
	uint16	p_mb_cnt;		//!< Number of MBs coded as P-macroblocks in this slice

	uint16	b_mb_cnt;		//!< Number of MBs coded as B-macroblocks in this slice
	uint16	skip_mb_cnt;	//!< Number of MBs coded as skipped in this slice

	uint16	ipcm_mb_cnt;	//!< Number of macroblocks coded as IPCM in this slice
	uint8	inter_sum_satd_hi;	//!< High 8 bits for the inter sum satd
	uint8	intra_sum_satd_hi;	//!< High 8 bits for the intra sum satd

	uint32	dc_bits;		//!< Number of bits use for coding DC coefficients in this slice
	uint32	mv_bits;		//!< Number of bits used for coding all Motion vector data in this slice
	uint32	symbols_bits;	//!< Number of bits used for coding all MB level symbols in this slice
	uint32	residual_bits;	//!< Number of bits used for coding residual data in all MBs in this slice

	uint32	qpy_inter;		//!< Sum of QPy/Qscale for all Inter-MBs in the slice
	uint32	qpy_intra;		//!< Sum of QPy/Qscale for all Intra-MBs in the slice
	uint32	inter_sum_satd;	//!< Sum of SATD for all Inter-MBs in the slice
	uint32	intra_sum_satd;	//!< Sum of SATD for all Intra-MBs in the slice
};

#define MAX_CODED_BUFFERS_PER_PACKAGE_FW 1
#define MAX_CODED_BUFFERS_PER_PACKAGE 1

// This structure is temporarily used during the 64 byte minimum DMA transfer from driver to FW
struct coded_package_dma_info {
	uint32 coded_mem_addr[MAX_CODED_BUFFERS_PER_PACKAGE_FW];
	//////////////////
	// 2 Info words //
	//////////////////
	uint32 coded_header_addr;
	uint32 coded_buffer_info; // Combined field Host->MTX = IsLinkedList, list segment (CB memory) size, number of list segments per coded buffer

	// PAD TO 64 BYTES
	uint32 padding[16 - MAX_CODED_BUFFERS_PER_PACKAGE_FW - 2];
};

#define SHIFT_JPEG_ISSUEBUFF_MPSP_SCANSTARTPOS		(2)
#define MASK_JPEG_ISSUEBUFF_MPSP_SCANSTARTPOS		(0xFFFFFFFC)
#define SHIFT_JPEG_ISSUEBUFF_MPSP_PIPENO				(0)
#define MASK_JPEG_ISSUEBUFF_MPSP_PIPENO				(0x3)

/*
 * Contents of the coded data buffer header feedback word
 */
#define SHIFT_CODED_FIRST_BU			(24)
#define MASK_CODED_FIRST_BU				(0xFFU << SHIFT_CODED_FIRST_BU)
#define SHIFT_CODED_SLICE_NUM			(16)
#define MASK_CODED_SLICE_NUM			(0xFF << SHIFT_CODED_SLICE_NUM)
#define SHIFT_CODED_STORAGE_FRAME_NUM	(14)
#define MASK_CODED_STORAGE_FRAME_NUM	(0x03 << SHIFT_CODED_STORAGE_FRAME_NUM)
#define SHIFT_CODED_LL_DISCARDED_FRAME	(13)
#define MASK_CODED_LL_DISCARDED_FRAME	(0x01 << SHIFT_CODED_LL_DISCARDED_FRAME)
#define SHIFT_CODED_ENTIRE_FRAME		(12)
#define MASK_CODED_ENTIRE_FRAME			(0x01 << SHIFT_CODED_ENTIRE_FRAME)
#define SHIFT_CODED_IS_SKIPPED			(11)
#define MASK_CODED_IS_SKIPPED			(0x01 << SHIFT_CODED_IS_SKIPPED)
#define SHIFT_CODED_IS_CODED			(10)
#define MASK_CODED_IS_CODED				(0x01 << SHIFT_CODED_IS_CODED)
#define SHIFT_CODED_RECON_IDX			(6)
#define MASK_CODED_RECON_IDX			(0x0F << SHIFT_CODED_RECON_IDX)
#define SHIFT_CODED_SOURCE_SLOT			(2)
#define MASK_CODED_SOURCE_SLOT			(0x0F << SHIFT_CODED_SOURCE_SLOT)
#define SHIFT_CODED_FRAME_TYPE			(0)
#define MASK_CODED_FRAME_TYPE			(0x03 << SHIFT_CODED_FRAME_TYPE)

/*
 * Contents of the coded data buffer header extra feedback word
 */
#define SHIFT_CODED_SLICES_SO_FAR					(24)
#define MASK_CODED_SLICES_SO_FAR					(0xFFU << SHIFT_CODED_SLICES_SO_FAR)

#define SHIFT_CODED_SLICES_IN_BUFFER				(16)
#define MASK_CODED_SLICES_IN_BUFFER					(0xFF << SHIFT_CODED_SLICES_IN_BUFFER)

#define SHIFT_CODED_BUFFER_PIPE						(14)
#define MASK_CODED_BUFFER_PIPE						(0x03 << SHIFT_CODED_BUFFER_PIPE)

#define SHIFT_CODED_BUFFER_NUMBER_USED				(2)
#define MASK_CODED_BUFFER_NUMBER_USED				(0xFF << SHIFT_CODED_BUFFER_NUMBER_USED)

#define SHIFT_CODED_FIELD							(1)
#define MASK_CODED_FIELD							(0x01 << SHIFT_CODED_FIELD)

#define SHIFT_CODED_PATCHED_RECON					(0)
#define MASK_CODED_PATCHED_RECON					(0x01 << SHIFT_CODED_PATCHED_RECON)

#define SHIFT_INTER_INTRA_SCALE_TAB_INDEX     (4) //Starting Bit for indicating the index of intra/intra scale table to be used
#define SHIFT_SKIPPED_CODED_SCALE_TAB_INDEX   (7) //Starting Bit for indicating the index of skipped/coded scale table to be used
#define SHIFT_INPUT_QP                        (10)//Starting Bit for requested QP for the particular macroblock

#define BIAS_CONFIG_INTRA_FOUR_INTER_ZERO     (0) // Force intra by scaling its cost by 0
#define BIAS_CONFIG_INTRA_THREE_INTER_ONE     (1) // favour intra by a factor 3
#define BIAS_CONFIG_INTRA_TWO_INTER_ONE       (2) // favour intra by a factor 2
#define BIAS_CONFIG_INTRA_ONE_INTER_ONE       (3) // no bias
#define BIAS_CONFIG_INTRA_ONE_INTER_ONE_DUP   (4) // no bias
#define BIAS_CONFIG_INTRA_ONE_INTER_TWO       (5) // favour inter by a factor 2
#define BIAS_CONFIG_INTRA_ONE_INTER_THREE     (6) // favour inter by a factor 3
#define BIAS_CONFIG_INTRA_ZERO_INTER_FOUR     (7) // Force inter by scaling it's cost by 0

#define BIAS_CONFIG_CODED_FOUR_SKIPPED_ZERO   (0) // Force coded by scaling its cost by 0
#define BIAS_CONFIG_CODED_THREE_SKIPPED_ONE   (1) // favour coded by a factor 3
#define BIAS_CONFIG_CODED_TWO_SKIPPED_ONE     (2) // favour coded by a factor 2
#define BIAS_CONFIG_CODED_ONE_SKIPPED_ONE     (3) // no bias
#define BIAS_CONFIG_CODED_ONE_SKIPPED_ONE_DUP (4) // no bias
#define BIAS_CONFIG_CODED_ONE_SKIPPED_TWO     (5) // favour skipped by a factor 2
#define BIAS_CONFIG_CODED_ONE_SKIPPED_THREE   (6) // favour skipped by a factor 3
#define BIAS_CONFIG_CODED_ZERO_SKIPPED_FOUR   (7) // Force skipped by scaling it's cost by 0

/*
 * Mask and Shift Values for software copy of line counter register
 */
// Bits [0:11] hold the line count
#define SHIFT_SW_LINE_COUNT		(0)
#define MASK_SW_LINE_COUNT		(0x00000FFF << SHIFT_SW_LINE_COUNT)
// Bits [16:31] hold the frame count
#define SHIFT_SW_FRAME_COUNT	(16)
#define MASK_SW_FRAME_COUNT		(0x0000FFFF << SHIFT_SW_FRAME_COUNT)

#endif /* _TOPAZSCFWIF_H_ */
