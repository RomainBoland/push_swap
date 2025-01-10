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
SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c)) \
      main.c

# Create object files in obj directory
OBJ_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

# Create directories for object files
OBJ_DIRS = $(OBJ_DIR) $(addprefix $(OBJ_DIR),$(SRC_DIRS))

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(OBJ_DIRS) $(LIBFT) $(NAME)

# Create object directories
$(OBJ_DIRS):
	mkdir -p $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Link program
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBFT)

# Compile source files
$(OBJ_DIR)%.o: %.c includes/push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re