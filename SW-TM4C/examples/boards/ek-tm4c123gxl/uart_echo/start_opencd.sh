#!/bin/bash
echo "-------------------------------------------------"
echo "Connect to the board with \"telnet localhost 4444\""
echo "-------------------------------------------------"

sudo openocd --file opencd.cfg --log output.txt
