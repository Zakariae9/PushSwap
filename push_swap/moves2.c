#include "push_swap.h"

void	rra(st_stack **head, int print)
{
	pop_then_push(head, head, 'p', 'l');
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(st_stack **head, int print)
{
	pop_then_push(head, head, 'p', 'l');
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(st_stack **a, st_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
		write(1, "rrr\n", 4);
}

void	sa(st_stack **head, int print)
{
	swap2top_elements(head);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(st_stack **head, int print)
{
	swap2top_elements(head);
	if (print)
		write(1, "sb\n", 3);
}
