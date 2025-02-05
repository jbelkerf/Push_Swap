/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:52:49 by codespace         #+#    #+#             */
/*   Updated: 2025/02/02 15:09:24 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ftt_atoi(const char *str, int *err)
{
	long int	n;
	int			sign;

	n = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if ((*str > '9' || *str < '0'))
		*err = 1;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		if ((n > 2147483647 && sign == 1) || (n > 2147483648 && sign == -1))
			return(*err= 1, 0);
		str++;
	}
	if (*str)
		*err = 1;
	return ((int)(sign * n));
}

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
			error("non di 1");
		while (argv[i][j])
		{
			c = argv[i][j];
			if ((c <= '9' && c >= '0') || c == '-' || c == '+')
				j++;
			else
				error("non dig 2");
		}
		i++;
	}
}

void	check_duplicated(char **args)
{
	int	i;
	int	err;
	int	*ints;

	i = 0;
	err = 0;
	while (args[i])
		i++;
	ints = malloc(i * sizeof(int));
	i = 0;
	while (args[i])
	{
		ints[i] = ftt_atoi(args[i], &err);
		if (err == 1)
		{
			free(ints);
			free_array(args);
			error("dup 1");
		}
		i++;
	}
	if (is_dup(ints, i))
	{
		free(ints);
		free_array(args);
		error("dup 2");
	}
	free(ints);
}
