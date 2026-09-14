#if !defined(LINNM_PAR_CFG_H)
#define LINNM_PAR_CFG_H

/* ===========================================================================
**
**  Name:           LinNm_Par_Cfg.h
**  Component:      LIN Network Management
**  Module:         LIN
**  Platforms :     This layer is Micro and Hardware agnostic & hence it satisfies the below requirement it
 *                  [SWS_LinNm_00026] ⌈The AUTOSAR LinNm state machine shall be processor independent, which means *                     shall  not rely on any processor specific hardware support and thus shall be realizable on any 
 *                  processor architecture that is in the scope of AUTOSAR. ⌋ ( )
**  Description:    LIN NM parameter configuration file for global constants
**
**  =========================================================================*/
#include "LinNm_Cfg.h"

/*@brief This macro is used to define number of channels in LIN Network management 
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 to 256
*/

#define LINNM_NUM_OF_CHANNELS                                           0x01U

/*@brief This macro is used to define Number of LIN peripherals channels in system 
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 to 256
*/
/* Number of LIN peripherals channels in system*/
#define LINNM_NUMBER_OF_SYS_CHANNELS                                    1u

# if (LINNM_PASSIVE_MODE_ENABLED == STD_ON)
/*@brief This macro denotes the time in seconds how long the NM shall stay in Network Mode in case of
 passive start-up before transition into Bus-Sleep Mode is initiated.
     Unit: Not Applicable
    Resolution: Not Applicable
    Range: Not Applicable
*/

#define LINNM_TIMEOUT_TIME                               0u
#endif

/*@brief this variable is used to define array index value of LIN Network mode and state buffer
 depen upon the channel request
      Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 to 256
 */
extern const NetworkHandleType LinNm_SystemToNmChannelInd[LINNM_NUMBER_OF_SYS_CHANNELS];


/*@brief this macro is used for Enables/disables the features of Call cycle in seconds
 of LinNm_MainFunction.
    Unit: Not Applicable
    Resolution: Not Applicable
    Range: 0 or 1
 */
#define LINNM_MAIN_FUNCTION_PERIOD      0u


/*--------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
---------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 10/Mar/2020
By                : BPANDURA
Traceability      : RTC # 725516, 725520, 725525, 780723, 780719, 780721, 780734.
Change Description: Added linNM main function period features
                    Changed "LINNM_PASSIVE_STARTUP_TIMEOUTTIME" to "LINNM_TIMEOUT_TIME"
----------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------
Date              : 08/Oct/2019
By                : MKANNAN2
Traceability      : RTC # 1375069
Change Description: Conditional compilation added to macro "LINNM_PASSIVE_STARTUP_TIMEOUTTIME".
----------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 26/July/2019
By                : MKANNAN2
Traceability      : RTC # 1351938
Change Description: Removed structure declaration "LinNm_ChannelConfig " and macro definition of LINNM_INVALID_CHANNEL 
----------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Date              : 15/July/2019
By                : MKANNAN2
Traceability      : RTC # 1351938
Change Description: Initial Version
----------------------------------------------------------------------------------------------------------------------*/


#endif
