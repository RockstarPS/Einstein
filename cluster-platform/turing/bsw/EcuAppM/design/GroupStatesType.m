classdef GroupStatesType < Simulink.IntEnumType
	enumeration
	eGroup_StateOff(0)
	eGroup_StateInit(1)
    eGroup_StateActivation(2)
    eGroup_StateActive(3)
    eGroup_StateDeactivation(4)
	eGroup_StateInactive(5)
    eGroup_StateMaxCount(6)
	end
	methods (Static = true)
		function retVal = getDescription()
			retVal = 'GroupStatesType';
		end
		function retVal = getDefaultValue()
			retVal = GroupStatesType.eGroup_StateOff;
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

