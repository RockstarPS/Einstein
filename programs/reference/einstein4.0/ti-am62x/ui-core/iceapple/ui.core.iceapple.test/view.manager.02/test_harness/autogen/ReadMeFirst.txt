After generating the files, hmi_logic_state_handler_02.inc is hand edited to include the screen definitions directly in it and remove the hmi_gfx_mgr02_cfg.h inclusion becuase this will otherwise lead to a graphics manager dependancy for VM02 testing.

So if you ever need to re generate this take care this.