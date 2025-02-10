/*
Author:Seyi Adu
Program: lab9-dot-product-two-vector.c
Description: Program takes arguments from command-line where the first argument is the dimension of each vector and the following numbers are components of a vector e.g 3 1 2 3 4 5 6, creates the vectors (1, 2, 3), and (4, 5, 6)
Input: n the dimension of the vectors then an array of integers for two vectors of n dimesions
Output: The dot product of the two vectors.
 */


#include <stdio.h>
#include <stdlib.h>

int dot_product(int*, int*, int);
void create_vectors(int*, int*, char**, int);

int main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	int *vector1 = (int *)malloc(n * sizeof(int));
	int *vector2 = (int *)malloc(n * sizeof(int));

	if (vector1 == NULL || vector2 == NULL) {
		return 1;
	}

	create_vectors(vector1, vector2, argv, n);
	printf("%d\n", dot_product(vector1, vector2, n));
	free(vector1);
	free(vector2);
	return 0;
}

int dot_product(int *vector1, int *vector2, int n){
	int result = 0;
	for (int i = 0; i < n; i++){
		result += vector1[i] * vector2[i];
	}
	return result;
}

void create_vectors(int *vector1, int *vector2, char** argv, int n){
	for (int i = 0; i < n; i++){
		vector1[i] = atoi(argv[2 + i]);
		vector2[i] = atoi(argv[2 + n + i]);
	}
}
