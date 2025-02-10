/*
Program: lab1-hello-again-further.c
Author: Seyi Adu
Input: A full name
Output: Print out the given name
*/


#include <stdio.h>
#include <stdlib.h> /* a header file with a function we might need */

int main()
{
   char name[30];
   fgets(name, sizeof(name), stdin);
   printf("Hello\n%s\n", name);
   return(0);
}
