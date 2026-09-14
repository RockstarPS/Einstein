#include <stdio.h>

#include "Std_Types.h"

#include "Nvm_Writer.h"
#include "FLS_Simulator.h"
#include "Rte_Type.h"
// #include "SrecMake.h"
#include "Mem_Cfg.h"
#include "Nvm_BlockLengthCalc.h"
#include "Srec_Gen_Cfg.h"



int main()
{
   
      printf("Running generator...\n");
      FLASH_Simulator_Init();
      BlockLengthCalc_Init();
      Calc_BlockLength();
      BlockLengthCalc_Close();
      init_main();
      printf("Success\n");
   return 0;
}
