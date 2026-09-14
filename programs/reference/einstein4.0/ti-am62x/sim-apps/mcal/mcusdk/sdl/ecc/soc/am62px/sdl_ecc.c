/*
 *  Copyright (C) 2023-2025 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

 #include <string.h>
 #include <stdint.h>
 #include <sdl/include/soc_config.h>
 #include <sdl/sdl_ecc.h>
 #include <sdl/include/sdl_types.h>
 #include <sdl/sdl_esm.h>
 #include <sdl/esm/soc/am62px/sdl_esm_core.h>
 #include <sdl/ecc/soc/am62px/sdl_ecc_soc.h>
 #include <sdl/ecc/sdl_ecc_core.h>
 #include <sdl/ecc/sdl_ecc_priv.h>
 #include <sdl/ecc/V0/sdl_ip_ecc.h>
 #include <sdl/ecc/V0/sdlr_edc_ctl.h>
 #include <sdl/ecc/V0/sdlr_ecc_ram.h>
 #include <sdl/dpl/sdl_dpl.h>

/* Local defines */
#define SDL_ECC_INVALID_ERROR_SOURCE (0xffffffffu)

#define BITS_PER_WORD (32u)

#define ECC_AGGR_LINE_SIZE (4)

#define ECC_AGGR_BASE_SIZE (0x400UL)

#define SDL_ECC_INVALID_SELF_TEST_RAM_ID (0xffffffffu)
#define SDL_ECC_INVALID_CHECKER_TYPE     (0xffu)

SDL_ecc_aggrRegs * SDL_ECC_aggrTransBaseAddressTable[SDL_ECC_MEMTYPE_MAX];

/* Event BitMap for ECC ESM callback for MAIN */
uint32_t eventBitMapMAIN[SDL_ESM_MAX_EVENT_MAP_NUM_WORDS] =
{
  0x77f1bf6eu, 0xffc3e0fcu, 0xef066cfeu, 0x03c0bf00u,
  0x034cf800u, 0x000f3f03u, 0x00000000u, 0x00000000u,
  0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
  0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
  0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
  0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
  0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
  0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
};

/* Event BitMap for ECC ESM callback for WKUP */
uint32_t eventBitMapWKUP[SDL_ESM_MAX_EVENT_MAP_NUM_WORDS] =
{
    0x003fc030u, 0x0000033fu, 0x000000f0u, 0x00000000u,
    0x00000000u, 0x000f0000u, 0x00000000u, 0x00000000u,
    0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
    0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
    0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
    0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
    0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
    0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
};

/** ---------------------------------------------------------------------------
 * @brief This enumerator defines the values for ecc self test flag
 * ----------------------------------------------------------------------------
 */
typedef enum {
    SDL_ECC_ERROR_FLAG_NONE=0,
    /**< Flag set during ECC initialization or end of the ECC self test */
    SDL_ECC_ERROR_FLAG_STARTING=1,
    /**< Flag set at the start of the ECC self test */
    SDL_ECC_ERROR_FLAG_TRIGGERED=2,
    /**< Flag set when ECC error happens during the ECC self test */

} SDL_ECC_ErrorFlag;

/** ---------------------------------------------------------------------------
 * @brief This structure defines the elements of ECC software instance
 * ----------------------------------------------------------------------------
 */

/**
 * Design: PROC_SDL-1295
 */
typedef struct SDL_ECC_Instance_s
{
    SDL_ECC_InitConfig_t eccInitConfig;
    /**< ecc Initial configuration */
    volatile SDL_ECC_ErrorFlag eccErrorFlag;
    /**< Ecc error triggered flag */
    SDL_ECC_InjectErrorType eccSelfTestErrorType;
    /**< Ecc self type error type in progress */
    uint32_t eccSelfTestRamId;
    /**< Ram id used in self test in progress */
    uint32_t *eccSelfTestAddr;
    /**< Address used in self test in progress */
}  SDL_ECC_Instance_t;

/* Global objects */
static SDL_ECC_Instance_t SDL_ECC_instance[SDL_ECC_Base_Address_TOTAL_ENTRIES];
/* Local functions */
static int32_t SDL_ECC_getRamId(SDL_ECC_MemType eccMemType, SDL_ECC_MemSubType memSubType,
                           uint32_t *ramIdP, uint32_t *pRAMIdType);
static int32_t SDL_ECC_getAggregatorType(SDL_ECC_MemType eccMemType,
                           SDL_ECC_MemSubType memSubType, uint32_t *pIinjectOnly);
static int32_t SDL_ECC_getAggrBaseAddr(SDL_ECC_MemType eccMemType, SDL_ecc_aggrRegs **pEccAggr);
static int32_t SDL_ECC_memoryRefresh(uint32_t *memAddr, size_t size);
static void SDL_ECC_triggerAccessForEcc(const uint32_t *memoryAccessAddr);

static int32_t SDL_ECC_getMemConfig(SDL_ECC_MemType eccMemType, SDL_ECC_MemSubType memSubType,
                               SDL_MemConfig_t *memConfig);
static int32_t SDL_ECC_getEDCCheckerGroupConfig(SDL_ECC_MemType eccMemType,
                                                   SDL_ECC_MemSubType memSubType,
                                                   uint32_t chkGrp,
                                                   SDL_GrpChkConfig_t *grpChkConfig);
static uint32_t SDL_ECC_getDetectErrorSource (SDL_ECC_InjectErrorType injectErorType);
static int32_t SDL_ECC_getBitLocation(uint32_t bitMask,
                            uint32_t startBitLocation,
                            uint32_t *bitLocation);
static int32_t SDL_ECC_handleEccAggrEvent (SDL_ECC_MemType eccMemType, uint32_t errorSrc,
                                       uint32_t errorAddr);
static int32_t SDL_ECC_ESMCallBackFunction_WKUP (SDL_ESM_Inst instance, SDL_ESM_IntType intrType,
                                             uint32_t grpChannel, uint32_t index, uint32_t intSrc,
                                             void *arg);

static int32_t SDL_ECC_ESMCallBackFunction_MAIN (SDL_ESM_Inst instance, SDL_ESM_IntType intrType,
                                             uint32_t grpChannel, uint32_t index, uint32_t intSrc,
                                             void *arg);

static int32_t SDL_ECC_checkMemoryType(SDL_ECC_MemType eccMemType, SDL_ECC_MemSubType memSubType);

static int32_t SDL_ECC_searchMemEntryTable(SDL_ECC_MemSubType memSubType,
                                              const SDL_MemConfig_t memEntryTable[],
                                              uint32_t tableSize,
                                              SDL_MemConfig_t *pMemConfig);

/** ============================================================================*
 *
 * \brief   Get the Error Source corresponding to the inject error
 *          type
 *
 *   @n  This function is called in ECC callback function to convert the injected
 *       error type to the source of the ECC error
 *
 * \param1  errorType: error Type
 *
 * \return  error Source or SDL_ECC_INVALID_ERROR_SOURCE in case of error
 */
static uint32_t SDL_ECC_getDetectErrorSource (SDL_ECC_InjectErrorType injectErorType)
{
    uint32_t errorSource;

    return errorSource;
}

/* Returns index >= 0 if successful, otherwise returns -1 if failure */ //
static int32_t SDL_ECC_mapRatEccAggrBaseAddress(SDL_ecc_aggrRegs * const eccAggrAddr, int32_t desiredMapIdx, SDL_ecc_aggrRegs **ppEccAggr)
{
    int32_t mappedIdx = -1;


    return (mappedIdx);
}

/** ============================================================================*
 *
 * \brief   Map an ECC Aggregator using the RAT
 *
 *   @n  This function is called prior to SDL_ECC_init() for an ECC aggregator
 *   where the base address of the ECC Aggegator is greater than 32-bits, so
 *   needs a mapping by the RAT.
 *
 * \param1  errorType: error Type
 *
 * \return  error Source or SDL_ECC_INVALID_ERROR_SOURCE in case of error
 */
/* Returns index >= 0 if successful, otherwise returns -1 if failure */
static int32_t SDL_ECC_mapEccAggrReg(SDL_ECC_MemType eccMemType, SDL_ecc_aggrRegs **ppEccAggr)
{
    int32_t retVal = SDL_PASS;


    return retVal;
}

/** ============================================================================*
 *
 * \brief   Ecc call back function registered with exception handler
 *
 * \param1  eccMemType: ECC Memory Type
 * \param2  errorSrc: Source of ECC Error
 * \param3  errorAddr: ECC error address
 *
 * \return  None
 */
static int32_t SDL_ECC_handleEccAggrEvent (SDL_ECC_MemType eccMemType, uint32_t errorSrc,
                                           uint32_t errorAddr)
{

    int32_t handledResult = 0;

    return handledResult;
}

/** ============================================================================*
 *
 * \brief   Ecc call back function registered with exception handler
 *          Certain ECC events on CPU memory are reported as Exception events
 *          And this function provides a way to intercept the event to do self test
 *
 * \param1  errorSrc: source of the ECC error reported.
 * \param2  errorAddr: Error address at which the actual error happened
 * \param3  ramId: ramId at which the actual error happened
 * \param4  bitErrorOffset: offset within the ramId that the bit error occurred
 *          For SEC errors, this contains the exact bit location for the single
 *          corrected error.  For DED Wrapper errors, this contains the bit location
 *          of the start of the row where the double error occurred.  For DED
 *          Interconnect errors, this field is invalid and set to 0.
 * \param5  bitErrorGroup: group checker that reported the error
 *          (Interconnect ECC type only).
 *
 * \return  None
 */
static void SDL_ECC_callBackFunction (uint32_t errorSrc, uint32_t errorAddr,
                                      uint32_t ramId, uint64_t bitErrorOffset,
                                      uint32_t bitErrorGroup)
{



}

/** ============================================================================
 *
 * \brief   Handle any event that needs to be handled locally before
 *          reporting to application
 *
 * \param1  pInstance: Pointer to ESM instance
 * \param2  intSrc: Source interrupt number
 *
 * \return  true: if event handled; false if not handled
 */
static bool SDL_ECC_getIntSrcErrInfo(SDL_ESM_Inst instance, uint32_t intSrc, uint32_t *errorSrc, uint32_t *errorAddr, uint32_t *eccMemType)
{
    bool handledFlag = ((bool)false);


    return handledFlag;
}

/** ============================================================================
 *
 * \brief   Get the ECC error information from the ESM error information
 *
 * \param1  instance: ESM instance
 * \param2  intSrc: Source interrupt number
 * \param3  eccMemType: Pointer to the ecc mem type
 * \param4  intrSrcType: Pointer to the interrupt source type
 *
 * \return SDL_PASS : Success; SDL_EFAIL for failures
 */
int32_t SDL_ECC_getESMErrorInfo(SDL_ESM_Inst instance, uint32_t intSrc,
                                SDL_ECC_MemType *eccMemType, SDL_Ecc_AggrIntrSrc *intrSrcType)
{
    int32_t retVal = SDL_PASS;


    return retVal;
}

/** ============================================================================*
 *
 * \brief   Ecc call back function registered with WKUP ESM handler
 *
 * \param1  errorSrc: Error source
 *
 * \return  None
 */
static int32_t SDL_ECC_ESMCallBackFunction_WKUP (SDL_ESM_Inst instance, SDL_ESM_IntType intrType,
                                             uint32_t grpChannel, uint32_t index, uint32_t intSrc,
                                             void *arg)
{

    int32_t handledResult = 0;


    return handledResult;
}


/** ============================================================================*
 *
 * \brief   Ecc call back function registered with Main Domain ESM handler
 *
 * \param1  errorSrc: Error source
 *
 * \return  None
 */
static int32_t SDL_ECC_ESMCallBackFunction_MAIN (SDL_ESM_Inst instance, SDL_ESM_IntType intrType,
                                             uint32_t grpChannel, uint32_t index, uint32_t intSrc,
                                             void *arg)
{

    int32_t handledResult = 0;

    return handledResult;
}


/** ============================================================================
 * \brief   Retrieves the error information for a specified ECC aggregator
 *          and interrupt source.
 *
 * \param   eccMemType ECC Mem Type
 * \param   intrSrc: interrupt source type
 * \param   pErrorInfo: pointer to the error information structure
 *
 * \return  SDL_PASS : Success; SDL_EFAIL for failures
 */
/*
 * Design: PROC_SDL-1291,PROC_SDL-1292
 */
int32_t SDL_ECC_getErrorInfo(SDL_ECC_MemType eccMemType, SDL_Ecc_AggrIntrSrc intrSrc, SDL_ECC_ErrorInfo_t *pErrorInfo)
{
    int32_t retVal = SDL_PASS;


    return retVal;
}

/** ============================================================================
 * \brief   Acknowledges the ECC interrupt
 *
 * \param   eccMemType ECC Mem Type
 * \param   intrSrc: interrupt source type
 *
 * \return  SDL_PASS : Success; SDL_EFAIL for failures
 */
int32_t SDL_ECC_ackIntr(SDL_ECC_MemType eccMemType, SDL_Ecc_AggrIntrSrc errorSrc)
{
    int32_t retVal = SDL_PASS;

    return retVal;
}

/** ============================================================================
 * \brief   Clears the pending interrupt
 *
 * \param   eccMemType ECC Mem Type
 * \param   memSubType: ECC mem sub-type
 * \param   intrSrc: interrupt source type
 * \param   subType: EDC sub type (if EDC type)
 * \param   numEvents: number of events to clear
 *
 * \return  SDL_PASS : Success; SDL_EFAIL for failures
 */
/*
 * Design: PROC_SDL-1293,PROC_SDL-1294
 */
int32_t SDL_ECC_clearNIntrPending(SDL_ECC_MemType eccMemType, SDL_ECC_MemSubType memSubType,
                                  SDL_Ecc_AggrIntrSrc intrSrc,
                                  SDL_Ecc_AggrEDCErrorSubType subType, uint32_t numEvents)
{
    int32_t retVal = SDL_PASS;


    return retVal;
}

/** ============================================================================*
 *
 * \brief   Initializes an ESM module for usage with ECC module
 *
 * \param   esmInstType: Instance of ESM
 *
 * \return  SDL_PASS : Success; SDL_EFAIL for failures
 */

/**
 * Design: PROC_SDL-1282,PROC_SDL-1283
 */
int32_t SDL_ECC_initEsm (const SDL_ESM_Inst esmInstType)
{

    return SDL_PASS;
}

/** ============================================================================*
 *
 * \brief   Initializes ECC module for ECC detection
 *
 * \param1 eccAggrInstNumber Instance number of ECC aggregator
 * \param2 pECCInitConfig     Pointer to Ecc init configuration
 *
 * \return  SDL_PASS : Success; SDL_EFAIL for failures
 *          NOTE: On failure the ECC peripheral registers may be initialized
 *          partially.
 */
int32_t SDL_ECC_init (SDL_ECC_MemType eccMemType,
                         const SDL_ECC_InitConfig_t *pECCInitConfig)
{

    int32_t retVal = SDL_PASS;

    return retVal;
}

/** ============================================================================*
 *
 * \brief   Refresh memory to make sure ECC is generated
 *
 *
 * \param1  memAddr: Address to refresh ( Need to aligned to 32 bit)
 * \param2  size: Size of memory region to refresh
 *                Should be multiple of 4
 *
 * \return  SDL_PASS : Success; SDL_EFAIL for failures

 */
static int32_t SDL_ECC_memoryRefresh(uint32_t *memAddr, size_t size)
{

    int32_t result = SDL_PASS;

    return result;
}

/** ============================================================================
 *
 * \brief   Initializes Memory to be ready for ECC error detection.
 *          Assumes ECC is already enabled.
 *
 * \param  eccMemType ECC memory type
 * \param  memSubType: Memory subtype
 *
 * \return  SDL_PASS : Success; SDL_EFAIL for failures
 */

/**
 * Design: PROC_SDL-1284,PROC_SDL-1285
 */
int32_t SDL_ECC_initMemory (SDL_ECC_MemType eccMemType,
                               SDL_ECC_MemSubType memSubType)
{
    int32_t result=SDL_PASS;


    return result;
}

/** ============================================================================
 *
 * \brief   Does access to trigger ECC
 *
 * \param  pMemoryAccessAddr: Memory Access Address
 *
 * @return  None

 */
   /* Read value to trigger ECC error injection */
volatile uint32_t testLocationValue;

static void SDL_ECC_triggerAccessForEcc(const uint32_t *pMemoryAccessAddr)
{

}

/** ============================================================================
 *
 * \brief   Runs self test by injecting and error and monitor response
 *          Assumes ECC is already enabled.
 *
 * \param1  eccMemType ECC memory type
 * \param2  memSubType: Memory subtype
 * \param3  errorType: ECC Self test type
 * \param4  pECCErrorConfig: Memory configuration self test area
 * \param4  selfTestTimeOut: Number of retries before time out
 *
 * \return  SDL_PASS : Success; SDL_EFAIL for failures
 */

/**
 * Design: PROC_SDL-1286,PROC_SDL-1287
 */
int32_t SDL_ECC_selfTest(SDL_ECC_MemType eccMemType,
                                  SDL_ECC_MemSubType memSubType,
                                  SDL_ECC_InjectErrorType errorType,
                                  const SDL_ECC_InjectErrorConfig_t *pECCErrorConfig,
                                  uint32_t selfTestTimeOut)
{
    int32_t retVal = SDL_PASS;

    return retVal;
}

/** ============================================================================
 *
 * \brief   Get bit location in word.
 *
 * \param1  bitMask: Input bitmask
 * \param2  startBitLocation: Bit location to start from
 * \param3  pPbitLocation: Pointer to Next location of 1b found
 *
 * \return  SDL_PASS : Success; SDL_EFAIL for failures
 */
static int32_t SDL_ECC_getBitLocation(uint32_t bitMask,
                                         uint32_t startBitLocation,
                                         uint32_t *pPbitLocation)
{
    int32_t result = SDL_PASS;

    return result;
}

/** ============================================================================
 *
 * \brief   Injects ECC error at specified location
 *          Assumes ECC is already enabled.
 *
 * \param1  memType: Memory type for self test
 * \param2  memSubType: Memory subtype
 * \param3  errorType: ECC error type
 * \param4  pECCErrorConfig: Pointer to Error configuration
 *
 * \return  SDL_PASS : Success; SDL_EFAIL for failures
 */

/**
 * Design: PROC_SDL-1288,PROC_SDL-1289
 */
int32_t SDL_ECC_injectError(SDL_ECC_MemType eccMemType,
                              SDL_ECC_MemSubType memSubType,
                              SDL_ECC_InjectErrorType errorType,
                              const SDL_ECC_InjectErrorConfig_t *pECCErrorConfig)
{

    int32_t retVal = SDL_PASS;


    return retVal;
}

/** ============================================================================
 *
 * \brief   Get Ram Id for given memory and memory subtype
 *
 * \param1  eccMemType: Memory type for self test
 * \param2  memSubType: Memory subtype for self test
 * \param3  pRAMId: pointer to return Ram Id
 * \param4  pRAMIdType: pointer to return Ram Id Type
 *
 * @return  SDL_PASS : Success; SDL_EFAIL for failures
 */
static int32_t SDL_ECC_getRamId(SDL_ECC_MemType eccMemType, SDL_ECC_MemSubType memSubType,
    uint32_t *pRAMId, uint32_t *pRAMIdType)
{
    int32_t retVal = SDL_PASS;


    return retVal;
}

/** ============================================================================
 *
 * \brief   Check ECC check valid memory and memory subtype
 *
 * \param1  eccMemType: Memory type for self test
 * \param2  memSubType: Memory subtype for self test
 *
 * @return  SDL_PASS : Success; SDL_EFAIL for failures
 */
static int32_t SDL_ECC_checkMemoryType(SDL_ECC_MemType eccMemType, SDL_ECC_MemSubType memSubType)
{
    int32_t retVal = SDL_PASS;


    return retVal;
}

/** ============================================================================
 *
 * \brief   Get ECC aggregator type for given memory and memory subtype
 *
 * \param1  eccMemType: Memory type for self test
 * \param2  memSubType: Memory subtype for self test
 * \param3  pInjectOnly: pointer to variable indicating ECC aggregator
 *                       inject only
 *
 * @return  SDL_PASS : Success; SDL_EFAIL for failures
 */
static int32_t SDL_ECC_getAggregatorType(SDL_ECC_MemType eccMemType,
                                            SDL_ECC_MemSubType memSubType,
                                            uint32_t *pIinjectOnly)
{
    int32_t retVal = SDL_PASS;

    return retVal;
}

/** ============================================================================
 *
 * \brief   Get ECC memory configuration for given memory subtype (only valid for
 *          Wrapper RAM ID's).
 *
 * \param1  memSubType: Memory subtype for which we are searching for memory
 *                      configuration
 * \param2  memEntryTable: Memory configuration table for all Wrapper RAM ID's
 *                         for a particular memType (i.e. ECC aggregator).
 * \param3  tableSize: Size of the memory configuration table to search

 * \param4  pMemConfig: pointer to memory configuration structure that will be
 *                      filled upon successful retrieval.
 *
 * @return  SDL_PASS : Success; SDL_EFAIL for failures
 */
static int32_t SDL_ECC_searchMemEntryTable(SDL_ECC_MemSubType memSubType,
                                              const SDL_MemConfig_t memEntryTable[],
                                              uint32_t tableSize,
                                              SDL_MemConfig_t *pMemConfig)
{
    int32_t retVal = SDL_EFAIL;

    return retVal;
}

/** ============================================================================
 *
 * \brief   Get Memory configuration for given memory type  and memory subtype
 *
 * \param1  eccMemType: Memory type for self test
 * \param2  memSubType: Memory subtype for self test
 * \param3  pMemConfig: pointer to return memory configuration
 *
 * \return  SDL_PASS : Success; SDL_EFAIL for failures
 */
static int32_t SDL_ECC_getMemConfig(SDL_ECC_MemType eccMemType, SDL_ECC_MemSubType memSubType,
                              SDL_MemConfig_t *pMemConfig)
{
    int32_t retVal = SDL_PASS;

   return retVal;
}

/** ============================================================================
 *
 * \brief   Get EDC Checker configuration given memory type, memory subtype
 *          and memory subsubtype for Interconnect type only
 *
 * \param1  eccMemType: Memory type for self test
 * \param2  memSubType: Memory subtype for self test
 * \param2  chkGrp:     Checker group for self test
 * \param3  grpChkConfig: pointer to Group checker configuration
 *
 * \return  SDL_PASS : Success; SDL_EFAIL for failures
 */
static int32_t SDL_ECC_getEDCCheckerGroupConfig(SDL_ECC_MemType eccMemType,
                                                   SDL_ECC_MemSubType memSubType,
                                                   uint32_t chkGrp,
                                                   SDL_GrpChkConfig_t *grpChkConfig)
{
    int32_t retVal = SDL_PASS;


    return retVal;
}

/** ============================================================================
 *
 * \brief   Get Ecc Aggregator Base Address for given memory type
 *
 * \param1  eccMemType: Memory type for self test
 * \param2  pEccAggr: pointer to Ecc Aggregator address
 *
 * @return  SDL_PASS : Success; SDL_EFAIL for failures
 */
static int32_t SDL_ECC_getAggrBaseAddr(SDL_ECC_MemType eccMemType, SDL_ecc_aggrRegs **pEccAggr)
{
    int32_t retVal = SDL_PASS;


    return retVal;
}
