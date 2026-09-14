%% This is an m script for Creating Application specific DataType definitions

FUEL_CAN_SIG_VAL_ONE = mpt.Parameter;
FUEL_CAN_SIG_VAL_ONE.Value = uint8(1);
FUEL_CAN_SIG_VAL_ONE.Min = 0;
FUEL_CAN_SIG_VAL_ONE.Max = 255;
FUEL_CAN_SIG_VAL_ONE.RTWInfo.StorageClass = 'Custom';
FUEL_CAN_SIG_VAL_ONE.RTWInfo.CustomStorageClass  = 'Define';


FUEL_PAYLOAD_INVALID_VALUE = mpt.Parameter;
FUEL_PAYLOAD_INVALID_VALUE.Value = uint32(0);
FUEL_PAYLOAD_INVALID_VALUE.RTWInfo.StorageClass = 'Custom';
FUEL_PAYLOAD_INVALID_VALUE.RTWInfo.CustomStorageClass  = 'Define';











