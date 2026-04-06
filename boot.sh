#!/bin/bash

echo "Starting OS Project..."

rm -rf bin
mkdir bin

if [ ! -d logs ]; then
    mkdir logs
fi

if [ ! -f logs/logs.txt ]; then
    touch logs/logs.txt
fi

echo "Compiling modules..."

gcc src/logger.c -o bin/logger
gcc src/peterson.c -o bin/peterson
gcc src/file_management.c -o bin/file_management
gcc src/memory.c -o bin/memory
gcc src/amdahl.c -o bin/amdahl
gcc src/main_menu.c -o bin/main_menu

echo "Compilation complete."
echo "Running main menu..."

cd bin
./main_menu
