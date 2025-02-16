#include "push_swap.h"

void	pa(st_stack **a, st_stack **b, int print)
{
	pop_then_push(a, b, 'p', 'f');
	if (print)
		write(1, "pa\n", 3);
}

void	pb(st_stack **b, st_stack **a, int print)
{
	pop_then_push(b, a, 'p', 'f');
	if (print)
		write(1, "pb\n", 3);
}

void	ra(st_stack **head, int print)
{
	if (!head || !(*head) || !(*head)->next)
		return ;
	pop_then_push(head, head, 'r', 'f');
	if (print)
		write(1, "ra\n", 3);
}

void	rb(st_stack **head, int print)
{
	if (!head || !(*head) || !(*head)->next)
		return ;
	pop_then_push(head, head, 'r', 'f');
	if (print)
		write(1, "rb\n", 3);
}

void	rr(st_stack **a, st_stack **b)
{
	ra(a, 0);
	rb(b, 0);
		write(1, "rr\n", 3);
}
