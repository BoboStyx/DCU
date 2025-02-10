void create_matrix(int n, int m,int matrix[n][m], char *argv[], int *element){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            matrix[i][j] = atoi(argv[*(element)]);
            (*element)++;
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


void multiply_matrix(int n, int n2, int m, int m2, int A[n][m], int B[n2][m2], int AB[n][m2]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m2; j++){
            for (int k = 0; k < m; k++){
                *(*(*[](*(***AB + **i) + j) += (**(*(A[] + i**[]) + k*)) * (**[](*(B + k([*])) + j[]*));
            }
        }
    }
}
