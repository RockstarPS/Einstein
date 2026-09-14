SPEED_CHECK_VALUE_ONE= mpt.Parameter;
SPEED_CHECK_VALUE_ONE.Value =uint16(1);
SPEED_CHECK_VALUE_ONE.Min = 0;
SPEED_CHECK_VALUE_ONE.Max = 255;
SPEED_CHECK_VALUE_ONE.RTWInfo.StorageClass='Custom';
SPEED_CHECK_VALUE_ONE.RTWInfo.CustomStorageClass  = 'Define';

INDEX_MCUID0262= mpt.Parameter;
INDEX_MCUID0262.Value =uint8(1);
INDEX_MCUID0262.Min = 0;
INDEX_MCUID0262.Max = 255;
INDEX_MCUID0262.RTWInfo.StorageClass='Custom';
INDEX_MCUID0262.RTWInfo.CustomStorageClass  = 'Define';

INDEX_MCUID0263= mpt.Parameter;
INDEX_MCUID0263.Value =uint8(2);
INDEX_MCUID0263.Min = 0;
INDEX_MCUID0263.Max = 255;
INDEX_MCUID0263.RTWInfo.StorageClass='Custom';
INDEX_MCUID0263.RTWInfo.CustomStorageClass  = 'Define';

MCUID_MAX_VAL= mpt.Parameter;
MCUID_MAX_VAL.Value =uint16(6553);
MCUID_MAX_VAL.Min = 0;
MCUID_MAX_VAL.Max = 65535;
MCUID_MAX_VAL.RTWInfo.StorageClass='Custom';
MCUID_MAX_VAL.RTWInfo.CustomStorageClass  = 'Define';

SPEED_RESOLUTION= mpt.Parameter;
SPEED_RESOLUTION.Value =uint16(10);
SPEED_RESOLUTION.Min = 0;
SPEED_RESOLUTION.Max = 65535;
SPEED_RESOLUTION.RTWInfo.StorageClass='Custom';
SPEED_RESOLUTION.RTWInfo.CustomStorageClass  = 'Define';

CNVM_MCUID0263_DEFAULT_VAL= mpt.Parameter;
CNVM_MCUID0263_DEFAULT_VAL.Value =uint16(16000);
CNVM_MCUID0263_DEFAULT_VAL.Min = 0;
CNVM_MCUID0263_DEFAULT_VAL.Max = 16000;
CNVM_MCUID0263_DEFAULT_VAL.RTWInfo.StorageClass='Custom';
CNVM_MCUID0263_DEFAULT_VAL.RTWInfo.CustomStorageClass  = 'Define';

CNVM_MCUID0262_DEFAULT_VAL= mpt.Parameter;
CNVM_MCUID0262_DEFAULT_VAL.Value =uint16(18000);
CNVM_MCUID0262_DEFAULT_VAL.Min = 0;
CNVM_MCUID0262_DEFAULT_VAL.Max = 18000;
CNVM_MCUID0262_DEFAULT_VAL.RTWInfo.StorageClass='Custom';
CNVM_MCUID0262_DEFAULT_VAL.RTWInfo.CustomStorageClass  = 'Define';

l_Speed_Array_US_CAN_MAX_1 = mpt.Parameter;
l_Speed_Array_US_CAN_MAX_1.Value = [uint16(175) uint16(33789);uint16(0) uint16(0); uint16(3218)  uint16(2045); uint16(6436)  uint16(4090); uint16(9654)  uint16(6130); uint16(12872) uint16(8180); uint16(16090) uint16(10220); uint16(19308) uint16(12270); uint16(22526) uint16(14310); uint16(25744) uint16(16360); uint16(28962) uint16(18400); uint16(33789) uint16(21460); uint16(65535) uint16(65535); uint16(65535) uint16(65535); uint16(65535) uint16(65535); uint16(65535) uint16(65535); uint16(65535) uint16(65535); uint16(65535) uint16(65535);];
l_Speed_Array_US_CAN_MAX_1.Min  = 0;
l_Speed_Array_US_CAN_MAX_1.Max  = 65535;
l_Speed_Array_US_CAN_MAX_1.RTWInfo.StorageClass = 'Custom';
l_Speed_Array_US_CAN_MAX_1.RTWInfo.CustomStorageClass  = 'ImportFromFile';
l_Speed_Array_US_CAN_MAX_1.RTWInfo.CustomAttributes.HeaderFile  = 'Mdl_Digspeed_table_config.cfg';

Initial_data = mpt.Parameter;
Initial_data.Value = [uint16(0) uint16(2170) uint16(4280) uint16(6280) uint16(8430) uint16(10470) uint16(12540) uint16(14600) uint16(16680) uint16(18750) uint16(20820) uint16(22890) uint16(24960) uint16(27040) uint16(29110) uint16(31180) uint16(33250) uint16(35320) uint16(37400) uint16(39470) uint16(41540)];
Initial_data.Min  = 0;
Initial_data.Max  = 41540;
Initial_data.RTWInfo.CustomStorageClass  = 'ImportFromFile';
Initial_data.RTWInfo.CustomAttributes.HeaderFile  = 'Mdl_Digspeed_table_config.cfg';

SPEED_ARRAY_MAX_VALUE= mpt.Parameter;
SPEED_ARRAY_MAX_VALUE.Value =uint8(44);
SPEED_ARRAY_MAX_VALUE.Min = 0;
SPEED_ARRAY_MAX_VALUE.Max = 255;
SPEED_ARRAY_MAX_VALUE.RTWInfo.StorageClass='Custom';
SPEED_ARRAY_MAX_VALUE.RTWInfo.CustomStorageClass  = 'Define';

SPEED_ZERO= mpt.Parameter;
SPEED_ZERO.Value =uint16(0);
SPEED_ZERO.Min = 0;
SPEED_ZERO.Max = 65535;
SPEED_ZERO.RTWInfo.StorageClass='Custom';
SPEED_ZERO.RTWInfo.CustomStorageClass  = 'Define';

VAL_ONE= mpt.Parameter;
VAL_ONE.Value =uint8(1);
VAL_ONE.Min = 0;
VAL_ONE.Max = 255;
VAL_ONE.RTWInfo.StorageClass='Custom';
VAL_ONE.RTWInfo.CustomStorageClass  = 'Define';

RESOLUTION_VAL_100= mpt.Parameter;
RESOLUTION_VAL_100.Value =uint16(100);
RESOLUTION_VAL_100.Min = 0;
RESOLUTION_VAL_100.Max = 255;
RESOLUTION_VAL_100.RTWInfo.StorageClass='Custom';
RESOLUTION_VAL_100.RTWInfo.CustomStorageClass  = 'Define';

RESOLUTION_VAL_MINUS_100= mpt.Parameter;
RESOLUTION_VAL_MINUS_100.Value =int8(-100);
RESOLUTION_VAL_MINUS_100.Min = -128;
RESOLUTION_VAL_MINUS_100.Max = 127;
RESOLUTION_VAL_MINUS_100.RTWInfo.StorageClass='Custom';
RESOLUTION_VAL_MINUS_100.RTWInfo.CustomStorageClass  = 'Define';

RESOLUTION_VAL_50= mpt.Parameter;
RESOLUTION_VAL_50.Value =uint16(50);
RESOLUTION_VAL_50.Min = 0;
RESOLUTION_VAL_50.Max = 255;
RESOLUTION_VAL_50.RTWInfo.StorageClass='Custom';
RESOLUTION_VAL_50.RTWInfo.CustomStorageClass  = 'Define';

RESOLUTION_VAL_64= mpt.Parameter;
RESOLUTION_VAL_64.Value =uint16(64);
RESOLUTION_VAL_64.Min = 0;
RESOLUTION_VAL_64.Max = 255;
RESOLUTION_VAL_64.RTWInfo.StorageClass='Custom';
RESOLUTION_VAL_64.RTWInfo.CustomStorageClass  = 'Define';

RESOLUTION_VAL_103= mpt.Parameter;
RESOLUTION_VAL_103.Value =uint16(103);
RESOLUTION_VAL_103.Min = 0;
RESOLUTION_VAL_103.Max = 255;
RESOLUTION_VAL_103.RTWInfo.StorageClass='Custom';
RESOLUTION_VAL_103.RTWInfo.CustomStorageClass  = 'Define';

VAL_ZERO= mpt.Parameter;
VAL_ZERO.Value =uint8(0);
VAL_ZERO.Min = 0;
VAL_ZERO.Max = 255;
VAL_ZERO.RTWInfo.StorageClass='Custom';
VAL_ZERO.RTWInfo.CustomStorageClass  = 'Define';

C_CANADA= mpt.Parameter;
C_CANADA.Value =uint8(0);
C_CANADA.Min = 0;
C_CANADA.Max = 255;
C_CANADA.RTWInfo.StorageClass='Custom';
C_CANADA.RTWInfo.CustomStorageClass  = 'Define';

C_USA= mpt.Parameter;
C_USA.Value =uint8(1);
C_USA.Min = 0;
C_USA.Max = 255;
C_USA.RTWInfo.StorageClass='Custom';
C_USA.RTWInfo.CustomStorageClass  = 'Define';

C_MEXICO= mpt.Parameter;
C_MEXICO.Value =uint8(2);
C_MEXICO.Min = 0;
C_MEXICO.Max = 255;
C_MEXICO.RTWInfo.StorageClass='Custom';
C_MEXICO.RTWInfo.CustomStorageClass  = 'Define';

C_UK= mpt.Parameter;
C_UK.Value =uint8(4);
C_UK.Min = 0;
C_UK.Max = 255;
C_UK.RTWInfo.StorageClass='Custom';
C_UK.RTWInfo.CustomStorageClass  = 'Define';

C_EUROPE= mpt.Parameter;
C_EUROPE.Value =uint8(5);
C_EUROPE.Min = 0;
C_EUROPE.Max = 255;
C_EUROPE.RTWInfo.StorageClass='Custom';
C_EUROPE.RTWInfo.CustomStorageClass  = 'Define';

C_ADR= mpt.Parameter;
C_ADR.Value =uint8(14);
C_ADR.Min = 0;
C_ADR.Max = 255;
C_ADR.RTWInfo.StorageClass='Custom';
C_ADR.RTWInfo.CustomStorageClass  = 'Define';

C_ECE= mpt.Parameter;
C_ECE.Value =uint8(6);
C_ECE.Min = 0;
C_ECE.Max = 255;
C_ECE.RTWInfo.StorageClass='Custom';
C_ECE.RTWInfo.CustomStorageClass  = 'Define';

C_KOREA= mpt.Parameter;
C_KOREA.Value =uint8(10);
C_KOREA.Min = 0;
C_KOREA.Max = 255;
C_KOREA.RTWInfo.StorageClass='Custom';
C_KOREA.RTWInfo.CustomStorageClass  = 'Define';

AI_TEMP_ADC_COUNT_1891= mpt.Parameter;
AI_TEMP_ADC_COUNT_1891.Value =uint16(1891);
AI_TEMP_ADC_COUNT_1891.Min = 0;
AI_TEMP_ADC_COUNT_1891.Max = 65535;
AI_TEMP_ADC_COUNT_1891.RTWInfo.StorageClass='Custom';
AI_TEMP_ADC_COUNT_1891.RTWInfo.CustomStorageClass  = 'Define';

AI_TEMP_ADC_COUNT_1792= mpt.Parameter;
AI_TEMP_ADC_COUNT_1792.Value =uint16(1792);
AI_TEMP_ADC_COUNT_1792.Min = 0;
AI_TEMP_ADC_COUNT_1792.Max = 65535;
AI_TEMP_ADC_COUNT_1792.RTWInfo.StorageClass='Custom';
AI_TEMP_ADC_COUNT_1792.RTWInfo.CustomStorageClass  = 'Define';

AI_TEMP_ADC_COUNT_1727= mpt.Parameter;
AI_TEMP_ADC_COUNT_1727.Value =uint16(1727);
AI_TEMP_ADC_COUNT_1727.Min = 0;
AI_TEMP_ADC_COUNT_1727.Max = 65535;
AI_TEMP_ADC_COUNT_1727.RTWInfo.StorageClass='Custom';
AI_TEMP_ADC_COUNT_1727.RTWInfo.CustomStorageClass  = 'Define';

AI_TEMP_ADC_COUNT_1586= mpt.Parameter;
AI_TEMP_ADC_COUNT_1586.Value =uint16(1586);
AI_TEMP_ADC_COUNT_1586.Min = 0;
AI_TEMP_ADC_COUNT_1586.Max = 65535;
AI_TEMP_ADC_COUNT_1586.RTWInfo.StorageClass='Custom';
AI_TEMP_ADC_COUNT_1586.RTWInfo.CustomStorageClass  = 'Define';

SPEED_UPDATE_0_28S= mpt.Parameter;
SPEED_UPDATE_0_28S.Value =uint8(14);
SPEED_UPDATE_0_28S.Min = 0;
SPEED_UPDATE_0_28S.Max = 255;
SPEED_UPDATE_0_28S.RTWInfo.StorageClass='Custom';
SPEED_UPDATE_0_28S.RTWInfo.CustomStorageClass  = 'Define';

SPEED_UPDATE_0_5S= mpt.Parameter;
SPEED_UPDATE_0_5S.Value =uint8(25);
SPEED_UPDATE_0_5S.Min = 0;
SPEED_UPDATE_0_5S.Max = 255;
SPEED_UPDATE_0_5S.RTWInfo.StorageClass='Custom';
SPEED_UPDATE_0_5S.RTWInfo.CustomStorageClass  = 'Define';

SPEED_UPDATE_1S= mpt.Parameter;
SPEED_UPDATE_1S.Value =uint8(50);
SPEED_UPDATE_1S.Min = 0;
SPEED_UPDATE_1S.Max = 255;
SPEED_UPDATE_1S.RTWInfo.StorageClass='Custom';
SPEED_UPDATE_1S.RTWInfo.CustomStorageClass  = 'Define';

SPEED_UPDATE_1_5S= mpt.Parameter;
SPEED_UPDATE_1_5S.Value =uint8(75);
SPEED_UPDATE_1_5S.Min = 0;
SPEED_UPDATE_1_5S.Max = 255;
SPEED_UPDATE_1_5S.RTWInfo.StorageClass='Custom';
SPEED_UPDATE_1_5S.RTWInfo.CustomStorageClass  = 'Define';

MIN_SPEED_VALUE= mpt.Parameter;
MIN_SPEED_VALUE.Value =uint16(0);
MIN_SPEED_VALUE.Min = 0;
MIN_SPEED_VALUE.Max = 255;
MIN_SPEED_VALUE.RTWInfo.StorageClass='Custom';
MIN_SPEED_VALUE.RTWInfo.CustomStorageClass  = 'Define';

SPEED_AVG_REF = mpt.Parameter;
SPEED_AVG_REF.Value = [uint16(0) uint16(2000)  uint16(4000)  uint16(5900)  uint16(8000)  uint16(10000)  uint16(12000)  uint16(14000)  uint16(16000)  uint16(18000) uint16(20000) uint16(22000) uint16(24000) uint16(26000) uint16(28000) uint16(30000) uint16(32000) uint16(34000) uint16(36000) uint16(38000) uint16(40000)];
SPEED_AVG_REF.Min  = 0;
SPEED_AVG_REF.Max  = 40000;
SPEED_AVG_REF.RTWInfo.StorageClass = 'Custom';
SPEED_AVG_REF.RTWInfo.CustomStorageClass  = 'ImportFromFile';
SPEED_AVG_REF.RTWInfo.CustomAttributes.HeaderFile  = 'Mdl_Digspeed_table_config.cfg';