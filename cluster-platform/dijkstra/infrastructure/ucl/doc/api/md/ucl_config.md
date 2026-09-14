# UCL Configuration and Generation {#ucl_config}

## Block Diagram
<table><tr><td><img src="UclConfigGen.PNG"/></td></tr></table>

## UML Design

### UCL Framework
UCL Framework is the package which defines the collection of classes that makes up the UCL Framework.
It incluldes the Abstraction Layer, Data Layer, Interface Layer, System Layer and Utilities.

### UCL Configuration
UCL Configuration has to be done per UCL node.
The node contains the Object Model Diagram which describes the instantiation fo the UCL Framework Classes and the links between them.
The UCL Configuration Generator Tool reads the Object Model Diagram and generates the glue layer that binds the instances to the classes.

## Invoking the generator
* Goto `app\highline.cfg1\design`
* Execute `generate_cfg.bat`
