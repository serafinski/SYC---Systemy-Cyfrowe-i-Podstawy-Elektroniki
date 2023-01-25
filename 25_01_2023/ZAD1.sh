#!/bin/bash

echo "S21" > /dev/ttyACM0
echo "T" > /dev/ttyACM0

while read -r line < /dev/ttyACM0
do
		echo $line > log_temp.txt
		if (echo $line | grep -q 'temp') 
		then
			break
		fi
done
