/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:52:02 by codespace         #+#    #+#             */
/*   Updated: 2025/02/01 12:43:33 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*multi_join(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*re;

	re = malloc((args_lenght(argc, argv) + 1 + argc) * sizeof(char));
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

void	free_array(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

t_stack	*init_stack(char **argm)
{
	int		i;
	t_stack	*head;
	int		total_argument;

	head = NULL;
	total_argument = 0;
	while (argm[total_argument])
		total_argument++;
	i = 0;
	while (i < total_argument)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_atoi(argm[i])));
		i++;
	}
	return (head);
}

int	is_dup(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
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
	return (0);
}

t_stack	*parce_and_fill(int argc, char **argv)
{
	char	*joinedargm;
	char	**splitedargm;
	t_stack	*stacka;

	check_non_digits(argc, argv);
	joinedargm = multi_join(argc, argv);
	splitedargm = ft_split(joinedargm, ' ');
	free(joinedargm);
	check_duplicated(splitedargm);
	stacka = init_stack(splitedargm);
	free_array(splitedargm);
	return (stacka);
}
