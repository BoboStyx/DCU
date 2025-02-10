#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list matrix
typedef struct Node {
    int value;
    struct Node* right; // Pointer to the next element in the row
    struct Node* down;  // Pointer to the next element in the column
} Node;

// Helper function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->right = NULL;
    newNode->down = NULL;
    return newNode;
}

// Function to create a linked list matrix from a 2D array
Node* createMatrix(int rows, int cols, int data[rows][cols]) {
    Node* head = NULL;
    Node* rowHeads[rows];
    Node* prevRow[cols];
    
    for (int i = 0; i < rows; i++) {
        Node* prev = NULL;
        for (int j = 0; j < cols; j++) {
            Node* newNode = createNode(data[i][j]);
            if (prev == NULL) {
                rowHeads[i] = newNode; // Start of the row
            } else {
                prev->right = newNode; // Link the previous node in the row
		}
 if (i == 0) {
                prevRow[j] = newNode; // Store the first row's nodes
            } else {
                prevRow[j]->down = newNode; // Link the above node in the column
                prevRow[j] = newNode; // Update the previous row pointer
            }
            prev = newNode;
        }
    }
    head = rowHeads[0];
    return head;
}

// Function to get a value at a specific position (row, col)
int getValue(Node* head, int row, int col) {
    Node* current = head;
    for (int i = 0; i < row; i++) {
        current = current->down;
    }
    for (int j = 0; j < col; j++) {
        current = current->right;
    }
    return current->value;
}

// Function to perform matrix multiplication
Node* multiplyMatrices(Node* head1, int rows1, int cols1, Node* head2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Matrix dimensions do not match for multiplication\n");
        return NULL;
    }

    int resultData[rows1][cols2];
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            resultData[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                resultData[i][j] += getValue(head1, i, k) * getValue(head2, k, j);
            }
        }
    }
    return createMatrix(rows1, cols2, resultData);
}

// Function to display a linked list matrix
void displayMatrix(Node* head) {
    Node* rowHead = head;
    while (rowHead) {
        Node* current = rowHead;
        while (current) {
            printf("%d ", current->value);
            current = current->right;
        }
        printf("\n");
        rowHead = rowHead->down;
    }
}

// Example usage
int main() {
    int matrix1Data[2][2] = {
        {1, 2},
        {3, 4}
    };
    int matrix2Data[2][2] = {
        {5, 6},
        {7, 8}
    };

    Node* matrix1 = createMatrix(2, 2, matrix1Data);
    Node* matrix2 = createMatrix(2, 2, matrix2Data);

    printf("Matrix 1:\n");
    displayMatrix(matrix1);

    printf("\nMatrix 2:\n");
    displayMatrix(matrix2);

    Node* result = multiplyMatrices(matrix1, 2, 2, matrix2, 2, 2);

    printf("\nResultant Matrix:\n");
    displayMatrix(result);

    return 0;
}

