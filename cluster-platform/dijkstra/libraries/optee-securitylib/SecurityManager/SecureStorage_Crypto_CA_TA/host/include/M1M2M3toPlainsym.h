#ifndef M1M2M3_TO_PLAINSYM_H
#define M1M2M3_TO_PLAINSYM_H

#include <openssl/bio.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/cmac.h>
#include <openssl/rsa.h>
#include <openssl/bn.h>
#include <openssl/evp.h>
#include <string.h>

/* === Key & Constant Definitions === */

#define AES_128_KEY_SIZE 16
#define AES_IV_SIZE 16
#define BLKSIZE 16

#ifndef M2_KEY_SIZE
#define M2_KEY_SIZE 32
#endif

#define AUTH_KEY_ID_PROTOTYPE  0x01
#define AUTH_KEY_ID_PRODUCTION 0x06

extern unsigned char initialization_vector[AES_IV_SIZE];

// Example authentication key (16 bytes of 0x00)
static const unsigned char key_auth[AES_128_KEY_SIZE] = {
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

// Prototype Master Key (0x01s)
static const unsigned char key_auth_proto[AES_128_KEY_SIZE] = {
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11
};

// Production Master Key (0xFFs)
static const unsigned char key_auth_prod[AES_128_KEY_SIZE] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

// Encrypted update key chunks
static const unsigned char KEY_UPDATE_ENC_C_01_to_10[AES_128_KEY_SIZE] __attribute__((unused)) = {
    0x01, 0x01, 0x53, 0x48, 0x45, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0
};

static const unsigned char KEY_UPDATE_ENC_C_11_to_20[AES_128_KEY_SIZE] __attribute__((unused)) = {
    0x01, 0x81, 0x53, 0x48, 0x45, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0
};

// Final plain key after decryption
static const unsigned char plainkey[AES_128_KEY_SIZE] = {
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF
};

// Update key for encryption step
static const unsigned char KEY_3_UPDATE[M2_KEY_SIZE] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
    0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
    0xFF, 0xFF, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
    0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF
};

/* === Function Prototypes === */

int32_t encrypt_aes_128_ecb(const unsigned char* plaintext, int plaintext_len, const unsigned char* key, unsigned char* ciphertext, int use_padding);
int32_t aes_mp(const unsigned char* input, size_t input_length, unsigned char* output);
int32_t encrypt_aes_128_cbc(const unsigned char* plaintext, int plaintext_len, const unsigned char* key, const unsigned char* iv, unsigned char* ciphertext, int use_padding);
int32_t decrypt_aes_128_cbc(const unsigned char* ciphertext, int ciphertext_len, const unsigned char* key, const unsigned char* iv, unsigned char* plaintext, int use_padding);
int32_t decrypt_aes_128_ecb(const unsigned char* ciphertext, int ciphertext_len, const unsigned char* key, unsigned char* plaintext, int use_padding);

#endif // M1M2M3_TO_PLAINSYM_H