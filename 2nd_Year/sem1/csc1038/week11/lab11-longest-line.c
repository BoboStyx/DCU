#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 200

int main() {
    FILE *file = fopen("paragraph.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LENGTH]; 
    char longest_line[MAX_LENGTH] = ""; 
    int longest_length = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        int length = strlen(line);
        if (length > longest_length) {
            longest_length = length;
            strcpy(longest_line, line);
        }
    }

    fclose(file);

    printf("%d\n", longest_length + 1);
    printf("%s\n\n", longest_line);

    return 0;
}

