#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[20];
    char programme[20];
    float grade;
} Student;

void display_students(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s, ", students[i].name);
        printf("%s, ", students[i].programme);
        printf("%.2f", students[i].grade);
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    int student_count = (argc - 1) / 3;
    int initial_size = 2;

    Student *students = (Student *)malloc(initial_size * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    if (student_count > initial_size) {
        students = (Student *)realloc(students, student_count * sizeof(Student));
        if (students == NULL) {
            printf("Memory reallocation failed.\n");
            return 1;
        }
    }

    for (int i = 0; i < student_count; i++) {
        strncpy(students[i].name, argv[1 + i * 3], 19);
        students[i].name[19] = '\0'; 

        strncpy(students[i].programme, argv[2 + i * 3], 19);
        students[i].programme[19] = '\0'; 
	
        students[i].grade = atof(argv[3 + i * 3]);
    }

    display_students(students, student_count);

    free(students);

    return 0;
}
