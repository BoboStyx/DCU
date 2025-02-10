/*
Author: Seyi Adu
Program: lab1-circle-area-further.c
Input: Radius
Output: Area
*/


#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415


int main(int argc, char *argv[])
{
	if(argc < 2){
            return (0);
}
	int radius = 0;
	float area = 0.0;
	radius = atoi(argv[1]);
	if (radius < 0){
		printf("Radius cannot be below 0. Invalid Input. Rerun program.\n");
		return(0);/* close program as a negative number cannot be given as input for a radius */
	}
	else{
	radius = radius*radius;

	area  = radius*PI; 

    printf ("%.2f\n",area); /* We only want to show only two values to the right of the decimal point*/
	}

    return (0); /* exit correctly*/
} /* end program*/
