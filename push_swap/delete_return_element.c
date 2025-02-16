#include "push_swap.h"

st_stack	*delete_return_element(st_stack **head, char element)
{
	st_stack	*temp;

	if (!head || !(*head))
		return (NULL);
	if (element == 'f')
	{
		temp = *head;
		*head = (*head)->next;
	}
	else
	{
		temp = last_node(*head);
		befor_last_node(*head)->next = NULL;
		 
	} 
	return (temp);
}
