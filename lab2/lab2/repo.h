#pragma once
#include "domain.h"
#include "dynamic-array.h"

typedef struct {
	DynamicArray array;
}Repo;

// With this function we create the repository
Repo* createRepo(DynamicArray arr);

// With this function we check if a product already exists in the array
int check_existence_product(Repo* repo, char name[], char type[]);

// With this function we get the length of the array
int getCount(Repo* R);

// With this function we add a product
void add_product_r(Repo* repo, char name[], char type[], int quantity, char date[]);

// With this function we delete a product
int delete_product_r(Repo* repo, char name[], char type[]);

// With this function we update the product's quantity
int update_products_quantity_r(Repo* repo, char name[], char type[], int quantity);

// With this function we update the product's expiration date
int update_products_expiration_date_r(Repo* repo, char name[], char type[], char date[]);

// With this function we dealloc the space for the repository
void destroy_r(Repo* R);

// With this function we search for products which names contain a given substring
void search_elements_by_string_r(Repo* repo, char string[], Repo* repository);

// With this function we search for elements of a given category
int search_elements_by_category_r(Repo* repo, char string[], Repo* repository);

// With this function we initialize the repository with 10 datas.
void init_repo(Repo* R);

// With this function we duplicate the repository
Repo duplicate_repo(Repo* repo);

// With this function we copy the elements of a repository into another repository
void copy_repo(Repo* repo, Repo new_repo);