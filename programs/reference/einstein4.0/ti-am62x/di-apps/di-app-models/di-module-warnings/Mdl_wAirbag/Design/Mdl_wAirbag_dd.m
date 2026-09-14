% This is an m script for Creating Application specific DataType definitions %
CAN_AIRBAG_SIGN_ONE_VALUE = mpt.Parameter;
CAN_AIRBAG_SIGN_ONE_VALUE.Value = uint8(1);
CAN_AIRBAG_SIGN_ONE_VALUE.Min = 1;
CAN_AIRBAG_SIGN_ONE_VALUE.Max = 255;
CAN_AIRBAG_SIGN_ONE_VALUE.RTWInfo.StorageClass = 'custom';
CAN_AIRBAG_SIGN_ONE_VALUE.RTWInfo.CustomStorageClass  = 'Define';

AIRBAG_SYSTEM_STAT_OFF = mpt.Parameter;
AIRBAG_SYSTEM_STAT_OFF.Value = uint8(0);
AIRBAG_SYSTEM_STAT_OFF.Min = 0;
AIRBAG_SYSTEM_STAT_OFF.Max = 255;
AIRBAG_SYSTEM_STAT_OFF.RTWInfo.StorageClass = 'Custom';
AIRBAG_SYSTEM_STAT_OFF.RTWInfo.CustomStorageClass  = 'Define';

AIRBAG_SYSTEM_STAT_ON = mpt.Parameter;
AIRBAG_SYSTEM_STAT_ON.Value = uint8(1);
AIRBAG_SYSTEM_STAT_ON.Min = 0;
AIRBAG_SYSTEM_STAT_ON.Max = 255;
AIRBAG_SYSTEM_STAT_ON.RTWInfo.StorageClass = 'Custom';
AIRBAG_SYSTEM_STAT_ON.RTWInfo.CustomStorageClass  = 'Define';



