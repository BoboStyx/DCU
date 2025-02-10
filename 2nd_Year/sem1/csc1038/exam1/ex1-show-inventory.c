/*
Author: Seyi Adu
Program: ex1-show-inventory.c
Date: 31/10/2024
Input: Arguments from command line consisting of Product Name(Maximum of 20 characters), Stock (unsigned integer representing the number of items available), Price(floating point number representing cost), Discount(binary value , 1=Discount Availble, 0=No Discount) e.g "Laptop" 15 800.00 1 "Keyboard" 50 20.99 0 "Mouse" 30 15.00 1
Output: The information for each item in a single line followed by newline character. e.g
Laptop,15,800.00,Discounted
Keyboard,50,20.99,No Discount
Mouse,30,15.00,Discounted
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
void PrintProduct(Product p[], int NumberOfProducts);

/*
Function: Main
Parameters: int argc (argument count from command line), char* argv[](An array of command-line arguments).
Description: Declares struct and Number of products then calls AddProduct function and PrintProduct function.
*/
int main(int argc, char* argv[]){
	Product product[50];//Declare a maximum of 50 products.
	int NumberOfProducts = (argc - 1) / 4;//Number of products is number of arguments, excluding the program call, divided by 4 as each product is grouped in 4's.
	AddProduct(product, argc, argv);//Call AddProduct function.
	PrintProduct(product, NumberOfProducts);//Call PrintProduct function.
	
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
Function: PrintProdunct
Parameters: Product p[](A list of type Product), int NumberOfProducts(Number of how many products)
Description: Prints the products information followed by a newline
*/
void PrintProduct(Product p[], int NumberOfProducts){
	char* discounted = "";//Declare discounted as an empty string
	for(int i = 0; i < NumberOfProducts; ++i){	
		if (p[i].discount == 1){
			discounted = "Discounted";//Change string to discount if discount is applicable
		}
		else if (p[i].discount == 0){
			discounted = "No Discount";//Change string to No Discount if discount is not applicable
		}
		printf("%s,%d,%.2f,%s\n", p[i].name, p[i].stock, p[i].price, discounted);//Print the name of the product, number of stock, price of product (rounded to two decimals), and whether product is discounted or not
	}
}
