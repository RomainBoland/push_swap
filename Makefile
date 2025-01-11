NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/ -I libft/includes/

# List all source files explicitly
SRC_CHECK = src/check_param/input_checker.c \
            src/check_param/input_formater.c \
            # Add other check_param files

SRC_ERROR = src/error_handling/error.c \
            # Add other error handling files

SRC_STACK = src/stack_ops/push.c \
            src/stack_ops/swap.c \
            src/stack_ops/rotate.c \
			src/stack_ops/reverse_rotate.c

SRC_UTILS = src/utils/free.c \
			src/utils/stack_init.c 
            # Add other utility files

SRC = $(SRC_CHECK) $(SRC_ERROR) $(SRC_STACK) $(SRC_UTILS) main.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c includes/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re