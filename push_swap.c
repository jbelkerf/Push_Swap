#include "header.h"



void error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}



int main(int argc, char **argv)
{
	t_stack *stacka;
	t_stack *stackb;
	t_stack *tmp;

	if (argc <= 1)
		error("zb\n");
	stackb = NULL;
	stacka = parce_and_fill(argc, argv);
	push_stack(&stacka, &stackb, 1, 1);
	push_stack(&stacka, &stackb, 1, 1);
	push_stack(&stacka, &stackb, 1, 1);
	push_stack(&stacka, &stackb, 1, 1);

	rev_rotate_a_and_b(&stacka, &stackb, 1);

	ft_printf("a--->\n");
	while (stacka)
	{
		printf("%d\n", stacka->value);
		tmp = stacka;
		stacka = stacka->next;
		free(tmp);
	}
	ft_printf("b--->\n");
	while (stackb)
	{
		printf("%d\n", stackb->value);
		tmp = stackb;
		stackb = stackb->next;
		free(tmp);
	}
	
	return (0);
}