#include "UclALHwCbk.h"

void Ucl_PhyTransmitCallback(void)
{
	UclALHwCbk_ReceiveComplete(0);
}
