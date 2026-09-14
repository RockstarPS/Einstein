#ifndef DIOAPP_H_
#define DIOAPP_H_   

extern void DioApp_Startup(void);
extern void DioApp_McuDomainPinMux(uint32 offset, uint32 muxmode); 
extern void DioApp_MainDomainPinMux(uint32 offset, uint32 muxmode);
extern void DioApp_unlockMmrRegisters(uint32 lockKey0, uint32 lockKey1);
extern void DioApp_mainTest(void);
extern void DioApp_PowerAndClkSrc(void);

#endif /* DIOAPP_H_ */



