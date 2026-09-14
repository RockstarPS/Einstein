package com.visteon.ucl.tools.generator.config;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.SortedMap;
import java.util.TreeMap;
import java.util.Vector;
import java.util.logging.Logger;

import com.telelogic.rhapsody.core.IRPArgument;
import com.telelogic.rhapsody.core.IRPClass;
import com.telelogic.rhapsody.core.IRPCollection;
import com.telelogic.rhapsody.core.IRPInstance;
import com.telelogic.rhapsody.core.IRPLink;
import com.telelogic.rhapsody.core.IRPModelElement;
import com.telelogic.rhapsody.core.IRPOperation;
import com.telelogic.rhapsody.core.IRPPackage;
import com.telelogic.rhapsody.core.IRPProject;

public class ConfigGenerator {
	private final static Logger logger = Logger.getLogger(Log.class.getName());

	IRPProject rpProj;
	IRPPackage rpUCL_FWK;
	IRPPackage rpUCL_PROXY;
	String proxyPackage;
	int noOfDLInstances;

	StringBuilder ConfigStr;

	public ConfigGenerator(IRPProject proj, String pack) {
		rpProj = proj;
		proxyPackage = pack;

		ConfigStr = new StringBuilder();
	}

	public void generateCode(String outPath) {
		rpUCL_FWK = (IRPPackage) rpProj.findNestedElementRecursive("UCL_FWK", "Package");
		if (rpUCL_FWK == null) {
			logger.severe("UCL_FWK Package not found. Aborting Generation.");
			return;
		}

		rpUCL_PROXY = (IRPPackage) rpProj.findNestedElementRecursive(proxyPackage, "Package");
		if (rpUCL_PROXY == null) {
			logger.severe(String.format("%s Proxy Package not found. Aborting Generation.", proxyPackage));
			return;
		}

		logger.info(String.format("Generating Code for %s", proxyPackage));

		buildFileHeader();
		buildIncludes();
		buildDefines();
		buildConfig();
		buildVtblTypes();
		buildInstanceDefinitions();
		buildInstanceLinks();
		buildInstanceArray();
		buildWrapper();
		writeFile(outPath);
	}

	private void buildFileHeader() {
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");
		ConfigStr.append("///\n");
		ConfigStr.append("/// VISTEON CORPORATION CONFIDENTIAL\n");
		ConfigStr.append("/// ________________________________\n");
		ConfigStr.append("///\n");
		ConfigStr.append("/// [2017] Visteon Corporation\n");
		ConfigStr.append("/// All Rights Reserved.\n");
		ConfigStr.append("///\n");
		ConfigStr.append("/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.\n");
		ConfigStr.append(
				"/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve\n");
		ConfigStr.append(
				"/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States\n");
		ConfigStr.append(
				"/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,\n");
		ConfigStr.append(
				"/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights\n");
		ConfigStr.append("/// under all copyright laws to protect this work as a published work, when appropriate.\n");
		ConfigStr.append(
				"/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it\n");
		ConfigStr.append("/// without the written authorization of Visteon Corporation.\n");
		ConfigStr.append("///\n");
		ConfigStr.append(
				"/// Generated on " + dateFormat.format(new Date()) + " by " + System.getProperty("user.name") + "\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");
	}

	private void buildIncludes() {
		Vector<String> vec = new Vector<String>();
		ConfigStr.append("\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");
		ConfigStr.append("/// Include files\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");
		ConfigStr.append("#ifdef UCL_DEBUG_ON\n");
		ConfigStr.append("  #include <stdarg.h>\n");
		ConfigStr.append("  #include <stdio.h>\n");  // warning: implicit declaration of function 'vsnprintf'
		ConfigStr.append("#endif\n");
		ConfigStr.append("#include \"Ucl.h\"\n");
		IRPCollection objList = rpUCL_PROXY.getNestedElementsByMetaClass("Object", 10);
		for (Object oObj : objList.toList()) {
			if (((IRPModelElement)oObj).getMetaClass().equals("Object")) {
				IRPInstance inst = (IRPInstance) oObj;
				String className = ((IRPClass) inst.getOtherClass()).getName();
				if (className.startsWith("Dummy")) {
					continue;
				}
				vec.add(className);
			}
		}

		Set<String> unique = new HashSet<String>();
		unique.addAll(vec);
		for (String str : unique) {
			ConfigStr.append("#include \"" + str.substring(1) + ".h\"\n");
		}
	}

	private void buildDefines() {
		ConfigStr.append("\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");
		ConfigStr.append("/// Definitions\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");

		SortedMap<String, Vector<String>> map = new TreeMap<String, Vector<String>>();
		IRPCollection linkList = rpUCL_PROXY.getNestedElementsByMetaClass("Link", 10);
		for (Object oLinkObj : linkList.toList()) {
			IRPLink linkObj = (IRPLink) oLinkObj;
			
			String linkStr = linkObj.getName();
			String intfStr = ((IRPClass) (linkObj.getFromPort().getProvidedInterfaces().toList().get(0))).getName();

			if (map.containsKey(intfStr)) {
				Vector<String> v = map.get(intfStr);
				v.add(linkStr);
			} else {
				Vector<String> v = new Vector<String>();
				v.add(linkStr);
				map.put(intfStr, v);
			}
		}

		Set<String> keys = map.keySet();
		for (Iterator<String> i = keys.iterator(); i.hasNext();) {
			String key = (String) i.next();
			Vector<String> value = (Vector<String>) map.get(key);
			if(key.compareTo("IUclDL") == 0)
			{
				noOfDLInstances = value.size(); //To Get the Router Index of each DL Instances in UclDLCbkObjs
				//logger.info(String.format("NUM_OF_DL_INSTANCE: %s - %d ", key, noOfDLInstances));				
			}
			ConfigStr.append("#define " + key.toUpperCase().substring(1) + "_NUM_INSTANCES     (" + value.size() + "u)\n");
		}
	}

	private void buildConfig() {
		ConfigStr.append("\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");
		ConfigStr.append("/// Instance Configuration\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");

		//SortedMap<String, Integer> map = new TreeMap<String, Integer>();
		SortedMap<String, String> map = new TreeMap<String, String>();
		IRPCollection objList = rpUCL_PROXY.getNestedElementsByMetaClass("Object", 10);
		for (Object oObj : objList.toList()) {
			if (((IRPModelElement)oObj).getMetaClass().equals("Object")) {
				IRPInstance inst = (IRPInstance) oObj;
				String className = ((IRPClass) inst.getOtherClass()).getName();
				if (className.startsWith("Dummy")) {
					continue;
				}
				map.put(inst.getDisplayName(), className);
			}
		}

		Set<String> keys = map.keySet();
		for (Iterator<String> i = keys.iterator(); i.hasNext();) {
			String key = (String) i.next();
			String value = (String) map.get(key);
			String cfgDeclStr = "S" + value.substring(1, value.indexOf("_")) + "Cfg";
			String cfgVarStr = key.replace("Inst", "Cfg");
			ConfigStr.append("extern " + cfgDeclStr + " " + cfgVarStr + ";\n");
		}
	}

	private void buildVtblTypes() {
		ConfigStr.append("\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");
		ConfigStr.append("/// Interface VTBL definitions\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");

		IRPCollection classList = rpUCL_FWK.getClasses();
		for (Object oClass : classList.toList()) {
			IRPClass rpClass = (IRPClass) oClass;
			String ifNameStr = rpClass.getDisplayName();
			if (ifNameStr.startsWith("I")) {
				IRPCollection opsList = rpClass.getOperations();

				if (opsList.getCount() > 0) {
					String vtblStr = "typedef struct " + ifNameStr + "_t {\n";
					for (Object oOp : opsList.toList()) {
						IRPOperation rpOp = (IRPOperation) oOp;
						String opName = rpOp.getName();
						String opReturn = rpOp.getReturns().getName();

						IRPCollection argsList = rpOp.getArguments();
						int argCount = argsList.getCount();
						if (argCount == 0) {
							vtblStr += "\t" + opReturn + " (*" + opName + ")(void);\n";
						} else {
							vtblStr += "\t" + opReturn + " (*" + opName + ")(";

							int tempArgCount = 0;
							for (Object oArgs : argsList.toList()) {
								IRPArgument rpArg = (IRPArgument) oArgs;
								String argType = rpArg.getType().getName();
								if (argType.startsWith("p_")) {
									vtblStr += argType.substring(2) + " *" + rpArg.getName();
								} else {
									vtblStr += argType + " " + rpArg.getName();
								}
								tempArgCount++;
								if (tempArgCount < argCount) {
									vtblStr += ", ";
								}
							}

							vtblStr += ");\n";
						}
					}

					vtblStr += "} " + ifNameStr + ";\n\n";
					ConfigStr.append(vtblStr);
				}
			}
		}
	}

	private void buildInstanceDefinitions() {
		ConfigStr.append("\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");
		ConfigStr.append("/// Instance Definitions\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");

		IRPCollection objList = rpUCL_PROXY.getNestedElementsByMetaClass("Object", 10);
		// Iterate over objects
		for (Object oObj : objList.toList()) {
			if (((IRPModelElement)oObj).getMetaClass().equals("Object")) {
				IRPInstance inst = (IRPInstance) oObj;
				String className = ((IRPClass) inst.getOtherClass()).getName();
				if (className.startsWith("Dummy")) {
					continue;
				}
				
				// Consolidate incoming links
				SortedMap<String, Vector<String>> map = new TreeMap<String, Vector<String>>();
				IRPCollection inLinksList = inst.getInLinks();
				for (Object oInLInk : inLinksList.toList()) {
					IRPLink rpInLInk = (IRPLink) oInLInk;
					IRPClass intf = (IRPClass) (rpInLInk.getFromPort().getProvidedInterfaces().toList().get(0));
					if (map.containsKey(intf.getDisplayName())) {
						Vector<String> v = map.get(intf.getDisplayName());
						v.add(rpInLInk.getFromElement().getName());
					} else {
						Vector<String> v = new Vector<String>();
						v.add(rpInLInk.getFromElement().getName());
						map.put(intf.getDisplayName(), v);
					}
				}
	
				// Generate Incoming Instance Array
				{
					Set<String> keys = map.keySet();
					for (Iterator<String> i = keys.iterator(); i.hasNext();) {
						String key = (String) i.next();
						Vector<String> value = (Vector<String>) map.get(key);
	
						String tempStr = "static uint8 " + inst.getDisplayName() + "_" + key + "["
								+ value.size() + "] = {";
						//for (Object oStr : value.toArray()) {
						//	String str = (String) oStr;
						//	tempStr += str.substring(str.length() - 1) + ",";
						//}
						//TODO: FIXME
						String str = (String)inst.getDisplayName();
						//logger.info(String.format("%s - %s ", tempStr, str));
						int instId = Character.getNumericValue(str.charAt(str.length() - 1));
						
						if(key.compareTo("IUclDLCbk") == 0)
						{							
							//To Get the Scheduler & Router Index of each DL Instances in UclDLCbkObjs
							tempStr += instId + "," + (instId + noOfDLInstances);							
						}
						else if((key.compareTo("IUclALPhy") == 0) || (key.compareTo("IUclALPhyCbk") == 0))
						{
							//TO Get right UclALPhyObjs & UclALPhyCbkObjs index in UCL MI
							tempStr += instId;
						}
						else
						{
							for(int j = 0; j < value.size(); j++) {
								tempStr += j + ",";
							}
							tempStr = tempStr.substring(0, tempStr.length() - 1);
						}												
						tempStr += "};\n";
						ConfigStr.append(tempStr);
					}
				}
	
				// Generate Instance Definition
				String instDefStr = "";
				instDefStr = "static S" + className.substring(1, className.indexOf("_")) + "Inst "
						+ inst.getName() + " = {\n";
				instDefStr += "\t.pCfg = &" + inst.getName().replace("Inst", "Cfg") + ",\n";
				{
					Set<String> keys = map.keySet();
					for (Iterator<String> i = keys.iterator(); i.hasNext();) {
						String key = (String) i.next();
						Vector<String> value = (Vector<String>) map.get(key);
						instDefStr += "\t.num" + key + " = " + value.size() + ",\n";
						instDefStr += "\t.p" + key + " = &" + inst.getDisplayName() + "_" + key + "[0],\n";
					}
				}
				instDefStr += "};\n\n";
				ConfigStr.append(instDefStr);
			}
		}
	}

	private void buildInstanceLinks() {
		ConfigStr.append("\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");
		ConfigStr.append("/// Instance Links\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");

		IRPCollection linkList = rpUCL_PROXY.getNestedElementsByMetaClass("Link", 10);
		for (Object oLinkObj : linkList.toList()) {
			IRPLink linkObj = (IRPLink) oLinkObj;

			String intfStr = ((IRPClass) (linkObj.getFromPort().getProvidedInterfaces().toList().get(0))).getName();
			String fromClassStr = ((IRPClass) ((IRPInstance) linkObj.getFromElement()).getOtherClass()).getName()
					.substring(1);
			String toClassStr = ((IRPClass) ((IRPInstance) linkObj.getToElement()).getOtherClass()).getName()
					.substring(1);
			String fromElementStr = linkObj.getFromElement().getDisplayName();
			String toElementStr = linkObj.getToElement().getDisplayName();

			String funcPrefix_1 = linkObj.getName() + "_" + intfStr;
			String funcPrefix_2 = fromClassStr + "_" + intfStr;

			IRPCollection opsList = ((IRPClass) (linkObj.getFromPort().getProvidedInterfaces().toList().get(0)))
					.getOperations();
			if (opsList.getCount() > 0) {
				String funcStr = "";
				for (Object oOp : opsList.toList()) {
					IRPOperation rpOp = (IRPOperation) oOp;
					String opName = rpOp.getName();
					String opReturn = rpOp.getReturns().getName();

					funcStr += "static " + opReturn + " " + funcPrefix_1 + "_" + opName;

					IRPCollection argsList = rpOp.getArguments();
					int argCount = argsList.getCount();
					if (argCount == 0) {
						funcStr += "(void) {";
					} else {
						funcStr += "(";
						int tempArgCount = 0;
						for (Object oArgs : argsList.toList()) {
							IRPArgument rpArg = (IRPArgument) oArgs;
							String argType = rpArg.getType().getName();
							if (argType.startsWith("p_")) {
								funcStr += argType.substring(2) + " *" + rpArg.getName();
							} else {
								funcStr += argType + " " + rpArg.getName();
							}
							tempArgCount++;
							if (tempArgCount < argCount) {
								funcStr += ", ";
							}
						}
						funcStr += ") { ";
					}

					if (!opReturn.equals("void")) {
						funcStr += "return ";
					}

					funcStr += funcPrefix_2 + "_" + opName + "(";
					funcStr += "&" + fromElementStr + ", ";
					
					if((toElementStr.substring(toElementStr.length() - 1).matches("^[0-9]+$")) && 
					(intfStr.substring(intfStr.length() - 3).matches("Cbk"))) 					
					{
						//funcStr += "(" + toClassStr.substring(0, toClassStr.indexOf("_")).toUpperCase() + " | "
						//		+ toElementStr.substring(toElementStr.length() - 1) + ")";
						funcStr += "(" + toElementStr.substring(toElementStr.length() - 1) + ")";						
					} 
					else if (fromElementStr.substring(fromElementStr.length() - 1).matches("^[0-9]+$"))
					{
						funcStr += "(" + fromElementStr.substring(fromElementStr.length() - 1) + ")";					
					}
					else {
						//funcStr += "(" + toClassStr.substring(0, toClassStr.indexOf("_")).toUpperCase() + " | "
						//		+ toElementStr.substring(toElementStr.length() - 1) + ")";
						funcStr += "(0)";
					}

					for (Object oArgs : argsList.toList()) {
						IRPArgument rpArg = (IRPArgument) oArgs;
						funcStr += ", " + rpArg.getName();
					}

					funcStr += "); }\n";
				}
				ConfigStr.append(funcStr + "\n");

				funcStr = "static const " + intfStr + " " + funcPrefix_1 + " = {\n";
				for (Object oOp : opsList.toList()) {
					IRPOperation rpOp = (IRPOperation) oOp;
					funcStr += "\t&" + funcPrefix_1 + "_" + rpOp.getName() + ",\n";
				}
				funcStr += "};\n";

				ConfigStr.append(funcStr + "\n");
			}
		}
	}

	private void buildInstanceArray() {
		ConfigStr.append("\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");
		ConfigStr.append("/// Instance Array\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");

		SortedMap<String, Vector<String>> map = new TreeMap<String, Vector<String>>();
		IRPCollection linkList = rpUCL_PROXY.getNestedElementsByMetaClass("Link", 10);
		for (Object oLinkObj : linkList.toList()) {
			IRPLink linkObj = (IRPLink) oLinkObj;
			
			String linkStr = linkObj.getName();
			String intfStr = ((IRPClass) (linkObj.getFromPort().getProvidedInterfaces().toList().get(0))).getName();

			if (map.containsKey(intfStr)) {
				Vector<String> v = map.get(intfStr);
				v.add(linkStr);
			} else {
				Vector<String> v = new Vector<String>();
				v.add(linkStr);
				map.put(intfStr, v);
			}
		}
		
		Set<String> keys = map.keySet();
		for (Iterator<String> i = keys.iterator(); i.hasNext();) {
			String key = (String) i.next();
			Vector<String> value = (Vector<String>) map.get(key);
			
			String println = "const " + key + " *" + key.substring(1) + "Objs[" + value.size() +"] = {\n";
			for (Object oStr : value.toArray()) {
				String str = (String) oStr;
				println += "\t&" + str + "_" + key + ",\n";
			}			
			println += "};\n\n";
			
			ConfigStr.append(println);
		}
	}
	
	private void buildWrapper() {
		ConfigStr.append("\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");
		ConfigStr.append("/// Wrapper Functions\n");
		ConfigStr.append(
				"///---------------------------------------------------------------------------------------------------------------------\n");

		IRPCollection classList = rpUCL_FWK.getClasses();
		for (Object oClass : classList.toList()) {
			IRPClass rpClass = (IRPClass) oClass;
			String ifNameStr = rpClass.getDisplayName();
			if (ifNameStr.startsWith("I")) {
				IRPCollection opsList = rpClass.getOperations();
				if (opsList.getCount() > 0) {
					for (Object oOp : opsList.toList()) {
						IRPOperation rpOp = (IRPOperation) oOp;
						String opName = rpOp.getName();
						String opReturn = rpOp.getReturns().getName();
						
						String funcName = ifNameStr.substring(1) + "_" + opName;
						
						if(funcName.equals("UclALDebug_Log")) {
							String funcStr = "void UclALDebug_Log(uint8 InstId, EUclALDebugLevel Level, const char8 *tag, const char8 * fmt, ...)\n{\n";
							funcStr += "#ifdef UCLALDEBUG_NUM_INSTANCES\n";
							funcStr += "#ifdef UCL_DEBUG_ON\n";
							funcStr += "    char8 buffer[256];\n";
							funcStr += "    va_list argptr;\n";
							funcStr += "    va_start(argptr, fmt);\n";
							funcStr += "    vsnprintf(buffer, 256, fmt, argptr);\n";
							funcStr += "    va_end(argptr);\n";
							funcStr += "    UclALDebugObjs[InstId]->Log(Level, (char8 *) tag, buffer);\n";
							funcStr += "#endif\n";
							funcStr += "#endif\n";
							funcStr += "}\n";
							ConfigStr.append(funcStr);
							continue;
						}
						
						String funcStr = opReturn + " " + funcName + "(uint8 instId";
						
						IRPCollection argsList = rpOp.getArguments();
						int argCount = argsList.getCount();
						if(0 == argCount) {
							funcStr += ") {\n";	
						} else {
							for (Object oArgs : argsList.toList()) {
								IRPArgument rpArg = (IRPArgument) oArgs;
								String argType = rpArg.getType().getName();
								if (argType.startsWith("p_")) {
									funcStr += ", " + argType.substring(2) + " *" + rpArg.getName();
								} else {
									funcStr += ", " + argType + " " + rpArg.getName();
								}
							}
							funcStr += ") { \n";
						}
						
						funcStr += "#ifdef " + ifNameStr.substring(1).toUpperCase() + "_NUM_INSTANCES\n";
						
						funcStr += "\t";
						if (!opReturn.equals("void")) {
							funcStr += "return ";
						}
						funcStr += ifNameStr.substring(1) + "Objs[instId]->" + opName + "(";
						
						for (Object oArgs : argsList.toList()) {
							IRPArgument rpArg = (IRPArgument) oArgs;
							funcStr += rpArg.getName() + ", ";
						}
						if(0 < argsList.getCount()) {
							funcStr = funcStr.substring(0, funcStr.length() - 2);
						}
						funcStr += ");\n";
						funcStr += "#else\n";
						if (!opReturn.equals("void")) {
							funcStr += "\treturn UCL_E_NOK;\n";
						} else {
							funcStr += "\treturn;\n";
						}
						funcStr += "#endif\n";
						funcStr += "}\n";
						ConfigStr.append(funcStr);
					}
				}
			}
		}
	}

	private void writeFile(String outPath) {
		logger.info("Writing configuration file " + outPath + "\\UclCfg.c");
		
		if(null == outPath) {
			outPath = ".\\";
		}
		
		makeDir(outPath);
		
		BufferedWriter out = null;
		try {
			FileWriter fstream = new FileWriter(outPath + "\\UclCfg.c", false);
			out = new BufferedWriter(fstream);
			out.write(ConfigStr.toString());
			out.close();
		} catch (IOException e) {
			logger.severe(e.getMessage());
		}
	}
	
	private void makeDir(String dirName) {
		File dir = new File(dirName);

		// if the directory does not exist, create it
		if (!dir.exists()) {
			logger.info("creating directory: " + dir.getName());
			try {
				dir.mkdirs();
			} catch (SecurityException se) {
				// handle it
			}
		} else {
			// Delete previous files
			for (File file : dir.listFiles())
				if (!file.isDirectory())
					file.delete();
		}
	}
}
