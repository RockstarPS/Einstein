/*============================================================================
 * **
 * ** Copyright <2021> Visteon Corporation.
 * **
 * ** These materials and the intellectual property rights associated therewith
 * ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 * ** the Materials are reserved by Visteon Corporation. Nothing contained in
 * ** these Materials shall grant or be deemed to grant to you or anyone else, by
 * ** implication, estoppel or otherwise, any rights in these Materials.
 * **
 * **==========================================================================*/

//#include "meet_application_types.h"
#include <sys/iofunc.h>
//#include <sys/dispatch.h>
//#include <openssl/sha.h>

#ifndef ETHERNET_REGISTER_READ_WRITE_H_
#define ETHERNET_REGISTER_READ_WRITE_H_


typedef struct
{
	uint32_t reg_access_DID_U32;
	uint32_t reg_value_U32;
}ts_reg_info;

class ENETregisterClass
{
    public:

   ENETregisterClass (  );
   ~ENETregisterClass()
   {

   }


uint8_t write_register(uint8_t ctrlOption, uint8_t MSBregisterDID,uint8_t  LSBregisterDID, uint8_t MSBregistervalue, uint8_t LSBregistervalue,uint8_t MSBmask,uint8_t LSBmask );
uint8_t read_register(uint8_t ctrlOption, uint8_t MSBregisterDID,uint8_t  LSBregisterDID, std::vector<uint32_t> &l_outdata);
};
#endif
