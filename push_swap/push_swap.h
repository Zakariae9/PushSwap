# ifndef	PUSH_SWAP_H
#define		PUSH_SWAP_H

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

typedef struct	list
{
	int			me;
	int			cost;
	int			index;
	int			is_up;
	int			data;
	int			rank;
	struct list	*next;
	struct list	*target;
} st_stack;

st_stack	*new_node(int data);
void	add_node_front(st_stack **head, st_stack *new_node);
int		length_stack(st_stack *head);
st_stack	*last_node(st_stack *head);
void	add_node_back(st_stack **head, st_stack *new);
void	swap2top_elements(st_stack **head);
void	sa(st_stack **head, int print);
void	sb(st_stack **head, int print);
void	ss(st_stack **a, st_stack **b);
st_stack	*delete_return_element(st_stack **head, char element);
void	pop_then_push(st_stack **node_fill, st_stack **node_empty, char type, char ele);
void	pb(st_stack **b, st_stack **a, int print);
void	pa(st_stack **a, st_stack **b, int print);
void	rb(st_stack **head, int print);
void	ra(st_stack **head, int print);
void	rr(st_stack **a, st_stack **b);
st_stack	*befor_last_node(st_stack *head);
void	rra(st_stack **head, int print);
void	rrb(st_stack **head, int print);
void	rrr(st_stack **a, st_stack **b);
int 	is_olny_numbers(char *str);
int		is_operation_wrong(char *str);
int		is_num_duplicate(char **str);
int		is_outside_range(char *str);
int		is_input_correct(char *str);
int		is_input_correct1(char **str, int words_num);
void	free_(char **str, int rows);
int		rows(char **s);
int	is_num_duplicate1(char **str);
int	expected_pos(st_stack *head, int data);
void	swap_first_with_nodepos(int	pos, st_stack **head);
void    rank_list(st_stack **head);
void    push_a_to_b(st_stack **a, st_stack **b);
void    set_up_or_down(st_stack **head);
void	sort_2elements(st_stack **head);
void	sort_3elements(st_stack **head);
void    turck_algo(st_stack **a, st_stack **b);
void    set_pos_all_elementes(st_stack **a, st_stack **b);
void    set_up_or_down(st_stack **head);
void    indexing_stacks(st_stack **a, st_stack **b);
void    indexing_list(st_stack **head);
void    set_targets(st_stack **a, st_stack **b);
void    set_target(st_stack **a, st_stack **node_than_b);
void    set_cost(st_stack *a, st_stack **b);
void    all_process_to_pa(st_stack **a, st_stack **b, st_stack *node);
st_stack    *set_less_cost(st_stack **b);
int less_cost(st_stack *head);
void    make_nodes_up_top(st_stack **a, st_stack **b, st_stack *cheapest);
void    make_nodes_down_top(st_stack **a, st_stack **b, st_stack *cheapest);
void    make_node_top_down_wheneed(st_stack **a, st_stack **b, char c);
void    if_they_both_deff_pos(st_stack **a, st_stack **b, st_stack *cheapest);
void    pb_while_a_more3(st_stack **a, st_stack **b);
void    rank_list(st_stack **head);
int are_inputs_correct(int ac, char **av, st_stack **head);
void	fill_stack(st_stack **a, char **str, char c);
int	is_list_ordered(st_stack *head);
long long	ft_atoi(const char *nptr);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int larger_num_at_stack(st_stack *head);
void	free_stack(st_stack	*list);

#endif