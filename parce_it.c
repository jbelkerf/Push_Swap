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
	while (i < argc )
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

void free_array(char **ar)
{
	int i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

t_stack *init_stack(char **argm, int argc)
{
	int i;
	t_stack *head;

	head = NULL;
	i = 0;
	while (i < argc - 1)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_atoi(argm[i])));
		i++;
	}
	return head;
}

void check_non_digits(char *str)
{
	int i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else
			error();
	}
}

int	is_dup(int *tab, int size)
{
	int i = 0;
	int j;

	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return 0;
}

void check_duplicated(char **args)
{
	int i;
	int *ints;

	i = 0;
	while (args[i])
		i++;
	ints = malloc(i * sizeof(int));
	i = 0;
	while (args[i])
	{
		ints[i] = ft_atoi(args[i]);
		i++;
	}
	if (is_dup(ints, i))
	{
		free(ints);
		error();
	}
	free(ints);
}
t_stack *parce_and_fill(int argc, char **argv)
{
	char	*joinedargm;
	char	**splitedargm;
	t_stack *stacka;

	joinedargm = multi_join(argc, argv);
	check_non_digits(joinedargm);
	splitedargm = ft_split(joinedargm, ' ');
	free(joinedargm);
	check_duplicated(splitedargm);
	stacka = init_stack(splitedargm, argc);
	free_array(splitedargm);
	return stacka;
}