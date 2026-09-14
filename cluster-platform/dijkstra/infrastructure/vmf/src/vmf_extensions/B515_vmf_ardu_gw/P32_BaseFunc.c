#include <string.h>
#include "P32_BaseFunc.h"
#include "P32_PNS3030RegDef.h"

//////////////////////////////////////////////////////
// USB Interface base function                      //
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
// PN3030EV COMMON Interface functions              //
//////////////////////////////////////////////////////

/* Read one register of PN3030EV via PN3022USB */
PN_S32 PN3030_Byte_Read(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *data)
{
#ifdef _SPI_MODE
    *data = SPI_ReadByte(chip_addr, reg_addr);
#else
    *data = I2C_ReadByte(chip_addr, reg_addr);
#endif
	return PN_FN_OK;
}
/* Write one register of PN3030EV via PN3022USB */
PN_S32 PN3030_Byte_Write(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 data)
{
#ifdef _SPI_MODE
    SPI_WriteByte(chip_addr, reg_addr, data);
#else
	I2C_WriteByte(chip_addr, reg_addr, data);
#endif
	return PN_FN_OK;
}
/* Read registers of PN3030EV via PN3022USB */
PN_S32 PN3030_Burst_Read(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *data, int size)
{
#ifdef _SPI_MODE
    SPI_ReadBlock(chip_addr, reg_addr, data, size);
#else
//	I2C_ReadBlock(chip_addr ,reg_addr ,data ,size);
#endif
	return PN_FN_OK;
}

/* Write one register of PN3030EV via PN3022USB */
PN_S32 PN3030_Burst_Write(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *data, int size)
{
#ifdef _SPI_MODE
#else
//	DANASMIX_I2C_Burst_Write(chip_addr,reg_addr, data, size);
#endif
	return PN_FN_OK;
}

PN_U8 ReadBurstRegisterDirect(PN_U8 hex_address, PN_U8 page, PN_U8 *dat, PN_U8 size)
{
    PN_U8 pRet = 0;

    PN3030_Reg_Page_Sel(PN3030E_ADDR, page);
    PN3030_Burst_Read(PN3030E_ADDR, hex_address, dat, size);

    return pRet;
}

/* Write one register's field of PN3030EV via PN3022USB */
PN_S32 PN3030_Field_Write(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 field, PN_U8 field_data)
{
    PN_U8 read_data;

#ifdef _SPI_MODE
    PN3030_Byte_Read(PN3030E_ADDR,reg_addr,&read_data);
    read_data = (read_data & (~field)) | (field_data);
    PN3030_Byte_Write(PN3030E_ADDR,reg_addr,read_data);
#else
    PN3030_Byte_Read(PN3030E_ADDR,reg_addr,&read_data);
    read_data = (read_data & (~field)) | (field_data);
    PN3030_Byte_Write(PN3030E_ADDR,reg_addr,read_data);
#endif

    return PN_FN_OK;
}


/* Write Interrupt register's field of PN3030EV via PN3022USB */
PN_S32 PN3030_Interrupt_Write(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 field, PN_U8 field_data)
{

    PN_U8 read_data;

    PN3030_Byte_Read(chip_addr,reg_addr,&read_data);

    if(field_data)
	read_data = read_data | field;
    else
        read_data = read_data & (~field);

    PN3030_Byte_Write(PN3030E_ADDR,reg_addr,read_data);

    return PN_FN_OK;
}

/* PN3030EV Register Page select function  */
PN_S32 PN3030_Reg_Page_Sel(PN_U8 pn_type, PN_U8 data)
{
    PN3030_Byte_Write(PN3030E_ADDR,TOP03_E,data);

    return PN_FN_OK;
}

void Delay_Us(PN_S32 delay)
{
    Delay10us(delay/10);
}

void Delay_Ms(PN_S32 delay)
{
    DelayMs(delay);
}



/* for test function */
PN_U8 WriteOneRegisterDirect(PN_U8 hex_address, PN_U8 page, PN_U8 data)
{
    PN_U8 pRet = 0;

    PN3030_Reg_Page_Sel(PN3030E_ADDR, page);
    PN3030_Byte_Write(PN3030E_ADDR, hex_address, data);

    return pRet;
}

/* for test function */
PN_U8 ReadOneRegisterDirect(PN_U8 hex_address, PN_U8 page)
{
    PN_U8 pRet = 0;

    PN3030_Reg_Page_Sel(PN3030E_ADDR, page);
    PN3030_Byte_Read(PN3030E_ADDR, hex_address, &pRet);

    return pRet;
}
