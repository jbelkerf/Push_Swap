NAME=push_swap
CC=cc 
libft=./libft/libft.a
CFLAGS= -Wall -Wextra -Werror
M_SRC= push_swap.c 
M_OBJ=$(M_SRC:.c=.o)

all: $(M_OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(M_OBJ) $(libft) -o $(NAME)

%.o:%.c header.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(MAKE) clean -C ./libft


	##-g -fsanitize=address 