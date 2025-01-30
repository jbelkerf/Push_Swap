# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:56:44 by codespace         #+#    #+#              #
#    Updated: 2025/01/30 16:07:07 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

CC=cc 

libft=./libft/libft.a

CFLAGS= -Wall -Wextra -Werror

M_SRC= push_swap.c swap_op.c parce_it.c push_op.c  rotate_op.c rev_rotate_op.c \
check_errors.c  tools.c

M_OBJ=$(M_SRC:.c=.o)

all: $(M_OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -g -fsanitize=address  $(M_OBJ) $(libft) -o $(NAME)

%.o:%.c header.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(MAKE) clean -C ./libft
	rm -f $(M_OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

