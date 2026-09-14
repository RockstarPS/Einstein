
%% Variant control information start

SIMULATION = Simulink.Variant('mode==1');
CODEGENERATION = Simulink.Variant('mode==2');

mode = 2;

%% Variant control information end

%% Constants %%

ECUAPPM_PERIOD_MSEC = mpt.Parameter;
ECUAPPM_PERIOD_MSEC.Value =uint16(10);
ECUAPPM_PERIOD_MSEC.RTWInfo.StorageClass = 'Custom';
ECUAPPM_PERIOD_MSEC.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_PERIOD_MSEC.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Cfg.h';

ECUAPPM_GROUP_ACTIVATION_TYPE = mpt.Parameter;
ECUAPPM_GROUP_ACTIVATION_TYPE.Value =uint8(0);
ECUAPPM_GROUP_ACTIVATION_TYPE.RTWInfo.StorageClass = 'Custom';
ECUAPPM_GROUP_ACTIVATION_TYPE.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_GROUP_ACTIVATION_TYPE.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Cfg.h';

ECUAPPM_MIN_GROUP_ACTIVE_TIME = mpt.Parameter;
ECUAPPM_MIN_GROUP_ACTIVE_TIME.Value =uint16(100);
ECUAPPM_MIN_GROUP_ACTIVE_TIME.RTWInfo.StorageClass = 'Custom';
ECUAPPM_MIN_GROUP_ACTIVE_TIME.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_MIN_GROUP_ACTIVE_TIME.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Cfg.h';

ASYNCHRONUS = mpt.Parameter;
ASYNCHRONUS.Value =uint8(0);
ASYNCHRONUS.RTWInfo.StorageClass = 'Custom';
ASYNCHRONUS.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ASYNCHRONUS.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Cfg.h';

SYNCHRONUS = mpt.Parameter;
SYNCHRONUS.Value =uint8(1);
SYNCHRONUS.RTWInfo.StorageClass = 'Custom';
SYNCHRONUS.RTWInfo.CustomStorageClass  = 'ImportFromFile';
SYNCHRONUS.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Cfg.h';

SHUTDOWN = mpt.Parameter;
SHUTDOWN.Value =uint8(0);
SHUTDOWN.RTWInfo.StorageClass = 'Custom';
SHUTDOWN.RTWInfo.CustomStorageClass  = 'ImportFromFile';
SHUTDOWN.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Cfg.h';

KEEP_ALIVE = mpt.Parameter;
KEEP_ALIVE.Value =uint8(1);
KEEP_ALIVE.RTWInfo.StorageClass = 'Custom';
KEEP_ALIVE.RTWInfo.CustomStorageClass  = 'ImportFromFile';
KEEP_ALIVE.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Cfg.h';

ECUAPPM_FALSE = mpt.Parameter;
ECUAPPM_FALSE.Value =uint8(0);
ECUAPPM_FALSE.RTWInfo.StorageClass = 'Custom';
ECUAPPM_FALSE.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_FALSE.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_TRUE = mpt.Parameter;
ECUAPPM_TRUE.Value =uint8(1);
ECUAPPM_TRUE.RTWInfo.StorageClass = 'Custom';
ECUAPPM_TRUE.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_TRUE.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_VALUE_ZERO = mpt.Parameter;
ECUAPPM_VALUE_ZERO.Value =uint8(0);
ECUAPPM_VALUE_ZERO.RTWInfo.StorageClass = 'Custom';
ECUAPPM_VALUE_ZERO.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_VALUE_ZERO.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_VALUE_ONE = mpt.Parameter;
ECUAPPM_VALUE_ONE.Value =uint8(1);
ECUAPPM_VALUE_ONE.RTWInfo.StorageClass = 'Custom';
ECUAPPM_VALUE_ONE.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_VALUE_ONE.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_VALIDATION_IN_PROGRESS = mpt.Parameter;
ECUAPPM_VALIDATION_IN_PROGRESS.Value =uint8(0);
ECUAPPM_VALIDATION_IN_PROGRESS.RTWInfo.StorageClass = 'Custom';
ECUAPPM_VALIDATION_IN_PROGRESS.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_VALIDATION_IN_PROGRESS.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_VALIDATION_FAILED = mpt.Parameter;
ECUAPPM_VALIDATION_FAILED.Value =uint8(1);
ECUAPPM_VALIDATION_FAILED.RTWInfo.StorageClass = 'Custom';
ECUAPPM_VALIDATION_FAILED.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_VALIDATION_FAILED.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_VALIDATION_SUCESS = mpt.Parameter;
ECUAPPM_VALIDATION_SUCESS.Value =uint8(2);
ECUAPPM_VALIDATION_SUCESS.RTWInfo.StorageClass = 'Custom';
ECUAPPM_VALIDATION_SUCESS.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_VALIDATION_SUCESS.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_JOB_IDLE = mpt.Parameter;
ECUAPPM_JOB_IDLE.Value =uint8(0);
ECUAPPM_JOB_IDLE.RTWInfo.StorageClass = 'Custom';
ECUAPPM_JOB_IDLE.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_JOB_IDLE.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_JOB_IN_PROGRESS = mpt.Parameter;
ECUAPPM_JOB_IN_PROGRESS.Value =uint8(1);
ECUAPPM_JOB_IN_PROGRESS.RTWInfo.StorageClass = 'Custom';
ECUAPPM_JOB_IN_PROGRESS.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_JOB_IN_PROGRESS.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_JOB_DONE = mpt.Parameter;
ECUAPPM_JOB_DONE.Value =uint8(2);
ECUAPPM_JOB_DONE.RTWInfo.StorageClass = 'Custom';
ECUAPPM_JOB_DONE.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_JOB_DONE.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_JOB_FAILED = mpt.Parameter;
ECUAPPM_JOB_FAILED.Value =uint8(3);
ECUAPPM_JOB_FAILED.RTWInfo.StorageClass = 'Custom';
ECUAPPM_JOB_FAILED.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_JOB_FAILED.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_READY_TO_SLEEP = mpt.Parameter;
ECUAPPM_READY_TO_SLEEP.Value =uint8(0);
ECUAPPM_READY_TO_SLEEP.RTWInfo.StorageClass = 'Custom';
ECUAPPM_READY_TO_SLEEP.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_READY_TO_SLEEP.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_REFUSE_TO_SLEEP = mpt.Parameter;
ECUAPPM_REFUSE_TO_SLEEP.Value =uint8(1);
ECUAPPM_REFUSE_TO_SLEEP.RTWInfo.StorageClass = 'Custom';
ECUAPPM_REFUSE_TO_SLEEP.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_REFUSE_TO_SLEEP.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_NOWKPEVENT = mpt.Parameter;
ECUAPPM_NOWKPEVENT.Value =uint8(0);
ECUAPPM_NOWKPEVENT.RTWInfo.StorageClass = 'Custom';
ECUAPPM_NOWKPEVENT.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_NOWKPEVENT.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_VALIDATION_TIME_ZERO = mpt.Parameter;
ECUAPPM_VALIDATION_TIME_ZERO.Value =uint8(0);
ECUAPPM_VALIDATION_TIME_ZERO.RTWInfo.StorageClass = 'Custom';
ECUAPPM_VALIDATION_TIME_ZERO.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_VALIDATION_TIME_ZERO.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_GROUP0 = mpt.Parameter;
ECUAPPM_GROUP0.Value =uint8(0);
ECUAPPM_GROUP0.RTWInfo.StorageClass = 'Custom';
ECUAPPM_GROUP0.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_GROUP0.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_GROUP1 = mpt.Parameter;
ECUAPPM_GROUP1.Value =uint8(1);
ECUAPPM_GROUP1.RTWInfo.StorageClass = 'Custom';
ECUAPPM_GROUP1.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_GROUP1.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_GROUP2 = mpt.Parameter;
ECUAPPM_GROUP2.Value =uint8(2);
ECUAPPM_GROUP2.RTWInfo.StorageClass = 'Custom';
ECUAPPM_GROUP2.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_GROUP2.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_MAX_GROUPS = mpt.Parameter;
ECUAPPM_MAX_GROUPS.Value =uint8(5);
ECUAPPM_MAX_GROUPS.RTWInfo.StorageClass = 'Custom';
ECUAPPM_MAX_GROUPS.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_MAX_GROUPS.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_GROUPDEACTIVATION = mpt.Parameter;
ECUAPPM_GROUPDEACTIVATION.Value =uint16(7);
ECUAPPM_GROUPDEACTIVATION.RTWInfo.StorageClass = 'Custom';
ECUAPPM_GROUPDEACTIVATION.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_GROUPDEACTIVATION.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_MAX_WAKEUP_SOURCES = mpt.Parameter;
ECUAPPM_MAX_WAKEUP_SOURCES.Value =uint16(6);
ECUAPPM_MAX_WAKEUP_SOURCES.RTWInfo.StorageClass = 'Custom';
ECUAPPM_MAX_WAKEUP_SOURCES.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_MAX_WAKEUP_SOURCES.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

FULL = mpt.Parameter;
FULL.Value =uint8(0);
FULL.RTWInfo.StorageClass = 'Custom';
FULL.RTWInfo.CustomStorageClass  = 'ImportFromFile';
FULL.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

PARTIAL = mpt.Parameter;
PARTIAL.Value =uint8(1);
PARTIAL.RTWInfo.StorageClass = 'Custom';
PARTIAL.RTWInfo.CustomStorageClass  = 'ImportFromFile';
PARTIAL.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_PREGROUP0_MAX_ELEMENTS = mpt.Parameter;
ECUAPPM_PREGROUP0_MAX_ELEMENTS.Value =uint8(2);
ECUAPPM_PREGROUP0_MAX_ELEMENTS.RTWInfo.StorageClass = 'Custom';
ECUAPPM_PREGROUP0_MAX_ELEMENTS.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_PREGROUP0_MAX_ELEMENTS.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_PREGROUP1_MAX_ELEMENTS = mpt.Parameter;
ECUAPPM_PREGROUP1_MAX_ELEMENTS.Value =uint8(2);
ECUAPPM_PREGROUP1_MAX_ELEMENTS.RTWInfo.StorageClass = 'Custom';
ECUAPPM_PREGROUP1_MAX_ELEMENTS.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_PREGROUP1_MAX_ELEMENTS.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

PRE_GROUP0 = mpt.Parameter;
PRE_GROUP0.Value =uint8(0);
PRE_GROUP0.RTWInfo.StorageClass = 'Custom';
PRE_GROUP0.RTWInfo.CustomStorageClass  = 'ImportFromFile';
PRE_GROUP0.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

PRE_GROUP1 = mpt.Parameter;
PRE_GROUP1.Value =uint8(1);
PRE_GROUP1.RTWInfo.StorageClass = 'Custom';
PRE_GROUP1.RTWInfo.CustomStorageClass  = 'ImportFromFile';
PRE_GROUP1.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

ECUAPPM_CONTEXTFLAG = mpt.Parameter;
ECUAPPM_CONTEXTFLAG.Value =uint8(1);
ECUAPPM_CONTEXTFLAG.RTWInfo.StorageClass = 'Custom';
ECUAPPM_CONTEXTFLAG.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ECUAPPM_CONTEXTFLAG.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Types.h';

%% Structures %%

%% EcuAppM structure

State = Simulink.BusElement;
State.Name = 'State';
State.DataType = 'Enum:EcuAppMType';

CurrentJobStatus = Simulink.BusElement;
CurrentJobStatus.Name = 'CurrentJobStatus';
CurrentJobStatus.DataType = 'uint8';

EarlyWakeupCheck = Simulink.BusElement;
EarlyWakeupCheck.Name = 'EarlyWakeupCheck';
EarlyWakeupCheck.DataType = 'uint8';

EcuAppMInfoType = Simulink.Bus;
EcuAppMInfoType.Elements = [State CurrentJobStatus EarlyWakeupCheck];
EcuAppMInfoType.DataScope = 'Imported';
EcuAppMInfoType.HeaderFile  = 'EcuAppM_Types.h';

EcuAppMInfo = mpt.Signal;
EcuAppMInfo.DataType = 'Bus:EcuAppMInfoType';
EcuAppMInfo.Dimensions = 1;
EcuAppMInfo.RTWInfo.StorageClass           = 'Custom';
EcuAppMInfo.RTWInfo.CustomStorageClass     = 'ImportFromFile';
EcuAppMInfo.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

% EcuAppM_GroupsStatus structure

GroupState = Simulink.BusElement;
GroupState.Name = 'GroupState';
GroupState.DataType = 'Enum:GroupStatesType';
GroupState.Dimensions = 2; 

GroupActivityTimer = Simulink.BusElement;
GroupActivityTimer.Name = 'GroupActivityTimer';
GroupActivityTimer.DataType = 'uint16';
GroupActivityTimer.Dimensions = 2;

GroupCurrentActivity = Simulink.BusElement;
GroupCurrentActivity.Name = 'GroupCurrentActivity';
GroupCurrentActivity.DataType = 'uint8';
GroupCurrentActivity.Dimensions = 2; 

EcuAppM_GroupsInfoType = Simulink.Bus;
EcuAppM_GroupsInfoType.Elements = [GroupState GroupActivityTimer GroupCurrentActivity];
EcuAppM_GroupsInfoType.DataScope = 'Imported';
EcuAppM_GroupsInfoType.HeaderFile = 'EcuAppM_Types.h';

EcuAppM_GroupsInfo = mpt.Signal;
EcuAppM_GroupsInfo.DataType = 'Bus:EcuAppM_GroupsInfoType';
EcuAppM_GroupsInfo.Dimensions = 1;
EcuAppM_GroupsInfo.RTWInfo.StorageClass           = 'Custom';
EcuAppM_GroupsInfo.RTWInfo.CustomStorageClass     = 'ImportFromFile';
EcuAppM_GroupsInfo.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

%% EcuAppM_GroupConfigData Structure %%

wakeupSourceMask = Simulink.BusElement;
wakeupSourceMask.Name = 'wakeupSourceMask';
wakeupSourceMask.DataType = 'uint16';

deactivationType = Simulink.BusElement;
deactivationType.Name = 'deactivationType';
deactivationType.DataType = 'uint8';

safetyLevel = Simulink.BusElement;
safetyLevel.Name = 'safetyLevel';
safetyLevel.DataType = 'Enum:SafetyLevelType';

failSafeTimeout = Simulink.BusElement;
failSafeTimeout.Name = 'failSafeTimeout';
failSafeTimeout.DataType = 'uint16';

attributes = Simulink.BusElement;
attributes.Name = 'attributes';
attributes.DataType = 'uint8';

EcuAppM_GroupConfigType = Simulink.Bus;
EcuAppM_GroupConfigType.Elements = [wakeupSourceMask  deactivationType safetyLevel failSafeTimeout attributes];
EcuAppM_GroupConfigType.DataScope = 'Imported';
EcuAppM_GroupConfigType.HeaderFile = 'EcuAppM_Cfg.h';

EcuAppM_GroupConfigData = mpt.Parameter;
EcuAppM_GroupConfigData.DataType = 'EcuAppM_GroupConfigType';
EcuAppM_GroupConfigData.Value = struct('wakeupSourceMask',{0xFF 0xFF 0x0F 0x10 0x20},'deactivationType',{1 0 0 0 0},'safetyLevel',{SafetyLevelType.eSafetyLevel_QM SafetyLevelType.eSafetyLevel_QM SafetyLevelType.eSafetyLevel_QM SafetyLevelType.eSafetyLevel_ASILA SafetyLevelType.eSafetyLevel_QM},'failSafeTimeout',{20 20 20 20 20},'attributes',{0 0 0 0 0});
EcuAppM_GroupConfigData.RTWInfo.StorageClass = 'Custom';
EcuAppM_GroupConfigData.RTWInfo.CustomStorageClass  = 'ImportFromFile';
EcuAppM_GroupConfigData.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Cfg.h';

EcuAppM_PreGroup0Elements = mpt.Parameter;
EcuAppM_PreGroup0Elements.Value = [uint8(0) uint8(2)];
EcuAppM_PreGroup0Elements.RTWInfo.StorageClass = 'Custom';
EcuAppM_PreGroup0Elements.RTWInfo.CustomStorageClass  = 'ImportFromFile';
EcuAppM_PreGroup0Elements.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

EcuAppM_PreGroup1Elements = mpt.Parameter;
EcuAppM_PreGroup1Elements.Value = [uint8(1) uint8(2)];
EcuAppM_PreGroup1Elements.RTWInfo.StorageClass = 'Custom';
EcuAppM_PreGroup1Elements.RTWInfo.CustomStorageClass  = 'ImportFromFile';
EcuAppM_PreGroup1Elements.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';


%% EcuAppM_WakeupSourcesData Structure %%

wakeupMask = Simulink.BusElement;
wakeupMask.Name = 'wakeupMask';
wakeupMask.DataType = 'uint32';

validationTime = Simulink.BusElement;
validationTime.Name = 'validationTime';
validationTime.DataType = 'uint16';

wakeupReaction = Simulink.BusElement; 
wakeupReaction.Name = 'wakeupReaction';
wakeupReaction.DataType = 'uint16';

EcuAppM_WakeupSourcesType = Simulink.Bus;
EcuAppM_WakeupSourcesType.Elements = [wakeupMask validationTime wakeupReaction];
EcuAppM_WakeupSourcesType.DataScope = 'Imported';
EcuAppM_WakeupSourcesType.HeaderFile = 'EcuAppM_Cfg.h';

EcuAppM_WakeupSourcesData = mpt.Parameter;
EcuAppM_WakeupSourcesData.DataType = 'EcuAppM_WakeupSourcesType';
EcuAppM_WakeupSourcesData.Value = struct('wakeupMask',{1 2 4 8 16 32}, 'validationTime',{20 20 20 20 20 20},'wakeupReaction',{0 0 0 0 1 1});
EcuAppM_WakeupSourcesData.RTWInfo.StorageClass = 'Custom';
EcuAppM_WakeupSourcesData.RTWInfo.CustomStorageClass  = 'ImportFromFile';
EcuAppM_WakeupSourcesData.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_Cfg.h';

EcuAppM_BufferedWakeupData = mpt.Signal;
EcuAppM_BufferedWakeupData.DataType = 'Bus:EcuAppM_WakeupSourcesType';
EcuAppM_BufferedWakeupData.Dimensions = 1;
EcuAppM_BufferedWakeupData.RTWInfo.StorageClass           = 'Custom';
EcuAppM_BufferedWakeupData.RTWInfo.CustomStorageClass     = 'ImportFromFile';
EcuAppM_BufferedWakeupData.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

%% Variables %% 

ApplicationSleepState = mpt.Signal;
ApplicationSleepState.DataType = 'uint8';
ApplicationSleepState.Dimensions = 1;
ApplicationSleepState.Min = 0;
ApplicationSleepState.Max = 255;
ApplicationSleepState.RTWInfo.StorageClass           = 'Custom';
ApplicationSleepState.RTWInfo.CustomStorageClass  = 'ImportFromFile';
ApplicationSleepState.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

WakeupEvent = mpt.Signal;
WakeupEvent.DataType = 'uint32';
WakeupEvent.Dimensions = 1;
WakeupEvent.Min = 0;
WakeupEvent.Max = 4294967295;
WakeupEvent.RTWInfo.StorageClass           = 'Custom';
WakeupEvent.RTWInfo.CustomStorageClass  = 'ImportFromFile';
WakeupEvent.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

EcuAppM_WakeupSource = mpt.Signal;
EcuAppM_WakeupSource.DataType = 'uint32';
EcuAppM_WakeupSource.Dimensions = 1;
EcuAppM_WakeupSource.Min = 0;
EcuAppM_WakeupSource.Max = 4294967295;
EcuAppM_WakeupSource.RTWInfo.StorageClass           = 'Custom';
EcuAppM_WakeupSource.RTWInfo.CustomStorageClass  = 'ImportFromFile';
EcuAppM_WakeupSource.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

EcuAppM_BufferedWakeupSource = mpt.Signal;
EcuAppM_BufferedWakeupSource.DataType = 'uint32';
EcuAppM_BufferedWakeupSource.Dimensions = 1;
EcuAppM_BufferedWakeupSource.Min = 0;
EcuAppM_BufferedWakeupSource.Max = 4294967295;
EcuAppM_BufferedWakeupSource.RTWInfo.StorageClass           = 'Custom';
EcuAppM_BufferedWakeupSource.RTWInfo.CustomStorageClass  = 'ImportFromFile';
EcuAppM_BufferedWakeupSource.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

EcuAppMStateOp = mpt.Signal;
EcuAppMStateOp.DataType = 'Enum:EcuAppMType';
EcuAppMStateOp.Dimensions = 1;
EcuAppMStateOp.RTWInfo.StorageClass           = 'Custom';
EcuAppMStateOp.RTWInfo.CustomStorageClass  = 'ImportFromFile';
EcuAppMStateOp.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

EcuAppM_WakeupValidationTimer = mpt.Signal;
EcuAppM_WakeupValidationTimer.DataType = 'uint16';
EcuAppM_WakeupValidationTimer.Dimensions = 1;
EcuAppM_WakeupValidationTimer.Min = 0;
EcuAppM_WakeupValidationTimer.Max = 65535;
EcuAppM_WakeupValidationTimer.RTWInfo.StorageClass           = 'Custom';
EcuAppM_WakeupValidationTimer.RTWInfo.CustomStorageClass     = 'ImportFromFile';
EcuAppM_WakeupValidationTimer.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

EcuAppM_From_Groupid = mpt.Signal;
EcuAppM_From_Groupid.DataType = 'uint8';
EcuAppM_From_Groupid.Dimensions = 1;
EcuAppM_From_Groupid.Min = 0;
EcuAppM_From_Groupid.Max = 255;
EcuAppM_From_Groupid.RTWInfo.StorageClass           = 'Custom';
EcuAppM_From_Groupid.RTWInfo.CustomStorageClass  = 'ImportFromFile';
EcuAppM_From_Groupid.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

EcuAppM_To_Groupid = mpt.Signal;
EcuAppM_To_Groupid.DataType = 'uint8';
EcuAppM_To_Groupid.Dimensions = 1;
EcuAppM_To_Groupid.Min = 0;
EcuAppM_To_Groupid.Max = 255;
EcuAppM_To_Groupid.RTWInfo.StorageClass           = 'Custom';
EcuAppM_To_Groupid.RTWInfo.CustomStorageClass  = 'ImportFromFile';
EcuAppM_To_Groupid.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

EcuAppM_Index = mpt.Signal;
EcuAppM_Index.DataType = 'uint16';
EcuAppM_Index.Dimensions = 1;
EcuAppM_Index.Min = 0;
EcuAppM_Index.Max = 65535;
EcuAppM_Index.RTWInfo.StorageClass           = 'Custom';
EcuAppM_Index.RTWInfo.CustomStorageClass  = 'ImportFromFile';
EcuAppM_Index.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

wakeupMask = mpt.Signal;
wakeupMask.DataType = 'uint32';
wakeupMask.Dimensions = 1;
wakeupMask.Min = 0;
wakeupMask.Max = 4294967295;
wakeupMask.RTWInfo.StorageClass           = 'Custom';
wakeupMask.RTWInfo.CustomStorageClass  = 'ImportFromFile';
wakeupMask.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

PrevwakeupMask = mpt.Signal;
PrevwakeupMask.DataType = 'uint32';
PrevwakeupMask.Dimensions = 1;
PrevwakeupMask.Min = 0;
PrevwakeupMask.Max = 4294967295;
PrevwakeupMask.RTWInfo.StorageClass           = 'Custom';
PrevwakeupMask.RTWInfo.CustomStorageClass  = 'ImportFromFile';
PrevwakeupMask.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

validationTime = mpt.Signal;
validationTime.DataType = 'uint16';
validationTime.Dimensions = 1;
validationTime.Min = 0;
validationTime.Max = 65535;
validationTime.RTWInfo.StorageClass           = 'Custom';
validationTime.RTWInfo.CustomStorageClass  = 'ImportFromFile';
validationTime.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

PrevvalidationTime = mpt.Signal;
PrevvalidationTime.DataType = 'uint16';
PrevvalidationTime.Dimensions = 1;
PrevvalidationTime.Min = 0;
PrevvalidationTime.Max = 65535;
PrevvalidationTime.RTWInfo.StorageClass           = 'Custom';
PrevvalidationTime.RTWInfo.CustomStorageClass  = 'ImportFromFile';
PrevvalidationTime.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

wakeupReaction = mpt.Signal;
wakeupReaction.DataType = 'uint16';
wakeupReaction.Dimensions = 1;
wakeupReaction.Min = 0;
wakeupReaction.Max = 65535;
wakeupReaction.RTWInfo.StorageClass           = 'Custom';
wakeupReaction.RTWInfo.CustomStorageClass  = 'ImportFromFile';
wakeupReaction.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

PrevwakeupReaction = mpt.Signal;
PrevwakeupReaction.DataType = 'uint16';
PrevwakeupReaction.Dimensions = 1;
PrevwakeupReaction.Min = 0;
PrevwakeupReaction.Max = 65535;
PrevwakeupReaction.RTWInfo.StorageClass           = 'Custom';
PrevwakeupReaction.RTWInfo.CustomStorageClass  = 'ImportFromFile';
PrevwakeupReaction.RTWInfo.CustomAttributes.HeaderFile  = 'EcuAppM_internal.h';

