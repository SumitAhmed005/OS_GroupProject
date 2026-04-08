# Modular Operating System Project
Overview
This project implements multiple Operating System concepts as separate modules integrated through a main menu. Each module demonstrates key OS concepts such as file management, synchronization, logging, and memory allocation.

#Modules

Logger
Handles logging of system events and writes logs into logs/logs.txt. Records actions such as file operations and process execution.
File Management
Supports basic file operations including creating files, reading files, listing files, and deleting files.
Peterson Solution
Demonstrates mutual exclusion using Peterson’s algorithm. Simulates two processes entering and exiting the critical section.
Amdahl’s Law
Calculates system speedup using Amdahl’s Law based on parallel fraction and number of processors.
Memory Allocation
Implements First Fit memory allocation and supports compaction. Allows allocation of processes into memory blocks.

#Project Structure

os_project/
src/
logger.c
file_management.c
peterson.c
amdahl.c
memory.c
main_menu.c

bin/
logger
file_management
peterson
amdahl
memory
main_menu

logs/
logs.txt

boot.sh
README.md

#How to Run

Navigate to the project directory
cd os_project
Make the boot script executable
chmod +x boot.sh
Run the project
./boot.sh
Use the menu to select modules
1 → Logger
2 → File Management
3 → Peterson Solution
4 → Amdahl’s Law
5 → Memory Allocation
6 → Exit

#Features
Modular design with separate files for each concept.
Centralized menu system.
Logging system to track operations.
Automated compilation using boot script.
Clean and organized directory structure.

#Requirements
GCC compiler
Linux or WSL environment
Bash shell

#
Notes
All modules are compiled using GCC.
Logs are stored in logs/logs.txt.
Boot script automatically cleans old builds, compiles modules, and runs the main menu.
All modules are fully integrated and functional.

#Authors
Navreet Pannu
Navneet Kaur
Sumit Ahmed
Gowil Madaan
Abdunasr Ebrahim
