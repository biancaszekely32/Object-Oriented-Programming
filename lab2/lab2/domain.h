#pragma once


typedef struct
{
	char name[50];
	char type[50];
	int quantity;
	char date[10];
}Product;


// With this function we create a product
Product createProduct(char name[], char type[], int quantity, char date[]);

// With this function we get the name of the product
char* getName(Product* p);

// With this function we get the type of the product
char* getType(Product* p);

// With this function we get the quantity of the product
int getQuantity(Product* p);

// With this function we get the expiration date of the product
char* getDate(Product* p);

// With this function we assign the attributes of a specific product to another new_product
void assign_values(Product* new_product, Product product);





