/*
Author: Seyi Adu
Program: lab3-leap-year.c
Input: Two numbers from command line range of two years
Output: The leap years including and in between this range
*/

#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year) {
    // A year is a leap year if:
    // It is divisible by 4 AND (not divisible by 100 OR divisible by 400)
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // true
    }
    return 0; // false
}

int main(int argc, char *argv[]) {
    // Check if two arguments are passedd
    if (argc != 3) {
        printf("Two arguments needed");
        return 1;
    }

    int start_year = atoi(argv[1]);
    int end_year = atoi(argv[2]);

    // Loop through the range and print leap years
    for (int year = start_year; year <= end_year; year++) {
        if (isLeapYear(year)) {
            printf("%d\n", year);
        }
    }

    return 0;
}
