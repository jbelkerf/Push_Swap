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
	sa_and_b(&stackb, &stacka, 1);
	while (stacka)
	{
		printf("%d\n", stacka->value);
		tmp = stacka;
		stacka = stacka->next;
		free(tmp);
	}
	
	return (0);
}