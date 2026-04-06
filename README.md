# Modular Operating System Project

This project is a Modular Operating System simulation developed in C using Unix system calls. 
The system is divided into multiple independent modules such as logging, memory management, file management, synchronization using Peterson’s algorithm, and performance calculation using Amdahl’s Law. 
All modules are controlled by a main menu program which uses fork(), exec(), and wait() system calls to execute different parts of the system.

---

## Project Structure

The project follows a modular folder structure where source files, executables, and logs are stored in separate directories.

OS_GroupProject  
│  
├── src/        → All .c source files  
├── bin/        → Compiled executables  
├── logs/       → logs.txt  
├── report/     → Contribution report  
├── boot.sh  
├── README.md  
└── .gitignore  

---

## System Flow

The system runs using a boot script which compiles all modules and then launches the main menu. 
The main menu then creates child processes and executes the selected module.

boot.sh  
   ↓  
Compile all modules  
   ↓  
main_menu  
   ↓  
fork()  
   ↓  
exec(module)  
   ↓  
Module runs  
   ↓  
logger → logs/logs.txt  

---

## Modules Description

The project contains multiple modules that simulate different operating system concepts.

logger.c → Handles system logging and writes activity to logs.txt  
peterson.c → Demonstrates process synchronization using Peterson’s Algorithm  
file_management.c → Performs file operations such as creating, reading, and writing files  
memory.c → Simulates memory management operations  
amdahl.c → Calculates performance improvement using Amdahl’s Law  
main_menu.c → Main controller program that launches modules using fork() and exec()  

---

## How To Run The Project

Open the terminal in the project folder and run the following commands:

chmod +x boot.sh  
./boot.sh  

The boot script will compile all source files, create executables in the bin folder, and start the main menu program.

---

## Group Members

Navneet Kaur  
Sumit Ahmed 
Navreet Kaur  
Gowil Madaan  
Abdunasr Ebrahim  

---

## Summary

This project demonstrates modular system design, process creation, execution control, synchronization, file handling, logging, and performance analysis in a Unix environment. 
The project structure separates source code, executables, and logs to simulate a real operating system environment.
