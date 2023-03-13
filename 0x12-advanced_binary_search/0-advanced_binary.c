#include "search_algos.h"
#include <stdio.h>

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in array.
 * @value: Value to search for.
 *
 * Return: The index where value is located or -1 if the value is not present
 *         in array or if array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, half;
	int index;

	if (array == NULL)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
		printf("%d%s", array[i], i == size - 1 ? "\n" : ", ");

	if (size == 1 && array[0] != value)
		return (-1);

	half = (size - 1) / 2;
	if (array[half] == value)
	{
		if (array[half - 1] < value)
			return (half);
		return (advanced_binary(array, half + 1, value));
	}
	else if (array[half] > value)
		return (advanced_binary(array, half + 1, value));
	else
	{
		index = advanced_binary(array + half + 1, size - half - 1, value);
		if (index == -1)
			return (-1);
		return (half + 1 + index);
	}
}
