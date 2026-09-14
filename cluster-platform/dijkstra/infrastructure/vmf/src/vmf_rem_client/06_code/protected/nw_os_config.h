
#ifndef VMF_CO_DATA_LEN
#define VMF_CO_DATA_LEN (16*1024)
#endif

void * nw_os_smemcpy(void *dest, size_t dest_len, void* src, size_t src_len);
void * nw_os_malloc(size_t size);
void nw_os_free(void *ptr);

