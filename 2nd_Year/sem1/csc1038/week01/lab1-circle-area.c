


#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415


int main(int argc, char *argv[])
{
	int radius = 0;
	float area = 0.0;
	radius = atoi(argv[1]);

	radius = radius*radius;

	area  = radius*PI; 

    printf ("%.2f\n",area); /* We only want to show only two values to the right of the decimal point*/
 /* We want to set the width of the shown number = 9. If the total number of digits < 9, spaces will be shown before the number*/

    return (0); /* exit correctly*/
} /* end program*/
