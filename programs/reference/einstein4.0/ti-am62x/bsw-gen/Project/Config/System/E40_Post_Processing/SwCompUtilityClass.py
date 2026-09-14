#%VASE-API=2.0% 

import clr
clr.AddReference("GenTool_CsDataServerDomAsr4.dll")
clr.AddReference("GenTool_CsDataServerAsrBase.dll")
from GenTool_CsDataServerDomAsr4.Iface import LEnum, IDomain
from GenTool_CsDataServerDomAsr4.Model import * #Model
from GenTool_CsDataServerDomAsr4.Transfer.Iface.Builder import IBuilder, ICopyBuilder, IMoveBuilder
from GenTool_CsDataServerDomAsr4.Transfer.Iface import ITransferer
import re


CommandStrExp = "(\s*\[\s*)+(.*)+(\s*\]\s*)" 
CommandDataExp = "(\s*\w*\s*)+(\=\s*\w*\s*)"

CommandList = {
	"RemoveCompositionSwComponent" : 1,
	"ArrayOfStructType"            : 2,
	"ArrayOfStructForSubElement"   : 3,
	"AddInitValueForStructType"	   : 4,
	"AddTypeReference"	   : 5,
	"AddUCLRunnableandEvent"	: 6,
	"AddEventsForOnDataTxRunnables"	: 7,
	"ChangeRunnableName"	: 8,
    "AddEventsForOnDataTxRunnablesSafe"	: 9

}

CommandDataAttributes = {
	 1 : ["SwComponentName"],
	 2 : ["PortName","SrcDataType","Size"],
	 3 : ["PortName","SrcDataType","DstDataType","Size"],
	 4 : ["PortName","SrcDataType"],
	 5 : ["SrcDataType","DstDataType"],
	 6 : ["AswcName","RunnableName","PortName","PortType","InterfaceName","DataElementName"],
	 7 : ["AswcName"],
	 8 : ["AswcName","RunnableName", "NewRunnableName"],
     9 : ["AswcName"]
}

class CGeneralFreeType():
	pass 


def	GetAppSwCompHandle(ArPkg,AppSwCompName):

	''' Retrieve given ASWC's information from list of  AR-PACKAGE '''
	AppSwcRef = []
	if hasattr(ArPkg, "ElementList"):
		for element in ArPkg.ElementList:
			if type(element) is VApplicationSwComponentType and element.ShortName == AppSwCompName:
				AppSwcRef = element
				break
	return AppSwcRef


def	GetCompSwCompHandle(ArPkg,CompSwCompName):

	''' Retrieve given ASWC's information from list of  AR-PACKAGE '''
	CompSwcRef = []
	if hasattr(ArPkg, "ElementList"):
		for element in ArPkg.ElementList:
			if type(element) is VCompositionSwComponentType and element.ShortName == CompSwCompName:
				CompSwcRef = element
				break
	return CompSwcRef

def	RemoveCompSwCompHandle(ArPkg,CompSwCompName):

	''' Retrieve given ASWC's information from list of  AR-PACKAGE '''
	CompSwcRef = []
	result = False
	CompSwcRef = GetCompSwCompHandle(ArPkg,CompSwCompName)
	if CompSwcRef: 
		CompSwcRef.DeleteAndRemoveFromOwner()
		result = True
	
	return result 		
		
        
def	GetRportHandle(AppSwcHandle,PortName):

	''' Retrieve given Rport information from ASWC '''

	PortRef = []
	if hasattr(AppSwcHandle, "PortList"):
		for port in AppSwcHandle.PortList:
			if ((type(port) is VRPortPrototype and port.ShortName == PortName) \
			or (type(port) is VPPortPrototype and port.ShortName == PortName)):
				PortRef = port
				break
	return PortRef

 
		

def	GetSwImplBehaviorHandle(ArPkg,AppSwcHandle):
	
	''' Read internal behvaior handle for the  ASWC '''

	SwcIBRef = []
	if hasattr(ArPkg, "ElementList"):
		for element in ArPkg.ElementList:
			if element.ShortName == "IMPL_" + AppSwcHandle.ShortName:
				if type(element.Behavior) is VSwcInternalBehavior_Ref:
					SwcIB = element.Find(element.Behavior.Value)
			   		if SwcIB.Count >0:
			   			SwcIBRef = SwcIB[0]
						break

	return SwcIBRef 
	
def GetOperationHandle(ArPkg,InterfaceName,DataElementName):

	''' Read Operation handle from the given Interface  '''
	
	OperationRef = []
	
	if hasattr(ArPkg, "ElementList"):
		for element in ArPkg.ElementList:
			if element.ShortName == InterfaceName:
				if hasattr(element, "OperationList"):
					for Operation in element.OperationList:
						if Operation.ShortName == DataElementName:
							OperationRef = Operation
							break  

	return OperationRef
def GetDataElementHandle(ArPkg,InterfaceName,DataElementName):

	''' Read Data element handle from the given Interface  '''
	
	VariableDataElementRef = []
	
	if hasattr(ArPkg, "ElementList"):
		for element in ArPkg.ElementList:
			if element.ShortName == InterfaceName:
				if hasattr(element, "DataElementList"):
					for VariableDataElement in element.DataElementList:
						if VariableDataElement.ShortName == DataElementName:
							VariableDataElementRef = VariableDataElement
							break  

	return VariableDataElementRef


def ReadArpkgInfo(ArPkg,TypeName):

	TypeRefObj = None

	if hasattr(ArPkg, "ElementList"):
		if ArPkg.ElementList.Count > 0:
			TypeRefObj = ReadTypeInfo(ArPkg,TypeName)

	if hasattr(ArPkg, "ArPackageList"):
		if ArPkg.ArPackageList.Count > 0:
			for ChildArPkg in ArPkg.ArPackageList:
				if TypeRefObj is None: 
					TypeRefObj = ReadArpkgInfo(ChildArPkg,TypeName)
					if TypeRefObj is not None:
						if TypeRefObj.ShortName == TypeName:
							return TypeRefObj
				else:
					break 
	return TypeRefObj


def ReadTypeInfo(ArPkg,TypeName):

	TyepRefHandle = None
	if hasattr(ArPkg, "ElementList"):
		for element in ArPkg.ElementList:
			if type(element) is VImplementationDataType and element.ShortName == TypeName:
				TyepRefHandle = element
											  
	return TyepRefHandle 				

def GetElementObj(ArPkg,Name,ElementType):

	ElementObj = None
	if hasattr(ArPkg, "ElementList"):
		for element in ArPkg.ElementList:
			if type(element) is ElementType and element.ShortName == Name:
				ElementObj = element
											  
	return ElementObj 				
		


def AddRunnable(SwcImplBehaviorHandle,RunnableName):

	''' Adds New Runnable and return its handle '''
	
	RunnableDataRef = []
	RunnableDataRef = SwcImplBehaviorHandle.AddNewRunnable()
	RunnableDataRef.ShortName = RunnableName
	RunnableDataRef.Symbol = RunnableName 
	RunnableDataRef.CanBeInvokedConcurrently = True
	
	return RunnableDataRef

	

def AddRteEvent(AppSwcHandle,SwcImplBehaviorHandle,RunnableDataHandle,PortHandle,DataElement,PortType,InterfaceName,TypesArPkg):
												  
	EventDataRef = []
	if not DataElement:
		return EventDataRef
	
	if PortType == "RPortProtoType":
		DataElementHandle = GetDataElementHandle(TypesArPkg,InterfaceName,DataElement)
		# Add Event 
		EventDataRef = SwcImplBehaviorHandle.AddNewEventAsDataReceivedEvent() 
		EventDataRef.ShortName = "DRE" + RunnableDataHandle.ShortName + "TrigBy"  + DataElementHandle.ShortName

		
		# Add Referrence to Receive port for Event Reception  
		EventDataRef.DataSpecified = True
		EventDataRef.Data.ContextRPortSpecified = True
		EventDataRef.Data.ContextRPort.DestType = PortHandle.IdType
		EventDataRef.Data.ContextRPort.Value = PortHandle.AsrPath
		# Refer to Event data
		EventDataRef.Data.TargetDataElementSpecified = True
		EventDataRef.Data.TargetDataElement.DestType = DataElementHandle.IdType 
		EventDataRef.Data.TargetDataElement.Value = DataElementHandle.AsrPath
		print "EventDataRef: name \"{0}\"".format(EventDataRef)
		#Upon Event reception Trigger the runnable 
		EventDataRef.StartOnEventSpecified = True	
		EventDataRef.StartOnEvent.DestType = RunnableDataHandle.IdType 
		EventDataRef.StartOnEvent.Value = RunnableDataHandle.AsrPath
		
		return EventDataRef
	if PortType == "PPortProtoType":
		DataElementHandle = GetOperationHandle(TypesArPkg,InterfaceName,DataElement)
		# Add Event 
		EventDataRef = SwcImplBehaviorHandle.AddNewEventAsOperationInvokedEvent() 
		EventDataRef.ShortName = "OIE" + RunnableDataHandle.ShortName + "TrigBy"  + DataElementHandle.ShortName
		
		# Add Referrence to Receive port for Event Reception  
		EventDataRef.OperationSpecified = True
		EventDataRef.Operation.ContextPPortSpecified = True
		EventDataRef.Operation.ContextPPort.DestType = PortHandle.IdType
		EventDataRef.Operation.ContextPPort.Value = PortHandle.AsrPath
		# Refer to Event operation
		EventDataRef.Operation.TargetProvidedOperationSpecified = True
		EventDataRef.Operation.TargetProvidedOperation.DestType = DataElementHandle.IdType 
		EventDataRef.Operation.TargetProvidedOperation.Value = DataElementHandle.AsrPath

		print "EventDataRef: name \"{0}\"".format(EventDataRef)
		#Upon Event reception Trigger the runnable 
		EventDataRef.StartOnEventSpecified = True	
		EventDataRef.StartOnEvent.DestType = RunnableDataHandle.IdType 
		EventDataRef.StartOnEvent.Value = RunnableDataHandle.AsrPath
		
		return EventDataRef



def AddDataReceivePointForRunnable(RunnableDataHandle,RportHandle,DataElementHandle):

	NewDataReceivePointDataRef = []
	if not DataElementHandle:
		return NewDataReceivePointDataRef

	NewDataReceivePointDataRef = RunnableDataHandle.AddNewDataReceivePointByArgument()
	NewDataReceivePointDataRef.ShortName = "DRA" + "_" + RportHandle.ShortName + "_" + DataElementHandle.ShortName

	NewDataReceivePointDataRef.AccessedVariableSpecified = True
	NewDataReceivePointDataRef.AccessedVariable.AutosarVariableSpecified = True
	NewDataReceivePointDataRef.AccessedVariable.AutosarVariable.PortPrototypeSpecified = True
	NewDataReceivePointDataRef.AccessedVariable.AutosarVariable.PortPrototype.DestType = RportHandle.IdType
	NewDataReceivePointDataRef.AccessedVariable.AutosarVariable.PortPrototype.Value = RportHandle.AsrPath

	NewDataReceivePointDataRef.AccessedVariable.AutosarVariable.TargetDataPrototypeSpecified = True
	NewDataReceivePointDataRef.AccessedVariable.AutosarVariable.TargetDataPrototype.DestType = DataElementHandle.IdType 
	NewDataReceivePointDataRef.AccessedVariable.AutosarVariable.TargetDataPrototype.Value = DataElementHandle.AsrPath 
	
	return NewDataReceivePointDataRef
	
def GetDataTypeInfo(root,TypeName):
 
	TypeRefObj = ReadArpkgInfo(root,TypeName)
	return TypeRefObj

def AddNewSwDataDefPropsVariantAsRef(SwDataDefProps,DataTypeObj):
	
	''' Adds new data properties variant '''

	NewSwDataDefPropsConditional = SwDataDefProps.AddNewSwDataDefPropsVariant()
	NewSwDataDefPropsConditional.ImplementationDataTypeSpecified = True
	NewSwDataDefPropsConditional.ImplementationDataType.DestType = DataTypeObj.IdType
	NewSwDataDefPropsConditional.ImplementationDataType.Value = DataTypeObj.AsrPath 


def SetSwDataDefProperties(element,DesTypeRefObj):
	
	RemoveTypes = []
	element.Category = "TYPE_REFERENCE" 
	SwDataDefProps = element.SwDataDefProps
	for SwDataDefPropsConditional in SwDataDefProps.SwDataDefPropsVariantList:
		if type(SwDataDefPropsConditional.BaseType) is VSwBaseType_Ref or \
		((type(SwDataDefPropsConditional.ImplementationDataType) is VImplementationDataType_Ref) or
        (type(SwDataDefPropsConditional.ImplementationDataType) is VAbstractImplementationDataType_Ref)):
			RemoveTypes.Add(SwDataDefPropsConditional)

	for RemoveType in RemoveTypes:
		SwDataDefProps.RemoveSwDataDefPropsVariant(RemoveType)
			
	AddNewSwDataDefPropsVariantAsRef(SwDataDefProps,DesTypeRefObj)



def ChangeSwDataDefProperties(ArPkg,element,DesTypeRefObj,SrcTypeName):
	
	if hasattr(element, "SubElementList"):
		
		for SubElement in element.SubElementList:
			SwDataDefPropsClass = ReadSwDataDefProperties(ArPkg,SubElement)
			if hasattr(SwDataDefPropsClass, "ImplTypeObj") and SwDataDefPropsClass.ImplTypeObj is not None:
				if SwDataDefPropsClass.ImplTypeObj.ShortName == SrcTypeName:
					SetSwDataDefProperties(SubElement,DesTypeRefObj)
			elif hasattr(SwDataDefPropsClass, "BaseTypeObj") and SwDataDefPropsClass.BaseTypeObj is not None:
				SetSwDataDefProperties(SubElement,DesTypeRefObj)
	else:
		
		SwDataDefPropsClass = ReadSwDataDefProperties(ArPkg,SubElement)
		if hasattr(SwDataDefPropsClass, "ImplTypeObj") and SwDataDefPropsClass.ImplTypeObj is not None:
			if SwDataDefPropsClass.ImplTypeObj.ShortName == SrcTypeName:
				SetSwDataDefProperties(element,DesTypeRefObj)

def CreateArrayType(ArPkg,DataTypeObj,size):

	''' Creates Array data type from the existing implementation type '''

	ArrayTypeObj = None
	ArrObj = None
	if ArPkg is not None and DataTypeObj is not None:
		if type(DataTypeObj) is VImplementationDataType or type(DataTypeObj) is VSwBaseType:
			name = DataTypeObj.ShortName+"_"+str(size)
			ArrObj = GetDataTypeInfo(ArPkg,name)
			if ArrObj is None:  
				ArrayTypeObj = ArPkg.AddNewElementAsImplementationDataType()
				ArrayTypeObj.ShortName = DataTypeObj.ShortName+"_"+str(size)
				ArrayTypeObj.Category = "ARRAY"
				element = ArrayTypeObj.AddNewSubElement()   	
	 			element.ShortName = "ArrayElement"
				element.Category = "TYPE_REFERENCE"
				element.ArraySizeSpecified = True
				element.ArraySizeSemanticsSpecified = True
				element.ArraySize.Value = str(size)
				element.SwDataDefPropsSpecified	= True
				AddNewSwDataDefPropsVariantAsRef(element.SwDataDefProps,DataTypeObj)
			else:
				ArrayTypeObj = ArrObj 
	
	return ArrayTypeObj 
    
def CreateRecordType(ArPkg,DataTypesArPkg):

	''' Creates new Record data type '''

	RecordTypeObj = None
	RecObj = None

	
	name = "t_vSwUpdM_Segment_Attributes"
	RecObj = GetDataTypeInfo(ArPkg,name)
	print"RecObj \"{0}\"  \"{1}\" ".format(RecObj,name)
	if RecObj is None:  
		RecordTypeObj = ArPkg.AddNewElementAsImplementationDataType()
		RecordTypeObj.ShortName = name
		RecordTypeObj.Category = "STRUCTURE"
		element = RecordTypeObj.AddNewSubElement()   	
		element.ShortName = "StartAddress"
		element.Category = "TYPE_REFERENCE"
		eleuint32 = "Uint32"
		elementObj = GetDataTypeInfo(DataTypesArPkg,eleuint32)
		print"elementObj \"{0}\" ".format(elementObj)
		element.SwDataDefPropsSpecified	= True
		AddNewSwDataDefPropsVariantAsRef(element.SwDataDefProps,elementObj)
	else:
		RecordTypeObj = RecObj 

	return RecordTypeObj 


def MapDataType(ArPkg,SrcTypeName, DesTypeName):
 

	SrcTypeRefObj = GetDataTypeInfo(ArPkg,SrcTypeName)

	if SrcTypeRefObj is not None: 
		DesTypeRefObj = GetDataTypeInfo(ArPkg,DesTypeName)
		if DesTypeRefObj is not None:
			ChangeSwDataDefProperties(ArPkg,SrcTypeRefObj,DesTypeRefObj,SrcTypeName)
			print "Updated data type reference of source type \"{0}\" to destination type \"{1}\"".format(SrcTypeName, DesTypeName)
		else:
			print "Error : Destination Type name not found !!!!"
	else:
		print "Error : Source Type name not found !!!!"

def CreateSRInterfaceType(ArPkg,DataTypeObj):
	
	SRObj = None
	if ArPkg and DataTypeObj is not None:
		name = "If"+DataTypeObj.ShortName
 		SRObjh = GetElementObj(ArPkg,name,VSenderReceiverInterface)
		if SRObjh is None:
			SRObj = ArPkg.AddNewElementAsSenderReceiverInterface()
			SRObj.ShortName = name 
			VariableDataPrototype = SRObj.AddNewDataElement()
			VariableDataPrototype.ShortName = DataTypeObj.ShortName +"_tData"
			VariableDataPrototype.SwDataDefPropsSpecified = True 
			AddNewSwDataDefPropsVariantAsRef(VariableDataPrototype.SwDataDefProps,DataTypeObj)
		else:
			SRObj = SRObjh 	

	return SRObj  


def CreateArrayOfSrcType(ArPkg,SrcTypeName,size):

	ArrayTypeObj = None
	DataTypeObj = GetDataTypeInfo(ArPkg,SrcTypeName)
	if DataTypeObj is not None:
		ArrayTypeObj = CreateArrayType(ArPkg,DataTypeObj,size)	
	else:
		print "Error : source Type name not found !!!"
	
	return ArrayTypeObj	

def CreateArrayOfStructConstantSpec(ArPkg,DstArPkg,DataTypeObj,ConstSpecObj):
	# print "DataTypeObj \"{0}\" \"{1}\" ".format(DataTypeObj.Category, ConstSpecObj)
	if DataTypeObj is not None:
		if DataTypeObj.Category == "STRUCTURE":
			if ConstSpecObj is not None:
				# print "ConstSpecObj111 \"{0}\" ".format(ConstSpecObj)
				RecordValueSpecObj = ConstSpecObj.NewValueSpecAsRecordValueSpecification()
				RecordValueSpecObj.ShortLabel = ConstSpecObj.ShortName 	
				if hasattr(DataTypeObj, "SubElementList"):
					for element  in DataTypeObj.SubElementList:
						SwDataDefPropsClass = ReadSwDataDefProperties(ArPkg,element)
						if hasattr(SwDataDefPropsClass, "ImplTypeObj") and SwDataDefPropsClass.ImplTypeObj is not None:
							if SwDataDefPropsClass.ImplTypeObj.Category == "ARRAY":
								CreateArrayConstantSpec(ArPkg,DstArPkg,SwDataDefPropsClass.ImplTypeObj,RecordValueSpecObj,"FieldType")	
							elif SwDataDefPropsClass.ImplTypeObj.Category == "STRUCTURE":
								name = SwDataDefPropsClass.ImplTypeObj.ShortName
								AddNewFieldAsRecordValueSpecification(ArPkg,SwDataDefPropsClass.ImplTypeObj,RecordValueSpecObj,NameMangling=None)
							else:
								FindElementTypeAndAddValueSpec(ArPkg,RecordValueSpecObj,element)
								


def CreateArrayConstantSpec(ArPkg,DstArPkg,ArrayTypeObj,ValueSpecObj,ValueSpecType=None):
	
	if ArrayTypeObj is not None: 
		if type(ArrayTypeObj) is VImplementationDataType:
			if hasattr(ArrayTypeObj, "SubElementList"):
		   		for SubElement in ArrayTypeObj.SubElementList:
					if hasattr(SubElement, "ArraySize"):
						if SubElement.ArraySizeSpecified == True:
							ArraySize = SubElement.ArraySize.Value
							SwDataDefPropsClass = ReadSwDataDefProperties(ArPkg,SubElement)

	if hasattr(SwDataDefPropsClass, "ImplTypeObj") and SwDataDefPropsClass.ImplTypeObj is not None:
		name = ArrayTypeObj.ShortName+"_InitValue"
		if ArraySize is not None:
			if ValueSpecType is None: 
				ArrayValueSpecObj = ValueSpecObj.NewValueSpecAsArrayValueSpecification()
			else:
				ArrayValueSpecObj = ValueSpecObj.AddNewFieldAsArrayValueSpecification()
			ArrayValueSpecObj.ShortLabel = name 
			for item in range(int(ArraySize)): 
				if SwDataDefPropsClass.ImplTypeObj.Category == "STRUCTURE":
					AddRecordValueSpec(ArPkg,ArrayValueSpecObj,SwDataDefPropsClass.ImplTypeObj,item)

	if hasattr(SwDataDefPropsClass, "BaseTypeObj") and SwDataDefPropsClass.BaseTypeObj is not None:
		name = ArrayTypeObj.ShortName+"_InitValue2"
		if ArraySize is not None:
			if ValueSpecType is None: 
				ArrayValueSpecObj = ValueSpecObj.NewValueSpecAsArrayValueSpecification()
			else:
				ArrayValueSpecObj = ValueSpecObj.AddNewFieldAsArrayValueSpecification()
			ArrayValueSpecObj.ShortLabel = name 
			for item in range(int(ArraySize)): 
				if SwDataDefPropsClass.BaseTypeObj.Category == "STRUCTURE":
					AddRecordValueSpec(ArPkg,ArrayValueSpecObj,SwDataDefPropsClass.ImplTypeObj,item)
				else:
					AddNewElementAsNumericalValueSpecification(ArrayValueSpecObj,name,0)





def AddNewElementAsConstantSpecification(DstArPkg,Name):
	
	ConstSpecObjh = DstArPkg.AddNewElementAsConstantSpecification() 
	ConstSpecObjh.ShortName = Name
	ConstSpecObjh.ValueSpecSpecified = True

	return ConstSpecObjh 
	




def AddRecordValueSpec(ArPkg,ValueSpecObj,TypeObj,NameMangling=None):
	RecordValueSpecObj = ValueSpecObj.AddNewElementAsRecordValueSpecification()	 
	if hasattr(TypeObj, "SubElementList"):
		for element  in TypeObj.SubElementList:
			if NameMangling is not None:
				name = element.ShortName+"_Init_Value_"+str(NameMangling)
			else:
				name = element.ShortName+"_Init_Value_"
			FindElementTypeAndAddValueSpec(ArPkg,RecordValueSpecObj,element,name)



def AddNumericValueSpec(ValueSpecObj,name,value):
	NumericalValueSpecObj = ValueSpecObj.AddNewFieldAsNumericalValueSpecification()
	NumericalValueSpecObj.ShortLabel = name 
	addValue(NumericalValueSpecObj,value)

def AddTextValueSpec(ValueSpecObj,name,value):
	TextValueSpecObj = ValueSpecObj.AddNewFieldAsTextValueSpecification()
	TextValueSpecObj.ShortLabel = name
	addValue(TextValueSpecObj,value)

def AddNewElementAsTextValueSpecification(ValueSpecObj,name,value):
	TextValueSpecObj = ValueSpecObj.AddNewElementAsTextValueSpecification()
	TextValueSpecObj.ShortLabel = name
	addValue(TextValueSpecObj,value)	 


def AddNewElementAsNumericalValueSpecification(ValueSpecObj,name,value):
	NumericalValueSpecObj = ValueSpecObj.AddNewElementAsNumericalValueSpecification()
	NumericalValueSpecObj.ShortLabel = name 
	addValue(NumericalValueSpecObj,value)


def AddNewFieldAsRecordValueSpecification(ArPkg,TypeObj,ValueSpecObj,NameMangling=None):
	RecordValueSpecObj = ValueSpecObj.AddNewFieldAsRecordValueSpecification()	 
	if hasattr(TypeObj, "SubElementList"):
		for element  in TypeObj.SubElementList:
			if NameMangling is not None:
				name = element.ShortName+"_Init_Value_"+str(NameMangling)
			else:
				name = element.ShortName+"_Init_Value_"
			ElementSwDataDefPropsClass = ReadSwDataDefProperties(ArPkg,element)
			if hasattr(ElementSwDataDefPropsClass, "CompuMethodObj") and ElementSwDataDefPropsClass.CompuMethodObj is not None:
				#AddTextValueSpec(RecordValueSpecObj,name,0)
				AddNumericValueSpec(RecordValueSpecObj,name,0)
			elif hasattr(ElementSwDataDefPropsClass, "ImplTypeObj") and ElementSwDataDefPropsClass.ImplTypeObj is not None:
				
				if ElementSwDataDefPropsClass.ImplTypeObj.Category == "ARRAY":
					CreateArrayConstantSpec(ArPkg,TypeObj,ElementSwDataDefPropsClass.ImplTypeObj,RecordValueSpecObj,"FieldType")
				else:
					AddNumericValueSpec(RecordValueSpecObj,name,0)





def addValue(ValueSpecObj,value):
	ValueSpecObj.ValueSpecified = True
	if type(ValueSpecObj.Value) is str:
		ValueSpecObj.Value = str(value)
	else:
		# Numerical values/non-string values have a container that stores the actual value
		ValueSpecObj.Value.Value = str(value)


def FindElementTypeAndAddValueSpec(ArPkg,ValueSpecObj,TypeObj,NameMangling=None):
	
	if type(TypeObj) is VImplementationDataTypeElement:
		SwDataDefPropsClass = ReadSwDataDefProperties(ArPkg,TypeObj)
		if NameMangling is not None:
			name = NameMangling
		else:
			name = TypeObj.ShortName+"_Init_Value"

		if hasattr(SwDataDefPropsClass, "CompuMethodObj") and SwDataDefPropsClass.CompuMethodObj is not None:
			#AddTextValueSpec(ValueSpecObj,name,0)
			AddNumericValueSpec(ValueSpecObj,name,0)
		else:
			if hasattr(SwDataDefPropsClass, "ImplTypeObj") and SwDataDefPropsClass.ImplTypeObj is not None:
				if SwDataDefPropsClass.ImplTypeObj.Category == "TYPE_REFERENCE" or SwDataDefPropsClass.ImplTypeObj.Category == "VALUE": 
					AddNumericValueSpec(ValueSpecObj,name,0)
				elif SwDataDefPropsClass.ImplTypeObj.Category == "STRUCTURE":
					AddNewFieldAsRecordValueSpecification(ArPkg,SwDataDefPropsClass.ImplTypeObj,ValueSpecObj,NameMangling)
				else:
					if hasattr(SwDataDefPropsClass.ImplTypeObj,"SubElementList"):
		   				for element in SwDataDefPropsClass.ImplTypeObj.SubElementList:
							if SwDataDefPropsClass.ImplTypeObj.Category == "ARRAY" and hasattr(element, "ArraySize") :
								if element.ArraySizeSpecified == True:
									size = element.ArraySize.Value
									ElementSwDataDefPropsClass = ReadSwDataDefProperties(ArPkg,element)
									ArrayValueSpecObj = ValueSpecObj.AddNewFieldAsArrayValueSpecification()
									for item in range(int(size)):
										if NameMangling is not None:
											name = NameMangling+str(item)
										else:
											name = TypeObj.ShortName+"_Init_Value_"+str(item)
										# if hasattr(ElementSwDataDefPropsClass, "CompuMethodObj") and ElementSwDataDefPropsClass.CompuMethodObj is not None:
											# AddNewElementAsTextValueSpecification(ArrayValueSpecObj,name,0)
							 			# else:
										AddNewElementAsNumericalValueSpecification(ArrayValueSpecObj,name,0)
					



						
def GetInterfaceObjsOfDataType(ArPkg,SrcTypeName):

	InterfaceObjs = []
	DataTypeObj = GetDataTypeInfo(ArPkg,SrcTypeName)
	if DataTypeObj is not None:
		if hasattr(DataTypeObj, "ReferencedFromList"):
			for referencedBy in DataTypeObj.ReferencedFromList:
				if type(referencedBy.Owner.Parent) is VSenderReceiverInterface:
					InterfaceObjs.Add(referencedBy.Owner.Parent) 	
	
	return InterfaceObjs

def GetPortObjsListForIfType(IfObj):

	PortObjs = []
	if IfObj is not None:
		if hasattr(IfObj, "ReferencedFromList"):
			for referencedBy in IfObj.ReferencedFromList:
				if type(referencedBy.Owner) is VRPortPrototype or type(referencedBy.Owner) is VPPortPrototype:
					PortObjs.Add(referencedBy.Owner) 	
	
	return PortObjs

def GetRefObjsListForPortObj(PortObj):

	RefObjs = []
	if PortObj is not None:
		if hasattr(PortObj, "ReferencedFromList"):
			for referencedBy in PortObj.ReferencedFromList:
					RefObjs.Add(referencedBy.Owner) 	
	
	return RefObjs

def GetBaseDataTypeObj(ArPkg,DataPropsObj):

	BaseTypeObj = None
	if type(DataPropsObj.BaseType) is VSwBaseType_Ref:
		BaseTypeRef = ArPkg.Find(DataPropsObj.BaseType.Value)
	   	if BaseTypeRef.Count >0:
	   		BaseTypeObj = BaseTypeRef[0]
	
	return BaseTypeObj


def GetImplDataTypeObj(ArPkg,DataPropsObj):

	ImplTypeObj = None

	if ((type(DataPropsObj.ImplementationDataType) is VImplementationDataType_Ref) or
	(type(DataPropsObj.ImplementationDataType) is VAbstractImplementationDataType_Ref)):
		ImplementationDataTypeRef = ArPkg.Find(DataPropsObj.ImplementationDataType.Value)
	   	if ImplementationDataTypeRef.Count >0:
	   		ImplTypeObj = ImplementationDataTypeRef[0]
		# print "ImplTypeObj\"{0}\" ".format(ImplTypeObj)
	return ImplTypeObj 


def GetCompuMethodObj(ArPkg,DataPropsObj):
	CompuMethodObj = None
	if type(DataPropsObj.CompuMethod) is VCompuMethod_Ref:
		CompuMethodRef = ArPkg.Find(DataPropsObj.CompuMethod.Value)
	   	if CompuMethodRef.Count >0:
	   		CompuMethodObj = CompuMethodRef[0]
	return CompuMethodObj 



					

def ReadSwDataDefProperties(ArPkg,DataTypeObj):

	TypeObj = None
	#Creating free class type
	SwDataDefPropsClass = CGeneralFreeType()
	SwDataDefPropsClass.ImplTypeObj    = None
	SwDataDefPropsClass.CompuMethodObj = None
	SwDataDefPropsClass.BaseTypeObj    = None

	if hasattr(DataTypeObj, "SwDataDefProps"):
		SwDataDefProps = DataTypeObj.SwDataDefProps
		for SwDataDefPropsConditional in SwDataDefProps.SwDataDefPropsVariantList:
			if hasattr(SwDataDefPropsConditional, "ImplementationDataType"):
				SwDataDefPropsClass.ImplTypeObj = GetImplDataTypeObj(ArPkg,SwDataDefPropsConditional)
				if SwDataDefPropsClass.ImplTypeObj is not None:
					if SwDataDefPropsClass.ImplTypeObj.SwDataDefProps is not None:
						SwDataDefProps1 = SwDataDefPropsClass.ImplTypeObj.SwDataDefProps
						for SwDataDefPropsConditional1 in SwDataDefProps1.SwDataDefPropsVariantList:
							SwDataDefPropsClass.CompuMethodObj = GetCompuMethodObj(ArPkg,SwDataDefPropsConditional1)
				
			if type(SwDataDefPropsConditional.CompuMethod) is VCompuMethod_Ref:
				SwDataDefPropsClass.CompuMethodObj = GetCompuMethodObj(ArPkg,SwDataDefPropsConditional)
			
			if hasattr(SwDataDefPropsConditional, "BaseType"):
				SwDataDefPropsClass.BaseTypeObj = GetBaseDataTypeObj(ArPkg,SwDataDefPropsConditional)

	return SwDataDefPropsClass


def ChangeDataElementRef(ComSpecObj,NewSRIfObj):

	if hasattr(NewSRIfObj, "DataElementList"):
		for DataElement in NewSRIfObj.DataElementList:
			ComSpecObj.DataElement.DestType = DataElement.IdType 
			ComSpecObj.DataElement.Value = DataElement.AsrPath 



def ChangeConstantspecRef(ArPkg,TypesArPkg,ComSpecObj,TypeName):
	# print "ComSpecObj \"{0}\" ".format(ComSpecObj)
	if type(ComSpecObj) is VNonqueuedReceiverComSpec or type(ComSpecObj) is VNonqueuedSenderComSpec:
		#Create constant specification of the given type.
		TypeObj = GetDataTypeInfo(TypesArPkg,TypeName)
		if TypeObj is not None: 
			name = TypeObj.ShortName+"_InitValue"
 			ConstSpecObj = GetElementObj(ArPkg,name,VConstantSpecification)
 			# print "ConstSpecObj \"{0}\" \"{1}\" ".format(ConstSpecObj,name)
			if ConstSpecObj is None:
				ConstSpecObj = AddNewElementAsConstantSpecification(ArPkg,name)
 				# print "ConstSpecObj \"{0}\" \"{1}\" ".format(ConstSpecObj,name)
				CreateArrayOfStructConstantSpec(TypesArPkg,ArPkg,TypeObj,ConstSpecObj)
 			# print "VVariableDataPrototype_Ref \"{0}\" \"{1}\" ".format((type(ComSpecObj.DataElement)),TypeName)
			if ConstSpecObj is not None: 
				if ((type(ComSpecObj.DataElement) is VVariableDataPrototype_Ref) or
				(type(ComSpecObj.DataElement) is VAutosarDataPrototype_Ref)):  	  
					VariableDataPrototypeRef = ArPkg.Find(ComSpecObj.DataElement.Value)
	  				if VariableDataPrototypeRef.Count >0:
	   					VariableDataPrototype = VariableDataPrototypeRef[0]
					SwDataDefPropsClass = ReadSwDataDefProperties(TypesArPkg,VariableDataPrototype)
					# print "SwDataDefPropsClass \"{0}\" \"{1}\" ".format(SwDataDefPropsClass,SwDataDefPropsClass.ImplTypeObj.ShortName)
					if hasattr(SwDataDefPropsClass, "ImplTypeObj") and SwDataDefPropsClass.ImplTypeObj is not None:
						if SwDataDefPropsClass.ImplTypeObj.ShortName == TypeName:
							if hasattr(ComSpecObj, "InitValue") and ComSpecObj.InitValueSpecified == True:
								if type(ComSpecObj.InitValue) is VConstantReference:
									ComSpecObj.InitValue.Constant.DestType = ConstSpecObj.IdType
									ComSpecObj.InitValue.Constant.Value = ConstSpecObj.AsrPath 		





def UpdatePortElementAndInitValue(ArPkg,TypesArPkg,PortObj,SRObj,ConstSpecObj,TypeName):

	if PortObj:
		if hasattr(PortObj, "RequiredComSpecList"):
			for RequiredComSpec in PortObj.RequiredComSpecList:
				ChangeConstantspecRef(ArPkg,TypesArPkg,RequiredComSpec,ConstSpecObj,TypeName)
				ChangeDataElementRef(RequiredComSpec,SRObj)
		if hasattr(PortObj, "ProvidedComSpecList"):
			for ProvidedComSpec in PortObj.ProvidedComSpecList:
				ChangeConstantspecRef(ArPkg,TypesArPkg,ProvidedComSpec,ConstSpecObj,TypeName)
				ChangeDataElementRef(ProvidedComSpec,SRObj)

def UpdatePortInitValue(ArPkg,TypesArPkg,PortObj,TypeName):
	
	if PortObj:
		if hasattr(PortObj, "RequiredComSpecList"):
			for RequiredComSpec in PortObj.RequiredComSpecList:
				ChangeConstantspecRef(ArPkg,TypesArPkg,RequiredComSpec,TypeName)
		if hasattr(PortObj, "ProvidedComSpecList"):
			for ProvidedComSpec in PortObj.ProvidedComSpecList:
				ChangeConstantspecRef(ArPkg,TypesArPkg,ProvidedComSpec,TypeName)



#====================================================== Commmand sequence txt file processing ================================
def Readline(fileObj,count=None):

	str = ''
	n = 0
	while True:
		str = fileObj.readline()
		n = n + 1
		if len(str.split()) > 0 or n >= count:
			break
	return str
	 


def ReadCommandFile(str,pattern,RemovelList=None,Delemiters=None):
			
	StringData = ''
	matchObj = re.search(pattern, str)
	if matchObj is not None:
		matchObjStrip = matchObj.group().strip()
		if RemovelList: 
			for Remove in RemovelList:
				matchObjStrip = matchObjStrip.replace(Remove,"")
		if Delemiters:
			for Delemiter in Delemiters:
				matchObjStrip = matchObjStrip.replace(Delemiter,"")
		StringData = matchObjStrip 
	
	return StringData.strip() 

def SearchForCommandDataToken(str,token,RemovelList=None):

	result = False
	matchObj = re.search(token, str)
	if matchObj is not None:
		matchObjStrip = matchObj.group().strip()
		if RemovelList: 
			for Remove in RemovelList:
				matchObjStrip = matchObjStrip.replace(Remove,"")
		if  matchObjStrip == token:
			result = True

	return result 

def ProcessCommandString(str,RemovelList=None):

	CommandDataList = []
	if str:
		CommandDatalist = str.split('=')
		for CommandData in CommandDatalist:
			if RemovelList: 
				for Remove in RemovelList:
					CommandData = CommandData.replace(Remove,"")
				CommandDataList.Add(CommandData)
	
	if len(CommandDataList) < 2:
		CommandDataList = []	
		
	return CommandDataList 	

def ReadCommandDataAttrValue(str,attr,RemovelList,Delemiters):

	AttrValue = None
	if str:
		CommandDataString = ReadCommandFile(str,CommandDataExp,RemovelList,Delemiters)
		if CommandDataString:
			CommandDataList = ProcessCommandString(CommandDataString,RemovelList)
			if CommandDataList:
				if CommandDataList[0] == attr: 
					AttrValue = CommandDataList[1]
	return AttrValue  

def ParseCommandFile(file):

	# Strip the new line, space and tab characters from the string
	RemovelList = [' ', '\t', '\n']
	CmdDataBaseList = []
	fileObj = open(file)
	TotalLines = fileObj.read().splitlines()
	fileObj.seek(0)
	n = 0
	while True:
		pos = fileObj.tell()
		#line = fileObj.readline()
		line = Readline(fileObj,len(TotalLines))
		n = n + 1
		if line.strip():
			CommandString = ReadCommandFile(line,CommandStrExp,RemovelList,['[',']'])
			if CommandString:
				LastCommand = CommandString
			else:
				fileObj.seek(pos)
			CommandDict = ProcessCommandDataAttr(LastCommand,fileObj,len(TotalLines))
			if CommandDict:
				CmdDataBaseList.Add(CommandDict)
		if n >= len(TotalLines):
			break
	fileObj.close()				
	
	return CmdDataBaseList


def ProcessCommandDataAttr(CommandString,fileObj,NoOfLines):

	#List of characters to be stripped off
	RemovelList = [' ', '\t', '\n']

	#Empty dictionary object
	CommandDict = {}
	#Get the command string
	ValidCommandStr = CommandList.has_key(CommandString)
	if ValidCommandStr: 
		CommandId = CommandList[CommandString]
		ValidCommandId = CommandDataAttributes.has_key(CommandId)
		if ValidCommandId:
			str = Readline(fileObj,NoOfLines)
			if str:
				result = SearchForCommandDataToken(str,"{",RemovelList)
				if result == True:
					#Found valid data start token, retrieve the command data attributes
					CommandDict["CommandId"] = CommandId
					CommandAttrList = CommandDataAttributes[CommandId]
					for CommandAttr in CommandAttrList:
						str = Readline(fileObj,NoOfLines)
						AttrValue = ReadCommandDataAttrValue(str,CommandAttr,RemovelList,['{','}'])
						if AttrValue is not None:
							CommandDict[CommandAttr] = AttrValue
						else:
							CommandDict = {}
							print "Error : Command data attribute format not matching for the command \"{0}\" ".format(CommandString)
							break			
					#Read Command Data end Token
					str = Readline(fileObj,NoOfLines)
					result = SearchForCommandDataToken(str,"}",RemovelList)
					if result == False:
						#No valid data end token
						print "Error : Command data end token was missing for the command \"{0}\" ".format(CommandString)
	
		else:
			print "Error : Command data attributes missing \"{0}\" ".format(CommandString)
	else:
		print "Error : Not a valid Command string \"{0}\" ".format(CommandString)

	return CommandDict 



#============================= Command implementations ======================================================================

def ArrayOfStructType(RootArPkg,TypesArPkg,CompsArPkg,CommandDict):
		
	PortObjs = []
	IfObjs = []


	if CommandDict.has_key("PortName") and CommandDict.has_key("SrcDataType") and CommandDict.has_key("Size"):
		PortName = CommandDict['PortName']
		DataType = CommandDict['SrcDataType']
		Size = CommandDict['Size']
		ArrayTypeObj = CreateArrayOfSrcType(TypesArPkg,DataType,Size)
		SRObj = CreateSRInterfaceType(TypesArPkg,ArrayTypeObj)
		if ArrayTypeObj is not None:
			name = ArrayTypeObj.ShortName+"_InitValue"
 			ConstSpecObj = GetElementObj(CompsArPkg,name,VConstantSpecification)
			if ConstSpecObj is None:
				ConstSpecObj = AddNewElementAsConstantSpecification(CompsArPkg,name)
				CreateArrayConstantSpec(TypesArPkg,CompsArPkg,ArrayTypeObj,ConstSpecObj)
			IfObjs = GetInterfaceObjsOfDataType(TypesArPkg,DataType)
			if IfObjs:
				for IfObj in IfObjs:
					PortObjs = GetPortObjsListForIfType(IfObj)
			if PortObjs:
				for PortObj in PortObjs:
					if PortObj.ShortName == PortName:
						print "Port name  \"{0}\" owned by App SWC  \"{1}\" ".format(PortObj.ShortName,PortObj.Owner.ShortName)
						UpdatePortElementAndInitValue(CompsArPkg,TypesArPkg,PortObj,SRObj,ConstSpecObj,DataType)
		else:
			print "Error : Array type creation failed !!!"


def RemoveCompositionSwComponent(ArPkg,CommandDict):

	if CommandDict.has_key("SwComponentName"):
		ComponentName = CommandDict["SwComponentName"]
		if hasattr(ArPkg, "ArPackageList"):
			if ArPkg.ArPackageList.Count > 0:
				for ChildArPkg in ArPkg.ArPackageList:
					result = RemoveCompSwCompHandle(ChildArPkg,ComponentName)
					if result == True:
						break
		else:
			RemoveCompSwCompHandle(ArPkg,ComponentName)
			print "Done"


def ArrayOfStructForSubElement(RootArPkg,TypesArPkg,CompsArPkg,CommandDict):

	#1.Create a array of source type.
	#2.Search the destination type and change the sub element type to array type.
	#3.Find all the S/R type interfaces whose data element refers the destination type.
	#4.Find all the Ports refering the S/R interfaces and matching the given input port name
	#5.Create constant specification for the destination type.
	#6.Update the init value reference of the matching ports to newly created constant specification.    
	PortObjs = ''
	if CommandDict.has_key("PortName") and CommandDict.has_key("SrcDataType") \
	and CommandDict.has_key("DstDataType") and CommandDict.has_key("Size"):
		
		PortName = CommandDict['PortName']
		SrcDataType = CommandDict['SrcDataType']
		DstDataType = CommandDict['DstDataType']
		Size = CommandDict['Size']
		if PortName and SrcDataType and DstDataType and Size:
			#1.Create a array of source type
			ArrayTypeObj = CreateArrayOfSrcType(TypesArPkg,SrcDataType,Size)
			#2.Search the destination type and change the element type to array type
			TypeObj = GetDataTypeInfo(TypesArPkg,DstDataType)
			print "TypeObj name  \"{0}\" ".format(TypeObj)              
			if TypeObj is not None and TypeObj.Category == "STRUCTURE":
				ChangeSwDataDefProperties(TypesArPkg,TypeObj,ArrayTypeObj,SrcDataType)
				#4 Find all the S/R type interfaces which uses the destination type
				#5 Find all the ports using the S/R type interface which inturn uses this destination type 
				IfObjs = GetInterfaceObjsOfDataType(TypesArPkg,DstDataType)
				if IfObjs:
					for IfObj in IfObjs:
						PortObjs = GetPortObjsListForIfType(IfObj)
				
				if PortObjs:
					for PortObj in PortObjs:
						if PortObj.ShortName == PortName or PortName == "All":
							print "Port name  \"{0}\" owned by App SWC  \"{1}\" ".format(PortObj.ShortName,PortObj.Owner.ShortName)
							#5.Create constant specification for the destination type.
							#6.Update the init value reference of the matching ports to newly created constant specification.    
							UpdatePortInitValue(CompsArPkg,TypesArPkg,PortObj,DstDataType)



def AddInitValueForStructType(RootArPkg,TypesArPkg,CompsArPkg,CommandDict):

	#1.Find all the S/R type interfaces whose data element refers the given type.
	#2.Find all the Ports refering the S/R interfaces and matching the given input port name
	#3.Create constant specification for the given type.
	#4.Update the init value reference of the matching ports to newly created constant specification.    
	
	if CommandDict.has_key("PortName") and CommandDict.has_key("SrcDataType"):
		PortName = CommandDict['PortName']
		SrcDataType = CommandDict['SrcDataType']
		if PortName and SrcDataType:
			#2.Get the object handle for the src data type 
			TypeObj = GetDataTypeInfo(TypesArPkg,SrcDataType)
			if TypeObj is not None and TypeObj.Category == "STRUCTURE":
				
				#1 Find all the S/R type interfaces which uses the destination type
				#2 Find all the ports using the S/R type interface which inturn uses this destination type 

				IfObjs = GetInterfaceObjsOfDataType(TypesArPkg,SrcDataType)
				if IfObjs:
					for IfObj in IfObjs:
						PortObjs = GetPortObjsListForIfType(IfObj)
				
				if PortObjs:
					for PortObj in PortObjs:
						if PortObj.ShortName == PortName or PortName == "All":
							print "Port name  \"{0}\" owned by App SWC  \"{1}\" ".format(PortObj.ShortName,PortObj.Owner.ShortName)
							#3.Create constant specification for the given type.
							#4.Update the init value reference of the matching ports to newly created constant specification.    
							UpdatePortInitValue(CompsArPkg,TypesArPkg,PortObj,SrcDataType)

def AddTypeReference(RootArPkg,TypesArPkg,CompsArPkg,DataTypesArPkg,ProgramName,CommandDict):
	#1.Search the destination type and change the sub element's category to TYEP-REFERENCE

	if CommandDict.has_key("SrcDataType") and CommandDict.has_key("DstDataType"):
		
		SrcDataType = CommandDict['SrcDataType']
		DstDataType = CommandDict['DstDataType']
		print"DstDataType \"{0}\" \"{1}\" ".format(SrcDataType, DstDataType)
		if SrcDataType and DstDataType:
			#1.Search the destination type and change the element's category to TYEP-REFERENCE
			if ProgramName == "HD_A99":
				TypeObj = GetDataTypeInfo(TypesArPkg,SrcDataType)
			else:
				TypeObj = GetDataTypeInfo(TypesArPkg,DstDataType)

			print"TypeObj \"{0}\"  ".format(TypeObj)
			if TypeObj is not None and TypeObj.Category == "ARRAY":
				print"MapDataType \"{0}\"  \"{1}\" ".format(SrcDataType, DstDataType)
				MapDataType(RootArPkg,SrcDataType, DstDataType)
			elif TypeObj is None:
				if DstDataType == "t_vSwUpdM_Segment_Attributes_x_16":
					print"DataTypesArPkg \"{0}\" ".format(DataTypesArPkg)
					#CreateRecordType(TypesArPkg,DataTypesArPkg)


def AddUCLRunnableandEvent(RootArPkg,TypesArPkg,CompsArPkg,CommandDict):
	#1.Get the object fro the ASWC, port, dataelement.
	#2.Add the Runnable and the DataReceivedEvent
	
	if CommandDict.has_key("AswcName") and CommandDict.has_key("RunnableName") \
	and CommandDict.has_key("PortName") and CommandDict.has_key("InterfaceName") and CommandDict.has_key("DataElementName") \
	and CommandDict.has_key("PortType"):
		
		EventTriggerRunnable = CEventTriggerRunnable()
		EventTriggerRunnable.AswcName = CommandDict['AswcName'] 	
		EventTriggerRunnable.RunnableName = CommandDict['RunnableName'] 	
		EventTriggerRunnable.PortName =  CommandDict['PortName'] 	
		EventTriggerRunnable.InterfaceName =  CommandDict['InterfaceName'] 	
		EventTriggerRunnable.DataElement =  CommandDict['DataElementName']
		EventTriggerRunnable.PortType =  CommandDict['PortType']
		
		Aswch = GetElementObj(CompsArPkg,EventTriggerRunnable.AswcName,VApplicationSwComponentType)
		
		if Aswch:
			
			PortPath = GetRportHandle(Aswch,EventTriggerRunnable.PortName)
			SwcIBDh     = GetSwImplBehaviorHandle(CompsArPkg,Aswch)
			#print "SwcImplComp: path \"{0}\"".format(SwcIBDh.AsrPath)
			
			
			#print "Data Element : Path \"{0}\"".format(DataElement.AsrPath)
			Runnableh = AddRunnable(SwcIBDh,EventTriggerRunnable.RunnableName)
			print "New Runnable: AsrPath \"{0}\"".format(Runnableh.AsrPath)
			AddRteEvent(Aswch,SwcIBDh,Runnableh,PortPath,CommandDict['DataElementName'], CommandDict['PortType'],EventTriggerRunnable.InterfaceName,TypesArPkg)
			
	
class CEventTriggerRunnable:
	pass

def AddRteDSCEvent(AppSwcHandle,SwcImplBehaviorHandle,RunnableDataHandle,DataElementHandle,VaribaleAccess):
												  
	EventDataRef = []
	
	# Add Event 
	EventDataRef = SwcImplBehaviorHandle.AddNewEventAsDataSendCompletedEvent() 
	EventDataRef.ShortName = "DSCE" + RunnableDataHandle.ShortName + "TrigBy"  + DataElementHandle
	
	
	#Upon Event reception Trigger the runnable 
	EventDataRef.StartOnEventSpecified = True	
	EventDataRef.StartOnEvent.DestType = RunnableDataHandle.IdType 
	EventDataRef.StartOnEvent.Value = RunnableDataHandle.AsrPath
	
	EventDataRef.EventSourceSpecified = True
	EventDataRef.EventSource.DestType = VaribaleAccess.IdType
	EventDataRef.EventSource.Value = VaribaleAccess.AsrPath
	return EventDataRef


def AddEventsForOnDataTxRunnables(RootArPkg,TypesArPkg,CompsArPkg,CommandDict):
	#1.Get the object fro the ASWC
	#2.Loop through runnables to identify the OnDataTX Runnables.
	#3.Get the Dataelement name and the Port name form the name of the Runnable
	#4.Creat the DataSendCOmpletedEvent for each of the runnables.
	
	
	if CommandDict.has_key("AswcName"):
		AswcName = CommandDict['AswcName']
		Aswch = GetElementObj(CompsArPkg,AswcName,VApplicationSwComponentType)
		
		if Aswch:
			SwcIBDh     = GetSwImplBehaviorHandle(CompsArPkg,Aswch)
			for Runnable in SwcIBDh.RunnableList:
				if type(Runnable) is VRunnableEntity and Runnable.ShortName == "CComAbsMdl_Impl_RxCanMdlMainFunction":
					if hasattr(Runnable, "DataSendPointList"):
						RunnableObj = Runnable
				if type(Runnable) is VRunnableEntity and 'CComAbsMdl_OnDataTx' in Runnable.ShortName:
					print "Runnable: name \"{0}\"".format(Runnable.ShortName)
					CommandDataList = []
					
					CommandDatalist = Runnable.ShortName.split('CComAbsMdl_OnDataTx_')
					for CommandData in CommandDatalist:
						if CommandData is not "":
							print "CommandData: name \"{0}\" \n".format(CommandData)
							DataElement = CommandData
							VaribaleAccess = "DWA_pp_SR_Tx" + DataElement + "_" + DataElement
							for element in RunnableObj.DataSendPointList:
								if type(element) is VVariableAccess and element.ShortName == VaribaleAccess:
									ElementObj = element
									break
							print "CommandDatalist: name \"{0}\" \"{1}\" \"{2}\" \n".format(DataElement,VaribaleAccess,ElementObj)
							AddRteDSCEvent(Aswch,SwcIBDh,Runnable,DataElement,ElementObj)
                            
def AddEventsForOnDataTxRunnablesSafe(RootArPkg,TypesArPkg,CompsArPkg,CommandDict):
	#1.Get the object fro the ASWC
	#2.Loop through runnables to identify the OnDataTX Runnables.
	#3.Get the Dataelement name and the Port name form the name of the Runnable
	#4.Creat the DataSendCOmpletedEvent for each of the runnables.
	
	
	if CommandDict.has_key("AswcName"):
		AswcName = CommandDict['AswcName']
		Aswch = GetElementObj(CompsArPkg,AswcName,VApplicationSwComponentType)
		
		if Aswch:
			SwcIBDh     = GetSwImplBehaviorHandle(CompsArPkg,Aswch)
			for Runnable in SwcIBDh.RunnableList:
				if type(Runnable) is VRunnableEntity and Runnable.ShortName == "CComAbsSafe_Impl_RxCanSafeMainFunction":
					if hasattr(Runnable, "DataSendPointList"):
						RunnableObj = Runnable
				if type(Runnable) is VRunnableEntity and 'CComAbsSafe_OnDataTx' in Runnable.ShortName:
					print "Runnable: name \"{0}\"".format(Runnable.ShortName)
					CommandDataList = []
					
					CommandDatalist = Runnable.ShortName.split('CComAbsSafe_OnDataTx_')
					for CommandData in CommandDatalist:
						if CommandData is not "":
							print "CommandData: name \"{0}\" \n".format(CommandData)
							DataElement = CommandData
							VaribaleAccess = "DWA_pp_SR_Tx" + DataElement + "_" + DataElement
							for element in RunnableObj.DataSendPointList:
								if type(element) is VVariableAccess and element.ShortName == VaribaleAccess:
									ElementObj = element
									break
							print "CommandDatalist: name \"{0}\" \"{1}\" \"{2}\" \n".format(DataElement,VaribaleAccess,ElementObj)
							AddRteDSCEvent(Aswch,SwcIBDh,Runnable,DataElement,ElementObj)                            
								  

def ChangeRunnableName(RootArPkg,TypesArPkg,CompsArPkg,CommandDict):
	#1.Get the object fro the ASWC
	#2.Loop through runnables to identify the OnDataTX Runnables.
	#3.Get the Dataelement name and the Port name form the name of the Runnable
	#4.Creat the DataSendCOmpletedEvent for each of the runnables.
	
	
	if CommandDict.has_key("AswcName") and CommandDict.has_key("RunnableName") :
		AswcName = CommandDict['AswcName']
		RunName = CommandDict['RunnableName']
		NewRunName = CommandDict['NewRunnableName']
		print "SwcImplComp: path \"{0}\"".format(RunName, NewRunName)
		Aswch = GetElementObj(CompsArPkg,AswcName,VApplicationSwComponentType)
		
		if Aswch:
			SwcIBDh = GetSwImplBehaviorHandle(CompsArPkg,Aswch)
			print "SwcImplComp: path \"{0}\"".format(SwcIBDh.RunnableList)
			for Runnable in SwcIBDh.RunnableList:
				
				if type(Runnable) is VRunnableEntity and Runnable.ShortName == RunName :
					Runnable.ShortName = NewRunName
					Runnable.Symbol = NewRunName
					print "Changed Names\"{0}\" \"{1}\" ".format(Runnable.ShortName, Runnable.Symbol)