/*
Author: Seyi Adu
Program: Draw Empty Square
Input: Integer taken from command line
Output: Square made of "*"
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int width = atoi(argv[1]);

    /* For the top of the square */
    for (int i = 0; i < width; i++) {
        printf("*");
    }
    printf("\n");

    /* For sides of the square*/
    for (int i = 0; i < width - 2; i++) {
        printf("*"); // Left side
        for (int j = 0; j < width - 2; j++) {
            printf(" "); /* Space in between*/
        }
        printf("*\n"); /*Right side*/
    }

    /*Print the bottom side of the square*/
    if (width > 1) {
        for (int i = 0; i < width; i++) {
            printf("*");
        }
    printf("\n");
    }
    return(0);
} 
