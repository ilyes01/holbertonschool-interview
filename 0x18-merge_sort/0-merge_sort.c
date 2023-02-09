#include "sort.h"

/**
 * merge - merge two sorted subarrays into a single sorted array
 * @array: array of table
 * @temp: temporary array used for merging
 * @left: start index of the left subarray
 * @mid: end index of the left subarray and start index of the right subarray
 * @right: end index of the right subarray
 * Return: void
 */
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	i = left;
	j = mid;
	k = 0;
	while (i < mid && j < right)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j < right)
		temp[k++] = array[j++];
	for (i = left, k = 0; i < right; i++)
		array[i] = temp[k++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * divide_array - divide the array into smaller subarrays
 * @array: array of the table
 * @temp: temporary array used for merging
 * @left: start index of the subarray
 * @right: end index of the subarray
 * Return: void
 */
void divide_array(int *array, int *temp, int left, int right)
{
	int mid;

	if (right - left > 1)
	{
		mid = (right + left) / 2;
		divide_array(array, temp, left, mid);
		divide_array(array, temp, mid, right);
		merge(array, temp, left, mid, right);
	};
}

/**
 * merge_sort - sort an array using the merge sort algorithm
 * @array: array of table
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2 || array == NULL)
		return;
	temp = malloc(sizeof(int) * size);
	divide_array(array, temp, 0, size);
	free(temp);
}
