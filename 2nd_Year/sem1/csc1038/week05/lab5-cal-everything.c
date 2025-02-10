/*
Author: Seyi Adu
Program: lab5-cal-everything.c
Input: Two integers e.g. 10 2
Output: Sum, difference, product, division, power and natural logarithm (log(a) + log(b)) of the two numbers. e.g. 12.00, 8.00, 20.00, 5.00, 100.00, 3.00.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sum(float, float);
float difference(float, float);
float product(float, float);
float division(float, float);
float power(float, float);
float natural_logarithm(float, float);

int main(int argc, char*argv[]){
	float num1 = atof(argv[1]);
	float num2 = atof(argv[2]);
	float (*pfunction)(float, float);
	
	pfunction = sum;
	printf("%.2f\n", pfunction(num1, num2));
	
	pfunction = difference;
	printf("%.2f\n", pfunction(num1, num2));

	pfunction = product;
	printf("%.2f\n", pfunction(num1, num2));

	pfunction = division;
	printf("%.2f\n", pfunction(num1, num2));

	pfunction = power;
	printf("%.2f\n", pfunction(num1, num2));

	pfunction = natural_logarithm;
	printf("%.2f\n", pfunction(num1, num2));

	return 0;
}

float sum(float num1, float num2){
	return num1 + num2;
}

float difference(float num1, float num2){
	return num1 - num2;
}

float product(float num1, float num2){
	return num1 * num2;
}

float division (float num1, float num2){
	return num1 / num2;
}

float power(float num1, float num2){
	int total = 1;
	for (int i = 0; num2 > 0; num2 -= 1){
		total = total * num1;
	}
	return total;
}

float natural_logarithm(float num1, float num2){
	float a = log(num1);
	float b = log(num2);
	return a + b;
}

