# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:56:44 by codespace         #+#    #+#              #
#    Updated: 2025/02/02 10:17:48 by jbelkerf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

NAME_BONUS=checker

CC=cc 

libft=./libft/libft.a

CFLAGS= -Wall -Wextra -Werror

M_SRC= push_swap.c operations/swap_op.c parce_it.c operations/push_op.c  \
operations/rotate_op.c operations/rev_rotate_op.c check_errors.c  tools.c \
set_sorted_index.c sort_the_stack.c

M_OBJ=$(M_SRC:.c=.o)

B_SRC= checker.c operations/push_op.c operations/rotate_op.c \
operations/rev_rotate_op.c operations/swap_op.c parce_it.c gnl/get_next_line_utils.c \
gnl/get_next_line.c tools.c set_sorted_index.c check_errors.c 


B_OBJ=$(B_SRC:.c=.o)

all: $(M_OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -g -fsanitize=address  $(M_OBJ) $(libft) -o $(NAME)

bonus: $(B_OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -g -fsanitize=address $(B_OBJ) $(libft) -o $(NAME_BONUS)

%.o:%.c header.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(MAKE) clean -C ./libft
	rm -f $(M_OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

