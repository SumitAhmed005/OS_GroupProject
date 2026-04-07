this is how i want the boot.sh #!/bin/bash

echo "Cleaning old build and logs..."
rm -rf bin logs

echo "Creating required folders..."
mkdir bin logs
touch logs/logs.txt

echo "Compiling logger..."
gcc src/logger.c -o bin/logger

echo "Compiling file management..."
gcc src/file_management.c -o bin/file_management

echo "Compiling peterson..."
gcc src/peterson.c -o bin/peterson

echo "Compiling amdahl..."
gcc src/amdahl.c -o bin/amdahl

echo "Compiling memory..."
gcc src/memory.c -o bin/memory

echo "Compiling main menu..."
gcc src/main_menu.c -o bin/main_menu

echo "Making executables runnable..."
chmod +x bin/*

echo "Running main menu..."
cd bin || exit
./main_menu
