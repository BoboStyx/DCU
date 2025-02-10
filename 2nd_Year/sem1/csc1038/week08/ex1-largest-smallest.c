/*
Author: Seyi Adu
Program: largest-smallest.c
Input: string "largest" or "smallest" followed by an array of floats
Output: Corresponding number to respective string
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float smallest(float*, int);
float largest(float*, int);

int main(int argc, char * argv[]){
	int length = argc - 2;
	float (*pfunction)(float*, int);
	char *word = argv[1];
	float numbers[50];
	for (int i = 0; i < length; i++){
		numbers[i] = atof(argv[i + 2]);
	}
	if (strcmp(word, "largest") == 0){
		pfunction = largest;
	}
	else if (strcmp(word, "smallest") == 0){
		pfunction = smallest;
	}
	printf("%.2f\n", pfunction(numbers, length));
	return 0;
}

float smallest(float* numbers, int length){
	float min = numbers[0];
	for (int i = 0; i < length; i++){
		if (numbers[i] < min){
			min = numbers[i];
		}
	}
	return min;
}

float largest(float* numbers, int length){
	float max = numbers[1];
	for (int i = 0; i < length; i++){
		if (max < numbers[i]){
			max = numbers[i];
		}
	}
	return max;
}
