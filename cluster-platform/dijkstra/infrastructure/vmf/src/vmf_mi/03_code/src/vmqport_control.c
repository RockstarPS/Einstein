/*
 * Copyright (c) 2013 OpenSynergy GmbH.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Author: Axel Soeding-Freiherr von Blomberg <axel.vonblomberg@opensynergy.com>
 */


#include "nw_os_config.h"

/* jmerkle  01.10.2013 14:49:15 */
/* jmerkle  #include <stdio.h> */
/* jmerkle  #include <stdlib.h> */
/* jmerkle  #include <unistd.h> */
/* jmerkle  #include <fcntl.h> */
/* jmerkle  #include <pthread.h> */
/* jmerkle  #include <sys/types.h> */
/* jmerkle  #include <dirent.h> */
/* jmerkle  #include <sys/stat.h> */
/* jmerkle  #include <string.h> */
#include "vmqport_control.h"

// #define LOCAL_TEST
#define CONSOLE_OUTPUT
#define SYSPATH_FILENAME_BUFSIZE 128

#ifdef LOCAL_TEST
#define SYSPATH_VMQPORT_DIRNAME     "/tmp"
#else
#define SYSPATH_VMQPORT_DIRNAME     "/sys/devices/virtual/vmport_char"
#endif

#define SYS_VMQPORT_PNAME_FILENAME  "portname"
#ifdef LOCAL_TEST
#define DEV_DIRNAME                 "/tmp"
#else
#define DEV_DIRNAME                 "/dev"
#endif

#define VMQ_ERROR                   -1
#define VMQ_OK                      0

/**************************************************************************//**
 *
 *   Function Name: find_qportdev_by_portname()
 *   Description:   search for a VMQ message queue in 
 *                  SYSPATH_VMQPORT_DIRNAME folder
 *   \param         message queue name (in)
 *   \param         device-name buffer (out)
 *   \param         lenght of device-name buffer (in)
 *   \return        VMQ_OK if OK,  VMQ_ERROR if error
 *
 ******************************************************************************/
static int find_qportdev_by_portname(const char *portname, char *devicename,int devname_len)
{
    int ret = VMQ_ERROR;

/* jmerkle  01.10.2013 14:49:08 */
#ifndef __WINDOWS__
    struct dirent **namelist=NULL;
    int n=0;

    /* argument check */
    if ((0 == devname_len)   ||
        (NULL == devicename) ||
        (NULL == portname))
    {
#ifdef CONSOLE_OUTPUT        
        (void) fprintf(stderr,"vmqport_control.c: find_qportdev_by_portname() argument error\n");
#endif
        return 0;
    }

    n = scandir(SYSPATH_VMQPORT_DIRNAME, &namelist, 0, alphasort);
    if (n < 0)
    {
#ifdef CONSOLE_OUTPUT        
        (void) fprintf (stderr,"'%s' - ",SYSPATH_VMQPORT_DIRNAME);
        perror("scandir: ");
#endif        
        return 0;
    }
    
    /* start to search for file "portname" in all found directories */
    while (n--) 
    {
        char        pname_buf[SYSPATH_FILENAME_BUFSIZE]={0};
        unsigned8   buf_len;
        if (VMQ_ERROR == ret)
        {
            int fd;
            off_t size;
            (void) strncpy(pname_buf, SYSPATH_VMQPORT_DIRNAME,sizeof(pname_buf));
            buf_len = strlen(pname_buf);
            (void) strncat(pname_buf, "/",sizeof(pname_buf)-buf_len-1);
            buf_len = strlen(pname_buf);
            (void) strncat(pname_buf, namelist[n]->d_name,sizeof(pname_buf)-buf_len-1);
            buf_len = strlen(pname_buf);
            (void) strncat(pname_buf, "/",sizeof(pname_buf)-buf_len-1);
            buf_len = strlen(pname_buf);
            (void) strncat(pname_buf, SYS_VMQPORT_PNAME_FILENAME,sizeof(pname_buf)-buf_len-1);
            fd = open(pname_buf, O_RDONLY);
            if (fd < 0)
            {
                continue;
            }
            else
#ifdef CONSOLE_OUTPUT        
            {
//                (void) fprintf(stderr,"found %s\n",pname_buf);
            }
#endif            
            size = read(fd, pname_buf, SYSPATH_FILENAME_BUFSIZE - 1);
            if ((size > 0) && (size < devname_len))
            {
                pname_buf[size] = '\0';
                if (pname_buf[size-1] < 0x20)
                {
                    /* remove 0x0a*/
                    pname_buf[size-1] = '\0';
                }

                if (!strcmp(portname, pname_buf))
                {
                    (void) strncpy(devicename, DEV_DIRNAME,devname_len);
                    (void) strncat(devicename, "/",devname_len);
                    (void) strncat(devicename, namelist[n]->d_name,devname_len);
                    ret = VMQ_OK;
                }
            }
            (void) close(fd);
        }
        (void)free(namelist[n]);
    }

    if (NULL != namelist)
    {
        free(namelist);
    }
#ifdef CONSOLE_OUTPUT        
    (void) fprintf(stderr,"vmqport_control.c: find_qportdev_by_portname(%s): %s\n", portname, (VMQ_OK==ret ? devicename : "<none>"));
#endif
#endif
    return ret;
}





/**************************************************************************//**
 *
 *   Function Name: open_vmqportdev_by_portname()
 *   Description:   Open a VMQ message queue
 *
 *   \param         message queue name (in)
 *   \param         flags
 *   \return        fd if OK, -1 if error
 *
 ******************************************************************************/
int open_vmqportdev_by_portname(const char *portname, int flags)
{
    int fd = -1;

/* jmerkle  01.10.2013 14:49:26 */
#ifndef __WINDOWS__
    char pname_buf[SYSPATH_FILENAME_BUFSIZE]={0};

    if (VMQ_OK == find_qportdev_by_portname(portname, pname_buf,sizeof(pname_buf)-1))
    {
#ifdef LOCAL_TEST
        strncat(pname_buf,"/",sizeof(pname_buf));
        strncat(pname_buf,portname,sizeof(pname_buf));
#endif
        fd = open(pname_buf, flags);
        if (0 == fd)
        {
#ifdef CONSOLE_OUTPUT        
            (void) fprintf(stderr,"open '%s' failed - ",portname);
            perror("open");
#endif            
        }
    }
/* jmerkle  01.10.2013 14:49:30 */
#endif

    return fd;
}
