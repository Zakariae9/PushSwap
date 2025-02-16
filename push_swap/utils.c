#include "push_swap.h"

int		length_stack(st_stack *head)
{
	int	counter;
	st_stack	*temp;

	counter = 0;
	temp = head;
	while (temp != NULL)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
}

void	free_stack(st_stack	*list)
{
	st_stack	*current;

	while (list)
	{
		current = list;
		list = list->next;
		free(current);
	}
}