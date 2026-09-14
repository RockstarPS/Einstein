package com.visteon.ucl.tools.generator.config;

import java.util.logging.Level;
import java.util.logging.Logger;

import com.telelogic.rhapsody.core.IRPApplication;
import com.telelogic.rhapsody.core.IRPProject;
import com.telelogic.rhapsody.core.RhapsodyAppServer;

import gnu.getopt.Getopt;

public class Main {
	public static int MAJ_VERSION = 0;
	public static int MIN_VERSION = 2;
	public static int PATCH_VERSION = 1;

	private final static Logger logger = Logger.getLogger(Log.class.getName());

	public static void main(String[] args) {
		IRPApplication rpAppl = null;
		IRPProject rpProj = null;

		String proj = null;
		String pack = null;
		String outPath = null;

		// Initialize Logger
		Log.init();

		logger.log(Level.ALL, String.format("UclCfgGen Version %d.%d.%d", MAJ_VERSION, MIN_VERSION, PATCH_VERSION));
		logger.info(String.format("UclCfgGen Version %d.%d.%d", MAJ_VERSION, MIN_VERSION, PATCH_VERSION));
		int c;
		Getopt g = new Getopt("UclCfgGen", args, "p:d:o:");

		while ((c = g.getopt()) != -1) {
			switch (c) {
			case 'p':
				proj = g.getOptarg();
				break;
			case 'd':
				pack = g.getOptarg();
				break;
			case 'o':
				outPath = g.getOptarg();
				break;
			}
		}

		if (proj == null) {
			logger.severe("Rhapsody project missing");
			return;
		}
		if (pack == null) {
			logger.severe("Rhapsody package missing");
			return;
		}

		logger.info(String.format("Rhapsody Project: %s", proj));
		logger.info(String.format("Selected Package: %s", pack));

		try {
			logger.info("Launching Rhapsody...");
			rpAppl = RhapsodyAppServer.createRhapsodyApplication();
			if (rpAppl != null) {
				logger.info(String.format("Opening Project %s", proj));
				rpProj = rpAppl.openProject(proj);
			}
			if (rpProj != null) {
				ConfigGenerator generator = new ConfigGenerator(rpProj, pack);
				generator.generateCode(outPath);
			}
		} catch (Exception e) {
			logger.log(Level.SEVERE, "Exception ", e);
		} finally {
			if(rpProj != null) {
				logger.info("Closing Project...");
				rpProj.close();			
			}
			if(rpAppl != null) {
				logger.info("Exiting Rhapsody...");
				rpAppl.quit();				
			}
		}
	}
}
