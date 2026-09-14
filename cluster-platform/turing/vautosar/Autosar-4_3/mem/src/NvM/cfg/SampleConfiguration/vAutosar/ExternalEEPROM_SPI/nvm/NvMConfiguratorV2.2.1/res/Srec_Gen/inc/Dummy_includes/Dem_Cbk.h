#include "Std_Types.h"
typedef struct Dem_Cfg_PrimaryEntryType_s {
  uint32 Timestamp;
  uint16 AgingCounter;
  uint16 EventId;
}Dem_Cfg_PrimaryEntryType;

typedef struct Dem_Cfg_StatusDataType_s {
  uint16         FirstFailedEvent;
  uint16         FirstConfirmedEvent;
  uint16         MostRecentFailedEvent;
  uint16         MostRecentConfmdEvent;
  volatile uint8 EventStatus[ 47 /*DEM_G_NUMBER_OF_EVENTS (incl. #0)*/];
}                                                                     Dem_Cfg_StatusDataType; 

typedef struct Dem_Cfg_AdminDataType_s {
  uint16 ImplementationVersion;
  uint16 ConfigurationId;
  uint16 CycleCounter[ 3 /*DEM_CFG_GLOBAL_CYCLE_COUNT*/];
  uint8  MemoryOverflow;                                                        /* (DEM_CFG_DATA_OVFLIND == STD_ON) || (DEM_CFG_SUPPORT_OVFLIND_API == STD_ON) */
}                                                                     Dem_Cfg_AdminDataType; 
