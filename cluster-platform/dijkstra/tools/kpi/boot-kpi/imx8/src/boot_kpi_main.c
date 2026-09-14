#include <stdio.h>
#include <unistd.h>
#include "boot_kpi_qnx.h"
static void print_kpi_timestamps(void)
{
	te_KPI_ID_t ts_idx;
	KPI_LOG_t * p_ts = mmap_device_memory(NULL, sizeof(KPI_LOG_t), PROT_READ, 0, KPI_SHARED_ADDR);
	if (MAP_FAILED != p_ts)
	{
		for (ts_idx=0; ts_idx<KPI_ENTRY_LAST_INV; ts_idx++)
			printf("%10s - %dms\n", p_ts->record[ts_idx].Marker_u8A, p_ts->record[ts_idx].Time_u32);
		munmap_device_memory(p_ts,sizeof(KPI_LOG_t));
	}
}

int main()
{
	sleep(10);
	printf("Boot KPI metrics:\n");
	print_kpi_timestamps();
	return 0;
}
