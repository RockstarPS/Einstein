#ifndef SECURITY_CRYPTO_HANDLER_H
#define SECURITY_CRYPTO_HANDLER_H
#include <stddef.h>

/**
 * @brief Generates a random encryption key.
 *
 * @param key         Pointer to the buffer where the key will be stored (output).
 * @param keyLength   Length of the key in bytes (input).
 * @return            0 on success, -1 on failure.
 */
int32_t GenerateRandomKey(uint8_t *key_p8, size_t keyLength_u32);

/**
 * @brief Encrypts a plaintext message using AES-256-CBC encryption.
 *
 * @param key            Pointer to the AES encryption key (input).
 * @param plaintext      Pointer to the plaintext data to be encrypted (input).
 * @param plaintextLen   Length of the plaintext data in bytes (input).
 * @param ciphertext     Pointer to the output buffer where the encrypted data will be stored (output).
 * @param ciphertextLen  Pointer to an integer where the length of the ciphertext will be stored (output).
 * @return               0 on success, -1 on failure.
 */
int32_t AesEncrypt(const uint8_t *key_p8, const uint8_t *plaintext_p, size_t plaintextLen_u32, uint8_t *ciphertext_p, size_t *ciphertextLen_p, const uint8_t *iv_p8);

/**
 * @brief Decrypts an AES-encrypted ciphertext back into plaintext.
 *
 * @param key            Pointer to the AES decryption key (input).
 * @param ciphertext     Pointer to the ciphertext data to be decrypted (input).
 * @param ciphertextLen  Length of the ciphertext data in bytes (input).
 * @param plaintext      Pointer to the output buffer where the decrypted data will be stored (output).
 * @param plaintextLen   Pointer to an integer where the length of the decrypted data will be stored (output).
 * @return               0 on success, -1 on failure.
 */
int32_t AesDecrypt(const uint8_t *key_p8, const uint8_t *ciphertext_p, size_t ciphertextLen, uint8_t *plaintext_p, size_t *plaintextLen_p, const uint8_t *iv_p8);

/**
 * @brief Computes SHA-256 hash of the given data.
 *
 * @param data      Pointer to the input data (input).
 * @param dataLen   Length of the input data in bytes (input).
 * @param hash      Pointer to the output buffer where the hash will be stored (output).
 * @param hashLen   Pointer to the length of the computed hash (output).
 * @return          0 on success, -1 on failure.
 */
int32_t Sha256Hash(const uint8_t *data_p, size_t dataLen_u32, uint8_t *hash_p, uint32_t *hashLen_p);
#endif // SECURITY_CRYPTO_HANDLER_H
