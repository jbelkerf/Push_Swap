NAME=push_swap
CC=cc 
CFLAGS= -Wall -Wextra -Werror

all:
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) ./libft/libft.a push_swap.c -o $(NAME)