#!/bin/bash

ddd --eval-command="target remote localhost:3333" --debugger arm-none-eabi-gdb main.bin
