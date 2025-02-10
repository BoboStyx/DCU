/*
Author: Seyi Adu
Program: is-triangular.c
Input: Integer
Output: is not a triangular number
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int number = atoi(argv[1]);
	int i = 1;
	int increment = 2;
	while (i < number){
		i += increment;
		increment += 1;
	}
	if (i == number){
		printf("%d is a triangular number\n", number);
	}
	else{
		printf("%d is not triangular number\n", number);
	}
	return 0;
}
