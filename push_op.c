/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:05:45 by codespace         #+#    #+#             */
/*   Updated: 2025/01/27 12:07:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void push_stack(t_stack **wahd, t_stack **joj, int option, int pattern)
{
	t_stack *tmp;
	t_stack *tmp_next;

	if (option)
	{
		if (pattern == 1)
			ft_printf("pa\n");
		else
			ft_printf("pb\n");
	}
	if (*wahd)
	{
		tmp = *wahd;
		tmp_next = (*wahd)->next;
		ft_lstadd_front(joj, tmp);
		*wahd= tmp_next;
	}
}