#pragma once
#include "domain.h"
#include "repo.h"
#include "service.h"
#include <stdio.h>

typedef struct
{
    Service service;
} Console;


//  With this function we create the console
Console* createConsole(Service service);

// With this function we destroy the console
void destroy_ui(Console* console);

// With this function we display all the products
void display_products_ui(Console* console);

// With this function we add a product
void add_product_ui(Console* console);

// With this function we delete a product
void delete_product_ui(Console* console);

// With this function we update the expiration date of a product
void update_products_expiration_date_ui(Console* console);

// With this function we update the quantity of a product
void update_products_quantity_ui(Console* console);

// With this function we search for products which contain in their name a given string
void search_elements_by_string_ui(Console* console);

// With this function we display the products of a given category
void display_products_by_category(Console* console);

// With this function we execute an undo operation
void undo_ui(Console* console);

// With this function we execute a redo operation
void redo_ui(Console* console);

// With this function we display the commands available in the program
void menu(Console* console);

// With this function we start the program
void start(Console* console);