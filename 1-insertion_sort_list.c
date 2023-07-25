#include "sort.h"

/**
 * swap_node - Swap two nodes in doubly-linked list
 * @h: A pointer to the head of the doubly-linked list.
 * @st_node: first node to swap
 * @nd_node: second node to swap
 */
void swap_node(listint_t **h, listint_t **st_node, listint_t *nd_node)
{
	(*st_node)->next = nd_node->next;
	if (nd_node->next != NULL)
		nd_node->next->prev = *st_node;
	nd_node->prev = (*st_node)->prev;
	nd_node->next = *st_node;

	if ((*st_node)->prev != NULL)
		(*st_node)->prev->next = nd_node;

	else
		*h = nd_node;

	(*st_node)->prev = nd_node;
	*st_node = nd_node->prev;
}

/**
 * insertion_sort_list - Sorts doubly linked list in
 * ascnd order using insertion sort
 * @list: Pointer
 * Description: Prints list after the swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itr, *inrt, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itr = (*list)->next; itr != NULL; itr = tmp)
	{
		tmp = itr->next;
		inrt = itr->prev;

		while (inrt != NULL && itr->n < inrt->n)
		{
			swap_node(list, &inrt, itr);
			print_list((const listint_t *)*list);
		}
	}
}
