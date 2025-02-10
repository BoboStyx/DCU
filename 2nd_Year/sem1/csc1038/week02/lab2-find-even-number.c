/*
Author: Seyi Adu
Program: Find Even Number
Input: Integers from command line no more than
Output: Even numbers and their position in the list
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int max_length = 10;

    /* Check if there are any arguments*/
    if (argc < 2) {
        printf("No numbers provided.\n");
        return 1;
    }

    /*Check if there are more than 10 arguments*/
    if (argc - 1 > max_length) {
        printf("Error: Maximum array length is %d.\n", max_length);
        return 1;
    }

    /*Create array of max numbers*/
    int numbers[max_length];
    int found_even = 0;

    /* Store input numbers in array and find even numbers*/
    for (int i = 1; i < argc; i++) {
        numbers[i - 1] = atoi(argv[i]); /* Convert input to integer*/
        if (numbers[i - 1] % 2 == 0) {
            /* Print index and value of the even number*/
            printf("%d - %d\n", i - 1, numbers[i - 1]);
            found_even = 1; // Mark that we found at least one even number
        }
    }

    /* If no even numbers were found, print "Not found!"*/
    if (!found_even) {
        printf("Not found!\n");
    }

    return 0;
}
