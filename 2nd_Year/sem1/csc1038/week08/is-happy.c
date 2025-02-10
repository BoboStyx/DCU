#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of the squares of digits of a number
int sum_of_squares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

// Function to check if a number is a happy number
int is_happy(int n) {
    int seen[1000] = {0}; // Array to keep track of numbers we've seen

    while (n != 1 && seen[n] == 0) {
        seen[n] = 1; // Mark this number as seen
        n = sum_of_squares(n);
    }

    return n == 1; // Return true if we reach 1, otherwise false
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    if (is_happy(n)) {
        printf("is happy\n");
    } else {
        printf("not happy\n");
    }

    return 0;
}

