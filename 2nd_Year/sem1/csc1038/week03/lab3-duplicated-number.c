/*
Author: Seyi Adu
Program: lab3-duplicated-number.c
Input: An array of integers, which has a duplicated e.g "4 9 12 5 7 8 4 13"
Output: The duplicated number we find i.e. "4"
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check that at least 2 arguments are put after running program
    if (argc < 3) {
        printf("Need at least 2 integers");
        return 1;
    }


    // Loop through the remaining arguments to search for a duplicated number
    for (int i = 1; i < argc; i++) {
        int current_num = atoi(argv[i]);
	// loop from current number to see if any other number is duplicated
	for (int j = i + 1; j < argc; j++) {
		int check = atoi(argv[j]);
		if (current_num == check){ // if number is duplicated
			printf("%d\n", current_num);
			return 0;
	}
        }
    }

    // If the number is not found in the array
    printf("no duplicated number\n");

    return 0;
}

