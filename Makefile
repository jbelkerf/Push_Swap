# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:56:44 by codespace         #+#    #+#              #
#    Updated: 2025/02/06 12:57:03 by jbelkerf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

NAME_BONUS=checker

NAME_COUNTER=counter

CC=cc 

LIBFT=./libft/libft.a

CFLAGS= -Wall -Wextra -Werror

M_SRC= push_swap.c operations/swap_op.c parce_it.c operations/push_op.c  \
operations/rotate_op.c operations/rev_rotate_op.c check_errors.c  tools.c \
set_sorted_index.c sort_the_stack.c

B_SRC= checker.c operations/push_op.c operations/rotate_op.c \
operations/rev_rotate_op.c operations/swap_op.c parce_it.c gnl/get_next_line_utils.c \
gnl/get_next_line.c tools.c set_sorted_index.c check_errors.c 

C_SRC= count_moves.c gnl/get_next_line.c gnl/get_next_line_utils.c tools.c 

C_OBJ=$(C_SRC:.c=.o)

M_OBJ=$(M_SRC:.c=.o)

B_OBJ=$(B_SRC:.c=.o)

all: $(M_OBJ) $(LIBFT)
	$(CC) $(CFLAGS)  $(M_OBJ) $(LIBFT) -o $(NAME)

truth: all bonus counter clean

bonus: $(B_OBJ) $(LIBFT)
	$(CC) $(CFLAGS)  $(B_OBJ) $(LIBFT) -o $(NAME_BONUS)

counter: $(C_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(C_OBJ) $(LIBFT) -o $(NAME_COUNTER)

%.o:%.c header.h
	$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
	$(MAKE) -C ./libft
clean:
	$(MAKE) clean -C ./libft
	@rm -f $(M_OBJ) $(B_OBJ) $(C_OBJ)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS) $(NAME_COUNTER)
	$(MAKE) fclean -C ./libft

