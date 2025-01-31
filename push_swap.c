/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:53:06 by codespace         #+#    #+#             */
/*   Updated: 2025/01/31 11:53:19 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_stack	*tmp;

	if (argc <= 1)
		error("zb\n");
	stackb = NULL;
	stacka = parce_and_fill(argc, argv);
	set_sorted_index(&stacka);
	while (stacka)
	{
		printf("value %d  sorted index %d\n", stacka->value, stacka->sorted_index);
		tmp = stacka;
		stacka = stacka->next;
		free(tmp);
	}
	ft_printf("b--->\n");
	while (stackb)
	{
		printf("%d\n", stackb->value);
		tmp = stackb;
		stackb = stackb->next;
		free(tmp);
	}
	return (0);
}
