
#include "domain.h"
#include <stdio.h>
#include <string.h>

Product createProduct(char name[], char type[], int quantity, char date[])
{
    Product p;
    strcpy(p.name, name);
    strcpy(p.type, type);
    p.quantity = quantity;
    strcpy(p.date, date);
    return p;
}

char* getName(Product* p)
{
    return p->name;
}

char* getType(Product* p)
{
    return p->type;
}

int getQuantity(Product* p)
{
    return p->quantity;
}

char* getDate(Product* p)
{
    return p->date;
}

void assign_values(Product* new_product, Product p)
{
    strcpy(new_product->name, p.name);
    strcpy(new_product->type, p.type);
    new_product->quantity = p.quantity;
    strcpy(new_product->date, p.date);
}
