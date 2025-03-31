/*
Name: Oluwaseyi Favour Adu
Student Number: 23378686
I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.
I have read and understood the DCU Academic Integrity and Plagiarism Policy. I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
*/

#ifndef CUSTOMSHELL_H
#define CUSTOMSHELL_H


//Include neccesarry libraries.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <libgen.h>
#include <limits.h>

#define MAX_BUFFER 1024 //Maximum user input up to 1024 bytes so no excess inputs corrupt memory.
#define MAX_ARGS 64 //Maximum number of command arguments(tokens) for the shell preventing stack overflow.
#define SEPARATORS " \t\n" //Seperates input at encounter of these.

extern char **environ; //Declares environ as a variable that is already defined by the system.

//Init functions.
void prompt();
void set_shell_env();
int get_input(char *buf, FILE *input_source);

//Utility functions.
void cd_command(char *path);
void dir_command(char *path);
void environ_command();
void echo_command(char *args[]);
void help_command();
void pause_command();
void parse_input(char *buffer, char *args[]);


//Execution, Redirection and External Commands functions.
void commands(char *args[]);
void background_execution(char *args[], int *background);
void io_redirection(char *args[], int *in_fd, int *out_fd, char **input_file, char **output_file, int *append);
void external_command(char *args[], int background, int in_fd, int out_fd, char *input_file, char *output_file, int append);

#endif

