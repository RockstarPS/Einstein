/*---------------------------------------------------------------------------------------------------------------------

 VISTEON CORPORATION CONFIDENTIAL
 ________________________________

 [2020] Visteon Corporation
 All Rights Reserved.

 NOTICE: This is an unpublished work of authorship, which contains trade secrets.
 Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
 under all copyright laws to protect this work as a published work, when appropriate.
 Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
 without the written authorization of Visteon Corporation.

---------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>
#include <spawn.h>
#include "debug.h"
#include "res_mon.h"

#define COMPRESS_BIN                    "/bin/tar"
#define COMPRESS_OPT                    "zcf"
#define ENCRYPT_BIN                     "/usr/bin/openssl"
#define ENCRYPT_KEY                     "5a1f2edcdca50198e634e4b361e603e5"
#define DATA_STORE                      "/data"
#define CORE_DUMP_STORE                 "core_dumps"
#define DLT_LOG_STORE                   "dlt_logs"
#define DLT_ARCHIVED_LOG_STORE          "archived_dlt_logs"
#define PACKAGE_OUT_PATH                "/tmp"
#define DLT_LOGS_OUT_PATH               "/data/dlt_logs"
#define PACKAGE_DLT_LOGS_OUT_PATH       "/data/archived_dlt_logs"

#define MAX_COMMAND_SIZE   100
#define MAX_PATH_SIZE      100

int32_t ParseFileExtensionsInDirectory(const struct dirent *directory)
{
    if (directory == NULL)
       return 0;

    const char *fileExtension = strrchr(directory->d_name,'.');

    if ((fileExtension == NULL) || (fileExtension == directory->d_name))
        return 0;
    else 
    {
        if (strcmp(fileExtension, ".dlt") == 0)
            return 1;
    }

     return 0;
}
void CopyLogsForPackageFromRamToFlash()
{
    char    copyCommand[MAX_COMMAND_SIZE]   = { 0 };
    struct  dirent **nameList               = NULL;
    int32_t numberOfFilesWithGivenExtension = 0;

    numberOfFilesWithGivenExtension = scandir("/tmp", &nameList, ParseFileExtensionsInDirectory, alphasort);

    while (numberOfFilesWithGivenExtension--) 
    {
        (void)memset(copyCommand, 0, MAX_COMMAND_SIZE);

        (void)sprintf(copyCommand,"cp /tmp/%s %s",nameList[numberOfFilesWithGivenExtension]->d_name, DLT_LOGS_OUT_PATH);

        (void)system(copyCommand);
    }
}
void RemoveAlreadyArchivedLogsFromFlash()
{
    char    pathToFileForRemoving[MAX_PATH_SIZE] = { 0 };
    struct  dirent **nameList                    = NULL;
    int32_t numberOfFilesWithGivenExtension      = 0;

    numberOfFilesWithGivenExtension = scandir(DLT_LOGS_OUT_PATH, &nameList, ParseFileExtensionsInDirectory, alphasort);

    while (numberOfFilesWithGivenExtension--) 
    {
        (void)memset(pathToFileForRemoving, 0 , MAX_PATH_SIZE);

        (void)sprintf(pathToFileForRemoving,"%s/%s",DLT_LOGS_OUT_PATH, nameList[numberOfFilesWithGivenExtension]->d_name);

        (void)remove(pathToFileForRemoving);
    }
}

int32_t ResMonPackage_Create( uint32_t encrypt, char *file, uint32_t size )
{
    int32_t ret = RM_FAILED;
    int32_t sts;
    struct timespec tp;
    char pack_filename[PACKAGE_PATH_MAX];
    char pack_filename_enc[PACKAGE_PATH_MAX];
    pid_t pid = -1;
    int32_t ret_val = 0;

    memset( pack_filename, 0, sizeof( pack_filename ) );
    memset( pack_filename_enc, 0, sizeof( pack_filename_enc ) );

    CopyLogsForPackageFromRamToFlash();

    if( (uint32_t) clock_gettime( CLOCK_MONOTONIC, &tp ) == 0U )
    {
        ret_val = snprintf( pack_filename, PACKAGE_PATH_MAX, "%s/package-%lu-%lu.tar.gz", PACKAGE_OUT_PATH, tp.tv_sec, tp.tv_nsec );
        if ( 0 > ret_val )
        {
            LOGE ( "%s", "snprintf failed" );
        }

        char *compress_args[] = { COMPRESS_BIN,COMPRESS_OPT,
                                  pack_filename, "-C",
                                  DATA_STORE, CORE_DUMP_STORE, DLT_LOG_STORE,DLT_ARCHIVED_LOG_STORE,
                                  (char *) 0 };

        if( posix_spawn ( &pid, COMPRESS_BIN, NULL, NULL, compress_args, NULL ) == 0U )
        {
            if (waitpid( pid, &sts, 0 ) != -1)
            {
                memset( file, 0, PACKAGE_PATH_MAX );
                memcpy( file, pack_filename, PACKAGE_PATH_MAX );
                ret = RM_OK;
            }
            else
            {
                LOGE ( "%s", "waitpid failed" );
            }
        }
        else
        {
            LOGE ( "%s", "Cannot spawn process to create the package" );
        }
    }
    else
    {
        LOGE ( "%s", "ClockTime_r Failed" );
    }

    if( (ret == RM_OK ) && ( TRUE == encrypt ) )
    {
        /* openssl enc -aes-256-cbc -md sha256 -salt -in <plain text file> -out <encrypted file> -k <password> */
        /* openssl enc -aes-256-cbc -md sha256 -d -<encrypted file> -out <plain text file> -k <password> */
        ret = RM_FAILED;
        ret_val = 0;
        ret_val = snprintf(pack_filename_enc, PACKAGE_PATH_MAX, "%s/package-%lu-%lu.dat", PACKAGE_OUT_PATH, tp.tv_sec, tp.tv_nsec );
        if ( 0 > ret_val )
        {
            LOGE ( "%s", "snprintf failed" );
        }

        char *encrypt_args[] = { ENCRYPT_BIN, "enc", "-aes-256-cbc",
                                 "-md", "sha256", "-salt",
                                 "-in", pack_filename,
                                 "-out", pack_filename_enc,
                                 "-k", ENCRYPT_KEY,
                                 (char *) 0 };

        if( (uint32_t) posix_spawn ( &pid, ENCRYPT_BIN, NULL, NULL, encrypt_args, NULL ) == 0U )
        {
            if ( waitpid ( pid, &sts, 0 ) != -1 )
            {
                (void) remove ( pack_filename );
                memset( file, 0, PACKAGE_PATH_MAX );
                memcpy( file, pack_filename_enc, PACKAGE_PATH_MAX );
                ret = RM_OK;
            }
            else
            {

                LOGE ( "%s", "waitpid failed" );
            }
        }
    }

    RemoveAlreadyArchivedLogsFromFlash();

    return ret;
}

int32_t ResMonPackage_CreatePackageWithDLTLogs(char *file, uint32_t size)
{
    int32_t ret = RM_FAILED;
    int32_t sts;
    struct timespec tp;
    char pack_filename[PACKAGE_PATH_MAX];
    char pack_filename_enc[PACKAGE_PATH_MAX];
    pid_t pid = -1;
    int32_t ret_val = 0;

    memset( pack_filename, 0, sizeof( pack_filename ) );
    memset( pack_filename_enc, 0, sizeof( pack_filename_enc ) );
    
    CopyLogsForPackageFromRamToFlash();

    if( (uint32_t) clock_gettime( CLOCK_MONOTONIC, &tp ) == 0U )
    {
        ret_val = snprintf( pack_filename, PACKAGE_PATH_MAX, "%s/package-%lu-%lu.tar.gz", PACKAGE_DLT_LOGS_OUT_PATH, tp.tv_sec, tp.tv_nsec );
        if ( 0 > ret_val )
        {
            LOGE ( "%s", "snprintf failed" );
        }

        char *compress_args[] = { COMPRESS_BIN,COMPRESS_OPT,
                                  pack_filename, "-C",
                                  DATA_STORE, DLT_LOG_STORE,
                                  (char *) 0 };

        if( posix_spawn ( &pid, COMPRESS_BIN, NULL, NULL, compress_args, NULL ) == 0U )
        {
            if (waitpid( pid, &sts, 0 ) != -1)
            {
                memset( file, 0, PACKAGE_PATH_MAX );
                memcpy( file, pack_filename, PACKAGE_PATH_MAX );

                sync();

                ret = RM_OK;
            }
            else
            {
                LOGE ( "%s", "waitpid failed" );
            }
        }
        else
        {
            LOGE ( "%s", "Cannot spawn process to create the package" );
        }
    }
    else
    {
        LOGE ( "%s", "ClockTime_r Failed" );
    }

    RemoveAlreadyArchivedLogsFromFlash();

    return ret;
}