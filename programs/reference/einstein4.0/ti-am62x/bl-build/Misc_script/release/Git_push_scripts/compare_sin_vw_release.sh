#!/bin/bash
 
VAR1=$(cat release.xml)
VAR2=$(cat last_release_build.xml)

if [ "$VAR1" != "$VAR2" ]
then
 echo "0"
else	
 echo "1"
   
fi
