#include <stdlib.h>
#include <math.h>
#include "search.h"

skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *list = NULL, *node = NULL, *prev = NULL;
	size_t i, step;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		node = malloc(sizeof(skiplist_t));
		if (!node)
			return (NULL);
		node->n = array[i];
		node->index = i;
		node->next = NULL;
		node->express = NULL;

		if (!list)
			list = node;
		else
			prev->next = node;

		prev = node;
	}

	/* Create express lane */
	step = sqrt(size);
	node = list;
	for (i = 0; node; i++)
	{
		skiplist_t *jump = node;
		size_t j;

		for (j = 0; j < step && jump; j++)
			jump = jump->next;

		if (jump)
			node->express = jump;

		node = node->next;
	}
	return (list);
}
