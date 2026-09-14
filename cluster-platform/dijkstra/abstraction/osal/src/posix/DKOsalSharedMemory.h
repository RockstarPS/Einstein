/**********************************************************************************
 **
 **  \file SharedMemory.h
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
#ifndef SRC_DKOSALSHAREDMEMORY_H_
#define SRC_DKOSALSHAREDMEMORY_H_

/**********************************************************************************************************************
 * INCLUDE
 **********************************************************************************************************************/ 
#include <cstdint>                /* standard datatype inclusion   */

/*!
 * \include      DKOsalErrorTypes.h
 *               header_files Dependancy_headers
 * \brief        For inclusion of our own Error data type
 * \addtogroup   header_files
 */
#include "DKOsalErrorTypes.h"           /*  */

namespace dk
{

namespace osal
{

/* coverity[misra_cpp_2008_rule_3_4_1_violation] : FALSE */
const uint32_t SHM_PAGE_SIZE = 4096U;

class SharedMemory
{
    public:

        /** 
         * \fn      SharedMemory()
         * \brief   Default Constructor
         * \details requirement ID 751539
         */
        SharedMemory();

        /** 
         * \fn      ~SharedMemory()
         * \brief   Default Destructor
         * \details requirement ID 751539
         */
        ~SharedMemory();

        /**
         * \fn      create ( const char *const name, const uint32_t size )  
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
        Error create ( const char *const name, const uint32_t size );

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
        Error open ( const char *const name );

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
        Error open ( const char *const name, const uint32_t size );

        /**
         * \fn      void close()
         * \brief   Closes the mapping of shared memory block.
         * \details requirement ID 751595
         */
        void close();

        /**
         * \fn      uint32_t size() const
         * \brief   Get the size of the currently mapped shared memory block.
         * \return  size of the shm block.
         * \details requirement id 751596
         */
        uint32_t size() const;

        /**
         * \fn      void *pointer() const
         * \brief   Get a pointer to the shared memory block.
         * \return  the pointer
         * \details requirement id 751597
         */
        void *pointer() const;

        /**
         * \fn      static Error remove ( const char *const name )  
         * \brief   Remove (unlink) the name of the shared memory block.
         * \param   name Global identifier for shm block.
         * \return  Error code.
         * \details requirement id 751598
         */
        /* coverity[cert_dcl51_cpp_violation] : FALSE */
        static Error remove ( const char *const name );

    private:

        /**
         * \fn      Error createOrOpen ( const char *const name, uint32_t size, const bool doCreate )
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
        Error createOrOpen ( const char *const name, uint32_t size, const bool doCreate );

        /**
         * \fn    SharedMemory ( const SharedMemory & )
         * \brief Disable Copy Constructor
         */
        SharedMemory ( const SharedMemory & ) = delete;

        /**
         * \fn    SharedMemory &operator= ( const SharedMemory & )
         * \brief Disable assignment operator
         */
        SharedMemory &operator= ( const SharedMemory & ) = delete;

        int32_t m_fd;
        char *m_addr;
        uint32_t m_size;

};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALSHAREDMEMORY_H_ */
