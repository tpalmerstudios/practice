/**
 * @file ll.c
 * @brief Linked List implementation
 */

/*
 * project: practice
 * module: Linked List
 * created: 2026-03-10
 * SPDX-License-Identifier: GPL-3.0-or-later
 * author: Tim Palmer
 */

#include "ll.h"
#include <stdlib.h>
#include <string.h>

ctLL_t *
ctListInit (size_t dataSize)
{
	ctLL_t *list = malloc (sizeof (ctLL_t));
	list->first = NULL;
	list->last = NULL;
	list->dataSize = dataSize;
	list->size = 0;
	return list;
}

void
ctListFree (ctLL_t *list)
{
	if (list == NULL) return;
	if (list->first != NULL)
		{
			ctLLNode_t *head = list->first;
			ctLLNode_t *next = head->next;
			size_t i;
			for (i = 0; i < list->size && head != NULL; i++)
				{
					free (head);
					head = next;
					if (head != NULL) next = head->next;
				}
		}
	list->first = NULL;
	list->last = NULL;
	list->dataSize = 0;
	list->size = 0;
	free (list);
}

int
ctListInsertFront (ctLL_t *list, void *data)
{
	if (list == NULL || data == NULL) return -1;
	ctLLNode_t *node = malloc (sizeof (ctLLNode_t));
	if (node == NULL) return -1;
	node->data = malloc (list->dataSize);
	if (node->data == NULL)
		{
			free (node);
			return -1;
		}

	memcpy ((char *) node->data, data, list->dataSize);
	if (list->last == NULL) list->last = node;
	node->next = list->first;
	list->first = node;
	list->size++;
	return 0;
}

int
ctListInsertBack (ctLL_t *list, void *data)
{
	if (list == NULL || data == NULL) return -1;
	ctLLNode_t *node = malloc (sizeof (ctLLNode_t));
	if (node == NULL) return -1;
	node->data = malloc (list->dataSize);
	if (node->data == NULL)
		{
			free (node);
			return -1;
		}

	memcpy ((char *) node->data, data, list->dataSize);
	if (list->first == NULL) list->first = node;
	node->next = NULL;
	if (list->last == NULL)
		{
			list->last = node;
			list->last->next = NULL;
		}
	else
		list->last->next = node;
	list->last = node;
	list->size++;

	return 0;
}

int
ctListRemove (ctLL_t *list, ctLLNode_t *node)
{
	if (list == NULL || node == NULL) return -1;
	void *next = node->next; // Ok if NULL
	ctLLNode_t *current = list->first;
	while (current != NULL)
	{
		if (current->next == node) break;
		current = current->next;
	}
	if (current == NULL) return -1;
	current->next = next;
	free (node->data);
	free (node);
	list->size--;
	return 0;
}
/*
void *ctListPopFront (ctLL_t *list);
void *ctListPopBack (ctLL_t *list);

ctLLNode_t ctListHead (ctLL_t *list);
ctLLNode_t ctListEnd (ctLL_t *list);
ctLLNode_t ctListNext (ctLLNode_t *node);
ctLLNode_t ctListTraverse (ctLL_t *list, size_t index);

void *ctListData (ctLL_t *list);

size_t ctListSize (ctLL_t *list);
int ctListIsEmpty (ctLL_t *list);
*/
