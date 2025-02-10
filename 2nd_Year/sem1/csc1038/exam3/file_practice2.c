#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

int main() {
    FILE *file;
    Employee emp = {1, "John Doe", 55000.5};

    // Writing to a binary file
    file = fopen("employee.dat", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fwrite(&emp, sizeof(Employee), 1, file);
    fclose(file);

    // Reading from the binary file
    file = fopen("employee.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    Employee readEmp;
    fread(&readEmp, sizeof(Employee), 1, file);
    fclose(file);

    printf("ID: %d, Name: %s, Salary: %.2f\n", readEmp.id, readEmp.name, readEmp.salary);

    return 0;
}

