/*
Author: Seyi Adu
Date: 28/11/2024
Program: ex2-array-degree.c
Description: Find the degree of a list of numbers, which is defined as the number of appearances of the most frequent value in the list via having a counting value for each individual number and returning the max of them.
Input: N number of integers from command-line argument. e.g. 4 2 4 2 2 5 6.
Output: The number of appearances of the most frequent value in the list.
*/

/*Include libraries*/
#include<stdio.h>
#include<stdlib.h>

//Define struct
typedef struct Node Node;

//Create Node struct
struct Node{
    int value;
    Node *next;
};


Node* getNode(int length, char*argv[]);//Function to Create a linked list
int getDegree(Node *first, int length);//Get degree of the numbers in linked list


/*
Function: Main
Parameters: int argc(number of arguments from command-line, char* argv[] (arguments from command-line)
Description: Has function calls to create then to return the degree of a created linked list
 */
int main(int argc, char*argv[])
{
    int length = argc - 1;//Length of integers
    Node* first = NULL;//Set up a null node
    first = getNode(length, argv); //Create a linked list
    printf("%d\n", getDegree(first, length));//Print the degree

    return 0;//exit program
}

/*
Function: getNode
Parameters: int length(lenght of list), char*argv(arguments from command-line)
Description: Creates a linked list
 */
Node* getNode(int length, char*argv[])
{
    Node* first = NULL;//Declare head of our linked list
    Node* current = NULL;//Declare a holder of the current node we are looking at
    
    first = (Node*)calloc(1, sizeof(Node));//Dynamic memory allocation
    current = first;//Set current to first value

    for(int i = 0; i < length - 1; ++i)
    {
        current->value = atoi(argv[i+1]);//Set value from command-line
        
        //Check if the last node
        if(i == length - 1){
            current->next = NULL;
        } else {
            current->next = (Node*)calloc(1, sizeof(Node));//Dynamic memory allocation
            current = current->next;
        }        
    }

    return first;
}

/*
Function:
Parameters: Node* first (head of our linked list) ,int length(length of list)
Description: Returns the degree
 */
int getDegree(Node *first, int length)
{
    Node* p = NULL;//Create a 
    int max = 0;//Variable to store the maximum count encountered
    for(p = first; p != NULL; p = p->next)
    {
	Node* tmp = (Node*)malloc(1 * sizeof(Node));//Dynamic memory allocation holder
        int curr = p->value;//To compare numbers to count
	int count = 0;//Initialise count each loop
	for (tmp = p; tmp != NULL; tmp = tmp->next){
		if (curr == tmp->value){
			count += 1;//Increase count if same number
		}
	}
	if (max < count){
		max = count;//Update max if current degree is greater
	}
    }
    return max;//Return degree
}
