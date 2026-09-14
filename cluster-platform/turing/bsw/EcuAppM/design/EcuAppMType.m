classdef EcuAppMType < Simulink.IntEnumType
	enumeration
	eEcuAppM_Init(0)
    eEcuAppM_PreGroupActivation(1)
    eEcuAppM_WakeupValidation(2)
	eEcuAppM_StartPowerUpSequence(3)
    eEcuAppM_ReadDataState(4)
    eEcuAppM_GroupsActivation(5)
    eEcuAppM_GroupsDeactivation(6)
    eEcuAppM_BackupData(7)
    eEcuAppM_StartPowerDownSequence(8)
	eEcuAppM_PreGroupDeactivation(9)
    eEcuAppM_SleepTransient(10)
    eEcuAppM_SleepState(11)
   	eEcuAppMState_Count(12)
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

