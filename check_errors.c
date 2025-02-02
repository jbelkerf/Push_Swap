/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:52:49 by codespace         #+#    #+#             */
/*   Updated: 2025/02/01 13:29:39 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_non_digits(int argc, char **argv)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == 0)
			error();
		while (argv[i][j])
		{
			c = argv[i][j];
			if ((c <= '9' && c >= '0') || c == '-' || c == '+')
				j++;
			else
				error();
		}
		i++;
	}
}

void	check_duplicated(char **args)
{
	int	i;
	int	*ints;

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
