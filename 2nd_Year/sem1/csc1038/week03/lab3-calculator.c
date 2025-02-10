/*
Author: Seyi Adu
Program: lab3-calculator.c
Input: the strings "multiply"/"divide" followed by two float numbers
Output: The multiplication or division of the two float numbers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//set up functions and parametes
float multiply(float num1, float num2);
float divide(float num1, float num2);

//main function
int main(int argc, char*argv[]){
	//initialise numbers
	float num1 = atof(argv[2]);
	float num2 = atof(argv[3]);
	//create string and copy the first argument into it
	char operator[8];
	strcpy(operator, argv[1]);
	
	//check whether argument is multiply or divide
	if (strcmp(operator, "multiply") == 0){
		float operation = multiply(num1, num2);
		printf("%f\n", operation);
	}
	else if (strcmp(operator, "divide") == 0){
		//check if the divisor is 0 so that you do not divide on zero
		if (num2 == 0){
			printf("invalid\n");
		}
		else{
			printf("%f\n", divide(num1, num2));
		}
	}
	return (0);
}

float multiply(float num1, float num2){
    //return the multiple of the two numbers	
    return num1 * num2;
}

float divide(float num1, float num2){
   //return the division of the two numbers
   return num1 / num2;
}
