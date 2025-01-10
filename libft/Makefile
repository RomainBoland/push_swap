NAME = libft.a

# Source directories and files
SRC_LIBFT = $(wildcard src/libft/*.c)
SRC_PRINTF = $(wildcard src/ft_printf/*.c)
SRC_GNL = $(wildcard src/get_next_line/*.c)

SRC = $(SRC_LIBFT) $(SRC_PRINTF) $(SRC_GNL)

# Generate object file names properly
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

all: $(NAME)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re