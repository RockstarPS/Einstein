/********************************************************************************************************************
|    File Name: CanNm_Types.h
|
|  Description: This header provides declaration of types of Can AUTOSAR NM module .
|--------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|--------------------------------------------------------------------------------------------------------------------
| Copyright (c) 2019 by Visteon Corporation.       All rights reserved.
|
| NOTICE: This is an unpublished work of authorship, which contains trade secrets.
| Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
| its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
| or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
| in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
| under all copyright laws to protect this work as a published work, when appropriate.
| Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
| without the written authorization of Visteon Corporation.
|--------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|--------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| MA            Muthu Alexander          Visteon Corporation
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2019-12-05  00.00.01  MA     Initial Version
|*******************************************************************************************************************/
#ifndef CANNM_TYPES_H
#define CANNM_TYPES_H

/*!
 *  @brief  This type contains the implementation-specific post build configuration structure of CanNm . 
            Dummy config is used as post build not supported
 */
typedef struct
{
    uint8 Dummy;
}CanNm_ConfigType;
#endif /* CANNM_TYPES_H */
