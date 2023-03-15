#pragma once
#include "repo.h"
#include "domain.h"
#include "dynamic-array.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Repo* createRepo(DynamicArray arr)
{
	Repo* R = (Repo*)malloc(sizeof(Repo));
	//make sure that the space was allocated
	if (R == NULL)
		return NULL;

	R->array = arr;

	return R;
}

int check_existence_product(Repo* repo, char name[], char type[])
{
	for (int i = 0; i < repo->array.count; i++)
		if ((strcmp(repo->array.data[i].name, name) == 0) && (strcmp(repo->array.data[i].type, type) == 0))
			return i;
	return -1;
}

int getCount(Repo* R)
{
	return R->array.count;
}

void add_product_r(Repo* repo, char name[], char type[], int quantity, char date[])
{
	int position;
	position = check_existence_product(repo, name, type);
	if (position == -1)
	{
		Product product;
		product = createProduct(name, type, quantity, date);
		addTElem(&repo->array, product);
	}
	else
	{
		repo->array.data[position].quantity = repo->array.data[position].quantity + quantity;
	}
}

int delete_product_r(Repo* repo, char name[], char type[])
{
	int position;
	position = check_existence_product(repo, name, type);
	if (position == -1)
		return 0;
	else
	{
		deleteTElem(&repo->array, position);
		return 1;
	}
}

int update_products_quantity_r(Repo* repo, char name[], char type[], int quantity)
{
	int position;
	position = check_existence_product(repo, name, type);
	if (position == -1)
		return 0;
	else
	{
		Product p = createProduct(name, type, quantity, getDate(&repo->array.data[position]));
		//repo->array.data[position].quantity = quantity;
		updateTElem(&repo->array, p, position);
		return 1;
	}
}

int update_products_expiration_date_r(Repo* repo, char name[], char type[], char date[])
{
	int position;
	position = check_existence_product(repo, name, type);
	if (position == -1)
		return 0;
	else
	{
		Product p = createProduct(name, type, getQuantity(&repo->array.data[position]), date);
		//strcpy(repo->array.data[position].date, date);
		updateTElem(&repo->array, p, position);
		return 1;
	}
}

void destroy_r(Repo* R)
{
	if (R == NULL)
		return;

	free(R);
}

void search_elements_by_string_r(Repo* repo, char string[], Repo* repository)
{
	string[strlen(string) - 1] = '\0';
	if (strcmp(string, "") == 0)
	{
		for (int i = 0; i < repo->array.count; i++)
			add_product_r(repository, repo->array.data[i].name, repo->array.data[i].type, repo->array.data[i].quantity,
				repo->array.data[i].date);
	}
	else
	{
		for (int i = 0; i < repo->array.count; i++)
			if (strstr(repo->array.data[i].name, string) != NULL)
				add_product_r(repository, repo->array.data[i].name, repo->array.data[i].type, repo->array.data[i].quantity,
					repo->array.data[i].date);
	}

}

int search_elements_by_category_r(Repo* repo, char string[], Repo* repository)
{
	int count = 0;
	for (int i = 0; i < repo->array.count; i++)
		if (strstr(repo->array.data[i].type, string) != NULL)
		{
			count++;
			add_product_r(repository, repo->array.data[i].name, repo->array.data[i].type, repo->array.data[i].quantity,
				repo->array.data[i].date);

		}

	if (count == 0)
	{
		for (int i = 0; i < repo->array.count; i++)
			add_product_r(repository, repo->array.data[i].name, repo->array.data[i].type, repo->array.data[i].quantity,
				repo->array.data[i].date);
	}

	if (count != 0)
		return 1;
	else
		return 0;
}

void init_repo(Repo* R)
{
	add_product_r(R, "Banana", "fruit", 100, "01.04.2023");//16
	add_product_r(R, "Apple", "fruit", 50, "01.04.2022");
	add_product_r(R, "Chicken", "meat", 10, "18.03.2023");
	add_product_r(R, "Pork", "meat", 40, "20.03.2023");
	add_product_r(R, "Chocolate", "sweets", 70, "06.09.2022");
	add_product_r(R, "Cake", "sweets", 124, "18.03.2023");
	add_product_r(R, "Milk", "dairy", 3, "16.06.2022");
	add_product_r(R, "Yogurt", "dairy", 5, "16.06.2023");
	add_product_r(R, "Cherry", "fruit", 150, "01.04.2024");
	add_product_r(R, "Cupcake", "sweets", 70, "18.03.2022");
}

Repo duplicate_repo(Repo* repo)
{
	Repo new_repo;
	new_repo.array.maxLength = repo->array.maxLength;
	new_repo.array.count = repo->array.count;

	new_repo.array.data = (Product*)malloc(new_repo.array.maxLength * sizeof(Product));

	copy_repo(repo, new_repo);
	return new_repo;
}

void copy_repo(Repo* repo, Repo new_repo)
{
	for (int i = 0; i < repo->array.count; i++)
		assign_values(&new_repo.array.data[i], repo->array.data[i]);
}


