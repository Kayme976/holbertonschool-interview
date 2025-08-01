#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array and prints the array.
 * @a: First integer.
 * @b: Second integer.
 * @array: The array to print.
 * @size: Size of the array.
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}

/**
 * sift_down - Maintains the max-heap property by sifting a node down.
 * @array: The array representing the heap.
 * @size: Total size of the array.
 * @start: Root index of the subtree.
 * @end: Last index of the heap.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child, swap_idx;

	while ((child = 2 * root + 1) <= end)
	{
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;

		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		if (swap_idx == root)
			return;

		swap(&array[root], &array[swap_idx], array, size);
		root = swap_idx;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 * @array: The array to sort.
 * @size: Number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;

	if (array == NULL || size < 2)
		return;

	/* Build the max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);

	/* Extract elements from the heap */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		sift_down(array, size, 0, i - 1);
	}
}
