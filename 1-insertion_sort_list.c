#include "sort.h"

/**
 * insertion_sort_list - performs insertion sort on a list
 * @list: list to sort
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sort = NULL, *head = NULL, *tar = NULL, *temp = NULL;
	int len, slen = 1, i, j;

	if (list == NULL || *list == NULL)
		return;
	sort = *list;
	while (sort->prev != NULL)
		sort = sort->prev;
	if (sort->next == NULL)
		return;
	head = sort->next, temp = sort->next;
	for (len = 0; temp != NULL; len++)
		temp = temp->next;
	for (i = 0; i < len; i++, slen++)
	{
		tar = head, temp = sort;
		head = head->next;
		for (j = 1; j < slen && temp->n < tar->n; j++)
			temp = temp->next;
		if (tar->next)
			tar->next->prev = tar->prev;
		if (tar->prev)
			tar->prev->next = tar->next;
		tar->prev = NULL, tar->next = NULL;
		if (tar->n < temp->n)
		{
			if (temp->prev)
				temp->prev->next = tar, tar->prev = temp->prev;
			else
				sort = tar, *list = tar;
			temp->prev = tar, tar->next = temp;
		}
		else
		{
			tar->next = temp->next, tar->prev = temp, temp->next = tar;
			if (tar->next)
				tar->next->prev = tar;
		}
		print_list(*list);
	}
}
