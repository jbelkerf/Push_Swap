#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

void error(char *str);
t_stack	*ft_lstnew(int value);
char	*multi_join(int argc, char **argv);
t_stack *init_stack(char **argm, int argc);
void check_non_digits(char *str);
int	is_dup(int *tab, int size);
void check_duplicated(char **args);
void sa_or_b(t_stack **a, int option, char stack);
t_stack *parce_and_fill(int argc, char **argv);
void	ftt_lstclear(t_stack **lst);
void sa_and_b(t_stack **a, t_stack **b, int option);
void rotate_a_orb(t_stack **stack, int option, int pattern);
void push_stack(t_stack **wahd, t_stack **joj, int option, int pattern);
int stack_size(t_stack *stack);
#endif