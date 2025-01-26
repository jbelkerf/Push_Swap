/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:01:02 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/04 16:34:57 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * the lstclear take a lst and del the entire lst
 */
void	ftt_lstclear(t_stack **lst)
{
	t_stack	*p;

	if (lst == NULL)
		return ;
	p = *lst;
	while (p)
	{
		free(p);
		*lst = (*lst)->next;
		*lst = p;
	}
	*lst = NULL;
}
