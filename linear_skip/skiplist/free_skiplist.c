#include <stdlib.h>
#include "search.h"

void free_skiplist(skiplist_t *list)
{
	skiplist_t *temp;

	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}
