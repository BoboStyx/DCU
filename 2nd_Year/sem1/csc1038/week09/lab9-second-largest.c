/*
Author: Seyi Adu
Program: lab9-second-largest.c
Description: Find the second largest value in the array and print the result up to 1 digit after the decimal point. Note that there can be more than one largest or second-largest elements. 
Input: An array of floats from command line
Output: The second largest number.
 */

#include <stdio.h>
#include <stdlib.h>

void sorting(float*, int);
void create_list(float*, char**, int);
float second_largest(float*, int);

int main(int argc, char* argv[]){
	int length = argc - 1;
	float *list = (float *)malloc((length) * sizeof(float));
	create_list(list, argv, length);
	sorting(list, length);
	printf("%.1f\n", second_largest(list, length));
	free(list);
	return 0;
}

void sorting(float* list, int length){
	float tmp = 0;
	for (int i = 0; i < length; i++){
		for (int j = 0; j < length - i; j++){
			if (list[j] < list[j + 1]){
				tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
		}
	}
}

float second_largest(float* list, int length){
	float result = 0;
	float max = list[0];
	for (int i = 0; i < length; i++){
		if (list[i] != max){
			result = list[i];
			break;
		}
	}
	return result;
}

void create_list(float* list, char** argv, int length){
	for (int i = 0; i < length; i++){
		list[i] = atof(argv[i + 1]);
	}
} 
