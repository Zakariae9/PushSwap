#include "push_swap.h"

st_stack	*last_node(st_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	add_node_back(st_stack **head, st_stack *new)
{
	st_stack	*last;

	if (!new || !head)
		return ;
	if (!(*head))
	{
		(*head) = new;
		return ;
	}
	last = last_node(*head);
	last->next = new;
}

void	add_node_front(st_stack **head, st_stack *new_node)
{
	if (!head || !new_node)
		return ;
	new_node->next = *head;
	*head = new_node;
}

st_stack	*new_node(int data)
{
	st_stack	*node = NULL;

	node = malloc(sizeof(st_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->rank = 0;
	return (node);
}

st_stack	*befor_last_node(st_stack *head)
{
	st_stack	*temp;

	temp = head;
	if (!head || !head->next)
		return (NULL);
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}
