/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2025. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "SecurityCryptoHandler.h" 

int main() {
    uint8_t key[32]; // AES-256 key size
    uint8_t iv[16]; // Initialization vector for AES
    uint8_t plaintext[] = "Hello, visteon! This is a plaintext message.";
    uint8_t ciphertext[128]; // Buffer to hold the ciphertext
    uint8_t decryptedtext[128]; // Buffer for decrypted text
    size_t ciphertextLen, decryptedtextLen;
    uint8_t hash[32]; // Hash buffer for SHA-256
    uint32_t hashLen;
    int32_t loopiterater;

    // Generate a random key
    if (GenerateRandomKey(key, sizeof(key)) != 0) {
        printf("Failed to generate random key.\n");
        return 1;
    } else {
        printf("Random key generated successfully: ");
        for (loopiterater = 0; loopiterater < (int32_t)sizeof(key); loopiterater++) {
            printf("%02x", key[loopiterater]);
        }
        printf("\n");
    }

    // Generate a randomkey
    if (GenerateRandomKey(iv, sizeof(iv)) != 0) {
        printf("Failed to generate random IV.\n");
        return 1;
    }

    // Encrypt the plaintext
    if (AesEncrypt(key, plaintext, strlen((char *)plaintext), ciphertext, &ciphertextLen, iv) != 0) {
        printf("Encryption failed.\n");
        return 1;
    } else {
        printf("Encryption successful. Ciphertext length: %zu bytes\n", ciphertextLen);
    }

    // Decrypt the ciphertext
    if (AesDecrypt(key, ciphertext, ciphertextLen, decryptedtext, &decryptedtextLen, iv) != 0) {
        printf("Decryption failed.\n");
        return 1;
    } else {
        decryptedtext[decryptedtextLen] = '\0'; // Null-terminate the decrypted string
        printf("Decryption successful. Decrypted text: %s\n", decryptedtext);
    }

    // Calculate SHA-256 hash of the original plaintext
    if (Sha256Hash(plaintext, strlen((char *)plaintext), hash, &hashLen) != 0) {
        printf("Hashing failed.\n");
        return 1;
    } else {
        printf("SHA-256 hash computed successfully.\n");
        printf("Hash (in hex): ");
        for (loopiterater = 0; loopiterater < (int32_t)hashLen; loopiterater++) {
            printf("%02x", hash[loopiterater]);
        }
        printf("\n");
    }

    return 0;
}