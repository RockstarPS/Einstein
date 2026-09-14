To use SYSLOG as debugconsole 

#Pre-requisites
1.syslog daemon should be running in the system .
2.In journald.conf file "ForwardToSyslog=yes"  should be enabled and set as yes.
3.In service file for required application set the StandardOutput and StandardError as journal
 "StandardOutput=journal
  StandardError=journal"
  

