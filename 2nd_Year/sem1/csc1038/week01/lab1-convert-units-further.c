/*
Program: lab1-convert-units.c
Author: Seyi Adu
 */

#include <stdio.h>
#include <stdlib.h>

#define low_end 30
#define high_end 50
/* Function: Main
 parameters: int argc (argument count)
 char *argv[] an array of command-line arguments
description:  Converts centimetres to inches
 */

int main()
{
/* variable initialisation */
	int cm;
	int i = 0;

	/*until i adds nineteen to centimetres*/
	for (cm = low_end; cm < high_end; cm++) {
		float inches  = cm / 2.54; /*conversion of centimetres to inches */

		if (i % 5 == 4) {
			printf("%.2f\n", inches);
		}
    		/* print to two decimal places*/
		else {
    			printf ("%.2f ", inches);
		}
		i++;
   }   	
    return (0); /* exit correctly*/
} /* end */ 


