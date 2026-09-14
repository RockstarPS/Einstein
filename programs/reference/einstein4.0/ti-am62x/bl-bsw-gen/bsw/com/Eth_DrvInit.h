#ifndef ETH_DRVINIT
#define ETH_DRVINIT

/*!
 * @brief This function does pre intialization for enabling the ethernet module and the invokes the Eth_Init to
 *  initialize the ethernet driver.
 * 
 */
void Eth_DrvInit(void);
/*!
 *  @brief This function should be called in mainfunction to initialize the Ethernet Trcv in Evk board, as Init needs
 *  delay time after Eth drv init
 * 
 */
void Eth_DrvTrcvInit(void);
#endif /* ETH_DRVINIT */