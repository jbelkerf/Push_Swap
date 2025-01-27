/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:33:45 by codespace         #+#    #+#             */
/*   Updated: 2025/01/27 13:50:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_a_or_b(t_stack **stack, int option, int pattern)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	if (option)
	{
		if (pattern == 1)
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
	tmp = *stack;
	if (*stack)
	{
		tmp_next = (*stack)->next;
		*stack = tmp_next;
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
	}
}

void	rotate_a_and_b(t_stack **a, t_stack **b, int option)
{
	if (option)
	{
		ft_printf("rr\n");
	}
	rotate_a_or_b(a, 0, 0);
	rotate_a_or_b(b, 0, 0);
}
