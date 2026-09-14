%% This is an Auto generated m script for adding the Autosar Ports and interfaces in Matlab Environment
close all; 
model_name = 'Mdl_Dim' ; 
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
RunnableName = ['Mdl_Dim_Task']; 
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

% ******************* Adding AutoSar Port rpVehicleAppModeand Interface TI_WSS_VehAppMode *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_WSS_VehAppMode_rpVehicleAppMode' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rpVehicleAppMode';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rpVehicleAppModeand Interface TI_WSS_VehAppMode *****************

% ******************* Adding AutoSar attribute WSSCurrentVehicleState as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rpVehicleAppMode_WSSCurrentVehicleState';
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

% ******************* Adding AutoSar Port rp_TFTDisplayOnand Interface TI_TFTDisplayOn *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_TFTDisplayOn_rp_TFTDisplayOn' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_TFTDisplayOn';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_TFTDisplayOnand Interface TI_TFTDisplayOn *****************

% ******************* Adding AutoSar attribute TFTDisplayOn as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_TFTDisplayOn_TFTDisplayOn';
blockoffset = 11;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'DisplayStatus');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'DisplayStatus');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'DisplayStatus');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'DisplayStatus');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'DisplayStatus');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'DisplayStatus');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'TFTDisplayOn';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute TFTDisplayOn as element *****************

% ******************* Adding AutoSar Port rp_EcoRunPresenceFlagand Interface TI_EcoRunPresenceFlag *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_EcoRunPresenceFlag_rp_EcoRunPresenceFlag' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_EcoRunPresenceFlag';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_EcoRunPresenceFlagand Interface TI_EcoRunPresenceFlag *****************

% ******************* Adding AutoSar attribute EcoRunPresenceFlag as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_EcoRunPresenceFlag_EcoRunPresenceFlag';
blockoffset = 12;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'EcoRunPresenceFlag';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute EcoRunPresenceFlag as element *****************

% ******************* Adding AutoSar Port rp_StopPwmUpdateand Interface TI_StopPwmUpdate *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_StopPwmUpdate_rp_StopPwmUpdate' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_StopPwmUpdate';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_StopPwmUpdateand Interface TI_StopPwmUpdate *****************

% ******************* Adding AutoSar attribute channel_id as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_StopPwmUpdate_channel_id';
blockoffset = 13;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'channel_id';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute channel_id as element *****************

% ******************* Adding AutoSar Port rp_PowerTrain_Stateand Interface TI_MVC_PowerTrain_State_Dummy *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_MVC_PowerTrain_State_Dummy_rp_PowerTrain_State' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_PowerTrain_State';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_PowerTrain_Stateand Interface TI_MVC_PowerTrain_State_Dummy *****************

% ******************* Adding AutoSar attribute PowerTrain_Flag as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_PowerTrain_State_PowerTrain_Flag';
blockoffset = 14;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'PowerTrain_Flag';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute PowerTrain_Flag as element *****************

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
blockoffset = 15;
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

% ******************* Adding AutoSar Port rp_Dcm_stop_appand Interface TI_SR_Dcm_AppStopNotification *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_Dcm_AppStopNotification_rp_Dcm_stop_app' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_Dcm_stop_app';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_Dcm_stop_appand Interface TI_SR_Dcm_AppStopNotification *****************

% ******************* Adding AutoSar attribute AppId as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_Dcm_stop_app_AppId';
blockoffset = 16;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'IOCtrl_Type');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'IOCtrl_Type');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'IOCtrl_Type');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'IOCtrl_Type');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'IOCtrl_Type');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'IOCtrl_Type');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'AppId';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute AppId as element *****************

% ******************* Adding AutoSar Port rp_Diag2F_Rheoand Interface TI_SR_Diag2F_Rheo *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_Diag2F_Rheo_rp_Diag2F_Rheo' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_Diag2F_Rheo';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_Diag2F_Rheoand Interface TI_SR_Diag2F_Rheo *****************

% ******************* Adding AutoSar attribute Diag_RheoStat as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_Diag2F_Rheo_Diag_RheoStat';
blockoffset = 17;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'Diag_RheoStat';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute Diag_RheoStat as element *****************

% ******************* Adding AutoSar Port rpEtmStsand Interface TI_Etm_Illum_Sts *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_Etm_Illum_Sts_rpEtmSts' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rpEtmSts';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rpEtmStsand Interface TI_Etm_Illum_Sts *****************

% ******************* Adding AutoSar attribute Illum_Status as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rpEtmSts_Illum_Status';
blockoffset = 18;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'Illum_Status';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute Illum_Status as element *****************

% ******************* Adding AutoSar Port rpIllum_Etmand Interface TIEtm_Illumination_dummy *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TIEtm_Illumination_dummy_rpIllum_Etm' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rpIllum_Etm';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rpIllum_Etmand Interface TIEtm_Illumination_dummy *****************

% ******************* Adding AutoSar attribute IllumStatus as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rpIllum_Etm_IllumStatus';
blockoffset = 19;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'IllumStatus';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute IllumStatus as element *****************

% ******************* Adding AutoSar Port rp_custom_resetand Interface TI_SR_UserID_Data *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_UserID_Data_rp_custom_reset' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_custom_reset';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_custom_resetand Interface TI_SR_UserID_Data *****************

% ******************* Adding AutoSar attribute CurrentUserID as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_custom_reset_CurrentUserID';
blockoffset = 20;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'UserIdType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'UserIdType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'UserIdType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'UserIdType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'UserIdType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'UserIdType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'CurrentUserID';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute CurrentUserID as element *****************

% ******************* Adding AutoSar attribute CustomizeReset as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_custom_reset_CustomizeReset';
blockoffset = 21;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'CustResetType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'CustResetType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'CustResetType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'CustResetType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'CustResetType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'CustResetType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'CustomizeReset';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute CustomizeReset as element *****************

% ******************* Adding AutoSar attribute SettingResetResult as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_custom_reset_SettingResetResult';
blockoffset = 22;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'SettingResetResult_Type');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'SettingResetResult_Type');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'SettingResetResult_Type');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'SettingResetResult_Type');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'SettingResetResult_Type');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'SettingResetResult_Type');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'SettingResetResult';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute SettingResetResult as element *****************

% ******************* Adding AutoSar Port rp_IlumDayNightRequiredand Interface TI_SR_IlumDayNightRequired *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_IlumDayNightRequired_rp_IlumDayNightRequired' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_IlumDayNightRequired';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_IlumDayNightRequiredand Interface TI_SR_IlumDayNightRequired *****************

% ******************* Adding AutoSar attribute IlumDayNightRequired as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_IlumDayNightRequired_IlumDayNightRequired';
blockoffset = 23;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'IlumDayNightRequired';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute IlumDayNightRequired as element *****************

% ******************* Adding AutoSar Port rp_IlumDayNightStatusand Interface TI_SR_Day_Night_Status *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_Day_Night_Status_rp_IlumDayNightStatus' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_IlumDayNightStatus';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_IlumDayNightStatusand Interface TI_SR_Day_Night_Status *****************

% ******************* Adding AutoSar attribute Day_Night_Status as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_IlumDayNightStatus_Day_Night_Status';
blockoffset = 24;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'Day_Night_Status';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute Day_Night_Status as element *****************

% ******************* Adding AutoSar Port rp_Ctrl_Ready_to_Sleepand Interface TI_Ctrl_Ready_to_sleep *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_Ctrl_Ready_to_sleep_rp_Ctrl_Ready_to_Sleep' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_Ctrl_Ready_to_Sleep';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_Ctrl_Ready_to_Sleepand Interface TI_Ctrl_Ready_to_sleep *****************

% ******************* Adding AutoSar attribute Ready_to_Sleep as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_Ctrl_Ready_to_Sleep_Ready_to_Sleep';
blockoffset = 25;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'boolean');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'boolean');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'boolean');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'boolean');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'boolean');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'boolean');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'Ready_to_Sleep';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute Ready_to_Sleep as element *****************

% ******************* Adding AutoSar Port rpEtmTTStsand Interface TIEtm_Illumination_dummy *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TIEtm_Illumination_dummy_rpEtmTTSts' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rpEtmTTSts';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rpEtmTTStsand Interface TIEtm_Illumination_dummy *****************

% ******************* Adding AutoSar attribute IllumStatus as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rpEtmTTSts_IllumStatus';
blockoffset = 26;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'IllumStatus';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute IllumStatus as element *****************

% ******************* Adding AutoSar Port pp_IlumDayNightRequiredand Interface TI_DayNightRequired *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_DayNightRequired_pp_IlumDayNightRequired' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_IlumDayNightRequired';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_IlumDayNightRequiredand Interface TI_DayNightRequired *****************

% ******************* Adding AutoSar attribute ilumDNRequired as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_IlumDayNightRequired_ilumDNRequired';
blockoffsetop = 1;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'ilumDNRequired';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute ilumDNRequired as element *****************

% ******************* Adding AutoSar Port pp_IlumDayNightStatusand Interface TI_DayNightStatus *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_DayNightStatus_pp_IlumDayNightStatus' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_IlumDayNightStatus';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_IlumDayNightStatusand Interface TI_DayNightStatus *****************

% ******************* Adding AutoSar attribute illumDNStatus as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_IlumDayNightStatus_illumDNStatus';
blockoffsetop = 2;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'illumDNStatus';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute illumDNStatus as element *****************

% ******************* Adding AutoSar Port pp_IlumStepand Interface TI_DimStepOutput *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_DimStepOutput_pp_IlumStep' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_IlumStep';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_IlumStepand Interface TI_DimStepOutput *****************

% ******************* Adding AutoSar attribute IllumStepValue as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_IlumStep_IllumStepValue';
blockoffsetop = 3;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'IllumStepValue';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute IllumStepValue as element *****************

% ******************* Adding AutoSar Port pp_RGBStepand Interface TI_RGBStepOutput *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_RGBStepOutput_pp_RGBStep' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_RGBStep';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_RGBStepand Interface TI_RGBStepOutput *****************

% ******************* Adding AutoSar attribute RGBStepValue as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_RGBStep_RGBStepValue';
blockoffsetop = 4;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'RGBStepValue';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute RGBStepValue as element *****************

% ******************* Adding AutoSar Port pp_illumStarterstatusand Interface TI_SR_Illum_StarterStatus *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_Illum_StarterStatus_pp_illumStarterstatus' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_illumStarterstatus';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_illumStarterstatusand Interface TI_SR_Illum_StarterStatus *****************

% ******************* Adding AutoSar attribute StarterStatus_Out as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_illumStarterstatus_StarterStatus_Out';
blockoffsetop = 5;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'StarterStatus_Out';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute StarterStatus_Out as element *****************

% ******************* Adding AutoSar Port pp_illumRheostatOnSTimerand Interface TI_SR_IllumRheostatONSTimer *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_IllumRheostatONSTimer_pp_illumRheostatOnSTimer' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_illumRheostatOnSTimer';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_illumRheostatOnSTimerand Interface TI_SR_IllumRheostatONSTimer *****************

% ******************* Adding AutoSar attribute Rheostat_OnSTime as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_illumRheostatOnSTimer_Rheostat_OnSTime';
blockoffsetop = 6;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'Rheostat_OnSTime';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute Rheostat_OnSTime as element *****************

% ******************* Adding AutoSar Port pp_IlluminationDutyand Interface TI_IlluminationDuty *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_IlluminationDuty_pp_IlluminationDuty' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_IlluminationDuty';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_IlluminationDutyand Interface TI_IlluminationDuty *****************

% ******************* Adding AutoSar attribute DutyValue as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_IlluminationDuty_DutyValue';
blockoffsetop = 7;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'DutyValue';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute DutyValue as element *****************

% ******************* Adding AutoSar Port pp_RheoSwStatusand Interface TI_RheoSwStatus *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_RheoSwStatus_pp_RheoSwStatus' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_RheoSwStatus';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_RheoSwStatusand Interface TI_RheoSwStatus *****************

% ******************* Adding AutoSar attribute SwitchStatus as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_RheoSwStatus_SwitchStatus';
blockoffsetop = 8;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'SwitchStatus';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute SwitchStatus as element *****************

% ******************* Adding AutoSar Port pp_illum_rheostat_changeand Interface TI_SR_RheostatChange *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_RheostatChange_pp_illum_rheostat_change' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_illum_rheostat_change';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_illum_rheostat_changeand Interface TI_SR_RheostatChange *****************

% ******************* Adding AutoSar attribute RheoUpdateVal as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_illum_rheostat_change_RheoUpdateVal';
blockoffsetop = 9;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'RheoUpdateVal';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute RheoUpdateVal as element *****************

% ******************* Adding AutoSar Port pp_RheoSwRaw_Statusand Interface TI_RheoSw_Raw_Status *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_RheoSw_Raw_Status_pp_RheoSwRaw_Status' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_RheoSwRaw_Status';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_RheoSwRaw_Statusand Interface TI_RheoSw_Raw_Status *****************

% ******************* Adding AutoSar attribute RawdataStatus as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_RheoSwRaw_Status_RawdataStatus';
blockoffsetop = 10;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'RawdataStatus';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute RawdataStatus as element *****************

% ******************* Adding AutoSar Port pp_Illum_Transstepand Interface TI_Illum_Transstep *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_Illum_Transstep_pp_Illum_Transstep' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_Illum_Transstep';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_Illum_Transstepand Interface TI_Illum_Transstep *****************

% ******************* Adding AutoSar attribute Trans_Stepvlaue as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_Illum_Transstep_Trans_Stepvlaue';
blockoffsetop = 11;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'Trans_Stepvlaue';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute Trans_Stepvlaue as element *****************

% ******************* Adding AutoSar Port pp_RheostatDayStepand Interface TI_RheostatDayStep *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_RheostatDayStep_pp_RheostatDayStep' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_RheostatDayStep';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_RheostatDayStepand Interface TI_RheostatDayStep *****************

% ******************* Adding AutoSar attribute RheostatDayStep as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_RheostatDayStep_RheostatDayStep';
blockoffsetop = 12;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'RheostatDayStep';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute RheostatDayStep as element *****************

% ******************* Adding AutoSar Port pp_RheostatNightStepand Interface TI_RheostatNightStep *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_RheostatNightStep_pp_RheostatNightStep' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_RheostatNightStep';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_RheostatNightStepand Interface TI_RheostatNightStep *****************

% ******************* Adding AutoSar attribute RheostatNightStep as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_RheostatNightStep_RheostatNightStep';
blockoffsetop = 13;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'RheostatNightStep';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute RheostatNightStep as element *****************

% ******************* Adding AutoSar Port pp_RHUP_Dbcand Interface TI_RHUP_Dbc *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_RHUP_Dbc_pp_RHUP_Dbc' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_RHUP_Dbc';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_RHUP_Dbcand Interface TI_RHUP_Dbc *****************

% ******************* Adding AutoSar attribute RHUP_Dbc as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_RHUP_Dbc_RHUP_Dbc';
blockoffsetop = 14;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'RHUP_Dbc';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute RHUP_Dbc as element *****************

% ******************* Adding AutoSar Port pp_RHDW_Dbcand Interface TI_RHDW_Dbc *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_RHDW_Dbc_pp_RHDW_Dbc' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_RHDW_Dbc';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_RHDW_Dbcand Interface TI_RHDW_Dbc *****************

% ******************* Adding AutoSar attribute RHDW_Dbc as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_RHDW_Dbc_RHDW_Dbc';
blockoffsetop = 15;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'RHDW_Dbc';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute RHDW_Dbc as element *****************

% ******************* Adding AutoSar Port pp_RheostatSwTypeand Interface TI_RheostatSwType *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_RheostatSwType_pp_RheostatSwType' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_RheostatSwType';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_RheostatSwTypeand Interface TI_RheostatSwType *****************

% ******************* Adding AutoSar attribute RheostatSwType as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_RheostatSwType_RheostatSwType';
blockoffsetop = 16;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'RheostatSwType';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute RheostatSwType as element *****************

% ******************* Adding AutoSar Port pp_RheostatONSStatusand Interface TI_RheostatONSStatus *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_RheostatONSStatus_pp_RheostatONSStatus' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_RheostatONSStatus';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_RheostatONSStatusand Interface TI_RheostatONSStatus *****************

% ******************* Adding AutoSar attribute RheostatONSStatus as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_RheostatONSStatus_RheostatONSStatus';
blockoffsetop = 17;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint8');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'RheostatONSStatus';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute RheostatONSStatus as element *****************

% ******************* Adding AutoSar Port pp_IllumCtrl_Ipand Interface TI_IllumCtrl_Ip *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_IllumCtrl_Ip_pp_IllumCtrl_Ip' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_IllumCtrl_Ip';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_IllumCtrl_Ipand Interface TI_IllumCtrl_Ip *****************

% ******************* Adding AutoSar attribute IllumCtrl_Ip_Data as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_IllumCtrl_Ip_IllumCtrl_Ip_Data';
blockoffsetop = 18;
PositionArray = [(leftoffset*10) (blockoffsetop * topoffset)  (leftoffset*10+30) ((blockoffsetop * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [model_name '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','-1');
set_param(HandleSR,'OutDataTypeStr', 'Bus:IllumCtrl_Ip');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [VariantOutputblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'Bus:IllumCtrl_Ip');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [VariantOutputblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'Bus:IllumCtrl_Ip');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputSimulationblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'Bus:IllumCtrl_Ip');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [OutputCodeGenblockpath '/' 'input'], 'Name', [Sl_SR_PortName '_in'],'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'Bus:IllumCtrl_Ip');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [OutputCodeGenblockpath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'Bus:IllumCtrl_Ip');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/' 'output'], 'Name', Sl_SR_PortName,'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'Bus:IllumCtrl_Ip');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Bus creator
blockoffsetop = 2;
BusName = 'IllumCtrl_Ip_Data';
BusObjectName = IllumCtrl_Ip;
BusBlockName = [BusName '_creator'];
PositionArray = [(leftoffset*5) (topoffset)  (leftoffset*5+10) ((topoffset)+300)];
HandleSR = add_block('simulink/Signal Routing/Bus Creator', [Apprunnablepath '/' 'Bus'], 'Name', BusBlockName,'Position',PositionArray);
set_param(HandleSR,'OutDataTypeStr', 'Bus:IllumCtrl_Ip');
NumberofElements = length(BusObjectName.Elements);
set_param(HandleSR,'Inputs', int2str(NumberofElements));
set_param(HandleSR,'NonVirtualBus', 'on');
add_line(Apprunnablepath, [BusBlockName '/1'], [Sl_SR_PortName '/1' ],'autorouting', 'on'); 
% Add the element 
element1 = 'IllumCtrl_Ip_Data';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute IllumCtrl_Ip_Data as element *****************

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

%%********** Adding TI if_CS_ComAbsRx***** Adding CS Port  rp_CS_RxCanMdl**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'if_CS_ComAbsRx';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_CS_RxCanMdl';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI if_CS_ComAbsRx***** Finish Adding CS Port  rp_CS_RxCanMdl**********

%%***** ADDING CS VARIABLE HOLDING TI RxCan_GetSignalValue*****
Sl_CS_Operation = 'RxCan_GetSignalValue';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_GetSignalValue*****
ArgumentIn0 = 'SignalId' ;

ArgumentOut0 = 'pSignalValue' ;
ArgumentOut1 = 'pSignalStatus' ;
ArgumentOut2 = 'error_status' ;

Operation_prototype = '[pSignalValue,pSignalStatus,error_status ] = RxCan_GetSignalValue( SignalId)'; 
blockoffset = 27;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
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
blockoffset = 28;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_GetSignalValueU8Arr******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SetSignalInitValue*****
Sl_CS_Operation = 'RxCan_SetSignalInitValue';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SetSignalInitValue*****
ArgumentIn0 = 'SignalId' ;

ArgumentOut0 = 'pSignalValue' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[pSignalValue,error_status ] = RxCan_SetSignalInitValue( SignalId)'; 
blockoffset = 29;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
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
blockoffset = 30;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SetSignalInitValueU8Arr******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalInvalidProcessingControl*****
Sl_CS_Operation = 'RxCan_SignalInvalidProcessingControl';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalInvalidProcessingControl*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'Status' ;


Operation_prototype = 'RxCan_SignalInvalidProcessingControl( SignalId,Status)'; 
blockoffset = 31;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalInvalidProcessingControl******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalMissingProcessingControl*****
Sl_CS_Operation = 'RxCan_SignalMissingProcessingControl';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalMissingProcessingControl*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'Status' ;


Operation_prototype = 'RxCan_SignalMissingProcessingControl( SignalId,Status)'; 
blockoffset = 32;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalMissingProcessingControl******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalNRProcessingControl*****
Sl_CS_Operation = 'RxCan_SignalNRProcessingControl';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalNRProcessingControl*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'Status' ;


Operation_prototype = 'RxCan_SignalNRProcessingControl( SignalId,Status)'; 
blockoffset = 33;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalNRProcessingControl******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalGetJustRcvdStatus*****
Sl_CS_Operation = 'RxCan_SignalGetJustRcvdStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalGetJustRcvdStatus*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'pJustRcvdStatus' ;


Operation_prototype = 'RxCan_SignalGetJustRcvdStatus( SignalId,pJustRcvdStatus)'; 
blockoffset = 34;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalGetJustRcvdStatus******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalClearJustRcvdStatus*****
Sl_CS_Operation = 'RxCan_SignalClearJustRcvdStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalClearJustRcvdStatus*****
ArgumentIn0 = 'SignalId' ;


Operation_prototype = 'RxCan_SignalClearJustRcvdStatus( SignalId)'; 
blockoffset = 35;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalClearJustRcvdStatus******

%%********** Adding TI TI_Variant_Status***** Adding CS Port  rp_Variant_Status**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_Variant_Status';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_Variant_Status';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI TI_Variant_Status***** Finish Adding CS Port  rp_Variant_Status**********

%%***** ADDING CS VARIABLE HOLDING TI GetVariant_Status*****
Sl_CS_Operation = 'GetVariant_Status';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION GetVariant_Status*****
ArgumentIn0 = 'Variant_Ind' ;

ArgumentOut0 = 'Variant_Status' ;

Operation_prototype = 'Variant_Status  = GetVariant_Status( Variant_Ind)'; 
blockoffset = 36;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetVariant_Status******

%%********** Adding TI TI_PwmCurrent_Duty***** Adding CS Port  rp_Current_duty**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_PwmCurrent_Duty';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_Current_duty';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI TI_PwmCurrent_Duty***** Finish Adding CS Port  rp_Current_duty**********

%%***** ADDING CS VARIABLE HOLDING TI GetPwmCurrentDuty*****
Sl_CS_Operation = 'GetPwmCurrentDuty';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION GetPwmCurrentDuty*****
ArgumentIn0 = 'ChannelID' ;

ArgumentOut0 = 'Channel_Duty' ;

Operation_prototype = 'Channel_Duty  = GetPwmCurrentDuty( ChannelID)'; 
blockoffset = 37;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetPwmCurrentDuty******

%%********** Adding TI TI_PwmDirect***** Adding CS Port  rp_UpdatePwmDirect**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_PwmDirect';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_UpdatePwmDirect';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI TI_PwmDirect***** Finish Adding CS Port  rp_UpdatePwmDirect**********

%%***** ADDING CS VARIABLE HOLDING TI GetPwmDirect*****
Sl_CS_Operation = 'GetPwmDirect';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION GetPwmDirect*****
ArgumentIn0 = 'ChannelID' ;
ArgumentIn1 = 'TargetDuty' ;


Operation_prototype = 'GetPwmDirect( ChannelID,TargetDuty)'; 
blockoffset = 38;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' IoHwAb_PwmSignalIdType_type_instance(1) ,uint16(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetPwmDirect******

%%********** Adding TI TI_PwmWithTimeExp***** Adding CS Port  rp_PwmWithTimeExp**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_PwmWithTimeExp';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_PwmWithTimeExp';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI TI_PwmWithTimeExp***** Finish Adding CS Port  rp_PwmWithTimeExp**********

%%***** ADDING CS VARIABLE HOLDING TI GetPwmWithTimeExp*****
Sl_CS_Operation = 'GetPwmWithTimeExp';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION GetPwmWithTimeExp*****
ArgumentIn0 = 'ChannelID' ;
ArgumentIn1 = 'TargetDuty' ;
ArgumentIn2 = 'TargetTime' ;


Operation_prototype = 'GetPwmWithTimeExp( ChannelID,TargetDuty,TargetTime)'; 
blockoffset = 39;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' IoHwAb_PwmSignalIdType_type_instance(1) ,uint16(1) ,uint16(1)');
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

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn2 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetPwmWithTimeExp******

%%********** Adding TI TI_PwmWithTime***** Adding CS Port  rp_PwmWithTime**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_PwmWithTime';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_PwmWithTime';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI TI_PwmWithTime***** Finish Adding CS Port  rp_PwmWithTime**********

%%***** ADDING CS VARIABLE HOLDING TI GetPwmWithTime*****
Sl_CS_Operation = 'GetPwmWithTime';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION GetPwmWithTime*****
ArgumentIn0 = 'ChannelID' ;
ArgumentIn1 = 'TargetDuty' ;
ArgumentIn2 = 'TargetTime' ;


Operation_prototype = 'GetPwmWithTime( ChannelID,TargetDuty,TargetTime)'; 
blockoffset = 40;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' IoHwAb_PwmSignalIdType_type_instance(1) ,uint16(1) ,uint16(1)');
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

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn2 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetPwmWithTime******

%%********** Adding TI TI_WSS_SWCAppSleepStatus***** Adding CS Port  rp_ILL_ReadyToSleep**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_WSS_SWCAppSleepStatus';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_ILL_ReadyToSleep';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI TI_WSS_SWCAppSleepStatus***** Finish Adding CS Port  rp_ILL_ReadyToSleep**********

%%***** ADDING CS VARIABLE HOLDING TI SWCSleepStatus*****
Sl_CS_Operation = 'SWCSleepStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION SWCSleepStatus*****
ArgumentIn0 = 'AppModule' ;
ArgumentIn1 = 'SleepStatus' ;


Operation_prototype = 'SWCSleepStatus( AppModule,SleepStatus)'; 
blockoffset = 41;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' eAppMdl_type_instance(1) ,eSleepSt_type_instance(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION SWCSleepStatus******

%%********** Adding TI TI_MVC_Get_Variant_State_Dummy***** Adding CS Port  rp_Get_Variant_Cfg**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_MVC_Get_Variant_State_Dummy';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_Get_Variant_Cfg';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI TI_MVC_Get_Variant_State_Dummy***** Finish Adding CS Port  rp_Get_Variant_Cfg**********

%%***** ADDING CS VARIABLE HOLDING TI Get_Variant_Config_State*****
Sl_CS_Operation = 'Get_Variant_Config_State';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_Variant_Config_State*****
ArgumentIn0 = 'VariantID' ;

ArgumentOut0 = 'VariantActiveSt' ;

Operation_prototype = 'VariantActiveSt  = Get_Variant_Config_State( VariantID)'; 
blockoffset = 42;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_Variant_Config_State******

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
blockoffset = 43;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
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
blockoffset = 44;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_GetSignalValueU8Arr******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SetSignalInitValue*****
Sl_CS_Operation = 'RxCan_SetSignalInitValue';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SetSignalInitValue*****
ArgumentIn0 = 'SignalId' ;

ArgumentOut0 = 'pSignalValue' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[pSignalValue,error_status ] = RxCan_SetSignalInitValue( SignalId)'; 
blockoffset = 45;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
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
blockoffset = 46;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SetSignalInitValueU8Arr******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalInvalidProcessingControl*****
Sl_CS_Operation = 'RxCan_SignalInvalidProcessingControl';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalInvalidProcessingControl*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'Status' ;


Operation_prototype = 'RxCan_SignalInvalidProcessingControl( SignalId,Status)'; 
blockoffset = 47;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalInvalidProcessingControl******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalMissingProcessingControl*****
Sl_CS_Operation = 'RxCan_SignalMissingProcessingControl';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalMissingProcessingControl*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'Status' ;


Operation_prototype = 'RxCan_SignalMissingProcessingControl( SignalId,Status)'; 
blockoffset = 48;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalMissingProcessingControl******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalNRProcessingControl*****
Sl_CS_Operation = 'RxCan_SignalNRProcessingControl';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalNRProcessingControl*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'Status' ;


Operation_prototype = 'RxCan_SignalNRProcessingControl( SignalId,Status)'; 
blockoffset = 49;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalNRProcessingControl******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalGetJustRcvdStatus*****
Sl_CS_Operation = 'RxCan_SignalGetJustRcvdStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalGetJustRcvdStatus*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'pJustRcvdStatus' ;


Operation_prototype = 'RxCan_SignalGetJustRcvdStatus( SignalId,pJustRcvdStatus)'; 
blockoffset = 50;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalGetJustRcvdStatus******

%%***** ADDING CS VARIABLE HOLDING TI RxCan_SignalClearJustRcvdStatus*****
Sl_CS_Operation = 'RxCan_SignalClearJustRcvdStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION RxCan_SignalClearJustRcvdStatus*****
ArgumentIn0 = 'SignalId' ;


Operation_prototype = 'RxCan_SignalClearJustRcvdStatus( SignalId)'; 
blockoffset = 51;
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION RxCan_SignalClearJustRcvdStatus******

%%********** Adding TI TI_IOHWAB_GetDIn***** Adding CS Port  rpIoHwAb_Din**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_IOHWAB_GetDIn';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rpIoHwAb_Din';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI TI_IOHWAB_GetDIn***** Finish Adding CS Port  rpIoHwAb_Din**********

%%***** ADDING CS VARIABLE HOLDING TI GetAsyncRawInput*****
Sl_CS_Operation = 'GetAsyncRawInput';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION GetAsyncRawInput*****
ArgumentIn0 = 'InputId' ;

ArgumentOut0 = 'AsyncInput' ;
ArgumentOut1 = 'ErrorStatus' ;
ArgumentOut2 = 'error_status' ;

Operation_prototype = '[AsyncInput,ErrorStatus,error_status ] = GetAsyncRawInput( InputId)'; 
blockoffset = 52;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' IoHwAb_DInSignalIdType_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' boolean(1) ,IoHwAb_ErrorType_type_instance(1) ,uint8(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetAsyncRawInput******

%%***** ADDING CS VARIABLE HOLDING TI GetProcessedInput*****
Sl_CS_Operation = 'GetProcessedInput';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION GetProcessedInput*****
ArgumentIn0 = 'InputId' ;

ArgumentOut0 = 'InputSignal' ;
ArgumentOut1 = 'ErrorStatus' ;
ArgumentOut2 = 'error_status' ;

Operation_prototype = '[InputSignal,ErrorStatus,error_status ] = GetProcessedInput( InputId)'; 
blockoffset = 53;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' IoHwAb_DInSignalIdType_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' boolean(1) ,IoHwAb_ErrorType_type_instance(1) ,uint8(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetProcessedInput******

%%***** ADDING CS VARIABLE HOLDING TI GetSyncRawInput*****
Sl_CS_Operation = 'GetSyncRawInput';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION GetSyncRawInput*****
ArgumentIn0 = 'InputId' ;

ArgumentOut0 = 'SyncInput' ;
ArgumentOut1 = 'ErrorStatus' ;
ArgumentOut2 = 'error_status' ;

Operation_prototype = '[SyncInput,ErrorStatus,error_status ] = GetSyncRawInput( InputId)'; 
blockoffset = 54;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' IoHwAb_DInSignalIdType_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' boolean(1) ,IoHwAb_ErrorType_type_instance(1) ,uint8(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetSyncRawInput******

%%***** ADDING CS VARIABLE HOLDING TI GetInputGroup*****
Sl_CS_Operation = 'GetInputGroup';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION GetInputGroup*****
ArgumentIn0 = 'InputId' ;

ArgumentOut0 = 'SyncInput' ;
ArgumentOut1 = 'ErrorStatus' ;
ArgumentOut2 = 'error_status' ;

Operation_prototype = '[SyncInput,ErrorStatus,error_status ] = GetInputGroup( InputId)'; 
blockoffset = 55;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' IoHwAb_DInGroupIdType_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,IoHwAb_ErrorType_type_instance(1) ,uint8(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetInputGroup******

%%********** Adding TI if_CS_MemAbsSet***** Adding CS Port  rp_CS_MemAbsSet**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'if_CS_MemAbsSet';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_CS_MemAbsSet';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI if_CS_MemAbsSet***** Finish Adding CS Port  rp_CS_MemAbsSet**********

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SwUpdReflash_Element*****
Sl_CS_Operation = 'Set_BsShare_SwUpdReflash_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SwUpdReflash_Element*****
ArgumentIn0 = 'BsShare_SwUpdReflash_Element' ;


Operation_prototype = 'Set_BsShare_SwUpdReflash_Element( BsShare_SwUpdReflash_Element)'; 
blockoffset = 56;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_8_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SwUpdReflash_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SwUpdFotaMode_Element*****
Sl_CS_Operation = 'Set_BsShare_SwUpdFotaMode_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SwUpdFotaMode_Element*****
ArgumentIn0 = 'BsShare_SwUpdFotaMode_Element' ;


Operation_prototype = 'Set_BsShare_SwUpdFotaMode_Element( BsShare_SwUpdFotaMode_Element)'; 
blockoffset = 57;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_16_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SwUpdFotaMode_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SwUpdFotaFinPrint_Element*****
Sl_CS_Operation = 'Set_BsShare_SwUpdFotaFinPrint_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SwUpdFotaFinPrint_Element*****
ArgumentIn0 = 'BsShare_SwUpdFotaFinPrint_Element' ;


Operation_prototype = 'Set_BsShare_SwUpdFotaFinPrint_Element( BsShare_SwUpdFotaFinPrint_Element)'; 
blockoffset = 58;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SwUpdFotaFinPrint_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SwUpdFotaStatus_Element*****
Sl_CS_Operation = 'Set_BsShare_SwUpdFotaStatus_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SwUpdFotaStatus_Element*****
ArgumentIn0 = 'BsShare_SwUpdFotaStatus_Element' ;


Operation_prototype = 'Set_BsShare_SwUpdFotaStatus_Element( BsShare_SwUpdFotaStatus_Element)'; 
blockoffset = 59;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_48_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SwUpdFotaStatus_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SwUpdFotadecrypt_Element*****
Sl_CS_Operation = 'Set_BsShare_SwUpdFotadecrypt_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SwUpdFotadecrypt_Element*****
ArgumentIn0 = 'BsShare_SwUpdFotadecrypt_Element' ;


Operation_prototype = 'Set_BsShare_SwUpdFotadecrypt_Element( BsShare_SwUpdFotadecrypt_Element)'; 
blockoffset = 60;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SwUpdFotadecrypt_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_EcuPartNumber_Element*****
Sl_CS_Operation = 'Set_BsShare_EcuPartNumber_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_EcuPartNumber_Element*****
ArgumentIn0 = 'BsShare_EcuPartNumber_Element' ;


Operation_prototype = 'Set_BsShare_EcuPartNumber_Element( BsShare_EcuPartNumber_Element)'; 
blockoffset = 61;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_61_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_EcuPartNumber_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_VisteonPartNumber*****
Sl_CS_Operation = 'Set_BsShare_VisteonPartNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_VisteonPartNumber*****
ArgumentIn0 = 'BsShare_VisteonPartNumber' ;


Operation_prototype = 'Set_BsShare_VisteonPartNumber( BsShare_VisteonPartNumber)'; 
blockoffset = 62;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_17_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_VisteonPartNumber******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_VisteonPCBPartNumber*****
Sl_CS_Operation = 'Set_BsShare_VisteonPCBPartNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_VisteonPCBPartNumber*****
ArgumentIn0 = 'BsShare_VisteonPCBPartNumber' ;


Operation_prototype = 'Set_BsShare_VisteonPCBPartNumber( BsShare_VisteonPCBPartNumber)'; 
blockoffset = 63;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_17_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_VisteonPCBPartNumber******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_ProductSerialNumber*****
Sl_CS_Operation = 'Set_BsShare_ProductSerialNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_ProductSerialNumber*****
ArgumentIn0 = 'BsShare_ProductSerialNumber' ;


Operation_prototype = 'Set_BsShare_ProductSerialNumber( BsShare_ProductSerialNumber)'; 
blockoffset = 64;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_10_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_ProductSerialNumber******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_PCBSerialNumber*****
Sl_CS_Operation = 'Set_BsShare_PCBSerialNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_PCBSerialNumber*****
ArgumentIn0 = 'BsShare_PCBSerialNumber' ;


Operation_prototype = 'Set_BsShare_PCBSerialNumber( BsShare_PCBSerialNumber)'; 
blockoffset = 65;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_9_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_PCBSerialNumber******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SMTManufacturingDate*****
Sl_CS_Operation = 'Set_BsShare_SMTManufacturingDate';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SMTManufacturingDate*****
ArgumentIn0 = 'BsShare_SMTManufacturingDate' ;


Operation_prototype = 'Set_BsShare_SMTManufacturingDate( BsShare_SMTManufacturingDate)'; 
blockoffset = 66;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_3_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SMTManufacturingDate******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_AssemblyManufacturingDate*****
Sl_CS_Operation = 'Set_BsShare_AssemblyManufacturingDate';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_AssemblyManufacturingDate*****
ArgumentIn0 = 'BsShare_AssemblyManufacturingDate' ;


Operation_prototype = 'Set_BsShare_AssemblyManufacturingDate( BsShare_AssemblyManufacturingDate)'; 
blockoffset = 67;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_3_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_AssemblyManufacturingDate******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SMTPlantNumber*****
Sl_CS_Operation = 'Set_BsShare_SMTPlantNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SMTPlantNumber*****
ArgumentIn0 = 'BsShare_SMTPlantNumber' ;


Operation_prototype = 'Set_BsShare_SMTPlantNumber( BsShare_SMTPlantNumber)'; 
blockoffset = 68;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_3_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SMTPlantNumber******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_AssemblyPlantNumber*****
Sl_CS_Operation = 'Set_BsShare_AssemblyPlantNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_AssemblyPlantNumber*****
ArgumentIn0 = 'BsShare_AssemblyPlantNumber' ;


Operation_prototype = 'Set_BsShare_AssemblyPlantNumber( BsShare_AssemblyPlantNumber)'; 
blockoffset = 69;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_3_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_AssemblyPlantNumber******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_HWModification*****
Sl_CS_Operation = 'Set_BsShare_HWModification';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_HWModification*****
ArgumentIn0 = 'BsShare_HWModification' ;


Operation_prototype = 'Set_BsShare_HWModification( BsShare_HWModification)'; 
blockoffset = 70;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint16(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_HWModification******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_VisMeet_Element*****
Sl_CS_Operation = 'Set_BsShare_VisMeet_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_VisMeet_Element*****
ArgumentIn0 = 'BsShare_VisMeet_Element' ;


Operation_prototype = 'Set_BsShare_VisMeet_Element( BsShare_VisMeet_Element)'; 
blockoffset = 71;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_46_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_VisMeet_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_VisMeet_EOLEntry_Element*****
Sl_CS_Operation = 'Set_BsShare_VisMeet_EOLEntry_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_VisMeet_EOLEntry_Element*****
ArgumentIn0 = 'BsShare_VisMeet_EOLEntry_Element' ;


Operation_prototype = 'Set_BsShare_VisMeet_EOLEntry_Element( BsShare_VisMeet_EOLEntry_Element)'; 
blockoffset = 72;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint16(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_VisMeet_EOLEntry_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_VehicleConfig_Element*****
Sl_CS_Operation = 'Set_BsShare_VehicleConfig_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_VehicleConfig_Element*****
ArgumentIn0 = 'BsShare_VehicleConfig_Element' ;


Operation_prototype = 'Set_BsShare_VehicleConfig_Element( BsShare_VehicleConfig_Element)'; 
blockoffset = 73;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_256_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_VehicleConfig_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_SpeedoGauge_Element*****
Sl_CS_Operation = 'Set_BsConst_SpeedoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_SpeedoGauge_Element*****
ArgumentIn0 = 'BsConst_SpeedoGauge_Element' ;


Operation_prototype = 'Set_BsConst_SpeedoGauge_Element( BsConst_SpeedoGauge_Element)'; 
blockoffset = 74;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_SpeedoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_TachoGauge_Element*****
Sl_CS_Operation = 'Set_BsConst_TachoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_TachoGauge_Element*****
ArgumentIn0 = 'BsConst_TachoGauge_Element' ;


Operation_prototype = 'Set_BsConst_TachoGauge_Element( BsConst_TachoGauge_Element)'; 
blockoffset = 75;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_TachoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_FuelGauge_Element*****
Sl_CS_Operation = 'Set_BsConst_FuelGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_FuelGauge_Element*****
ArgumentIn0 = 'BsConst_FuelGauge_Element' ;


Operation_prototype = 'Set_BsConst_FuelGauge_Element( BsConst_FuelGauge_Element)'; 
blockoffset = 76;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_128_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_FuelGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_TempGauge_Element*****
Sl_CS_Operation = 'Set_BsConst_TempGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_TempGauge_Element*****
ArgumentIn0 = 'BsConst_TempGauge_Element' ;


Operation_prototype = 'Set_BsConst_TempGauge_Element( BsConst_TempGauge_Element)'; 
blockoffset = 77;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_TempGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PowerGauge_Element*****
Sl_CS_Operation = 'Set_BsConst_PowerGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PowerGauge_Element*****
ArgumentIn0 = 'BsConst_PowerGauge_Element' ;


Operation_prototype = 'Set_BsConst_PowerGauge_Element( BsConst_PowerGauge_Element)'; 
blockoffset = 78;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PowerGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_OilGauge_Element*****
Sl_CS_Operation = 'Set_BsConst_OilGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_OilGauge_Element*****
ArgumentIn0 = 'BsConst_OilGauge_Element' ;


Operation_prototype = 'Set_BsConst_OilGauge_Element( BsConst_OilGauge_Element)'; 
blockoffset = 79;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_OilGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_TripComputer_Element*****
Sl_CS_Operation = 'Set_BsConst_TripComputer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_TripComputer_Element*****
ArgumentIn0 = 'BsConst_TripComputer_Element' ;


Operation_prototype = 'Set_BsConst_TripComputer_Element( BsConst_TripComputer_Element)'; 
blockoffset = 80;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_TripComputer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Compensation_Line_Slope_m*****
Sl_CS_Operation = 'Set_BsConst_Compensation_Line_Slope_m';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Compensation_Line_Slope_m*****
ArgumentIn0 = 'BsConst_Compensation_Line_Slope_m' ;


Operation_prototype = 'Set_BsConst_Compensation_Line_Slope_m( BsConst_Compensation_Line_Slope_m)'; 
blockoffset = 81;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint32(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Compensation_Line_Slope_m******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Compensation_Line_Shift_b*****
Sl_CS_Operation = 'Set_BsConst_Compensation_Line_Shift_b';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Compensation_Line_Shift_b*****
ArgumentIn0 = 'BsConst_Compensation_Line_Shift_b' ;


Operation_prototype = 'Set_BsConst_Compensation_Line_Shift_b( BsConst_Compensation_Line_Shift_b)'; 
blockoffset = 82;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint32(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Compensation_Line_Shift_b******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Lookup_Curve_HotSpot_Coef_X*****
Sl_CS_Operation = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_X';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_X*****
ArgumentIn0 = 'BsConst_Lookup_Curve_HotSpot_Coef_X' ;


Operation_prototype = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_X( BsConst_Lookup_Curve_HotSpot_Coef_X)'; 
blockoffset = 83;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u16_7_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_X******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Lookup_Curve_HotSpot_Coef_Y*****
Sl_CS_Operation = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_Y';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_Y*****
ArgumentIn0 = 'BsConst_Lookup_Curve_HotSpot_Coef_Y' ;


Operation_prototype = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_Y( BsConst_Lookup_Curve_HotSpot_Coef_Y)'; 
blockoffset = 84;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u16_7_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_Y******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Temp_Threshold_Hysteresis_Derating*****
Sl_CS_Operation = 'Set_BsConst_Temp_Threshold_Hysteresis_Derating';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Temp_Threshold_Hysteresis_Derating*****
ArgumentIn0 = 'BsConst_Temp_Threshold_Hysteresis_Derating' ;


Operation_prototype = 'Set_BsConst_Temp_Threshold_Hysteresis_Derating( BsConst_Temp_Threshold_Hysteresis_Derating)'; 
blockoffset = 85;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Temp_Threshold_Hysteresis_Derating******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Derating_Backlight_Disable*****
Sl_CS_Operation = 'Set_BsConst_Derating_Backlight_Disable';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Derating_Backlight_Disable*****
ArgumentIn0 = 'BsConst_Derating_Backlight_Disable' ;


Operation_prototype = 'Set_BsConst_Derating_Backlight_Disable( BsConst_Derating_Backlight_Disable)'; 
blockoffset = 86;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Derating_Backlight_Disable******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Temperature_Sensor_Conv*****
Sl_CS_Operation = 'Set_BsConst_Temperature_Sensor_Conv';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Temperature_Sensor_Conv*****
ArgumentIn0 = 'BsConst_Temperature_Sensor_Conv' ;


Operation_prototype = 'Set_BsConst_Temperature_Sensor_Conv( BsConst_Temperature_Sensor_Conv)'; 
blockoffset = 87;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Temperature_Sensor_Conv******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PCB_Temperature_Sensor_Conv*****
Sl_CS_Operation = 'Set_BsConst_PCB_Temperature_Sensor_Conv';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PCB_Temperature_Sensor_Conv*****
ArgumentIn0 = 'BsConst_PCB_Temperature_Sensor_Conv' ;


Operation_prototype = 'Set_BsConst_PCB_Temperature_Sensor_Conv( BsConst_PCB_Temperature_Sensor_Conv)'; 
blockoffset = 88;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PCB_Temperature_Sensor_Conv******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Display_Illum_Max_Level*****
Sl_CS_Operation = 'Set_BsConst_Display_Illum_Max_Level';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Display_Illum_Max_Level*****
ArgumentIn0 = 'BsConst_Display_Illum_Max_Level' ;


Operation_prototype = 'Set_BsConst_Display_Illum_Max_Level( BsConst_Display_Illum_Max_Level)'; 
blockoffset = 89;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint16(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Display_Illum_Max_Level******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PWM_boost_bypass_duty*****
Sl_CS_Operation = 'Set_BsConst_PWM_boost_bypass_duty';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PWM_boost_bypass_duty*****
ArgumentIn0 = 'BsConst_PWM_boost_bypass_duty' ;


Operation_prototype = 'Set_BsConst_PWM_boost_bypass_duty( BsConst_PWM_boost_bypass_duty)'; 
blockoffset = 90;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PWM_boost_bypass_duty******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_BsConst_Illumination_ReservedByte*****
Sl_CS_Operation = 'Set_BsConst_BsConst_Illumination_ReservedByte';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_BsConst_Illumination_ReservedByte*****
ArgumentIn0 = 'BsConst_BsConst_Illumination_ReservedByte' ;


Operation_prototype = 'Set_BsConst_BsConst_Illumination_ReservedByte( BsConst_BsConst_Illumination_ReservedByte)'; 
blockoffset = 91;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_28_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_BsConst_Illumination_ReservedByte******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Compensation_Line_Slope_m_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Compensation_Line_Slope_m_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Compensation_Line_Slope_m_SafeCopy1*****
ArgumentIn0 = 'BsConst_Compensation_Line_Slope_m_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Compensation_Line_Slope_m_SafeCopy1( BsConst_Compensation_Line_Slope_m_SafeCopy1)'; 
blockoffset = 92;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint32(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Compensation_Line_Slope_m_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Compensation_Line_Shift_b_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Compensation_Line_Shift_b_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Compensation_Line_Shift_b_SafeCopy1*****
ArgumentIn0 = 'BsConst_Compensation_Line_Shift_b_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Compensation_Line_Shift_b_SafeCopy1( BsConst_Compensation_Line_Shift_b_SafeCopy1)'; 
blockoffset = 93;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint32(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Compensation_Line_Shift_b_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1*****
ArgumentIn0 = 'BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1( BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1)'; 
blockoffset = 94;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u16_7_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1*****
ArgumentIn0 = 'BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1( BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1)'; 
blockoffset = 95;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u16_7_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1*****
ArgumentIn0 = 'BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1( BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1)'; 
blockoffset = 96;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Derating_Backlight_Disable_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Derating_Backlight_Disable_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Derating_Backlight_Disable_SafeCopy1*****
ArgumentIn0 = 'BsConst_Derating_Backlight_Disable_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Derating_Backlight_Disable_SafeCopy1( BsConst_Derating_Backlight_Disable_SafeCopy1)'; 
blockoffset = 97;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Derating_Backlight_Disable_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Temperature_Sensor_Conv_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Temperature_Sensor_Conv_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Temperature_Sensor_Conv_SafeCopy1*****
ArgumentIn0 = 'BsConst_Temperature_Sensor_Conv_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Temperature_Sensor_Conv_SafeCopy1( BsConst_Temperature_Sensor_Conv_SafeCopy1)'; 
blockoffset = 98;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Temperature_Sensor_Conv_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1*****
ArgumentIn0 = 'BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1( BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1)'; 
blockoffset = 99;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Display_Illum_Max_Level_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Display_Illum_Max_Level_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Display_Illum_Max_Level_SafeCopy1*****
ArgumentIn0 = 'BsConst_Display_Illum_Max_Level_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Display_Illum_Max_Level_SafeCopy1( BsConst_Display_Illum_Max_Level_SafeCopy1)'; 
blockoffset = 100;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint16(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Display_Illum_Max_Level_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PWM_boost_bypass_duty_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_PWM_boost_bypass_duty_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PWM_boost_bypass_duty_SafeCopy1*****
ArgumentIn0 = 'BsConst_PWM_boost_bypass_duty_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_PWM_boost_bypass_duty_SafeCopy1( BsConst_PWM_boost_bypass_duty_SafeCopy1)'; 
blockoffset = 101;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PWM_boost_bypass_duty_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1*****
ArgumentIn0 = 'BsConst_BsConst_Illumination_ReservedByte_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1( BsConst_BsConst_Illumination_ReservedByte_SafeCopy1)'; 
blockoffset = 102;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_28_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Compensation_Line_Slope_m_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Compensation_Line_Slope_m_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Compensation_Line_Slope_m_SafeCopy2*****
ArgumentIn0 = 'BsConst_Compensation_Line_Slope_m_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Compensation_Line_Slope_m_SafeCopy2( BsConst_Compensation_Line_Slope_m_SafeCopy2)'; 
blockoffset = 103;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint32(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Compensation_Line_Slope_m_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Compensation_Line_Shift_b_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Compensation_Line_Shift_b_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Compensation_Line_Shift_b_SafeCopy2*****
ArgumentIn0 = 'BsConst_Compensation_Line_Shift_b_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Compensation_Line_Shift_b_SafeCopy2( BsConst_Compensation_Line_Shift_b_SafeCopy2)'; 
blockoffset = 104;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint32(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Compensation_Line_Shift_b_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2*****
ArgumentIn0 = 'BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2( BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2)'; 
blockoffset = 105;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u16_7_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2*****
ArgumentIn0 = 'BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2( BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2)'; 
blockoffset = 106;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u16_7_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2*****
ArgumentIn0 = 'BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2( BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2)'; 
blockoffset = 107;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Derating_Backlight_Disable_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Derating_Backlight_Disable_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Derating_Backlight_Disable_SafeCopy2*****
ArgumentIn0 = 'BsConst_Derating_Backlight_Disable_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Derating_Backlight_Disable_SafeCopy2( BsConst_Derating_Backlight_Disable_SafeCopy2)'; 
blockoffset = 108;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Derating_Backlight_Disable_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Temperature_Sensor_Conv_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Temperature_Sensor_Conv_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Temperature_Sensor_Conv_SafeCopy2*****
ArgumentIn0 = 'BsConst_Temperature_Sensor_Conv_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Temperature_Sensor_Conv_SafeCopy2( BsConst_Temperature_Sensor_Conv_SafeCopy2)'; 
blockoffset = 109;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Temperature_Sensor_Conv_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2*****
ArgumentIn0 = 'BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2( BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2)'; 
blockoffset = 110;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Display_Illum_Max_Level_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Display_Illum_Max_Level_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Display_Illum_Max_Level_SafeCopy2*****
ArgumentIn0 = 'BsConst_Display_Illum_Max_Level_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Display_Illum_Max_Level_SafeCopy2( BsConst_Display_Illum_Max_Level_SafeCopy2)'; 
blockoffset = 111;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint16(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Display_Illum_Max_Level_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PWM_boost_bypass_duty_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_PWM_boost_bypass_duty_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PWM_boost_bypass_duty_SafeCopy2*****
ArgumentIn0 = 'BsConst_PWM_boost_bypass_duty_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_PWM_boost_bypass_duty_SafeCopy2( BsConst_PWM_boost_bypass_duty_SafeCopy2)'; 
blockoffset = 112;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PWM_boost_bypass_duty_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2*****
ArgumentIn0 = 'BsConst_BsConst_Illumination_ReservedByte_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2( BsConst_BsConst_Illumination_ReservedByte_SafeCopy2)'; 
blockoffset = 113;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_28_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Audio_Element*****
Sl_CS_Operation = 'Set_BsConst_Audio_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Audio_Element*****
ArgumentIn0 = 'BsConst_Audio_Element' ;


Operation_prototype = 'Set_BsConst_Audio_Element( BsConst_Audio_Element)'; 
blockoffset = 114;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_128_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Audio_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Warning_Element*****
Sl_CS_Operation = 'Set_BsConst_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Warning_Element*****
ArgumentIn0 = 'BsConst_Warning_Element' ;


Operation_prototype = 'Set_BsConst_Warning_Element( BsConst_Warning_Element)'; 
blockoffset = 115;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_RealTimeClock_Element*****
Sl_CS_Operation = 'Set_BsConst_RealTimeClock_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_RealTimeClock_Element*****
ArgumentIn0 = 'BsConst_RealTimeClock_Element' ;


Operation_prototype = 'Set_BsConst_RealTimeClock_Element( BsConst_RealTimeClock_Element)'; 
blockoffset = 116;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_48_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_RealTimeClock_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Communication_Element*****
Sl_CS_Operation = 'Set_BsConst_Communication_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Communication_Element*****
ArgumentIn0 = 'BsConst_Communication_Element' ;


Operation_prototype = 'Set_BsConst_Communication_Element( BsConst_Communication_Element)'; 
blockoffset = 117;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Communication_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Power_Element*****
Sl_CS_Operation = 'Set_BsConst_Power_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Power_Element*****
ArgumentIn0 = 'BsConst_Power_Element' ;


Operation_prototype = 'Set_BsConst_Power_Element( BsConst_Power_Element)'; 
blockoffset = 118;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Power_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_ServiceReminder_Element*****
Sl_CS_Operation = 'Set_BsConst_ServiceReminder_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_ServiceReminder_Element*****
ArgumentIn0 = 'BsConst_ServiceReminder_Element' ;


Operation_prototype = 'Set_BsConst_ServiceReminder_Element( BsConst_ServiceReminder_Element)'; 
blockoffset = 119;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_48_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_ServiceReminder_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_EngOffTimer_Element*****
Sl_CS_Operation = 'Set_BsConst_EngOffTimer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_EngOffTimer_Element*****
ArgumentIn0 = 'BsConst_EngOffTimer_Element' ;


Operation_prototype = 'Set_BsConst_EngOffTimer_Element( BsConst_EngOffTimer_Element)'; 
blockoffset = 120;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_EngOffTimer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsCys_Certicificate_Element*****
Sl_CS_Operation = 'Set_BsCys_Certicificate_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsCys_Certicificate_Element*****
ArgumentIn0 = 'BsCys_Certicificate_Element' ;


Operation_prototype = 'Set_BsCys_Certicificate_Element( BsCys_Certicificate_Element)'; 
blockoffset = 121;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsCys_Certicificate_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_RefCys_Certicificate_Element*****
Sl_CS_Operation = 'Set_RefCys_Certicificate_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_RefCys_Certicificate_Element*****
ArgumentIn0 = 'RefCys_Certicificate_Element' ;


Operation_prototype = 'Set_RefCys_Certicificate_Element( RefCys_Certicificate_Element)'; 
blockoffset = 122;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_RefCys_Certicificate_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_RefCys_Certicificate1_Element*****
Sl_CS_Operation = 'Set_RefCys_Certicificate1_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_RefCys_Certicificate1_Element*****
ArgumentIn0 = 'RefCys_Certicificate1_Element' ;


Operation_prototype = 'Set_RefCys_Certicificate1_Element( RefCys_Certicificate1_Element)'; 
blockoffset = 123;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_RefCys_Certicificate1_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_Odometer_Element*****
Sl_CS_Operation = 'Set_BsRt_Odometer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_Odometer_Element*****
ArgumentIn0 = 'BsRt_Odometer_Element' ;


Operation_prototype = 'Set_BsRt_Odometer_Element( BsRt_Odometer_Element)'; 
blockoffset = 124;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_128_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_Odometer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_SpeedoGauge_Element*****
Sl_CS_Operation = 'Set_BsRt_SpeedoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_SpeedoGauge_Element*****
ArgumentIn0 = 'BsRt_SpeedoGauge_Element' ;


Operation_prototype = 'Set_BsRt_SpeedoGauge_Element( BsRt_SpeedoGauge_Element)'; 
blockoffset = 125;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_8_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_SpeedoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_TachoGauge_Element*****
Sl_CS_Operation = 'Set_BsRt_TachoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_TachoGauge_Element*****
ArgumentIn0 = 'BsRt_TachoGauge_Element' ;


Operation_prototype = 'Set_BsRt_TachoGauge_Element( BsRt_TachoGauge_Element)'; 
blockoffset = 126;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_16_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_TachoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_FuelGauge_Element*****
Sl_CS_Operation = 'Set_BsRt_FuelGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_FuelGauge_Element*****
ArgumentIn0 = 'BsRt_FuelGauge_Element' ;


Operation_prototype = 'Set_BsRt_FuelGauge_Element( BsRt_FuelGauge_Element)'; 
blockoffset = 127;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_FuelGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_TempGauge_Element*****
Sl_CS_Operation = 'Set_BsRt_TempGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_TempGauge_Element*****
ArgumentIn0 = 'BsRt_TempGauge_Element' ;


Operation_prototype = 'Set_BsRt_TempGauge_Element( BsRt_TempGauge_Element)'; 
blockoffset = 128;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_TempGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_PowerGauge_Element*****
Sl_CS_Operation = 'Set_BsRt_PowerGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_PowerGauge_Element*****
ArgumentIn0 = 'BsRt_PowerGauge_Element' ;


Operation_prototype = 'Set_BsRt_PowerGauge_Element( BsRt_PowerGauge_Element)'; 
blockoffset = 129;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_PowerGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_OilGauge_Element*****
Sl_CS_Operation = 'Set_BsRt_OilGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_OilGauge_Element*****
ArgumentIn0 = 'BsRt_OilGauge_Element' ;


Operation_prototype = 'Set_BsRt_OilGauge_Element( BsRt_OilGauge_Element)'; 
blockoffset = 130;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_8_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_OilGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_TripComputer_Element*****
Sl_CS_Operation = 'Set_BsRt_TripComputer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_TripComputer_Element*****
ArgumentIn0 = 'BsRt_TripComputer_Element' ;


Operation_prototype = 'Set_BsRt_TripComputer_Element( BsRt_TripComputer_Element)'; 
blockoffset = 131;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_TripComputer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_Warning_Element*****
Sl_CS_Operation = 'Set_BsRt_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_Warning_Element*****
ArgumentIn0 = 'BsRt_Warning_Element' ;


Operation_prototype = 'Set_BsRt_Warning_Element( BsRt_Warning_Element)'; 
blockoffset = 132;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_RealTimeClock_Element*****
Sl_CS_Operation = 'Set_BsRt_RealTimeClock_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_RealTimeClock_Element*****
ArgumentIn0 = 'BsRt_RealTimeClock_Element' ;


Operation_prototype = 'Set_BsRt_RealTimeClock_Element( BsRt_RealTimeClock_Element)'; 
blockoffset = 133;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_48_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_RealTimeClock_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_Personalization_Element*****
Sl_CS_Operation = 'Set_BsRt_Personalization_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_Personalization_Element*****
ArgumentIn0 = 'BsRt_Personalization_Element' ;


Operation_prototype = 'Set_BsRt_Personalization_Element( BsRt_Personalization_Element)'; 
blockoffset = 134;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_128_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_Personalization_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_Illumination_Element*****
Sl_CS_Operation = 'Set_BsRt_Illumination_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_Illumination_Element*****
ArgumentIn0 = 'BsRt_Illumination_Element' ;


Operation_prototype = 'Set_BsRt_Illumination_Element( BsRt_Illumination_Element)'; 
blockoffset = 135;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_Illumination_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_CusDlt_Element*****
Sl_CS_Operation = 'Set_BsRt_CusDlt_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_CusDlt_Element*****
ArgumentIn0 = 'BsRt_CusDlt_Element' ;


Operation_prototype = 'Set_BsRt_CusDlt_Element( BsRt_CusDlt_Element)'; 
blockoffset = 136;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_128_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_CusDlt_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Odometer_Element*****
Sl_CS_Operation = 'Set_BsReten_Odometer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Odometer_Element*****
ArgumentIn0 = 'BsReten_Odometer_Element' ;


Operation_prototype = 'Set_BsReten_Odometer_Element( BsReten_Odometer_Element)'; 
blockoffset = 137;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Odometer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Gauges_Element*****
Sl_CS_Operation = 'Set_BsReten_Gauges_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Gauges_Element*****
ArgumentIn0 = 'BsReten_Gauges_Element' ;


Operation_prototype = 'Set_BsReten_Gauges_Element( BsReten_Gauges_Element)'; 
blockoffset = 138;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Gauges_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Tripcomputer_Element*****
Sl_CS_Operation = 'Set_BsReten_Tripcomputer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Tripcomputer_Element*****
ArgumentIn0 = 'BsReten_Tripcomputer_Element' ;


Operation_prototype = 'Set_BsReten_Tripcomputer_Element( BsReten_Tripcomputer_Element)'; 
blockoffset = 139;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Tripcomputer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Illumination_Element*****
Sl_CS_Operation = 'Set_BsReten_Illumination_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Illumination_Element*****
ArgumentIn0 = 'BsReten_Illumination_Element' ;


Operation_prototype = 'Set_BsReten_Illumination_Element( BsReten_Illumination_Element)'; 
blockoffset = 140;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Illumination_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Audio_Element*****
Sl_CS_Operation = 'Set_BsReten_Audio_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Audio_Element*****
ArgumentIn0 = 'BsReten_Audio_Element' ;


Operation_prototype = 'Set_BsReten_Audio_Element( BsReten_Audio_Element)'; 
blockoffset = 141;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Audio_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Warning_Element*****
Sl_CS_Operation = 'Set_BsReten_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Warning_Element*****
ArgumentIn0 = 'BsReten_Warning_Element' ;


Operation_prototype = 'Set_BsReten_Warning_Element( BsReten_Warning_Element)'; 
blockoffset = 142;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_RealTimeClock_Element*****
Sl_CS_Operation = 'Set_BsReten_RealTimeClock_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_RealTimeClock_Element*****
ArgumentIn0 = 'BsReten_RealTimeClock_Element' ;


Operation_prototype = 'Set_BsReten_RealTimeClock_Element( BsReten_RealTimeClock_Element)'; 
blockoffset = 143;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_RealTimeClock_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Communication_Element*****
Sl_CS_Operation = 'Set_BsReten_Communication_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Communication_Element*****
ArgumentIn0 = 'BsReten_Communication_Element' ;


Operation_prototype = 'Set_BsReten_Communication_Element( BsReten_Communication_Element)'; 
blockoffset = 144;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Communication_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Personalization_Element*****
Sl_CS_Operation = 'Set_BsReten_Personalization_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Personalization_Element*****
ArgumentIn0 = 'BsReten_Personalization_Element' ;


Operation_prototype = 'Set_BsReten_Personalization_Element( BsReten_Personalization_Element)'; 
blockoffset = 145;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Personalization_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_VisDlt_Element*****
Sl_CS_Operation = 'Set_BsReten_VisDlt_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_VisDlt_Element*****
ArgumentIn0 = 'BsReten_VisDlt_Element' ;


Operation_prototype = 'Set_BsReten_VisDlt_Element( BsReten_VisDlt_Element)'; 
blockoffset = 146;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_256_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_VisDlt_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Power_Element*****
Sl_CS_Operation = 'Set_BsReten_Power_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Power_Element*****
ArgumentIn0 = 'BsReten_Power_Element' ;


Operation_prototype = 'Set_BsReten_Power_Element( BsReten_Power_Element)'; 
blockoffset = 147;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Power_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Display_Element*****
Sl_CS_Operation = 'Set_BsReten_Display_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Display_Element*****
ArgumentIn0 = 'BsReten_Display_Element' ;


Operation_prototype = 'Set_BsReten_Display_Element( BsReten_Display_Element)'; 
blockoffset = 148;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Display_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsDiag_ErrorRecord_Element*****
Sl_CS_Operation = 'Set_BsDiag_ErrorRecord_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsDiag_ErrorRecord_Element*****
ArgumentIn0 = 'BsDiag_ErrorRecord_Element' ;


Operation_prototype = 'Set_BsDiag_ErrorRecord_Element( BsDiag_ErrorRecord_Element)'; 
blockoffset = 149;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_1024_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsDiag_ErrorRecord_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsDiag_Dtc_Element*****
Sl_CS_Operation = 'Set_BsDiag_Dtc_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsDiag_Dtc_Element*****
ArgumentIn0 = 'BsDiag_Dtc_Element' ;


Operation_prototype = 'Set_BsDiag_Dtc_Element( BsDiag_Dtc_Element)'; 
blockoffset = 150;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_2048_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsDiag_Dtc_Element******

%%********** Adding TI if_CS_MemAbsGet***** Adding CS Port  rp_CS_MemAbsGet**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'if_CS_MemAbsGet';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_CS_MemAbsGet';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI if_CS_MemAbsGet***** Finish Adding CS Port  rp_CS_MemAbsGet**********

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SwUpdReflash_Element*****
Sl_CS_Operation = 'Get_BsShare_SwUpdReflash_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SwUpdReflash_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SwUpdReflash_Element( )'; 
blockoffset = 151;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_8_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SwUpdReflash_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SwUpdFotaMode_Element*****
Sl_CS_Operation = 'Get_BsShare_SwUpdFotaMode_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SwUpdFotaMode_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SwUpdFotaMode_Element( )'; 
blockoffset = 152;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_16_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SwUpdFotaMode_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SwUpdFotaFinPrint_Element*****
Sl_CS_Operation = 'Get_BsShare_SwUpdFotaFinPrint_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SwUpdFotaFinPrint_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SwUpdFotaFinPrint_Element( )'; 
blockoffset = 153;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SwUpdFotaFinPrint_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SwUpdFotaStatus_Element*****
Sl_CS_Operation = 'Get_BsShare_SwUpdFotaStatus_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SwUpdFotaStatus_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SwUpdFotaStatus_Element( )'; 
blockoffset = 154;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_48_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SwUpdFotaStatus_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SwUpdFotadecrypt_Element*****
Sl_CS_Operation = 'Get_BsShare_SwUpdFotadecrypt_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SwUpdFotadecrypt_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SwUpdFotadecrypt_Element( )'; 
blockoffset = 155;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SwUpdFotadecrypt_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_EcuPartNumber_Element*****
Sl_CS_Operation = 'Get_BsShare_EcuPartNumber_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_EcuPartNumber_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_EcuPartNumber_Element( )'; 
blockoffset = 156;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_61_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_EcuPartNumber_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_VisteonPartNumber*****
Sl_CS_Operation = 'Get_BsShare_VisteonPartNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_VisteonPartNumber*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_VisteonPartNumber( )'; 
blockoffset = 157;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_17_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_VisteonPartNumber******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_VisteonPCBPartNumber*****
Sl_CS_Operation = 'Get_BsShare_VisteonPCBPartNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_VisteonPCBPartNumber*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_VisteonPCBPartNumber( )'; 
blockoffset = 158;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_17_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_VisteonPCBPartNumber******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_ProductSerialNumber*****
Sl_CS_Operation = 'Get_BsShare_ProductSerialNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_ProductSerialNumber*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_ProductSerialNumber( )'; 
blockoffset = 159;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_10_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_ProductSerialNumber******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_PCBSerialNumber*****
Sl_CS_Operation = 'Get_BsShare_PCBSerialNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_PCBSerialNumber*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_PCBSerialNumber( )'; 
blockoffset = 160;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_9_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_PCBSerialNumber******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SMTManufacturingDate*****
Sl_CS_Operation = 'Get_BsShare_SMTManufacturingDate';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SMTManufacturingDate*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SMTManufacturingDate( )'; 
blockoffset = 161;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_3_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SMTManufacturingDate******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_AssemblyManufacturingDate*****
Sl_CS_Operation = 'Get_BsShare_AssemblyManufacturingDate';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_AssemblyManufacturingDate*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_AssemblyManufacturingDate( )'; 
blockoffset = 162;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_3_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_AssemblyManufacturingDate******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SMTPlantNumber*****
Sl_CS_Operation = 'Get_BsShare_SMTPlantNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SMTPlantNumber*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SMTPlantNumber( )'; 
blockoffset = 163;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_3_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SMTPlantNumber******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_AssemblyPlantNumber*****
Sl_CS_Operation = 'Get_BsShare_AssemblyPlantNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_AssemblyPlantNumber*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_AssemblyPlantNumber( )'; 
blockoffset = 164;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_3_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_AssemblyPlantNumber******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_HWModification*****
Sl_CS_Operation = 'Get_BsShare_HWModification';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_HWModification*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_HWModification( )'; 
blockoffset = 165;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_HWModification******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_VisMeet_Element*****
Sl_CS_Operation = 'Get_BsShare_VisMeet_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_VisMeet_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_VisMeet_Element( )'; 
blockoffset = 166;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_46_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_VisMeet_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_VisMeet_EOLEntry_Element*****
Sl_CS_Operation = 'Get_BsShare_VisMeet_EOLEntry_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_VisMeet_EOLEntry_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_VisMeet_EOLEntry_Element( )'; 
blockoffset = 167;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_VisMeet_EOLEntry_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_VehicleConfig_Element*****
Sl_CS_Operation = 'Get_BsShare_VehicleConfig_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_VehicleConfig_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_VehicleConfig_Element( )'; 
blockoffset = 168;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_256_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_VehicleConfig_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_SpeedoGauge_Element*****
Sl_CS_Operation = 'Get_BsConst_SpeedoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_SpeedoGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_SpeedoGauge_Element( )'; 
blockoffset = 169;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_SpeedoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_TachoGauge_Element*****
Sl_CS_Operation = 'Get_BsConst_TachoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_TachoGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_TachoGauge_Element( )'; 
blockoffset = 170;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_TachoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_FuelGauge_Element*****
Sl_CS_Operation = 'Get_BsConst_FuelGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_FuelGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_FuelGauge_Element( )'; 
blockoffset = 171;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_128_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_FuelGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_TempGauge_Element*****
Sl_CS_Operation = 'Get_BsConst_TempGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_TempGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_TempGauge_Element( )'; 
blockoffset = 172;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_TempGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PowerGauge_Element*****
Sl_CS_Operation = 'Get_BsConst_PowerGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PowerGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PowerGauge_Element( )'; 
blockoffset = 173;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PowerGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_OilGauge_Element*****
Sl_CS_Operation = 'Get_BsConst_OilGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_OilGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_OilGauge_Element( )'; 
blockoffset = 174;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_OilGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_TripComputer_Element*****
Sl_CS_Operation = 'Get_BsConst_TripComputer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_TripComputer_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_TripComputer_Element( )'; 
blockoffset = 175;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_TripComputer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Compensation_Line_Slope_m*****
Sl_CS_Operation = 'Get_BsConst_Compensation_Line_Slope_m';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Compensation_Line_Slope_m*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Compensation_Line_Slope_m( )'; 
blockoffset = 176;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Compensation_Line_Slope_m******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Compensation_Line_Shift_b*****
Sl_CS_Operation = 'Get_BsConst_Compensation_Line_Shift_b';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Compensation_Line_Shift_b*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Compensation_Line_Shift_b( )'; 
blockoffset = 177;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Compensation_Line_Shift_b******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Lookup_Curve_HotSpot_Coef_X*****
Sl_CS_Operation = 'Get_BsConst_Lookup_Curve_HotSpot_Coef_X';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_X*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Lookup_Curve_HotSpot_Coef_X( )'; 
blockoffset = 178;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u16_7_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_X******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Lookup_Curve_HotSpot_Coef_Y*****
Sl_CS_Operation = 'Get_BsConst_Lookup_Curve_HotSpot_Coef_Y';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_Y*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Lookup_Curve_HotSpot_Coef_Y( )'; 
blockoffset = 179;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u16_7_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_Y******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Temp_Threshold_Hysteresis_Derating*****
Sl_CS_Operation = 'Get_BsConst_Temp_Threshold_Hysteresis_Derating';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Temp_Threshold_Hysteresis_Derating*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Temp_Threshold_Hysteresis_Derating( )'; 
blockoffset = 180;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Temp_Threshold_Hysteresis_Derating******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Derating_Backlight_Disable*****
Sl_CS_Operation = 'Get_BsConst_Derating_Backlight_Disable';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Derating_Backlight_Disable*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Derating_Backlight_Disable( )'; 
blockoffset = 181;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Derating_Backlight_Disable******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Temperature_Sensor_Conv*****
Sl_CS_Operation = 'Get_BsConst_Temperature_Sensor_Conv';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Temperature_Sensor_Conv*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Temperature_Sensor_Conv( )'; 
blockoffset = 182;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Temperature_Sensor_Conv******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PCB_Temperature_Sensor_Conv*****
Sl_CS_Operation = 'Get_BsConst_PCB_Temperature_Sensor_Conv';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PCB_Temperature_Sensor_Conv*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PCB_Temperature_Sensor_Conv( )'; 
blockoffset = 183;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PCB_Temperature_Sensor_Conv******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Display_Illum_Max_Level*****
Sl_CS_Operation = 'Get_BsConst_Display_Illum_Max_Level';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Display_Illum_Max_Level*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Display_Illum_Max_Level( )'; 
blockoffset = 184;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Display_Illum_Max_Level******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PWM_boost_bypass_duty*****
Sl_CS_Operation = 'Get_BsConst_PWM_boost_bypass_duty';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PWM_boost_bypass_duty*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PWM_boost_bypass_duty( )'; 
blockoffset = 185;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PWM_boost_bypass_duty******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_BsConst_Illumination_ReservedByte*****
Sl_CS_Operation = 'Get_BsConst_BsConst_Illumination_ReservedByte';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_BsConst_Illumination_ReservedByte*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_BsConst_Illumination_ReservedByte( )'; 
blockoffset = 186;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_28_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_BsConst_Illumination_ReservedByte******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Compensation_Line_Slope_m_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Compensation_Line_Slope_m_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Compensation_Line_Slope_m_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Compensation_Line_Slope_m_SafeCopy1( )'; 
blockoffset = 187;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Compensation_Line_Slope_m_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Compensation_Line_Shift_b_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Compensation_Line_Shift_b_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Compensation_Line_Shift_b_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Compensation_Line_Shift_b_SafeCopy1( )'; 
blockoffset = 188;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Compensation_Line_Shift_b_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1( )'; 
blockoffset = 189;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u16_7_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1( )'; 
blockoffset = 190;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u16_7_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1( )'; 
blockoffset = 191;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Derating_Backlight_Disable_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Derating_Backlight_Disable_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Derating_Backlight_Disable_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Derating_Backlight_Disable_SafeCopy1( )'; 
blockoffset = 192;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Derating_Backlight_Disable_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Temperature_Sensor_Conv_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Temperature_Sensor_Conv_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Temperature_Sensor_Conv_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Temperature_Sensor_Conv_SafeCopy1( )'; 
blockoffset = 193;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Temperature_Sensor_Conv_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1( )'; 
blockoffset = 194;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Display_Illum_Max_Level_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Display_Illum_Max_Level_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Display_Illum_Max_Level_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Display_Illum_Max_Level_SafeCopy1( )'; 
blockoffset = 195;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Display_Illum_Max_Level_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PWM_boost_bypass_duty_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_PWM_boost_bypass_duty_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PWM_boost_bypass_duty_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PWM_boost_bypass_duty_SafeCopy1( )'; 
blockoffset = 196;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PWM_boost_bypass_duty_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1( )'; 
blockoffset = 197;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_28_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Compensation_Line_Slope_m_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Compensation_Line_Slope_m_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Compensation_Line_Slope_m_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Compensation_Line_Slope_m_SafeCopy2( )'; 
blockoffset = 198;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Compensation_Line_Slope_m_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Compensation_Line_Shift_b_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Compensation_Line_Shift_b_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Compensation_Line_Shift_b_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Compensation_Line_Shift_b_SafeCopy2( )'; 
blockoffset = 199;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Compensation_Line_Shift_b_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2( )'; 
blockoffset = 200;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u16_7_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2( )'; 
blockoffset = 201;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u16_7_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2( )'; 
blockoffset = 202;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Derating_Backlight_Disable_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Derating_Backlight_Disable_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Derating_Backlight_Disable_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Derating_Backlight_Disable_SafeCopy2( )'; 
blockoffset = 203;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Derating_Backlight_Disable_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Temperature_Sensor_Conv_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Temperature_Sensor_Conv_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Temperature_Sensor_Conv_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Temperature_Sensor_Conv_SafeCopy2( )'; 
blockoffset = 204;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Temperature_Sensor_Conv_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2( )'; 
blockoffset = 205;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Display_Illum_Max_Level_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Display_Illum_Max_Level_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Display_Illum_Max_Level_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Display_Illum_Max_Level_SafeCopy2( )'; 
blockoffset = 206;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Display_Illum_Max_Level_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PWM_boost_bypass_duty_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_PWM_boost_bypass_duty_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PWM_boost_bypass_duty_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PWM_boost_bypass_duty_SafeCopy2( )'; 
blockoffset = 207;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PWM_boost_bypass_duty_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2( )'; 
blockoffset = 208;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_28_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Audio_Element*****
Sl_CS_Operation = 'Get_BsConst_Audio_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Audio_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Audio_Element( )'; 
blockoffset = 209;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_128_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Audio_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Warning_Element*****
Sl_CS_Operation = 'Get_BsConst_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Warning_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Warning_Element( )'; 
blockoffset = 210;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_RealTimeClock_Element*****
Sl_CS_Operation = 'Get_BsConst_RealTimeClock_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_RealTimeClock_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_RealTimeClock_Element( )'; 
blockoffset = 211;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_48_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_RealTimeClock_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Communication_Element*****
Sl_CS_Operation = 'Get_BsConst_Communication_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Communication_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Communication_Element( )'; 
blockoffset = 212;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Communication_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Power_Element*****
Sl_CS_Operation = 'Get_BsConst_Power_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Power_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Power_Element( )'; 
blockoffset = 213;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Power_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_ServiceReminder_Element*****
Sl_CS_Operation = 'Get_BsConst_ServiceReminder_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_ServiceReminder_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_ServiceReminder_Element( )'; 
blockoffset = 214;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_48_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_ServiceReminder_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_EngOffTimer_Element*****
Sl_CS_Operation = 'Get_BsConst_EngOffTimer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_EngOffTimer_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_EngOffTimer_Element( )'; 
blockoffset = 215;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_EngOffTimer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsCys_Certicificate_Element*****
Sl_CS_Operation = 'Get_BsCys_Certicificate_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsCys_Certicificate_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsCys_Certicificate_Element( )'; 
blockoffset = 216;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsCys_Certicificate_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_RefCys_Certicificate_Element*****
Sl_CS_Operation = 'Get_RefCys_Certicificate_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_RefCys_Certicificate_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_RefCys_Certicificate_Element( )'; 
blockoffset = 217;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_RefCys_Certicificate_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_RefCys_Certicificate1_Element*****
Sl_CS_Operation = 'Get_RefCys_Certicificate1_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_RefCys_Certicificate1_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_RefCys_Certicificate1_Element( )'; 
blockoffset = 218;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_RefCys_Certicificate1_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_Odometer_Element*****
Sl_CS_Operation = 'Get_BsRt_Odometer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_Odometer_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_Odometer_Element( )'; 
blockoffset = 219;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_128_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_Odometer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_SpeedoGauge_Element*****
Sl_CS_Operation = 'Get_BsRt_SpeedoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_SpeedoGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_SpeedoGauge_Element( )'; 
blockoffset = 220;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_8_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_SpeedoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_TachoGauge_Element*****
Sl_CS_Operation = 'Get_BsRt_TachoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_TachoGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_TachoGauge_Element( )'; 
blockoffset = 221;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_16_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_TachoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_FuelGauge_Element*****
Sl_CS_Operation = 'Get_BsRt_FuelGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_FuelGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_FuelGauge_Element( )'; 
blockoffset = 222;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_FuelGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_TempGauge_Element*****
Sl_CS_Operation = 'Get_BsRt_TempGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_TempGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_TempGauge_Element( )'; 
blockoffset = 223;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_TempGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_PowerGauge_Element*****
Sl_CS_Operation = 'Get_BsRt_PowerGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_PowerGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_PowerGauge_Element( )'; 
blockoffset = 224;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_PowerGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_OilGauge_Element*****
Sl_CS_Operation = 'Get_BsRt_OilGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_OilGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_OilGauge_Element( )'; 
blockoffset = 225;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_8_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_OilGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_TripComputer_Element*****
Sl_CS_Operation = 'Get_BsRt_TripComputer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_TripComputer_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_TripComputer_Element( )'; 
blockoffset = 226;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_TripComputer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_Warning_Element*****
Sl_CS_Operation = 'Get_BsRt_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_Warning_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_Warning_Element( )'; 
blockoffset = 227;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_RealTimeClock_Element*****
Sl_CS_Operation = 'Get_BsRt_RealTimeClock_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_RealTimeClock_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_RealTimeClock_Element( )'; 
blockoffset = 228;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_48_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_RealTimeClock_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_Personalization_Element*****
Sl_CS_Operation = 'Get_BsRt_Personalization_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_Personalization_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_Personalization_Element( )'; 
blockoffset = 229;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_128_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_Personalization_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_Illumination_Element*****
Sl_CS_Operation = 'Get_BsRt_Illumination_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_Illumination_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_Illumination_Element( )'; 
blockoffset = 230;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_Illumination_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_CusDlt_Element*****
Sl_CS_Operation = 'Get_BsRt_CusDlt_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_CusDlt_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_CusDlt_Element( )'; 
blockoffset = 231;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_128_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_CusDlt_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Odometer_Element*****
Sl_CS_Operation = 'Get_BsReten_Odometer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Odometer_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Odometer_Element( )'; 
blockoffset = 232;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Odometer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Gauges_Element*****
Sl_CS_Operation = 'Get_BsReten_Gauges_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Gauges_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Gauges_Element( )'; 
blockoffset = 233;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Gauges_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Tripcomputer_Element*****
Sl_CS_Operation = 'Get_BsReten_Tripcomputer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Tripcomputer_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Tripcomputer_Element( )'; 
blockoffset = 234;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Tripcomputer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Illumination_Element*****
Sl_CS_Operation = 'Get_BsReten_Illumination_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Illumination_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Illumination_Element( )'; 
blockoffset = 235;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Illumination_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Audio_Element*****
Sl_CS_Operation = 'Get_BsReten_Audio_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Audio_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Audio_Element( )'; 
blockoffset = 236;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Audio_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Warning_Element*****
Sl_CS_Operation = 'Get_BsReten_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Warning_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Warning_Element( )'; 
blockoffset = 237;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_RealTimeClock_Element*****
Sl_CS_Operation = 'Get_BsReten_RealTimeClock_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_RealTimeClock_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_RealTimeClock_Element( )'; 
blockoffset = 238;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_RealTimeClock_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Communication_Element*****
Sl_CS_Operation = 'Get_BsReten_Communication_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Communication_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Communication_Element( )'; 
blockoffset = 239;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Communication_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Personalization_Element*****
Sl_CS_Operation = 'Get_BsReten_Personalization_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Personalization_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Personalization_Element( )'; 
blockoffset = 240;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Personalization_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_VisDlt_Element*****
Sl_CS_Operation = 'Get_BsReten_VisDlt_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_VisDlt_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_VisDlt_Element( )'; 
blockoffset = 241;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_256_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_VisDlt_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Power_Element*****
Sl_CS_Operation = 'Get_BsReten_Power_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Power_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Power_Element( )'; 
blockoffset = 242;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Power_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Display_Element*****
Sl_CS_Operation = 'Get_BsReten_Display_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Display_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Display_Element( )'; 
blockoffset = 243;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Display_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsDiag_ErrorRecord_Element*****
Sl_CS_Operation = 'Get_BsDiag_ErrorRecord_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsDiag_ErrorRecord_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsDiag_ErrorRecord_Element( )'; 
blockoffset = 244;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_1024_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsDiag_ErrorRecord_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsDiag_Dtc_Element*****
Sl_CS_Operation = 'Get_BsDiag_Dtc_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsDiag_Dtc_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsDiag_Dtc_Element( )'; 
blockoffset = 245;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_2048_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsDiag_Dtc_Element******

%%********** Adding TI TI_Ctrl_Warning_UpdateWarningStatus***** Adding CS Port  rpUpdateDIMWarning**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_Ctrl_Warning_UpdateWarningStatus';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rpUpdateDIMWarning';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI TI_Ctrl_Warning_UpdateWarningStatus***** Finish Adding CS Port  rpUpdateDIMWarning**********

%%***** ADDING CS VARIABLE HOLDING TI UpdateWarningStatus*****
Sl_CS_Operation = 'UpdateWarningStatus';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION UpdateWarningStatus*****
ArgumentIn0 = 'WarningCurId' ;
ArgumentIn1 = 'WarningCurStatus' ;
ArgumentIn2 = 'WarningCurEvent' ;
ArgumentIn3 = 'WarningPayload' ;


Operation_prototype = 'UpdateWarningStatus( WarningCurId,WarningCurStatus,WarningCurEvent,WarningPayload)'; 
blockoffset = 246;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' WarningId_type_instance(1) ,WarningStatus_type_instance(1) ,WarningEvent_type_instance(1) ,uint32(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION UpdateWarningStatus******

%%********** Adding TI if_CS_MemAbsGet***** Adding CS Port  rp_GetNVM_IlluminationData**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'if_CS_MemAbsGet';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_GetNVM_IlluminationData';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI if_CS_MemAbsGet***** Finish Adding CS Port  rp_GetNVM_IlluminationData**********

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SwUpdReflash_Element*****
Sl_CS_Operation = 'Get_BsShare_SwUpdReflash_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SwUpdReflash_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SwUpdReflash_Element( )'; 
blockoffset = 247;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_8_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SwUpdReflash_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SwUpdFotaMode_Element*****
Sl_CS_Operation = 'Get_BsShare_SwUpdFotaMode_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SwUpdFotaMode_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SwUpdFotaMode_Element( )'; 
blockoffset = 248;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_16_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SwUpdFotaMode_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SwUpdFotaFinPrint_Element*****
Sl_CS_Operation = 'Get_BsShare_SwUpdFotaFinPrint_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SwUpdFotaFinPrint_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SwUpdFotaFinPrint_Element( )'; 
blockoffset = 249;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SwUpdFotaFinPrint_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SwUpdFotaStatus_Element*****
Sl_CS_Operation = 'Get_BsShare_SwUpdFotaStatus_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SwUpdFotaStatus_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SwUpdFotaStatus_Element( )'; 
blockoffset = 250;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_48_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SwUpdFotaStatus_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SwUpdFotadecrypt_Element*****
Sl_CS_Operation = 'Get_BsShare_SwUpdFotadecrypt_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SwUpdFotadecrypt_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SwUpdFotadecrypt_Element( )'; 
blockoffset = 251;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SwUpdFotadecrypt_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_EcuPartNumber_Element*****
Sl_CS_Operation = 'Get_BsShare_EcuPartNumber_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_EcuPartNumber_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_EcuPartNumber_Element( )'; 
blockoffset = 252;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_61_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_EcuPartNumber_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_VisteonPartNumber*****
Sl_CS_Operation = 'Get_BsShare_VisteonPartNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_VisteonPartNumber*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_VisteonPartNumber( )'; 
blockoffset = 253;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_17_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_VisteonPartNumber******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_VisteonPCBPartNumber*****
Sl_CS_Operation = 'Get_BsShare_VisteonPCBPartNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_VisteonPCBPartNumber*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_VisteonPCBPartNumber( )'; 
blockoffset = 254;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_17_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_VisteonPCBPartNumber******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_ProductSerialNumber*****
Sl_CS_Operation = 'Get_BsShare_ProductSerialNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_ProductSerialNumber*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_ProductSerialNumber( )'; 
blockoffset = 255;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_10_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_ProductSerialNumber******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_PCBSerialNumber*****
Sl_CS_Operation = 'Get_BsShare_PCBSerialNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_PCBSerialNumber*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_PCBSerialNumber( )'; 
blockoffset = 256;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_9_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_PCBSerialNumber******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SMTManufacturingDate*****
Sl_CS_Operation = 'Get_BsShare_SMTManufacturingDate';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SMTManufacturingDate*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SMTManufacturingDate( )'; 
blockoffset = 257;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_3_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SMTManufacturingDate******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_AssemblyManufacturingDate*****
Sl_CS_Operation = 'Get_BsShare_AssemblyManufacturingDate';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_AssemblyManufacturingDate*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_AssemblyManufacturingDate( )'; 
blockoffset = 258;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_3_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_AssemblyManufacturingDate******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_SMTPlantNumber*****
Sl_CS_Operation = 'Get_BsShare_SMTPlantNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_SMTPlantNumber*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_SMTPlantNumber( )'; 
blockoffset = 259;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_3_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_SMTPlantNumber******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_AssemblyPlantNumber*****
Sl_CS_Operation = 'Get_BsShare_AssemblyPlantNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_AssemblyPlantNumber*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_AssemblyPlantNumber( )'; 
blockoffset = 260;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_3_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_AssemblyPlantNumber******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_HWModification*****
Sl_CS_Operation = 'Get_BsShare_HWModification';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_HWModification*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_HWModification( )'; 
blockoffset = 261;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_HWModification******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_VisMeet_Element*****
Sl_CS_Operation = 'Get_BsShare_VisMeet_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_VisMeet_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_VisMeet_Element( )'; 
blockoffset = 262;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_46_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_VisMeet_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_VisMeet_EOLEntry_Element*****
Sl_CS_Operation = 'Get_BsShare_VisMeet_EOLEntry_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_VisMeet_EOLEntry_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_VisMeet_EOLEntry_Element( )'; 
blockoffset = 263;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_VisMeet_EOLEntry_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsShare_VehicleConfig_Element*****
Sl_CS_Operation = 'Get_BsShare_VehicleConfig_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsShare_VehicleConfig_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsShare_VehicleConfig_Element( )'; 
blockoffset = 264;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_256_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsShare_VehicleConfig_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_SpeedoGauge_Element*****
Sl_CS_Operation = 'Get_BsConst_SpeedoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_SpeedoGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_SpeedoGauge_Element( )'; 
blockoffset = 265;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_SpeedoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_TachoGauge_Element*****
Sl_CS_Operation = 'Get_BsConst_TachoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_TachoGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_TachoGauge_Element( )'; 
blockoffset = 266;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_TachoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_FuelGauge_Element*****
Sl_CS_Operation = 'Get_BsConst_FuelGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_FuelGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_FuelGauge_Element( )'; 
blockoffset = 267;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_128_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_FuelGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_TempGauge_Element*****
Sl_CS_Operation = 'Get_BsConst_TempGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_TempGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_TempGauge_Element( )'; 
blockoffset = 268;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_TempGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PowerGauge_Element*****
Sl_CS_Operation = 'Get_BsConst_PowerGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PowerGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PowerGauge_Element( )'; 
blockoffset = 269;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PowerGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_OilGauge_Element*****
Sl_CS_Operation = 'Get_BsConst_OilGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_OilGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_OilGauge_Element( )'; 
blockoffset = 270;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_OilGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_TripComputer_Element*****
Sl_CS_Operation = 'Get_BsConst_TripComputer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_TripComputer_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_TripComputer_Element( )'; 
blockoffset = 271;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_TripComputer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Compensation_Line_Slope_m*****
Sl_CS_Operation = 'Get_BsConst_Compensation_Line_Slope_m';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Compensation_Line_Slope_m*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Compensation_Line_Slope_m( )'; 
blockoffset = 272;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Compensation_Line_Slope_m******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Compensation_Line_Shift_b*****
Sl_CS_Operation = 'Get_BsConst_Compensation_Line_Shift_b';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Compensation_Line_Shift_b*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Compensation_Line_Shift_b( )'; 
blockoffset = 273;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Compensation_Line_Shift_b******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Lookup_Curve_HotSpot_Coef_X*****
Sl_CS_Operation = 'Get_BsConst_Lookup_Curve_HotSpot_Coef_X';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_X*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Lookup_Curve_HotSpot_Coef_X( )'; 
blockoffset = 274;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u16_7_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_X******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Lookup_Curve_HotSpot_Coef_Y*****
Sl_CS_Operation = 'Get_BsConst_Lookup_Curve_HotSpot_Coef_Y';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_Y*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Lookup_Curve_HotSpot_Coef_Y( )'; 
blockoffset = 275;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u16_7_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_Y******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Temp_Threshold_Hysteresis_Derating*****
Sl_CS_Operation = 'Get_BsConst_Temp_Threshold_Hysteresis_Derating';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Temp_Threshold_Hysteresis_Derating*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Temp_Threshold_Hysteresis_Derating( )'; 
blockoffset = 276;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Temp_Threshold_Hysteresis_Derating******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Derating_Backlight_Disable*****
Sl_CS_Operation = 'Get_BsConst_Derating_Backlight_Disable';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Derating_Backlight_Disable*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Derating_Backlight_Disable( )'; 
blockoffset = 277;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Derating_Backlight_Disable******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Temperature_Sensor_Conv*****
Sl_CS_Operation = 'Get_BsConst_Temperature_Sensor_Conv';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Temperature_Sensor_Conv*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Temperature_Sensor_Conv( )'; 
blockoffset = 278;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Temperature_Sensor_Conv******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PCB_Temperature_Sensor_Conv*****
Sl_CS_Operation = 'Get_BsConst_PCB_Temperature_Sensor_Conv';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PCB_Temperature_Sensor_Conv*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PCB_Temperature_Sensor_Conv( )'; 
blockoffset = 279;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PCB_Temperature_Sensor_Conv******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Display_Illum_Max_Level*****
Sl_CS_Operation = 'Get_BsConst_Display_Illum_Max_Level';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Display_Illum_Max_Level*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Display_Illum_Max_Level( )'; 
blockoffset = 280;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Display_Illum_Max_Level******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PWM_boost_bypass_duty*****
Sl_CS_Operation = 'Get_BsConst_PWM_boost_bypass_duty';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PWM_boost_bypass_duty*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PWM_boost_bypass_duty( )'; 
blockoffset = 281;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PWM_boost_bypass_duty******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_BsConst_Illumination_ReservedByte*****
Sl_CS_Operation = 'Get_BsConst_BsConst_Illumination_ReservedByte';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_BsConst_Illumination_ReservedByte*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_BsConst_Illumination_ReservedByte( )'; 
blockoffset = 282;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_28_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_BsConst_Illumination_ReservedByte******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Compensation_Line_Slope_m_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Compensation_Line_Slope_m_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Compensation_Line_Slope_m_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Compensation_Line_Slope_m_SafeCopy1( )'; 
blockoffset = 283;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Compensation_Line_Slope_m_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Compensation_Line_Shift_b_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Compensation_Line_Shift_b_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Compensation_Line_Shift_b_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Compensation_Line_Shift_b_SafeCopy1( )'; 
blockoffset = 284;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Compensation_Line_Shift_b_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1( )'; 
blockoffset = 285;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u16_7_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1( )'; 
blockoffset = 286;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u16_7_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1( )'; 
blockoffset = 287;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Derating_Backlight_Disable_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Derating_Backlight_Disable_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Derating_Backlight_Disable_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Derating_Backlight_Disable_SafeCopy1( )'; 
blockoffset = 288;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Derating_Backlight_Disable_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Temperature_Sensor_Conv_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Temperature_Sensor_Conv_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Temperature_Sensor_Conv_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Temperature_Sensor_Conv_SafeCopy1( )'; 
blockoffset = 289;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Temperature_Sensor_Conv_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1( )'; 
blockoffset = 290;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Display_Illum_Max_Level_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_Display_Illum_Max_Level_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Display_Illum_Max_Level_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Display_Illum_Max_Level_SafeCopy1( )'; 
blockoffset = 291;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Display_Illum_Max_Level_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PWM_boost_bypass_duty_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_PWM_boost_bypass_duty_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PWM_boost_bypass_duty_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PWM_boost_bypass_duty_SafeCopy1( )'; 
blockoffset = 292;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PWM_boost_bypass_duty_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1*****
Sl_CS_Operation = 'Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1( )'; 
blockoffset = 293;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_28_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Compensation_Line_Slope_m_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Compensation_Line_Slope_m_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Compensation_Line_Slope_m_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Compensation_Line_Slope_m_SafeCopy2( )'; 
blockoffset = 294;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Compensation_Line_Slope_m_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Compensation_Line_Shift_b_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Compensation_Line_Shift_b_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Compensation_Line_Shift_b_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Compensation_Line_Shift_b_SafeCopy2( )'; 
blockoffset = 295;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint32(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Compensation_Line_Shift_b_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2( )'; 
blockoffset = 296;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u16_7_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2( )'; 
blockoffset = 297;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u16_7_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2( )'; 
blockoffset = 298;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Derating_Backlight_Disable_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Derating_Backlight_Disable_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Derating_Backlight_Disable_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Derating_Backlight_Disable_SafeCopy2( )'; 
blockoffset = 299;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Derating_Backlight_Disable_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Temperature_Sensor_Conv_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Temperature_Sensor_Conv_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Temperature_Sensor_Conv_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Temperature_Sensor_Conv_SafeCopy2( )'; 
blockoffset = 300;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Temperature_Sensor_Conv_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2( )'; 
blockoffset = 301;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Display_Illum_Max_Level_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_Display_Illum_Max_Level_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Display_Illum_Max_Level_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Display_Illum_Max_Level_SafeCopy2( )'; 
blockoffset = 302;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Display_Illum_Max_Level_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_PWM_boost_bypass_duty_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_PWM_boost_bypass_duty_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_PWM_boost_bypass_duty_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_PWM_boost_bypass_duty_SafeCopy2( )'; 
blockoffset = 303;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint8(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_PWM_boost_bypass_duty_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2*****
Sl_CS_Operation = 'Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2( )'; 
blockoffset = 304;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_28_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Audio_Element*****
Sl_CS_Operation = 'Get_BsConst_Audio_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Audio_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Audio_Element( )'; 
blockoffset = 305;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_128_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Audio_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Warning_Element*****
Sl_CS_Operation = 'Get_BsConst_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Warning_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Warning_Element( )'; 
blockoffset = 306;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_RealTimeClock_Element*****
Sl_CS_Operation = 'Get_BsConst_RealTimeClock_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_RealTimeClock_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_RealTimeClock_Element( )'; 
blockoffset = 307;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_48_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_RealTimeClock_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Communication_Element*****
Sl_CS_Operation = 'Get_BsConst_Communication_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Communication_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Communication_Element( )'; 
blockoffset = 308;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Communication_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Power_Element*****
Sl_CS_Operation = 'Get_BsConst_Power_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Power_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Power_Element( )'; 
blockoffset = 309;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_Power_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_ServiceReminder_Element*****
Sl_CS_Operation = 'Get_BsConst_ServiceReminder_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_ServiceReminder_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_ServiceReminder_Element( )'; 
blockoffset = 310;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_48_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_ServiceReminder_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_EngOffTimer_Element*****
Sl_CS_Operation = 'Get_BsConst_EngOffTimer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_EngOffTimer_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_EngOffTimer_Element( )'; 
blockoffset = 311;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsConst_EngOffTimer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsCys_Certicificate_Element*****
Sl_CS_Operation = 'Get_BsCys_Certicificate_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsCys_Certicificate_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsCys_Certicificate_Element( )'; 
blockoffset = 312;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsCys_Certicificate_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_RefCys_Certicificate_Element*****
Sl_CS_Operation = 'Get_RefCys_Certicificate_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_RefCys_Certicificate_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_RefCys_Certicificate_Element( )'; 
blockoffset = 313;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_RefCys_Certicificate_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_RefCys_Certicificate1_Element*****
Sl_CS_Operation = 'Get_RefCys_Certicificate1_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_RefCys_Certicificate1_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_RefCys_Certicificate1_Element( )'; 
blockoffset = 314;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_RefCys_Certicificate1_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_Odometer_Element*****
Sl_CS_Operation = 'Get_BsRt_Odometer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_Odometer_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_Odometer_Element( )'; 
blockoffset = 315;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_128_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_Odometer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_SpeedoGauge_Element*****
Sl_CS_Operation = 'Get_BsRt_SpeedoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_SpeedoGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_SpeedoGauge_Element( )'; 
blockoffset = 316;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_8_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_SpeedoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_TachoGauge_Element*****
Sl_CS_Operation = 'Get_BsRt_TachoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_TachoGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_TachoGauge_Element( )'; 
blockoffset = 317;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_16_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_TachoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_FuelGauge_Element*****
Sl_CS_Operation = 'Get_BsRt_FuelGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_FuelGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_FuelGauge_Element( )'; 
blockoffset = 318;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_FuelGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_TempGauge_Element*****
Sl_CS_Operation = 'Get_BsRt_TempGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_TempGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_TempGauge_Element( )'; 
blockoffset = 319;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_TempGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_PowerGauge_Element*****
Sl_CS_Operation = 'Get_BsRt_PowerGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_PowerGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_PowerGauge_Element( )'; 
blockoffset = 320;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_PowerGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_OilGauge_Element*****
Sl_CS_Operation = 'Get_BsRt_OilGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_OilGauge_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_OilGauge_Element( )'; 
blockoffset = 321;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_8_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_OilGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_TripComputer_Element*****
Sl_CS_Operation = 'Get_BsRt_TripComputer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_TripComputer_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_TripComputer_Element( )'; 
blockoffset = 322;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_64_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_TripComputer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_Warning_Element*****
Sl_CS_Operation = 'Get_BsRt_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_Warning_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_Warning_Element( )'; 
blockoffset = 323;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_32_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_RealTimeClock_Element*****
Sl_CS_Operation = 'Get_BsRt_RealTimeClock_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_RealTimeClock_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_RealTimeClock_Element( )'; 
blockoffset = 324;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_48_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_RealTimeClock_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_Personalization_Element*****
Sl_CS_Operation = 'Get_BsRt_Personalization_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_Personalization_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_Personalization_Element( )'; 
blockoffset = 325;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_128_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_Personalization_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_Illumination_Element*****
Sl_CS_Operation = 'Get_BsRt_Illumination_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_Illumination_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_Illumination_Element( )'; 
blockoffset = 326;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_Illumination_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsRt_CusDlt_Element*****
Sl_CS_Operation = 'Get_BsRt_CusDlt_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsRt_CusDlt_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsRt_CusDlt_Element( )'; 
blockoffset = 327;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_128_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsRt_CusDlt_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Odometer_Element*****
Sl_CS_Operation = 'Get_BsReten_Odometer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Odometer_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Odometer_Element( )'; 
blockoffset = 328;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Odometer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Gauges_Element*****
Sl_CS_Operation = 'Get_BsReten_Gauges_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Gauges_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Gauges_Element( )'; 
blockoffset = 329;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Gauges_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Tripcomputer_Element*****
Sl_CS_Operation = 'Get_BsReten_Tripcomputer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Tripcomputer_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Tripcomputer_Element( )'; 
blockoffset = 330;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Tripcomputer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Illumination_Element*****
Sl_CS_Operation = 'Get_BsReten_Illumination_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Illumination_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Illumination_Element( )'; 
blockoffset = 331;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Illumination_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Audio_Element*****
Sl_CS_Operation = 'Get_BsReten_Audio_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Audio_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Audio_Element( )'; 
blockoffset = 332;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Audio_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Warning_Element*****
Sl_CS_Operation = 'Get_BsReten_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Warning_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Warning_Element( )'; 
blockoffset = 333;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_RealTimeClock_Element*****
Sl_CS_Operation = 'Get_BsReten_RealTimeClock_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_RealTimeClock_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_RealTimeClock_Element( )'; 
blockoffset = 334;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_RealTimeClock_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Communication_Element*****
Sl_CS_Operation = 'Get_BsReten_Communication_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Communication_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Communication_Element( )'; 
blockoffset = 335;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Communication_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Personalization_Element*****
Sl_CS_Operation = 'Get_BsReten_Personalization_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Personalization_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Personalization_Element( )'; 
blockoffset = 336;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Personalization_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_VisDlt_Element*****
Sl_CS_Operation = 'Get_BsReten_VisDlt_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_VisDlt_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_VisDlt_Element( )'; 
blockoffset = 337;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_256_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_VisDlt_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Power_Element*****
Sl_CS_Operation = 'Get_BsReten_Power_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Power_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Power_Element( )'; 
blockoffset = 338;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Power_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsReten_Display_Element*****
Sl_CS_Operation = 'Get_BsReten_Display_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsReten_Display_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsReten_Display_Element( )'; 
blockoffset = 339;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_100_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsReten_Display_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsDiag_ErrorRecord_Element*****
Sl_CS_Operation = 'Get_BsDiag_ErrorRecord_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsDiag_ErrorRecord_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsDiag_ErrorRecord_Element( )'; 
blockoffset = 340;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_1024_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsDiag_ErrorRecord_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsDiag_Dtc_Element*****
Sl_CS_Operation = 'Get_BsDiag_Dtc_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsDiag_Dtc_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsDiag_Dtc_Element( )'; 
blockoffset = 341;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'OutputArgumentSpecifications', ' Arr_u8_2048_type_instance(1) ,uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Get_BsDiag_Dtc_Element******

%%********** Adding TI TI_IOHWAB_GetAdc***** Adding CS Port  rp_IoHwAb_ADC**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_IOHWAB_GetAdc';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_IoHwAb_ADC';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI TI_IOHWAB_GetAdc***** Finish Adding CS Port  rp_IoHwAb_ADC**********

%%***** ADDING CS VARIABLE HOLDING TI GetAsyncRawAdc*****
Sl_CS_Operation = 'GetAsyncRawAdc';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION GetAsyncRawAdc*****
ArgumentIn0 = 'AdcId' ;

ArgumentOut0 = 'AsyncRawAdc' ;
ArgumentOut1 = 'ErrorStatus' ;
ArgumentOut2 = 'error_status' ;

Operation_prototype = '[AsyncRawAdc,ErrorStatus,error_status ] = GetAsyncRawAdc( AdcId)'; 
blockoffset = 342;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' IoHwAb_AdcSignalIdType_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1) ,IoHwAb_ErrorType_type_instance(1) ,uint8(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetAsyncRawAdc******

%%***** ADDING CS VARIABLE HOLDING TI GetSyncRawAdc*****
Sl_CS_Operation = 'GetSyncRawAdc';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION GetSyncRawAdc*****
ArgumentIn0 = 'AdcId' ;

ArgumentOut0 = 'SyncRawAdc' ;
ArgumentOut1 = 'ErrorStatus' ;
ArgumentOut2 = 'error_status' ;

Operation_prototype = '[SyncRawAdc,ErrorStatus,error_status ] = GetSyncRawAdc( AdcId)'; 
blockoffset = 343;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' IoHwAb_AdcSignalIdType_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' uint16(1) ,IoHwAb_ErrorType_type_instance(1) ,uint8(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetSyncRawAdc******

%%***** ADDING CS VARIABLE HOLDING TI GetProcessedAdc*****
Sl_CS_Operation = 'GetProcessedAdc';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION GetProcessedAdc*****
ArgumentIn0 = 'AdcId' ;

ArgumentOut0 = 'ProcessedAdc' ;
ArgumentOut1 = 'ErrorStatus' ;
ArgumentOut2 = 'error_status' ;

Operation_prototype = '[ProcessedAdc,ErrorStatus,error_status ] = GetProcessedAdc( AdcId)'; 
blockoffset = 344;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' IoHwAb_AdcSignalIdType_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' int32(1) ,IoHwAb_ErrorType_type_instance(1) ,uint8(1)');
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


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION GetProcessedAdc******

%%********** Adding TI if_CS_MemAbsSet***** Adding CS Port  rp_SetNVM_IlluminationData**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'if_CS_MemAbsSet';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_SetNVM_IlluminationData';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI if_CS_MemAbsSet***** Finish Adding CS Port  rp_SetNVM_IlluminationData**********

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SwUpdReflash_Element*****
Sl_CS_Operation = 'Set_BsShare_SwUpdReflash_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SwUpdReflash_Element*****
ArgumentIn0 = 'BsShare_SwUpdReflash_Element' ;


Operation_prototype = 'Set_BsShare_SwUpdReflash_Element( BsShare_SwUpdReflash_Element)'; 
blockoffset = 345;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_8_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SwUpdReflash_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SwUpdFotaMode_Element*****
Sl_CS_Operation = 'Set_BsShare_SwUpdFotaMode_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SwUpdFotaMode_Element*****
ArgumentIn0 = 'BsShare_SwUpdFotaMode_Element' ;


Operation_prototype = 'Set_BsShare_SwUpdFotaMode_Element( BsShare_SwUpdFotaMode_Element)'; 
blockoffset = 346;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_16_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SwUpdFotaMode_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SwUpdFotaFinPrint_Element*****
Sl_CS_Operation = 'Set_BsShare_SwUpdFotaFinPrint_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SwUpdFotaFinPrint_Element*****
ArgumentIn0 = 'BsShare_SwUpdFotaFinPrint_Element' ;


Operation_prototype = 'Set_BsShare_SwUpdFotaFinPrint_Element( BsShare_SwUpdFotaFinPrint_Element)'; 
blockoffset = 347;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SwUpdFotaFinPrint_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SwUpdFotaStatus_Element*****
Sl_CS_Operation = 'Set_BsShare_SwUpdFotaStatus_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SwUpdFotaStatus_Element*****
ArgumentIn0 = 'BsShare_SwUpdFotaStatus_Element' ;


Operation_prototype = 'Set_BsShare_SwUpdFotaStatus_Element( BsShare_SwUpdFotaStatus_Element)'; 
blockoffset = 348;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_48_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SwUpdFotaStatus_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SwUpdFotadecrypt_Element*****
Sl_CS_Operation = 'Set_BsShare_SwUpdFotadecrypt_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SwUpdFotadecrypt_Element*****
ArgumentIn0 = 'BsShare_SwUpdFotadecrypt_Element' ;


Operation_prototype = 'Set_BsShare_SwUpdFotadecrypt_Element( BsShare_SwUpdFotadecrypt_Element)'; 
blockoffset = 349;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SwUpdFotadecrypt_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_EcuPartNumber_Element*****
Sl_CS_Operation = 'Set_BsShare_EcuPartNumber_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_EcuPartNumber_Element*****
ArgumentIn0 = 'BsShare_EcuPartNumber_Element' ;


Operation_prototype = 'Set_BsShare_EcuPartNumber_Element( BsShare_EcuPartNumber_Element)'; 
blockoffset = 350;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_61_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_EcuPartNumber_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_VisteonPartNumber*****
Sl_CS_Operation = 'Set_BsShare_VisteonPartNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_VisteonPartNumber*****
ArgumentIn0 = 'BsShare_VisteonPartNumber' ;


Operation_prototype = 'Set_BsShare_VisteonPartNumber( BsShare_VisteonPartNumber)'; 
blockoffset = 351;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_17_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_VisteonPartNumber******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_VisteonPCBPartNumber*****
Sl_CS_Operation = 'Set_BsShare_VisteonPCBPartNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_VisteonPCBPartNumber*****
ArgumentIn0 = 'BsShare_VisteonPCBPartNumber' ;


Operation_prototype = 'Set_BsShare_VisteonPCBPartNumber( BsShare_VisteonPCBPartNumber)'; 
blockoffset = 352;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_17_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_VisteonPCBPartNumber******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_ProductSerialNumber*****
Sl_CS_Operation = 'Set_BsShare_ProductSerialNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_ProductSerialNumber*****
ArgumentIn0 = 'BsShare_ProductSerialNumber' ;


Operation_prototype = 'Set_BsShare_ProductSerialNumber( BsShare_ProductSerialNumber)'; 
blockoffset = 353;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_10_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_ProductSerialNumber******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_PCBSerialNumber*****
Sl_CS_Operation = 'Set_BsShare_PCBSerialNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_PCBSerialNumber*****
ArgumentIn0 = 'BsShare_PCBSerialNumber' ;


Operation_prototype = 'Set_BsShare_PCBSerialNumber( BsShare_PCBSerialNumber)'; 
blockoffset = 354;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_9_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_PCBSerialNumber******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SMTManufacturingDate*****
Sl_CS_Operation = 'Set_BsShare_SMTManufacturingDate';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SMTManufacturingDate*****
ArgumentIn0 = 'BsShare_SMTManufacturingDate' ;


Operation_prototype = 'Set_BsShare_SMTManufacturingDate( BsShare_SMTManufacturingDate)'; 
blockoffset = 355;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_3_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SMTManufacturingDate******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_AssemblyManufacturingDate*****
Sl_CS_Operation = 'Set_BsShare_AssemblyManufacturingDate';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_AssemblyManufacturingDate*****
ArgumentIn0 = 'BsShare_AssemblyManufacturingDate' ;


Operation_prototype = 'Set_BsShare_AssemblyManufacturingDate( BsShare_AssemblyManufacturingDate)'; 
blockoffset = 356;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_3_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_AssemblyManufacturingDate******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_SMTPlantNumber*****
Sl_CS_Operation = 'Set_BsShare_SMTPlantNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_SMTPlantNumber*****
ArgumentIn0 = 'BsShare_SMTPlantNumber' ;


Operation_prototype = 'Set_BsShare_SMTPlantNumber( BsShare_SMTPlantNumber)'; 
blockoffset = 357;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_3_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_SMTPlantNumber******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_AssemblyPlantNumber*****
Sl_CS_Operation = 'Set_BsShare_AssemblyPlantNumber';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_AssemblyPlantNumber*****
ArgumentIn0 = 'BsShare_AssemblyPlantNumber' ;


Operation_prototype = 'Set_BsShare_AssemblyPlantNumber( BsShare_AssemblyPlantNumber)'; 
blockoffset = 358;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_3_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_AssemblyPlantNumber******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_HWModification*****
Sl_CS_Operation = 'Set_BsShare_HWModification';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_HWModification*****
ArgumentIn0 = 'BsShare_HWModification' ;


Operation_prototype = 'Set_BsShare_HWModification( BsShare_HWModification)'; 
blockoffset = 359;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint16(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_HWModification******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_VisMeet_Element*****
Sl_CS_Operation = 'Set_BsShare_VisMeet_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_VisMeet_Element*****
ArgumentIn0 = 'BsShare_VisMeet_Element' ;


Operation_prototype = 'Set_BsShare_VisMeet_Element( BsShare_VisMeet_Element)'; 
blockoffset = 360;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_46_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_VisMeet_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_VisMeet_EOLEntry_Element*****
Sl_CS_Operation = 'Set_BsShare_VisMeet_EOLEntry_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_VisMeet_EOLEntry_Element*****
ArgumentIn0 = 'BsShare_VisMeet_EOLEntry_Element' ;


Operation_prototype = 'Set_BsShare_VisMeet_EOLEntry_Element( BsShare_VisMeet_EOLEntry_Element)'; 
blockoffset = 361;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint16(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_VisMeet_EOLEntry_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsShare_VehicleConfig_Element*****
Sl_CS_Operation = 'Set_BsShare_VehicleConfig_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsShare_VehicleConfig_Element*****
ArgumentIn0 = 'BsShare_VehicleConfig_Element' ;


Operation_prototype = 'Set_BsShare_VehicleConfig_Element( BsShare_VehicleConfig_Element)'; 
blockoffset = 362;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_256_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsShare_VehicleConfig_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_SpeedoGauge_Element*****
Sl_CS_Operation = 'Set_BsConst_SpeedoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_SpeedoGauge_Element*****
ArgumentIn0 = 'BsConst_SpeedoGauge_Element' ;


Operation_prototype = 'Set_BsConst_SpeedoGauge_Element( BsConst_SpeedoGauge_Element)'; 
blockoffset = 363;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_SpeedoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_TachoGauge_Element*****
Sl_CS_Operation = 'Set_BsConst_TachoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_TachoGauge_Element*****
ArgumentIn0 = 'BsConst_TachoGauge_Element' ;


Operation_prototype = 'Set_BsConst_TachoGauge_Element( BsConst_TachoGauge_Element)'; 
blockoffset = 364;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_TachoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_FuelGauge_Element*****
Sl_CS_Operation = 'Set_BsConst_FuelGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_FuelGauge_Element*****
ArgumentIn0 = 'BsConst_FuelGauge_Element' ;


Operation_prototype = 'Set_BsConst_FuelGauge_Element( BsConst_FuelGauge_Element)'; 
blockoffset = 365;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_128_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_FuelGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_TempGauge_Element*****
Sl_CS_Operation = 'Set_BsConst_TempGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_TempGauge_Element*****
ArgumentIn0 = 'BsConst_TempGauge_Element' ;


Operation_prototype = 'Set_BsConst_TempGauge_Element( BsConst_TempGauge_Element)'; 
blockoffset = 366;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_TempGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PowerGauge_Element*****
Sl_CS_Operation = 'Set_BsConst_PowerGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PowerGauge_Element*****
ArgumentIn0 = 'BsConst_PowerGauge_Element' ;


Operation_prototype = 'Set_BsConst_PowerGauge_Element( BsConst_PowerGauge_Element)'; 
blockoffset = 367;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PowerGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_OilGauge_Element*****
Sl_CS_Operation = 'Set_BsConst_OilGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_OilGauge_Element*****
ArgumentIn0 = 'BsConst_OilGauge_Element' ;


Operation_prototype = 'Set_BsConst_OilGauge_Element( BsConst_OilGauge_Element)'; 
blockoffset = 368;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_OilGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_TripComputer_Element*****
Sl_CS_Operation = 'Set_BsConst_TripComputer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_TripComputer_Element*****
ArgumentIn0 = 'BsConst_TripComputer_Element' ;


Operation_prototype = 'Set_BsConst_TripComputer_Element( BsConst_TripComputer_Element)'; 
blockoffset = 369;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_TripComputer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Compensation_Line_Slope_m*****
Sl_CS_Operation = 'Set_BsConst_Compensation_Line_Slope_m';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Compensation_Line_Slope_m*****
ArgumentIn0 = 'BsConst_Compensation_Line_Slope_m' ;


Operation_prototype = 'Set_BsConst_Compensation_Line_Slope_m( BsConst_Compensation_Line_Slope_m)'; 
blockoffset = 370;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint32(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Compensation_Line_Slope_m******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Compensation_Line_Shift_b*****
Sl_CS_Operation = 'Set_BsConst_Compensation_Line_Shift_b';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Compensation_Line_Shift_b*****
ArgumentIn0 = 'BsConst_Compensation_Line_Shift_b' ;


Operation_prototype = 'Set_BsConst_Compensation_Line_Shift_b( BsConst_Compensation_Line_Shift_b)'; 
blockoffset = 371;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint32(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Compensation_Line_Shift_b******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Lookup_Curve_HotSpot_Coef_X*****
Sl_CS_Operation = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_X';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_X*****
ArgumentIn0 = 'BsConst_Lookup_Curve_HotSpot_Coef_X' ;


Operation_prototype = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_X( BsConst_Lookup_Curve_HotSpot_Coef_X)'; 
blockoffset = 372;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u16_7_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_X******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Lookup_Curve_HotSpot_Coef_Y*****
Sl_CS_Operation = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_Y';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_Y*****
ArgumentIn0 = 'BsConst_Lookup_Curve_HotSpot_Coef_Y' ;


Operation_prototype = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_Y( BsConst_Lookup_Curve_HotSpot_Coef_Y)'; 
blockoffset = 373;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u16_7_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_Y******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Temp_Threshold_Hysteresis_Derating*****
Sl_CS_Operation = 'Set_BsConst_Temp_Threshold_Hysteresis_Derating';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Temp_Threshold_Hysteresis_Derating*****
ArgumentIn0 = 'BsConst_Temp_Threshold_Hysteresis_Derating' ;


Operation_prototype = 'Set_BsConst_Temp_Threshold_Hysteresis_Derating( BsConst_Temp_Threshold_Hysteresis_Derating)'; 
blockoffset = 374;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Temp_Threshold_Hysteresis_Derating******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Derating_Backlight_Disable*****
Sl_CS_Operation = 'Set_BsConst_Derating_Backlight_Disable';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Derating_Backlight_Disable*****
ArgumentIn0 = 'BsConst_Derating_Backlight_Disable' ;


Operation_prototype = 'Set_BsConst_Derating_Backlight_Disable( BsConst_Derating_Backlight_Disable)'; 
blockoffset = 375;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Derating_Backlight_Disable******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Temperature_Sensor_Conv*****
Sl_CS_Operation = 'Set_BsConst_Temperature_Sensor_Conv';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Temperature_Sensor_Conv*****
ArgumentIn0 = 'BsConst_Temperature_Sensor_Conv' ;


Operation_prototype = 'Set_BsConst_Temperature_Sensor_Conv( BsConst_Temperature_Sensor_Conv)'; 
blockoffset = 376;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Temperature_Sensor_Conv******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PCB_Temperature_Sensor_Conv*****
Sl_CS_Operation = 'Set_BsConst_PCB_Temperature_Sensor_Conv';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PCB_Temperature_Sensor_Conv*****
ArgumentIn0 = 'BsConst_PCB_Temperature_Sensor_Conv' ;


Operation_prototype = 'Set_BsConst_PCB_Temperature_Sensor_Conv( BsConst_PCB_Temperature_Sensor_Conv)'; 
blockoffset = 377;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PCB_Temperature_Sensor_Conv******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Display_Illum_Max_Level*****
Sl_CS_Operation = 'Set_BsConst_Display_Illum_Max_Level';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Display_Illum_Max_Level*****
ArgumentIn0 = 'BsConst_Display_Illum_Max_Level' ;


Operation_prototype = 'Set_BsConst_Display_Illum_Max_Level( BsConst_Display_Illum_Max_Level)'; 
blockoffset = 378;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint16(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Display_Illum_Max_Level******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PWM_boost_bypass_duty*****
Sl_CS_Operation = 'Set_BsConst_PWM_boost_bypass_duty';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PWM_boost_bypass_duty*****
ArgumentIn0 = 'BsConst_PWM_boost_bypass_duty' ;


Operation_prototype = 'Set_BsConst_PWM_boost_bypass_duty( BsConst_PWM_boost_bypass_duty)'; 
blockoffset = 379;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PWM_boost_bypass_duty******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_BsConst_Illumination_ReservedByte*****
Sl_CS_Operation = 'Set_BsConst_BsConst_Illumination_ReservedByte';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_BsConst_Illumination_ReservedByte*****
ArgumentIn0 = 'BsConst_BsConst_Illumination_ReservedByte' ;


Operation_prototype = 'Set_BsConst_BsConst_Illumination_ReservedByte( BsConst_BsConst_Illumination_ReservedByte)'; 
blockoffset = 380;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_28_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_BsConst_Illumination_ReservedByte******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Compensation_Line_Slope_m_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Compensation_Line_Slope_m_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Compensation_Line_Slope_m_SafeCopy1*****
ArgumentIn0 = 'BsConst_Compensation_Line_Slope_m_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Compensation_Line_Slope_m_SafeCopy1( BsConst_Compensation_Line_Slope_m_SafeCopy1)'; 
blockoffset = 381;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint32(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Compensation_Line_Slope_m_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Compensation_Line_Shift_b_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Compensation_Line_Shift_b_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Compensation_Line_Shift_b_SafeCopy1*****
ArgumentIn0 = 'BsConst_Compensation_Line_Shift_b_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Compensation_Line_Shift_b_SafeCopy1( BsConst_Compensation_Line_Shift_b_SafeCopy1)'; 
blockoffset = 382;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint32(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Compensation_Line_Shift_b_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1*****
ArgumentIn0 = 'BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1( BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1)'; 
blockoffset = 383;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u16_7_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1*****
ArgumentIn0 = 'BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1( BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1)'; 
blockoffset = 384;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u16_7_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1*****
ArgumentIn0 = 'BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1( BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1)'; 
blockoffset = 385;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Derating_Backlight_Disable_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Derating_Backlight_Disable_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Derating_Backlight_Disable_SafeCopy1*****
ArgumentIn0 = 'BsConst_Derating_Backlight_Disable_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Derating_Backlight_Disable_SafeCopy1( BsConst_Derating_Backlight_Disable_SafeCopy1)'; 
blockoffset = 386;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Derating_Backlight_Disable_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Temperature_Sensor_Conv_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Temperature_Sensor_Conv_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Temperature_Sensor_Conv_SafeCopy1*****
ArgumentIn0 = 'BsConst_Temperature_Sensor_Conv_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Temperature_Sensor_Conv_SafeCopy1( BsConst_Temperature_Sensor_Conv_SafeCopy1)'; 
blockoffset = 387;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Temperature_Sensor_Conv_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1*****
ArgumentIn0 = 'BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1( BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1)'; 
blockoffset = 388;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Display_Illum_Max_Level_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_Display_Illum_Max_Level_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Display_Illum_Max_Level_SafeCopy1*****
ArgumentIn0 = 'BsConst_Display_Illum_Max_Level_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_Display_Illum_Max_Level_SafeCopy1( BsConst_Display_Illum_Max_Level_SafeCopy1)'; 
blockoffset = 389;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint16(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Display_Illum_Max_Level_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PWM_boost_bypass_duty_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_PWM_boost_bypass_duty_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PWM_boost_bypass_duty_SafeCopy1*****
ArgumentIn0 = 'BsConst_PWM_boost_bypass_duty_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_PWM_boost_bypass_duty_SafeCopy1( BsConst_PWM_boost_bypass_duty_SafeCopy1)'; 
blockoffset = 390;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PWM_boost_bypass_duty_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1*****
Sl_CS_Operation = 'Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1*****
ArgumentIn0 = 'BsConst_BsConst_Illumination_ReservedByte_SafeCopy1' ;


Operation_prototype = 'Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1( BsConst_BsConst_Illumination_ReservedByte_SafeCopy1)'; 
blockoffset = 391;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_28_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Compensation_Line_Slope_m_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Compensation_Line_Slope_m_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Compensation_Line_Slope_m_SafeCopy2*****
ArgumentIn0 = 'BsConst_Compensation_Line_Slope_m_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Compensation_Line_Slope_m_SafeCopy2( BsConst_Compensation_Line_Slope_m_SafeCopy2)'; 
blockoffset = 392;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint32(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Compensation_Line_Slope_m_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Compensation_Line_Shift_b_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Compensation_Line_Shift_b_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Compensation_Line_Shift_b_SafeCopy2*****
ArgumentIn0 = 'BsConst_Compensation_Line_Shift_b_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Compensation_Line_Shift_b_SafeCopy2( BsConst_Compensation_Line_Shift_b_SafeCopy2)'; 
blockoffset = 393;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint32(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Compensation_Line_Shift_b_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2*****
ArgumentIn0 = 'BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2( BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2)'; 
blockoffset = 394;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u16_7_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2*****
ArgumentIn0 = 'BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2( BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2)'; 
blockoffset = 395;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u16_7_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2*****
ArgumentIn0 = 'BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2( BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2)'; 
blockoffset = 396;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Derating_Backlight_Disable_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Derating_Backlight_Disable_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Derating_Backlight_Disable_SafeCopy2*****
ArgumentIn0 = 'BsConst_Derating_Backlight_Disable_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Derating_Backlight_Disable_SafeCopy2( BsConst_Derating_Backlight_Disable_SafeCopy2)'; 
blockoffset = 397;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Derating_Backlight_Disable_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Temperature_Sensor_Conv_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Temperature_Sensor_Conv_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Temperature_Sensor_Conv_SafeCopy2*****
ArgumentIn0 = 'BsConst_Temperature_Sensor_Conv_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Temperature_Sensor_Conv_SafeCopy2( BsConst_Temperature_Sensor_Conv_SafeCopy2)'; 
blockoffset = 398;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Temperature_Sensor_Conv_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2*****
ArgumentIn0 = 'BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2( BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2)'; 
blockoffset = 399;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' T_NV_Temperature_Conversion_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Display_Illum_Max_Level_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_Display_Illum_Max_Level_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Display_Illum_Max_Level_SafeCopy2*****
ArgumentIn0 = 'BsConst_Display_Illum_Max_Level_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_Display_Illum_Max_Level_SafeCopy2( BsConst_Display_Illum_Max_Level_SafeCopy2)'; 
blockoffset = 400;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint16(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Display_Illum_Max_Level_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_PWM_boost_bypass_duty_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_PWM_boost_bypass_duty_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_PWM_boost_bypass_duty_SafeCopy2*****
ArgumentIn0 = 'BsConst_PWM_boost_bypass_duty_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_PWM_boost_bypass_duty_SafeCopy2( BsConst_PWM_boost_bypass_duty_SafeCopy2)'; 
blockoffset = 401;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' uint8(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_PWM_boost_bypass_duty_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2*****
Sl_CS_Operation = 'Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2*****
ArgumentIn0 = 'BsConst_BsConst_Illumination_ReservedByte_SafeCopy2' ;


Operation_prototype = 'Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2( BsConst_BsConst_Illumination_ReservedByte_SafeCopy2)'; 
blockoffset = 402;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_28_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Audio_Element*****
Sl_CS_Operation = 'Set_BsConst_Audio_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Audio_Element*****
ArgumentIn0 = 'BsConst_Audio_Element' ;


Operation_prototype = 'Set_BsConst_Audio_Element( BsConst_Audio_Element)'; 
blockoffset = 403;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_128_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Audio_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Warning_Element*****
Sl_CS_Operation = 'Set_BsConst_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Warning_Element*****
ArgumentIn0 = 'BsConst_Warning_Element' ;


Operation_prototype = 'Set_BsConst_Warning_Element( BsConst_Warning_Element)'; 
blockoffset = 404;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_RealTimeClock_Element*****
Sl_CS_Operation = 'Set_BsConst_RealTimeClock_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_RealTimeClock_Element*****
ArgumentIn0 = 'BsConst_RealTimeClock_Element' ;


Operation_prototype = 'Set_BsConst_RealTimeClock_Element( BsConst_RealTimeClock_Element)'; 
blockoffset = 405;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_48_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_RealTimeClock_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Communication_Element*****
Sl_CS_Operation = 'Set_BsConst_Communication_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Communication_Element*****
ArgumentIn0 = 'BsConst_Communication_Element' ;


Operation_prototype = 'Set_BsConst_Communication_Element( BsConst_Communication_Element)'; 
blockoffset = 406;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Communication_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_Power_Element*****
Sl_CS_Operation = 'Set_BsConst_Power_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_Power_Element*****
ArgumentIn0 = 'BsConst_Power_Element' ;


Operation_prototype = 'Set_BsConst_Power_Element( BsConst_Power_Element)'; 
blockoffset = 407;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_Power_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_ServiceReminder_Element*****
Sl_CS_Operation = 'Set_BsConst_ServiceReminder_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_ServiceReminder_Element*****
ArgumentIn0 = 'BsConst_ServiceReminder_Element' ;


Operation_prototype = 'Set_BsConst_ServiceReminder_Element( BsConst_ServiceReminder_Element)'; 
blockoffset = 408;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_48_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_ServiceReminder_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsConst_EngOffTimer_Element*****
Sl_CS_Operation = 'Set_BsConst_EngOffTimer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsConst_EngOffTimer_Element*****
ArgumentIn0 = 'BsConst_EngOffTimer_Element' ;


Operation_prototype = 'Set_BsConst_EngOffTimer_Element( BsConst_EngOffTimer_Element)'; 
blockoffset = 409;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsConst_EngOffTimer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsCys_Certicificate_Element*****
Sl_CS_Operation = 'Set_BsCys_Certicificate_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsCys_Certicificate_Element*****
ArgumentIn0 = 'BsCys_Certicificate_Element' ;


Operation_prototype = 'Set_BsCys_Certicificate_Element( BsCys_Certicificate_Element)'; 
blockoffset = 410;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsCys_Certicificate_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_RefCys_Certicificate_Element*****
Sl_CS_Operation = 'Set_RefCys_Certicificate_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_RefCys_Certicificate_Element*****
ArgumentIn0 = 'RefCys_Certicificate_Element' ;


Operation_prototype = 'Set_RefCys_Certicificate_Element( RefCys_Certicificate_Element)'; 
blockoffset = 411;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_RefCys_Certicificate_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_RefCys_Certicificate1_Element*****
Sl_CS_Operation = 'Set_RefCys_Certicificate1_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_RefCys_Certicificate1_Element*****
ArgumentIn0 = 'RefCys_Certicificate1_Element' ;


Operation_prototype = 'Set_RefCys_Certicificate1_Element( RefCys_Certicificate1_Element)'; 
blockoffset = 412;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_RefCys_Certicificate1_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_Odometer_Element*****
Sl_CS_Operation = 'Set_BsRt_Odometer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_Odometer_Element*****
ArgumentIn0 = 'BsRt_Odometer_Element' ;


Operation_prototype = 'Set_BsRt_Odometer_Element( BsRt_Odometer_Element)'; 
blockoffset = 413;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_128_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_Odometer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_SpeedoGauge_Element*****
Sl_CS_Operation = 'Set_BsRt_SpeedoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_SpeedoGauge_Element*****
ArgumentIn0 = 'BsRt_SpeedoGauge_Element' ;


Operation_prototype = 'Set_BsRt_SpeedoGauge_Element( BsRt_SpeedoGauge_Element)'; 
blockoffset = 414;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_8_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_SpeedoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_TachoGauge_Element*****
Sl_CS_Operation = 'Set_BsRt_TachoGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_TachoGauge_Element*****
ArgumentIn0 = 'BsRt_TachoGauge_Element' ;


Operation_prototype = 'Set_BsRt_TachoGauge_Element( BsRt_TachoGauge_Element)'; 
blockoffset = 415;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_16_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_TachoGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_FuelGauge_Element*****
Sl_CS_Operation = 'Set_BsRt_FuelGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_FuelGauge_Element*****
ArgumentIn0 = 'BsRt_FuelGauge_Element' ;


Operation_prototype = 'Set_BsRt_FuelGauge_Element( BsRt_FuelGauge_Element)'; 
blockoffset = 416;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_FuelGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_TempGauge_Element*****
Sl_CS_Operation = 'Set_BsRt_TempGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_TempGauge_Element*****
ArgumentIn0 = 'BsRt_TempGauge_Element' ;


Operation_prototype = 'Set_BsRt_TempGauge_Element( BsRt_TempGauge_Element)'; 
blockoffset = 417;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_TempGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_PowerGauge_Element*****
Sl_CS_Operation = 'Set_BsRt_PowerGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_PowerGauge_Element*****
ArgumentIn0 = 'BsRt_PowerGauge_Element' ;


Operation_prototype = 'Set_BsRt_PowerGauge_Element( BsRt_PowerGauge_Element)'; 
blockoffset = 418;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_PowerGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_OilGauge_Element*****
Sl_CS_Operation = 'Set_BsRt_OilGauge_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_OilGauge_Element*****
ArgumentIn0 = 'BsRt_OilGauge_Element' ;


Operation_prototype = 'Set_BsRt_OilGauge_Element( BsRt_OilGauge_Element)'; 
blockoffset = 419;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_8_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_OilGauge_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_TripComputer_Element*****
Sl_CS_Operation = 'Set_BsRt_TripComputer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_TripComputer_Element*****
ArgumentIn0 = 'BsRt_TripComputer_Element' ;


Operation_prototype = 'Set_BsRt_TripComputer_Element( BsRt_TripComputer_Element)'; 
blockoffset = 420;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_64_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_TripComputer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_Warning_Element*****
Sl_CS_Operation = 'Set_BsRt_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_Warning_Element*****
ArgumentIn0 = 'BsRt_Warning_Element' ;


Operation_prototype = 'Set_BsRt_Warning_Element( BsRt_Warning_Element)'; 
blockoffset = 421;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_32_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_RealTimeClock_Element*****
Sl_CS_Operation = 'Set_BsRt_RealTimeClock_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_RealTimeClock_Element*****
ArgumentIn0 = 'BsRt_RealTimeClock_Element' ;


Operation_prototype = 'Set_BsRt_RealTimeClock_Element( BsRt_RealTimeClock_Element)'; 
blockoffset = 422;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_48_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_RealTimeClock_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_Personalization_Element*****
Sl_CS_Operation = 'Set_BsRt_Personalization_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_Personalization_Element*****
ArgumentIn0 = 'BsRt_Personalization_Element' ;


Operation_prototype = 'Set_BsRt_Personalization_Element( BsRt_Personalization_Element)'; 
blockoffset = 423;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_128_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_Personalization_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_Illumination_Element*****
Sl_CS_Operation = 'Set_BsRt_Illumination_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_Illumination_Element*****
ArgumentIn0 = 'BsRt_Illumination_Element' ;


Operation_prototype = 'Set_BsRt_Illumination_Element( BsRt_Illumination_Element)'; 
blockoffset = 424;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_Illumination_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsRt_CusDlt_Element*****
Sl_CS_Operation = 'Set_BsRt_CusDlt_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsRt_CusDlt_Element*****
ArgumentIn0 = 'BsRt_CusDlt_Element' ;


Operation_prototype = 'Set_BsRt_CusDlt_Element( BsRt_CusDlt_Element)'; 
blockoffset = 425;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_128_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsRt_CusDlt_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Odometer_Element*****
Sl_CS_Operation = 'Set_BsReten_Odometer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Odometer_Element*****
ArgumentIn0 = 'BsReten_Odometer_Element' ;


Operation_prototype = 'Set_BsReten_Odometer_Element( BsReten_Odometer_Element)'; 
blockoffset = 426;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Odometer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Gauges_Element*****
Sl_CS_Operation = 'Set_BsReten_Gauges_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Gauges_Element*****
ArgumentIn0 = 'BsReten_Gauges_Element' ;


Operation_prototype = 'Set_BsReten_Gauges_Element( BsReten_Gauges_Element)'; 
blockoffset = 427;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Gauges_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Tripcomputer_Element*****
Sl_CS_Operation = 'Set_BsReten_Tripcomputer_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Tripcomputer_Element*****
ArgumentIn0 = 'BsReten_Tripcomputer_Element' ;


Operation_prototype = 'Set_BsReten_Tripcomputer_Element( BsReten_Tripcomputer_Element)'; 
blockoffset = 428;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Tripcomputer_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Illumination_Element*****
Sl_CS_Operation = 'Set_BsReten_Illumination_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Illumination_Element*****
ArgumentIn0 = 'BsReten_Illumination_Element' ;


Operation_prototype = 'Set_BsReten_Illumination_Element( BsReten_Illumination_Element)'; 
blockoffset = 429;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Illumination_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Audio_Element*****
Sl_CS_Operation = 'Set_BsReten_Audio_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Audio_Element*****
ArgumentIn0 = 'BsReten_Audio_Element' ;


Operation_prototype = 'Set_BsReten_Audio_Element( BsReten_Audio_Element)'; 
blockoffset = 430;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Audio_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Warning_Element*****
Sl_CS_Operation = 'Set_BsReten_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Warning_Element*****
ArgumentIn0 = 'BsReten_Warning_Element' ;


Operation_prototype = 'Set_BsReten_Warning_Element( BsReten_Warning_Element)'; 
blockoffset = 431;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_RealTimeClock_Element*****
Sl_CS_Operation = 'Set_BsReten_RealTimeClock_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_RealTimeClock_Element*****
ArgumentIn0 = 'BsReten_RealTimeClock_Element' ;


Operation_prototype = 'Set_BsReten_RealTimeClock_Element( BsReten_RealTimeClock_Element)'; 
blockoffset = 432;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_RealTimeClock_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Communication_Element*****
Sl_CS_Operation = 'Set_BsReten_Communication_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Communication_Element*****
ArgumentIn0 = 'BsReten_Communication_Element' ;


Operation_prototype = 'Set_BsReten_Communication_Element( BsReten_Communication_Element)'; 
blockoffset = 433;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Communication_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Personalization_Element*****
Sl_CS_Operation = 'Set_BsReten_Personalization_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Personalization_Element*****
ArgumentIn0 = 'BsReten_Personalization_Element' ;


Operation_prototype = 'Set_BsReten_Personalization_Element( BsReten_Personalization_Element)'; 
blockoffset = 434;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Personalization_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_VisDlt_Element*****
Sl_CS_Operation = 'Set_BsReten_VisDlt_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_VisDlt_Element*****
ArgumentIn0 = 'BsReten_VisDlt_Element' ;


Operation_prototype = 'Set_BsReten_VisDlt_Element( BsReten_VisDlt_Element)'; 
blockoffset = 435;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_256_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_VisDlt_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Power_Element*****
Sl_CS_Operation = 'Set_BsReten_Power_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Power_Element*****
ArgumentIn0 = 'BsReten_Power_Element' ;


Operation_prototype = 'Set_BsReten_Power_Element( BsReten_Power_Element)'; 
blockoffset = 436;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Power_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsReten_Display_Element*****
Sl_CS_Operation = 'Set_BsReten_Display_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsReten_Display_Element*****
ArgumentIn0 = 'BsReten_Display_Element' ;


Operation_prototype = 'Set_BsReten_Display_Element( BsReten_Display_Element)'; 
blockoffset = 437;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_100_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsReten_Display_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsDiag_ErrorRecord_Element*****
Sl_CS_Operation = 'Set_BsDiag_ErrorRecord_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsDiag_ErrorRecord_Element*****
ArgumentIn0 = 'BsDiag_ErrorRecord_Element' ;


Operation_prototype = 'Set_BsDiag_ErrorRecord_Element( BsDiag_ErrorRecord_Element)'; 
blockoffset = 438;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_1024_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsDiag_ErrorRecord_Element******

%%***** ADDING CS VARIABLE HOLDING TI Set_BsDiag_Dtc_Element*****
Sl_CS_Operation = 'Set_BsDiag_Dtc_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Set_BsDiag_Dtc_Element*****
ArgumentIn0 = 'BsDiag_Dtc_Element' ;


Operation_prototype = 'Set_BsDiag_Dtc_Element( BsDiag_Dtc_Element)'; 
blockoffset = 439;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' Arr_u8_2048_type_instance(1)');
set_param(fnCaller,'BackgroundColor', 'lightBlue');
add(arProps,[ifPkg '/' InterfaceName], 'Operations', Sl_CS_Operation);

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentIn0 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION Set_BsDiag_Dtc_Element******

%%********** Adding TI TI_EcumExtInit***** Adding CS Port  pp_Init**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_EcumExtInit';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'pp_Init';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI Mdl_Dim_Init*****
Sl_CS_Operation = 'Mdl_Dim_Init';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Mdl_Dim_Init*****


Operation_prototype = 'Mdl_Dim_Init( )'; 
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

%autosar.api.syncModel(model_name);
try
autosar.api.validateModel(model_name)
catch validationErr
throw(validationErr)
end
