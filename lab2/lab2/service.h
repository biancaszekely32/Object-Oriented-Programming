#pragma once

#include "repo.h"
#include "repo_undo.h"

typedef struct
{
    Repo repo;
    UndoRepo undo_redo;

} Service;

Service* createService(Repo repository, UndoRepo UndoRedo);
//Service* createService(Repository repository);

// With this function we add a new product
void add_product_s(Service* service, char name[], char type[], int quantity, char date[]);

// With this function we delete a product
int delete_product_s(Service* service, char name[], char type[]);

// With this function we update the product's quantity
int update_products_quantity_s(Service* service, char name[], char type[], int quantity);

// With this function we update the product's expiration date
int update_products_expiration_date_s(Service* service, char name[], char type[], char date[]);

// With this function we destroy the created service
void destroy_s(Service* service);

// With this function we sort the array by the name of the products
void sort_function_name(Service* service, Repo* r);

// With this function we sort the array by the quantity of the products
void sort_function_quantity(Service* service, Repo* r);

// With this function we search elements by a given string
void search_elements_by_string_s(Service* service, char string[], Repo* repository);

// With this function we compute the number of days between two different dates
int compute_number_days_between_two_dates(Service* service, char date1[]);

// With this function we create a copy of the repository
void copy_repo_service(Service* service, UndoRepo* UndoRedo);

// With this function we search elements by a given category
int search_elements_by_category_s(Service* service, char string[], Repo* repository, int number_of_days);
