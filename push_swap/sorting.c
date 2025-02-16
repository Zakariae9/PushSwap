#include "push_swap.h"
/*#include "length_stack.c"
#include "pb.c"
#include "pop_then_push.c"
#include "delete_return_element.c"
#include "nodes.c"
#include "rank.c"
#include "pa.c"
#include "ra.c"*/



//#include <stdio.h>
int main()
{
    st_stack *a=NULL, *b =  NULL;
    st_stack *a1= new_node(100);
    st_stack *a2 = new_node(20);
    st_stack *a3=new_node(350);
    st_stack *a4=new_node(30);
    st_stack *a5=new_node(137);

    add_node_back(&a, a1);
    add_node_back(&a, a2);
    add_node_back(&a, a3);
    add_node_back(&a, a4);
    add_node_back(&a, a5);

    push_a_to_b(&a, &b);

   // st_stack *temp = a;
 
    //printf("here1");
    /*while (temp != NULL)
    {
        printf("a->data = %d\n", temp->data);
        temp = temp->next;
    }*/
    //printf("here2");

}