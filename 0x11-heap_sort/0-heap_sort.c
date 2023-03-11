#include "sort.h"

/**
 * swap - Swaps two integers in an array
 *
 * @a: The first integer
 * @b: The second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapify - Converts an array to a heap
 *
 * @array: The array to convert
 * @size: The size of the array
 * @index: The root index of the heap
 * @total_size: The total size of the heap
 */
void heapify(int *array, size_t size, int index, size_t total_size)
{
    int max = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < (int)size && array[left] > array[max])
        max = left;

    if (right < (int)size && array[right] > array[max])
        max = right;

    if (max != index)
    {
        swap(&array[index], &array[max]);
        print_array(array, total_size);
        heapify(array, size, max, total_size);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm
 *
 * @array: The array to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;

    for (i = (size / 2) - 1; i >= 0; i--)
        heapify(array, size, i, size);

    for (i = size - 1; i >= 0; i--)
    {
        swap(&array[0], &array[i]);
        if (i != 0)
            print_array(array, size);
        heapify(array, i, 0, size);
    }
}
