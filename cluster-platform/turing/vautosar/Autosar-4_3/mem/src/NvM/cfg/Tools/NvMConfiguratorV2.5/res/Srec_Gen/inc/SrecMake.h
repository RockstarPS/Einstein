#ifndef SREC_MAKE_H
#define SREC_MAKE_H

#define EEPROM_OFSET     0x14000000
#define SREC_DATA_BYTES_PER_LINE  16

// Fls Configuration

#define NO_OF_PARTITION       2
#define SECTOR_SIZE           16384
#define SECTOR_FOOTER_LENGTH  16
uint32 Partition_StartAddress[NO_OF_PARTITION] = {0,32768};

// Small Sector Configs
#define NO_OF_FIXED_PARTITION    1
uint32 Fixed_Start_Address[NO_OF_FIXED_PARTITION] = {0x18000};
uint32 Fixed_End_Address[NO_OF_FIXED_PARTITION] = {0x20000};
#define SMALL_SEC_START_ADDR                    0x14018000UL
#define SMALL_SEC_END_ADDR                      0x14020000UL


extern void srec_main(uint8 nthVariant);

#endif
