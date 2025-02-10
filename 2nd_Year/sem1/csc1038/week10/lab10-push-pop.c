#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node **head, int value) {
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

void pop(struct Node **head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
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

    for (int i = 2; i < n + 2; i++) {
        int value = atoi(argv[i]);
        push(&head, value);
    }

    pop(&head);
    pop(&head);

    int pushValue1 = atoi(argv[n + 2]);
    int pushValue2 = atoi(argv[n + 3]);
    push(&head, pushValue1);
    push(&head, pushValue2);

    displayList(head);

    freeList(head);

    return 0;
}
