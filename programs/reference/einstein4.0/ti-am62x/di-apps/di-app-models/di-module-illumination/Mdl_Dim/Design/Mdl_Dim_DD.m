STATUS_ON = mpt.Parameter;
STATUS_ON.Value = uint8(1);
STATUS_ON.Min =  0 ;
STATUS_ON.Max =  255;
STATUS_ON.RTWInfo.StorageClass = 'Custom';
STATUS_ON.RTWInfo.CustomStorageClass  = 'Define';

STATUS_OFF = mpt.Parameter;
STATUS_OFF.Value = uint8(0);
STATUS_OFF.Min =  0 ;
STATUS_OFF.Max =  255;
STATUS_OFF.RTWInfo.StorageClass = 'Custom';
STATUS_OFF.RTWInfo.CustomStorageClass  = 'Define';

SWITCHING_MECHANISM = mpt.Parameter;
SWITCHING_MECHANISM.Value = uint8(0);
SWITCHING_MECHANISM.Min =  0 ;
SWITCHING_MECHANISM.Max =  255;
SWITCHING_MECHANISM.RTWInfo.StorageClass = 'Custom';
SWITCHING_MECHANISM.RTWInfo.CustomStorageClass  = 'Define';

ZERO_VAL = mpt.Parameter;
ZERO_VAL.Value = uint8(0);
ZERO_VAL.Min =  0 ;
ZERO_VAL.Max =  255;
ZERO_VAL.RTWInfo.StorageClass = 'Custom';
ZERO_VAL.RTWInfo.CustomStorageClass  = 'Define';

DEFAULT_MODE = mpt.Parameter;
DEFAULT_MODE.Value = uint8(0); %DAY MODE
DEFAULT_MODE.Min =  0 ;
DEFAULT_MODE.Max =  255;
DEFAULT_MODE.RTWInfo.StorageClass = 'Custom';
DEFAULT_MODE.RTWInfo.CustomStorageClass  = 'Define';

DEFAULT_STEP = mpt.Parameter;
DEFAULT_STEP.Value = uint8(4); %DEFAULT STEP
DEFAULT_STEP.Min =  0 ;
DEFAULT_STEP.Max =  255;
DEFAULT_STEP.RTWInfo.StorageClass = 'Custom';
DEFAULT_STEP.RTWInfo.CustomStorageClass  = 'Define';