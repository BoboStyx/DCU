/*
Author: Seyi Adu
Program: lab6-find-country.c
Input: The detail of a list of countries from the command line as follows: - Name - Capital - Population (in million) - Size (in km2) e.g Ireland Dublin 4.99 84421
Output: The first line shows the header which include each information separated by three tab characters. The following lines show each corresponding data for each input country, separated by three tab characters .
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

void desc(Country *, int length);

int main(int argc, char * argv[]){

	printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

	int length = argc - 1;
	Country country[length / 4];
	int j = 1;
	for (int i = 0; i  < length; i++){
		int ccount = i / 4;
		if (j == 1){
			strncpy(country[ccount].name, argv[i + 1], sizeof(country[ccount].name) - 1);
		}
		if (j == 2){
			strncpy(country[ccount].capital, argv[i + 1], sizeof(country[ccount].capital) - 1);
		}
		if (j == 3){
			country[ccount].population = atof(argv[i + 1]);
		}
		if (j == 4){
			country[ccount].size = atoi(argv[i + 1]);
			j = 0;

		}
		j++;
	}
	desc(country, length);
	for (int i = 0; i < length / 4; i++){
		printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country[i].name, country[i].capital, country[i].size, country[i].population);
	}
	return 0;
}

void desc(Country *country, int length){
	Country tmp;
	for (int i = 0; i < length / 4; i++){
 		for (int j = 0; j < length / 4 - i; j++){
 			if (country[j].population < country[j + 1].population){
 				tmp = country[j];
 				country[j] = country[j + 1];
 				country[j + 1] = tmp;
 				}
		}
	}
}
