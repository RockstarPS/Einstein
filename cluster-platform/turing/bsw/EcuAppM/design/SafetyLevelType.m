classdef SafetyLevelType < Simulink.IntEnumType
	enumeration
	eSafetyLevel_QM(0)
    eSafetyLevel_ASILA(1)
    eSafetyLevel_ASILB(2)
    eSafetyLevel_ASILC(3)
    eSafetyLevel_ASILD(4)
    eSafetyLevel_MaxCount(5)
	end
	methods (Static = true)
		function retVal = getDescription()
			retVal = 'SafetyLevelType';
		end
		function retVal = getDefaultValue()
			retVal = SafetyLevelType.eSafetyLevel_QM;
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