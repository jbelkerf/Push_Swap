#include "header.h"

int stack_size(t_stack *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}

void sa_or_b(t_stack **a, int option, char stack)
{
    t_stack *tmp;
    if (option == 1)
        printf("s%c\n", stack);
    if (stack_size(*a) < 2)
       return ;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = (*a)->next;
    (*a)->next = tmp;
}
void sa_and_b(t_stack **a, t_stack **b, int option)
{
    sa_or_b(b, 0, 'b');
    sa_or_b(a, 0, 'a');
    if (option)
        printf("ss\n");
}



// void	ft_lstadd_front(t_stack **lst, t_stack *new)
// {
// 	if (new != NULL || lst != NULL)
// 	{
// 		new->next = *lst;
// 		*lst = new;
// 	}
// }

// void pa_or_b(t_stack **a, t_stack **b, int option)
// {
    
// }