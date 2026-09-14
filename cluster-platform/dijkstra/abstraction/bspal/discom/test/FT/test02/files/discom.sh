
#!/bin/sh

a=1
b=1

until [ $a -gt 100 ]
do 
    # Print the values
    echo starting loop count $a
	/tmp/discom_loop
	sleep 2
      
    # increment the value
    a=$(( $a + $b ))
done
