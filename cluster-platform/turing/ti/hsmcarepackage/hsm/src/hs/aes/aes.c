/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file aes.c
 *
 * \brief  DMSC AES engine driver
 *
 */

#include <types/short_types.h>
#include <string.h>

#include <aes.h>
#include <common_funcs.h>

/**
 * \brief AES engine registers
 *
 * \param KEY2_6  XTS second key / CBC-MAC third key
 * \param KEY2_7  XTS second key (MSW for 256-bit key) / CBC-MAC third key (MSW)
 * \param KEY2_4  XTS / CCM second key / CBC-MAC third key (LSW)
 * \param KEY2_5  XTS second key (MSW for 192-bit key) / CBC-MAC third key
 * \param KEY2_2  XTS / CCM / CBC-MAC second key / Hash Key input
 * \param KEY2_3  XTS second key (MSW for 128-bit key) +
 *                CCM/CBC-MAC second key (MSW) + Hash Key input (MSW)
 * \param KEY2_0  XTS / CCM / CBC-MAC second key (LSW) / Hash Key input (LSW)
 * \param KEY2_1  XTS / CCM / CBC-MAC second key / Hash Key input
 * \param KEY1_6  Key (LSW for 256-key)
 * \param KEY1_7  Key (MSW for 256-bit key)
 * \param KEY1_4  Key (LSW for 192-bit key)
 * \param KEY1_5  Key (MSW for 192-bit key)
 * \param KEY1_2  Key
 * \param KEY1_3  Key (MSW for 128-bit key)
 * \param KEY1_0  Key (LSW for 128-bit key)
 * \param KEY1_1  Key
 * \param IV_IN_0 Initialization Vector input (LSW)
 * \param IV_IN_1 Initialization vector input
 * \param IV_IN_2 Initialization vector input
 * \param IV_IN_3 Initialization Vector input (MSW)
 * \param CTRL register determines the mode of operation of the AES Engine
 * \param C_LENGTH_0  Crypto data length registers (LSW and MSW) store the
 *                    cryptographic data length in bytes for all modes. Once
 *                    processing with this context is started, this length
 *                    decrements to zero. Data lengths up to (2^61 - 1) bytes
 *                    are allowed. For GCM, any value up to 2^36 - 32 bytes can
 *                    be used. This is because a 32-bit counter mode is used;
 *                    the maximum number of 128-bit blocks is 2^32 - 2,
 *                    resulting in a maximum number of bytes of 2^36 - 32.
 *                    A write to this register triggers the engine to start
 *                    using this context. This is valid for all modes except
 *                    GCM and CCM. Note that for the combined modes, this length
 *                    does not include the authentication only data; the
 *                    authentication length is specified in the AES_AUTH_LENGTH
 *                    register below. All modes must have a length > 0. For the
 *                    combined modes, it is allowed to have one of the lengths
 *                    equal to zero. For the basic encryption modes
 *                    (ECB/CBC/CTR/ICM/CFB128) it is allowed to program zero to
 *                    the length field; in that case the length is assumed
 *                    infinite. All data must be byte (8-bit) aligned; bit
 *                    aligned data streams are not supported by the AES Engine.
 *                    For a Host read operation, these registers return
 *                    all-zeroes.
 * \param C_LENGTH_1  \ref C_LENGTH_0
 * \param AUTH_LENGTH AAD data length. The authentication length register store
 *                    the authentication data length in bytes for combined modes
 *                    only (GCM or CCM) Supported AAD-lengths for CCM are from
 *                    0 to (2^16 - 2^8) bytes. For GCM any value up to
 *                    (2^32 - 1) bytes can be used. Once processing with this
 *                    context is started, this length decrements to zero. A
 *                    write to this register triggers the engine to start using
 *                    this context for GCM and CCM. For XTS this register is
 *                    optionally used to load "j". Loading of "j" is only
 *                    required if "j" != 0. "j" is a 28-bit value and must be
 *                    written to bits [31-4] of this register. "j" represents
 *                    the sequential number of the 128-bit block inside the data
 *                    unit. For the first block in a unit, this value is zero.
 *                    It is not required to provide a "j" for each n ta
 *                    block within a unit. Note that it is possible to start
 *                    with a "j" unequal to zero; refer to Table 4 for more
 *                    details. For a Host read operation, these registers return
 *                    all-zeroes.
 * \param DATA_IN_0  Data register to read and write plaintext/ciphertext (MSW)
 * \param DATA_IN_1  Data register to read and write plaintext/ciphertext
 * \param DATA_IN_2  Data register to read and write plaintext/ciphertext
 * \param DATA_IN_3  Data register to read and write plaintext/ciphertext (LSW)
 * \param TAG_OUT_0  Tag output 0 for modes that produce a TAG
 * \param TAG_OUT_1  Tag output 1 for modes that produce a TAG
 * \param TAG_OUT_2  Tag output 2 for modes that produce a TAG
 * \param TAG_OUT_3  Tag output 3 for modes that produce a TAG
 * \param REVISION   H/W revision
 * \param SYSCONFIG  This register configures IDLE and reset logic
 * \param SYSSTS     S_SYSSTS
 * \param IRQSTS     This register indicates the interrupt status
 * \param IRQEN      This register contains an enable bit for each unique
 *                   interrupt generated by the module. It matches the layout of
 *                   \ref IRQSTS register. An interrupt is enabled when the bit
 *                   in this register is set to "1". An interrupt that is
 *                   enabled is propagated to the SINTREQUEST_x output. All
 *                   interrupts need to be enabled explicitly by writing this
 *                   register.
 * \param S_DIRTYBITS S_DIRTYBITS
 * \param S_LOCKDOWN S_LOCKDOWN
 *
 */
struct aes_regs {
	u32	KEY2_6;
	u32	KEY2_7;
	u32	KEY2_4;
	u32	KEY2_5;
	u32	KEY2_2;
	u32	KEY2_3;
	u32	KEY2_0;
	u32	KEY2_1;
	u32	KEY1_6;
	u32	KEY1_7;
	u32	KEY1_4;
	u32	KEY1_5;
	u32	KEY1_2;
	u32	KEY1_3;
	u32	KEY1_0;
	u32	KEY1_1;
	u32	IV_IN_0;
	u32	IV_IN_1;
	u32	IV_IN_2;
	u32	IV_IN_3;
	u32	CTRL;
	u32	C_LENGTH_0;
	u32	C_LENGTH_1;
	u32	AUTH_LENGTH;
	u32	DATA_IN_0;
	u32	DATA_IN_1;
	u32	DATA_IN_2;
	u32	DATA_IN_3;
	u32	TAG_OUT_0;
	u32	TAG_OUT_1;
	u32	TAG_OUT_2;
	u32	TAG_OUT_3;
	u32	REVISION;
	u32	SYSCONFIG;
	u32	SYSSTS;
	u32	IRQSTS;
	u32	IRQEN;
	u32	S_DIRTYBITS;
	u32	S_LOCKDOWN;
	u8	RSVD0[0x1000 - 0x9c];
};

volatile struct aes_regs AES_REGS[2] __attribute__((location(0x4423D000U)));

#define AES_CTRL_OUTPUT_READY_MASK                        (0x00000001U)
#define AES_CTRL_OUTPUT_READY_SHIFT                       (0U)
#define AES_CTRL_OUTPUT_READY_MAX                         (0x00000001U)

#define AES_CTRL_INPUT_READY_MASK                         (0x00000002U)
#define AES_CTRL_INPUT_READY_SHIFT                        (1U)
#define AES_CTRL_INPUT_READY_MAX                          (0x00000001U)

#define AES_CTRL_DIRECTION_MASK                           (0x00000004U)
#define AES_CTRL_DIRECTION_SHIFT                          (2U)
#define AES_CTRL_DIRECTION_ENCRYPT                        (0x00000001U)

#define AES_CTRL_KEY_SIZE_MASK                            (0x00000018U)
#define AES_CTRL_KEY_SIZE_SHIFT                           (3U)
#define AES_CTRL_KEY_SIZE_KEY128                          (0x00000001U)
#define AES_CTRL_KEY_SIZE_KEY192                          (0x00000002U)
#define AES_CTRL_KEY_SIZE_KEY256                          (0x00000003U)

#define AES_CTRL_MODE_MASK                                (0x00000020U)
#define AES_CTRL_MODE_SHIFT                               (5U)
#define AES_CTRL_MODE_CBC                                 (0x00000001U)

#define AES_CTRL_CTR_MASK                                 (0x00000040U)
#define AES_CTRL_CTR_SHIFT                                (6U)
#define AES_CTRL_CTR_CTR                                  (0x00000001U)

#define AES_CTRL_CTR_WIDTH_MASK                           (0x00000180U)
#define AES_CTRL_CTR_WIDTH_SHIFT                          (7U)
#define AES_CTRL_CTR_WIDTH_COUNTER64                      (0x00000001U)
#define AES_CTRL_CTR_WIDTH_COUNTER96                      (0x00000002U)
#define AES_CTRL_CTR_WIDTH_COUNTER128                     (0x00000003U)

#define AES_CTRL_ICM_MASK                                 (0x00000200U)
#define AES_CTRL_ICM_SHIFT                                (9U)
#define AES_CTRL_ICM_ICM                                  (0x00000001U)

#define AES_CTRL_CFB_MASK                                 (0x00000400U)
#define AES_CTRL_CFB_SHIFT                                (10U)
#define AES_CTRL_CFB_CFB                                  (0x00000001U)

#define AES_CTRL_XTS_MASK                                 (0x00001800U)
#define AES_CTRL_XTS_SHIFT                                (11U)
#define AES_CTRL_XTS_XTS01                                (0x00000001U)
#define AES_CTRL_XTS_XTS10                                (0x00000002U)
#define AES_CTRL_XTS_XTS11                                (0x00000003U)

#define AES_CTRL_F8_MASK                                  (0x00002000U)
#define AES_CTRL_F8_SHIFT                                 (13U)
#define AES_CTRL_F8_F8                                    (0x00000001U)

#define AES_CTRL_F9_MASK                                  (0x00004000U)
#define AES_CTRL_F9_SHIFT                                 (14U)
#define AES_CTRL_F9_F9                                    (0x00000001U)

#define AES_CTRL_CBCMAC_MASK                              (0x00008000U)
#define AES_CTRL_CBCMAC_SHIFT                             (15U)
#define AES_CTRL_CBCMAC_CBCMAC                            (0x00000001U)

#define AES_CTRL_GCM_MASK                                 (0x00030000U)
#define AES_CTRL_GCM_SHIFT                                (16U)
#define AES_CTRL_GCM_GCM01                                (0x00000001U)
#define AES_CTRL_GCM_GCMA10                               (0x00000002U)
#define AES_CTRL_GCM_GCM11                                (0x00000003U)

#define AES_CTRL_CCM_MASK                                 (0x00040000U)
#define AES_CTRL_CCM_SHIFT                                (18U)
#define AES_CTRL_CCM_CCM                                  (0x00000001U)

#define AES_CTRL_CCM_L_MASK                               (0x00380000U)
#define AES_CTRL_CCM_L_SHIFT                              (19U)
#define AES_CTRL_CCM_L_MAX                                (0x00000007U)

#define AES_CTRL_CCM_M_MASK                               (0x01C00000U)
#define AES_CTRL_CCM_M_SHIFT                              (22U)
#define AES_CTRL_CCM_M_MAX                                (0x00000007U)

#define AES_CTRL_SAVE_CONTEXT_MASK                        (0x20000000U)
#define AES_CTRL_SAVE_CONTEXT_SHIFT                       (29U)
#define AES_CTRL_SAVE_CONTEXT_MAX                         (0x00000001U)

#define AES_CTRL_SAVE_CONTEXT_READY_MASK                  (0x40000000U)
#define AES_CTRL_SAVE_CONTEXT_READY_SHIFT                 (30U)
#define AES_CTRL_SAVE_CONTEXT_READY_MAX                   (0x00000001U)

#define AES_CTRL_CONTEXT_READY_MASK                       (0x80000000U)
#define AES_CTRL_CONTEXT_READY_SHIFT                      (31U)
#define AES_CTRL_CONTEXT_READY_MAX                        (0x00000001U)

/* SYSCONFIG */
#define AES_SYSCONFIG_AUTOIDLE_MASK                       (0x00000001U)
#define AES_SYSCONFIG_AUTOIDLE_SHIFT                      (0U)
#define AES_SYSCONFIG_AUTOIDLE_CLOCKS_OFF                 (0x00000001U)

#define AES_SYSCONFIG_SOFTRESET_MASK                      (0x00000002U)
#define AES_SYSCONFIG_SOFTRESET_SHIFT                     (1U)
#define AES_SYSCONFIG_SOFTRESET_SOFRESET                  (0x00000001U)

#define AES_SYSCONFIG_SIDLE_MASK                          (0x0000000CU)
#define AES_SYSCONFIG_SIDLE_SHIFT                         (2U)
#define AES_SYSCONFIG_SIDLE_NOIDLE                        (0x00000001U)
#define AES_SYSCONFIG_SIDLE_SMARTIDLE                     (0x00000002U)
#define AES_SYSCONFIG_SIDLE_RESERVED                      (0x00000003U)

#define AES_SYSCONFIG_DIRECTBUSEN_MASK                    (0x00000010U)
#define AES_SYSCONFIG_DIRECTBUSEN_SHIFT                   (4U)
#define AES_SYSCONFIG_DIRECTBUSEN_DIRECT                  (0x00000001U)

#define AES_SYSCONFIG_DMA_REQ_DATA_IN_EN_MASK             (0x00000020U)
#define AES_SYSCONFIG_DMA_REQ_DATA_IN_EN_SHIFT            (5U)
#define AES_SYSCONFIG_DMA_REQ_DATA_IN_EN_DMA_EN           (0x00000001U)

#define AES_SYSCONFIG_DMA_REQ_DATA_OUT_EN_MASK            (0x00000040U)
#define AES_SYSCONFIG_DMA_REQ_DATA_OUT_EN_SHIFT           (6U)
#define AES_SYSCONFIG_DMA_REQ_DATA_OUT_EN_DMA_EN          (0x00000001U)

#define AES_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_MASK          (0x00000080U)
#define AES_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_SHIFT         (7U)
#define AES_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN_DMA_EN        (0x00000001U)

#define AES_SYSCONFIG_DMA_REQ_CONTEXT_OUT_EN_MASK         (0x00000100U)
#define AES_SYSCONFIG_DMA_REQ_CONTEXT_OUT_EN_SHIFT        (8U)
#define AES_SYSCONFIG_DMA_REQ_CONTEXT_OUT_EN_DMA_EN       (0x00000001U)

#define AES_SYSCONFIG_MAP_CONTEXT_OUT_ON_DATA_MASK        (0x00000200U)
#define AES_SYSCONFIG_MAP_CONTEXT_OUT_ON_DATA_SHIFT       (9U)
#define AES_SYSCONFIG_MAP_CONTEXT_OUT_ON_DATA_MAX         (0x00000001U)

#define AES_SYSCONFIG_KEK_MODE_MASK                       (0x00000400U)
#define AES_SYSCONFIG_KEK_MODE_SHIFT                      (10U)
#define AES_SYSCONFIG_KEK_MODE_MAX                        (0x00000001U)

#define AES_SYSCONFIG_KEY_ENC_MASK                        (0x00000800U)
#define AES_SYSCONFIG_KEY_ENC_SHIFT                       (11U)
#define AES_SYSCONFIG_KEY_ENC_MAX                         (0x00000001U)

#define AES_SYSCONFIG_K3_MASK                             (0x00001000U)
#define AES_SYSCONFIG_K3_SHIFT                            (12U)
#define AES_SYSCONFIG_K3_MAX                              (0x00000001U)

#define AES_SYSCONFIG_KEK_MODE_ID_MASK                    (0x00004000U)
#define AES_SYSCONFIG_KEK_MODE_ID_SHIFT                   (14U)
#define AES_SYSCONFIG_KEK_MODE_ID_MAX                     (0x00000001U)

#define AES_SYSCONFIG_KEK_MODE_LEN_MASK                   (0x00018000U)
#define AES_SYSCONFIG_KEK_MODE_LEN_SHIFT                  (15U)
#define AES_SYSCONFIG_KEK_MODE_LEN_KEY128                 (0x00000001U)
#define AES_SYSCONFIG_KEK_MODE_LEN_KEY192                 (0x00000002U)
#define AES_SYSCONFIG_KEK_MODE_LEN_KEY256                 (0x00000003U)

#define AES_HIB_SECURE (0)
#define AES_HIB_PUBLIC (1)

#define RD_FIELD(val, bits) (((u32) val & bits##_MASK) >> bits##_SHIFT)
#define IS_ALIGNED(val, align) (((val) & ((align) - 1U)) == 0)
#define AES_BLOCK_ALIGN(val) ((val) & (~(AES_BLOCKLEN_BYTES - 1U)))

/**
 * Timeout for operations such as waiting one block processing to complete
 */
#define AES_OP_TIMEOUT_US         100U
/**
 * Timeout for sysreset
 */
#define AES_SRESET_TIMEOUT_US     100U

/*
 * Function prototypes
 */
static u32 aes_get_hib(struct aes_ctx *ctx __attribute__((unused)));
static void aes_release_hib(u32 hib __attribute__((unused)));
static void aes_cmac_shift(u8 in[AES_BLOCKLEN_BYTES]);
static void aes_u32_to_u8(u32 in, u8 out[4]);
static u32 aes_u8_to_u32(const u8 in[4]);
static fterr aes_read_tag(u32 hib, struct aes_ctx *ctx);
static fterr aes_save_context(u32 hib, struct aes_ctx *ctx);
static fterr aes_restore_context(u32 hib, const struct aes_ctx *ctx);
static fterr aes_copy_input_block(u32 hib, const u8 input[AES_BLOCKLEN_BYTES]);
static fterr aes_copy_output_block(u32 hib, u8 output[AES_BLOCKLEN_BYTES]);
static void aes_append_to_rdata(struct aes_ctx *ctx, const u8 *in, u32 in_len);
static fterr aes_process(u32 hib, struct aes_ctx *ctx, const u8 *in, u32 in_len, u8 *out, u32 *out_len);
static fterr aes_process_rdata(u32 hib, struct aes_ctx *ctx, u8 *out, u32 *out_len);
static fterr aes_aenc_validate(const struct aes_ctx *ctx, u32 iv_len, u32 aad_len);


u32 aes_revision(void)
{
	return readl(&AES_REGS[0].REVISION) |
	       (readl(&AES_REGS[1].REVISION) << 16);
}

fterr aes_softreset(void)
{
	fterr ret = -ETIMEDOUT;

	writel(&AES_REGS[0].SYSCONFIG,
	       AES_SYSCONFIG_SOFTRESET_SOFRESET <<
	       AES_SYSCONFIG_SOFTRESET_SHIFT);

	if (reg_poll_timeout_us(&AES_REGS[0].SYSSTS, 1U, 1U,
				AES_SRESET_TIMEOUT_US)) {
		ret = EFTOK;
	}
	return ret;
}

/**
 * \brief Acquire (and lock) a H/W context
 *
 * Acquire (and lock) a H/W context. This function should use a mutex and could
 * block if an instance is currently in use.
 *
 * \param ctx AES driver context
 *
 * \return AES HIB allocated to the caller
 */
static u32 aes_get_hib(struct aes_ctx *ctx __attribute__((unused)))
{
	/* TODO: acquire a lock, etc.. for multi-threaded case if required */
	return AES_HIB_SECURE;
}

/**
 * \brief Release a locked H/W context
 *
 * \param hib AES HIB allocated to the caller
 */
static void aes_release_hib(u32 hib __attribute__((unused)))
{
	/* TODO: */
}

/**
 * \brief Left shift by 1 and XOR with constant for CMAC mode in-place
 *
 * \param in Input/output data of one AES block size
 */
static void aes_cmac_shift(u8 in[AES_BLOCKLEN_BYTES])
{
	u8 tmp = (in[0] << 1), carry = (in[0] >> 7);
	u32 i;

	for (i = 1U; i < AES_BLOCKLEN_BYTES; i++) {
		in[i - 1U] = (in[i] >> 7) | tmp;
		tmp = (in[i] << 1);
	}
	in[AES_BLOCKLEN_BYTES - 1U] = tmp ^ ((0U - carry) & 0x87U);
}

/**
 * \brief write a u32 values into a u8 array
 *
 * \param in Input 32-bit word
 * \param out Output 4-byte array
 */
static void aes_u32_to_u8(u32 in, u8 out[4])
{
	out[3] = (u8) (in >> 24);
	out[2] = (u8) (in >> 16);
	out[1] = (u8) (in >> 8);
	out[0] = (u8) (in);
}

/**
 * \brief Read a u8 array into a u32 value
 *
 * \param in Input 4-byte array
 * \return Output 32-bit word
 */
static u32 aes_u8_to_u32(const u8 in[4])
{
	return (((u32) in[3]) << 24) |
	       (((u32) in[2]) << 16) |
	       (((u32) in[1]) << 8) |
	       ((u32) in[0]);
}

/**
 * \brief Read TAG for modes that needs to output this.
 *
 * \param hib AES HIB allocated to the caller
 * \param ctx AES driver context
 *
 * \return EFTOK on success, errorcode otherwise
 */
static fterr aes_read_tag(u32 hib, struct aes_ctx *ctx)
{
	fterr ret = -ETIMEDOUT;

	if (reg_poll_timeout_us(&AES_REGS[hib].CTRL,
				AES_CTRL_SAVE_CONTEXT_READY_MASK,
				(u32) 1U << AES_CTRL_SAVE_CONTEXT_READY_SHIFT,
				AES_OP_TIMEOUT_US)) {
		ctx->tag[0] = readl(&AES_REGS[hib].TAG_OUT_0);
		ctx->tag[1] = readl(&AES_REGS[hib].TAG_OUT_1);
		ctx->tag[2] = readl(&AES_REGS[hib].TAG_OUT_2);
		ctx->tag[3] = readl(&AES_REGS[hib].TAG_OUT_3);
		ret = EFTOK;
	}
	return ret;
}

/**
 * \brief Save the current AES context, IV and Key
 *
 * \param hib AES HIB allocated to the caller
 * \param ctx AES driver context
 *
 * \return EFTOK on success, errorcode otherwise
 */
static fterr aes_save_context(u32 hib, struct aes_ctx *ctx)
{
	fterr ret = EFTOK;

	if (ctx->mode != AES_MODE_ECB) {
		ret = -ETIMEDOUT;

		if (reg_poll_timeout_us(
			    &AES_REGS[hib].CTRL,
			    AES_CTRL_SAVE_CONTEXT_READY_MASK,
			    (u32) 1U << AES_CTRL_SAVE_CONTEXT_READY_SHIFT,
			    AES_OP_TIMEOUT_US)) {
			ctx->iv[0] = readl(&AES_REGS[hib].IV_IN_0);
			ctx->iv[1] = readl(&AES_REGS[hib].IV_IN_1);
			ctx->iv[2] = readl(&AES_REGS[hib].IV_IN_2);
			ctx->iv[3] = readl(&AES_REGS[hib].IV_IN_3);

			if (ctx->fixed_clen) {
				ctx->fixed_clen =
					readl(&AES_REGS[hib].C_LENGTH_0);
			}
			ret = EFTOK;
		}
	}

	return ret;
}

/**
 * \brief Restore the current AES context of KEY, IV and TAG (if required)
 *
 * \param hib AES HIB allocated to the caller
 * \param ctx AES driver context
 *
 * \return EFTOK on success, errorcode otherwise
 */
static fterr aes_restore_context(u32 hib, const struct aes_ctx *ctx)
{
	u32 reg;
	fterr ret = EFTOK;

	/* Wait for context ready */
	if (!reg_poll_timeout_us(&AES_REGS[hib].CTRL,
				 AES_CTRL_CONTEXT_READY_MASK,
				 (u32) 1U << AES_CTRL_CONTEXT_READY_SHIFT,
				 AES_OP_TIMEOUT_US)) {
		ret = -ETIMEDOUT;
	}
	if (ret == EFTOK) {
		reg = readl(&AES_REGS[hib].SYSCONFIG) &
		      AES_SYSCONFIG_AUTOIDLE_MASK;
		if (ctx->kek_options == AES_KEK_OPTIONS_KEK_DIRECT) {
			/*
			 * Enable KEK mode in SYSCONFIG
			 * TODO: other KEK modes
			 */
			reg |= ((u32) AES_SYSCONFIG_DIRECTBUSEN_DIRECT <<
				AES_SYSCONFIG_DIRECTBUSEN_SHIFT);
		}
		writel(&AES_REGS[hib].SYSCONFIG, reg);
		reg = 0;

		reg |= (RD_FIELD(ctx->op_key_size, AES_OP_DIRECTION) <<
			AES_CTRL_DIRECTION_SHIFT);
		reg |= (RD_FIELD(ctx->op_key_size, AES_OP_KEY_SIZE) <<
			AES_CTRL_KEY_SIZE_SHIFT);

		switch (ctx->mode) {
		case AES_MODE_ECB:
			break;
		case AES_MODE_CBC:
			reg |= ((u32) AES_CTRL_MODE_CBC <<
				AES_CTRL_MODE_SHIFT);
			break;
		case AES_MODE_ICM:
			reg |= ((u32) AES_CTRL_ICM_ICM << AES_CTRL_ICM_SHIFT);
			break;
		case AES_MODE_CFB:
			reg |= ((u32) AES_CTRL_CFB_CFB << AES_CTRL_CFB_SHIFT);
			break;
		case AES_MODE_CTR:
			reg |= ((u32) AES_CTRL_CTR_CTR << AES_CTRL_CTR_SHIFT);
			reg |= (((u32) ctx->ctr_width) <<
				AES_CTRL_CTR_WIDTH_SHIFT);
			break;
		case AES_MODE_CMAC:
			reg |= ((u32) AES_CTRL_CBCMAC_CBCMAC <<
				AES_CTRL_CBCMAC_SHIFT);
			break;
		case AES_MODE_GCM:
			reg |= (((u32) ctx->gcm_mode) <<
				AES_CTRL_GCM_SHIFT);
			reg |= ((u32) AES_CTRL_CTR_CTR <<
				AES_CTRL_CTR_SHIFT);
			break;
		case AES_MODE_CCM:
			reg |= ((u32) AES_CTRL_CCM_CCM << AES_CTRL_CCM_SHIFT);
			reg |= ((u32) AES_CTRL_CTR_CTR << AES_CTRL_CTR_SHIFT);
			reg |= (((u32) ctx->ccm_l) <<
				AES_CTRL_CCM_L_SHIFT);
			reg |= ((u32) 7U << AES_CTRL_CCM_M_SHIFT);
			break;
		default:
			/*
			 * Must never come here because this internal
			 * function is always called with one of the
			 * valid modes
			 */
			break;
		}
		/* Need to save context for all modes except ECB */
		if (ctx->mode != AES_MODE_ECB) {
			reg |=
				((u32) AES_CTRL_SAVE_CONTEXT_MAX <<
				 AES_CTRL_SAVE_CONTEXT_SHIFT);
		}

		/*
		 * Write IV, TAG, key_1 and key_2 for modes where
		 * these are not
		 * used, the values must be zero initialized
		 */
		writel(&AES_REGS[hib].IV_IN_0, ctx->iv[0]);
		writel(&AES_REGS[hib].IV_IN_1, ctx->iv[1]);
		writel(&AES_REGS[hib].IV_IN_2, ctx->iv[2]);
		writel(&AES_REGS[hib].IV_IN_3, ctx->iv[3]);

		writel(&AES_REGS[hib].KEY1_0, ctx->key_1[0]);
		writel(&AES_REGS[hib].KEY1_1, ctx->key_1[1]);
		writel(&AES_REGS[hib].KEY1_2, ctx->key_1[2]);
		writel(&AES_REGS[hib].KEY1_3, ctx->key_1[3]);
		writel(&AES_REGS[hib].KEY1_4, ctx->key_1[4]);
		writel(&AES_REGS[hib].KEY1_5, ctx->key_1[5]);
		writel(&AES_REGS[hib].KEY1_6, ctx->key_1[6]);
		writel(&AES_REGS[hib].KEY1_7, ctx->key_1[7]);

		writel(&AES_REGS[hib].KEY2_0, ctx->key_2[0]);
		writel(&AES_REGS[hib].KEY2_1, ctx->key_2[1]);
		writel(&AES_REGS[hib].KEY2_2, ctx->key_2[2]);
		writel(&AES_REGS[hib].KEY2_3, ctx->key_2[3]);
		writel(&AES_REGS[hib].KEY2_4, ctx->key_2[4]);
		writel(&AES_REGS[hib].KEY2_5, ctx->key_2[5]);
		writel(&AES_REGS[hib].KEY2_6, ctx->key_2[6]);
		writel(&AES_REGS[hib].KEY2_7, ctx->key_2[7]);

		writel(&AES_REGS[hib].CTRL, reg);

		/*
		 * Length registers are also write-only
		 */
		writel(&AES_REGS[hib].C_LENGTH_1, 0);
		if (ctx->fixed_clen) {
			writel(&AES_REGS[hib].C_LENGTH_0, ctx->fixed_clen);
		}
		if ((ctx->mode == AES_MODE_GCM) ||
		    (ctx->mode == AES_MODE_CCM)) {
			writel(&AES_REGS[hib].AUTH_LENGTH, ctx->aad_len);
		}
	}
	return ret;
}

/**
 * \brief Copy input data block into registers
 *
 * \param hib AES HIB allocated to the caller
 * \param input Input data to write into AES IP input registers
 *
 * \return EFTOK on success, errorcode otherwise
 */
static fterr aes_copy_input_block(u32 hib, const u8 input[AES_BLOCKLEN_BYTES])
{
	fterr ret = -ETIMEDOUT;

	/* Wait for input */
	if (reg_poll_timeout_us(&AES_REGS[hib].CTRL,
				AES_CTRL_INPUT_READY_MASK,
				(u32) 1U << AES_CTRL_INPUT_READY_SHIFT,
				AES_OP_TIMEOUT_US)) {
		/*
		 * Input registers are the same as output registers cannot
		 * readback verify
		 */
		if (IS_ALIGNED((u32) input, 4U)) {
			writel(&AES_REGS[hib].DATA_IN_0, ((u32 *) input)[0]);
			writel(&AES_REGS[hib].DATA_IN_1, ((u32 *) input)[1]);
			writel(&AES_REGS[hib].DATA_IN_2, ((u32 *) input)[2]);
			writel(&AES_REGS[hib].DATA_IN_3, ((u32 *) input)[3]);
		} else {
			writel(&AES_REGS[hib].DATA_IN_0,
			       aes_u8_to_u32(&input[0]));
			writel(&AES_REGS[hib].DATA_IN_1,
			       aes_u8_to_u32(&input[4]));
			writel(&AES_REGS[hib].DATA_IN_2,
			       aes_u8_to_u32(&input[8]));
			writel(&AES_REGS[hib].DATA_IN_3,
			       aes_u8_to_u32(&input[12]));
		}
		ret = EFTOK;
	}
	return ret;
}

/**
 * \brief Copy output data block from registers
 *
 * \param hib AES HIB allocated to the caller
 * \param output Output data to write into data read from AES output registers
 *
 * \return EFTOK on success, errorcode otherwise
 */
static fterr aes_copy_output_block(u32 hib, u8 output[AES_BLOCKLEN_BYTES])
{
	fterr ret = -ETIMEDOUT;

	/* Wait for output */
	if (reg_poll_timeout_us(&AES_REGS[hib].CTRL,
				AES_CTRL_OUTPUT_READY_MASK,
				(u32) 1U << AES_CTRL_OUTPUT_READY_SHIFT,
				AES_OP_TIMEOUT_US)) {
		if (IS_ALIGNED((u32) output, 4U)) {
			((u32 *) output)[0] = readl(&AES_REGS[hib].DATA_IN_0);
			((u32 *) output)[1] = readl(&AES_REGS[hib].DATA_IN_1);
			((u32 *) output)[2] = readl(&AES_REGS[hib].DATA_IN_2);
			((u32 *) output)[3] = readl(&AES_REGS[hib].DATA_IN_3);
		} else {
			aes_u32_to_u8(readl(&AES_REGS[hib].DATA_IN_0),
				      &output[0]);
			aes_u32_to_u8(readl(&AES_REGS[hib].DATA_IN_1),
				      &output[4]);
			aes_u32_to_u8(readl(&AES_REGS[hib].DATA_IN_2),
				      &output[8]);
			aes_u32_to_u8(readl(&AES_REGS[hib].DATA_IN_3),
				      &output[12]);
		}
		ret = EFTOK;
	}
	return ret;
}

/**
 * \brief Save partial input data in a internal buffer
 *
 * \param ctx AES driver context
 * \param in Input residual data after consuming data in block length chunks
 * \param in_len Length of input data
 */
static void aes_append_to_rdata(struct aes_ctx *ctx,
				const u8 *in, u32 in_len)
{
	memcpy(((u8 *) ctx->rdata) + ctx->rdata_len, in, in_len);
	ctx->rdata_len += in_len;
}

/**
 * \brief Internal function to process data in a AES context
 *
 * \param hib AES HIB allocated to the caller
 * \param ctx AES driver context
 * \param in Input data to process
 * \param in_len Length of input data
 * \param out Output pointer to write the processed data
 * \param out_len Length of output written (output)
 *
 * \return EFTOK on success, errorcode otherwise
 */
static fterr aes_process(u32 hib, struct aes_ctx *ctx,
			 const u8 *in, u32 in_len, u8 *out,
			 u32 *out_len)
{
	fterr ret;
	u32 len;
	const u8 *input;

	len = in_len + ctx->rdata_len;

	/* Set C_LENGTH  */
	if (ctx->fixed_clen == 0U) {
		writel(&AES_REGS[hib].C_LENGTH_0, AES_BLOCK_ALIGN(len));
	}

	if (out_len) {
		*out_len = AES_BLOCK_ALIGN(len);
	}

	while (len >= AES_BLOCKLEN_BYTES) {
		if (ctx->rdata_len) {
			memcpy(((u8 *) ctx->rdata) + ctx->rdata_len, in,
			       AES_BLOCKLEN_BYTES - ctx->rdata_len);
			in += (AES_BLOCKLEN_BYTES - ctx->rdata_len);
			ctx->rdata_len = 0;
			input = (u8 *) ctx->rdata;
		} else {
			input = in;
			in += AES_BLOCKLEN_BYTES;
		}
		ret = aes_copy_input_block(hib, input);
		if (ret != EFTOK) {
			break;
		}
		if (out) {
			ret = aes_copy_output_block(hib, out);
			if (ret != EFTOK) {
				break;
			}
			out += AES_BLOCKLEN_BYTES;
		}
		len -= AES_BLOCKLEN_BYTES;
	}
	if (len < AES_BLOCKLEN_BYTES) {
		if (len > 0U) {
			memcpy(((u8 *) ctx->rdata), in, len);
			ctx->rdata_len = len;
		}
		ret = EFTOK;
	}
	return ret;
}

/**
 * \brief Internal function to process any residual data after
 *        all processing is done
 *
 * \param hib AES HIB allocated to the caller
 * \param ctx AES driver context
 * \param out Output pointer to write the processed data
 * \param out_len Length of output written (output)
 *
 * \return EFTOK on success, errorcode otherwise
 */
static fterr aes_process_rdata(u32 hib, struct aes_ctx *ctx,
			       u8 *out, u32 *out_len)
{
	fterr ret;
	u32 i;
	u8 tmp[AES_BLOCKLEN_BYTES];

	while (ctx->rdata_len > 0U) {
		if (ctx->mode == AES_MODE_CMAC) {
			/* Apply padding - binary 1 followed by zeros */
			((u8 *) ctx->rdata)[ctx->rdata_len] = 0x80U;
			ctx->rdata_len++;
		}
		/* Apply padding of zeros */
		for (i = ctx->rdata_len; i < AES_BLOCKLEN_BYTES; i++) {
			((u8 *) ctx->rdata)[i] = 0U;
		}

		if (ctx->fixed_clen == 0U) {
			writel(&AES_REGS[hib].C_LENGTH_0, AES_BLOCKLEN_BYTES);
		}

		ret = aes_copy_input_block(hib, (u8 *) ctx->rdata);
		if (ret != EFTOK) {
			break;
		}
		if (out) {
			ret = aes_copy_output_block(hib, tmp);
			if (ret != EFTOK) {
				break;
			}
			for (i = 0; i < ctx->rdata_len; i++) {
				out[i] = tmp[i];
			}
		}
		if (out_len) {
			*out_len = ctx->rdata_len;
		}
		ctx->rdata_len = 0U;
	}
	if (ctx->rdata_len == 0U) {
		ret = EFTOK;
	}
	return ret;
}

fterr aes_init(struct aes_ctx *ctx)
{
	fterr ret = EFTOK;

	if ((ctx->mode != AES_MODE_ECB) &&
	    (ctx->mode != AES_MODE_CBC) &&
	    (ctx->mode != AES_MODE_ICM) &&
	    (ctx->mode != AES_MODE_CFB) &&
	    (ctx->mode != AES_MODE_CTR)) {
		ret = -EINVAL;
	}

	ctx->rdata_len = 0U;
	ctx->fixed_clen = 0U;

	return ret;
}

fterr aes_update(struct aes_ctx *ctx, const u8 *in, u32 in_len,
		 u8 *out, u32 *out_len)
{
	fterr ret = EFTOK;
	u32 hib;

	/* Enough data to process? */
	if ((in_len + ctx->rdata_len) >= AES_BLOCKLEN_BYTES) {
		hib = aes_get_hib(ctx);
		ret = aes_restore_context(hib, ctx);
		if (ret == EFTOK) {
			ret = aes_process(hib, ctx, in, in_len,
					  out, out_len);
		}
		if (ret == EFTOK) {
			ret = aes_save_context(hib, ctx);
		}
		aes_release_hib(hib);
	} else {
		aes_append_to_rdata(ctx, in, in_len);
		*out_len = 0U;
	}

	return ret;
}

fterr aes_final(struct aes_ctx *ctx, u8 *out, u32 *out_len)
{
	fterr ret = EFTOK;
	u32 hib;

	if (ctx->rdata_len) {
		hib = aes_get_hib(ctx);
		ret = aes_restore_context(hib, ctx);
		if (ret == EFTOK) {
			ret = aes_process_rdata(hib, ctx, out, out_len);
		}
		if (ret == EFTOK) {
			ret = aes_save_context(hib, ctx);
		}
		aes_release_hib(hib);
	}
	return ret;
}

fterr aes_mac_oneshot(struct aes_ctx *ctx, const u8 *in, u32 in_len)
{
	u32 hib;
	u32 tmp[AES_BLOCKLEN_WORDS];
	u32 len;
	fterr ret = -EINVAL;

	hib = aes_get_hib(ctx);

	if (ctx->mode == AES_MODE_CMAC) {
		/* Pre-processong for AES CMAC operation, as described in
		 * NIST SP 800-38B */
		/* Generate subkeys, k1 and k2 */
		memset(tmp, 0, sizeof(tmp));

		ctx->op_key_size |= AES_OP_ENCRYPT;
		ctx->mode = AES_MODE_ECB;

		ret = aes_init(ctx);

		if (ret == EFTOK) {
			ret = aes_restore_context(hib, ctx);
		}

		if (ret == EFTOK) {
			ret = aes_process(hib, ctx, (const u8 *) tmp,
					  AES_BLOCKLEN_BYTES,
					  (u8 *) ctx->key_2, &len);
		}
		if (ret == EFTOK) {
			aes_cmac_shift((u8 *) ctx->key_2);

			memcpy(&ctx->key_2[AES_BLOCKLEN_WORDS], &ctx->key_2[0],
			       AES_BLOCKLEN_BYTES);

			aes_cmac_shift((u8 *) &ctx->key_2[
					       AES_BLOCKLEN_WORDS]);

			ctx->mode = AES_MODE_CMAC;
			ctx->rdata_len = 0U;
			ctx->fixed_clen = in_len;

			do {
				ret = aes_restore_context(hib, ctx);
				if (ret != EFTOK) {
					break;
				}
				if (in_len >= AES_BLOCKLEN_BYTES) {
					ret = aes_process(hib, ctx, in, in_len,
							  NULL, NULL);
					if (ret != EFTOK) {
						break;
					}
				} else {
					aes_append_to_rdata(ctx, in, in_len);
				}

				ret = aes_process_rdata(hib, ctx, NULL, NULL);
				if (ret != EFTOK) {
					break;
				}

				ret = aes_read_tag(hib, ctx);
				if (ret != EFTOK) {
					break;
				}
			} while (0);
		}
	}
	aes_release_hib(hib);
	return ret;
}

/**
 * \brief Authenticated encryption parameter validation
 *
 * \param ctx AES driver context
 * \param iv_len Length of IV for GCM, nonce for CCM, populated in ctx->iv
 * \param aad_len Additional authentication data length
 *
 * \return EFTOK on success, errorcode otherwise
 */
static fterr aes_aenc_validate(const struct aes_ctx *ctx, u32 iv_len,
			       u32 aad_len)
{
	fterr ret = EFTOK;

	if (ctx->mode == AES_MODE_GCM) {
		if (iv_len != 12U) {
			ret = -EINVAL;
		}
	} else if (ctx->mode == AES_MODE_CCM) {
		if ((iv_len > 13U) || (iv_len < 7U)) {
			ret = -EINVAL;
		} else if (aad_len > 0xff00U) {
			/* Hardware limitation according to the spec */
			ret = -EINVAL;
		}
	} else {
		ret = -EINVAL;
	}
	return ret;
}

fterr aes_aenc_oneshot(struct aes_ctx *ctx, u32 iv_len, const u8 *aad,
		       u32 aad_len, const u8 *in, u32 in_len,
		       u8 *out, u32 *outlen)
{
	fterr ret;

	u32 hib, i, res_outlen;
	u8 *ivbptr;

	ret = aes_aenc_validate(ctx, iv_len, aad_len);
	if (ret == EFTOK) {
		ivbptr = (u8 *) &ctx->iv[0];
		for (i = iv_len; i < 15U; i++) {
			ivbptr[i] = 0U;
		}
		ivbptr[i] = (ctx->mode == AES_MODE_GCM) ? 1U : 0U;

		if (ctx->mode == AES_MODE_GCM) {
			/* TODO: Other GCM modes */
			ctx->gcm_mode = AES_CTRL_GCM_GCM11;
		} else if (ctx->mode == AES_MODE_CCM) {
			/*
			 * First byte of IV in CCM has a value computed here,
			 * so shift the user provided iv by 1 byte
			 */
			for (i = iv_len; i > 0U; i--) {
				ivbptr[i] = ivbptr[i - 1U];
			}
			ctx->ccm_l = (u8) (14U - iv_len);
			ivbptr[0] = ctx->ccm_l;
		}
		ctx->rdata_len = 0U;
		ctx->fixed_clen = in_len;
		ctx->aad_len = aad_len;

		hib = aes_get_hib(ctx);

		do {
			ret = aes_restore_context(hib, ctx);
			if (ret != EFTOK) {
				break;
			}

			if (aad_len) {
				/* Process AAD data first */
				if (aad_len >= AES_BLOCKLEN_BYTES) {
					ret = aes_process(hib, ctx, aad,
							  aad_len, NULL, NULL);
					if (ret != EFTOK) {
						break;
					}
				} else {
					aes_append_to_rdata(ctx, aad, aad_len);
				}
				ret = aes_process_rdata(hib, ctx, NULL, NULL);
				if (ret != EFTOK) {
					break;
				}
			}

			/* Process input data next */
			if (in_len >= AES_BLOCKLEN_BYTES) {
				ret = aes_process(hib, ctx, in, in_len, out,
						  outlen);
				if (ret != EFTOK) {
					break;
				}
				out += *outlen;
			} else {
				aes_append_to_rdata(ctx, in, in_len);
			}
			res_outlen = 0U;
			ret = aes_process_rdata(hib, ctx, out, &res_outlen);
			if (ret != EFTOK) {
				break;
			}
			*outlen += res_outlen;

			ret = aes_read_tag(hib, ctx);
			if (ret != EFTOK) {
				break;
			}

			aes_release_hib(hib);
		} while (0);

		if (ctx->mode == AES_MODE_CCM) {
			/*
			 * Shift back the user provided IV same as before
			 */
			for (i = 0U; i < (iv_len - 1U); i++) {
				ivbptr[i] = ivbptr[i + 1U];
			}
		}
	}
	return ret;
}

fterr aes_oneshot(struct aes_ctx *ctx, const u8 *in,
		  u32 in_len, u8 *out, u32 *outlen)
{
	u32 hib, res_outlen;
	fterr ret;

	hib = aes_get_hib(ctx);

	ret = aes_init(ctx);
	if (ret == EFTOK) {
		ret = aes_restore_context(hib, ctx);
	}
	if (ret == EFTOK) {
		do {
			if (in_len >= AES_BLOCKLEN_BYTES) {
				ret = aes_process(hib, ctx, in, in_len, out,
						  outlen);
				if (ret != EFTOK) {
					break;
				}
				out += *outlen;
			} else {
				aes_append_to_rdata(ctx, in, in_len);
			}

			res_outlen = 0U;
			ret = aes_process_rdata(hib, ctx, out, &res_outlen);
			if (ret != EFTOK) {
				break;
			}
			*outlen += res_outlen;

			ret = aes_save_context(hib, ctx);
			if (ret != EFTOK) {
				break;
			}
		} while (0);
	}
	aes_release_hib(hib);
	return ret;
}
