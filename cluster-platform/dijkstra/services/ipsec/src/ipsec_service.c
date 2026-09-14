#include <ipsec_service.h>
#include "SecurestorageCrypto_ca.h"
#include <sys/stat.h>
#include <unistd.h>

int32_t securitymanager_store_ipsec_key(const uint8_t *p_pem_data_U8,
                                       size_t pem_len_U32)
{
    int32_t s32Result = ENOK;
    struct TEE_resource_ctx stCtx = {0};
    uint32_t u32PemLenLocal = 0U;
    char IPSEC_KEY_ID[] = IPSEC_KEY_ID_STR;
    uint32_t IPSEC_KEY_ID_LEN = (uint32_t)strlen((const char *)IPSEC_KEY_ID);
    TEEC_Result teecPemResLocal = TEEC_SUCCESS;

    /* sanity check block */
    if ((p_pem_data_U8 == NULL) || (pem_len_U32 == 0U))
    {
        printf("\n Invalid PEM key input\n");
        s32Result = ENOK;
    }
    else
    {
        if (pem_len_U32 <= UINT32_MAX)
        {
            u32PemLenLocal = (uint32_t)pem_len_U32;
            prepare_tee_session_securestorage_crypto(&stCtx);
            teecPemResLocal = Privatesecurestorage_opteeapi(&stCtx,
                                                    (uint8_t *)p_pem_data_U8,
                                                    u32PemLenLocal,
                                                    (char *)IPSEC_KEY_ID,
                                                    (uint32_t)IPSEC_KEY_ID_LEN);

            if (teecPemResLocal != TEEC_SUCCESS)
            {
                printf("\n Failed to store IPsec key (0x%08" PRIx32 "). "
                       "Secure blob may be missing.\n",
                       (uint32_t)teecPemResLocal);
                s32Result = ENOK;
            }
            else
            {
                printf("\n External PEM stored in OP-TEE successfully.\n");
                s32Result = EOK;
            }

            terminate_tee_session_securestorage_crypto(&stCtx);
        }
        else
        {
            s32Result = ENOK;
        }
    }
    printf("\n return = %d \n",s32Result);
    return s32Result;
}

int32_t LockStatus_Service(void)
{
    int32_t s32Result = ENOK;

    if (access(LOCK_FILE, F_OK) == EOK) {
       printf("\n strongswan service is locked unlock first \n");
       s32Result = EOK;
    }
    else 
    {
        printf("\n strongswan service is not locked \n");
        s32Result = ENOK;
    }
    printf("\n return = %d \n",s32Result);

    return s32Result;
}

int32_t EnableStatus_Service(void)
{
    int32_t s32Result = ENOK;

    if (system("systemctl is-active --quiet strongswan") == EOK)
    {
        printf("\n Already active and running \n");
        s32Result = EOK;
    }
    else
    {
        printf("\n strongswan service not started \n");
        s32Result = ENOK;
    }
    printf("\n return = %d \n",s32Result);
    
    return s32Result;
}

int32_t StartStrongSwan_Service(void) {
    int32_t s32Result = INVALID;
    struct TEE_resource_ctx stCtx = {0};
    char IPSEC_KEY_ID[] = IPSEC_KEY_ID_STR;
    uint32_t IPSEC_KEY_ID_LEN = (uint32_t)strlen((const char *)IPSEC_KEY_ID);
    TEEC_Result teecResLocal = TEEC_SUCCESS;

    if (access(LOCK_FILE, F_OK) == EOK) {
       printf("\n strongswan service is locked unlock first \n");
       s32Result = INVALID;
    }
    else
    {
        if (system("systemctl is-active --quiet strongswan") == EOK){
            printf("\n Already active and running \n");
            s32Result = OPERATION_ALREADY_RUNNING;
        }
        else
        {
            if (system("systemctl stop strongswan-starter") != EOK)
            {
                printf("\n Failed to stop strongswan-starter\n");
                s32Result = ENOK;
            }
            else
            {
                printf("\n strongswan-starter stopped successfully\n");

                if (system("systemctl enable strongswan") != EOK)
                {
                    printf("\n Failed to enable strongswan\n");
                    s32Result = ENOK;
                }
                else
                {
                    printf("\n StrongSwan enabled successfully\n");

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
                            if (system("systemctl start strongswan") != EOK)
                            {
                                printf("\n Failed to start StrongSwan\n");
                                (void)unlink(IPSEC_KEY_FILE_PATH);
                                s32Result = ENOK;
                            }
                            else
                            {
                                printf("\n StrongSwan started successfully\n");
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
                }
            }
        }
    }
    printf("\n return = %d \n",s32Result);
    return s32Result;
}

int32_t StopStrongSwan_Service(void) {
    int32_t res = INVALID;
    if (system("systemctl is-active --quiet strongswan") != EOK){
        printf("\n strongswan service not started\n");
        res = OPERATION_ALREADY_RUNNING;
    }
    else
    {
        if (access(LOCK_FILE, F_OK) != EOK) {
            printf("\nConfiguration is not locked.\n");
            if(system("systemctl stop strongswan") == EOK){
                printf("\n strongswan service stopped\n");
                res = EOK;
            }
            else{
                printf("\n strongswan service stop error");
                res = ENOK;
            }  
        }
        else{
            printf("\n strongswan service is locked unlock first \n");
            res = FORBIDDEN;
        }  
    }
    printf("\n return = %d \n",res);
    return res;
}

int32_t DisableStrongSwan_Service(void) {
    int32_t res = ENOK; 
     if (access(LOCK_FILE, F_OK) != EOK) {
        printf("\nConfiguration is not locked.\n");
        if (system("systemctl stop strongswan") == EOK) {
            printf("\n StrongSwan stop successfully \n");
            if (system("systemctl disable strongswan") == EOK) {
                printf("\nStrongSwan disabled successfully proceeding to stop the service\n");
                res = EOK;
            }
            else {
                printf("\n Failed to disable strongswan \n");
                res = ENOK;
            }
        }
        else{
            printf("\n strongswan service stop error");
            res = ENOK;
        }
    }
    else{
        printf("\n strongswan service is locked unlock first \n");
    }
    printf("\n return = %d \n",res);
    return res;
}

int32_t RestartStrongSwan_Service(void) {
    int32_t s32Result = ENOK;
    struct TEE_resource_ctx stCtx = {0};
    char IPSEC_KEY_ID[] = IPSEC_KEY_ID_STR;
    uint32_t IPSEC_KEY_ID_LEN = (uint32_t)strlen((const char *)IPSEC_KEY_ID);
    TEEC_Result teecResLocal = TEEC_SUCCESS;

    if (access(LOCK_FILE, F_OK) == EOK) {
       printf("\n strongswan service is locked unlock first \n");
       s32Result = INVALID;
    }
    else
    {
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
    }
    printf("\n return = %d \n",s32Result);
    return s32Result;
}

int32_t StatusStrongSwan_Service(uint8_t *status, uint8_t *dataLength)
{
    int32_t  res            = ENOK;
    FILE    *fp             = NULL;
    char     line[128]      = {0};
    char    *saveptr        = NULL;
    char    *token          = NULL;
    uint16_t index_buf          = 0U;
    uint32_t value          = 0U;
    uint8_t  byte_val       = 0U;
    uint8_t  loop_exit      = 0U;
    uint8_t  local_buf[UDS_MAX_LEN] = {0};

    if ((status == NULL) || (dataLength == NULL))
    {
        printf("Invalid arguments\n");
    }
    else
    {
        fp = popen("/etc/swanctl/bash/status.sh", "r");
        if (fp == NULL)
        {
            printf("Failed to execute script\n");
        }
        else
        {
            while ((fgets(line, sizeof(line), fp) != NULL) &&
                   (loop_exit == 0U))
            {
                token = strtok_r(line, " \n", &saveptr);

                while ((token != NULL) && (loop_exit == 0U))
                {
                    if (sscanf(token, "%u", &value) == 1)
                    {
                        if ((value <= UDS_MAX_LEN) && (index_buf < UDS_MAX_LEN))
                        {
                            byte_val = (uint8_t)value;
                            local_buf[index_buf] = byte_val;
                            index_buf++;
                        }
                        else
                        {
                            printf("Invalid value or status buffer overflow\n");
                            res = ENOK;
                            loop_exit = 1U;
                        }
                    }

                    token = strtok_r(NULL, " \n", &saveptr);
                }
            }

            (void)pclose(fp);

            if ((loop_exit == 0U) && (index_buf > 0U))
            {
                memcpy(status, local_buf, index_buf);
                if (index_buf <= UDS_MAX_LEN)
                {
                    *dataLength = (uint8_t)index_buf;
                }
                res = EOK;
            }
        }
    }

    return res;
}

int32_t ErrorStrongSwan_Service(uint8_t *error, uint8_t *dataLength)
{
    int32_t  res            = ENOK;
    FILE    *fp             = NULL;
    char     line[128]      = {0};
    char    *saveptr        = NULL;
    char    *token          = NULL;
    uint16_t index_buf          = 0U;
    uint64_t value          = 0U;
    uint8_t  byte_val       = 0U;
    uint8_t  loop_exit      = 0U;
    uint8_t  local_buf[MAX_ERROR] = {0};

    if ((error == NULL) || (dataLength == NULL))
    {
        printf("Invalid arguments\n");
    }
    else
    {
        fp = popen("/etc/swanctl/bash/error.sh", "r");
        if (fp == NULL)
        {
            printf("Failed to execute error script\n");
        }
        else
        {
            while ((fgets(line, sizeof(line), fp) != NULL) &&
                   (loop_exit == 0U))
            {
                token = strtok_r(line, " \n", &saveptr);

                while ((token != NULL) && (loop_exit == 0U))
                {
                    errno = 0;
                    value = (uint64_t)strtoul(token, NULL, 0);

                    if (errno != 0)
                    {
                        printf("strtoul conversion failed\n");
                        res = ENOK;
                        loop_exit = 1U;
                    }
                    else if ((value <= UDS_MAX_LEN) &&
                             (index_buf <  (uint16_t)MAX_ERROR))
                    {
                        byte_val = (uint8_t)value;
                        local_buf[index_buf] = byte_val;
                        index_buf++;
                    }
                    else
                    {
                        printf("Invalid value or error buffer overflow\n");
                        res = ENOK;
                        loop_exit = 1U;
                    }

                    token = strtok_r(NULL, " \n", &saveptr);
                }
            }

            (void)pclose(fp);

            if ((loop_exit == 0U) && (index_buf > 0U))
            {
                memcpy(error, local_buf, index_buf);
                if (index_buf <= UDS_MAX_LEN)
                {
                    *dataLength = (uint8_t)index_buf;
                }
                res = EOK;
            }
        }
    }

    return res;
}

int32_t IpMaskStrongSwan_Service(const uint8_t *req, uint8_t len)
{
    int32_t res = ENOK;
    char command[IP_MASK_CMD_LEN] = {0};
    int32_t conf_file = EOK;
    int32_t flags = EOK;
    int32_t write_cmd = EOK;
    char third_octet_str[THIRD_OCTET_MAX_LEN] = {0};
    char hex_mask_str[HEX_MAX_STR] = {0}; /* 0x + 64 hex chars + null */
    uint8_t i = EOK;
    uint8_t req_local[UDS_MAX_LEN] = {0};
    conf_file = open(IPSEC_TEMP_CONF, O_RDONLY);
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
            /* remove immutable flag */
            flags &= ~FS_IMMUTABLE_FL;
            if (ioctl(conf_file, FS_IOC_SETFLAGS, &flags) == 0)
            {
                printf("\npermission removed successfully.\n");
                close(conf_file);
                if ((req == NULL) || (len == 0U) || (len >= UDS_MAX_LEN))
                {
                    printf("Invalid inputs\n");
                }
                else
                {
                    memcpy(req_local, req, (size_t)len);
                    snprintf(third_octet_str, sizeof(third_octet_str), "%u", req_local[SUBNET_INDEX]);
                    strcpy(hex_mask_str, "0x");

                    for (i = 0U; i < BITMASK_LEN; i++)
                    {
                        snprintf(&hex_mask_str[HEX_MASK + (i * HEX_MASK)],
                                       THIRD_OCTET_MAX_LEN_N,
                                       "%02x",
                                       req_local[BITMASK_START_IDX + i]);
                    }
                    printf("Subnet (3rd octet): %s\n", third_octet_str);
                    printf("Mask: %s\n", hex_mask_str);
                    write_cmd = snprintf(command,
                                         sizeof(command),
                                         "/etc/swanctl/bash/ip_mask_write.sh %s %s",
                                         third_octet_str,
                                         hex_mask_str);

                    if ((write_cmd < EOK) || (write_cmd >= (int32_t)sizeof(command))) {
                        printf("Error constructing command string -too long or snprintf failed.\n");
                        res = ENOK;
                    }
                    else {
                        printf(" Securely constructing command string.\n");
                        if (system(command) == EOK) {
                            printf("\nIP Masked successfully\n");
                            res = EOK;
                        } else {
                            printf("\nError running the ip_mask script\n");
                            res = ENOK;
                        }
                    }
                }
            }
            else
            {
                printf("\nFailed to remove immutable flag.\n");
                close(conf_file);
            }
        }
    }
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
            if (chmod(IPSEC_TEMP_CONF, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) == EOK)
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
    printf("\n return = %d \n",res);
    return res;
}
int32_t IpMaskReadStrongSwan_Service(uint8_t *data, uint8_t *len)
{
    char     buffer[IP_MASK_BUF_LEN_HEX]       = {0};
    char     hex_str[IP_MASK_BUF_LEN_HEX]      = {0};
    char     byte_str[THIRD_OCTET_MAX_LEN_N]    = {0};
    char     tmp[THIRD_OCTET_MAX_LEN]           = {0};
    FILE    *fp             = NULL;
    size_t   space_index    = 0U;
    size_t   buf_pos        = 0U;
    size_t   hex_len        = 0U;
    size_t   i              = 0U;
    size_t   j              = 0U;
    int32_t  res            = ENOK;
    uint64_t value          = 0U;
    uint8_t  byte_val       = 0U;
    uint8_t  loop_exit      = 0U;
    uint8_t  local_buf[IP_MASK_READ_LEN] = {0};

    if ((data == NULL) || (len == NULL))
    {
        printf("Invalid output argument\n");
    }
    else
    {
        fp = popen("/etc/swanctl/bash/ip_mask_read.sh", "r");
        if (fp == NULL)
        {
            printf("Error running script\n");
        }
        else
        {
            if (fgets(buffer, sizeof(buffer), fp) == NULL)
            {
                printf("Failed to read script output\n");
            }
            else
            {
                buffer[strcspn(buffer, "\n")] = '\0';

                space_index = strcspn(buffer, " ");

                if (space_index == 0U)
                {
                    printf("Parsing failed: no space separator found\n");
                }
                else if (space_index >= sizeof(tmp))
                {
                    printf("Parsing failed: third octet too long\n");
                }
                else
                {
                    /* extract hex string */
                    buf_pos = space_index + 1U;
                    while ((buffer[buf_pos] != '\0') &&
                           (hex_len < (sizeof(hex_str) - 1U)))
                    {
                        if (buffer[buf_pos] != ' ')
                        {
                            hex_str[hex_len] = buffer[buf_pos];
                            hex_len++;
                        }
                        buf_pos++;
                    }
                    hex_str[hex_len] = '\0';

                    if (hex_len == 0U)
                    {
                        printf("Parsing failed: empty hex mask\n");
                    }
                    else
                    {
                        /* skip 0x prefix if present */
                        i = 0U;
                        if ((hex_str[0] == '0') &&
                            ((hex_str[1] == 'x') || (hex_str[1] == 'X')))
                        {
                            i = HEX_MASK;
                        }

                        /* validate hex length */
                        if (((hex_len - i) / HEX_MASK) > BITMASK_LEN)
                        {
                            printf("Parsing failed: hex mask too long\n");
                        }
                        else
                        {
                            /* parse third octet */
                            memcpy(tmp, buffer, space_index);
                            tmp[space_index] = '\0';

                            local_buf[0] = 0x01U;           /* Version Identifier */

                            errno = 0;
                            value = (uint64_t)strtoul(tmp, NULL, STRBUF);
                            if (errno != 0)
                            {
                                printf("strtoul failed for third octet\n");
                                res = ENOK;
                            }
                            else
                            {
                                if (value <= UDS_MAX_LEN)
                                {
                                    byte_val     = (uint8_t)value;
                                }
                                local_buf[1] = byte_val;    /* Subnet (3rd octet) */

                                /* convert hex string -> bytes into local_buf[2..33] */
                                j = 0U;
                                while (((i + 1U)        <  sizeof(hex_str))  &&
                                       (hex_str[i]      != '\0')             &&
                                       (hex_str[i + 1U] != '\0')             &&
                                       (j               <  BITMASK_LEN)      &&
                                       (loop_exit       == 0U))
                                {
                                    byte_str[0] = hex_str[i];
                                    byte_str[1] = hex_str[i + 1U];
                                    byte_str[2] = '\0';

                                    errno = 0;
                                    value = (uint64_t)strtoul(byte_str, NULL, TWO_BYTE);
                                    if (errno != 0)
                                    {
                                        printf("strtoul failed at index_buf %zu\n", j);
                                        res      = ENOK;
                                        loop_exit = 1U;
                                    }
                                    else
                                    {
                                        if (value <= UDS_MAX_LEN)
                                        {
                                            byte_val     = (uint8_t)value;
                                        }
                                        local_buf[HEX_MASK + j] = byte_val;
                                        i += HEX_MASK;
                                        j++;
                                    }
                                }

                                if (loop_exit == 0U)
                                {
                                    memcpy(data, local_buf, sizeof(local_buf));
                                    *len = (uint8_t)IP_MASK_READ_LEN;
                                    res  = EOK;
                                }
                            }
                        }
                    }
                }
            }

            (void)pclose(fp);
        }
    }

    return res;
}
int32_t LockStrongSwan_Service(void) {
    int32_t res = INVALID;
    int32_t flags = EOK;
    int32_t lock_file = EOK;
    printf("\nLocking the configuration...\n");
    if (access(LOCK_FILE, F_OK) == EOK) {
        printf("\nConfiguration is already locked.\n");
        res = OPERATION_ALREADY_RUNNING;
    }
    else 
    {
        if (system("systemctl is-active --quiet strongswan") == EOK){
            lock_file = open(LOCK_FILE, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            if (lock_file < EOK) {
                printf("\nFailed to create lock file.\n");
                res = ENOK;
            }
            else{
                if (ioctl(lock_file, FS_IOC_GETFLAGS, &flags) < EOK) {
                    printf("\nError getting file flags.\n");
                    close(lock_file);
                    res = ENOK;
                }
                else{
                    flags |= FS_IMMUTABLE_FL;
                    if (ioctl(lock_file, FS_IOC_SETFLAGS, &flags) < EOK) {
                        printf("\n Not able to set Permission \n");
                        close(lock_file);
                        res = ENOK;
                    }
                    else
                    {
                        printf("\npermission set successfully.\n");
                        printf("\nConfiguration locked successfully.\n");
                        close(lock_file);
                        res = EOK;
                    }
                }
            }
            
        }
        else {
            printf("\n strongswan is not active, enable strongswan first .... \n");
            res = FORBIDDEN;
        }
    }
    printf("\n return = %d \n",res);
    return res; 
}

int32_t UnlockStrongSwan_Service(void) {
    int32_t res = INVALID;
    int32_t flags = EOK;
    int32_t lock_file = EOK;
    printf("\nUnlocking the configuration...\n");

    if (access(LOCK_FILE, F_OK) != EOK) {
        printf("\nConfiguration is not locked.\n");
        res = OPERATION_ALREADY_RUNNING;
    }
    else{
        lock_file = open(LOCK_FILE, O_RDONLY);
        if (lock_file < EOK) {
            printf("\nFailed to open lock file.\n");
            res = ENOK;
        }
        else{
            if (ioctl(lock_file, FS_IOC_GETFLAGS, &flags) < EOK) {
                printf("\nError getting file flags.\n");
                close(lock_file);
                res = ENOK;
            }
            else{
                flags &= ~FS_IMMUTABLE_FL;
                if (ioctl(lock_file, FS_IOC_SETFLAGS, &flags) == EOK) {
                    printf("\npermission removed successfully.\n");
                    close(lock_file);
                    if (remove(LOCK_FILE) == EOK)
                    {
                        printf("\n Lock file removed successfully.\n");
                        res = EOK;
                    }
                    else
                    {
                        printf("Error removing lock file");
                        res = ENOK;
                    }
                }
                else
                {
                    printf("\n Not able to remove Permission \n");
                    close(lock_file);
                    res = ENOK;
                }
            }   
        }            
        }
    printf("\n return = %d \n",res);
    return res;
}