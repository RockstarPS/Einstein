#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_layout.h"

extern void HmiMainShowComputer(UINT32 index);
extern UINT32 GddCddTick(void);

extern UINT32 l_fuel_dte_val;
extern UINT32 l_fuel_afe_val;

// static configuration data
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static SINT32 fuelGradientDirection;
static SINT32 fuelPercentFill;
static UINT32 fuelDteValueOld;
static UINT32 startTick;

// interface functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ScrFuelInit(void)
{
    fuelGradientDirection = 1;
    fuelPercentFill = 100;
    fuelDteValueOld = l_fuel_dte_val - (UINT32)1;
}

void ScrFuelRefresh(void)
{
    GFX_MGR02_VCLIP_DATA fuelGradientClipping;
    HMI_CHAR fuelDteValue[4];
    HMI_CHAR fuelAfeValue[5];
    UINT32 dteVal;
    UINT32 elapsedTicks = GddCddTick() - startTick;

    UINT32 afeIntVal = (UINT32)0;
    UINT32 afeDecVal = (UINT32)0;

    if (fuelDteValueOld != l_fuel_dte_val)
    {
        // Do conversion here
        dteVal = l_fuel_dte_val;
        afeIntVal = l_fuel_afe_val / (UINT32)10;
        afeDecVal = l_fuel_afe_val % (UINT32)10;

        (void)HMI_SPRINTF(fuelDteValue, (UINT32)4, HMI_TEXT((unsigned char*)"%u"), dteVal);
        (void)HMI_SPRINTF(fuelAfeValue, (UINT32)5, HMI_TEXT((unsigned char*)"%02u.%u"), afeIntVal, afeDecVal);

        fuelDteValueOld = l_fuel_dte_val;
    }

    if (fuelGradientDirection == 0)
    {
        fuelPercentFill += elapsedTicks;

        if (fuelPercentFill >= 100)
        {
            fuelPercentFill = 100;
            fuelGradientDirection = 1;
        }
        else
        {
            fuelGradientDirection = 0;
        }
    }
    else
    {
        fuelPercentFill -= elapsedTicks;

        if (fuelPercentFill <= 16)
        {
            fuelPercentFill = 16;
            fuelGradientDirection = 0;
        }
        else
        {
            fuelGradientDirection = 1;
        }
    }

    startTick = GddCddTick();

    fuelGradientClipping.num_lines = ((UINT16)fuelPercentFill * (UINT16)156) / (UINT16)100;
    fuelGradientClipping.start_line = 156 - fuelGradientClipping.num_lines;
}
void ScrFuelShow(void)
{

    HmiMainShowComputer((UINT32)1);

    startTick = GddCddTick();
}

void ScrFuelHide(void)
{

}

