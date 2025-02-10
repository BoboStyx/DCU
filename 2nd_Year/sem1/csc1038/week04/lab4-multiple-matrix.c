/*
Author: Seyi Adu
Program: lab4-multiple-matrix.c
Input: 
Output:
 */

#include <stdio.h>
#include <stdlib.h>

void create_matrix(int n, int m,int matrix[n][m], char *argv[], int *element);
void print_matrix(int n, int m, int matrix[n][m]);
void multiply_matrix(int n, int n2, int m, int m2, int A[n][m], int B[n2][m2], int AB[n][m2]);

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int element = 3;
    int A_matrix[n][m];

    create_matrix(n, m, A_matrix, argv, &element);

    int n2 = atoi(argv[element]);
    element++;
    int m2 = atoi(argv[element]);
    element++;
    int B_matrix[n2][m2];

    create_matrix(n2, m2, B_matrix, argv,&element);

    int AB_matrix[n][m2];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m2; j++){
            AB_matrix[i][j] = 0;
        }
    }
    multiply_matrix(n, n2, m, m2, A_matrix, B_matrix, AB_matrix);
    print_matrix(n, m2, AB_matrix);

    return 0;
}

void create_matrix(int n, int m,int matrix[n][m], char *argv[], int *element){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            matrix[i][j] = atoi(argv[*(element)]);
            (*element)++;
        }
    }
}

void multiply_matrix(int n, int n2, int m, int m2, int A[n][m], int B[n2][m2], int AB[n][m2]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m2; j++){
            for (int k = 0; k < m; k++){
                *(*(AB + i) + j) += (*(*(A + i) + k)) * (*(*(B + k) + j));
            }
        }
    }
}

void print_matrix(int n, int m, int matrix[n][m]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d", matrix[i][j]);
            if (j < m - 1){
                printf(" ");
            }
        }
        printf("\n");
    }
}
