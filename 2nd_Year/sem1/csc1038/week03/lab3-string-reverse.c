/*
Author: Seyi Adu
Program: lab3-string-reverse.c
Input: A string from command-line as the first argument e.g ./lab3-string-reverse "to be or not to be"
Output: The reverse of the string e.g. "eb ot ton ro eb ot"
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char input[51]; // the input string (50 characters + null terminator)
    strncpy(input, argv[1], 50); // copy the argument to the input string capped off at 50 characters
    input[50] = '\0'; // ensure the null terminator at the end

    int length = strlen(input);

    // print reverse of the string
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", input[i]);
    }
    printf("\n");

    return 0;
}

