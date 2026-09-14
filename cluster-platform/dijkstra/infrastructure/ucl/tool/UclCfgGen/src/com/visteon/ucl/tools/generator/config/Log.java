package com.visteon.ucl.tools.generator.config;

import java.io.IOException;
import java.util.logging.ConsoleHandler;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

public class Log {
	private final static Logger logger = Logger.getLogger(Log.class.getName());
	private static FileHandler fh = null;
	private static ConsoleHandler ch = null;
	
	public static void init()
	{
		try {
			fh = new FileHandler("UclCfgGen.log", false);
		} catch (SecurityException | IOException e) {
			e.printStackTrace();
		}
		ch = new ConsoleHandler();
		
		fh.setFormatter(new SimpleFormatter());
		logger.addHandler(fh);
		logger.addHandler(ch);
		logger.setLevel(Level.FINE);
		logger.setUseParentHandlers(false);
		logger.info("Logger Initialized");
	}
}
