/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:46:34 by codespace         #+#    #+#             */
/*   Updated: 2025/02/01 13:08:53 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

void	error(char *str);
void	free_array(char **ar);
void	free_stack(t_stack **a);
void	check_non_digits(int argc, char **argv);
void	check_duplicated(char **args);
void	sa_or_b(t_stack **a, int option, int pattern);
void	sa_and_b(t_stack **a, t_stack **b, int option);
void	rotate_a_or_b(t_stack **stack, int option, int pattern);
void	rotate_a_and_b(t_stack **a, t_stack **b, int option);
void	push_stack(t_stack **wahd, t_stack **joj, int option, int pattern);
void	rev_rotate_a_or_b(t_stack **stack, int option, int pattern);
void	rev_rotate_a_and_b(t_stack **a, t_stack **b, int option);
void	set_sorted_index(t_stack **stack);
void	sort_the_stack(t_stack **a, t_stack **b);
void	tiny_sort(t_stack **a, t_stack **b);
t_stack	*init_stack(char **argm);
t_stack	*parce_and_fill(int argc, char **argv);
t_stack	*ft_lstnew(int value);
int		is_dup(int *tab, int size);
int		stack_size(t_stack *stack);
int		args_lenght(int argc, char **argv);
int		order_of_big(t_stack *stack, int big);
int	is_sorted(t_stack *a);
char	*multi_join(int argc, char **argv);
#endif