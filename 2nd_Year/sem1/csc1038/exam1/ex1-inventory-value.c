/*
Author: Seyi Adu
Program: ex1-inventory-value.c
Date: 31/10/2024
Input: Arguments from command line consisting of Product Name(Maximum of 20 characters), Stock (unsigned integer representing the number of items available), Price(floating point number representing cost), Discount(binary value , 1=Discount Availble, 0=No Discount) e.g "Laptop" 15 800.00 1 "Keyboard" 50 20.99 0 "Mouse" 30 15.00 1
Output: The information for each item in a single line followed by newline character. e.g Laptop: Discount applies, so value is 15 * 800.00 * 0.9 = 10800.00, etc. i.e output is 15284.00 
*/

/*Include libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define a new type
typedef struct Product Product;

//Define struct
struct Product
{
	char name[20];
	float price;
	unsigned int stock;
	int discount;
};

//Function prototypes
void AddProduct(Product p[], int argc, char*argv[]);
void TotalProducts(Product p[], int NumberOfProducts);

/*
Function: Main
Parameters: int argc (argument count from command line), char* argv[](An array of command-line arguments).
Description: Declares struct and Number of products then calls AddProduct function and TotalProducts function.
 */
int main(int argc, char* argv[]){
	Product product[50];//Declare a maximum of 50 products.
	int NumberOfProducts = (argc - 1) / 4;//Number of products is number of arguments, excluding the program call, divided by 4 as each product is grouped in 4's.
	AddProduct(product, argc, argv);//Call AddProduct function.
	TotalProducts(product, NumberOfProducts);//Call TotalProducts function.
	return 0;//Exit program.
}

/*
Function: AddProduct
Parameters: Product p[](A list of type Product), int argc(argument count from command line), char* argv[](An array of command-line arguments).
Description: Populates attributes of an index/indexes of the list of Type Product
 */
void AddProduct(Product p[], int argc, char*argv[]){
	int NumberOfProducts = (argc - 1)/4;//Number of products.
	int index = 1;//Start at index 1 to avoid encountering program index
	for(int i = 0; i < NumberOfProducts; i++){
		strcpy(p[i].name, argv[index]);//Populates name attribute
		p[i].stock = atoi(argv[index + 1]);//Populates stock attribute
		p[i].price = atof(argv[index + 2]);//Populates price attribute
		p[i].discount = atoi(argv[index + 3]);//Populates discount attribute
		index = index + 4;//Start from name of next prodcut
	}
}

/*
Function: TotalProduncts
Parameters: Product p[](A list of type Product), int NumberOfProducts(Number of how many products)
Description: Gets total of the products prices * their respective stock, also accounts for discount is applicable, in which case the calculation is their stock * their price * .9
 */
void TotalProducts(Product p[], int NumberOfProducts){
	float total = 0;//Declare total equalling 0
	for(int i = 0; i < NumberOfProducts; ++i){
		if (p[i].discount == 1){
			total += p[i].stock * p[i].price * .9;//Update total in case discount is applicable.
		}
		else if (p[i].discount == 0){
			total += p[i].stock * p[i].price;//Update total when discount is not applicable.
		}
	}
	printf("%.2f\n", total);//Print rounded to two decimal places the total for all products.
}
