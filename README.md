# Advanced Embedded C Training

This repository contains the **Advanced Embedded C Training**, which covers fundamental and advanced topics in embedded software development by [Modular MX](https://www.linkedin.com/company/modular-mx/). 

![Embedded C training banner](https://github.com/yesustrasvina/Advanced-Embedded-C-Training/blob/main/Images/Advance_Embedded_C.png)

Date: *February 2025*

- The [**Certificate and Badge**]() are available.

## Table of Contents
- [Introduction](#introduction)
- [Training Topics](#training-topics)
- [Project Components](#project-components)
- [Environment Setup](#environment-setup)
- [Building the Project](#building-the-project)
- [Project Execution](#project-execution)
- [Evidences](#evidences)

## Introduction
_<-- Back to [Table of Contents](#table-of-contents)_  

This training is designed for embedded software engineers aiming to enhance their skills in **C programming** for embedded systems. The exercises and project focus on practical applications, ensuring a hands-on learning experience.

## Training Topics
_<-- Back to [Table of Contents](#table-of-contents)_  

This repository covers the following key topics:

### 1. Introduction
   - Introduction to C with basic concepts as variables, format specifiers, inputs and outputs.

### 2. Structured Programs
   - Exercises to practice if statements, loops and logical operators.

### 3. Program Control
   - Practice for loops and switch statements.

### 4. Password State Machine
   - Design a program to read a password following state machine diagram.

### 5. Functions
   - All about functions. Function prototypes, arguments, and return statement.

### 6. Bits and Bytes (with Unit Testing)
   - Bitwise operations, masks, and writing testable embedded code.

### 7. Arrays
   - Arrays in C, array of strings, string library.

### 8. Pointers
   - Memory addresses, pointer notation, pointers in functions, array with pointers.

### 9. Structures
   - C structs, typedef word, array of structs access to structure members and functions with structures.

![Training tree](https://github.com/yesustrasvina/Advanced-Embedded-C-Training/blob/main/Images/Training_tree.png)

## Project Components

_<-- Back to [Table of Contents](#table-of-contents)_

This training includes various project modules, progressively building toward a complete embedded system.

### 1. Circular Buffer
   - Implementation of a circular buffer for efficient reading and writing data.
   ![Circular buffer](https://github.com/yesustrasvina/Advanced-Embedded-C-Training/blob/main/Images/Circular%20buffer.png)

### 2. Queue Implementation
   - Basically, Queues are the same as circular buffers but this time with a small modification Queues shall be able to handle any type of data from 8-bit variables to any     kind of structure.  The use of void pointers and the memcpy function from the standard library can help us create queues that can handle any type of element. In this way, we can create waiting queues that store any type of element with a single algorithm.

### 3. Scheduler
   - Every task or process we have in our programs should have been designed to run with a predefined periodicity, this is a must for a real-life program, and timing is an important asset to keep in mind when we design our programs. It is desired to have an algorithm to set each task periodicity and ensure each run according to the time established. The Scheduler is the part of the program in charge to accomplish such objective, the most common version of this scheduler is the round robin, which means each task will run after the other with no preemption.
   Taking as reference a scheduler made by Profesor Fran Vahid [RIOS Scheduler](https://www.cs.ucr.edu/~vahid/rios/)

### 4. Scheduler with Software Timers
   - The scheduler should have an interface to register task-independent software timers. the software timer shall be decremented down to zero during the scheduler tick and should have the possibility to call a pre-registered callback function. Once its count reaches zero the timer decrement must stop, to later be restarted again by the application in case necessary.

### 5. Real-Time Clock Control (RTCC)
   - Managing a real-time clock and using it to schedule and store time-based data with option to set alarm.

## Environment Setup

_<-- Back to [Table of Contents](#table-of-contents)_

To work on this project, install the following tools:

### Linux System
**Manjaro Linux** or any Arch-based Linux distribution. Install essential development tools:

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

_<-- Back to [Table of Contents](#table-of-contents)_

```
project/
    queue.h
    queue.c
    scheduler.h
    scheduler.c
    Rtcc.h
    Rtcc.c
    main.c
    makefile
```

Use the provided **Makefile** to compile and run the project:
```sh
make
```

![Makefile_evidence](https://github.com/yesustrasvina/Advanced-Embedded-C-Training/blob/main/Images/Makefile_evidence.png)

## Project Execution

_<-- Back to [Table of Contents](#table-of-contents)_

Running `make` compiles all files and executes the program:
```sh
$ make
Init task 500 millisecond
Init task 1000 millisecond
Time - 23:59:58
Date - 31/12/1984
...
```

## Evidences

_<-- Back to [Table of Contents](#table-of-contents)_

### 1. Circular Buffer
![Circular Buffer](https://github.com/yesustrasvina/Advanced-Embedded-C-Training/blob/main/Images/Evidence_Circular_Buffer.png)

### 2. Queue Buffer
![Queue Buffer](https://github.com/yesustrasvina/Advanced-Embedded-C-Training/blob/main/Images/Evidence_Queue_Buffer.png)

### 3. Scheduler
![Scheduler](https://github.com/yesustrasvina/Advanced-Embedded-C-Training/blob/main/Images/Evidence_Scheduler.png)

### 4. Scheduler with software timers
![Scheduler with Software Timers](https://github.com/yesustrasvina/Advanced-Embedded-C-Training/blob/main/Images/Evidence_Software_Timers.png)

### 5. Project with Real Time Clock and Calendar
![Project with Real Time Clock and Calendar](https://github.com/yesustrasvina/Advanced-Embedded-C-Training/blob/main/Images/Evidence_Clock_and_Calendar.png)