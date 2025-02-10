/*
Author: Seyi Adu
Program: is-symmetric.c
Input: String
Output: Print yes or no
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	char *word = argv[1];
	int length = strlen(word);
	for (int i = 0; i < length - 1; i++){
		if (word[i] != word[length - i - 1]){
			printf("no\n");
			return 0;
		}
	}
	printf("yes\n");
	return 0;

}
