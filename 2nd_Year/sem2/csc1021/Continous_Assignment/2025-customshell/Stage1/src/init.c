/*
Name: Oluwaseyi Favour Adu
Student Number: 23378686
I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.
I have read and understood the DCU Academic Integrity and Plagiarism Policy. I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
*/

#include "customshell.h"

//Sets shell environment to where the executable is.
void set_shell_env(){
    char path[PATH_MAX];

    ssize_t count = readlink("/proc/self/exe", path, PATH_MAX - 1);//Get the full path of the running shell executable.
    if (count != -1){
        path[count] = '\0';//Null-terminate the string properly.

        setenv("SHELL", path, 1); //Set SHELL environment variable dynamically.
    }

	else{
        perror("Failed to set SHELL environment variable");
    }
}

//Displays the shell prompt.
void prompt(){
    char cwd[MAX_BUFFER];// Current working directory less than 1024 bytes.

    if (getcwd(cwd, sizeof(cwd)) != NULL){
        printf("%s ==> ", cwd);
    }
	else{
        perror("getcwd error");
    }
    fflush(stdout);//Ensures prompt is primpted before input can be given.
}

//Reads input from either the user or a batch file.
int get_input(char *buffer, FILE *input_source){
    if (fgets(buffer, MAX_BUFFER, input_source) == NULL){
        return 0;
    }
    return 1;//Return error otherwise.
}

