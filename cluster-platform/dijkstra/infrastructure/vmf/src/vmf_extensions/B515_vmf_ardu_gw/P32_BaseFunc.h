#ifndef _PN3030_BASE_FUNC_H_
#define _PN3030_BASE_FUNC_H_

#include "P32_TypeDef.h"
#include "P32_HardwareProfile.h"


//////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C" {
#endif
////////////////////////////////////////////////////////////////////////////////////////

#define SILAB_USB		0x0
#define CYPRESS_USB		0x1
#define DANASMIX_USB	0x2

#define SILAB_I2C_IF	0x0	/// if define then you can use Silab I2C Interface. 
#define SILAB_SPI_IF	0x1	/// if define then you can use Silab SPI Interface.
#define SILAB_HPI_IF	0x2	/// if define then you can use Silab HPI Interface.

#define CYPRESS_I2C_IF	0x3	/// if define then you can use Cypress I2C Interface. 
#define CYPRESS_SPI_IF	0x4	/// if define then you can use Cypress SPI Interface.
#define CYPRESS_HPI_IF	0x5	/// if define then you can use Cypress HPI Interface.

#define DANASMIX_I2C_IF	0x6	/// if define then you can use Cypress I2C Interface. 
#define DANASMIX_SPI_IF	0x7	/// if define then you can use Cypress SPI Interface.
#define DANASMIX_HPI_IF	0x8	/// if define then you can use Cypress HPI Interface.

#define _SPI_MODE

/********************************************/
/*	Device ID Definitions					*/
/********************************************/
typedef enum
{
	DEVID_IRIS0 = 0,
	DEVID_IRIS1 = 1,
	DEVID_INVALID = 0xFF
}PN_DEVICEID;

typedef enum
{
	PNS3030_WRADDR = 0x86,
	PNS3030_RDADDR = 0x87
}PNS3030_CHIPADDR;
////////////////////////////////////////////////////////////////////////////////////////
// Target Dependant Implementation                                                    //
// User must modify MCU and PN3030 Interface adapt to your MCU(CPU, DSP)              //
////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// USB COMMON Interface functions                   //
//////////////////////////////////////////////////////

PN_S32 PN3030_Byte_Read(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *data);
/*! 
\brief Write one register of PN3030 
\param chip_addr: PN3030 Chip Address
\param reg_addr : PN3030's register
\param *data    : the value to write
\return OK or FAIL result is returned
\sa Version 
*/
PN_S32 PN3030_Byte_Write(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 data);
/*! 
\brief Read registers of PN3030 
\param chip_addr: PN3030 Chip Address
\param reg_addr : PN3030's register
\param *data    : the read value
\param size     : the read size	
\return OK or FAIL result is returned
\sa Version 
*/
PN_S32 PN3030_Burst_Read(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *data, int size);
/*! 
\brief Burst Write registers of PN3030 
\param chip_addr: PN3030 Chip Address
\param reg_addr : PN3030's register
\param *data    : the write value
\param size     : the write size	
\return OK or FAIL result is returned
\sa Version 
*/
PN_S32 PN3030_Burst_Write(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *data, int size);
/*! 
\brief Write field of one register  
\param chip_addr: PN3030 Chip Address
\param reg_addr : PN3030's register
\param field    : PN3030 field position
\param *field_data: the field value to write
\return OK or FAIL result is returned
\sa Version 
*/
PN_S32 PN3030_Field_Write(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 field, PN_U8 field_data);
/*! 
\brief Write field of one register  
\param chip_addr: PN3030 Chip Address
\param reg_addr : PN3030's register
\param field    : PN3030 field position
\param *field_data: the field value to write
\return OK or FAIL result is returned
\sa Version 
*/
PN_S32 PN3030_Interrupt_Write(PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 field, PN_U8 field_data);
/*! 
\brief PN3030 Register Page select function  
\param data: register page
\return OK or FAIL result is returned
\sa Version
*/
PN_S32 PN3030_Reg_Page_Sel(PN_U8 pn_type, PN_U8 data);
/*! 
\brief System Time Delay Function (micro_sec) 
\param delay: delay time by microsecond
\return OK or FAIL result is returned
\sa Version
*/
void Delay_Us(PN_S32 delay);
/*! 
\brief System Time Delay Function (mili_sec) 
\param delay: delay time by millisecond
\return OK or FAIL result is returned
\sa Version
*/
void Delay_Ms(PN_S32 delay);

PN_U8 WriteOneRegisterDirect(PN_U8 hex_address, PN_U8 page, PN_U8 data);
PN_U8 ReadOneRegisterDirect(PN_U8 hex_address, PN_U8 page);
#ifdef __cplusplus
	}
#endif

#endif