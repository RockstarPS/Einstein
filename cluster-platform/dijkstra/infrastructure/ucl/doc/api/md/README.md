# Unified Communication Link Documentation 
UCL Version $(UCL_VERSION)

## Introduction
The purpose of the Unified Communication Link (UCL) is to provide the communication link between two processing systems. The processing system can be a physical or virtual core(s) running an operating system, an external processor or an external system connected over the network.
<br/>
[Click here for UCL Wiki](http://cdwiki.visteon.com/infrastructure/middleware/dijkstra/components/ucl)
<br/>
## Important Links
- [Component Information](@ref comp_info)
- [UCL Configuration & Generation](@ref ucl_config)
- [Build Instructions](@ref build_instructions)
- [Release Notes](@ref rel_notes)
- [Frequently Asked Questions](@ref faq)

## How To Guides
- [Interfacing with the UCL DL Layer](@ref ucl_dl_interface)

## Block Diagram
The block diagram below shows the UCL Configuration with adapters for AUTOSAR RTE and Visteon Messaging Framework (VMF)

<table><tr><td><img src="UclEndToEndBlockDiagram.PNG"/></td></tr></table>

## Package Structure
The block diagram below shows the UCL Layers

<table>
  <tr>
    <td width="400" valign="top">
		UCL_ADAPTER provides interface to communicate with the 
		chosen communication framework such as AUTOSAR, VMF etc.
		
		UCL_SYS provides entry point for the UCL Sub-system and     
		initializes the participating software modules.             	
																		
		UCL_IL module manage the DL Instancs, scheduing of the 	
		UCL messages for transmission and routing of the received
		UCL messages.  	

		UCL_DL module receives the structured UCL messages from the 	
		UCL_IL layer, encode them and transports them over the      	
		physical communication drivers.                             	
																		
		UCL_CMN module contains the utility functions.              	
																		
		UCL_AL_OS provides interfaces to start/stop tasks,          	
		perform mutual exclusions, enable/disable interrupts and    	
		other Operating System services.                            	
																		
		UCL_AL_PHY provides interfaces to access the physical 
		transport layer such as SPI, UART, ShMem to send and 
		receive unstructured data.                            	

		UCL_AL_CRYPTO provides interfaces to perform crypto 
		operation such as CMAC calculation, CBC encryption/
		decryption and random number generation.

		UCL_AL_DEBUG provides the debug interface to log            	
		debug prints and UCL messages for analysis. It provides     	
		flexible debug sinks to route the output to standard        	
		error console or file system.                               	
	</td>
    <td><img src="UclPackageStructure.jpg" width="600"></td>
  </tr>
</table>

