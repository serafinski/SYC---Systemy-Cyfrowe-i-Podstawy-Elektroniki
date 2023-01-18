#!/bin/bash

while : 
do 
	if (users | grep -q 'r4pi23')
	then
		echo 1 > /sys/class/gpio/gpio23/value
		sleep 1
		echo 0 > /sys/class/gpio/gpio23/value
		sleep 1
	fi
done
