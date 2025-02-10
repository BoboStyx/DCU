#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("studentBinary.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (1) {
        int name_length;
        if (fread(&name_length, sizeof(int), 1, file) != 1) break;

        char *name = (char *)malloc(name_length + 1);
        if (name == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        fread(name, sizeof(char), name_length, file);
        name[name_length] = '\0';  // Null-terminate the string

        int college_length;
        fread(&college_length, sizeof(int), 1, file);

        char *college = (char *)malloc(college_length + 1);
        if (college == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        fread(college, sizeof(char), college_length, file);
        college[college_length] = '\0';  

        int age;
        fread(&age, sizeof(int), 1, file);

        float grade;
        fread(&grade, sizeof(float), 1, file);

        printf("Name: %s\n", name);
        printf("College: %s\n", college);
        printf("Age: %d\n", age);
        printf("Grade: %.2f\n", grade);

        free(name);
        free(college);
    }

    fclose(file);

    return 0;
}
