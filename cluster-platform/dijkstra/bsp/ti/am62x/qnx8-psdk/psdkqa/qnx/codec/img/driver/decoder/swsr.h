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
 * Software Shift Register Access fucntions
 */
#ifndef _SWSR_H
#define _SWSR_H

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_types.h"
#include "img_errors.h"
#include "lst.h"

#define SWSR_MAX_DELIM_LENGTH   (8 * 8)

enum swsr_exception {
	SWSR_EXCEPT_NO_EXCEPTION = 0x00,
	SWSR_EXCEPT_ENCAPULATION_ERROR1,
	SWSR_EXCEPT_ENCAPULATION_ERROR2,
	SWSR_EXCEPT_ACCESS_INTO_SCP,
	SWSR_EXCEPT_ACCESS_BEYOND_EOD,
	SWSR_EXCEPT_EXPGOULOMB_ERROR,
	SWSR_EXCEPT_WRONG_CODEWORD_ERROR,
	SWSR_EXCEPT_NO_SCP,
	SWSR_EXCEPT_INVALID_CONTEXT,
	SWSR_EXCEPT_FORCE32BITS = 0x7FFFFFFFU
};

enum swsr_cbevent {
	SWSR_EVENT_INPUT_BUFFER_START = 0,
	SWSR_EVENT_OUTPUT_BUFFER_END,
	SWSR_EVENT_DELIMITER_NAL_TYPE,
	SWSR_EVENT_FORCE32BITS = 0x7FFFFFFFU
};

enum swsr_found {
	SWSR_FOUND_NONE = 0,
	SWSR_FOUND_EOD,
	SWSR_FOUND_DELIM,
	SWSR_FOUND_DATA,
	SWSR_FOUND_FORCE32BITS = 0x7FFFFFFFU
};

enum swsr_delim_type {
	SWSR_DELIM_NONE = 0,
	SWSR_DELIM_SCP,
	SWSR_DELIM_SIZE,
	SWSR_DELIM_MAX,
	SWSR_DELIM_FORCE32BITS = 0x7FFFFFFFU
};

enum swsr_emprevent {
	SWSR_EMPREVENT_NONE = 0x00,
	SWSR_EMPREVENT_00000300,
	SWSR_EMPREVENT_ff00,
	SWSR_EMPREVENT_000002,
	SWSR_EMPREVENT_MAX,
	SWSR_EMPREVENT_FORCE32BITS = 0x7FFFFFFFU
};

struct swsr_config {
	enum swsr_delim_type delim_type;
	uint32 delim_length;
	uint64 scp_value;
};

/*
 * This is the function prototype for the caller supplier exception handler.
 *
 * NOTE: The internally recorded exception is reset to #SWSR_EXCEPT_NO_EXCEPTION
 * on return from SWSR_CheckException() or a call to the caller supplied
 * exception handler see #SWSR_pfnExceptHandler.
 *
 * NOTE: By defining an exception handler the caller can handle Shift Register
 * errors as they occur - for example, using a structure exception mechanism
 * such as setjmp/longjmp.
 */
typedef void (*swsr_except_handler_fxn)(enum swsr_exception exception,
					void *callback_param);

/*
 * This is the function prototype for the caller supplier to retrieve the data
 * from the application
 */
typedef void (*swsr_callback_fxn)(enum swsr_cbevent event,
				  void *priv_data,
				  uint8 nal_type, uint8 **data_buffer,
				  uint64 *data_size);

int32 swsr_get_total_bitsconsumed(void *context, uint64 *total_bitsconsumed);

/*
 * This function is used to return the offset into the current bitstream buffer
 * on the shift-register output FIFO. Call after #SWSR_SeekDelimOrEOD to
 * determine the offset of an delimiter.
 */
int32 swsr_get_byte_offset_curbuf(void *context, uint64 *byte_offset);

/*
 * This function is used to read a signed Exp-Goulomb value from the Shift
 * Register.
 *
 * NOTE: If this function is used to attempt to read into a Start-Code-Prefix
 * or beyond the End-Of-Data then and exception is generated which can be
 * handled by the caller supplied exception handler see
 * #SWSR_pfnExceptionHandler. If no exception handler has been supplied (or the
 * exception handler returns) then the exception is recorded and can be obtained
 * using SWSR_CheckException(). In this event the function returns 0.
 */
int32 swsr_read_signed_expgoulomb(void *context);

/*
 * This function is used to read a unsigned Exp-Goulomb value from the Shift
 * Register.
 *
 * NOTE: If this function is used to attempt to read into a Start-Code-Prefix
 * or beyond the End-Of-Data then and exception is generated which can be
 * handled by the caller supplied exception handler see
 * #SWSR_pfnExceptionHandler. If no exception handler has been supplied (or the
 * exception handler returns) then the exception is recorded and can be obtained
 * using SWSR_CheckException(). In this event the function returns 0.
 */
uint32 swsr_read_unsigned_expgoulomb(void *context);

/*
 * This function is used to check for exceptions.
 *
 * NOTE: The internally recorded exception is reset to #SWSR_EXCEPT_NO_EXCEPTION
 * on return from SWSR_CheckException() or a call to the caller supplied
 * exception  handler see #SWSR_pfnExceptionHandler.
 */
enum swsr_exception swsr_check_exception(void *context);

/*
 * This function is used to check for bitstream data with
 * SWSR_EMPREVENT_00000300 whether more RBSP data is present.
 */
int32 swsr_check_more_rbsp_data(void *context, osa_bool *more_rbsp_data);

/*
 * This function is used to read a single bit from the Shift Register.
 *
 * NOTE: If this function is used to attempt to read into a Start-Code-Prefix
 * or beyond the End-Of-Data then and exception is generated which can be
 * handled by the caller supplied exception handler see
 * #SWSR_pfnExceptionHandler. If no exception handler has been supplied (or the
 * exception handler returns) then the exception is recorded and can be obtained
 * using SWSR_CheckException(). In this event the function returns 0.
 */
uint32 swsr_read_onebit(void *context);

/*
 * This function is used to consume a number of bits from the Shift Register.
 *
 * NOTE: If this function is used to attempt to read into a Start-Code-Prefix
 * or beyond the End-Of-Data then and exception is generated which can be
 * handled by the caller supplied exception handler see
 * #SWSR_pfnExceptionHandler. If no exception handler has been supplied (or the
 * exception handler returns) then the exception is recorded and can be obtained
 * using SWSR_CheckException(). In this event the function returns 0.
 */
uint32 swsr_read_bits(void *context, uint32 no_bits);

int32 swsr_read_signedbits(void *context, uint32 no_bits);

/*
 * This function is used to peek at number of bits from the Shift Register. The
 * bits are not consumed.
 *
 * NOTE: If this function is used to attempt to read into a Start-Code-Prefix
 * or beyond the End-Of-Data then and exception is generated which can be
 * handled by the caller supplied exception handler see
 * #SWSR_pfnExceptionHandler. If no exception handler has been supplied (or
 * the exception handler returns) then the exception is recorded and can be
 * obtained using SWSR_CheckException(). In this event the function returns 0.
 */
uint32 swsr_peekbits(void *context, uint32 no_bits);

/*
 * Makes the shift-register output byte-aligned by consuming the remainder of
 * the current partially read byte.
 */
int32 swsr_byte_align(void *context);

/*
 * Consume the next delimiter whose length should be specified if delimiter type
 * is #SWSR_DELIM_SIZE. The emulation prevention detection/removal scheme can
 * also be specified for this and subsequent units.
 *
 * Consumes the unit delimiter from the bitstream buffer. The delimiter type
 * depends upon the bitstream format.
 */
int32 swsr_consume_delim(void *context,
		       enum swsr_emprevent emprevent,
		       uint32 size_delim_length,
		       uint64 *byte_count);

/*
 * Seek for the next delimiter or end of bitstream data if no delimiter is
 * found.
 */
enum swsr_found swsr_seek_delim_or_eod(void *context);

/*
 * Check if shift-register is at a delimiter or end of data.
 */
enum swsr_found swsr_check_delim_or_eod(void *context);

/*
 * This function automatically fetches the first bitstream buffer (using
 * callback with event type #SWSR_EVENT_INPUT_BUFFER_START) before returning.
 */
int32 swsr_start_bitstream(void *context,
			 const struct swsr_config *pconfig,
			 uint64 bitstream_size,
			 enum swsr_emprevent emprevent);

/*
 * This function is used to de-initialise the Shift Register.
 */
int32 swsr_deinitialise(void *context);

/*
 * This function is used to initialise the Shift Register.
 *
 * NOTE: If no exception handler is provided (pfnExceptionHandler == IMG_NULL)
 * then the caller must check for exceptions using the function
 * SWSR_CheckException().
 *
 * NOTE: If pui8RbduBuffer is IMG_NULL then the bit stream is not encapsulated
 * so the Shift Register needn't perform and de-encapsulation.  However,
 * if this is not IMG_NULL then, from time to time, the Shift Register APIs
 * will de-encapsulate portions of the bit stream into this intermediate buffer
 * - the larger the buffer the less frequent the de-encapsulation function
 * needs to be called.
 */
int32 swsr_initialise(swsr_except_handler_fxn exception_handler_fxn,
		    void *exception_cbparam,
		    swsr_callback_fxn callback_fxn,
		    void *cb_param,
		    void **context);

/*
 *  This function is used to return the size in bytes of the delimited unit
 *  that's currently being processed.
 *
 *  NOTE: This size includes all the emulation prevention bytes present
 *  in the delimited unit.
 */
int32 swsr_get_current_delimited_unitsize(void *context, uint32 *size);

/*
 * This function is used to copy the delimited unit that's currently being
 * processed to the provided buffer.
 *
 * NOTE: This delimited unit includes all the emulation prevention bytes present
 * in it.
 */
int32 swsr_get_current_delimited_unit(void *context, uint8 *data, uint32 *size);

/*
 * This function is used to return the bit offset the shift register is at
 * in processing the current delimited unit.
 *
 * NOTE: This offset does not count emulation prevention bytes.
 */
int32 swsr_get_current_delimited_unit_bit_offset(void *context, uint32 *bit_offset);

#endif /* _SWSR_H */
