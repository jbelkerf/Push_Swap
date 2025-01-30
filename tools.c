/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:57:27 by codespace         #+#    #+#             */
/*   Updated: 2025/01/30 16:04:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	args_lenght(int argc, char **argv)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < argc)
	{
		total += ft_strlen(argv[i]);
		i++;
	}
	return (total);
}
