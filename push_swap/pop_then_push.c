#include "push_swap.h"

// p means push (i use it in push and rra\/) and r rotate^ 

void	pop_then_push(st_stack **node_fill, st_stack **node_empty, char type, char ele)
{
	st_stack	*node;

	node = delete_return_element(node_empty, ele);
	if (node && type == 'p')
		add_node_front(node_fill, node);
	else if (node && type == 'r')
	{
		node->next = NULL;
		add_node_back(node_fill, node);
	}
	else
		return ;
}
