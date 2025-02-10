/*
Author: Seyi Adu
Program: lab4-count-character.c
Input: A lower case letter followed by a string in which we look for the count of the appearences of the first letter e.g a "abcdefg"
Output: The number of times the letter showed up e.g. 1
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check for correct amount of arguments
    if (argc != 3) {
        printf("Program requires three arguments\n");
        return 1;
    }

    // Get the string and character from the arguments
    char *inputString = argv[2];
    char targetChar = argv[1][0];
    int count = 0;

    // Count the appearencess of the character in the string
    for (int i = 0; i < strlen(inputString); i++) {
        if (inputString[i] == targetChar) {
            count++;
        }
    }

    // Print the result
    printf("%d\n", count);

    return 0;
}

