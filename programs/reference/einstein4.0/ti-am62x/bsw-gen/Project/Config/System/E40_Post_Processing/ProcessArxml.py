#%VASE-API=2.0% 

import clr
clr.AddReference("GenTool_CsDataServerDomAsr4.dll")
clr.AddReference("GenTool_CsDataServerAsrBase.dll")
from GenTool_CsDataServerDomAsr4.Iface import LEnum, IDomain
from GenTool_CsDataServerDomAsr4.Model import * #Model
from GenTool_CsDataServerDomAsr4.Transfer.Iface.Builder import IBuilder, ICopyBuilder, IMoveBuilder
from GenTool_CsDataServerDomAsr4.Transfer.Iface import ITransferer
clr.AddReferenceToFileAndPath(".\\SwCompUtilityClass.dll")
from SwCompUtilityClass import * 


def Execute():
	print "System Package Name \"{0}\" ".format(SystemPkgName)
	print "Architecture Package Name \"{0}\" ".format(ArchPkgName)
	print "Types Package Path \"{0}\" ".format(TypesPkgPath)
	print "Cmponents Package Path \"{0}\" ".format(ComponentsPkgPath)
	print "DataTypes Package Path \"{0}\" ".format(DataTypesPkgPath)
	
	CompositionComp = model.Find(SystemPkgName)
	TypesArPkgRef = model.Find(TypesPkgPath)
	ComponentsPkgRef = model.Find(ComponentsPkgPath)
	DataTypesArPkgRef = model.Find(DataTypesPkgPath)
	ProgramNameRef = format(ProgramName)
	print "ProgramNameRef \"{0}\" ".format(ProgramName)

	for ArPkg in CompositionComp:
		RemoveCompSwCompHandle(ArPkg,ArchPkgName)

	if ComponentsPkgRef.Count >0:
		ComponentsArPkg = ComponentsPkgRef[0]

	if TypesArPkgRef.Count >0:
		TypesArPkg = TypesArPkgRef[0]
	if DataTypesArPkgRef.Count >0:
		DataTypesArPkg = DataTypesArPkgRef[0]

	CmdDataBaseLists = ParseCommandFile('command-file.txt')
	for i in range(len(CmdDataBaseLists)):
		print "cmdlist \"{0}\" ".format(CmdDataBaseLists[i]['CommandId'])
		if CmdDataBaseLists[i]['CommandId'] == 1:
			RemoveCompositionSwComponent(CompositionComp,CmdDataBaseLists[i])
		if CmdDataBaseLists[i]['CommandId'] == 2:
			ArrayOfStructType(model,TypesArPkg,ComponentsArPkg,CmdDataBaseLists[i])
		if CmdDataBaseLists[i]['CommandId'] == 3:
			ArrayOfStructForSubElement(model,TypesArPkg,ComponentsArPkg,CmdDataBaseLists[i])
		if CmdDataBaseLists[i]['CommandId'] == 4:
			AddInitValueForStructType(model,TypesArPkg,ComponentsArPkg,CmdDataBaseLists[i])
		if CmdDataBaseLists[i]['CommandId'] == 5:
			if ProgramNameRef == "NissanJ32v":
				AddTypeReference(model,DataTypesArPkg,ComponentsArPkg,DataTypesArPkg,ProgramNameRef,CmdDataBaseLists[i])
			else:
				AddTypeReference(model,TypesArPkg,ComponentsArPkg,DataTypesArPkg,ProgramNameRef,CmdDataBaseLists[i])
		if CmdDataBaseLists[i]['CommandId'] == 6:
			AddUCLRunnableandEvent(model,TypesArPkg,ComponentsArPkg,CmdDataBaseLists[i])
		if CmdDataBaseLists[i]['CommandId'] == 7:
			AddEventsForOnDataTxRunnables(model,TypesArPkg,ComponentsArPkg,CmdDataBaseLists[i])
		if CmdDataBaseLists[i]['CommandId'] == 8:
			ChangeRunnableName(model,TypesArPkg,ComponentsArPkg,CmdDataBaseLists[i])
        if CmdDataBaseLists[i]['CommandId'] == 9:
			AddEventsForOnDataTxRunnablesSafe(model,TypesArPkg,ComponentsArPkg,CmdDataBaseLists[i])
        

	
	
	print "Generation completed ..." 


		 
	


Execute()
