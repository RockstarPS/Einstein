#include <stdio.h>
#include <stdlib.h>
#include "dk_bspal_deserializer.h"
#include "dk_bspal_dio.h"
#include "CDio_Ioctl.h"

#define MDI_DES_READY GPIO0_70


void streaming_start() {
    if (dk_bspal_deserializer_streaming_control(DESERIALIZER_START) == 0) {
        printf("DeSerializer streaming started successfully.\n");
    } else {
        printf("Failed to start Deserializer streaming.\n");
    }
}

void streaming_stop() {
    if (dk_bspal_deserializer_streaming_control(DESERIALIZER_STOP) == 0) {
        printf("DeSerializer streaming stopped successfully.\n");
    } else {
        printf("Failed to stop Deserializer streaming.\n");
    }
}

void get_status() {
    int status;
    if (dk_bspal_deserializer_get_status(DESERIALIZER_LINK_STATUS, &status) == 0) {
        printf("Retrieved Deserializer device status successfully: %d\n", status);
    } else {
        printf("Failed to get Deserializer device status.\n");
    }
}

void get_error_status() {
    int status;
    if (dk_bspal_deserializer_get_status(DESERIALIZER_ERROR_STATUS, &status) == 0) {
        printf("Retrieved Deserializer Error status successfully: %d\n", status);
    } else {
        printf("Failed to get Deserializer Error status.\n");
    }
}

void get_ready_status() {

    int status = -1;
    bool ready_pin = false;
    printf("before status\n");
    status = dk_bspal_dio_get_value(MDI_DES_READY, &ready_pin);
    printf("after status\n");
    if (status == 0) {
        if (ready_pin) {
            printf("MDI_DES_READY is HIGH (Ready)\n");
        } else {
            printf("MDI_DES_READY is LOW (Not Ready)\n");
        }
    } else {
        printf("Failed to read MDI_DES_READY status\n");
    }

}

void initialize_deser() {

    if (dk_bspal_deserializer_configure(DESERIALIZER_INIT)   == 0) {
        printf("DeSerializer initialized successfully.\n");
    } else {
        printf("Failed to initialize Deserializer.\n");
    }
}

void deinitialize_deser() {

    if (dk_bspal_deserializer_configure(DESERIALIZER_DEINIT)   == 0) {
        printf("DeSerializer deinitialized successfully.\n");
    } else {
        printf("Failed to deinitialize Deserializer.\n");
    }
}

void enable_test_pattern(){
    int status;
    if (dk_bspal_deserializer_test_pattern(DESERIALIZER_TEST_PATTERN)==0){
        printf("Deserailizer Test Pattern Enabled.\n");
    } else {
        printf("Failed to stop Deserializer streaming.\n");
    }
}


int main(int argc, char *argv[]) {
    int choice = 0;

    if (argc < 2) {
        printf("Deserializer Test utility\n");
        printf("1. Initialize deserializer\n");
        printf("2. Deinitialize deserializer\n");
        printf("3. Start Streaming\n");
        printf("4. Stop Streaming\n");
        printf("5. Get Device Status\n");
        printf("6. Get Error Status\n");
        printf("7. Get ready signal status\n");
        printf("8. Test Pattern Enable \n");
        return 1;
    }

    choice = atoi(argv[1]);

    switch (choice) {
        case 1:
            printf("Option 1: Initialize deserializer\n");
            initialize_deser();
            break;

        case 2:
            printf("Option 2: Deinitialize deserializer\n");
            deinitialize_deser();
            break;

        case 3:
            printf("Option 3: Start Streaming\n");
            streaming_start();
            break;

        case 4:
            printf("Option 4: Stop Streaming\n");
            streaming_stop();
            break;

        case 5:
            printf("Option 5: Get Device Status\n");
            get_status();
            break;

        case 6:
            printf("Option 6: Get ready signal status\n");
            get_error_status();
            break;

        case 7:
            printf("Option 5: Get Device Status\n");
            get_ready_status();
            break;

        case 8:
            printf("8. Test Pattern Enable \n");
            enable_test_pattern();
            break;

        default:
            printf("Invalid option: %d\n", choice);
            break;
    }

    return 0;
}

