#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define int32_t int
#define uint8_t char

#define CONFIG_PATH_LENGTH 26

int32_t StartStrongSwan_Service(void) {
    int32_t res = -1;
    if(system("systemctl stop strongswan-starter")== 0){
        printf("\n strongswan starter stopped\n");
    }
    else{
        printf("\n strongswan starter stop error");
    }

    if (system("systemctl enable strongswan") == 0) {
        printf("\nStrongSwan enabled successfully proceeding to start the service\n");
        if (system("systemctl start strongswan") == 0) {
            printf("\n StrongSwan started successfully proceeding to start the service \n");
            res = 0;
        }
        else {
            printf("\n Failed to start stronswan \n");
        }
    }

    
    return res;
}

void main(void) {
    int32_t ret = -1;
    uint8_t ConfigFilePath[CONFIG_PATH_LENGTH] = "/etc/swanctl/swanctl.conf";
    if ((open(ConfigFilePath, O_RDONLY, S_IRUSR)) == -1) {
        printf("\n Swanctl configuration not present failed to start strongswan service \n");
    }
    else {
        ret = StartStrongSwan_Service();
        if (ret == 0) {
            printf("\n IPSEC enabled and started successfully \n");
        }
    }

    return;
}