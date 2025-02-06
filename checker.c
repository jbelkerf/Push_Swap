/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:04:24 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/06 12:56:06 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "./gnl/get_next_line.h"

void	free_stacks_and_str(t_stack **a, t_stack **b, char *str)
{
	free(str);
	free_stack(a);
	free_stack(b);
	error("bad instraction");
}

void	do_operation(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "sa\n"))
		sa_or_b(a, 0, 0);
	else if (!ft_strcmp(str, "sb\n"))
		sa_or_b(b, 0, 0);
	else if (!ft_strcmp(str, "ss\n"))
		sa_and_b(a, b, 0);
	else if (!ft_strcmp(str, "pa\n"))
		push_stack(b, a, 0, 0);
	else if (!ft_strcmp(str, "pb\n"))
		push_stack(a, b, 0, 0);
	else if (!ft_strcmp(str, "ra\n"))
		rotate_a_or_b(a, 0, 0);
	else if (!ft_strcmp(str, "rb\n"))
		rotate_a_or_b(b, 0, 0);
	else if (!ft_strcmp(str, "rr\n"))
		rotate_a_and_b(a, b, 0);
	else if (!ft_strcmp(str, "rra\n"))
		rev_rotate_a_or_b(a, 0, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		rev_rotate_a_or_b(b, 0, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		rev_rotate_a_and_b(a, b, 0);
	else
		free_stacks_and_str(a, b, str);
}

int	is_sorted(t_stack *a)
{
	set_sorted_index(&a);
	while (a && a->next)
	{
		if (a->sorted_index > a->next->sorted_index)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	char	*str;

	if (argc <= 1)
		error("too few argms");
	stackb = NULL;
	stacka = parce_and_fill(argc, argv);
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		do_operation(str, &stacka, &stackb);
		free(str);
		str = NULL;
	}
	if (is_sorted(stacka) && stackb == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stacka);
	free_stack(&stackb);
	return (0);
}
