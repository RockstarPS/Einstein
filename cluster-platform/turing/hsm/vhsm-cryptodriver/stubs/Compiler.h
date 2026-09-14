/* [SWS_COMPILER_00001] */
/** \brief Indirection for function declaration */
//#define FUNC(rettype, memclass) rettype memclass
#define CONST(consttype, memclass) const consttype memclass
#ifndef VAR 
#define VAR(vartype, memclass) vartype
#endif

#define CRY_VAR
#define CRY_APPL_DATA
#define CRYPTO_VAR

#define CRY_CODE
#define CSM_CONST
#define CRYPTO_CODE
//#define te_canceljobid
//#define ts_vHsm_Cryptodata
//define te_cryptojobid
//#define te_jobpriority
/*The below were defined due to the error "Undeclared", after commenting all the 
include "vHsmCryptoManager.h" and include "vHsmIpcHostManager"*/
/*#define CID_67_CRYPTO_JOB_CANCEL_UPDATE 0
#define CID_58_SYM_ENCRYPT_FN 0
#define CID_57_SYM_ENCRYPT_FINISH 0
#define CRYPTO_JOB_DONE 0
#define CID_31_RANDOM_GEN 0
#define CID_53_SYM_DECRYPT_FN 0
#define CID_52_SYM_DECRYPT_FINISH 0
#define CID_16_HASH_START 0
#define CID_17_HASH_UPDATE 0
#define CID_122_JTAG_SETPASSWORD_GEN 0
#define CID_62_SYM_EXTRACT_FINISH 0
#define CID_89_HMAC_SHA256_GEN 0
#define CID_44_SYM_BLOCK_DECRYPT_START 0
#define CID_21_MAC_GEN_FN 0
#define CID_27_MAC_VER_START 0
#define CID_28_MAC_VER_UPDATE 0
#define CID_49_SYM_BLOCK_ENCRYPT_START 0
#define CID_47_SYM_BLOCK_ENCRYPT_FINISH 0
#define CID_63_SYM_ENCRYPT256_FN 0
#define CID_64_SYM_ENCRYPT256_FINISH 0
#define CID_25_MAC_VER_FINISH 0
#define CID_42_SYM_BLOCK_DECRYPT_FINISH 0
#define CID_123_JTAG_CHECKPASSWORD_GEN 0
#define CID_130_SET_KEY_FN 0
#define CID_55_SYM_DECRYPT_UPDATE 0
#define CID_65_SYM_ENCRYPT256_UPDATE 0
#define CID_50_SYM_BLOCK_ENCRYPT_UPDATE 0
#define CID_15_HASH_FN 0
#define CID_14_HASH_FINISH 0
#define CID_60_SYM_ENCRYPT_UPDATE 0
#define CID_45_SYM_BLOCK_DECRYPT_UPDATE 0
*/