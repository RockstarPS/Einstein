
#ifndef GDC_H_
#define GDC_H_

typedef struct { int hw_all_err; } GDC_ERR_INFO;
typedef struct { int sw_all_err; } GDC_SW_ERR_INFO;
typedef int GDC_ENUM;
typedef int EL_ERROR;

#define GDC_SUCCESS 1

#define GdcInitDriver() 1

#define GdcGetSoftwareError(a) 1

#define GdcGetError() 1


#define __attribute__(a)

#endif
