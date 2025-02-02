/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:02:22 by codespace         #+#    #+#             */
/*   Updated: 2025/02/02 10:07:48 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	rev_rotate_a_or_b(t_stack **stack, int option, int pattern)
{
	t_stack	*head;
	t_stack	*prev;
	t_stack	*tmp;

	if (option)
	{
		if (pattern == 1)
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
	head = *stack;
	prev = NULL;
	while (head)
	{
		if (head->next == NULL && prev != NULL)
		{
			tmp = head;
			prev->next = NULL;
			ft_lstadd_front(stack, tmp);
			break ;
		}
		prev = head;
		head = head->next;
	}
}

void	rev_rotate_a_and_b(t_stack **a, t_stack **b, int option)
{
	if (option)
		ft_printf("rrr\n");
	rev_rotate_a_or_b(a, 0, 0);
	rev_rotate_a_or_b(b, 0, 0);
}
