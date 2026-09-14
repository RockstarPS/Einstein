%% This is an Auto generated m script for adding the Autosar Ports and interfaces in Matlab Environment
close all; 
model_name = 'Mdl_Airbag' ; 
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
%set(arProps,SRPath{1}, 'symbol', [model_name '_Init']);
%set(arProps,SRPath{1}, 'Name', [model_name '_Init']);
slMap = autosar.api.getSimulinkMapping(model_name);
%% Set AUTOSAR attributes
swCalibValue = 'ReadOnly';
SendMOde = 'ExplicitSend';
ReceiveMode = 'ExplicitReceive';
blockoffset =  8;
PositionArray = [(leftoffset + 100) (topoffset)  ((leftoffset + 100)+ 30) ((topoffset)+20)];
RunnableName = ['Mdl_Airbag_Task']; 
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
% OutputHarness creation
blockoffset =   10 ;
PositionArray = [(leftoffset * blockoffset) (topoffset)  ((leftoffset * blockoffset)+200) ((topoffset)+200)];
HandleVariant = add_block('simulink/Ports & Subsystems/Variant Subsystem', [Apprunnablepath '/OutputHarness'], 'Name', 'OutputHarness','Position',PositionArray);
Simulink.SubSystem.deleteContents(HandleVariant);
blockoffset =   4 ;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset +200) ((blockoffset * topoffset)+200)];
HandleSubSys = add_block('simulink/Ports & Subsystems/Subsystem', [Apprunnablepath '/InputHarness' '/' 'Simulation'], 'Name', 'Simulation','Position',PositionArray);
Simulink.SubSystem.deleteContents(HandleSubSys);
blockoffset =   4 ;
% Simulation system creation inside OutputHarness 
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset +200) ((blockoffset * topoffset)+200)];
HandleSubSys = add_block('simulink/Ports & Subsystems/Subsystem', [Apprunnablepath '/OutputHarness' '/' 'Simulation'], 'Name', 'Simulation','Position',PositionArray);
Simulink.SubSystem.deleteContents(HandleSubSys);
blockoffset =   8 ;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+200)];
HandleSubSys = add_block('simulink/Ports & Subsystems/Subsystem', [Apprunnablepath '/InputHarness' '/' 'CodeGeneration'], 'Name', 'CodeGeneration','Position',PositionArray);
Simulink.SubSystem.deleteContents(HandleSubSys);
blockoffset =   8 ;
% CodeGeneration system creation inside OutputHarness 
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+200)];
HandleSubSys = add_block('simulink/Ports & Subsystems/Subsystem', [Apprunnablepath '/OutputHarness' '/' 'CodeGeneration'], 'Name', 'CodeGeneration','Position',PositionArray);
Simulink.SubSystem.deleteContents(HandleSubSys);
RunnableBlockPath = [RunnableName '_sys'];
Variantblockpath = [Apprunnablepath '/InputHarness'];
CodeGenblockpath = [Apprunnablepath '/InputHarness' '/' 'CodeGeneration'];
Simulationblockpath = [Apprunnablepath '/InputHarness' '/' 'Simulation'];
OutputCodeGenblockpath = [Apprunnablepath '/OutputHarness' '/' 'CodeGeneration'];
OutputSimulationblockpath = [Apprunnablepath '/OutputHarness' '/' 'Simulation'];
VariantOutputblockpath = [Apprunnablepath '/OutputHarness'];
mode = 2;
SIMULATION = Simulink.Variant('mode==1');
CODEGENERATION = Simulink.Variant('mode==2');
set_param(Simulationblockpath,'VariantControl','SIMULATION');
set_param(CodeGenblockpath,'VariantControl','CODEGENERATION');
%Associate Variant control to outputharness
set_param(OutputSimulationblockpath,'VariantControl','SIMULATION');
set_param(OutputCodeGenblockpath,'VariantControl','CODEGENERATION');

%% VARIANT CONFIG SUBSYSTEM ENDS
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
blockoffset = 9;
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

% ******************* Adding AutoSar Port rp_VehicleAppModeand Interface TI_WSS_VehAppMode *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_WSS_VehAppMode_rp_VehicleAppMode' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_VehicleAppMode';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_VehicleAppModeand Interface TI_WSS_VehAppMode *****************

% ******************* Adding AutoSar attribute WSSCurrentVehicleState as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_VehicleAppMode_WSSCurrentVehicleState';
blockoffset = 10;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'VehicleActiveModes');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'VehicleActiveModes');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'VehicleActiveModes');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'VehicleActiveModes');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'VehicleActiveModes');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'VehicleActiveModes');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'WSSCurrentVehicleState';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute WSSCurrentVehicleState as element *****************

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
blockoffset = 11;
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

% ******************* Adding AutoSar Port pp_Airbag_TT_Statusand Interface TIUpdateTelltaleStatus *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TIUpdateTelltaleStatus_pp_Airbag_TT_Status' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_Airbag_TT_Status';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_Airbag_TT_Statusand Interface TIUpdateTelltaleStatus *****************

% ******************* Adding AutoSar attribute CurrentTelltaleStatus as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_Airbag_TT_Status_CurrentTelltaleStatus';
blockoffsetop = 1;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'TT_OP_STATES');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'TT_OP_STATES');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'TT_OP_STATES');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'TT_OP_STATES');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'TT_OP_STATES');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'TT_OP_STATES');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'TT_OP_STATES');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'CurrentTelltaleStatus';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute CurrentTelltaleStatus as element *****************

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
% Auto connections for the Output harness codegeneration block
outport1 = find_system(OutputCodeGenblockpath, 'SearchDepth', 1, 'Type', 'block','BlockType', 'Inport','OutputFunctionCall', 'off');
for portIdx = 1:length(outport1)
PortName = get_param(outport1(portIdx), 'Name');
OutportPortName = strsplit(PortName{1}, '_in');
LineHandle = get_param(outport1(portIdx),'LineHandles');
PortNumber = int2str(1);
SubSysPortNumber = int2str(portIdx);
if isequal(LineHandle{1}.Outport,-1) == 1
add_line(OutputCodeGenblockpath, [PortName{1} '/' PortNumber], [OutportPortName{1} '/' PortNumber],'autorouting', 'on'); 
end
end

%%********** Adding TI if_CS_ComAbsSafeRx***** Adding CS Port  rp_CS_CanAdapterRx**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'if_CS_ComAbsSafeRx';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_CS_CanAdapterRx';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI if_CS_ComAbsSafeRx***** Finish Adding CS Port  rp_CS_CanAdapterRx**********

%%***** ADDING CS VARIABLE HOLDING TI RxCan_GetSafeSignalValue*****
Sl_CS_Operation = 'RxCan_GetSafeSignalValue';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_GetSafeSignalValue*****
ArgumentIn0 = 'SignalId' ;

ArgumentOut0 = 'pSignalValue' ;
ArgumentOut1 = 'pSignalStatus' ;
ArgumentOut2 = 'error_status' ;

Operation_prototype = '[pSignalValue,pSignalStatus,error_status ] = RxCan_GetSafeSignalValue( SignalId)'; 
blockoffset = 12;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSafeSignalId_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,tRxSafeSignalStatus_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut1 ,...
'Direction','Out',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut2 ,...
'Direction','Error',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_GetSafeSignalValue******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SetSignalInitValue*****
Sl_CS_Operation = 'RxCan_SetSignalInitValue';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SetSignalInitValue*****
ArgumentIn0 = 'SignalId' ;

ArgumentOut0 = 'pSignalValue' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[pSignalValue,error_status ] = RxCan_SetSignalInitValue( SignalId)'; 
blockoffset = 13;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSafeSignalId_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut1 ,...
'Direction','Error',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SetSignalInitValue******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalInvalidProcessingControl*****
Sl_CS_Operation = 'RxCan_SignalInvalidProcessingControl';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalInvalidProcessingControl*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'Status' ;


Operation_prototype = 'RxCan_SignalInvalidProcessingControl( SignalId,Status)'; 
blockoffset = 14;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSafeSignalId_type_instance(1) ,boolean(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalInvalidProcessingControl******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalMissingProcessingControl*****
Sl_CS_Operation = 'RxCan_SignalMissingProcessingControl';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalMissingProcessingControl*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'Status' ;


Operation_prototype = 'RxCan_SignalMissingProcessingControl( SignalId,Status)'; 
blockoffset = 15;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSafeSignalId_type_instance(1) ,boolean(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalMissingProcessingControl******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalNRProcessingControl*****
Sl_CS_Operation = 'RxCan_SignalNRProcessingControl';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalNRProcessingControl*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'Status' ;


Operation_prototype = 'RxCan_SignalNRProcessingControl( SignalId,Status)'; 
blockoffset = 16;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSafeSignalId_type_instance(1) ,boolean(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalNRProcessingControl******

%%***** ADDING CS VARIABLE HOLDING TI Mdl_SafetyAdapter_ReloadMissingTimer*****
Sl_CS_Operation = 'Mdl_SafetyAdapter_ReloadMissingTimer';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Mdl_SafetyAdapter_ReloadMissingTimer*****
ArgumentIn0 = 'SignalId' ;


Operation_prototype = 'Mdl_SafetyAdapter_ReloadMissingTimer( SignalId)'; 
blockoffset = 17;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSafeSignalId_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Mdl_SafetyAdapter_ReloadMissingTimer******

%%***** ADDING CS VARIABLE HOLDING TI RxCanVarInit*****
Sl_CS_Operation = 'RxCanVarInit';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCanVarInit*****


Operation_prototype = 'RxCanVarInit( )'; 
blockoffset = 18;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCanVarInit******

%%********** Adding TI if_CS_ComAbsRx***** Adding CS Port  rp_CS_CanRx**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'if_CS_ComAbsRx';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_CS_CanRx';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI if_CS_ComAbsRx***** Finish Adding CS Port  rp_CS_CanRx**********

%%***** ADDING CS VARIABLE HOLDING TI RxCan_GetSignalValue*****
Sl_CS_Operation = 'RxCan_GetSignalValue';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_GetSignalValue*****
ArgumentIn0 = 'SignalId' ;

ArgumentOut0 = 'pSignalValue' ;
ArgumentOut1 = 'pSignalStatus' ;
ArgumentOut2 = 'error_status' ;

Operation_prototype = '[pSignalValue,pSignalStatus,error_status ] = RxCan_GetSignalValue( SignalId)'; 
blockoffset = 19;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSignalId_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,tRxSignalStatus_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut1 ,...
'Direction','Out',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut2 ,...
'Direction','Error',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_GetSignalValue******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_GetSignalValueU8Arr*****
Sl_CS_Operation = 'RxCan_GetSignalValueU8Arr';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_GetSignalValueU8Arr*****
ArgumentIn0 = 'SignalId' ;

ArgumentOut0 = 'pSignalValue' ;
ArgumentOut1 = 'pSignalStatus' ;
ArgumentOut2 = 'pSignalLength' ;
ArgumentOut3 = 'error_status' ;

Operation_prototype = '[pSignalValue,pSignalStatus,pSignalLength,error_status ] = RxCan_GetSignalValueU8Arr( SignalId)'; 
blockoffset = 20;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSignalId_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,tRxSignalStatus_type_instance(1) ,uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut1 ,...
'Direction','Out',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut2 ,...
'Direction','Out',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut3 ,...
'Direction','Error',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_GetSignalValueU8Arr******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SetSignalInitValue*****
Sl_CS_Operation = 'RxCan_SetSignalInitValue';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SetSignalInitValue*****
ArgumentIn0 = 'SignalId' ;

ArgumentOut0 = 'pSignalValue' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[pSignalValue,error_status ] = RxCan_SetSignalInitValue( SignalId)'; 
blockoffset = 21;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSignalId_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut1 ,...
'Direction','Error',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SetSignalInitValue******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SetSignalInitValueU8Arr*****
Sl_CS_Operation = 'RxCan_SetSignalInitValueU8Arr';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SetSignalInitValueU8Arr*****
ArgumentIn0 = 'SignalId' ;

ArgumentOut0 = 'pSignaValue' ;
ArgumentOut1 = 'pSignalLength' ;
ArgumentOut2 = 'error_status' ;

Operation_prototype = '[pSignaValue,pSignalLength,error_status ] = RxCan_SetSignalInitValueU8Arr( SignalId)'; 
blockoffset = 22;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSignalId_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut1 ,...
'Direction','Out',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut2 ,...
'Direction','Error',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SetSignalInitValueU8Arr******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalInvalidProcessingControl*****
Sl_CS_Operation = 'RxCan_SignalInvalidProcessingControl';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalInvalidProcessingControl*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'Status' ;


Operation_prototype = 'RxCan_SignalInvalidProcessingControl( SignalId,Status)'; 
blockoffset = 23;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSignalId_type_instance(1) ,boolean(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalInvalidProcessingControl******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalMissingProcessingControl*****
Sl_CS_Operation = 'RxCan_SignalMissingProcessingControl';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalMissingProcessingControl*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'Status' ;


Operation_prototype = 'RxCan_SignalMissingProcessingControl( SignalId,Status)'; 
blockoffset = 24;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSignalId_type_instance(1) ,boolean(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalMissingProcessingControl******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalNRProcessingControl*****
Sl_CS_Operation = 'RxCan_SignalNRProcessingControl';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalNRProcessingControl*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'Status' ;


Operation_prototype = 'RxCan_SignalNRProcessingControl( SignalId,Status)'; 
blockoffset = 25;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSignalId_type_instance(1) ,boolean(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalNRProcessingControl******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalGetJustRcvdStatus*****
Sl_CS_Operation = 'RxCan_SignalGetJustRcvdStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalGetJustRcvdStatus*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'pJustRcvdStatus' ;


Operation_prototype = 'RxCan_SignalGetJustRcvdStatus( SignalId,pJustRcvdStatus)'; 
blockoffset = 26;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSignalId_type_instance(1) ,tRxSignalJustRcvdStatus_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
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


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalGetJustRcvdStatus******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalClearJustRcvdStatus*****
Sl_CS_Operation = 'RxCan_SignalClearJustRcvdStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalClearJustRcvdStatus*****
ArgumentIn0 = 'SignalId' ;


Operation_prototype = 'RxCan_SignalClearJustRcvdStatus( SignalId)'; 
blockoffset = 27;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tRxSignalId_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


autosar.api.syncModel(model_name);
mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalClearJustRcvdStatus******

%%********** Adding TI TI_SafeInit***** Adding CS Port  pp_Init**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_SafeInit';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'pp_Init';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Mdl_Airbag_Init*****
Sl_CS_Operation = 'Mdl_Airbag_Init';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Mdl_Airbag_Init*****


Operation_prototype = 'Mdl_Airbag_Init( )'; 
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
%%***** COMPLETED ADDING OPERATION Init******

autosar.api.syncModel(model_name);
try
autosar.api.validateModel(model_name)
catch validationErr
throw(validationErr)
end
