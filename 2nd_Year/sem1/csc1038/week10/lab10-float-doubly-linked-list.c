#include <stdio.h>
#include <stdlib.h>

struct Node {
    float value;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **head, struct Node **tail, float value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void displayListReverse(struct Node *tail) {
    struct Node* temp = tail;
    while (temp != NULL) {
        printf("%.2f\n", temp->value);
        temp = temp->prev;
    }
}

void freeList(struct Node *head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    if (argc != n + 2) {
        printf("Error: The number of elements does not match the provided list of floating-point numbers.\n");
        return 1;
    }

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 2; i < argc; i++) {
        float value = atof(argv[i]);
        insertNode(&head, &tail, value);
    }

    displayListReverse(tail);

    freeList(head);

    return 0;
}
