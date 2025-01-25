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

void sa_or_b(t_stack **a)
{
    t_stack *tmp;
    
    if (stack_size(*a) < 2)
        error();
    tmp = *a;
    *a = (*a)->next;
    tmp->next = (*a)->next;
    (*a)->next = tmp;
}
void sa_and_b(t_stack **a, t_stack **b)
{
    sa_or_b(b);
    sa_or_b(a);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new != NULL || lst != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

void pa_or_b(t_stack **a, t_stack **b, int option)
{
    
}