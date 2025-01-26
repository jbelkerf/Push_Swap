#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

void error(void);
t_stack	*ft_lstnew(int value);
char	*multi_join(int argc, char **argv);
t_stack *init_stack(char **argm, int argc);
void check_non_digits(char *str);
int	is_dup(int *tab, int size);
void check_duplicated(char **args);
t_stack *parce_and_fill(int argc, char **argv);
#endif