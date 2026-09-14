#include "windows.h"
#include "nw_vmf.h"


unsigned8 	SPI_ReadByte(unsigned8 chip_addr, unsigned8 reg_addr);
void 		SPI_ReadBlock(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *data, int size);
void 		SPI_WriteByte(unsigned8 chip_addr, unsigned8 reg_addr, unsigned8 data);

