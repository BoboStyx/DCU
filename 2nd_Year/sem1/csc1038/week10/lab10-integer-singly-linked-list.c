#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

struct Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
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

    int n = atoi(argv[1]);

    struct Node* head = NULL;

    for (int i = 2; i < argc; i++) {
        int value = atoi(argv[i]);
        insertNode(&head, value);
    }

    displayList(head);

    freeList(head);

    return 0;
}
