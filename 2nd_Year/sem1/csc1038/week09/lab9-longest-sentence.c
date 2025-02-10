/*
Author:Seyi Adu
Program: lab9-longest-sentence.c
Description: The program finds and prints the longest string(s) line by line.
Input: Array of strings 
Output: Longest string(s) follow by \n
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_max_length(char **strings, int n) {
    int max_length = strlen(strings[0]);
    for (int i = 1; i < n; i++) {
        int length = strlen(strings[i]);
        if (length > max_length) {
            max_length = length;
        }
    }
    return max_length;
}

void print_longest_strings(char **strings, int n, int max_length) {
    for (int i = 0; i < n; i++) {
        if (strlen(strings[i]) == max_length) {
            printf("%s\n", strings[i]);
        }
    }
}

int main(int argc, char* argv[]){
    int n = argc - 1;
    char **strings = (char **)malloc(n * sizeof(char *));
    if (strings == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        strings[i] = (char *)malloc((strlen(argv[i + 1]) + 1) * sizeof(char));
        if (strings[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        strcpy(strings[i], argv[i + 1]);
    }

    int max_length = find_max_length(strings, n);

    print_longest_strings(strings, n, max_length);

    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
