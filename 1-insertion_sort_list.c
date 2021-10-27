#include "sort.h"

/**
 * insertion_sort_list - performs insertion sort on a list
 * @list: list to sort
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL, *j = NULL, *i = NULL;
	int b = 1;

	if (!list)
		return;
	head = *list;
	while (head->prev != NULL)
		head = head->prev;
	if (head->next == NULL)
		return;

	while (b)
	{
		b = 0;
		head = *list;
		while (head->prev != NULL)
			head = head->prev;
		i = head;
		j = i->next;
		while (j != NULL)
		{
			if (i->n > j->n)
			{
				node_swap(list, i, j);
				print_list(*list);
				b++;
				break;
			}
			i = j;
			j = j->next;
		}
	}
}

/**
 * node_swap - will swap subsequent nodes in a list
 * @head: pointer to the head of the list
 * @x: first node to swap
 * @y: later node to swap
 *
 * Return: nothing
 */
void node_swap(listint_t **head, listint_t *x, listint_t *y)
{
	listint_t *hx, *hy;

	if (!x || !y || !head)
		return;
	if (*head == x)
		*head = y;

	if (x->next && x->next != y)
		(x->next)->prev = y;
	if (x->prev)
		(x->prev)->next = y;
	if (y->next)
		(y->next)->prev = x;
	if (y->prev && y->prev != x)
		(y->prev)->next = x;
	hy = y->prev;
	hx = x->next;
	y->prev = x->prev;
	x->next = y->next;
	if (hy == x || hx == y)
		y->next = x, x->prev = y;
	else
		y->next = hx, x->prev = hy;
}
