/**********************************************************************************
 **
 **  \file OsalConfig.cpp
 **
 **  Created on: may 12, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                                              |
 **  |------------|----------|--------------------------------                          |
 **  | 2017-05-12 | VMUTHUSU | Create Initial Module.
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
 *  INCLUDES
 *********************************************************************************************************************/
/* Related Header file */
#include "DKOsalConfig.h"

/*!
 * \include      cstring
 * C Library includes 
 * C++ Library includes
 * \brief        For string related functions
 */
#include <cstring>
/*!
 * \include      DKOsalMutexLock.h
 *  other library includes 
 *  project includes 
 * \brief        access to SYNCHRONIZED macro
 */
#include "DKOsalMutexLock.h" 
/*!
 * \include      DKOsalTrace.h
 *  other library includes 
 *  project includes 
 * \brief        For OSAL_DBG inclusion
 */
#include "DKOsalTrace.h"

namespace dk
{

namespace osal
{

/*!
 * \fn      static const OSAL_THREAD_CONFIG s_DefaultConfig[] =
 * \brief   OsalConfig shall abstract thread configuration and posix functions provided by OS
 * \details Requirement ID 751532
 */
static const OSAL_THREAD_CONFIG s_DefaultConfig[] =
{
    { THREAD_DEFAULT, OSAL_PRIO_DEFAULT, OSAL_STACKSIZE_DEFAULT },
};

static uint32_t s_ThreadConfigTblSize = 0U;
/* coverity[misra_cpp_2008_rule_4_10_2_violation] : FALSE */
static const OSAL_THREAD_CONFIG *s_ThreadConfigTbl = NULL;

/*************************************************************************************************** 
START OF PUBLIC MEMBER FUNCTIONS 
***************************************************************************************************/

/** 
 * \fn       OsalConfig()
 * \brief    Destructor of osalconfig
 */
OsalConfig::OsalConfig()
    :
    mMutex()
{
    OSAL_DBG ( OSAL_SCOPE_CONFIG, "OsalConfig::OsalConfig() Constructor (this = %p)\n", this );

}

/** 
 * \fn       ~OsalConfig()
 * \brief    Destructor of osalconfig
 */
OsalConfig::~OsalConfig()
{
    OSAL_DBG ( OSAL_SCOPE_CONFIG, "OsalConfig::~OsalConfig() destructor (this = %p)\n", this );
}

/** 
 * \fn      OsalConfig &OsalConfig::getInstance()
 * \brief   function to get instance of OsalConfig
 * \return  reference to OsalConfig.
 * \details Requirement ID 751552
 */
OsalConfig &OsalConfig::getInstance()
{
    static OsalConfig s_ConfigSingleTon;
    OSAL_DBG ( OSAL_SCOPE_CONFIG, "OsalConfig::getInstance() returns %p\n", &s_ConfigSingleTon );
    return s_ConfigSingleTon;
}
/** 
 * \fn    void OsalConfig::setDefaultThreadConfigTable()
 * \brief To set a default thread configuration table.
 */
void OsalConfig::setDefaultThreadConfigTable()
{
    OSAL_DBG ( OSAL_SCOPE_CONFIG, "OsalConfig::setDefaultThreadConfigTable() (this = %p)\n", this );
    /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
    SYNCHRONIZED ( mMutex )
    {
        s_ThreadConfigTbl = NULL;
        s_ThreadConfigTblSize = 0U;
    }
}
/* **sets a user provided thread configuration table** */
/** 
 * \fn      bool OsalConfig::setThreadConfigTable ( const OSAL_THREAD_CONFIG configTbl[], uint32_t size )
 * \brief   This should be called from main() before threads are created.
 * \param   configTbl a fixed array of OSAL_THREAD_CONFIG entries.
 *          The array must not be modified after this call, since OsalConfig
 *          accessess it per pointers.
 * \param   size the number of entries in the configTbl[] array
 * \return  true on sucess.
 * \details Requirement ID 751552
 */
/* coverity[misra_cpp_2008_rule_7_1_1_violation] : FALSE */
bool OsalConfig::setThreadConfigTable ( const OSAL_THREAD_CONFIG configTbl[], const uint32_t size )
{
    OSAL_DBG ( OSAL_SCOPE_CONFIG, "OsalConfig::setThreadConfigTable(%p , %lu) (this = %p)\n", configTbl, size,
            this );
    bool result = false;

    if ( ( 0U == size ) || ( NULL == configTbl ) )
    {
        OSAL_WARN ( OSAL_SCOPE_CONFIG, "OsalConfig::setThreadConfigTable(): Invalide Arguments (this = %p)\n",
                this );
    }
    else
    {
        /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
        SYNCHRONIZED ( mMutex )
        {
            s_ThreadConfigTblSize = size;
            s_ThreadConfigTbl = &configTbl[0];
        }
        result = true;
    }

    OSAL_DBG ( OSAL_SCOPE_CONFIG,
            "OsalCofig::setThreadConfigTable() returns s_ThreadConfigTbl = %p s_ThreadConfigTblSize = %lu\n",
            s_ThreadConfigTbl, s_ThreadConfigTblSize );
    return result;
}
/** 
 * \fn      bool OsalConfig::getThreadConfig ( const ThreadConfigID id, ThreadPrio &prio, uint32_t &stackSize ) const 
 * \brief   search a thread configuration for the given ID.
 * \param   id the thread id for which the config is searched.
 * \param   prio a reference where the found prio is stored in.
 * \param   stackSize a reference where the found stackSize is stored in.
 * \return  true if a config for the given id was found.
 * \details Requirement ID 751552
 */
bool OsalConfig::getThreadConfig ( const ThreadConfigID id, ThreadPrio &prio, uint32_t &stackSize ) const
{
    bool result;
    result = false;

    OSAL_DBG ( OSAL_SCOPE_CONFIG, "OsalConfig::getThreadConfig(\"%s\", %lu, %lu) (this = %p)\n",
            ( NULL != id ) ? id : "null", prio, stackSize );
    prio = OSAL_PRIO_DEFAULT;
    stackSize = OSAL_STACKSIZE_DEFAULT;

    if ( NULL == id )
    {
        OSAL_WARN ( OSAL_SCOPE_CONFIG, "OsalConfig::getThreadConfig() : Invalid arguments (this = %p)\n", this );
    }
    else
    {
        /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
        SYNCHRONIZED ( mMutex )
        {
            if ( NULL != s_ThreadConfigTbl )
            {
                for ( uint32_t i = 0U; i < s_ThreadConfigTblSize; i++ )
                {
                    /* coverity[misra_cpp_2008_rule_5_0_15_violation] : FALSE */
                    if ( strncmp ( id, s_ThreadConfigTbl[i].ID, 150U ) == 0 )
                    {
                        /* coverity[misra_cpp_2008_rule_5_0_15_violation] : FALSE */
                        prio = s_ThreadConfigTbl[i].Prio;
                        /* coverity[misra_cpp_2008_rule_5_0_15_violation] : FALSE */
                        stackSize = s_ThreadConfigTbl[i].StackSize;
                        result = true;
                        break;
                    }
                }
            }

            if ( result == false )
            {
                for ( uint32_t i = 0U; i < ( sizeof ( s_DefaultConfig ) / sizeof ( s_DefaultConfig[0] ) ); i++ )
                {
                    if ( strncmp ( id, s_DefaultConfig[i].ID, 150U ) == 0 )
                    {
                        prio = s_DefaultConfig[i].Prio;
                        stackSize = s_DefaultConfig[i].StackSize;
                        result = true;
                        break;
                    }
                }
            }
        }
    }

    if ( result == false )
    {
        /* coverity[misra_cpp_2008_rule_4_10_2_violation] : FALSE */
        OSAL_WARN ( OSAL_SCOPE_CONFIG,
                "OsalConfig::getThreadConfig() : No Config for id \"%s\" found, using OS defaults. (this = %p)\n",
                ( NULL != id ) ? id : "null", this );
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_CONFIG,
                "OsalConfig::getThreadConfig() id = %s, prio = %lu, stackSize = %lu (this = %p)\n",
                ( NULL != id ) ? id : "null", prio, stackSize, this );
    }

    return result;
}
 /** 
 * \fn       bool OsalConfig::isPrioReserved ( const ThreadPrio prio ) const 
 * \brief    if a thread configuration exists which uses the given priority value.
 * \param    prio the thread priority
 * \return   true if a config specified this priority.
 * \details  Requirement ID 751552
 */
bool OsalConfig::isPrioReserved ( const ThreadPrio prio ) const
{
    bool result;
    result = false;

    OSAL_DBG ( OSAL_SCOPE_CONFIG, "OsalConfig::isPrioReserved(%lu) (this = %p)\n", this );

    /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
    SYNCHRONIZED ( mMutex )
    {
        const OSAL_THREAD_CONFIG *table;
        uint32_t size;

        if ( NULL != s_ThreadConfigTbl )
        {
            /* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
            table = s_ThreadConfigTbl;
            size = s_ThreadConfigTblSize;
        }
        else
        {
            table = &s_DefaultConfig[0];
            size = sizeof ( s_DefaultConfig ) / sizeof ( s_DefaultConfig[0] );
        }

        for ( uint32_t i = 0U; i < size; i++ )
        {
            /* coverity[misra_cpp_2008_rule_5_0_15_violation] : FALSE */
            if ( table[i].Prio != OSAL_PRIO_DEFAULT )
            {
                /* coverity[misra_cpp_2008_rule_5_0_15_violation] : FALSE */
                if ( table[i].Prio < 0xFFU )
                {
                    /* coverity[misra_cpp_2008_rule_5_0_15_violation] : FALSE */
                    result = ( prio == table[i].Prio );
                }
                else
                {
				    /* The configuration logic is preserved for further usage. */
                    /* coverity[misra_cpp_2008_rule_2_7_3_violation] : FALSE */
                    const uint8_t prio1 = 0U; //OSAL_PRIO_RANGE_P1(table[i].Prio);
                    /* coverity[misra_cpp_2008_rule_2_7_3_violation] : FALSE */
                    const uint8_t prio2 = 0U; //OSAL_PRIO_RANGE_P2(table[i].Prio);

                    if ( prio2 > prio1 )
                    {
                        result = ( ( prio >= prio1 ) && ( prio <= prio2 ) );
                    }
                    else
                    {
                        /* The configuration logic is preserved for further usage. */
                        /* coverity[misra_cpp_2008_rule_0_1_2_violation] : FALSE */
                        /* coverity[dead_error_condition] : FALSE */
                        /* coverity[unsigned_compare] : FALSE */
                        result = ( ( prio <= prio1 ) && ( prio >= prio2 ) );
                    }
                }

                if ( result )
                {
                    break;
                }
            }
        }
    }
    return result;
}

/* END OF PUBLIC MEMBER FUNCTIONS */

} /* namespace osal */

} /* namespace dk */
