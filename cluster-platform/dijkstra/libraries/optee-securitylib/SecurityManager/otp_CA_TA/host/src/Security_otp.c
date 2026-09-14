/*
 * Copyright (c) 2017, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <err.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>
#include <stdlib.h>

/* OP-TEE TEE client API (built by optee_client) */
#include <tee_client_api.h>

/* TA API: UUID and command IDs */
#include <otp_keywriting_ta.h>

#define OTP_ROW_MAX_MASK 0x1ffffff

/* TEE resources */
struct test_ctx {
	TEEC_Context ctx;
	TEEC_Session sess;
};

void prepare_tee_session(struct test_ctx *ctx);
void terminate_tee_session(struct test_ctx *ctx);
TEEC_Result read_otp_mmr(struct test_ctx *ctx, const uint8_t index_mmr, uint32_t *data)
{
	TEEC_Operation op;
	uint32_t origin;
	TEEC_Result res;

	op.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_INPUT, TEEC_VALUE_OUTPUT,
					 TEEC_NONE, TEEC_NONE);

	op.params[0].value.a = index_mmr;

	res = TEEC_InvokeCommand(&ctx->sess, TA_OTP_KEYWRITING_CMD_READ_MMR,
				 &op, &origin);

	switch (res) {
	case TEEC_SUCCESS:
	case TEEC_ERROR_ITEM_NOT_FOUND:
		break;
	default:
		fprintf(stderr, "Command READ_RAW failed: 0x%x / %u\n", res,
			origin);
	}

	*data = op.params[1].value.a;

	return res;

}

TEEC_Result write_otp_row(struct test_ctx *ctx, uint8_t index_row,
			  const uint32_t data, const uint32_t mask)
{
	TEEC_Operation op;
	uint32_t origin;
	TEEC_Result res;

	op.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_INPUT, TEEC_VALUE_INPUT,
					 TEEC_NONE, TEEC_NONE);

	if (mask > OTP_ROW_MAX_MASK)
		return TEEC_ERROR_BAD_PARAMETERS;

	op.params[0].value.a = index_row;
	op.params[1].value.a = data;
	op.params[1].value.b = mask;

	res = TEEC_InvokeCommand(&ctx->sess, TA_OTP_KEYWRITING_CMD_WRITE_ROW,
				 &op, &origin);

	switch (res) {
	case TEEC_SUCCESS:
	case TEEC_ERROR_ITEM_NOT_FOUND:
		break;
	default:
		fprintf(stderr, "Command READ_RAW failed: 0x%x / %u\n", res,
			origin);
	}

	return res;
}
#if 0
TEEC_Result lock_otp_row(struct test_ctx *ctx, uint8_t index_row, uint8_t lock_mask)
{
	TEEC_Operation op;
	uint32_t origin;
	TEEC_Result res;

	op.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_INPUT, TEEC_NONE,
					 TEEC_NONE, TEEC_NONE);

	op.params[0].value.a = index_row;
	op.params[0].value.b = lock_mask;

	res = TEEC_InvokeCommand(&ctx->sess, TA_OTP_KEYWRITING_CMD_LOCK_ROW,
				 &op, &origin);

	switch (res) {
	case TEEC_SUCCESS:
	case TEEC_ERROR_ITEM_NOT_FOUND:
		break;
	default:
		fprintf(stderr, "Command READ_RAW failed: 0x%x / %u\n", res,
			origin);
	}

	return res;
}
#endif

TEEC_Result get_keyrev_keycnt(struct test_ctx *ctx, uint32_t *key_cnt, uint32_t *key_rev)
{
    TEEC_Operation op;
    uint32_t origin;
    TEEC_Result res;

	memset(&op, 0, sizeof(op));
    op.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_OUTPUT, TEEC_VALUE_OUTPUT,
                                     TEEC_NONE, TEEC_NONE);

	uint32_t l_keycnt = 0, l_keyrev = 0;
	op.params[0].value.a = l_keycnt;
	op.params[1].value.a = l_keyrev;

    res = TEEC_InvokeCommand(&ctx->sess, TA_OTP_KEYWRITING_CMD_KEYREV_KEYCNT,
                             &op, &origin);

    if (res != TEEC_SUCCESS) {
        fprintf(stderr, "Command GET_KEYREV failed: 0x%x / %u\n", res, origin);
        return res;
    }

	*key_cnt = op.params[0].value.a;
	*key_rev = op.params[1].value.a;

    return res;
}

void otp_prepare_tee_session(struct test_ctx *ctx)
{
	TEEC_UUID uuid = PTA_K3_OTP_KEYWRITING_UUID;
	uint32_t origin;
	TEEC_Result res;

	/* Initialize a context connecting us to the TEE */
	res = TEEC_InitializeContext(NULL, &ctx->ctx);
	if (res != TEEC_SUCCESS)
		errx(1, "TEEC_InitializeContext failed with code 0x%x", res);

	/* Open a session with the TA */
	res = TEEC_OpenSession(&ctx->ctx, &ctx->sess, &uuid, TEEC_LOGIN_PUBLIC,
			       NULL, NULL, &origin);
	if (res != TEEC_SUCCESS)
		errx(1, "TEEC_Opensession failed with code 0x%x origin 0x%x",
		     res, origin);
}

void otp_terminate_tee_session(struct test_ctx *ctx)
{
	TEEC_CloseSession(&ctx->sess);
	TEEC_FinalizeContext(&ctx->ctx);
}