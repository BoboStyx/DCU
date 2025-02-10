/*
Author: Seyi Adu
Program: Count odd elements in an array
Input: No more than 10 integer command line arguments
Output: The number of odd elements in command line
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /* Maximum array length*/
    int max_length = 10;

    /* Checking if there are any numbers provided (argc > 1)*/
    if (argc == 1) {
        printf("No numbers provided.\n");
        return (1);
    }

    /* Checking if number of inputs exceeds the max array length*/
    if (argc - 1 > max_length) {
        printf("Error: Maximum array length is %d.\n", max_length);
        return (1);
    }

    /* Array to store input numbers*/
    int numbers[max_length];
    int count_odd = 0;/*Count of odd numbers*/

    /* Store input numbers in array and count odd numbers*/
    for (int i = 1; i < argc; i++) {
        numbers[i - 1] = atoi(argv[i]); /* Convert input to integer*/
        if (numbers[i - 1] % 2 != 0) {
            count_odd++; /* Increment odd count if number is odd*/
        }
    }

    /* Output the total number of odd numbers*/
    printf("%d\n", count_odd);

    return (0);
}

