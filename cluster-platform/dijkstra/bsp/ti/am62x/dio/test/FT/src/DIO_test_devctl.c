#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <devctl.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdbool.h>

#include "CDio_Devctl.h"

char *buffer;
int dir_write(uint32_t dir);
int data_write(uint32_t value);
int dir_read();
int data_read();
static bool options ( const int32_t argc, char **const argv );
void usage();
void usage()
{}

uint8_t pinGpio;
uint32_t dir;
uint32_t value;

#define DIRECTION_PATH 	"/dev/gpio/gpio%d/direction"
#define VALUE_PATH 		"/dev/gpio/gpio%d/value"

static char exportPathDirection[PATH_MAX] = {};
static char exportPathValue[PATH_MAX] = {};

/*!*******************************************************************************************************************
Function Name: main
@brief     Main function for DIO functional test
@param[in] argc int Count of command line parameters.
@param[in] argv[] char**  Command line parameters .
@return    int    exit status
 *********************************************************************************************************************/
int main(int argc, char *argv[])
{

    options(argc, argv);
    return EXIT_SUCCESS;
}

/*!****************************************************************************
Function Name: dir_write
 @brief     Function that is called to write the direction of gpio.
 @param     dir in or out parsed from command line.
 @return    int Return Error code to indicate success or failure
 *****************************************************************************/
int dir_write(uint32_t dir)
{
    int fd, ret;

    fd = open(exportPathDirection, O_RDWR);
    if(fd < 0)
    {
        printf("opening the device %s failed \n", exportPathDirection);
    }
    gpio_buffer_type gpioBuf;
    gpioBuf.e_direction = dir;

    ret = devctl(fd, GPIO_DIRECTION_WRITE, &gpioBuf, sizeof(gpioBuf),NULL);

    close(fd);

    return ret;
}

/*!****************************************************************************
Function Name: data_write
 @brief     Function that is called to write the data to gpio.
 @param     data high or low parsed from command line.
 @return    int Return Error code to indicate success or failure
 *****************************************************************************/
int data_write(uint32_t data)
{
    int fd, ret;

    fd = open(exportPathValue, O_RDWR);
    if(fd < 0)
    {
        printf("opening the device %s failed \n", exportPathValue);
    }

    gpio_buffer_type gpioBuf;
    gpioBuf.gpio_value = data;

    ret = devctl(fd, GPIO_VALUE_WRITE, &gpioBuf, sizeof(gpioBuf),NULL);

    close(fd);

    return ret;
}

/*!****************************************************************************
Function Name: dir_read
 @brief     Function that is called to read the direction of gpio.
 @param     None
 @return    int Return Error code to indicate success or failure
 *****************************************************************************/
int dir_read()
{
    int fd, ret;

    fd = open(exportPathDirection, O_RDWR);
    if(fd < 0)
    {
        printf("opening the device %s failed \n", exportPathDirection);
    }
    gpio_buffer_type gpioBuf;

    ret = devctl(fd, GPIO_DIRECTION_READ, &gpioBuf, sizeof(gpioBuf),NULL);
    printf("Direction is %d \n", gpioBuf.e_direction);

    close(fd);

    return ret;
}

/*!****************************************************************************
Function Name: data_read
 @brief     Function that is called to read the data of gpio.
 @param     None
 @return    int Return Error code to indicate success or failure
 *****************************************************************************/
int data_read()
{
    int fd, ret;

    fd = open(exportPathValue, O_RDWR);
    if(fd < 0)
    {
        printf("opening the device %s failed \n", exportPathValue);
    }
    gpio_buffer_type gpioBuf;

    ret = devctl(fd, GPIO_VALUE_READ, &gpioBuf, sizeof(gpioBuf),NULL);
    printf("Value is %d \n", gpioBuf.gpio_value);

    close(fd);

    return ret;
}

/*!*******************************************************************************************************************
Function Name: getopt_chk
@brief     Function to parse the options from the command line.
@param[out] p_opt char* to be parsed from command line.
@param[in] p_argc int Count of command line parameters for the Resource manager.
@param[in] p_argv[] char**  Command line parameters for the resource manager
@return    bool    Return value to indicate true or false for the operation done
 *********************************************************************************************************************/
static bool getopt_chk ( char *const p_opt, const int32_t p_argc, char *const p_argv[] )
{
    bool l_ret_val = false;
    int32_t l_getopt_ret;
    l_getopt_ret = getopt ( p_argc, p_argv, "p:W:w:R:r:" );

    if ( l_getopt_ret < 0 )
    {
        l_ret_val = false;
        *p_opt = ( char ) 0;
    }
    else
    {
        l_ret_val = true;
        *p_opt = ( char ) l_getopt_ret;
    }

    return ( l_ret_val );
}

/*!*******************************************************************************************************************
Function Name: options
@brief     Function to check the options passed from command line.
@param[in] argc int Count of command line parameters.
@param[in] argv[] char**  Command line parameters.
@return    bool    Return value to indicate true or false for the operation done
 *********************************************************************************************************************/
static bool options ( const int32_t argc, char **const argv )
{
    char l_opt = '0';
    bool l_ret = true;
    int l_status;

    // put ':' in the starting of the
    // string so that program can
    //distinguish between '?' and ':'

    while ( true == getopt_chk ( &l_opt, argc, argv ) )
    {
        switch ( l_opt )
        {
        case 'p':
            errno = EOK;
            pinGpio = ( uint32_t ) strtol ( optarg, NULL, 0 );

            if ( errno != EOK )
            {
                if ( errno == ERANGE )
                {
                    l_status = errno;
                    printf("Failed strtol %s and status is %d \n ", strerror ( errno ), l_status );
                    l_ret = false;
                }
            }
            else
            {
                (void)snprintf(exportPathDirection, PATH_MAX, DIRECTION_PATH, pinGpio );
                (void)snprintf(exportPathValue, PATH_MAX, VALUE_PATH, pinGpio);
            }
            break;

        case 'W':
            errno = EOK;
            dir = ( uint32_t ) strtol ( optarg, NULL, 0 );

            if ( errno != EOK )
            {
                if ( errno == ERANGE )
                {
                    l_status = errno;
                    printf("Failed strtol %s and status is %d \n ", strerror ( errno ), l_status );
                    l_ret = false;
                }
            }
            else
            {
                dir_write(dir);

            }
            break;

        case 'w':
            errno = EOK;
            value = ( uint32_t ) strtol ( optarg, NULL, 0 );

            if ( errno != EOK )
            {
                if ( errno == ERANGE )
                {
                    l_status = errno;
                    printf("Failed strtol %s and status is %d \n ", strerror ( errno ), l_status );
                    l_ret = false;
                }
            }
            else
            {
                data_write(value);
            }

            break;

        case 'R':
            dir_read();

            break;

        case 'r':
            data_read();

            break;

        default:
            printf(" unknown option " );
            usage();
            l_ret = false;
            break;
        }
    }

    return l_ret;
}

