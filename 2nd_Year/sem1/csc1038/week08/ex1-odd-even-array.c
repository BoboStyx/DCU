/*
Author: Seyi Adu
Program: odd-even-array.c
Input: Array of integer numbers.
Output: Sum of all odd numbers, total of all subtracted even numbers from first even number
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
	int length = argc - 1;
	int numbers[50];
	int odd = 0;
	int even = 0;
	for (int i = 0; i < length; i++){
		if (atoi(argv[i + 1]) % 2 == 0){
			even = atoi(argv[i + 1]);
			even = even * 2;
			break;
		}
	}
	for (int i = 0; i < length; i++){
		if (atoi(argv[i + 1]) % 2 == 1){
			odd += atoi(argv[i + 1]);	
		}
		else if (atoi(argv[i + 1]) % 2 == 0){
			even -= atoi(argv[i + 1]);
		}
	}
	printf("%d\n%d\n", odd, even);
	return 0;
}
