NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/ -I libft/includes/

SRC = src/sorting/*.c				\
			src/check_param/*.c		\
			src/error_handling/*.c	\
			src/stack_ops/*.c		\
			src/utils/*.c			\
			main.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
