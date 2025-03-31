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
