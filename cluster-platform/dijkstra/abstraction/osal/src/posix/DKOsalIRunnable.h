/**********************************************************************************
 **
 **  \file IRunnable.h
 **
 **  Created on: Apr 18, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                                              |
 **  |------------|----------|--------------------------------                          |
 **  | 2017-04-18 | VMUTHUSU | Create Initial Module.
 **  | 2023-09-20 | damudhar | Added Doxygen document
 **
 ** \copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **********************************************************************************/
/**********************************************************************************************************************
 *  HEADER FILE GUARD
 *********************************************************************************************************************/
#ifndef DKOSALIRUNNABLE_H_
#define DKOSALIRUNNABLE_H_

namespace dk
{

namespace osal
{
/*!
* \class    IRunnable
* \brief    pure virtual function run() Child class inheriting the IRunnable should implement the method run() 
*/
class IRunnable
{
    public:
        /* coverity[misra_cpp_2008_rule_7_1_2_violation] : FALSE */
        virtual void *run() = 0;
};

} /* namespace osal */

} /* namespace dk */

#endif /* IRUNNABLE_H_ */
