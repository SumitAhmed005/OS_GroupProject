# OS_GroupProject
Modular Operating System Project

# Group Members
- Navneet Kaur
- Sumit Ahmed
- Navreet Kaur
- Gowil Madaan
- Abdunasr Ebrahim

## Project Description
This project is a modular operating system simulation built using C and Unix system calls. 
The system consists of multiple modules such as logging, memory management, file management, synchronization using Peterson’s algorithm, and Amdahl’s Law performance calculation. 
The main menu program allows the user to select and run different modules using fork(), exec(), and wait() system calls.

## Folder Structure
OS_GroupProject/
│
├── src/                (All source code files)
├── logs/               (Log file storage)
├── boot.sh             (Script to compile and run project)
├── README.md
└── .gitignore

## How to Compile and Run
Open terminal in the project folder and run:

chmod +x boot.sh
./boot.sh

This will compile all modules and run the main menu program.

## Modules
- logger.c → Handles system logging
- peterson.c → Synchronization using Peterson’s algorithm
- file_management.c → File operations module
- memory.c → Memory management simulation
- amdahl.c → Amdahl’s Law performance calculation
- main_menu.c → Main controller program
