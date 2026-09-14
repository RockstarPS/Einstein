% Simulink Signal data object attributes 

BASE_DATA_TYPE = mpt.Parameter;
BASE_DATA_TYPE.Value = uint8(8);
BASE_DATA_TYPE.RTWInfo.StorageClass = 'Custom';
BASE_DATA_TYPE.RTWInfo.CustomStorageClass  = 'Define';


MASTER_LAMP_MASK = mpt.Parameter;
MASTER_LAMP_MASK.Value = uint8(3);
MASTER_LAMP_MASK.RTWInfo.StorageClass = 'Custom';
MASTER_LAMP_MASK.RTWInfo.CustomStorageClass  = 'Define';

YELLOW = mpt.Parameter;
YELLOW.Value = uint8(1);
YELLOW.RTWInfo.StorageClass = 'Custom';
YELLOW.RTWInfo.CustomStorageClass  = 'Define';

RED = mpt.Parameter;
RED.Value = uint8(2);
RED.RTWInfo.StorageClass = 'Custom';
RED.RTWInfo.CustomStorageClass  = 'Define';

CTRLWARN_FALSE = mpt.Parameter;
CTRLWARN_FALSE.Value = uint8(0);
CTRLWARN_FALSE.RTWInfo.StorageClass = 'Custom';
CTRLWARN_FALSE.RTWInfo.CustomStorageClass  = 'Define';

EXTD_PAYLOAD_AVBLSTS = mpt.Parameter;
EXTD_PAYLOAD_AVBLSTS.Value = uint8(1);
EXTD_PAYLOAD_AVBLSTS.RTWInfo.StorageClass = 'Custom';
EXTD_PAYLOAD_AVBLSTS.RTWInfo.CustomStorageClass  = 'Define';

WRN_PAYLOAD_INITVAL = mpt.Parameter;
WRN_PAYLOAD_INITVAL.Value = uint8(0);
WRN_PAYLOAD_INITVAL.RTWInfo.StorageClass = 'Custom';
WRN_PAYLOAD_INITVAL.RTWInfo.CustomStorageClass  = 'Define';

WarningPayloadRecd    = Simulink.BusElement;
WarningPayloadRecd.Name    = 'WarningPayloadRecd';
WarningPayloadRecd.DataType    =  'uint8';
WarningPayloadRecd.Dimensions = 8;

WarningPayload_Type    = Simulink.Bus;
WarningPayload_Type.Elements   = [WarningPayloadRecd  ];
WarningPayload_Type.HeaderFile =  'Ctrl_warning_data.h';

WarningPayload_STRUCT    = mpt.Parameter;
WarningPayload_STRUCT.Value   = struct ('WarningPayloadRecd' ,1 );
WarningPayload_STRUCT.DataType = 'Bus:WarningPayload_Type';

ExtWarningCurrentPayload.Dimensions = 8;