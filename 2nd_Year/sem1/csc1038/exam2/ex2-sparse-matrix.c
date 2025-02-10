/*
Author: Seyi Adu
Date: 28/11/2024
Program: ex2-sparse-matrix.c
Description: A program to display a sparse matrix, store its non-zero elements in a linked list,
             and calculate the sum of the main diagonal elements.
Input: Matrix size (rows, columns), number of non-zero elements, and their values with positions.
Output: Full matrix with zeros in appropriate positions and the sum of the main diagonal.
*/

/* Include libraries */
#include <stdio.h>
#include <stdlib.h>

/* Define a node for the linked list */
typedef struct Node {
    int row;               // Row index
    int column;            // Column index
    int value;             // Non-zero value
    struct Node* next;     // Pointer to the next node
} Node;

/* Function to create a new node */
Node* CreateNode(int row, int column, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Allocate memory for a new node
    if (newNode == NULL) {
        return 1;
    }
    newNode->row = row;
    newNode->column = column;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

/* Function to insert a node into the linked list */
void InsertNode(Node** head, int row, int column, int value) {
    Node* newNode = CreateNode(row, column, value);  // Create a new node
    if (*head == NULL) {
        *head = newNode;  // If the list is empty, the new node becomes the head
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {  // Traverse to the end of the list
            temp = temp->next;
        }
        temp->next = newNode;  // Insert the new node at the end
    }
}

/* Function to calculate the sum of the main diagonal */
int CalculateSumDiagonal(Node* head) {
    int sum = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->row == temp->column) {  // Check if the element is on the main diagonal
            sum += temp->value;
        }
     }
    return sum;
}

/* Function to display the full matrix */
void DisplayMatrix(Node* head, int rows, int columns) {
    Node* temp = head;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (temp != NULL && temp->row == i && temp->column == j) {
                printf("%d ", temp->value);  // Print the non-zero value
                temp = temp->next;          // Move to the next node
            } else {
                printf("0 ");  // Print 0 for all unspecified positions
            }
        }
        printf("\n");  // New line at the end of each row
    }
}

/* Main function */
int main(int argc, char* argv[]){
     // Read matrix size and number of non-zero elements
    int rows = atoi(argv[1]);
    int columns = atoi(argv[2]);
    int nonZeroCount = atoi(argv[3]);

    Node* head = NULL;  // Initialize the linked list head to NULL

    // Parse the non-zero elements and insert them into the linked list
    int index = 4;
    for (int i = 0; i < nonZeroCount; i++) {
        int value = atoi(argv[index]);
        int row = atoi(argv[index + 1]);
        int column = atoi(argv[index + 2]);
        InsertNode(&head, row, column, value);
        index += 3;
    }
    DisplayMatrix(head, rows, columns);

    // Calculate and display the sum of the main diagonal
    int diagonalSum = CalculateSumDiagonal(head);
    printf("Sum of main diagonal: %d\n", diagonalSum);

    // Free allocated memory
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
