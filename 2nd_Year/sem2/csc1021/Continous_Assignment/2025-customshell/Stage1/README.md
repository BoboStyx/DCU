Name: Oluwaseyi Favour Adu
Student Number: 23378686
I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.
I have read and understood the DCU Academic Integrity and Plagiarism Policy. I accept the penalties that may be imposed should I engage in practice or practices that breach this policy

# Custom Shell Assignment

## Overview
This is a **custom shell** implementation in C. It supports various internal (built-in) commands and can execute external commands like a typical Unix shell.

## Features
- **Built-in Commands:**
  - `cd` – Change directory
  - `clr` – Clear the screen
  - `dir` – List directory contents
  - `environ` – Show all environment variables
  - `echo` – Print text to the terminal
  - `help` – Display the shell manual
  - `pause` – Wait for user input
  - `quit` – Exit the shell program

- **Batch Mode:** Execute commands from a text file.
- **Dynamic Prompt:** Displays the current working directory.
- **Environment Variable:** Automatically sets `$SHELL` to the executable's path.

---

## Compilation
- **GCC Compiler**

### Steps
```sh
make
./customshell
./customshell batchfile.txt  # Run batch mode
make clean
