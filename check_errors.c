/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:52:49 by codespace         #+#    #+#             */
/*   Updated: 2025/01/31 11:55:15 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_non_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '-')
			i++;
		else
			error("non digit\n");
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
		error("duplicated\n");
	}
	free(ints);
}
