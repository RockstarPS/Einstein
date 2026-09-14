#include "P32_TypeDef.h"



/////////////////////////////////////////////////////////////////////////////
//                            RF Definition                                //
/////////////////////////////////////////////////////////////////////////////
#define Tunerselect     0
#define PNS3030D        1
#define PNS3030A        2
#define MAX2172         4

#define HIGH_IF         (38.912)
#define LOW_IF          (2.048)
#define RF_STEP         (0.016)  //MHz
#define ITD_IF          (0.85)
#define RF_REF          (16.384)

#define DAB7_IF         (38.912)				
#define DAB7_RF_STEP    (0.016)

#define BANDII          (110.)
#define BANDIII         (246.)
#define BAND_L          (1450.)
#define BANDUHF		(810.)


/*! Initialize Tuner
   \param tuner : Tuner type  1-PNS3030D
   \param tuner : Tuner type  2-PNS3030A
   \param tuner : Tuner type  4-MAX2172
   \param tuner_freq : Tuner frequency
   \return Area is returned
   \sa Version
*/

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//                          RF Control Module                              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////


/******************************************************************************
**  Name:           INIT_TUNER
**  Description:    this function is to call for all tuner initialization.
**  Parameters:     tuner: Tuner type
**                  tuner_freq : Selected Broadcasting Frequency
**  Returns:        PN_OK or PN_FN_FAIL			
**  Dependencies:   none
******************************************************************************/
PN_S32 PN_INIT_TUNER(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT tuner_freq);

/******************************************************************************
**  Name:           CHANGE_TUNER_FREQ
**  Description:    this function is to call for Frequency changing.
**  Parameters:     tuner: Tuner type
**                  tuner_freq : Selected Broadcasting Frequency
**  Returns:        PN_OK or PN_FN_FAIL			
**  Dependencies:   none
******************************************************************************/
PN_S32 CHANGE_TUNER_FREQ(PN_U8 tuner, PN_FLOAT tuner_freq);

/******************************************************************************
**  Name:           SLEEP_TUNER
**  Description:    this function is to call for tuner sleep mode control
**  Parameters:     tuner: Tuner type
**  Returns:        PN_OK or PN_FN_FAIL			
**  Dependencies:   none
******************************************************************************/
PN_U8 SLEEP_TUNER(PN_U8 tuner);

/******************************************************************************
**  Name:           AGC_STAT_TUNER
**  Description:    this function is to call for tuner sleep mode control
**  Parameters:     tuner: Tuner type
**  Returns:        RF_level: RF Gain read by on time	
**                  IF_level: IF Gain read by on time    		
**  Dependencies:   none
******************************************************************************/
PN_U8 AGC_STAT_TUNER(PN_U8 tuner, PN_S32 *RF_level, PN_U8 *IF_level, PN_U8 *GVBB_level);

/******************************************************************************
**  Name:           AGC_CON_TUNER
**  Description:    this function is to call for AGC control
**  Parameters:     tuner: Tuner type
**                  tuner_freq: Selected Broadcasting Frequency
**                  post_agc: Post AGC value	
**  Returns:        PN_OK or PN_FN_FAIL
**  Dependencies:   none
******************************************************************************/
PN_U8 AGC_CON_TUNER(PN_U8 tuner,PN_FLOAT tuner_freq,int post_agc);

/******************************************************************************
**  Name:           T_DMB_CFREQ_SERH
**  Description:    this function is to call for Center frequency search
**  Parameters:     tuner_freq: Selected Broadcasting Frequency	
**  Returns:        tuner_cfreq_flag: calculated center frequency
**  Dependencies:   none
******************************************************************************/
PN_S32 T_DMB_CFREQ_SERH(float tuner_freq);

/******************************************************************************
**  Name:           RF_Delay_Us
**  Description:    RF delay time set, when this function is to call.
**  Parameters:     delay: delay time value(micro-sec)	
**  Returns:        none
**  Dependencies:   none
******************************************************************************/
PN_VOID RF_Delay_Us(PN_S32 delay);

/******************************************************************************
**  Name:           RF_Delay_Ms
**  Description:    RF delay time set, when this function is to call.
**  Parameters:     delay: delay time value(mili-sec)	
**  Returns:        none
**  Dependencies:   none
******************************************************************************/
PN_VOID RF_Delay_Ms(PN_S32 delay);

