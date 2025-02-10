/*
Author: Seyi Adu
Program: Day of the week
Input: Number from command line argument
Output: Corresponding day of the week e.g 1 - Sunday, ..., 7 - Saturday
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if exactly one argument is provided
    if (argc != 2) {
        printf("EXACTLY ONE ARGUMENT IS NEEDED!\n", argv[0]);
        return 1;
    }

    // Argument to integer
    int day = atoi(argv[1]);

    // Check if the number is from 1-7
    if (day < 1 || day > 7) {
        printf("Please enter a number between 1 and 7.\n");
        return 1;
    }

    // Print the corresponding day of the week
    switch(day) {
        case 1:
            printf("Sunday\n");
            break;
        case 2:
            printf("Monday\n");
            break;
        case 3:
            printf("Tuesday\n");
            break;
        case 4:
            printf("Wednesday\n");
            break;
        case 5:
            printf("Thursday\n");
            break;
        case 6:
            printf("Friday\n");
            break;
        case 7:
            printf("Saturday\n");
        default:
            printf("Error: Invalid day number.\n");
    }

    return 0;
}
       
