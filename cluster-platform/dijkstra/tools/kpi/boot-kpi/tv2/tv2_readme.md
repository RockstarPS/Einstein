# Key Performance Indices

## Steps to integrate BOOT-KPI

### Linker Directive Integration

Add the following in the `MEMORY` section of `memory_map.ld`

```c
KPI_SHARED_MEMORY : ORIGIN = 0xXXXXXXXX, LENGTH = 0xXX
```

Add the following in the `SECTIONS` section of your `linker_directives.ld`

```c
.bss_kpi_shared_memory : > KPI_SHARED_MEMORY
```

### Source Code Integration

- Include the header `boot_kpi_var.h` in any one file in HSM or APP Side.

- Include the header based on your binary
  - [HSM](./include/boot_kpi_hsm.h)
  - [BL](./include/boot_kpi_bl.h)
  - [APP](./include/boot_kpi_asr.h)

```c
#include "boot_kpi_var.h"
#include "boot_kpi_hsm.h"
```

If your binary is the first binary to start - clear the shared memory section.

```c
BOOT_KPI_CLEAR(); /* Only HSM will call it to clear the address. */
```

### Logging Events

- Call the BOOT_KPI_LOG to get the time from HSM and log the time in shared memory region.

```c
BOOT_KPI_LOG(KPI_ENTRY_HSM_HSM_AUTH, "HSM_HSM_AUTH", sizeof("HSM_HSM_AUTH"));
```
