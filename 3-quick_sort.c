#include "sort.h"

void quick_sort_core(int *a, size_t size, int lo, int hi);
int partition(int *a, size_t size, int lo, int hi);
void swap_a(int *a, size_t size, int *x, int *y);

/**
 * quick_sort - will use the quick sort algorithm on an array
 * @array: array to sort
 * @size: size of array
 *
 * Return: no
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;
	quick_sort_core(array, size, 0, (int)size - 1);
}

/**
 * quick_sort_core - core of quick sort
 * @a: array to sort
 * @size: size of array
 * @lo: low point of partition
 * @hi: hi point of partition
 *
 * Return: nothing
 */
void quick_sort_core(int *a, size_t size, int lo, int hi)
{
	int p;

	if (lo >= 0 && hi >= 0 && lo < hi)
	{
		p = partition(a, size, lo, hi);
		quick_sort_core(a, size, lo, p - 1);
		quick_sort_core(a, size, p + 1, hi);
	}
}

/**
 * partition - will partition an array
 * @a: array to sort
 * @size: size of array
 * @lo: low point of partition
 * @hi: high point of partition
 *
 * Return: pivot index
 */
int partition(int *a, size_t size, int lo, int hi)
{
	int p, i, j;

	p = a[hi];
	i = lo - 1;

	for (j = lo; j <= hi; j++)
		if (a[j] <= p)
		{
			i++;
			if (i != j)
				swap_a(a, size, a + i, a + j);
		}
	return (i);
}

/**
 * swap_a - swaps two numbers in array, prints array
 * @a: array to print
 * @size: size of array
 * @x: first number to swap
 * @y: second number to swap
 *
 * Return: nothing
 */
void swap_a(int *a, size_t size, int *x, int *y)
{
	int hold;

	hold = *x;
	*x = *y;
	*y = hold;
	print_array(a, size);
}
