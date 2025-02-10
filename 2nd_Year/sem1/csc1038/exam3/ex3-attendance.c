/* 
Author: Seyi Adu
Program: ex3-attendance.c
Description: This program calculates whether a student has missed four days or more of class. Outputting a 1 if they have, or a 0 if they haven't. Input is recieved as characters from the command line. Student attendances are strings of P's, A's and Ls. P = Present, A = Absent, L = Late. Four consecutive L's  are counted as an absence.

Input: PAPPLPLA PPLLLPPPAPPPA ...
Output: 0\n 1\n ...

Approach: The program will read in the input from the command line. I will have Student structs to hold their attendances, and an attendance status that will either be 0 or 1. I will then use a function to retrieve the attendance status for each student. That function will use another function which counts absences and returns the attendance status. If the number of absences is greater than or equal to 4, I will output a 1, otherwise I will output a 0.

Date 18/12/2024
 */

/*Include libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Create Struct*/
typedef struct Student {
    char *attendance;
    int attendanceStatus;
} std;

/*Function Prototypes*/
int countAbsences(char *attendance);
std *getStudents(int n, char **argv);
void attendanceStatus(std *students, int n);

/* Main Function*/
int main(int argc, char *argv[]) {
    // Number of students
    int numStudents = argc - 1;

    // Read in the attendances from the command line
    std *students = getStudents(numStudents, argv);

    // Count the number of absences for each student
    attendanceStatus(students, numStudents);

    // Output the attendance status for each student
    for (int i = 0; i < numStudents; i++) {
        printf("%i\n", students[i].attendanceStatus);
    }

    // Free the memory
    free(students);
    students = NULL;

    return 0;
}

// Function Definitions
std *getStudents(int n, char **argv) {
    // Allocate memory for the students
    std *students = calloc(n, sizeof(std));
    // Check if memory was allocated successfully
    if (!students) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    // Read in the attendances
    for (int i = 0; i < n; i++) {
        students[i].attendance = argv[i + 1];
    }
    // Return the students
    return students;
}

// Gets the attendance status of each student
void attendanceStatus(std *students, int n) {
    // Iterate through the students
    for (int i = 0; i < n; i++) {
        // Get the attendance status of each student
        students[i].attendanceStatus = countAbsences(students[i].attendance);
    }

    return;
}

// Count the number of absences for a student and returns
// their attendance status
int countAbsences(char *attendance) {
    // Variables
    int numAbsences = 0;

    // Count the number of absences
    for (int i = 0; i < strlen(attendance); i++) {
	int numLates = 0;
        // If the student is absent
        if (attendance[i] == 'A') {
            // Increment the number of absences
            numAbsences++;
        // else if the student is late
        } else if (attendance[i] == 'L') {
	    //Check for consecutives lates and update the Absence if equaling 4
            for (int j = i; j < i + 4; j++){
		    if (attendance[j] == 'L'){
			    numLates++;
		    }
		    else{
			    numLates = 0;
		    }
		    if (numLates == 4){
			    numAbsences++;
		    }
	    }
    }
    }
    // Return the attendance status
    if (numAbsences >= 4) {
        return 1;
    } else {
        return 0;
    }

}
