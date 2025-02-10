/*
 lab1-convert-units.c
 author Seyi Adu
 */

#include <stdio.h>
#include <stdlib.h>


/* Function: Main
 parameters: int argc (argument count)
 char *argv[] an array of command-line arguments
description:  Converts centimetres to inches
 */

int main(int argc, char *argv[])
{
/* variable initialisation */
	int centimetres = 0;
	float inches = 0.0;
/* all command-line arguments come in as character strings, so atoi turns them into ints*/
	centimetres = atoi(argv[1]);

	inches  = centimetres / 2.54; /*conversion of centimetres to inches */

    /* print to two decimal places*/
    printf ("%.2f\n", inches); 
    return (0); /* exit correctly*/
} /* end */ 


