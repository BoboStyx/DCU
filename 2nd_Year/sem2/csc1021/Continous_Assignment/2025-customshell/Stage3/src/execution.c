/*
Name: Oluwaseyi Favour Adu
Student Number: 23378686
I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.
I have read and understood the DCU Academic Integrity and Plagiarism Policy. I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
*/

#include "customshell.h"

//Handles user internal commands from custom shell.
void commands(char *args[]){

    //Initialise redirection and background variables.
    int background = 0;//Background execution true or false
    int in_fd = STDIN_FILENO;//Input file description
	int out_fd = STDOUT_FILENO;//Output file description
    char *input_file = NULL;//Input file name
	char  *output_file = NULL;//Output file name
    int append = 0;//Appending true or false

    //Check for background execution.
    background_execution(args, &background);

    //Commands that are not used for i/o redirection
    if (strcmp(args[0], "cd") == 0){
        cd_command(args[1]);
        return;
    }
    else if (strcmp(args[0], "pause") == 0){
        pause_command();
        return;
	}
	else if (strcmp(args[0], "clr") == 0){
		system("clear");
		return;
    }
    else if (strcmp(args[0], "quit") == 0){
        printf("Closing shell.\n");
        exit(0);
    }

    io_redirection(args, &in_fd, &out_fd, &input_file, &output_file, &append);
    //For commands that use i/o redirection.
    if (strcmp(args[0], "echo") == 0 || strcmp(args[0], "dir") == 0 || strcmp(args[0], "help") == 0 || strcmp(args[0], "environ") == 0){

        pid_t pid = fork();//Create child process
        if (pid == 0){
            //Set up input redirection if specified.
            if (input_file) {
                dup2(in_fd, STDIN_FILENO);
                close(in_fd);
            }
            //Set up output redirection if specified.
            if (output_file) {
                dup2(out_fd, STDOUT_FILENO);
                close(out_fd);
            }

            //Execute the proper internal command.
            if (strcmp(args[0], "echo") == 0){
                echo_command(args);
			}
            else if (strcmp(args[0], "dir") == 0){
                dir_command(args[1]);
			}
            else if (strcmp(args[0], "help") == 0){
                help_command();
			}
            else if (strcmp(args[0], "environ") == 0){
   				environ_command();
			}
            exit(0); //Ensure the child exits.
        }
        else if (pid > 0){
            //If parent process wait for internal commands to complete.
            waitpid(pid, NULL, 0);
        }
        else{
            perror("Fork failed");
        }
        return;
    }

    //Command is not internal run for external commands.
    external_command(args, background, in_fd, out_fd, input_file, output_file, append);
}

//Checks for & symbol and changes background execution to true if & is a lone argument
void background_execution(char *args[], int *background){
    for (int i = 0; args[i] != NULL; i++){
        if (strcmp(args[i], "&") == 0){
			*background = 1;//Background execution is true
            args[i] = NULL;//Remove input symbol
            break;
        }
    }
}

//Input and output redirection, with files, and commands
void io_redirection(char *args[], int *in_fd, int *out_fd, char **input_file, char **output_file, int *append){
    for (int i = 0; args[i] != NULL; i++){//Check for i/o redirection
        if (strcmp(args[i], "<") == 0){//Check if input file
            *input_file = args[i + 1];//Get file name
            args[i] = NULL;//Remove input symbol
            *in_fd = open(*input_file, O_RDONLY);//Get file description and read only
            if (*in_fd == -1){//Error case
                perror("Input redirection failed");
                exit(1);
            }
        }
		else if (strcmp(args[i], ">") == 0){//Check if output file and if to overwrite
            *output_file = args[i + 1];//Get file name
            args[i] = NULL;//Remove input symbol
            *append = 0;//Ensure append is false
            *out_fd = open(*output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);//Get file description and writes one, creates if no file exists, and truncates if there's already information in file also sets the files permissions if new file created.
            if (*out_fd == -1){//Error case
                perror("Output redirection failed");
                exit(1);
            }
        }
		else if (strcmp(args[i], ">>") == 0){//Check if output file and if to apepnd.
            *output_file = args[i + 1];//Get file name.
            args[i] = NULL;//Remove input symbol.
            *append = 1;//Ensure append is true.
            *out_fd = open(*output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);//Get file description and writes one, creates if no file exists, and appendss if there's already information in file also sets the permissions if new file created.
            if (*out_fd == -1){//Error case
                perror("Output redirection failed");
                exit(1);
            }
        }
    }
}

//Handles user external commands e.g. ls.
void external_command(char *args[], int background, int in_fd, int out_fd, char *input_file, char *output_file, int append){
    pid_t pid = fork();//Create child process
    if (pid == 0){
        if (input_file){//Handling input redirection for external commands
            in_fd = open(input_file, O_RDONLY);//Get file description
            if (in_fd == -1){//Error case
                perror("Input redirection failed");
                exit(1);
            }
            dup2(in_fd, STDIN_FILENO);//Duplicates file description into standard input file descriptor
            close(in_fd);//Close file description
        }

        if (output_file){//Handling output redirection for external commands
            out_fd = open(output_file, append ? O_APPEND | O_WRONLY | O_CREAT : O_WRONLY | O_CREAT | O_TRUNC, 0644);//Depending whether append is true or false
            if (out_fd == -1){//Error case
                perror("Output redirection failed");
                exit(1);
            }
            dup2(out_fd, STDOUT_FILENO);//Duplcates file description into standard output file descriptor
            close(out_fd);//Close file description
        }

        execvp(args[0], args);//Launch external command
        perror("Command execution failed");//Child process error
        exit(1);//Exit
    }
	else if (pid > 0){//Parent Process
        if (background){//If background execution is still happening
            signal(SIGCHLD, SIG_IGN);//Clean up terminated child process
        }
		else{
            waitpid(pid, NULL, 0);//wait for internal commands to be completed
        }
    }
	else{//Error case
        perror("Fork failed");
    }
}
