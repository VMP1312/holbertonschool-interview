#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * maximum_heap - Max Heap Algorithm
 * @array: Array
 * @idx: Index
 * @size: Size
 * @len: Length
 */
void maximum_heap(int *array, int idx, int size, int len)
{
	int left = (idx * 2) + 1;
	int right = (idx * 2) + 2;
	int max = idx;


	if (left > 0 && left < len && array[left] > array[max])
		max = left;

	if (right > 0 && right < len && array[right] > array[max])
		max = right;
	if (max != idx)
	{
		swapper(array + max, array + idx);
		print_array(array, size);
		maximum_heap(array, max, size, len);
	}
}

/**
 * swapper - Makes a Swap
 * @i: Swap 1
 * @j: Swap 2
 */
void swapper(int *i, int *j)
{
	*i = (*i) * (*j);
	*j = (*i) / (*j);
	*i = (*i) / (*j);
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: arr of integers to sort
 * @size: Size of the ar
 */
void heap_sort(int *array, size_t size)
{
	int a = size - 1;
	int b = (size / 2) - 1;

	while (b >= 0)
	{
		maximum_heap(array, b, size, size);
		b--;
	}
	while (a > 0)
	{
		swapper(array + a, array);
		print_array(array, size);
		maximum_heap(array, 0, size, a);
		a--;
	}


}