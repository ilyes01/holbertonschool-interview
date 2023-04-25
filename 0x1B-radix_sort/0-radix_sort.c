#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using
 *              the LSD radix sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
    int *tmp, *bucket;
    size_t i, j, k, exp;

    if (!array || size < 2)
        return;

    tmp = malloc(size * sizeof(*tmp));
    if (!tmp)
        return;

    bucket = malloc(10 * sizeof(*bucket));
    if (!bucket)
    {
        free(tmp);
        return;
    }

    for (exp = 1, k = 0; k < 10; ++k, exp *= 10)
    {
        memset(bucket, 0, 10 * sizeof(*bucket));

        for (i = 0; i < size; ++i)
            ++bucket[(array[i] / exp) % 10];

        for (i = 1; i < 10; ++i)
            bucket[i] += bucket[i - 1];

        for (i = size - 1; i != (size_t)(-1); --i)
        {
            j = (array[i] / exp) % 10;
            tmp[--bucket[j]] = array[i];
        }

        memcpy(array, tmp, size * sizeof(*array));
        print_array(array, size);
    }

    free(bucket);
    free(tmp);
}

