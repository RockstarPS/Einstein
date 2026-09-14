/*
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file aes_unittest.c
 *
 * \brief AES driver unittests
 */

#include <string.h>
#include <types/sbool.h>
#include <aes.h>
#include <aes_kdf.h>
#include <unit_test.h>
#include <sec_mem_mgr.h>

#define DBG(...)

static const u32 key[] = {
	0x10eb3d60, 0xbe71ca15, 0xf0ae732b, 0x81777d85,
	0x072c351f, 0xd708613b, 0xa310982d, 0xf4df1409
};
static const u8 ecb_input_data[] = {
	0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11,
	0x73, 0x93, 0x17, 0x2a, 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96,
	0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a
};
static const u8 ecb_output_data[] = {
	0xf3, 0xee, 0xd1, 0xbd, 0xb5, 0xd2, 0xa0, 0x3c, 0x06, 0x4b, 0x5a, 0x7e,
	0x3d, 0xb1, 0x81, 0xf8, 0xf3, 0xee, 0xd1, 0xbd, 0xb5, 0xd2, 0xa0, 0x3c,
	0x06, 0x4b, 0x5a, 0x7e, 0x3d, 0xb1, 0x81, 0xf8
};
static const u8 cmac_input_data1[] = {
	0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 0x96, 0xE9, 0x3D, 0x7E, 0x11,
	0x73, 0x93, 0x17, 0x2A
};
static const u8 tag1[] = {
	0x28, 0xA7, 0x02, 0x3F, 0x45, 0x2E, 0x8F, 0x82, 0xBD, 0x4B, 0xF2, 0x8D,
	0x8C, 0x37, 0xC3, 0x5C
};
static const u8 cmac_input_data2[] = {
	0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11,
	0x73, 0x93, 0x17, 0x2a, 0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c,
	0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51, 0x30, 0xc8, 0x1c, 0x46,
	0xa3, 0x5c, 0xe4, 0x11
};
static const u8 tag2[] = {
	0xaa, 0xf3, 0xd8, 0xf1, 0xde, 0x56, 0x40, 0xc2, 0x32, 0xf5, 0xb1, 0x69,
	0xb9, 0xc9, 0x11, 0xe6
};

static const u8 cbc_key[] = {
	0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88,
	0x09, 0xcf, 0x4f, 0x3c
};
static const u8 cbc_iv[] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
	0x0c, 0x0d, 0x0e, 0x0f
};
static const u8 cbc_input[] = {
	0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11,
	0x73, 0x93, 0x17, 0x2a, 0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c,
	0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51, 0x30, 0xc8, 0x1c, 0x46,
	0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
	0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b,
	0xe6, 0x6c, 0x37, 0x10
};
static const u8 cbc_output[] = {
	0x76, 0x49, 0xab, 0xac, 0x81, 0x19, 0xb2, 0x46, 0xce, 0xe9, 0x8e, 0x9b,
	0x12, 0xe9, 0x19, 0x7d, 0x50, 0x86, 0xcb, 0x9b, 0x50, 0x72, 0x19, 0xee,
	0x95, 0xdb, 0x11, 0x3a, 0x91, 0x76, 0x78, 0xb2, 0x73, 0xbe, 0xd6, 0xb8,
	0xe3, 0xc1, 0x74, 0x3b, 0x71, 0x16, 0xe6, 0x9e, 0x22, 0x22, 0x95, 0x16,
	0x3f, 0xf1, 0xca, 0xa1, 0x68, 0x1f, 0xac, 0x09, 0x12, 0x0e, 0xca, 0x30,
	0x75, 0x86, 0xe1, 0xa7
};

static u8 *scratch_buffer;

fterr aes_unittest_interleaved()
{
	struct aes_ctx ctx1, ctx2;
	u8 *out1, *out2, *o1, *o2;
	u32 outlen1, outlen2;
	fterr ret;

	memset(&ctx1, 0, sizeof(ctx1));
	memcpy(ctx1.key_1, key, sizeof(key));
	ctx1.op_key_size = AES_OP_KEY_SIZE_256 | AES_OP_ENCRYPT;
	ctx1.mode = AES_MODE_ECB;

	memset(&ctx2, 0, sizeof(ctx2));
	memcpy(ctx2.key_1, cbc_key, sizeof(cbc_key));
	memcpy(ctx2.iv, cbc_iv, sizeof(cbc_iv));
	ctx2.op_key_size = AES_OP_KEY_SIZE_128 | AES_OP_ENCRYPT;
	ctx2.mode = AES_MODE_CBC;

	ret = aes_init(&ctx1);
	if (ret != EFTOK) {
		DBG("aes_init returned %d\n", -ret);
		return ret;
	}
	ret = aes_init(&ctx2);
	if (ret != EFTOK) {
		DBG("aes_init returned %d\n", -ret);
		return ret;
	}

	o1 = out1 = &scratch_buffer[0];
	o2 = out2 = &scratch_buffer[256];

	ret = aes_update(&ctx1, ecb_input_data,
			 sizeof(ecb_input_data) / 2, o1, &outlen1);

	if (ret != EFTOK) {
		DBG("aes_update returned %d\n", -ret);
		return ret;
	}
	o1 += outlen1;

	ret = aes_update(&ctx2, cbc_input, sizeof(cbc_input) / 2, o2,
			 &outlen2);
	if (ret != EFTOK) {
		DBG("aes_update returned %d\n", -ret);
		return ret;
	}
	o2 += outlen2;

	ret = aes_update(&ctx1, ecb_input_data +
			 (sizeof(ecb_input_data) / 2),
			 sizeof(ecb_input_data) / 2, o1, &outlen1);
	if (ret != EFTOK) {
		DBG("aes_update returned %d\n", -ret);
		return ret;
	}

	o1 += outlen1;
	ret = aes_update(&ctx2, cbc_input + (sizeof(cbc_input) / 2),
			 sizeof(cbc_input) / 2, o2,
			 &outlen2);
	if (ret != EFTOK) {
		DBG("aes_update returned %d\n", -ret);
		return ret;
	}
	o2 += outlen2;

	ret = aes_final(&ctx1, o1, &outlen1);
	if (ret != EFTOK) {
		DBG("aes_final returned %d\n", -ret);
		return ret;
	}
	ret = aes_final(&ctx2, o2, &outlen2);
	if (ret != EFTOK) {
		DBG("aes_final returned %d\n", -ret);
		return ret;
	}

	if (0 != memcmp(out1, ecb_output_data, sizeof(ecb_output_data))) {
		DBG("ecb test output mismatch\n");
		return -EFAIL;
	} else {
		DBG("aes ecb unittest passed.\n");
	}

	if (0 != memcmp(out2, cbc_output, sizeof(cbc_output))) {
		DBG("aes (cbc) output mismatch\n");
		return -EFAIL;
	} else {
		DBG("aes (cbc) unittest passed.\n");
	}

	memset(&ctx1, 0, sizeof(ctx1));
	memcpy(ctx1.key_1, key, sizeof(key));
	ctx1.op_key_size = AES_OP_KEY_SIZE_256 | AES_OP_ENCRYPT;
	ctx1.mode = AES_MODE_ECB;

	memset(&ctx2, 0, sizeof(ctx2));
	memcpy(ctx2.key_1, cbc_key, sizeof(cbc_key));
	memcpy(ctx2.iv, cbc_iv, sizeof(cbc_iv));
	ctx2.op_key_size = AES_OP_KEY_SIZE_128 | AES_OP_ENCRYPT;
	ctx2.mode = AES_MODE_CBC;

	ret = aes_init(&ctx1);
	if (ret != EFTOK) {
		DBG("aes_init returned %d\n", -ret);
		return ret;
	}
	ret = aes_init(&ctx2);
	if (ret != EFTOK) {
		DBG("aes_init returned %d\n", -ret);
		return ret;
	}

	o1 = out1;
	o2 = out2;

	ret = aes_update(&ctx1, ecb_input_data, 19, o1, &outlen1);
	if (ret != EFTOK) {
		DBG("aes_update returned %d\n", -ret);
		return ret;
	}
	o1 += outlen1;
	ret = aes_update(&ctx2, cbc_input, 11, o2, &outlen2);
	if (ret != EFTOK) {
		DBG("aes_update returned %d\n", -ret);
		return ret;
	}
	o2 += outlen2;

	ret =
		aes_update(&ctx1, ecb_input_data + 19, sizeof(ecb_input_data) -
			   19, o1,
			   &outlen1);
	if (ret != EFTOK) {
		DBG("aes_update returned %d\n", -ret);
		return ret;
	}
	o1 += outlen1;
	ret = aes_update(&ctx2, cbc_input + 11, sizeof(cbc_input) - 11, o2,
			 &outlen2);
	if (ret != EFTOK) {
		DBG("aes_update returned %d\n", -ret);
		return ret;
	}
	o2 += outlen2;

	ret = aes_final(&ctx1, o1, &outlen1);
	if (ret != EFTOK) {
		DBG("aes_final returned %d\n", -ret);
		return ret;
	}
	ret = aes_final(&ctx2, o2, &outlen2);
	if (ret != EFTOK) {
		DBG("aes_final returned %d\n", -ret);
		return ret;
	}

	if (0 != memcmp(out1, ecb_output_data, sizeof(ecb_output_data))) {
		DBG("ecb test output mismatch\n");
		return -EFAIL;
	} else {
		DBG("ecb unittest passed.\n");
	}

	if (0 != memcmp(out2, cbc_output, sizeof(cbc_output))) {
		DBG("aes (cbc) output mismatch\n");
		ret--;
	} else {
		DBG("aes (cbc) unittest passed.\n");
	}
	return ret;
}

fterr aes_unittest_oneshot()
{
	struct aes_ctx ctx;
	u32 outlen;
	fterr ret = EFTOK;

	memset(&ctx, 0, sizeof(ctx));
	memcpy(ctx.key_1, key, sizeof(key));
	ctx.op_key_size = AES_OP_KEY_SIZE_256 | AES_OP_ENCRYPT;
	ctx.mode = AES_MODE_ECB;
	ctx.kek_options = 0;

	ret = aes_oneshot(&ctx, ecb_input_data, sizeof(ecb_input_data),
			  scratch_buffer, &outlen);
	if (ret == EFTOK) {
		if (outlen != sizeof(ecb_output_data) ||
		    0 != memcmp(scratch_buffer, ecb_output_data,
				sizeof(ecb_output_data))) {
			DBG("aes_oneshot output mismatch\n");
			return -EFAIL;
		} else {
			DBG("aes_oneshot unittest passed.\n");
		}
	} else {
		DBG("aes_oneshot returned %d\n", -ret);
		return ret;
	}

	memset(&ctx, 0, sizeof(ctx));
	memcpy(ctx.key_1, cbc_key, sizeof(cbc_key));
	memcpy(ctx.iv, cbc_iv, sizeof(cbc_iv));
	ctx.op_key_size = AES_OP_KEY_SIZE_128 | AES_OP_ENCRYPT;
	ctx.mode = AES_MODE_CBC;
	ctx.kek_options = 0;

	ret = aes_oneshot(&ctx, cbc_input, sizeof(cbc_input), scratch_buffer,
			  &outlen);
	if (ret == EFTOK) {
		if (outlen != sizeof(cbc_output) ||
		    0 !=
		    memcmp(scratch_buffer, cbc_output, sizeof(cbc_output))) {
			DBG("aes_oneshot(cbc) output mismatch\n");
			return -EFAIL;
		} else {
			DBG("aes_oneshot (cbc)  unittest passed.\n");
		}
	} else {
		DBG("aes_oneshot returned %d\n", -ret);
		return ret;
	}

	memset(&ctx, 0, sizeof(ctx));
	memcpy(ctx.key_1, key, sizeof(key));
	ctx.op_key_size = AES_OP_KEY_SIZE_256 | AES_OP_ENCRYPT;
	ctx.mode = AES_MODE_CMAC;
	ctx.kek_options = 0;

	ret = aes_mac_oneshot(&ctx, cmac_input_data1,
			      sizeof(cmac_input_data1));
	if (ret == EFTOK) {
		if (0 != memcmp(ctx.tag, tag1, sizeof(tag1))) {
			DBG("aes_mac_oneshot output mismatch\n");
			return -EFAIL;
		} else {
			DBG("aes_mac_oneshot unittest passed.\n");
		}
	} else {
		DBG("aes_mac_oneshot returned %d\n", -ret);
		return ret;
	}

	memset(&ctx, 0, sizeof(ctx));
	memcpy(ctx.key_1, key, sizeof(key));
	ctx.op_key_size = AES_OP_KEY_SIZE_256 | AES_OP_ENCRYPT;
	ctx.mode = AES_MODE_CMAC;
	ctx.kek_options = 0;

	ret = aes_mac_oneshot(&ctx, cmac_input_data2,
			      sizeof(cmac_input_data2));
	if (ret == EFTOK) {
		if (0 != memcmp(ctx.tag, tag2, sizeof(tag2))) {
			DBG("aes_mac_oneshot output mismatch\n");
			return -EFAIL;
		} else {
			DBG("aes_mac_oneshot unittest passed.\n");
		}
	} else {
		DBG("aes_mac_oneshot returned %d\n", -ret);
		return ret;
	}
	return ret;
}

fterr aes_unittest_kdf()
{
	fterr ret;
	const char *label1 = "Secure storage key";
	const char *context1 = "Partition 0";
	const char *label2 =
		"Secure storage key for secure hardware extension (SHE)";
	const char *context2 = "Instance of SHE running on R5";
	u8 dkey1[27], dkey2[27];
	u8 local_ctx[2] = { 1U, 2U };

	memset(dkey1, 0, sizeof(dkey1));
	ret = aes_cmac_kdf(&local_ctx[0], 1U, (const u8 *) label1,
			   sizeof(label1),
			   (const u8 *) context1, sizeof(context1), dkey1,
			   sizeof(dkey1));
	if (ret == EFTOK) {
		DBG("aes_cmac_kdf returned OK\n");
	} else {
		DBG("aes_cmac_kdf returned %d\n", -ret);
		return ret;
	}
	memset(dkey2, 0, sizeof(dkey2));
	ret = aes_cmac_kdf(&local_ctx[0], 1U, (const u8 *) label2,
			   sizeof(label2),
			   (const u8 *) context2, sizeof(context2), dkey2,
			   sizeof(dkey2));
	if (ret == EFTOK) {
		DBG("aes_cmac_kdf returned OK\n");
	} else {
		DBG("aes_cmac_kdf returned %d\n", -ret);
		return ret;
	}
	if (0 == memcmp(dkey1, dkey2, sizeof(dkey2))) {
		DBG("aes_cmac_kdf returned same value for different ctxs\n");
		return -EFAIL;
	}

	memset(dkey2, 0, sizeof(dkey2));
	ret = aes_cmac_kdf(&local_ctx[0], 1U, (const u8 *) label1,
			   sizeof(label1),
			   (const u8 *) context1, sizeof(context1), dkey2,
			   sizeof(dkey2));
	if (ret == EFTOK) {
		DBG("aes_cmac_kdf returned OK\n");
	} else {
		DBG("aes_cmac_kdf returned %d\n", -ret);
		return ret;
	}
	if (0 != memcmp(dkey1, dkey2, sizeof(dkey2))) {
		DBG("aes_cmac_kdf returned different for same context\n");
		return -EFAIL;
	}

	memset(dkey2, 0, sizeof(dkey2));
	ret = aes_cmac_kdf(&local_ctx[1], 1U, (const u8 *) label1,
			   sizeof(label1),
			   (const u8 *) context1, sizeof(context1), dkey2,
			   sizeof(dkey2));
	if (ret == EFTOK) {
		DBG("aes_cmac_kdf returned OK\n");
	} else {
		DBG("aes_cmac_kdf returned %d\n", -ret);
		return ret;
	}
	if (0 == memcmp(dkey1, dkey2, sizeof(dkey2))) {
		DBG("aes_cmac_kdf returned same value different localctx\n");
		return -EFAIL;
	}
	return ret;
}

fterr aes_unittest_gcm()
{
	struct aes_ctx ctx;
	u32 outlen;
	fterr ret;
	static const u32 gcm_key[] = {
		0x92e9fffe, 0x1c736586, 0x948f6a6d, 0x08833067
	};
	static const u8 aad_in[] = {
		0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef, 0xfe,
		0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef, 0xab, 0xad,
		0xda, 0xd2
	};
	static const u8 iv_in[] = {
		0xca, 0xfe, 0xba, 0xbe, 0xfa, 0xce, 0xdb, 0xad, 0xde,
		0xca, 0xf8, 0x88
	};
	static const u8 data_in[] = {
		0xd9, 0x31, 0x32, 0x25, 0xf8, 0x84, 0x06, 0xe5, 0xa5,
		0x59, 0x09, 0xc5, 0xaf, 0xf5, 0x26, 0x9a,
		0x86, 0xa7, 0xa9, 0x53, 0x15, 0x34, 0xf7, 0xda, 0x2e,
		0x4c, 0x30, 0x3d, 0x8a, 0x31, 0x8a, 0x72,
		0x1c, 0x3c, 0x0c, 0x95, 0x95, 0x68, 0x09, 0x53, 0x2f,
		0xcf, 0x0e, 0x24, 0x49, 0xa6, 0xb5, 0x25,
		0xb1, 0x6a, 0xed, 0xf5, 0xaa, 0x0d, 0xe6, 0x57, 0xba,
		0x63, 0x7b, 0x39
	};
	static const u8 data_out[] = {
		0x42, 0x83, 0x1e, 0xc2, 0x21, 0x77, 0x74, 0x24, 0x4b,
		0x72, 0x21, 0xb7, 0x84, 0xd0, 0xd4, 0x9c,
		0xe3, 0xaa, 0x21, 0x2f, 0x2c, 0x02, 0xa4, 0xe0, 0x35,
		0xc1, 0x7e, 0x23, 0x29, 0xac, 0xa1, 0x2e,
		0x21, 0xd5, 0x14, 0xb2, 0x54, 0x66, 0x93, 0x1c, 0x7d,
		0x8f, 0x6a, 0x5a, 0xac, 0x84, 0xaa, 0x05,
		0x1b, 0xa3, 0x0b, 0x39, 0x6a, 0x0a, 0xac, 0x97, 0x3d,
		0x58, 0xe0, 0x91
	};
	static const u8 tag_out[] = {
		0x5b, 0xc9, 0x4f, 0xbc, 0x32, 0x21, 0xa5, 0xdb, 0x94,
		0xfa, 0xe9, 0x5a, 0xe7, 0x12, 0x1a, 0x47
	};

	memset(&ctx, 0, sizeof(ctx));
	memcpy(ctx.key_1, gcm_key, sizeof(gcm_key));
	memcpy(ctx.iv, iv_in, sizeof(iv_in));

	ctx.op_key_size = AES_OP_KEY_SIZE_128 | AES_OP_ENCRYPT;
	ctx.mode = AES_MODE_GCM;
	ctx.kek_options = 0;

	ret = aes_aenc_oneshot(&ctx, sizeof(iv_in), aad_in, sizeof(aad_in),
			       data_in, sizeof(data_in), scratch_buffer,
			       &outlen);
	if (ret == EFTOK) {
		if (0 != memcmp(scratch_buffer, data_out, sizeof(data_out))) {
			DBG("GCM data out mismatch\n");
			return -EFAIL;
		}
		if (0 != memcmp(ctx.tag, tag_out, sizeof(tag_out))) {
			DBG("GCM tag out mismatch\n");
			return -EFAIL;
		}
		DBG("aes_aenc_oneshot(gcm) test passed\n");
	} else {
		DBG("aes_aenc_oneshot returned %d\n", -ret);
		return ret;
	}
	return ret;
}

fterr aes_unittest_ccm()
{
	struct aes_ctx ctx;
	u32 outlen;
	fterr ret;
	static const u8 ccm_key[] = {
		0xce, 0xb0, 0x09, 0xae, 0xa4, 0x45, 0x44, 0x51, 0xfe,
		0xad, 0xf0, 0xe6, 0xb3, 0x6f, 0x45, 0x55, 0x5d, 0xd0,
		0x47, 0x23, 0xba, 0xa4, 0x48, 0xe8
	};

	static const u8 ccm_nonce[] = {
		0x76, 0x40, 0x43, 0xc4, 0x94, 0x60, 0xb7
	};

	static const u8 ccm_adata[] = {
		0x6e, 0x80, 0xdd, 0x7f, 0x1b, 0xad, 0xf3, 0xa1, 0xc9,
		0xab, 0x25, 0xc7, 0x5f, 0x10, 0xbd, 0xe7, 0x8c, 0x23,
		0xfa, 0x0e, 0xb8, 0xf9, 0xaa, 0xa5, 0x3a, 0xde, 0xfb,
		0xf4, 0xcb, 0xf7, 0x8f, 0xe4
	};

	static const u8 ccm_pt[] = {
		0xc8, 0xd2, 0x75, 0xf9, 0x19, 0xe1, 0x7d, 0x7f, 0xe6,
		0x9c, 0x2a, 0x1f, 0x58, 0x93, 0x9d, 0xfe, 0x4d, 0x40,
		0x37, 0x91, 0xb5, 0xdf, 0x13, 0x10
	};

	static const u8 ccm_ct[] = {
		0x8a, 0x0f, 0x3d, 0x82, 0x29, 0xe4, 0x8e, 0x74, 0x87,
		0xfd, 0x95, 0xa2, 0x8a, 0xd3, 0x92, 0xc8, 0x0b, 0x36,
		0x81, 0xd4, 0xfb, 0xc7, 0xbb, 0xfd
	};

	static const u8 ccm_tag[] = {
		0x2d, 0xd6, 0xef, 0x1c, 0x45, 0xd4, 0xcc, 0xb7, 0x23,
		0xdc, 0x07, 0x44, 0x14, 0xdb, 0x50, 0x6d
	};

	memset(&ctx, 0, sizeof(ctx));
	memcpy(ctx.key_1, ccm_key, sizeof(ccm_key));
	memcpy(ctx.iv, ccm_nonce, sizeof(ccm_nonce));

	ctx.op_key_size = AES_OP_KEY_SIZE_192 | AES_OP_ENCRYPT;
	ctx.mode = AES_MODE_CCM;
	ctx.kek_options = 0;

	ret = aes_aenc_oneshot(&ctx, sizeof(ccm_nonce), ccm_adata,
			       sizeof(ccm_adata), ccm_pt, sizeof(ccm_pt),
			       scratch_buffer, &outlen);
	if (ret == EFTOK) {
		if (0 != memcmp(scratch_buffer, ccm_ct, sizeof(ccm_ct))) {
			DBG("CCM output mismatch\n");
			return -EFAIL;
		}
		if (0 != memcmp(ctx.tag, ccm_tag, sizeof(ccm_tag))) {
			DBG("CCM tag mismatch\n");
			return -EFAIL;
		}
		DBG("aes_aenc_oneshot(ccm) test passed\n");
	} else {
		DBG("aes_aenc_oneshot returned %d\n", -ret);
		return ret;
	}
	return ret;
}
/**
 * \brief AES driver unit tests
 *
 * Tests AES driver in different modes
 *
 * \param param test input (unused)
 *
 * \return retruns zero for no error, test case number that failed otherwise
 */
u32 aes_unittest(void)
{
	u32 ret = 0;
	do {
		ret++;
		if (EFTOK != aes_unittest_interleaved()) {
			break;
		}
		ret++;
		if (EFTOK != aes_unittest_oneshot()) {
			break;
		}
		ret++;
		if (EFTOK != aes_unittest_kdf()) {
			break;
		}
		ret++;
		if (EFTOK != aes_unittest_gcm()) {
			break;
		}
		ret++;
		if (EFTOK != aes_unittest_ccm()) {
			break;
		}
		ret = 0;
	} while (0);
	DBG("aes_unittest done, returning %d\n", ret);

	return ret;
}

