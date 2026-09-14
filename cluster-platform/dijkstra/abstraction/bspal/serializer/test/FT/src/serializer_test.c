#include <stdio.h>
#include <stdlib.h>
#include "dk_bspal_serializer.h"


void serializer_init() 
{
    if (dk_bspal_serializer_configure(SERIALIZER_INIT) == 0) 
    {
        printf("Serializer initialized successfully.\n");
    } 
    else 
    {
        printf("Failed to initialize serializer.\n");
    }
}

void serializer_deinit() 
{
    if (dk_bspal_serializer_configure(SERIALIZER_DEINIT) == 0) 
    {
        printf("Serializer deinitialized successfully.\n");
    } 
    else 
    {
        printf("Failed to deinitialize serializer.\n");
    }
}

void streaming_start() 
{
    if (dk_bspal_serializer_streaming_control(SERIALIZER_START) == 0) 
    {
        printf("Serializer streaming started successfully.\n");
    } 
    else 
    {
        printf("Failed to start serializer streaming.\n");
    }
}

void streaming_stop() 
{
    if (dk_bspal_serializer_streaming_control(SERIALIZER_STOP) == 0) 
    {
        printf("Serializer streaming stopped successfully.\n");
    } 
    else 
    {
        printf("Failed to stop serializer streaming.\n");
    }
}

void get_link_status() 
{
    int status;
    if (dk_bspal_serializer_get_status(SERIALIZER_LINK_STATUS, &status) == 0) 
    {
        printf("Serializer link status: %d\n", status);
    } 
    else 
    {
        printf("Failed to get serializer link status.\n");
    }
}

void get_error_status() 
{
    int status;
    if (dk_bspal_serializer_get_status(SERIALIZER_ERROR_STATUS, &status) == 0) 
    {
        printf("Serializer error status: %d\n", status);
    } 
    else 
    {
        printf("Failed to get serializer error status.\n");
    }
}

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Usage: %s <option>\n", argv[0]);
        printf("CXD4951 - Serializer Test Utility\n");
        printf("1. Initialize Serializer\n");
        printf("2. Deinitialize Serializer\n");
        printf("3. Start Streaming\n");
        printf("4. Stop Streaming\n");
        printf("5. Get Link Status\n");
        printf("6. Get Error Status\n");
        return 1;
    }

    int choice = atoi(argv[1]);
    switch (choice) 
    {
        case 1:
            serializer_init();
            break;
        case 2:
            serializer_deinit();
            break;
        case 3:
            streaming_start();
            break;
        case 4:
            streaming_stop();
            break;
        case 5:
            get_link_status();
            break;
        case 6:
            get_error_status();
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
    return 0;

}


