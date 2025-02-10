#include <stdio.h>

int main() {
    FILE *file;

    // Writing to the file
    file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a file example.\n");
    fclose(file);

    // Reading from the file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
	    printf("%s", line);
    }
    fclose(file);

    return 0;
}

