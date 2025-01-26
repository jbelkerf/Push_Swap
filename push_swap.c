#include "header.h"



void error(void)
{
	ft_putstr_fd("non digits has been found\n", 2);
	exit(1);
}



int main(int argc, char **argv)
{
	t_stack *stacka;
	t_stack *tmp;

	if (argc == 1)
		error();
	stacka = parce_and_fill(argc, argv);
	sa_or_b(&stacka);
	while (stacka)
	{
		printf("%d\n", stacka->value);
		tmp = stacka;
		stacka = stacka->next;
		free(tmp);
	}
	//ftt_lstclear(&stacka);
	//printf("%s\n", argv[0]);
	return (0);
}