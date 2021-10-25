#include "sort.h"

/**
 * bubble_sort - will perform the bubble sort algorithm on an integer array
 * @array: array of integers to sort
 * @size: size of the array
 *
 * Return: doesn't
 */
void bubble_sort(int *array, size_t size)
{
	int j = 0, i = 0;
	int hold = 0;
	int *a = array;

	for (j = size; j > 1; j--)
	{
		for (i = 1; i < j; i++)
			if (a[i - 1] > a[i])
			{
				hold = a[i];
				a[i] = a[i - 1];
				a[i - 1] = hold;
				print_array(array, size);
			}
	}
}
