/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:21:51 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/02/02 10:27:03 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "gnl/get_next_line.h"

int	main(void)
{
	char	*str;
	int		i;

	i = 0;
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		i++;
		free(str);
		str = NULL;
	}
	ft_printf("the move count is %i\n", i);
	return (0);
}
