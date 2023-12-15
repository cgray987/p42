

#include "list.h"

void	swap(t_list *a, t_list *b)
{
	int swap;

	swap = a->data;
	a->data = b->data;
	b->data = swap;
}


t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *current;
	int swapped = 1;

	current = lst;
	while (swapped == 1)
	{
		swapped = 0;
		while (current != 0 && current->next != 0)
		{
			if (cmp(current->data, current->next->data) == 0)
			{
				swap(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
		current = lst;
	}
	return (lst);
}
