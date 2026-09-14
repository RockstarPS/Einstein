/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
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
/*****************************************************************************
*  File Name         :  securitystorage_crypto_ca.c                          *
*  Module Short Name :  Securestorage and crypto                             *
*  Description       :  This file contains Crypto operations like encryption,*
*  decryption, sha computation and secure storage OPTEE client Implementation*
*                       		                                             *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* \authors
*          Name                     | CDSID     | Location                 | *
*          ------------------------ | --------- | ------------------------ | *
*          Vignesh Pandian          | vpandia1  | VTSC, Coimbatore, India  | *
*          Hema Srinivasan          | hsriniv5  | VTSC, Chennai, India     | *
*          Karnadas Praveen         | pkarnada  | VTSC, Bangalore, India     | *
* ---------------------------------------------------------------------------* 
*                                                                            *
******************************************************************************/

/*Refer the below included header file for interface and i/o parameter details*/

#include "SecurestorageCrypto_ca.h"
#include "M1M2M3toPlainsym.h"
#include "tee_client_api.h"
#include <sys/ioctl.h>
#include <linux/fs.h>
#include <fcntl.h>
#include <unistd.h>

#define KEY_LENGTH16_BYTE 16U
#define KEY_LENGTH32_BYTE 32U
/* IPSEC MACROS*/
#define IPSEC_BUFFER_SIZE         ((uint32_t)4096U)
//#define PROTOTYPE_KEY
//#define INTERNAL_DEV_KEY
#define CA_VERBOSE
#define M2_BLOB_NAME_SIZE    (15U)
#define M2_BLOB_NAME_LEN     (M2_BLOB_NAME_SIZE - 1U)

unsigned char initialization_vector[AES_IV_SIZE] = {
    0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U
};


#define SANITY_CHECK_POINTER_TYPE(a) ((NULL == (a)) || (NULL == (a)->data_U8P) || (0U == (a)->length_U32))

#define SANITY_CHECK_PUBLIC_KEY(a)                                                                                     \
    ((NULL == (a)) || (NULL == (a)->modulus_S.data_U8P) || (0U == (a)->modulus_S.length_U32) ||                       \
     (NULL == (a)->exponent_S.data_U8P) || (0U == (a)->exponent_S.length_U32))

#define SANITY_CHECK_PUBLIC_KEY_ECC(a)                                                                                     \
    ((NULL == (a)) || (NULL == (a)->Xcrd_S.data_U8P) || (0U == (a)->Xcrd_S.length_U32) ||                       \
     (NULL == (a)->Ycrd_S.data_U8P) || (0U == (a)->Ycrd_S.length_U32))

void prepare_tee_session_securestorage_crypto(struct TEE_resource_ctx *ctx)
{
	TEEC_UUID uuid = TA_CRYPTO_UUID_TI;
	uint32_t origin;
	TEEC_Result res;

	/* Initialize a context connecting us to the TEE */
	res = TEEC_InitializeContext(NULL, &ctx->ctx);
	if (res != TEEC_SUCCESS)
    {
		errx(1, "TEEC_InitializeContext failed with code 0x%x", res);
    }
    else
    {
	    /* Open a session with the TA */
	    res = TEEC_OpenSession(&ctx->ctx, &ctx->sess, &uuid,
	    		       TEEC_LOGIN_PUBLIC, NULL, NULL, &origin);
	    if (res != TEEC_SUCCESS){
	    	errx(1, "TEEC_Opensession failed with code 0x%x origin 0x%x",
	    		res, origin);
        }
    }
}

void terminate_tee_session_securestorage_crypto(struct TEE_resource_ctx *ctx)
{
	(void) TEEC_CloseSession(&ctx->sess);
	(void) TEEC_FinalizeContext(&ctx->ctx);
}

/*static void teec_err(TEEC_Result res, uint32_t eo, const char *str)
{
	errx(1, "%s: %#" PRIx32 " (error origin %#" PRIx32 ")", str, res, eo);
}*/

TEEC_Result SecureStorageCreateAndStore_CA(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size,  const ts_pointerType *enc_m1, const ts_pointerType *enc_m2, const ts_pointerType *enc_m3)
{
	TEEC_Operation op;
	uint32_t origin;
	TEEC_Result res = TEEC_ERROR_GENERIC;
	char *l_keyid;
	uint8_t K1[KEY_LENGTH16_BYTE] = {0U};
	uint8_t K1_input[KEY_LENGTH32_BYTE] = {0U}; //input from aes
	uint8_t decrypted_key[KEY_LENGTH32_BYTE] = {0U}; //Store decrypted key
	int32_t decrypted_len = 0;
    uint8_t m1_key_id = 0U;
    uint8_t auth_key_id = 0U;
    const uint8_t *selected_auth_key = NULL;
    TEEC_Result flag_check_res = TEEC_ERROR_ITEM_NOT_FOUND; // Prototype flag check result
    uint8_t chained_auth_key[KEY_LENGTH16_BYTE] = {0U}; // To store the existing key in case of key update
    uint8_t stored_m2[KEY_LENGTH32_BYTE] = {0U}; // To store M2 blob
    const uint8_t m2_blob_id[M2_BLOB_NAME_SIZE] = "Secure_M2_blob";

#ifdef CA_VERBOSE
	printf("\n Executing SecureStorageCreateAndStore_CA\n");
#endif

	if (((key_id && keyid_size) != 0U) &&
		(((enc_m1 && enc_m1->data_U8P) && enc_m1->length_U32) != 0U) &&
		(((enc_m2 && enc_m2->data_U8P) && enc_m2->length_U32) != 0U) &&
		(((enc_m3 && enc_m3->data_U8P) && enc_m3->length_U32) != 0U)){

		l_keyid = (char *) malloc(keyid_size);
        if(l_keyid == NULL)
        {
            //misra
        }
        else
        {
		    strcpy(l_keyid, key_id);
    		if (!l_keyid) {
    			printf("\nMemory allocation failed\n");
    		}
            else
            {
                (void)memset(&op, 0, sizeof(op));
                op.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
                op.params[0].tmpref.buffer = l_keyid;
                op.params[0].tmpref.size   = keyid_size;
                // Check Blob exsistence
                res = TEEC_InvokeCommand(&ctx->sess, TA_SECURE_STORAGE_CMD_SECUREBLOB_CHECK, &op, &origin);
                // Check Prototype flag exsistence
                if (access("/persist/prototype_key_flag", F_OK) == 0)
                {
                    flag_check_res = TEEC_SUCCESS;
                }
                else
                {
                    flag_check_res = TEEC_ERROR_ITEM_NOT_FOUND;
                }
                // Authentication key selection based of M1 AuthID which is the last byte of M1
                m1_key_id = enc_m1->data_U8P[enc_m1->length_U32 - 1];
                auth_key_id = (m1_key_id & 0x0FU);

                if (res == TEEC_SUCCESS) // Key already exists
                {
                    printf("\n[CA] Key already exists");

                    if (flag_check_res == TEEC_SUCCESS) // Prototype Flag already exist
                    {
                        if (auth_key_id == AUTH_KEY_ID_PRODUCTION)
                        {
                            printf("\n[CA] Production key update on Development board is allowed.\n");
                            selected_auth_key = key_auth_prod;
                        }
                        else
                        {
                            printf("\n[CA] REJECT - Development update is not allowed.\n");
                            res = TEEC_ERROR_GENERIC;
                            selected_auth_key = NULL;
                        }
                    }
                    else
                    {
                        printf("\n[CA] Prototype flag does not exists, Production key is written in the board\n");

                        if (auth_key_id == AUTH_KEY_ID_PROTOTYPE)
                        {
                            printf("\n[CA] REJECT - Cannot write a Development key (ID 1) onto a Production board. keyupdate not allowed.\n");
                            res = TEEC_ERROR_GENERIC;
                            selected_auth_key = NULL;
                        }

                        else
                        {
                            printf("\n[CA] Checking if the incoming key is different.\n");
                            (void)memset(&op, 0, sizeof(op));
                            op.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE);
                            op.params[0].tmpref.buffer = (void *)m2_blob_id;
                            op.params[0].tmpref.size = (uint32_t)M2_BLOB_NAME_LEN;
                            op.params[1].tmpref.buffer = stored_m2;
                            op.params[1].tmpref.size = KEY_LENGTH32_BYTE;

                            TEEC_Result m2_res = TEEC_InvokeCommand(&ctx->sess, TA_SECURE_STORAGE_CMD_READ_PEM_KEY, &op, &origin);

                            if (m2_res == TEEC_SUCCESS)
                            {
                                if (memcmp(stored_m2, enc_m2->data_U8P, KEY_LENGTH32_BYTE) == 0)
                                {
                                    (void)printf("\n[CA] REJECT - New Production key is identical to the stored key.\n");
                                    res = TEEC_ERROR_GENERIC;
                                    selected_auth_key = NULL;
                                }
                                else
                                {
                                    (void)printf("\n[CA] Production key update allowed. Proceeding with chained authentication.\n");
                                    (void)memset(&op, 0, sizeof(op));
                                    op.paramTypes = (uint32_t)TEEC_PARAM_TYPES((uint32_t)TEEC_MEMREF_TEMP_INPUT, (uint32_t)TEEC_MEMREF_TEMP_OUTPUT, (uint32_t)TEEC_NONE, (uint32_t)TEEC_NONE);
                                    op.params[0].tmpref.buffer = l_keyid;
                                    op.params[0].tmpref.size   = keyid_size;
                                    op.params[1].tmpref.buffer = chained_auth_key;
                                    op.params[1].tmpref.size   = KEY_LENGTH16_BYTE;

                                    // Invoking READ command to fetch the existing key
                                    res = TEEC_InvokeCommand(&ctx->sess, TA_SECURE_STORAGE_CMD_READ_PEM_KEY, &op, &origin);
                                    if (res == TEEC_SUCCESS)
                                    {
                                        printf("\n[CA] Successfully fetched the current key\n");
                                        selected_auth_key = chained_auth_key;
                                    }
                                    else
                                    {
                                        printf("\n[CA] Error: Failed to retrieve existing key (0x%x)\n", res);
                                        selected_auth_key = NULL;
                                    }
                                }
                            }
                            else
                            {
                                (void)printf("\n[CA] Error: Failed to read existing M2 blob (0x%x)\n", m2_res);
                                selected_auth_key = NULL;
                            }
                        }
                    }
                }
                else // First time key writing
                {
                    printf("\n[CA] First time key writing, M1 Key ID: 0x%x\n", auth_key_id);

                    if (auth_key_id == AUTH_KEY_ID_PROTOTYPE)
                    {
                        printf("\n[CA] Prototype key is used as authentication key, M1 Key ID: 0x%x\n", auth_key_id);
                        selected_auth_key = key_auth_proto;
                    }
                    else if (auth_key_id == AUTH_KEY_ID_PRODUCTION)
                    {
                        printf("\n[CA] Production key is used as authentication key, M1 Key ID: 0x%x\n", auth_key_id);
                        selected_auth_key = key_auth_prod;
                    }
                    else
                    {
                        printf("\n[CA] Invalid M1 Key ID: 0x%x\n", auth_key_id);
                        res = TEEC_ERROR_BAD_PARAMETERS;
                    }
                }
                if (selected_auth_key != NULL)
                {
                    if(memcpy(K1_input, selected_auth_key, KEY_LENGTH16_BYTE) == (K1_input))
                    {
                        if(memcpy(&K1_input[16], KEY_UPDATE_ENC_C_01_to_10, KEY_LENGTH16_BYTE) == (&K1_input[16]))
                        {
                            /* Encrypt then decrypt */
                            if(aes_mp(K1_input, KEY_LENGTH32_BYTE, K1) == 0)
                            {
                                decrypted_len = decrypt_aes_128_cbc(enc_m2->data_U8P, enc_m2->length_U32, K1, initialization_vector, decrypted_key, 0);
                                if (decrypted_len == 0)
                                {
                                    printf("\nDecryption failed or invalid key length. Got: %d\n", decrypted_len);
                                }
                                else
                                {
                                    if(memset(&op, 0, sizeof(op)) == (&op))
                                    {
                                        op.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE);
                                        op.params[0].tmpref.buffer = l_keyid;
                                        op.params[0].tmpref.size   = keyid_size;
                                        op.params[1].tmpref.buffer = &decrypted_key[KEY_LENGTH16_BYTE];
                                        op.params[1].tmpref.size   =  KEY_LENGTH16_BYTE;

                                        res = TEEC_InvokeCommand(&ctx->sess, TA_SECURE_STORAGE_CMD_WRITE_RAW, &op, &origin);
                                        if (res != TEEC_SUCCESS)
                                        {
                                            printf("\nFailed to store the key in persist blob");
                                        }
                                        else
                                        {
                                            printf("\nSecure_blob created as object id : %d",2);

                                            if (auth_key_id == AUTH_KEY_ID_PROTOTYPE) // Creating flag if authentication key is prototype key
                                            {
                                                printf("\n[CA] Creating Immutable Prototype flag\n");
                                                int flag_fd = open("/persist/prototype_key_flag", O_RDWR | O_CREAT, 0644);
                                                if (flag_fd < 0)
                                                {
                                                    printf("\n[CA] Error: Could not create flag file\n");
                                                }
                                                else
                                                {
                                                    int fs_flags = 0;
                                                    if (ioctl(flag_fd, FS_IOC_GETFLAGS, &fs_flags) == 0)
                                                    {
                                                        fs_flags |= FS_IMMUTABLE_FL;
                                                        if (ioctl(flag_fd, FS_IOC_SETFLAGS, &fs_flags) == 0)
                                                        {
                                                            printf("\n[CA] Prototype flag successfully created\n");
                                                        }
                                                        else
                                                        {
                                                            printf("\n[CA] Error: Failed to set Immutable attribute.\n");
                                                        }
                                                    }
                                                    else
                                                    {
                                                        //
                                                    }
                                                    (void)close(flag_fd);
                                                }
                                            }
                                            else
                                            {
                                                (void)memset(&op, 0, sizeof(op));
                                                op.paramTypes = (uint32_t)TEEC_PARAM_TYPES((uint32_t)TEEC_MEMREF_TEMP_INPUT, (uint32_t)TEEC_MEMREF_TEMP_INPUT, (uint32_t)TEEC_NONE, (uint32_t)TEEC_NONE);
                                                op.params[0].tmpref.buffer = (void *)m2_blob_id;
                                                op.params[0].tmpref.size = (uint32_t)M2_BLOB_NAME_LEN;
                                                op.params[1].tmpref.buffer = (void *)enc_m2->data_U8P;
                                                op.params[1].tmpref.size = KEY_LENGTH32_BYTE;

                                                TEEC_Result m2_store_res = TEEC_InvokeCommand(&ctx->sess, TA_SECURE_STORAGE_CMD_WRITE_RAW, &op, &origin);

                                                if (m2_store_res != TEEC_SUCCESS)
                                                {
                                                    (void)printf("\n[CA] Error: Failed to store M2 blob (0x%x)", m2_store_res);
                                                }
                                                else
                                                {
                                                    (void)printf("\n[CA] Success: Secure_M2_blob updated");
                                                }
                                                // No flag creation for production key
                                                printf("\n[CA] Prototype flag not created for production key\n");
                                                if (flag_check_res == TEEC_SUCCESS)
                                                {
                                                    int flag_fd = open("/persist/prototype_key_flag", O_RDONLY);
                                                    if (flag_fd >= 0)
                                                    {
                                                        int fs_flags = 0;
                                                        if (ioctl(flag_fd, FS_IOC_GETFLAGS, &fs_flags) == 0)
                                                        {
                                                            fs_flags &= ~FS_IMMUTABLE_FL;
                                                            if (ioctl(flag_fd, FS_IOC_SETFLAGS, &fs_flags) == 0)
                                                            {
                                                                (void)close(flag_fd);
                                                                if (unlink("/persist/prototype_key_flag") == 0)
                                                                {
                                                                    printf("\n[CA] Prototype flag deleted successfully\n");
                                                                }
                                                                else
                                                                {
                                                                    printf("\n[CA] Error: Failed to delete Prototype flag\n");
                                                                }
                                                            }
                                                            else
                                                            {
                                                                printf("\n[CA] Error: Failed to clear Immutable attribute.\n");
                                                                (void)close(flag_fd);
                                                            }
                                                        }
                                                        else
                                                        {
                                                            printf("\n[CA] Error: Failed to get flag attributes.\n");
                                                            (void)close(flag_fd);
                                                        }
                                                    }
                                                    else
                                                    {
                                                        printf("\n[CA] Could not open flag file for deletion\n");
                                                    }
                                                }
                                                else
                                                {
                                                    printf("\n[CA] No existing Prototype flag found, no deletion needed for Production key update.\n");
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        printf("\n[CA] MEMSET Failed\n");
                                        res = TEEC_ERROR_GENERIC;
                                    }
                                }
                            }
                            else
                            {
                                printf("\naes_mp failed \n");
                            }
                        }
                        else
                        {
                            printf("\n[CA] MEMCPY Failed\n");
                            res = TEEC_ERROR_GENERIC;
                        }
                    }
                    else
                    {
                        printf("\n[CA] MEMCPY Failed\n");
                        res = TEEC_ERROR_GENERIC;
                    }
                }
                else
                {
                    printf("\n[CA] Authentication key selection failed\n");
                }

    		}
            free(l_keyid);
    	}
    }
	else
    {
		printf("\n Unable to store the key sanity check failed invalid paramters\n");
	}
#ifdef CA_VERBOSE
	printf("\n Exiting SecureStorageCreateAndStore_CA\n");
#endif
	return res;
}

TEEC_Result Crypto_GetKeyFromBlob(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size) {

	TEEC_Operation operation;
	uint32_t origin;
	TEEC_Result res = TEEC_ERROR_GENERIC;
	char *l_keyid;

#ifdef CA_VERBOSE
	printf("\n Execution Crypto_GetKeyFromBlob\n");
#endif
	l_keyid = malloc(keyid_size);
    if(l_keyid == NULL)
    {
        //misra
    }
    else
    {
	    strcpy(l_keyid, key_id);
    	if(memset(&operation, 0, sizeof(operation)) == (&operation))
        {
        	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
            operation.params[0].tmpref.buffer = l_keyid;
            operation.params[0].tmpref.size   = keyid_size;
        	 // Invoke AES encryption command
            res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_SETKEY_FROM_BLOB, &operation, &origin);
            if (res != TEEC_SUCCESS) {
                printf("\n Failed to invoke Crypto_GetKeyFromBlob unable to access Secure_blob or set the key :");
            }
        }
        else
        {
            printf("\n[CA] MEMSET Failed\n");
            res = TEEC_ERROR_GENERIC;
        }
    }
#ifdef CA_VERBOSE
	printf("\n Exit Crypto_GetKeyFromBlob \n");
#endif
	return res;
}

TEEC_Result Crypto_GetasymKeyFromBlob(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size) {

	TEEC_Operation operation;
	uint32_t origin;
	TEEC_Result res = TEEC_ERROR_GENERIC;
	char *l_keyid;

#ifdef CA_VERBOSE
	printf("\n Execution Crypto_GetKeyFromBlob\n");
#endif
	l_keyid = malloc(keyid_size);
    if(l_keyid == NULL)
    {
        //misra
    }
    else
    {
	    strcpy(l_keyid, key_id);
    	if(memset(&operation, 0, sizeof(operation)) == (&operation))
        {
        	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
            operation.params[0].tmpref.buffer = l_keyid;
            operation.params[0].tmpref.size   = keyid_size;
        	 // Invoke AES encryption command
            res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_ASM_SETKEY_FROM_BLOB, &operation, &origin);
            if (res != TEEC_SUCCESS) {
                printf("\n Failed to invoke Crypto_GetKeyFromBlob unable to access Secure_blob or set the key :0x%08x ", res);
            }
        }
        else
        {
            printf("\n[CA] MEMSET Failed\n");
            res = TEEC_ERROR_GENERIC;
        }
    }
#ifdef CA_VERBOSE
	printf("\n Exit Crypto_GetKeyFromBlob \n");
#endif
	return res;
}

TEEC_Result Crypto_SetuserAesKey(struct TEE_resource_ctx *ctx, uint8_t *key, size_t key_len) {

	TEEC_Operation operation;
	uint32_t origin;
	TEEC_Result res;

#ifdef CA_VERBOSE
	printf("\n Execution Crypto_SetuserAesKey");
#endif

	if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
    	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE,
    					 TEEC_NONE, TEEC_NONE);
    	operation.params[0].tmpref.buffer = key;
    	operation.params[0].tmpref.size   = key_len;

    	 // Invoke AES encryption command
        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_SETUSERKEY, &operation, &origin);
        if (res != TEEC_SUCCESS) {
            printf("\n Failed to set the user key :");
        }
    }
    else
    {
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }

#ifdef CA_VERBOSE
	printf("\n Exit Crypto_SetuserAesKey");
#endif

	return res;
}

TEEC_Result Crypto_SetuserRsaPubKey(struct TEE_resource_ctx *ctx, const ts_publicKey *p_publicKey_SP, uint8_t key_len) {
 
    TEEC_Operation operation;
    uint32_t origin = 0U;
    TEEC_Result res = TEEC_ERROR_GENERIC;
 
#ifdef CA_VERBOSE
    printf("\n Execution Crypto_SetuserRsaPubKey");
#endif
    if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
        operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT,
                         TEEC_NONE, TEEC_NONE);
        operation.params[0].tmpref.buffer = p_publicKey_SP->modulus_S.data_U8P;
        operation.params[0].tmpref.size   = p_publicKey_SP->modulus_S.length_U32;
	    operation.params[1].tmpref.buffer = p_publicKey_SP->exponent_S.data_U8P;
        operation.params[1].tmpref.size   = p_publicKey_SP->exponent_S.length_U32;
        
	    if(key_len == RSA_2K){
	    	// Invoke rsa 2k public key command
        	res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_RSA_SETUSERPUBKEY, &operation, &origin);
	    }
	    else if(key_len == RSA_3K)
	    {
	    	// Invoke rsa 3k public key command
        	res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_RSA_SETUSERPUBKEY_3K, &operation, &origin);
	    }   
	    else
        {
	    	printf("\n Invalid key length");
	    }
        if (res != TEEC_SUCCESS) {
        printf("\n Failed to set the user key: 0x%x, origin: 0x%x\n", res, origin);
        }
        switch (res) {
                    case TEEC_SUCCESS:
	    				break;
                    case TEEC_ERROR_SHORT_BUFFER:
	    				break;
   	                case TEEC_ERROR_ITEM_NOT_FOUND:
        	            break;
        	        default:
        	            printf("\n Command set user key failed : ");
                        break;
        	        }
    }
    else{
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }
#ifdef CA_VERBOSE
    printf("\n Exit Crypto_SetuserRsapubKey");
#endif
 
    return res;
}

TEEC_Result Crypto_AES128CbcEncryptionWithPkcs7Pad(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType *Plaintext, 
			const ts_pointerType *InitialVector, ts_pointerType *ciphertext)
{
	TEEC_Operation operation;
	TEEC_Result res;
	uint32_t origin;
#ifdef CA_VERBOSE
	printf("\n Execution Crypto_AES128CbcEncryptionWithPkcs7Pad");
#endif
	//sanity check of input and output paramters
	if ((ctx == NULL) || (SANITY_CHECK_POINTER_TYPE(Plaintext)) || (SANITY_CHECK_POINTER_TYPE(InitialVector)) ||
	 (SANITY_CHECK_POINTER_TYPE(ciphertext)) || (((key_id == NULL)) || (keyid_size == 0U))) {
		printf("\n Crypto_AES128CbcDecryptionWithNoPad : sanity check failed\n");
		res = TEEC_ERROR_SHORT_BUFFER;
	}
	else {
		 res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
		if (res != TEEC_SUCCESS) {
			printf("\n Unable to set the key");
		}
		else 
		{
			if ((NULL == ciphertext->data_U8P) && (0U == ciphertext->length_U32)){
				ciphertext->length_U32 = Plaintext->length_U32 + (16U - (Plaintext->length_U32 % 16U));
				res = TEEC_SUCCESS;
			}
			else {
				if ((NULL == ciphertext->data_U8P) ||
					((Plaintext->length_U32 + (16U - (Plaintext->length_U32 % 16U))) !=
					ciphertext->length_U32))
				{
					printf("\n Crypto_AES128CbcEncryptionWithPkcs7Pad: Sanity Check2 Failed!");
					res = TEEC_ERROR_SHORT_BUFFER;
				}
				else {
					if(memset(&operation, 0, sizeof(operation)) == (&operation))
                    {
					    operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE);
					    operation.params[0].tmpref.buffer = Plaintext->data_U8P;
					    operation.params[0].tmpref.size   = Plaintext->length_U32;
					    operation.params[1].tmpref.buffer = InitialVector->data_U8P;
					    operation.params[1].tmpref.size   = InitialVector->length_U32;
					    operation.params[2].tmpref.buffer = ciphertext->data_U8P;
					    operation.params[2].tmpref.size   = ciphertext->length_U32;

					    // Invoke AES encryption command
					    res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_ENCRYPT, &operation, &origin);
					    if (res != TEEC_SUCCESS) {
					    	printf("\n Failed to invoke AES encryption");
					    }
					    switch (res) {
					    case TEEC_SUCCESS:
                            break;
					    case TEEC_ERROR_SHORT_BUFFER:
                            break;
					    case TEEC_ERROR_ITEM_NOT_FOUND:
					    	break;
					    default:
					    	printf("\n Command AES encryption failed : ");
                            break;
					    }
					    ciphertext->length_U32 = operation.params[2].tmpref.size;
                    }
                    else{
                        printf("\n[CA] MEMSET Failed\n");
                        res = TEEC_ERROR_GENERIC;
                    }
				}
			}
		}
	}

#ifdef CA_VERBOSE
	printf("\n Exit Crypto_AES128CbcEncryptionWithPkcs7Pad");
#endif
	return res;
}


TEEC_Result Crypto_AES128CbcDecryptionWithPkcs7Pad(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType *ciphertext,
			const ts_pointerType *InitialVector, ts_pointerType *Plaintext)
{
	TEEC_Operation operation;
	TEEC_Result res = TEEC_ERROR_GENERIC;
	uint32_t origin;
	uint8_t *tempOutBuf_pU8 = NULL;
    size_t tempOutBufLen_pU32 = 0U;
    if(Plaintext->length_U32 > (UINT32_MAX - 0U))
    {
        printf("\n Crypto_AES128CbcDecryptionWithNoPad : length of plain text is large - failed\n");
    }
    else
    {
        tempOutBufLen_pU32 = (size_t)Plaintext->length_U32 + (16ULL - ((size_t)Plaintext->length_U32 % 16ULL));
        tempOutBuf_pU8              = malloc(tempOutBufLen_pU32);
        if (tempOutBuf_pU8 != NULL)
        {
            if(memset(tempOutBuf_pU8, 0, tempOutBufLen_pU32) == (tempOutBuf_pU8))
            {
            #ifdef CA_VERBOSE
            	printf("\n Execution Crypto_AES128CbcDecryptionWithPkcs7Pad");
            #endif

            	if ((ctx == NULL) || (SANITY_CHECK_POINTER_TYPE(Plaintext)) || (SANITY_CHECK_POINTER_TYPE(InitialVector)) ||
            	 (SANITY_CHECK_POINTER_TYPE(ciphertext)) || (((key_id == NULL)) || (keyid_size == 0U))) {
            		printf("\n Crypto_AES128CbcDecryptionWithNoPad : sanity check failed\n");
            		res = TEEC_ERROR_SHORT_BUFFER;
            	}
            	else {
            		 res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
            		if (res != TEEC_SUCCESS) {
            			printf("\n Unable to set the key");
            		}
            		else 
            		{
            			// Set up the operation parameters for Decryption
            			if(memset(&operation, 0, sizeof(operation)) == (&operation))
                        {
            			    operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE);
            			    operation.params[0].tmpref.buffer = ciphertext->data_U8P;
            			    operation.params[0].tmpref.size   = ciphertext->length_U32;
            			    operation.params[1].tmpref.buffer = InitialVector->data_U8P;
            			    operation.params[1].tmpref.size   = InitialVector->length_U32;
            			    operation.params[2].tmpref.buffer = tempOutBuf_pU8;
            			    operation.params[2].tmpref.size   = tempOutBufLen_pU32;

            			    // Invoke AES encryption command
            			    res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_DECRYPTNOPAD, &operation, &origin);
            			    if (res != TEEC_SUCCESS) {
            			    	printf("\n Failed to invoke AES Decryption");
            			    }
            			    switch (res) {
            			    case TEEC_SUCCESS:
                                break;
            			    case TEEC_ERROR_SHORT_BUFFER:
                                break;
            			    case TEEC_ERROR_ITEM_NOT_FOUND:
            			    	break;
            			    default:
            			    	printf("\n Command AES Decryption failed : ");
                                break;
            			    }
                            if(tempOutBuf_pU8 == NULL)
                            {
                                res = TEEC_ERROR_OUT_OF_MEMORY;
                            }
                            else
                            {
            			        if(memcpy(Plaintext->data_U8P, tempOutBuf_pU8, (size_t)Plaintext->length_U32) == (Plaintext->data_U8P))
                                {
                                    res = TEEC_SUCCESS;
                                }
                                else{
                                    printf("\n[CA] MEMCPY Failed\n");
                                    res = TEEC_ERROR_GENERIC;
                                }
                            }
                        }
                        else{
                            printf("\n[CA] MEMSET Failed\n");
                            res = TEEC_ERROR_GENERIC;
                        }
            		}
            	}
                if(tempOutBuf_pU8 != NULL)
                {
                    free(tempOutBuf_pU8);
                }
            }
            else{
                free(tempOutBuf_pU8);
                printf("\n[CA] MEMSET Failed\n");
                res = TEEC_ERROR_GENERIC;
            }
        }
        else{
            printf("\n[CA] tempOutBuf_pU8 is null \n");
            res = TEEC_ERROR_GENERIC;
        }
    }
#ifdef CA_VERBOSE
	printf("\n Exit Crypto_AES128CbcDecryptionWithPkcs7Pad");
#endif
	return res;
}

// AES128 GCM encryption start
TEEC_Result Crypto_AES128GcmEncrypt(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType *Plaintext, const ts_pointerType *InitialVector,
                                    ts_pointerType *AdditionalData, ts_pointerType *ciphertext, ts_pointerType *Tag)
{
    TEEC_Operation operation;
    TEEC_Result res;
    uint32_t origin;

#ifdef CA_VERBOSE
    printf("\nExecution Crypto_AES128GcmEncrypt");
#endif
    // Sanity check of input and output parameters
    if ((ctx == NULL) ||
        (SANITY_CHECK_POINTER_TYPE(Plaintext)) ||
        (SANITY_CHECK_POINTER_TYPE(InitialVector)) ||
        (SANITY_CHECK_POINTER_TYPE(ciphertext)) ||
        (SANITY_CHECK_POINTER_TYPE(Tag)) ||
        (((key_id == NULL)) || (keyid_size == 0U)))
    {
        printf("Crypto_AES128GcmEncrypt : sanity check failed\n");
        res = TEEC_ERROR_SHORT_BUFFER;
    }
    else
    {
        res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
        if (res != TEEC_SUCCESS)
        {
            printf("\n Unable to set the key");
        }
        else
        {
            if ((NULL == ciphertext->data_U8P) && (0U == ciphertext->length_U32))
            {
                ciphertext->length_U32 = Plaintext->length_U32;
                res = TEEC_ERROR_SHORT_BUFFER;
            }
            else
            {
                if ((NULL == ciphertext->data_U8P) ||
                    (Plaintext->length_U32 != ciphertext->length_U32))
                {
                    printf("Crypto_AES128GcmEncrypt: Sanity Check2 Failed!");
                    res = TEEC_ERROR_SHORT_BUFFER;
                }
                else
                {
                    if(memset(&operation, 0, sizeof(operation)) == (&operation))
                    {
                        operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT,     // Plaintext
                                                                 TEEC_MEMREF_TEMP_INPUT,     // IV || AAD
                                                                 TEEC_MEMREF_TEMP_OUTPUT,    // Ciphertext
                                                                 TEEC_MEMREF_TEMP_OUTPUT);   // GCM Tag
                        operation.params[0].tmpref.buffer = Plaintext->data_U8P;
                        operation.params[0].tmpref.size   = Plaintext->length_U32;
                        // Concatenated AAD and IV buffer logic (or pass IV as param[1], AAD hardcoded or NULL)
                        operation.params[1].tmpref.buffer = InitialVector->data_U8P;
                        operation.params[1].tmpref.size   = InitialVector->length_U32;
                        operation.params[2].tmpref.buffer = ciphertext->data_U8P;
                        operation.params[2].tmpref.size   = ciphertext->length_U32;
                        operation.params[3].tmpref.buffer = Tag->data_U8P;
                        operation.params[3].tmpref.size   = Tag->length_U32;
                        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_GCM_ENCRYPT, &operation, &origin);
                        if (res != TEEC_SUCCESS)
                        {
                            printf("\n[CA] Failed to invoke AES GCM encryption: 0x%08X origin: 0x%08X", res, origin);
                        }
                        switch (res)
                        {
                            case TEEC_SUCCESS:
                                break;
                            case TEEC_ERROR_SHORT_BUFFER:
                                break;
                            case TEEC_ERROR_ITEM_NOT_FOUND:
                                break;
                            default:
                                printf("\n[CA] Command AES GCM encryption failed: 0x%08X origin: 0x%08X", res, origin);
                                break;
                        }
                        ciphertext->length_U32 = operation.params[2].tmpref.size;
                        Tag->length_U32        = operation.params[3].tmpref.size;
                    }
                    else
                    {
                        printf("\n[CA] MEMSET Failed\n");
                        res = TEEC_ERROR_GENERIC;
                    }
                }
            }
        }
    }
#ifdef CA_VERBOSE
    printf("\nExit Crypto_AES128GcmEncrypt");
#endif

    return res;
}

// AES128 GCM decryption start
TEEC_Result Crypto_AES128GcmDecrypt(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size,
                                    const ts_pointerType *ciphertext, const ts_pointerType *InitialVector,
                                    const ts_pointerType *Tag, ts_pointerType *Plaintext)
{
    TEEC_Operation operation;
    TEEC_Result res = TEEC_ERROR_GENERIC;
    uint32_t origin;
    uint8_t *tempOutBuf_pU8 ;
    size_t tempOutBufLen_pU32;

#ifdef CA_VERBOSE
            printf("\nExecution Crypto_AES128GcmDecrypt");
#endif
    // Sanity check
    if ((ctx == NULL) ||
        (SANITY_CHECK_POINTER_TYPE(ciphertext)) ||
        (SANITY_CHECK_POINTER_TYPE(InitialVector)) ||
        (SANITY_CHECK_POINTER_TYPE(Tag)) ||
        (SANITY_CHECK_POINTER_TYPE(Plaintext)) ||
        ((key_id == NULL) || (keyid_size == 0U)))
    {
        printf("Crypto_AES128GcmDecrypt : sanity check failed\n");
        res = TEEC_ERROR_SHORT_BUFFER;
    }
    else
    {
        tempOutBufLen_pU32 = (size_t)Plaintext->length_U32;
        tempOutBuf_pU8              = malloc(tempOutBufLen_pU32);
        if(tempOutBuf_pU8 != NULL)
        {
            if(memset(tempOutBuf_pU8, 0, tempOutBufLen_pU32) == (tempOutBuf_pU8))
            {
                res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
                if (res != TEEC_SUCCESS)
                {
                    printf("\n Unable to set the key");
                }
                else
                {
                    // Prepare operation
                    if(memset(&operation, 0, sizeof(operation)) == (&operation))
                    {
                        operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT,     // Ciphertext
                                                                 TEEC_MEMREF_TEMP_INPUT,     // IV
                                                                 TEEC_MEMREF_TEMP_INPUT,     // GCM Tag
                                                                 TEEC_MEMREF_TEMP_OUTPUT);   // Decrypted outpu
                        operation.params[0].tmpref.buffer = ciphertext->data_U8P;
                        operation.params[0].tmpref.size   = ciphertext->length_U32;
                        operation.params[1].tmpref.buffer = InitialVector->data_U8P;
                        operation.params[1].tmpref.size   = InitialVector->length_U32;
                        operation.params[2].tmpref.buffer = Tag->data_U8P;
                        operation.params[2].tmpref.size   = Tag->length_U32;
                        operation.params[3].tmpref.buffer = tempOutBuf_pU8;
                        operation.params[3].tmpref.size   = tempOutBufLen_pU32;
                        // Command to decrypt
                        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_GCM_DECRYPT, &operation, &origin);
                        if (res != TEEC_SUCCESS)
                        {
                            printf("\n[CA] Failed to invoke AES GCM decryption: 0x%08X origin: 0x%08X", res, origin);
                        }
                        switch (res)
                        {
                            case TEEC_SUCCESS:
                                break;
                            case TEEC_ERROR_SHORT_BUFFER:
                                    break;
                            case TEEC_ERROR_ITEM_NOT_FOUND:
                                break;
                            default:
                                printf("\n[CA] Command AES GCM decryption failed: 0x%08X origin: 0x%08X", res, origin);
                                break;
                        }
                        // Copy decrypted data to output
                        if(tempOutBuf_pU8 == NULL)
                        {
                            res = TEEC_ERROR_OUT_OF_MEMORY;
                        }
                        else
                        {
                            if(memcpy(Plaintext->data_U8P, tempOutBuf_pU8, operation.params[3].tmpref.size) == (Plaintext->data_U8P))
                            {
                                Plaintext->length_U32 = operation.params[3].tmpref.size;
                            }
                            else
                            {
                                printf("\n[CA] MEMCPY Failed\n");
                                res = TEEC_ERROR_GENERIC;
                            }
                        }
                    }
                    else
                    {
                        printf("\n[CA] MEMSET Failed\n");
                        res = TEEC_ERROR_GENERIC;
                    }
                }
            }
            if(tempOutBuf_pU8 != NULL)
            {
                free(tempOutBuf_pU8);
            }
        }
    }
    
#ifdef CA_VERBOSE
    printf("\nExit Crypto_AES128GcmDecrypt");
#endif
    return res;
}

// ECB_EncryptionWithNoPad
TEEC_Result Crypto_AES128EcbEncryptionWithNoPad(struct TEE_resource_ctx *ctx,
                                                 const char* key_id,
                                                 const uint32_t keyid_size,
                                                 const ts_pointerType *Plaintext,
                                                 ts_pointerType *Ciphertext)
{
     TEEC_Operation operation;
    TEEC_Result res = TEEC_ERROR_GENERIC;
    uint32_t origin = 0U;

#ifdef CA_VERBOSE
    printf("\n Execution Crypto_AES128EcbEncryptionWithNoPad");
#endif

    if ((((ctx && key_id )&& (keyid_size > 0U)) && Plaintext) && Ciphertext) {
        if (!SANITY_CHECK_POINTER_TYPE(Plaintext) && !SANITY_CHECK_POINTER_TYPE(Ciphertext)) {
            if ((Plaintext->length_U32 % AES_BLOCK_SIZE) == 0U) {
                res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
                if (res == TEEC_SUCCESS) {
                    if ((Ciphertext->data_U8P != NULL) && (Ciphertext->length_U32 >= Plaintext->length_U32))
                    {
                        if(memset(&operation, 0, sizeof(operation)) == (&operation))
                        {

                            operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT,
                                                                    TEEC_MEMREF_TEMP_OUTPUT,
                                                                    TEEC_NONE,
                                                                    TEEC_NONE);

                            operation.params[0].tmpref.buffer = Plaintext->data_U8P;
                            operation.params[0].tmpref.size   = Plaintext->length_U32;

                            operation.params[1].tmpref.buffer = Ciphertext->data_U8P;
                            operation.params[1].tmpref.size   = Ciphertext->length_U32;

                            res = (TEEC_Result)TEEC_InvokeCommand(&ctx->sess,
                                                     TA_CRYPTO_CMD_AES_ECB_ENCRYPT,
                                                     &operation,
                                                     &origin);

                            if (res == TEEC_SUCCESS) {
                                if (operation.params[1].tmpref.size <= UINT32_MAX)
                                {
                                    Ciphertext->length_U32 = (uint32_t)operation.params[1].tmpref.size;
                                }
                                else
                                {
                                    res = TEEC_ERROR_EXCESS_DATA;
                                    printf("\n AES ECB encryption successful, output length: %u", Ciphertext->length_U32);
                                }
                            } else {
                                printf("\n Failed to invoke AES ECB encryption, error: 0x%08X, origin: %u", res, origin);
                            }
                        }
                        else
                        {
                            printf("\n[CA] MEMSET Failed\n");
                            res = TEEC_ERROR_GENERIC;
                        }
                    } 
                    else {
                        Ciphertext->length_U32 = Plaintext->length_U32;
                        res = TEEC_ERROR_SHORT_BUFFER;
                    }
                } else {
                    printf("\n Unable to set the key");
                }
            } else {
                printf("\n Plaintext length must be a multiple of block size for ECB mode");
                res = TEEC_ERROR_BAD_PARAMETERS;
            }
        } else {
            printf("\n Crypto_AES128EcbEncryptionWithNoPad: pointer type check failed");
            res = TEEC_ERROR_BAD_PARAMETERS;
        }
    } else {
        printf("\n Crypto_AES128EcbEncryptionWithNoPad: sanity check failed");
        res = TEEC_ERROR_BAD_PARAMETERS;
    }

#ifdef CA_VERBOSE
    printf("\n Exit Crypto_AES128EcbEncryptionWithNoPad");
#endif

    return res;
}

TEEC_Result Crypto_AES128EcbDecryptionWithNoPad(struct TEE_resource_ctx *ctx,
                                                 const char* key_id,
                                                 const uint32_t keyid_size,
                                                 const ts_pointerType *Ciphertext,
                                                 ts_pointerType *Plaintext)
{
    TEEC_Operation operation;
    TEEC_Result    res     = TEEC_ERROR_GENERIC;
    uint32_t       origin  = 0U;

#ifdef CA_VERBOSE
    printf("\n Execution Crypto_AES128EcbDecryptionWithNoPad");
#endif

    // Sanity check on all input and output pointers
    if ((ctx != NULL) &&
        (!SANITY_CHECK_POINTER_TYPE(Plaintext)) &&
        (!SANITY_CHECK_POINTER_TYPE(Ciphertext)) &&
        ((key_id != NULL) && (keyid_size != 0U)))
    {
        // Ensure ciphertext length is multiple of AES block size
        if ((Ciphertext->length_U32 % AES_BLOCK_SIZE) == 0U)
        {
            res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
            if (res == TEEC_SUCCESS)
            {
                if ((Plaintext->data_U8P != NULL) &&
                    (Plaintext->length_U32 >= Ciphertext->length_U32))
                {
                    if(memset(&operation, 0, sizeof(operation)) == (&operation))
                    {
                        operation.paramTypes               = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT,
                                                                             TEEC_MEMREF_TEMP_OUTPUT,
                                                                             TEEC_NONE,
                                                                             TEEC_NONE);

                        operation.params[0].tmpref.buffer  = Ciphertext->data_U8P;
                        operation.params[0].tmpref.size    = Ciphertext->length_U32;

                        operation.params[1].tmpref.buffer  = Plaintext->data_U8P;
                        operation.params[1].tmpref.size    = Plaintext->length_U32;

                        res = TEEC_InvokeCommand(&ctx->sess,
                                                 TA_CRYPTO_CMD_AES_ECB_DECRYPT,
                                                 &operation,
                                                 &origin);
                        if (res == TEEC_SUCCESS)
                        {
                            if (operation.params[1].tmpref.size <= UINT32_MAX)
                            {
                                Plaintext->length_U32 = (uint32_t)operation.params[1].tmpref.size;
                            }
                            else
                            {
                                 res = TEEC_ERROR_EXCESS_DATA;
                            }
                        }
                        else
                        {
                            printf("\n Failed to invoke AES ECB decryption");
                        }
                    }
                    else{
                        printf("\n[CA] MEMSET Failed\n");
                        res = TEEC_ERROR_GENERIC;
                    }
                }
                else
                {
                    Plaintext->length_U32 = Ciphertext->length_U32;
                    res = TEEC_ERROR_SHORT_BUFFER;
                }
            }
            else
            {
                printf("\n Unable to set the key");
            }
        }
        else
        {
            printf("\n Ciphertext length must be a multiple of block size for ECB mode");
            res = TEEC_ERROR_BAD_PARAMETERS;
        }
    }
    else
    {
        printf("\n Crypto_AES128EcbDecryptionWithNoPad: sanity check failed");
        res = TEEC_ERROR_BAD_PARAMETERS;
    }

#ifdef CA_VERBOSE
    printf("\n Exit Crypto_AES128EcbDecryptionWithNoPad");
#endif

    return res;
}

TEEC_Result Crypto_AES128CbcEncryptionWithNoPad(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType *Plaintext,
			const ts_pointerType *InitialVector, ts_pointerType *ciphertext)
{
	TEEC_Operation operation;
	TEEC_Result res;
	uint32_t origin;
#ifdef CA_VERBOSE
	printf("\n Execution Crypto_AES128CbcEncryptionWithNoPad");
#endif

	if ((ctx == NULL) || (SANITY_CHECK_POINTER_TYPE(Plaintext)) || (SANITY_CHECK_POINTER_TYPE(InitialVector)) ||
	 (SANITY_CHECK_POINTER_TYPE(ciphertext)) || (((key_id == NULL)) || (keyid_size == 0U))) {
		printf("\n Crypto_AES128CbcDecryptionWithNoPad : sanity check failed\n");
		res = TEEC_ERROR_SHORT_BUFFER;
	}
	else {
		 res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
		if (res != TEEC_SUCCESS) {
			printf("\n Unable to set the key");
		}
		else 
		{
			if(memset(&operation, 0, sizeof(operation)) == (&operation))
            {
		    	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE);
		    	operation.params[0].tmpref.buffer = Plaintext->data_U8P;
		    	operation.params[0].tmpref.size   = Plaintext->length_U32;
		    	operation.params[1].tmpref.buffer = InitialVector->data_U8P;
		    	operation.params[1].tmpref.size   = InitialVector->length_U32;
		    	operation.params[2].tmpref.buffer = ciphertext->data_U8P;
		    	operation.params[2].tmpref.size   = ciphertext->length_U32;

		    	// Invoke AES encryption command
		    	res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_ENCRYPTNOPAD, &operation, &origin);
		    	if (res != TEEC_SUCCESS) {
		    		printf("\n Failed to invoke AES encryption");
		    	}
		    	switch (res) {
		    	case TEEC_SUCCESS:
                    break;
                case TEEC_ERROR_SHORT_BUFFER:
                    break;
                case TEEC_ERROR_ITEM_NOT_FOUND:
                    break;
		    	default:
		    		printf("\n Command AES encryption failed : ");
                    break;
		    	}
            }
            else{
                printf("\n[CA] MEMSET Failed\n");
                res = TEEC_ERROR_GENERIC;
            }
		}
	}

#ifdef CA_VERBOSE
	printf("\n Exit Crypto_AES128CbcEncryptionWithNoPad");
#endif
	return res;
}


TEEC_Result Crypto_AES128CbcDecryptionWithNoPad(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType *ciphertext,
			const ts_pointerType *InitialVector, ts_pointerType *Plaintext)
{
	TEEC_Operation operation;
	TEEC_Result res;
	uint32_t origin;
#ifdef CA_VERBOSE
	printf("\n Execution Crypto_AES128CbcDecryptionWithNoPad");
#endif

	if ((ctx == NULL) || (SANITY_CHECK_POINTER_TYPE(Plaintext)) || (SANITY_CHECK_POINTER_TYPE(InitialVector)) ||
	 (SANITY_CHECK_POINTER_TYPE(ciphertext)) || (((key_id == NULL)) || (keyid_size == 0U))) {
		printf("\n Crypto_AES128CbcDecryptionWithNoPad : sanity check failed\n");
		res = TEEC_ERROR_SHORT_BUFFER;
	}
	else {
		res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
		if (res != TEEC_SUCCESS) {
			printf("\n Unable to set the key");
		}
		else 
		{
			// Set up the operation parameters for Decryption
			if(memset(&operation, 0, sizeof(operation)) == (&operation))
            {
		    	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE);
		    	operation.params[0].tmpref.buffer = ciphertext->data_U8P;
		    	operation.params[0].tmpref.size   = ciphertext->length_U32;
		    	operation.params[1].tmpref.buffer = InitialVector->data_U8P;
		    	operation.params[1].tmpref.size   = InitialVector->length_U32;
		    	operation.params[2].tmpref.buffer = Plaintext->data_U8P;
		    	operation.params[2].tmpref.size   = Plaintext->length_U32;

		    	// Invoke AES encryption command
		    	res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_DECRYPTNOPAD, &operation, &origin);
		    	if (res != TEEC_SUCCESS) {
		    		printf("\n Failed to invoke AES Decryption");
		    	}
		    	switch (res) {
		    	case TEEC_SUCCESS:
                        break;
		    	case TEEC_ERROR_SHORT_BUFFER:
                        break;
		    	case TEEC_ERROR_ITEM_NOT_FOUND:
		    		break;
		    	default:
		    		printf("\n Command AES Decryption failed : ");
                    break;
		    	}
            }
            else{
                printf("\n[CA] MEMSET Failed\n");
                res = TEEC_ERROR_GENERIC;
            }
		}
	}

#ifdef CA_VERBOSE
	printf("\n Exit Crypto_AES128CbcDecryptionWithNoPad");
#endif
	return res;
}

TEEC_Result Crypto_SHA256(struct TEE_resource_ctx *ctx,
			const ts_pointerType *Plaintext, ts_pointerType *Digest)
{
	TEEC_Operation operation;
	TEEC_Result res;
	uint32_t origin;

#ifdef CA_VERBOSE
	printf("\n Execution Crypto_SHA256");
#endif

	if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
    	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE);
        operation.params[0].tmpref.buffer = Plaintext->data_U8P;
        operation.params[0].tmpref.size   = Plaintext->length_U32;
        operation.params[1].tmpref.buffer = Digest->data_U8P;
        operation.params[1].tmpref.size   = Digest->length_U32;
        

        // Invoke AES encryption command
        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_SHA256_HASH, &operation, &origin);
        if (res != TEEC_SUCCESS) {
            printf("\n Failed to invoke AES SHA256 hash computation");
        }
    	switch (res) 
        {
    	case TEEC_SUCCESS:
            break;
    	case TEEC_ERROR_SHORT_BUFFER:
            break;
    	case TEEC_ERROR_ITEM_NOT_FOUND:
    		break;
    	default:
    		printf("\n Command AES Decryption failed : ");
            break;
    	}
        if (operation.params[1].tmpref.size <= UINT32_MAX)
        {
    	    Digest->length_U32 = (uint32_t)operation.params[1].tmpref.size;
        }
        else
        {
            res = TEEC_ERROR_EXCESS_DATA;
        }
    }
    else
    {
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }
#ifdef CA_VERBOSE
	printf("\n Exit Crypto_SHA256");
#endif

	return res;
}

TEEC_Result Crypto_RSASSA_PKCS1_v1_5_SHA256_Verify(struct TEE_resource_ctx *ctx, const ts_pointerType *message, const ts_pointerType *signature, uint8_t key_len) 
{
    TEEC_Operation operation;
    TEEC_Result res;
    uint32_t origin;
#ifdef PROTOTYPE_KEY
	/** 3k **/
	const uint8_t p_PublicModulusPtr3k_pU8[SIZE_OF_3k_MODULUS_BYTES] = { 
    	    0xA8, 0x47, 0x99, 0xCA, 0x1E, 0x60, 0xC5, 0x0F, 0x6C, 0x42, 0xE6, 0xE9, 0x24, 0x72, 0xF0, 0x7A,  
        	0x64, 0x89, 0xAA, 0xC2, 0xC8, 0xE0, 0x41, 0xF2, 0xD7, 0xB5, 0x4B, 0x3E, 0xEB, 0x73, 0x89, 0x2F,  
    	    0x07, 0xD9, 0x71, 0xFB, 0xDA, 0xBD, 0x42, 0x83, 0x43, 0x7B, 0x4C, 0xB5, 0x2F, 0xAD, 0xEE, 0xF2,  
    	    0x86, 0x58, 0x53, 0x2D, 0xDE, 0xD8, 0xDA, 0x77, 0x63, 0x98, 0x44, 0xD8, 0x1E, 0xB7, 0x57, 0xDB,  
    	    0x05, 0xE7, 0x9C, 0x12, 0x9E, 0x4D, 0xEF, 0x85, 0x3C, 0x83, 0x43, 0xA0, 0xEA, 0x89, 0xB6, 0xB6,  
    	    0xFF, 0x67, 0x72, 0x54, 0xB6, 0x07, 0x0B, 0x40, 0xE4, 0x95, 0x1C, 0x3F, 0x8E, 0x3E, 0x33, 0x13,  
    	    0x9E, 0x2F, 0xB7, 0x78, 0xAB, 0x59, 0xED, 0x4A, 0xA7, 0xF6, 0x5A, 0xC7, 0x79, 0x7E, 0xCF, 0x07,  
    	    0xD7, 0x88, 0xB2, 0x20, 0x6B, 0x0C, 0x02, 0x3E, 0xCD, 0x4D, 0x56, 0xF8, 0x1F, 0x88, 0x3D, 0x25,  
    	    0xF2, 0x51, 0x35, 0xA4, 0x28, 0xFC, 0x9B, 0x99, 0xFB, 0x41, 0xC3, 0x8B, 0x0F, 0xBD, 0x2F, 0x6D,  
	        0x4A, 0x51, 0x06, 0x57, 0xCC, 0xE3, 0x66, 0xB4, 0x11, 0x6E, 0x71, 0xB5, 0x2D, 0x05, 0x26, 0x4B,  
	        0xC0, 0x86, 0x19, 0x03, 0x89, 0xE4, 0x8C, 0x81, 0x81, 0x3B, 0x12, 0x3B, 0x4D, 0x82, 0x8B, 0x67,  
	        0x15, 0x62, 0x26, 0x84, 0x14, 0xB3, 0x72, 0x18, 0x89, 0x9B, 0x79, 0x8F, 0xB0, 0x8D, 0x98, 0x5B,  
	        0x16, 0x31, 0xB7, 0x51, 0x95, 0x49, 0x61, 0xED, 0xB2, 0x04, 0xCB, 0x05, 0x87, 0x7B, 0xE4, 0xF0,  
	        0xDB, 0xB3, 0x88, 0x6C, 0x41, 0xD1, 0xEB, 0x01, 0x0C, 0x39, 0x37, 0xCA, 0x0A, 0x0F, 0xA1, 0x0D,  
	        0x1A, 0x11, 0x2D, 0xC8, 0x24, 0xD6, 0xD5, 0x3F, 0x77, 0x0C, 0x8B, 0x17, 0xD9, 0x14, 0xEA, 0x70,  
	        0x40, 0xC4, 0x27, 0xBB, 0x40, 0x9A, 0x7F, 0xDD, 0x92, 0x72, 0xD6, 0x63, 0x75, 0x4D, 0x81, 0x5D,  
	        0xD7, 0x94, 0x7E, 0x45, 0x0F, 0xC3, 0x60, 0xD0, 0xBC, 0x1C, 0x50, 0xCF, 0x99, 0x6A, 0xE0, 0xC3,  
	        0x5A, 0xE2, 0x24, 0x1D, 0x12, 0x34, 0x41, 0xA3, 0xDA, 0xF2, 0x07, 0xAF, 0x5F, 0xBD, 0x8F, 0xF8,  
	        0x84, 0x39, 0x39, 0x6B, 0x5B, 0x65, 0xB2, 0x29, 0x4A, 0x69, 0x64, 0x1C, 0xF6, 0x5E, 0x1C, 0xFC,  
	        0x19, 0x10, 0x71, 0x79, 0x20, 0x7A, 0x4D, 0x64, 0x17, 0x8D, 0x23, 0x3B, 0x42, 0xE7, 0x71, 0x01,  
	        0x12, 0xCC, 0x28, 0xB8, 0xD0, 0xD6, 0x7F, 0x19, 0xAF, 0xCD, 0xCD, 0x5F, 0x1F, 0xE6, 0x07, 0x8A,  
	        0x16, 0x97, 0x9A, 0x56, 0x4E, 0x82, 0xE8, 0x63, 0x3F, 0x81, 0x0D, 0xFB, 0xA3, 0x88, 0xEC, 0x3D,  
	        0x10, 0x49, 0xA4, 0xDD, 0xF5, 0x94, 0xBE, 0xBD, 0x5C, 0xC9, 0x10, 0xC5, 0xB3, 0x4B, 0xF8, 0x89,  
	        0xD6, 0xEB, 0x10, 0x0A, 0x7C, 0xB4, 0x48, 0x56, 0xAB, 0x19, 0xF0, 0x68, 0xE3, 0xCC, 0xC3, 0xA1  
	
	
	    };
#endif

#ifdef INTERNAL_DEV_KEY
	/** 3k **/
	const uint8_t p_PublicModulusPtr3k_pU8[SIZE_OF_3k_MODULUS_BYTES] = {
			0XB3,0XC5,0X42,0XA4,0XF4,0XE1,0X09,0XCE,0XF9,0XF8,0X1B,0XD9,0X74,0X21,0XA8,0X20,
			0XD7,0X0C,0XB2,0X1E,0X4C,0X0A,0X19,0XED,0XB0,0X10,0X9B,0XAD,0X88,0X6C,0X8F,0X6A,
			0XC3,0X81,0X8D,0X3A,0X64,0X49,0X42,0X63,0XF4,0XD1,0X0D,0X2F,0X97,0XE2,0XEC,0X9E,
			0XC4,0X79,0XC6,0X32,0X52,0X86,0XB7,0XD0,0XF6,0XAB,0X94,0X39,0X32,0X3B,0XD5,0XD9,
			0X28,0XAF,0X21,0X8E,0X63,0XC9,0XD6,0X12,0X9D,0X2D,0XB9,0XF7,0XB9,0X6C,0XB4,0X87,
			0X87,0XA5,0X59,0XA2,0X80,0X12,0XC5,0X18,0X4B,0XD5,0XAD,0X68,0X77,0X35,0XEF,0XDC,
			0X5F,0X75,0X42,0XE4,0XF8,0X5A,0XCB,0XC7,0XA9,0X65,0X49,0X6F,0XA3,0XD4,0XB2,0X93,
			0X9F,0X0B,0X02,0XF3,0X3C,0XDB,0X0A,0XE7,0XEC,0X0D,0X2B,0X77,0X77,0XFB,0XC2,0XC8,
			0XBF,0XCA,0X77,0X48,0X01,0X45,0X4B,0X05,0XA8,0XE6,0X77,0XE1,0XD5,0X3D,0X6B,0X22,
			0X40,0XA1,0X23,0X6F,0XF9,0X52,0X07,0X6C,0X3B,0X3E,0X59,0X13,0X93,0XAD,0X40,0X42,
			0X31,0X4B,0X65,0X1F,0X33,0XDE,0XDD,0XBE,0X15,0X54,0X8A,0XE6,0XC9,0X2A,0X19,0X8B,
			0X59,0X75,0X5D,0XB4,0X86,0X4A,0XED,0XFC,0X80,0XF7,0X5B,0X20,0X5D,0XB5,0X03,0X71,
			0XDF,0X19,0X65,0X09,0X81,0XAA,0XAD,0X6B,0XB2,0X9C,0XB9,0X9E,0X01,0X77,0X7B,0X3B,
			0XEB,0XB8,0X03,0X36,0XBB,0X3A,0XBE,0X17,0X90,0XC8,0X7C,0X85,0XA1,0X68,0X11,0XEB,
			0XB5,0X88,0X42,0X00,0XD5,0X4F,0XB5,0XBE,0XE6,0X9D,0XED,0X70,0X06,0XA7,0X54,0XEB,
			0XD8,0XAC,0X3D,0XDB,0X87,0X62,0X1D,0XBA,0X69,0X6C,0X85,0XD3,0X78,0X45,0XDF,0XEB,
			0XDD,0XFA,0X93,0X38,0XBC,0X5C,0XA8,0X7C,0XE2,0X07,0XEA,0X73,0X74,0X4D,0X32,0XCC,
			0XCD,0X75,0X25,0X09,0XAF,0X26,0X89,0XE8,0XFA,0XAC,0X96,0X6F,0XFB,0X90,0X22,0X69,
			0X71,0XA4,0X6B,0X81,0XF2,0XC5,0X2E,0X30,0XC3,0XAC,0X68,0XD9,0X19,0X67,0XE0,0XAC,
			0X6D,0X5C,0X93,0X97,0XF4,0XFC,0X6B,0XD3,0XA5,0XE2,0XDF,0XDC,0XB9,0XEF,0XF5,0XEC,
			0XF5,0XEF,0X4A,0X81,0X8E,0XDE,0XC3,0X66,0X85,0X91,0XDA,0XA5,0X9B,0XCF,0X57,0X81,
			0X17,0XD6,0X63,0XD9,0XA0,0XD0,0X17,0X5A,0X95,0XC4,0X95,0X9C,0X68,0XA0,0X78,0XC5,
			0XA5,0X61,0XB0,0X40,0X76,0XF7,0X57,0X3F,0X01,0X42,0X40,0X2C,0X05,0XC6,0X2A,0X98,
			0XAF,0X5F,0X60,0XA1,0XBE,0XE3,0X27,0XD6,0X4A,0XB4,0X45,0X0B,0X3E,0X9E,0X57,0X53

	};

	const uint8_t p_PublicExponentPtr_pU8[SIZE_OF_EXPONENT] = {0x01, 0x00, 0x01};
	ts_pointerType l_modulus3_S;
    ts_pointerType  l_exponent3_S;
    ts_publicKey l_publicKey3_S;
    ts_pointerType l_modulus2_S;
    ts_pointerType l_exponent2_S;
    ts_publicKey l_publicKey2_S;
    ts_publicKey p_publicKey_S;
    l_modulus3_S.data_U8P = malloc(SIZE_OF_3k_MODULUS_BYTES); 
    if(l_modulus3_S.data_U8P == NULL)
    {
        res = TEEC_ERROR_OUT_OF_MEMORY;
    }
    else
    {
	    if(memcpy(l_modulus3_S.data_U8P,&p_PublicModulusPtr3k_pU8[0],SIZE_OF_3k_MODULUS_BYTES) == (l_modulus3_S.data_U8P))
        {
            l_modulus3_S.length_U32 = SIZE_OF_3k_MODULUS_BYTES;
        	
            l_exponent3_S.data_U8P = malloc(SIZE_OF_EXPONENT);
        	if(l_exponent3_S.data_U8P == NULL)
            {
                res = TEEC_ERROR_OUT_OF_MEMORY;
            }
            else
            {
                if(memcpy(l_exponent3_S.data_U8P,&p_PublicExponentPtr_pU8[0],SIZE_OF_EXPONENT) == (l_exponent3_S.data_U8P))
                {
                    l_exponent3_S.length_U32 = SIZE_OF_EXPONENT;
                	l_publicKey3_S.modulus_S = l_modulus3_S;
                	l_publicKey3_S.exponent_S = l_exponent3_S;

                	/** 2k **/

                	const uint8_t p_PublicModulusPtr2k_pU8[SIZE_OF_2k_MODULUS_BYTES] = {
                    0xbb, 0x21, 0x03, 0x97, 0xdf, 0xd6, 0x82, 0xc7, 0x07, 0xfd, 0xbb, 0x89, 0x82, 0x37, 0xa8 ,
                    0xe2, 0x6c, 0x33, 0x74, 0x89, 0x18, 0x54, 0x35, 0x0c, 0xab, 0x96, 0x07, 0x9b, 0x09, 0x4e,
                    0xba, 0x29, 0xde, 0x8d, 0xce, 0xb3, 0xa0, 0x4f, 0xef, 0x81, 0xc0, 0x0e, 0x1c, 0x0d, 0x1f,
                    0x58, 0x4c, 0xf7, 0x5e, 0x1e, 0xa9, 0xcd, 0x80, 0x05, 0x93, 0xfb, 0x9a, 0xb7, 0xfe,
                    0xbb, 0x51, 0x73, 0xc1, 0x31, 0x6a, 0xbe, 0x24, 0x04, 0x7a, 0x8c, 0x4c, 0xcb, 0x92, 0x23,
                    0x81, 0x70, 0x23, 0xbd, 0x45, 0x90, 0xf5, 0xdf, 0x2b, 0xa4, 0x99, 0x88, 0xfa, 0xd8, 0x9f,
                    0x42, 0xa3, 0x0c, 0x1f, 0x0f, 0xd0, 0x5e, 0x82, 0x5f, 0xd3, 0xae, 0xa5, 0x3c, 0xfc, 0x7e,
                    0x66, 0x83, 0x5e, 0x06, 0x12, 0x92, 0xc8, 0x8d, 0xdb, 0x84, 0xef, 0x3c, 0x01, 0xd8, 0xac,
                    0xf0, 0x5b, 0x31, 0x8b, 0xcc, 0x37, 0xf9, 0x1d, 0xe5, 0x53, 0x66, 0x20, 0x2b, 0x55, 0x41,
                    0x72, 0x8f, 0xc4, 0x2e, 0x72, 0xcf, 0xe6, 0xc8, 0x0b, 0x13, 0xcb, 0x22, 0x5b, 0x5c, 0x1e,
                    0xac, 0x11, 0xde, 0xbb, 0x68, 0x64, 0x1b, 0x5d, 0xd8, 0x75, 0xa6, 0x3f, 0x95, 0xd8, 0x8c,
                    0x96, 0x97, 0x49, 0xf3, 0x71, 0xe5, 0xc9, 0x14, 0xf6, 0x8a, 0x2f, 0x34, 0x18, 0x93, 0xc0,
                    0x35, 0xb9, 0xbf, 0x34, 0x41, 0x40, 0x69, 0x16, 0x10, 0xa5, 0xc5, 0xe1, 0x1f, 0xed, 0x4a,
                    0x09, 0x63, 0xc0, 0x4b, 0x6b, 0xbd, 0x89, 0x29, 0xbf, 0x1a, 0xd2, 0xa5, 0x85, 0x43, 0xd1,
                    0x76, 0xf1, 0x9a, 0x0b, 0x98, 0x19, 0xe4, 0x2f, 0x1c, 0x35, 0xe9, 0x18, 0xdc, 0xf1, 0x52,
                    0x28, 0xcc, 0x24, 0x02, 0xf0, 0x26, 0xb2, 0xa1, 0x7c, 0xfe, 0x64, 0xe3, 0xa7, 0xeb, 0xc0,
                    0x62, 0x6a, 0x06, 0x04, 0x4e, 0xe3, 0xbf, 0xd4, 0xe8, 0xec, 0x46, 0x08, 0x53, 0x6e, 0x0d,
                    0xd9, 0xfd
                    };
                    l_modulus2_S.data_U8P = malloc(SIZE_OF_2k_MODULUS_BYTES);
                    if(l_modulus2_S.data_U8P == NULL)
                    {
                        res = TEEC_ERROR_OUT_OF_MEMORY;
                    }
                    else
                    {
                	    if(memcpy(l_modulus2_S.data_U8P,&p_PublicModulusPtr2k_pU8[0],SIZE_OF_2k_MODULUS_BYTES) == (l_modulus2_S.data_U8P))
                        {
                            l_modulus2_S.length_U32 = SIZE_OF_2k_MODULUS_BYTES;
                            l_exponent2_S.data_U8P = malloc(SIZE_OF_EXPONENT);
                            if(l_exponent2_S.data_U8P == NULL)
                            {
                                res = TEEC_ERROR_OUT_OF_MEMORY;
                            }
                            else
                            {
                    	        if(memcpy(l_exponent2_S.data_U8P,&p_PublicExponentPtr_pU8[0],SIZE_OF_EXPONENT) == (l_exponent2_S.data_U8P))
                                {
                                    l_exponent2_S.length_U32 = SIZE_OF_EXPONENT;
                                    l_publicKey2_S.modulus_S = l_modulus2_S;
                                    l_publicKey2_S.exponent_S = l_exponent2_S; 
#endif
                                    #ifdef    CA_VERBOSE
                                        printf("\n Execution Crypto_RSASSA_PKCS1_v1_5_SHA256_Verify");
                                    #endif   
                                    	if ((ctx != NULL) || (!SANITY_CHECK_POINTER_TYPE(message)) || (!SANITY_CHECK_POINTER_TYPE(signature)) || (key_len != 0U))
                                    	{   
                                    		if(memset(&operation, 0, sizeof(operation)) == (&operation))
                                            {   
                                    	    	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_VALUE_INPUT, TEEC_NONE);
#ifdef INTERNAL_DEV_KEY
                                    	    	if(key_len == RSA_2K){
                                    	    		p_publicKey_S = l_publicKey2_S;
                                    	    		operation.params[2].value.a = RSA_2K;
                                    	    	}
                                    	    	else if(key_len == RSA_3K)
                                        	    {
                                        	    	p_publicKey_S = l_publicKey3_S;
                                        	    	operation.params[2].value.a = RSA_3K;
                                        	    }
                                        	    else
                                                {
                                    	        	printf("\n Invalid key length");
                                    	        }
                                    	        res = Crypto_SetuserRsaPubKey(ctx, &p_publicKey_S, key_len);
                                    	        if (res != TEEC_SUCCESS)
                                                {
                                    	        	printf("\n Unable to get the usr key");
                                    	        }
                                    	        else
                                                {
#endif
                                    	        	operation.params[0].tmpref.buffer = message->data_U8P;
                                    	        	operation.params[0].tmpref.size   = message->length_U32;
                                    	        	operation.params[1].tmpref.buffer = signature->data_U8P;
                                    	        	operation.params[1].tmpref.size   = signature->length_U32;
#ifndef INTERNAL_DEV_KEY
                                                    operation.params[2].value.a       = key_len;
#endif
                                    	        	// Invoke the **same** RSA-SSA-PKCS1-v1_5-SHA256 verification command for **both 2K and 3K**
                                    	        	res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_RSASSA_PKCS1_V1_5_SHA256_VERIFY, &operation, &origin);
                                    	            		if (res != TEEC_SUCCESS)
                                                            {
                                    	            			printf("\n Failed to invoke RSA-SSA-PKCS1-v1_5-SHA256 verification");
                                                                printf("\n res    = 0x%08x", res);
                                                                printf("\n origin = 0x%08x\n", origin);
                                    	            		}
                                                		else
                                                        {
                                                			//for misra
                                                		}
                                                		switch (res) {
                                    	        	case TEEC_SUCCESS:
                                    	        		printf("\n Signature verification successfull.\n");
                                    	        		break;
                                    	        	case TEEC_ERROR_SHORT_BUFFER:
                                                        break;
                                    	        	case TEEC_ERROR_ITEM_NOT_FOUND:
                                    	        		break;
                                    	        	default:
                                    	        		printf("\n Command RSA-SSA-PKCS1-v1_5-SHA256 verification failed: ");
                                                        break;
                                    	        	}
#ifdef INTERNAL_DEV_KEY
                                    	        }
#endif
                                            }
                                            else
                                            {
                                            printf("\n[CA] MEMSET Failed\n");
                                            res = TEEC_ERROR_GENERIC;
                                            }
                                        }
                                        else
                    	                {
                    	                	printf("\n Crypto_RSASSA_PKCS1_v1_5_SHA256_Verify : sanity check failed\n");
                    	                	res = TEEC_ERROR_SHORT_BUFFER;
                    	                }
#ifdef INTERNAL_DEV_KEY
                                }
                                else
                                {
                                     printf("\n[CA] MEMCPY Failed\n");
                                     res = TEEC_ERROR_GENERIC;
                                }
                            }
                        }
                        else
                        {
                            printf("\n[CA] MEMCPY Failed\n");
                            res = TEEC_ERROR_GENERIC;
                        }
                        if(l_modulus2_S.data_U8P != NULL)
                        {
                            free(l_modulus2_S.data_U8P);
                        }
                        if(l_exponent2_S.data_U8P != NULL)
                        {
                            free(l_exponent2_S.data_U8P);
                        }
                    }
                }
                else
                {
                     printf("\n[CA] MEMCPY Failed\n");
                     res = TEEC_ERROR_GENERIC;
                }
            }
            if(l_exponent3_S.data_U8P != NULL)
            {
                free(l_exponent3_S.data_U8P);
            }
            if(l_modulus3_S.data_U8P)
            {
                free(l_modulus3_S.data_U8P);
            }
        }
        else
        {
            printf("\n[CA] MEMCPY Failed\n");
            res = TEEC_ERROR_GENERIC;
        }
    }
#endif
#ifdef CA_VERBOSE
    printf("\n Exit Crypto_RSASSA_PKCS1_v1_5_SHA256_Verify");
#endif
    return res;
}

TEEC_Result SecurityManagerAes128CbcDecryptionfile(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const uint8_t* p_InitialVectorPtr_pU8,
                                          uint8_t p_InitialVectorLength_pU8, FILE* p_cipherTextFile_p,
                                          FILE* p_plainTextFile_p)
{
	TEEC_Operation operation;
	TEEC_Result res = TEEC_ERROR_GENERIC;
	uint32_t origin;
	uint8_t           l_InitialVectorPtr_pU8[16] = {0};
    size_t            bytes_read                 =  0U;
    size_t            bytes_write                =  0U;
    uint8_t l_CipherTextPtr_pU8[512]             = {0};
    uint8_t l_PlainTextPtr_pU8[512]              = {0};

#ifdef CA_VERBOSE
	printf("\n Execution SecurityManagerAes128CbcDecryptionfile");
#endif

	if ((p_InitialVectorLength_pU8 == 16U) && (p_cipherTextFile_p != NULL) && (p_plainTextFile_p != NULL)
			&& ((key_id != NULL)) && (keyid_size != 0U))
	{
		res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
		if (res != TEEC_SUCCESS) 
        {
			printf("\n Unable to get the decryption key");
    	}
		else {
			if (l_InitialVectorPtr_pU8 == memcpy(l_InitialVectorPtr_pU8, p_InitialVectorPtr_pU8, (size_t)16U))
        	{
				while ((uint8_t)0 != (bytes_read = fread(l_CipherTextPtr_pU8, 1, 512, p_cipherTextFile_p))) {
                
					if ((bytes_read % 16U) == 0U) {
						if(memset(&operation, 0, sizeof(operation)) == (&operation))
                        {
					    	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE);
    				    	operation.params[0].tmpref.buffer = l_CipherTextPtr_pU8;
    				    	operation.params[0].tmpref.size   = bytes_read;
					    	operation.params[1].tmpref.buffer = l_InitialVectorPtr_pU8;
 					    	operation.params[1].tmpref.size   = p_InitialVectorLength_pU8;
    				    	operation.params[2].tmpref.buffer = l_PlainTextPtr_pU8;
    				    	operation.params[2].tmpref.size   = bytes_read;
					    	// Invoke AES encryption command
    				    	res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_DECRYPTNOPAD, &operation, &origin);
    				    	if (res != TEEC_SUCCESS)    
                            {
        			    		printf("\n Failed to invoke AES Decryption");
    				    	}
					    	else {
                            	if(l_InitialVectorPtr_pU8 != memcpy(l_InitialVectorPtr_pU8, &l_CipherTextPtr_pU8[bytes_read - 16U], (size_t)16U))
                            	{
                                	printf("\n[CA] MEMCPY Failed\n");
                                    res = TEEC_ERROR_GENERIC;
                            	}
                                else{
                                	bytes_write = fwrite(l_PlainTextPtr_pU8, 1U, bytes_read, p_plainTextFile_p);
                                	if (bytes_write == bytes_read)
                                	{
					    	    		// for misra;
                                	}
                                	else
                                	{
                                    	printf("\n Unable to write to FILE\n");
                                    	break;
                                	}
                                }
					    	}
                        }
                        else{
                            printf("\n[CA] MEMSET Failed\n");
                            res = TEEC_ERROR_GENERIC;
                        }
					}
				}
			}
		}
	}
	else
    {
        printf("\n SANITY CHECK FAILED\n");
    }

#ifdef CA_VERBOSE
	printf("\n Exit SecurityManagerAes128CbcDecryptionfile");
#endif

	return res;
}

TEEC_Result Crypto_SHA256_Start(struct TEE_resource_ctx *ctx) {
	TEEC_Operation operation;
	TEEC_Result res;
	uint32_t origin;

#ifdef CA_VERBOSE
	printf("\n Execution Crypto_SHA256_Start");
#endif

	if(memset(&operation, 0, (sizeof(operation))) == (&operation))
    {
	    operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_NONE, TEEC_NONE, TEEC_NONE, TEEC_NONE);

        // Invoke AES sha256 hash computation start command
        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_SHA256_START, &operation, &origin);
        if (res != TEEC_SUCCESS)
        {
            printf("\n Failed to invoke AES SHA256 hash computation start \n ");
        }
	    switch (res) {
	    case TEEC_SUCCESS:
            break;
	    case TEEC_ERROR_SHORT_BUFFER:
            break;
	    case TEEC_ERROR_ITEM_NOT_FOUND:
	    	break;
	    default:
	    	printf("\n Command AES SHA256 hash computation start failed : \n ");
            break;
	    }
    }
    else{
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }

#ifdef CA_VERBOSE
	printf("\n Exit Crypto_SHA256_Start \n");
#endif

	return res;
}

TEEC_Result Crypto_SHA256_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *Plaintext) {
	TEEC_Operation operation;
	TEEC_Result res;
	uint32_t origin;

	#ifdef CA_VERBOSE
		printf("\n Execution Crypto_SHA256_Update \n");
	#endif

	if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
	    operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
	    operation.params[0].tmpref.buffer = Plaintext->data_U8P;
	    operation.params[0].tmpref.size   = Plaintext->length_U32;


	    // Invoke AES encryption command
	    res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_SHA256_UPDATE, &operation, &origin);
	    if (res != TEEC_SUCCESS)
        {
	    	printf("\n Failed to invoke AES SHA256 hash computation update \n");
	    }
	    switch (res) {
	    	case TEEC_SUCCESS:
                break;
	    	case TEEC_ERROR_SHORT_BUFFER:
                break;
	    	case TEEC_ERROR_ITEM_NOT_FOUND:
        		break;
	    	default:
	    	printf("\n  Command AES SHA256 hash computation update failed : \n");
            break;
	    }
    }
    else
    {
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }
	#ifdef CA_VERBOSE
	printf("\n Exit Crypto_SHA256_Update");
	#endif

	return res;
}

TEEC_Result Crypto_SHA256_Final(struct TEE_resource_ctx *ctx, ts_pointerType *Digest) {
	TEEC_Operation operation;
	TEEC_Result res;
	uint32_t origin;

#ifdef CA_VERBOSE
	printf("\n Execution Crypto_SHA256_Final");
#endif

	if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
    	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
        operation.params[0].tmpref.buffer = Digest->data_U8P;
        operation.params[0].tmpref.size   = Digest->length_U32;
        

        // Invoke AES encryption command
        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_SHA256_FINISH, &operation, &origin);
        if (res != TEEC_SUCCESS)
        {
            printf("\n Failed to invoke AES SHA256 hash computation final \n");
        }
    	switch (res) {
    	case TEEC_SUCCESS:
            break;
    	case TEEC_ERROR_SHORT_BUFFER:
            break;
    	case TEEC_ERROR_ITEM_NOT_FOUND:
    		break;
    	default:
    		printf("\n Command AES SHA256 hash computation final failed : \n");
            break;
    	}

    	Digest->length_U32 = operation.params[0].tmpref.size;
    }
    else{
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }
#ifdef CA_VERBOSE
	printf("\n Exit Crypto_SHA256_Final \n");
#endif

	return res;
}

TEEC_Result Crypto_SHA512_Start(struct TEE_resource_ctx *ctx) {
	TEEC_Operation operation;
	TEEC_Result res;
	uint32_t origin;

#ifdef CA_VERBOSE
	printf("\n Execution Crypto_SHA512_Start");
#endif

	if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
    	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_NONE, TEEC_NONE, TEEC_NONE, TEEC_NONE);

        // Invoke AES sha256 hash computation start command
        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_SHA512_START, &operation, &origin);
        if (res != TEEC_SUCCESS)
        {
            printf("\n Failed to invoke AES SHA512 hash computation start \n ");
        }
    	switch (res) {
    	case TEEC_SUCCESS:
            break;
    	case TEEC_ERROR_SHORT_BUFFER:
            break;
    	case TEEC_ERROR_ITEM_NOT_FOUND:
    		break;
    	default:
    		printf("\n Command AES SHA512 hash computation start failed : \n ");
            break;
    	}
    }
    else{
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }

#ifdef CA_VERBOSE
	printf("\n Exit Crypto_SHA512_Start \n");
#endif

	return res;
}

TEEC_Result Crypto_SHA512_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *Plaintext) {
	TEEC_Operation operation;
	TEEC_Result res;
	uint32_t origin;

	#ifdef CA_VERBOSE
		printf("\n Execution Crypto_SHA256_Update \n");
	#endif

	if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
	    operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
	    operation.params[0].tmpref.buffer = Plaintext->data_U8P;
	    operation.params[0].tmpref.size   = Plaintext->length_U32;


	    // Invoke AES encryption command
	    res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_SHA512_UPDATE, &operation, &origin);
	    if (res != TEEC_SUCCESS)
        {
	    	printf("\n Failed to invoke AES SHA512 hash computation update \n");
	    }
	    switch (res) {
	    	case TEEC_SUCCESS:
                break;
	    	case TEEC_ERROR_SHORT_BUFFER:
                break;
	    	case TEEC_ERROR_ITEM_NOT_FOUND:
	    	break;
	    	default:
	    	printf("\n  Command AES SHA512 hash computation update failed : \n");
            break;
	    }
    }
    else{
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }
	#ifdef CA_VERBOSE
	printf("\n Exit Crypto_SHA384_Update");
	#endif

	return res;
}

TEEC_Result Crypto_SHA512_Final(struct TEE_resource_ctx *ctx, ts_pointerType *Digest) {
	TEEC_Operation operation;
	TEEC_Result res = TEEC_SUCCESS;
	uint32_t origin;

#ifdef CA_VERBOSE
	printf("\n Execution Crypto_SHA512_Final");
#endif

    if ((ctx == NULL) || (SANITY_CHECK_POINTER_TYPE(Digest)) || (Digest->length_U32 == AES_SHA512_SIZE)){
        if(memset(&operation, 0, sizeof(operation)) == (&operation))
        {
            operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
            operation.params[0].tmpref.buffer = Digest->data_U8P;
            operation.params[0].tmpref.size   = Digest->length_U32;

            // Invoke AES encryption command
            res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_SHA512_FINISH, &operation, &origin);
            if (res != TEEC_SUCCESS)
            {
                printf("\n Failed to invoke AES SHA384 hash computation final \n");
            }
            switch (res) {
            case TEEC_SUCCESS:
                break;
            case TEEC_ERROR_SHORT_BUFFER:
                break;
            case TEEC_ERROR_ITEM_NOT_FOUND:
                break;
            default:
                printf("\n Command AES SHA512 hash computation final failed : \n");
                break;
            }

            Digest->length_U32 = operation.params[0].tmpref.size;
        }
        else
        {
            printf("\n[CA] MEMSET Failed\n");
            res = TEEC_ERROR_GENERIC;
        }
    }
    else {
        printf("\n Insufficient memory for sha512 digest \n");
        res = TEEC_ERROR_SHORT_BUFFER;
    }
	
#ifdef CA_VERBOSE
	printf("\n Exit Crypto_SHA512_Final \n");
#endif

	return res;
}

TEEC_Result Crypto_SHA384_Start(struct TEE_resource_ctx *ctx) {
	TEEC_Operation operation;
	TEEC_Result res;
	uint32_t origin;

#ifdef CA_VERBOSE
	printf("\n Execution Crypto_SHA384_Start");
#endif

	if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
    	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_NONE, TEEC_NONE, TEEC_NONE, TEEC_NONE);

        // Invoke AES sha256 hash computation start command
        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_SHA384_START, &operation, &origin);
        if (res != TEEC_SUCCESS)
        {
            printf("\n Failed to invoke AES SHA384 hash computation start \n ");
        }
    	switch (res) {
    	case TEEC_SUCCESS:
            break;
    	case TEEC_ERROR_SHORT_BUFFER:
            break;
    	case TEEC_ERROR_ITEM_NOT_FOUND:
    		break;
    	default:
    		printf("\n Command AES SHA384 hash computation start failed : \n ");
            break;
    	}
    }
    else{
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }

#ifdef CA_VERBOSE
	printf("\n Exit Crypto_SHA384_Start \n");
#endif

	return res;
}

TEEC_Result Crypto_SHA384_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *Plaintext) {
	TEEC_Operation operation;
	TEEC_Result res;
	uint32_t origin;

	#ifdef CA_VERBOSE
		printf("\n Execution Crypto_SHA256_Update \n");
	#endif

	if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
	    operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
	    operation.params[0].tmpref.buffer = Plaintext->data_U8P;
	    operation.params[0].tmpref.size   = Plaintext->length_U32;


	    // Invoke AES encryption command
	    res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_SHA384_UPDATE, &operation, &origin);
	    if (res != TEEC_SUCCESS)
        {
	    	printf("\n Failed to invoke AES SHA384 hash computation update \n");
	    }
	    switch (res) {
	    	case TEEC_SUCCESS:
                break;
	    	case TEEC_ERROR_SHORT_BUFFER:
                break;
	    	case TEEC_ERROR_ITEM_NOT_FOUND:
	    	break;
	    	default:
	    	printf("\n  Command AES SHA384 hash computation update failed : \n");
            break;
	    }
    }
    else{
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }
	#ifdef CA_VERBOSE
	printf("\n Exit Crypto_SHA384_Update");
	#endif

	return res;
}

TEEC_Result Crypto_SHA384_Final(struct TEE_resource_ctx *ctx, ts_pointerType *Digest) {
	TEEC_Operation operation;
	TEEC_Result res;
	uint32_t origin;

#ifdef CA_VERBOSE
	printf("\n Execution Crypto_SHA384_Final");
#endif

	if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
	    operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
        operation.params[0].tmpref.buffer = Digest->data_U8P;
        operation.params[0].tmpref.size   = Digest->length_U32;
        

        // Invoke AES encryption command
        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_SHA384_FINISH, &operation, &origin);
        if (res != TEEC_SUCCESS)
        {
            printf("\n Failed to invoke AES SHA384 hash computation final \n");
        }
	    switch (res) {
	    case TEEC_SUCCESS:
            break;
	    case TEEC_ERROR_SHORT_BUFFER:
            break;
	    case TEEC_ERROR_ITEM_NOT_FOUND:
	    	break;
	    default:
	    	printf("\n Command AES SHA384 hash computation final failed : \n");
            break;
	    }

	    Digest->length_U32 = operation.params[0].tmpref.size;
    }
    else
    {
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }
#ifdef CA_VERBOSE
	printf("\n Exit Crypto_SHA384_Final \n");
#endif

	return res;
}

TEEC_Result Crypto_SymKeyCheckStatus(struct TEE_resource_ctx *ctx) {
	TEEC_Operation operation;
    TEEC_Result res = TEEC_ERROR_BAD_PARAMETERS;
    uint32_t origin = 0U;


#ifdef CA_VERBOSE
    printf("\n[CA] Entering Crypto_SymKeyCheckStatus \n");
#endif

	// Input validation sanity check
	if (ctx == NULL) {
		printf("\n[CA] Invalid input parameters to AES128CBC_Decrypt_Start\n");
        res = TEEC_ERROR_BAD_PARAMETERS;
	}
	else {

		if(memset(&operation, 0, sizeof(operation)) == (&operation))
        {
            operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_NONE, TEEC_NONE, TEEC_NONE, TEEC_NONE);
            
		    res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_SYM_KEY_CHECK, &operation, &origin);
        }
        else{
            printf("\n[CA] MEMSET Failed\n");
            res = TEEC_ERROR_GENERIC;
        }
	}

#ifdef CA_VERBOSE
	printf("\n[CA] Exiting Crypto_SymKeyCheckStatus \n");
#endif

	return res;
}

/******************************************************************************************************************************************
** Function: Crypto_AES128CBC_Decrypt_Start
********************************************************************************************************************************************/

TEEC_Result Crypto_AES128CBC_Decrypt_Start(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType* iv) {
    TEEC_Operation operation;
    TEEC_Result res = TEEC_SUCCESS;
    uint32_t origin = 0U;

#ifdef CA_VERBOSE
    printf("\n[CA] Entering Crypto_AES128CBC_Decrypt_Start\n");
#endif

    /* Input validation */
    if ((ctx == NULL) || (key_id == NULL) || (keyid_size == 0U) ||
        (iv == NULL) || (iv->data_U8P == NULL) || (iv->length_U32 != AES_BLOCK_SIZE)) 
    {
        printf("\n[CA] Invalid input parameters to AES128CBC_Decrypt_Start\n");
        res = TEEC_ERROR_BAD_PARAMETERS;
    }
    else
    {
        /* Get the key status */
        res = Crypto_SymKeyCheckStatus(ctx);
        printf("\n[CA] Crypto_SymKeyCheckStatus return : 0x%08X\n", res);

        if (res != TEEC_SUCCESS)
        {
            res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
            if (res != TEEC_SUCCESS)
            {
                printf("\n[CA] Failed to get key from blob. Error: 0x%08X\n", res);
            }
            /* else: key already set, no action needed */
        }
        else
        {
            /* Key is already set, no need to load from blob */
			/* Adding for misra */
        }

        if (res == TEEC_SUCCESS)
        {
            if(memset(&operation, 0, sizeof(operation)) == (&operation))
            {
                operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
                operation.params[0].tmpref.buffer = iv->data_U8P;
                operation.params[0].tmpref.size   = iv->length_U32;

                res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_CBC_DECRYPT_START, &operation, &origin);
                if (res == TEEC_SUCCESS)
                {
                    printf("[CA] CBC decryption start passed ret : 0x%08X\n", res);
                }
                else
                {
                    printf("\n[CA] Failed to invoke AES128 CBC decryption start. Error: 0x%08X\n", res);
                }
            }
            else
            {
                printf("\n[CA] MEMSET Failed\n");
                res = TEEC_ERROR_GENERIC;
            }
        }
        else
        {
            /* Key load failed, already logged */
			/* Adding for misra */
        }
    }

#ifdef CA_VERBOSE
    printf("\n[CA] Exiting Crypto_AES128CBC_Decrypt_Start with result: 0x%08X\n", res);
#endif

    return res;
}

/******************************************************************************************************************************************
** Function: Crypto_AES128CBC_Decrypt_Update
********************************************************************************************************************************************/

TEEC_Result Crypto_AES128CBC_Decrypt_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *Ciphertext, ts_pointerType *Plaintext) {
    TEEC_Operation operation;
    TEEC_Result res = TEEC_SUCCESS;
    uint32_t origin = 0U;
	uint8_t * tempOutBuf_pU8;
    size_t tempOutBufLen_pU32 = 0U;

#ifdef CA_VERBOSE
    printf("\n Execution Crypto_AES128CBC_Decrypt_Update \n");
#endif

	if ((ctx == NULL) || (SANITY_CHECK_POINTER_TYPE(Plaintext)) || (SANITY_CHECK_POINTER_TYPE(Ciphertext))) {
		printf("\n Crypto_AES128CBC_Decrypt_Update : sanity check failed\n");
		res = TEEC_ERROR_SHORT_BUFFER;
	}
	else 
    {
		tempOutBufLen_pU32 = (size_t)Plaintext->length_U32;
        tempOutBuf_pU8     = malloc(tempOutBufLen_pU32);
        if(tempOutBuf_pU8 != NULL)
        {
            if(memset(tempOutBuf_pU8, 0, tempOutBufLen_pU32) == (tempOutBuf_pU8))
            {
		        if(memset(&operation, 0, sizeof(operation)) == (&operation))
                {
		            operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE);
		            operation.params[0].tmpref.buffer = Ciphertext->data_U8P;
		            operation.params[0].tmpref.size   = Ciphertext->length_U32;
		            operation.params[1].tmpref.buffer = tempOutBuf_pU8;
		            operation.params[1].tmpref.size   = tempOutBufLen_pU32;

		            res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_CBC_DECRYPT_UPDATE, &operation, &origin);
		            if (res == TEEC_SUCCESS)
                        {
                            if (operation.params[1].tmpref.size <= UINT32_MAX)
                            {
                                Plaintext->length_U32 = (uint32_t)operation.params[1].tmpref.size;
                                if(tempOutBuf_pU8 == NULL)
                                {
                                    res = TEEC_ERROR_OUT_OF_MEMORY;
                                }
                                else
                                {
                                    if(memcpy(Plaintext->data_U8P, tempOutBuf_pU8, (size_t)Plaintext->length_U32) == (Plaintext->data_U8P))
                                    {
                                        printf("[CA] Crypto_AES128CBC_Decrypt_Update passed ret : 0x%08X\n", res);
                                    }
                                    else{
                                        printf("\n[CA] MEMCPY Failed\n");
                                        res = TEEC_ERROR_GENERIC;
                                    }
                                }
                            }
                            else
                            {
                                res = TEEC_ERROR_EXCESS_DATA;
                            }
                        }
                        else
                        {
                            printf("\n AES Decryption failed, ret = 0x%08X\n", res);
                            switch (res)
                            {
                                case TEEC_ERROR_SHORT_BUFFER:
                                    break;
                                case TEEC_ERROR_ITEM_NOT_FOUND:
                                    break;
                                default:
                                    printf("Command AES Decryption failed\n");
                                    break;
                            }
                        }
                }
                else{
                    printf("\n[CA] MEMSET Failed\n");
                    res = TEEC_ERROR_GENERIC;
                }
                if(tempOutBuf_pU8 != NULL)
                {
                    free(tempOutBuf_pU8);
                }
            }
            else
            {
                printf("\n[CA] MEMSET Failed\n");
                res = TEEC_ERROR_GENERIC;
                free(tempOutBuf_pU8);
            }
        }
        else
        {
            printf("\n[CA] tempOutBuf_pU8 is NULL\n");
            res = TEEC_ERROR_GENERIC;
        }
	}
#ifdef CA_VERBOSE
    printf("\n Exit Crypto_AES128CBC_Decrypt_Update \n");
#endif

    return res;
}

/******************************************************************************************************************************************
** Function: Crypto_AES128CBC_Decrypt_Final
********************************************************************************************************************************************/

TEEC_Result Crypto_AES128CBC_Decrypt_Final(struct TEE_resource_ctx *ctx, ts_pointerType *Plaintext) {
    TEEC_Operation operation = {0};
    TEEC_Result res = TEEC_SUCCESS;
    uint32_t origin = 0U;
	uint8_t *tempOutBuf_pU8 = NULL;
    size_t tempOutBufLen_pU32 = 0U;

#ifdef CA_VERBOSE
    printf("\n Execution Crypto_AES128CBC_Decrypt_Update \n");
#endif

	if ((ctx == NULL) || (SANITY_CHECK_POINTER_TYPE(Plaintext))) {
		printf("\n Crypto_AES128CBC_Decrypt_Update : sanity check failed\n");
		res = TEEC_ERROR_SHORT_BUFFER;
	}
	else {
		tempOutBufLen_pU32 = Plaintext->length_U32;
        tempOutBuf_pU8     = malloc(tempOutBufLen_pU32);
        if(tempOutBuf_pU8 != NULL)
        {
            if(memset(tempOutBuf_pU8, 0, tempOutBufLen_pU32) == (tempOutBuf_pU8))
            {
		        if(memset(&operation, 0, sizeof(operation)) == (&operation))
                {
		        operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE);
		        operation.params[0].tmpref.buffer = Plaintext->data_U8P;
		        operation.params[0].tmpref.size   = Plaintext->length_U32;
		        operation.params[1].tmpref.buffer = tempOutBuf_pU8;
		        operation.params[1].tmpref.size   = tempOutBufLen_pU32;

		        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_CBC_DECRYPT_FINISH, &operation, &origin);
		        if (res == TEEC_SUCCESS)
                    {
                        if (operation.params[1].tmpref.size <= UINT32_MAX)
                        {
                            Plaintext->length_U32 = (uint32_t)operation.params[1].tmpref.size;
                            if(tempOutBuf_pU8 == NULL)
                            {
                                res = TEEC_ERROR_OUT_OF_MEMORY;
                            }
                            else
                            {
                                if(memcpy(Plaintext->data_U8P, tempOutBuf_pU8, (size_t)Plaintext->length_U32) == (Plaintext->data_U8P))
                                {
                                    printf("[CA] Crypto_AES128CBC_Decrypt_Final passed ret : 0x%08X\n", res);
                                }
                                else{
                                    printf("\n[CA] MEMCPY Failed\n");
                                    res = TEEC_ERROR_GENERIC;
                                }
                            }
                        }
                        else
                        {
                            res = TEEC_ERROR_EXCESS_DATA;
                        }
                    }
                    else
                    {
                        printf("\n Failed to invoke AES Decryption, ret = 0x%08X\n", res);
                        switch (res)
                        {
                            case TEEC_ERROR_SHORT_BUFFER:
                                break;
                            case TEEC_ERROR_ITEM_NOT_FOUND:
                                break;
                            default:
                                printf("\n Command AES Decryption failed\n");
                                break;
                        }
                    }

		        free(tempOutBuf_pU8);
                }
                else{
                    printf("\n[CA] MEMSET Failed\n");
                    res = TEEC_ERROR_GENERIC;
                }
            }
            else
            {
                printf("\n[CA] MEMSET Failed\n");
                res = TEEC_ERROR_GENERIC;
            }
        }
        else
        {
            printf("\n[CA] tempOutBuf_pU8 is Null\n");
            res = TEEC_ERROR_GENERIC;
        }
	}
#ifdef CA_VERBOSE
    printf("\n[CA] Exiting Crypto_AES128CBC_Decrypt_Final with result: 0x%08X\n", res);
#endif

    return res;
}

/******************************************************************************************************************************************
************************************ GCM_decryption *********************************************
** Function: Crypto_AES128GCM_Decrypt_Start
********************************************************************************************************************************************/

TEEC_Result Crypto_AES128GCM_Decrypt_Start(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType* iv) {
	TEEC_Operation operation;
	TEEC_Result res = TEEC_SUCCESS;
	uint32_t origin = 0U;

#ifdef CA_VERBOSE
	printf("\n[CA] Entering Crypto_AES128GCM_Decrypt_Start\n");
#endif

	if ((ctx == NULL) || (key_id == NULL) || (keyid_size == 0U) ||
		(iv == NULL) || (iv->data_U8P == NULL) || (iv->length_U32 != AES_GCM_IV_RECOMMENDED_LEN)) {
		printf("\n[CA] Invalid input parameters to AES128GCM_Decrypt_Start\n");
		res = TEEC_ERROR_BAD_PARAMETERS;
	}
    else {
		res = Crypto_SymKeyCheckStatus(ctx);
		printf("\n[CA]  Crypto_SymKeyCheckStatus return : 0x%08X\n", res);

		if (res != TEEC_SUCCESS)
        {
			res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
        }
		if (res != TEEC_SUCCESS)
        {
			printf("\n[CA] Failed to get key from blob. Error: 0x%08X\n", res);
		} else {
			if(memset(&operation, 0, sizeof(operation)) == (&operation))
            {
		    	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
		    	operation.params[0].tmpref.buffer = iv->data_U8P;
		    	operation.params[0].tmpref.size   = iv->length_U32;

		    	res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_GCM_DECRYPT_START, &operation, &origin);

		    	if (res != TEEC_SUCCESS) 
                {
		    		printf("\n[CA] Failed to invoke AES128 GCM decryption start. Error: 0x%08X\n", res);
		    	} else {
		    		printf("[CA]  GCM decryption start passed ret : 0x%08X\n", res);
		    	}
            }
            else{
                printf("\n[CA] MEMSET Failed\n");
                res = TEEC_ERROR_GENERIC;
            }
		}
	}

#ifdef CA_VERBOSE
	printf("\n[CA] Exiting Crypto_AES128GCM_Decrypt_Start with result: 0x%08X\n", res);
#endif

	return res;
}

/******************************************************************************************************************************************
** Function: Crypto_AES128GCM_Decrypt_Update
********************************************************************************************************************************************/

TEEC_Result Crypto_AES128GCM_Decrypt_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *Ciphertext, ts_pointerType *Plaintext) {
	TEEC_Operation operation;
	TEEC_Result res = TEEC_SUCCESS;
	uint32_t origin;
	uint8_t * tempOutBuf_pU8;
	size_t tempOutBufLen_pU32 = 0U;
#ifdef CA_VERBOSE
	printf("\n Execution Crypto_AES128GCM_Decrypt_Update \n");
#endif
	if ((ctx == NULL) || (SANITY_CHECK_POINTER_TYPE(Plaintext)) || (SANITY_CHECK_POINTER_TYPE(Ciphertext))) {
		printf("\n Crypto_AES128GCM_Decrypt_Update : sanity check failed\n");
		res = TEEC_ERROR_SHORT_BUFFER;
	}
    else {
		tempOutBufLen_pU32 = Plaintext->length_U32;
        tempOutBuf_pU8     = malloc(tempOutBufLen_pU32);
        if(tempOutBuf_pU8 != NULL)
        {
            if(memset(tempOutBuf_pU8, 0, tempOutBufLen_pU32) == (tempOutBuf_pU8))
            {
		        if(memset(&operation, 0, sizeof(operation)) == (&operation))
                {
	            	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE);
	            	operation.params[0].tmpref.buffer = Ciphertext->data_U8P;
	            	operation.params[0].tmpref.size   = Ciphertext->length_U32;
	            	operation.params[1].tmpref.buffer = tempOutBuf_pU8;
	            	operation.params[1].tmpref.size   = tempOutBufLen_pU32;
	            	res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_GCM_DECRYPT_UPDATE, &operation, &origin);
	            	if (res != TEEC_SUCCESS)
                    {
	            		printf("\n Failed to invoke AES GCM Decryption update\n");
	            	}
	            	switch (res) {
	            		case TEEC_SUCCESS:
	            			printf("[CA]  Crypto_AES128GCM_Decrypt_Update passed ret : 0x%08X\n", res);
                            break;
                        case TEEC_ERROR_SHORT_BUFFER:
                            break;
	            		case TEEC_ERROR_ITEM_NOT_FOUND:
	            			break;
	            		default:
	            			printf("\n Command AES GCM Decryption failed : ");
                            break;
	            	}
                    if (operation.params[1].tmpref.size <= UINT32_MAX)
                    {
	            	    Plaintext->length_U32 = (uint32_t)operation.params[1].tmpref.size;
                        if(tempOutBuf_pU8 == NULL)
                        {
                            res = TEEC_ERROR_OUT_OF_MEMORY;
                        }
                        else
                        {
	            	        if(memcpy(Plaintext->data_U8P, tempOutBuf_pU8, (size_t)Plaintext->length_U32) == (Plaintext->data_U8P))
                            {
	            	            free(tempOutBuf_pU8);
                            }
                            else{
                                free(tempOutBuf_pU8);
                                printf("\n[CA] MEMCPY Failed\n");
                                res = TEEC_ERROR_GENERIC;
                            }
                        }
                    }
                    else
                    {
                        res = TEEC_ERROR_EXCESS_DATA;
                    }
                }
                else{
                    free(tempOutBuf_pU8);
                    printf("\n[CA] MEMSET Failed\n");
                    res = TEEC_ERROR_GENERIC;
                }
            }
            else
            {
                free(tempOutBuf_pU8);
                printf("\n[CA] MEMSET Failed\n");
                res = TEEC_ERROR_GENERIC;
            }
        }
	}

#ifdef CA_VERBOSE
	printf("\n Exit Crypto_AES128GCM_Decrypt_Update \n");
#endif
	return res;
}
/******************************************************************************************************************************************
** Function: Crypto_AES128GCM_Decrypt_Final
********************************************************************************************************************************************/

TEEC_Result Crypto_AES128GCM_Decrypt_Final(struct TEE_resource_ctx *ctx, ts_pointerType *Plaintext, ts_pointerType *Tag)
{
    TEEC_Operation operation;
    TEEC_Result res = TEEC_SUCCESS;
    uint32_t origin = 0U;
    uint8_t *tempOutBuf_pU8 = NULL;

#ifdef CA_VERBOSE
    printf("\n[CA] Entering Crypto_AES128GCM_Decrypt_Final\n");
#endif

    if ((ctx != NULL) && !SANITY_CHECK_POINTER_TYPE(Plaintext) && !SANITY_CHECK_POINTER_TYPE(Tag))
    {
        if (Tag->length_U32 != AES_GCM_TAG_SIZE)
        {
            printf("\n[CA] Invalid GCM tag length: %u\n", Tag->length_U32);
            res = TEEC_ERROR_BAD_PARAMETERS;
        }
        else
        {
#ifdef CA_VERBOSE
            printf("[CA] Auth Tag: ");
            for (uint32_t i = 0U; i < Tag->length_U32; i++)
                printf("0x%02X ", Tag->data_U8P[i]);
            printf("\n");
#endif
            tempOutBuf_pU8 = malloc(Plaintext->length_U32);
            if(tempOutBuf_pU8 != NULL)
            {
                if(memset(tempOutBuf_pU8, 0, (size_t)Plaintext->length_U32) == (tempOutBuf_pU8))
                {
                    if(memset(&operation, 0, sizeof(operation)) == (&operation))
                    {
                        operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT,
                                                                TEEC_MEMREF_TEMP_OUTPUT,
                                                                TEEC_NONE,
                                                                TEEC_NONE);
                        operation.params[0].tmpref.buffer = Tag->data_U8P;
                        operation.params[0].tmpref.size   = Tag->length_U32;
                        operation.params[1].tmpref.buffer = tempOutBuf_pU8;
                        operation.params[1].tmpref.size   = Plaintext->length_U32;
                        
                        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_AES_GCM_DECRYPT_FINAL, &operation, &origin);
                        if (res == TEEC_SUCCESS)
                        {
                            if (operation.params[1].tmpref.size <= UINT32_MAX)
                            {
                                Plaintext->length_U32 = (uint32_t)operation.params[1].tmpref.size;
                                if(memcpy(Plaintext->data_U8P, tempOutBuf_pU8, (size_t)Plaintext->length_U32) == (Plaintext->data_U8P))
                                {
                                    printf("[CA] Crypto_AES128GCM_Decrypt_Final passed ret: 0x%08X\n", res);
                                }
                                else{
                                    printf("\n[CA] MEMCPY Failed\n");
                                    res = TEEC_ERROR_GENERIC;
                                }
                            }
                            else
                            {
                                res = TEEC_ERROR_EXCESS_DATA;
                            }
                        }
                        else
                        {
                            printf("\n[CA] Failed to invoke AES GCM Decryption Final, res: 0x%08X\n", res);
                        }
                    }
                    else{
                        printf("\n[CA] MEMSET Failed\n");
                        res = TEEC_ERROR_GENERIC;
                    }
                    if(tempOutBuf_pU8 != NULL)
                    {
                        free(tempOutBuf_pU8);
                    }
                }
                else{
                    free(tempOutBuf_pU8);
                    res = TEEC_ERROR_GENERIC;
                    printf("\n[CA] Crypto_AES128GCM_Decrypt_Final: MEMSET Failed\n");
                }
            }
            else
            {
                res = TEEC_ERROR_GENERIC;
                printf("\n[CA] tempOutBuf_pU8 is null\n");
            }
        }
    }
    else
    {
        printf("\n[CA] Crypto_AES128GCM_Decrypt_Final: sanity check failed\n");
        res = TEEC_ERROR_SHORT_BUFFER;
    }

#ifdef CA_VERBOSE
    printf("\n[CA] Exiting Crypto_AES128GCM_Decrypt_Final with result: 0x%08X\n", res);
#endif

    return res;
}

/******************************************************************************************************************************************
************************************ ECB_decryption *********************************************
** Function: Crypto_AES128ECB_Decrypt_Start
********************************************************************************************************************************************/

TEEC_Result Crypto_AES128ECB_Decrypt_Start(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size) {
    TEEC_Result    res     = TEEC_SUCCESS;
    TEEC_Operation operation;
    uint32_t       origin  = 0U;

#ifdef CA_VERBOSE
    printf("\n Entering Crypto_AES128ECB_Decrypt_Start \n");
#endif

    if ((ctx == NULL) || (key_id == NULL) || (keyid_size == 0U)) {
        printf("[CA] Invalid input to Decrypt_Start\n");
        res = TEEC_ERROR_BAD_PARAMETERS;
    }
    else {
        // Check if key is already present
        res = Crypto_SymKeyCheckStatus(ctx);

        if (res != TEEC_SUCCESS) {
            // Load the key into secure context if not already set
            printf("[CA] Key not set, loading key...\n");
            res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);

            if (res != TEEC_SUCCESS) {
                printf("[CA] Crypto_GetKeyFromBlob failed: 0x%08X\n", res);
            }
        }
        else
        {
            if (res == TEEC_SUCCESS) {
                // Invoke ECB decrypt start
                if(memset(&operation, 0, sizeof(operation)) == (&operation))
                {
                    operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_NONE,
                                                            TEEC_NONE,
                                                            TEEC_NONE,
                                                            TEEC_NONE);

                    res = TEEC_InvokeCommand(&ctx->sess,
                                             TA_CRYPTO_CMD_AES_ECB_DECRYPT_START,
                                             &operation,
                                             &origin);

                    if (res == TEEC_SUCCESS)
                    {
                        printf("[CA] AES ECB Decrypt Start: Success\n");
                    } else {
                        printf("[CA] AES ECB Decrypt Start failed: 0x%08X\n", res);
                    }
                }
                else{
                    printf("\n[CA] MEMSET Failed\n");
                    res = TEEC_ERROR_GENERIC;
                }
            }
        }
    }

#ifdef CA_VERBOSE
    printf("\n Exiting Crypto_AES128ECB_Decrypt_Start \n");
#endif

    return res;
}

/******************************************************************************************************************************************
** Function: Crypto_AES128ECB_Decrypt_Update
********************************************************************************************************************************************/

TEEC_Result Crypto_AES128ECB_Decrypt_Update(struct TEE_resource_ctx *ctx, ts_pointerType *Ciphertext, ts_pointerType *Plaintext) {
    TEEC_Result    res     = TEEC_SUCCESS;
    TEEC_Operation operation;
    uint32_t       origin  = 0U;
    uint8_t       *temp_out_buf_pU8 = NULL;
    size_t       temp_out_len_U32 = 0U;

#ifdef CA_VERBOSE
    printf("\n Entering Crypto_AES128ECB_Decrypt_Update \n");
#endif

    // Sanity checks
    if ((ctx == NULL) ||
        (SANITY_CHECK_POINTER_TYPE(Ciphertext)) ||
        (SANITY_CHECK_POINTER_TYPE(Plaintext)))
    {
        printf("[CA] Invalid pointer(s) in Decrypt_Update\n");
        res = TEEC_ERROR_BAD_PARAMETERS;
    }
    else{
        // Input length must be AES block aligned
        if ((Ciphertext->length_U32 % AES_BLOCK_SIZE) != 0U)
        {
            printf("[CA] Input length is not AES block aligned: %u\n", Ciphertext->length_U32);
            res = TEEC_ERROR_BAD_PARAMETERS;
        }
        else
        {
            // Allocate temporary output buffer equal to ciphertext size
            temp_out_len_U32 = (size_t)Ciphertext->length_U32;
            temp_out_buf_pU8 = malloc(temp_out_len_U32);

            if (temp_out_buf_pU8 == NULL)
            {
                printf("[CA] malloc failed for temp output buffer\n");
                res = TEEC_ERROR_OUT_OF_MEMORY;
            }
            else
            {
                if(memset(&operation, 0, sizeof(operation)) == (&operation))
                {

                    operation.paramTypes               = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT,
                                                                           TEEC_MEMREF_TEMP_OUTPUT,
                                                                           TEEC_NONE,
                                                                           TEEC_NONE);

                    operation.params[0].tmpref.buffer  = Ciphertext->data_U8P;
                    operation.params[0].tmpref.size    = Ciphertext->length_U32;

                    operation.params[1].tmpref.buffer  = temp_out_buf_pU8;
                    operation.params[1].tmpref.size    = temp_out_len_U32;

                    // Call TA update command
                    res = TEEC_InvokeCommand(&ctx->sess,
                                             TA_CRYPTO_CMD_AES_ECB_DECRYPT_UPDATE,
                                             &operation,
                                             &origin);

                    if (res == TEEC_SUCCESS)
                    {
                        // Check for buffer overflow before copying back to user
                        if (Plaintext->length_U32 < operation.params[1].tmpref.size)
                        {
                            printf("[CA] Output buffer in Plaintext struct too small! Required: %zu, Given: %u\n",
                                   operation.params[1].tmpref.size, Plaintext->length_U32);
                            res = TEEC_ERROR_SHORT_BUFFER;
                        }
                        else
                        {
                            if(temp_out_buf_pU8 == NULL)
                            {
                                //misra
                            }
                            else
                            {
                                if (operation.params[1].tmpref.size <= UINT32_MAX)
                                {
	            	                Plaintext->length_U32 = (uint32_t)operation.params[1].tmpref.size;
                                    if(temp_out_buf_pU8 == NULL)
                                    {
                                        res = TEEC_ERROR_OUT_OF_MEMORY;
                                    }
                                    else
                                    {
	            	                    if(memcpy(Plaintext->data_U8P, temp_out_buf_pU8, (size_t)Plaintext->length_U32) == (Plaintext->data_U8P))
                                        {
	            	                        free(temp_out_buf_pU8);
                                        }
                                        else{
                                            free(temp_out_buf_pU8);
                                            printf("\n[CA] MEMCPY Failed\n");
                                            res = TEEC_ERROR_GENERIC;
                                        }
                                    }
                                }
                                else
                                {
                                    res = TEEC_ERROR_EXCESS_DATA;
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("[CA] AES ECB Decrypt Update failed: 0x%08X\n", res);
                    }
                }
                else{
                    free(temp_out_buf_pU8);
                    printf("\n[CA] MEMSET Failed\n");
                    res = TEEC_ERROR_GENERIC;
                }
            }
        }
    }

#ifdef CA_VERBOSE
    printf("\n Exiting Crypto_AES128ECB_Decrypt_Update \n");
#endif

    return res;
}

/******************************************************************************************************************************************
** Function: Crypto_AES128ECB_Decrypt_Final
********************************************************************************************************************************************/

TEEC_Result Crypto_AES128ECB_Decrypt_Final(struct TEE_resource_ctx *ctx, ts_pointerType *Plaintext) {
    TEEC_Result    res     = TEEC_SUCCESS;
    TEEC_Operation operation;
    uint32_t       origin  = 0U;

#ifdef CA_VERBOSE
    printf("\n Entering Crypto_AES128ECB_Decrypt_Final \n");
#endif

    if (ctx == NULL) 
    {
        printf("[CA] Context NULL in Decrypt_Final\n");
        res = TEEC_ERROR_BAD_PARAMETERS;
    }
    else{
        // Zero out the structure
        if(memset(&operation, 0, sizeof(operation)) == (&operation))
        {
            // Only this line sets the correct paramTypes (None,None,None,None)
            operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_NONE,
                                                    TEEC_NONE,
                                                    TEEC_NONE,
                                                    TEEC_NONE);
            
            // Do NOT touch operation.params[i].tmpref.buffer — those are NOT used!
            
            res = TEEC_InvokeCommand(&ctx->sess,
                                     TA_CRYPTO_CMD_AES_ECB_DECRYPT_FINISH,
                                     &operation,
                                     &origin);
            
            if (res == TEEC_SUCCESS)
            {
                printf("[CA] AES ECB Decrypt Final - Cleanup Success\n");
            } else {
                printf("[CA] AES ECB Decrypt Final failed: 0x%08X\n", res);
            }
        }
        else{
            printf("\n[CA] MEMSET Failed\n");
            res = TEEC_ERROR_GENERIC;
        }
    }

#ifdef CA_VERBOSE
    printf("\n Exiting Crypto_AES128ECB_Decrypt_Final \n");
#endif

    return res;
}

// This interface shall used to store the ecdsa public key 
TEEC_Result Crypto_SetuserEcdsaPubKey(struct TEE_resource_ctx *ctx, const ts_ecdsaPublicKey *p_publicKey_SP) {
 
    TEEC_Operation operation;
    uint32_t origin = 0U;
    TEEC_Result res;
 
#ifdef CA_VERBOSE
    printf("\n Execution Crypto_SetuserEcdsaPubKey");
#endif
    if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
        operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT,
                         TEEC_NONE, TEEC_NONE);
        operation.params[0].tmpref.buffer = p_publicKey_SP->Xcrd_S.data_U8P;
        operation.params[0].tmpref.size   = p_publicKey_SP->Xcrd_S.length_U32;
	    operation.params[1].tmpref.buffer = p_publicKey_SP->Ycrd_S.data_U8P;
        operation.params[1].tmpref.size   = p_publicKey_SP->Ycrd_S.length_U32;
        
        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_ECDSA_SETUSERPUBKEY, &operation, &origin);
        if (res != TEEC_SUCCESS) {
        printf("\n Failed to set the user key: 0x%x, origin: 0x%x\n", res, origin);
        }
        switch (res) {
                    case TEEC_SUCCESS:
                        break;
                    case TEEC_ERROR_SHORT_BUFFER:
                        break;
   	                case TEEC_ERROR_ITEM_NOT_FOUND:
        	            break;
        	        default:
        	            printf("\n Command set user key failed : ");
                        break;
        	        }
    }
    else{
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }
#ifdef CA_VERBOSE
    printf("\n Exit Crypto_SetuserRsapubKey");
#endif
 
    return res;
}

// This interface shall used to store the ecdsa private key 
TEEC_Result Crypto_SetuserEcdsaPrivKey(struct TEE_resource_ctx *ctx, const ts_pointerType *p_privateKey_SP, const ts_ecdsaPublicKey *p_publicKey_SP) {
 
    TEEC_Operation operation;
    uint32_t origin = 0U;
    TEEC_Result res;
 
#ifdef CA_VERBOSE
    printf("\n Execution Crypto_SetuserEcdsaPrivKey");
#endif
    if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
        operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT,
                         TEEC_MEMREF_TEMP_INPUT, TEEC_NONE);
        operation.params[0].tmpref.buffer = p_privateKey_SP->data_U8P;
        operation.params[0].tmpref.size   = p_privateKey_SP->length_U32;
        operation.params[1].tmpref.buffer = p_publicKey_SP->Xcrd_S.data_U8P;
        operation.params[1].tmpref.size   = p_publicKey_SP->Xcrd_S.length_U32;
	    operation.params[2].tmpref.buffer = p_publicKey_SP->Ycrd_S.data_U8P;
        operation.params[2].tmpref.size   = p_publicKey_SP->Ycrd_S.length_U32;

        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_ECDSA_SETUSERPRIVKEY, &operation, &origin);
        if (res != TEEC_SUCCESS) {
        printf("\n Failed to set the ecdsa priv key: 0x%x, origin: 0x%x\n", res, origin);
        }
        switch (res) {
                    case TEEC_SUCCESS:
                        break;
                    case TEEC_ERROR_SHORT_BUFFER:
                        break;
   	                case TEEC_ERROR_ITEM_NOT_FOUND:
        	            break;
        	        default:
        	            printf("\n Command set user key failed : ");
                        break;
        	        }
    }
    else{
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }
#ifdef CA_VERBOSE
    printf("\n Exit Crypto_SetuserRsaprivKey");
#endif
 
    return res;
}

// This interface shall used to verify the signature using ecdsa p384 algo 
TEEC_Result Crypto_ECDSA_P384_Verify(struct TEE_resource_ctx *ctx, const ts_pointerType *message, const ts_pointerType *signature, const ts_ecdsaPublicKey *p_publicKey_SP) 
{
    TEEC_Operation operation;
    TEEC_Result res;
    uint32_t origin;
#ifdef CA_VERBOSE
    printf("\n Execution Crypto_ecdsa_p384_Verify");
#endif

	if ((ctx != NULL) || (!SANITY_CHECK_POINTER_TYPE(message)) || (!SANITY_CHECK_POINTER_TYPE(signature) || (!SANITY_CHECK_PUBLIC_KEY_ECC(p_publicKey_SP)))) 
	{	
		if(memset(&operation, 0, sizeof(operation)) == (&operation))
        {
	    	operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE);

	    	res = Crypto_SetuserEcdsaPubKey(ctx, p_publicKey_SP);
	    	if (res != TEEC_SUCCESS) {
	    		printf("\n Unable to get the usr key");
	    	}
	    	else {
	    		operation.params[0].tmpref.buffer = message->data_U8P;
	    		operation.params[0].tmpref.size   = message->length_U32;
	    		operation.params[1].tmpref.buffer = signature->data_U8P;
	    		operation.params[1].tmpref.size   = signature->length_U32;
            
	    		res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_ecdsa_p384_VERIFY, &operation, &origin);

	    		if (res != TEEC_SUCCESS) {
	    			printf("\n Failed to invoke ecdsa_p384 verification");
	    		}
	    		else
                {
	    			//for misra
	    		}
	    		switch (res) {
	    		case TEEC_SUCCESS:
	    			printf("\n Signature verification successfull.\n");
	    			break;
	    		case TEEC_ERROR_SHORT_BUFFER:
                    break;
	    		case TEEC_ERROR_ITEM_NOT_FOUND:
	    			break;
	    		default:
	    			printf("\n Command ecdsa_p384 verification failed: ");
                    break;
	    		}
	    	}
        }
        else{
            printf("\n[CA] MEMSET Failed\n");
            res = TEEC_ERROR_GENERIC;
        }
	}
	else 
	{
		printf("\n Crypto_ecdsa_p384_Verify : sanity check failed\n");
		res = TEEC_ERROR_SHORT_BUFFER;
	}


#ifdef CA_VERBOSE
    printf("\n Exit Crypto_ecdsa_p384_Verify");
#endif

    return res;
}

// This interface shall used to generate the signature using ecdsa p384 algo 
TEEC_Result Crypto_ECDSA_P384_sign_generate(struct TEE_resource_ctx *ctx, 
                                             const char* key_id, 
                                             uint32_t keyid_size, 
                                             const ts_pointerType *message, 
                                             ts_pointerType *signature)
{
    TEEC_Operation operation;
    TEEC_Result res;
    uint32_t origin;

#ifdef CA_VERBOSE
    printf("\n Execution Crypto_ECDSA_P384_sign_generate");
#endif

    if ((ctx == NULL) || (SANITY_CHECK_POINTER_TYPE(message)) || 
        (SANITY_CHECK_POINTER_TYPE(signature)) || (((key_id == NULL)) || (keyid_size == 0U))) {
        printf("\n Crypto_ECDSA_P384_sign_generate : sanity check failed\n");
        res = TEEC_ERROR_BAD_PARAMETERS;
    }
    else 
    {
        res = Crypto_GetasymKeyFromBlob(ctx, key_id, keyid_size);
        if (res != TEEC_SUCCESS) 
        {
            printf("\n Unable to set the key for signing");
        }
        else 
        {

            if(memset(&operation, 0, sizeof(operation)) == (&operation))
            {
                operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, 
                                                                     TEEC_MEMREF_TEMP_OUTPUT, 
                                                                     TEEC_NONE, 
                                                                     TEEC_NONE);
                    
                operation.params[0].tmpref.buffer = message->data_U8P;
                operation.params[0].tmpref.size   = message->length_U32;
                
                operation.params[1].tmpref.buffer = signature->data_U8P;
                operation.params[1].tmpref.size   = signature->length_U32;
                // Invoke ECDSA signing command
                res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_ecdsa_p384_SIGN, &operation, &origin);
                    
                if (res != TEEC_SUCCESS) {
                    printf("\n Failed to invoke ECDSA signature generation: 0x%08x", res);
                }
                switch (res) {
                case TEEC_SUCCESS:
                    printf("\n Signature generation successful.");
                    break;
                case TEEC_ERROR_SHORT_BUFFER:
                    printf("\n TA reported short buffer.");
                    break;
                default:
                    printf("\n Command ECDSA sign failed.");
                    break;
                }
                signature->length_U32 = (uint32_t)operation.params[1].tmpref.size;
            }
            else {
                printf("\n[CA] MEMSET Failed\n");
                res = TEEC_ERROR_GENERIC;
            }
        }
    }

#ifdef CA_VERBOSE
    printf("\n Exit Crypto_ECDSA_P384_sign_generate");
#endif
    return res;
}

TEEC_Result Privatesecurestorage_opteeapi(struct TEE_resource_ctx *ctx, uint8_t *pem_data, uint32_t pem_len, char *key_id, uint32_t key_id_len)
{
    TEEC_Operation op;
    uint32_t origin = 0U;
    TEEC_Result res = TEEC_ERROR_GENERIC;

    if ((ctx == NULL) || (pem_data == NULL) || (pem_len == 0U) ||
        (key_id == NULL) || (key_id_len == 0U))
    {
        printf("Invalid input parameters\n");
        res = TEEC_ERROR_BAD_PARAMETERS;
    }
    else
    {
        if(memset(&op, 0, sizeof(op)) == (&op))
        {
            op.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT,
                                             TEEC_MEMREF_TEMP_INPUT,
                                             TEEC_NONE,
                                             TEEC_NONE);

            op.params[0].tmpref.buffer = key_id;
            op.params[0].tmpref.size   = key_id_len;

            op.params[1].tmpref.buffer = pem_data;
            op.params[1].tmpref.size   = pem_len;

    #ifdef CA_VERBOSE
            printf("IPSEC_KEY_ID(hex): ");
            for (uint32_t i = 0U; i < key_id_len; i++)
            {
                printf("0x%02X ", (unsigned char)key_id[i]);
            }
            printf("\nDEBUG: IPSEC_KEY_ID(str): '%s'\n", key_id);
            printf("DEBUG: ipsec_key_id_len = %u\n", (uint32_t)key_id_len);
            printf("DEBUG: ipsec_pem_len    = %u\n", (uint32_t)pem_len);
    #endif

            res = TEEC_InvokeCommand(&ctx->sess,
                                     TA_SECURE_STORAGE_CMD_WRITE_PEM_KEY,
                                     &op,
                                     &origin);

            if (res == TEEC_SUCCESS)
            {
                printf("IPsec key stored as '%s' (len=%u)\n",
                       key_id, (uint32_t)key_id_len);
            }
            else
            {
                printf("Store failed: TEEC=0x%08x origin=0x%08x\n",
                       (unsigned)res, (unsigned)origin);
            }
        }
        else{
            printf("\n[CA] MEMSET Failed\n");
            res = TEEC_ERROR_GENERIC;
        }
    }

    return res;
}

TEEC_Result RetrieveIpsecKeyFromOPTEE(struct TEE_resource_ctx *ctx, const char *output_path, char *key_id, uint32_t key_id_len)
{
    TEEC_Operation op;
    uint32_t origin = 0U;
    TEEC_Result res = TEEC_ERROR_GENERIC;
    uint8_t *buffer = NULL;
    int32_t fd = 0;
    FILE *fp = NULL;

    if ((ctx == NULL) || (output_path == NULL) ||
        (key_id == NULL) || (key_id_len == 0U))
    {
        printf("Invalid input parameters\n");
        res = TEEC_ERROR_BAD_PARAMETERS;
    }
    else
    {
        buffer = (uint8_t *)malloc(IPSEC_BUFFER_SIZE);
        if (buffer == NULL)
        {
            printf("malloc failed\n");
            res = TEEC_ERROR_OUT_OF_MEMORY;
        }
        else
        {
            if(memset(&op, 0, sizeof(op)) == (&op))
            {
                op.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT,
                                                 TEEC_MEMREF_TEMP_OUTPUT,
                                                 TEEC_NONE,
                                                 TEEC_NONE);

                op.params[0].tmpref.buffer = key_id;
                op.params[0].tmpref.size   = key_id_len;

                op.params[1].tmpref.buffer = buffer;
                op.params[1].tmpref.size   = IPSEC_BUFFER_SIZE;

                res = TEEC_InvokeCommand(&ctx->sess,
                                         TA_SECURE_STORAGE_CMD_READ_PEM_KEY,
                                         &op,
                                         &origin);

                if (res == TEEC_SUCCESS)
                {
                        fd = open(output_path,
                              O_WRONLY | O_CREAT | O_EXCL | O_NOFOLLOW,
                              S_IRUSR | S_IWUSR);

                    if (fd >= 0)
                    {
                        fp = fdopen(fd, "wb");
                        if (fp != NULL)
                        {
                            (void)fwrite(buffer, 1U, op.params[1].tmpref.size, fp);
                            (void)fclose(fp);
                            fp = NULL;
                            printf("Key saved to %s (%zu bytes)\n",
                                   output_path, op.params[1].tmpref.size);
                        }
                        else
                        {
                            (void)close(fd);
                            printf("fopen(%s) failed\n", output_path);
                            res = TEEC_ERROR_STORAGE_NO_SPACE;
                        }
                    }
                }
                else
                {
                    printf("Retrieve failed: TEEC=0x%08x origin=0x%08x\n",
                           (unsigned)res, (unsigned)origin);
                }

                free(buffer);
                buffer = NULL;
            }
            else{
                printf("\n[CA] MEMSET Failed\n");
                res = TEEC_ERROR_GENERIC;
            }
        }
    }

    return res;
}

// This interface shall used to generare the key pair using ecdsa p384 algo 
TEEC_Result Crypto_ECDSA_P384_key_generate(struct TEE_resource_ctx *ctx, ts_pointerType *p_privateKey_SP, ts_ecdsaPublicKey *p_publicKey_SP)
{
    TEEC_Operation operation;
    uint32_t origin = 0U;
    TEEC_Result res = TEEC_ERROR_GENERIC;
 
#ifdef CA_VERBOSE
    printf("\n Execution Crypto_ECDSA_P384_key_generate");
#endif
	if ((ctx != NULL) || (!SANITY_CHECK_POINTER_TYPE(p_privateKey_SP)) || (!SANITY_CHECK_PUBLIC_KEY_ECC(p_publicKey_SP))) 
    {
        if(memset(&operation, 0, sizeof(operation)) == (&operation))
        {
            operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_OUTPUT, TEEC_MEMREF_TEMP_OUTPUT,
                             TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE);
            operation.params[0].tmpref.buffer = p_privateKey_SP->data_U8P;
            operation.params[0].tmpref.size   = p_privateKey_SP->length_U32;
            operation.params[1].tmpref.buffer = p_publicKey_SP->Xcrd_S.data_U8P;
            operation.params[1].tmpref.size   = p_publicKey_SP->Xcrd_S.length_U32;
	        operation.params[2].tmpref.buffer = p_publicKey_SP->Ycrd_S.data_U8P;
            operation.params[2].tmpref.size   = p_publicKey_SP->Ycrd_S.length_U32;

            res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_ECDSA_GENERATE, &operation, &origin);
            if (res != TEEC_SUCCESS) {
            printf("\n Failed to set the ecdsa priv key: 0x%x, origin: 0x%x\n", res, origin);
            }
            switch (res) {
                        case TEEC_SUCCESS:
                            break;
                        case TEEC_ERROR_SHORT_BUFFER:
                            break;
   	                    case TEEC_ERROR_ITEM_NOT_FOUND:
            	            break;
            	        default:
            	            printf("\n Command set user key failed : ");
                            break;
            	        }
        }
        else{
            printf("\n[CA] MEMSET Failed\n");
            res = TEEC_ERROR_GENERIC;
        }
    }
    else
    {
        printf("\n sanity check Crypto_ECDSA_P384_key_generate failed\n");
    }
#ifdef CA_VERBOSE
    printf("\n Exit Crypto_ECDSA_P384_key_generate");
#endif
 
    return res;
} 

// This interface shall used to certificate verififcation using ecdsa p384 algo 
TEEC_Result Crypto_Certificate_Verification(struct TEE_resource_ctx *ctx, const ts_pointerType *p_certificate_SP, const ts_pointerType *p_ca_cert_SP)
{
    TEEC_Operation operation;
    uint32_t origin = 0U;
    TEEC_Result res = TEEC_ERROR_GENERIC;
 
#ifdef CA_VERBOSE
    printf("\n Execution Crypto_Certificate_Verification");
#endif
    if(memset(&operation, 0, sizeof(operation)) == (&operation))
    {
        operation.paramTypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT,
                         TEEC_NONE, TEEC_NONE);
        operation.params[0].tmpref.buffer = p_certificate_SP->data_U8P;
        operation.params[0].tmpref.size   = p_certificate_SP->length_U32;
        operation.params[1].tmpref.buffer = p_ca_cert_SP->data_U8P;
        operation.params[1].tmpref.size   = p_ca_cert_SP->length_U32;

        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_CERT_VERIFY, &operation, &origin);
        if (res != TEEC_SUCCESS) {
        printf("\n Failed to Verify the ceritificate : 0x%x, origin: 0x%x\n", res, origin);
        }
        switch (res) {
                    case TEEC_SUCCESS:
                        break;
                    case TEEC_ERROR_SHORT_BUFFER:
                        break;
   	                case TEEC_ERROR_ITEM_NOT_FOUND:
        	            break;
        	        default:
        	            printf("\n Command Crypto_Certificate_Verification failed : ");
                        break;
                    }
    }
    else{
        printf("\n[CA] MEMSET Failed\n");
        res = TEEC_ERROR_GENERIC;
    }
#ifdef CA_VERBOSE
    printf("\n Exit Certificate verification");
#endif
 
    return res;
}

// CMAC Generation API
TEEC_Result Crypto_CMAC_Generate(struct TEE_resource_ctx *ctx,
                                 const char* key_id, uint32_t keyid_size,
                                 const ts_pointerType *InputData, ts_pointerType *Mac)
{
    TEEC_Operation operation;
    TEEC_Result res = TEEC_ERROR_BAD_PARAMETERS;
    uint32_t origin;

    if ((ctx != NULL) && (key_id != NULL) && (!SANITY_CHECK_POINTER_TYPE(InputData)) &&
        (Mac != NULL) && (Mac->data_U8P != NULL))
    {
        res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
        if (res == TEEC_SUCCESS)
        {
            memset(&operation, 0, sizeof(operation));
            operation.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT,
                                                    TEEC_MEMREF_TEMP_OUTPUT,
                                                    TEEC_NONE, TEEC_NONE);

            operation.params[0].tmpref.buffer = InputData->data_U8P;
            operation.params[0].tmpref.size   = InputData->length_U32;

            operation.params[1].tmpref.buffer = Mac->data_U8P;
            operation.params[1].tmpref.size   = Mac->length_U32;

            res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_CMAC_GENERATE, &operation, &origin);

            if (res == TEEC_SUCCESS) {
                Mac->length_U32 = operation.params[1].tmpref.size;
            }
            else {
                printf("\n [CA] Crypto_CMAC_Generate : Failed 0x%08X origin 0x%08X\n", res, origin);
            }
        }
        else {
            printf("\n [CA] Crypto_CMAC_Generate : Failed to load key (0x%08X)\n", res);
        }
    }
    else {
        printf("\n [CA] Crypto_CMAC_Generate : sanity check failed\n");
    }

    return res;
}

// CMAC Verification API
TEEC_Result Crypto_CMAC_Verify(struct TEE_resource_ctx *ctx,
                               const char* key_id, uint32_t keyid_size,
                               const ts_pointerType *InputData, const ts_pointerType *Mac)
{
    TEEC_Operation operation;
    TEEC_Result res = TEEC_ERROR_BAD_PARAMETERS;
    uint32_t origin;

    if ((ctx != NULL) && (key_id != NULL) && (!SANITY_CHECK_POINTER_TYPE(InputData)) &&
        (!SANITY_CHECK_POINTER_TYPE(Mac)))
    {
        res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
        if (res == TEEC_SUCCESS)
        {
            memset(&operation, 0, sizeof(operation));
            operation.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT,
                                                    TEEC_MEMREF_TEMP_INPUT,
                                                    TEEC_NONE, TEEC_NONE);

            operation.params[0].tmpref.buffer = InputData->data_U8P;
            operation.params[0].tmpref.size   = InputData->length_U32;

            operation.params[1].tmpref.buffer = Mac->data_U8P;
            operation.params[1].tmpref.size   = Mac->length_U32;

            res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_CMAC_VERIFY, &operation, &origin);

            if (res != TEEC_SUCCESS) {
                printf("\n [CA] Crypto_CMAC_Verify : Failed 0x%08X origin 0x%08X\n", res, origin);
            }
        }
        else {
            printf("\n [CA] Crypto_CMAC_Verify : Failed to load key (0x%08X)\n", res);
        }
    }
    else {
        printf("\n [CA] Crypto_CMAC_Verify : sanity check failed\n");
    }

    return res;
}

// CMAC Generation Start Update Finish APIs
TEEC_Result Crypto_CMAC_Gen_Start(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size)
{
    TEEC_Result res = TEEC_ERROR_BAD_PARAMETERS;
    uint32_t origin;

    if ((ctx != NULL) && (key_id != NULL))
    {
        res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
        if (res == TEEC_SUCCESS)
        {
            res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_CMAC_GEN_START, NULL, &origin);
            if (res != TEEC_SUCCESS)
            {
                printf("\n [CA] CMAC Gen Start: Command Failed (0x%08X)\n", res);
            }
        }
        else
        {
            printf("\n [CA] CMAC Gen Start: Key Load Failed (0x%08X)\n", res);
        }
    }
    else
    {
        printf("\n [CA] CMAC Gen Start: Sanity Check Failed\n");
    }

    return res;
}

TEEC_Result Crypto_CMAC_Gen_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *InputChunk)
{
    TEEC_Result res = TEEC_ERROR_BAD_PARAMETERS;
    TEEC_Operation operation;
    uint32_t origin;

    if ((ctx != NULL) && (!SANITY_CHECK_POINTER_TYPE(InputChunk)))
    {
        memset(&operation, 0, sizeof(operation));
        operation.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
        operation.params[0].tmpref.buffer = InputChunk->data_U8P;
        operation.params[0].tmpref.size   = InputChunk->length_U32;

        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_CMAC_GEN_UPDATE, &operation, &origin);
        if (res != TEEC_SUCCESS)
        {
            printf("\n [CA] CMAC Gen Update: Command Failed (0x%08X)\n", res);
        }
    }
    else
    {
        printf("\n [CA] CMAC Gen Update: Sanity Check Failed\n");
    }

    return res;
}

TEEC_Result Crypto_CMAC_Gen_Finish(struct TEE_resource_ctx *ctx, ts_pointerType *MacOut)
{
    TEEC_Result res = TEEC_ERROR_BAD_PARAMETERS;
    TEEC_Operation operation;
    uint32_t origin;

    if ((ctx != NULL) && (MacOut != NULL) && (MacOut->data_U8P != NULL))
    {
        memset(&operation, 0, sizeof(operation));
        operation.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_OUTPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
        operation.params[0].tmpref.buffer = MacOut->data_U8P;
        operation.params[0].tmpref.size   = MacOut->length_U32;

        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_CMAC_GEN_FINISH, &operation, &origin);

        if (res == TEEC_SUCCESS)
        {
            MacOut->length_U32 = operation.params[0].tmpref.size;
        }
        else
        {
            printf("\n [CA] CMAC Gen Finish: Command Failed (0x%08X)\n", res);
        }
    }
    else
    {
        printf("\n [CA] CMAC Gen Finish: Sanity Check Failed\n");
    }

    return res;
}

// CMAC Verification Start Update Finish APIs
TEEC_Result Crypto_CMAC_Ver_Start(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size)
{
    TEEC_Result res = TEEC_ERROR_BAD_PARAMETERS;
    uint32_t origin;

    if ((ctx != NULL) && (key_id != NULL))
    {
        res = Crypto_GetKeyFromBlob(ctx, key_id, keyid_size);
        if (res == TEEC_SUCCESS)
        {
            res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_CMAC_VER_START, NULL, &origin);
            if (res != TEEC_SUCCESS) {
                printf("\n [CA] CMAC Ver Start: Command Failed (0x%08X)\n", res);
            }
        }
        else
        {
            printf("\n [CA] CMAC Ver Start: Key Load Failed (0x%08X)\n", res);
        }
    }
    else
    {
        printf("\n [CA] CMAC Ver Start: Sanity Check Failed\n");
    }

    return res;
}

TEEC_Result Crypto_CMAC_Ver_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *InputChunk)
{
    TEEC_Result res = TEEC_ERROR_BAD_PARAMETERS;
    TEEC_Operation operation;
    uint32_t origin;

    if ((ctx != NULL) && (!SANITY_CHECK_POINTER_TYPE(InputChunk)))
    {
        memset(&operation, 0, sizeof(operation));
        operation.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
        operation.params[0].tmpref.buffer = InputChunk->data_U8P;
        operation.params[0].tmpref.size   = InputChunk->length_U32;

        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_CMAC_VER_UPDATE, &operation, &origin);
        if (res != TEEC_SUCCESS) {
            printf("\n [CA] CMAC Ver Update: Command Failed (0x%08X)\n", res);
        }
    }
    else
    {
        printf("\n [CA] CMAC Ver Update: Sanity Check Failed\n");
    }

    return res;
}

TEEC_Result Crypto_CMAC_Ver_Finish(struct TEE_resource_ctx *ctx, const ts_pointerType *ExpectedMac)
{
    TEEC_Result res = TEEC_ERROR_BAD_PARAMETERS;
    TEEC_Operation operation;
    uint32_t origin;

    if ((ctx != NULL) && (!SANITY_CHECK_POINTER_TYPE(ExpectedMac)))
    {
        memset(&operation, 0, sizeof(operation));
        operation.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
        operation.params[0].tmpref.buffer = ExpectedMac->data_U8P;
        operation.params[0].tmpref.size   = ExpectedMac->length_U32;

        res = TEEC_InvokeCommand(&ctx->sess, TA_CRYPTO_CMD_CMAC_VER_FINISH, &operation, &origin);
        if (res != TEEC_SUCCESS) {
            printf("\n [CA] CMAC Ver Finish: Command Failed (0x%08X)\n", res);
        }
    }
    else
    {
        printf("\n [CA] CMAC Ver Finish: Sanity Check Failed\n");
    }

    return res;
}
