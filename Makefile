NAME=push_swap
CC=cc 
libft=./libft/libft.a
CFLAGS= -Wall -Wextra -Werror
M_SRC= push_swap.c operations.c ft_lstnew_bonus.c  ft_lstsize_bonus.c \
	 ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
	 ft_lstclear_bonus.c ft_lstdelone_bonus.c parce_it.c
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
