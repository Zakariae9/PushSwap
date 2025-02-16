#include "push_swap.h"

void	swap2top_elements(st_stack **head)
{
	st_stack	*first;
	st_stack	*second;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}
