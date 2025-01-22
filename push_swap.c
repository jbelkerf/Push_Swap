#include "header.h"

t_stack	*ftt_lstlast(t_stack *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_stack	*ftt_lstnew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(1 * sizeof(t_stack));
	if (new == 0)
		return (0);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ftt_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ftt_lstlast(*lst);
		last->next = new;
	}
}

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

t_stack *init_stack(char **argm, int argc)
{
	int i;
	t_stack *head;

	head = NULL;
	i = 0;
	while (i < argc - 1)
	{
		ftt_lstadd_back(&head, ftt_lstnew(ft_atoi(argm[i])));
		i++;
	}
	return head;
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
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
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

	joinedargm = multi_join(argc, argv);
	check_non_digits(joinedargm);
	splitedargm = ft_split(joinedargm, ' ');
	stacka = init_stack(splitedargm, argc);
	return stacka;
}

int main(int argc, char **argv)
{
	t_stack *stacka;

	if (argc == 1)
		error();
	stacka = parce_and_fill(argc, argv);
	while (stacka)
	{
		printf("%d\n", stacka->value);
		stacka = stacka->next;
	}
	printf("%s\n", argv[0]);
	return (0);
}