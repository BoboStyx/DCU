/*
Author: Seyi Adu
Program: hailstone.c
Input: Positive integer which we call n
Output: Sequence until equals 1
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
	int number = atoi(argv[1]);
	while (number != 1){
		printf("%d ", number);
		if (number % 2 == 0){
			number = number / 2;
		}
		else if (number % 2 == 1){
			number = number * 3 + 1;	
		}
	}
	printf("%d\n", number);
	return 0;
}
