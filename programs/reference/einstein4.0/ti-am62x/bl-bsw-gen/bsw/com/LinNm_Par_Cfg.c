

/* ===========================================================================
**
**  Name:           LinNm_Par_Cfg.c
**  Component:      LIN Network Management
**  Module:         LIN
**  Platforms :     This layer is Micro and Hardware agnostic & hence it satisfies the below requirement it
 *                  [SWS_LinNm_00026] ⌈The AUTOSAR LinNm state machine shall be processor independent, which means *                     shall  not rely on any processor specific hardware support and thus shall be realizable on any 
 *                  processor architecture that is in the scope of AUTOSAR. ⌋ ( )
**  Description:    LIN NM project specific configurations definition file
**  =========================================================================*/ 

/* ===========================================================================
** I N C L U D E   F I L E S
** =========================================================================*/
#include "LinNm.h"
#include "LinNm_Par_Cfg.h"


/* ===========================================================================
** G L O B A L   C O N F I G U R A T I O N   C O N S T A N T S
** =========================================================================*/


/*@brief this variable is used to define array index value of LIN Network mode and state buffer
 depen upon the channel request
      Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 to 256
 */
const NetworkHandleType LinNm_SystemToNmChannelInd[LINNM_NUMBER_OF_SYS_CHANNELS] = 
{
  0x00U,
};



/*@brief "LinNm_ConfigType" structure variable "LinNM_Config" and given value for "LinNm_NMstate" and "LinNM_NMmode
      Unit: Not Applicable
      Resolution: Not Applicable
      Range: Not Applicable
 */
LinNm_ConfigType LinNM_Config = {NM_STATE_BUS_SLEEP, NM_MODE_BUS_SLEEP};


/*--------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
---------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 10/Mar/2020
By                : BPANDURA
Traceability      : RTC # 725516, 725520, 725525, 780723, 780719, 780721, 780734.
Change Description: Added value to structure variabel linNM_Config
----------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 15/July/2019
By                : MKANNAN2
Traceability      : RTC # 1351938
Change Description: Initial Version
----------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------
Date              : 26/July/2019
By                : MKANNAN2
Traceability      : RTC # 1351938
Change Description: Removed structure definition "LinNm_GenConfig" and LinNm_ChannelConfig .
----------------------------------------------------------------------------------------------------------------------*/


