#include "dynamic-array.h"
#include <stdlib.h>

DynamicArray* createDynamicArray(int cap)
{
    DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
    //be sure that the space was allocated
    if (da == NULL)
        return NULL;

    da->maxLength = cap;
    da->count = 0;

    //allocate space for the elements
    da->data = (TElem*)malloc(cap * sizeof(TElem));
    if (da->data == NULL)
        return NULL;

    return da;
}

void destroy(DynamicArray* array)
{
    if (array == NULL)
        return;

    //free the space allocated for the elements
    free(array->data);
    array->data = NULL;

    //free the space allocated for dynamic array
    free(array);
}

void resize(DynamicArray* array)
{
    array->data = (TElem*)(realloc(array, sizeof(TElem) * array->maxLength * 2));
    array->maxLength = array->maxLength * 2;

}

void addTElem(DynamicArray* array, TElem TElem)
{
    if (array == NULL)
        return;
    if (array->data == NULL)
        return;

    //resize the array if necessary
    if (array->maxLength == array->count)
        resize(array);
    //add the element to the array
    array->data[array->count] = TElem;
    array->count++;
}

void deleteTElem(DynamicArray* array, int pos)
{
    for (int i = pos; i <= array->count - 1; i++)
        array->data[i] = array->data[i + 1];

    array->count--;
}

void updateTElem(DynamicArray* array, TElem TElem, int pos)
{
    array->data[pos] = TElem;
}
