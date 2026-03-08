/**
 * @file da.c
 * @brief Dynamic Arrays and Stacks
 */

/*
 * project: practice
 * module: Data Structures
 * created: 2026-03-07
 * SPDX-License-Identifier: GPL-3.0-or-later
 * author: Tim Palmer
 */

#include "da.h"
#include <stdlib.h>

struct ctDynamicArray
{
	void **data;
	size_t size;
	size_t capacity;
};
void
ctDynamicArrayInit (ctDynamicArray_t *da, size_t initialCapacity)
{
	if (da == NULL) return;
	if (initialCapacity == 0) initialCapacity++;

	da->data = malloc (initialCapacity * sizeof (*da->data));
	da->size = 0;
	if (da->data == NULL)
		{
			da->capacity = 0;
			return;
		}
	da->capacity = initialCapacity;
}

void
ctDynamicArrayFree (ctDynamicArray_t *da)
{
	if (da == NULL) return;
	free (da->data);
	da->data = NULL;
	da->size = 0;
	da->capacity = 0;
}

int
ctDynamicArrayResize (ctDynamicArray_t *da, size_t newCapacity)
{
	if (da == NULL) return -1;
	void *tmp = realloc (da->data, newCapacity * sizeof (*da->data));
	if (tmp == NULL) return -1;
	da->data = tmp;
	da->capacity = newCapacity;
	// Truncates to smaller sizes
	da->size = da->size > da->capacity ? da->capacity : da->size;
	return 0;
}

int
ctDynamicArrayReserve (ctDynamicArray_t *da, size_t capacity)
{
	if (da == NULL) return -1;
	if (da->capacity >= capacity) return 0;
	void *tmp = realloc (da->data, capacity * sizeof (*da->data));
	if (tmp == NULL) return -1;
	da->data = tmp;
	da->capacity = capacity;
	return 0;
}

int
ctDynamicArrayShrinkToFit (ctDynamicArray_t *da)
{
	if (da == NULL) return -1;
	if (da->capacity == da->size) return 0;
	if (da->size == 0)
	{
		ctDynamicArrayFree (da);
		return 0;
	}
	void *tmp = realloc (da->data, da->size * sizeof (*da->data));
	if (tmp == NULL) return -1;
	da->data = tmp;
	da->capacity = da->size;
	return 0;
}

int
ctDynamicArrayPush (ctDynamicArray_t *da, void *element)
{
	if (da == NULL) return -1;
	if (da->capacity == 0) da->capacity = 1;
	if (da->size == da->capacity)
		if (ctDynamicArrayResize (da, da->capacity * 2) != 0) return -1;
	da->data[da->size] = element;
	da->size++;
	return 0;
}

void *
ctDynamicArrayPop (ctDynamicArray_t *da)
{
	if (da == NULL || da->size == 0) return NULL;
	da->size--;
	void *tmp = da->data[da->size];
	da->data[da->size] = NULL;
	return tmp;
}

void *
ctDynamicArrayGet (const ctDynamicArray_t *da, size_t index)
{
	if (da == NULL || index >= da->size) return NULL;
	return da->data[index];
}

int
ctDynamicArraySet (ctDynamicArray_t *da, size_t index, void *element)
{
	if (da == NULL || index >= da->size) return -1;
	da->data[index] = element;
	return 0;
}

int
ctDynamicArrayInsert (ctDynamicArray_t *da, size_t index, void *element)
{
	if (da == NULL || index > da->size) return -1;
	if (index == da->size)
		{
			if (ctDynamicArrayPush (da, element) != 0) return -1;
			return 0;
		}
	if (da->size == da->capacity)
		if (ctDynamicArrayResize (da, da->capacity * 2) != 0) return -1;
	size_t i;
	for (i = da->size; i > index; i--)
		da->data[i] = da->data[i - 1];
	da->data[index] = element;
	da->size++;
	return 0;
}

void *
ctDynamicArrayRemove (ctDynamicArray_t *da, size_t index)
{
	if (da == NULL || index >= da->size) return NULL;
	void *tmp = da->data[index];
	size_t i;
	for (i = index; i < da->size - 1; i++)
		da->data[i] = da->data[i + 1];
	da->size--;
	da->data[da->size] = NULL;
	return tmp;
}

size_t
ctDynamicArraySize (const ctDynamicArray_t *da)
{
	if (da == NULL) return 0;
	return da->size;
}

size_t
ctDynamicArrayCapacity (const ctDynamicArray_t *da)
{
	if (da == NULL) return 0;
	return da->capacity;
}

void
ctDynamicArrayClear (ctDynamicArray_t *da)
{
	if (da == NULL) return;
	size_t i;
	for (i = 0; i < da->size; i++)
		da->data[i] = NULL;
	da->size = 0;
}
