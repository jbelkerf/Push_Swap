/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:21:19 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/01/26 19:24:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_dec(int n, int count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n == 2147483647)
	{
		write(1, "2147483647", 10);
		return (10);
	}
	if (n < 0)
	{
		count += print_char('-');
		count = print_dec(n * (-1), count);
	}
	else if (n <= 9)
		count += print_char(n + '0');
	else
	{
		count = print_dec(n / 10, count);
		count += print_char(n % 10 + '0');
	}
	return (count);
}
