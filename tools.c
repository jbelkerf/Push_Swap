/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:57:27 by codespace         #+#    #+#             */
/*   Updated: 2025/02/01 13:57:39 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	args_lenght(int argc, char **argv)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < argc)
	{
		total += ft_strlen(argv[i]);
		i++;
	}
	return (total);
}

int	order_of_big(t_stack *stack, int big)
{
	int	i;

	i = 1;
	while (stack)
	{
		if (stack->sorted_index == big)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

void	error(void)
{
	ft_putstr_fd("error\n", 1);
	exit(1);
}
