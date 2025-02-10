/*
Author: Seyi Adu
Program: lab6-find-country.c
Input: The detail of a list of countries from the command line as follows:<country1> <city1> <size1> <city2> <size2> <city3> <size3> <country2>... and so on e.g Ireland Dublin 117.8 Cork 187 Galway 54.2 France Paris 105.4 Marseille 240.6 Lyon 47.87 Spain Madrid 604.3 Barcelona 101.4 Sevilla 140
Output: The program find the largest city of all countries and display the result. e.g Ireland: Cork
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Country Country;
typedef struct City City;
int maxcity (City *);

struct City{
	char name[30];
	float size;
};

struct Country{
	char name[30];
	City city[3];
};

int main(int argc, char * argv[]){

	int cities = 0;
	int length = argc - 1;
	Country country[length / 7];
	for (int i = 0; i  < length / 7; i++){

		strncpy(country[i].name, argv[7 * i + 1], sizeof(country[i].name) - 1);
		cities = 0;
		for (int j = 0; j < 5; j++){
			if (j % 2 == 0){
				strncpy(country[i].city[cities].name, argv[7 * i + j + 2], sizeof(country[i].city[cities].name) - 1);
			}
			else{
				country[i].city[cities].size = atof(argv[7 * i + j + 2]);
				cities++;
			}
		}

		cities = maxcity(country[i].city);
		printf("%s: %s\n", country[i].name, country[i].city[cities].name);
	
	}
	return 0;
}

int maxcity(City *city){
	int max = 0;
	int index = 0;
	for (int i = 0; i < 3; i++){
		if (max < city[i].size){
			max = city[i].size;
			index = i;
		}
	}
	return index;
}
