/*
Author: Seyi Adu
Program: lab3-findMax.c
Input: Command line consists of array of numbers from command line
Output: Prints the biggest number
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // check to see if at least one integer is provided
    if (argc < 2) {
        printf("Program needs at least one integer on command-line", argv[0]);
        return 1;
    }

    // take the first number as the maximum number
    int max = atoi(argv[1]);

    // Loop through arguments to see if there is a bigger number
    for (int i = 2; i < argc; i++) {
        int num = atoi(argv[i]); // convert argument to integer
        if (num > max) {
            max = num;
        }
    }

    // print the largest number
    printf("%d\n", max);

    return 0;
}

