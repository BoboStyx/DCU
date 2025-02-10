/*
Author: Seyi Adu
Program: Cylinder Area
Input: First argument radius of cylinder Second argument height of cylinder
Output: The area of the cylinder
*/

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415

int main( int argc, char * argv[]){
	if (argc < 2){
	printf("No input given!\n");
	return (0);
	}
	if (argc < 3){
	printf("Two arguments needed!\n");
	return (0);
	}
	if ((atoi(argv[1]) < 0) || (atoi(argv[2]) < 0)){
	printf("The radius or height cannot be negative!\n");
	return (0);
	}
	int radius = atoi(argv[1]);
	int height = atoi(argv[2]);
	float area = 2 * PI * radius * height + 2 * PI * radius * radius;
	printf("%.2f\n", area);
	return (0);

}
