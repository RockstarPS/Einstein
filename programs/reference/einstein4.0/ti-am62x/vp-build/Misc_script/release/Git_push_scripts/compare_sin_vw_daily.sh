#!/bin/bash
 
VAR1=$(cat daily.xml)
VAR2=$(cat last_daily_build.xml)

if [ "$VAR1" != "$VAR2" ]
then
 echo "0"
else	
 echo "1"
   
fi
