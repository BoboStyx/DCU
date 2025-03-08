/*
Name: Oluwaseyi Favour Adu
Student Number: 23378686
I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.
I have read and understood the DCU Academic Integrity and Plagiarism Policy. I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
*/

#include "customshell.h"


//Main operating functions.
int main(int argc, char **argv){
    char buf[MAX_BUFFER];
    char *args[MAX_ARGS];
    FILE *input = stdin;//Default input to stdin.

    // Set SHELL environment variable dynamically.
    set_shell_env();

    // Check if a batch file is provided.
    if (argc > 1){
        input = fopen(argv[1], "r");
        if (!input){
            perror("Error opening batch file");
            return 1;
        }
    }

	//Running shell.
    while (1){
        if (input == stdin){
            prompt();//Display prompt only if batch file is unprovided.
        }

        if (!get_input(buf, input)){
            printf("\n");
            break;//Ctrl-D exits shell.
        }

        parse_input(buf, args);//Parse input of buffer and put it into args.

        if (args[0] != NULL){
            if (strcmp(args[0], "quit") == 0){
                printf("Closing shell.\n");
                break;//Quit command exits the shell.
            }
            commands(args);//Execute commands.
        }
    }

    return 0;//Safely exit program.
}

//Parses user input into arguments.
void parse_input(char *buffer, char *args[]){
    char *token;
    int i = 0;

    token = strtok(buffer, SEPARATORS);//Get first token. Seperate input using SEPERATORS.
    while (token != NULL && i < MAX_ARGS - 1){
        args[i++] = token;//Update args with token.
        token = strtok(NULL, SEPARATORS);//Seperate remaining string.
    }
    args[i] = NULL;//Argument at i  is null to have a stopping point in functions.
}

//Handles user commands.
void commands(char *args[]){
    if (strcmp(args[0], "clr") == 0){
        system("clear");
        return;
    }
	else if (strcmp(args[0], "cd") == 0){
        cd_command(args[1]);
        return;
    }
	else if (strcmp(args[0], "dir") == 0){
        dir_command(args[1]);
        return;
    }
	else if (strcmp(args[0], "environ") == 0){
        environ_command();
        return;
    }
	else if (strcmp(args[0], "echo") == 0){
        echo_command(args);
        return;
    }
	else if (strcmp(args[0], "help") == 0){
        help_command();
        return;
    }
	else if (strcmp(args[0], "pause") == 0){
        pause_command();
        return;
    }
    printf("Command '%s' not found. Try 'help' to see available commands.\n", args[0]);//Encourages user to use help if using unknown commands.
}

