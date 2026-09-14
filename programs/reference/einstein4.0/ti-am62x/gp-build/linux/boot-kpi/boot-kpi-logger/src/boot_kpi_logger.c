#include <stdio.h>
#include "boot_kpi_a53_linux.h"

int main(int argc, char *argv[])
{
    const char *plabel = NULL;
    if (argc != 2) {
        printf("Usage: %s <ENUM_NAME> <10-char-string>\n", argv[0]);
        return 1;
    }
    plabel = argv[1];
    if(strcmp(plabel, "safehmi_start") == 0) {
        BOOT_KPI_LOG(KPI_ID_GIP_SAFE_HMI_START, "Safe HMI START");
    } else if(strcmp(plabel, "safehmi_end") == 0) {
        BOOT_KPI_LOG(KPI_ID_GIP_SAFE_HMI_END, "Safe HMI END");
    } else if(strcmp(plabel, "MainHmi_start") == 0) {
        BOOT_KPI_LOG(KPI_ID_GIP_FULL_HMI_START, "MainHmi START");
    } else if(strcmp(plabel, "MainHmi_end") == 0) {
        BOOT_KPI_LOG(KPI_ID_GIP_FULL_HMI_END, "MainHmi END");
    } else {
        printf("Enter KPI name \r\n");
    }
    return 0;
}