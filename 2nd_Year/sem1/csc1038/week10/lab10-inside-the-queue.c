#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAfter(struct Node *head, int target, int newValue) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->value == target) {
            struct Node* newNode = createNode(newValue);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
}

void displayList(struct Node *head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
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

    int values[] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
    int n = sizeof(values) / sizeof(values[0]);

    int target = atoi(argv[1]);
    int newValue = atoi(argv[2]);

    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        insertNode(&head, values[i]);
    }

    insertAfter(head, target, newValue);

    displayList(head);

    freeList(head);

    return 0;
}
