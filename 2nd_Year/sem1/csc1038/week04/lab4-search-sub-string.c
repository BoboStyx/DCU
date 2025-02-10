/*
Author: Seyi Adu
Input: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void SearchString(char *string, char *substr, int len_string, int len_substr);

int main(int argc, char *argv[]){

	char *string = argv[1];
	char *substr = argv[2];

	int len_string = strlen(string);
	int len_substr = strlen(substr);

	SearchString(string, substr, len_string, len_substr);

	return(0);

}

void SearchString(char *string, char *substr, int len_string, int len_substr){
	int i = 0;
	while (i <= len_string - len_substr){
		int j = i;
		int k = 0;
		int count = 0;
		while ((j < i + len_substr) && (string[j] == substr[k])){
			count++;
			k++;
			j++;
		}
		if (count == len_substr){
			printf("%d %d\n", i, j - 1);
		}
		i++;
	}
}
