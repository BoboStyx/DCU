/*
Author: Seyi Adu
Program: lab1-rugby.c
*/

#include  <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
       int try = 0;
       int conversion = 0;
       int penalty = 0;
       int dropgoal = 0;
       int points = 0;
	
       try = atoi(argv[1]) * 5;
       conversion = atoi(argv[2]) * 2;
       penalty = atoi(argv[3]) * 3;
       dropgoal = atoi(argv[4]) * 3;

       points = try + conversion + penalty + dropgoal;
       printf("%d\n", points);
       return 0;
              
}
