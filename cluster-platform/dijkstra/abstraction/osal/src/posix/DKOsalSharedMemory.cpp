/**********************************************************************************
 **
 **  \file SharedMemory.cpp
 **
 **  Created on: May 15, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                                           
 **  |------------|----------|--------------------------------                          
 **  | 2017-05-15 | VMUTHUSU | Create Initial Module.
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
 **********************************************************************************************************************/
#ifndef _WIN32
/* Related Header file */
/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "DKOsalSharedMemory.h"
/* C Library includes */
#include <unistd.h>                     /* for ftruncate,close() inclusion for linux build */
#include <fcntl.h>                      /* for O_RDWR, O_CREAT inclusions */
#include <sys/stat.h>                   /* for fstat() inclusion linux build */
#include <sys/mman.h>                   /* for mmap,munmap,shm_unlink,shm_open inclusion */
/* C++ Library includes */
#include <cstring>                      /* for string related functions */
#include <cerrno>                       /* for errno such as EBUSY, ETIMEDOUT */
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

/******************************************************************************************* 
START OF PUBLIC MEMBER FUNCTIONS 
**********************************************************************************************/
/** 
 * \fn      SharedMemory()
 * \brief   Default Constructor
 * \details requirement ID 751539
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
SharedMemory::SharedMemory()
    :
    m_fd ( -1 )
    ,
    m_addr ( NULL )
    ,
    m_size ( 0U )
{
    OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory::SharedMemory() default constructor (this = %p)\n", this );

}

/** 
 * \fn      ~SharedMemory()
 * \brief   Default Destructor
 * \details requirement ID 751539
 */
SharedMemory::~SharedMemory()
{
    OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory::~SharedMemory() destructor (this = %p)\n", this );

    if ( NULL != m_addr )
    {
        close();
    }
}

/**
 * \fn      create ( const char *name, const uint32_t size )  
 * \brief   Create or Open an existing shared memory block.
 * \param   name Global identifier for shm block. name can be upto
 *          NAME_MAX (255) characters long.
 * Under QNX:
 *            The name is interpreted as follows:
 *            <table>
 *            <tr><td> "entry"         </td><td> "$CWD/entry"        </td></tr>
 *            <tr><td> "/entry"        </td><td> "/dev/shmem/entry"  </td></tr>
 *            <tr><td> "entry/entry2"  </td><td> "$CWD/entry/entry2" </td></tr>
 *            <tr><td> "/entry/entry2" </td><td> "/entry/entry2"     </td></tr>
 *            </table>
 *          For portable use, you should use the form "/entry".
 * \param   size size of the shm block.
 * \return  Error code.
 * \details tequirement id 751593
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
Error SharedMemory::create ( const char *const name, const uint32_t size )
{
    OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory::create(\"%s\",%lu) (this = %p)\n", name, size, this );
    return createOrOpen ( name, size, true );
}

/**
 * \fn      
 * \brief   Open an existing shared memory block.
 *          NOTE: There is a race condition possible here where the process
 *          creating the shared memory block is preempted right after its call
 *          to open(..., O_CREAT, ...) and BEFORE ftruncate has been finished.
 *          The other process calling open() might then see a smaller memory
 *          size than the creator actually is still about to allocate. <br>
 *          NOTE2: On some OSes (e.g. Integrity) it's even worse because ftruncate()
 *          is asynchronous, meaning it will return immediately and the real memory
 *          allocation seems to be done in the background by a kernel task. So here
 *          you don't have any means of avoiding the race condition when two
 *          processes simultaneously call create()/open(). Use open(name, size)
 *          to prevent problems.
 * \param   name Global identifier for shm block.
 * \return  Error code.
 * \details requirement ID 751594
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
Error SharedMemory::open ( const char *const name )
{
    OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory::open(\"%s\") (this = %p)\n", name, this );
    return createOrOpen ( name, 0U, false );
}

/**
 *  \fn      open ( const char *name, uint32_t size )
 *  \brief   Open an existing shared memory block with a defined size.<br>
 *           If the shm block could be opened it will be truncated, because
 *           the creating side might not yet be finished with its ftruncate().
 *           So we do it on both sides to be sure, the shm block has the
 *           correct size. See also http://stackoverflow.com/q/16502767/3519749.
 *  \param   name Global identifier for shm block.
 *  \param   size Size of shm block.
 *  \return  Error code.
 *  \details requirement ID 751594
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
Error SharedMemory::open ( const char *const name, const uint32_t size )
{
    OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory::open(\"%s\",%lu) (this = %p)\n", name, size, this );
    return createOrOpen ( name, size, false );
}


/**
 * \fn      void close()
 * \brief   Closes the mapping of shared memory block.
 * \details requirement ID 751595
 */
void SharedMemory::close()
{
    OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory::close() (this = %p)\n", this );

    if ( NULL != m_addr )
    {
        const int32_t ret = munmap ( m_addr, static_cast<uint64_t>( m_size ));
    	if(ret !=0)
    	{
            /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
    		OSAL_ERR ( OSAL_SCOPE_SHM, "SharedMemory::close() munmap failed, error= %d [%s] \n",ret, strerror ( errno ) );
    	}
        m_addr = NULL;
    }

    m_size = 0U;

    if ( m_fd != -1 )
    {
        (void) ::close ( m_fd );
        m_fd = -1;
    }
}

/**
 * \fn      uint32_t size() const
 * \brief   Get the size of the currently mapped shared memory block.
 * \return  size of the shm block.
 * \details requirement id 751596
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
uint32_t SharedMemory::size() const
{
    OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory()::size() returns %lu (this = %p)\n", m_size, this );
    return m_size;
}

/**
 * \fn      void *pointer() const
 * \brief   Get a pointer to the shared memory block.
 * \return  the pointer
 * \details requirement id 751597
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
void *SharedMemory::pointer() const
{
    OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory()::pointer() returns %p (this = %p)\n", m_addr, this );
    /* coverity[misra_cpp_2008_rule_9_3_2_violation] : FALSE */
    /* coverity[misra_cpp_2008_rule_9_3_1_violation] : FALSE */
    return m_addr;
}

/**
 * \fn      static Error remove ( const char *const name )  
 * \brief   Remove (unlink) the name of the shared memory block.
 * \param   name Global identifier for shm block.
 * \return  Error code.
 * \details requirement id 751598
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
/* coverity[cert_dcl51_cpp_violation] : FALSE */
Error SharedMemory::remove ( const char *const name )
{
    Error retValue = OK;
    OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory::remove(\"%s\")\n", name );

    if ( shm_unlink ( name ) == -1 )
    {
        /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
        if ( errno == ENOENT )
        {
            retValue = OBJECT_NOT_FOUND;
        }
        else
        {
            retValue = FAILED;
        }
    }

    return retValue;
}

/* END OF PUBLIC MEMBER FUNCTIONS */

/* START OF PRIVATE MEMBER FUNCTIONS */

/**
 * \fn      Error createOrOpen ( const char *name, uint32_t size, bool doCreate )
 * \brief   Helper method during the real work. Creates or Opens a shared memory
 *          region depending on doCreate.
 * \param   name global identifier for shm block.
 * \param   size size of the shm block. For doCreate=false this can be 0.
 *          however you might run into race condition then (see description
 *          of open() )
 * \param   doCreate true for creating the shm object, false for just opening it.
 * \return  Error Code.
 * \details requirement id 751593,751594
 */
Error SharedMemory::createOrOpen ( const char *const name, uint32_t size, const bool doCreate )
{
    OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory::%s(\"%s\") (this= %p, size= %lu)\n",
            doCreate ? "create" : "open", name, this, size );

    // close an already existing mapping
    if ( NULL != m_addr )
    {
        close();
    }

    /* coverity[misra_cpp_2008_rule_5_0_21_violation] : FALSE */
    const int32_t flags = doCreate ? static_cast<int32_t>( O_RDWR | O_CREAT ) : static_cast<int32_t>( O_RDWR );

    // create / open the memory object
    /* coverity[misra_cpp_2008_rule_2_13_2_violation] : FALSE */
    m_fd = ::shm_open ( name, flags, 0777U );

    if ( m_fd == -1 )
    {
        /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
        if ( errno == ENOENT )
        {
            /* coverity[misra_cpp_2008_rule_6_6_5_violation] : FALSE */
            // object to be opened not there yet (can not happen with O_CREAT)
            CIA_RETURN ( OBJECT_NOT_FOUND );
        }

        OSAL_WARN ( OSAL_SCOPE_SHM, "SharedMemory::%s() shm_open() failed, error= %d [%s] (this= %p)\n",
                doCreate ? "create" : "open", errno, strerror ( errno ), this );
        /* coverity[misra_cpp_2008_rule_6_6_5_violation] : FALSE */
        CIA_RETURN ( FAILED );
    }

    if ( ( !doCreate ) && ( size == 0U ) )
    {
        // no size specified, get it
        OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory::open() fstat (this= %p)\n", this );

        struct stat sb;
        const int32_t ret = ::fstat ( m_fd, &sb );

        if ( ret == -1 )
        {
            OSAL_ERR ( OSAL_SCOPE_SHM, "SharedMemory::open() fstat failed, error= %d [%s] (this= %p)\n",
                    errno, strerror ( errno ), this );
            close();
            /* coverity[misra_cpp_2008_rule_6_6_5_violation] : FALSE */
            CIA_RETURN ( FAILED );
        }

        m_size = static_cast<uint32_t>( sb.st_size );

        if ( m_size == 0U )
        {
            // file not yet truncated on server side
            close();
            /* coverity[misra_cpp_2008_rule_6_6_5_violation] : FALSE */
            CIA_RETURN ( OBJECT_NOT_FOUND );
        }
    }
    else
    {
        // size must be a multiple of the page size, so round up the given value
        size = ( ( ( size + SHM_PAGE_SIZE ) - 1U ) / SHM_PAGE_SIZE ) * SHM_PAGE_SIZE;

        // Set the specified size. This ftruncate() on client side is needed, because
        // the server might not yet be finished with its own call to ftruncate().
        OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory::%s() ftruncate (this= %p, size= %lu)\n",
                doCreate ? "create" : "open", this, size );

        const int32_t ret = ::ftruncate ( m_fd, static_cast<int64_t>( size ));

        if ( ret == -1 )
        {
            OSAL_ERR ( OSAL_SCOPE_SHM,
                    "SharedMemory::%s() ftruncate() failed, error= %d [%s] (this= %p, size= %d)\n",
                    doCreate ? "create" : "open", errno, strerror ( errno ), this, size );
            close();
            /* coverity[misra_cpp_2008_rule_6_6_5_violation] : FALSE */
            CIA_RETURN ( FAILED );
        }

        m_size = size;
    }

    // map memory object
    OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory::%s() mmap (this= %p, size= %lu)\n",
            doCreate ? "create" : "open", this, size );

    /* coverity[misra_cpp_2008_rule_5_2_8_violation] : FALSE */
    /* coverity[misra_cpp_2008_rule_5_0_21_violation] : FALSE */
    m_addr = static_cast<char *> ( ::mmap ( NULL, static_cast<uint64_t>( m_size ), PROT_READ | PROT_WRITE, MAP_SHARED, m_fd, 0 ) );

    /* coverity[misra_cpp_2008_rule_5_2_4_violation] : FALSE */
    /* coverity[misra_cpp_2008_rule_5_2_9_violation] : FALSE */
    if ( m_addr == MAP_FAILED )
    {
        OSAL_ERR ( OSAL_SCOPE_SHM, "SharedMemory::%s() mmap() failed, error= %d [%s] (this= %p)\n",
                doCreate ? "create" : "open", errno, strerror ( errno ), this );
        m_addr = NULL;
        close();
        /* coverity[misra_cpp_2008_rule_6_6_5_violation] : FALSE */
        CIA_RETURN ( FAILED );
    }

    OSAL_DBG ( OSAL_SCOPE_SHM, "SharedMemory::%s(): shm block: %p - %p (%lu bytes / %lu pages) (this= %p)\n",
            doCreate ? "create" : "open", m_addr, m_addr + m_size, m_size, ( ( m_size + 4095 ) / 4096 ),
            this );
    /* coverity[misra_cpp_2008_rule_6_6_5_violation] : FALSE */
    /* coverity[extra_return] : FALSE */
    CIA_RETURN_OK;
}

/* END OF PRIVATE MENBER FUNCTIONS   */

} /* namespace osal */

} /* namespace dk */
#endif
