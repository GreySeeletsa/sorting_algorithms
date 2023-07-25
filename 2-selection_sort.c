#include "sort.h"

/**
 * swap_int - Swap integers in array
 * @int_one: int one
 * @int_two: int two
 */
void swap_int(int *int_one, int *int_two)
{
	int tmp;

	tmp = *int_one;
	*int_one = *int_two;
	*int_two = tmp;
}

/**
 * selection_sort - Sort array of integers in ascending order using
 * selection sort algorithm
 * @array: array of integers
 * @size: size of array
 * Description: Prints array after swap
 */
void selection_sort(int *array, size_t size)
{
	int *m;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		m = array + i;
		for (j = i + 1; j < size; j++)
			m = (array[j] < *m) ? (array + j) : m;

		if ((array + i) != m)
		{
			swap_int(array + i, m);
			print_array(array, size);
		}
	}
}
