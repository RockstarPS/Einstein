/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2016. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  Crc.c                                                *
*  Module Short Name :  Crc                                                  *
*  Description       :  This file contains implementations of the Cyclic     *
*                       Redundancy Check                                     *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef CRC_C
#define CRC_C

/*Version details of CRC Source file*/
# define CRC_SW_MAJOR_VERSION_SOURCE              (1u)
# define CRC_SW_MINOR_VERSION_SOURCE              (0u)
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Crc.h"
 
/* SWS_Crc_00005 Version check */
#if((CRC_SW_MAJOR_VERSION_SOURCE != CRC_SW_MAJOR_VERSION ) \
    || (CRC_SW_MINOR_VERSION_SOURCE != CRC_SW_MINOR_VERSION ))
# error "Version numbers of Crc.c and Crc.h are inconsistent!"
#endif

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*MISRA RULE 2.5 VIOLATION: Macro is used to indicate the start of declaring constants section ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
#define CRCLIB_CONST_SEC_START
#include "Crc_MemMap.h"
/* CRC8 */
#define CRC_FINAL_XOR_CRC8          (0xFFU)
#define CRC_FINAL_XOR_CRC32         (0xFFFFFFFFuL)
#define CRC_POLYNOMIAL_8            (0x1Du)
#define CRC_POLYNOMIAL_8H2F         (0x2Fu)
#define CRC_RUNTIME_POLYNOMIAL_8      (0x80u)
/* These value shall be used as start value when CRC is calculated */
#define CRC_INITIAL_VALUE8          (0xFFU)
#define CRC_INITIAL_VALUE16         (0xFFFFU)
#define CRC_POLYNOMIAL_16           (0x1021u)
#define CRC_RUNTIME_POLYNOMIAL_16      (0x8000u)
#define CRC_U32_DATAPTRADDR_VALUE    0xFFFFFFFFu
#define CRC_UINT8_VALUE              0xFFU
#define CRC_BYTELENGTH_U             8U

/* CRC32 polynomial */
#define CRC_INITIAL_VALUE32         (0xFFFFFFFFuL)
#define CRC_POLYNOMIAL_32           (0x04C11DB7uL)
#define CRC_POLYNOMIAL_32_REFLECT   (0xEDB88320uL)


/* CRC32P4 polynomial */

#define CRC_POLYNOMIAL_32P4         (0xF4ACFB13uL)
#define CRC_POLYNOMIAL_32P4_REFLECT (0xC8DF352FuL) 


/* CRC64 polynomial */
#define CRC_INITIAL_VALUE64         (0xFFFFFFFFFFFFFFFFuLL)
#define CRC_POLYNOMIAL_64           (0x42F0E1EBA9EA3693uLL)
#define CRC_POLYNOMIAL_64_REFLECT   (0xC96C5795D7870F42uLL)
#define CRC_FINAL_XOR_CRC64         (0xFFFFFFFFFFFFFFFFuLL)

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/


/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

#if (CRC_CALCULATE_CRC8_ENABLE == STD_ON)
	/*MISRA RULE 4.9 VIOLATION and MISRA RULE 8.9 VIOLATION: The declaration Crc_Table8bit will be used by other functions in future ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
    static const uint8 Crc_Table8bit[256] =
    {
        0x00, 0x1D, 0x3A, 0x27, 0x74, 0x69, 0x4E, 0x53, 0xE8, 0xF5, 0xD2, 0xCF, 0x9C, 0x81, 0xA6, 0xBB, 
        0xCD, 0xD0, 0xF7, 0xEA, 0xB9, 0xA4, 0x83, 0x9E, 0x25, 0x38, 0x1F, 0x02, 0x51, 0x4C, 0x6B, 0x76, 
        0x87, 0x9A, 0xBD, 0xA0, 0xF3, 0xEE, 0xC9, 0xD4, 0x6F, 0x72, 0x55, 0x48, 0x1B, 0x06, 0x21, 0x3C, 
        0x4A, 0x57, 0x70, 0x6D, 0x3E, 0x23, 0x04, 0x19, 0xA2, 0xBF, 0x98, 0x85, 0xD6, 0xCB, 0xEC, 0xF1, 
        0x13, 0x0E, 0x29, 0x34, 0x67, 0x7A, 0x5D, 0x40, 0xFB, 0xE6, 0xC1, 0xDC, 0x8F, 0x92, 0xB5, 0xA8, 
        0xDE, 0xC3, 0xE4, 0xF9, 0xAA, 0xB7, 0x90, 0x8D, 0x36, 0x2B, 0x0C, 0x11, 0x42, 0x5F, 0x78, 0x65, 
        0x94, 0x89, 0xAE, 0xB3, 0xE0, 0xFD, 0xDA, 0xC7, 0x7C, 0x61, 0x46, 0x5B, 0x08, 0x15, 0x32, 0x2F, 
        0x59, 0x44, 0x63, 0x7E, 0x2D, 0x30, 0x17, 0x0A, 0xB1, 0xAC, 0x8B, 0x96, 0xC5, 0xD8, 0xFF, 0xE2, 
        0x26, 0x3B, 0x1C, 0x01, 0x52, 0x4F, 0x68, 0x75, 0xCE, 0xD3, 0xF4, 0xE9, 0xBA, 0xA7, 0x80, 0x9D, 
        0xEB, 0xF6, 0xD1, 0xCC, 0x9F, 0x82, 0xA5, 0xB8, 0x03, 0x1E, 0x39, 0x24, 0x77, 0x6A, 0x4D, 0x50, 
        0xA1, 0xBC, 0x9B, 0x86, 0xD5, 0xC8, 0xEF, 0xF2, 0x49, 0x54, 0x73, 0x6E, 0x3D, 0x20, 0x07, 0x1A, 
        0x6C, 0x71, 0x56, 0x4B, 0x18, 0x05, 0x22, 0x3F, 0x84, 0x99, 0xBE, 0xA3, 0xF0, 0xED, 0xCA, 0xD7, 
        0x35, 0x28, 0x0F, 0x12, 0x41, 0x5C, 0x7B, 0x66, 0xDD, 0xC0, 0xE7, 0xFA, 0xA9, 0xB4, 0x93, 0x8E, 
        0xF8, 0xE5, 0xC2, 0xDF, 0x8C, 0x91, 0xB6, 0xAB, 0x10, 0x0D, 0x2A, 0x37, 0x64, 0x79, 0x5E, 0x43, 
        0xB2, 0xAF, 0x88, 0x95, 0xC6, 0xDB, 0xFC, 0xE1, 0x5A, 0x47, 0x60, 0x7D, 0x2E, 0x33, 0x14, 0x09, 
        0x7F, 0x62, 0x45, 0x58, 0x0B, 0x16, 0x31, 0x2C, 0x97, 0x8A, 0xAD, 0xB0, 0xE3, 0xFE, 0xD9, 0xC4 
    };
#endif


#if (CRC_CALCULATE_CRC16_ENABLE == STD_ON)
	/*MISRA RULE 4.9 VIOLATION and MISRA RULE 8.9 VIOLATION: The declaration Crc_Table16bit will be used by other functions in future ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
    static const uint16 Crc_Table16bit[256] = 
    {
        0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7, 0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
        0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6, 0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
        0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485, 0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
        0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4, 0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
        0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823, 0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
        0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12, 0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
        0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41, 0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
        0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70, 0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
        0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F, 0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
        0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E, 0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
        0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D, 0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
        0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C, 0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
        0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB, 0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
        0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A, 0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
        0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9, 0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
        0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8, 0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
    };
#endif

#if (CRC_CALCULATE_CRC32_ENABLE == STD_ON)
	/*MISRA RULE 4.9 VIOLATION and MISRA RULE 8.9 VIOLATION: The declaration Crc_Table32bit will be used by other functions in future ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
    static const uint32 Crc_Table32bit[256] = 
    {
        0x00000000uL, 0x77073096uL, 0xEE0E612CuL, 0x990951BAuL,
        0x076DC419uL, 0x706AF48FuL, 0xE963A535uL, 0x9E6495A3uL,
        0x0EDB8832uL, 0x79DCB8A4uL, 0xE0D5E91EuL, 0x97D2D988uL,
        0x09B64C2BuL, 0x7EB17CBDuL, 0xE7B82D07uL, 0x90BF1D91uL,
        0x1DB71064uL, 0x6AB020F2uL, 0xF3B97148uL, 0x84BE41DEuL,
        0x1ADAD47DuL, 0x6DDDE4EBuL, 0xF4D4B551uL, 0x83D385C7uL,
        0x136C9856uL, 0x646BA8C0uL, 0xFD62F97AuL, 0x8A65C9ECuL,
        0x14015C4FuL, 0x63066CD9uL, 0xFA0F3D63uL, 0x8D080DF5uL,
        0x3B6E20C8uL, 0x4C69105EuL, 0xD56041E4uL, 0xA2677172uL,
        0x3C03E4D1uL, 0x4B04D447uL, 0xD20D85FDuL, 0xA50AB56BuL,
        0x35B5A8FAuL, 0x42B2986CuL, 0xDBBBC9D6uL, 0xACBCF940uL,
        0x32D86CE3uL, 0x45DF5C75uL, 0xDCD60DCFuL, 0xABD13D59uL,
        0x26D930ACuL, 0x51DE003AuL, 0xC8D75180uL, 0xBFD06116uL,
        0x21B4F4B5uL, 0x56B3C423uL, 0xCFBA9599uL, 0xB8BDA50FuL,
        0x2802B89EuL, 0x5F058808uL, 0xC60CD9B2uL, 0xB10BE924uL,
        0x2F6F7C87uL, 0x58684C11uL, 0xC1611DABuL, 0xB6662D3DuL,
        0x76DC4190uL, 0x01DB7106uL, 0x98D220BCuL, 0xEFD5102AuL,
        0x71B18589uL, 0x06B6B51FuL, 0x9FBFE4A5uL, 0xE8B8D433uL,
        0x7807C9A2uL, 0x0F00F934uL, 0x9609A88EuL, 0xE10E9818uL,
        0x7F6A0DBBuL, 0x086D3D2DuL, 0x91646C97uL, 0xE6635C01uL,
        0x6B6B51F4uL, 0x1C6C6162uL, 0x856530D8uL, 0xF262004EuL,
        0x6C0695EDuL, 0x1B01A57BuL, 0x8208F4C1uL, 0xF50FC457uL,
        0x65B0D9C6uL, 0x12B7E950uL, 0x8BBEB8EAuL, 0xFCB9887CuL,
        0x62DD1DDFuL, 0x15DA2D49uL, 0x8CD37CF3uL, 0xFBD44C65uL,
        0x4DB26158uL, 0x3AB551CEuL, 0xA3BC0074uL, 0xD4BB30E2uL,
        0x4ADFA541uL, 0x3DD895D7uL, 0xA4D1C46DuL, 0xD3D6F4FBuL,
        0x4369E96AuL, 0x346ED9FCuL, 0xAD678846uL, 0xDA60B8D0uL,
        0x44042D73uL, 0x33031DE5uL, 0xAA0A4C5FuL, 0xDD0D7CC9uL,
        0x5005713CuL, 0x270241AAuL, 0xBE0B1010uL, 0xC90C2086uL,
        0x5768B525uL, 0x206F85B3uL, 0xB966D409uL, 0xCE61E49FuL,
        0x5EDEF90EuL, 0x29D9C998uL, 0xB0D09822uL, 0xC7D7A8B4uL,
        0x59B33D17uL, 0x2EB40D81uL, 0xB7BD5C3BuL, 0xC0BA6CADuL,
        0xEDB88320uL, 0x9ABFB3B6uL, 0x03B6E20CuL, 0x74B1D29AuL,
        0xEAD54739uL, 0x9DD277AFuL, 0x04DB2615uL, 0x73DC1683uL,
        0xE3630B12uL, 0x94643B84uL, 0x0D6D6A3EuL, 0x7A6A5AA8uL,
        0xE40ECF0BuL, 0x9309FF9DuL, 0x0A00AE27uL, 0x7D079EB1uL,
        0xF00F9344uL, 0x8708A3D2uL, 0x1E01F268uL, 0x6906C2FEuL,
        0xF762575DuL, 0x806567CBuL, 0x196C3671uL, 0x6E6B06E7uL,
        0xFED41B76uL, 0x89D32BE0uL, 0x10DA7A5AuL, 0x67DD4ACCuL,
        0xF9B9DF6FuL, 0x8EBEEFF9uL, 0x17B7BE43uL, 0x60B08ED5uL,
        0xD6D6A3E8uL, 0xA1D1937EuL, 0x38D8C2C4uL, 0x4FDFF252uL,
        0xD1BB67F1uL, 0xA6BC5767uL, 0x3FB506DDuL, 0x48B2364BuL,
        0xD80D2BDAuL, 0xAF0A1B4CuL, 0x36034AF6uL, 0x41047A60uL,
        0xDF60EFC3uL, 0xA867DF55uL, 0x316E8EEFuL, 0x4669BE79uL,
        0xCB61B38CuL, 0xBC66831AuL, 0x256FD2A0uL, 0x5268E236uL,
        0xCC0C7795uL, 0xBB0B4703uL, 0x220216B9uL, 0x5505262FuL,
        0xC5BA3BBEuL, 0xB2BD0B28uL, 0x2BB45A92uL, 0x5CB36A04uL,
        0xC2D7FFA7uL, 0xB5D0CF31uL, 0x2CD99E8BuL, 0x5BDEAE1DuL,
        0x9B64C2B0uL, 0xEC63F226uL, 0x756AA39CuL, 0x026D930AuL,
        0x9C0906A9uL, 0xEB0E363FuL, 0x72076785uL, 0x05005713uL,
        0x95BF4A82uL, 0xE2B87A14uL, 0x7BB12BAEuL, 0x0CB61B38uL,
        0x92D28E9BuL, 0xE5D5BE0DuL, 0x7CDCEFB7uL, 0x0BDBDF21uL,
        0x86D3D2D4uL, 0xF1D4E242uL, 0x68DDB3F8uL, 0x1FDA836EuL,
        0x81BE16CDuL, 0xF6B9265BuL, 0x6FB077E1uL, 0x18B74777uL,
        0x88085AE6uL, 0xFF0F6A70uL, 0x66063BCAuL, 0x11010B5CuL,
        0x8F659EFFuL, 0xF862AE69uL, 0x616BFFD3uL, 0x166CCF45uL,
        0xA00AE278uL, 0xD70DD2EEuL, 0x4E048354uL, 0x3903B3C2uL,
        0xA7672661uL, 0xD06016F7uL, 0x4969474DuL, 0x3E6E77DBuL,
        0xAED16A4AuL, 0xD9D65ADCuL, 0x40DF0B66uL, 0x37D83BF0uL,
        0xA9BCAE53uL, 0xDEBB9EC5uL, 0x47B2CF7FuL, 0x30B5FFE9uL,
        0xBDBDF21CuL, 0xCABAC28AuL, 0x53B39330uL, 0x24B4A3A6uL,
        0xBAD03605uL, 0xCDD70693uL, 0x54DE5729uL, 0x23D967BFuL,
        0xB3667A2EuL, 0xC4614AB8uL, 0x5D681B02uL, 0x2A6F2B94uL,
        0xB40BBE37uL, 0xC30C8EA1uL, 0x5A05DF1BuL, 0x2D02EF8DuL
    };
#endif

#if (CRC_CALCULATE_CRC8H2F_ENABLE == STD_ON)
/*MISRA RULE 4.9 VIOLATION and MISRA RULE 8.9 VIOLATION: The declaration Crc_Table8bitH2F will be used by other functions in future ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
	static const uint8 Crc_Table8bitH2F[256]=
	{
		0x00, 0x2f, 0x5e, 0x71, 0xbc, 0x93, 0xe2, 0xcd, 0x57, 0x78, 0x09, 0x26, 0xeb,
        0xc4, 0xb5, 0x9a, 0xae, 0x81, 0xf0, 0xdf, 0x12, 0x3d, 0x4c, 0x63, 0xf9, 0xd6,
        0xa7, 0x88, 0x45, 0x6a, 0x1b, 0x34, 0x73, 0x5c, 0x2d, 0x02, 0xcf, 0xe0, 0x91,
        0xbe, 0x24, 0x0b, 0x7a, 0x55, 0x98, 0xb7, 0xc6, 0xe9, 0xdd, 0xf2, 0x83, 0xac,
        0x61, 0x4e, 0x3f, 0x10, 0x8a, 0xa5, 0xd4, 0xfb, 0x36, 0x19, 0x68, 0x47, 0xe6,
        0xc9, 0xb8, 0x97, 0x5a, 0x75, 0x04, 0x2b, 0xb1, 0x9e, 0xef, 0xc0, 0x0d, 0x22,
        0x53, 0x7c, 0x48, 0x67, 0x16, 0x39, 0xf4, 0xdb, 0xaa, 0x85, 0x1f, 0x30, 0x41,
        0x6e, 0xa3, 0x8c, 0xfd, 0xd2, 0x95, 0xba, 0xcb, 0xe4, 0x29, 0x06, 0x77, 0x58,
        0xc2, 0xed, 0x9c, 0xb3, 0x7e, 0x51, 0x20, 0x0f, 0x3b, 0x14, 0x65, 0x4a, 0x87,
        0xa8, 0xd9, 0xf6, 0x6c, 0x43, 0x32, 0x1d, 0xd0, 0xff, 0x8e, 0xa1, 0xe3, 0xcc,
        0xbd, 0x92, 0x5f, 0x70, 0x01, 0x2e, 0xb4, 0x9b, 0xea, 0xc5, 0x08, 0x27, 0x56,
        0x79, 0x4d, 0x62, 0x13, 0x3c, 0xf1, 0xde, 0xaf, 0x80, 0x1a, 0x35, 0x44, 0x6b,
        0xa6, 0x89, 0xf8, 0xd7, 0x90, 0xbf, 0xce, 0xe1, 0x2c, 0x03, 0x72, 0x5d, 0xc7,
        0xe8, 0x99, 0xb6, 0x7b, 0x54, 0x25, 0x0a, 0x3e, 0x11, 0x60, 0x4f, 0x82, 0xad,
        0xdc, 0xf3, 0x69, 0x46, 0x37, 0x18, 0xd5, 0xfa, 0x8b, 0xa4, 0x05, 0x2a, 0x5b,
        0x74, 0xb9, 0x96, 0xe7, 0xc8, 0x52, 0x7d, 0x0c, 0x23, 0xee, 0xc1, 0xb0, 0x9f,
        0xab, 0x84, 0xf5, 0xda, 0x17, 0x38, 0x49, 0x66, 0xfc, 0xd3, 0xa2, 0x8d, 0x40,
        0x6f, 0x1e, 0x31, 0x76, 0x59, 0x28, 0x07, 0xca, 0xe5, 0x94, 0xbb, 0x21, 0x0e,
        0x7f, 0x50, 0x9d, 0xb2, 0xc3, 0xec, 0xd8, 0xf7, 0x86, 0xa9, 0x64, 0x4b, 0x3a,
        0x15, 0x8f, 0xa0, 0xd1, 0xfe, 0x33, 0x1c, 0x6d, 0x42
	};
#endif

#if (CRC_CALCULATE_CRC32P4_ENABLE == STD_ON)
	/*MISRA RULE 4.9 VIOLATION and MISRA RULE 8.9 VIOLATION: The declaration Crc_Table32bitP4 will be used by other functions in future ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
	static const uint32 Crc_Table32bitP4[256]=
	{
		0x00000000UL, 0x30850FF5UL, 0x610A1FEAUL, 0x518F101FUL, 0xC2143FD4UL, 0xF2913021UL, 0xA31E203EUL, 0x939B2FCBUL,
        0x159615F7UL, 0x25131A02UL, 0x749C0A1DUL, 0x441905E8UL, 0xD7822A23UL, 0xE70725D6UL, 0xB68835C9UL, 0x860D3A3CUL,
        0x2B2C2BEEUL, 0x1BA9241BUL, 0x4A263404UL, 0x7AA33BF1UL, 0xE938143AUL, 0xD9BD1BCFUL, 0x88320BD0UL, 0xB8B70425UL,
        0x3EBA3E19UL, 0x0E3F31ECUL, 0x5FB021F3UL, 0x6F352E06UL, 0xFCAE01CDUL, 0xCC2B0E38UL, 0x9DA41E27UL, 0xAD2111D2UL,
        0x565857DCUL, 0x66DD5829UL, 0x37524836UL, 0x07D747C3UL, 0x944C6808UL, 0xA4C967FDUL, 0xF54677E2UL, 0xC5C37817UL,
        0x43CE422BUL, 0x734B4DDEUL, 0x22C45DC1UL, 0x12415234UL, 0x81DA7DFFUL, 0xB15F720AUL, 0xE0D06215UL, 0xD0556DE0UL,
        0x7D747C32UL, 0x4DF173C7UL, 0x1C7E63D8UL, 0x2CFB6C2DUL, 0xBF6043E6UL, 0x8FE54C13UL, 0xDE6A5C0CUL, 0xEEEF53F9UL,
        0x68E269C5UL, 0x58676630UL, 0x09E8762FUL, 0x396D79DAUL, 0xAAF65611UL, 0x9A7359E4UL, 0xCBFC49FBUL, 0xFB79460EUL,
        0xACB0AFB8UL, 0x9C35A04DUL, 0xCDBAB052UL, 0xFD3FBFA7UL, 0x6EA4906CUL, 0x5E219F99UL, 0x0FAE8F86UL, 0x3F2B8073UL,
        0xB926BA4FUL, 0x89A3B5BAUL, 0xD82CA5A5UL, 0xE8A9AA50UL, 0x7B32859BUL, 0x4BB78A6EUL, 0x1A389A71UL, 0x2ABD9584UL,
        0x879C8456UL, 0xB7198BA3UL, 0xE6969BBCUL, 0xD6139449UL, 0x4588BB82UL, 0x750DB477UL, 0x2482A468UL, 0x1407AB9DUL,
        0x920A91A1UL, 0xA28F9E54UL, 0xF3008E4BUL, 0xC38581BEUL, 0x501EAE75UL, 0x609BA180UL, 0x3114B19FUL, 0x0191BE6AUL,
        0xFAE8F864UL, 0xCA6DF791UL, 0x9BE2E78EUL, 0xAB67E87BUL, 0x38FCC7B0UL, 0x0879C845UL, 0x59F6D85AUL, 0x6973D7AFUL,
        0xEF7EED93UL, 0xDFFBE266UL, 0x8E74F279UL, 0xBEF1FD8CUL, 0x2D6AD247UL, 0x1DEFDDB2UL, 0x4C60CDADUL, 0x7CE5C258UL,
        0xD1C4D38AUL, 0xE141DC7FUL, 0xB0CECC60UL, 0x804BC395UL, 0x13D0EC5EUL, 0x2355E3ABUL, 0x72DAF3B4UL, 0x425FFC41UL,
        0xC452C67DUL, 0xF4D7C988UL, 0xA558D997UL, 0x95DDD662UL, 0x0646F9A9UL, 0x36C3F65CUL, 0x674CE643UL, 0x57C9E9B6UL,
        0xC8DF352FUL, 0xF85A3ADAUL, 0xA9D52AC5UL, 0x99502530UL, 0x0ACB0AFBUL, 0x3A4E050EUL, 0x6BC11511UL, 0x5B441AE4UL,
        0xDD4920D8UL, 0xEDCC2F2DUL, 0xBC433F32UL, 0x8CC630C7UL, 0x1F5D1F0CUL, 0x2FD810F9UL, 0x7E5700E6UL, 0x4ED20F13UL,
        0xE3F31EC1UL, 0xD3761134UL, 0x82F9012BUL, 0xB27C0EDEUL, 0x21E72115UL, 0x11622EE0UL, 0x40ED3EFFUL, 0x7068310AUL,
        0xF6650B36UL, 0xC6E004C3UL, 0x976F14DCUL, 0xA7EA1B29UL, 0x347134E2UL, 0x04F43B17UL, 0x557B2B08UL, 0x65FE24FDUL,
        0x9E8762F3UL, 0xAE026D06UL, 0xFF8D7D19UL, 0xCF0872ECUL, 0x5C935D27UL, 0x6C1652D2UL, 0x3D9942CDUL, 0x0D1C4D38UL,
        0x8B117704UL, 0xBB9478F1UL, 0xEA1B68EEUL, 0xDA9E671BUL, 0x490548D0UL, 0x79804725UL, 0x280F573AUL, 0x188A58CFUL,
        0xB5AB491DUL, 0x852E46E8UL, 0xD4A156F7UL, 0xE4245902UL, 0x77BF76C9UL, 0x473A793CUL, 0x16B56923UL, 0x263066D6UL,
        0xA03D5CEAUL, 0x90B8531FUL, 0xC1374300UL, 0xF1B24CF5UL, 0x6229633EUL, 0x52AC6CCBUL, 0x03237CD4UL, 0x33A67321UL,
        0x646F9A97UL, 0x54EA9562UL, 0x0565857DUL, 0x35E08A88UL, 0xA67BA543UL, 0x96FEAAB6UL, 0xC771BAA9UL, 0xF7F4B55CUL,
        0x71F98F60UL, 0x417C8095UL, 0x10F3908AUL, 0x20769F7FUL, 0xB3EDB0B4UL, 0x8368BF41UL, 0xD2E7AF5EUL, 0xE262A0ABUL,
        0x4F43B179UL, 0x7FC6BE8CUL, 0x2E49AE93UL, 0x1ECCA166UL, 0x8D578EADUL, 0xBDD28158UL, 0xEC5D9147UL, 0xDCD89EB2UL,
        0x5AD5A48EUL, 0x6A50AB7BUL, 0x3BDFBB64UL, 0x0B5AB491UL, 0x98C19B5AUL, 0xA84494AFUL, 0xF9CB84B0UL, 0xC94E8B45UL,
        0x3237CD4BUL, 0x02B2C2BEUL, 0x533DD2A1UL, 0x63B8DD54UL, 0xF023F29FUL, 0xC0A6FD6AUL, 0x9129ED75UL, 0xA1ACE280UL,
        0x27A1D8BCUL, 0x1724D749UL, 0x46ABC756UL, 0x762EC8A3UL, 0xE5B5E768UL, 0xD530E89DUL, 0x84BFF882UL, 0xB43AF777UL,
        0x191BE6A5UL, 0x299EE950UL, 0x7811F94FUL, 0x4894F6BAUL, 0xDB0FD971UL, 0xEB8AD684UL, 0xBA05C69BUL, 0x8A80C96EUL,
        0x0C8DF352UL, 0x3C08FCA7UL, 0x6D87ECB8UL, 0x5D02E34DUL, 0xCE99CC86UL, 0xFE1CC373UL, 0xAF93D36CUL, 0x9F16DC99UL
	};
#endif

#if (CRC_CALCULATE_CRC64_ENABLE == STD_ON)
    static const uint64 Crc_Table64bit[256]=
    {
        0x0000000000000000uLL, 0xB32E4CBE03A75F6FuLL, 0xF4843657A840A05BuLL, 0x47AA7AE9ABE7FF34uLL,
        0x7BD0C384FF8F5E33uLL, 0xC8FE8F3AFC28015CuLL, 0x8F54F5D357CFFE68uLL, 0x3C7AB96D5468A107uLL,
        0xF7A18709FF1EBC66uLL, 0x448FCBB7FCB9E309uLL, 0x0325B15E575E1C3DuLL, 0xB00BFDE054F94352uLL,
        0x8C71448D0091E255uLL, 0x3F5F08330336BD3AuLL, 0x78F572DAA8D1420EuLL, 0xCBDB3E64AB761D61uLL,
        0x7D9BA13851336649uLL, 0xCEB5ED8652943926uLL, 0x891F976FF973C612uLL, 0x3A31DBD1FAD4997DuLL,
        0x064B62BCAEBC387AuLL, 0xB5652E02AD1B6715uLL, 0xF2CF54EB06FC9821uLL, 0x41E11855055BC74EuLL,
        0x8A3A2631AE2DDA2FuLL, 0x39146A8FAD8A8540uLL, 0x7EBE1066066D7A74uLL, 0xCD905CD805CA251BuLL,
        0xF1EAE5B551A2841CuLL, 0x42C4A90B5205DB73uLL, 0x056ED3E2F9E22447uLL, 0xB6409F5CFA457B28uLL,
        0xFB374270A266CC92uLL, 0x48190ECEA1C193FDuLL, 0x0FB374270A266CC9uLL, 0xBC9D3899098133A6uLL,
        0x80E781F45DE992A1uLL, 0x33C9CD4A5E4ECDCEuLL, 0x7463B7A3F5A932FAuLL, 0xC74DFB1DF60E6D95uLL,
        0x0C96C5795D7870F4uLL, 0xBFB889C75EDF2F9BuLL, 0xF812F32EF538D0AFuLL, 0x4B3CBF90F69F8FC0uLL,
        0x774606FDA2F72EC7uLL, 0xC4684A43A15071A8uLL, 0x83C230AA0AB78E9CuLL, 0x30EC7C140910D1F3uLL,
        0x86ACE348F355AADBuLL, 0x3582AFF6F0F2F5B4uLL, 0x7228D51F5B150A80uLL, 0xC10699A158B255EFuLL,
        0xFD7C20CC0CDAF4E8uLL, 0x4E526C720F7DAB87uLL, 0x09F8169BA49A54B3uLL, 0xBAD65A25A73D0BDCuLL,
        0x710D64410C4B16BDuLL, 0xC22328FF0FEC49D2uLL, 0x85895216A40BB6E6uLL, 0x36A71EA8A7ACE989uLL,
        0x0ADDA7C5F3C4488EuLL, 0xB9F3EB7BF06317E1uLL, 0xFE5991925B84E8D5uLL, 0x4D77DD2C5823B7BAuLL,
        0x64B62BCAEBC387A1uLL, 0xD7986774E864D8CEuLL, 0x90321D9D438327FAuLL, 0x231C512340247895uLL,
        0x1F66E84E144CD992uLL, 0xAC48A4F017EB86FDuLL, 0xEBE2DE19BC0C79C9uLL, 0x58CC92A7BFAB26A6uLL,
        0x9317ACC314DD3BC7uLL, 0x2039E07D177A64A8uLL, 0x67939A94BC9D9B9CuLL, 0xD4BDD62ABF3AC4F3uLL,
        0xE8C76F47EB5265F4uLL, 0x5BE923F9E8F53A9BuLL, 0x1C4359104312C5AFuLL, 0xAF6D15AE40B59AC0uLL,
        0x192D8AF2BAF0E1E8uLL, 0xAA03C64CB957BE87uLL, 0xEDA9BCA512B041B3uLL, 0x5E87F01B11171EDCuLL,
        0x62FD4976457FBFDBuLL, 0xD1D305C846D8E0B4uLL, 0x96797F21ED3F1F80uLL, 0x2557339FEE9840EFuLL,
        0xEE8C0DFB45EE5D8EuLL, 0x5DA24145464902E1uLL, 0x1A083BACEDAEFDD5uLL, 0xA9267712EE09A2BAuLL,
        0x955CCE7FBA6103BDuLL, 0x267282C1B9C65CD2uLL, 0x61D8F8281221A3E6uLL, 0xD2F6B4961186FC89uLL,
        0x9F8169BA49A54B33uLL, 0x2CAF25044A02145CuLL, 0x6B055FEDE1E5EB68uLL, 0xD82B1353E242B407uLL,
        0xE451AA3EB62A1500uLL, 0x577FE680B58D4A6FuLL, 0x10D59C691E6AB55BuLL, 0xA3FBD0D71DCDEA34uLL,
        0x6820EEB3B6BBF755uLL, 0xDB0EA20DB51CA83AuLL, 0x9CA4D8E41EFB570EuLL, 0x2F8A945A1D5C0861uLL,
        0x13F02D374934A966uLL, 0xA0DE61894A93F609uLL, 0xE7741B60E174093DuLL, 0x545A57DEE2D35652uLL,
        0xE21AC88218962D7AuLL, 0x5134843C1B317215uLL, 0x169EFED5B0D68D21uLL, 0xA5B0B26BB371D24EuLL,
        0x99CA0B06E7197349uLL, 0x2AE447B8E4BE2C26uLL, 0x6D4E3D514F59D312uLL, 0xDE6071EF4CFE8C7DuLL,
        0x15BB4F8BE788911CuLL, 0xA6950335E42FCE73uLL, 0xE13F79DC4FC83147uLL, 0x521135624C6F6E28uLL,
        0x6E6B8C0F1807CF2FuLL, 0xDD45C0B11BA09040uLL, 0x9AEFBA58B0476F74uLL, 0x29C1F6E6B3E0301BuLL,
        0xC96C5795D7870F42uLL, 0x7A421B2BD420502DuLL, 0x3DE861C27FC7AF19uLL, 0x8EC62D7C7C60F076uLL,
        0xB2BC941128085171uLL, 0x0192D8AF2BAF0E1EuLL, 0x4638A2468048F12AuLL, 0xF516EEF883EFAE45uLL,
        0x3ECDD09C2899B324uLL, 0x8DE39C222B3EEC4BuLL, 0xCA49E6CB80D9137FuLL, 0x7967AA75837E4C10uLL,
        0x451D1318D716ED17uLL, 0xF6335FA6D4B1B278uLL, 0xB199254F7F564D4CuLL, 0x02B769F17CF11223uLL,
        0xB4F7F6AD86B4690BuLL, 0x07D9BA1385133664uLL, 0x4073C0FA2EF4C950uLL, 0xF35D8C442D53963FuLL,
        0xCF273529793B3738uLL, 0x7C0979977A9C6857uLL, 0x3BA3037ED17B9763uLL, 0x888D4FC0D2DCC80CuLL,
        0x435671A479AAD56DuLL, 0xF0783D1A7A0D8A02uLL, 0xB7D247F3D1EA7536uLL, 0x04FC0B4DD24D2A59uLL,
        0x3886B22086258B5EuLL, 0x8BA8FE9E8582D431uLL, 0xCC0284772E652B05uLL, 0x7F2CC8C92DC2746AuLL,
        0x325B15E575E1C3D0uLL, 0x8175595B76469CBFuLL, 0xC6DF23B2DDA1638BuLL, 0x75F16F0CDE063CE4uLL,
        0x498BD6618A6E9DE3uLL, 0xFAA59ADF89C9C28CuLL, 0xBD0FE036222E3DB8uLL, 0x0E21AC88218962D7uLL,
        0xC5FA92EC8AFF7FB6uLL, 0x76D4DE52895820D9uLL, 0x317EA4BB22BFDFEDuLL, 0x8250E80521188082uLL,
        0xBE2A516875702185uLL, 0x0D041DD676D77EEAuLL, 0x4AAE673FDD3081DEuLL, 0xF9802B81DE97DEB1uLL,
        0x4FC0B4DD24D2A599uLL, 0xFCEEF8632775FAF6uLL, 0xBB44828A8C9205C2uLL, 0x086ACE348F355AADuLL,
        0x34107759DB5DFBAAuLL, 0x873E3BE7D8FAA4C5uLL, 0xC094410E731D5BF1uLL, 0x73BA0DB070BA049EuLL,
        0xB86133D4DBCC19FFuLL, 0x0B4F7F6AD86B4690uLL, 0x4CE50583738CB9A4uLL, 0xFFCB493D702BE6CBuLL,
        0xC3B1F050244347CCuLL, 0x709FBCEE27E418A3uLL, 0x3735C6078C03E797uLL, 0x841B8AB98FA4B8F8uLL,
        0xADDA7C5F3C4488E3uLL, 0x1EF430E13FE3D78CuLL, 0x595E4A08940428B8uLL, 0xEA7006B697A377D7uLL,
        0xD60ABFDBC3CBD6D0uLL, 0x6524F365C06C89BFuLL, 0x228E898C6B8B768BuLL, 0x91A0C532682C29E4uLL,
        0x5A7BFB56C35A3485uLL, 0xE955B7E8C0FD6BEAuLL, 0xAEFFCD016B1A94DEuLL, 0x1DD181BF68BDCBB1uLL,
        0x21AB38D23CD56AB6uLL, 0x9285746C3F7235D9uLL, 0xD52F0E859495CAEDuLL, 0x6601423B97329582uLL,
        0xD041DD676D77EEAAuLL, 0x636F91D96ED0B1C5uLL, 0x24C5EB30C5374EF1uLL, 0x97EBA78EC690119EuLL,
        0xAB911EE392F8B099uLL, 0x18BF525D915FEFF6uLL, 0x5F1528B43AB810C2uLL, 0xEC3B640A391F4FADuLL,
        0x27E05A6E926952CCuLL, 0x94CE16D091CE0DA3uLL, 0xD3646C393A29F297uLL, 0x604A2087398EADF8uLL,
        0x5C3099EA6DE60CFFuLL, 0xEF1ED5546E415390uLL, 0xA8B4AFBDC5A6ACA4uLL, 0x1B9AE303C601F3CBuLL,
        0x56ED3E2F9E224471uLL, 0xE5C372919D851B1EuLL, 0xA26908783662E42AuLL, 0x114744C635C5BB45uLL,
        0x2D3DFDAB61AD1A42uLL, 0x9E13B115620A452DuLL, 0xD9B9CBFCC9EDBA19uLL, 0x6A978742CA4AE576uLL,
        0xA14CB926613CF817uLL, 0x1262F598629BA778uLL, 0x55C88F71C97C584CuLL, 0xE6E6C3CFCADB0723uLL,
        0xDA9C7AA29EB3A624uLL, 0x69B2361C9D14F94BuLL, 0x2E184CF536F3067FuLL, 0x9D36004B35545910uLL,
        0x2B769F17CF112238uLL, 0x9858D3A9CCB67D57uLL, 0xDFF2A94067518263uLL, 0x6CDCE5FE64F6DD0CuLL,
        0x50A65C93309E7C0BuLL, 0xE388102D33392364uLL, 0xA4226AC498DEDC50uLL, 0x170C267A9B79833FuLL,
        0xDCD7181E300F9E5EuLL, 0x6FF954A033A8C131uLL, 0x28532E49984F3E05uLL, 0x9B7D62F79BE8616AuLL,
        0xA707DB9ACF80C06DuLL, 0x14299724CC279F02uLL, 0x5383EDCD67C06036uLL, 0xE0ADA17364673F59uLL
    };
#endif
/*MISRA RULE 2.5 VIOLATION: Macro is used to indicate the end of declaring constants section ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
#define CRCLIB_CONST_SEC_END
/*MISRA RULE 20.1 VIOLATION: program should be used after all the #include directives are done ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
#include "Crc_MemMap.h"
/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
/*============================================================================
**
** Function Name    :   Crc_CalculateCRC8
**
** Visibility       :   Public
**
** Description      :   This function calculates and returns the 8 bit CRC  
**                      (8 bit SAE J1850)for the given number of data.
**
** Invocation       :   Whoever wants to calculate the 8 bit SAE J1850 CRC
**
** Inputs           :   Crc_DataPtr: Pointer to the data for which the CRC to be calculated
**                      Crc_Length: Number of bytes to be taken for calculation.
**                      Crc_StartValue8: CRC Start value, if this is a continuation of 
**                                       previous CRC calculation. Crc_IsFirstCall shall be 
**                                       FALSE for this to be considered.
**                      Crc_IsFirstCall: TRUE if this is the first call for CRC calculation. Start Value will be 0xFF
**                                       FALSE if this is a continuation of precious CRC calculation.
**
** Outputs          :   Calculated 8 bit CRC value
**
** Critical Section :   NA
**
**==========================================================================*/
/*MISRA RULE 2.5 VIOLATION: Macro is used to indicate the start of coding section ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
#define CRCLIB_CODE_SEC_START
#include "Crc_MemMap.h"

	/*MISRA RULE 4.9 VIOLATION and MISRA RULE 8.7 VIOLATION: As per the autosar standard the function is defined ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
uint8 Crc_CalculateCRC8(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8, boolean Crc_IsFirstCall)
{
    uint8 Crc_Value = 0;
#if (CRC_CALCULATE_CRC8_ENABLE == STD_ON)  
    #if (CRC_8_MODE == CRC_8_TABLE)
    uint32 Crc_DataCount = 0;
    #endif
    #if (CRC_8_MODE == CRC_8_RUNTIME)
    uint32 Crc_DataPtrAddr = 0;
    uint8 Crc_LoopCounter = 0;
    #endif

	if( FALSE != Crc_IsFirstCall )
    {
        /* If first CRC call, set the initial value */
        Crc_Value = CRC_INITIAL_VALUE8;
    }
    else
    {
        /* If continuation of CRC calculation, then revert back the last CRC value*/
        Crc_Value = (CRC_FINAL_XOR_CRC8 ^ Crc_StartValue8);
    }
    #if (CRC_8_MODE == CRC_8_TABLE)
    if (NULL_PTR != Crc_DataPtr)
	{

		for (Crc_DataCount = 0; Crc_DataCount < Crc_Length; Crc_DataCount++)
		{
			Crc_Value = Crc_Table8bit[Crc_Value ^ Crc_DataPtr[Crc_DataCount]];
		}
    }
        #endif

        #if (CRC_8_MODE == CRC_8_RUNTIME)
        if (NULL_PTR != Crc_DataPtr)
	{
       for (Crc_DataPtrAddr = 0; Crc_DataPtrAddr < Crc_Length; Crc_DataPtrAddr++)
  {
    
    Crc_Value ^= Crc_DataPtr[Crc_DataPtrAddr];

    
    for (Crc_LoopCounter = 0; Crc_LoopCounter < 8; Crc_LoopCounter++)
    {
     
      if ((Crc_Value & (uint8) CRC_RUNTIME_POLYNOMIAL_8) > 0)
      {
        Crc_Value = ( (uint8)(Crc_Value << 1u) ) ^ CRC_POLYNOMIAL_8;
      }
      else
      {
        Crc_Value = (uint8) (Crc_Value << 1u);
      }
    }
  }
      
	}
      #endif
    /* Invert the final CRC Value */
    Crc_Value = CRC_FINAL_XOR_CRC8 ^ Crc_Value;
#endif /* CRC_CALCULATE_CRC8_ENABLE */
    return Crc_Value;
  }

/*============================================================================
**
** Function Name    :   Crc_CalculateCRC8H2F
**
** Visibility       :   Public
**
** Description      :   This function calculates and returns the 8 bit CRC  
**                      (8 bit with 0x2F polynomial)for the given number of data.
**
** Invocation       :   Whoever wants to calculate the 8 bit  CRC with 0x2F polynomial.
**
** Inputs           :   Crc_DataPtr: Pointer to the data for which the CRC to be calculated
**                      Crc_Length: Number of bytes to be taken for calculation.
**                      Crc_StartValue8: CRC Start value, if this is a continuation of 
**                                       previous CRC calculation. Crc_IsFirstCall shall be 
**                                       FALSE for this to be considered.
**                      Crc_IsFirstCall: TRUE if this is the first call for CRC calculation. Start Value will be 0xFF
**                                       FALSE if this is a continuation of precious CRC calculation.
**
** Outputs          :   Calculated 8 bit CRC value
**
** Critical Section :   NA
**
**==========================================================================*/
	/*MISRA RULE 4.9 VIOLATION and MISRA RULE 8.7 VIOLATION: As per the autosar standard the function is defined ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
uint8 Crc_CalculateCRC8H2F(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8, boolean Crc_IsFirstCall)
{
    uint8 Crc_Value = 0;
#if (CRC_CALCULATE_CRC8H2F_ENABLE == STD_ON)
    #if (CRC_8H2F_MODE == CRC_8H2F_TABLE)
    uint32 Crc_DataCount = 0;
    #endif
     #if (CRC_8H2F_MODE == CRC_8H2F_RUNTIME)
    uint32 Crc_DataPtrAddr = 0;
    uint8 Crc_LoopCounter = 0;
    #endif
    
    if( FALSE != Crc_IsFirstCall )
    {
        /* If first CRC call, set the initial value */
        Crc_Value = CRC_INITIAL_VALUE8;
    }
    else
    {
        /* If continuation of CRC calculation, then revert back the last CRC value*/
        Crc_Value = (CRC_FINAL_XOR_CRC8 ^ Crc_StartValue8);
    }
     #if (CRC_8H2F_MODE == CRC_8H2F_TABLE)
	if (NULL_PTR != Crc_DataPtr)
	{
       
		for (Crc_DataCount = 0; Crc_DataCount < Crc_Length; Crc_DataCount++)
		{
			Crc_Value = Crc_Table8bitH2F[Crc_Value ^ Crc_DataPtr[Crc_DataCount]];
		}
    }
        #endif
        #if (CRC_8H2F_MODE == CRC_8H2F_RUNTIME)
        for (Crc_DataPtrAddr = 0; Crc_DataPtrAddr < Crc_Length; Crc_DataPtrAddr++)
  {
    
    Crc_Value ^= Crc_DataPtr[Crc_DataPtrAddr];

    
    for (Crc_LoopCounter = 0; Crc_LoopCounter < 8; Crc_LoopCounter++)
    {
      
      if ((Crc_Value & (uint8) CRC_RUNTIME_POLYNOMIAL_8) > 0)
      {
        Crc_Value = ( (uint8)(Crc_Value << 1u) ) ^ CRC_POLYNOMIAL_8H2F;
      }
      else
      {
        Crc_Value = (uint8) (Crc_Value << 1u);
      }
    }
  }
    #endif
    /* Invert the final CRC Value */
    Crc_Value = CRC_FINAL_XOR_CRC8 ^ Crc_Value;
#endif /* CRC_CALCULATE_CRC8H2F_ENABLE */
    return Crc_Value;
}

/*============================================================================
**
** Function Name    :   Crc_CalculateCRC16
**
** Visibility       :   Public
**
** Description      :   This function calculates and returns the 16 bit CRC  
**                      (16 bit with 0x1021 polynomial(CRC-CCITT))for the given number of data.
**                      Width = 16 bits
**                      CRC-CCITT Specification:
**                      Truncated polynomial = 0x1021
**                      Initial value = 0xFFFF
**                      Input data is NOT reflected
**                      Output CRC is NOT reflected
**                      No XOR is performed on the output CRC
**
** Invocation       :   Whoever wants to calculate the 16 bit CRC with 0x1021 polynomial.
**
** Inputs           :   Crc_DataPtr: Pointer to the data for which the CRC to be calculated
**                      Crc_Length: Number of bytes to be taken for calculation.
**                      Crc_StartValue16: CRC Start value, if this is a continuation of 
**                                       previous CRC calculation. Crc_IsFirstCall shall be 
**                                       FALSE for this to be considered.
**                      Crc_IsFirstCall: TRUE if this is the first call for CRC calculation. Start Value will be 0xFFFF.
**                                       FALSE if this is a continuation of precious CRC calculation.
**
** Outputs          :   Calculated 16 bit CRC value
**
** Critical Section :   NA
**
**==========================================================================*/
	/*MISRA RULE 4.9 VIOLATION and MISRA RULE 8.7 VIOLATION: As per the autosar standard the function is defined ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
uint16 Crc_CalculateCRC16(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall)
{
    uint16 Crc_Value16 = 0;
#if (CRC_CALCULATE_CRC16_ENABLE == STD_ON)
    #if (CRC_16_MODE == CRC_16_TABLE)
    uint8 Crc_TableIndex = 0;
     uint32 Crc_DataCount = 0;
    #endif
    #if (CRC_16_MODE == CRC_16_RUNTIME)
    uint32 Crc_DataPtrAddr = 0;
    uint8 Crc_LoopCounter = 0;
    #endif 

    if( TRUE == Crc_IsFirstCall )
    {
        Crc_Value16 = CRC_INITIAL_VALUE16;
    }
    else
    {
        Crc_Value16 = Crc_StartValue16;
    }
    #if (CRC_16_MODE == CRC_16_TABLE)
    if (NULL_PTR != Crc_DataPtr)
	{

        for(Crc_DataCount=0; Crc_DataCount<Crc_Length; Crc_DataCount++)
        {
            Crc_TableIndex = ((uint8)( Crc_Value16 >> 8U )) ^ Crc_DataPtr[Crc_DataCount];
            Crc_Value16 = ( Crc_Value16 << 8U ) ^ Crc_Table16bit[ Crc_TableIndex ];
			
        }
    }
    #endif

    #if (CRC_16_MODE == CRC_16_RUNTIME)
   if (NULL_PTR != Crc_DataPtr)
	{
   for (Crc_DataPtrAddr = 0; Crc_DataPtrAddr < Crc_Length; Crc_DataPtrAddr++)
  {
    
    Crc_Value16 ^= ((uint16)Crc_DataPtr[Crc_DataPtrAddr] << 8u);

   
    for (Crc_LoopCounter = 0; Crc_LoopCounter < 8; Crc_LoopCounter++)
    {
      
      if ((Crc_Value16 & (uint16)CRC_RUNTIME_POLYNOMIAL_16) > 0)
      {
        Crc_Value16 = ( (uint16)(Crc_Value16 << 1u) ) ^ CRC_POLYNOMIAL_16;
      }
      else
      {
        Crc_Value16 <<= 1u;
      }
    }
  }
    }
#endif
#endif /* CRC_CALCULATE_CRC16_ENABLE */
    return Crc_Value16;
}

/*============================================================================
**
** Function Name    :   Crc_CalculateCRC32
**
** Visibility       :   Public
**
** Description      :   This function calculates and returns the 32 bit CRC  
**                      (32 bit Ethernet IEEE-802 with 0x04C11DB7 polynomial) for the given number of data.
**
** Invocation       :   Whoever wants to calculate the 32 bit Ethernet IEEE-802 with 0x04C11DB7 polynomial CRC.
**
** Inputs           :   Crc_DataPtr: Pointer to the data for which the CRC to be calculated
**                      Crc_Length: Number of bytes to be taken for calculation.
**                      Crc_StartValue32: CRC Start value, if this is a continuation of 
**                                       previous CRC calculation. Crc_IsFirstCall shall be 
**                                       FALSE for this to be considered.
**                      Crc_IsFirstCall: TRUE if this is the first call for CRC calculation. Start Value will be 0xFFFFFFFF.
**                                       FALSE if this is a continuation of precious CRC calculation.
**
** Outputs          :   Calculated 32 bit CRC value
**
** Critical Section :   NA 
**
**==========================================================================*/

	/*MISRA RULE 4.9 VIOLATION and MISRA RULE 8.7 VIOLATION: As per the autosar standard the function is defined ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
uint32 Crc_CalculateCRC32(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall)
{
    uint32 Crc_Value32 = 0;
#if (CRC_CALCULATE_CRC32_ENABLE == STD_ON)
    uint32 fl_CrcLength_u32 = Crc_Length;
    #if (CRC_32_MODE == CRC_32_TABLE)
    uint32 DataPtrAddr_u16 = 0;
    #endif
    #if (CRC_32_MODE == CRC_32_RUNTIME)
    uint32 Crc_DataPtrAddr = 0;
    uint8 Crc_LoopCounter = 0;
    #endif


    if( TRUE == Crc_IsFirstCall )
    {
        Crc_Value32 = CRC_INITIAL_VALUE32;
    }
    else
    {
        Crc_Value32 = (CRC_FINAL_XOR_CRC32 ^ Crc_StartValue32);
    }
    #if (CRC_32_MODE == CRC_32_TABLE)
    if (NULL_PTR != Crc_DataPtr)
	{
      for(DataPtrAddr_u16 = 0; DataPtrAddr_u16<fl_CrcLength_u32; DataPtrAddr_u16 ++)
      {
			Crc_Value32 ^= CRC_UINT8_VALUE & (uint32) Crc_DataPtr[DataPtrAddr_u16];
			Crc_Value32 = ( Crc_Value32 >> 8 ) ^ ( Crc_Table32bit [ (uint8)(Crc_Value32 )]);
      }
				/*MISRA RULE 4.9 VIOLATION and MISRA RULE 10.5 VIOLATION: Macro is replaced by the function ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
		} 
#endif

#if (CRC_32_MODE == CRC_32_RUNTIME)
if (NULL_PTR != Crc_DataPtr)
	{
for (Crc_DataPtrAddr = 0; Crc_DataPtrAddr < fl_CrcLength_u32; Crc_DataPtrAddr++)
  {

    
    Crc_Value32 ^= 0xFFuL & (uint32) Crc_DataPtr[Crc_DataPtrAddr];

    
    for (Crc_LoopCounter = 0; Crc_LoopCounter < 8; Crc_LoopCounter++)
    {
      
      if ( (Crc_Value32 & 1u) > 0 )
      {
        Crc_Value32 = ( Crc_Value32 >> 1u ) ^ CRC_POLYNOMIAL_32_REFLECT;
      }
      else
      {
        Crc_Value32 = Crc_Value32 >> 1u;
      }
    }
  }
    }
    #endif
    Crc_Value32 = CRC_FINAL_XOR_CRC32 ^ Crc_Value32; 
#endif /* CRC_CALCULATE_CRC32_ENABLE */
    return Crc_Value32;
}


/*============================================================================
**
** Function Name    :   Crc_CalculateCRC32P4
**
** Visibility       :   Public
**
** Description      :   This function calculates and returns the 32 bit CRC  
**                      (32 bit CRC with 0xF4ACFB13 polynomial) for the given number of data.
**
** Invocation       :   Whoever wants to calculate the 32 bit CRC with 0xF4ACFB13 polynomial CRC.
**
** Inputs           :   Crc_DataPtr: Pointer to the data for which the CRC to be calculated
**                      Crc_Length: Number of bytes to be taken for calculation.
**                      Crc_StartValue32: CRC Start value, if this is a continuation of 
**                                       previous CRC calculation. Crc_IsFirstCall shall be 
**                                       FALSE for this to be considered.
**                      Crc_IsFirstCall: TRUE if this is the first call for CRC calculation. Start Value will be 0xFFFFFFFF.
**                                       FALSE if this is a continuation of precious CRC calculation.
**
** Outputs          :   Calculated 32 bit CRC value
**
** Critical Section :   NA
**
**==========================================================================*/
	/*MISRA RULE 4.9 VIOLATION and MISRA RULE 8.7 VIOLATION: As per the autosar standard the function is defined ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
uint32 Crc_CalculateCRC32P4(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall)
{
    uint32 Crc_Value32 = 0; 
#if (CRC_CALCULATE_CRC32P4_ENABLE == STD_ON) 
    uint32 fl_CrcLength_u32 = Crc_Length;
    #if (CRC_32P4_MODE == CRC_32P4_TABLE)
    uint32 DataPtrAddr_u16 = 0;
    #endif
    #if (CRC_32_MODE == CRC_32P4_RUNTIME)
    uint32 Crc_DataPtrAddr = 0;
    uint8 Crc_LoopCounter = 0;
    #endif

    if( TRUE == Crc_IsFirstCall )
    {
        Crc_Value32 = CRC_INITIAL_VALUE32;
    }
    else
    {
        Crc_Value32 = (CRC_FINAL_XOR_CRC32 ^ Crc_StartValue32);
    }
    #if (CRC_32P4_MODE == CRC_32P4_TABLE)
	if (NULL_PTR != Crc_DataPtr)
	{
       for(DataPtrAddr_u16 = 0; DataPtrAddr_u16<fl_CrcLength_u32; DataPtrAddr_u16 ++)
      {
			Crc_Value32 ^= CRC_UINT8_VALUE & (uint32) Crc_DataPtr[DataPtrAddr_u16];
			Crc_Value32 = ( Crc_Value32 >> 8 ) ^ ( Crc_Table32bitP4 [ (uint8)(Crc_Value32 )]);
      }			
		}
    
#endif
#if (CRC_32_MODE == CRC_32P4_RUNTIME)
if (NULL_PTR != Crc_DataPtr)
	{
for (Crc_DataPtrAddr = 0; Crc_DataPtrAddr < Crc_Length; Crc_DataPtrAddr++)
  {

    
    Crc_Value32 ^= 0xFFuL & (uint32) Crc_DataPtr[Crc_DataPtrAddr];

    
    for (Crc_LoopCounter = 0; Crc_LoopCounter < 8; Crc_LoopCounter++)
    {
      
      if ( (Crc_Value32 & 1u) > 0 )
      {
        Crc_Value32 = ( Crc_Value32 >> 1u ) ^ CRC_POLYNOMIAL_32P4_REFLECT;
      }
      else
      {
        Crc_Value32 = Crc_Value32 >> 1u;
      }
    }
  }
	}
    #endif
    Crc_Value32 = CRC_FINAL_XOR_CRC32 ^ Crc_Value32;
#endif /* CRC_CALCULATE_CRC32P4_ENABLE */
    return Crc_Value32;
}

/*============================================================================
**
** Function Name    :   Crc_CalculateCRC64
**
** Visibility       :   Public
**
** Description      :   This service makes a CRC64 calculation on Crc_Length data bytes, 
**                      using the polynomial 0x42F0E1EBA9EA3693.
**
** Invocation       :   Whoever wants to calculate the 64 bit CRC with 0x42F0E1EBA9EA3693 polynomial CRC.
**
** Inputs           :   Crc_DataPtr: Pointer to the data for which the CRC to be calculated
**                      Crc_Length: Number of bytes to be taken for calculation.
**                      Crc_StartValue64: CRC Start value, if this is a continuation of 
**                                       previous CRC calculation. Crc_IsFirstCall shall be 
**                                       FALSE for this to be considered.
**                      Crc_IsFirstCall: TRUE if this is the first call for CRC calculation. Start Value will be  0xFFFFFFFFFFFFFFFFh.
**                                       FALSE if this is a continuation of precious CRC calculation.
**
** Outputs          :   Calculated 64 bit CRC value
**
** Critical Section :   NA
**
**==========================================================================*/
uint64 Crc_CalculateCRC64(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint64 Crc_StartValue64, boolean Crc_IsFirstCall)
{
    uint64 Crc_Value64 = 0;
#if (CRC_CALCULATE_CRC64_ENABLE == STD_ON)
    #if (CRC_64_MODE == CRC_64_TABLE)  
    uint8 Crc_TableIndex = 0;
    uint32 Crc_DataCount = 0;
    #endif
    #if (CRC_64_MODE == CRC_64_RUNTIME) 
    uint32 index = 0;
    uint8 Crc_LoopCounter = 0;
    #endif

    if( FALSE != Crc_IsFirstCall ) 
    {
        Crc_Value64 = CRC_INITIAL_VALUE64;
    }
    else
    {
        Crc_Value64 = Crc_StartValue64 ^ CRC_FINAL_XOR_CRC64;
    }
   #if (CRC_64_MODE == CRC_64_TABLE)
    if (NULL_PTR != Crc_DataPtr)
    {

        for(Crc_DataCount=0; Crc_DataCount<Crc_Length; Crc_DataCount++)
        {
            Crc_Value64 = Crc_Value64 ^ Crc_DataPtr[Crc_DataCount];
            /*Calculate the CRC64 table index value*/
            Crc_TableIndex = ((uint8)( Crc_Value64 & CRC_UINT8_VALUE));
            /*shift the index out*/
            Crc_Value64 = ( Crc_Value64 >> CRC_BYTELENGTH_U ) ^ Crc_Table64bit[ Crc_TableIndex ];
        }
    }
        #endif

#if (CRC_64_MODE == CRC_64_RUNTIME)
if (NULL_PTR != Crc_DataPtr)
    {
        for (index = 0; index < Crc_Length; index++) 
  {

   
    Crc_Value64 ^= 0xFFuLL & (uint64) Crc_DataPtr[index];

    
    for (Crc_LoopCounter = 0; Crc_LoopCounter < 8; Crc_LoopCounter++)
    {
      
      if ( (Crc_Value64 & 1uL) > 0 )
      {
        Crc_Value64 = ( Crc_Value64 >> 1uL ) ^ CRC_POLYNOMIAL_64_REFLECT;
      }
      else
      {
        Crc_Value64 = Crc_Value64 >> 1uL;
      }
    }
  }

    }
    #endif
    Crc_Value64 = CRC_FINAL_XOR_CRC64 ^ Crc_Value64;
#endif /* uint64 Crc_Value64 = 0; */
    return Crc_Value64;
}

/*============================================================================
**
** Function Name    :   Crc_GetVersionInfo
**
** Visibility       :   Public
**
** Description      :   Provide the version information.
**
** Invocation       :   Whoever wants to read version information of component.
**
** Inputs           :   Versioninfo
**
** Outputs          :  Void
**
** Critical Section :   NA
**
**==========================================================================*/
#if (CRC_VERSION_INFO_API==STD_ON)
	/*MISRA RULE 4.9 VIOLATION and MISRA RULE 8.7 VIOLATION: As per the autosar standard the function is defined ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
void Crc_GetVersionInfo (Std_VersionInfoType * Versioninfo)
{
  if (Versioninfo != NULL_PTR)
  {
    Versioninfo->vendorID = CRC_VENDOR_ID;
    Versioninfo->moduleID = CRC_MODULE_ID; 
    Versioninfo->sw_major_version = CRC_SW_MAJOR_VERSION; 
    Versioninfo->sw_minor_version = CRC_SW_MINOR_VERSION;
    Versioninfo->sw_patch_version = CRC_SW_PATCH_VERSION;
  }
}
#endif
/*MISRA RULE 2.5 VIOLATION: Macro is used to indicate the end of coding section ; This is the reason why the MISRA
                     rule could not be followed in this special case*/

#define CRCLIB_CODE_SEC_END
/*MISRA RULE 20.1 VIOLATION: program should be used after all the #include directives are done ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
#include "Crc_MemMap.h"
#endif
/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 30-Aug-2016
CDSID              : ssebast1
Traceability       : RTC #674918
Change Description : Initial Framework version of CRC
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 04-NOV-2019
CDSID              : snaray12
Traceability       : RTC #641186
Change Description : MISRA Warning fix CRC
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 07-NOV-2019
CDSID              : snaray12
Traceability       : RTC #649992
Change Description : MISRA Warning fix CRC
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 15-NOV-2019
CDSID              : snaray12
Traceability       : RTC #649992
Change Description : PR Defects for MISRA Warning fixed
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 19-May-2020
CDSID              : bbaskara
Traceability       : RTC #883468
Change Description : Updated Source file as per SSR
-----------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------
Date              : 27/March/2022
By                : gthanapp
Traceability      : RTC #1564070
Change Description: Cert-C warning analysis and fix
----------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 10-May-2022
CDSID              : dbalasub
Traceability       : RTC #1652961
Change Description : Coverity & MISRA warning analysis and fix
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 23-May-2022
CDSID              : eganesan
Traceability       : RTC #1668701
Change Description : Bsw General Requirement supported
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/



