#ifndef DEVCTL_H
#define DEVCTL_H

#include <sys/types.h>

#define EOK (0)

#define DCMD_I2C_RECV (0)

extern int
devctl(int fd, int dcmd, void *dev_data_ptr, size_t nbytes, int *dev_info_ptr);

#endif /* DEVCTL_H */