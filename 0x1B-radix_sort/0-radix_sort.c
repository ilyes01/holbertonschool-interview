#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: the array of integers to sort
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
    size_t i, exp = 1;
    int max_value = 0;
    int *output = NULL;

    if (array == NULL || size < 2)
        return;

    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    for (i = 0; i < size; i++)
        max_value = array[i] > max_value ? array[i] : max_value;

    while (max_value / exp > 0)
    {
        size_t bucket[10] = {0};

        for (i = 0; i < size; i++)
            bucket[array[i] / exp % 10]++;

        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];

        for (i = size - 1; i < SIZE_MAX; i--)
        {
            output[bucket[array[i] / exp % 10] - 1] = array[i];
            bucket[array[i] / exp % 10]--;
        }

        for (i = 0; i < size; i++)
            array[i] = output[i];

        exp *= 10;
        print_array(array, size);
    }

    free(output);
}

