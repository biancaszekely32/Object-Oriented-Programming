#pragma once

#include "domain.h"

typedef Product TElem;

typedef struct {
	TElem* data;
	int count;
	int maxLength;
}DynamicArray;

//  With this function we create the dynamic array
DynamicArray* createDynamicArray(int cap);

// With this function we destroy the dynamic array
void destroy(DynamicArray* array);

//  With this function we add a new element to the dynamic array
void addTElem(DynamicArray* array, TElem TElem);

//  With this function we delete an element from the dynamic array
void deleteTElem(DynamicArray* array, int pos);

// With this function we update an element from the dynamic array
void updateTElem(DynamicArray* array, TElem TElem, int pos);