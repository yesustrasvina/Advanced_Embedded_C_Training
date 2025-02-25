# Advanced Embedded C Training

This repository contains the **Advanced Embedded C Training**, which covers fundamental and advanced topics in embedded software development by [Modular MX](https://www.linkedin.com/company/modular-mx/). 

## Table of Contents
- [Introduction](#introduction)
- [Training Topics](#training-topics)
- [Project Components](#project-components)
- [Environment Setup](#environment-setup)
- [Building the Project](#building-the-project)
- [Project Execution](#project-execution)
- [Acknowledgments](#acknowledgments)

## Introduction
This training is designed for embedded software engineers aiming to enhance their skills in **C programming** for embedded systems. The exercises and project focus on practical applications, ensuring a hands-on learning experience.

## Training Topics
This repository covers the following key topics:

### 1. Structured Programs
   - Understanding program flow and modular programming principles.

### 2. Program Control
   - Conditional statements, loops, and state machines.

### 3. Password State Machine
   - Implementing a simple password authentication system using state machines.

### 4. Functions
   - Function prototypes, recursion, and passing arguments by value and reference.

### 5. Bits and Bytes (with Unit Testing)
   - Bitwise operations, masks, and writing testable embedded code.

### 6. Arrays, Pointers, and Structures
   - Dynamic memory management, pointer arithmetic, and data structures.

## Project Components
This training includes various project modules, progressively building toward a complete embedded system.

### 1. Circular Buffer
   - Implementation of a circular buffer for efficient data storage and retrieval.

### 2. Queue Implementation
   - Creating a queue for inter-process communication between tasks.

### 3. Scheduler
   - Task scheduling with periodic execution support.

### 4. Scheduler with Software Timers
   - Extending the scheduler with software timers to handle timed tasks.

### 5. Real-Time Clock Control (RTCC)
   - Managing a real-time clock and using it to schedule and store time-based data.

## Environment Setup
To work on this project, install the following tools:

### Linux System
We recommend using **Manjaro Linux** or any Arch-based Linux distribution. Install essential development tools:

First, install the linux base devel package
```sh
sudo pacman -Syu base-devel
```

Install GCC compiler
```sh
sudo pacman -Syu gcc
```

Install its debugger
```sh
sudo pacman -Syu gdb
```
Next, you need to install make, again you can try to see if it is already installed typing  make -v, and in case you haven’t
```sh
sudo pacman -Syu make
```

Prior to continue it is need it to install an arch linux utility that will allow us to install extra packages, it is called yay and if you are using Manjaro then it will pretty easy
```sh
sudo pacman -Syyu
sudo pacman -S yay
```

### VS Code
Install Visual Studio Code with:
```sh
yay -S visual-studio-code-bin
```

## Building the Project
Ensure all project files are in a single directory:
```
project/
    queue.h
    queue.c
    scheduler.h
    scheduler.c
    rtcc.h
    rtcc.c
    main.c
    makefile
```

Use the provided **Makefile** to compile and run the project:
```sh
make
```

## Project Execution
Running `make` compiles all files and executes the program:
```sh
$ make
./main.exe
Init task 500 millisecond
Init task 1000 millisecond
Time - 12:30:1
Date - 24/6/1984
...
```

## Acknowledgments
Special thanks to **Modular MX** for providing high-quality embedded software training.

---
This repository is a hands-on approach to mastering **Advanced Embedded C**. Contributions and feedback are welcome!
