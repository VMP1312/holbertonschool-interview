#include "search_algos.h"

/**
* print_array - printer
* @array: array
* @a: mv aux
* @high: max position
*/

void printer(int *array, int mv, int maxi)
{
	if (mv <= maxi)
	{
		printf(" %d", array[mv]);
		if (mv < (maxi))
			printf(",");
		printer(array, mv + 1, maxi);
	}
}

/**
* advanced_binary - Searches for a value in a sorted array of integers
* @array: array
* @size: size
* @value: value
* Return: Value or -1 if not found
*/
int advanced_binary(int *array, size_t size, int value)
{
	int mini = 0;
	int mv = 0;
	int maxi = (int)size - 1; 
	int half = 0;

	if (array == NULL || size <= 0)
		return (-1);

	while (mini <= maxi)
	{
		half = (((maxi + mini) / 2));

		printf("Searching in array:");
		mv = mini;

		printer(array, mv, maxi);
		printf("\n");

		if (array[half] == value)
		{
			if (array[half - 1] == value)
				maxi = half;
			else
				return (half);
		}
		else if (array[half] < value)
			mini = half + 1;
		else
			if (size % 2 == 0)
				maxi = half - 1;
			else
				maxi = half;
	}
	return (-1);
}
