#include <stdio.h>
#include "search.h"

void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *node;

	printf("List :\n");
	for (node = list; node; node = node->next)
		printf("Index[%lu] = [%d]\n", node->index, node->n);

	printf("\nExpress lane :\n");
	for (node = list; node; node = node->express)
		printf("Index[%lu] = [%d]\n", node->index, node->n);
	printf("\n");
}
