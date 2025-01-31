/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sorted_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:40:40 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/01/31 11:51:13 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_sorted_index(t_stack **stack)
{
	t_stack	*head1;
	t_stack	*head2;
	t_stack	*head3;

	head1 = *stack;
	head2 = *stack;
	head3 = *stack;
	while (head1)
	{
		head2 = head3;
		head1->sorted_index = 0;
		while (head2)
		{
			if (head1->value > head2->value)
				head1->sorted_index++;
			head2 = head2->next;
		}
		head1 = head1->next;
	}
}
