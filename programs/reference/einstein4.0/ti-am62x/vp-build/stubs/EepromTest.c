#include "Stubs.h"
#include "Os.h"
#include "Spi.h"
#include "NvM.h"
#include "MemIf.h"
#include "Ea.h"
#include "EepDrv.h"



static uint8 SrcEepBuffer[64];
static uint8 DestEepBuffer[64];




void EepDrv_WriteBufferFill(void)
{
    SrcEepBuffer[0] = 0x02;
    SrcEepBuffer[1] = 0x00;
    SrcEepBuffer[2] = 0x00;
    SrcEepBuffer[3] = 0x33;
    SrcEepBuffer[4] = 0x85;
}

void EepDrv_ReadBufferFill(void)
{
    SrcEepBuffer[0] = 0x03;
    SrcEepBuffer[1] = 0x00;
    SrcEepBuffer[2] = 0x00;
    SrcEepBuffer[3] = 0xFF;
    SrcEepBuffer[4] = 0xFF;
}

void EepDrv_CommandBufferFill(void)
{
    SrcEepBuffer[0] = 0x06;
}

static volatile Std_ReturnType RetVal;
static volatile uint8 EepTestEnable;


void EepDrv_Test(void)
{

    if(EepTestEnable == 1)
    {
        EepTestEnable = 0;
        EepDrv_CommandBufferFill();
        if ((uint8)E_OK == Spi_SetupEB(0, SrcEepBuffer,NULL, 1))
        {
            RetVal = Spi_AsyncTransmit(0);
        }
    }
    else if(EepTestEnable == 2)
    {
        EepTestEnable = 0;
        EepDrv_WriteBufferFill();
        if ((uint8)E_OK == Spi_SetupEB(0, SrcEepBuffer,NULL, 5))
        {
            RetVal = Spi_AsyncTransmit(0);
        }
    }
    else if(EepTestEnable == 3)
    {
        EepTestEnable = 0;
        EepDrv_ReadBufferFill();
        if ((uint8)E_OK == Spi_SetupEB(0, SrcEepBuffer,DestEepBuffer, 5))
        {
            RetVal = Spi_AsyncTransmit(0);
        }
    }
}
static volatile uint16 TestBlockId = 2;
static volatile uint8 NvMTestVariable;
void NvM_Test(void)
{
    if(NvMTestVariable == 1)
    {
        NvM_WriteBlock(TestBlockId, NULL);
        NvMTestVariable = 0;
    }
    if(NvMTestVariable == 2)
    {
        NvM_ReadBlock(TestBlockId, NULL);
        NvMTestVariable = 0;
    }
}

