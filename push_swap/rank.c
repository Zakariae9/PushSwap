#include "push_swap.h"
/*#include "nodes.c"
#include "length_stack.c"
#include "sorting_fundamenals.c"
#include "moves1.c"
#include "moves2.c"
#include "pop_then_push.c"
#include "swap2top_elemenets.c"
#include "delete_return_element.c"*/


void    rank_list(st_stack **head)
{
    int         rank;
    st_stack    *current;
    st_stack    *temp;

    current = *head;
    while (current != NULL)
    {    
        rank = 0;

        temp = *head;
        while (temp != NULL)
        {
            if (current->data > temp->data)
                rank++;
            temp = temp->next;
        }
        current->rank = rank; 
        current = current->next;
    }
}

void    indexing_list(st_stack **head)
{
    st_stack    *helper;
    int         i;

    i = 0;
    helper = *head;
    while (helper != NULL)
    {
        helper->index = i++;
        helper = helper->next;
    }
}

void    indexing_stacks(st_stack **a, st_stack **b)
{
    indexing_list(a);
    indexing_list(b);
}

void    set_up_or_down(st_stack **head)
{
    int         len;
    st_stack    *helper;

    helper = *head;
    len = length_stack(helper) / 2;
    /*if (len % 2 == 0 && len != 0)
    {
        len--;
    }*/
    while (helper != NULL)
    {
        if (helper->index < len)
            helper->is_up = 1;
        else 
            helper->is_up = 0;
        helper = helper->next;
    }
}

void    set_pos_all_elementes(st_stack **a, st_stack **b)
{
    indexing_stacks(a, b);
    set_up_or_down(a);
    set_up_or_down(b);
}

void    pb_while_a_more3(st_stack **a, st_stack **b)
{
    int len;
    len = length_stack(*a);
    rank_list(a);
    while ((len = length_stack(*a)) > 3)
    {
        if ((*a)->rank < (len / 2))
        {
            pb(b, a, 1);
            rank_list(a);
        }
        else
            ra(a, 1);
    }
    sort_3elements(a);
}

int is_there_biggest(st_stack *head, int num)
{
    while (head)
    {
        if (head->data > num)
            return (1);
        head = head->next;    
    }
    return (0);
}
st_stack *min_stack(st_stack *head)
{
    st_stack *min_node;
    int    min;

    min_node = head;
    min = head->data;
    while (head)
    {
        if (min > head->data)
        {
            min = head->data;
            min_node = head;
        }
        head = head->next;  
    }
    return (min_node);
}

int min_num_at_stack(st_stack *head)
{
    int min;

    min = head->data;
    while (head)
    {
        if (min > head->data)
            min = head->data;
        head = head->next;  
    }
    return (min);
}

int min_max_num_in_a(st_stack *a, st_stack *b)
{
    int min_max;

    min_max = INT_MAX;
    if (!is_there_biggest(a, b->data))
        return (min_num_at_stack(a));
    while (a)
    {
        if (b->data < a->data && min_max > a->data)
            min_max = a->data;
        a = a->next;
    }
    return (min_max);
}

void    set_target(st_stack **a, st_stack **node_than_b)
{
    st_stack    *helper;
    int         num;

    helper = *a;
    num = min_max_num_in_a(*a, *node_than_b);
    while (helper)
    {
        if (helper->data == num)
        {
            (*node_than_b)->target = helper;
            return ;
        }
        helper = helper->next;
    }
}

void    set_targets(st_stack **a, st_stack **b)
{
    st_stack    *helper;

    helper = *b;
    while (helper)
    {
        set_target(a, &helper);
        helper = helper->next;
    }    
}

void    set_cost(st_stack *a, st_stack **b)
{
    st_stack    *current;
    int         len_a;
    int         len_b;

    len_a = length_stack(a);
    len_b = length_stack(*b);
    current = *b;
    while (current)
    {
        current->cost = 0;
        if (current->is_up)
            current->cost = current->index;
        else
            current->cost = len_b - current->index;
        if (current->target->is_up)
            current->cost += current->target->index;
        else
            current->cost += (len_a - current->target->index);
        current = current->next;
    }
}

/*void    make_node_top_down_wheneed(st_stack **a, st_stack **b, char c)
{
    if(c == 'u')
    {
        if ((*a)->me)
            rb(b, 1);
        else
            ra(a, 1);
        return ;
    }
    if ((*a)->me)
        rrb(b, 1);
    else
        rra(a, 1);
}*/

void    make_nodes_up_top(st_stack **a, st_stack **b, st_stack *cheapest)
{   
    while ((*b) != cheapest && (*a) != cheapest->target)
	    rr(a, b);
    while ((*b) != cheapest)
	    rb(b, 1);
    while ((*a) != cheapest->target)
	    ra(a, 1);
}

void    make_nodes_down_top(st_stack **a, st_stack **b, st_stack *cheapest)
{
    while ((*b) != cheapest && (*a) != cheapest->target)
	    rrr(a, b);
    while ((*b) != cheapest)
	    rrb(b, 1);
    while ((*a) != cheapest->target)
	    rra(a, 1);
}

void    if_they_both_deff_pos(st_stack **a, st_stack **b, st_stack *cheapest)
{
    while ((*b) != cheapest)
    {
        if (cheapest->is_up)
            rb(b, 1);
        else
            rrb(b, 1);
    }
    while ((*a) != cheapest->target)
    {
        if (cheapest->target->is_up)
            ra(a, 1);
        else
            rra(a, 1);
    }
}

int less_cost(st_stack *head)
{
    int i;

    i = head->cost;
    while (head)
    {
        if (head->cost < i)
            i = head->cost;
        head = head->next;
    }
    return (i);
}

void    final_case(st_stack **a, st_stack **b)
{
    while ((*b)->target != *a)
    {
        if ((*b)->target->is_up)
            ra(a, 1);
        else
            rra(a, 1);
    }
}

void    all_process_to_pa(st_stack **a, st_stack **b, st_stack *node)
{
     if (node->is_up && node->target->is_up)
        make_nodes_up_top(a, b, node);
    else if (node->is_up == 0 && node->target->is_up == 0)
        make_nodes_down_top(a, b, node);
    else
        if_they_both_deff_pos(a, b, node);
    pa(a, b, 1);
}

st_stack    *set_less_cost(st_stack **b)
{
    st_stack    *current;
    st_stack    *less_cost_node;
    int         min;

    min = less_cost(*b);
    current = *b;
    while (current)
    {
        if (current->cost == min)
        {
            current->me = 1;
            current->target->me = 1;
            less_cost_node = current;
            break ;
        }
        current = current->next;
    }
    return (less_cost_node);
}

void    reset_me(st_stack **a, st_stack **b)
{
    st_stack    *current;

    current = *a;
    while (current)
    {
        current->me= 0;
        current = current->next;
    }
    current = *b;
    while (current)
    {
        current->me = 0;
        current = current->next;
    }
}

int larger_num_at_stack(st_stack *head)
{
    int larger;

    larger = head->data;
    while (head)
    {
        if (larger < head->data)
            larger = head->data;
        head = head->next;
    }
    return (larger);
}

int should_up_down(st_stack *head)
{
    int min;

    min = min_num_at_stack(head);
    while (head->data != min)
        head = head->next;
    return (head->is_up);
}

void    check_if_sorted(st_stack **a, int min)
{
    int up_or_down;
    
    set_up_or_down(a);
    up_or_down = should_up_down(*a);
    while ((*a)->data != min)
    {    

        if (up_or_down)
            ra(a, 1);
        else
            rra(a, 1);
    }
}

void set_target_node(st_stack *a, st_stack *b)
{
    st_stack    *target;
    int         best_match;
    st_stack    *current_a;

    current_a = a;
    while (b)
    {
        a = current_a;
        target = min_stack(a);
        best_match = INT_MAX;
        while (a)
        {
            if (b->data < a->data && a->data < best_match)
            {
                target = a;
                best_match = a->data;
            }
            a = a->next;
        }
        b->target = target;
        b = b->next;
    }
}

void    turck_algo(st_stack **a, st_stack **b)
{
    pb_while_a_more3(a, b);
   while (*b)
   {
        reset_me(a, b);
        set_pos_all_elementes(a, b);
        set_target_node(*a, *b);
        set_cost(*a, b);
        all_process_to_pa(a, b, set_less_cost(b));
   }
    indexing_list(a);
    check_if_sorted(a, min_num_at_stack(*a));
}
