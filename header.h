#ifndef HEADER_H
#define HEADER_H

typedef struct a_stack
{
    int value;
    struct a_stack *next;
}  t_stack;
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#endif