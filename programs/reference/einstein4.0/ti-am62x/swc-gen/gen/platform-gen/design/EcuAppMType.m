classdef EcuAppMType < Simulink.IntEnumType
	enumeration
	eEcuAppM_Init(0)
    eEcuAppM_StartRunState(1)
    eEcuAppM_PreGroupActivation(2)
    eEcuAppM_WakeupValidation(3)
	eEcuAppM_StartPowerUpSequence(4)
    eEcuAppM_ReadDataState(5)
    eEcuAppM_GroupsActivation(6)
    eEcuAppM_GroupsDeactivation(7)
    eEcuAppM_BackupData(8)
    eEcuAppM_StartPowerDownSequence(9)
	eEcuAppM_PreGroupDeactivation(10)
    eEcuAppM_SleepTransient(11)
    eEcuAppM_PrepareForSleep(12)
    eEcuAppM_SleepState(13)
   	eEcuAppMState_Count(14)
	end
	methods (Static = true)
		function retVal = getDescription()
			retVal = 'EcuAppMType';
		end
		function retVal = getDefaultValue()
			retVal = EcuAppMType.eEcuAppM_Init;
        end
        function retVal = getDataScope()
            retVal = 'Imported';
        end    
		function retVal = getHeaderFile()
			retVal = 'EcuAppM_Types.h';
        end
		function retVal = addClassNameToEnumNames()
			retVal = false;
		end
	end
end

