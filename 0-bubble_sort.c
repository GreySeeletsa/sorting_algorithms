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
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: To be sorted
 * @size: Size of array
 * Description: Prints array after its been swapped
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, len = size;
	bool bb = false;

	if (array == NULL || size < 2)
		return;

	while (bb == false)
	{
		bb = true;
		for (a = 0; a < len - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				swap_int(array + a, array + a + 1);
				print_array(array, size);
				bb = false;
			}
		}
		len--;
	}
}
