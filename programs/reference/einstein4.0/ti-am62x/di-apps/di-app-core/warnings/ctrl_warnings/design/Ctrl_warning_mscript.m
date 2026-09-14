%% This is an Auto generated m script for adding the Autosar Ports and interfaces in Matlab Environment
close all; 
model_name = 'Ctrl_warning' ; 
ModelExist = exist(model_name,'file');
if ModelExist == 4
disp('model already exist');
open_system(model_name);
else
new_system(model_name);
   open_system(model_name);
end

%% Block position
leftoffset = 60;
topoffset  = 60;
%blockoffset = 100;
width = 30;
height = 20;

 %% Set Model Configuration Parameters and Target File to AUTOSAR 
set_param(model_name, 'SystemTargetFile', 'autosar.tlc' );
set_param(model_name, 'PortableWordSizes', 'on');
set_param(model_name,'SolverType', 'Fixed-step');   % Type
set_param(model_name, 'Solver', 'FixedStepDiscrete');
set_param(model_name, 'FixedStep', '0.1');
set_param(model_name,'SampleTimeConstraint','Unconstrained');
set_param(model_name, 'AutosarMaxShortNameLength', 128);
set_param(model_name, 'AutosarSchemaVersion', '4.2');
set_param(model_name, 'SolverMode','Auto');
set_param(model_name, 'OptimizeBlockIOStorage', 'on');
set_param(model_name, 'LocalBlockOutputs', 'on');
set_param(model_name, 'ExpressionFolding', 'on');
set_param(model_name, 'BufferReuse', 'on');
set_param(model_name, 'GlobalBufferReuse', 'on');
set_param(model_name, 'GlobalVariableUsage', 'Use global to hold temporary results');
set_param(model_name, 'MaxStackSize', '750');
set_param(model_name, 'BooleanDataType', 'on');
% Signal logging to workspace not allowed in multi runnbale environment
set_param(model_name, 'SaveOutput', 'off');
set_param(model_name, 'ParenthesesLevel', 'Maximum');
set_param(model_name, 'CastingMode', 'Standards');
set_param(model_name, 'ERTFilePackagingFormat', 'CompactWithDataFile');
set_param(model_name, 'AutosarCompilerAbstraction', 'on');
 %% Create AUTOSAR properties and Simulink Mapping Components
autosar.api.create(model_name,'default')
arProps = autosar.api.getAUTOSARProperties(model_name);
aswcPath = find(arProps,[],'AtomicComponent','PathType','FullyQualified'); %#ok<GTARG>
ifPkg = get(arProps,'XmlOptions','InterfacePackage');
swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib = get(arProps,swc,'Behavior');
%Delete Existing Runnable
SRPath = find(arProps,ib,'Runnable','Name','Runnable_Step');      %#ok<GTARG>
if ~isempty(SRPath)
delete(arProps,SRPath{1});
end
SRPath = get(arProps,ib,'Events');  
if ~isempty(SRPath)
delete(arProps,SRPath{1});                             
end
SRPath = find(arProps,aswcPath{1},'Runnable','Name','Runnable_Init');     %#ok<GTARG> 
set(arProps,SRPath{1}, 'symbol', [model_name '_Init']);
set(arProps,SRPath{1}, 'Name', [model_name '_Init']);
slMap = autosar.api.getSimulinkMapping(model_name);
%% Set AUTOSAR attributes
swCalibValue = 'ReadOnly';
SendMOde = 'ExplicitSend';
ReceiveMode = 'ExplicitReceive';
blockoffset =  8;
PositionArray = [(leftoffset + 100) (topoffset)  ((leftoffset + 100)+ 30) ((topoffset)+20)];
RunnableName = ['Ctrl_warning_Task']; 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', RunnableName, 'Position',PositionArray);
set_param(HandleSR, 'OutputFunctionCall', 'on');
set_param(HandleSR, 'SampleTime', '0.1');
PositionArray = [(leftoffset*blockoffset) (topoffset)  ((leftoffset*blockoffset)+ 200) ((blockoffset * topoffset)+100)];
HandleSubSys = add_block('simulink/Ports & Subsystems/Function-Call Subsystem', [model_name '/' 'subsystem'], 'Name', [RunnableName '_sys'],'Position',PositionArray);
delete_line([model_name '/' RunnableName '_sys'], 'In1/1', 'Out1/1'); 
delete_block([model_name '/' RunnableName '_sys' '/In1']);
delete_block([model_name '/' RunnableName '_sys' '/Out1']);
f_blk = find_system([model_name '/' RunnableName '_sys'], 'FindAll', 'on', 'BlockType', 'TriggerPort');
set_param(f_blk,'SampleTimeType','periodic');
set_param(f_blk,'SampleTime','-1');
set_param(HandleSubSys,'BackgroundColor', 'lightBlue');
add_line(model_name, [RunnableName '/1'], [[RunnableName '_sys'] '/Trigger'],'autorouting', 'on');
swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib = get(arProps,swc,'Behavior');
add(arProps,ib,'Runnables', RunnableName);
EventName = ['Event_' RunnableName];
add(arProps,ib,'Events',EventName,'Category','TimingEvent','StartOnEvent',[ib '/' RunnableName]);
mapFunction(slMap,RunnableName,RunnableName);

%% VARIANT CONFIG SUBSYSTEM STARTS
blockoffset =   1 ;
% RunnableSysName = [RunnableName '_sys'];
Apprunnablepath = [model_name '/' [RunnableName '_sys']];
PositionArray = [(leftoffset * blockoffset) (blockoffset * topoffset)  ((leftoffset * blockoffset)+200) ((blockoffset * topoffset)+200)];
HandleVariant = add_block('simulink/Ports & Subsystems/Variant Subsystem', [Apprunnablepath '/InputHarness'], 'Name', 'InputHarness','Position',PositionArray);
Simulink.SubSystem.deleteContents(HandleVariant);
blockoffset =   4 ;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset +200) ((blockoffset * topoffset)+200)];
HandleSubSys = add_block('simulink/Ports & Subsystems/Subsystem', [Apprunnablepath '/InputHarness' '/' 'Simulation'], 'Name', 'Simulation','Position',PositionArray);
Simulink.SubSystem.deleteContents(HandleSubSys);
blockoffset =   8 ;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+200)];
HandleSubSys = add_block('simulink/Ports & Subsystems/Subsystem', [Apprunnablepath '/InputHarness' '/' 'CodeGeneration'], 'Name', 'CodeGeneration','Position',PositionArray);
Simulink.SubSystem.deleteContents(HandleSubSys);
RunnableBlockPath = [RunnableName '_sys'];
Variantblockpath = [Apprunnablepath '/InputHarness'];
CodeGenblockpath = [Apprunnablepath '/InputHarness' '/' 'CodeGeneration'];
Simulationblockpath = [Apprunnablepath '/InputHarness' '/' 'Simulation'];
mode = 2;
SIMULATION = Simulink.Variant('mode==1');
CODEGENERATION = Simulink.Variant('mode==2');
set_param(Simulationblockpath,'VariantControl','SIMULATION');
set_param(CodeGenblockpath,'VariantControl','CODEGENERATION');

%% VARIANT CONFIG SUBSYSTEM ENDS
% ******************* Adding AutoSar Port rp_ClusterModeand Interface TI_WSS_ClusterMode *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_WSS_ClusterMode_rp_ClusterMode' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_ClusterMode';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_ClusterModeand Interface TI_WSS_ClusterMode *****************

% ******************* Adding AutoSar attribute WSSCurrentClusterMode as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_ClusterMode_WSSCurrentClusterMode';
blockoffset = 9;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'ClusterModes');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'ClusterModes');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'ClusterModes');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'ClusterModes');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'ClusterModes');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'ClusterModes');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'WSSCurrentClusterMode';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute WSSCurrentClusterMode as element *****************

% ******************* Adding AutoSar Port rpIgnSubstateand Interface TI_WSS_IgnitionSubstate *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_WSS_IgnitionSubstate_rpIgnSubstate' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rpIgnSubstate';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rpIgnSubstateand Interface TI_WSS_IgnitionSubstate *****************

% ******************* Adding AutoSar attribute IgnitionSubstate as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rpIgnSubstate_IgnitionSubstate';
blockoffset = 10;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'IgntionSubstateType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'IgntionSubstateType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'IgntionSubstateType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'IgntionSubstateType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'IgntionSubstateType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'IgntionSubstateType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'IgnitionSubstate';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute IgnitionSubstate as element *****************

inport = find_system(model_name, 'SearchDepth', 1, 'Type', 'block','BlockType', 'Inport','OutputFunctionCall', 'off');
for portIdx = 1:length(inport)
PortName = get_param(inport(portIdx), 'Name');
PortNumber = int2str(1);
SubSysPortNumber = int2str(portIdx);
add_line(model_name, [PortName{1} '/' PortNumber], [[RunnableName '_sys'] '/' SubSysPortNumber],'autorouting', 'on'); 
end

outport = find_system(model_name, 'SearchDepth', 1, 'Type', 'block','BlockType', 'Outport');
for portIdx = 1:length(outport)
PortName = get_param(outport(portIdx), 'Name');
PortNumber = int2str(1);
SubSysPortNumber = int2str(portIdx);
add_line(model_name, [[RunnableName '_sys'] '/' SubSysPortNumber], [PortName{1} '/' PortNumber], 'autorouting', 'on'); 
end

inport1 = find_system(CodeGenblockpath, 'SearchDepth', 1, 'Type', 'block','BlockType', 'Inport','OutputFunctionCall', 'off');
for portIdx = 1:length(inport1)
PortName = get_param(inport1(portIdx), 'Name');
PortNumber = int2str(1);
SubSysPortNumber = int2str(portIdx);
add_line(CodeGenblockpath, [PortName{1} '/' PortNumber], [[PortName{1} '_out'] '/' PortNumber],'autorouting', 'on'); 
end

%%********** Adding TI TI_Ctrl_Warning_UpdateWarningStatus***** Adding CS Port  ppCtrlWarningStatus**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_Ctrl_Warning_UpdateWarningStatus';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'ppCtrlWarningStatus';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Ctrl_warning_UpdateWarningStatus*****
Sl_CS_Operation = 'Ctrl_warning_UpdateWarningStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Ctrl_warning_UpdateWarningStatus*****
ArgumentIn0 = 'WarningCurId' ;
ArgumentIn1 = 'WarningCurStatus' ;
ArgumentIn2 = 'WarningCurEvent' ;
ArgumentIn3 = 'WarningPayload' ;


Operation_prototype = 'Ctrl_warning_UpdateWarningStatus( WarningCurId,WarningCurStatus,WarningCurEvent,WarningPayload)'; 
slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% configure Simulink function
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
if ~verLessThan('matlab','9.5')
set_param(f_blk, 'FunctionVisibility', 'global');
end
set_param(f_blk, 'FunctionPrototype', Operation_prototype);
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn0);
set_param(f_blk, 'OutDataTypeStr', ' WarningId ');
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn1);
set_param(f_blk, 'OutDataTypeStr', ' WarningStatus ');
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn2);
set_param(f_blk, 'OutDataTypeStr', ' WarningEvent ');
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn3);
set_param(f_blk, 'OutDataTypeStr', ' uint32 ');
set_param(slfunc_status,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);
%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn1 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn2 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn3 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib =  get(arProps,swc,'Behavior');
add(arProps,ib,'Runnables',Sl_CS_Operation);

EventName = ['Event_' Sl_CS_Operation];

add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION UpdateWarningStatus******

%%********** Adding TI TI_Ctrl_WarningDisplayedStatus***** Adding CS Port  ppWarningDisplayedStatus**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_Ctrl_WarningDisplayedStatus';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'ppWarningDisplayedStatus';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Ctrl_warning_GetWarningDisplayedStatus*****
Sl_CS_Operation = 'Ctrl_warning_GetWarningDisplayedStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Ctrl_warning_GetWarningDisplayedStatus*****
ArgumentIn0 = 'CurWarningId' ;

ArgumentOut0 = 'DisplayedStatus' ;

Operation_prototype = 'DisplayedStatus  = Ctrl_warning_GetWarningDisplayedStatus( CurWarningId)'; 
slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% configure Simulink function
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
if ~verLessThan('matlab','9.5')
set_param(f_blk, 'FunctionVisibility', 'global');
end
set_param(f_blk, 'FunctionPrototype', Operation_prototype);
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn0);
set_param(f_blk, 'OutDataTypeStr', ' WarningId ');
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgOut','Name', ArgumentOut0);
set_param(f_blk, 'OutDataTypeStr', ' WarningDisplayedStatus ');
set_param(slfunc_status,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);
%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut0 ,...
'Direction','Out',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib =  get(arProps,swc,'Behavior');
add(arProps,ib,'Runnables',Sl_CS_Operation);

EventName = ['Event_' Sl_CS_Operation];

add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetWarningDisplayedStatus******

%%********** Adding TI TI_Ctrl_WarningActiveStatus***** Adding CS Port  ppWarningActiveStatus**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_Ctrl_WarningActiveStatus';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'ppWarningActiveStatus';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Ctrl_warning_GetWarningActiveStatus*****
Sl_CS_Operation = 'Ctrl_warning_GetWarningActiveStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Ctrl_warning_GetWarningActiveStatus*****
ArgumentIn0 = 'CurrentWarning' ;

ArgumentOut0 = 'CurrentWarningStatus' ;

Operation_prototype = 'CurrentWarningStatus  = Ctrl_warning_GetWarningActiveStatus( CurrentWarning)'; 
slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% configure Simulink function
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
if ~verLessThan('matlab','9.5')
set_param(f_blk, 'FunctionVisibility', 'global');
end
set_param(f_blk, 'FunctionPrototype', Operation_prototype);
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn0);
set_param(f_blk, 'OutDataTypeStr', ' WarningId ');
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgOut','Name', ArgumentOut0);
set_param(f_blk, 'OutDataTypeStr', ' Bus:WarningDataS ');
set_param(slfunc_status,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);
%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut0 ,...
'Direction','Out',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib =  get(arProps,swc,'Behavior');
add(arProps,ib,'Runnables',Sl_CS_Operation);

EventName = ['Event_' Sl_CS_Operation];

add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetWarningActiveStatus******

%%********** Adding TI TI_Ctrl_Warning_LampStatus***** Adding CS Port  ppCtrlWarningLampStatus**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_Ctrl_Warning_LampStatus';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'ppCtrlWarningLampStatus';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Ctrl_warning_Get_Red_MasterLamp_Status*****
Sl_CS_Operation = 'Ctrl_warning_Get_Red_MasterLamp_Status';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Ctrl_warning_Get_Red_MasterLamp_Status*****

ArgumentOut0 = 'LampStatus' ;

Operation_prototype = 'LampStatus  = Ctrl_warning_Get_Red_MasterLamp_Status( )'; 
slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% configure Simulink function
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
if ~verLessThan('matlab','9.5')
set_param(f_blk, 'FunctionVisibility', 'global');
end
set_param(f_blk, 'FunctionPrototype', Operation_prototype);
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgOut','Name', ArgumentOut0);
set_param(f_blk, 'OutDataTypeStr', ' uint8 ');
set_param(slfunc_status,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);
%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut0 ,...
'Direction','Out',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib =  get(arProps,swc,'Behavior');
add(arProps,ib,'Runnables',Sl_CS_Operation);

EventName = ['Event_' Sl_CS_Operation];

add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_Red_MasterLamp_Status******

%%***** ADDING CS VARIABLE HOLDING TI Ctrl_warning_Get_Yellow_MasterLamp_Status*****
Sl_CS_Operation = 'Ctrl_warning_Get_Yellow_MasterLamp_Status';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Ctrl_warning_Get_Yellow_MasterLamp_Status*****

ArgumentOut0 = 'LampStatus' ;

Operation_prototype = 'LampStatus  = Ctrl_warning_Get_Yellow_MasterLamp_Status( )'; 
slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% configure Simulink function
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
if ~verLessThan('matlab','9.5')
set_param(f_blk, 'FunctionVisibility', 'global');
end
set_param(f_blk, 'FunctionPrototype', Operation_prototype);
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgOut','Name', ArgumentOut0);
set_param(f_blk, 'OutDataTypeStr', ' uint8 ');
set_param(slfunc_status,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);
%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut0 ,...
'Direction','Out',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib =  get(arProps,swc,'Behavior');
add(arProps,ib,'Runnables',Sl_CS_Operation);

EventName = ['Event_' Sl_CS_Operation];

add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_Yellow_MasterLamp_Status******

%%********** Adding TI TI_EcumExtInit***** Adding CS Port  pp_Init**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_EcumExtInit';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'pp_Init';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Ctrl_warning_Init*****
Sl_CS_Operation = 'Ctrl_warning_Init';
%%***** COMPLETE ADDING TI VARIABLE 

% %%***** ADDING OPERATION Ctrl_warning_Init*****
% 
% 
% Operation_prototype = 'Ctrl_warning_Init( )'; 
% slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
% delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% % configure Simulink function
% f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
% if ~verLessThan('matlab','9.5')
% set_param(f_blk, 'FunctionVisibility', 'global');
% end
% set_param(f_blk, 'FunctionPrototype', Operation_prototype);
% set_param(slfunc_status,'BackgroundColor', 'lightBlue');
% add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);
% 
% swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
% ib =  get(arProps,swc,'Behavior');
% add(arProps,ib,'Runnables',Sl_CS_Operation);
% 
% EventName = ['Event_' Sl_CS_Operation];
% 
% add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
% 'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
% mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
% %%***** COMPLETED ADDING OPERATION Init******

%%********** Adding TI TI_CS_Warning_Group_Update***** Adding CS Port  pp_CtrlWarningGroupUpdate**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_CS_Warning_Group_Update';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'pp_CtrlWarningGroupUpdate';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Ctrl_warning_Warning_Group_update*****
Sl_CS_Operation = 'Ctrl_warning_Warning_Group_update';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Ctrl_warning_Warning_Group_update*****


Operation_prototype = 'Ctrl_warning_Warning_Group_update( )'; 
slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% configure Simulink function
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
if ~verLessThan('matlab','9.5')
set_param(f_blk, 'FunctionVisibility', 'global');
end
set_param(f_blk, 'FunctionPrototype', Operation_prototype);
set_param(slfunc_status,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib =  get(arProps,swc,'Behavior');
add(arProps,ib,'Runnables',Sl_CS_Operation);

EventName = ['Event_' Sl_CS_Operation];

add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Warning_Group_update******

%%********** Adding TI TI_Ctrl_Warning_UpdateDisplayedStatus***** Adding CS Port  ppWarnDisplayStatus**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_Ctrl_Warning_UpdateDisplayedStatus';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'ppWarnDisplayStatus';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Ctrl_warning_SetWarningDisplayedStatus*****
Sl_CS_Operation = 'Ctrl_warning_SetWarningDisplayedStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Ctrl_warning_SetWarningDisplayedStatus*****
ArgumentIn0 = 'CurWarningId' ;
ArgumentIn1 = 'CurWarningDispStatus' ;


Operation_prototype = 'Ctrl_warning_SetWarningDisplayedStatus( CurWarningId,CurWarningDispStatus)'; 
slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% configure Simulink function
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
if ~verLessThan('matlab','9.5')
set_param(f_blk, 'FunctionVisibility', 'global');
end
set_param(f_blk, 'FunctionPrototype', Operation_prototype);
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn0);
set_param(f_blk, 'OutDataTypeStr', ' WarningId ');
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn1);
set_param(f_blk, 'OutDataTypeStr', ' WarningDisplayedStatus ');
set_param(slfunc_status,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);
%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn1 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib =  get(arProps,swc,'Behavior');
add(arProps,ib,'Runnables',Sl_CS_Operation);

EventName = ['Event_' Sl_CS_Operation];

add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION SetWarningDisplayedStatus******

%%********** Adding TI TI_Ctrl_Warning_UpdateDisplayedPayload***** Adding CS Port  ppWarnDisplayPayload**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_Ctrl_Warning_UpdateDisplayedPayload';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'ppWarnDisplayPayload';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Ctrl_warning_SetWarningDisplayedPayload*****
Sl_CS_Operation = 'Ctrl_warning_SetWarningDisplayedPayload';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Ctrl_warning_SetWarningDisplayedPayload*****
ArgumentIn0 = 'CurWarningId' ;
ArgumentIn1 = 'CurWarningDispPayload' ;


Operation_prototype = 'Ctrl_warning_SetWarningDisplayedPayload( CurWarningId,CurWarningDispPayload)'; 
slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% configure Simulink function
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
if ~verLessThan('matlab','9.5')
set_param(f_blk, 'FunctionVisibility', 'global');
end
set_param(f_blk, 'FunctionPrototype', Operation_prototype);
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn0);
set_param(f_blk, 'OutDataTypeStr', ' WarningId ');
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn1);
set_param(f_blk, 'OutDataTypeStr', ' PayloadArr_u8_8 ');
set_param(slfunc_status,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);
%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn1 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib =  get(arProps,swc,'Behavior');
add(arProps,ib,'Runnables',Sl_CS_Operation);

EventName = ['Event_' Sl_CS_Operation];

add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION SetWarningDisplayedPayload******

%%********** Adding TI TI_Ctrl_Warning_ActiveWarningStatus***** Adding CS Port  ppActiveWarningStatus**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_Ctrl_Warning_ActiveWarningStatus';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'ppActiveWarningStatus';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Ctrl_warning_GetActiveWarningStatus*****
Sl_CS_Operation = 'Ctrl_warning_GetActiveWarningStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Ctrl_warning_GetActiveWarningStatus*****
ArgumentIn0 = 'CurrentWarning' ;

ArgumentOut0 = 'CurrentWarningStatus' ;

Operation_prototype = 'CurrentWarningStatus  = Ctrl_warning_GetActiveWarningStatus( CurrentWarning)'; 
slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% configure Simulink function
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
if ~verLessThan('matlab','9.5')
set_param(f_blk, 'FunctionVisibility', 'global');
end
set_param(f_blk, 'FunctionPrototype', Operation_prototype);
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn0);
set_param(f_blk, 'OutDataTypeStr', ' WarningId ');
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgOut','Name', ArgumentOut0);
set_param(f_blk, 'OutDataTypeStr', ' Bus:ExtWarningData ');
set_param(slfunc_status,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);
%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut0 ,...
'Direction','Out',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib =  get(arProps,swc,'Behavior');
add(arProps,ib,'Runnables',Sl_CS_Operation);

EventName = ['Event_' Sl_CS_Operation];

add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetActiveWarningStatus******

%%********** Adding TI TI_Ctrl_Warning_UpdateExtdPayload***** Adding CS Port  ppCtrlWarningExtdPayload**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_Ctrl_Warning_UpdateExtdPayload';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'ppCtrlWarningExtdPayload';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Ctrl_warning_UpdateExtdPayload*****
Sl_CS_Operation = 'Ctrl_warning_UpdateExtdPayload';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Ctrl_warning_UpdateExtdPayload*****
ArgumentIn0 = 'WarningCurId' ;
ArgumentIn1 = 'WarningPayload' ;


Operation_prototype = 'Ctrl_warning_UpdateExtdPayload( WarningCurId,WarningPayload)'; 
slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% configure Simulink function
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
if ~verLessThan('matlab','9.5')
set_param(f_blk, 'FunctionVisibility', 'global');
end
set_param(f_blk, 'FunctionPrototype', Operation_prototype);
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn0);
set_param(f_blk, 'OutDataTypeStr', ' WarningId ');
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn1);
set_param(f_blk, 'OutDataTypeStr', ' PayloadArr_u8_8 ');
set_param(slfunc_status,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);
%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn1 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib =  get(arProps,swc,'Behavior');
add(arProps,ib,'Runnables',Sl_CS_Operation);

EventName = ['Event_' Sl_CS_Operation];

add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION UpdateExtdPayload******

%%********** Adding TI TI_Ctrl_WarningDisplayedPayload***** Adding CS Port  ppWarningDisplayedPayload**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_Ctrl_WarningDisplayedPayload';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'ppWarningDisplayedPayload';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Ctrl_warning_GetWarningDisplayedPayload*****
Sl_CS_Operation = 'Ctrl_warning_GetWarningDisplayedPayload';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Ctrl_warning_GetWarningDisplayedPayload*****
ArgumentIn0 = 'CurWarningId' ;

ArgumentOut0 = 'DisplayedPayload' ;

Operation_prototype = 'DisplayedPayload  = Ctrl_warning_GetWarningDisplayedPayload( CurWarningId)'; 
slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% configure Simulink function
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
if ~verLessThan('matlab','9.5')
set_param(f_blk, 'FunctionVisibility', 'global');
end
set_param(f_blk, 'FunctionPrototype', Operation_prototype);
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgIn','Name', ArgumentIn0);
set_param(f_blk, 'OutDataTypeStr', ' WarningId ');
f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'ArgOut','Name', ArgumentOut0);
set_param(f_blk, 'OutDataTypeStr', ' PayloadArr_u8_8 ');
set_param(slfunc_status,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);
%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut0 ,...
'Direction','Out',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
ib =  get(arProps,swc,'Behavior');
add(arProps,ib,'Runnables',Sl_CS_Operation);

EventName = ['Event_' Sl_CS_Operation];

add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetWarningDisplayedPayload******

% %%***** ADDING OPERATION Ctrl_warning_Init*****
% 
% 
% Operation_prototype = 'Ctrl_warning_Init( )'; 
% slfunc_status = add_block('simulink/User-Defined Functions/Simulink Function',[model_name '/function'],'Name', Sl_CS_Operation );
% delete_line([model_name '/' Sl_CS_Operation], ['u' '/1'], ['y' '/1']);
% % configure Simulink function
% f_blk = find_system([model_name '/' Sl_CS_Operation], 'FindAll', 'on', 'BlockType', 'TriggerPort');
% if ~verLessThan('matlab','9.5')
% set_param(f_blk, 'FunctionVisibility', 'global');
% end
% set_param(f_blk, 'FunctionPrototype', Operation_prototype);
% set_param(slfunc_status,'BackgroundColor', 'lightBlue');
% add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);
% 
% swc = get(arProps,'XmlOptions','ComponentQualifiedName');  % get qualified name under atomic components
% ib =  get(arProps,swc,'Behavior');
% add(arProps,ib,'Runnables',Sl_CS_Operation);
% 
% EventName = ['Event_' Sl_CS_Operation];
% 
% add(arProps,ib,'Events',EventName,'Category','OperationInvokedEvent',...
% 'Trigger',[ServerPortName '.' Sl_CS_Operation],'StartOnEvent',[ib '/' Sl_CS_Operation]);
% mapFunction(slMap,Sl_CS_Operation,Sl_CS_Operation);
% %%***** COMPLETED ADDING OPERATION Init******

autosar.api.syncModel(model_name);
try
autosar.api.validateModel(model_name)
catch validationErr
throw(validationErr)
end
