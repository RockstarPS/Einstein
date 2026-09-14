#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <devctl.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/slogcodes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/neutrino.h>
#include <CDisplay_Devctl.h>
#include <CDisplay_ThermalDev.h>

#define BRIGHTNESS "brightness"
#define THERMAL "thermal"
#define EEPROM "eeprom"
typedef struct
{
    uint16_t writeData;
    uint8_t power_opr;
    uint8_t state_opr;
    uint8_t thermal_opr;
} displayTest;

displayTest displayTestData;
void executeDisplayPower ( void );
void executeDisplayState();
void executeThermal ( void );
static bool getopt_chk ( char *const p_opt, const int32_t p_argc, char *const p_argv[] );
static int32_t Display_Test_ParseOptions ( int32_t argc, char *const argv[], displayTest *p_displayTestData );

/* @brief    usage
 *
 * This function displays its usage.
 */
void usage()
{
    printf ( "Display RM Test\n"
             "Usage: display_test [-b] [-t][-e][-w] \n"
             "-r] runcount [-g] delay\n"
             "where:\n"
             "    p - power        \n"
             "	 t - thermal           \n"
             "	 s - state            \n"
             "    w - write value "
           );
}

/* @brief   main function
 *
 * @return   0 on success
 *          -1 on error
 */
int main ( int argc, char *argv[] )
{
    if ( argc < 1 )
    {
        printf ( "Check usage and provide required arguments\n" );
        usage();
        return EXIT_FAILURE;
    }

    int exit_value = Display_Test_ParseOptions ( argc, argv, &displayTestData );

    if ( EXIT_SUCCESS == exit_value )
    {
        if ( ( displayTestData.power_opr != 0 ) && ( displayTestData.state_opr == 0 ) && ( displayTestData.thermal_opr == 0 ) )
        {
            executeDisplayPower();
        }
        else if ( ( displayTestData.power_opr == 0 ) && ( displayTestData.state_opr == 0 ) && ( displayTestData.thermal_opr != 0 ) )
        {
            executeThermal();
        }
        else if ( ( displayTestData.power_opr == 0 ) && ( displayTestData.state_opr != 0 ) && ( displayTestData.thermal_opr == 0 ) )
        {
            executeDisplayState();
        }
    }
    else
    {
        printf ( "test fail \n" );
    }

    return 0;
}

void executeDisplayPower ( void )
{
    int     fd;
    int status;
    display_power_buffer_type_ts l_power;
    memset ( &l_power.power_U8, 0, sizeof ( l_power.power_U8 ) );

    switch ( displayTestData.power_opr )
    {
    case 1:
        printf ( "executing set display power  test case\n" );

        /*=================Connect to the display power=== */
        fd = open ( "/dev/display/display0/power", O_RDWR );
        printf ( "display_test::errno=%d:\"%s\"\n", errno, strerror ( errno ) );

        if ( fd < 0 )
        {
            perror ( "display_test::/dev/display/display0/power \n" );
            exit ( EXIT_FAILURE );
        }

        l_power.power_U8 = displayTestData.writeData;
        status =  devctl ( fd, POWER_ID_VALUE_WRITE, &l_power, sizeof ( l_power ), NULL );
        printf ( "devctl_ret=%d:\"%s\"\n", status, strerror ( status ) );
        close ( fd );
        break;

    case 2:
        printf ( "executing set display power  test case\n" );
        /*=================Connect to the display power=== */
        fd = open ( "/dev/display/display0/power", O_RDWR );
        printf ( "display_test::errno=%d:\"%s\"\n", errno, strerror ( errno ) );

        if ( fd < 0 )
        {
            perror ( "display_test::/dev/display/display0/power \n" );
            exit ( EXIT_FAILURE );
        }

        display_power_buffer_type_ts l_power;
        memset ( &l_power.power_U8, 0, sizeof ( l_power.power_U8 ) );
        status =  devctl ( fd, POWER_ID_VALUE_READ, &l_power, sizeof ( l_power ), NULL );
        printf ( "devctl_ret=%d:\"%s\"\n", status, strerror ( status ) );
        printf ( "internal read value = %d\n", l_power.power_U8 );
        close ( fd );
        break;

    default:
        printf ( "incorrect parameter passed, check usage \n" );
        usage();
        break;
    }
}

void executeDisplayState ( void )
{
    printf ( "executing set display state  test case\n" );
    int     fd;
    int status;

    /*=================Connect to the display state=== */
    fd = open ( "/dev/display/display0/state", O_RDWR );
    printf ( "display_test::errno=%d:\"%s\"\n", errno, strerror ( errno ) );

    if ( fd < 0 )
    {
        perror ( "display_test::/dev/display/display0/state \n" );
        exit ( EXIT_FAILURE );
    }

    display_state_buffer_type_ts l_state;
    memset ( &l_state.state, 0, sizeof ( l_state.state ) );
    status =  devctl ( fd, STATE_ID_VALUE_READ, &l_state, sizeof ( l_state ), NULL );
    printf ( "devctl_ret=%d:\"%s\"\n", status, strerror ( status ) );
    printf ( "internal read value = %d\n", l_state.state );
    close ( fd );

}

void executeThermal ( void )
{
    int     fd = 0;;
    int status = EOK;

    switch ( displayTestData.thermal_opr )
    {
    case 1:
        fd = open ( "/dev/thermal/thermal0/temperature/value", O_RDONLY );

        if ( fd < 0 )
        {
            perror ( "display_test::/dev/thermal/thermal0/temperature/value \n" );
            exit ( EXIT_FAILURE );
        }

        thermal_temperature_buffer blThermalBuf;
        status =  devctl ( fd, THERMAL_TEMPERATURE_READ, &blThermalBuf, sizeof ( blThermalBuf ), NULL );
        printf ( "display_thermaltest::errno=%d:\"%s\"\n", errno, strerror ( errno ) );
        printf ( "display_thermaltest::temp read value = %d\n", blThermalBuf.temperature_value );
        break;

    case 2:
        fd = open ( "/dev/thermal/thermal0/temperature/type", O_RDONLY );

        if ( fd < 0 )
        {
            perror ( "display_test::/dev/thermal/thermal0/temperature/type \n" );
            exit ( EXIT_FAILURE );
        }

        thermal_type_buffer blThermalTypeBuf;
        status =  devctl ( fd, THERMAL_TYPE_READ, &blThermalTypeBuf, sizeof ( blThermalTypeBuf ), NULL );
        printf ( "display_thermaltest::errno=%d:\"%s\"\n", status, strerror ( errno ) );
        printf ( "display_thermaltest::temp read type = %s\n", blThermalTypeBuf.thermal_type );
        break;

    default:
        printf ( "incorrect parameter passed, check usage \n" );
        usage();
        break;
    }

    close ( fd );
}

static int32_t Display_Test_ParseOptions ( int32_t argc, char *const argv[], displayTest *p_displayTestData )
{
    int32_t status = 0;
    char l_opt;

    /* Scan the Command line options for the channel number, bus speed */
    /* and verbose option */
    if ( argc >= 1 )
    {
        while ( true == getopt_chk ( &l_opt, argc, argv ) )
        {
            switch ( l_opt )
            {
            case 'p':
                p_displayTestData->power_opr = strtoul ( optarg, NULL, 0 );
                break;

            case 't':
                p_displayTestData->thermal_opr = strtoul ( optarg, NULL, 0 );
                break;

            case 's':
                p_displayTestData->state_opr = strtoul ( optarg, NULL, 0 );
                break;

            case 'w':
                p_displayTestData->writeData =  strtoul ( optarg, NULL, 0 );
                break;

            case '?':
                printf ( "Unknown option \n" );
                break;

            default:
                usage();
                break;
            }

        }
    }
    else
    {
        printf ( "Incorrect options passed to driver, check usage \n" );
        usage();
        status = EXIT_FAILURE;
    }


    return status;
}

static bool getopt_chk ( char *const p_opt, const int32_t p_argc, char *const p_argv[] )
{
    bool l_ret_val = false;
    int32_t getopt_ret = -1;
    getopt_ret = getopt ( p_argc, p_argv, "p:s:t:w:r:" );

    if ( getopt_ret < 0 )
    {
        l_ret_val = false;
        *p_opt = ( char ) 0;
    }
    else
    {
        l_ret_val = true;
        *p_opt = ( char ) getopt_ret;
    }

    return ( l_ret_val );
}
