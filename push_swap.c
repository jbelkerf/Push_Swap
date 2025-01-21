#include "header.h"

char	*multi_join(int argc, char **argv)
{
	int i;
	int	j;
	int k;
	int str_tot;
	char *re;

	i = 1;
	str_tot = 0;
	while (i < argc)
	{
		str_tot += ft_strlen(argv[i]);
		i++;
	}
	re = malloc((str_tot + 1 + argc) * sizeof(char));
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			re[k] = argv[i][j];
			k++;
			j++;
		}
        re[k] = ' ';
        k++;
		i++;
	}
	re[k] = 0;
	return (re);
}

t_stack *init_stack(char **argm)
{
	t_stack *head;

}

void error(void)
{
	ft_putstr_fd("non digits has been found\n", 2);
	exit(1);
}

void check_non_digits(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			error();
	}
}

t_stack *parce_and_fill(int argc, char **argv)
{
	char	*joinedargm;
	char	**splitedargm;
	t_stack *stacka;

	joinedargm = multi_join(int argc, char **argv);
	check_non_digits(joinedargm);
	splitedargm = ft_split(joinedargm, ' ');
	stacka = init_stack(splitedargm);
}

int main(int argc, char **argv)
{
	t_stack *stacka;

	stacka = parce_and_fill(int argc, char **argv);
	return (0);
}