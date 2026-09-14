#ifndef OS_STUBS_C
#define OS_STUBS_C


#include "sdl_ecc.h"

#define SDL_EXCEPTION_SYNC_PARITY_OR_ECC_ERROR_MASK 		                0x409u
#define SDL_EXCEPTION_ASYNC_PARITY_OR_ECC_ERROR_MASK 		                0x408u

void osDataAbortHandlerInternal (void);
extern void osDataAbortHandler (void);

void osDataAbortHandlerInternal (void)
{
  uint32_t dfsrValue;
  uint32_t cp15_value;
#ifndef SIMULATION_BUILD
  __asm__ volatile ( "mrc p15, #0, r0, c5, c0, #0 \n"
        "mov %[variable], %[dest_reg] \n"
        : [variable] "=r" (dfsrValue), [dest_reg] "=&r" (cp15_value) // Output operands
    );

    if(((dfsrValue & SDL_EXCEPTION_SYNC_PARITY_OR_ECC_ERROR_MASK)
                  == SDL_EXCEPTION_SYNC_PARITY_OR_ECC_ERROR_MASK) || 
      ((dfsrValue & SDL_EXCEPTION_ASYNC_PARITY_OR_ECC_ERROR_MASK)
                  == SDL_EXCEPTION_ASYNC_PARITY_OR_ECC_ERROR_MASK))
      {
          __asm__ volatile( "sub    lr,lr,#4 \n"   /* push to caller stack */
            "srsfd  sp!, #31 \n"
            "cps    #31 \n"
            "rfeia   sp! \n"
        );
      }
      else
      {
        osDataAbortHandler();
      }
#endif
}
#endif /* OS_STUBS_C */

