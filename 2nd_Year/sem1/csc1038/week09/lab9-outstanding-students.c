#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[20];
    char programme[20];
    float grade;
} Student;


float calculate_average(Student *students, int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += students[i].grade;
    }
    return total / count;
}

void display_outstanding_students(Student *students, int count, float average_grade) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].programme, "CSCE") == 0 && students[i].grade > average_grade) {
            printf("%s, %.2f\n", students[i].name, students[i].grade);
            found = 1;
        }
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

    float average_grade = calculate_average(students, student_count);

    display_outstanding_students(students, student_count, average_grade);
    printf("Average grade: %.2f\n", average_grade);
    free(students);

    return 0;
}
