## **42_Pipex**
## 🔍 Overview

Pipex is a C programming project that focuses on creating a simplified version of the pipe command, similar to how Unix/Linux shells handle pipes. The project challenges you to work with processes, file descriptors, and piping, providing a deeper understanding of inter-process communication. The goal is to implement a program that simulates a pipeline between commands by reading from one command’s output and feeding it as input to another.
## 🛠 Features

- Pipe Implementation: The program uses Unix/Linux pipes to connect multiple commands together.
- Process Creation: The project handles the creation of child processes using fork().
- File Handling: It deals with file opening, reading, writing, and closing through file descriptors.
- Command Parsing: The program parses command-line arguments to correctly set up the piping mechanism between commands.
- Error Handling: Proper error handling is implemented for system calls like fork(), pipe(), and execve() to ensure smooth execution.

## 💡 Inspiration

The Pipex project was created to strengthen my understanding of Unix/Linux system calls, inter-process communication, and the use of pipes to connect commands. By re-implementing pipe functionality, I gained practical experience working with processes, handling file descriptors, and understanding how complex shell commands work under the hood.