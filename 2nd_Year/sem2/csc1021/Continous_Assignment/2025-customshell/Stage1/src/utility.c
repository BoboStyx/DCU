/*
Name: Oluwaseyi Favour Adu
Student Number: 23378686
I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.
I have read and understood the DCU Academic Integrity and Plagiarism Policy. I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
*/

#include "customshell.h"

//Changes the working directory and updates PWD.
void cd_command(char *path){
    char cwd[MAX_BUFFER];

    if (path == NULL){
        getcwd(cwd, sizeof(cwd));
        printf("Current directory: %s\n", cwd);//Print current directory if no path is provided.
        return;
    }

    char new_path[MAX_BUFFER];
    char *home = getenv("HOME");//Get home environment.

    if (strcmp(path, "~") == 0){
        if (home) {
            path = home;//If ~ is used get home path set up as path.
        } else {
            printf("Error: HOME directory not found.\n");
            return;
        }
    }

    if (path[0] == '~' && home){
        snprintf(new_path, sizeof(new_path), "%s%s", home, path + 1);//If starting with ~ the path is filed out as the home path and whatever would originally follow i.e. ~/Documents = usr/Seyi/Documents.
        path = new_path;//Path equals the updated full path.
    }

    if (chdir(path) == 0){
        if (getcwd(cwd, sizeof(cwd)) != NULL){
            setenv("PWD", cwd, 1);//Update PWD with actual absolute path and not path string.
        }
		else{
            perror("Error updating PWD");
        }
    }
	else{
        perror("cd failed");
    }
}

//Lists directory contents.
void dir_command(char *path){
    if (path == NULL){
        path = ".";//Default directory is current directory.
    }
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "ls -al %s", path);
    system(command);//Calls ls -al on the path.
}

//Displays all environment variables.
void environ_command(){
    char **env = environ;//Get all environment variables from environ.
    while (*env) {
        printf("%s\n", *env++);//Prints each environment variable with a newline until we finish traversing the list of them.
    }
}

//Prints user input.
void echo_command(char *args[]) {
    for (int i = 1; args[i] != NULL; i++) {
        printf("%s ", args[i]);//Takes each argument and splits them by one space.
    }
    printf("\n");
}

// Displays the help manual.
void help_command(){
    char path[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", path, PATH_MAX);//Stores the length of the path string. The path here being a special symlink in Linux that points to the currently running executable.
    if (count != -1){
        path[count] = '\0';//Null-terminating the string.
        char *dir = dirname(path);//Get current directory.
        dir = dirname(dir);//Get immediate parent of current directory.
        char manual_path[PATH_MAX];//Declare path for the manual.

        snprintf(manual_path, sizeof(manual_path), "%s/manual/manualfile.txt", dir);//Saves manual path using dir as the path before the file.

        char command[PATH_MAX + 10];//+10 for calling of more function.
        snprintf(command, sizeof(command), "more %s", manual_path);
        system(command);//calls more on manualfile.txt.
    }
	else{
        perror("Error locating manualfile.txt");
    }
}

//Pauses the customshell until the user presses enter.
void pause_command(){
    printf("Press Enter to continue.\n");
    while (getchar() != '\n');//Wait until enter is pressed to proceed with the customshell.
}
