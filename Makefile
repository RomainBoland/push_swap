NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/ -I libft/includes/

# Source directories
SRC_DIRS = src/check_param \
           src/error_handling \
           src/stack_ops \
           src/utils

# Get all .c files from each directory
SRC = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c)) \
      main.c

# Create object files in same directory structure
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT)

# Rule to compile .c files into .o files
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
