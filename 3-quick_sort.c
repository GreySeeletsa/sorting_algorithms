#include "sort.h"

void swap_int(int *int_one, int *int_two);
int lomuto_part(int *array, size_t size, int start, int end);
void lomuto_sort(int *array, size_t size, int start, int end);
void quick_sort(int *array, size_t size);

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
 * lomuto_part - Order subset of array
 * acc to lomuto partition scheme
 * @array: array of integers
 * @size: size of array
 * @start: Start of index of subset
 * @end: Ending index of subset
 * Return: Final partition index
 */
int lomuto_part(int *array, size_t size, int start, int end)
{
	int *i, up, down;

	i = array + end;
	for (up = down = start; down < end; down++)
	{
		if (array[down] < *i)
		{
			if (up < down)
			{
				swap_int(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *i)
	{
		swap_int(array + up, i);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - Quick sort algorithm through recursion
 * @array: Integers to sort
 * @size: size of array
 * @start: Start of index of array partition
 * @end: End of index of array partition
 * Description: Uses Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int start, int end)
{
	int a;

	if (end - start > 0)
	{
		a = lomuto_part(array, size, start, end);
		lomuto_sort(array, size, start, a - 1);
		lomuto_sort(array, size, a + 1, end);
	}
}

/**
 * quick_sort - Sort array of ints in ascending order using quicksort algorithm
 * @array: integers
 * @size: size of array
 * Description: Uses the Lomuto partition scheme
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
