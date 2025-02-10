/*
Author: Seyi Adu
Program: lab4-matrix-diagonal-sum.c
Input: First argument is the n x n matrix rest of arguments are elements in the matrix e.g 3 1 2 3 4 5 6 7 8 9
Output: The addition of the matrix diagonally e.g. 15
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int n = atoi(argv[1]);
	int elements_in_matrix = n * n;
	int matrix[n][n];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			matrix[i][j] = atoi(argv[(i * n) + 2 + j]);

		}
	}

	int total = 0;
	for (int i = 0; i < n; i++){
		total += matrix[i][i];

	}
	printf("%d\n", total);

	return(0);
}
