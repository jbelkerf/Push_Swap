/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:08:14 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/01/26 19:20:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * the lstdelone take a node and a del func used to delete the content and then
 * free the node
 */
void	ft_lstdelone(t_stack *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		free(lst);
	}
}
