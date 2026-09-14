# Key Performance Indices

## Steps to integrate BOOT-KPI

### Memory Section used for KPI logging

Update the `SHARED_MEMORY_ADDRESS` macro in `boot_kpi.h`

```c
#define SHARED_MEMORY_ADDRESS 0x43C38000
```

### Source Code Integration

- Include the header `boot_kpi_<core>_<xxx>.h` in all files where `BOOT_KPI_LOG` is called in DM/VIP/HSM/GIP Side. 

```c
#include "boot_kpi_r5_dm.h"
```

If your binary is the first binary to start(Usually in DM) - clear the shared memory section.

```c
BOOT_KPI_CLEAR(); /* To be called only once in first stage */
```

### Logging Events

- Call the BOOT_KPI_LOG to get the time and log the time in shared memory region.

```c
BOOT_KPI_LOG(KPI_ID_SBL_S1_SYSTEM_INIT, "SBL_S1_SYSINIT");
```
