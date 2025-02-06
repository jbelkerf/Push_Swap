/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:53:06 by codespace         #+#    #+#             */
/*   Updated: 2025/02/06 17:21:13 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;

	if (argc <= 1)
		return (0);
	stackb = NULL;
	stacka = parce_and_fill(argc, argv);
	if (is_sorted(stacka))
		return (0);
	set_sorted_index(&stacka);
	if (stack_size(stacka) <= 5)
		tiny_sort(&stacka, &stackb);
	else
		sort_the_stack(&stacka, &stackb);
	free_stack(&stacka);
	free_stack(&stackb);
	return (0);
}
