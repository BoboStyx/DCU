/*
Author: Seyi Adu
Program: lab5-sort-numbers.c
Input: A list of numbers from command line and either the string "asc" or "desc" meaning ascending or descending respectively 
Output: The list of numbers sorted in that order
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void asc(int *plist, int);
void desc(int *plist, int);

int main(int argc, char * argv[]){

	char *str = argv[argc - 1];
	int length = atoi(argv[1]);
	int list[length];
	void (*pfunction)(int*, int);

	for (int i = 0; i < argc - 3; i++){
		list[i] = atoi(argv[i + 2]);
	}
	if (strcmp(str, "asc") == 0){
		pfunction = asc;
		pfunction(list, length);
	}

	else if (strcmp(str, "desc") == 0){
		pfunction = desc;
		pfunction(list, length);
	}

	printf("Sorted numbers: ");

	for (int i = 0; i < length - 1; i++){
		printf("%d ", list[i]);
	}

	printf("%d\n", list[length - 1]);

	return 0;
}

void asc(int *plist, int length){

	int tmp;
	for (int i = 0; i < length - 1; i++){
		bool swapped = false;
		for (int j = 0; j < length - i - 1; j++){
			if (plist[j] > plist[j + 1]){
				tmp = plist[j];
				plist[j] = plist[j + 1];
				plist[j + 1] = tmp;
				swapped = true;
			}
		}
		if (!swapped){
			break;
		}
		}
}

void desc(int *plist, int length){
	int tmp;
	for (int i = 0; i < length - 1; i++){
		bool swapped = false;
		for (int j = 0; j < length - i - 1; j++){
			if (plist[j] < plist[j + 1]){
				tmp = plist[j];
				plist[j] = plist[j + 1];
				plist[j + 1] = tmp;
				swapped = true;
		}
	}
	if (!swapped){
		break;
	}
	}
}
