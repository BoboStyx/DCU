/*
Author: Seyi Adu
Program: lab9-largest-twice.c
Description: Find the largest element which is at least twice as much as at least one number in the array, print the result. Otherwise the program prints 0.
Input: An array of integers
Output: The largest element which is at least twise as much as at least one number. Otherwise print 0.
 */

#include <stdio.h>
#include <stdlib.h>

void sorting(int*, int);
void create_list(int*, char**, int);
int find_largest(int*, int);

int main(int argc, char* argv[]){
	int length = argc - 1;
	int *list = (int* )malloc((length) * sizeof(int));
	create_list(list, argv, length);
	sorting(list, length);
	int result = find_largest(list, length);
	printf("%d\n", result);
	free(list);
	return 0;
}

void sorting(int* list, int length){
	int tmp;
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

void create_list(int* list, char** argv, int length){
	for (int i = 0; i < length; i++){
		list[i] = atoi(argv[i + 1]);
	}
}

int find_largest(int* list, int length){
	for (int i = 0; i < length; i++){
		for (int j = 0; j < length; j++){
			if (list[i] / 2 == list[j] && list[i] % 2 == 0){
				return list[i];
			}
		}
	}
	return 0;
}
