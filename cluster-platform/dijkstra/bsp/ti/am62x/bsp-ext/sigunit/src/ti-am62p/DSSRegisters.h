/*============================================================================
 **  \file DSSRegisters.h
 **
 **  \brief Defines for DSS (Display Subsystem) Registers
 **
 **  This file provides the base addresses and offsets for DSS registers
 **  Component Name: Signature Unit
 **  Date: SEP 10 2024
 **  Author: DAMUDHAR
 **
 **==========================================================================*/

#ifndef DSS_REGISTERS_H_
#define DSS_REGISTERS_H_

// Base addresses for DSS0
#define DSS0_VIDL1_BASE_ADDR 0x30202000
#define DSS0_VID_BASE_ADDR   0x30206000
#define DSS0_VP1_BASE_ADDR   0x3020A000
#define DSS0_VP2_BASE_ADDR   0x3020B000

// Base addresses for DSS1
#define DSS1_VIDL1_BASE_ADDR 0x30222000
#define DSS1_VID_BASE_ADDR   0x30226000
#define DSS1_VP1_BASE_ADDR   0x3022A000
#define DSS1_VP2_BASE_ADDR   0x3022B000

#define DSS_UNIT_0_VP1_REG_BASE    DSS0_VP1_BASE_ADDR + 0x70 //0x70h - 0x110h
#define DSS_UNIT_1_VP2_REG_BASE    DSS0_VP2_BASE_ADDR + 0x70 //0x70h - 0x110h
#define DSS_UNIT_2_VP1_REG_BASE    DSS1_VP1_BASE_ADDR + 0x70 //0x70h - 0x110h
#define DSS_UNIT_3_VP2_REG_BASE    DSS1_VP2_BASE_ADDR + 0x70 //0x70h - 0x110h
#define DSS_UNIT_REG_SIZE          0xA0 // 0xA0

// Register Offsets and Names for DSS0_VIDL1
#define DSS0_VIDL1_DSS_SAFETY_ATTRIBUTES_OFFSET 0x2A0           //Indicates which frames to be skipped
#define DSS0_VIDL1_DSS_SAFETY_CAPT_SIGNATURE_OFFSET 0x2A4       //Register captures the signature from the MISR of safety sub-region
#define DSS0_VIDL1_DSS_SAFETY_POSITION_OFFSET 0x2A8             //Y and X position of safety sub-region
#define DSS0_VIDL1_DSS_SAFETY_REF_SIGNATURE_OFFSET 0x2AC        //Register configures the reference signature of safety sub-region
#define DSS0_VIDL1_DSS_SAFETY_SIZE_OFFSET 0x2B0                 //Height and Width of safety sub-region
#define DSS0_VIDL1_DSS_SAFETY_LFSR_SEED_OFFSET 0x2B4            //Register configures the seed [initial value] of MISR.

// Register Offsets and Names for DSS0_VID
#define DSS0_VID_DSS_SAFETY_ATTRIBUTES_OFFSET 0x2A0             //Indicates which frames to be skipped
#define DSS0_VID_DSS_SAFETY_CAPT_SIGNATURE_OFFSET 0x2A4         //Register captures the signature from the MISR of safety sub-region
#define DSS0_VID_DSS_SAFETY_POSITION_OFFSET 0x2A8               //Y and X position of safety sub-region
#define DSS0_VID_DSS_SAFETY_REF_SIGNATURE_OFFSET 0x2AC          //Register configures the reference signature of safety sub-region
#define DSS0_VID_DSS_SAFETY_SIZE_OFFSET 0x2B0                   //Height and Width of safety sub-region
#define DSS0_VID_DSS_SAFETY_LFSR_SEED_OFFSET 0x2B4              //Register configures the seed [initial value] of MISR.

// DSS0 VP1 Window 0 Registers
#define DSS0_VP1_DSS_SAFETY_ATTRIBUTES_0_OFFSET 0x0             //Indicates, frames to be skipped for window 0
#define DSS0_VP1_DSS_SAFETY_CAPT_SIGNATURE_0_OFFSET 0x20        //Register Captures for window 0
#define DSS0_VP1_DSS_SAFETY_POSITION_0_OFFSET 0x40              //y and x position for window 0
#define DSS0_VP1_DSS_SAFETY_REF_SIGNATURE_0_OFFSET 0x60         //Reference sigunitur for window 0
#define DSS0_VP1_DSS_SAFETY_SIZE_0_OFFSET 0x80                  //Height and Width for window 0

// DSS0 VP1 Window 1 Registers
#define DSS0_VP1_DSS_SAFETY_ATTRIBUTES_1_OFFSET 0x04            //Indicates, frames to be skipped for window 1
#define DSS0_VP1_DSS_SAFETY_CAPT_SIGNATURE_1_OFFSET 0x24        //Register Captures for window 1
#define DSS0_VP1_DSS_SAFETY_POSITION_1_OFFSET 0x44              //y and x position for window 1
#define DSS0_VP1_DSS_SAFETY_REF_SIGNATURE_1_OFFSET 0x64         //Reference sigunitur for window 1
#define DSS0_VP1_DSS_SAFETY_SIZE_1_OFFSET 0x84                  //Height and Width for window 1

// DSS0 VP1 Window 2 Registers
#define DSS0_VP1_DSS_SAFETY_ATTRIBUTES_2_OFFSET 0x08            //Indicates, frames to be skipped for window 2
#define DSS0_VP1_DSS_SAFETY_CAPT_SIGNATURE_2_OFFSET 0x28        //Register Captures for window 2
#define DSS0_VP1_DSS_SAFETY_POSITION_2_OFFSET 0x48              //y and x position for window 2
#define DSS0_VP1_DSS_SAFETY_REF_SIGNATURE_2_OFFSET 0x68         //Reference sigunitur for window 2
#define DSS0_VP1_DSS_SAFETY_SIZE_2_OFFSET 0x88                  //Height and Width for window 2

// DSS0 VP1 Window 3 Registers
#define DSS0_VP1_DSS_SAFETY_ATTRIBUTES_3_OFFSET 0x0C            //Indicates, frames to be skipped for window 3
#define DSS0_VP1_DSS_SAFETY_CAPT_SIGNATURE_3_OFFSET 0x2C        //Register Captures for window 3
#define DSS0_VP1_DSS_SAFETY_POSITION_3_OFFSET 0x4C              //y and x position for window 3 
#define DSS0_VP1_DSS_SAFETY_REF_SIGNATURE_3_OFFSET 0x6C         //Reference sigunitur for window 3
#define DSS0_VP1_DSS_SAFETY_SIZE_3_OFFSET 0x8C                  //Height and Width for window 3

#define DSS0_VP1_DSS_SAFETY_LFSR_SEED_OFFSET 0xA0               //Register configures the seed [initial value] of MISR

// DSS0 VP2 Window 4 Registers 
#define DSS0_VP2_DSS_SAFETY_ATTRIBUTES_0_OFFSET 0x0             //Indicates, frames to be skipped for window 4
#define DSS0_VP2_DSS_SAFETY_CAPT_SIGNATURE_0_OFFSET 0x20        //Register Captures for window 4
#define DSS0_VP2_DSS_SAFETY_POSITION_0_OFFSET 0x40              //y and x position for window 4 
#define DSS0_VP2_DSS_SAFETY_REF_SIGNATURE_0_OFFSET 0x60         //Reference sigunitur for window 4
#define DSS0_VP2_DSS_SAFETY_SIZE_0_OFFSET 0x80                  //Height and Width for window 4

// DSS0 VP2 Window 5 Registers
#define DSS0_VP2_DSS_SAFETY_ATTRIBUTES_1_OFFSET 0x04            //Indicates, frames to be skipped for window 5
#define DSS0_VP2_DSS_SAFETY_CAPT_SIGNATURE_1_OFFSET 0x24        //Register Captures for window 5
#define DSS0_VP2_DSS_SAFETY_POSITION_1_OFFSET 0x44              //y and x position for window 5
#define DSS0_VP2_DSS_SAFETY_REF_SIGNATURE_1_OFFSET 0x64         //Reference sigunitur for window 5
#define DSS0_VP2_DSS_SAFETY_SIZE_1_OFFSET 0x84                  //Height and Width for window 5

// DSS0 VP2 Window 6 Registers
#define DSS0_VP2_DSS_SAFETY_ATTRIBUTES_2_OFFSET 0x08            //Indicates, frames to be skipped for window 6
#define DSS0_VP2_DSS_SAFETY_CAPT_SIGNATURE_2_OFFSET 0x28        //Register Captures for window 6
#define DSS0_VP2_DSS_SAFETY_POSITION_2_OFFSET 0x48              //y and x position for window 6
#define DSS0_VP2_DSS_SAFETY_REF_SIGNATURE_2_OFFSET 0x68         //Reference sigunitur for window 6
#define DSS0_VP2_DSS_SAFETY_SIZE_2_OFFSET 0x88                  //Height and Width for window 6

// DSS0 VP2 Window 7 Registers
#define DSS0_VP2_DSS_SAFETY_ATTRIBUTES_3_OFFSET 0x0C            //Indicates, frames to be skipped for window 7
#define DSS0_VP2_DSS_SAFETY_CAPT_SIGNATURE_3_OFFSET 0x2C        //Register Captures for window 7
#define DSS0_VP2_DSS_SAFETY_POSITION_3_OFFSET 0x4C              //y and x position for window 7
#define DSS0_VP2_DSS_SAFETY_REF_SIGNATURE_3_OFFSET 0x6C         //Reference sigunitur for window 7
#define DSS0_VP2_DSS_SAFETY_SIZE_3_OFFSET 0x8C                  //Height and Width for window 7

#define DSS0_VP2_DSS_SAFETY_LFSR_SEED_OFFSET 0xA0               //Register configures the seed [initial value] of MISR.

// Register Offsets and Names for DSS1_VIDL1
#define DSS1_VIDL1_DSS_SAFETY_ATTRIBUTES_OFFSET 0x2A0           //Indicates which frames to be skipped
#define DSS1_VIDL1_DSS_SAFETY_CAPT_SIGNATURE_OFFSET 0x2A4       //Register captures the signature from the MISR of safety sub-region
#define DSS1_VIDL1_DSS_SAFETY_POSITION_OFFSET 0x2A8             //Y and X position of safety sub-region
#define DSS1_VIDL1_DSS_SAFETY_REF_SIGNATURE_OFFSET 0x2AC        //Register configures the reference signature of safety sub-region
#define DSS1_VIDL1_DSS_SAFETY_SIZE_OFFSET 0x2B0                 //Height and Width of safety sub-region
#define DSS1_VIDL1_DSS_SAFETY_LFSR_SEED_OFFSET 0x2B4            //Register configures the seed [initial value] of MISR

// Register Offsets and Names for DSS1_VID
#define DSS1_VID_DSS_SAFETY_ATTRIBUTES_OFFSET 0x2A0             //Indicates which frames to be skipped
#define DSS1_VID_DSS_SAFETY_CAPT_SIGNATURE_OFFSET 0x2A4         //Register captures the signature from the MISR of safety sub-region
#define DSS1_VID_DSS_SAFETY_POSITION_OFFSET 0x2A8               //Y and X position of safety sub-region
#define DSS1_VID_DSS_SAFETY_REF_SIGNATURE_OFFSET 0x2AC          //Register configures the reference signature of safety sub-region
#define DSS1_VID_DSS_SAFETY_SIZE_OFFSET 0x2B0                   //Height and Width of safety sub-region
#define DSS1_VID_DSS_SAFETY_LFSR_SEED_OFFSET 0x2B4              //Register configures the seed [initial value] of MISR

// DSS1_VP1 Window 0 Register
#define DSS1_VP1_DSS_SAFETY_ATTRIBUTES_0_OFFSET 0x0             //Indicates, frames to be skipped for window 0
#define DSS1_VP1_DSS_SAFETY_CAPT_SIGNATURE_0_OFFSET 0x20        //Register Captures for window 0
#define DSS1_VP1_DSS_SAFETY_POSITION_0_OFFSET 0x40              //y and x position for window 0
#define DSS1_VP1_DSS_SAFETY_REF_SIGNATURE_0_OFFSET 0x60         //Reference sigunitur for window 0
#define DSS1_VP1_DSS_SAFETY_SIZE_0_OFFSET 0x80                  //Height and Width for window 0

// DSS1_VP1 Window 1 Register
#define DSS1_VP1_DSS_SAFETY_ATTRIBUTES_1_OFFSET 0x04            //Indicates, frames to be skipped for window 1
#define DSS1_VP1_DSS_SAFETY_CAPT_SIGNATURE_1_OFFSET 0x24        //Register Captures for window 1
#define DSS1_VP1_DSS_SAFETY_POSITION_1_OFFSET 0x44              //y and x position for window 1
#define DSS1_VP1_DSS_SAFETY_REF_SIGNATURE_1_OFFSET 0x64         //Reference sigunitur for window 1
#define DSS1_VP1_DSS_SAFETY_SIZE_1_OFFSET 0x84                  //Height and Width for window 1

// DSS1_VP1 Window 2 Register
#define DSS1_VP1_DSS_SAFETY_ATTRIBUTES_2_OFFSET 0x08            //Indicates, frames to be skipped for window 2
#define DSS1_VP1_DSS_SAFETY_CAPT_SIGNATURE_2_OFFSET 0x28        //Register Captures for window 2
#define DSS1_VP1_DSS_SAFETY_POSITION_2_OFFSET 0x48              //y and x position for window 2
#define DSS1_VP1_DSS_SAFETY_REF_SIGNATURE_2_OFFSET 0x68         //Reference sigunitur for window 2
#define DSS1_VP1_DSS_SAFETY_SIZE_2_OFFSET 0x88                  //Height and Width for window 2

// DSS1_VP1 Window 3 Register
#define DSS1_VP1_DSS_SAFETY_ATTRIBUTES_3_OFFSET 0x0C            //Indicates, frames to be skipped for window 3
#define DSS1_VP1_DSS_SAFETY_CAPT_SIGNATURE_3_OFFSET 0x2C        //Register Captures for window 3
#define DSS1_VP1_DSS_SAFETY_POSITION_3_OFFSET 0x4C              //y and x position for window 3
#define DSS1_VP1_DSS_SAFETY_REF_SIGNATURE_3_OFFSET 0x6C         //Reference sigunitur for window 3
#define DSS1_VP1_DSS_SAFETY_SIZE_3_OFFSET 0x8C                  //Height and Width for window 3

#define DSS1_VP1_DSS_SAFETY_LFSR_SEED_OFFSET 0xA0               //Register configures the seed [initial value] of MISR		

// DSS1_VP2 Window 4 Register
#define DSS1_VP2_DSS_SAFETY_ATTRIBUTES_0_OFFSET 0x0             //Indicates, frames to be skipped for window 4
#define DSS1_VP2_DSS_SAFETY_CAPT_SIGNATURE_0_OFFSET 0x20        //Register Captures for window 4
#define DSS1_VP2_DSS_SAFETY_POSITION_0_OFFSET 0x40              //y and x position for window 4
#define DSS1_VP2_DSS_SAFETY_REF_SIGNATURE_0_OFFSET 0x60         //Reference sigunitur for window 4
#define DSS1_VP2_DSS_SAFETY_SIZE_0_OFFSET 0x80                  //Height and Width for window 4

// DSS1_VP2 Window 5 Register
#define DSS1_VP2_DSS_SAFETY_ATTRIBUTES_1_OFFSET 0x04            //Indicates, frames to be skipped for window 5
#define DSS1_VP2_DSS_SAFETY_CAPT_SIGNATURE_1_OFFSET 0x24        //Register Captures for window 5
#define DSS1_VP2_DSS_SAFETY_POSITION_1_OFFSET 0x44              //y and x position for window 5
#define DSS1_VP2_DSS_SAFETY_REF_SIGNATURE_1_OFFSET 0x64         //Reference sigunitur for window 5
#define DSS1_VP2_DSS_SAFETY_SIZE_1_OFFSET 0x84                  //Height and Width for window 5

// DSS1_VP2 Window 6 Register
#define DSS1_VP2_DSS_SAFETY_ATTRIBUTES_2_OFFSET 0x08            //Indicates, frames to be skipped for window 6
#define DSS1_VP2_DSS_SAFETY_CAPT_SIGNATURE_2_OFFSET 0x28        //Register Captures for window 6
#define DSS1_VP2_DSS_SAFETY_POSITION_2_OFFSET 0x48              //y and x position for window 6
#define DSS1_VP2_DSS_SAFETY_REF_SIGNATURE_2_OFFSET 0x68         //Reference sigunitur for window 6
#define DSS1_VP2_DSS_SAFETY_SIZE_2_OFFSET 0x88                  //Height and Width for window 6

// DSS1_VP2 Window 7 Register
#define DSS1_VP2_DSS_SAFETY_ATTRIBUTES_3_OFFSET 0x0C            //Indicates, frames to be skipped for window 7
#define DSS1_VP2_DSS_SAFETY_CAPT_SIGNATURE_3_OFFSET 0x2C        //Register Captures for window 7
#define DSS1_VP2_DSS_SAFETY_POSITION_3_OFFSET 0x4C              //y and x position for window 7
#define DSS1_VP2_DSS_SAFETY_REF_SIGNATURE_3_OFFSET 0x6C         //Reference sigunitur for window 7
#define DSS1_VP2_DSS_SAFETY_SIZE_3_OFFSET 0x8C                  //Height and Width for window 7

#define DSS1_VP2_DSS_SAFETY_LFSR_SEED_OFFSET 0xA0               //Register configures the seed [initial value] of MISR.

// common window register

#define DSS_SAFETY_ATTRIBUTES_0_OFFSET 0x0                      //Indicates, frames to be skipped for window 0
#define DSS_SAFETY_CAPT_SIGNATURE_0_OFFSET 0x20                 //Register Captures for window 0
#define DSS_SAFETY_POSITION_0_OFFSET 0x40                       //y and x position for window 0
#define DSS_SAFETY_REF_SIGNATURE_0_OFFSET 0x60                  //Reference sigunitur for window 0
#define DSS_SAFETY_SIZE_0_OFFSET 0x80                           //Height and Width for window 0


#define DSS_SAFETY_ATTRIBUTES_1_OFFSET 0x04                     //Indicates, frames to be skipped for window 1
#define DSS_SAFETY_CAPT_SIGNATURE_1_OFFSET 0x24                 //Register Captures for window 1
#define DSS_SAFETY_POSITION_1_OFFSET 0x44                       //y and x position for window 1
#define DSS_SAFETY_REF_SIGNATURE_1_OFFSET 0x64                  //Reference sigunitur for window 1
#define DSS_SAFETY_SIZE_1_OFFSET 0x84                           //Height and Width for window 1


#define DSS_SAFETY_ATTRIBUTES_2_OFFSET 0x08                     //Indicates, frames to be skipped for window 2
#define DSS_SAFETY_CAPT_SIGNATURE_2_OFFSET 0x28                 //Register Captures for window 2
#define DSS_SAFETY_POSITION_2_OFFSET 0x48                       //y and x position for window 2
#define DSS_SAFETY_REF_SIGNATURE_2_OFFSET 0x68                  //Reference sigunitur for window 2
#define DSS_SAFETY_SIZE_2_OFFSET 0x88                           //Height and Width for window 2


#define DSS_SAFETY_ATTRIBUTES_3_OFFSET 0x0C                     //Indicates, frames to be skipped for window 3
#define DSS_SAFETY_CAPT_SIGNATURE_3_OFFSET 0x2C                 //Register Captures for window 3
#define DSS_SAFETY_POSITION_3_OFFSET 0x4C                       //y and x position for window 3
#define DSS_SAFETY_REF_SIGNATURE_3_OFFSET 0x6C                  //Reference sigunitur for window 3
#define DSS_SAFETY_SIZE_3_OFFSET 0x8C                           //Height and Width for window 3

#define DSS_SAFETY_LFSR_SEED_OFFSET 0xA0                        //Register configures the seed [initial value] of MISR.

#endif