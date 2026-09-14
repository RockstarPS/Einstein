%% This is an Auto generated m script for adding the Autosar Ports and interfaces in Matlab Environment
close all; 
model_name = 'View_Speed' ; 
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
RunnableName = ['View_Speed_Task']; 
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

% ******************* Adding AutoSar Port rp_SPD_SP1_In_Statusand Interface TI_SPD_SP1_In_Status *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SPD_SP1_In_Status_rp_SPD_SP1_In_Status' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_SPD_SP1_In_Status';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_SPD_SP1_In_Statusand Interface TI_SPD_SP1_In_Status *****************

% ******************* Adding AutoSar attribute SP1_In_Status as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_SPD_SP1_In_Status_SP1_In_Status';
blockoffset = 10;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'SP1_In_Status';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute SP1_In_Status as element *****************

% ******************* Adding AutoSar Port rp_SPD_Target_Statusand Interface TI_SPD_Target_Status *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SPD_Target_Status_rp_SPD_Target_Status' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_SPD_Target_Status';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_SPD_Target_Statusand Interface TI_SPD_Target_Status *****************

% ******************* Adding AutoSar attribute Spd_Target_Status as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_SPD_Target_Status_Spd_Target_Status';
blockoffset = 11;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'Spd_Target_Status';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute Spd_Target_Status as element *****************

% ******************* Adding AutoSar Port rp_SPD_Trim_Statusand Interface TI_SPD_Trim_Status *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SPD_Trim_Status_rp_SPD_Trim_Status' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_SPD_Trim_Status';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_SPD_Trim_Statusand Interface TI_SPD_Trim_Status *****************

% ******************* Adding AutoSar attribute Spd_Trim_Status as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_SPD_Trim_Status_Spd_Trim_Status';
blockoffset = 12;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'Spd_Trim_Status';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute Spd_Trim_Status as element *****************

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
blockoffset = 13;
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

% ******************* Adding AutoSar Port rp_Dcm_appStopand Interface TI_SR_Dcm_AppStopNotification *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_Dcm_AppStopNotification_rp_Dcm_appStop' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_Dcm_appStop';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_Dcm_appStopand Interface TI_SR_Dcm_AppStopNotification *****************

% ******************* Adding AutoSar attribute AppId as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_Dcm_appStop_AppId';
blockoffset = 14;
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

% ******************* Adding AutoSar Port rp_SPD_Target2_Statusand Interface TI_SPD_Target2_Status *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SPD_Target2_Status_rp_SPD_Target2_Status' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_SPD_Target2_Status';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_SPD_Target2_Statusand Interface TI_SPD_Target2_Status *****************

% ******************* Adding AutoSar attribute Spd_Target2_Status as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_SPD_Target2_Status_Spd_Target2_Status';
blockoffset = 15;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'Spd_Target2_Status';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute Spd_Target2_Status as element *****************

% ******************* Adding AutoSar Port rp_SPD_Trim2_Statusand Interface TI_SPD_Trim2_Status *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SPD_Trim2_Status_rp_SPD_Trim2_Status' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_SPD_Trim2_Status';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_SPD_Trim2_Statusand Interface TI_SPD_Trim2_Status *****************

% ******************* Adding AutoSar attribute Spd_Trim2_Status as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_SPD_Trim2_Status_Spd_Trim2_Status';
blockoffset = 16;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'Spd_Trim2_Status';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute Spd_Trim2_Status as element *****************

% ******************* Adding AutoSar Port rp_DispDistanceUnitand Interface TI_SR_Meter_DisplayDistanceUnit *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_Meter_DisplayDistanceUnit_rp_DispDistanceUnit' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_DispDistanceUnit';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_DispDistanceUnitand Interface TI_SR_Meter_DisplayDistanceUnit *****************

% ******************* Adding AutoSar attribute DisplayUnit as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_DispDistanceUnit_DisplayUnit';
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
element1 = 'DisplayUnit';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute DisplayUnit as element *****************

% ******************* Adding AutoSar Port rp_Diag_Digitalspeedand Interface TI_SR_Diag_Display_speed_Value *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_Diag_Display_speed_Value_rp_Diag_Digitalspeed' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_Diag_Digitalspeed';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_Diag_Digitalspeedand Interface TI_SR_Diag_Display_speed_Value *****************

% ******************* Adding AutoSar attribute Diag_Digital_Speed_Value as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_Diag_Digitalspeed_Diag_Digital_Speed_Value';
blockoffset = 18;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'uint16');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'Diag_Digital_Speed_Value';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute Diag_Digital_Speed_Value as element *****************

% ******************* Adding AutoSar Port rp_SPD_Selection_Tableand Interface TI_SPD_Selection_Table *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SPD_Selection_Table_rp_SPD_Selection_Table' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_SPD_Selection_Table';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_SPD_Selection_Tableand Interface TI_SPD_Selection_Table *****************

% ******************* Adding AutoSar attribute Speed_Selection_Table as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_SPD_Selection_Table_Speed_Selection_Table';
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
element1 = 'Speed_Selection_Table';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute Speed_Selection_Table as element *****************

% ******************* Adding AutoSar Port rp_Countrycode_Funcand Interface TI_SR_CountryCode_Func *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_CountryCode_Func_rp_Countrycode_Func' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Receiver Port under Atomic Component
receiverPortName = 'rp_Countrycode_Func';
add(arProps,aswcPath{1},'ReceiverPorts',receiverPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port rp_Countrycode_Funcand Interface TI_SR_CountryCode_Func *****************

% ******************* Adding AutoSar attribute CountryCode_Func as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'rp_Countrycode_Func_CountryCode_Func';
blockoffset = 20;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
HandleSR = add_block('simulink/Ports & Subsystems/In1', [model_name '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
%Set Simulink inport properties
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'CountryCode_FuncType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'CountryCode_FuncType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
HandleSR = add_block('simulink/Ports & Subsystems/In1', [Apprunnablepath '/InputHarness' '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'CountryCode_FuncType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 30 + 200) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used in Variant subsytem 
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [Apprunnablepath '/InputHarness' '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'CountryCode_FuncType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+30) ((blockoffset * topoffset)+20)];
% Add a inport to Code generation --> used for Code generation 
HandleSR = add_block('simulink/Ports & Subsystems/In1', [CodeGenblockpath '/' 'input'], 'Name', Sl_SR_PortName, 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'CountryCode_FuncType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
PositionArray = [(leftoffset + 200) (blockoffset * topoffset)  (leftoffset+ 200 + 30) ((blockoffset * topoffset)+20)];
% Add a outport to input harness --> used for Code generation
HandleSR = add_block('simulink/Ports & Subsystems/Out1', [CodeGenblockpath '/' 'output'], 'Name', [Sl_SR_PortName '_out'], 'Position',PositionArray);
set_param(HandleSR,'PortDimensions','1');
set_param(HandleSR,'OutDataTypeStr', 'CountryCode_FuncType');
set_param(HandleSR,'BackgroundColor', 'lightBlue');
% Add the element 
element1 = 'CountryCode_Func';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink inport to Receive port of the Atomic Component
mapInport(slMap,Sl_SR_PortName,receiverPortName,element1,'ExplicitReceive');

% ******************* Complete Adding AutoSar attribute CountryCode_Func as element *****************

% ******************* Adding AutoSar Port pp_Display_speed_Valueand Interface TI_Display_speed_Value *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_Display_speed_Value_pp_Display_speed_Value' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_Display_speed_Value';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_Display_speed_Valueand Interface TI_Display_speed_Value *****************

% ******************* Adding AutoSar attribute Digital_Speed_Value as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_Display_speed_Value_Digital_Speed_Value';
blockoffsetop = 1;
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
element1 = 'Digital_Speed_Value';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute Digital_Speed_Value as element *****************

% ******************* Adding AutoSar Port pp_SubDisplaySpeed_Valueand Interface TI_SR_SubDisplaySpeed_Value *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_SubDisplaySpeed_Value_pp_SubDisplaySpeed_Value' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_SubDisplaySpeed_Value';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_SubDisplaySpeed_Valueand Interface TI_SR_SubDisplaySpeed_Value *****************

% ******************* Adding AutoSar attribute SubDispSpeedVal as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_SubDisplaySpeed_Value_SubDispSpeedVal';
blockoffsetop = 2;
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
element1 = 'SubDispSpeedVal';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute SubDispSpeedVal as element *****************

% ******************* Adding AutoSar Port pp_SubSpeedUnit_Valueand Interface TI_SR_SubSpeedUnitValue *****************

%% Add Sender/Receiver Interface to the Application SWC's
%add Sender/Receiver Interface
InterfaceType = 'SenderReceiverInterface';
InterfaceName = 'TI_SR_SubSpeedUnitValue_pp_SubSpeedUnit_Value' ; % This is a TI name inside the UML
% Add interface to AUTOSAR interface Package
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);

%add a Sender Port under Atomic Component
SenderPortName = 'pp_SubSpeedUnit_Value';
add(arProps,aswcPath{1},'SenderPorts',SenderPortName,'Interface',InterfaceName);

% ******************* Complete Adding AutoSar Port pp_SubSpeedUnit_Valueand Interface TI_SR_SubSpeedUnitValue *****************

% ******************* Adding AutoSar attribute SubSpeedunit as element *****************

%add an inport in simulink to map with receiver port of the Application SWC
Sl_SR_PortName = 'pp_SubSpeedUnit_Value_SubSpeedunit';
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
element1 = 'SubSpeedunit';
% Link the element and the AutoSar Interface. 
add(arProps,[ifPkg '/' InterfaceName], 'DataElements', element1,'SwCalibrationAccess',swCalibValue);   
% Map Simulink OutPort to Sender port of the Atomic Component
mapOutport(slMap,Sl_SR_PortName,SenderPortName,element1,'ExplicitSend');

% ******************* Complete Adding AutoSar attribute SubSpeedunit as element *****************

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
blockoffset = 21;
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
blockoffset = 22;
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
blockoffset = 23;
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
blockoffset = 24;
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
blockoffset = 25;
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
blockoffset = 26;
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
blockoffset = 27;
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
blockoffset = 28;
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
blockoffset = 29;
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
blockoffset = 30;
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
blockoffset = 31;
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
blockoffset = 32;
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
blockoffset = 33;
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
blockoffset = 34;
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
blockoffset = 35;
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
blockoffset = 36;
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
blockoffset = 37;
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
blockoffset = 38;
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
blockoffset = 39;
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
blockoffset = 40;
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
blockoffset = 41;
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
blockoffset = 42;
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
blockoffset = 43;
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
blockoffset = 44;
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
blockoffset = 45;
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

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Illumination_Element*****
Sl_CS_Operation = 'Get_BsConst_Illumination_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Illumination_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Illumination_Element( )'; 
blockoffset = 46;
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
%%***** COMPLETED ADDING OPERATION Get_BsConst_Illumination_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsConst_Audio_Element*****
Sl_CS_Operation = 'Get_BsConst_Audio_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsConst_Audio_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsConst_Audio_Element( )'; 
blockoffset = 47;
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
blockoffset = 48;
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
blockoffset = 49;
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
blockoffset = 50;
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
blockoffset = 51;
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
blockoffset = 52;
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
blockoffset = 53;
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

%%***** ADDING CS VARIABLE HOLDING TI Get_BsFuSa_FeatureData_Warning_Element*****
Sl_CS_Operation = 'Get_BsFuSa_FeatureData_Warning_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsFuSa_FeatureData_Warning_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsFuSa_FeatureData_Warning_Element( )'; 
blockoffset = 54;
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
%%***** COMPLETED ADDING OPERATION Get_BsFuSa_FeatureData_Warning_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsFuSa_FeatureData_Power_Element*****
Sl_CS_Operation = 'Get_BsFuSa_FeatureData_Power_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsFuSa_FeatureData_Power_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsFuSa_FeatureData_Power_Element( )'; 
blockoffset = 55;
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
%%***** COMPLETED ADDING OPERATION Get_BsFuSa_FeatureData_Power_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsFuSa_FeatureData_Display_Element*****
Sl_CS_Operation = 'Get_BsFuSa_FeatureData_Display_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsFuSa_FeatureData_Display_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsFuSa_FeatureData_Display_Element( )'; 
blockoffset = 56;
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
%%***** COMPLETED ADDING OPERATION Get_BsFuSa_FeatureData_Display_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsFuSa_FeatureData_Audio_Element*****
Sl_CS_Operation = 'Get_BsFuSa_FeatureData_Audio_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsFuSa_FeatureData_Audio_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsFuSa_FeatureData_Audio_Element( )'; 
blockoffset = 57;
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
%%***** COMPLETED ADDING OPERATION Get_BsFuSa_FeatureData_Audio_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsFuSa_FeatureData_Communication_Element*****
Sl_CS_Operation = 'Get_BsFuSa_FeatureData_Communication_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsFuSa_FeatureData_Communication_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsFuSa_FeatureData_Communication_Element( )'; 
blockoffset = 58;
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
%%***** COMPLETED ADDING OPERATION Get_BsFuSa_FeatureData_Communication_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsFuSa_FeatureData_Fota_Element*****
Sl_CS_Operation = 'Get_BsFuSa_FeatureData_Fota_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsFuSa_FeatureData_Fota_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsFuSa_FeatureData_Fota_Element( )'; 
blockoffset = 59;
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
%%***** COMPLETED ADDING OPERATION Get_BsFuSa_FeatureData_Fota_Element******

%%***** ADDING CS VARIABLE HOLDING TI Get_BsCys_Certicificate_Element*****
Sl_CS_Operation = 'Get_BsCys_Certicificate_Element';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION Get_BsCys_Certicificate_Element*****

ArgumentOut0 = 'Ptr' ;
ArgumentOut1 = 'error_status' ;

Operation_prototype = '[Ptr,error_status ] = Get_BsCys_Certicificate_Element( )'; 
blockoffset = 60;
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
blockoffset = 61;
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
blockoffset = 62;
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
blockoffset = 63;
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
blockoffset = 64;
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
blockoffset = 65;
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
blockoffset = 66;
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
blockoffset = 67;
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
blockoffset = 68;
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
blockoffset = 69;
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
blockoffset = 70;
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
blockoffset = 71;
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
blockoffset = 72;
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
blockoffset = 73;
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
blockoffset = 74;
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
blockoffset = 75;
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
blockoffset = 76;
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
blockoffset = 77;
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
blockoffset = 78;
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
blockoffset = 79;
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
blockoffset = 80;
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
blockoffset = 81;
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
blockoffset = 82;
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
blockoffset = 83;
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
blockoffset = 84;
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
blockoffset = 85;
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
blockoffset = 86;
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
blockoffset = 87;
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
blockoffset = 88;
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
blockoffset = 89;
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

%%********** Adding TI if_CS_ComAbsTx***** Adding CS Port  rp_CS_TxCanMdl**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'if_CS_ComAbsTx';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ClientPortName = 'rp_CS_TxCanMdl';
add(arProps,aswcPath{1},'ClientPorts',ClientPortName,'Interface',InterfaceName);
%%********** Finish Adding TI if_CS_ComAbsTx***** Finish Adding CS Port  rp_CS_TxCanMdl**********

%%***** ADDING CS VARIABLE HOLDING TI TxCan_ClearCanSignalTxConfirmation*****
Sl_CS_Operation = 'TxCan_ClearCanSignalTxConfirmation';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION TxCan_ClearCanSignalTxConfirmation*****
ArgumentIn0 = 'SignalId' ;


Operation_prototype = 'TxCan_ClearCanSignalTxConfirmation( SignalId)'; 
blockoffset = 90;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tTxSignalId_type_instance(1)');
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
%%***** COMPLETED ADDING OPERATION TxCan_ClearCanSignalTxConfirmation******

%%***** ADDING CS VARIABLE HOLDING TI TxCan_GetCanSignalTxConfirmation*****
Sl_CS_Operation = 'TxCan_GetCanSignalTxConfirmation';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION TxCan_GetCanSignalTxConfirmation*****
ArgumentIn0 = 'SignalId' ;

ArgumentOut0 = 'pStatus' ;

Operation_prototype = 'pStatus  = TxCan_GetCanSignalTxConfirmation( SignalId)'; 
blockoffset = 91;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tTxSignalId_type_instance(1)');
set_param(fnCaller, 'OutputArgumentSpecifications', ' tTxSigConfirmStatus_type_instance(1)');
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
%%***** COMPLETED ADDING OPERATION TxCan_GetCanSignalTxConfirmation******

%%***** ADDING CS VARIABLE HOLDING TI TxCan_SetSignalFromRetentionBuffer*****
Sl_CS_Operation = 'TxCan_SetSignalFromRetentionBuffer';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION TxCan_SetSignalFromRetentionBuffer*****
ArgumentIn0 = 'SignalId' ;

ArgumentOut0 = 'error_status' ;

Operation_prototype = 'error_status  = TxCan_SetSignalFromRetentionBuffer( SignalId)'; 
blockoffset = 92;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tTxSignalId_type_instance(1)');
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
'Direction','Error',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION TxCan_SetSignalFromRetentionBuffer******

%%***** ADDING CS VARIABLE HOLDING TI TxCan_SetSignalValue*****
Sl_CS_Operation = 'TxCan_SetSignalValue';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION TxCan_SetSignalValue*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'pTxSignalData' ;

ArgumentOut0 = 'error_status' ;

Operation_prototype = 'error_status  = TxCan_SetSignalValue( SignalId,pTxSignalData)'; 
blockoffset = 93;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tTxSignalId_type_instance(1) ,uint8(1)');
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
'Arguments',ArgumentIn1 ,...
'Direction','In',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************

%%*************PARAMETER ADDITION STARTS*************

add(arProps, [ifPkg '/' InterfaceName '/' Sl_CS_Operation],...
'Arguments',ArgumentOut0 ,...
'Direction','Error',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION TxCan_SetSignalValue******

%%***** ADDING CS VARIABLE HOLDING TI TxCan_SetSignalValueU8Arr*****
Sl_CS_Operation = 'TxCan_SetSignalValueU8Arr';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION TxCan_SetSignalValueU8Arr*****
ArgumentIn0 = 'SignalId' ;
ArgumentIn1 = 'pTxSignalData' ;
ArgumentIn2 = 'SignalLength' ;

ArgumentOut0 = 'error_status' ;

Operation_prototype = 'error_status  = TxCan_SetSignalValueU8Arr( SignalId,pTxSignalData,SignalLength)'; 
blockoffset = 94;
PositionArray = [leftoffset (blockoffset * topoffset)  (leftoffset+200) ((blockoffset * topoffset)+100)];
fnCaller = add_block('simulink/User-Defined Functions/Function Caller', [CodeGenblockpath '/' 'caller'], 'Name', Sl_CS_Operation,'Position',PositionArray);
set_param(fnCaller, 'FunctionPrototype', Operation_prototype);
set_param(fnCaller, 'InputArgumentSpecifications', ' tTxSignalId_type_instance(1) ,uint8(1) ,uint32(1)');
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
'Arguments',ArgumentOut0 ,...
'Direction','Error',...
'SwCalibrationAccess',swCalibValue);

%%*************PARAMETER ADDITION ENDS *************


%autosar.api.syncModel(model_name);
%mapFunctionCaller(slMap,Sl_CS_Operation,ClientPortName,Sl_CS_Operation);
%%***** COMPLETED ADDING OPERATION TxCan_SetSignalValueU8Arr******

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
blockoffset = 95;
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
blockoffset = 96;
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
blockoffset = 97;
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
blockoffset = 98;
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
blockoffset = 99;
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
blockoffset = 100;
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
blockoffset = 101;
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
blockoffset = 102;
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
blockoffset = 103;
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

%%********** Adding TI TI_EcumExtInit***** Adding CS Port  pp_Init**********

InterfaceType = 'ClientServerInterface'; 
InterfaceName = 'TI_EcumExtInit';
addPackageableElement(arProps,InterfaceType,ifPkg,InterfaceName,'IsService',false);
ServerPortName = 'pp_Init';
add(arProps,aswcPath{1},'ServerPorts',ServerPortName,'Interface',InterfaceName);
%%***** ADDING CS VARIABLE HOLDING TI View_Speed_Init*****
Sl_CS_Operation = 'View_Speed_Init';
%%***** COMPLETE ADDING TI VARIABLE 

%%***** ADDING OPERATION View_Speed_Init*****


Operation_prototype = 'View_Speed_Init( )'; 
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
