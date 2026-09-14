#!/bin/bash
 
VAR1=$(cat develop.xml)
VAR2=$(cat last_build_manifest.xml)

if [ "$VAR1" != "$VAR2" ]
then
 echo "0"
else	
 echo "1"
   
fi
