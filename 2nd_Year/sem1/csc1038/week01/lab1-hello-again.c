/*
Program: lab1-hello_again.c
Author: Seyi Adu
Input: A full name
Output: Print out the given name
*/


#include <stdio.h>
#include <stdlib.h> /* a header file with a function we might need */

int main(int argc, char * argv[])
{
   printf("Hello %s\n", argv[1]);
   return(0);
}
