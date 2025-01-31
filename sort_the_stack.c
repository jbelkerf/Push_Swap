/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:59:37 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/01/31 14:55:40 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_three(t_stack **a)
{
	set_sorted_index(a);
	if (order_of_big(*a, 2) == 3 && order_of_big(*a, 0) == 2)
		sa_or_b(a, 1, 1);
	else if (order_of_big(*a, 2) == 1)
	{
		rotate_a_or_b(a, 1, 1);
		sort_three(a);
	}
	else if (order_of_big(*a, 2) == 2)
	{
		rev_rotate_a_or_b(a, 1, 1);
		sort_three(a);
	}
}

void	sort_more_than_three(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (order_of_big(*a, i) <= stack_size(*a) / 2)
		{
			while (order_of_big(*a, i) != 1)
				rotate_a_or_b(a, 1, 1);
		}
		else
		{
			while (order_of_big(*a, i) != 1)
				rev_rotate_a_or_b(a, 1, 1);
		}
		push_stack(a, b, 1, 2);
		i++;
	}
	sort_three(a);
	while (b && *b)
	{
		push_stack(b, a, 1, 1);
	}
}

void	tiny_sort(t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 2 && (*a)->value > (*a)->next->value)
		sa_or_b(a, 1, 1);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) > 3)
	{
		sort_more_than_three(a, b);
	}
}

void	second_part(t_stack **a, t_stack **b)
{
	int	big;

	set_sorted_index(b);
	big = stack_size(*b) - 1;
	while (b && *b)
	{
		if (order_of_big(*b, big) == -1)
			;
		else if (order_of_big(*b, big) < stack_size(*b) / 2)
		{
			while (order_of_big(*b, big) != 1)
				rotate_a_or_b(b, 1, 2);
			push_stack(b, a, 1, 1);
		}
		else
		{
			while (order_of_big(*b, big) != 1)
				rev_rotate_a_or_b(b, 1, 2);
			push_stack(b, a, 1, 1);
		}
		big--;
	}
}

void	sort_the_stack(t_stack **a, t_stack **b)
{
	int		min;
	int		max;

	min = 0;
	max = stack_size(*a) * 0.048 + 10;
	while (a && *a)
	{
		if ((*a)->sorted_index < min)
		{
			push_stack(a, b, 1, 2);
			rotate_a_or_b(b, 1, 2);
			min++;
			max++;
		}
		else if ((*a)->sorted_index >= min && (*a)->sorted_index <= max)
		{
			push_stack(a, b, 1, 2);
			min++;
			max++;
		}
		else
			rotate_a_or_b(a, 1, 1);
	}
	second_part(a, b);
}
