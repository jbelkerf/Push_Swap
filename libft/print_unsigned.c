/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:16:35 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/01/26 19:24:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unsigned(unsigned int n, int count)
{
	if (n <= 9)
		count += print_char(n + '0');
	else
	{
		count = print_dec(n / 10, count);
		count += print_char(n % 10 + '0');
	}
	return (count);
}
