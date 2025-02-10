/*
Author: Seyi Adu
Program: ex3-delete-prime.c
Description: This program accepts a list of positive integer numbers from the command line. After reading all input data, the program finds all prime numbers and delete them from the list. Then the program calculates the average of all the remaining numbers and puts it at the end of the list as a float to the second decimal. Finally the program displays the elemements line by line. If the list is empty after deletion output 0. 
Input: List of numbers from command line e.g. 2 2 3 4 5 6 7 8 9
Output: "4\n6\n8\n9\n6.75\n"
Date: 18/12/2024
 */

#include <stdio.h>
#include <stdlib.h>

/*Node Structure*/
typedef struct Node {
    int data;//Value for current element of linked list
    struct Node* prev;//Value for previous element of linked list
    struct Node* next;// Value fpr next element of linked list
} Node;

/*Function to create a new node*/
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));//Dynamic memory allocation
    newNode->data = data;//Update data
    newNode->prev = NULL;//Default to NULL
    newNode->next = NULL;//Default to NULL
    return newNode;//Return newNode
}

/*Function to insert at the beginning of the list*/
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);//Create a node
    if (*head != NULL) {
        (*head)->prev = newNode;//Set head to have it's prev pointer to the new head node
    }
    newNode->next = *head;//New head points to old head
    *head = newNode;//Refer to new head as head
}

/*Function to insert at the end of the list*/
void insertAtTail(Node** head, int data) {
    Node* newNode = createNode(data);//Create a node
    if (*head == NULL) {
        *head = newNode;//If no head tail is at the head
        return;//Exit function
    }
    Node* temp = *head;//Temporary node to traverse list
    while (temp->next != NULL) {
        temp = temp->next;//Traverse to end of list
    }
    temp->next = newNode;//Last node of list now points to new tail
    newNode->prev = temp;//New tail points back to old tail
}

/*Function to delete a node from the list*/
void deleteNode(Node** head, int key) {
    Node* temp = *head;//Tempory node to traverse the list
    while (temp != NULL && temp->data != key) {
        temp = temp->next;//Traverse till you find the key
    }
    if (temp == NULL) {//Traversed to end of the list and no key
        return;//Exit function as there is no key to delete
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;//Update the previous node to point to node after current node
    } else {
        *head = temp->next; // Update head if the node to delete is the first node
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;//Update the node after current node to point to node previous current node
    }
    free(temp);//Free space
}

/*Function to check if node values are prime*/
void isPrime(Node** head){
	Node* temp = *head;//Temp node
	while (temp != NULL){
		int half = (temp->data / 2);
		int notPrime = 0;//Truth indicator
		for (int i = 2; i < half + 1; i++){
			if (temp->data % i == 0 && temp->data != 2){//If all values before the half mark of the number are not a divisor than the number is prime
				notPrime = 1;
			}
		}
		if (notPrime == 0){
			deleteNode(head, temp->data);//Delete Node if prime number
		}
	       temp = temp->next;// Onto the next node
	}
}
// Function to display the list from the beginning
void displayForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);//Print value with newline
        temp = temp->next;
    }
}


void calculateAverage(Node **head){
	float total = 0;
	int count = 0;
	Node* temp = *head;
	if (temp == NULL){
		printf("0\n");
	}
	else{
	while (temp != NULL){
		total += temp->data;//Update total
		count++;//Increase count of numbers
		temp = temp->next;
	}
	float average = total / count;
	printf("%.2f\n", average);
	}
}

/* Main function to demonstrate the doubly linked list*/
int main(int argc, char *argv[]) {
    /*Variables*/
    Node* head = NULL;
    int first = atoi(argv[1]);

    /*Insert head*/
    insertAtHead(&head, first);

    for (int i = 1; i < argc - 1; i++){
	    int data = atoi(argv[i + 1]);
	    insertAtTail(&head, data);//Insert nodes at bottom of list
    }

    isPrime(&head);//Call isPrime function to update linked list
    displayForward(head);//Call displayForward to print linked list
    calculateAverage(&head);//Call caclculateAverage functiont to print linked list and print the average or 0 if no elements in list
    return 0;//Exit program
}
