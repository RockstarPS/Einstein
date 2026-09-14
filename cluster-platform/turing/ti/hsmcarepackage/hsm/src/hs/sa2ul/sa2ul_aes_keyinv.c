/*
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_aes_keyinv.c
 *
 * \brief Key inversion helper function for SA2_UL AES
 *
 * This code is based on public domain code provided by OpenSSL.
 *
 * The following source was taken from cryptographic software written by the
 * below authors and has been modified and adapted by TI
 */
/*
 *****************************************************************************
 * rijndael-alg-fst.c
 *
 * @version 3.0 (December 2000)
 *
 * Optimised ANSI C code for the Rijndael cipher (now AES)
 *
 * @author Vincent Rijmen <vincent.rijmen@esat.kuleuven.ac.be>
 * @author Antoon Bosselaers <antoon.bosselaers@esat.kuleuven.ac.be>
 * @author Paulo Barreto <paulo.barreto@terra.com.br>
 *
 * This code is hereby placed in the public domain.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include "sa2ul_aes_keyinv.h"

/******************************************************************************
 * FUNCTION PURPOSE:  AES Encoder Implementation
 ******************************************************************************
 *
 * DESCRIPTION: Core AES Encryption Algorithm Implementation
 *
 * EXTERNAL COMPILE TIME FLAGS:
 *
 *              aes_LARGE_ENC_TABLE:
 *                           If we want to support large encryption table
 *
 * The following source was taken from cryptographic software written by the
 * below authors and has been modified and adapted by TI
 *****************************************************************************
 * rijndael-alg-fst.c
 *
 * @version 3.0 (December 2000)
 *
 * Optimised ANSI C code for the Rijndael cipher (now AES)
 *
 * @author Vincent Rijmen <vincent.rijmen@esat.kuleuven.ac.be>
 * @author Antoon Bosselaers <antoon.bosselaers@esat.kuleuven.ac.be>
 * @author Paulo Barreto <paulo.barreto@terra.com.br>
 *
 * This code is hereby placed in the public domain.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

const u32 aesTe4[] = {
	0x63636363U, 0x7c7c7c7cU, 0x77777777U, 0x7b7b7b7bU,
	0xf2f2f2f2U, 0x6b6b6b6bU, 0x6f6f6f6fU, 0xc5c5c5c5U,
	0x30303030U, 0x01010101U, 0x67676767U, 0x2b2b2b2bU,
	0xfefefefeU, 0xd7d7d7d7U, 0xababababU, 0x76767676U,
	0xcacacacaU, 0x82828282U, 0xc9c9c9c9U, 0x7d7d7d7dU,
	0xfafafafaU, 0x59595959U, 0x47474747U, 0xf0f0f0f0U,
	0xadadadadU, 0xd4d4d4d4U, 0xa2a2a2a2U, 0xafafafafU,
	0x9c9c9c9cU, 0xa4a4a4a4U, 0x72727272U, 0xc0c0c0c0U,
	0xb7b7b7b7U, 0xfdfdfdfdU, 0x93939393U, 0x26262626U,
	0x36363636U, 0x3f3f3f3fU, 0xf7f7f7f7U, 0xccccccccU,
	0x34343434U, 0xa5a5a5a5U, 0xe5e5e5e5U, 0xf1f1f1f1U,
	0x71717171U, 0xd8d8d8d8U, 0x31313131U, 0x15151515U,
	0x04040404U, 0xc7c7c7c7U, 0x23232323U, 0xc3c3c3c3U,
	0x18181818U, 0x96969696U, 0x05050505U, 0x9a9a9a9aU,
	0x07070707U, 0x12121212U, 0x80808080U, 0xe2e2e2e2U,
	0xebebebebU, 0x27272727U, 0xb2b2b2b2U, 0x75757575U,
	0x09090909U, 0x83838383U, 0x2c2c2c2cU, 0x1a1a1a1aU,
	0x1b1b1b1bU, 0x6e6e6e6eU, 0x5a5a5a5aU, 0xa0a0a0a0U,
	0x52525252U, 0x3b3b3b3bU, 0xd6d6d6d6U, 0xb3b3b3b3U,
	0x29292929U, 0xe3e3e3e3U, 0x2f2f2f2fU, 0x84848484U,
	0x53535353U, 0xd1d1d1d1U, 0x00000000U, 0xededededU,
	0x20202020U, 0xfcfcfcfcU, 0xb1b1b1b1U, 0x5b5b5b5bU,
	0x6a6a6a6aU, 0xcbcbcbcbU, 0xbebebebeU, 0x39393939U,
	0x4a4a4a4aU, 0x4c4c4c4cU, 0x58585858U, 0xcfcfcfcfU,
	0xd0d0d0d0U, 0xefefefefU, 0xaaaaaaaaU, 0xfbfbfbfbU,
	0x43434343U, 0x4d4d4d4dU, 0x33333333U, 0x85858585U,
	0x45454545U, 0xf9f9f9f9U, 0x02020202U, 0x7f7f7f7fU,
	0x50505050U, 0x3c3c3c3cU, 0x9f9f9f9fU, 0xa8a8a8a8U,
	0x51515151U, 0xa3a3a3a3U, 0x40404040U, 0x8f8f8f8fU,
	0x92929292U, 0x9d9d9d9dU, 0x38383838U, 0xf5f5f5f5U,
	0xbcbcbcbcU, 0xb6b6b6b6U, 0xdadadadaU, 0x21212121U,
	0x10101010U, 0xffffffffU, 0xf3f3f3f3U, 0xd2d2d2d2U,
	0xcdcdcdcdU, 0x0c0c0c0cU, 0x13131313U, 0xececececU,
	0x5f5f5f5fU, 0x97979797U, 0x44444444U, 0x17171717U,
	0xc4c4c4c4U, 0xa7a7a7a7U, 0x7e7e7e7eU, 0x3d3d3d3dU,
	0x64646464U, 0x5d5d5d5dU, 0x19191919U, 0x73737373U,
	0x60606060U, 0x81818181U, 0x4f4f4f4fU, 0xdcdcdcdcU,
	0x22222222U, 0x2a2a2a2aU, 0x90909090U, 0x88888888U,
	0x46464646U, 0xeeeeeeeeU, 0xb8b8b8b8U, 0x14141414U,
	0xdedededeU, 0x5e5e5e5eU, 0x0b0b0b0bU, 0xdbdbdbdbU,
	0xe0e0e0e0U, 0x32323232U, 0x3a3a3a3aU, 0x0a0a0a0aU,
	0x49494949U, 0x06060606U, 0x24242424U, 0x5c5c5c5cU,
	0xc2c2c2c2U, 0xd3d3d3d3U, 0xacacacacU, 0x62626262U,
	0x91919191U, 0x95959595U, 0xe4e4e4e4U, 0x79797979U,
	0xe7e7e7e7U, 0xc8c8c8c8U, 0x37373737U, 0x6d6d6d6dU,
	0x8d8d8d8dU, 0xd5d5d5d5U, 0x4e4e4e4eU, 0xa9a9a9a9U,
	0x6c6c6c6cU, 0x56565656U, 0xf4f4f4f4U, 0xeaeaeaeaU,
	0x65656565U, 0x7a7a7a7aU, 0xaeaeaeaeU, 0x08080808U,
	0xbabababaU, 0x78787878U, 0x25252525U, 0x2e2e2e2eU,
	0x1c1c1c1cU, 0xa6a6a6a6U, 0xb4b4b4b4U, 0xc6c6c6c6U,
	0xe8e8e8e8U, 0xddddddddU, 0x74747474U, 0x1f1f1f1fU,
	0x4b4b4b4bU, 0xbdbdbdbdU, 0x8b8b8b8bU, 0x8a8a8a8aU,
	0x70707070U, 0x3e3e3e3eU, 0xb5b5b5b5U, 0x66666666U,
	0x48484848U, 0x03030303U, 0xf6f6f6f6U, 0x0e0e0e0eU,
	0x61616161U, 0x35353535U, 0x57575757U, 0xb9b9b9b9U,
	0x86868686U, 0xc1c1c1c1U, 0x1d1d1d1dU, 0x9e9e9e9eU,
	0xe1e1e1e1U, 0xf8f8f8f8U, 0x98989898U, 0x11111111U,
	0x69696969U, 0xd9d9d9d9U, 0x8e8e8e8eU, 0x94949494U,
	0x9b9b9b9bU, 0x1e1e1e1eU, 0x87878787U, 0xe9e9e9e9U,
	0xcecececeU, 0x55555555U, 0x28282828U, 0xdfdfdfdfU,
	0x8c8c8c8cU, 0xa1a1a1a1U, 0x89898989U, 0x0d0d0d0dU,
	0xbfbfbfbfU, 0xe6e6e6e6U, 0x42424242U, 0x68686868U,
	0x41414141U, 0x99999999U, 0x2d2d2d2dU, 0x0f0f0f0fU,
	0xb0b0b0b0U, 0x54545454U, 0xbbbbbbbbU, 0x16161616U
};

/* for 128-bit blocks, AES never uses more than 10 rcon values */
static const u32 rcon[] =
{
	0x01000000, 0x02000000, 0x04000000, 0x08000000,
	0x10000000, 0x20000000, 0x40000000, 0x80000000,
	0x1B000000, 0x36000000
};

/******************************************************************************
  * FUNCTION: aesKeyExpandEnc
  * PURPOSE: Expand the cipher key into the encryption key schedule
  ******************************************************************************/
static s32 aesKeyExpandEnc(u32 *rk, u32 cipherKey[], s32 keyBits)
{
	s32 i = 0;
	u32 temp;
	u32 *Te4 = (u32 *) &aesTe4[0];

	/* Caution: cipher key is little Endian */
	rk[0] = cipherKey[0];
	rk[1] = cipherKey[1];
	rk[2] = cipherKey[2];
	rk[3] = cipherKey[3];

	if (keyBits == 128) {
		for (;;) {
			temp = rk[3];
			rk[4] = rk[0] ^
				(Te4[(temp >> 16U) & 0xffU] & 0xff000000U) ^
				(Te4[(temp >> 8U) & 0xffU] & 0x00ff0000U) ^
				(Te4[(temp) & 0xffU] & 0x0000ff00U) ^
				(Te4[(temp >> 24U)] & 0x000000ffU) ^
				rcon[i];
			rk[5] = rk[1] ^ rk[4];
			rk[6] = rk[2] ^ rk[5];
			rk[7] = rk[3] ^ rk[6];
			if (++i == 10) {
				return 10;   /* Nr is fixed and set to 10 */
			}
			rk += 4;
		}
	}

	/* Cipher key expansion for keyBits > 128 */
	rk[4] = cipherKey[4];
	rk[5] = cipherKey[5];
	if (keyBits == 192) {
		for (;;) {
			temp = rk[5];
			rk[6] = rk[0] ^
				(Te4[(temp >> 16U) & 0xffU] & 0xff000000U) ^
				(Te4[(temp >> 8U) & 0xffU] & 0x00ff0000U) ^
				(Te4[(temp) & 0xffU] & 0x0000ff00U) ^
				(Te4[(temp >> 24U)] & 0x000000ffU) ^
				rcon[i];
			rk[7] = rk[1] ^ rk[6];
			rk[8] = rk[2] ^ rk[7];
			rk[9] = rk[3] ^ rk[8];
			if (++i == 8) {
				return 12;
			}
			rk[10] = rk[4] ^ rk[9];
			rk[11] = rk[5] ^ rk[10];
			rk += 6;
		}
	}

	/* Cipher key expansion for keyBits > 192 */
	rk[6] = cipherKey[6];
	rk[7] = cipherKey[7];
	if (keyBits == 256) {
		for (;;) {
			temp = rk[7];
			rk[8] = rk[0] ^
				(Te4[(temp >> 16U) & 0xffU] & 0xff000000U) ^
				(Te4[(temp >> 8U) & 0xffU] & 0x00ff0000U) ^
				(Te4[(temp) & 0xffU] & 0x0000ff00U) ^
				(Te4[(temp >> 24U)] & 0x000000ffU) ^
				rcon[i];
			rk[9] = rk[1] ^ rk[8];
			rk[10] = rk[2] ^ rk[9];
			rk[11] = rk[3] ^ rk[10];

			temp = rk[11];
			rk[12] = rk[4] ^
				 (Te4[(temp >> 24U)] & 0xff000000U) ^
				 (Te4[(temp >> 16U) & 0xffU] & 0x00ff0000U) ^
				 (Te4[(temp >> 8U) & 0xffU] & 0x0000ff00U) ^
				 (Te4[(temp) & 0xffU] & 0x000000ffU);
			rk[13] = rk[5] ^ rk[12];
			rk[14] = rk[6] ^ rk[13];
			rk[15] = rk[7] ^ rk[14];

			rk += 8;
			if (++i == 7) {
				return 15;
			}
		}
	}

	return 0;
}

/******************************************************************************
  * FUNCTION: aesInvKey
  * PURPOSE: Derive the inverse key used at AES-CBC decryption operation
  ******************************************************************************/
void sa2ul_aes_invkey(u32 invKey[], u32 cipherKey[], s32 keyBits, ftbool enableCm)
{
	s32 i = 0;
	u32 roundKey[64];
	u32 *rk = &roundKey[0];
	u32 temp;
	u32 *Te4 = (u32 *) &aesTe4[0];
	u32 *pInvRK = &roundKey[40];
	s32 keySize = keyBits >> (s32) 5;  /* Key size in 32-bit words */

	if (keyBits == 128) {
		aesKeyExpandEnc(rk, cipherKey, 128);
	}

	/* Cipher key expansion for keyBits > 128 */
	if (keyBits == 192) {
		/* Input the cipher key as big Endian byte stream */
		rk[0] = cipherKey[0];
		rk[1] = cipherKey[1];
		rk[2] = cipherKey[2];
		rk[3] = cipherKey[3];
		rk[4] = cipherKey[4];
		rk[5] = cipherKey[5];
		for (;;) {
			temp = rk[5];
			rk[6] = rk[0] ^
				(Te4[(temp >> 16U) & 0xffU] & 0xff000000U) ^
				(Te4[(temp >> 8U) & 0xffU] & 0x00ff0000U) ^
				(Te4[(temp) & 0xffU] & 0x0000ff00U) ^
				(Te4[(temp >> 24U)] & 0x000000ffU) ^
				rcon[i];
			rk[7] = rk[1] ^ rk[6];
			rk[8] = rk[2] ^ rk[7];
			rk[9] = rk[3] ^ rk[8];
			rk[10] = rk[4] ^ rk[9];
			rk[11] = rk[5] ^ rk[10];
			if (++i == 8) {
				break;
			}
			rk += 6;
		}
		pInvRK = &roundKey[48];
	}

	/* Cipher key expansion for keyBits > 192 */
	if (keyBits == 256) {
		aesKeyExpandEnc(rk, cipherKey, 256);
		/* If counter measures are enabled, SA2UL needs an extra round of key inversion */
		if (ft_is_true(enableCm)) {
			pInvRK = &roundKey[56]; /* Round 14 and 15 */
		} else {
			pInvRK = &roundKey[52]; /* Round 13 and 14 */
		}
	}


	/* Output the inverse key as little-endian */
	for (i = 0; i < keySize; i++) {
		invKey[i] = pInvRK[i];
	}
}
