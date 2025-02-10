/*
Author: Seyi Adu
Program: ex1-max-diff.c
Date: 31/10/2024
Input: Array of integers from command line e.g 8 3 10 2 -4 -6 0 9
Output: The biggest difference possible between numbers i.e 10 -(-6) = 16, the maximum number - the minimum number
 */

/*Include libraries*/
#include <stdio.h>
#include <stdlib.h>

/*Declare max_diff function*/
int max_diff(int *, int);

/*
Function: Main
Parameters: int argc (argument count)
char* argv[] an array of command-line arguments
Description: Declares the length of the list and creates list with integers from argument line.
Calls max_diff function and prints the returned value.
 */
int main(int argc, char* argv[]){
	int length = argc - 1; //The arguments from command line excluding the program call itself, i.e the number of numbers in command line.
	int numbers[100];//Initialise list of integers
	for (int i = 0; i < length; i++){
		numbers[i] = atoi(argv[i + 1]);//Convert command-line arguments to integers
	}
	printf("%d\n", max_diff(numbers, length));//Call max_diff function and print result
	return 0;//Exit program.
}

/*
Function: Max_Diff
Parameters: int* (list of numbers), 
int (length of that list)
Description: Takes the list of integers and finds the smallest and biggest numbers respectively, then from the biggest subtract the smallest number to get the biggest difference possible in that list. Returns the result upon function call.
*/
int max_diff(int* numbers, int length){
	int max = numbers[0];//Take first number as biggest number encountered.
	int min = numbers[0];//Take first number as smallest number encoutered also.
	for (int i = 0; i < length; i++){
		if (max < numbers[i]){
			max = numbers[i];//If current number is bigger than biggest number encountered update smallest number to current number.
		}
		if (min > numbers[i]){
			min = numbers[i];//If current number is smaller than smallest number encountered update smallest number to current number.
		}	
	}
	int result = max - min;//The smallest number in the list subtracted from the biggest number in the list gives us the biggest difference possible in the list.
	return result;//Return the biggest difference possible
}
