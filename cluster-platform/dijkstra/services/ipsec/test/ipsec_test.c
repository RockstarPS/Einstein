#include <ipsec_service.h>
#include <err.h>

static const uint8_t ipsec_pem_data[] = {
    0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x42, 0x45, 0x47, 0x49, 0x4e, 0x20, 0x45,
    0x43, 0x20, 0x50, 0x52, 0x49, 0x56, 0x41, 0x54, 0x45, 0x20, 0x4b, 0x45,
    0x59, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a, 0x4d, 0x49, 0x47, 0x6b, 0x41,
    0x67, 0x45, 0x42, 0x42, 0x44, 0x44, 0x41, 0x7a, 0x64, 0x4b, 0x6a, 0x71,
    0x41, 0x58, 0x48, 0x4b, 0x4f, 0x4a, 0x78, 0x55, 0x70, 0x46, 0x69, 0x66,
    0x63, 0x4e, 0x33, 0x63, 0x6b, 0x32, 0x73, 0x54, 0x43, 0x6b, 0x67, 0x6e,
    0x4f, 0x49, 0x50, 0x73, 0x4a, 0x61, 0x4a, 0x33, 0x71, 0x6d, 0x7a, 0x70,
    0x45, 0x65, 0x56, 0x46, 0x67, 0x63, 0x4a, 0x64, 0x65, 0x6a, 0x4c, 0x0a,
    0x49, 0x61, 0x50, 0x35, 0x56, 0x36, 0x55, 0x75, 0x61, 0x6e, 0x79, 0x67,
    0x42, 0x77, 0x59, 0x46, 0x4b, 0x34, 0x45, 0x45, 0x41, 0x43, 0x4b, 0x68,
    0x5a, 0x41, 0x4e, 0x69, 0x41, 0x41, 0x52, 0x48, 0x67, 0x61, 0x6c, 0x59,
    0x6b, 0x2b, 0x63, 0x6f, 0x4d, 0x2f, 0x64, 0x33, 0x59, 0x33, 0x6f, 0x6c,
    0x37, 0x41, 0x45, 0x47, 0x50, 0x32, 0x65, 0x59, 0x69, 0x2b, 0x2b, 0x34,
    0x2b, 0x78, 0x55, 0x6f, 0x0a, 0x6e, 0x59, 0x55, 0x68, 0x5a, 0x33, 0x65,
    0x41, 0x6e, 0x6f, 0x4a, 0x70, 0x31, 0x63, 0x4a, 0x37, 0x2b, 0x56, 0x32,
    0x58, 0x67, 0x31, 0x65, 0x72, 0x71, 0x6a, 0x45, 0x67, 0x6f, 0x47, 0x7a,
    0x33, 0x2f, 0x45, 0x44, 0x52, 0x6e, 0x31, 0x4f, 0x7a, 0x74, 0x59, 0x4d,
    0x6f, 0x32, 0x37, 0x46, 0x4f, 0x57, 0x69, 0x36, 0x2f, 0x65, 0x33, 0x4b,
    0x53, 0x38, 0x57, 0x59, 0x33, 0x49, 0x49, 0x79, 0x51, 0x0a, 0x54, 0x44,
    0x54, 0x55, 0x61, 0x6f, 0x44, 0x46, 0x74, 0x4b, 0x65, 0x50, 0x77, 0x36,
    0x4a, 0x71, 0x66, 0x51, 0x75, 0x54, 0x48, 0x32, 0x34, 0x63, 0x44, 0x32,
    0x38, 0x77, 0x31, 0x2b, 0x77, 0x3d, 0x0a, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d,
    0x45, 0x4e, 0x44, 0x20, 0x45, 0x43, 0x20, 0x50, 0x52, 0x49, 0x56, 0x41,
    0x54, 0x45, 0x20, 0x4b, 0x45, 0x59, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a
};

static void usage(int argc, char *argv[])
{
	const char *pname = "IPSEC_STRONGSWAN";

	if (argc)
		pname = argv[0];

	fprintf(stderr, "usage: %s <requested operation>\n", pname);
	fprintf(stderr, "Operations can be requested in : %s are start, stop, disable ,restart ,status, error, ipmaskread, ipmaskwrite, lock, unlock, storekey \n", pname);
	exit(1);
}

static void get_args(int argc, char *argv[], void **request)
{
	if (argc != 2) {
		warnx("Unexpected number of arguments %d (expected 2)",
		      argc - 1);
		usage(argc, argv);
	}

	*request = argv[1];
}


int main(int argc, char *argv[]) {
    int32_t ret = ENOK;
    void *request;
    get_args(argc, argv, &request);
    uint8_t ConfigFilePath[CONFIG_PATH_LENGTH] = "/etc/swanctl/swanctl.conf";
    if ((open((const char *)ConfigFilePath, O_RDONLY, S_IRUSR)) == -1) {
        printf("\n Swanctl configuration not present, failed to start strongswan service \n");
    }
    else {
        if (strcmp(request,"start") == EOK) {
                ret = StartStrongSwan_Service();
                if (ret == EOK) {
                    printf("\n IPSEC enabled and started successfully \n");
                }
        }
        else if (strcmp(request,"stop") == EOK) {
            ret = StopStrongSwan_Service();
            if (ret == EOK) {
                printf("\n IPSEC service stopped successfully \n");
            }
        }
        else if (strcmp(request,"disable") == EOK) {
            ret = DisableStrongSwan_Service();
            if (ret == EOK) {
                printf("\n IPSEC disabled and stopped successfully \n");
            }
        }
        else if (strcmp(request,"restart") == EOK) {
            ret = RestartStrongSwan_Service();
            if (ret == EOK) {
                printf("\n IPSEC restarted successfully \n");
            }
        }
        else if (strcmp(request, "status") == EOK)
        {
            uint8_t status[STATUS_LEN];
            uint8_t statusLen = 0U;
            ret = StatusStrongSwan_Service(status, &statusLen);
        
            if (ret == EOK)
            {
                printf("\nIPSEC status fetched successfully\n");
                printf("Length: %u\n", statusLen);
            
                for (uint8_t i = 0U; i < statusLen; i++)
                {
                    printf("STATUS[%u] = %u\n", i, status[i]);
                }
            }
            else
            {
                printf("\nIPSEC status fetch FAILED\n");
            }
        }
        else if (strcmp(request, "error") == EOK)
        {
            uint8_t error[MAX_ERROR];
            uint8_t errorLen = 0U;
            ret = ErrorStrongSwan_Service(error, &errorLen);
        
            if (ret == EOK)
            {
                printf("\nIPSEC error fetched successfully\n");
                printf("Length: %u\n", errorLen);
            
                for (uint8_t i = 0U; i < errorLen; i++)
                {
                    printf("ERROR[%u] = 0x%u\n", i, error[i]);
                }
            }
            else
            {
                printf("\nIPSEC error fetch FAILED\n");
            }
        }
        else if (strcmp(request, "ipmaskread") == EOK)
        {
            uint8_t data[IP_MASK_READ_LEN] = {0};
            uint8_t data_len               = 0U;
            ret = IpMaskReadStrongSwan_Service(data, &data_len);
            if (ret == EOK)
            {
                printf("\nIPSEC IP mask read successfully\n");
                printf("Version Identifier: 0x%02X\n",       data[0]);
                printf("Subnet (3rd octet): 0x%02X (%u)\n",  data[1], data[1]);
                printf("Bitmask (%u bytes):\n", data_len - 2U);
                for (uint8_t i = 2U; i < data_len; i++)
                {
                    printf("0x%02X ", data[i]);
                    if (((i - 1U) % 8U) == 0U)
                    {
                        printf("\n");
                    }
                }
                printf("\n");
                printf("data_len = %u\n", data_len);
            }
            else
            {
                printf("\nIPSEC IP mask read Error\n");
            }
        }
        else if (strcmp(request, "ipmaskwrite") == EOK)
        {
            uint8_t uds_req[EXPECTED_PAYLOAD_LEN] = {
                0x2EU, 0x80U, 0x17U, 0x01U, 0xC7U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
                0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
                0x00U, 0x00U, 0x00U, 0x00U, 0x01U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
                0x00U, 0x00U, 0x00U, 0x00U, 0x01U, 0x04U, 0x00U
            };
            ret = IpMaskStrongSwan_Service(uds_req, (uint8_t)sizeof(uds_req));
            if (ret == EOK)
            {
                printf("\nIPSEC IP masked successfully\n");
            }
            else
            {
                printf("\nIPSEC IP masked Error\n");
            }
        }
		else if (strcmp(request,"lock") == EOK) {
            ret = LockStrongSwan_Service();
            if (ret == EOK) {
                printf("\n Configuration locked successfully \n");
            }
        }
        else if (strcmp(request,"unlock") == EOK) {
            ret = UnlockStrongSwan_Service();
            if (ret == EOK) {
                printf("\n Configuration unlocked successfully \n");
            }
		}
        else if (strcmp(request,"storekey") == EOK)  {
            ret = securitymanager_store_ipsec_key(ipsec_pem_data, sizeof(ipsec_pem_data));
            if (ret == EOK) {
                printf("\n IPSEC key stored successfully \n");
            }
            else{
                printf("\n IPSEC key store Error \n");
            }
        }
        else if (strcmp(request,"lockstatus") == EOK) {
            ret = LockStatus_Service();
            if (ret == EOK) {
                printf("\n Configuration locked status updated \n");
            }
        }
        else if (strcmp(request,"enablestatus") == EOK) {
            ret = EnableStatus_Service();
            if (ret == EOK) {
                printf("\n Configuration enable status updated \n");
            }
		}
        else {
            printf("Invalid option\n");
        }
        
    }
    return ret;
}