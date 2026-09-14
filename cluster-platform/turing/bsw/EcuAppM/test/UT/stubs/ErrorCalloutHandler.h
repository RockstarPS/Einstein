#if (!defined ErrorCalloutHandler_H)
#define ErrorCalloutHandler_H

extern void ErrorCalloutHandler(
   uint16 ModuleId,
   uint8  InstanceId,
   uint8  ApiId,
   uint8  ErrorId);

extern void Mcu_NotificationFunction_HvLvd1(void);
 
#endif /* !defined ErrorCalloutHandler_H ) */
/*==================[end of file]===========================================*/

