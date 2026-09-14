% Signals 

%**************************************************************************
%********************   Tachometer Configuration variables *********************
%**************************************************************************
SPD_THRESHOLD = mpt.Parameter;
SPD_THRESHOLD.Value = uint16(175);
SPD_THRESHOLD.Min  = 0;
SPD_THRESHOLD.Max  = 65535;
SPD_THRESHOLD.RTWInfo.StorageClass = 'Custom';
SPD_THRESHOLD.RTWInfo.CustomStorageClass = 'Define';

TACHO_THRESHOLD = mpt.Parameter;
TACHO_THRESHOLD.Value = uint16(32768);
TACHO_THRESHOLD.Min  = 0;
TACHO_THRESHOLD.Max  = 65535;
TACHO_THRESHOLD.RTWInfo.StorageClass = 'Custom';
TACHO_THRESHOLD.RTWInfo.CustomStorageClass = 'Define';

MCUID0639 = mpt.Parameter;
MCUID0639.Value = uint8(1);
MCUID0639.Min  = 0;
MCUID0639.Max  = 255;
MCUID0639.RTWInfo.StorageClass = 'Custom';
MCUID0639.RTWInfo.CustomStorageClass = 'Define';

MCUID0025_MAX = mpt.Parameter;
MCUID0025_MAX.Value = uint8(6);
MCUID0025_MAX.Min  = 0;
MCUID0025_MAX.Max  = 255;
MCUID0025_MAX.RTWInfo.StorageClass = 'Custom';
MCUID0025_MAX.RTWInfo.CustomStorageClass = 'Define';

VAL_ONE = mpt.Parameter;
VAL_ONE.Value = uint8(1);
VAL_ONE.Min  = 0;
VAL_ONE.Max  = 255;
VAL_ONE.RTWInfo.StorageClass = 'Custom';
VAL_ONE.RTWInfo.CustomStorageClass = 'Define';

VAL_ZERO = mpt.Parameter;
VAL_ZERO.Value = uint8(0);
VAL_ZERO.Min  = 0;
VAL_ZERO.Max  = 255;
VAL_ZERO.RTWInfo.StorageClass = 'Custom';
VAL_ZERO.RTWInfo.CustomStorageClass = 'Define';

MCUID0025 = mpt.Parameter;
MCUID0025.Value = uint8(0);
MCUID0025.Min  = 0;
MCUID0025.Max  = 255;
MCUID0025.RTWInfo.StorageClass = 'Custom';
MCUID0025.RTWInfo.CustomStorageClass = 'Define';

MCUID0640 = mpt.Parameter;
MCUID0640.Value = uint8(2);
MCUID0640.Min  = 0;
MCUID0640.Max  = 255;
MCUID0640.RTWInfo.StorageClass = 'Custom';
MCUID0640.RTWInfo.CustomStorageClass = 'Define';

TACHO_DEBOUNCE_TIME = mpt.Parameter;
TACHO_DEBOUNCE_TIME.Value = uint8(120);
TACHO_DEBOUNCE_TIME.Min  = 0;
TACHO_DEBOUNCE_TIME.Max  = 255;
TACHO_DEBOUNCE_TIME.RTWInfo.StorageClass = 'Custom';
TACHO_DEBOUNCE_TIME.RTWInfo.CustomStorageClass = 'Define';

TACHO_COUNT_INIT = mpt.Parameter;
TACHO_COUNT_INIT.Value = uint8(0);
TACHO_COUNT_INIT.Min  = 0;
TACHO_COUNT_INIT.Max  = 255;
TACHO_COUNT_INIT.RTWInfo.StorageClass = 'Custom';
TACHO_COUNT_INIT.RTWInfo.CustomStorageClass = 'Define';

TACHO_COUNT_ONE = mpt.Parameter;
TACHO_COUNT_ONE.Value = uint8(1);
TACHO_COUNT_ONE.Min  = 0;
TACHO_COUNT_ONE.Max  = 255;
TACHO_COUNT_ONE.RTWInfo.StorageClass = 'Custom';
TACHO_COUNT_ONE.RTWInfo.CustomStorageClass = 'Define';

TACHO_COUNT_TWO = mpt.Parameter;
TACHO_COUNT_TWO.Value = uint8(2);
TACHO_COUNT_TWO.Min  = 0;
TACHO_COUNT_TWO.Max  = 255;
TACHO_COUNT_TWO.RTWInfo.StorageClass = 'Custom';
TACHO_COUNT_TWO.RTWInfo.CustomStorageClass = 'Define';

TACHO_COUNT_THREE_INT = mpt.Parameter;
TACHO_COUNT_THREE_INT.Value = int8(3);
TACHO_COUNT_THREE_INT.Min  = 0;
TACHO_COUNT_THREE_INT.Max  = 127;
TACHO_COUNT_THREE_INT.RTWInfo.StorageClass = 'Custom';
TACHO_COUNT_THREE_INT.RTWInfo.CustomStorageClass = 'Define';

RZ_INIT_VAL = mpt.Parameter;
RZ_INIT_VAL.Value = uint8(52);
RZ_INIT_VAL.Min  = 0;
RZ_INIT_VAL.Max  = 52;
RZ_INIT_VAL.RTWInfo.StorageClass = 'Custom';
RZ_INIT_VAL.RTWInfo.CustomStorageClass = 'Define';

TACHO_VAL_TEN = mpt.Parameter;
TACHO_VAL_TEN.Value = uint8(10);
TACHO_VAL_TEN.Min  = 0;
TACHO_VAL_TEN.Max  = 255;
TACHO_VAL_TEN.RTWInfo.StorageClass = 'Custom';
TACHO_VAL_TEN.RTWInfo.CustomStorageClass = 'Define';

TACHO_VAL_ZERO = mpt.Parameter;
TACHO_VAL_ZERO.Value = uint8(0);
TACHO_VAL_ZERO.Min  = 0;
TACHO_VAL_ZERO.Max  = 255;
TACHO_VAL_ZERO.RTWInfo.StorageClass = 'Custom';
TACHO_VAL_ZERO.RTWInfo.CustomStorageClass = 'Define';

TACHO_VAL_ZERO_U16 = mpt.Parameter;
TACHO_VAL_ZERO_U16.Value = uint16(0);
TACHO_VAL_ZERO_U16.Min  = 0;
TACHO_VAL_ZERO_U16.Max  = 255;
TACHO_VAL_ZERO_U16.RTWInfo.StorageClass = 'Custom';
TACHO_VAL_ZERO_U16.RTWInfo.CustomStorageClass = 'Define';

TACHO_VAL_ZERO_U32 = mpt.Parameter;
TACHO_VAL_ZERO_U32.Value = uint32(0);
TACHO_VAL_ZERO_U32.Min  = 0;
TACHO_VAL_ZERO_U32.Max  = 255;
TACHO_VAL_ZERO_U32.RTWInfo.StorageClass = 'Custom';
TACHO_VAL_ZERO_U32.RTWInfo.CustomStorageClass = 'Define';


TACHO_VAL_ONE = mpt.Parameter;
TACHO_VAL_ONE.Value = uint8(1);
TACHO_VAL_ONE.Min  = 0;
TACHO_VAL_ONE.Max  = 255;
TACHO_VAL_ONE.RTWInfo.StorageClass = 'Custom';
TACHO_VAL_ONE.RTWInfo.CustomStorageClass = 'Define';

TACHO_VAL_THREE = mpt.Parameter;
TACHO_VAL_THREE.Value = uint8(3);
TACHO_VAL_THREE.Min  = 0;
TACHO_VAL_THREE.Max  = 255;
TACHO_VAL_THREE.RTWInfo.StorageClass = 'Custom';
TACHO_VAL_THREE.RTWInfo.CustomStorageClass = 'Define';

TACHO_VAL_ONE_U16 = mpt.Parameter;
TACHO_VAL_ONE_U16.Value = uint16(1);
TACHO_VAL_ONE_U16.Min  = 0;
TACHO_VAL_ONE_U16.Max  = 255;
TACHO_VAL_ONE_U16.RTWInfo.StorageClass = 'Custom';
TACHO_VAL_ONE_U16.RTWInfo.CustomStorageClass = 'Define';

TACHO_VAL_TWENTY = mpt.Parameter;
TACHO_VAL_TWENTY.Value = uint8(20);
TACHO_VAL_TWENTY.Min  = 0;
TACHO_VAL_TWENTY.Max  = 255;
TACHO_VAL_TWENTY.RTWInfo.StorageClass = 'Custom';
TACHO_VAL_TWENTY.RTWInfo.CustomStorageClass = 'Define';

TACHO_ON = mpt.Parameter;
TACHO_ON.Value = boolean(1);
TACHO_ON.Min  = 0;
TACHO_ON.Max  = 1;
TACHO_ON.RTWInfo.StorageClass = 'Custom';
TACHO_ON.RTWInfo.CustomStorageClass = 'Define';

TACHO_OFF = mpt.Parameter;
TACHO_OFF.Value = boolean(0);
TACHO_OFF.Min  = 0;
TACHO_OFF.Max  = 1;
TACHO_OFF.RTWInfo.StorageClass = 'Custom';
TACHO_OFF.RTWInfo.CustomStorageClass = 'Define';

TACHO_GR = mpt.Parameter;
TACHO_GR.Value = uint8(2);
TACHO_GR.Min  = 0;
TACHO_GR.Max  = 255;
TACHO_GR.RTWInfo.StorageClass = 'Custom';
TACHO_GR.RTWInfo.CustomStorageClass = 'Define';

TACHO_REV_PEAK_TIMER_ELAPSED = mpt.Parameter;
TACHO_REV_PEAK_TIMER_ELAPSED.Value = uint8(42);
TACHO_REV_PEAK_TIMER_ELAPSED.Min  = 0;
TACHO_REV_PEAK_TIMER_ELAPSED.Max  = 255;
TACHO_REV_PEAK_TIMER_ELAPSED.RTWInfo.StorageClass = 'Custom';
TACHO_REV_PEAK_TIMER_ELAPSED.RTWInfo.CustomStorageClass = 'Define';

TACHO_GRMN = mpt.Parameter;
TACHO_GRMN.Value = uint8(3);
TACHO_GRMN.Min  = 0;
TACHO_GRMN.Max  = 255;
TACHO_GRMN.RTWInfo.StorageClass = 'Custom';
TACHO_GRMN.RTWInfo.CustomStorageClass = 'Define';

TACHO_FSPORT = mpt.Parameter;
TACHO_FSPORT.Value = uint8(4);
TACHO_FSPORT.Min  = 0;
TACHO_FSPORT.Max  = 255;
TACHO_FSPORT.RTWInfo.StorageClass = 'Custom';
TACHO_FSPORT.RTWInfo.CustomStorageClass = 'Define';

TACHO_F = mpt.Parameter;
TACHO_F.Value = uint8(5);
TACHO_F.Min  = 0;
TACHO_F.Max  = 255;
TACHO_F.RTWInfo.StorageClass = 'Custom';
TACHO_F.RTWInfo.CustomStorageClass = 'Define';

TACHO_070D = mpt.Parameter;
TACHO_070D.Value = uint8(6);
TACHO_070D.Min  = 0;
TACHO_070D.Max  = 255;
TACHO_070D.RTWInfo.StorageClass = 'Custom';
TACHO_070D.RTWInfo.CustomStorageClass = 'Define';

TACHO_COUNT_INIT_U16 = mpt.Parameter;
TACHO_COUNT_INIT_U16.Value = uint16(0);
TACHO_COUNT_INIT_U16.Min  = 0;
TACHO_COUNT_INIT_U16.Max  = 255;
TACHO_COUNT_INIT_U16.RTWInfo.StorageClass = 'Custom';
TACHO_COUNT_INIT_U16.RTWInfo.CustomStorageClass = 'Define';

EQUIPPED_FLAG = mpt.Parameter;
EQUIPPED_FLAG.Value = uint8(1);
EQUIPPED_FLAG.Min  = 0;
EQUIPPED_FLAG.Max  = 255;
EQUIPPED_FLAG.RTWInfo.StorageClass = 'Custom';
EQUIPPED_FLAG.RTWInfo.CustomStorageClass = 'Define';

N1 = mpt.Parameter;
N1.Value = uint16(3);
N1.Min  = 0;
N1.Max  = 65535;
N1.RTWInfo.StorageClass = 'Custom';
N1.RTWInfo.CustomStorageClass = 'Define';

NE_AVG_INIT = mpt.Parameter;
NE_AVG_INIT.Value = uint16(0);
NE_AVG_INIT.Min  = 0;
NE_AVG_INIT.Max  = 65535;
NE_AVG_INIT.RTWInfo.StorageClass = 'Custom';
NE_AVG_INIT.RTWInfo.CustomStorageClass = 'Define';

TACHO_HYS_MIN = mpt.Parameter;
TACHO_HYS_MIN.Value = uint16(10);
TACHO_HYS_MIN.Min  = 0;
TACHO_HYS_MIN.Max  = 65535;
TACHO_HYS_MIN.RTWInfo.StorageClass = 'Custom';
TACHO_HYS_MIN.RTWInfo.CustomStorageClass = 'Define';

TACHO_HYS_MAX = mpt.Parameter;
TACHO_HYS_MAX.Value = uint16(6000);
TACHO_HYS_MAX.Min  = 0;
TACHO_HYS_MAX.Max  = 65535;
TACHO_HYS_MAX.RTWInfo.StorageClass = 'Custom';
TACHO_HYS_MAX.RTWInfo.CustomStorageClass = 'Define';

N2 = mpt.Parameter;
N2.Value = uint16(6);
N2.Min  = 0;
N2.Max  = 65535;
N2.RTWInfo.StorageClass = 'Custom';
N2.RTWInfo.CustomStorageClass = 'Define';

NE1 = mpt.Parameter;
NE1.Value = uint8(0);
NE1.Min  = 0;
NE1.Max  = 255;
NE1.RTWInfo.StorageClass = 'Custom';
NE1.RTWInfo.CustomStorageClass = 'Define';

NE_MET = mpt.Parameter;
NE_MET.Value = uint8(1);
NE_MET.Min  = 0;
NE_MET.Max  = 255;
NE_MET.RTWInfo.StorageClass = 'Custom';
NE_MET.RTWInfo.CustomStorageClass = 'Define';

HV_NE = mpt.Parameter;
HV_NE.Value = uint8(2);
HV_NE.Min  = 0;
HV_NE.Max  = 255;
HV_NE.RTWInfo.StorageClass = 'Custom';
HV_NE.RTWInfo.CustomStorageClass = 'Define';

NE_MET_INVALID = mpt.Parameter;
NE_MET_INVALID.Value = uint16(32768);
NE_MET_INVALID.Min  = 0;
NE_MET_INVALID.Max  = 65535;
NE_MET_INVALID.RTWInfo.StorageClass = 'Custom';
NE_MET_INVALID.RTWInfo.CustomStorageClass = 'Define';

TACHO_INIT_U8 = mpt.Parameter;
TACHO_INIT_U8.Value = uint8(0);
TACHO_INIT_U8.Min  = 0;
TACHO_INIT_U8.Max  = 1;
TACHO_INIT_U8.RTWInfo.StorageClass = 'Custom';
TACHO_INIT_U8.RTWInfo.CustomStorageClass = 'Define';

TACHO_TEN = mpt.Parameter;
TACHO_TEN.Value = uint8(10);
TACHO_TEN.Min  = 0;
TACHO_TEN.Max  = 10;
TACHO_TEN.RTWInfo.StorageClass = 'Custom';
TACHO_TEN.RTWInfo.CustomStorageClass = 'Define';

REDZONE_MIN_VAL = mpt.Parameter;
REDZONE_MIN_VAL.Value = uint8(39);
REDZONE_MIN_VAL.Min  = 0;
REDZONE_MIN_VAL.Max  = 39;
REDZONE_MIN_VAL.RTWInfo.StorageClass = 'Custom';
REDZONE_MIN_VAL.RTWInfo.CustomStorageClass = 'Define';

REDZONE_MAX_VAL = mpt.Parameter;
REDZONE_MAX_VAL.Value = uint8(90);
REDZONE_MAX_VAL.Min  = 0;
REDZONE_MAX_VAL.Max  = 91;
REDZONE_MAX_VAL.RTWInfo.StorageClass = 'Custom';
REDZONE_MAX_VAL.RTWInfo.CustomStorageClass = 'Define';

TACHO_RESOLUTION = mpt.Parameter;
TACHO_RESOLUTION.Value = uint32(78125);
TACHO_RESOLUTION.Min  = 0;
TACHO_RESOLUTION.Max  = 4294967295;
TACHO_RESOLUTION.RTWInfo.StorageClass = 'Custom';
TACHO_RESOLUTION.RTWInfo.CustomStorageClass = 'Define';

TACHO_ENABLE = mpt.Parameter;
TACHO_ENABLE.Value = boolean(1);
TACHO_ENABLE.Min  = 0;
TACHO_ENABLE.Max  = 1;
TACHO_ENABLE.RTWInfo.StorageClass = 'Custom';
TACHO_ENABLE.RTWInfo.CustomStorageClass = 'Define';

TACHO_DISABLE = mpt.Parameter;
TACHO_DISABLE.Value = boolean(0);
TACHO_DISABLE.Min  = 0;
TACHO_DISABLE.Max  = 1;
TACHO_DISABLE.RTWInfo.StorageClass = 'Custom';
TACHO_DISABLE.RTWInfo.CustomStorageClass = 'Define';

TACHO_RES_DIVIDER = mpt.Parameter;
TACHO_RES_DIVIDER.Value = uint32(10000);
TACHO_RES_DIVIDER.Min  = 0;
TACHO_RES_DIVIDER.Max  = 4294967295;
TACHO_RES_DIVIDER.RTWInfo.StorageClass = 'Custom';
TACHO_RES_DIVIDER.RTWInfo.CustomStorageClass = 'Define';

TACHO_RPM_THRESHOLD = mpt.Parameter;
TACHO_RPM_THRESHOLD.Value = uint16(200);
TACHO_RPM_THRESHOLD.Min  = 0;
TACHO_RPM_THRESHOLD.Max  = 65535;
TACHO_RPM_THRESHOLD.RTWInfo.StorageClass = 'Custom';
TACHO_RPM_THRESHOLD.RTWInfo.CustomStorageClass = 'Define';

SIMULATION = Simulink.Variant('mode==1');
CODEGENERATION = Simulink.Variant('mode==2');

PTSYS_CONV = mpt.Parameter;
PTSYS_CONV.Value = uint8(1);
PTSYS_CONV.Min  = 0;
PTSYS_CONV.Max  = 255;
PTSYS_CONV.RTWInfo.StorageClass = 'Custom';
PTSYS_CONV.RTWInfo.CustomStorageClass = 'Define';

PTSYS_S_S = mpt.Parameter;
PTSYS_S_S.Value = uint8(2);
PTSYS_S_S.Min  = 0;
PTSYS_S_S.Max  = 255;
PTSYS_S_S.RTWInfo.StorageClass = 'Custom';
PTSYS_S_S.RTWInfo.CustomStorageClass = 'Define';

PTSYS_HV = mpt.Parameter;
PTSYS_HV.Value = uint8(3);
PTSYS_HV.Min  = 0;
PTSYS_HV.Max  = 255;
PTSYS_HV.RTWInfo.StorageClass = 'Custom';
PTSYS_HV.RTWInfo.CustomStorageClass = 'Define';

PTSYS_PHV = mpt.Parameter;
PTSYS_PHV.Value = uint8(4);
PTSYS_PHV.Min  = 0;
PTSYS_PHV.Max  = 255;
PTSYS_PHV.RTWInfo.StorageClass = 'Custom';
PTSYS_PHV.RTWInfo.CustomStorageClass = 'Define';

PTSYS_EV = mpt.Parameter;
PTSYS_EV.Value = uint8(5);
PTSYS_EV.Min  = 0;
PTSYS_EV.Max  = 255;
PTSYS_EV.RTWInfo.StorageClass = 'Custom';
PTSYS_EV.RTWInfo.CustomStorageClass = 'Define';

PTSYS_MOTORHV = mpt.Parameter;
PTSYS_MOTORHV.Value = uint8(6);
PTSYS_MOTORHV.Min  = 0;
PTSYS_MOTORHV.Max  = 255;
PTSYS_MOTORHV.RTWInfo.StorageClass = 'Custom';
PTSYS_MOTORHV.RTWInfo.CustomStorageClass = 'Define';

PTSYS_FCV = mpt.Parameter;
PTSYS_FCV.Value = uint8(7);
PTSYS_FCV.Min  = 0;
PTSYS_FCV.Max  = 255;
PTSYS_FCV.RTWInfo.StorageClass = 'Custom';
PTSYS_FCV.RTWInfo.CustomStorageClass = 'Define';

PTSYS_48V = mpt.Parameter;
PTSYS_48V.Value = uint8(8);
PTSYS_48V.Min  = 0;
PTSYS_48V.Max  = 255;
PTSYS_48V.RTWInfo.StorageClass = 'Custom';
PTSYS_48V.RTWInfo.CustomStorageClass = 'Define';

PTSYS_DEFAULT = mpt.Parameter;
PTSYS_DEFAULT.Value = uint8(0);
PTSYS_DEFAULT.Min  = 0;
PTSYS_DEFAULT.Max  = 255;
PTSYS_DEFAULT.RTWInfo.StorageClass = 'Custom';
PTSYS_DEFAULT.RTWInfo.CustomStorageClass = 'Define';