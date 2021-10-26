#include "sort.h"

/**
 * selection_sort - will sort an array with the selection sort algorithm
 * @array: array to sort
 * @size: size of array to sort
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	unsigned int sub = 0, posi = 0;
	int tar = 0, hold;
	int *a = array;

	if (size < 2 || array == NULL)
		return;

	while (sub < size)
	{
		tar = sub;
		hold = a[sub];
		for (posi = sub; posi < size; posi++)
			if (a[posi] < hold && a[posi] < a[tar])
				tar = posi;
		if (a[sub] > a[tar])
		{
			a[sub] = a[tar];
			a[tar] = hold;
			print_array(array, size);
		}
		sub++;
	}
}
