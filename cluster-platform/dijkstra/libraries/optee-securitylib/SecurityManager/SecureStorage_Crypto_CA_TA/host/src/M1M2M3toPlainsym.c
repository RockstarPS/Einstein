

#include <M1M2M3toPlainsym.h>

int32_t aes_mp(const unsigned char* input, size_t input_length, unsigned char* output)
{
	int32_t res = 0;
	int32_t actual_len = 0;
	int32_t number_of_blocks = 0;
	if ((input_length / BLKSIZE) > INT_MAX)
	{
	    ERR_print_errors_fp(stderr);
		res = 1;
	}
	else
	{
		 number_of_blocks = (int32_t)(input_length / BLKSIZE);
	     unsigned char x_i[BLKSIZE] = { 0 };
	     unsigned char enc[BLKSIZE] = { 0 };
		 if(memset(output, 0, BLKSIZE) == output)
		 {
		 	for (int32_t i = 1; i <= number_of_blocks; i++)
	     	{
				if (memcpy(x_i, &input[(BLKSIZE) * (i - 1)], BLKSIZE) == x_i)
				{	
	     			actual_len = encrypt_aes_128_ecb(x_i, BLKSIZE, output, enc, 0);
					if(actual_len <= 0)
					{
						ERR_print_errors_fp(stderr);
						res = 1;
					}
					else
					{
	     				if (actual_len != BLKSIZE)
	     				{
	     				    ERR_print_errors_fp(stderr);
							res = 1;
	     				}
	     				else
	     				{
	     					for (int32_t j = 0; j < BLKSIZE; j++)
	     					{
	     						output[j] = output[j] ^ x_i[j] ^ enc[j];
	     					}
	     				}
					}
				}
				else
				{
					res = 1;
					ERR_print_errors_fp(stderr);
				}
	     	}
		}
		else
		{
			res = 1;
			ERR_print_errors_fp(stderr);
		}
	}
	return res;
}

int32_t encrypt_aes_128_cbc(const unsigned char* plaintext, int plaintext_len, const unsigned char* key,
	const unsigned char* iv, unsigned char* ciphertext, int use_padding)
{
	EVP_CIPHER_CTX* ctx;

	int32_t len;
	int32_t padding_sts = 1;
	int32_t ciphertext_len = 0;
	unsigned char* local_buf = NULL;
	local_buf = malloc((size_t)plaintext_len + 16U);
    if (local_buf != NULL)
	{

		/* Create and initialise the context */
		ctx = EVP_CIPHER_CTX_new();
		if (NULL != ctx)
		{
			/*
			 * Initialise the encryption operation. IMPORTANT - ensure you use a key
			 * and IV size appropriate for your cipher
			 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
			 * IV size for *most* modes is the same as the block size. For AES this
			 * is 128 bits
			 */
			if (1 == EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
			{
				if (0 == use_padding)
				{
					if(1 != EVP_CIPHER_CTX_set_padding(ctx, 0))
					{
						ERR_print_errors_fp(stderr);
						padding_sts = -1;
					}
					else
					{
						padding_sts = 1;
					}
				}
				/*
				 * Provide the message to be encrypted, and obtain the encrypted output.
				 * EVP_EncryptUpdate can be called multiple times if necessary
				 */
				if((0 != use_padding) || ((0 == use_padding) && (padding_sts == 1)))
				{
					if (1 == EVP_EncryptUpdate(ctx, local_buf, &len, plaintext, plaintext_len))
					{
						ciphertext_len = len;
						/*
						 * Finalise the encryption. Further ciphertext bytes may be written at
						 * this stage.
						 */
						if (1 == EVP_EncryptFinal_ex(ctx, &local_buf[len], &len))
						{
							ciphertext_len += len;
							if(memcpy(ciphertext, local_buf, (size_t)ciphertext_len) != ciphertext)
							{
								ERR_print_errors_fp(stderr);
								ciphertext_len = 1;	
							}
						}
						else
						{
							ERR_print_errors_fp(stderr);
							ciphertext_len = 1;
						}
					}
					else
					{
						ERR_print_errors_fp(stderr);
						ciphertext_len = 1;
					}
				}
				else
				{
					ERR_print_errors_fp(stderr);
					ciphertext_len = 1;
				}
			}
			else
			{
				ERR_print_errors_fp(stderr);
				ciphertext_len = 1;
			}

			/* Clean up */
			EVP_CIPHER_CTX_free(ctx);
		}
		else
		{
			ERR_print_errors_fp(stderr);
			ciphertext_len = 1;
		}
	}
	else
	{
		ERR_print_errors_fp(stderr);
		ciphertext_len = 1;
	}
	if(local_buf != NULL)
	{
		free(local_buf);
	}

	return ciphertext_len;
}

int32_t encrypt_aes_128_ecb(const unsigned char* plaintext, int plaintext_len, const unsigned char* key, unsigned char* ciphertext, int use_padding)
{
	EVP_CIPHER_CTX* ctx;

	int32_t len;

	int32_t ciphertext_len = 0;

	int32_t padding_sts = 1;

	unsigned char *local_buf = NULL;

	local_buf = malloc((size_t)plaintext_len + 16U);
    if (local_buf != NULL)
	{
		/* Create and initialise the context */
		ctx = EVP_CIPHER_CTX_new();
		if (NULL != ctx)
		{
			/*
			 * Initialise the encryption operation. IMPORTANT - ensure you use a key
			 * and IV size appropriate for your cipher
			 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
			 * IV size for *most* modes is the same as the block size. For AES this
			 * is 128 bits
			 */
			if (1 == EVP_EncryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL))
			{
				if (0 == use_padding)
				{
					if(1 != EVP_CIPHER_CTX_set_padding(ctx, 0))
					{
						ERR_print_errors_fp(stderr);
						padding_sts = -1;
					}
					else
					{
						padding_sts = 1;
					}
				}

				/*
				 * Provide the message to be encrypted, and obtain the encrypted output.
				 * EVP_EncryptUpdate can be called multiple times if necessary
				 */
				if((0 != use_padding) || ((0 == use_padding) && (padding_sts == 1)))
				{
					if (1 == EVP_EncryptUpdate(ctx, local_buf, &len, plaintext, plaintext_len))
					{
						ciphertext_len = len;

						/*
						 * Finalise the encryption. Further ciphertext bytes may be written at
						 * this stage.
						 */
						if (1 == EVP_EncryptFinal_ex(ctx, &local_buf[len], &len))
						{
							ciphertext_len += len;
							if(memcpy(ciphertext, local_buf, (size_t)ciphertext_len) != ciphertext)
							{
								ERR_print_errors_fp(stderr);
								ciphertext_len = 1;	
							}
						}
						else
						{
							ERR_print_errors_fp(stderr);
							ciphertext_len = 1;
						}
					}
					else
					{
						ERR_print_errors_fp(stderr);
						ciphertext_len = 1;
					}
				}
				else
				{
					ERR_print_errors_fp(stderr);
					ciphertext_len = 1;
				}
			}
			else
			{
				ERR_print_errors_fp(stderr);
				ciphertext_len = 1;
			}

			/* Clean up */
			EVP_CIPHER_CTX_free(ctx);
		}
		else
		{
			ERR_print_errors_fp(stderr);
			ciphertext_len = 1;
		}
	}
	else
	{
		ERR_print_errors_fp(stderr);
		ciphertext_len = 1;
	}

	if(local_buf != NULL)
	{
		free(local_buf);
	}

	return ciphertext_len;
}

int32_t decrypt_aes_128_cbc(const unsigned char* ciphertext, int ciphertext_len, const unsigned char* key,
	const unsigned char* iv, unsigned char* plaintext, int use_padding)
{
	EVP_CIPHER_CTX* ctx;

	int32_t len = 0;

	int32_t plaintext_len = 0;

	int32_t padding_sts = 1;
	unsigned char* local_buf = NULL;
	if(ciphertext_len != 0)
	{
		local_buf = malloc((size_t)ciphertext_len);
    	if (local_buf != NULL)
		{
			/* Create and initialise the context */
			ctx = EVP_CIPHER_CTX_new();
			if (NULL != ctx)
			{
				/*
				 * Initialise the decryption operation. IMPORTANT - ensure you use a key
				 * and IV size appropriate for your cipher
				 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
				 * IV size for *most* modes is the same as the block size. For AES this
				 * is 128 bits
				 */
				if (1 == EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
				{
					if (0 == use_padding)
					{
						if(1 != EVP_CIPHER_CTX_set_padding(ctx, 0))
						{
							ERR_print_errors_fp(stderr);
							padding_sts = -1;
						}
						else
						{
							padding_sts = 1;
						}
					}
					/*
					 * Provide the message to be decrypted, and obtain the plaintext output.
					 * EVP_DecryptUpdate can be called multiple times if necessary.
					 */
					if((0 != use_padding) || ((0 == use_padding) && (padding_sts == 1)))
					{
						if (1 == EVP_DecryptUpdate(ctx, local_buf, &len, ciphertext, ciphertext_len))
						{
							plaintext_len = len;

							/*
							 * Finalise the decryption. Further plaintext bytes may be written at
							 * this stage.
							 */
							if (1 == EVP_DecryptFinal_ex(ctx, &local_buf[len], &len))
							{
								plaintext_len +=len;
								if(memcpy(plaintext, local_buf, (size_t)plaintext_len) != plaintext)
								{
									ERR_print_errors_fp(stderr);
									plaintext_len = 1;
								}
							}
							else
							{
								ERR_print_errors_fp(stderr);
								plaintext_len = 1;
							}
						}
						else
						{
							ERR_print_errors_fp(stderr);
							plaintext_len = 1;
						}
					}
					else
					{
						ERR_print_errors_fp(stderr);
						plaintext_len = 1;
					}
				}
				else
				{
					ERR_print_errors_fp(stderr);
					plaintext_len = 1;
				}
				/* Clean up */
				EVP_CIPHER_CTX_free(ctx);
			}
			else
			{
				ERR_print_errors_fp(stderr);
				plaintext_len = 1;
			}
		}
		else{
			ERR_print_errors_fp(stderr);
			plaintext_len = 1;
		}
		if(local_buf != NULL)
		{
			free(local_buf);
		}
	}
	else
	{
		ERR_print_errors_fp(stderr);
		plaintext_len = 1;
	}
	return plaintext_len;
}

int32_t decrypt_aes_128_ecb(const unsigned char* ciphertext, int ciphertext_len, const unsigned char* key, unsigned char* plaintext, int use_padding)
{
	EVP_CIPHER_CTX* ctx;

	int32_t len = 0;

	int32_t plaintext_len = 0;

	int32_t padding_sts = 1;
	unsigned char* local_buf = NULL;
	if(ciphertext_len != 0)
	{
		local_buf = malloc((size_t)ciphertext_len);
    	if (local_buf != NULL)
		{
			/* Create and initialise the context */
			ctx = EVP_CIPHER_CTX_new();
			if (NULL != ctx)
			{
				/*
				 * Initialise the decryption operation. IMPORTANT - ensure you use a key
				 * and IV size appropriate for your cipher
				 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
				 * IV size for *most* modes is the same as the block size. For AES this
				 * is 128 bits
				 */
				if (1 == EVP_DecryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL))
				{
					if (0 == use_padding)
					{
						if(1 != EVP_CIPHER_CTX_set_padding(ctx, 0))
						{
							ERR_print_errors_fp(stderr);
							padding_sts = -1;
						}
						else
						{
							padding_sts = 1;
						}
					}
					/*
					 * Provide the message to be decrypted, and obtain the plaintext output.
					 * EVP_DecryptUpdate can be called multiple times if necessary.
					 */
					if((0 != use_padding) || ((0 == use_padding) && (padding_sts == 1)))
					{
						if (1 == EVP_DecryptUpdate(ctx, local_buf, &len, ciphertext, ciphertext_len))
						{
							plaintext_len = len;

							/*
							 * Finalise the decryption. Further plaintext bytes may be written at
							 * this stage.
							 */
							if (1 == EVP_DecryptFinal_ex(ctx, &local_buf[len], &len))
							{
								plaintext_len +=len;
								if(memcpy(plaintext, local_buf, (size_t)plaintext_len) != plaintext)
								{
									ERR_print_errors_fp(stderr);
									plaintext_len = 1;	
								}
							}
							else
							{
								ERR_print_errors_fp(stderr);
								plaintext_len = 1;
							}
						}
						else
						{
							ERR_print_errors_fp(stderr);
							plaintext_len = 1;
						}
					}
					else
					{
						ERR_print_errors_fp(stderr);
						plaintext_len = 1;
					}
				}
				else
				{
					ERR_print_errors_fp(stderr);
					plaintext_len = 1;
				}
				/* Clean up */
				EVP_CIPHER_CTX_free(ctx);
			}
			else
			{
				ERR_print_errors_fp(stderr);
				plaintext_len = 1;
			}
		}
		else{
			ERR_print_errors_fp(stderr);
			plaintext_len = 1;
		}
		if(local_buf != NULL)
		{
			free(local_buf);
		}
	}
	else
	{
		ERR_print_errors_fp(stderr);
		plaintext_len = 1;
	}

	return plaintext_len;
}