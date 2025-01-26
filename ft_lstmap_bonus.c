/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:28:31 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/04 16:28:15 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
 * the lstmap func etirete on the given list, using the functiong f we make 
 * a new content from the existing one, then we give it to ft_lstnew to put it 
 * in new node then we give that node to the lst_add_back to gather this nodes
 * if this add failed we free the new content usig del and then we use the 
 * lst_clear function to free both the content and node for the lpast created
 * lst.
 */
t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*new_content;
	t_stack	*new_node;
	t_stack	*p;
	t_stack	*nw;

	nw = NULL;
	if (!lst || !f || !del)
		return (NULL);
	p = lst;
	while (p)
	{
		new_content = f(p->value);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&nw, del);
			return (0);
		}
		ft_lstadd_back(&nw, new_node);
		p = p->next;
	}
	return (nw);
}
