#include "header.h"

char	*multi_join(int argc, char **argv)
{
	int i;
	int str_tot;
	char *re;

	i = 0;
	str_tot = 0;
	while (i < argc)
	{
		str_tot += ft_strlen(argv[i]);
		i++;
	}
	re = malloc();
}

t_stack *parce_and_fill(int argc, char **argv)
{
	char	*joinedargm;
	char	**splitedargm;

	joinedargm = multi_join(int argc, char **argv);
	splitedargm = ft_split(joinedargm);
}

int main(int argc, char **argv)
{
	t_stack *stacka;

	stacka = parce_and_fill(int argc, char **argv);
	return (0);
}