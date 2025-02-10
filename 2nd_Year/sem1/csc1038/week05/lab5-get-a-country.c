/*
Author: Seyi Adu
Program: lab5-get-a-country.c
Input: The detail of a country from the command line as follows: - Name - Capital - Population (in million) - Size (in km2) e.g Ireland Dublin 4.99 84421
Output: The information of the country line by line in the above order of information.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Country Country;

struct Country{
	char name[30];
	char capital[30];
	float population;
	int size;
};

int main(int argc, char * argv[]){

	Country country;
	strncpy(country.name, argv[1], sizeof(country.name) - 1);
	strncpy(country.capital, argv[2], sizeof(country.capital) - 1);
	country.population = atof(argv[3]);
	country.size = atoi(argv[4]);

	printf("%s\n", country.name);
	printf("%s\n", country.capital);
	printf("%.2f million people\n", country.population);
	printf("%d km2\n", country.size);

	return 0;
}
