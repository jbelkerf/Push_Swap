/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:52:32 by codespace         #+#    #+#             */
/*   Updated: 2025/02/02 10:07:58 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	sa_or_b(t_stack **a, int option, int pattern)
{
	t_stack	*tmp;

	if (option)
	{
		if (pattern == 1)
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
	if (stack_size(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	sa_and_b(t_stack **a, t_stack **b, int option)
{
	sa_or_b(b, 0, 'b');
	sa_or_b(a, 0, 'a');
	if (option)
		ft_printf("ss\n");
}
