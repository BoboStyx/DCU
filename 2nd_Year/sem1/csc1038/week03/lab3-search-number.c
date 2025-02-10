/*
Author: Seyi Adu
Program: lab3-search-number.c
Input: An array of integers, first argument is the number to be searched for, rest of integers are numbers to be searched through e.g "4 9 12 5 7 8 4 13"
Output: The number we search for and the position i.e. "Found 4 at 5"
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check that at least 2 arguments are put after running program
    if (argc < 3) {
        printf("Need at least 2 integers");
        return 1;
    }

    // The first argument is the number we search for
    int num_to_search = atoi(argv[1]);

    // Loop through the remaining arguments to search for the number
    for (int i = 2; i < argc; i++) {
        int current_num = atoi(argv[i]);
        if (current_num == num_to_search) {
            // Print the value and index when the number is found
            printf("Found %d at %d\n", num_to_search, i - 2);
            return 0; // Exit the program after finding the number
        }
    }

    // If the number is not found in the array
    printf("%d not found\n", num_to_search);

    return 0;
}

