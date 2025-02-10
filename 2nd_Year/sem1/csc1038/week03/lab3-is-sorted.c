/*
Author: Seyi Adu
Program: lab3-is-sorted.c
Input: An array of integers from command line e.g 5 1 4 2 8
Output: Sorted array of integers one per line
 */


#include <stdio.h>
#include <stdlib.h>

//Bubble Sort Algorithm
void bubbleSort(int arr[], int n){
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Need at least one integer to sort");
        return 1;
    }

    int num_of_elements = argc - 1; // Number of elements
    int array[num_of_elements]; // Initialise array

    // Read input numbers from command-line arguments
    for (int i = 0; i < num_of_elements; i++) {
        array[i] = atoi(argv[i + 1]); // Convert arguments to integers
    }

    // Sort the array using bubble sort
    bubbleSort(array, num_of_elements);

    // Print the sorted array line by line
    for (int i = 0; i < num_of_elements; i++) {
        printf("%d\n", array[i]);
    }
}
