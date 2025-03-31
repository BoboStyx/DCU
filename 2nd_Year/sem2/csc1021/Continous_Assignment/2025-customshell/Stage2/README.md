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
<<<<<<< HEAD
=======
```
>>>>>>> dba6c744c9a9dc6030a1a7e486460f306e60a294

- **External Commands:**
  Non-built-in commands are executed by forking a child process and invoking `execvp()`. The child process inherits an environment variable `parent` set to the full path of the shell executable.

- **I/O Redirection:**
  The shell supports:
  - **Input Redirection (`<`):** Replaces `stdin` with the specified file.
  - **Output Redirection (`>` / `>>`):**
    - `>` creates/truncates a file for `stdout`.
    - `>>` appends to the file if it exists (or creates it if not).

- **Background Execution:**
  Append an ampersand (`&`) to run external commands in the background. The shell returns immediately to the prompt, while the command executes concurrently.
<<<<<<< HEAD
  *Note: Internal commands always run in the foreground.*
=======
  *Note: Internal commands always run in the foreground.*
>>>>>>> dba6c744c9a9dc6030a1a7e486460f306e60a294
