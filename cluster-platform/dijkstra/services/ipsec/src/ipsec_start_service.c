#include <ipsec_service.h>
#include "SecurestorageCrypto_ca.h"
#include <sys/stat.h>
#include <unistd.h>

int32_t main(void) {
    int32_t fd;
    int32_t flags = EOK;
    int32_t conf_file = EOK;
    int32_t s32Result = INVALID;
    struct TEE_resource_ctx stCtx = {0};
    char IPSEC_KEY_ID[] = IPSEC_KEY_ID_STR;
    uint32_t IPSEC_KEY_ID_LEN = (uint32_t)strlen((const char *)IPSEC_KEY_ID);
    TEEC_Result teecResLocal = TEEC_SUCCESS;
    uint8_t ConfigFilePath[CONFIG_PATH_LENGTH] = "/etc/swanctl/swanctl.conf";
    fd = open((const char *)ConfigFilePath, O_RDONLY, S_IRUSR);
    if (fd == -1) {
        printf("\n Swanctl configuration not present failed to start strongswan service \n");
    }
    else {

        conf_file = open(IPSEC_TEMP_CONF, O_RDWR);
        if (conf_file < 0)
        {
            printf("\nFailed to open file.\n");
        }
        else
        {
            if (ioctl(conf_file, FS_IOC_GETFLAGS, &flags) < 0)
            {
                printf("\nError getting file flags.\n");
                close(conf_file);
            }
            else
            {
                if (chmod(IPSEC_TEMP_CONF, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) == 0)
                {
                    printf("File permissions changed successfully\n");
                }
                else
                {
                    printf("chmod failed");
                }
                /* Set immutable flag */
                flags |= FS_IMMUTABLE_FL;

                if (ioctl(conf_file, FS_IOC_SETFLAGS, &flags) < 0)
                {
                    printf("\nNot able to set immutable permission.\n");
                }
                else
                {
                    printf("\nImmutable flag set successfully.\n");
                }
                close(conf_file);
            }
        }
        prepare_tee_session_securestorage_crypto(&stCtx);
        
        teecResLocal = RetrieveIpsecKeyFromOPTEE(&stCtx,
                                                 IPSEC_KEY_FILE_PATH,
                                                 (char *)IPSEC_KEY_ID,
                                                 (uint32_t)IPSEC_KEY_ID_LEN);
        
        if (teecResLocal != TEEC_SUCCESS)
        {
            printf("\n Failed to retrieve IPsec key from OP-TEE (0x%08"
                   PRIx32 ")\n",
                   (uint32_t)teecResLocal);
            s32Result = ENOK;
        }
        else
        {
            if (chmod(IPSEC_KEY_FILE_PATH, S_IRUSR) != EOK)
            {
                printf("\n chmod failed on key file\n");
                (void)unlink(IPSEC_KEY_FILE_PATH);
                s32Result = ENOK;
            }
            else
            {
                if (system("systemctl restart strongswan") != EOK)
                {
                    printf("\n Failed to restart StrongSwan\n");
                    (void)unlink(IPSEC_KEY_FILE_PATH);
                    s32Result = ENOK;
                }
                else
                {
                    printf("\n StrongSwan restarted successfully\n");
                    if (unlink(IPSEC_KEY_FILE_PATH) != EOK)
                    {
                        printf("\n Warning: Key file deletion issue\n");
                    }
                    else
                    {
                        printf("\n IPsec key securely deleted\n");
                    }
                    s32Result = EOK;
                }
            }
        }
        terminate_tee_session_securestorage_crypto(&stCtx);
        close(fd);
    }
    printf("\n return = %d \n",s32Result);
    return s32Result;
}