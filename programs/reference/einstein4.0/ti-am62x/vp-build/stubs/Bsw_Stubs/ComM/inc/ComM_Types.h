#ifndef COMM_TYPES_H
#define COMM_TYPES_H

 /*NCHELLAP Stub Added to resolve compilation error from EcuM.c*/
/*! @brief Initialization status of ComM. */
typedef enum
{
    /*! @brief The COM Manager is not initialized or not usable. This shall be the default value after reset. 
        This status shall have the value 0. */
    COMM_UNINIT=0U, 
    /*! @brief The COM Manager is initialized and usable. */
    COMM_INIT       
}ComM_InitStatusType;




#endif
